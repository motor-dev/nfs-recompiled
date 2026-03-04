#include "nfs2se.h"
#include <lib/thread.h>

namespace nfs2se
{

/* align: skip  */
void Application::sub_4772b7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004772b7  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004772b8  8b1518844c00           -mov edx, dword ptr [0x4c8418]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5014552) /* 0x4c8418 */);
    // 004772be  a124b05100             -mov eax, dword ptr [0x51b024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5353508) /* 0x51b024 */);
    // 004772c3  a318844c00             -mov dword ptr [0x4c8418], eax
    app->getMemory<x86::reg32>(x86::reg32(5014552) /* 0x4c8418 */) = cpu.eax;
    // 004772c8  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004772ca  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004772cb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4772cc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004772cc  c70524b0510000000000   -mov dword ptr [0x51b024], 0
    app->getMemory<x86::reg32>(x86::reg32(5353508) /* 0x51b024 */) = 0 /*0x0*/;
    // 004772d6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4772d7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004772d7  030524b05100           -add eax, dword ptr [0x51b024]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5353508) /* 0x51b024 */)));
    // 004772dd  a314844c00             -mov dword ptr [0x4c8414], eax
    app->getMemory<x86::reg32>(x86::reg32(5014548) /* 0x4c8414 */) = cpu.eax;
    // 004772e2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4772e3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
L_0x004772e3:
    // 004772e3  a124b05100             -mov eax, dword ptr [0x51b024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5353508) /* 0x51b024 */);
    // 004772e8  2b0514844c00           +sub eax, dword ptr [0x4c8414]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014548) /* 0x4c8414 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    app->unlockContext(cpu);
    win32::Thread::sleep(0);
    app->lockContext(cpu);
    // 004772ee  78f3                   -js 0x4772e3
    if (cpu.flags.sf)
    {
        goto L_0x004772e3;
    }
    // 004772f0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4772f1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004772f1  a124b05100             -mov eax, dword ptr [0x51b024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5353508) /* 0x51b024 */);
    // 004772f6  2b0514844c00           +sub eax, dword ptr [0x4c8414]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014548) /* 0x4c8414 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004772fc  19c0                   -sbb eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 004772fe  40                     -inc eax
    (cpu.eax)++;
    // 004772ff  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_477300(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477300  030524b05100           -add eax, dword ptr [0x51b024]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5353508) /* 0x51b024 */)));
    // 00477306  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
L_0x00477307:
    // 00477307  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00477309  e8720d0000             -call 0x478080
    cpu.esp -= 4;
    sub_478080(app, cpu);
    if (cpu.terminate) return;
    // 0047730e  a124b05100             -mov eax, dword ptr [0x51b024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5353508) /* 0x51b024 */);
    // 00477313  2b0424                 +sub eax, dword ptr [esp]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00477316  78ef                   -js 0x477307
    if (cpu.flags.sf)
    {
        goto L_0x00477307;
    }
    // 00477318  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047731b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_477320(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477320  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00477321  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00477322  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00477323  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00477326  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00477328  8b7004                 -mov esi, dword ptr [eax + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0047732b  8b7808                 -mov edi, dword ptr [eax + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0047732e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00477330  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00477334  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00477337  e820f0ffff             -call 0x47635c
    cpu.esp -= 4;
    sub_47635c(app, cpu);
    if (cpu.terminate) return;
    // 0047733c  8b420c                 -mov eax, dword ptr [edx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0047733f  39c3                   +cmp ebx, eax
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
    // 00477341  0f8c69000000           -jl 0x4773b0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004773b0;
    }
L_0x00477347:
    // 00477347  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0047734a  39c1                   +cmp ecx, eax
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
    // 0047734c  7d0e                   -jge 0x47735c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047735c;
    }
    // 0047734e  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00477350  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00477353  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00477356  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00477358  01cf                   -add edi, ecx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0047735a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x0047735c:
    // 0047735c  8d0433                 -lea eax, [ebx + esi]
    cpu.eax = x86::reg32(cpu.ebx + cpu.esi * 1);
    // 0047735f  3b4214                 +cmp eax, dword ptr [edx + 0x14]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00477362  7e05                   -jle 0x477369
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00477369;
    }
    // 00477364  8b7214                 -mov esi, dword ptr [edx + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 00477367  29de                   -sub esi, ebx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00477369:
    // 00477369  8d0439                 -lea eax, [ecx + edi]
    cpu.eax = x86::reg32(cpu.ecx + cpu.edi * 1);
    // 0047736c  3b4218                 +cmp eax, dword ptr [edx + 0x18]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047736f  7e05                   -jle 0x477376
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00477376;
    }
    // 00477371  8b7a18                 -mov edi, dword ptr [edx + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 00477374  29cf                   -sub edi, ecx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00477376:
    // 00477376  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00477378  7e2d                   -jle 0x4773a7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004773a7;
    }
    // 0047737a  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0047737c  7e29                   -jle 0x4773a7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004773a7;
    }
    // 0047737e  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00477382  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00477384  7405                   -je 0x47738b
    if (cpu.flags.zf)
    {
        goto L_0x0047738b;
    }
    // 00477386  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
L_0x0047738b:
    // 0047738b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047738c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047738d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047738e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047738f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00477390  8b4a34                 -mov ecx, dword ptr [edx + 0x34]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(52) /* 0x34 */);
    // 00477393  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00477394  8b4534                 -mov eax, dword ptr [ebp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(52) /* 0x34 */);
    // 00477397  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0047739b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047739c  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004773a0  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004773a2  e891cb0000             -call 0x483f38
    cpu.esp -= 4;
    sub_483f38(app, cpu);
    if (cpu.terminate) return;
L_0x004773a7:
    // 004773a7  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004773aa  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004773ab  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004773ac  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004773ad  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004773b0:
    // 004773b0  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004773b2  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004773b6  8b420c                 -mov eax, dword ptr [edx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004773b9  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004773bb  01de                   +add esi, ebx
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004773bd  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004773bf  eb86                   -jmp 0x477347
    goto L_0x00477347;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4773c4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004773c4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004773c5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004773c6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004773c7  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004773ca  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004773cc  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004773ce  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004773d0  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004773d2  8b4d04                 -mov ecx, dword ptr [ebp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 004773d5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004773d7  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004773da  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004773de  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004773e1  e876efffff             -call 0x47635c
    cpu.esp -= 4;
    sub_47635c(app, cpu);
    if (cpu.terminate) return;
    // 004773e6  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004773e8  7c2d                   -jl 0x477417
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00477417;
    }
L_0x004773ea:
    // 004773ea  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004773ec  7c3b                   -jl 0x477429
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00477429;
    }
L_0x004773ee:
    // 004773ee  8d040a                 -lea eax, [edx + ecx]
    cpu.eax = x86::reg32(cpu.edx + cpu.ecx * 1);
    // 004773f1  3b4704                 +cmp eax, dword ptr [edi + 4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004773f4  7e05                   -jle 0x4773fb
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004773fb;
    }
    // 004773f6  8b4f04                 -mov ecx, dword ptr [edi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 004773f9  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
L_0x004773fb:
    // 004773fb  8d0433                 -lea eax, [ebx + esi]
    cpu.eax = x86::reg32(cpu.ebx + cpu.esi * 1);
    // 004773fe  3b4708                 +cmp eax, dword ptr [edi + 8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00477401  7e05                   -jle 0x477408
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00477408;
    }
    // 00477403  8b7708                 -mov esi, dword ptr [edi + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 00477406  29de                   -sub esi, ebx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00477408:
    // 00477408  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047740a  7e04                   -jle 0x477410
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00477410;
    }
    // 0047740c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0047740e  7f29                   -jg 0x477439
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00477439;
    }
L_0x00477410:
    // 00477410  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00477413  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477414  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477415  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477416  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00477417:
    // 00477417  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0047741b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047741d  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0047741f  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 00477421  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00477423  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00477427  ebc1                   -jmp 0x4773ea
    goto L_0x004773ea;
L_0x00477429:
    // 00477429  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0047742c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047742e  01de                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00477430  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 00477432  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00477434  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00477437  ebb5                   -jmp 0x4773ee
    goto L_0x004773ee;
L_0x00477439:
    // 00477439  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047743b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047743c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047743d  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00477441  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00477442  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00477446  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00477447  8b4534                 -mov eax, dword ptr [ebp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(52) /* 0x34 */);
    // 0047744a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047744b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047744c  8b4734                 -mov eax, dword ptr [edi + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(52) /* 0x34 */);
    // 0047744f  e8e4ca0000             -call 0x483f38
    cpu.esp -= 4;
    sub_483f38(app, cpu);
    if (cpu.terminate) return;
    // 00477454  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00477457  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477458  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477459  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047745a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_47745c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047745c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047745d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047745e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047745f  8b7c2410               -mov edi, dword ptr [esp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00477463  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00477465  e8f2eeffff             -call 0x47635c
    cpu.esp -= 4;
    sub_47635c(app, cpu);
    if (cpu.terminate) return;
    // 0047746a  8b6e0c                 -mov ebp, dword ptr [esi + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0047746d  39ea                   +cmp edx, ebp
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
    // 0047746f  7d06                   -jge 0x477477
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00477477;
    }
    // 00477471  29ea                   -sub edx, ebp
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00477473  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00477475  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
L_0x00477477:
    // 00477477  8b6e10                 -mov ebp, dword ptr [esi + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0047747a  39eb                   +cmp ebx, ebp
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
    // 0047747c  7d06                   -jge 0x477484
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00477484;
    }
    // 0047747e  29eb                   -sub ebx, ebp
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00477480  01df                   -add edi, ebx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00477482  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
L_0x00477484:
    // 00477484  8b6e14                 -mov ebp, dword ptr [esi + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00477487  8d040a                 -lea eax, [edx + ecx]
    cpu.eax = x86::reg32(cpu.edx + cpu.ecx * 1);
    // 0047748a  39e8                   +cmp eax, ebp
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
    // 0047748c  7e04                   -jle 0x477492
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00477492;
    }
    // 0047748e  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 00477490  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
L_0x00477492:
    // 00477492  8b6e18                 -mov ebp, dword ptr [esi + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00477495  8d043b                 -lea eax, [ebx + edi]
    cpu.eax = x86::reg32(cpu.ebx + cpu.edi * 1);
    // 00477498  39e8                   +cmp eax, ebp
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
    // 0047749a  7e04                   -jle 0x4774a0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004774a0;
    }
    // 0047749c  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 0047749e  29df                   -sub edi, ebx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004774a0:
    // 004774a0  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004774a2  7e04                   -jle 0x4774a8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004774a8;
    }
    // 004774a4  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004774a6  7f06                   -jg 0x4774ae
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004774ae;
    }
L_0x004774a8:
    // 004774a8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004774a9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004774aa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004774ab  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004774ae:
    // 004774ae  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004774b2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004774b3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004774b4  8b4634                 -mov eax, dword ptr [esi + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */);
    // 004774b7  e808ca0000             -call 0x483ec4
    cpu.esp -= 4;
    sub_483ec4(app, cpu);
    if (cpu.terminate) return;
    // 004774bc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004774bd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004774be  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004774bf  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4774c4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004774c4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004774c5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004774c6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004774c7  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004774ca  8b6c2428               -mov ebp, dword ptr [esp + 0x28]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004774ce  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004774d1  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004774d3  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004774d5  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004774d7  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004774d9  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004774dc  c1e810                 +shr eax, 0x10
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
    // 004774df  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004774e1  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004774e5  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004774e7  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004774eb  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004774ed  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004774ef  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004774f2  c1e810                 +shr eax, 0x10
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
    // 004774f5  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004774f7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004774f9  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004774fb  e85ceeffff             -call 0x47635c
    cpu.esp -= 4;
    sub_47635c(app, cpu);
    if (cpu.terminate) return;
    // 00477500  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00477502  7e47                   -jle 0x47754b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047754b;
    }
    // 00477504  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00477506  7e43                   -jle 0x47754b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047754b;
    }
    // 00477508  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047750a  7e3f                   -jle 0x47754b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047754b;
    }
    // 0047750c  837c241800             +cmp dword ptr [esp + 0x18], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00477511  7e38                   -jle 0x47754b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047754b;
    }
    // 00477513  837c242c00             +cmp dword ptr [esp + 0x2c], 0
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
    // 00477518  743a                   -je 0x477554
    if (cpu.flags.zf)
    {
        goto L_0x00477554;
    }
    // 0047751a  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
L_0x0047751f:
    // 0047751f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00477520  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00477521  8b6c240c               -mov ebp, dword ptr [esp + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00477525  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00477526  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0047752a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047752b  8b542430               -mov edx, dword ptr [esp + 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0047752f  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00477533  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00477534  8b7834                 -mov edi, dword ptr [eax + 0x34]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    // 00477537  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00477538  8b6c2430               -mov ebp, dword ptr [esp + 0x30]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0047753c  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00477540  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00477541  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00477543  8b4034                 -mov eax, dword ptr [eax + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    // 00477546  e8edc90000             -call 0x483f38
    cpu.esp -= 4;
    sub_483f38(app, cpu);
    if (cpu.terminate) return;
L_0x0047754b:
    // 0047754b  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0047754e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047754f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477550  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477551  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x00477554:
    // 00477554  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00477556  ebc7                   -jmp 0x47751f
    goto L_0x0047751f;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4775a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 004775a0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004775a1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004775a2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004775a3  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004775a5  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004775a7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004775a9  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004775ab  7411                   -je 0x4775be
    if (cpu.flags.zf)
    {
        goto L_0x004775be;
    }
    // 004775ad  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004775af:
    // 004775af  48                     -dec eax
    (cpu.eax)--;
    // 004775b0  83f8ff                 +cmp eax, -1
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
    // 004775b3  7409                   -je 0x4775be
    if (cpu.flags.zf)
    {
        goto L_0x004775be;
    }
    // 004775b5  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004775b6  8a16                   -mov dl, byte ptr [esi]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi);
    // 004775b8  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004775b9  8857ff                 -mov byte ptr [edi - 1], dl
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(-1) /* -0x1 */) = cpu.dl;
    // 004775bc  ebf1                   -jmp 0x4775af
    goto L_0x004775af;
L_0x004775be:
    // 004775be  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004775c0  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004775c2  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004775c4  c1f902                 -sar ecx, 2
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (2 /*0x2*/ % 32));
    // 004775c7  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004775c9  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004775cb  c1fd06                 -sar ebp, 6
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (6 /*0x6*/ % 32));
    // 004775ce  83e60f                 -and esi, 0xf
    cpu.esi &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004775d1  83e303                 -and ebx, 3
    cpu.ebx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004775d4  83fe0f                 +cmp esi, 0xf
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(15 /*0xf*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004775d7  0f87c6000000           -ja 0x4776a3
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004776a3;
    }
    // 004775dd  ff24b560754700         -jmp dword ptr [esi*4 + 0x477560]
    cpu.ip = app->getMemory<x86::reg32>(4683104 + cpu.esi * 4); goto dynamic_jump;
  case 0x004775e4:
L_0x004775e4:
    // 004775e4  4d                     -dec ebp
    (cpu.ebp)--;
    // 004775e5  83fdff                 +cmp ebp, -1
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
    // 004775e8  0f84b5000000           -je 0x4776a3
    if (cpu.flags.zf)
    {
        goto L_0x004776a3;
    }
    // 004775ee  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004775f1  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 004775f3  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004775f6  8970fc                 -mov dword ptr [eax - 4], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.esi;
  [[fallthrough]];
  case 0x004775f9:
    // 004775f9  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004775fc  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004775fe  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00477601  8948fc                 -mov dword ptr [eax - 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
  [[fallthrough]];
  case 0x00477604:
    // 00477604  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00477607  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 00477609  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047760c  8948fc                 -mov dword ptr [eax - 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
  [[fallthrough]];
  case 0x0047760f:
    // 0047760f  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00477612  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 00477614  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00477617  8948fc                 -mov dword ptr [eax - 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
  [[fallthrough]];
  case 0x0047761a:
    // 0047761a  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047761d  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 0047761f  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00477622  8948fc                 -mov dword ptr [eax - 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
  [[fallthrough]];
  case 0x00477625:
    // 00477625  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00477628  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 0047762a  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047762d  8970fc                 -mov dword ptr [eax - 4], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.esi;
  [[fallthrough]];
  case 0x00477630:
    // 00477630  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00477633  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 00477635  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00477638  8948fc                 -mov dword ptr [eax - 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
  [[fallthrough]];
  case 0x0047763b:
    // 0047763b  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047763e  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 00477640  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00477643  8948fc                 -mov dword ptr [eax - 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
  [[fallthrough]];
  case 0x00477646:
    // 00477646  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00477649  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 0047764b  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047764e  8948fc                 -mov dword ptr [eax - 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
  [[fallthrough]];
  case 0x00477651:
    // 00477651  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00477654  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 00477656  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00477659  8948fc                 -mov dword ptr [eax - 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
  [[fallthrough]];
  case 0x0047765c:
    // 0047765c  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047765f  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 00477661  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00477664  8948fc                 -mov dword ptr [eax - 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
  [[fallthrough]];
  case 0x00477667:
    // 00477667  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047766a  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 0047766c  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047766f  8970fc                 -mov dword ptr [eax - 4], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.esi;
  [[fallthrough]];
  case 0x00477672:
    // 00477672  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00477675  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 00477677  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047767a  8970fc                 -mov dword ptr [eax - 4], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.esi;
  [[fallthrough]];
  case 0x0047767d:
    // 0047767d  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00477680  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 00477682  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00477685  8970fc                 -mov dword ptr [eax - 4], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.esi;
  [[fallthrough]];
  case 0x00477688:
    // 00477688  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047768b  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 0047768d  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00477690  8970fc                 -mov dword ptr [eax - 4], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.esi;
  [[fallthrough]];
  case 0x00477693:
    // 00477693  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00477696  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 00477698  83c204                 +add edx, 4
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
    // 0047769b  8970fc                 -mov dword ptr [eax - 4], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.esi;
    // 0047769e  e941ffffff             -jmp 0x4775e4
    goto L_0x004775e4;
L_0x004776a3:
    // 004776a3  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x004776a5:
    // 004776a5  4b                     -dec ebx
    (cpu.ebx)--;
    // 004776a6  83fbff                 +cmp ebx, -1
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
    // 004776a9  740d                   -je 0x4776b8
    if (cpu.flags.zf)
    {
        goto L_0x004776b8;
    }
    // 004776ab  8d0c32                 -lea ecx, [edx + esi]
    cpu.ecx = x86::reg32(cpu.edx + cpu.esi * 1);
    // 004776ae  8d3c30                 -lea edi, [eax + esi]
    cpu.edi = x86::reg32(cpu.eax + cpu.esi * 1);
    // 004776b1  8a09                   -mov cl, byte ptr [ecx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx);
    // 004776b3  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004776b4  880f                   -mov byte ptr [edi], cl
    app->getMemory<x86::reg8>(cpu.edi) = cpu.cl;
    // 004776b6  ebed                   -jmp 0x4776a5
    goto L_0x004776a5;
L_0x004776b8:
    // 004776b8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004776b9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004776ba  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004776bb  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void Application::sub_4776bc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004776bc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004776bd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004776be  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004776c0  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004776c2  83fb04                 +cmp ebx, 4
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
    // 004776c5  7d13                   -jge 0x4776da
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004776da;
    }
L_0x004776c7:
    // 004776c7  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004776c9  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
L_0x004776cb:
    // 004776cb  4b                     -dec ebx
    (cpu.ebx)--;
    // 004776cc  83fbff                 +cmp ebx, -1
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
    // 004776cf  742a                   -je 0x4776fb
    if (cpu.flags.zf)
    {
        goto L_0x004776fb;
    }
    // 004776d1  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004776d2  8a48ff                 -mov cl, byte ptr [eax - 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 004776d5  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004776d6  880a                   -mov byte ptr [edx], cl
    app->getMemory<x86::reg8>(cpu.edx) = cpu.cl;
    // 004776d8  ebf1                   -jmp 0x4776cb
    goto L_0x004776cb;
L_0x004776da:
    // 004776da  39c2                   +cmp edx, eax
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
    // 004776dc  7607                   -jbe 0x4776e5
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004776e5;
    }
    // 004776de  8d0c18                 -lea ecx, [eax + ebx]
    cpu.ecx = x86::reg32(cpu.eax + cpu.ebx * 1);
    // 004776e1  39ca                   +cmp edx, ecx
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
    // 004776e3  72e2                   -jb 0x4776c7
    if (cpu.flags.cf)
    {
        goto L_0x004776c7;
    }
L_0x004776e5:
    // 004776e5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004776e7  be04000000             -mov esi, 4
    cpu.esi = 4 /*0x4*/;
    // 004776ec  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004776ef  29ce                   -sub esi, ecx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004776f1  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004776f3  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004776f6  e8a5feffff             -call 0x4775a0
    cpu.esp -= 4;
    sub_4775a0(app, cpu);
    if (cpu.terminate) return;
L_0x004776fb:
    // 004776fb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004776fc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004776fd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_477700(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477700  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00477701  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00477703  d1fb                   -sar ebx, 1
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (1 /*0x1*/ % 32));
    // 00477705  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00477707  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00477709  e8aeffffff             -call 0x4776bc
    cpu.esp -= 4;
    sub_4776bc(app, cpu);
    if (cpu.terminate) return;
    // 0047770e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047770f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_477710(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477710  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00477711  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00477713  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00477715  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00477717  e8a0ffffff             -call 0x4776bc
    cpu.esp -= 4;
    sub_4776bc(app, cpu);
    if (cpu.terminate) return;
    // 0047771c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047771d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_477720(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477720  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00477721  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00477723  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00477725  01db                   -add ebx, ebx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00477727  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00477729  e88effffff             -call 0x4776bc
    cpu.esp -= 4;
    sub_4776bc(app, cpu);
    if (cpu.terminate) return;
    // 0047772e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047772f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_477730(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477730  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00477731  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00477732  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00477734  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00477736  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00477738  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
    // 0047773b  29d3                   -sub ebx, edx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0047773d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047773f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00477741  e876ffffff             -call 0x4776bc
    cpu.esp -= 4;
    sub_4776bc(app, cpu);
    if (cpu.terminate) return;
    // 00477746  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477747  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477748  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47774c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047774c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047774d  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0047774f  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
    // 00477752  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00477754  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00477756  e861ffffff             -call 0x4776bc
    cpu.esp -= 4;
    sub_4776bc(app, cpu);
    if (cpu.terminate) return;
    // 0047775b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047775c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_477760(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477760  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00477761  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00477762  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00477763  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00477764  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00477766  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00477768  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0047776a  b91c844c00             -mov ecx, 0x4c841c
    cpu.ecx = 5014556 /*0x4c841c*/;
    // 0047776f  e8a8b40100             -call 0x492c1c
    cpu.esp -= 4;
    sub_492c1c(app, cpu);
    if (cpu.terminate) return;
    // 00477774  6681660c00f0           -and word ptr [esi + 0xc], 0xf000
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(12) /* 0xc */) &= x86::reg16(x86::sreg16(61440 /*0xf000*/));
    // 0047777a  81e7ff0f0000           -and edi, 0xfff
    cpu.edi &= x86::reg32(x86::sreg32(4095 /*0xfff*/));
    // 00477780  097e0c                 -or dword ptr [esi + 0xc], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) |= x86::reg32(x86::sreg32(cpu.edi));
    // 00477783  668b5e0e               -mov bx, word ptr [esi + 0xe]
    cpu.bx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(14) /* 0xe */);
    // 00477787  81e300f0ffff           -and ebx, 0xfffff000
    cpu.ebx &= x86::reg32(x86::sreg32(4294963200 /*0xfffff000*/));
    // 0047778d  81e5ff0f0000           -and ebp, 0xfff
    cpu.ebp &= x86::reg32(x86::sreg32(4095 /*0xfff*/));
    // 00477793  66895e0e               -mov word ptr [esi + 0xe], bx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(14) /* 0xe */) = cpu.bx;
    // 00477797  c1e510                 -shl ebp, 0x10
    cpu.ebp <<= 16 /*0x10*/ % 32;
    // 0047779a  096e0c                 -or dword ptr [esi + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) |= x86::reg32(x86::sreg32(cpu.ebp));
    // 0047779d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047779e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047779f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004777a0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004777a1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4777a4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004777a4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004777a5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004777a6  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004777a9  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004777ac  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 004777af  c1e214                 -shl edx, 0x14
    cpu.edx <<= 20 /*0x14*/ % 32;
    // 004777b2  c1fb14                 -sar ebx, 0x14
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (20 /*0x14*/ % 32));
    // 004777b5  c1fa14                 -sar edx, 0x14
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (20 /*0x14*/ % 32));
    // 004777b8  e8a3ffffff             -call 0x477760
    cpu.esp -= 4;
    sub_477760(app, cpu);
    if (cpu.terminate) return;
    // 004777bd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004777be  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004777bf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4777c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004777c0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004777c1  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004777c4  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004777c7  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004777c9  8b4806                 -mov ecx, dword ptr [eax + 6]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 004777cc  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004777cf  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004777d1  e88affffff             -call 0x477760
    cpu.esp -= 4;
    sub_477760(app, cpu);
    if (cpu.terminate) return;
    // 004777d6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004777d7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4777d8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004777d8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004777d9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004777da  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004777dd  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004777e0  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 004777e3  c1e214                 -shl edx, 0x14
    cpu.edx <<= 20 /*0x14*/ % 32;
    // 004777e6  c1fb14                 -sar ebx, 0x14
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (20 /*0x14*/ % 32));
    // 004777e9  c1fa14                 -sar edx, 0x14
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (20 /*0x14*/ % 32));
    // 004777ec  e86fffffff             -call 0x477760
    cpu.esp -= 4;
    sub_477760(app, cpu);
    if (cpu.terminate) return;
    // 004777f1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004777f2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004777f3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4777f4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004777f4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004777f5  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004777f8  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004777fb  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004777fd  8b4806                 -mov ecx, dword ptr [eax + 6]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 00477800  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00477803  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00477805  e856ffffff             -call 0x477760
    cpu.esp -= 4;
    sub_477760(app, cpu);
    if (cpu.terminate) return;
    // 0047780a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047780b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_477810(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477810  d1fb                   +sar ebx, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.ebx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 00477812  e90dba0100             -jmp 0x493224
    return sub_493224(app, cpu);
}

/* align: skip 0x90 */
void Application::sub_477818(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477818  01db                   +add ebx, ebx
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
    // 0047781a  e905ba0100             -jmp 0x493224
    return sub_493224(app, cpu);
}

/* align: skip 0x90 */
void Application::sub_477820(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477820  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00477821  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00477823  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 0047782a  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047782c  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047782e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00477830  e8efb90100             -call 0x493224
    cpu.esp -= 4;
    sub_493224(app, cpu);
    if (cpu.terminate) return;
    // 00477835  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477836  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_477838(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477838  c1e302                 +shl ebx, 2
    {
        x86::reg8 tmp = 2 /*0x2*/ % 32;
        x86::reg32& op = cpu.ebx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0047783b  e9e4b90100             -jmp 0x493224
    return sub_493224(app, cpu);
}

/* align: skip  */
void Application::sub_477840(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477840  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00477841  b940844c00             -mov ecx, 0x4c8440
    cpu.ecx = 5014592 /*0x4c8440*/;
    // 00477846  e8d1b30100             -call 0x492c1c
    cpu.esp -= 4;
    sub_492c1c(app, cpu);
    if (cpu.terminate) return;
    // 0047784b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047784c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_477850(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477850  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00477851  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00477852  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00477853  b940844c00             -mov ecx, 0x4c8440
    cpu.ecx = 5014592 /*0x4c8440*/;
    // 00477858  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0047785b  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0047785e  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 00477861  c1e214                 -shl edx, 0x14
    cpu.edx <<= 20 /*0x14*/ % 32;
    // 00477864  c1fb14                 -sar ebx, 0x14
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (20 /*0x14*/ % 32));
    // 00477867  c1fa14                 -sar edx, 0x14
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (20 /*0x14*/ % 32));
    // 0047786a  e8adb30100             -call 0x492c1c
    cpu.esp -= 4;
    sub_492c1c(app, cpu);
    if (cpu.terminate) return;
    // 0047786f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477870  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477871  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477872  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_477874(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477874  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00477875  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00477878  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0047787b  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047787d  8b4806                 -mov ecx, dword ptr [eax + 6]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 00477880  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00477883  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00477885  b940844c00             -mov ecx, 0x4c8440
    cpu.ecx = 5014592 /*0x4c8440*/;
    // 0047788a  e88db30100             -call 0x492c1c
    cpu.esp -= 4;
    sub_492c1c(app, cpu);
    if (cpu.terminate) return;
    // 0047788f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477890  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_477894(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477894  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00477895  b940844c00             -mov ecx, 0x4c8440
    cpu.ecx = 5014592 /*0x4c8440*/;
    // 0047789a  e87db30100             -call 0x492c1c
    cpu.esp -= 4;
    sub_492c1c(app, cpu);
    if (cpu.terminate) return;
    // 0047789f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004778a0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4778a4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004778a4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004778a5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004778a6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004778a7  b940844c00             -mov ecx, 0x4c8440
    cpu.ecx = 5014592 /*0x4c8440*/;
    // 004778ac  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004778af  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004778b2  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 004778b5  c1e214                 -shl edx, 0x14
    cpu.edx <<= 20 /*0x14*/ % 32;
    // 004778b8  c1fb14                 -sar ebx, 0x14
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (20 /*0x14*/ % 32));
    // 004778bb  c1fa14                 -sar edx, 0x14
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (20 /*0x14*/ % 32));
    // 004778be  e859b30100             -call 0x492c1c
    cpu.esp -= 4;
    sub_492c1c(app, cpu);
    if (cpu.terminate) return;
    // 004778c3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004778c4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004778c5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004778c6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4778c8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004778c8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004778c9  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004778cc  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004778cf  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004778d1  8b4806                 -mov ecx, dword ptr [eax + 6]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 004778d4  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004778d7  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004778d9  b940844c00             -mov ecx, 0x4c8440
    cpu.ecx = 5014592 /*0x4c8440*/;
    // 004778de  e839b30100             -call 0x492c1c
    cpu.esp -= 4;
    sub_492c1c(app, cpu);
    if (cpu.terminate) return;
    // 004778e3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004778e4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4778f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004778f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004778f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004778f2  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004778f4  39d0                   +cmp eax, edx
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
    // 004778f6  746c                   -je 0x477964
    if (cpu.flags.zf)
    {
        goto L_0x00477964;
    }
L_0x004778f8:
    // 004778f8  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004778fa  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004778fc  39c1                   +cmp ecx, eax
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
    // 004778fe  7569                   -jne 0x477969
    if (!cpu.flags.zf)
    {
        goto L_0x00477969;
    }
    // 00477900  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00477902  05fffefefe             -add eax, 0xfefefeff
    (cpu.eax) += x86::reg32(x86::sreg32(4278124287 /*0xfefefeff*/));
    // 00477907  21c8                   -and eax, ecx
    cpu.eax &= x86::reg32(x86::sreg32(cpu.ecx));
    // 00477909  2580808080             +and eax, 0x80808080
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(2155905152 /*0x80808080*/))));
    // 0047790e  7554                   -jne 0x477964
    if (!cpu.flags.zf)
    {
        goto L_0x00477964;
    }
    // 00477910  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 00477913  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00477916  39c1                   +cmp ecx, eax
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
    // 00477918  754f                   -jne 0x477969
    if (!cpu.flags.zf)
    {
        goto L_0x00477969;
    }
    // 0047791a  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0047791c  05fffefefe             -add eax, 0xfefefeff
    (cpu.eax) += x86::reg32(x86::sreg32(4278124287 /*0xfefefeff*/));
    // 00477921  21c8                   -and eax, ecx
    cpu.eax &= x86::reg32(x86::sreg32(cpu.ecx));
    // 00477923  2580808080             +and eax, 0x80808080
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(2155905152 /*0x80808080*/))));
    // 00477928  753a                   -jne 0x477964
    if (!cpu.flags.zf)
    {
        goto L_0x00477964;
    }
    // 0047792a  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0047792d  8b4a08                 -mov ecx, dword ptr [edx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00477930  39c1                   +cmp ecx, eax
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
    // 00477932  7535                   -jne 0x477969
    if (!cpu.flags.zf)
    {
        goto L_0x00477969;
    }
    // 00477934  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00477936  05fffefefe             -add eax, 0xfefefeff
    (cpu.eax) += x86::reg32(x86::sreg32(4278124287 /*0xfefefeff*/));
    // 0047793b  21c8                   -and eax, ecx
    cpu.eax &= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047793d  2580808080             +and eax, 0x80808080
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(2155905152 /*0x80808080*/))));
    // 00477942  7520                   -jne 0x477964
    if (!cpu.flags.zf)
    {
        goto L_0x00477964;
    }
    // 00477944  8b430c                 -mov eax, dword ptr [ebx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 00477947  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0047794a  39c1                   +cmp ecx, eax
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
    // 0047794c  751b                   -jne 0x477969
    if (!cpu.flags.zf)
    {
        goto L_0x00477969;
    }
    // 0047794e  83c310                 -add ebx, 0x10
    (cpu.ebx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00477951  83c210                 -add edx, 0x10
    (cpu.edx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00477954  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00477956  05fffefefe             -add eax, 0xfefefeff
    (cpu.eax) += x86::reg32(x86::sreg32(4278124287 /*0xfefefeff*/));
    // 0047795b  21c8                   -and eax, ecx
    cpu.eax &= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047795d  2580808080             +and eax, 0x80808080
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(2155905152 /*0x80808080*/))));
    // 00477962  7494                   -je 0x4778f8
    if (cpu.flags.zf)
    {
        goto L_0x004778f8;
    }
L_0x00477964:
    // 00477964  29c0                   -sub eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00477966  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477967  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477968  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00477969:
    // 00477969  38c8                   +cmp al, cl
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
    // 0047796b  751d                   -jne 0x47798a
    if (!cpu.flags.zf)
    {
        goto L_0x0047798a;
    }
    // 0047796d  3c00                   +cmp al, 0
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
    // 0047796f  74f3                   -je 0x477964
    if (cpu.flags.zf)
    {
        goto L_0x00477964;
    }
    // 00477971  38ec                   +cmp ah, ch
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.ch));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00477973  7515                   -jne 0x47798a
    if (!cpu.flags.zf)
    {
        goto L_0x0047798a;
    }
    // 00477975  80fc00                 +cmp ah, 0
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00477978  74ea                   -je 0x477964
    if (cpu.flags.zf)
    {
        goto L_0x00477964;
    }
    // 0047797a  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 0047797d  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 00477980  38c8                   +cmp al, cl
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
    // 00477982  7506                   -jne 0x47798a
    if (!cpu.flags.zf)
    {
        goto L_0x0047798a;
    }
    // 00477984  3c00                   +cmp al, 0
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
    // 00477986  74dc                   -je 0x477964
    if (cpu.flags.zf)
    {
        goto L_0x00477964;
    }
    // 00477988  38ec                   +cmp ah, ch
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.ch));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
L_0x0047798a:
    // 0047798a  19c0                   -sbb eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 0047798c  0c01                   -or al, 1
    cpu.al |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 0047798e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047798f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477990  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4779a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004779a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004779a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004779a2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004779a3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004779a4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004779a5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004779a6  2eff15f4544b00         -call dword ptr cs:[0x4b54f4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936948) /* 0x4b54f4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004779ad  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004779af  e818750000             -call 0x47eecc
    cpu.esp -= 4;
    sub_47eecc(app, cpu);
    if (cpu.terminate) return;
    // 004779b4  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004779b6  a308b05100             -mov dword ptr [0x51b008], eax
    app->getMemory<x86::reg32>(x86::reg32(5353480) /* 0x51b008 */) = cpu.eax;
    // 004779bb  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x004779bd:
    // 004779bd  a108b05100             -mov eax, dword ptr [0x51b008]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5353480) /* 0x51b008 */);
    // 004779c2  e855750000             -call 0x47ef1c
    cpu.esp -= 4;
    sub_47ef1c(app, cpu);
    if (cpu.terminate) return;
    // 004779c7  3b3d00b05100           +cmp edi, dword ptr [0x51b000]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5353472) /* 0x51b000 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004779cd  7463                   -je 0x477a32
    if (cpu.flags.zf)
    {
        goto L_0x00477a32;
    }
    // 004779cf  ff0524b05100           -inc dword ptr [0x51b024]
    (app->getMemory<x86::reg32>(x86::reg32(5353508) /* 0x51b024 */))++;
    // 004779d5  ff0520b05100           -inc dword ptr [0x51b020]
    (app->getMemory<x86::reg32>(x86::reg32(5353504) /* 0x51b020 */))++;
    // 004779db  2eff15f4544b00         -call dword ptr cs:[0x4b54f4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936948) /* 0x4b54f4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004779e2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004779e4  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004779e6  69d2a9040000           -imul edx, edx, 0x4a9
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(1193 /*0x4a9*/)));
    // 004779ec  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004779ee  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004779f0  81fbffff0000           +cmp ebx, 0xffff
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65535 /*0xffff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004779f6  7e11                   -jle 0x477a09
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00477a09;
    }
    // 004779f8  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004779fa  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004779fd  010504b05100           -add dword ptr [0x51b004], eax
    (app->getMemory<x86::reg32>(x86::reg32(5353476) /* 0x51b004 */)) += x86::reg32(x86::sreg32(cpu.eax));
    // 00477a03  81e3ffff0000           -and ebx, 0xffff
    cpu.ebx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
L_0x00477a09:
    // 00477a09  8b2db0af5100           -mov ebp, dword ptr [0x51afb0]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5353392) /* 0x51afb0 */);
    // 00477a0f  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00477a11  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00477a13  39ef                   +cmp edi, ebp
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
    // 00477a15  74a6                   -je 0x4779bd
    if (cpu.flags.zf)
    {
        goto L_0x004779bd;
    }
L_0x00477a17:
    // 00477a17  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00477a19  41                     -inc ecx
    (cpu.ecx)++;
    // 00477a1a  ff90b0af5100           -call dword ptr [eax + 0x51afb0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5353392) /* 0x51afb0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00477a20  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00477a23  83f908                 +cmp ecx, 8
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
    // 00477a26  7395                   -jae 0x4779bd
    if (!cpu.flags.cf)
    {
        goto L_0x004779bd;
    }
    // 00477a28  3bbab0af5100           +cmp edi, dword ptr [edx + 0x51afb0]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5353392) /* 0x51afb0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00477a2e  75e7                   -jne 0x477a17
    if (!cpu.flags.zf)
    {
        goto L_0x00477a17;
    }
    // 00477a30  eb8b                   -jmp 0x4779bd
    goto L_0x004779bd;
L_0x00477a32:
    // 00477a32  a108b05100             -mov eax, dword ptr [0x51b008]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5353480) /* 0x51b008 */);
    // 00477a37  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00477a39  e86a750000             -call 0x47efa8
    cpu.esp -= 4;
    sub_47efa8(app, cpu);
    if (cpu.terminate) return;
    // 00477a3e  891508b05100           -mov dword ptr [0x51b008], edx
    app->getMemory<x86::reg32>(x86::reg32(5353480) /* 0x51b008 */) = cpu.edx;
    // 00477a44  891534824c00           -mov dword ptr [0x4c8234], edx
    app->getMemory<x86::reg32>(x86::reg32(5014068) /* 0x4c8234 */) = cpu.edx;
    // 00477a4a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477a4b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477a4c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477a4d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477a4e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477a4f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477a50  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_477a54(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477a54  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00477a55  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00477a56  e871740000             -call 0x47eecc
    cpu.esp -= 4;
    sub_47eecc(app, cpu);
    if (cpu.terminate) return;
    // 00477a5b  8b15dcaf5100           -mov edx, dword ptr [0x51afdc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5353436) /* 0x51afdc */);
    // 00477a61  a3fcaf5100             -mov dword ptr [0x51affc], eax
    app->getMemory<x86::reg32>(x86::reg32(5353468) /* 0x51affc */) = cpu.eax;
    // 00477a66  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00477a68  741a                   -je 0x477a84
    if (cpu.flags.zf)
    {
        goto L_0x00477a84;
    }
L_0x00477a6a:
    // 00477a6a  ff15dcaf5100           -call dword ptr [0x51afdc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5353436) /* 0x51afdc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00477a70  a1fcaf5100             -mov eax, dword ptr [0x51affc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5353468) /* 0x51affc */);
    // 00477a75  e8a2740000             -call 0x47ef1c
    cpu.esp -= 4;
    sub_47ef1c(app, cpu);
    if (cpu.terminate) return;
    // 00477a7a  833ddcaf510000         +cmp dword ptr [0x51afdc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5353436) /* 0x51afdc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00477a81  75e7                   -jne 0x477a6a
    if (!cpu.flags.zf)
    {
        goto L_0x00477a6a;
    }
    // 00477a83  90                     -nop 
    ;
L_0x00477a84:
    // 00477a84  a1fcaf5100             -mov eax, dword ptr [0x51affc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5353468) /* 0x51affc */);
    // 00477a89  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00477a8b  e818750000             -call 0x47efa8
    cpu.esp -= 4;
    sub_47efa8(app, cpu);
    if (cpu.terminate) return;
    // 00477a90  891dfcaf5100           -mov dword ptr [0x51affc], ebx
    app->getMemory<x86::reg32>(x86::reg32(5353468) /* 0x51affc */) = cpu.ebx;
    // 00477a96  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477a97  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477a98  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_477a9c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477a9c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00477a9d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00477a9e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00477a9f  a3dcaf5100             -mov dword ptr [0x51afdc], eax
    app->getMemory<x86::reg32>(x86::reg32(5353436) /* 0x51afdc */) = cpu.eax;
    // 00477aa4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00477aa6  740a                   -je 0x477ab2
    if (cpu.flags.zf)
    {
        goto L_0x00477ab2;
    }
    // 00477aa8  8b15fcaf5100           -mov edx, dword ptr [0x51affc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5353468) /* 0x51affc */);
    // 00477aae  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00477ab0  741a                   -je 0x477acc
    if (cpu.flags.zf)
    {
        goto L_0x00477acc;
    }
L_0x00477ab2:
    // 00477ab2  833ddcaf510000         +cmp dword ptr [0x51afdc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5353436) /* 0x51afdc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00477ab9  750d                   -jne 0x477ac8
    if (!cpu.flags.zf)
    {
        goto L_0x00477ac8;
    }
    // 00477abb  8b1dfcaf5100           -mov ebx, dword ptr [0x51affc]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5353468) /* 0x51affc */);
    // 00477ac1  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00477ac3  753e                   -jne 0x477b03
    if (!cpu.flags.zf)
    {
        goto L_0x00477b03;
    }
    // 00477ac5  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x00477ac8:
    // 00477ac8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477ac9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477aca  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477acb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00477acc:
    // 00477acc  68e0af5100             -push 0x51afe0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5353440 /*0x51afe0*/;
    cpu.esp -= 4;
    // 00477ad1  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 00477ad6  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 00477adb  b8547a4700             -mov eax, 0x477a54
    cpu.eax = 4684372 /*0x477a54*/;
    // 00477ae0  e8bb700000             -call 0x47eba0
    cpu.esp -= 4;
    sub_47eba0(app, cpu);
    if (cpu.terminate) return;
    // 00477ae5  833dfcaf510000         +cmp dword ptr [0x51affc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5353468) /* 0x51affc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00477aec  75da                   -jne 0x477ac8
    if (!cpu.flags.zf)
    {
        goto L_0x00477ac8;
    }
    // 00477aee  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00477af0:
    // 00477af0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00477af2  e865710000             -call 0x47ec5c
    cpu.esp -= 4;
    sub_47ec5c(app, cpu);
    if (cpu.terminate) return;
    // 00477af7  3b15fcaf5100           +cmp edx, dword ptr [0x51affc]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5353468) /* 0x51affc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00477afd  74f1                   -je 0x477af0
    if (cpu.flags.zf)
    {
        goto L_0x00477af0;
    }
    // 00477aff  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477b00  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477b01  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477b02  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00477b03:
    // 00477b03  b8e0af5100             -mov eax, 0x51afe0
    cpu.eax = 5353440 /*0x51afe0*/;
    // 00477b08  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00477b0a  e8d1730000             -call 0x47eee0
    cpu.esp -= 4;
    sub_47eee0(app, cpu);
    if (cpu.terminate) return;
    // 00477b0f  833dfcaf510000         +cmp dword ptr [0x51affc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5353468) /* 0x51affc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00477b16  74b0                   -je 0x477ac8
    if (cpu.flags.zf)
    {
        goto L_0x00477ac8;
    }
    // 00477b18  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00477b1a:
    // 00477b1a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00477b1c  e83b710000             -call 0x47ec5c
    cpu.esp -= 4;
    sub_47ec5c(app, cpu);
    if (cpu.terminate) return;
    // 00477b21  3b15fcaf5100           +cmp edx, dword ptr [0x51affc]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5353468) /* 0x51affc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00477b27  75f1                   -jne 0x477b1a
    if (!cpu.flags.zf)
    {
        goto L_0x00477b1a;
    }
    // 00477b29  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477b2a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477b2b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477b2c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_477b30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477b30  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00477b31  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00477b33:
    // 00477b33  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00477b36  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00477b38  8990acaf5100           -mov dword ptr [eax + 0x51afac], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5353388) /* 0x51afac */) = cpu.edx;
    // 00477b3e  83f820                 +cmp eax, 0x20
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
    // 00477b41  75f0                   -jne 0x477b33
    if (!cpu.flags.zf)
    {
        goto L_0x00477b33;
    }
    // 00477b43  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477b44  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_477b48(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477b48  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00477b49  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00477b4a  a1d0af5100             -mov eax, dword ptr [0x51afd0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5353424) /* 0x51afd0 */);
    // 00477b4f  8b15f8af5100           -mov edx, dword ptr [0x51aff8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5353464) /* 0x51aff8 */);
    // 00477b55  8b0dd8af5100           -mov ecx, dword ptr [0x51afd8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5353432) /* 0x51afd8 */);
    // 00477b5b  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00477b5d  8b1d00b05100           -mov ebx, dword ptr [0x51b000]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5353472) /* 0x51b000 */);
    // 00477b63  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00477b65  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00477b68  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00477b6e  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00477b70  8915f8af5100           -mov dword ptr [0x51aff8], edx
    app->getMemory<x86::reg32>(x86::reg32(5353464) /* 0x51aff8 */) = cpu.edx;
    // 00477b76  890dd8af5100           -mov dword ptr [0x51afd8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5353432) /* 0x51afd8 */) = cpu.ecx;
    // 00477b7c  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00477b7e  753f                   -jne 0x477bbf
    if (!cpu.flags.zf)
    {
        goto L_0x00477bbf;
    }
L_0x00477b80:
    // 00477b80  8b0dfcaf5100           -mov ecx, dword ptr [0x51affc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5353468) /* 0x51affc */);
    // 00477b86  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00477b88  740c                   -je 0x477b96
    if (cpu.flags.zf)
    {
        goto L_0x00477b96;
    }
    // 00477b8a  b8e0af5100             -mov eax, 0x51afe0
    cpu.eax = 5353440 /*0x51afe0*/;
    // 00477b8f  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00477b91  e84a730000             -call 0x47eee0
    cpu.esp -= 4;
    sub_47eee0(app, cpu);
    if (cpu.terminate) return;
L_0x00477b96:
    // 00477b96  8b1d08b05100           -mov ebx, dword ptr [0x51b008]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5353480) /* 0x51b008 */);
    // 00477b9c  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00477b9e  7415                   -je 0x477bb5
    if (cpu.flags.zf)
    {
        goto L_0x00477bb5;
    }
    // 00477ba0  833d64844c0000         +cmp dword ptr [0x4c8464], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5014628) /* 0x4c8464 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00477ba7  750c                   -jne 0x477bb5
    if (!cpu.flags.zf)
    {
        goto L_0x00477bb5;
    }
    // 00477ba9  b80cb05100             -mov eax, 0x51b00c
    cpu.eax = 5353484 /*0x51b00c*/;
    // 00477bae  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00477bb0  e82b730000             -call 0x47eee0
    cpu.esp -= 4;
    sub_47eee0(app, cpu);
    if (cpu.terminate) return;
L_0x00477bb5:
    // 00477bb5  e8c6b90100             -call 0x493580
    cpu.esp -= 4;
    sub_493580(app, cpu);
    if (cpu.terminate) return;
    // 00477bba  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477bbb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477bbc  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
L_0x00477bbf:
    // 00477bbf  2eff15f4544b00         -call dword ptr cs:[0x4b54f4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936948) /* 0x4b54f4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00477bc6  8b15d8af5100           -mov edx, dword ptr [0x51afd8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5353432) /* 0x51afd8 */);
    // 00477bcc  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00477bce  8d42ff                 -lea eax, [edx - 1]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 00477bd1  83f801                 +cmp eax, 1
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
    // 00477bd4  7d28                   -jge 0x477bfe
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00477bfe;
    }
    // 00477bd6  3d18fcffff             +cmp eax, 0xfffffc18
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4294966296 /*0xfffffc18*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00477bdb  7d1c                   -jge 0x477bf9
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00477bf9;
    }
    // 00477bdd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00477bde  2eff15f4544b00         -call dword ptr cs:[0x4b54f4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936948) /* 0x4b54f4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00477be5  8b3570844c00           -mov esi, dword ptr [0x4c8470]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5014640) /* 0x4c8470 */);
    // 00477beb  40                     -inc eax
    (cpu.eax)++;
    // 00477bec  46                     -inc esi
    (cpu.esi)++;
    // 00477bed  a3d8af5100             -mov dword ptr [0x51afd8], eax
    app->getMemory<x86::reg32>(x86::reg32(5353432) /* 0x51afd8 */) = cpu.eax;
    // 00477bf2  893570844c00           -mov dword ptr [0x4c8470], esi
    app->getMemory<x86::reg32>(x86::reg32(5014640) /* 0x4c8470 */) = cpu.esi;
    // 00477bf8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00477bf9:
    // 00477bf9  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00477bfe:
    // 00477bfe  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00477c00  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00477c02  68487b4700             -push 0x477b48
    app->getMemory<x86::reg32>(cpu.esp-4) = 4684616 /*0x477b48*/;
    cpu.esp -= 4;
    // 00477c07  8b3dd4af5100           -mov edi, dword ptr [0x51afd4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5353428) /* 0x51afd4 */);
    // 00477c0d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00477c0e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00477c0f  2eff1500564b00         -call dword ptr cs:[0x4b5600]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4937216) /* 0x4b5600 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00477c16  a3f4af5100             -mov dword ptr [0x51aff4], eax
    app->getMemory<x86::reg32>(x86::reg32(5353460) /* 0x51aff4 */) = cpu.eax;
    // 00477c1b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00477c1d  0f855dffffff           -jne 0x477b80
    if (!cpu.flags.zf)
    {
        goto L_0x00477b80;
    }
    // 00477c23  8b15d4af5100           -mov edx, dword ptr [0x51afd4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5353428) /* 0x51afd4 */);
    // 00477c29  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00477c2a  a334824c00             -mov dword ptr [0x4c8234], eax
    app->getMemory<x86::reg32>(x86::reg32(5014068) /* 0x4c8234 */) = cpu.eax;
    // 00477c2f  a300b05100             -mov dword ptr [0x51b000], eax
    app->getMemory<x86::reg32>(x86::reg32(5353472) /* 0x51b000 */) = cpu.eax;
    // 00477c34  2eff15f4554b00         -call dword ptr cs:[0x4b55f4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4937204) /* 0x4b55f4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00477c3b  e940ffffff             -jmp 0x477b80
    goto L_0x00477b80;
}

/* align: skip  */
void Application::sub_477c40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477c40  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00477c41  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00477c42  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00477c43  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00477c44  8b3564844c00           -mov esi, dword ptr [0x4c8464]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5014628) /* 0x4c8464 */);
    // 00477c4a  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00477c4c  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 00477c51  46                     -inc esi
    (cpu.esi)++;
    // 00477c52  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00477c54  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00477c56:
    // 00477c56  83b8b0af510000         +cmp dword ptr [eax + 0x51afb0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5353392) /* 0x51afb0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00477c5d  7504                   -jne 0x477c63
    if (!cpu.flags.zf)
    {
        goto L_0x00477c63;
    }
    // 00477c5f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00477c61  7c29                   -jl 0x477c8c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00477c8c;
    }
L_0x00477c63:
    // 00477c63  3b98b0af5100           +cmp ebx, dword ptr [eax + 0x51afb0]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5353392) /* 0x51afb0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00477c69  7415                   -je 0x477c80
    if (cpu.flags.zf)
    {
        goto L_0x00477c80;
    }
L_0x00477c6b:
    // 00477c6b  42                     -inc edx
    (cpu.edx)++;
    // 00477c6c  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00477c6f  83fa08                 +cmp edx, 8
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00477c72  7ce2                   -jl 0x477c56
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00477c56;
    }
    // 00477c74  83f9ff                 +cmp ecx, -1
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
    // 00477c77  7407                   -je 0x477c80
    if (cpu.flags.zf)
    {
        goto L_0x00477c80;
    }
    // 00477c79  891c8db0af5100         -mov dword ptr [ecx*4 + 0x51afb0], ebx
    app->getMemory<x86::reg32>(x86::reg32(5353392) /* 0x51afb0 */ + cpu.ecx * 4) = cpu.ebx;
L_0x00477c80:
    // 00477c80  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00477c81  893564844c00           -mov dword ptr [0x4c8464], esi
    app->getMemory<x86::reg32>(x86::reg32(5014628) /* 0x4c8464 */) = cpu.esi;
    // 00477c87  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477c88  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477c89  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477c8a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477c8b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00477c8c:
    // 00477c8c  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00477c8e  ebdb                   -jmp 0x477c6b
    goto L_0x00477c6b;
}

/* align: skip  */
void Application::sub_477c90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477c90  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00477c91  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00477c92  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00477c93  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00477c94  8b1d64844c00           -mov ebx, dword ptr [0x4c8464]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5014628) /* 0x4c8464 */);
    // 00477c9a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00477c9c  8b35b0af5100           -mov esi, dword ptr [0x51afb0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5353392) /* 0x51afb0 */);
    // 00477ca2  43                     -inc ebx
    (cpu.ebx)++;
    // 00477ca3  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00477ca5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00477ca7  39f1                   +cmp ecx, esi
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
    // 00477ca9  7411                   -je 0x477cbc
    if (cpu.flags.zf)
    {
        goto L_0x00477cbc;
    }
L_0x00477cab:
    // 00477cab  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00477cae  42                     -inc edx
    (cpu.edx)++;
    // 00477caf  83f820                 +cmp eax, 0x20
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
    // 00477cb2  7d08                   -jge 0x477cbc
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00477cbc;
    }
    // 00477cb4  3b88b0af5100           +cmp ecx, dword ptr [eax + 0x51afb0]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5353392) /* 0x51afb0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00477cba  75ef                   -jne 0x477cab
    if (!cpu.flags.zf)
    {
        goto L_0x00477cab;
    }
L_0x00477cbc:
    // 00477cbc  83fa08                 +cmp edx, 8
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00477cbf  7d32                   -jge 0x477cf3
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00477cf3;
    }
    // 00477cc1  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00477cc8  3b88b0af5100           +cmp ecx, dword ptr [eax + 0x51afb0]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5353392) /* 0x51afb0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00477cce  7523                   -jne 0x477cf3
    if (!cpu.flags.zf)
    {
        goto L_0x00477cf3;
    }
    // 00477cd0  83fa07                 +cmp edx, 7
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00477cd3  7d17                   -jge 0x477cec
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00477cec;
    }
L_0x00477cd5:
    // 00477cd5  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00477cd8  8b90b0af5100           -mov edx, dword ptr [eax + 0x51afb0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5353392) /* 0x51afb0 */);
    // 00477cde  8990acaf5100           -mov dword ptr [eax + 0x51afac], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5353388) /* 0x51afac */) = cpu.edx;
    // 00477ce4  83f81c                 +cmp eax, 0x1c
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(28 /*0x1c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00477ce7  7cec                   -jl 0x477cd5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00477cd5;
    }
    // 00477ce9  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x00477cec:
    // 00477cec  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00477cee  a3ccaf5100             -mov dword ptr [0x51afcc], eax
    app->getMemory<x86::reg32>(x86::reg32(5353420) /* 0x51afcc */) = cpu.eax;
L_0x00477cf3:
    // 00477cf3  4b                     -dec ebx
    (cpu.ebx)--;
    // 00477cf4  891d64844c00           -mov dword ptr [0x4c8464], ebx
    app->getMemory<x86::reg32>(x86::reg32(5014628) /* 0x4c8464 */) = cpu.ebx;
    // 00477cfa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477cfb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477cfc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477cfd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477cfe  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_477d00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477d00  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00477d01  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00477d02  8b0db0af5100           -mov ecx, dword ptr [0x51afb0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5353392) /* 0x51afb0 */);
    // 00477d08  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00477d0a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00477d0c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00477d0e  7412                   -je 0x477d22
    if (cpu.flags.zf)
    {
        goto L_0x00477d22;
    }
L_0x00477d10:
    // 00477d10  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00477d13  42                     -inc edx
    (cpu.edx)++;
    // 00477d14  83f820                 +cmp eax, 0x20
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
    // 00477d17  7d09                   -jge 0x477d22
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00477d22;
    }
    // 00477d19  83b8b0af510000         +cmp dword ptr [eax + 0x51afb0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5353392) /* 0x51afb0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00477d20  75ee                   -jne 0x477d10
    if (!cpu.flags.zf)
    {
        goto L_0x00477d10;
    }
L_0x00477d22:
    // 00477d22  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00477d24  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477d25  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477d26  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_477d28(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477d28  ff0564844c00           -inc dword ptr [0x4c8464]
    (app->getMemory<x86::reg32>(x86::reg32(5014628) /* 0x4c8464 */))++;
    // 00477d2e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_477d30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477d30  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00477d31  8b1564844c00           -mov edx, dword ptr [0x4c8464]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5014628) /* 0x4c8464 */);
    // 00477d37  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00477d39  7502                   -jne 0x477d3d
    if (!cpu.flags.zf)
    {
        goto L_0x00477d3d;
    }
    // 00477d3b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477d3c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00477d3d:
    // 00477d3d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00477d3e  8d4aff                 -lea ecx, [edx - 1]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 00477d41  890d64844c00           -mov dword ptr [0x4c8464], ecx
    app->getMemory<x86::reg32>(x86::reg32(5014628) /* 0x4c8464 */) = cpu.ecx;
    // 00477d47  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477d48  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477d49  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_477d4c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477d4c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00477d4d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00477d4e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00477d4f  833d00b0510000         +cmp dword ptr [0x51b000], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5353472) /* 0x51b000 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00477d56  7448                   -je 0x477da0
    if (cpu.flags.zf)
    {
        goto L_0x00477da0;
    }
    // 00477d58  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00477d59  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00477d5b  8b35f4af5100           -mov esi, dword ptr [0x51aff4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5353460) /* 0x51aff4 */);
    // 00477d61  890d34824c00           -mov dword ptr [0x4c8234], ecx
    app->getMemory<x86::reg32>(x86::reg32(5014068) /* 0x4c8234 */) = cpu.ecx;
    // 00477d67  890d00b05100           -mov dword ptr [0x51b000], ecx
    app->getMemory<x86::reg32>(x86::reg32(5353472) /* 0x51b000 */) = cpu.ecx;
    // 00477d6d  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00477d6f  7553                   -jne 0x477dc4
    if (!cpu.flags.zf)
    {
        goto L_0x00477dc4;
    }
L_0x00477d71:
    // 00477d71  8b2dd4af5100           -mov ebp, dword ptr [0x51afd4]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5353428) /* 0x51afd4 */);
    // 00477d77  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00477d78  2eff15f4554b00         -call dword ptr cs:[0x4b55f4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4937204) /* 0x4b55f4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00477d7f  a108b05100             -mov eax, dword ptr [0x51b008]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5353480) /* 0x51b008 */);
    // 00477d84  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00477d86  7546                   -jne 0x477dce
    if (!cpu.flags.zf)
    {
        goto L_0x00477dce;
    }
L_0x00477d88:
    // 00477d88  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00477d8d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00477d8e:
    // 00477d8e  833df4af510000         +cmp dword ptr [0x51aff4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5353460) /* 0x51aff4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00477d95  7409                   -je 0x477da0
    if (cpu.flags.zf)
    {
        goto L_0x00477da0;
    }
    // 00477d97  833d08b0510000         +cmp dword ptr [0x51b008], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5353480) /* 0x51b008 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00477d9e  753c                   -jne 0x477ddc
    if (!cpu.flags.zf)
    {
        goto L_0x00477ddc;
    }
L_0x00477da0:
    // 00477da0  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 00477da2  8935f8af5100           -mov dword ptr [0x51aff8], esi
    app->getMemory<x86::reg32>(x86::reg32(5353464) /* 0x51aff8 */) = cpu.esi;
    // 00477da8  893564844c00           -mov dword ptr [0x4c8464], esi
    app->getMemory<x86::reg32>(x86::reg32(5014628) /* 0x4c8464 */) = cpu.esi;
    // 00477dae  8935d4af5100           -mov dword ptr [0x51afd4], esi
    app->getMemory<x86::reg32>(x86::reg32(5353428) /* 0x51afd4 */) = cpu.esi;
    // 00477db4  8935f4af5100           -mov dword ptr [0x51aff4], esi
    app->getMemory<x86::reg32>(x86::reg32(5353460) /* 0x51aff4 */) = cpu.esi;
    // 00477dba  893570824c00           -mov dword ptr [0x4c8270], esi
    app->getMemory<x86::reg32>(x86::reg32(5014128) /* 0x4c8270 */) = cpu.esi;
    // 00477dc0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477dc1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477dc2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477dc3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00477dc4:
    // 00477dc4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00477dc5  2eff15fc554b00         -call dword ptr cs:[0x4b55fc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4937212) /* 0x4b55fc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00477dcc  eba3                   -jmp 0x477d71
    goto L_0x00477d71;
L_0x00477dce:
    // 00477dce  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00477dd0  b80cb05100             -mov eax, 0x51b00c
    cpu.eax = 5353484 /*0x51b00c*/;
    // 00477dd5  e806710000             -call 0x47eee0
    cpu.esp -= 4;
    sub_47eee0(app, cpu);
    if (cpu.terminate) return;
    // 00477dda  ebac                   -jmp 0x477d88
    goto L_0x00477d88;
L_0x00477ddc:
    // 00477ddc  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00477dde  e8796e0000             -call 0x47ec5c
    cpu.esp -= 4;
    sub_47ec5c(app, cpu);
    if (cpu.terminate) return;
    // 00477de3  eba9                   -jmp 0x477d8e
    goto L_0x00477d8e;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_477de8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477de8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00477de9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00477dea  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00477deb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00477dec  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00477ded  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00477dee  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00477df1  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00477df3  e854ffffff             -call 0x477d4c
    cpu.esp -= 4;
    sub_477d4c(app, cpu);
    if (cpu.terminate) return;
    // 00477df8  83fe01                 +cmp esi, 1
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
    // 00477dfb  7d70                   -jge 0x477e6d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00477e6d;
    }
L_0x00477dfd:
    // 00477dfd  be64000000             -mov esi, 0x64
    cpu.esi = 100 /*0x64*/;
L_0x00477e02:
    // 00477e02  b80000e803             -mov eax, 0x3e80000
    cpu.eax = 65536000 /*0x3e80000*/;
    // 00477e07  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00477e09  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00477e0c  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00477e0e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00477e10  a3d0af5100             -mov dword ptr [0x51afd0], eax
    app->getMemory<x86::reg32>(x86::reg32(5353424) /* 0x51afd0 */) = cpu.eax;
    // 00477e15  8915f8af5100           -mov dword ptr [0x51aff8], edx
    app->getMemory<x86::reg32>(x86::reg32(5353464) /* 0x51aff8 */) = cpu.edx;
    // 00477e1b  891524b05100           -mov dword ptr [0x51b024], edx
    app->getMemory<x86::reg32>(x86::reg32(5353508) /* 0x51b024 */) = cpu.edx;
    // 00477e21  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 00477e23  891504b05100           -mov dword ptr [0x51b004], edx
    app->getMemory<x86::reg32>(x86::reg32(5353476) /* 0x51b004 */) = cpu.edx;
    // 00477e29  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00477e2d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00477e2e  2eff15f8554b00         -call dword ptr cs:[0x4b55f8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4937208) /* 0x4b55f8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00477e35  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00477e37  753e                   -jne 0x477e77
    if (!cpu.flags.zf)
    {
        goto L_0x00477e77;
    }
    // 00477e39  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 00477e3e  8b15d0af5100           -mov edx, dword ptr [0x51afd0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5353424) /* 0x51afd0 */);
    // 00477e44  893c24                 -mov dword ptr [esp], edi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edi;
    // 00477e47  897c2404               -mov dword ptr [esp + 4], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 00477e4b  893dd4af5100           -mov dword ptr [0x51afd4], edi
    app->getMemory<x86::reg32>(x86::reg32(5353428) /* 0x51afd4 */) = cpu.edi;
    // 00477e51  81fa00000100           +cmp edx, 0x10000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00477e57  732e                   -jae 0x477e87
    if (!cpu.flags.cf)
    {
        goto L_0x00477e87;
    }
L_0x00477e59:
    // 00477e59  a334824c00             -mov dword ptr [0x4c8234], eax
    app->getMemory<x86::reg32>(x86::reg32(5014068) /* 0x4c8234 */) = cpu.eax;
    // 00477e5e  a300b05100             -mov dword ptr [0x51b000], eax
    app->getMemory<x86::reg32>(x86::reg32(5353472) /* 0x51b000 */) = cpu.eax;
L_0x00477e63:
    // 00477e63  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00477e66  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477e67  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477e68  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477e69  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477e6a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477e6b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477e6c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00477e6d:
    // 00477e6d  81fe10270000           +cmp esi, 0x2710
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10000 /*0x2710*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00477e73  7f88                   -jg 0x477dfd
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00477dfd;
    }
    // 00477e75  eb8b                   -jmp 0x477e02
    goto L_0x00477e02;
L_0x00477e77:
    // 00477e77  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 00477e79  893d34824c00           -mov dword ptr [0x4c8234], edi
    app->getMemory<x86::reg32>(x86::reg32(5014068) /* 0x4c8234 */) = cpu.edi;
    // 00477e7f  893d00b05100           -mov dword ptr [0x51b000], edi
    app->getMemory<x86::reg32>(x86::reg32(5353472) /* 0x51b000 */) = cpu.edi;
    // 00477e85  ebdc                   -jmp 0x477e63
    goto L_0x00477e63;
L_0x00477e87:
    // 00477e87  680cb05100             -push 0x51b00c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5353484 /*0x51b00c*/;
    cpu.esp -= 4;
    // 00477e8c  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 00477e91  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 00477e96  b8a0794700             -mov eax, 0x4779a0
    cpu.eax = 4684192 /*0x4779a0*/;
    // 00477e9b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00477e9d  e8fe6c0000             -call 0x47eba0
    cpu.esp -= 4;
    sub_47eba0(app, cpu);
    if (cpu.terminate) return;
    // 00477ea2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00477ea4  74b3                   -je 0x477e59
    if (cpu.flags.zf)
    {
        goto L_0x00477e59;
    }
    // 00477ea6  8b0dd4af5100           -mov ecx, dword ptr [0x51afd4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5353428) /* 0x51afd4 */);
    // 00477eac  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00477ead  2eff15f0554b00         -call dword ptr cs:[0x4b55f0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4937200) /* 0x4b55f0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00477eb4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00477eb6  755e                   -jne 0x477f16
    if (!cpu.flags.zf)
    {
        goto L_0x00477f16;
    }
    // 00477eb8  b84c7d4700             -mov eax, 0x477d4c
    cpu.eax = 4685132 /*0x477d4c*/;
    // 00477ebd  e85a370100             -call 0x48b61c
    cpu.esp -= 4;
    sub_48b61c(app, cpu);
    if (cpu.terminate) return;
    // 00477ec2  893534824c00           -mov dword ptr [0x4c8234], esi
    app->getMemory<x86::reg32>(x86::reg32(5014068) /* 0x4c8234 */) = cpu.esi;
    // 00477ec8  893500b05100           -mov dword ptr [0x51b000], esi
    app->getMemory<x86::reg32>(x86::reg32(5353472) /* 0x51b000 */) = cpu.esi;
    // 00477ece  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00477ed0  756c                   -jne 0x477f3e
    if (!cpu.flags.zf)
    {
        goto L_0x00477f3e;
    }
L_0x00477ed2:
    // 00477ed2  a124b05100             -mov eax, dword ptr [0x51b024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5353508) /* 0x51b024 */);
    // 00477ed7  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00477ed9  2eff15f4544b00         -call dword ptr cs:[0x4b54f4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936948) /* 0x4b54f4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00477ee0  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00477ee2  b810270000             -mov eax, 0x2710
    cpu.eax = 10000 /*0x2710*/;
    // 00477ee7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00477ee9  8b3d34824c00           -mov edi, dword ptr [0x4c8234]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5014068) /* 0x4c8234 */);
    // 00477eef  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00477ef2  f7ff                   -idiv edi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.edi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00477ef4  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
L_0x00477ef6:
    // 00477ef6  2eff15f4544b00         -call dword ptr cs:[0x4b54f4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936948) /* 0x4b54f4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00477efd  39f0                   +cmp eax, esi
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
    // 00477eff  7362                   -jae 0x477f63
    if (!cpu.flags.cf)
    {
        goto L_0x00477f63;
    }
    // 00477f01  a124b05100             -mov eax, dword ptr [0x51b024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5353508) /* 0x51b024 */);
    // 00477f06  39c3                   +cmp ebx, eax
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
    // 00477f08  7559                   -jne 0x477f63
    if (!cpu.flags.zf)
    {
        goto L_0x00477f63;
    }
    // 00477f0a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00477f0f  e8486d0000             -call 0x47ec5c
    cpu.esp -= 4;
    sub_47ec5c(app, cpu);
    if (cpu.terminate) return;
    // 00477f14  ebe0                   -jmp 0x477ef6
    goto L_0x00477ef6;
L_0x00477f16:
    // 00477f16  b80cb05100             -mov eax, 0x51b00c
    cpu.eax = 5353484 /*0x51b00c*/;
    // 00477f1b  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00477f1d  8b1508b05100           -mov edx, dword ptr [0x51b008]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5353480) /* 0x51b008 */);
    // 00477f23  892d34824c00           -mov dword ptr [0x4c8234], ebp
    app->getMemory<x86::reg32>(x86::reg32(5014068) /* 0x4c8234 */) = cpu.ebp;
    // 00477f29  892d00b05100           -mov dword ptr [0x51b000], ebp
    app->getMemory<x86::reg32>(x86::reg32(5353472) /* 0x51b000 */) = cpu.ebp;
    // 00477f2f  e8ac6f0000             -call 0x47eee0
    cpu.esp -= 4;
    sub_47eee0(app, cpu);
    if (cpu.terminate) return;
    // 00477f34  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00477f37  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477f38  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477f39  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477f3a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477f3b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477f3c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477f3d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00477f3e:
    // 00477f3e  8b1df4af5100           -mov ebx, dword ptr [0x51aff4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5353460) /* 0x51aff4 */);
    // 00477f44  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00477f46  758a                   -jne 0x477ed2
    if (!cpu.flags.zf)
    {
        goto L_0x00477ed2;
    }
    // 00477f48  2eff15f4544b00         -call dword ptr cs:[0x4b54f4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936948) /* 0x4b54f4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00477f4f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00477f50  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00477f51  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00477f52  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00477f53  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00477f54  a3d8af5100             -mov dword ptr [0x51afd8], eax
    app->getMemory<x86::reg32>(x86::reg32(5353432) /* 0x51afd8 */) = cpu.eax;
    // 00477f59  e8eafbffff             -call 0x477b48
    cpu.esp -= 4;
    sub_477b48(app, cpu);
    if (cpu.terminate) return;
    // 00477f5e  e96fffffff             -jmp 0x477ed2
    goto L_0x00477ed2;
L_0x00477f63:
    // 00477f63  a124b05100             -mov eax, dword ptr [0x51b024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5353508) /* 0x51b024 */);
    // 00477f68  39c3                   +cmp ebx, eax
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
    // 00477f6a  7505                   -jne 0x477f71
    if (!cpu.flags.zf)
    {
        goto L_0x00477f71;
    }
    // 00477f6c  e8dbfdffff             -call 0x477d4c
    cpu.esp -= 4;
    sub_477d4c(app, cpu);
    if (cpu.terminate) return;
L_0x00477f71:
    // 00477f71  833d34824c0000         +cmp dword ptr [0x4c8234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5014068) /* 0x4c8234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00477f78  0f84e5feffff           -je 0x477e63
    if (cpu.flags.zf)
    {
        goto L_0x00477e63;
    }
    // 00477f7e  c70570824c00307b4700   -mov dword ptr [0x4c8270], 0x477b30
    app->getMemory<x86::reg32>(x86::reg32(5014128) /* 0x4c8270 */) = 4684592 /*0x477b30*/;
    // 00477f88  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00477f8b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477f8c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477f8d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477f8e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477f8f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477f90  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477f91  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_477fa0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477fa0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00477fa1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00477fa2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00477fa3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00477fa4  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00477fa7  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00477fa9  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00477fac  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00477fae  8b1d74844c00           -mov ebx, dword ptr [0x4c8474]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5014644) /* 0x4c8474 */);
    // 00477fb4  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 00477fb9  8d5301                 -lea edx, [ebx + 1]
    cpu.edx = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 00477fbc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00477fbe  891574844c00           -mov dword ptr [0x4c8474], edx
    app->getMemory<x86::reg32>(x86::reg32(5014644) /* 0x4c8474 */) = cpu.edx;
    // 00477fc4  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00477fc6:
    // 00477fc6  8baa28b05100           -mov ebp, dword ptr [edx + 0x51b028]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5353512) /* 0x51b028 */);
    // 00477fcc  39ee                   +cmp esi, ebp
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
    // 00477fce  751e                   -jne 0x477fee
    if (!cpu.flags.zf)
    {
        goto L_0x00477fee;
    }
L_0x00477fd0:
    // 00477fd0  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x00477fd2:
    // 00477fd2  40                     -inc eax
    (cpu.eax)++;
    // 00477fd3  83c210                 -add edx, 0x10
    (cpu.edx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00477fd6  83f810                 +cmp eax, 0x10
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
    // 00477fd9  7ceb                   -jl 0x477fc6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00477fc6;
    }
    // 00477fdb  83f9ff                 +cmp ecx, -1
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
    // 00477fde  751e                   -jne 0x477ffe
    if (!cpu.flags.zf)
    {
        goto L_0x00477ffe;
    }
    // 00477fe0  ff0d74844c00           -dec dword ptr [0x4c8474]
    (app->getMemory<x86::reg32>(x86::reg32(5014644) /* 0x4c8474 */))--;
    // 00477fe6  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00477fe9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477fea  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477feb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477fec  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477fed  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00477fee:
    // 00477fee  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00477ff0  75e0                   -jne 0x477fd2
    if (!cpu.flags.zf)
    {
        goto L_0x00477fd2;
    }
    // 00477ff2  83f9ff                 +cmp ecx, -1
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
    // 00477ff5  75db                   -jne 0x477fd2
    if (!cpu.flags.zf)
    {
        goto L_0x00477fd2;
    }
    // 00477ff7  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00477ff9  74d5                   -je 0x477fd0
    if (cpu.flags.zf)
    {
        goto L_0x00477fd0;
    }
    // 00477ffb  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00477ffc  ebd4                   -jmp 0x477fd2
    goto L_0x00477fd2;
L_0x00477ffe:
    // 00477ffe  c1e104                 -shl ecx, 4
    cpu.ecx <<= 4 /*0x4*/ % 32;
    // 00478001  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00478004  89b128b05100           -mov dword ptr [ecx + 0x51b028], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5353512) /* 0x51b028 */) = cpu.esi;
    // 0047800a  89812cb05100           -mov dword ptr [ecx + 0x51b02c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5353516) /* 0x51b02c */) = cpu.eax;
    // 00478010  033d20b05100           -add edi, dword ptr [0x51b020]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5353504) /* 0x51b020 */)));
    // 00478016  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00478018  89b930b05100           -mov dword ptr [ecx + 0x51b030], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5353520) /* 0x51b030 */) = cpu.edi;
    // 0047801e  899134b05100           -mov dword ptr [ecx + 0x51b034], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5353524) /* 0x51b034 */) = cpu.edx;
    // 00478024  ff0d74844c00           -dec dword ptr [0x4c8474]
    (app->getMemory<x86::reg32>(x86::reg32(5014644) /* 0x4c8474 */))--;
    // 0047802a  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047802d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047802e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047802f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478030  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478031  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_478034(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478034  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00478035  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00478036  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00478037  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00478038  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047803a  8b1d28b05100           -mov ebx, dword ptr [0x51b028]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5353512) /* 0x51b028 */);
    // 00478040  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00478042  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00478044  39d9                   +cmp ecx, ebx
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
    // 00478046  7413                   -je 0x47805b
    if (cpu.flags.zf)
    {
        goto L_0x0047805b;
    }
L_0x00478048:
    // 00478048  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0047804b  42                     -inc edx
    (cpu.edx)++;
    // 0047804c  3d00010000             +cmp eax, 0x100
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(256 /*0x100*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00478051  7d08                   -jge 0x47805b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047805b;
    }
    // 00478053  3b8828b05100           +cmp ecx, dword ptr [eax + 0x51b028]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5353512) /* 0x51b028 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00478059  75ed                   -jne 0x478048
    if (!cpu.flags.zf)
    {
        goto L_0x00478048;
    }
L_0x0047805b:
    // 0047805b  83fa10                 +cmp edx, 0x10
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
    // 0047805e  7d0b                   -jge 0x47806b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047806b;
    }
    // 00478060  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 00478063  3b8a28b05100           +cmp ecx, dword ptr [edx + 0x51b028]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5353512) /* 0x51b028 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00478069  7405                   -je 0x478070
    if (cpu.flags.zf)
    {
        goto L_0x00478070;
    }
L_0x0047806b:
    // 0047806b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047806c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047806d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047806e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047806f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00478070:
    // 00478070  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00478072  89aa28b05100           -mov dword ptr [edx + 0x51b028], ebp
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5353512) /* 0x51b028 */) = cpu.ebp;
    // 00478078  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478079  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047807a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047807b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047807c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_478080(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478080  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00478081  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00478082  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00478083  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00478084  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00478085  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00478086  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00478088  a178844c00             -mov eax, dword ptr [0x4c8478]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5014648) /* 0x4c8478 */);
    // 0047808d  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0047808f  3b0520b05100           +cmp eax, dword ptr [0x51b020]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5353504) /* 0x51b020 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    app->unlockContext(cpu);
    win32::Thread::sleep(0);
    app->lockContext(cpu);
    // 00478095  0f8470000000           -je 0x47810b
    if (cpu.flags.zf)
    {
        goto L_0x0047810b;
    }
    // 0047809b  a120b05100             -mov eax, dword ptr [0x51b020]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5353504) /* 0x51b020 */);
    // 004780a0  a378844c00             -mov dword ptr [0x4c8478], eax
    app->getMemory<x86::reg32>(x86::reg32(5014648) /* 0x4c8478 */) = cpu.eax;
    // 004780a5  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004780a7:
    // 004780a7  8b9928b05100           -mov ebx, dword ptr [ecx + 0x51b028]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5353512) /* 0x51b028 */);
    // 004780ad  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004780af  744f                   -je 0x478100
    if (cpu.flags.zf)
    {
        goto L_0x00478100;
    }
    // 004780b1  a120b05100             -mov eax, dword ptr [0x51b020]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5353504) /* 0x51b020 */);
    // 004780b6  3b8130b05100           +cmp eax, dword ptr [ecx + 0x51b030]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5353520) /* 0x51b030 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004780bc  7c42                   -jl 0x478100
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00478100;
    }
    // 004780be  83b934b0510000         +cmp dword ptr [ecx + 0x51b034], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5353524) /* 0x51b034 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004780c5  7539                   -jne 0x478100
    if (!cpu.flags.zf)
    {
        goto L_0x00478100;
    }
    // 004780c7  c78134b0510001000000   -mov dword ptr [ecx + 0x51b034], 1
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5353524) /* 0x51b034 */) = 1 /*0x1*/;
    // 004780d1  8b1520b05100           -mov edx, dword ptr [0x51b020]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5353504) /* 0x51b020 */);
    // 004780d7  8ba930b05100           -mov ebp, dword ptr [ecx + 0x51b030]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5353520) /* 0x51b030 */);
    // 004780dd  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004780df  29ea                   -sub edx, ebp
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004780e1  ffd3                   -call ebx
    cpu.ip = cpu.ebx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004780e3  09c6                   -or esi, eax
    cpu.esi |= x86::reg32(x86::sreg32(cpu.eax));
    // 004780e5  a120b05100             -mov eax, dword ptr [0x51b020]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5353504) /* 0x51b020 */);
    // 004780ea  8b912cb05100           -mov edx, dword ptr [ecx + 0x51b02c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5353516) /* 0x51b02c */);
    // 004780f0  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004780f2  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004780f4  899934b05100           -mov dword ptr [ecx + 0x51b034], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5353524) /* 0x51b034 */) = cpu.ebx;
    // 004780fa  898130b05100           -mov dword ptr [ecx + 0x51b030], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5353520) /* 0x51b030 */) = cpu.eax;
L_0x00478100:
    // 00478100  83c110                 -add ecx, 0x10
    (cpu.ecx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00478103  81f900010000           +cmp ecx, 0x100
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
    // 00478109  759c                   -jne 0x4780a7
    if (!cpu.flags.zf)
    {
        goto L_0x004780a7;
    }
L_0x0047810b:
    // 0047810b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047810d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047810e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047810f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478110  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478111  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478112  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478113  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_478114(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478114  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00478115  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00478116  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00478118  a124b05100             -mov eax, dword ptr [0x51b024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5353508) /* 0x51b024 */);
    // 0047811d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047811f  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x00478121:
    // 00478121  a124b05100             -mov eax, dword ptr [0x51b024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5353508) /* 0x51b024 */);
    // 00478126  39c8                   +cmp eax, ecx
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
    // 00478128  7d04                   -jge 0x47812e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047812e;
    }
    // 0047812a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047812c  7405                   -je 0x478133
    if (cpu.flags.zf)
    {
        goto L_0x00478133;
    }
L_0x0047812e:
    // 0047812e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00478130  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478131  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478132  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00478133:
    // 00478133  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00478135  e846ffffff             -call 0x478080
    cpu.esp -= 4;
    sub_478080(app, cpu);
    if (cpu.terminate) return;
    // 0047813a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047813c  ebe3                   -jmp 0x478121
    goto L_0x00478121;
}

/* align: skip 0x00 0x00 */
void Application::sub_478140(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478140  ff057c844c00           -inc dword ptr [0x4c847c]
    (app->getMemory<x86::reg32>(x86::reg32(5014652) /* 0x4c847c */))++;
    // 00478146  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_478148(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478148  833d6cb5510000         +cmp dword ptr [0x51b56c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5354860) /* 0x51b56c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047814f  7509                   -jne 0x47815a
    if (!cpu.flags.zf)
    {
        goto L_0x0047815a;
    }
    // 00478151  833d80844c0000         +cmp dword ptr [0x4c8480], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5014656) /* 0x4c8480 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00478158  7406                   -je 0x478160
    if (cpu.flags.zf)
    {
        goto L_0x00478160;
    }
L_0x0047815a:
    // 0047815a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047815f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00478160:
    // 00478160  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00478162  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_478160(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00478160;
    // 00478148  833d6cb5510000         +cmp dword ptr [0x51b56c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5354860) /* 0x51b56c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047814f  7509                   -jne 0x47815a
    if (!cpu.flags.zf)
    {
        goto L_0x0047815a;
    }
    // 00478151  833d80844c0000         +cmp dword ptr [0x4c8480], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5014656) /* 0x4c8480 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00478158  7406                   -je 0x478160
    if (cpu.flags.zf)
    {
        goto L_0x00478160;
    }
L_0x0047815a:
    // 0047815a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047815f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00478160:
L_entry_0x00478160:
    // 00478160  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00478162  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_478164(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478164  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00478166  a08fb55100             -mov al, byte ptr [0x51b58f]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5354895) /* 0x51b58f */);
    // 0047816b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47816c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047816c  803d90b5510000         +cmp byte ptr [0x51b590], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5354896) /* 0x51b590 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00478173  74eb                   -je 0x478160
    if (cpu.flags.zf)
    {
        return sub_478160(app, cpu);
    }
    // 00478175  803d65b5510000         +cmp byte ptr [0x51b565], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5354853) /* 0x51b565 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047817c  75e2                   -jne 0x478160
    if (!cpu.flags.zf)
    {
        return sub_478160(app, cpu);
    }
    // 0047817e  803d64b5510000         +cmp byte ptr [0x51b564], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5354852) /* 0x51b564 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00478185  75d9                   -jne 0x478160
    if (!cpu.flags.zf)
    {
        return sub_478160(app, cpu);
    }
    // 00478187  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047818c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_478190(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478190  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00478192  a092b55100             -mov al, byte ptr [0x51b592]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5354898) /* 0x51b592 */);
    // 00478197  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_478198(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478198  83ec70                 -sub esp, 0x70
    (cpu.esp) -= x86::reg32(x86::sreg32(112 /*0x70*/));
    // 0047819b  833d04854c0000         +cmp dword ptr [0x4c8504], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5014788) /* 0x4c8504 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004781a2  741c                   -je 0x4781c0
    if (cpu.flags.zf)
    {
        goto L_0x004781c0;
    }
    // 004781a4  833d84a84c0000         +cmp dword ptr [0x4ca884], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5023876) /* 0x4ca884 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004781ab  741c                   -je 0x4781c9
    if (cpu.flags.zf)
    {
        goto L_0x004781c9;
    }
    // 004781ad  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004781af  e8ecb30100             -call 0x4935a0
    cpu.esp -= 4;
    sub_4935a0(app, cpu);
    if (cpu.terminate) return;
    // 004781b4  e8a3e1ffff             -call 0x47635c
    cpu.esp -= 4;
    sub_47635c(app, cpu);
    if (cpu.terminate) return;
    // 004781b9  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004781bb  e804b40100             -call 0x4935c4
    cpu.esp -= 4;
    sub_4935c4(app, cpu);
    if (cpu.terminate) return;
L_0x004781c0:
    // 004781c0  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004781c5  83c470                 -add esp, 0x70
    (cpu.esp) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 004781c8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004781c9:
    // 004781c9  b830b15100             -mov eax, 0x51b130
    cpu.eax = 5353776 /*0x51b130*/;
    // 004781ce  e8a1b70000             -call 0x483974
    cpu.esp -= 4;
    sub_483974(app, cpu);
    if (cpu.terminate) return;
    // 004781d3  83c470                 -add esp, 0x70
    (cpu.esp) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 004781d6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4781d8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004781d8  833da4b5510000         +cmp dword ptr [0x51b5a4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5354916) /* 0x51b5a4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004781df  0f847bffffff           -je 0x478160
    if (cpu.flags.zf)
    {
        return sub_478160(app, cpu);
    }
    // 004781e5  833d84b5510000         +cmp dword ptr [0x51b584], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5354884) /* 0x51b584 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004781ec  0f846effffff           -je 0x478160
    if (cpu.flags.zf)
    {
        return sub_478160(app, cpu);
    }
    // 004781f2  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
    // 004781f4  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004781f9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4781fc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004781fc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004781fd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004781fe  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004781ff  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00478201  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00478203  2eff15c8534b00         -call dword ptr cs:[0x4b53c8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936648) /* 0x4b53c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047820a  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0047820c  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 0047820e  2eff15c8534b00         -call dword ptr cs:[0x4b53c8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936648) /* 0x4b53c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00478215  c7430800000000         -mov dword ptr [ebx + 8], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 0047821c  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0047821f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478220  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478221  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478222  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_478224(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478224  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00478225  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00478226  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00478227  833dac814c0000         +cmp dword ptr [0x4c81ac], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5013932) /* 0x4c81ac */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047822e  750c                   -jne 0x47823c
    if (!cpu.flags.zf)
    {
        goto L_0x0047823c;
    }
    // 00478230  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00478232  746c                   -je 0x4782a0
    if (cpu.flags.zf)
    {
        goto L_0x004782a0;
    }
    // 00478234  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x00478236:
    // 00478236  891dac814c00           -mov dword ptr [0x4c81ac], ebx
    app->getMemory<x86::reg32>(x86::reg32(5013932) /* 0x4c81ac */) = cpu.ebx;
L_0x0047823c:
    // 0047823c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047823e  7505                   -jne 0x478245
    if (!cpu.flags.zf)
    {
        goto L_0x00478245;
    }
    // 00478240  a1ac814c00             -mov eax, dword ptr [0x4c81ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5013932) /* 0x4c81ac */);
L_0x00478245:
    // 00478245  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00478246  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00478248  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047824a  2eff1534544b00         -call dword ptr cs:[0x4b5434]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936756) /* 0x4b5434 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00478251  a3a8b55100             -mov dword ptr [0x51b5a8], eax
    app->getMemory<x86::reg32>(x86::reg32(5354920) /* 0x51b5a8 */) = cpu.eax;
    // 00478256  2eff15c0544b00         -call dword ptr cs:[0x4b54c0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936896) /* 0x4b54c0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047825d  3db7000000             +cmp eax, 0xb7
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(183 /*0xb7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00478262  7536                   -jne 0x47829a
    if (!cpu.flags.zf)
    {
        goto L_0x0047829a;
    }
    // 00478264  8b0dac814c00           -mov ecx, dword ptr [0x4c81ac]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5013932) /* 0x4c81ac */);
    // 0047826a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047826b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047826d  2eff15b0534b00         -call dword ptr cs:[0x4b53b0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936624) /* 0x4b53b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00478274  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00478276  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00478278  7412                   -je 0x47828c
    if (cpu.flags.zf)
    {
        goto L_0x0047828c;
    }
    // 0047827a  6a09                   -push 9
    app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 0047827c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047827d  2eff1508544b00         -call dword ptr cs:[0x4b5408]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936712) /* 0x4b5408 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00478284  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00478285  2eff15f8534b00         -call dword ptr cs:[0x4b53f8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936696) /* 0x4b53f8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0047828c:
    // 0047828c  833d88844c0000         +cmp dword ptr [0x4c8488], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5014664) /* 0x4c8488 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00478293  7415                   -je 0x4782aa
    if (cpu.flags.zf)
    {
        goto L_0x004782aa;
    }
    // 00478295  e887330100             -call 0x48b621
    cpu.esp -= 4;
    sub_48b621(app, cpu);
    if (cpu.terminate) return;
L_0x0047829a:
    // 0047829a  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0047829c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047829d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047829e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047829f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004782a0:
    // 004782a0  8b1dbc605200           -mov ebx, dword ptr [0x5260bc]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5398716) /* 0x5260bc */);
    // 004782a6  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004782a8  eb8c                   -jmp 0x478236
    goto L_0x00478236;
L_0x004782aa:
    // 004782aa  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004782af  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004782b0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004782b1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004782b2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::crt_exit(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004782c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004782c1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004782c2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004782c3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004782c4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004782c5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004782c6  81ec04030000           -sub esp, 0x304
    (cpu.esp) -= x86::reg32(x86::sreg32(772 /*0x304*/));
    // 004782cc  8b159c844c00           -mov edx, dword ptr [0x4c849c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5014684) /* 0x4c849c */);
    // 004782d2  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004782d4  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004782d6  0f8582010000           -jne 0x47845e
    if (!cpu.flags.zf)
    {
        goto L_0x0047845e;
    }
    // 004782dc  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004782e1  8b9c2420030000         -mov ebx, dword ptr [esp + 0x320]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(800) /* 0x320 */);
    // 004782e8  890d9c844c00           -mov dword ptr [0x4c849c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5014684) /* 0x4c849c */) = cpu.ecx;
    // 004782ee  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004782f0  0f8575010000           -jne 0x47846b
    if (!cpu.flags.zf)
    {
        goto L_0x0047846b;
    }
    // 004782f6  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 004782f8  882424                 -mov byte ptr [esp], ah
    app->getMemory<x86::reg8>(cpu.esp) = cpu.ah;
L_0x004782fb:
    // 004782fb  833d68824c0000         +cmp dword ptr [0x4c8268], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5014120) /* 0x4c8268 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00478302  0f8592010000           -jne 0x47849a
    if (!cpu.flags.zf)
    {
        goto L_0x0047849a;
    }
L_0x00478308:
    // 00478308  833d64824c0000         +cmp dword ptr [0x4c8264], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5014116) /* 0x4c8264 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047830f  0f84a4000000           -je 0x4783b9
    if (cpu.flags.zf)
    {
        goto L_0x004783b9;
    }
    // 00478315  8b158c844c00           -mov edx, dword ptr [0x4c848c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5014668) /* 0x4c848c */);
    // 0047831b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047831d  7448                   -je 0x478367
    if (cpu.flags.zf)
    {
        goto L_0x00478367;
    }
    // 0047831f  8b0d90844c00           -mov ecx, dword ptr [0x4c8490]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5014672) /* 0x4c8490 */);
    // 00478325  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00478326  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00478327  68fcdd4b00             -push 0x4bddfc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4972028 /*0x4bddfc*/;
    cpu.esp -= 4;
    // 0047832c  8d84240c020000         -lea eax, [esp + 0x20c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(524) /* 0x20c */);
    // 00478333  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00478334  e8e8200000             -call 0x47a421
    cpu.esp -= 4;
    sub_47a421(app, cpu);
    if (cpu.terminate) return;
    // 00478339  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0047833c  8db42400020000         -lea esi, [esp + 0x200]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(512) /* 0x200 */);
    // 00478343  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00478345  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00478346  2bc9                   +sub ecx, ecx
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
    // 00478348  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00478349  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 0047834b  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0047834d  4f                     -dec edi
    (cpu.edi)--;
L_0x0047834e:
    // 0047834e  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00478350  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00478352  3c00                   +cmp al, 0
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
    // 00478354  7410                   -je 0x478366
    if (cpu.flags.zf)
    {
        goto L_0x00478366;
    }
    // 00478356  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00478359  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0047835c  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0047835f  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00478362  3c00                   +cmp al, 0
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
    // 00478364  75e8                   -jne 0x47834e
    if (!cpu.flags.zf)
    {
        goto L_0x0047834e;
    }
L_0x00478366:
    // 00478366  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00478367:
    // 00478367  8b3594844c00           -mov esi, dword ptr [0x4c8494]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5014676) /* 0x4c8494 */);
    // 0047836d  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0047836f  7448                   -je 0x4783b9
    if (cpu.flags.zf)
    {
        goto L_0x004783b9;
    }
    // 00478371  8b3d98844c00           -mov edi, dword ptr [0x4c8498]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5014680) /* 0x4c8498 */);
    // 00478377  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00478378  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00478379  6810de4b00             -push 0x4bde10
    app->getMemory<x86::reg32>(cpu.esp-4) = 4972048 /*0x4bde10*/;
    cpu.esp -= 4;
    // 0047837e  8d84248c020000         -lea eax, [esp + 0x28c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(652) /* 0x28c */);
    // 00478385  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00478386  e896200000             -call 0x47a421
    cpu.esp -= 4;
    sub_47a421(app, cpu);
    if (cpu.terminate) return;
    // 0047838b  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0047838e  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00478390  8db42480020000         -lea esi, [esp + 0x280]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(640) /* 0x280 */);
    // 00478397  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00478398  2bc9                   +sub ecx, ecx
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
    // 0047839a  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0047839b  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 0047839d  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0047839f  4f                     -dec edi
    (cpu.edi)--;
L_0x004783a0:
    // 004783a0  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004783a2  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004783a4  3c00                   +cmp al, 0
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
    // 004783a6  7410                   -je 0x4783b8
    if (cpu.flags.zf)
    {
        goto L_0x004783b8;
    }
    // 004783a8  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004783ab  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004783ae  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004783b1  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004783b4  3c00                   +cmp al, 0
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
    // 004783b6  75e8                   -jne 0x4783a0
    if (!cpu.flags.zf)
    {
        goto L_0x004783a0;
    }
L_0x004783b8:
    // 004783b8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004783b9:
    // 004783b9  833d58824c0000         +cmp dword ptr [0x4c8258], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5014104) /* 0x4c8258 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004783c0  7411                   -je 0x4783d3
    if (cpu.flags.zf)
    {
        goto L_0x004783d3;
    }
    // 004783c2  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004783c4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004783c5  2eff1524554b00         -call dword ptr cs:[0x4b5524]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936996) /* 0x4b5524 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004783cc  2eff153c544b00         -call dword ptr cs:[0x4b543c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936764) /* 0x4b543c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004783d3:
    // 004783d3  833d6c824c0000         +cmp dword ptr [0x4c826c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5014124) /* 0x4c826c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004783da  7408                   -je 0x4783e4
    if (cpu.flags.zf)
    {
        goto L_0x004783e4;
    }
    // 004783dc  ff156c824c00           -call dword ptr [0x4c826c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5014124) /* 0x4c826c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004783e2  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
L_0x004783e4:
    // 004783e4  833d70824c0000         +cmp dword ptr [0x4c8270], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5014128) /* 0x4c8270 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004783eb  7406                   -je 0x4783f3
    if (cpu.flags.zf)
    {
        goto L_0x004783f3;
    }
    // 004783ed  ff1570824c00           -call dword ptr [0x4c8270]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5014128) /* 0x4c8270 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004783f3:
    // 004783f3  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004783f5  2eff1504544b00         -call dword ptr cs:[0x4b5404]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936708) /* 0x4b5404 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004783fc  6831100100             -push 0x11031
    app->getMemory<x86::reg32>(cpu.esp-4) = 69681 /*0x11031*/;
    cpu.esp -= 4;
    // 00478401  6830de4b00             -push 0x4bde30
    app->getMemory<x86::reg32>(cpu.esp-4) = 4972080 /*0x4bde30*/;
    cpu.esp -= 4;
    // 00478406  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047840a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047840b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047840d  2eff15d4534b00         -call dword ptr cs:[0x4b53d4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936660) /* 0x4b53d4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00478414  83f801                 +cmp eax, 1
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
    // 00478417  7528                   -jne 0x478441
    if (!cpu.flags.zf)
    {
        goto L_0x00478441;
    }
    // 00478419  833d5c824c0000         +cmp dword ptr [0x4c825c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5014108) /* 0x4c825c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00478420  741f                   -je 0x478441
    if (cpu.flags.zf)
    {
        goto L_0x00478441;
    }
    // 00478422  833d60824c0000         +cmp dword ptr [0x4c8260], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5014112) /* 0x4c8260 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00478429  7416                   -je 0x478441
    if (cpu.flags.zf)
    {
        goto L_0x00478441;
    }
    // 0047842b  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0047842d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047842e  6840de4b00             -push 0x4bde40
    app->getMemory<x86::reg32>(cpu.esp-4) = 4972096 /*0x4bde40*/;
    cpu.esp -= 4;
    // 00478433  e8a9b10100             -call 0x4935e1
    cpu.esp -= 4;
    sub_4935e1(app, cpu);
    if (cpu.terminate) return;
    // 00478438  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0047843b  ff1560824c00           -call dword ptr [0x4c8260]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5014112) /* 0x4c8260 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00478441:
    // 00478441  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00478443  7407                   -je 0x47844c
    if (cpu.flags.zf)
    {
        goto L_0x0047844c;
    }
    // 00478445  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00478447  e8d46b0000             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
L_0x0047844c:
    // 0047844c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047844e  e855680000             -call 0x47eca8
    cpu.esp -= 4;
    sub_47eca8(app, cpu);
    if (cpu.terminate) return;
    // 00478453  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00478455  745a                   -je 0x4784b1
    if (cpu.flags.zf)
    {
        goto L_0x004784b1;
    }
    // 00478457  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00478459  e8872f0100             -call 0x48b3e5
    cpu.esp -= 4;
    sub_48b3e5(app, cpu);
    if (cpu.terminate) return;
L_0x0047845e:
    // 0047845e  81c404030000           +add esp, 0x304
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(772 /*0x304*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00478464  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478465  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478466  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478467  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478468  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478469  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047846a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047846b:
    // 0047846b  8d842424030000         -lea eax, [esp + 0x324]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(804) /* 0x324 */);
    // 00478472  8d9c2400030000         -lea ebx, [esp + 0x300]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(768) /* 0x300 */);
    // 00478479  8b942420030000         -mov edx, dword ptr [esp + 0x320]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(800) /* 0x320 */);
    // 00478480  89842400030000         -mov dword ptr [esp + 0x300], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(768) /* 0x300 */) = cpu.eax;
    // 00478487  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00478489  e888b10100             -call 0x493616
    cpu.esp -= 4;
    sub_493616(app, cpu);
    if (cpu.terminate) return;
    // 0047848e  89ac2400030000         -mov dword ptr [esp + 0x300], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(768) /* 0x300 */) = cpu.ebp;
    // 00478495  e961feffff             -jmp 0x4782fb
    goto L_0x004782fb;
L_0x0047849a:
    // 0047849a  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0047849c  ff1568824c00           -call dword ptr [0x4c8268]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5014120) /* 0x4c8268 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004784a2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004784a4  0f855efeffff           -jne 0x478308
    if (!cpu.flags.zf)
    {
        goto L_0x00478308;
    }
    // 004784aa  a39c844c00             -mov dword ptr [0x4c849c], eax
    app->getMemory<x86::reg32>(x86::reg32(5014684) /* 0x4c849c */) = cpu.eax;
    // 004784af  ebad                   -jmp 0x47845e
    goto L_0x0047845e;
L_0x004784b1:
    // 004784b1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004784b2  2eff1554544b00         -call dword ptr cs:[0x4b5454]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936788) /* 0x4b5454 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004784b9  81c404030000           -add esp, 0x304
    (cpu.esp) += x86::reg32(x86::sreg32(772 /*0x304*/));
    // 004784bf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004784c0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004784c1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004784c2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004784c3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004784c4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004784c5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4784d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004784d0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004784d1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004784d2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004784d3  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004784d5  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004784d7  e854b10100             -call 0x493630
    cpu.esp -= 4;
    sub_493630(app, cpu);
    if (cpu.terminate) return;
    // 004784dc  a330b75100             -mov dword ptr [0x51b730], eax
    app->getMemory<x86::reg32>(x86::reg32(5355312) /* 0x51b730 */) = cpu.eax;
    // 004784e1  e86ab10100             -call 0x493650
    cpu.esp -= 4;
    sub_493650(app, cpu);
    if (cpu.terminate) return;
    // 004784e6  b8b0b55100             -mov eax, 0x51b5b0
    cpu.eax = 5354928 /*0x51b5b0*/;
    // 004784eb  8915ac844c00           -mov dword ptr [0x4c84ac], edx
    app->getMemory<x86::reg32>(x86::reg32(5014700) /* 0x4c84ac */) = cpu.edx;
    // 004784f1  ba80010000             -mov edx, 0x180
    cpu.edx = 384 /*0x180*/;
    // 004784f6  e8e16b0000             -call 0x47f0dc
    cpu.esp -= 4;
    sub_47f0dc(app, cpu);
    if (cpu.terminate) return;
    // 004784fb  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004784fd  01de                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004784ff  8d3c9500000000         -lea edi, [edx*4]
    cpu.edi = x86::reg32(cpu.edx * 4);
    // 00478506  a1ac844c00             -mov eax, dword ptr [0x4c84ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5014700) /* 0x4c84ac */);
    // 0047850b  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 0047850d  e8fe090000             -call 0x478f10
    cpu.esp -= 4;
    sub_478f10(app, cpu);
    if (cpu.terminate) return;
    // 00478512  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00478514  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00478516  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00478518  b844de4b00             -mov eax, 0x4bde44
    cpu.eax = 4972100 /*0x4bde44*/;
    // 0047851d  8b1dac844c00           -mov ebx, dword ptr [0x4c84ac]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5014700) /* 0x4c84ac */);
    // 00478523  6a20                   -push 0x20
    app->getMemory<x86::reg32>(cpu.esp-4) = 32 /*0x20*/;
    cpu.esp -= 4;
    // 00478525  c1e703                 -shl edi, 3
    cpu.edi <<= 3 /*0x3*/ % 32;
    // 00478528  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047852a  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 0047852c  01fb                   -add ebx, edi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0047852e  8935a8844c00           -mov dword ptr [0x4c84a8], esi
    app->getMemory<x86::reg32>(x86::reg32(5014696) /* 0x4c84a8 */) = cpu.esi;
    // 00478534  e823000000             -call 0x47855c
    cpu.esp -= 4;
    sub_47855c(app, cpu);
    if (cpu.terminate) return;
    // 00478539  a1a8844c00             -mov eax, dword ptr [0x4c84a8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5014696) /* 0x4c84a8 */);
    // 0047853e  8b15ac844c00           -mov edx, dword ptr [0x4c84ac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5014700) /* 0x4c84ac */);
    // 00478544  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00478546  a33cb75100             -mov dword ptr [0x51b73c], eax
    app->getMemory<x86::reg32>(x86::reg32(5355324) /* 0x51b73c */) = cpu.eax;
    // 0047854b  a130b75100             -mov eax, dword ptr [0x51b730]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355312) /* 0x51b730 */);
    // 00478550  e803b10100             -call 0x493658
    cpu.esp -= 4;
    sub_493658(app, cpu);
    if (cpu.terminate) return;
    // 00478555  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478556  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478557  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478558  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47855c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047855c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047855d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047855e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047855f  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00478561  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00478563  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 00478565  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00478567  81e1000f0000           -and ecx, 0xf00
    cpu.ecx &= x86::reg32(x86::sreg32(3840 /*0xf00*/));
    // 0047856d  c1f908                 -sar ecx, 8
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (8 /*0x8*/ % 32));
    // 00478570  8d148d00000000         -lea edx, [ecx*4]
    cpu.edx = x86::reg32(cpu.ecx * 4);
    // 00478577  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00478579  b9b0b55100             -mov ecx, 0x51b5b0
    cpu.ecx = 5354928 /*0x51b5b0*/;
    // 0047857e  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 00478581  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00478585  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00478587  48                     -dec eax
    (cpu.eax)--;
    // 00478588  894108                 -mov dword ptr [ecx + 8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0047858b  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0047858f  48                     -dec eax
    (cpu.eax)--;
    // 00478590  89410c                 -mov dword ptr [ecx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00478593  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00478597  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0047859b  894110                 -mov dword ptr [ecx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0047859e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004785a0  7405                   -je 0x4785a7
    if (cpu.flags.zf)
    {
        goto L_0x004785a7;
    }
    // 004785a2  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
L_0x004785a7:
    // 004785a7  895114                 -mov dword ptr [ecx + 0x14], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004785aa  8b1534b75100           -mov edx, dword ptr [0x51b734]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5355316) /* 0x51b734 */);
    // 004785b0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004785b1  8b4220                 -mov eax, dword ptr [edx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 004785b4  684cde4b00             -push 0x4bde4c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4972108 /*0x4bde4c*/;
    cpu.esp -= 4;
    // 004785b9  a334b75100             -mov dword ptr [0x51b734], eax
    app->getMemory<x86::reg32>(x86::reg32(5355316) /* 0x51b734 */) = cpu.eax;
    // 004785be  8d4204                 -lea eax, [edx + 4]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004785c1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004785c2  e85a1e0000             -call 0x47a421
    cpu.esp -= 4;
    sub_47a421(app, cpu);
    if (cpu.terminate) return;
    // 004785c7  c7421400000000         -mov dword ptr [edx + 0x14], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 004785ce  c7422400000000         -mov dword ptr [edx + 0x24], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 004785d5  8b4214                 -mov eax, dword ptr [edx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 004785d8  894210                 -mov dword ptr [edx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004785db  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004785dd  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 004785df  80cc80                 -or ah, 0x80
    cpu.ah |= x86::reg8(x86::sreg8(128 /*0x80*/));
    // 004785e2  894218                 -mov dword ptr [edx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004785e5  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004785e8  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 004785ea  8b1534b75100           -mov edx, dword ptr [0x51b734]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5355316) /* 0x51b734 */);
    // 004785f0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004785f1  8b5a20                 -mov ebx, dword ptr [edx + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 004785f4  6858de4b00             -push 0x4bde58
    app->getMemory<x86::reg32>(cpu.esp-4) = 4972120 /*0x4bde58*/;
    cpu.esp -= 4;
    // 004785f9  891d34b75100           -mov dword ptr [0x51b734], ebx
    app->getMemory<x86::reg32>(x86::reg32(5355316) /* 0x51b734 */) = cpu.ebx;
    // 004785ff  8d5a04                 -lea ebx, [edx + 4]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00478602  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00478603  e8191e0000             -call 0x47a421
    cpu.esp -= 4;
    sub_47a421(app, cpu);
    if (cpu.terminate) return;
    // 00478608  c7421400000000         -mov dword ptr [edx + 0x14], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 0047860f  c7422000000000         -mov dword ptr [edx + 0x20], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 00478616  6681ce2080             -or si, 0x8020
    cpu.si |= x86::reg16(x86::sreg16(32800 /*0x8020*/));
    // 0047861b  892a                   -mov dword ptr [edx], ebp
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebp;
    // 0047861d  897218                 -mov dword ptr [edx + 0x18], esi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 00478620  8b4214                 -mov eax, dword ptr [edx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 00478623  894210                 -mov dword ptr [edx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00478626  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00478628  895104                 -mov dword ptr [ecx + 4], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0047862b  895020                 -mov dword ptr [eax + 0x20], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 0047862e  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00478631  8b19                   -mov ebx, dword ptr [ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00478633  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00478635  895a24                 -mov dword ptr [edx + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 00478638  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478639  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047863a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047863b  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_478640(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478640  c705c0844c00d01b4900   -mov dword ptr [0x4c84c0], 0x491bd0
    app->getMemory<x86::reg32>(x86::reg32(5014720) /* 0x4c84c0 */) = 4791248 /*0x491bd0*/;
    // 0047864a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_47864c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047864c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047864d  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00478652  e84d000000             -call 0x4786a4
    cpu.esp -= 4;
    sub_4786a4(app, cpu);
    if (cpu.terminate) return;
    // 00478657  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478658  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47865c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047865c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047865d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047865f  e840000000             -call 0x4786a4
    cpu.esp -= 4;
    sub_4786a4(app, cpu);
    if (cpu.terminate) return;
    // 00478664  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478665  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_478668(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478668  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00478669  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0047866e  e831000000             -call 0x4786a4
    cpu.esp -= 4;
    sub_4786a4(app, cpu);
    if (cpu.terminate) return;
    // 00478673  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00478675  7502                   -jne 0x478679
    if (!cpu.flags.zf)
    {
        goto L_0x00478679;
    }
    // 00478677  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478678  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00478679:
    // 00478679  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0047867b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047867c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_478680(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478680  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00478681  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00478683  e81c000000             -call 0x4786a4
    cpu.esp -= 4;
    sub_4786a4(app, cpu);
    if (cpu.terminate) return;
    // 00478688  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047868a  7502                   -jne 0x47868e
    if (!cpu.flags.zf)
    {
        goto L_0x0047868e;
    }
    // 0047868c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047868d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047868e:
    // 0047868e  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00478690  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478691  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_478694(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478694  e80b000000             -call 0x4786a4
    cpu.esp -= 4;
    sub_4786a4(app, cpu);
    if (cpu.terminate) return;
    // 00478699  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047869b  7503                   -jne 0x4786a0
    if (!cpu.flags.zf)
    {
        goto L_0x004786a0;
    }
    // 0047869d  c3                     -ret 
    cpu.esp += 4;
    return;
    // 0047869e  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x004786a0:
    // 004786a0  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004786a2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4786a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004786a0;
    // 00478694  e80b000000             -call 0x4786a4
    cpu.esp -= 4;
    sub_4786a4(app, cpu);
    if (cpu.terminate) return;
    // 00478699  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047869b  7503                   -jne 0x4786a0
    if (!cpu.flags.zf)
    {
        goto L_0x004786a0;
    }
    // 0047869d  c3                     -ret 
    cpu.esp += 4;
    return;
    // 0047869e  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x004786a0:
L_entry_0x004786a0:
    // 004786a0  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004786a2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4786a4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004786a4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004786a5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004786a6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004786a7  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004786a9  8b3d30b75100           -mov edi, dword ptr [0x51b730]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5355312) /* 0x51b730 */);
    // 004786af  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004786b1  7407                   -je 0x4786ba
    if (cpu.flags.zf)
    {
        goto L_0x004786ba;
    }
    // 004786b3  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004786b5  e896af0100             -call 0x493650
    cpu.esp -= 4;
    sub_493650(app, cpu);
    if (cpu.terminate) return;
L_0x004786ba:
    // 004786ba  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004786bc  e81f000000             -call 0x4786e0
    cpu.esp -= 4;
    sub_4786e0(app, cpu);
    if (cpu.terminate) return;
    // 004786c1  8b2d30b75100           -mov ebp, dword ptr [0x51b730]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5355312) /* 0x51b730 */);
    // 004786c7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004786c9  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004786cb  7506                   -jne 0x4786d3
    if (!cpu.flags.zf)
    {
        goto L_0x004786d3;
    }
    // 004786cd  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004786cf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004786d0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004786d1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004786d2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004786d3:
    // 004786d3  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004786d5  e87eaf0100             -call 0x493658
    cpu.esp -= 4;
    sub_493658(app, cpu);
    if (cpu.terminate) return;
    // 004786da  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004786dc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004786dd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004786de  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004786df  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4786e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004786e0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004786e1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004786e2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004786e3  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004786e6  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004786ea  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004786ee  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004786f0  81e2000f0000           -and edx, 0xf00
    cpu.edx &= x86::reg32(x86::sreg32(3840 /*0xf00*/));
    // 004786f6  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 004786f9  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00478700  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00478702  b9b0b55100             -mov ecx, 0x51b5b0
    cpu.ecx = 5354928 /*0x51b5b0*/;
    // 00478707  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0047870a  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047870c  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00478710  e84baf0100             -call 0x493660
    cpu.esp -= 4;
    sub_493660(app, cpu);
    if (cpu.terminate) return;
    // 00478715  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00478719  f6c340                 +test bl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 64 /*0x40*/));
    // 0047871c  0f850a010000           -jne 0x47882c
    if (!cpu.flags.zf)
    {
        goto L_0x0047882c;
    }
    // 00478722  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00478726  034114                 -add eax, dword ptr [ecx + 0x14]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */)));
    // 00478729  8b5108                 -mov edx, dword ptr [ecx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0047872c  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047872e  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
L_0x00478731:
    // 00478731  f7d0                   -not eax
    cpu.eax = ~cpu.eax;
    // 00478733  21c2                   -and edx, eax
    cpu.edx &= x86::reg32(x86::sreg32(cpu.eax));
    // 00478735  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00478738  8b39                   -mov edi, dword ptr [ecx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx);
    // 0047873a  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0047873c  0f84b6010000           -je 0x4788f8
    if (cpu.flags.zf)
    {
        goto L_0x004788f8;
    }
    // 00478742  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00478744  25000f0000             -and eax, 0xf00
    cpu.eax &= x86::reg32(x86::sreg32(3840 /*0xf00*/));
    // 00478749  3d00030000             +cmp eax, 0x300
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(768 /*0x300*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047874e  0f84ee000000           -je 0x478842
    if (cpu.flags.zf)
    {
        goto L_0x00478842;
    }
    // 00478754  f6c320                 +test bl, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 32 /*0x20*/));
    // 00478757  0f85d2010000           -jne 0x47892f
    if (!cpu.flags.zf)
    {
        goto L_0x0047892f;
    }
    // 0047875d  833db8844c0000         +cmp dword ptr [0x4c84b8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5014712) /* 0x4c84b8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00478764  0f8542010000           -jne 0x4788ac
    if (!cpu.flags.zf)
    {
        goto L_0x004788ac;
    }
L_0x0047876a:
    // 0047876a  8b39                   -mov edi, dword ptr [ecx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx);
    // 0047876c  8b7720                 -mov esi, dword ptr [edi + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */);
    // 0047876f  8b3f                   -mov edi, dword ptr [edi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi);
    // 00478771  f6c340                 +test bl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 64 /*0x40*/));
    // 00478774  0f854a010000           -jne 0x4788c4
    if (!cpu.flags.zf)
    {
        goto L_0x004788c4;
    }
L_0x0047877a:
    // 0047877a  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0047877c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047877e  39c7                   +cmp edi, eax
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
L_0x00478780:
    // 00478780  0f824f010000           -jb 0x4788d5
    if (cpu.flags.cf)
    {
        goto L_0x004788d5;
    }
    // 00478786  8b3e                   -mov edi, dword ptr [esi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi);
    // 00478788  037e10                 -add edi, dword ptr [esi + 0x10]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */)));
    // 0047878b  f6c340                 +test bl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 64 /*0x40*/));
    // 0047878e  740c                   -je 0x47879c
    if (cpu.flags.zf)
    {
        goto L_0x0047879c;
    }
    // 00478790  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00478793  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 00478795  8b790c                 -mov edi, dword ptr [ecx + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00478798  f7d7                   -not edi
    cpu.edi = ~cpu.edi;
    // 0047879a  21c7                   -and edi, eax
    cpu.edi &= x86::reg32(x86::sreg32(cpu.eax));
L_0x0047879c:
    // 0047879c  3b7104                 +cmp esi, dword ptr [ecx + 4]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047879f  0f8539010000           -jne 0x4788de
    if (!cpu.flags.zf)
    {
        goto L_0x004788de;
    }
L_0x004787a5:
    // 004787a5  3b1424                 +cmp edx, dword ptr [esp]
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
    // 004787a8  0f8c3a010000           -jl 0x4788e8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004788e8;
    }
    // 004787ae  8b2d34b75100           -mov ebp, dword ptr [0x51b734]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5355316) /* 0x51b734 */);
    // 004787b4  8b15b4844c00           -mov edx, dword ptr [0x4c84b4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5014708) /* 0x4c84b4 */);
    // 004787ba  895d18                 -mov dword ptr [ebp + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 004787bd  896c2408               -mov dword ptr [esp + 8], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebp;
    // 004787c1  8b4520                 -mov eax, dword ptr [ebp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 004787c4  89551c                 -mov dword ptr [ebp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004787c7  bb0c000000             -mov ebx, 0xc
    cpu.ebx = 12 /*0xc*/;
    // 004787cc  a334b75100             -mov dword ptr [0x51b734], eax
    app->getMemory<x86::reg32>(x86::reg32(5355316) /* 0x51b734 */) = cpu.eax;
    // 004787d1  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004787d5  42                     -inc edx
    (cpu.edx)++;
    // 004787d6  894514                 -mov dword ptr [ebp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004787d9  8915b4844c00           -mov dword ptr [0x4c84b4], edx
    app->getMemory<x86::reg32>(x86::reg32(5014708) /* 0x4c84b4 */) = cpu.edx;
    // 004787df  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004787e2  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004787e6  894510                 -mov dword ptr [ebp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004787e9  8d4504                 -lea eax, [ebp + 4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 004787ec  e80b1c0000             -call 0x47a3fc
    cpu.esp -= 4;
    sub_47a3fc(app, cpu);
    if (cpu.terminate) return;
    // 004787f1  897d00                 -mov dword ptr [ebp], edi
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.edi;
    // 004787f4  8b4624                 -mov eax, dword ptr [esi + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004787f7  894524                 -mov dword ptr [ebp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 004787fa  897520                 -mov dword ptr [ebp + 0x20], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */) = cpu.esi;
    // 004787fd  8b4624                 -mov eax, dword ptr [esi + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 00478800  896820                 -mov dword ptr [eax + 0x20], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ebp;
    // 00478803  896e24                 -mov dword ptr [esi + 0x24], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.ebp;
    // 00478806  83791400               +cmp dword ptr [ecx + 0x14], 0
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
    // 0047880a  7407                   -je 0x478813
    if (cpu.flags.zf)
    {
        goto L_0x00478813;
    }
    // 0047880c  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0047880e  e88dae0100             -call 0x4936a0
    cpu.esp -= 4;
    sub_4936a0(app, cpu);
    if (cpu.terminate) return;
L_0x00478813:
    // 00478813  833db8844c0000         +cmp dword ptr [0x4c84b8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5014712) /* 0x4c84b8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047881a  7405                   -je 0x478821
    if (cpu.flags.zf)
    {
        goto L_0x00478821;
    }
    // 0047881c  e8c3040000             -call 0x478ce4
    cpu.esp -= 4;
    sub_478ce4(app, cpu);
    if (cpu.terminate) return;
L_0x00478821:
    // 00478821  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
L_0x00478825:
    // 00478825  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00478828  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478829  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047882a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047882b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047882c:
    // 0047882c  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00478830  8b7114                 -mov esi, dword ptr [ecx + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 00478833  8b510c                 -mov edx, dword ptr [ecx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00478836  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00478838  01c2                   +add edx, eax
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047883a  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0047883d  e9effeffff             -jmp 0x478731
    goto L_0x00478731;
L_0x00478842:
    // 00478842  8b0d34b75100           -mov ecx, dword ptr [0x51b734]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5355316) /* 0x51b734 */);
    // 00478848  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 0047884b  a334b75100             -mov dword ptr [0x51b734], eax
    app->getMemory<x86::reg32>(x86::reg32(5355316) /* 0x51b734 */) = cpu.eax;
    // 00478850  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00478852  8b7720                 -mov esi, dword ptr [edi + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */);
    // 00478855  e82a880100             -call 0x491084
    cpu.esp -= 4;
    sub_491084(app, cpu);
    if (cpu.terminate) return;
    // 0047885a  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 0047885c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047885e  74c5                   -je 0x478825
    if (cpu.flags.zf)
    {
        goto L_0x00478825;
    }
    // 00478860  8b15b4844c00           -mov edx, dword ptr [0x4c84b4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5014708) /* 0x4c84b4 */);
    // 00478866  895918                 -mov dword ptr [ecx + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 00478869  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0047886d  89511c                 -mov dword ptr [ecx + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 00478870  bb0c000000             -mov ebx, 0xc
    cpu.ebx = 12 /*0xc*/;
    // 00478875  894114                 -mov dword ptr [ecx + 0x14], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00478878  42                     -inc edx
    (cpu.edx)++;
    // 00478879  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0047887c  8915b4844c00           -mov dword ptr [0x4c84b4], edx
    app->getMemory<x86::reg32>(x86::reg32(5014708) /* 0x4c84b4 */) = cpu.edx;
    // 00478882  894110                 -mov dword ptr [ecx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00478885  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00478889  8d4104                 -lea eax, [ecx + 4]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0047888c  e86b1b0000             -call 0x47a3fc
    cpu.esp -= 4;
    sub_47a3fc(app, cpu);
    if (cpu.terminate) return;
    // 00478891  8b4624                 -mov eax, dword ptr [esi + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 00478894  894124                 -mov dword ptr [ecx + 0x24], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 00478897  897120                 -mov dword ptr [ecx + 0x20], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.esi;
    // 0047889a  8b4624                 -mov eax, dword ptr [esi + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 0047889d  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 004788a0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004788a2  894e24                 -mov dword ptr [esi + 0x24], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.ecx;
    // 004788a5  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004788a8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004788a9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004788aa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004788ab  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004788ac:
    // 004788ac  f6c310                 +test bl, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 16 /*0x10*/));
    // 004788af  0f85b5feffff           -jne 0x47876a
    if (!cpu.flags.zf)
    {
        goto L_0x0047876a;
    }
    // 004788b5  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004788b7  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004788ba  e819af0100             -call 0x4937d8
    cpu.esp -= 4;
    sub_4937d8(app, cpu);
    if (cpu.terminate) return;
    // 004788bf  e9a6feffff             -jmp 0x47876a
    goto L_0x0047876a;
L_0x004788c4:
    // 004788c4  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004788c7  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 004788c9  8b790c                 -mov edi, dword ptr [ecx + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004788cc  f7d7                   -not edi
    cpu.edi = ~cpu.edi;
    // 004788ce  21c7                   +and edi, eax
    cpu.clear_co();
    cpu.set_szp((cpu.edi &= x86::reg32(x86::sreg32(cpu.eax))));
    // 004788d0  e9a5feffff             -jmp 0x47877a
    goto L_0x0047877a;
L_0x004788d5:
    // 004788d5  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 004788d7  29fa                   +sub edx, edi
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004788d9  e9c7feffff             -jmp 0x4787a5
    goto L_0x004787a5;
L_0x004788de:
    // 004788de  8b7620                 -mov esi, dword ptr [esi + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004788e1  3b3e                   +cmp edi, dword ptr [esi]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004788e3  e998feffff             -jmp 0x478780
    goto L_0x00478780;
L_0x004788e8:
    // 004788e8  3b7104                 +cmp esi, dword ptr [ecx + 4]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004788eb  7514                   -jne 0x478901
    if (!cpu.flags.zf)
    {
        goto L_0x00478901;
    }
    // 004788ed  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004788ef  e8a4b10100             -call 0x493a98
    cpu.esp -= 4;
    sub_493a98(app, cpu);
    if (cpu.terminate) return;
    // 004788f4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004788f6  7528                   -jne 0x478920
    if (!cpu.flags.zf)
    {
        goto L_0x00478920;
    }
L_0x004788f8:
    // 004788f8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004788fa  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004788fd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004788fe  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004788ff  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478900  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00478901:
    // 00478901  8b3e                   -mov edi, dword ptr [esi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi);
    // 00478903  037e10                 -add edi, dword ptr [esi + 0x10]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */)));
    // 00478906  f6c340                 +test bl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 64 /*0x40*/));
    // 00478909  7508                   -jne 0x478913
    if (!cpu.flags.zf)
    {
        goto L_0x00478913;
    }
L_0x0047890b:
    // 0047890b  8b7620                 -mov esi, dword ptr [esi + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 0047890e  e967feffff             -jmp 0x47877a
    goto L_0x0047877a;
L_0x00478913:
    // 00478913  8b510c                 -mov edx, dword ptr [ecx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00478916  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00478918  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 0047891a  f7d0                   -not eax
    cpu.eax = ~cpu.eax;
    // 0047891c  21c7                   +and edi, eax
    cpu.clear_co();
    cpu.set_szp((cpu.edi &= x86::reg32(x86::sreg32(cpu.eax))));
    // 0047891e  ebeb                   -jmp 0x47890b
    goto L_0x0047890b;
L_0x00478920:
    // 00478920  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00478922  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00478925  e8aeae0100             -call 0x4937d8
    cpu.esp -= 4;
    sub_4937d8(app, cpu);
    if (cpu.terminate) return;
    // 0047892a  e93bfeffff             -jmp 0x47876a
    goto L_0x0047876a;
L_0x0047892f:
    // 0047892f  833db8844c0000         +cmp dword ptr [0x4c84b8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5014712) /* 0x4c84b8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00478936  0f85c8000000           -jne 0x478a04
    if (!cpu.flags.zf)
    {
        goto L_0x00478a04;
    }
L_0x0047893c:
    // 0047893c  8b7904                 -mov edi, dword ptr [ecx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0047893f  8b7724                 -mov esi, dword ptr [edi + 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */);
    // 00478942  8b3f                   -mov edi, dword ptr [edi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi);
    // 00478944  f6c340                 +test bl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 64 /*0x40*/));
    // 00478947  0f85cf000000           -jne 0x478a1c
    if (!cpu.flags.zf)
    {
        goto L_0x00478a1c;
    }
L_0x0047894d:
    // 0047894d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047894f  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
L_0x00478953:
    // 00478953  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00478955  034610                 -add eax, dword ptr [esi + 0x10]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */)));
    // 00478958  f6c340                 +test bl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 64 /*0x40*/));
    // 0047895b  740c                   -je 0x478969
    if (cpu.flags.zf)
    {
        goto L_0x00478969;
    }
    // 0047895d  8b510c                 -mov edx, dword ptr [ecx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00478960  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00478962  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00478965  f7d0                   -not eax
    cpu.eax = ~cpu.eax;
    // 00478967  21d0                   -and eax, edx
    cpu.eax &= x86::reg32(x86::sreg32(cpu.edx));
L_0x00478969:
    // 00478969  39f8                   +cmp eax, edi
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
    // 0047896b  0f83b7000000           -jae 0x478a28
    if (!cpu.flags.cf)
    {
        goto L_0x00478a28;
    }
    // 00478971  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00478973  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00478975  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
L_0x00478979:
    // 00478979  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0047897d  3b0424                 +cmp eax, dword ptr [esp]
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
    // 00478980  0f8cc0000000           -jl 0x478a46
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00478a46;
    }
    // 00478986  8b2d34b75100           -mov ebp, dword ptr [0x51b734]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5355316) /* 0x51b734 */);
    // 0047898c  8b15b4844c00           -mov edx, dword ptr [0x4c84b4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5014708) /* 0x4c84b4 */);
    // 00478992  895d18                 -mov dword ptr [ebp + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 00478995  896c2404               -mov dword ptr [esp + 4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 00478999  8b4520                 -mov eax, dword ptr [ebp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 0047899c  89551c                 -mov dword ptr [ebp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 0047899f  bb0c000000             -mov ebx, 0xc
    cpu.ebx = 12 /*0xc*/;
    // 004789a4  a334b75100             -mov dword ptr [0x51b734], eax
    app->getMemory<x86::reg32>(x86::reg32(5355316) /* 0x51b734 */) = cpu.eax;
    // 004789a9  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004789ad  42                     -inc edx
    (cpu.edx)++;
    // 004789ae  894514                 -mov dword ptr [ebp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004789b1  8915b4844c00           -mov dword ptr [0x4c84b4], edx
    app->getMemory<x86::reg32>(x86::reg32(5014708) /* 0x4c84b4 */) = cpu.edx;
    // 004789b7  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004789ba  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004789be  894510                 -mov dword ptr [ebp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004789c1  8d4504                 -lea eax, [ebp + 4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 004789c4  e8331a0000             -call 0x47a3fc
    cpu.esp -= 4;
    sub_47a3fc(app, cpu);
    if (cpu.terminate) return;
    // 004789c9  2b3c24                 -sub edi, dword ptr [esp]
    (cpu.edi) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
    // 004789cc  897524                 -mov dword ptr [ebp + 0x24], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */) = cpu.esi;
    // 004789cf  897d00                 -mov dword ptr [ebp], edi
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.edi;
    // 004789d2  8b4620                 -mov eax, dword ptr [esi + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004789d5  894520                 -mov dword ptr [ebp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 004789d8  896824                 -mov dword ptr [eax + 0x24], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = cpu.ebp;
    // 004789db  896e20                 -mov dword ptr [esi + 0x20], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = cpu.ebp;
    // 004789de  83791400               +cmp dword ptr [ecx + 0x14], 0
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
    // 004789e2  7407                   -je 0x4789eb
    if (cpu.flags.zf)
    {
        goto L_0x004789eb;
    }
    // 004789e4  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004789e6  e8b5ac0100             -call 0x4936a0
    cpu.esp -= 4;
    sub_4936a0(app, cpu);
    if (cpu.terminate) return;
L_0x004789eb:
    // 004789eb  833db8844c0000         +cmp dword ptr [0x4c84b8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5014712) /* 0x4c84b8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004789f2  7405                   -je 0x4789f9
    if (cpu.flags.zf)
    {
        goto L_0x004789f9;
    }
    // 004789f4  e8eb020000             -call 0x478ce4
    cpu.esp -= 4;
    sub_478ce4(app, cpu);
    if (cpu.terminate) return;
L_0x004789f9:
    // 004789f9  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004789fd  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00478a00  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478a01  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478a02  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478a03  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00478a04:
    // 00478a04  f6c310                 +test bl, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 16 /*0x10*/));
    // 00478a07  0f852fffffff           -jne 0x47893c
    if (!cpu.flags.zf)
    {
        goto L_0x0047893c;
    }
    // 00478a0d  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00478a0f  8b5104                 -mov edx, dword ptr [ecx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00478a12  e8d1ae0100             -call 0x4938e8
    cpu.esp -= 4;
    sub_4938e8(app, cpu);
    if (cpu.terminate) return;
    // 00478a17  e920ffffff             -jmp 0x47893c
    goto L_0x0047893c;
L_0x00478a1c:
    // 00478a1c  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00478a1f  f7d0                   -not eax
    cpu.eax = ~cpu.eax;
    // 00478a21  21c7                   +and edi, eax
    cpu.clear_co();
    cpu.set_szp((cpu.edi &= x86::reg32(x86::sreg32(cpu.eax))));
    // 00478a23  e925ffffff             -jmp 0x47894d
    goto L_0x0047894d;
L_0x00478a28:
    // 00478a28  8b3e                   -mov edi, dword ptr [esi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi);
    // 00478a2a  f6c340                 +test bl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 64 /*0x40*/));
    // 00478a2d  7407                   -je 0x478a36
    if (cpu.flags.zf)
    {
        goto L_0x00478a36;
    }
    // 00478a2f  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00478a32  f7d0                   -not eax
    cpu.eax = ~cpu.eax;
    // 00478a34  21c7                   -and edi, eax
    cpu.edi &= x86::reg32(x86::sreg32(cpu.eax));
L_0x00478a36:
    // 00478a36  3b31                   +cmp esi, dword ptr [ecx]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00478a38  0f843bffffff           -je 0x478979
    if (cpu.flags.zf)
    {
        goto L_0x00478979;
    }
    // 00478a3e  8b7624                 -mov esi, dword ptr [esi + 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 00478a41  e90dffffff             -jmp 0x478953
    goto L_0x00478953;
L_0x00478a46:
    // 00478a46  3b31                   +cmp esi, dword ptr [ecx]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00478a48  7418                   -je 0x478a62
    if (cpu.flags.zf)
    {
        goto L_0x00478a62;
    }
    // 00478a4a  8b3e                   -mov edi, dword ptr [esi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi);
    // 00478a4c  f6c340                 +test bl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 64 /*0x40*/));
    // 00478a4f  7508                   -jne 0x478a59
    if (!cpu.flags.zf)
    {
        goto L_0x00478a59;
    }
L_0x00478a51:
    // 00478a51  8b7624                 -mov esi, dword ptr [esi + 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 00478a54  e9f4feffff             -jmp 0x47894d
    goto L_0x0047894d;
L_0x00478a59:
    // 00478a59  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00478a5c  f7d0                   -not eax
    cpu.eax = ~cpu.eax;
    // 00478a5e  21c7                   +and edi, eax
    cpu.clear_co();
    cpu.set_szp((cpu.edi &= x86::reg32(x86::sreg32(cpu.eax))));
    // 00478a60  ebef                   -jmp 0x478a51
    goto L_0x00478a51;
L_0x00478a62:
    // 00478a62  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00478a64  e82fb00100             -call 0x493a98
    cpu.esp -= 4;
    sub_493a98(app, cpu);
    if (cpu.terminate) return;
    // 00478a69  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00478a6b  0f8487feffff           -je 0x4788f8
    if (cpu.flags.zf)
    {
        goto L_0x004788f8;
    }
    // 00478a71  8b5104                 -mov edx, dword ptr [ecx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00478a74  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00478a76  e86dae0100             -call 0x4938e8
    cpu.esp -= 4;
    sub_4938e8(app, cpu);
    if (cpu.terminate) return;
    // 00478a7b  e9bcfeffff             -jmp 0x47893c
    goto L_0x0047893c;
}

/* align: skip  */
void Application::sub_478a80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478a80  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00478a81  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00478a82  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00478a84  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00478a86  742e                   -je 0x478ab6
    if (cpu.flags.zf)
    {
        goto L_0x00478ab6;
    }
    // 00478a88  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00478a8a:
    // 00478a8a  8b93b4b55100           -mov edx, dword ptr [ebx + 0x51b5b4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5354932) /* 0x51b5b4 */);
    // 00478a90  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00478a92  7417                   -je 0x478aab
    if (cpu.flags.zf)
    {
        goto L_0x00478aab;
    }
    // 00478a94  8b83b0b55100           -mov eax, dword ptr [ebx + 0x51b5b0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5354928) /* 0x51b5b0 */);
L_0x00478a9a:
    // 00478a9a  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 00478a9d  3b08                   +cmp ecx, dword ptr [eax]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00478a9f  7404                   -je 0x478aa5
    if (cpu.flags.zf)
    {
        goto L_0x00478aa5;
    }
    // 00478aa1  39d0                   +cmp eax, edx
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
    // 00478aa3  75f5                   -jne 0x478a9a
    if (!cpu.flags.zf)
    {
        goto L_0x00478a9a;
    }
L_0x00478aa5:
    // 00478aa5  f6401980               +test byte ptr [eax + 0x19], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(25) /* 0x19 */) & 128 /*0x80*/));
    // 00478aa9  740d                   -je 0x478ab8
    if (cpu.flags.zf)
    {
        goto L_0x00478ab8;
    }
L_0x00478aab:
    // 00478aab  83c318                 -add ebx, 0x18
    (cpu.ebx) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00478aae  81fb80010000           +cmp ebx, 0x180
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(384 /*0x180*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00478ab4  7cd4                   -jl 0x478a8a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00478a8a;
    }
L_0x00478ab6:
    // 00478ab6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00478ab8:
    // 00478ab8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478ab9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478aba  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_478abc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478abc  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00478abd  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00478ac2  e8b9ffffff             -call 0x478a80
    cpu.esp -= 4;
    sub_478a80(app, cpu);
    if (cpu.terminate) return;
    // 00478ac7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478ac8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_478acc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478acc  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00478acd  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00478ad2  e8a9ffffff             -call 0x478a80
    cpu.esp -= 4;
    sub_478a80(app, cpu);
    if (cpu.terminate) return;
    // 00478ad7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00478ad9  a130b75100             -mov eax, dword ptr [0x51b730]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355312) /* 0x51b730 */);
    // 00478ade  e86dab0100             -call 0x493650
    cpu.esp -= 4;
    sub_493650(app, cpu);
    if (cpu.terminate) return;
    // 00478ae3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00478ae5  e82e000000             -call 0x478b18
    cpu.esp -= 4;
    sub_478b18(app, cpu);
    if (cpu.terminate) return;
    // 00478aea  a130b75100             -mov eax, dword ptr [0x51b730]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355312) /* 0x51b730 */);
    // 00478aef  e864ab0100             -call 0x493658
    cpu.esp -= 4;
    sub_493658(app, cpu);
    if (cpu.terminate) return;
    // 00478af4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478af5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_478af8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478af8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00478af9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00478afb  a130b75100             -mov eax, dword ptr [0x51b730]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355312) /* 0x51b730 */);
    // 00478b00  e84bab0100             -call 0x493650
    cpu.esp -= 4;
    sub_493650(app, cpu);
    if (cpu.terminate) return;
    // 00478b05  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00478b07  e80c000000             -call 0x478b18
    cpu.esp -= 4;
    sub_478b18(app, cpu);
    if (cpu.terminate) return;
    // 00478b0c  a130b75100             -mov eax, dword ptr [0x51b730]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355312) /* 0x51b730 */);
    // 00478b11  e842ab0100             -call 0x493658
    cpu.esp -= 4;
    sub_493658(app, cpu);
    if (cpu.terminate) return;
    // 00478b16  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478b17  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_478b18(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478b18  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00478b19  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00478b1b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00478b1d  743a                   -je 0x478b59
    if (cpu.flags.zf)
    {
        goto L_0x00478b59;
    }
    // 00478b1f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00478b20  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00478b21  8b5824                 -mov ebx, dword ptr [eax + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 00478b24  8b4820                 -mov ecx, dword ptr [eax + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 00478b27  894b20                 -mov dword ptr [ebx + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00478b2a  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00478b2c  8b4824                 -mov ecx, dword ptr [eax + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 00478b2f  894b24                 -mov dword ptr [ebx + 0x24], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */) = cpu.ecx;
    // 00478b32  8b4818                 -mov ecx, dword ptr [eax + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00478b35  81e1000f0000           -and ecx, 0xf00
    cpu.ecx &= x86::reg32(x86::sreg32(3840 /*0xf00*/));
    // 00478b3b  81f900030000           +cmp ecx, 0x300
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(768 /*0x300*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00478b41  7418                   -je 0x478b5b
    if (cpu.flags.zf)
    {
        goto L_0x00478b5b;
    }
L_0x00478b43:
    // 00478b43  a134b75100             -mov eax, dword ptr [0x51b734]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355316) /* 0x51b734 */);
    // 00478b48  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 00478b4e  891534b75100           -mov dword ptr [0x51b734], edx
    app->getMemory<x86::reg32>(x86::reg32(5355316) /* 0x51b734 */) = cpu.edx;
    // 00478b54  894220                 -mov dword ptr [edx + 0x20], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 00478b57  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478b58  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00478b59:
    // 00478b59  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478b5a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00478b5b:
    // 00478b5b  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00478b5d  e886850100             -call 0x4910e8
    cpu.esp -= 4;
    sub_4910e8(app, cpu);
    if (cpu.terminate) return;
    // 00478b62  ebdf                   -jmp 0x478b43
    goto L_0x00478b43;
}

/* align: skip  */
void Application::sub_478b64(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478b64  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00478b65  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00478b6a  e811ffffff             -call 0x478a80
    cpu.esp -= 4;
    sub_478a80(app, cpu);
    if (cpu.terminate) return;
    // 00478b6f  e804000000             -call 0x478b78
    cpu.esp -= 4;
    sub_478b78(app, cpu);
    if (cpu.terminate) return;
    // 00478b74  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478b75  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_478b78(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478b78  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00478b79  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00478b7b  a130b75100             -mov eax, dword ptr [0x51b730]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355312) /* 0x51b730 */);
    // 00478b80  e8cbaa0100             -call 0x493650
    cpu.esp -= 4;
    sub_493650(app, cpu);
    if (cpu.terminate) return;
    // 00478b85  8b5220                 -mov edx, dword ptr [edx + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 00478b88  f6421820               +test byte ptr [edx + 0x18], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(24) /* 0x18 */) & 32 /*0x20*/));
    // 00478b8c  7512                   -jne 0x478ba0
    if (!cpu.flags.zf)
    {
        goto L_0x00478ba0;
    }
L_0x00478b8e:
    // 00478b8e  8b5220                 -mov edx, dword ptr [edx + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 00478b91  8b4224                 -mov eax, dword ptr [edx + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */);
    // 00478b94  e87fffffff             -call 0x478b18
    cpu.esp -= 4;
    sub_478b18(app, cpu);
    if (cpu.terminate) return;
    // 00478b99  f6421820               +test byte ptr [edx + 0x18], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(24) /* 0x18 */) & 32 /*0x20*/));
    // 00478b9d  74ef                   -je 0x478b8e
    if (cpu.flags.zf)
    {
        goto L_0x00478b8e;
    }
    // 00478b9f  90                     -nop 
    ;
L_0x00478ba0:
    // 00478ba0  a130b75100             -mov eax, dword ptr [0x51b730]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355312) /* 0x51b730 */);
    // 00478ba5  e8aeaa0100             -call 0x493658
    cpu.esp -= 4;
    sub_493658(app, cpu);
    if (cpu.terminate) return;
    // 00478baa  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478bab  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_478bac(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478bac  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00478bad  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00478baf  a130b75100             -mov eax, dword ptr [0x51b730]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355312) /* 0x51b730 */);
    // 00478bb4  e897aa0100             -call 0x493650
    cpu.esp -= 4;
    sub_493650(app, cpu);
    if (cpu.terminate) return;
    // 00478bb9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00478bbb  e810000000             -call 0x478bd0
    cpu.esp -= 4;
    sub_478bd0(app, cpu);
    if (cpu.terminate) return;
    // 00478bc0  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00478bc2  a130b75100             -mov eax, dword ptr [0x51b730]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355312) /* 0x51b730 */);
    // 00478bc7  e88caa0100             -call 0x493658
    cpu.esp -= 4;
    sub_493658(app, cpu);
    if (cpu.terminate) return;
    // 00478bcc  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00478bce  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478bcf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_478bd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478bd0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00478bd1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00478bd2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00478bd3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00478bd4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00478bd5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00478bd6  8b35b4844c00           -mov esi, dword ptr [0x4c84b4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5014708) /* 0x4c84b4 */);
    // 00478bdc  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00478bde  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00478be0  81e2000f0000           -and edx, 0xf00
    cpu.edx &= x86::reg32(x86::sreg32(3840 /*0xf00*/));
    // 00478be6  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 00478be9  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00478bf0  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00478bf2  bdb0b55100             -mov ebp, 0x51b5b0
    cpu.ebp = 5354928 /*0x51b5b0*/;
    // 00478bf7  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00478bfa  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 00478bfc  83e107                 -and ecx, 7
    cpu.ecx &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 00478bff  8b4500                 -mov eax, dword ptr [ebp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp);
    // 00478c02  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00478c04  8b5504                 -mov edx, dword ptr [ebp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 00478c07  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 00478c0a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00478c0c  39d0                   +cmp eax, edx
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
    // 00478c0e  7429                   -je 0x478c39
    if (cpu.flags.zf)
    {
        goto L_0x00478c39;
    }
L_0x00478c10:
    // 00478c10  f6401808               +test byte ptr [eax + 0x18], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(24) /* 0x18 */) & 8 /*0x8*/));
    // 00478c14  741b                   -je 0x478c31
    if (cpu.flags.zf)
    {
        goto L_0x00478c31;
    }
    // 00478c16  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00478c19  83e207                 -and edx, 7
    cpu.edx &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 00478c1c  39ca                   +cmp edx, ecx
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
    // 00478c1e  7632                   -jbe 0x478c52
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00478c52;
    }
L_0x00478c20:
    // 00478c20  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00478c22  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00478c24  8b581c                 -mov ebx, dword ptr [eax + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00478c27  8b4818                 -mov ecx, dword ptr [eax + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00478c2a  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00478c2c  83e107                 -and ecx, 7
    cpu.ecx &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 00478c2f  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
L_0x00478c31:
    // 00478c31  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 00478c34  3b4504                 +cmp eax, dword ptr [ebp + 4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00478c37  75d7                   -jne 0x478c10
    if (!cpu.flags.zf)
    {
        goto L_0x00478c10;
    }
L_0x00478c39:
    // 00478c39  8935b4844c00           -mov dword ptr [0x4c84b4], esi
    app->getMemory<x86::reg32>(x86::reg32(5014708) /* 0x4c84b4 */) = cpu.esi;
    // 00478c3f  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00478c41  751c                   -jne 0x478c5f
    if (!cpu.flags.zf)
    {
        goto L_0x00478c5f;
    }
    // 00478c43  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00478c45  8b35b4844c00           -mov esi, dword ptr [0x4c84b4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5014708) /* 0x4c84b4 */);
    // 00478c4b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478c4c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478c4d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478c4e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478c4f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478c50  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478c51  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00478c52:
    // 00478c52  75dd                   -jne 0x478c31
    if (!cpu.flags.zf)
    {
        goto L_0x00478c31;
    }
    // 00478c54  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00478c56  2b501c                 -sub edx, dword ptr [eax + 0x1c]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */)));
    // 00478c59  39da                   +cmp edx, ebx
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
    // 00478c5b  73c3                   -jae 0x478c20
    if (!cpu.flags.cf)
    {
        goto L_0x00478c20;
    }
    // 00478c5d  ebd2                   -jmp 0x478c31
    goto L_0x00478c31;
L_0x00478c5f:
    // 00478c5f  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00478c61  e8b2feffff             -call 0x478b18
    cpu.esp -= 4;
    sub_478b18(app, cpu);
    if (cpu.terminate) return;
    // 00478c66  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00478c6b  8b35b4844c00           -mov esi, dword ptr [0x4c84b4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5014708) /* 0x4c84b4 */);
    // 00478c71  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478c72  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478c73  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478c74  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478c75  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478c76  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478c77  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_478c78(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478c78  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00478c79  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00478c7a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00478c7b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00478c7c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00478c7e  81e2000f0000           -and edx, 0xf00
    cpu.edx &= x86::reg32(x86::sreg32(3840 /*0xf00*/));
    // 00478c84  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 00478c87  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00478c8e  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00478c90  bfb0b55100             -mov edi, 0x51b5b0
    cpu.edi = 5354928 /*0x51b5b0*/;
    // 00478c95  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00478c98  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00478c9a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00478c9c  e8bfa90100             -call 0x493660
    cpu.esp -= 4;
    sub_493660(app, cpu);
    if (cpu.terminate) return;
    // 00478ca1  8b0f                   -mov ecx, dword ptr [edi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi);
    // 00478ca3  8b5704                 -mov edx, dword ptr [edi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00478ca6  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00478ca8  39d1                   +cmp ecx, edx
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
    // 00478caa  741b                   -je 0x478cc7
    if (cpu.flags.zf)
    {
        goto L_0x00478cc7;
    }
L_0x00478cac:
    // 00478cac  bb0c000000             -mov ebx, 0xc
    cpu.ebx = 12 /*0xc*/;
    // 00478cb1  8d5104                 -lea edx, [ecx + 4]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00478cb4  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00478cb6  e8e8190100             -call 0x48a6a3
    cpu.esp -= 4;
    sub_48a6a3(app, cpu);
    if (cpu.terminate) return;
    // 00478cbb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00478cbd  740f                   -je 0x478cce
    if (cpu.flags.zf)
    {
        goto L_0x00478cce;
    }
    // 00478cbf  8b4920                 -mov ecx, dword ptr [ecx + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00478cc2  3b4f04                 +cmp ecx, dword ptr [edi + 4]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00478cc5  75e5                   -jne 0x478cac
    if (!cpu.flags.zf)
    {
        goto L_0x00478cac;
    }
L_0x00478cc7:
    // 00478cc7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00478cc9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478cca  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478ccb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478ccc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478ccd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00478cce:
    // 00478cce  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00478cd0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478cd1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478cd2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478cd3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478cd4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_478cd8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478cd8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00478cd9  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00478cdb  e898ffffff             -call 0x478c78
    cpu.esp -= 4;
    sub_478c78(app, cpu);
    if (cpu.terminate) return;
    // 00478ce0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478ce1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_478ce4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478ce4  833dbc844c0000         +cmp dword ptr [0x4c84bc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5014716) /* 0x4c84bc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00478ceb  7503                   -jne 0x478cf0
    if (!cpu.flags.zf)
    {
        goto L_0x00478cf0;
    }
    // 00478ced  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00478cef  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00478cf0:
    // 00478cf0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00478cf2  e83d000000             -call 0x478d34
    cpu.esp -= 4;
    sub_478d34(app, cpu);
    if (cpu.terminate) return;
    // 00478cf7  3b053cb75100           +cmp eax, dword ptr [0x51b73c]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5355324) /* 0x51b73c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00478cfd  7d05                   -jge 0x478d04
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00478d04;
    }
    // 00478cff  a33cb75100             -mov dword ptr [0x51b73c], eax
    app->getMemory<x86::reg32>(x86::reg32(5355324) /* 0x51b73c */) = cpu.eax;
L_0x00478d04:
    // 00478d04  a13cb75100             -mov eax, dword ptr [0x51b73c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355324) /* 0x51b73c */);
    // 00478d09  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_478d0c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478d0c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00478d0e  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
    // 00478d10  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00478d11  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00478d13  a130b75100             -mov eax, dword ptr [0x51b730]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355312) /* 0x51b730 */);
    // 00478d18  e833a90100             -call 0x493650
    cpu.esp -= 4;
    sub_493650(app, cpu);
    if (cpu.terminate) return;
    // 00478d1d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00478d1f  e810000000             -call 0x478d34
    cpu.esp -= 4;
    sub_478d34(app, cpu);
    if (cpu.terminate) return;
    // 00478d24  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00478d26  a130b75100             -mov eax, dword ptr [0x51b730]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355312) /* 0x51b730 */);
    // 00478d2b  e828a90100             -call 0x493658
    cpu.esp -= 4;
    sub_493658(app, cpu);
    if (cpu.terminate) return;
    // 00478d30  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00478d32  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478d33  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_478d34(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478d34  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00478d35  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00478d36  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00478d37  25000f0000             -and eax, 0xf00
    cpu.eax &= x86::reg32(x86::sreg32(3840 /*0xf00*/));
    // 00478d3c  3d00030000             +cmp eax, 0x300
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(768 /*0x300*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00478d41  7456                   -je 0x478d99
    if (cpu.flags.zf)
    {
        goto L_0x00478d99;
    }
    // 00478d43  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 00478d46  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00478d48  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00478d4b  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00478d4d  beb0b55100             -mov esi, 0x51b5b0
    cpu.esi = 5354928 /*0x51b5b0*/;
    // 00478d52  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00478d55  8b15b8844c00           -mov edx, dword ptr [0x4c84b8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5014712) /* 0x4c84b8 */);
    // 00478d5b  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00478d5d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00478d5f  7541                   -jne 0x478da2
    if (!cpu.flags.zf)
    {
        goto L_0x00478da2;
    }
L_0x00478d61:
    // 00478d61  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00478d62  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00478d63  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00478d64  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 00478d66  8b7e04                 -mov edi, dword ptr [esi + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00478d69  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00478d6b  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00478d6e  8b7f20                 -mov edi, dword ptr [edi + 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */);
L_0x00478d71:
    // 00478d71  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00478d73  2b11                   -sub edx, dword ptr [ecx]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx)));
    // 00478d75  8b6910                 -mov ebp, dword ptr [ecx + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00478d78  8b4e14                 -mov ecx, dword ptr [esi + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00478d7b  29ea                   -sub edx, ebp
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00478d7d  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00478d7f  39da                   +cmp edx, ebx
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
    // 00478d81  7e02                   -jle 0x478d85
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00478d85;
    }
    // 00478d83  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
L_0x00478d85:
    // 00478d85  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00478d87  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 00478d8a  39f8                   +cmp eax, edi
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
    // 00478d8c  75e3                   -jne 0x478d71
    if (!cpu.flags.zf)
    {
        goto L_0x00478d71;
    }
    // 00478d8e  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00478d90  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478d91  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478d92  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00478d93:
    // 00478d93  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00478d95  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478d96  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478d97  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478d98  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00478d99:
    // 00478d99  e8a2af0100             -call 0x493d40
    cpu.esp -= 4;
    sub_493d40(app, cpu);
    if (cpu.terminate) return;
    // 00478d9e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00478da0  ebf1                   -jmp 0x478d93
    goto L_0x00478d93;
L_0x00478da2:
    // 00478da2  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00478da4  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00478da7  e82caa0100             -call 0x4937d8
    cpu.esp -= 4;
    sub_4937d8(app, cpu);
    if (cpu.terminate) return;
    // 00478dac  ebb3                   -jmp 0x478d61
    goto L_0x00478d61;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_478db0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478db0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00478db1  8b15a0844c00           -mov edx, dword ptr [0x4c84a0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5014688) /* 0x4c84a0 */);
    // 00478db7  81faf8b55100           +cmp edx, 0x51b5f8
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5355000 /*0x51b5f8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00478dbd  741c                   -je 0x478ddb
    if (cpu.flags.zf)
    {
        goto L_0x00478ddb;
    }
    // 00478dbf  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00478dc1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00478dc3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00478dc5  7410                   -je 0x478dd7
    if (cpu.flags.zf)
    {
        goto L_0x00478dd7;
    }
L_0x00478dc7:
    // 00478dc7  f6401818               +test byte ptr [eax + 0x18], 0x18
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(24) /* 0x18 */) & 24 /*0x18*/));
    // 00478dcb  7503                   -jne 0x478dd0
    if (!cpu.flags.zf)
    {
        goto L_0x00478dd0;
    }
    // 00478dcd  035010                 -add edx, dword ptr [eax + 0x10]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */)));
L_0x00478dd0:
    // 00478dd0  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 00478dd3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00478dd5  75f0                   -jne 0x478dc7
    if (!cpu.flags.zf)
    {
        goto L_0x00478dc7;
    }
L_0x00478dd7:
    // 00478dd7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00478dd9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478dda  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00478ddb:
    // 00478ddb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00478ddd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478dde  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_478de0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478de0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00478de1  8b15a0844c00           -mov edx, dword ptr [0x4c84a0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5014688) /* 0x4c84a0 */);
    // 00478de7  81faf8b55100           +cmp edx, 0x51b5f8
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5355000 /*0x51b5f8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00478ded  741c                   -je 0x478e0b
    if (cpu.flags.zf)
    {
        goto L_0x00478e0b;
    }
    // 00478def  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00478df1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00478df3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00478df5  7410                   -je 0x478e07
    if (cpu.flags.zf)
    {
        goto L_0x00478e07;
    }
L_0x00478df7:
    // 00478df7  f6401810               +test byte ptr [eax + 0x18], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(24) /* 0x18 */) & 16 /*0x10*/));
    // 00478dfb  7403                   -je 0x478e00
    if (cpu.flags.zf)
    {
        goto L_0x00478e00;
    }
    // 00478dfd  035010                 -add edx, dword ptr [eax + 0x10]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */)));
L_0x00478e00:
    // 00478e00  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 00478e03  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00478e05  75f0                   -jne 0x478df7
    if (!cpu.flags.zf)
    {
        goto L_0x00478df7;
    }
L_0x00478e07:
    // 00478e07  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00478e09  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478e0a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00478e0b:
    // 00478e0b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00478e0d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478e0e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_478e10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478e10  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00478e11  8b15a0844c00           -mov edx, dword ptr [0x4c84a0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5014688) /* 0x4c84a0 */);
    // 00478e17  81faf8b55100           +cmp edx, 0x51b5f8
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5355000 /*0x51b5f8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00478e1d  741c                   -je 0x478e3b
    if (cpu.flags.zf)
    {
        goto L_0x00478e3b;
    }
    // 00478e1f  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00478e21  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00478e23  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00478e25  7410                   -je 0x478e37
    if (cpu.flags.zf)
    {
        goto L_0x00478e37;
    }
L_0x00478e27:
    // 00478e27  f6401808               +test byte ptr [eax + 0x18], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(24) /* 0x18 */) & 8 /*0x8*/));
    // 00478e2b  7403                   -je 0x478e30
    if (cpu.flags.zf)
    {
        goto L_0x00478e30;
    }
    // 00478e2d  035010                 -add edx, dword ptr [eax + 0x10]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */)));
L_0x00478e30:
    // 00478e30  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 00478e33  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00478e35  75f0                   -jne 0x478e27
    if (!cpu.flags.zf)
    {
        goto L_0x00478e27;
    }
L_0x00478e37:
    // 00478e37  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00478e39  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478e3a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00478e3b:
    // 00478e3b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00478e3d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478e3e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_478e40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478e40  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00478e41  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00478e42  8b35a0844c00           -mov esi, dword ptr [0x4c84a0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5014688) /* 0x4c84a0 */);
    // 00478e48  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00478e4a  81fef8b55100           +cmp esi, 0x51b5f8
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5355000 /*0x51b5f8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00478e50  7420                   -je 0x478e72
    if (cpu.flags.zf)
    {
        goto L_0x00478e72;
    }
    // 00478e52  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00478e53  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00478e54  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00478e56  8b5020                 -mov edx, dword ptr [eax + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
L_0x00478e59:
    // 00478e59  3b4604                 +cmp eax, dword ptr [esi + 4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00478e5c  7422                   -je 0x478e80
    if (cpu.flags.zf)
    {
        goto L_0x00478e80;
    }
    // 00478e5e  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 00478e60  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00478e63  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00478e65  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 00478e67  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00478e69  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00478e6b  01d9                   +add ecx, ebx
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
    // 00478e6d  8b5220                 -mov edx, dword ptr [edx + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 00478e70  ebe7                   -jmp 0x478e59
    goto L_0x00478e59;
L_0x00478e72:
    // 00478e72  e8c9ae0100             -call 0x493d40
    cpu.esp -= 4;
    sub_493d40(app, cpu);
    if (cpu.terminate) return;
    // 00478e77  8b35a0844c00           -mov esi, dword ptr [0x4c84a0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5014688) /* 0x4c84a0 */);
    // 00478e7d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478e7e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478e7f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00478e80:
    // 00478e80  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00478e82  8935a0844c00           -mov dword ptr [0x4c84a0], esi
    app->getMemory<x86::reg32>(x86::reg32(5014688) /* 0x4c84a0 */) = cpu.esi;
    // 00478e88  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478e89  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478e8a  8b35a0844c00           -mov esi, dword ptr [0x4c84a0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5014688) /* 0x4c84a0 */);
    // 00478e90  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478e91  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478e92  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_478e94(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478e94  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00478e95  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00478e96  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00478e97  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00478e99  81e2000f0000           -and edx, 0xf00
    cpu.edx &= x86::reg32(x86::sreg32(3840 /*0xf00*/));
    // 00478e9f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00478ea1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00478ea3  81fa00030000           +cmp edx, 0x300
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(768 /*0x300*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00478ea9  7450                   -je 0x478efb
    if (cpu.flags.zf)
    {
        goto L_0x00478efb;
    }
    // 00478eab  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00478eac  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00478ead  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00478eae  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 00478eb1  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00478eb3  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 00478eb6  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00478eb8  bfb0b55100             -mov edi, 0x51b5b0
    cpu.edi = 5354928 /*0x51b5b0*/;
    // 00478ebd  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 00478ec0  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 00478ec2  8b0f                   -mov ecx, dword ptr [edi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi);
    // 00478ec4  8b7704                 -mov esi, dword ptr [edi + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00478ec7  8b5120                 -mov edx, dword ptr [ecx + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00478eca  39f1                   +cmp ecx, esi
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
    // 00478ecc  7424                   -je 0x478ef2
    if (cpu.flags.zf)
    {
        goto L_0x00478ef2;
    }
L_0x00478ece:
    // 00478ece  8b31                   -mov esi, dword ptr [ecx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx);
    // 00478ed0  8b4910                 -mov ecx, dword ptr [ecx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00478ed3  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
    // 00478ed5  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 00478ed7  29ce                   -sub esi, ecx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00478ed9  8a4a18                 -mov cl, byte ptr [edx + 0x18]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 00478edc  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00478ede  f6c108                 +test cl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 8 /*0x8*/));
    // 00478ee1  7421                   -je 0x478f04
    if (cpu.flags.zf)
    {
        goto L_0x00478f04;
    }
    // 00478ee3  034210                 -add eax, dword ptr [edx + 0x10]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */)));
L_0x00478ee6:
    // 00478ee6  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00478ee8  8b6f04                 -mov ebp, dword ptr [edi + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00478eeb  8b5220                 -mov edx, dword ptr [edx + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 00478eee  39e9                   +cmp ecx, ebp
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
    // 00478ef0  75dc                   -jne 0x478ece
    if (!cpu.flags.zf)
    {
        goto L_0x00478ece;
    }
L_0x00478ef2:
    // 00478ef2  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00478ef4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478ef5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478ef6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478ef7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478ef8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478ef9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478efa  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00478efb:
    // 00478efb  e840ae0100             -call 0x493d40
    cpu.esp -= 4;
    sub_493d40(app, cpu);
    if (cpu.terminate) return;
    // 00478f00  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478f01  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478f02  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478f03  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00478f04:
    // 00478f04  39d8                   +cmp eax, ebx
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
    // 00478f06  7e02                   -jle 0x478f0a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00478f0a;
    }
    // 00478f08  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x00478f0a:
    // 00478f0a  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00478f0c  ebd8                   -jmp 0x478ee6
    goto L_0x00478ee6;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_478f10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478f10  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00478f11  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00478f12  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00478f14  a334b75100             -mov dword ptr [0x51b734], eax
    app->getMemory<x86::reg32>(x86::reg32(5355316) /* 0x51b734 */) = cpu.eax;
    // 00478f19  49                     -dec ecx
    (cpu.ecx)--;
    // 00478f1a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00478f1c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00478f1e  7e10                   -jle 0x478f30
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00478f30;
    }
L_0x00478f20:
    // 00478f20  8d5828                 -lea ebx, [eax + 0x28]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 00478f23  42                     -inc edx
    (cpu.edx)++;
    // 00478f24  895820                 -mov dword ptr [eax + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 00478f27  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00478f29  39ca                   +cmp edx, ecx
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
    // 00478f2b  7cf3                   -jl 0x478f20
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00478f20;
    }
    // 00478f2d  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x00478f30:
    // 00478f30  c7402000000000         -mov dword ptr [eax + 0x20], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 00478f37  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478f38  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478f39  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_478f3c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478f3c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00478f3d  8b1534b75100           -mov edx, dword ptr [0x51b734]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5355316) /* 0x51b734 */);
    // 00478f43  a334b75100             -mov dword ptr [0x51b734], eax
    app->getMemory<x86::reg32>(x86::reg32(5355316) /* 0x51b734 */) = cpu.eax;
    // 00478f48  895020                 -mov dword ptr [eax + 0x20], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 00478f4b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478f4c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_478f50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478f50  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00478f51  a134b75100             -mov eax, dword ptr [0x51b734]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355316) /* 0x51b734 */);
    // 00478f56  8b5020                 -mov edx, dword ptr [eax + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 00478f59  891534b75100           -mov dword ptr [0x51b734], edx
    app->getMemory<x86::reg32>(x86::reg32(5355316) /* 0x51b734 */) = cpu.edx;
    // 00478f5f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478f60  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_478f64(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478f64  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00478f65  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00478f6a  e811fbffff             -call 0x478a80
    cpu.esp -= 4;
    sub_478a80(app, cpu);
    if (cpu.terminate) return;
    // 00478f6f  8b4014                 -mov eax, dword ptr [eax + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 00478f72  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478f73  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_478f74(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478f74  8b4014                 -mov eax, dword ptr [eax + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 00478f77  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_478f78(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478f78  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00478f7b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_478f7c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478f7c  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00478f7f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_478f80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478f80  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00478f81  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00478f83  a130b75100             -mov eax, dword ptr [0x51b730]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355312) /* 0x51b730 */);
    // 00478f88  e8c3a60100             -call 0x493650
    cpu.esp -= 4;
    sub_493650(app, cpu);
    if (cpu.terminate) return;
    // 00478f8d  806218ef               -and byte ptr [edx + 0x18], 0xef
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(24) /* 0x18 */) &= x86::reg8(x86::sreg8(239 /*0xef*/));
    // 00478f91  a130b75100             -mov eax, dword ptr [0x51b730]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355312) /* 0x51b730 */);
    // 00478f96  e8bda60100             -call 0x493658
    cpu.esp -= 4;
    sub_493658(app, cpu);
    if (cpu.terminate) return;
    // 00478f9b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478f9c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_478fa0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478fa0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00478fa1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00478fa3  a130b75100             -mov eax, dword ptr [0x51b730]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355312) /* 0x51b730 */);
    // 00478fa8  e8a3a60100             -call 0x493650
    cpu.esp -= 4;
    sub_493650(app, cpu);
    if (cpu.terminate) return;
    // 00478fad  804a1810               -or byte ptr [edx + 0x18], 0x10
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(24) /* 0x18 */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
    // 00478fb1  a130b75100             -mov eax, dword ptr [0x51b730]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355312) /* 0x51b730 */);
    // 00478fb6  e89da60100             -call 0x493658
    cpu.esp -= 4;
    sub_493658(app, cpu);
    if (cpu.terminate) return;
    // 00478fbb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478fbc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_478fc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00478fc0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00478fc1  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00478fc3  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00478fc8  e8b3faffff             -call 0x478a80
    cpu.esp -= 4;
    sub_478a80(app, cpu);
    if (cpu.terminate) return;
    // 00478fcd  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00478fcf  e804000000             -call 0x478fd8
    cpu.esp -= 4;
    sub_478fd8(app, cpu);
    if (cpu.terminate) return;
    // 00478fd4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00478fd5  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
