#include "nfs3hp.h"
#include <lib/thread.h>

namespace nfs3hp
{

/* align: skip 0x8b 0xc0 */
void Application::sub_526244(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00526244  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00526245  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00526246  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00526247  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00526249  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0052624e  e875feffff             -call 0x5260c8
    cpu.esp -= 4;
    sub_5260c8(app, cpu);
    if (cpu.terminate) return;
    // 00526253  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00526255  83f801                 +cmp eax, 1
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
    // 00526258  7425                   -je 0x52627f
    if (cpu.flags.zf)
    {
        goto L_0x0052627f;
    }
    // 0052625a  83f802                 +cmp eax, 2
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
    // 0052625d  7420                   -je 0x52627f
    if (cpu.flags.zf)
    {
        goto L_0x0052627f;
    }
    // 0052625f  83f803                 +cmp eax, 3
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
    // 00526262  741b                   -je 0x52627f
    if (cpu.flags.zf)
    {
        goto L_0x0052627f;
    }
    // 00526264  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00526269  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0052626b  e810feffff             -call 0x526080
    cpu.esp -= 4;
    sub_526080(app, cpu);
    if (cpu.terminate) return;
    // 00526270  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00526275  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00526277  ffd1                   -call ecx
    cpu.ip = cpu.ecx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00526279  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0052627b  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052627c  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052627d  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052627e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052627f:
    // 0052627f  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00526284  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00526285  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00526286  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00526287  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_526288(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00526288  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00526289  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052628a  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052628b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0052628d  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0052628f  83f801                 +cmp eax, 1
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
    // 00526292  7c05                   -jl 0x526299
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00526299;
    }
    // 00526294  83f80c                 +cmp eax, 0xc
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
    // 00526297  7e13                   -jle 0x5262ac
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x005262ac;
    }
L_0x00526299:
    // 00526299  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 0052629e  e8ddc5fdff             -call 0x502880
    cpu.esp -= 4;
    sub_502880(app, cpu);
    if (cpu.terminate) return;
    // 005262a3  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 005262a8  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005262a9  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005262aa  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005262ab  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005262ac:
    // 005262ac  c705ccb1560038625200   -mov dword ptr [0x56b1cc], 0x526238
    *app->getMemory<x86::reg32>(x86::reg32(5681612) /* 0x56b1cc */) = 5399096 /*0x526238*/;
    // 005262b6  83f902                 +cmp ecx, 2
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
    // 005262b9  741f                   -je 0x5262da
    if (cpu.flags.zf)
    {
        goto L_0x005262da;
    }
    // 005262bb  83f903                 +cmp ecx, 3
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
    // 005262be  741a                   -je 0x5262da
    if (cpu.flags.zf)
    {
        goto L_0x005262da;
    }
    // 005262c0  e827feffff             -call 0x5260ec
    cpu.esp -= 4;
    sub_5260ec(app, cpu);
    if (cpu.terminate) return;
    // 005262c5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005262c7  7411                   -je 0x5262da
    if (cpu.flags.zf)
    {
        goto L_0x005262da;
    }
    // 005262c9  83fb02                 +cmp ebx, 2
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
    // 005262cc  750c                   -jne 0x5262da
    if (!cpu.flags.zf)
    {
        goto L_0x005262da;
    }
    // 005262ce  ba9f000000             -mov edx, 0x9f
    cpu.edx = 159 /*0x9f*/;
    // 005262d3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005262d5  e8b619fdff             -call 0x4f7c90
    cpu.esp -= 4;
    sub_4f7c90(app, cpu);
    if (cpu.terminate) return;
L_0x005262da:
    // 005262da  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 005262dc  e8e7fdffff             -call 0x5260c8
    cpu.esp -= 4;
    sub_5260c8(app, cpu);
    if (cpu.terminate) return;
    // 005262e1  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 005262e3  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 005262e5  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 005262e7  e894fdffff             -call 0x526080
    cpu.esp -= 4;
    sub_526080(app, cpu);
    if (cpu.terminate) return;
    // 005262ec  e8a3feffff             -call 0x526194
    cpu.esp -= 4;
    sub_526194(app, cpu);
    if (cpu.terminate) return;
    // 005262f1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005262f3  7407                   -je 0x5262fc
    if (cpu.flags.zf)
    {
        goto L_0x005262fc;
    }
    // 005262f5  e8d2feffff             -call 0x5261cc
    cpu.esp -= 4;
    sub_5261cc(app, cpu);
    if (cpu.terminate) return;
    // 005262fa  eb05                   -jmp 0x526301
    goto L_0x00526301;
L_0x005262fc:
    // 005262fc  e8fbfeffff             -call 0x5261fc
    cpu.esp -= 4;
    sub_5261fc(app, cpu);
    if (cpu.terminate) return;
L_0x00526301:
    // 00526301  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00526303  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00526304  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00526305  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00526306  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_526338(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00526338  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00526339  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052633a  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052633b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0052633d  e886fdffff             -call 0x5260c8
    cpu.esp -= 4;
    sub_5260c8(app, cpu);
    if (cpu.terminate) return;
    // 00526342  8d53ff                 -lea edx, [ebx - 1]
    cpu.edx = x86::reg32(cpu.ebx + x86::reg32(-1) /* -0x1 */);
    // 00526345  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00526347  83fa0b                 +cmp edx, 0xb
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(11 /*0xb*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052634a  774d                   -ja 0x526399
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00526399;
    }
    // 0052634c  2eff249508635200       -jmp dword ptr cs:[edx*4 + 0x526308]
    cpu.ip = *app->getMemory<x86::reg32>(5399304 + cpu.edx * 4); goto dynamic_jump;
  case 0x00526354:
    // 00526354  b88c000000             -mov eax, 0x8c
    cpu.eax = 140 /*0x8c*/;
    // 00526359  e8e6feffff             -call 0x526244
    cpu.esp -= 4;
    sub_526244(app, cpu);
    if (cpu.terminate) return;
    // 0052635e  eb42                   -jmp 0x5263a2
    goto L_0x005263a2;
  case 0x00526360:
    // 00526360  83f802                 +cmp eax, 2
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
    // 00526363  7505                   -jne 0x52636a
    if (!cpu.flags.zf)
    {
        goto L_0x0052636a;
    }
    // 00526365  e80e650000             -call 0x52c878
    cpu.esp -= 4;
    sub_52c878(app, cpu);
    if (cpu.terminate) return;
  [[fallthrough]];
  case 0x0052636a:
L_0x0052636a:
    // 0052636a  83f901                 +cmp ecx, 1
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
    // 0052636d  741a                   -je 0x526389
    if (cpu.flags.zf)
    {
        goto L_0x00526389;
    }
    // 0052636f  83f902                 +cmp ecx, 2
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
    // 00526372  7415                   -je 0x526389
    if (cpu.flags.zf)
    {
        goto L_0x00526389;
    }
    // 00526374  83f903                 +cmp ecx, 3
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
    // 00526377  7410                   -je 0x526389
    if (cpu.flags.zf)
    {
        goto L_0x00526389;
    }
    // 00526379  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 0052637e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00526380  e8fbfcffff             -call 0x526080
    cpu.esp -= 4;
    sub_526080(app, cpu);
    if (cpu.terminate) return;
    // 00526385  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00526387  ffd1                   -call ecx
    cpu.ip = cpu.ecx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00526389:
    // 00526389  e806feffff             -call 0x526194
    cpu.esp -= 4;
    sub_526194(app, cpu);
    if (cpu.terminate) return;
    // 0052638e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00526390  7510                   -jne 0x5263a2
    if (!cpu.flags.zf)
    {
        goto L_0x005263a2;
    }
    // 00526392  e865feffff             -call 0x5261fc
    cpu.esp -= 4;
    sub_5261fc(app, cpu);
    if (cpu.terminate) return;
    // 00526397  eb09                   -jmp 0x5263a2
    goto L_0x005263a2;
L_0x00526399:
    // 00526399  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0052639e  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052639f  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005263a0  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005263a1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005263a2:
    // 005263a2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005263a4  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005263a5  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005263a6  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005263a7  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void Application::sub_5263a8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005263a8  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005263a9  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005263aa  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005263ab  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005263ac  06                     -push es
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 005263ad  ba08000000             -mov edx, 8
    cpu.edx = 8 /*0x8*/;
L_0x005263b2:
    // 005263b2  ff1564775600           -call dword ptr [0x567764]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5666660) /* 0x567764 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005263b8  8d3410                 -lea esi, [eax + edx]
    cpu.esi = x86::reg32(cpu.eax + cpu.edx * 1);
    // 005263bb  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 005263bd  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 005263bf  8d7e58                 -lea edi, [esi + 0x58]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(88) /* 0x58 */);
    // 005263c2  8db2bcb05600           -lea esi, [edx + 0x56b0bc]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(5681340) /* 0x56b0bc */);
    // 005263c8  83c208                 -add edx, 8
    (cpu.edx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 005263cb  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 005263cc  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 005263cd  83fa68                 +cmp edx, 0x68
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
    // 005263d0  75e0                   -jne 0x5263b2
    if (!cpu.flags.zf)
    {
        goto L_0x005263b2;
    }
    // 005263d2  ba10615200             -mov edx, 0x526110
    cpu.edx = 5398800 /*0x526110*/;
    // 005263d7  bb38635200             -mov ebx, 0x526338
    cpu.ebx = 5399352 /*0x526338*/;
    // 005263dc  8915d4ac5600           -mov dword ptr [0x56acd4], edx
    *app->getMemory<x86::reg32>(x86::reg32(5680340) /* 0x56acd4 */) = cpu.edx;
    // 005263e2  891dd8ac5600           -mov dword ptr [0x56acd8], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5680344) /* 0x56acd8 */) = cpu.ebx;
    // 005263e8  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 005263e9  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005263ea  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005263eb  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005263ec  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005263ed  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_5263f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005263f0  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005263f1  e89efdffff             -call 0x526194
    cpu.esp -= 4;
    sub_526194(app, cpu);
    if (cpu.terminate) return;
    // 005263f6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005263f8  7423                   -je 0x52641d
    if (cpu.flags.zf)
    {
        goto L_0x0052641d;
    }
    // 005263fa  e8fdfdffff             -call 0x5261fc
    cpu.esp -= 4;
    sub_5261fc(app, cpu);
    if (cpu.terminate) return;
    // 005263ff  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00526404  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00526409  e872fcffff             -call 0x526080
    cpu.esp -= 4;
    sub_526080(app, cpu);
    if (cpu.terminate) return;
    // 0052640e  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00526413  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 00526418  e863fcffff             -call 0x526080
    cpu.esp -= 4;
    sub_526080(app, cpu);
    if (cpu.terminate) return;
L_0x0052641d:
    // 0052641d  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052641e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_526420(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00526420  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00526421  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00526422  baa8635200             -mov edx, 0x5263a8
    cpu.edx = 5399464 /*0x5263a8*/;
    // 00526427  bbf0635200             -mov ebx, 0x5263f0
    cpu.ebx = 5399536 /*0x5263f0*/;
    // 0052642c  8915a4775600           -mov dword ptr [0x5677a4], edx
    *app->getMemory<x86::reg32>(x86::reg32(5666724) /* 0x5677a4 */) = cpu.edx;
    // 00526432  891da8775600           -mov dword ptr [0x5677a8], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5666728) /* 0x5677a8 */) = cpu.ebx;
    // 00526438  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00526439  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052643a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_52643c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052643c  09db                   +or ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0052643e  750b                   -jne 0x52644b
    if (!cpu.flags.zf)
    {
        goto L_0x0052644b;
    }
    // 00526440  01c9                   +add ecx, ecx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00526442  7505                   -jne 0x526449
    if (!cpu.flags.zf)
    {
        goto L_0x00526449;
    }
    // 00526444  e952640000             -jmp 0x52c89b
    return sub_52c89b(app, cpu);
L_0x00526449:
    // 00526449  d1d9                   -rcr ecx, 1
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
L_0x0052644b:
    // 0052644b  09c0                   +or eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(cpu.eax))));
    // 0052644d  7507                   -jne 0x526456
    if (!cpu.flags.zf)
    {
        goto L_0x00526456;
    }
    // 0052644f  01d2                   +add edx, edx
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00526451  7501                   -jne 0x526454
    if (!cpu.flags.zf)
    {
        goto L_0x00526454;
    }
    // 00526453  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00526454:
    // 00526454  d1da                   -rcr edx, 1
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
L_0x00526456:
    // 00526456  803dc144560000         +cmp byte ptr [0x5644c1], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(x86::reg32(5653697) /* 0x5644c1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0052645d  7430                   -je 0x52648f
    if (cpu.flags.zf)
    {
        goto L_0x0052648f;
    }
    // 0052645f  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00526460  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00526461  dd0424                 -fld qword ptr [esp]
    cpu.fpu.push(x86::Float(*app->getMemory<double>(cpu.esp)));
    // 00526464  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00526465  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00526466  f6055878560001         +test byte ptr [0x567858], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(x86::reg32(5666904) /* 0x567858 */) & 1 /*0x1*/));
    // 0052646d  7407                   -je 0x526476
    if (cpu.flags.zf)
    {
        goto L_0x00526476;
    }
    // 0052646f  e8980b0000             -call 0x52700c
    cpu.esp -= 4;
    sub_52700c(app, cpu);
    if (cpu.terminate) return;
    // 00526474  eb06                   -jmp 0x52647c
    goto L_0x0052647c;
L_0x00526476:
    // 00526476  dc3424                 -fdiv qword ptr [esp]
    cpu.fpu.st(0) /= x86::Float(*app->getMemory<double>(cpu.esp));
    // 00526479  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x0052647c:
    // 0052647c  dd1c24                 -fstp qword ptr [esp]
    *app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052647f  9b                     -wait 
    /*nothing*/;
    // 00526480  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00526481  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00526482  81fa00000080           +cmp edx, 0x80000000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2147483648 /*0x80000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00526488  7504                   -jne 0x52648e
    if (!cpu.flags.zf)
    {
        goto L_0x0052648e;
    }
    // 0052648a  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0052648c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x0052648e:
    // 0052648e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052648f:
    // 0052648f  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00526490  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00526492  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00526493  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00526494  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00526496  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00526498  c1ff14                 -sar edi, 0x14
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (20 /*0x14*/ % 32));
    // 0052649b  c1f914                 -sar ecx, 0x14
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (20 /*0x14*/ % 32));
    // 0052649e  81e7ff070080           -and edi, 0x800007ff
    cpu.edi &= x86::reg32(x86::sreg32(2147485695 /*0x800007ff*/));
    // 005264a4  81e1ff070080           -and ecx, 0x800007ff
    cpu.ecx &= x86::reg32(x86::sreg32(2147485695 /*0x800007ff*/));
    // 005264aa  c1c710                 -rol edi, 0x10
    {
        x86::reg32& op = cpu.edi;
        x86::reg32 shift = 16 /*0x10*/ % 32;
        while (shift)
        {
            x86::reg32 cf = (op & 0x80000000);
            op = op << 1 | cf >> 31;
            shift--;
        }
    }
    // 005264ad  c1c110                 -rol ecx, 0x10
    {
        x86::reg32& op = cpu.ecx;
        x86::reg32 shift = 16 /*0x10*/ % 32;
        while (shift)
        {
            x86::reg32 cf = (op & 0x80000000);
            op = op << 1 | cf >> 31;
            shift--;
        }
    }
    // 005264b0  6601cf                 -add di, cx
    (cpu.di) += x86::reg16(x86::sreg16(cpu.cx));
    // 005264b3  c1c710                 -rol edi, 0x10
    {
        x86::reg32& op = cpu.edi;
        x86::reg32 shift = 16 /*0x10*/ % 32;
        while (shift)
        {
            x86::reg32 cf = (op & 0x80000000);
            op = op << 1 | cf >> 31;
            shift--;
        }
    }
    // 005264b6  c1c110                 -rol ecx, 0x10
    {
        x86::reg32& op = cpu.ecx;
        x86::reg32 shift = 16 /*0x10*/ % 32;
        while (shift)
        {
            x86::reg32 cf = (op & 0x80000000);
            op = op << 1 | cf >> 31;
            shift--;
        }
    }
    // 005264b9  81e2ffff0f00           -and edx, 0xfffff
    cpu.edx &= x86::reg32(x86::sreg32(1048575 /*0xfffff*/));
    // 005264bf  81e6ffff0f00           -and esi, 0xfffff
    cpu.esi &= x86::reg32(x86::sreg32(1048575 /*0xfffff*/));
    // 005264c5  6609ff                 +or di, di
    cpu.clear_co();
    cpu.set_szp((cpu.di |= x86::reg16(x86::sreg16(cpu.di))));
    // 005264c8  7408                   -je 0x5264d2
    if (cpu.flags.zf)
    {
        goto L_0x005264d2;
    }
    // 005264ca  81ca00001000           +or edx, 0x100000
    cpu.clear_co();
    cpu.set_szp((cpu.edx |= x86::reg32(x86::sreg32(1048576 /*0x100000*/))));
    // 005264d0  eb0e                   -jmp 0x5264e0
    goto L_0x005264e0;
L_0x005264d2:
    // 005264d2  01c0                   +add eax, eax
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
    // 005264d4  11d2                   -adc edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 005264d6  664f                   -dec di
    (cpu.di)--;
    // 005264d8  f7c200001000           +test edx, 0x100000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 1048576 /*0x100000*/));
    // 005264de  74f2                   -je 0x5264d2
    if (cpu.flags.zf)
    {
        goto L_0x005264d2;
    }
L_0x005264e0:
    // 005264e0  6609c9                 +or cx, cx
    cpu.clear_co();
    cpu.set_szp((cpu.cx |= x86::reg16(x86::sreg16(cpu.cx))));
    // 005264e3  7408                   -je 0x5264ed
    if (cpu.flags.zf)
    {
        goto L_0x005264ed;
    }
    // 005264e5  81ce00001000           +or esi, 0x100000
    cpu.clear_co();
    cpu.set_szp((cpu.esi |= x86::reg32(x86::sreg32(1048576 /*0x100000*/))));
    // 005264eb  eb0e                   -jmp 0x5264fb
    goto L_0x005264fb;
L_0x005264ed:
    // 005264ed  01db                   +add ebx, ebx
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
    // 005264ef  11f6                   -adc esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi) + cpu.flags.cf);
    // 005264f1  6649                   -dec cx
    (cpu.cx)--;
    // 005264f3  f7c600001000           +test esi, 0x100000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & 1048576 /*0x100000*/));
    // 005264f9  74f2                   -je 0x5264ed
    if (cpu.flags.zf)
    {
        goto L_0x005264ed;
    }
L_0x005264fb:
    // 005264fb  6629cf                 -sub di, cx
    (cpu.di) -= x86::reg16(x86::sreg16(cpu.cx));
    // 005264fe  6681c7ff03             +add di, 0x3ff
    {
        x86::reg16& tmp1 = cpu.di;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(1023 /*0x3ff*/));
        x86::reg16 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) == (1 & (tmp2 >> 15));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00526503  7811                   -js 0x526516
    if (cpu.flags.sf)
    {
        goto L_0x00526516;
    }
    // 00526505  6681ffff07             +cmp di, 0x7ff
    {
        x86::reg16 tmp1 = cpu.di;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(2047 /*0x7ff*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0052650a  720a                   -jb 0x526516
    if (cpu.flags.cf)
    {
        goto L_0x00526516;
    }
    // 0052650c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0052650e  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052650f  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00526510  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00526511  e991630000             -jmp 0x52c8a7
    return sub_52c8a7(app, cpu);
L_0x00526516:
    // 00526516  6683ffcc               +cmp di, -0x34
    {
        x86::reg16 tmp1 = cpu.di;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(-52 /*-0x34*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0052651a  7d08                   -jge 0x526524
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00526524;
    }
    // 0052651c  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052651d  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052651e  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052651f  e966630000             -jmp 0x52c88a
    return sub_52c88a(app, cpu);
L_0x00526524:
    // 00526524  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00526525  b10b                   -mov cl, 0xb
    cpu.cl = 11 /*0xb*/;
    // 00526527  0fa5c2                 -shld edx, eax, cl
    {
        x86::reg32& destination = cpu.edx;
        destination <<= (cpu.cl % 32);
        destination |= cpu.eax >> (32 - (cpu.cl % 32));
    }
    // 0052652a  0fa5e8                 -shld eax, ebp, cl
    {
        x86::reg32& destination = cpu.eax;
        destination <<= (cpu.cl % 32);
        destination |= cpu.ebp >> (32 - (cpu.cl % 32));
    }
    // 0052652d  2500f8ffff             -and eax, 0xfffff800
    cpu.eax &= x86::reg32(x86::sreg32(4294965248 /*0xfffff800*/));
    // 00526532  0fa5de                 -shld esi, ebx, cl
    {
        x86::reg32& destination = cpu.esi;
        destination <<= (cpu.cl % 32);
        destination |= cpu.ebx >> (32 - (cpu.cl % 32));
    }
    // 00526535  0fa5eb                 -shld ebx, ebp, cl
    {
        x86::reg32& destination = cpu.ebx;
        destination <<= (cpu.cl % 32);
        destination |= cpu.ebp >> (32 - (cpu.cl % 32));
    }
    // 00526538  81e300f8ffff           -and ebx, 0xfffff800
    cpu.ebx &= x86::reg32(x86::sreg32(4294965248 /*0xfffff800*/));
    // 0052653e  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052653f  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00526540  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00526542  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00526544  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00526546  29c0                   -sub eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00526548  39d1                   +cmp ecx, edx
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
    // 0052654a  7703                   -ja 0x52654f
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0052654f;
    }
    // 0052654c  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0052654e  40                     -inc eax
    (cpu.eax)++;
L_0x0052654f:
    // 0052654f  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00526550  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00526552  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00526554  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00526555  93                     -xchg ebx, eax
    {
        x86::reg32 tmp = cpu.ebx;
        cpu.ebx = cpu.eax;
        cpu.eax = tmp;
    }
    // 00526556  f7e3                   -mul ebx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ebx);
    // 00526558  91                     -xchg ecx, eax
    {
        x86::reg32 tmp = cpu.ecx;
        cpu.ecx = cpu.eax;
        cpu.eax = tmp;
    }
    // 00526559  87d3                   -xchg ebx, edx
    {
        x86::reg32 tmp = cpu.ebx;
        cpu.ebx = cpu.edx;
        cpu.edx = tmp;
    }
    // 0052655b  f7e2                   -mul edx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.edx);
    // 0052655d  01d8                   +add eax, ebx
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
    // 0052655f  83d200                 -adc edx, 0
    (cpu.edx) += x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 00526562  8b5dec                 -mov ebx, dword ptr [ebp - 0x14]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00526565  f645e801               +test byte ptr [ebp - 0x18], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-24) /* -0x18 */) & 1 /*0x1*/));
    // 00526569  7405                   -je 0x526570
    if (cpu.flags.zf)
    {
        goto L_0x00526570;
    }
    // 0052656b  01d8                   +add eax, ebx
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
    // 0052656d  1355f0                 -adc edx, dword ptr [ebp - 0x10]
    (cpu.edx) += x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */)) + cpu.flags.cf);
L_0x00526570:
    // 00526570  f7d9                   +neg ecx
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
    // 00526572  19c6                   +sbb esi, eax
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax)) + cpu.flags.cf;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00526574  19d7                   +sbb edi, edx
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx)) + cpu.flags.cf;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00526576  7412                   -je 0x52658a
    if (cpu.flags.zf)
    {
        goto L_0x0052658a;
    }
L_0x00526578:
    // 00526578  836de401               +sub dword ptr [ebp - 0x1c], 1
    {
        x86::reg32& tmp1 = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0052657c  835de800               -sbb dword ptr [ebp - 0x18], 0
    (*app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */)) -= x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 00526580  01d9                   +add ecx, ebx
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
    // 00526582  1375f0                 +adc esi, dword ptr [ebp - 0x10]
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */))) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00526585  83d700                 +adc edi, 0
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00526588  75ee                   -jne 0x526578
    if (!cpu.flags.zf)
    {
        goto L_0x00526578;
    }
L_0x0052658a:
    // 0052658a  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 0052658c  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0052658e  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00526591  39f9                   +cmp ecx, edi
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
    // 00526593  770a                   -ja 0x52659f
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0052659f;
    }
    // 00526595  29cf                   -sub edi, ecx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00526597  8345e401               +add dword ptr [ebp - 0x1c], 1
    {
        x86::reg32& tmp1 = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0052659b  8355e800               -adc dword ptr [ebp - 0x18], 0
    (*app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */)) += x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
L_0x0052659f:
    // 0052659f  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 005265a1  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 005265a3  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 005265a5  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005265a6  09c0                   +or eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(cpu.eax))));
    // 005265a8  742c                   -je 0x5265d6
    if (cpu.flags.zf)
    {
        goto L_0x005265d6;
    }
    // 005265aa  93                     -xchg ebx, eax
    {
        x86::reg32 tmp = cpu.ebx;
        cpu.ebx = cpu.eax;
        cpu.eax = tmp;
    }
    // 005265ab  f7e3                   -mul ebx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ebx);
    // 005265ad  91                     -xchg ecx, eax
    {
        x86::reg32 tmp = cpu.ecx;
        cpu.ecx = cpu.eax;
        cpu.eax = tmp;
    }
    // 005265ae  87d3                   -xchg ebx, edx
    {
        x86::reg32 tmp = cpu.ebx;
        cpu.ebx = cpu.edx;
        cpu.edx = tmp;
    }
    // 005265b0  f7e2                   -mul edx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.edx);
    // 005265b2  01d8                   +add eax, ebx
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
    // 005265b4  83d200                 -adc edx, 0
    (cpu.edx) += x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 005265b7  f7d9                   +neg ecx
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
    // 005265b9  19c6                   +sbb esi, eax
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax)) + cpu.flags.cf;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 005265bb  19d7                   +sbb edi, edx
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx)) + cpu.flags.cf;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 005265bd  7417                   -je 0x5265d6
    if (cpu.flags.zf)
    {
        goto L_0x005265d6;
    }
L_0x005265bf:
    // 005265bf  836de001               +sub dword ptr [ebp - 0x20], 1
    {
        x86::reg32& tmp1 = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 005265c3  835de400               +sbb dword ptr [ebp - 0x1c], 0
    {
        x86::reg32& tmp1 = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/)) + cpu.flags.cf;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 005265c7  835de800               -sbb dword ptr [ebp - 0x18], 0
    (*app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */)) -= x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 005265cb  034dec                 +add ecx, dword ptr [ebp - 0x14]
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 005265ce  1375f0                 +adc esi, dword ptr [ebp - 0x10]
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */))) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 005265d1  83d700                 +adc edi, 0
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 005265d4  75e9                   -jne 0x5265bf
    if (!cpu.flags.zf)
    {
        goto L_0x005265bf;
    }
L_0x005265d6:
    // 005265d6  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005265d7  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005265d8  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005265d9  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 005265dc  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005265dd  664f                   -dec di
    (cpu.di)--;
    // 005265df  d1eb                   +shr ebx, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.ebx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 005265e1  7305                   -jae 0x5265e8
    if (!cpu.flags.cf)
    {
        goto L_0x005265e8;
    }
    // 005265e3  d1da                   +rcr edx, 1
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
    // 005265e5  d1d8                   -rcr eax, 1
    {
        x86::reg32& op = cpu.eax;
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
    // 005265e7  47                     -inc edi
    (cpu.edi)++;
L_0x005265e8:
    // 005265e8  29f6                   -sub esi, esi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.esi));
    // 005265ea  b10b                   -mov cl, 0xb
    cpu.cl = 11 /*0xb*/;
    // 005265ec  0fadd0                 +shrd eax, edx, cl
    {
        x86::reg32& destination = cpu.eax;
        cpu.flags.cf = 1 & (destination >> (cpu.cl - 1));
        cpu.flags.of = 1 & (destination >> (32 - 1));
        destination >>= (cpu.cl % 32);
        destination |= cpu.edx  << (32 - (cpu.cl % 32));
        cpu.flags.of ^= 1 & (destination >> (32 - 1));
        cpu.set_szp(destination);
    }
    // 005265ef  d1de                   -rcr esi, 1
    {
        x86::reg32& op = cpu.esi;
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
    // 005265f1  0fadf2                 -shrd edx, esi, cl
    {
        x86::reg32& destination = cpu.edx;
        destination >>= (cpu.cl % 32);
        destination |= cpu.esi  << (32 - (cpu.cl % 32));
    }
    // 005265f4  81ca0000f0ff           -or edx, 0xfff00000
    cpu.edx |= x86::reg32(x86::sreg32(4293918720 /*0xfff00000*/));
    // 005265fa  01f6                   +add esi, esi
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
    // 005265fc  83d000                 +adc eax, 0
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
    // 005265ff  83d200                 +adc edx, 0
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
    // 00526602  83d700                 -adc edi, 0
    (cpu.edi) += x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 00526605  6609ff                 +or di, di
    cpu.clear_co();
    cpu.set_szp((cpu.di |= x86::reg16(x86::sreg16(cpu.di))));
    // 00526608  7f1d                   -jg 0x526627
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00526627;
    }
    // 0052660a  7504                   -jne 0x526610
    if (!cpu.flags.zf)
    {
        goto L_0x00526610;
    }
    // 0052660c  b101                   -mov cl, 1
    cpu.cl = 1 /*0x1*/;
    // 0052660e  eb06                   -jmp 0x526616
    goto L_0x00526616;
L_0x00526610:
    // 00526610  66f7df                 -neg di
    cpu.di = ~cpu.di + 1;
    // 00526613  6689f9                 -mov cx, di
    cpu.cx = cpu.di;
L_0x00526616:
    // 00526616  81e2ffff1f00           -and edx, 0x1fffff
    cpu.edx &= x86::reg32(x86::sreg32(2097151 /*0x1fffff*/));
    // 0052661c  29db                   -sub ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0052661e  0fadd0                 -shrd eax, edx, cl
    {
        x86::reg32& destination = cpu.eax;
        destination >>= (cpu.cl % 32);
        destination |= cpu.edx  << (32 - (cpu.cl % 32));
    }
    // 00526621  0fadda                 -shrd edx, ebx, cl
    {
        x86::reg32& destination = cpu.edx;
        destination >>= (cpu.cl % 32);
        destination |= cpu.ebx  << (32 - (cpu.cl % 32));
    }
    // 00526624  6629ff                 -sub di, di
    (cpu.di) -= x86::reg16(x86::sreg16(cpu.di));
L_0x00526627:
    // 00526627  81e2ffff0f00           -and edx, 0xfffff
    cpu.edx &= x86::reg32(x86::sreg32(1048575 /*0xfffff*/));
    // 0052662d  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 0052662f  c1cf0b                 -ror edi, 0xb
    {
        x86::reg32& op = cpu.edi;
        x86::reg32 shift = 11 /*0xb*/ % 32;
        while (shift)
        {
            x86::reg32 cf = op & 1;
            op = op >> 1 | cf << 31;
            shift--;
        }
    }
    // 00526632  01f6                   +add esi, esi
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
    // 00526634  d1df                   -rcr edi, 1
    {
        x86::reg32& op = cpu.edi;
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
    // 00526636  81e70000f0ff           -and edi, 0xfff00000
    cpu.edi &= x86::reg32(x86::sreg32(4293918720 /*0xfff00000*/));
    // 0052663c  09fa                   -or edx, edi
    cpu.edx |= x86::reg32(x86::sreg32(cpu.edi));
    // 0052663e  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052663f  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00526640  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00526641  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_526642(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00526642  81f100000080           -xor ecx, 0x80000000
    cpu.ecx ^= x86::reg32(x86::sreg32(2147483648 /*0x80000000*/));
    // 00526648  09db                   +or ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0052664a  7506                   -jne 0x526652
    if (!cpu.flags.zf)
    {
        goto L_0x00526652;
    }
    // 0052664c  01c9                   +add ecx, ecx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0052664e  740e                   -je 0x52665e
    if (cpu.flags.zf)
    {
        goto L_0x0052665e;
    }
    // 00526650  d1d9                   -rcr ecx, 1
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
L_0x00526652:
    // 00526652  09c0                   +or eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(cpu.eax))));
    // 00526654  750b                   -jne 0x526661
    if (!cpu.flags.zf)
    {
        goto L_0x00526661;
    }
    // 00526656  01d2                   +add edx, edx
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00526658  7505                   -jne 0x52665f
    if (!cpu.flags.zf)
    {
        goto L_0x0052665f;
    }
    // 0052665a  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0052665c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x0052665e:
    // 0052665e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052665f:
    // 0052665f  d1da                   -rcr edx, 1
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
L_0x00526661:
    // 00526661  803dc144560000         +cmp byte ptr [0x5644c1], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(x86::reg32(5653697) /* 0x5644c1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00526668  7421                   -je 0x52668b
    if (cpu.flags.zf)
    {
        goto L_0x0052668b;
    }
    // 0052666a  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052666b  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0052666c  dd0424                 -fld qword ptr [esp]
    cpu.fpu.push(x86::Float(*app->getMemory<double>(cpu.esp)));
    // 0052666f  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00526670  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00526671  dc0424                 -fadd qword ptr [esp]
    cpu.fpu.st(0) += x86::Float(*app->getMemory<double>(cpu.esp));
    // 00526674  dd5c2408               -fstp qword ptr [esp + 8]
    *app->getMemory<double>(cpu.esp + x86::reg32(8) /* 0x8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526678  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0052667b  9b                     -wait 
    /*nothing*/;
    // 0052667c  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052667d  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052667e  81fa00000080           +cmp edx, 0x80000000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2147483648 /*0x80000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00526684  7504                   -jne 0x52668a
    if (!cpu.flags.zf)
    {
        goto L_0x0052668a;
    }
    // 00526686  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00526688  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x0052668a:
    // 0052668a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052668b:
    // 0052668b  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052668c  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052668d  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052668e  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00526690  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00526692  c1ff14                 -sar edi, 0x14
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (20 /*0x14*/ % 32));
    // 00526695  c1f914                 -sar ecx, 0x14
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (20 /*0x14*/ % 32));
    // 00526698  81e7ff070080           -and edi, 0x800007ff
    cpu.edi &= x86::reg32(x86::sreg32(2147485695 /*0x800007ff*/));
    // 0052669e  81e1ff070080           -and ecx, 0x800007ff
    cpu.ecx &= x86::reg32(x86::sreg32(2147485695 /*0x800007ff*/));
    // 005266a4  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 005266a6  c1c710                 -rol edi, 0x10
    {
        x86::reg32& op = cpu.edi;
        x86::reg32 shift = 16 /*0x10*/ % 32;
        while (shift)
        {
            x86::reg32 cf = (op & 0x80000000);
            op = op << 1 | cf >> 31;
            shift--;
        }
    }
    // 005266a9  c1c110                 -rol ecx, 0x10
    {
        x86::reg32& op = cpu.ecx;
        x86::reg32 shift = 16 /*0x10*/ % 32;
        while (shift)
        {
            x86::reg32 cf = (op & 0x80000000);
            op = op << 1 | cf >> 31;
            shift--;
        }
    }
    // 005266ac  6601f9                 -add cx, di
    (cpu.cx) += x86::reg16(x86::sreg16(cpu.di));
    // 005266af  c1c710                 -rol edi, 0x10
    {
        x86::reg32& op = cpu.edi;
        x86::reg32 shift = 16 /*0x10*/ % 32;
        while (shift)
        {
            x86::reg32 cf = (op & 0x80000000);
            op = op << 1 | cf >> 31;
            shift--;
        }
    }
    // 005266b2  c1c110                 -rol ecx, 0x10
    {
        x86::reg32& op = cpu.ecx;
        x86::reg32 shift = 16 /*0x10*/ % 32;
        while (shift)
        {
            x86::reg32 cf = (op & 0x80000000);
            op = op << 1 | cf >> 31;
            shift--;
        }
    }
    // 005266b5  81e2ffff0f00           -and edx, 0xfffff
    cpu.edx &= x86::reg32(x86::sreg32(1048575 /*0xfffff*/));
    // 005266bb  81e6ffff0f00           -and esi, 0xfffff
    cpu.esi &= x86::reg32(x86::sreg32(1048575 /*0xfffff*/));
    // 005266c1  6609ff                 +or di, di
    cpu.clear_co();
    cpu.set_szp((cpu.di |= x86::reg16(x86::sreg16(cpu.di))));
    // 005266c4  7406                   -je 0x5266cc
    if (cpu.flags.zf)
    {
        goto L_0x005266cc;
    }
    // 005266c6  81ca00001000           -or edx, 0x100000
    cpu.edx |= x86::reg32(x86::sreg32(1048576 /*0x100000*/));
L_0x005266cc:
    // 005266cc  6609c9                 +or cx, cx
    cpu.clear_co();
    cpu.set_szp((cpu.cx |= x86::reg16(x86::sreg16(cpu.cx))));
    // 005266cf  7406                   -je 0x5266d7
    if (cpu.flags.zf)
    {
        goto L_0x005266d7;
    }
    // 005266d1  81ce00001000           -or esi, 0x100000
    cpu.esi |= x86::reg32(x86::sreg32(1048576 /*0x100000*/));
L_0x005266d7:
    // 005266d7  01c0                   +add eax, eax
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
    // 005266d9  11d2                   -adc edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 005266db  01db                   +add ebx, ebx
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
    // 005266dd  11f6                   -adc esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi) + cpu.flags.cf);
    // 005266df  6629f9                 +sub cx, di
    {
        x86::reg16& tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(cpu.di));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 005266e2  742f                   -je 0x526713
    if (cpu.flags.zf)
    {
        goto L_0x00526713;
    }
    // 005266e4  7308                   -jae 0x5266ee
    if (!cpu.flags.cf)
    {
        goto L_0x005266ee;
    }
    // 005266e6  89fd                   -mov ebp, edi
    cpu.ebp = cpu.edi;
    // 005266e8  66f7d9                 -neg cx
    cpu.cx = ~cpu.cx + 1;
    // 005266eb  93                     -xchg ebx, eax
    {
        x86::reg32 tmp = cpu.ebx;
        cpu.ebx = cpu.eax;
        cpu.eax = tmp;
    }
    // 005266ec  87f2                   -xchg edx, esi
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.esi;
        cpu.esi = tmp;
    }
L_0x005266ee:
    // 005266ee  6683f936               +cmp cx, 0x36
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(54 /*0x36*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 005266f2  761f                   -jbe 0x526713
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00526713;
    }
    // 005266f4  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 005266f6  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 005266f8  01ed                   +add ebp, ebp
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
    // 005266fa  d1da                   +rcr edx, 1
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
    // 005266fc  d1d8                   -rcr eax, 1
    {
        x86::reg32& op = cpu.eax;
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
    // 005266fe  81e2ffff0f80           -and edx, 0x800fffff
    cpu.edx &= x86::reg32(x86::sreg32(2148532223 /*0x800fffff*/));
    // 00526704  c1cd0d                 -ror ebp, 0xd
    {
        x86::reg32& op = cpu.ebp;
        x86::reg32 shift = 13 /*0xd*/ % 32;
        while (shift)
        {
            x86::reg32 cf = op & 1;
            op = op >> 1 | cf << 31;
            shift--;
        }
    }
    // 00526707  81e50000f07f           -and ebp, 0x7ff00000
    cpu.ebp &= x86::reg32(x86::sreg32(2146435072 /*0x7ff00000*/));
    // 0052670d  09ea                   -or edx, ebp
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ebp));
    // 0052670f  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00526710  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00526711  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00526712  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00526713:
    // 00526713  09c9                   +or ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00526715  790d                   -jns 0x526724
    if (!cpu.flags.sf)
    {
        goto L_0x00526724;
    }
    // 00526717  f7de                   -neg esi
    cpu.esi = ~cpu.esi + 1;
    // 00526719  f7db                   +neg ebx
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
    // 0052671b  83de00                 -sbb esi, 0
    (cpu.esi) -= x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 0052671e  81f500000080           -xor ebp, 0x80000000
    cpu.ebp ^= x86::reg32(x86::sreg32(2147483648 /*0x80000000*/));
L_0x00526724:
    // 00526724  29ff                   -sub edi, edi
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00526726  80f900                 +cmp cl, 0
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00526729  7423                   -je 0x52674e
    if (cpu.flags.zf)
    {
        goto L_0x0052674e;
    }
    // 0052672b  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052672c  29db                   -sub ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0052672e  80f920                 +cmp cl, 0x20
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
    // 00526731  720d                   -jb 0x526740
    if (cpu.flags.cf)
    {
        goto L_0x00526740;
    }
    // 00526733  09c0                   +or eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(cpu.eax))));
    // 00526735  0f95c3                 -setne bl
    cpu.bl = !cpu.flags.zf;
    // 00526738  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0052673a  29db                   -sub ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0052673c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0052673e  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
L_0x00526740:
    // 00526740  0fadc3                 -shrd ebx, eax, cl
    {
        x86::reg32& destination = cpu.ebx;
        destination >>= (cpu.cl % 32);
        destination |= cpu.eax  << (32 - (cpu.cl % 32));
    }
    // 00526743  09df                   -or edi, ebx
    cpu.edi |= x86::reg32(x86::sreg32(cpu.ebx));
    // 00526745  29db                   -sub ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00526747  0fadd0                 -shrd eax, edx, cl
    {
        x86::reg32& destination = cpu.eax;
        destination >>= (cpu.cl % 32);
        destination |= cpu.edx  << (32 - (cpu.cl % 32));
    }
    // 0052674a  0fadda                 -shrd edx, ebx, cl
    {
        x86::reg32& destination = cpu.edx;
        destination >>= (cpu.cl % 32);
        destination |= cpu.ebx  << (32 - (cpu.cl % 32));
    }
    // 0052674d  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0052674e:
    // 0052674e  01d8                   +add eax, ebx
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
    // 00526750  11f2                   +adc edx, esi
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00526752  7923                   -jns 0x526777
    if (!cpu.flags.sf)
    {
        goto L_0x00526777;
    }
    // 00526754  80f935                 +cmp cl, 0x35
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(53 /*0x35*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00526757  7211                   -jb 0x52676a
    if (cpu.flags.cf)
    {
        goto L_0x0052676a;
    }
    // 00526759  f7c7ffffff7f           +test edi, 0x7fffffff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & 2147483647 /*0x7fffffff*/));
    // 0052675f  0f95c3                 -setne bl
    cpu.bl = !cpu.flags.zf;
    // 00526762  d1eb                   +shr ebx, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.ebx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 00526764  83d000                 +adc eax, 0
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
    // 00526767  83d200                 -adc edx, 0
    (cpu.edx) += x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
L_0x0052676a:
    // 0052676a  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 0052676c  f7d8                   +neg eax
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
    // 0052676e  83da00                 -sbb edx, 0
    (cpu.edx) -= x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 00526771  81f500000080           -xor ebp, 0x80000000
    cpu.ebp ^= x86::reg32(x86::sreg32(2147483648 /*0x80000000*/));
L_0x00526777:
    // 00526777  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00526779  09d3                   +or ebx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(cpu.edx))));
    // 0052677b  746a                   -je 0x5267e7
    if (cpu.flags.zf)
    {
        goto L_0x005267e7;
    }
    // 0052677d  6609ed                 +or bp, bp
    cpu.clear_co();
    cpu.set_szp((cpu.bp |= x86::reg16(x86::sreg16(cpu.bp))));
    // 00526780  7469                   -je 0x5267eb
    if (cpu.flags.zf)
    {
        goto L_0x005267eb;
    }
L_0x00526782:
    // 00526782  f7c20000e07f           +test edx, 0x7fe00000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 2145386496 /*0x7fe00000*/));
    // 00526788  750a                   -jne 0x526794
    if (!cpu.flags.zf)
    {
        goto L_0x00526794;
    }
    // 0052678a  664d                   +dec bp
    {
        x86::reg16& tmp = cpu.bp;
        cpu.flags.of = 1 & (tmp >> 15);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 15));
        cpu.set_szp(tmp);
    }
    // 0052678c  745d                   -je 0x5267eb
    if (cpu.flags.zf)
    {
        goto L_0x005267eb;
    }
    // 0052678e  01c0                   +add eax, eax
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
    // 00526790  11d2                   +adc edx, edx
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
    // 00526792  ebee                   -jmp 0x526782
    goto L_0x00526782;
L_0x00526794:
    // 00526794  f7c200004000           +test edx, 0x400000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 4194304 /*0x400000*/));
    // 0052679a  7410                   -je 0x5267ac
    if (cpu.flags.zf)
    {
        goto L_0x005267ac;
    }
    // 0052679c  d1ea                   +shr edx, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 0052679e  d1d8                   +rcr eax, 1
    {
        x86::reg32& op = cpu.eax;
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
    // 005267a0  83d700                 -adc edi, 0
    (cpu.edi) += x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 005267a3  6645                   -inc bp
    (cpu.bp)++;
    // 005267a5  6681fdff07             +cmp bp, 0x7ff
    {
        x86::reg16 tmp1 = cpu.bp;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(2047 /*0x7ff*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 005267aa  7449                   -je 0x5267f5
    if (cpu.flags.zf)
    {
        goto L_0x005267f5;
    }
L_0x005267ac:
    // 005267ac  d1ea                   +shr edx, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 005267ae  d1d8                   +rcr eax, 1
    {
        x86::reg32& op = cpu.eax;
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
    // 005267b0  7324                   -jae 0x5267d6
    if (!cpu.flags.cf)
    {
        goto L_0x005267d6;
    }
    // 005267b2  09ff                   +or edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi |= x86::reg32(x86::sreg32(cpu.edi))));
    // 005267b4  0f95c3                 -setne bl
    cpu.bl = !cpu.flags.zf;
    // 005267b7  09c3                   -or ebx, eax
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.eax));
    // 005267b9  d1eb                   +shr ebx, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.ebx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 005267bb  83d000                 +adc eax, 0
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
    // 005267be  83d200                 -adc edx, 0
    (cpu.edx) += x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 005267c1  f7c200002000           +test edx, 0x200000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 2097152 /*0x200000*/));
    // 005267c7  740d                   -je 0x5267d6
    if (cpu.flags.zf)
    {
        goto L_0x005267d6;
    }
    // 005267c9  d1ea                   +shr edx, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 005267cb  d1d8                   -rcr eax, 1
    {
        x86::reg32& op = cpu.eax;
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
    // 005267cd  6645                   -inc bp
    (cpu.bp)++;
    // 005267cf  6681fdff07             +cmp bp, 0x7ff
    {
        x86::reg16 tmp1 = cpu.bp;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(2047 /*0x7ff*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 005267d4  741f                   -je 0x5267f5
    if (cpu.flags.zf)
    {
        goto L_0x005267f5;
    }
L_0x005267d6:
    // 005267d6  81e2ffff0f00           -and edx, 0xfffff
    cpu.edx &= x86::reg32(x86::sreg32(1048575 /*0xfffff*/));
    // 005267dc  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 005267de  c1e515                 -shl ebp, 0x15
    cpu.ebp <<= 21 /*0x15*/ % 32;
    // 005267e1  01c9                   +add ecx, ecx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 005267e3  d1dd                   -rcr ebp, 1
    {
        x86::reg32& op = cpu.ebp;
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
    // 005267e5  09ea                   -or edx, ebp
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ebp));
L_0x005267e7:
    // 005267e7  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005267e8  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005267e9  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005267ea  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005267eb:
    // 005267eb  01ed                   +add ebp, ebp
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
    // 005267ed  d1da                   +rcr edx, 1
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
    // 005267ef  d1d8                   +rcr eax, 1
    {
        x86::reg32& op = cpu.eax;
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
    // 005267f1  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005267f2  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005267f3  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005267f4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005267f5:
    // 005267f5  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 005267f7  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005267f8  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005267f9  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005267fa  e9a8600000             -jmp 0x52c8a7
    return sub_52c8a7(app, cpu);
}

/* align: skip  */
void Application::sub_526674(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00526674;
    // 00526642  81f100000080           -xor ecx, 0x80000000
    cpu.ecx ^= x86::reg32(x86::sreg32(2147483648 /*0x80000000*/));
    // 00526648  09db                   +or ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0052664a  7506                   -jne 0x526652
    if (!cpu.flags.zf)
    {
        goto L_0x00526652;
    }
    // 0052664c  01c9                   +add ecx, ecx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0052664e  740e                   -je 0x52665e
    if (cpu.flags.zf)
    {
        goto L_0x0052665e;
    }
    // 00526650  d1d9                   -rcr ecx, 1
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
L_0x00526652:
    // 00526652  09c0                   +or eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(cpu.eax))));
    // 00526654  750b                   -jne 0x526661
    if (!cpu.flags.zf)
    {
        goto L_0x00526661;
    }
    // 00526656  01d2                   +add edx, edx
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00526658  7505                   -jne 0x52665f
    if (!cpu.flags.zf)
    {
        goto L_0x0052665f;
    }
    // 0052665a  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0052665c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x0052665e:
    // 0052665e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052665f:
    // 0052665f  d1da                   -rcr edx, 1
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
L_0x00526661:
    // 00526661  803dc144560000         +cmp byte ptr [0x5644c1], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(x86::reg32(5653697) /* 0x5644c1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00526668  7421                   -je 0x52668b
    if (cpu.flags.zf)
    {
        goto L_0x0052668b;
    }
    // 0052666a  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052666b  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0052666c  dd0424                 -fld qword ptr [esp]
    cpu.fpu.push(x86::Float(*app->getMemory<double>(cpu.esp)));
    // 0052666f  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00526670  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00526671  dc0424                 -fadd qword ptr [esp]
    cpu.fpu.st(0) += x86::Float(*app->getMemory<double>(cpu.esp));
L_entry_0x00526674:
    // 00526674  dd5c2408               -fstp qword ptr [esp + 8]
    *app->getMemory<double>(cpu.esp + x86::reg32(8) /* 0x8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526678  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0052667b  9b                     -wait 
    /*nothing*/;
    // 0052667c  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052667d  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052667e  81fa00000080           +cmp edx, 0x80000000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2147483648 /*0x80000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00526684  7504                   -jne 0x52668a
    if (!cpu.flags.zf)
    {
        goto L_0x0052668a;
    }
    // 00526686  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00526688  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x0052668a:
    // 0052668a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052668b:
    // 0052668b  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052668c  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052668d  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052668e  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00526690  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00526692  c1ff14                 -sar edi, 0x14
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (20 /*0x14*/ % 32));
    // 00526695  c1f914                 -sar ecx, 0x14
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (20 /*0x14*/ % 32));
    // 00526698  81e7ff070080           -and edi, 0x800007ff
    cpu.edi &= x86::reg32(x86::sreg32(2147485695 /*0x800007ff*/));
    // 0052669e  81e1ff070080           -and ecx, 0x800007ff
    cpu.ecx &= x86::reg32(x86::sreg32(2147485695 /*0x800007ff*/));
    // 005266a4  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 005266a6  c1c710                 -rol edi, 0x10
    {
        x86::reg32& op = cpu.edi;
        x86::reg32 shift = 16 /*0x10*/ % 32;
        while (shift)
        {
            x86::reg32 cf = (op & 0x80000000);
            op = op << 1 | cf >> 31;
            shift--;
        }
    }
    // 005266a9  c1c110                 -rol ecx, 0x10
    {
        x86::reg32& op = cpu.ecx;
        x86::reg32 shift = 16 /*0x10*/ % 32;
        while (shift)
        {
            x86::reg32 cf = (op & 0x80000000);
            op = op << 1 | cf >> 31;
            shift--;
        }
    }
    // 005266ac  6601f9                 -add cx, di
    (cpu.cx) += x86::reg16(x86::sreg16(cpu.di));
    // 005266af  c1c710                 -rol edi, 0x10
    {
        x86::reg32& op = cpu.edi;
        x86::reg32 shift = 16 /*0x10*/ % 32;
        while (shift)
        {
            x86::reg32 cf = (op & 0x80000000);
            op = op << 1 | cf >> 31;
            shift--;
        }
    }
    // 005266b2  c1c110                 -rol ecx, 0x10
    {
        x86::reg32& op = cpu.ecx;
        x86::reg32 shift = 16 /*0x10*/ % 32;
        while (shift)
        {
            x86::reg32 cf = (op & 0x80000000);
            op = op << 1 | cf >> 31;
            shift--;
        }
    }
    // 005266b5  81e2ffff0f00           -and edx, 0xfffff
    cpu.edx &= x86::reg32(x86::sreg32(1048575 /*0xfffff*/));
    // 005266bb  81e6ffff0f00           -and esi, 0xfffff
    cpu.esi &= x86::reg32(x86::sreg32(1048575 /*0xfffff*/));
    // 005266c1  6609ff                 +or di, di
    cpu.clear_co();
    cpu.set_szp((cpu.di |= x86::reg16(x86::sreg16(cpu.di))));
    // 005266c4  7406                   -je 0x5266cc
    if (cpu.flags.zf)
    {
        goto L_0x005266cc;
    }
    // 005266c6  81ca00001000           -or edx, 0x100000
    cpu.edx |= x86::reg32(x86::sreg32(1048576 /*0x100000*/));
L_0x005266cc:
    // 005266cc  6609c9                 +or cx, cx
    cpu.clear_co();
    cpu.set_szp((cpu.cx |= x86::reg16(x86::sreg16(cpu.cx))));
    // 005266cf  7406                   -je 0x5266d7
    if (cpu.flags.zf)
    {
        goto L_0x005266d7;
    }
    // 005266d1  81ce00001000           -or esi, 0x100000
    cpu.esi |= x86::reg32(x86::sreg32(1048576 /*0x100000*/));
L_0x005266d7:
    // 005266d7  01c0                   +add eax, eax
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
    // 005266d9  11d2                   -adc edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 005266db  01db                   +add ebx, ebx
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
    // 005266dd  11f6                   -adc esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi) + cpu.flags.cf);
    // 005266df  6629f9                 +sub cx, di
    {
        x86::reg16& tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(cpu.di));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 005266e2  742f                   -je 0x526713
    if (cpu.flags.zf)
    {
        goto L_0x00526713;
    }
    // 005266e4  7308                   -jae 0x5266ee
    if (!cpu.flags.cf)
    {
        goto L_0x005266ee;
    }
    // 005266e6  89fd                   -mov ebp, edi
    cpu.ebp = cpu.edi;
    // 005266e8  66f7d9                 -neg cx
    cpu.cx = ~cpu.cx + 1;
    // 005266eb  93                     -xchg ebx, eax
    {
        x86::reg32 tmp = cpu.ebx;
        cpu.ebx = cpu.eax;
        cpu.eax = tmp;
    }
    // 005266ec  87f2                   -xchg edx, esi
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.esi;
        cpu.esi = tmp;
    }
L_0x005266ee:
    // 005266ee  6683f936               +cmp cx, 0x36
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(54 /*0x36*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 005266f2  761f                   -jbe 0x526713
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00526713;
    }
    // 005266f4  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 005266f6  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 005266f8  01ed                   +add ebp, ebp
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
    // 005266fa  d1da                   +rcr edx, 1
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
    // 005266fc  d1d8                   -rcr eax, 1
    {
        x86::reg32& op = cpu.eax;
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
    // 005266fe  81e2ffff0f80           -and edx, 0x800fffff
    cpu.edx &= x86::reg32(x86::sreg32(2148532223 /*0x800fffff*/));
    // 00526704  c1cd0d                 -ror ebp, 0xd
    {
        x86::reg32& op = cpu.ebp;
        x86::reg32 shift = 13 /*0xd*/ % 32;
        while (shift)
        {
            x86::reg32 cf = op & 1;
            op = op >> 1 | cf << 31;
            shift--;
        }
    }
    // 00526707  81e50000f07f           -and ebp, 0x7ff00000
    cpu.ebp &= x86::reg32(x86::sreg32(2146435072 /*0x7ff00000*/));
    // 0052670d  09ea                   -or edx, ebp
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ebp));
    // 0052670f  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00526710  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00526711  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00526712  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00526713:
    // 00526713  09c9                   +or ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00526715  790d                   -jns 0x526724
    if (!cpu.flags.sf)
    {
        goto L_0x00526724;
    }
    // 00526717  f7de                   -neg esi
    cpu.esi = ~cpu.esi + 1;
    // 00526719  f7db                   +neg ebx
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
    // 0052671b  83de00                 -sbb esi, 0
    (cpu.esi) -= x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 0052671e  81f500000080           -xor ebp, 0x80000000
    cpu.ebp ^= x86::reg32(x86::sreg32(2147483648 /*0x80000000*/));
L_0x00526724:
    // 00526724  29ff                   -sub edi, edi
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00526726  80f900                 +cmp cl, 0
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00526729  7423                   -je 0x52674e
    if (cpu.flags.zf)
    {
        goto L_0x0052674e;
    }
    // 0052672b  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052672c  29db                   -sub ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0052672e  80f920                 +cmp cl, 0x20
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
    // 00526731  720d                   -jb 0x526740
    if (cpu.flags.cf)
    {
        goto L_0x00526740;
    }
    // 00526733  09c0                   +or eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(cpu.eax))));
    // 00526735  0f95c3                 -setne bl
    cpu.bl = !cpu.flags.zf;
    // 00526738  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0052673a  29db                   -sub ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0052673c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0052673e  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
L_0x00526740:
    // 00526740  0fadc3                 -shrd ebx, eax, cl
    {
        x86::reg32& destination = cpu.ebx;
        destination >>= (cpu.cl % 32);
        destination |= cpu.eax  << (32 - (cpu.cl % 32));
    }
    // 00526743  09df                   -or edi, ebx
    cpu.edi |= x86::reg32(x86::sreg32(cpu.ebx));
    // 00526745  29db                   -sub ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00526747  0fadd0                 -shrd eax, edx, cl
    {
        x86::reg32& destination = cpu.eax;
        destination >>= (cpu.cl % 32);
        destination |= cpu.edx  << (32 - (cpu.cl % 32));
    }
    // 0052674a  0fadda                 -shrd edx, ebx, cl
    {
        x86::reg32& destination = cpu.edx;
        destination >>= (cpu.cl % 32);
        destination |= cpu.ebx  << (32 - (cpu.cl % 32));
    }
    // 0052674d  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0052674e:
    // 0052674e  01d8                   +add eax, ebx
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
    // 00526750  11f2                   +adc edx, esi
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00526752  7923                   -jns 0x526777
    if (!cpu.flags.sf)
    {
        goto L_0x00526777;
    }
    // 00526754  80f935                 +cmp cl, 0x35
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(53 /*0x35*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00526757  7211                   -jb 0x52676a
    if (cpu.flags.cf)
    {
        goto L_0x0052676a;
    }
    // 00526759  f7c7ffffff7f           +test edi, 0x7fffffff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & 2147483647 /*0x7fffffff*/));
    // 0052675f  0f95c3                 -setne bl
    cpu.bl = !cpu.flags.zf;
    // 00526762  d1eb                   +shr ebx, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.ebx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 00526764  83d000                 +adc eax, 0
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
    // 00526767  83d200                 -adc edx, 0
    (cpu.edx) += x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
L_0x0052676a:
    // 0052676a  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 0052676c  f7d8                   +neg eax
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
    // 0052676e  83da00                 -sbb edx, 0
    (cpu.edx) -= x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 00526771  81f500000080           -xor ebp, 0x80000000
    cpu.ebp ^= x86::reg32(x86::sreg32(2147483648 /*0x80000000*/));
L_0x00526777:
    // 00526777  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00526779  09d3                   +or ebx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(cpu.edx))));
    // 0052677b  746a                   -je 0x5267e7
    if (cpu.flags.zf)
    {
        goto L_0x005267e7;
    }
    // 0052677d  6609ed                 +or bp, bp
    cpu.clear_co();
    cpu.set_szp((cpu.bp |= x86::reg16(x86::sreg16(cpu.bp))));
    // 00526780  7469                   -je 0x5267eb
    if (cpu.flags.zf)
    {
        goto L_0x005267eb;
    }
L_0x00526782:
    // 00526782  f7c20000e07f           +test edx, 0x7fe00000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 2145386496 /*0x7fe00000*/));
    // 00526788  750a                   -jne 0x526794
    if (!cpu.flags.zf)
    {
        goto L_0x00526794;
    }
    // 0052678a  664d                   +dec bp
    {
        x86::reg16& tmp = cpu.bp;
        cpu.flags.of = 1 & (tmp >> 15);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 15));
        cpu.set_szp(tmp);
    }
    // 0052678c  745d                   -je 0x5267eb
    if (cpu.flags.zf)
    {
        goto L_0x005267eb;
    }
    // 0052678e  01c0                   +add eax, eax
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
    // 00526790  11d2                   +adc edx, edx
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
    // 00526792  ebee                   -jmp 0x526782
    goto L_0x00526782;
L_0x00526794:
    // 00526794  f7c200004000           +test edx, 0x400000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 4194304 /*0x400000*/));
    // 0052679a  7410                   -je 0x5267ac
    if (cpu.flags.zf)
    {
        goto L_0x005267ac;
    }
    // 0052679c  d1ea                   +shr edx, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 0052679e  d1d8                   +rcr eax, 1
    {
        x86::reg32& op = cpu.eax;
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
    // 005267a0  83d700                 -adc edi, 0
    (cpu.edi) += x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 005267a3  6645                   -inc bp
    (cpu.bp)++;
    // 005267a5  6681fdff07             +cmp bp, 0x7ff
    {
        x86::reg16 tmp1 = cpu.bp;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(2047 /*0x7ff*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 005267aa  7449                   -je 0x5267f5
    if (cpu.flags.zf)
    {
        goto L_0x005267f5;
    }
L_0x005267ac:
    // 005267ac  d1ea                   +shr edx, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 005267ae  d1d8                   +rcr eax, 1
    {
        x86::reg32& op = cpu.eax;
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
    // 005267b0  7324                   -jae 0x5267d6
    if (!cpu.flags.cf)
    {
        goto L_0x005267d6;
    }
    // 005267b2  09ff                   +or edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi |= x86::reg32(x86::sreg32(cpu.edi))));
    // 005267b4  0f95c3                 -setne bl
    cpu.bl = !cpu.flags.zf;
    // 005267b7  09c3                   -or ebx, eax
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.eax));
    // 005267b9  d1eb                   +shr ebx, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.ebx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 005267bb  83d000                 +adc eax, 0
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
    // 005267be  83d200                 -adc edx, 0
    (cpu.edx) += x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 005267c1  f7c200002000           +test edx, 0x200000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 2097152 /*0x200000*/));
    // 005267c7  740d                   -je 0x5267d6
    if (cpu.flags.zf)
    {
        goto L_0x005267d6;
    }
    // 005267c9  d1ea                   +shr edx, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 005267cb  d1d8                   -rcr eax, 1
    {
        x86::reg32& op = cpu.eax;
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
    // 005267cd  6645                   -inc bp
    (cpu.bp)++;
    // 005267cf  6681fdff07             +cmp bp, 0x7ff
    {
        x86::reg16 tmp1 = cpu.bp;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(2047 /*0x7ff*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 005267d4  741f                   -je 0x5267f5
    if (cpu.flags.zf)
    {
        goto L_0x005267f5;
    }
L_0x005267d6:
    // 005267d6  81e2ffff0f00           -and edx, 0xfffff
    cpu.edx &= x86::reg32(x86::sreg32(1048575 /*0xfffff*/));
    // 005267dc  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 005267de  c1e515                 -shl ebp, 0x15
    cpu.ebp <<= 21 /*0x15*/ % 32;
    // 005267e1  01c9                   +add ecx, ecx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 005267e3  d1dd                   -rcr ebp, 1
    {
        x86::reg32& op = cpu.ebp;
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
    // 005267e5  09ea                   -or edx, ebp
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ebp));
L_0x005267e7:
    // 005267e7  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005267e8  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005267e9  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005267ea  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005267eb:
    // 005267eb  01ed                   +add ebp, ebp
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
    // 005267ed  d1da                   +rcr edx, 1
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
    // 005267ef  d1d8                   +rcr eax, 1
    {
        x86::reg32& op = cpu.eax;
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
    // 005267f1  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005267f2  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005267f3  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005267f4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005267f5:
    // 005267f5  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 005267f7  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005267f8  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005267f9  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005267fa  e9a8600000             -jmp 0x52c8a7
    return sub_52c8a7(app, cpu);
}

/* align: skip  */
void Application::sub_5267ff(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005267ff  09c0                   +or eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(cpu.eax))));
    // 00526801  7507                   -jne 0x52680a
    if (!cpu.flags.zf)
    {
        goto L_0x0052680a;
    }
    // 00526803  01d2                   +add edx, edx
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00526805  7501                   -jne 0x526808
    if (!cpu.flags.zf)
    {
        goto L_0x00526808;
    }
    // 00526807  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00526808:
    // 00526808  d1da                   -rcr edx, 1
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
L_0x0052680a:
    // 0052680a  09db                   +or ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0052680c  750b                   -jne 0x526819
    if (!cpu.flags.zf)
    {
        goto L_0x00526819;
    }
    // 0052680e  01c9                   +add ecx, ecx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00526810  7505                   -jne 0x526817
    if (!cpu.flags.zf)
    {
        goto L_0x00526817;
    }
    // 00526812  29c0                   -sub eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00526814  29d2                   +sub edx, edx
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00526816  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00526817:
    // 00526817  d1d9                   -rcr ecx, 1
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
L_0x00526819:
    // 00526819  803dc144560000         +cmp byte ptr [0x5644c1], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(x86::reg32(5653697) /* 0x5644c1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00526820  740f                   -je 0x526831
    if (cpu.flags.zf)
    {
        goto L_0x00526831;
    }
    // 00526822  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00526823  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00526824  dd0424                 +fld qword ptr [esp]
    cpu.fpu.push(x86::Float(*app->getMemory<double>(cpu.esp)));
    // 00526827  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00526828  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00526829  dc0c24                 +fmul qword ptr [esp]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<double>(cpu.esp));
    // 0052682c  e943feffff             -jmp 0x526674
    return sub_526674(app, cpu);
L_0x00526831:
    // 00526831  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00526832  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00526833  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00526834  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00526836  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00526838  c1ff14                 -sar edi, 0x14
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (20 /*0x14*/ % 32));
    // 0052683b  c1f914                 -sar ecx, 0x14
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (20 /*0x14*/ % 32));
    // 0052683e  81e7ff070080           -and edi, 0x800007ff
    cpu.edi &= x86::reg32(x86::sreg32(2147485695 /*0x800007ff*/));
    // 00526844  81e1ff070080           -and ecx, 0x800007ff
    cpu.ecx &= x86::reg32(x86::sreg32(2147485695 /*0x800007ff*/));
    // 0052684a  c1c710                 -rol edi, 0x10
    {
        x86::reg32& op = cpu.edi;
        x86::reg32 shift = 16 /*0x10*/ % 32;
        while (shift)
        {
            x86::reg32 cf = (op & 0x80000000);
            op = op << 1 | cf >> 31;
            shift--;
        }
    }
    // 0052684d  c1c110                 -rol ecx, 0x10
    {
        x86::reg32& op = cpu.ecx;
        x86::reg32 shift = 16 /*0x10*/ % 32;
        while (shift)
        {
            x86::reg32 cf = (op & 0x80000000);
            op = op << 1 | cf >> 31;
            shift--;
        }
    }
    // 00526850  6601f9                 -add cx, di
    (cpu.cx) += x86::reg16(x86::sreg16(cpu.di));
    // 00526853  c1c710                 -rol edi, 0x10
    {
        x86::reg32& op = cpu.edi;
        x86::reg32 shift = 16 /*0x10*/ % 32;
        while (shift)
        {
            x86::reg32 cf = (op & 0x80000000);
            op = op << 1 | cf >> 31;
            shift--;
        }
    }
    // 00526856  c1c110                 -rol ecx, 0x10
    {
        x86::reg32& op = cpu.ecx;
        x86::reg32 shift = 16 /*0x10*/ % 32;
        while (shift)
        {
            x86::reg32 cf = (op & 0x80000000);
            op = op << 1 | cf >> 31;
            shift--;
        }
    }
    // 00526859  81e2ffff0f00           -and edx, 0xfffff
    cpu.edx &= x86::reg32(x86::sreg32(1048575 /*0xfffff*/));
    // 0052685f  81e6ffff0f00           -and esi, 0xfffff
    cpu.esi &= x86::reg32(x86::sreg32(1048575 /*0xfffff*/));
    // 00526865  6609ff                 +or di, di
    cpu.clear_co();
    cpu.set_szp((cpu.di |= x86::reg16(x86::sreg16(cpu.di))));
    // 00526868  7510                   -jne 0x52687a
    if (!cpu.flags.zf)
    {
        goto L_0x0052687a;
    }
    // 0052686a  6647                   -inc di
    (cpu.di)++;
L_0x0052686c:
    // 0052686c  664f                   -dec di
    (cpu.di)--;
    // 0052686e  01c0                   +add eax, eax
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
    // 00526870  11d2                   -adc edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00526872  f7c200001000           +test edx, 0x100000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 1048576 /*0x100000*/));
    // 00526878  74f2                   -je 0x52686c
    if (cpu.flags.zf)
    {
        goto L_0x0052686c;
    }
L_0x0052687a:
    // 0052687a  81ca00001000           -or edx, 0x100000
    cpu.edx |= x86::reg32(x86::sreg32(1048576 /*0x100000*/));
    // 00526880  6609c9                 +or cx, cx
    cpu.clear_co();
    cpu.set_szp((cpu.cx |= x86::reg16(x86::sreg16(cpu.cx))));
    // 00526883  7510                   -jne 0x526895
    if (!cpu.flags.zf)
    {
        goto L_0x00526895;
    }
    // 00526885  6641                   -inc cx
    (cpu.cx)++;
L_0x00526887:
    // 00526887  6649                   -dec cx
    (cpu.cx)--;
    // 00526889  01db                   +add ebx, ebx
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
    // 0052688b  11f6                   -adc esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi) + cpu.flags.cf);
    // 0052688d  f7c600001000           +test esi, 0x100000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & 1048576 /*0x100000*/));
    // 00526893  74f2                   -je 0x526887
    if (cpu.flags.zf)
    {
        goto L_0x00526887;
    }
L_0x00526895:
    // 00526895  81ce00001000           -or esi, 0x100000
    cpu.esi |= x86::reg32(x86::sreg32(1048576 /*0x100000*/));
    // 0052689b  6601f9                 -add cx, di
    (cpu.cx) += x86::reg16(x86::sreg16(cpu.di));
    // 0052689e  6681e9ff03             +sub cx, 0x3ff
    {
        x86::reg16& tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(1023 /*0x3ff*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 005268a3  7811                   -js 0x5268b6
    if (cpu.flags.sf)
    {
        goto L_0x005268b6;
    }
    // 005268a5  6681f9ff07             +cmp cx, 0x7ff
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(2047 /*0x7ff*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 005268aa  720a                   -jb 0x5268b6
    if (cpu.flags.cf)
    {
        goto L_0x005268b6;
    }
    // 005268ac  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 005268ae  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005268af  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005268b0  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005268b1  e9f15f0000             -jmp 0x52c8a7
    return sub_52c8a7(app, cpu);
L_0x005268b6:
    // 005268b6  6683f9cb               +cmp cx, -0x35
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(-53 /*-0x35*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 005268ba  7d08                   -jge 0x5268c4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x005268c4;
    }
    // 005268bc  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005268bd  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005268be  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005268bf  e9c65f0000             -jmp 0x52c88a
    return sub_52c88a(app, cpu);
L_0x005268c4:
    // 005268c4  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005268c5  b10b                   -mov cl, 0xb
    cpu.cl = 11 /*0xb*/;
    // 005268c7  0fa5c2                 -shld edx, eax, cl
    {
        x86::reg32& destination = cpu.edx;
        destination <<= (cpu.cl % 32);
        destination |= cpu.eax >> (32 - (cpu.cl % 32));
    }
    // 005268ca  0fa5e8                 -shld eax, ebp, cl
    {
        x86::reg32& destination = cpu.eax;
        destination <<= (cpu.cl % 32);
        destination |= cpu.ebp >> (32 - (cpu.cl % 32));
    }
    // 005268cd  2500f8ffff             -and eax, 0xfffff800
    cpu.eax &= x86::reg32(x86::sreg32(4294965248 /*0xfffff800*/));
    // 005268d2  0fa5de                 -shld esi, ebx, cl
    {
        x86::reg32& destination = cpu.esi;
        destination <<= (cpu.cl % 32);
        destination |= cpu.ebx >> (32 - (cpu.cl % 32));
    }
    // 005268d5  0fa5eb                 -shld ebx, ebp, cl
    {
        x86::reg32& destination = cpu.ebx;
        destination <<= (cpu.cl % 32);
        destination |= cpu.ebp >> (32 - (cpu.cl % 32));
    }
    // 005268d8  81e300f8ffff           -and ebx, 0xfffff800
    cpu.ebx &= x86::reg32(x86::sreg32(4294965248 /*0xfffff800*/));
    // 005268de  29ed                   -sub ebp, ebp
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 005268e0  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005268e1  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005268e2  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005268e3  f7e3                   -mul ebx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ebx);
    // 005268e5  96                     -xchg esi, eax
    {
        x86::reg32 tmp = cpu.esi;
        cpu.esi = cpu.eax;
        cpu.eax = tmp;
    }
    // 005268e6  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 005268e8  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005268e9  f7e2                   -mul edx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.edx);
    // 005268eb  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 005268ed  01c1                   +add ecx, eax
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
    // 005268ef  11ef                   +adc edi, ebp
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 005268f1  11ed                   -adc ebp, ebp
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ebp) + cpu.flags.cf);
    // 005268f3  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005268f4  93                     -xchg ebx, eax
    {
        x86::reg32 tmp = cpu.ebx;
        cpu.ebx = cpu.eax;
        cpu.eax = tmp;
    }
    // 005268f5  f7e3                   -mul ebx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ebx);
    // 005268f7  01c1                   +add ecx, eax
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
    // 005268f9  11d7                   +adc edi, edx
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 005268fb  83d500                 -adc ebp, 0
    (cpu.ebp) += x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 005268fe  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00526900  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00526901  f7e2                   -mul edx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.edx);
    // 00526903  01f8                   +add eax, edi
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
    // 00526905  11ea                   -adc edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp) + cpu.flags.cf);
    // 00526907  29db                   -sub ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00526909  b10a                   -mov cl, 0xa
    cpu.cl = 10 /*0xa*/;
    // 0052690b  0fadc3                 -shrd ebx, eax, cl
    {
        x86::reg32& destination = cpu.ebx;
        destination >>= (cpu.cl % 32);
        destination |= cpu.eax  << (32 - (cpu.cl % 32));
    }
    // 0052690e  0fadd0                 -shrd eax, edx, cl
    {
        x86::reg32& destination = cpu.eax;
        destination >>= (cpu.cl % 32);
        destination |= cpu.edx  << (32 - (cpu.cl % 32));
    }
    // 00526911  0fadda                 -shrd edx, ebx, cl
    {
        x86::reg32& destination = cpu.edx;
        destination >>= (cpu.cl % 32);
        destination |= cpu.ebx  << (32 - (cpu.cl % 32));
    }
    // 00526914  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00526915:
    // 00526915  f7c200002000           +test edx, 0x200000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 2097152 /*0x200000*/));
    // 0052691b  7411                   -je 0x52692e
    if (cpu.flags.zf)
    {
        goto L_0x0052692e;
    }
    // 0052691d  d1ea                   +shr edx, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 0052691f  d1d8                   +rcr eax, 1
    {
        x86::reg32& op = cpu.eax;
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
    // 00526921  d1db                   -rcr ebx, 1
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
    // 00526923  6641                   -inc cx
    (cpu.cx)++;
    // 00526925  6681f9ff07             +cmp cx, 0x7ff
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(2047 /*0x7ff*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0052692a  7466                   -je 0x526992
    if (cpu.flags.zf)
    {
        goto L_0x00526992;
    }
    // 0052692c  ebe7                   -jmp 0x526915
    goto L_0x00526915;
L_0x0052692e:
    // 0052692e  01db                   +add ebx, ebx
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
    // 00526930  732a                   -jae 0x52695c
    if (!cpu.flags.cf)
    {
        goto L_0x0052695c;
    }
    // 00526932  750d                   -jne 0x526941
    if (!cpu.flags.zf)
    {
        goto L_0x00526941;
    }
    // 00526934  09f6                   +or esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi |= x86::reg32(x86::sreg32(cpu.esi))));
    // 00526936  0f95c3                 -setne bl
    cpu.bl = !cpu.flags.zf;
    // 00526939  d1eb                   +shr ebx, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.ebx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 0052693b  7204                   -jb 0x526941
    if (cpu.flags.cf)
    {
        goto L_0x00526941;
    }
    // 0052693d  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0052693f  d1ee                   +shr esi, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.esi;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
L_0x00526941:
    // 00526941  83d000                 +adc eax, 0
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
    // 00526944  83d200                 -adc edx, 0
    (cpu.edx) += x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 00526947  f7c200002000           +test edx, 0x200000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 2097152 /*0x200000*/));
    // 0052694d  740d                   -je 0x52695c
    if (cpu.flags.zf)
    {
        goto L_0x0052695c;
    }
    // 0052694f  d1ea                   +shr edx, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 00526951  d1d8                   -rcr eax, 1
    {
        x86::reg32& op = cpu.eax;
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
    // 00526953  6641                   -inc cx
    (cpu.cx)++;
    // 00526955  6681f9ff07             +cmp cx, 0x7ff
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(2047 /*0x7ff*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0052695a  7436                   -je 0x526992
    if (cpu.flags.zf)
    {
        goto L_0x00526992;
    }
L_0x0052695c:
    // 0052695c  6609c9                 +or cx, cx
    cpu.clear_co();
    cpu.set_szp((cpu.cx |= x86::reg16(x86::sreg16(cpu.cx))));
    // 0052695f  7f16                   -jg 0x526977
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00526977;
    }
    // 00526961  7504                   -jne 0x526967
    if (!cpu.flags.zf)
    {
        goto L_0x00526967;
    }
    // 00526963  b101                   -mov cl, 1
    cpu.cl = 1 /*0x1*/;
    // 00526965  eb05                   -jmp 0x52696c
    goto L_0x0052696c;
L_0x00526967:
    // 00526967  66f7d9                 -neg cx
    cpu.cx = ~cpu.cx + 1;
    // 0052696a  6649                   -dec cx
    (cpu.cx)--;
L_0x0052696c:
    // 0052696c  29db                   -sub ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0052696e  0fadd0                 -shrd eax, edx, cl
    {
        x86::reg32& destination = cpu.eax;
        destination >>= (cpu.cl % 32);
        destination |= cpu.edx  << (32 - (cpu.cl % 32));
    }
    // 00526971  0fadda                 -shrd edx, ebx, cl
    {
        x86::reg32& destination = cpu.edx;
        destination >>= (cpu.cl % 32);
        destination |= cpu.ebx  << (32 - (cpu.cl % 32));
    }
    // 00526974  6629c9                 -sub cx, cx
    (cpu.cx) -= x86::reg16(x86::sreg16(cpu.cx));
L_0x00526977:
    // 00526977  81e2ffff0f00           -and edx, 0xfffff
    cpu.edx &= x86::reg32(x86::sreg32(1048575 /*0xfffff*/));
    // 0052697d  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0052697f  c1c90b                 -ror ecx, 0xb
    {
        x86::reg32& op = cpu.ecx;
        x86::reg32 shift = 11 /*0xb*/ % 32;
        while (shift)
        {
            x86::reg32 cf = op & 1;
            op = op >> 1 | cf << 31;
            shift--;
        }
    }
    // 00526982  01f6                   +add esi, esi
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
    // 00526984  d1d9                   -rcr ecx, 1
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
    // 00526986  81e10000f0ff           -and ecx, 0xfff00000
    cpu.ecx &= x86::reg32(x86::sreg32(4293918720 /*0xfff00000*/));
    // 0052698c  09ca                   +or edx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.edx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0052698e  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052698f  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00526990  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00526991  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00526992:
    // 00526992  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00526994  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00526995  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00526996  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00526997  e90b5f0000             -jmp 0x52c8a7
    return sub_52c8a7(app, cpu);
}

/* align: skip  */
void Application::sub_52699c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052699c  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052699d  f7c20000f07f           +test edx, 0x7ff00000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 2146435072 /*0x7ff00000*/));
    // 005269a3  7502                   -jne 0x5269a7
    if (!cpu.flags.zf)
    {
        goto L_0x005269a7;
    }
    // 005269a5  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
L_0x005269a7:
    // 005269a7  f7c10000f07f           +test ecx, 0x7ff00000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & 2146435072 /*0x7ff00000*/));
    // 005269ad  7502                   -jne 0x5269b1
    if (!cpu.flags.zf)
    {
        goto L_0x005269b1;
    }
    // 005269af  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
L_0x005269b1:
    // 005269b1  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 005269b3  31d5                   +xor ebp, edx
    cpu.clear_co();
    cpu.set_szp((cpu.ebp ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 005269b5  bd00000000             -mov ebp, 0
    cpu.ebp = 0 /*0x0*/;
    // 005269ba  780c                   -js 0x5269c8
    if (cpu.flags.sf)
    {
        goto L_0x005269c8;
    }
    // 005269bc  39ca                   +cmp edx, ecx
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
    // 005269be  7502                   -jne 0x5269c2
    if (!cpu.flags.zf)
    {
        goto L_0x005269c2;
    }
    // 005269c0  39d8                   +cmp eax, ebx
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
L_0x005269c2:
    // 005269c2  740c                   -je 0x5269d0
    if (cpu.flags.zf)
    {
        goto L_0x005269d0;
    }
    // 005269c4  d1d9                   -rcr ecx, 1
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
    // 005269c6  31ca                   -xor edx, ecx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x005269c8:
    // 005269c8  01d2                   +add edx, edx
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 005269ca  83dd00                 -sbb ebp, 0
    (cpu.ebp) -= x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 005269cd  01ed                   -add ebp, ebp
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ebp));
    // 005269cf  45                     -inc ebp
    (cpu.ebp)++;
L_0x005269d0:
    // 005269d0  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 005269d2  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005269d3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_5269d4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005269d4  db6c2410               -fld xword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 005269d8  db6c2404               -fld xword ptr [esp + 4]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(4) /* 0x4 */)));
L_0x005269dc:
    // 005269dc  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 005269e0  01c0                   +add eax, eax
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
    // 005269e2  0f8386000000           -jae 0x526a6e
    if (!cpu.flags.cf)
    {
        goto L_0x00526a6e;
    }
    // 005269e8  350000000e             -xor eax, 0xe000000
    cpu.eax ^= x86::reg32(x86::sreg32(234881024 /*0xe000000*/));
    // 005269ed  a90000000e             +test eax, 0xe000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 234881024 /*0xe000000*/));
    // 005269f2  7403                   -je 0x5269f7
    if (cpu.flags.zf)
    {
        goto L_0x005269f7;
    }
    // 005269f4  def9                   -fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 005269f6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005269f7:
    // 005269f7  c1e81c                 -shr eax, 0x1c
    cpu.eax >>= 28 /*0x1c*/ % 32;
    // 005269fa  80b8c0cc560000         +cmp byte ptr [eax + 0x56ccc0], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5688512) /* 0x56ccc0 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00526a01  7503                   -jne 0x526a06
    if (!cpu.flags.zf)
    {
        goto L_0x00526a06;
    }
    // 00526a03  def9                   -fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00526a05  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00526a06:
    // 00526a06  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00526a0a  25ff7f0000             +and eax, 0x7fff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(32767 /*0x7fff*/))));
    // 00526a0f  7467                   -je 0x526a78
    if (cpu.flags.zf)
    {
        goto L_0x00526a78;
    }
    // 00526a11  3dff7f0000             +cmp eax, 0x7fff
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
    // 00526a16  7460                   -je 0x526a78
    if (cpu.flags.zf)
    {
        goto L_0x00526a78;
    }
    // 00526a18  d97c241c               -fnstcw word ptr [esp + 0x1c]
    *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.fpu.control.word;
    // 00526a1c  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00526a20  0d3f030000             -or eax, 0x33f
    cpu.eax |= x86::reg32(x86::sreg32(831 /*0x33f*/));
    // 00526a25  25fff30000             -and eax, 0xf3ff
    cpu.eax &= x86::reg32(x86::sreg32(62463 /*0xf3ff*/));
    // 00526a2a  89442420               -mov dword ptr [esp + 0x20], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 00526a2e  d96c2420               -fldcw word ptr [esp + 0x20]
    cpu.fpu.control.word = *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00526a32  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00526a36  25ff7f0000             -and eax, 0x7fff
    cpu.eax &= x86::reg32(x86::sreg32(32767 /*0x7fff*/));
    // 00526a3b  83f801                 +cmp eax, 1
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
    // 00526a3e  7417                   -je 0x526a57
    if (cpu.flags.zf)
    {
        goto L_0x00526a57;
    }
    // 00526a40  d80dd0cc5600           -fmul dword ptr [0x56ccd0]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(5688528) /* 0x56ccd0 */));
    // 00526a46  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00526a48  d80dd0cc5600           -fmul dword ptr [0x56ccd0]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(5688528) /* 0x56ccd0 */));
    // 00526a4e  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00526a50  d96c241c               -fldcw word ptr [esp + 0x1c]
    cpu.fpu.control.word = *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00526a54  def9                   -fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00526a56  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00526a57:
    // 00526a57  d80dd4cc5600           -fmul dword ptr [0x56ccd4]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(5688532) /* 0x56ccd4 */));
    // 00526a5d  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00526a5f  d80dd4cc5600           -fmul dword ptr [0x56ccd4]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(5688532) /* 0x56ccd4 */));
    // 00526a65  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00526a67  d96c241c               -fldcw word ptr [esp + 0x1c]
    cpu.fpu.control.word = *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00526a6b  def9                   -fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00526a6d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00526a6e:
    // 00526a6e  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00526a72  0b442408               +or eax, dword ptr [esp + 8]
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */)))));
    // 00526a76  7503                   -jne 0x526a7b
    if (!cpu.flags.zf)
    {
        goto L_0x00526a7b;
    }
L_0x00526a78:
    // 00526a78  def9                   -fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00526a7a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00526a7b:
    // 00526a7b  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00526a7f  25ff7f0000             +and eax, 0x7fff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(32767 /*0x7fff*/))));
    // 00526a84  75f2                   -jne 0x526a78
    if (!cpu.flags.zf)
    {
        goto L_0x00526a78;
    }
    // 00526a86  d97c241c               -fnstcw word ptr [esp + 0x1c]
    *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.fpu.control.word;
    // 00526a8a  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00526a8e  0d3f030000             -or eax, 0x33f
    cpu.eax |= x86::reg32(x86::sreg32(831 /*0x33f*/));
    // 00526a93  25fff30000             -and eax, 0xf3ff
    cpu.eax &= x86::reg32(x86::sreg32(62463 /*0xf3ff*/));
    // 00526a98  89442420               -mov dword ptr [esp + 0x20], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 00526a9c  d96c2420               -fldcw word ptr [esp + 0x20]
    cpu.fpu.control.word = *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00526aa0  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00526aa4  25ff7f0000             +and eax, 0x7fff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(32767 /*0x7fff*/))));
    // 00526aa9  7411                   -je 0x526abc
    if (cpu.flags.zf)
    {
        goto L_0x00526abc;
    }
    // 00526aab  3dff7f0000             +cmp eax, 0x7fff
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
    // 00526ab0  7432                   -je 0x526ae4
    if (cpu.flags.zf)
    {
        goto L_0x00526ae4;
    }
    // 00526ab2  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00526ab6  01c0                   +add eax, eax
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
    // 00526ab8  732a                   -jae 0x526ae4
    if (!cpu.flags.cf)
    {
        goto L_0x00526ae4;
    }
    // 00526aba  eb08                   -jmp 0x526ac4
    goto L_0x00526ac4;
L_0x00526abc:
    // 00526abc  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00526ac0  01c0                   +add eax, eax
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
    // 00526ac2  7220                   -jb 0x526ae4
    if (cpu.flags.cf)
    {
        goto L_0x00526ae4;
    }
L_0x00526ac4:
    // 00526ac4  d9c9                   +fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00526ac6  ddd8                   +fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526ac8  d9c0                   +fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 00526aca  d80dd8cc5600           +fmul dword ptr [0x56ccd8]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(5688536) /* 0x56ccd8 */));
    // 00526ad0  db7c2404               +fstp xword ptr [esp + 4]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(4) /* 0x4 */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526ad4  db6c2410               +fld xword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 00526ad8  d9c9                   +fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00526ada  9b                     -wait 
    /*nothing*/;
    // 00526adb  d96c241c               -fldcw word ptr [esp + 0x1c]
    cpu.fpu.control.word = *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00526adf  e9f8feffff             -jmp 0x5269dc
    goto L_0x005269dc;
L_0x00526ae4:
    // 00526ae4  d96c241c               -fldcw word ptr [esp + 0x1c]
    cpu.fpu.control.word = *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00526ae8  def9                   -fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00526aea  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_526aeb(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00526aeb  83ec2c                 +sub esp, 0x2c
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(44 /*0x2c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00526aee  ff2485dccc5600         -jmp dword ptr [eax*4 + 0x56ccdc]
    cpu.ip = *app->getMemory<x86::reg32>(5688540 + cpu.eax * 4); goto dynamic_jump;
  case 0x00526af5:
    // 00526af5  d8f0                   -fdiv st(0)
    cpu.fpu.st(0) /= x86::Float(cpu.fpu.st(0));
    // 00526af7  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00526afa  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00526afb:
    // 00526afb  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00526afe  cd06                   -int 6
    NFS2_ASSERT(false);
  [[fallthrough]];
  case 0x00526b00:
    // 00526b00  d8f8                   -fdivr st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0)) / cpu.fpu.st(0);
    // 00526b02  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00526b05  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00526b06:
    // 00526b06  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00526b09  cd06                   -int 6
    NFS2_ASSERT(false);
  [[fallthrough]];
  case 0x00526b0b:
    // 00526b0b  d8f0                   -fdiv st(0)
    cpu.fpu.st(0) /= x86::Float(cpu.fpu.st(0));
    // 00526b0d  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00526b10  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00526b11:
    // 00526b11  def8                   -fdivp st(0)
    cpu.fpu.st(0) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00526b13  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00526b16  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00526b17:
    // 00526b17  d8f8                   -fdivr st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0)) / cpu.fpu.st(0);
    // 00526b19  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00526b1c  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00526b1d:
    // 00526b1d  def0                   -fdivrp st(0)
    cpu.fpu.st(0) = cpu.fpu.st(0) / x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526b1f  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00526b22  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00526b23:
    // 00526b23  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526b27  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 00526b29  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526b2c  db7c2420               -fstp xword ptr [esp + 0x20]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526b30  e89ffeffff             -call 0x5269d4
    cpu.esp -= 4;
    sub_5269d4(app, cpu);
    if (cpu.terminate) return;
    // 00526b35  db6c2420               -fld xword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 00526b39  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00526b3b  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00526b3e  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00526b3f:
    // 00526b3f  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00526b42  cd06                   -int 6
    NFS2_ASSERT(false);
  [[fallthrough]];
  case 0x00526b44:
    // 00526b44  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526b47  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526b4b  e884feffff             -call 0x5269d4
    cpu.esp -= 4;
    sub_5269d4(app, cpu);
    if (cpu.terminate) return;
    // 00526b50  db6c240c               -fld xword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 00526b54  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00526b56  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00526b59  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00526b5a:
    // 00526b5a  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00526b5d  cd06                   -int 6
    NFS2_ASSERT(false);
  [[fallthrough]];
  case 0x00526b5f:
    // 00526b5f  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00526b61  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526b65  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 00526b67  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526b6a  db7c2420               -fstp xword ptr [esp + 0x20]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526b6e  e861feffff             -call 0x5269d4
    cpu.esp -= 4;
    sub_5269d4(app, cpu);
    if (cpu.terminate) return;
    // 00526b73  db6c2420               -fld xword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 00526b77  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00526b7a  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00526b7b:
    // 00526b7b  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526b7e  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526b82  e84dfeffff             -call 0x5269d4
    cpu.esp -= 4;
    sub_5269d4(app, cpu);
    if (cpu.terminate) return;
    // 00526b87  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00526b8a  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00526b8b:
    // 00526b8b  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526b8f  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526b92  e83dfeffff             -call 0x5269d4
    cpu.esp -= 4;
    sub_5269d4(app, cpu);
    if (cpu.terminate) return;
    // 00526b97  db6c240c               -fld xword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 00526b9b  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00526b9e  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00526b9f:
    // 00526b9f  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526ba3  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526ba6  e829feffff             -call 0x5269d4
    cpu.esp -= 4;
    sub_5269d4(app, cpu);
    if (cpu.terminate) return;
    // 00526bab  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00526bae  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00526baf:
    // 00526baf  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526bb3  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00526bb5  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 00526bb7  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526bba  db7c2420               -fstp xword ptr [esp + 0x20]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526bbe  e811feffff             -call 0x5269d4
    cpu.esp -= 4;
    sub_5269d4(app, cpu);
    if (cpu.terminate) return;
    // 00526bc3  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00526bc5  db6c2420               -fld xword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 00526bc9  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 00526bcb  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00526bce  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00526bcf:
    // 00526bcf  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00526bd2  cd06                   -int 6
    NFS2_ASSERT(false);
  [[fallthrough]];
  case 0x00526bd4:
    // 00526bd4  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526bd7  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00526bd9  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526bdd  e8f2fdffff             -call 0x5269d4
    cpu.esp -= 4;
    sub_5269d4(app, cpu);
    if (cpu.terminate) return;
    // 00526be2  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00526be4  db6c240c               -fld xword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 00526be8  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 00526bea  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00526bed  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00526bee:
    // 00526bee  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00526bf1  cd06                   -int 6
    NFS2_ASSERT(false);
  [[fallthrough]];
  case 0x00526bf3:
    // 00526bf3  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 00526bf5  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526bf9  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00526bfb  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 00526bfd  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526c00  db7c2420               -fstp xword ptr [esp + 0x20]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526c04  e8cbfdffff             -call 0x5269d4
    cpu.esp -= 4;
    sub_5269d4(app, cpu);
    if (cpu.terminate) return;
    // 00526c09  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00526c0b  db6c2420               -fld xword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 00526c0f  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00526c12  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00526c13:
    // 00526c13  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526c16  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00526c18  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526c1c  e8b3fdffff             -call 0x5269d4
    cpu.esp -= 4;
    sub_5269d4(app, cpu);
    if (cpu.terminate) return;
    // 00526c21  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00526c23  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00526c26  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00526c27:
    // 00526c27  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526c2b  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00526c2d  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526c30  e89ffdffff             -call 0x5269d4
    cpu.esp -= 4;
    sub_5269d4(app, cpu);
    if (cpu.terminate) return;
    // 00526c35  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00526c37  db6c240c               -fld xword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 00526c3b  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00526c3e  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00526c3f:
    // 00526c3f  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526c43  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00526c45  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526c48  e887fdffff             -call 0x5269d4
    cpu.esp -= 4;
    sub_5269d4(app, cpu);
    if (cpu.terminate) return;
    // 00526c4d  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00526c4f  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00526c52  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00526c53:
    // 00526c53  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526c57  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 00526c59  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 00526c5b  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526c5e  db7c2420               -fstp xword ptr [esp + 0x20]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526c62  e86dfdffff             -call 0x5269d4
    cpu.esp -= 4;
    sub_5269d4(app, cpu);
    if (cpu.terminate) return;
    // 00526c67  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 00526c69  db6c2420               -fld xword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 00526c6d  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 00526c6f  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00526c72  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00526c73:
    // 00526c73  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00526c76  cd06                   -int 6
    NFS2_ASSERT(false);
  [[fallthrough]];
  case 0x00526c78:
    // 00526c78  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526c7b  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 00526c7d  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526c81  e84efdffff             -call 0x5269d4
    cpu.esp -= 4;
    sub_5269d4(app, cpu);
    if (cpu.terminate) return;
    // 00526c86  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 00526c88  db6c240c               -fld xword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 00526c8c  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 00526c8e  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00526c91  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00526c92:
    // 00526c92  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00526c95  cd06                   -int 6
    NFS2_ASSERT(false);
  [[fallthrough]];
  case 0x00526c97:
    // 00526c97  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 00526c99  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526c9d  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 00526c9f  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 00526ca1  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526ca4  db7c2420               -fstp xword ptr [esp + 0x20]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526ca8  e827fdffff             -call 0x5269d4
    cpu.esp -= 4;
    sub_5269d4(app, cpu);
    if (cpu.terminate) return;
    // 00526cad  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 00526caf  db6c2420               -fld xword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 00526cb3  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00526cb6  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00526cb7:
    // 00526cb7  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526cba  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 00526cbc  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526cc0  e80ffdffff             -call 0x5269d4
    cpu.esp -= 4;
    sub_5269d4(app, cpu);
    if (cpu.terminate) return;
    // 00526cc5  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 00526cc7  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00526cca  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00526ccb:
    // 00526ccb  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526ccf  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 00526cd1  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526cd4  e8fbfcffff             -call 0x5269d4
    cpu.esp -= 4;
    sub_5269d4(app, cpu);
    if (cpu.terminate) return;
    // 00526cd9  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 00526cdb  db6c240c               -fld xword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 00526cdf  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00526ce2  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00526ce3:
    // 00526ce3  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526ce7  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 00526ce9  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526cec  e8e3fcffff             -call 0x5269d4
    cpu.esp -= 4;
    sub_5269d4(app, cpu);
    if (cpu.terminate) return;
    // 00526cf1  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 00526cf3  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00526cf6  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00526cf7:
    // 00526cf7  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526cfb  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 00526cfd  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 00526cff  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526d02  db7c2420               -fstp xword ptr [esp + 0x20]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526d06  e8c9fcffff             -call 0x5269d4
    cpu.esp -= 4;
    sub_5269d4(app, cpu);
    if (cpu.terminate) return;
    // 00526d0b  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 00526d0d  db6c2420               -fld xword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 00526d11  d9cc                   -fxch st(4)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(4);
        cpu.fpu.st(4) = tmp;
    }
    // 00526d13  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00526d16  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00526d17:
    // 00526d17  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00526d1a  cd06                   -int 6
    NFS2_ASSERT(false);
  [[fallthrough]];
  case 0x00526d1c:
    // 00526d1c  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526d1f  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 00526d21  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526d25  e8aafcffff             -call 0x5269d4
    cpu.esp -= 4;
    sub_5269d4(app, cpu);
    if (cpu.terminate) return;
    // 00526d2a  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 00526d2c  db6c240c               -fld xword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 00526d30  d9cc                   -fxch st(4)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(4);
        cpu.fpu.st(4) = tmp;
    }
    // 00526d32  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00526d35  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00526d36:
    // 00526d36  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00526d39  cd06                   -int 6
    NFS2_ASSERT(false);
  [[fallthrough]];
  case 0x00526d3b:
    // 00526d3b  d9cc                   -fxch st(4)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(4);
        cpu.fpu.st(4) = tmp;
    }
    // 00526d3d  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526d41  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 00526d43  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 00526d45  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526d48  db7c2420               -fstp xword ptr [esp + 0x20]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526d4c  e883fcffff             -call 0x5269d4
    cpu.esp -= 4;
    sub_5269d4(app, cpu);
    if (cpu.terminate) return;
    // 00526d51  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 00526d53  db6c2420               -fld xword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 00526d57  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00526d5a  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00526d5b:
    // 00526d5b  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526d5e  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 00526d60  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526d64  e86bfcffff             -call 0x5269d4
    cpu.esp -= 4;
    sub_5269d4(app, cpu);
    if (cpu.terminate) return;
    // 00526d69  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 00526d6b  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00526d6e  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00526d6f:
    // 00526d6f  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526d73  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 00526d75  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526d78  e857fcffff             -call 0x5269d4
    cpu.esp -= 4;
    sub_5269d4(app, cpu);
    if (cpu.terminate) return;
    // 00526d7d  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 00526d7f  db6c240c               -fld xword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 00526d83  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00526d86  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00526d87:
    // 00526d87  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526d8b  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 00526d8d  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526d90  e83ffcffff             -call 0x5269d4
    cpu.esp -= 4;
    sub_5269d4(app, cpu);
    if (cpu.terminate) return;
    // 00526d95  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 00526d97  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00526d9a  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00526d9b:
    // 00526d9b  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526d9f  d9cc                   -fxch st(4)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(4);
        cpu.fpu.st(4) = tmp;
    }
    // 00526da1  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 00526da3  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526da6  db7c2420               -fstp xword ptr [esp + 0x20]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526daa  e825fcffff             -call 0x5269d4
    cpu.esp -= 4;
    sub_5269d4(app, cpu);
    if (cpu.terminate) return;
    // 00526daf  d9cc                   -fxch st(4)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(4);
        cpu.fpu.st(4) = tmp;
    }
    // 00526db1  db6c2420               -fld xword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 00526db5  d9cd                   -fxch st(5)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(5);
        cpu.fpu.st(5) = tmp;
    }
    // 00526db7  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00526dba  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00526dbb:
    // 00526dbb  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00526dbe  cd06                   -int 6
    NFS2_ASSERT(false);
  [[fallthrough]];
  case 0x00526dc0:
    // 00526dc0  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526dc3  d9cc                   -fxch st(4)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(4);
        cpu.fpu.st(4) = tmp;
    }
    // 00526dc5  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526dc9  e806fcffff             -call 0x5269d4
    cpu.esp -= 4;
    sub_5269d4(app, cpu);
    if (cpu.terminate) return;
    // 00526dce  d9cc                   -fxch st(4)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(4);
        cpu.fpu.st(4) = tmp;
    }
    // 00526dd0  db6c240c               -fld xword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 00526dd4  d9cd                   -fxch st(5)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(5);
        cpu.fpu.st(5) = tmp;
    }
    // 00526dd6  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00526dd9  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00526dda:
    // 00526dda  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00526ddd  cd06                   -int 6
    NFS2_ASSERT(false);
  [[fallthrough]];
  case 0x00526ddf:
    // 00526ddf  d9cd                   -fxch st(5)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(5);
        cpu.fpu.st(5) = tmp;
    }
    // 00526de1  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526de5  d9cc                   -fxch st(4)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(4);
        cpu.fpu.st(4) = tmp;
    }
    // 00526de7  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 00526de9  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526dec  db7c2420               -fstp xword ptr [esp + 0x20]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526df0  e8dffbffff             -call 0x5269d4
    cpu.esp -= 4;
    sub_5269d4(app, cpu);
    if (cpu.terminate) return;
    // 00526df5  d9cc                   -fxch st(4)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(4);
        cpu.fpu.st(4) = tmp;
    }
    // 00526df7  db6c2420               -fld xword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 00526dfb  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00526dfe  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00526dff:
    // 00526dff  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526e02  d9cc                   -fxch st(4)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(4);
        cpu.fpu.st(4) = tmp;
    }
    // 00526e04  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526e08  e8c7fbffff             -call 0x5269d4
    cpu.esp -= 4;
    sub_5269d4(app, cpu);
    if (cpu.terminate) return;
    // 00526e0d  d9cc                   -fxch st(4)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(4);
        cpu.fpu.st(4) = tmp;
    }
    // 00526e0f  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00526e12  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00526e13:
    // 00526e13  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526e17  d9cc                   -fxch st(4)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(4);
        cpu.fpu.st(4) = tmp;
    }
    // 00526e19  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526e1c  e8b3fbffff             -call 0x5269d4
    cpu.esp -= 4;
    sub_5269d4(app, cpu);
    if (cpu.terminate) return;
    // 00526e21  d9cc                   -fxch st(4)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(4);
        cpu.fpu.st(4) = tmp;
    }
    // 00526e23  db6c240c               -fld xword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 00526e27  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00526e2a  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00526e2b:
    // 00526e2b  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526e2f  d9cc                   -fxch st(4)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(4);
        cpu.fpu.st(4) = tmp;
    }
    // 00526e31  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526e34  e89bfbffff             -call 0x5269d4
    cpu.esp -= 4;
    sub_5269d4(app, cpu);
    if (cpu.terminate) return;
    // 00526e39  d9cc                   -fxch st(4)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(4);
        cpu.fpu.st(4) = tmp;
    }
    // 00526e3b  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00526e3e  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00526e3f:
    // 00526e3f  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526e43  d9cd                   -fxch st(5)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(5);
        cpu.fpu.st(5) = tmp;
    }
    // 00526e45  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 00526e47  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526e4a  db7c2420               -fstp xword ptr [esp + 0x20]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526e4e  e881fbffff             -call 0x5269d4
    cpu.esp -= 4;
    sub_5269d4(app, cpu);
    if (cpu.terminate) return;
    // 00526e53  d9cd                   -fxch st(5)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(5);
        cpu.fpu.st(5) = tmp;
    }
    // 00526e55  db6c2420               -fld xword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 00526e59  d9ce                   -fxch st(6)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(6);
        cpu.fpu.st(6) = tmp;
    }
    // 00526e5b  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00526e5e  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00526e5f:
    // 00526e5f  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00526e62  cd06                   -int 6
    NFS2_ASSERT(false);
  [[fallthrough]];
  case 0x00526e64:
    // 00526e64  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526e67  d9cd                   -fxch st(5)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(5);
        cpu.fpu.st(5) = tmp;
    }
    // 00526e69  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526e6d  e862fbffff             -call 0x5269d4
    cpu.esp -= 4;
    sub_5269d4(app, cpu);
    if (cpu.terminate) return;
    // 00526e72  d9cd                   -fxch st(5)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(5);
        cpu.fpu.st(5) = tmp;
    }
    // 00526e74  db6c240c               -fld xword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 00526e78  d9ce                   -fxch st(6)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(6);
        cpu.fpu.st(6) = tmp;
    }
    // 00526e7a  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00526e7d  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00526e7e:
    // 00526e7e  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00526e81  cd06                   -int 6
    NFS2_ASSERT(false);
  [[fallthrough]];
  case 0x00526e83:
    // 00526e83  d9ce                   -fxch st(6)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(6);
        cpu.fpu.st(6) = tmp;
    }
    // 00526e85  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526e89  d9cd                   -fxch st(5)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(5);
        cpu.fpu.st(5) = tmp;
    }
    // 00526e8b  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 00526e8d  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526e90  db7c2420               -fstp xword ptr [esp + 0x20]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526e94  e83bfbffff             -call 0x5269d4
    cpu.esp -= 4;
    sub_5269d4(app, cpu);
    if (cpu.terminate) return;
    // 00526e99  d9cd                   -fxch st(5)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(5);
        cpu.fpu.st(5) = tmp;
    }
    // 00526e9b  db6c2420               -fld xword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 00526e9f  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00526ea2  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00526ea3:
    // 00526ea3  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526ea6  d9cd                   -fxch st(5)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(5);
        cpu.fpu.st(5) = tmp;
    }
    // 00526ea8  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526eac  e823fbffff             -call 0x5269d4
    cpu.esp -= 4;
    sub_5269d4(app, cpu);
    if (cpu.terminate) return;
    // 00526eb1  d9cd                   -fxch st(5)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(5);
        cpu.fpu.st(5) = tmp;
    }
    // 00526eb3  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00526eb6  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00526eb7:
    // 00526eb7  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526ebb  d9cd                   -fxch st(5)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(5);
        cpu.fpu.st(5) = tmp;
    }
    // 00526ebd  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526ec0  e80ffbffff             -call 0x5269d4
    cpu.esp -= 4;
    sub_5269d4(app, cpu);
    if (cpu.terminate) return;
    // 00526ec5  d9cd                   -fxch st(5)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(5);
        cpu.fpu.st(5) = tmp;
    }
    // 00526ec7  db6c240c               -fld xword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 00526ecb  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00526ece  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00526ecf:
    // 00526ecf  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526ed3  d9cd                   -fxch st(5)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(5);
        cpu.fpu.st(5) = tmp;
    }
    // 00526ed5  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526ed8  e8f7faffff             -call 0x5269d4
    cpu.esp -= 4;
    sub_5269d4(app, cpu);
    if (cpu.terminate) return;
    // 00526edd  d9cd                   -fxch st(5)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(5);
        cpu.fpu.st(5) = tmp;
    }
    // 00526edf  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00526ee2  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00526ee3:
    // 00526ee3  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526ee7  d9ce                   -fxch st(6)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(6);
        cpu.fpu.st(6) = tmp;
    }
    // 00526ee9  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 00526eeb  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526eee  db7c2420               -fstp xword ptr [esp + 0x20]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526ef2  e8ddfaffff             -call 0x5269d4
    cpu.esp -= 4;
    sub_5269d4(app, cpu);
    if (cpu.terminate) return;
    // 00526ef7  d9ce                   -fxch st(6)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(6);
        cpu.fpu.st(6) = tmp;
    }
    // 00526ef9  db6c2420               -fld xword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 00526efd  d9cf                   -fxch st(7)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(7);
        cpu.fpu.st(7) = tmp;
    }
    // 00526eff  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00526f02  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00526f03:
    // 00526f03  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00526f06  cd06                   -int 6
    NFS2_ASSERT(false);
  [[fallthrough]];
  case 0x00526f08:
    // 00526f08  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526f0b  d9ce                   -fxch st(6)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(6);
        cpu.fpu.st(6) = tmp;
    }
    // 00526f0d  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526f11  e8befaffff             -call 0x5269d4
    cpu.esp -= 4;
    sub_5269d4(app, cpu);
    if (cpu.terminate) return;
    // 00526f16  d9ce                   -fxch st(6)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(6);
        cpu.fpu.st(6) = tmp;
    }
    // 00526f18  db6c240c               -fld xword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 00526f1c  d9cf                   -fxch st(7)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(7);
        cpu.fpu.st(7) = tmp;
    }
    // 00526f1e  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00526f21  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00526f22:
    // 00526f22  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00526f25  cd06                   -int 6
    NFS2_ASSERT(false);
  [[fallthrough]];
  case 0x00526f27:
    // 00526f27  d9cf                   -fxch st(7)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(7);
        cpu.fpu.st(7) = tmp;
    }
    // 00526f29  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526f2d  d9ce                   -fxch st(6)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(6);
        cpu.fpu.st(6) = tmp;
    }
    // 00526f2f  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 00526f31  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526f34  db7c2420               -fstp xword ptr [esp + 0x20]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526f38  e897faffff             -call 0x5269d4
    cpu.esp -= 4;
    sub_5269d4(app, cpu);
    if (cpu.terminate) return;
    // 00526f3d  d9ce                   -fxch st(6)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(6);
        cpu.fpu.st(6) = tmp;
    }
    // 00526f3f  db6c2420               -fld xword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 00526f43  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00526f46  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00526f47:
    // 00526f47  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526f4a  d9ce                   -fxch st(6)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(6);
        cpu.fpu.st(6) = tmp;
    }
    // 00526f4c  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526f50  e87ffaffff             -call 0x5269d4
    cpu.esp -= 4;
    sub_5269d4(app, cpu);
    if (cpu.terminate) return;
    // 00526f55  d9ce                   -fxch st(6)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(6);
        cpu.fpu.st(6) = tmp;
    }
    // 00526f57  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00526f5a  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00526f5b:
    // 00526f5b  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526f5f  d9ce                   -fxch st(6)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(6);
        cpu.fpu.st(6) = tmp;
    }
    // 00526f61  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526f64  e86bfaffff             -call 0x5269d4
    cpu.esp -= 4;
    sub_5269d4(app, cpu);
    if (cpu.terminate) return;
    // 00526f69  d9ce                   -fxch st(6)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(6);
        cpu.fpu.st(6) = tmp;
    }
    // 00526f6b  db6c240c               -fld xword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 00526f6f  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00526f72  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00526f73:
    // 00526f73  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526f77  d9ce                   -fxch st(6)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(6);
        cpu.fpu.st(6) = tmp;
    }
    // 00526f79  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526f7c  e853faffff             -call 0x5269d4
    cpu.esp -= 4;
    sub_5269d4(app, cpu);
    if (cpu.terminate) return;
    // 00526f81  d9ce                   -fxch st(6)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(6);
        cpu.fpu.st(6) = tmp;
    }
    // 00526f83  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00526f86  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void Application::sub_526f87(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00526f87  83ec2c                 -sub esp, 0x2c
    (cpu.esp) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00526f8a  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526f8d  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526f91  e83efaffff             -call 0x5269d4
    cpu.esp -= 4;
    sub_5269d4(app, cpu);
    if (cpu.terminate) return;
    // 00526f96  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00526f99  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_526f9a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00526f9a  83ec2c                 -sub esp, 0x2c
    (cpu.esp) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00526f9d  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526fa1  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526fa4  e82bfaffff             -call 0x5269d4
    cpu.esp -= 4;
    sub_5269d4(app, cpu);
    if (cpu.terminate) return;
    // 00526fa9  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00526fac  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_526fad(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00526fad  83ec2c                 -sub esp, 0x2c
    (cpu.esp) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00526fb0  db7c240c               -fstp xword ptr [esp + 0xc]
    *app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526fb4  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526fb7  e818faffff             -call 0x5269d4
    cpu.esp -= 4;
    sub_5269d4(app, cpu);
    if (cpu.terminate) return;
    // 00526fbc  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00526fbf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_526fc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00526fc0  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00526fc1  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00526fc5  250000807f             -and eax, 0x7f800000
    cpu.eax &= x86::reg32(x86::sreg32(2139095040 /*0x7f800000*/));
    // 00526fca  3d0000807f             +cmp eax, 0x7f800000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2139095040 /*0x7f800000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00526fcf  7433                   -je 0x527004
    if (cpu.flags.zf)
    {
        goto L_0x00527004;
    }
    // 00526fd1  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00526fd3  2500380000             +and eax, 0x3800
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(14336 /*0x3800*/))));
    // 00526fd8  740d                   -je 0x526fe7
    if (cpu.flags.zf)
    {
        goto L_0x00526fe7;
    }
    // 00526fda  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 00526fde  e8a4ffffff             -call 0x526f87
    cpu.esp -= 4;
    sub_526f87(app, cpu);
    if (cpu.terminate) return;
    // 00526fe3  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00526fe4  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00526fe7:
    // 00526fe7  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00526fe9  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00526fec  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00526fef  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 00526ff3  e88fffffff             -call 0x526f87
    cpu.esp -= 4;
    sub_526f87(app, cpu);
    if (cpu.terminate) return;
    // 00526ff8  db2c24                 -fld xword ptr [esp]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.esp)));
    // 00526ffb  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00526ffd  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00527000  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00527001  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00527004:
    // 00527004  d8742408               -fdiv dword ptr [esp + 8]
    cpu.fpu.st(0) /= x86::Float(*app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */));
    // 00527008  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00527009  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_52700c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052700c  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0052700d  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00527011  250000f07f             -and eax, 0x7ff00000
    cpu.eax &= x86::reg32(x86::sreg32(2146435072 /*0x7ff00000*/));
    // 00527016  3d0000f07f             +cmp eax, 0x7ff00000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2146435072 /*0x7ff00000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052701b  7433                   -je 0x527050
    if (cpu.flags.zf)
    {
        goto L_0x00527050;
    }
    // 0052701d  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0052701f  2500380000             +and eax, 0x3800
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(14336 /*0x3800*/))));
    // 00527024  740d                   -je 0x527033
    if (cpu.flags.zf)
    {
        goto L_0x00527033;
    }
    // 00527026  dd442408               -fld qword ptr [esp + 8]
    cpu.fpu.push(x86::Float(*app->getMemory<double>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 0052702a  e858ffffff             -call 0x526f87
    cpu.esp -= 4;
    sub_526f87(app, cpu);
    if (cpu.terminate) return;
    // 0052702f  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00527030  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00527033:
    // 00527033  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00527035  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00527038  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052703b  dd442414               -fld qword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(*app->getMemory<double>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 0052703f  e843ffffff             -call 0x526f87
    cpu.esp -= 4;
    sub_526f87(app, cpu);
    if (cpu.terminate) return;
    // 00527044  db2c24                 -fld xword ptr [esp]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.esp)));
    // 00527047  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00527049  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0052704c  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052704d  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00527050:
    // 00527050  dc742408               -fdiv qword ptr [esp + 8]
    cpu.fpu.st(0) /= x86::Float(*app->getMemory<double>(cpu.esp + x86::reg32(8) /* 0x8 */));
    // 00527054  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00527055  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_527058(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00527058  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00527059  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052705d  250000807f             -and eax, 0x7f800000
    cpu.eax &= x86::reg32(x86::sreg32(2139095040 /*0x7f800000*/));
    // 00527062  3d0000807f             +cmp eax, 0x7f800000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2139095040 /*0x7f800000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00527067  7433                   -je 0x52709c
    if (cpu.flags.zf)
    {
        goto L_0x0052709c;
    }
    // 00527069  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0052706b  2500380000             +and eax, 0x3800
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(14336 /*0x3800*/))));
    // 00527070  740d                   -je 0x52707f
    if (cpu.flags.zf)
    {
        goto L_0x0052707f;
    }
    // 00527072  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 00527076  e81fffffff             -call 0x526f9a
    cpu.esp -= 4;
    sub_526f9a(app, cpu);
    if (cpu.terminate) return;
    // 0052707b  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052707c  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0052707f:
    // 0052707f  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00527081  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00527084  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00527087  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 0052708b  e80affffff             -call 0x526f9a
    cpu.esp -= 4;
    sub_526f9a(app, cpu);
    if (cpu.terminate) return;
    // 00527090  db2c24                 -fld xword ptr [esp]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.esp)));
    // 00527093  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00527095  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00527098  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00527099  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0052709c:
    // 0052709c  d87c2408               -fdivr dword ptr [esp + 8]
    cpu.fpu.st(0) = x86::Float(*app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)) / cpu.fpu.st(0);
    // 005270a0  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005270a1  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_5270a4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005270a4  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005270a5  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 005270a9  250000f07f             -and eax, 0x7ff00000
    cpu.eax &= x86::reg32(x86::sreg32(2146435072 /*0x7ff00000*/));
    // 005270ae  3d0000f07f             +cmp eax, 0x7ff00000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2146435072 /*0x7ff00000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005270b3  7433                   -je 0x5270e8
    if (cpu.flags.zf)
    {
        goto L_0x005270e8;
    }
    // 005270b5  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 005270b7  2500380000             +and eax, 0x3800
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(14336 /*0x3800*/))));
    // 005270bc  740d                   -je 0x5270cb
    if (cpu.flags.zf)
    {
        goto L_0x005270cb;
    }
    // 005270be  dd442408               -fld qword ptr [esp + 8]
    cpu.fpu.push(x86::Float(*app->getMemory<double>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 005270c2  e8d3feffff             -call 0x526f9a
    cpu.esp -= 4;
    sub_526f9a(app, cpu);
    if (cpu.terminate) return;
    // 005270c7  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005270c8  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x005270cb:
    // 005270cb  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 005270cd  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 005270d0  db3c24                 -fstp xword ptr [esp]
    *app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 005270d3  dd442414               -fld qword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(*app->getMemory<double>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 005270d7  e8befeffff             -call 0x526f9a
    cpu.esp -= 4;
    sub_526f9a(app, cpu);
    if (cpu.terminate) return;
    // 005270dc  db2c24                 -fld xword ptr [esp]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.esp)));
    // 005270df  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 005270e1  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 005270e4  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005270e5  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x005270e8:
    // 005270e8  dc7c2408               -fdivr qword ptr [esp + 8]
    cpu.fpu.st(0) = x86::Float(*app->getMemory<double>(cpu.esp + x86::reg32(8) /* 0x8 */)) / cpu.fpu.st(0);
    // 005270ec  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005270ed  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_5270f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005270f0  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005270f1  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 005270f3  60                     -pushal 
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    *app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    *app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    *app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    *app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    *app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    *app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    *app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 005270f4  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005270f5  bbffff0000             -mov ebx, 0xffff
    cpu.ebx = 65535 /*0xffff*/;
    // 005270fa  0f6edb                 -movd mm3, ebx
    cpu.mmx.mm3 = { _mm_cvtsi32_si128(cpu.ebx) };
    // 005270fd  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00527100  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00527103  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00527106  8b451c                 -mov eax, dword ptr [ebp + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 00527109  8b5520                 -mov edx, dword ptr [ebp + 0x20]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 0052710c  8b5d18                 -mov ebx, dword ptr [ebp + 0x18]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 0052710f  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebx);
    // 00527111  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00527114  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.ebp);
    // 00527117  0f6ecb                 -movd mm1, ebx
    cpu.mmx.mm1 = { _mm_cvtsi32_si128(cpu.ebx) };
    // 0052711a  0f6ed3                 -movd mm2, ebx
    cpu.mmx.mm2 = { _mm_cvtsi32_si128(cpu.ebx) };
    // 0052711d  0f72d110               -psrld mm1, 0x10
    cpu.mmx.mm1 = { _mm_srli_epi32(cpu.mmx.mm1, 16 /*0x10*/) };
    // 00527121  0febca                 -por mm1, mm2
    cpu.mmx.mm1 = { _mm_or_si128(cpu.mmx.mm1, cpu.mmx.mm2) };
    // 00527124  0fefcb                 -pxor mm1, mm3
    cpu.mmx.mm1 = { _mm_xor_si128(cpu.mmx.mm1, cpu.mmx.mm3) };
    // 00527127  4a                     -dec edx
    (cpu.edx)--;
    // 00527128  0f6ee2                 -movd mm4, edx
    cpu.mmx.mm4 = { _mm_cvtsi32_si128(cpu.edx) };
    // 0052712b  42                     -inc edx
    (cpu.edx)++;
    // 0052712c  0f6eea                 -movd mm5, edx
    cpu.mmx.mm5 = { _mm_cvtsi32_si128(cpu.edx) };
    // 0052712f  0f72d410               -psrld mm4, 0x10
    cpu.mmx.mm4 = { _mm_srli_epi32(cpu.mmx.mm4, 16 /*0x10*/) };
    // 00527133  0febe5                 -por mm4, mm5
    cpu.mmx.mm4 = { _mm_or_si128(cpu.mmx.mm4, cpu.mmx.mm5) };
    // 00527136  0fefe3                 -pxor mm4, mm3
    cpu.mmx.mm4 = { _mm_xor_si128(cpu.mmx.mm4, cpu.mmx.mm3) };
L_0x00527139:
    // 00527139  0f60443500             -punpcklbw mm0, dword ptr [ebp + esi]
    cpu.mmx.mm0 = { _mm_unpacklo_epi8(cpu.mmx.mm0, x86::from_reg64(*app->getMemory<x86::reg64>(cpu.ebp + cpu.esi * 1))) };
    // 0052713e  0f7fca                 -movq mm2, mm1
    cpu.mmx.mm2 = cpu.mmx.mm1;
    // 00527141  0f71d201               -psrlw mm2, 1
    cpu.mmx.mm2 = { _mm_srli_epi16(cpu.mmx.mm2, 1 /*0x1*/) };
    // 00527145  0ff5c2                 -pmaddwd mm0, mm2
    cpu.mmx.mm0 = { _mm_madd_epi16(cpu.mmx.mm0, cpu.mmx.mm2) };
    // 00527148  0f73d017               -psrlq mm0, 0x17
    cpu.mmx.mm0 = { _mm_srli_epi64(cpu.mmx.mm0, 23 /*0x17*/) };
    // 0052714c  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052714d  0f7ec1                 -movd ecx, mm0
    cpu.ecx = _mm_cvtsi128_si32(cpu.mmx.mm0);
    // 00527150  0ffdcc                 -paddw mm1, mm4
    cpu.mmx.mm1 = { _mm_add_epi16(cpu.mmx.mm1, cpu.mmx.mm4) };
    // 00527153  880f                   -mov byte ptr [edi], cl
    *app->getMemory<x86::reg8>(cpu.edi) = cpu.cl;
    // 00527155  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00527156  03da                   +add ebx, edx
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00527158  13e8                   -adc ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 0052715a  83c701                 +add edi, 1
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0052715d  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0052715e  7fd9                   -jg 0x527139
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00527139;
    }
    // 00527160  8bcd                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 00527162  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00527163  8b5518                 -mov edx, dword ptr [ebp + 0x18]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00527166  891a                   -mov dword ptr [edx], ebx
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 00527168  8b5514                 -mov edx, dword ptr [ebp + 0x14]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0052716b  890a                   -mov dword ptr [edx], ecx
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 0052716d  61                     -popal 
    {
        cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
        cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + 4);
        cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp + 8);
        // skip esp
        cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + 16);
        cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + 20);
        cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + 24);
        cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + 28);
        cpu.esp += 32;
    }
    // 0052716e  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052716f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_527170(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00527170  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00527171  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00527173  60                     -pushal 
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    *app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    *app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    *app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    *app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    *app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    *app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    *app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 00527174  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00527175  bbffff0000             -mov ebx, 0xffff
    cpu.ebx = 65535 /*0xffff*/;
    // 0052717a  0f6ee3                 -movd mm4, ebx
    cpu.mmx.mm4 = { _mm_cvtsi32_si128(cpu.ebx) };
    // 0052717d  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00527180  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00527183  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00527186  8b451c                 -mov eax, dword ptr [ebp + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 00527189  8b5520                 -mov edx, dword ptr [ebp + 0x20]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 0052718c  8b5d18                 -mov ebx, dword ptr [ebp + 0x18]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 0052718f  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebx);
    // 00527191  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00527194  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.ebp);
    // 00527197  0f6ed3                 -movd mm2, ebx
    cpu.mmx.mm2 = { _mm_cvtsi32_si128(cpu.ebx) };
    // 0052719a  0f6edb                 -movd mm3, ebx
    cpu.mmx.mm3 = { _mm_cvtsi32_si128(cpu.ebx) };
    // 0052719d  0f72d210               -psrld mm2, 0x10
    cpu.mmx.mm2 = { _mm_srli_epi32(cpu.mmx.mm2, 16 /*0x10*/) };
    // 005271a1  0febd3                 -por mm2, mm3
    cpu.mmx.mm2 = { _mm_or_si128(cpu.mmx.mm2, cpu.mmx.mm3) };
    // 005271a4  0fefd4                 -pxor mm2, mm4
    cpu.mmx.mm2 = { _mm_xor_si128(cpu.mmx.mm2, cpu.mmx.mm4) };
    // 005271a7  0f7fd5                 -movq mm5, mm2
    cpu.mmx.mm5 = cpu.mmx.mm2;
    // 005271aa  0f73f220               -psllq mm2, 0x20
    cpu.mmx.mm2 = { _mm_slli_epi64(cpu.mmx.mm2, 32 /*0x20*/) };
    // 005271ae  0febd5                 -por mm2, mm5
    cpu.mmx.mm2 = { _mm_or_si128(cpu.mmx.mm2, cpu.mmx.mm5) };
    // 005271b1  4a                     -dec edx
    (cpu.edx)--;
    // 005271b2  0f6eea                 -movd mm5, edx
    cpu.mmx.mm5 = { _mm_cvtsi32_si128(cpu.edx) };
    // 005271b5  42                     -inc edx
    (cpu.edx)++;
    // 005271b6  0f6ef2                 -movd mm6, edx
    cpu.mmx.mm6 = { _mm_cvtsi32_si128(cpu.edx) };
    // 005271b9  0f72d510               -psrld mm5, 0x10
    cpu.mmx.mm5 = { _mm_srli_epi32(cpu.mmx.mm5, 16 /*0x10*/) };
    // 005271bd  0febee                 -por mm5, mm6
    cpu.mmx.mm5 = { _mm_or_si128(cpu.mmx.mm5, cpu.mmx.mm6) };
    // 005271c0  0fefec                 -pxor mm5, mm4
    cpu.mmx.mm5 = { _mm_xor_si128(cpu.mmx.mm5, cpu.mmx.mm4) };
    // 005271c3  0f7fec                 -movq mm4, mm5
    cpu.mmx.mm4 = cpu.mmx.mm5;
    // 005271c6  0f73f520               -psllq mm5, 0x20
    cpu.mmx.mm5 = { _mm_slli_epi64(cpu.mmx.mm5, 32 /*0x20*/) };
    // 005271ca  0febec                 -por mm5, mm4
    cpu.mmx.mm5 = { _mm_or_si128(cpu.mmx.mm5, cpu.mmx.mm4) };
L_0x005271cd:
    // 005271cd  0f6e0c6e               -movd mm1, dword ptr [esi + ebp*2]
    cpu.mmx.mm1 = { _mm_loadu_si32(&*app->getMemory<x86::reg32>(cpu.esi + cpu.ebp * 2)) };
    // 005271d1  0f7fd3                 -movq mm3, mm2
    cpu.mmx.mm3 = cpu.mmx.mm2;
    // 005271d4  0f71d301               -psrlw mm3, 1
    cpu.mmx.mm3 = { _mm_srli_epi16(cpu.mmx.mm3, 1 /*0x1*/) };
    // 005271d8  0f604c6e02             -punpcklbw mm1, dword ptr [esi + ebp*2 + 2]
    cpu.mmx.mm1 = { _mm_unpacklo_epi8(cpu.mmx.mm1, x86::from_reg64(*app->getMemory<x86::reg64>(cpu.esi + x86::reg32(2) /* 0x2 */ + cpu.ebp * 2))) };
    // 005271dd  0f60c1                 -punpcklbw mm0, mm1
    cpu.mmx.mm0 = { _mm_unpacklo_epi8(cpu.mmx.mm0, cpu.mmx.mm1) };
    // 005271e0  0ff5c3                 -pmaddwd mm0, mm3
    cpu.mmx.mm0 = { _mm_madd_epi16(cpu.mmx.mm0, cpu.mmx.mm3) };
    // 005271e3  0f72e017               -psrad mm0, 0x17
    cpu.mmx.mm0 = { _mm_srai_epi32(cpu.mmx.mm0, 23 /*0x17*/) };
    // 005271e7  0ffdd5                 -paddw mm2, mm5
    cpu.mmx.mm2 = { _mm_add_epi16(cpu.mmx.mm2, cpu.mmx.mm5) };
    // 005271ea  0f6bc1                 -packssdw mm0, mm1
    { __m128i _packed = _mm_packs_epi32(cpu.mmx.mm0, cpu.mmx.mm1); cpu.mmx.mm0 = {_mm_unpacklo_epi32(_packed, _mm_srli_si128(_packed, 8))}; }
    // 005271ed  0f63c1                 -packsswb mm0, mm1
    { __m128i _packed = _mm_packs_epi16(cpu.mmx.mm0, cpu.mmx.mm1); cpu.mmx.mm0 = {_mm_unpacklo_epi32(_packed, _mm_srli_si128(_packed, 8))}; }
    // 005271f0  03da                   +add ebx, edx
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 005271f2  0f7e07                 -movd dword ptr [edi], mm0
    _mm_storeu_si32(&*app->getMemory<x86::reg32>(cpu.edi), cpu.mmx.mm0);
    // 005271f5  13e8                   -adc ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 005271f7  83c702                 +add edi, 2
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 005271fa  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 005271fb  7fd0                   -jg 0x5271cd
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x005271cd;
    }
    // 005271fd  8bcd                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 005271ff  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00527200  8b5518                 -mov edx, dword ptr [ebp + 0x18]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00527203  891a                   -mov dword ptr [edx], ebx
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 00527205  8b5514                 -mov edx, dword ptr [ebp + 0x14]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00527208  890a                   -mov dword ptr [edx], ecx
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 0052720a  61                     -popal 
    {
        cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
        cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + 4);
        cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp + 8);
        // skip esp
        cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + 16);
        cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + 20);
        cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + 24);
        cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + 28);
        cpu.esp += 32;
    }
    // 0052720b  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052720c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_527210(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00527210  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00527211  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00527213  60                     -pushal 
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    *app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    *app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    *app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    *app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    *app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    *app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    *app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 00527214  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00527215  bbffff0000             -mov ebx, 0xffff
    cpu.ebx = 65535 /*0xffff*/;
    // 0052721a  0f6edb                 -movd mm3, ebx
    cpu.mmx.mm3 = { _mm_cvtsi32_si128(cpu.ebx) };
    // 0052721d  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00527220  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00527223  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00527226  8b451c                 -mov eax, dword ptr [ebp + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 00527229  8b5520                 -mov edx, dword ptr [ebp + 0x20]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 0052722c  8b5d18                 -mov ebx, dword ptr [ebp + 0x18]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 0052722f  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebx);
    // 00527231  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00527234  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.ebp);
    // 00527237  0f6ecb                 -movd mm1, ebx
    cpu.mmx.mm1 = { _mm_cvtsi32_si128(cpu.ebx) };
    // 0052723a  0f6ed3                 -movd mm2, ebx
    cpu.mmx.mm2 = { _mm_cvtsi32_si128(cpu.ebx) };
    // 0052723d  0f72d110               -psrld mm1, 0x10
    cpu.mmx.mm1 = { _mm_srli_epi32(cpu.mmx.mm1, 16 /*0x10*/) };
    // 00527241  0febca                 -por mm1, mm2
    cpu.mmx.mm1 = { _mm_or_si128(cpu.mmx.mm1, cpu.mmx.mm2) };
    // 00527244  0fefcb                 -pxor mm1, mm3
    cpu.mmx.mm1 = { _mm_xor_si128(cpu.mmx.mm1, cpu.mmx.mm3) };
    // 00527247  4a                     -dec edx
    (cpu.edx)--;
    // 00527248  0f6ee2                 -movd mm4, edx
    cpu.mmx.mm4 = { _mm_cvtsi32_si128(cpu.edx) };
    // 0052724b  42                     -inc edx
    (cpu.edx)++;
    // 0052724c  0f6eea                 -movd mm5, edx
    cpu.mmx.mm5 = { _mm_cvtsi32_si128(cpu.edx) };
    // 0052724f  0f72d410               -psrld mm4, 0x10
    cpu.mmx.mm4 = { _mm_srli_epi32(cpu.mmx.mm4, 16 /*0x10*/) };
    // 00527253  0febe5                 -por mm4, mm5
    cpu.mmx.mm4 = { _mm_or_si128(cpu.mmx.mm4, cpu.mmx.mm5) };
    // 00527256  0fefe3                 -pxor mm4, mm3
    cpu.mmx.mm4 = { _mm_xor_si128(cpu.mmx.mm4, cpu.mmx.mm3) };
L_0x00527259:
    // 00527259  0f6e046e               -movd mm0, dword ptr [esi + ebp*2]
    cpu.mmx.mm0 = { _mm_loadu_si32(&*app->getMemory<x86::reg32>(cpu.esi + cpu.ebp * 2)) };
    // 0052725d  0f7fca                 -movq mm2, mm1
    cpu.mmx.mm2 = cpu.mmx.mm1;
    // 00527260  0f71d201               -psrlw mm2, 1
    cpu.mmx.mm2 = { _mm_srli_epi16(cpu.mmx.mm2, 1 /*0x1*/) };
    // 00527264  0ff5c2                 -pmaddwd mm0, mm2
    cpu.mmx.mm0 = { _mm_madd_epi16(cpu.mmx.mm0, cpu.mmx.mm2) };
    // 00527267  0f73d00f               -psrlq mm0, 0xf
    cpu.mmx.mm0 = { _mm_srli_epi64(cpu.mmx.mm0, 15 /*0xf*/) };
    // 0052726b  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052726c  0f7ec1                 -movd ecx, mm0
    cpu.ecx = _mm_cvtsi128_si32(cpu.mmx.mm0);
    // 0052726f  0ffdcc                 -paddw mm1, mm4
    cpu.mmx.mm1 = { _mm_add_epi16(cpu.mmx.mm1, cpu.mmx.mm4) };
    // 00527272  66890f                 -mov word ptr [edi], cx
    *app->getMemory<x86::reg16>(cpu.edi) = cpu.cx;
    // 00527275  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00527276  03da                   +add ebx, edx
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00527278  13e8                   -adc ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 0052727a  83c702                 +add edi, 2
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0052727d  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0052727e  7fd9                   -jg 0x527259
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00527259;
    }
    // 00527280  8bcd                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 00527282  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00527283  8b5518                 -mov edx, dword ptr [ebp + 0x18]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00527286  891a                   -mov dword ptr [edx], ebx
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 00527288  8b5514                 -mov edx, dword ptr [ebp + 0x14]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0052728b  890a                   -mov dword ptr [edx], ecx
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 0052728d  61                     -popal 
    {
        cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
        cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + 4);
        cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp + 8);
        // skip esp
        cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + 16);
        cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + 20);
        cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + 24);
        cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + 28);
        cpu.esp += 32;
    }
    // 0052728e  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052728f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_527290(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00527290  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00527291  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00527293  60                     -pushal 
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    *app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    *app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    *app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    *app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    *app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    *app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    *app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 00527294  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00527295  bbffff0000             -mov ebx, 0xffff
    cpu.ebx = 65535 /*0xffff*/;
    // 0052729a  0f6ee3                 -movd mm4, ebx
    cpu.mmx.mm4 = { _mm_cvtsi32_si128(cpu.ebx) };
    // 0052729d  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 005272a0  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 005272a3  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 005272a6  8b451c                 -mov eax, dword ptr [ebp + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 005272a9  8b5520                 -mov edx, dword ptr [ebp + 0x20]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 005272ac  8b5d18                 -mov ebx, dword ptr [ebp + 0x18]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 005272af  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebx);
    // 005272b1  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 005272b4  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.ebp);
    // 005272b7  0f6ed3                 -movd mm2, ebx
    cpu.mmx.mm2 = { _mm_cvtsi32_si128(cpu.ebx) };
    // 005272ba  0f6edb                 -movd mm3, ebx
    cpu.mmx.mm3 = { _mm_cvtsi32_si128(cpu.ebx) };
    // 005272bd  0f72d210               -psrld mm2, 0x10
    cpu.mmx.mm2 = { _mm_srli_epi32(cpu.mmx.mm2, 16 /*0x10*/) };
    // 005272c1  0febd3                 -por mm2, mm3
    cpu.mmx.mm2 = { _mm_or_si128(cpu.mmx.mm2, cpu.mmx.mm3) };
    // 005272c4  0fefd4                 -pxor mm2, mm4
    cpu.mmx.mm2 = { _mm_xor_si128(cpu.mmx.mm2, cpu.mmx.mm4) };
    // 005272c7  0f7fd5                 -movq mm5, mm2
    cpu.mmx.mm5 = cpu.mmx.mm2;
    // 005272ca  0f73f220               -psllq mm2, 0x20
    cpu.mmx.mm2 = { _mm_slli_epi64(cpu.mmx.mm2, 32 /*0x20*/) };
    // 005272ce  0febd5                 -por mm2, mm5
    cpu.mmx.mm2 = { _mm_or_si128(cpu.mmx.mm2, cpu.mmx.mm5) };
    // 005272d1  4a                     -dec edx
    (cpu.edx)--;
    // 005272d2  0f6eea                 -movd mm5, edx
    cpu.mmx.mm5 = { _mm_cvtsi32_si128(cpu.edx) };
    // 005272d5  42                     -inc edx
    (cpu.edx)++;
    // 005272d6  0f6ef2                 -movd mm6, edx
    cpu.mmx.mm6 = { _mm_cvtsi32_si128(cpu.edx) };
    // 005272d9  0f72d510               -psrld mm5, 0x10
    cpu.mmx.mm5 = { _mm_srli_epi32(cpu.mmx.mm5, 16 /*0x10*/) };
    // 005272dd  0febee                 -por mm5, mm6
    cpu.mmx.mm5 = { _mm_or_si128(cpu.mmx.mm5, cpu.mmx.mm6) };
    // 005272e0  0fefec                 -pxor mm5, mm4
    cpu.mmx.mm5 = { _mm_xor_si128(cpu.mmx.mm5, cpu.mmx.mm4) };
    // 005272e3  0f7fec                 -movq mm4, mm5
    cpu.mmx.mm4 = cpu.mmx.mm5;
    // 005272e6  0f73f520               -psllq mm5, 0x20
    cpu.mmx.mm5 = { _mm_slli_epi64(cpu.mmx.mm5, 32 /*0x20*/) };
    // 005272ea  0febec                 -por mm5, mm4
    cpu.mmx.mm5 = { _mm_or_si128(cpu.mmx.mm5, cpu.mmx.mm4) };
L_0x005272ed:
    // 005272ed  0f6e04ae               -movd mm0, dword ptr [esi + ebp*4]
    cpu.mmx.mm0 = { _mm_loadu_si32(&*app->getMemory<x86::reg32>(cpu.esi + cpu.ebp * 4)) };
    // 005272f1  0f6144ae04             -punpcklwd mm0, dword ptr [esi + ebp*4 + 4]
    cpu.mmx.mm0 = { _mm_unpacklo_epi16(cpu.mmx.mm0, x86::from_reg64(*app->getMemory<x86::reg64>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ebp * 4))) };
    // 005272f6  0f7fd3                 -movq mm3, mm2
    cpu.mmx.mm3 = cpu.mmx.mm2;
    // 005272f9  0f71d301               -psrlw mm3, 1
    cpu.mmx.mm3 = { _mm_srli_epi16(cpu.mmx.mm3, 1 /*0x1*/) };
    // 005272fd  0ff5c3                 -pmaddwd mm0, mm3
    cpu.mmx.mm0 = { _mm_madd_epi16(cpu.mmx.mm0, cpu.mmx.mm3) };
    // 00527300  0f72e00f               -psrad mm0, 0xf
    cpu.mmx.mm0 = { _mm_srai_epi32(cpu.mmx.mm0, 15 /*0xf*/) };
    // 00527304  0ffdd5                 -paddw mm2, mm5
    cpu.mmx.mm2 = { _mm_add_epi16(cpu.mmx.mm2, cpu.mmx.mm5) };
    // 00527307  0f6bc1                 -packssdw mm0, mm1
    { __m128i _packed = _mm_packs_epi32(cpu.mmx.mm0, cpu.mmx.mm1); cpu.mmx.mm0 = {_mm_unpacklo_epi32(_packed, _mm_srli_si128(_packed, 8))}; }
    // 0052730a  03da                   +add ebx, edx
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0052730c  0f7e07                 -movd dword ptr [edi], mm0
    _mm_storeu_si32(&*app->getMemory<x86::reg32>(cpu.edi), cpu.mmx.mm0);
    // 0052730f  13e8                   -adc ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 00527311  83c704                 +add edi, 4
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
    // 00527314  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00527315  7fd6                   -jg 0x5272ed
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x005272ed;
    }
    // 00527317  8bcd                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 00527319  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052731a  8b5518                 -mov edx, dword ptr [ebp + 0x18]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 0052731d  891a                   -mov dword ptr [edx], ebx
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 0052731f  8b5514                 -mov edx, dword ptr [ebp + 0x14]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00527322  890a                   -mov dword ptr [edx], ecx
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 00527324  61                     -popal 
    {
        cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
        cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + 4);
        cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp + 8);
        // skip esp
        cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + 16);
        cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + 20);
        cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + 24);
        cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + 28);
        cpu.esp += 32;
    }
    // 00527325  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00527326  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_527330(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00527330  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00527331  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00527333  60                     -pushal 
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    *app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    *app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    *app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    *app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    *app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    *app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    *app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 00527334  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00527335  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00527338  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0052733b  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0052733e  8b451c                 -mov eax, dword ptr [ebp + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 00527341  8b5520                 -mov edx, dword ptr [ebp + 0x20]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 00527344  8b5d18                 -mov ebx, dword ptr [ebp + 0x18]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00527347  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebx);
    // 00527349  891d38b15600           -mov dword ptr [0x56b138], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5681464) /* 0x56b138 */) = cpu.ebx;
    // 0052734f  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00527352  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.ebp);
    // 00527355  eb06                   -jmp 0x52735d
    goto L_0x0052735d;
L_0x00527357:
    // 00527357  d95ff8                 -fstp dword ptr [edi - 8]
    *app->getMemory<float>(cpu.edi + x86::reg32(-8) /* -0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052735a  d95ffc                 -fstp dword ptr [edi - 4]
    *app->getMemory<float>(cpu.edi + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x0052735d:
    // 0052735d  db053ab15600           -fild dword ptr [0x56b13a]
    cpu.fpu.push(x86::Float(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5681466) /* 0x56b13a */))));
    // 00527363  d90530b15600           -fld dword ptr [0x56b130]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(x86::reg32(5681456) /* 0x56b130 */)));
    // 00527369  d904ee                 -fld dword ptr [esi + ebp*8]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.esi + cpu.ebp * 8)));
    // 0052736c  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 0052736e  d80d34b15600           -fmul dword ptr [0x56b134]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(5681460) /* 0x56b134 */));
    // 00527374  d944ee04               -fld dword ptr [esi + ebp*8 + 4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ebp * 8)));
    // 00527378  d944ee08               -fld dword ptr [esi + ebp*8 + 8]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.esi + x86::reg32(8) /* 0x8 */ + cpu.ebp * 8)));
    // 0052737c  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 0052737e  dceb                   -fsub st(3), st(0)
    cpu.fpu.st(3) -= x86::Float(cpu.fpu.st(0));
    // 00527380  dcca                   -fmul st(2), st(0)
    cpu.fpu.st(2) *= cpu.fpu.st(0);
    // 00527382  d944ee0c               -fld dword ptr [esi + ebp*8 + 0xc]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.esi + x86::reg32(12) /* 0xc */ + cpu.ebp * 8)));
    // 00527386  d9cc                   -fxch st(4)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(4);
        cpu.fpu.st(4) = tmp;
    }
    // 00527388  dccd                   -fmul st(5), st(0)
    cpu.fpu.st(5) *= cpu.fpu.st(0);
    // 0052738a  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0052738d  03da                   +add ebx, edx
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0052738f  deca                   +fmulp st(2)
    cpu.fpu.st(2) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00527391  13e8                   -adc ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 00527393  891d38b15600           -mov dword ptr [0x56b138], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5681464) /* 0x56b138 */) = cpu.ebx;
    // 00527399  decb                   -fmulp st(3)
    cpu.fpu.st(3) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052739b  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 0052739d  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052739f  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 005273a1  dec2                   -faddp st(2)
    cpu.fpu.st(2) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 005273a3  83e901                 +sub ecx, 1
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
    // 005273a6  7faf                   -jg 0x527357
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00527357;
    }
    // 005273a8  d95ff8                 -fstp dword ptr [edi - 8]
    *app->getMemory<float>(cpu.edi + x86::reg32(-8) /* -0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 005273ab  d95ffc                 -fstp dword ptr [edi - 4]
    *app->getMemory<float>(cpu.edi + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 005273ae  8bcd                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 005273b0  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005273b1  8b5518                 -mov edx, dword ptr [ebp + 0x18]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 005273b4  891a                   -mov dword ptr [edx], ebx
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 005273b6  8b5514                 -mov edx, dword ptr [ebp + 0x14]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 005273b9  890a                   -mov dword ptr [edx], ecx
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 005273bb  61                     -popal 
    {
        cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
        cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + 4);
        cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp + 8);
        // skip esp
        cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + 16);
        cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + 20);
        cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + 24);
        cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + 28);
        cpu.esp += 32;
    }
    // 005273bc  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005273bd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_5273c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005273c0  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005273c1  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 005273c3  60                     -pushal 
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    *app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    *app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    *app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    *app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    *app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    *app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    *app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 005273c4  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005273c5  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 005273c8  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 005273cb  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 005273ce  8b451c                 -mov eax, dword ptr [ebp + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 005273d1  8b5520                 -mov edx, dword ptr [ebp + 0x20]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 005273d4  8b5d18                 -mov ebx, dword ptr [ebp + 0x18]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 005273d7  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebx);
    // 005273d9  891d48b15600           -mov dword ptr [0x56b148], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5681480) /* 0x56b148 */) = cpu.ebx;
    // 005273df  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 005273e2  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.ebp);
    // 005273e5  83f901                 +cmp ecx, 1
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
    // 005273e8  7e7a                   -jle 0x527464
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00527464;
    }
    // 005273ea  83e901                 -sub ecx, 1
    (cpu.ecx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x005273ed:
    // 005273ed  db054ab15600           -fild dword ptr [0x56b14a]
    cpu.fpu.push(x86::Float(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5681482) /* 0x56b14a */))));
    // 005273f3  d904ae                 -fld dword ptr [esi + ebp*4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.esi + cpu.ebp * 4)));
    // 005273f6  d944ae04               -fld dword ptr [esi + ebp*4 + 4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ebp * 4)));
    // 005273fa  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 005273fd  03da                   +add ebx, edx
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 005273ff  13e8                   -adc ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 00527401  891d48b15600           -mov dword ptr [0x56b148], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5681480) /* 0x56b148 */) = cpu.ebx;
    // 00527407  db054ab15600           -fild dword ptr [0x56b14a]
    cpu.fpu.push(x86::Float(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5681482) /* 0x56b14a */))));
    // 0052740d  d904ae                 -fld dword ptr [esi + ebp*4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.esi + cpu.ebp * 4)));
    // 00527410  d944ae04               -fld dword ptr [esi + ebp*4 + 4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ebp * 4)));
    // 00527414  d9cd                   -fxch st(5)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(5);
        cpu.fpu.st(5) = tmp;
    }
    // 00527416  d80d44b15600           -fmul dword ptr [0x56b144]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(5681476) /* 0x56b144 */));
    // 0052741c  d90540b15600           -fld dword ptr [0x56b140]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(x86::reg32(5681472) /* 0x56b140 */)));
    // 00527422  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 00527424  d80d44b15600           -fmul dword ptr [0x56b144]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(5681476) /* 0x56b144 */));
    // 0052742a  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0052742c  dceb                   -fsub st(3), st(0)
    cpu.fpu.st(3) -= x86::Float(cpu.fpu.st(0));
    // 0052742e  d90540b15600           -fld dword ptr [0x56b140]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(x86::reg32(5681472) /* 0x56b140 */)));
    // 00527434  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 00527436  dcea                   -fsub st(2), st(0)
    cpu.fpu.st(2) -= x86::Float(cpu.fpu.st(0));
    // 00527438  d9cc                   -fxch st(4)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(4);
        cpu.fpu.st(4) = tmp;
    }
    // 0052743a  dece                   -fmulp st(6)
    cpu.fpu.st(6) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052743c  03da                   +add ebx, edx
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0052743e  decc                   +fmulp st(4)
    cpu.fpu.st(4) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00527440  dec9                   +fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00527442  d9c9                   +fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00527444  decc                   +fmulp st(4)
    cpu.fpu.st(4) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00527446  d9ca                   +fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 00527448  dec1                   +faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052744a  d9c9                   +fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0052744c  dec2                   +faddp st(2)
    cpu.fpu.st(2) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052744e  13e8                   -adc ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 00527450  891d48b15600           -mov dword ptr [0x56b148], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5681480) /* 0x56b148 */) = cpu.ebx;
    // 00527456  d95ff8                 -fstp dword ptr [edi - 8]
    *app->getMemory<float>(cpu.edi + x86::reg32(-8) /* -0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00527459  d95ffc                 -fstp dword ptr [edi - 4]
    *app->getMemory<float>(cpu.edi + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052745c  83e902                 +sub ecx, 2
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0052745f  7f8c                   -jg 0x5273ed
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x005273ed;
    }
    // 00527461  83c101                 -add ecx, 1
    (cpu.ecx) += x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x00527464:
    // 00527464  83f900                 +cmp ecx, 0
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00527467  7e36                   -jle 0x52749f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052749f;
    }
    // 00527469  db054ab15600           -fild dword ptr [0x56b14a]
    cpu.fpu.push(x86::Float(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5681482) /* 0x56b14a */))));
    // 0052746f  d90540b15600           -fld dword ptr [0x56b140]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(x86::reg32(5681472) /* 0x56b140 */)));
    // 00527475  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00527477  d80d44b15600           -fmul dword ptr [0x56b144]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(5681476) /* 0x56b144 */));
    // 0052747d  dce9                   -fsub st(1), st(0)
    cpu.fpu.st(1) -= x86::Float(cpu.fpu.st(0));
    // 0052747f  d84cae04               -fmul dword ptr [esi + ebp*4 + 4]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ebp * 4));
    // 00527483  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00527485  d80cae                 -fmul dword ptr [esi + ebp*4]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.esi + cpu.ebp * 4));
    // 00527488  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052748a  03da                   +add ebx, edx
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0052748c  13e8                   -adc ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 0052748e  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00527491  891d48b15600           -mov dword ptr [0x56b148], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5681480) /* 0x56b148 */) = cpu.ebx;
    // 00527497  d95ffc                 -fstp dword ptr [edi - 4]
    *app->getMemory<float>(cpu.edi + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052749a  83e901                 +sub ecx, 1
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
    // 0052749d  7fc5                   -jg 0x527464
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00527464;
    }
L_0x0052749f:
    // 0052749f  8bcd                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 005274a1  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005274a2  8b5518                 -mov edx, dword ptr [ebp + 0x18]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 005274a5  891a                   -mov dword ptr [edx], ebx
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 005274a7  8b5514                 -mov edx, dword ptr [ebp + 0x14]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 005274aa  890a                   -mov dword ptr [edx], ecx
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 005274ac  61                     -popal 
    {
        cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
        cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + 4);
        cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp + 8);
        // skip esp
        cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + 16);
        cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + 20);
        cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + 24);
        cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + 28);
        cpu.esp += 32;
    }
    // 005274ad  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005274ae  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_5274b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005274b0  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005274b1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 005274b3  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 005274b5  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 005274b7  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 005274bb  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005274bc  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 005274c0  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005274c1  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 005274c6  e8d5540000             -call 0x52c9a0
    cpu.esp -= 4;
    sub_52c9a0(app, cpu);
    if (cpu.terminate) return;
    // 005274cb  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005274cc  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 */
void Application::sub_5274d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005274d0  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005274d1  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 005274d5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 005274d7  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 005274d9  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 005274dd  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 005274e1  c70600000000           -mov dword ptr [esi], 0
    *app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 005274e7  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 005274eb  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005274ec  6a01                   -push 1
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 005274ee  e855550000             -call 0x52ca48
    cpu.esp -= 4;
    sub_52ca48(app, cpu);
    if (cpu.terminate) return;
    // 005274f3  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005274f4  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_527500(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00527500  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00527504  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00527506  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0052750a  c70200000000           -mov dword ptr [edx], 0
    *app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 00527510  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00527515  e85a560000             -call 0x52cb74
    cpu.esp -= 4;
    sub_52cb74(app, cpu);
    if (cpu.terminate) return;
    // 0052751a  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_527520(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00527520  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00527524  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00527528  c70300000000           -mov dword ptr [ebx], 0
    *app->getMemory<x86::reg32>(cpu.ebx) = 0 /*0x0*/;
    // 0052752e  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00527533  e880570000             -call 0x52ccb8
    cpu.esp -= 4;
    sub_52ccb8(app, cpu);
    if (cpu.terminate) return;
    // 00527538  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_527540(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00527540  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00527541  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00527543  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00527545  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00527547  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0052754b  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052754c  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00527550  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00527551  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 00527556  e845540000             -call 0x52c9a0
    cpu.esp -= 4;
    sub_52c9a0(app, cpu);
    if (cpu.terminate) return;
    // 0052755b  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052755c  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 */
void Application::sub_527560(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00527560  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00527561  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00527565  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00527567  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00527569  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052756d  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00527571  c70600000000           -mov dword ptr [esi], 0
    *app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 00527577  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0052757b  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052757c  6a02                   -push 2
    *app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0052757e  e8c5540000             -call 0x52ca48
    cpu.esp -= 4;
    sub_52ca48(app, cpu);
    if (cpu.terminate) return;
    // 00527583  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00527584  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_527590(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00527590  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00527594  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00527596  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0052759a  c70200000000           -mov dword ptr [edx], 0
    *app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 005275a0  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 005275a5  e8ca550000             -call 0x52cb74
    cpu.esp -= 4;
    sub_52cb74(app, cpu);
    if (cpu.terminate) return;
    // 005275aa  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_5275b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005275b0  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 005275b4  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 005275b8  c70300000000           -mov dword ptr [ebx], 0
    *app->getMemory<x86::reg32>(cpu.ebx) = 0 /*0x0*/;
    // 005275be  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 005275c3  e8f0560000             -call 0x52ccb8
    cpu.esp -= 4;
    sub_52ccb8(app, cpu);
    if (cpu.terminate) return;
    // 005275c8  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_5275d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005275d0  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005275d1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 005275d3  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 005275d5  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 005275d7  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 005275db  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005275dc  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 005275e0  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005275e1  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 005275e3  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 005275e5  e8ea570000             -call 0x52cdd4
    cpu.esp -= 4;
    sub_52cdd4(app, cpu);
    if (cpu.terminate) return;
    // 005275ea  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005275eb  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_5275f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005275f0  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005275f1  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 005275f5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 005275f7  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 005275f9  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 005275fd  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00527601  c70600000000           -mov dword ptr [esi], 0
    *app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 00527607  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0052760b  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052760c  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0052760e  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00527610  e89b580000             -call 0x52ceb0
    cpu.esp -= 4;
    sub_52ceb0(app, cpu);
    if (cpu.terminate) return;
    // 00527615  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00527616  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_527620(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00527620  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00527624  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00527626  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0052762a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0052762c  c70200000000           -mov dword ptr [edx], 0
    *app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 00527632  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00527634  e89f590000             -call 0x52cfd8
    cpu.esp -= 4;
    sub_52cfd8(app, cpu);
    if (cpu.terminate) return;
    // 00527639  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_527640(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00527640  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00527644  c70100000000           -mov dword ptr [ecx], 0
    *app->getMemory<x86::reg32>(cpu.ecx) = 0 /*0x0*/;
    // 0052764a  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0052764e  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052764f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00527651  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00527653  e8b85a0000             -call 0x52d110
    cpu.esp -= 4;
    sub_52d110(app, cpu);
    if (cpu.terminate) return;
    // 00527658  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_527660(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00527660  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00527661  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00527663  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00527665  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00527667  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0052766b  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052766c  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00527670  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00527671  6a01                   -push 1
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00527673  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00527675  e85a570000             -call 0x52cdd4
    cpu.esp -= 4;
    sub_52cdd4(app, cpu);
    if (cpu.terminate) return;
    // 0052767a  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052767b  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_527680(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00527680  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00527681  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00527685  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00527687  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00527689  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052768d  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00527691  c70600000000           -mov dword ptr [esi], 0
    *app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 00527697  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0052769b  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052769c  6a01                   -push 1
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0052769e  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 005276a0  e80b580000             -call 0x52ceb0
    cpu.esp -= 4;
    sub_52ceb0(app, cpu);
    if (cpu.terminate) return;
    // 005276a5  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005276a6  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_5276b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005276b0  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 005276b4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 005276b6  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 005276ba  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 005276bf  c70200000000           -mov dword ptr [edx], 0
    *app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 005276c5  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 005276c7  e80c590000             -call 0x52cfd8
    cpu.esp -= 4;
    sub_52cfd8(app, cpu);
    if (cpu.terminate) return;
    // 005276cc  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 */
void Application::sub_5276d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005276d0  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 005276d4  c70100000000           -mov dword ptr [ecx], 0
    *app->getMemory<x86::reg32>(cpu.ecx) = 0 /*0x0*/;
    // 005276da  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 005276de  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005276df  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 005276e1  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 005276e6  e8255a0000             -call 0x52d110
    cpu.esp -= 4;
    sub_52d110(app, cpu);
    if (cpu.terminate) return;
    // 005276eb  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_5276f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005276f0  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005276f1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 005276f3  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 005276f5  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 005276f7  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 005276fb  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005276fc  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00527700  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00527701  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 00527706  e895520000             -call 0x52c9a0
    cpu.esp -= 4;
    sub_52c9a0(app, cpu);
    if (cpu.terminate) return;
    // 0052770b  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052770c  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 */
void Application::sub_527710(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00527710  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00527711  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00527715  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00527717  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00527719  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052771d  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00527721  c70600000000           -mov dword ptr [esi], 0
    *app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 00527727  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0052772b  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052772c  6a02                   -push 2
    *app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0052772e  e815530000             -call 0x52ca48
    cpu.esp -= 4;
    sub_52ca48(app, cpu);
    if (cpu.terminate) return;
    // 00527733  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00527734  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_527740(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00527740  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00527744  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00527746  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0052774a  c70200000000           -mov dword ptr [edx], 0
    *app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 00527750  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00527755  e81a540000             -call 0x52cb74
    cpu.esp -= 4;
    sub_52cb74(app, cpu);
    if (cpu.terminate) return;
    // 0052775a  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_527760(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00527760  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00527764  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00527768  c70300000000           -mov dword ptr [ebx], 0
    *app->getMemory<x86::reg32>(cpu.ebx) = 0 /*0x0*/;
    // 0052776e  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 00527773  e840550000             -call 0x52ccb8
    cpu.esp -= 4;
    sub_52ccb8(app, cpu);
    if (cpu.terminate) return;
    // 00527778  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_527780(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00527780  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00527781  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00527783  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00527785  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00527787  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0052778b  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052778c  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00527790  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00527791  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 00527796  e805520000             -call 0x52c9a0
    cpu.esp -= 4;
    sub_52c9a0(app, cpu);
    if (cpu.terminate) return;
    // 0052779b  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052779c  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 */
void Application::sub_5277a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005277a0  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005277a1  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 005277a5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 005277a7  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 005277a9  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 005277ad  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 005277b1  c70600000000           -mov dword ptr [esi], 0
    *app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 005277b7  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 005277bb  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005277bc  6a04                   -push 4
    *app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 005277be  e885520000             -call 0x52ca48
    cpu.esp -= 4;
    sub_52ca48(app, cpu);
    if (cpu.terminate) return;
    // 005277c3  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005277c4  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_5277d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005277d0  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 005277d4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 005277d6  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 005277da  c70200000000           -mov dword ptr [edx], 0
    *app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 005277e0  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 005277e5  e88a530000             -call 0x52cb74
    cpu.esp -= 4;
    sub_52cb74(app, cpu);
    if (cpu.terminate) return;
    // 005277ea  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_5277f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005277f0  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 005277f4  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 005277f8  c70300000000           -mov dword ptr [ebx], 0
    *app->getMemory<x86::reg32>(cpu.ebx) = 0 /*0x0*/;
    // 005277fe  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 00527803  e8b0540000             -call 0x52ccb8
    cpu.esp -= 4;
    sub_52ccb8(app, cpu);
    if (cpu.terminate) return;
    // 00527808  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_527810(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00527810  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00527811  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00527813  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00527815  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00527817  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0052781b  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052781c  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00527820  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00527821  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00527823  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00527828  e8a7550000             -call 0x52cdd4
    cpu.esp -= 4;
    sub_52cdd4(app, cpu);
    if (cpu.terminate) return;
    // 0052782d  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052782e  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_527840(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00527840  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00527841  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00527845  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00527847  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00527849  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052784d  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00527851  c70600000000           -mov dword ptr [esi], 0
    *app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 00527857  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0052785b  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052785c  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0052785e  6a01                   -push 1
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00527860  e84b560000             -call 0x52ceb0
    cpu.esp -= 4;
    sub_52ceb0(app, cpu);
    if (cpu.terminate) return;
    // 00527865  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00527866  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_527870(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00527870  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00527874  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00527876  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0052787a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0052787c  c70200000000           -mov dword ptr [edx], 0
    *app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 00527882  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00527887  e84c570000             -call 0x52cfd8
    cpu.esp -= 4;
    sub_52cfd8(app, cpu);
    if (cpu.terminate) return;
    // 0052788c  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 */
void Application::sub_527890(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00527890  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00527894  c70100000000           -mov dword ptr [ecx], 0
    *app->getMemory<x86::reg32>(cpu.ecx) = 0 /*0x0*/;
    // 0052789a  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0052789e  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052789f  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 005278a4  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 005278a6  e865580000             -call 0x52d110
    cpu.esp -= 4;
    sub_52d110(app, cpu);
    if (cpu.terminate) return;
    // 005278ab  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_5278b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005278b0  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005278b1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 005278b3  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 005278b5  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 005278b7  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 005278bb  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005278bc  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 005278c0  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005278c1  6a01                   -push 1
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 005278c3  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 005278c8  e807550000             -call 0x52cdd4
    cpu.esp -= 4;
    sub_52cdd4(app, cpu);
    if (cpu.terminate) return;
    // 005278cd  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005278ce  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_5278e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005278e0  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005278e1  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 005278e5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 005278e7  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 005278e9  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 005278ed  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 005278f1  c70600000000           -mov dword ptr [esi], 0
    *app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 005278f7  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 005278fb  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005278fc  6a01                   -push 1
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 005278fe  6a01                   -push 1
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00527900  e8ab550000             -call 0x52ceb0
    cpu.esp -= 4;
    sub_52ceb0(app, cpu);
    if (cpu.terminate) return;
    // 00527905  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00527906  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_527910(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00527910  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00527914  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00527916  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0052791a  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0052791f  c70200000000           -mov dword ptr [edx], 0
    *app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 00527925  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00527927  e8ac560000             -call 0x52cfd8
    cpu.esp -= 4;
    sub_52cfd8(app, cpu);
    if (cpu.terminate) return;
    // 0052792c  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 */
void Application::sub_527930(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00527930  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00527934  c70100000000           -mov dword ptr [ecx], 0
    *app->getMemory<x86::reg32>(cpu.ecx) = 0 /*0x0*/;
    // 0052793a  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0052793e  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052793f  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00527944  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00527946  e8c5570000             -call 0x52d110
    cpu.esp -= 4;
    sub_52d110(app, cpu);
    if (cpu.terminate) return;
    // 0052794b  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_527950(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00527950  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00527953  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_527954(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00527954  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00527955  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00527956  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00527957  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00527958  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0052795a  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0052795c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052795e  8b511c                 -mov edx, dword ptr [ecx + 0x1c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 00527961  8b7918                 -mov edi, dword ptr [ecx + 0x18]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 00527964  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00527966  39fa                   +cmp edx, edi
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
    // 00527968  7d67                   -jge 0x5279d1
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x005279d1;
    }
    // 0052796a  8b6920                 -mov ebp, dword ptr [ecx + 0x20]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 0052796d  894110                 -mov dword ptr [ecx + 0x10], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00527970  39ee                   +cmp esi, ebp
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
    // 00527972  7f67                   -jg 0x5279db
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x005279db;
    }
    // 00527974  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00527976  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00527978  7e1e                   -jle 0x527998
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00527998;
    }
    // 0052797a  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
L_0x0052797c:
    // 0052797c  8b4b10                 -mov ecx, dword ptr [ebx + 0x10]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 0052797f  8b7a24                 -mov edi, dword ptr [edx + 0x24]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */);
    // 00527982  8939                   -mov dword ptr [ecx], edi
    *app->getMemory<x86::reg32>(cpu.ecx) = cpu.edi;
    // 00527984  8b4b10                 -mov ecx, dword ptr [ebx + 0x10]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 00527987  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052798a  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052798d  40                     -inc eax
    (cpu.eax)++;
    // 0052798e  894b10                 -mov dword ptr [ebx + 0x10], ecx
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00527991  39f0                   +cmp eax, esi
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
    // 00527993  7ce7                   -jl 0x52797c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052797c;
    }
    // 00527995  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x00527998:
    // 00527998  8b7320                 -mov esi, dword ptr [ebx + 0x20]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */);
    // 0052799b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0052799d  39f0                   +cmp eax, esi
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
    // 0052799f  7d23                   -jge 0x5279c4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x005279c4;
    }
    // 005279a1  8d348500000000         -lea esi, [eax*4]
    cpu.esi = x86::reg32(cpu.eax * 4);
    // 005279a8  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 005279aa  01de                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
L_0x005279ac:
    // 005279ac  d94624                 -fld dword ptr [esi + 0x24]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.esi + x86::reg32(36) /* 0x24 */)));
    // 005279af  41                     -inc ecx
    (cpu.ecx)++;
    // 005279b0  40                     -inc eax
    (cpu.eax)++;
    // 005279b1  d95a24                 -fstp dword ptr [edx + 0x24]
    *app->getMemory<float>(cpu.edx + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 005279b4  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005279b7  8b7b20                 -mov edi, dword ptr [ebx + 0x20]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */);
    // 005279ba  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005279bd  39f8                   +cmp eax, edi
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
    // 005279bf  7ceb                   -jl 0x5279ac
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005279ac;
    }
    // 005279c1  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x005279c4:
    // 005279c4  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 005279c9  894b20                 -mov dword ptr [ebx + 0x20], ecx
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 005279cc  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005279cd  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005279ce  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005279cf  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005279d0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005279d1:
    // 005279d1  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 005279d6  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005279d7  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005279d8  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005279d9  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005279da  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005279db:
    // 005279db  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 005279dd  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 005279df  7e1f                   -jle 0x527a00
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00527a00;
    }
    // 005279e1  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x005279e3:
    // 005279e3  8b4b10                 -mov ecx, dword ptr [ebx + 0x10]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 005279e6  d94024                 -fld dword ptr [eax + 0x24]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */)));
    // 005279e9  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005279ec  d919                   -fstp dword ptr [ecx]
    *app->getMemory<float>(cpu.ecx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 005279ee  8b4b10                 -mov ecx, dword ptr [ebx + 0x10]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 005279f1  42                     -inc edx
    (cpu.edx)++;
    // 005279f2  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005279f5  8b7b20                 -mov edi, dword ptr [ebx + 0x20]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */);
    // 005279f8  894b10                 -mov dword ptr [ebx + 0x10], ecx
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 005279fb  39fa                   +cmp edx, edi
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
    // 005279fd  7ce4                   -jl 0x5279e3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005279e3;
    }
    // 005279ff  90                     -nop 
    ;
L_0x00527a00:
    // 00527a00  8b7b18                 -mov edi, dword ptr [ebx + 0x18]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 00527a03  8b431c                 -mov eax, dword ptr [ebx + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */);
    // 00527a06  8b6b20                 -mov ebp, dword ptr [ebx + 0x20]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */);
    // 00527a09  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00527a0b  29ee                   -sub esi, ebp
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00527a0d  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00527a0f  0f8c81000000           -jl 0x527a96
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00527a96;
    }
L_0x00527a15:
    // 00527a15  39fe                   +cmp esi, edi
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
    // 00527a17  0f8d80000000           -jge 0x527a9d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00527a9d;
    }
    // 00527a1d  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
L_0x00527a1f:
    // 00527a1f  8b531c                 -mov edx, dword ptr [ebx + 0x1c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */);
    // 00527a22  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00527a29  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00527a2b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00527a2d  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00527a30  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00527a32  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00527a34  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 00527a39  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00527a3c  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00527a3e  8b5314                 -mov edx, dword ptr [ebx + 0x14]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 00527a41  892b                   -mov dword ptr [ebx], ebp
    *app->getMemory<x86::reg32>(cpu.ebx) = cpu.ebp;
    // 00527a43  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00527a45  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00527a46  89530c                 -mov dword ptr [ebx + 0xc], edx
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00527a49  e84291fdff             -call 0x500b90
    cpu.esp -= 4;
    sub_500b90(app, cpu);
    if (cpu.terminate) return;
    // 00527a4e  8b531c                 -mov edx, dword ptr [ebx + 0x1c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */);
    // 00527a51  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00527a53  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx);
    // 00527a55  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00527a57  89531c                 -mov dword ptr [ebx + 0x1c], edx
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 00527a5a  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00527a5c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00527a5f  894b1c                 -mov dword ptr [ebx + 0x1c], ecx
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00527a62  39ef                   +cmp edi, ebp
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
    // 00527a64  753e                   -jne 0x527aa4
    if (!cpu.flags.zf)
    {
        goto L_0x00527aa4;
    }
    // 00527a66  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00527a68  8b7b18                 -mov edi, dword ptr [ebx + 0x18]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 00527a6b  29ee                   -sub esi, ebp
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00527a6d  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00527a6f  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00527a71  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00527a73  7e17                   -jle 0x527a8c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00527a8c;
    }
L_0x00527a75:
    // 00527a75  8b4310                 -mov eax, dword ptr [ebx + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 00527a78  c70000000000           -mov dword ptr [eax], 0
    *app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 00527a7e  8b6b10                 -mov ebp, dword ptr [ebx + 0x10]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 00527a81  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00527a84  4e                     -dec esi
    (cpu.esi)--;
    // 00527a85  896b10                 -mov dword ptr [ebx + 0x10], ebp
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.ebp;
    // 00527a88  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00527a8a  7fe9                   -jg 0x527a75
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00527a75;
    }
L_0x00527a8c:
    // 00527a8c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00527a91  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00527a92  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00527a93  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00527a94  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00527a95  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00527a96:
    // 00527a96  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 00527a98  e978ffffff             -jmp 0x527a15
    goto L_0x00527a15;
L_0x00527a9d:
    // 00527a9d  89fd                   -mov ebp, edi
    cpu.ebp = cpu.edi;
    // 00527a9f  e97bffffff             -jmp 0x527a1f
    goto L_0x00527a1f;
L_0x00527aa4:
    // 00527aa4  8b33                   -mov esi, dword ptr [ebx]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebx);
    // 00527aa6  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00527aa8  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00527aaa  7c0d                   -jl 0x527ab9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00527ab9;
    }
    // 00527aac  894b20                 -mov dword ptr [ebx + 0x20], ecx
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00527aaf  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00527ab4  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00527ab5  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00527ab6  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00527ab7  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00527ab8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00527ab9:
    // 00527ab9  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00527abb  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
L_0x00527ac2:
    // 00527ac2  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00527ac5  46                     -inc esi
    (cpu.esi)++;
    // 00527ac6  8b7b10                 -mov edi, dword ptr [ebx + 0x10]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 00527ac9  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00527acc  41                     -inc ecx
    (cpu.ecx)++;
    // 00527acd  8b6c07fc               -mov ebp, dword ptr [edi + eax - 4]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-4) /* -0x4 */ + cpu.eax * 1);
    // 00527ad1  896a20                 -mov dword ptr [edx + 0x20], ebp
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */) = cpu.ebp;
    // 00527ad4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00527ad6  7cea                   -jl 0x527ac2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00527ac2;
    }
    // 00527ad8  894b20                 -mov dword ptr [ebx + 0x20], ecx
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00527adb  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00527ae0  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00527ae1  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00527ae2  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00527ae3  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00527ae4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_527ae8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00527ae8  c7421c00000000         -mov dword ptr [edx + 0x1c], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 00527aef  c7422000000000         -mov dword ptr [edx + 0x20], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 00527af6  c7420400000000         -mov dword ptr [edx + 4], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00527afd  c7420800000000         -mov dword ptr [edx + 8], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 00527b04  895a14                 -mov dword ptr [edx + 0x14], ebx
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 00527b07  894a18                 -mov dword ptr [edx + 0x18], ecx
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 00527b0a  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00527b0e  c70254795200           -mov dword ptr [edx], 0x527954
    *app->getMemory<x86::reg32>(cpu.edx) = 5405012 /*0x527954*/;
    // 00527b14  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00527b18  b890000000             -mov eax, 0x90
    cpu.eax = 144 /*0x90*/;
    // 00527b1d  c70250795200           -mov dword ptr [edx], 0x527950
    *app->getMemory<x86::reg32>(cpu.edx) = 5405008 /*0x527950*/;
    // 00527b23  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_527b30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00527b30  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00527b31  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00527b32  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00527b33  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00527b36  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00527b38  891424                 -mov dword ptr [esp], edx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00527b3b  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 00527b3d  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00527b3f  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx);
    // 00527b41  39d8                   +cmp eax, ebx
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
    // 00527b43  7d02                   -jge 0x527b47
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00527b47;
    }
    // 00527b45  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x00527b47:
    // 00527b47  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00527b49  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00527b4b  7e13                   -jle 0x527b60
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00527b60;
    }
    // 00527b4d  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
L_0x00527b50:
    // 00527b50  d901                   -fld dword ptr [ecx]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.ecx)));
    // 00527b52  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00527b55  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00527b58  40                     -inc eax
    (cpu.eax)++;
    // 00527b59  d95afc                 -fstp dword ptr [edx - 4]
    *app->getMemory<float>(cpu.edx + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00527b5c  39f0                   +cmp eax, esi
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
    // 00527b5e  7cf0                   -jl 0x527b50
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00527b50;
    }
L_0x00527b60:
    // 00527b60  39f8                   +cmp eax, edi
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
    // 00527b62  7d1c                   -jge 0x527b80
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00527b80;
    }
    // 00527b64  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    // 00527b67  8d0c8500000000         -lea ecx, [eax*4]
    cpu.ecx = x86::reg32(cpu.eax * 4);
    // 00527b6e  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
L_0x00527b70:
    // 00527b70  d901                   -fld dword ptr [ecx]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.ecx)));
    // 00527b72  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00527b75  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00527b78  40                     -inc eax
    (cpu.eax)++;
    // 00527b79  d95bfc                 -fstp dword ptr [ebx - 4]
    *app->getMemory<float>(cpu.ebx + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00527b7c  39f8                   +cmp eax, edi
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
    // 00527b7e  7cf0                   -jl 0x527b70
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00527b70;
    }
L_0x00527b80:
    // 00527b80  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00527b82  895500                 -mov dword ptr [ebp], edx
    *app->getMemory<x86::reg32>(cpu.ebp) = cpu.edx;
    // 00527b85  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00527b88  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00527b89  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00527b8a  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00527b8b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_527b8c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00527b8c  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00527b8d  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00527b8e  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00527b8f  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00527b90  83ec7c                 -sub esp, 0x7c
    (cpu.esp) -= x86::reg32(x86::sreg32(124 /*0x7c*/));
    // 00527b93  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00527b95  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00527b97  895810                 -mov dword ptr [eax + 0x10], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 00527b9a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00527b9c  7e55                   -jle 0x527bf3
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00527bf3;
    }
    // 00527b9e  8d5010                 -lea edx, [eax + 0x10]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00527ba1  89542474               -mov dword ptr [esp + 0x74], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */) = cpu.edx;
    // 00527ba5  8d682c                 -lea ebp, [eax + 0x2c]
    cpu.ebp = x86::reg32(cpu.eax + x86::reg32(44) /* 0x2c */);
L_0x00527ba8:
    // 00527ba8  8b4e28                 -mov ecx, dword ptr [esi + 0x28]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 00527bab  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00527bad  7566                   -jne 0x527c15
    if (!cpu.flags.zf)
    {
        goto L_0x00527c15;
    }
    // 00527baf  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00527bb2  8b5e24                 -mov ebx, dword ptr [esi + 0x24]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 00527bb5  83c01b                 -add eax, 0x1b
    (cpu.eax) += x86::reg32(x86::sreg32(27 /*0x1b*/));
    // 00527bb8  39d8                   +cmp eax, ebx
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
    // 00527bba  7d74                   -jge 0x527c30
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00527c30;
    }
    // 00527bbc  6b561c0f               -imul edx, dword ptr [esi + 0x1c], 0xf
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */))) * x86::sreg64(x86::sreg32(15 /*0xf*/)));
    // 00527bc0  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 00527bc5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00527bc7  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00527bca  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00527bcc  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00527bcf  c7061c000000           -mov dword ptr [esi], 0x1c
    *app->getMemory<x86::reg32>(cpu.esi) = 28 /*0x1c*/;
    // 00527bd5  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00527bd7  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00527bd8  89560c                 -mov dword ptr [esi + 0xc], edx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00527bdb  e8b08ffdff             -call 0x500b90
    cpu.esp -= 4;
    sub_500b90(app, cpu);
    if (cpu.terminate) return;
    // 00527be0  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00527be3  83ef1c                 -sub edi, 0x1c
    (cpu.edi) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00527be6  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00527be9  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00527bec  89461c                 -mov dword ptr [esi + 0x1c], eax
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.eax;
L_0x00527bef:
    // 00527bef  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00527bf1  7fb5                   -jg 0x527ba8
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00527ba8;
    }
L_0x00527bf3:
    // 00527bf3  8d04bd00000000         -lea eax, [edi*4]
    cpu.eax = x86::reg32(cpu.edi * 4);
    // 00527bfa  014610                 -add dword ptr [esi + 0x10], eax
    (*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */)) += x86::reg32(x86::sreg32(cpu.eax));
    // 00527bfd  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x00527c00:
    // 00527c00  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00527c02  0f8c27010000           -jl 0x527d2f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00527d2f;
    }
    // 00527c08  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00527c0d  83c47c                 -add esp, 0x7c
    (cpu.esp) += x86::reg32(x86::sreg32(124 /*0x7c*/));
    // 00527c10  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00527c11  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00527c12  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00527c13  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00527c14  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00527c15:
    // 00527c15  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00527c17  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00527c19  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00527c1b  8b4c2474               -mov ecx, dword ptr [esp + 0x74]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 00527c1f  e80cffffff             -call 0x527b30
    cpu.esp -= 4;
    sub_527b30(app, cpu);
    if (cpu.terminate) return;
    // 00527c24  8b5628                 -mov edx, dword ptr [esi + 0x28]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 00527c27  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00527c29  29c7                   +sub edi, eax
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00527c2b  895628                 -mov dword ptr [esi + 0x28], edx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 00527c2e  ebbf                   -jmp 0x527bef
    goto L_0x00527bef;
L_0x00527c30:
    // 00527c30  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00527c33  89442470               -mov dword ptr [esp + 0x70], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */) = cpu.eax;
    // 00527c37  6b561c0f               -imul edx, dword ptr [esi + 0x1c], 0xf
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */))) * x86::sreg64(x86::sreg32(15 /*0xf*/)));
    // 00527c3b  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 00527c40  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00527c42  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00527c45  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00527c47  c7061c000000           -mov dword ptr [esi], 0x1c
    *app->getMemory<x86::reg32>(cpu.esi) = 28 /*0x1c*/;
    // 00527c4d  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00527c50  896e10                 -mov dword ptr [esi + 0x10], ebp
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ebp;
    // 00527c53  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00527c55  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00527c56  89560c                 -mov dword ptr [esi + 0xc], edx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00527c59  e8328ffdff             -call 0x500b90
    cpu.esp -= 4;
    sub_500b90(app, cpu);
    if (cpu.terminate) return;
    // 00527c5e  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00527c61  83c21c                 -add edx, 0x1c
    (cpu.edx) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00527c64  8b4e24                 -mov ecx, dword ptr [esi + 0x24]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 00527c67  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00527c69  89561c                 -mov dword ptr [esi + 0x1c], edx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 00527c6c  ba1c000000             -mov edx, 0x1c
    cpu.edx = 28 /*0x1c*/;
    // 00527c71  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00527c73  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00527c75  8b4620                 -mov eax, dword ptr [esi + 0x20]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 00527c78  895628                 -mov dword ptr [esi + 0x28], edx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 00527c7b  8d5a01                 -lea ebx, [edx + 1]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00527c7e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00527c80  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 00527c85  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00527c88  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00527c8a  0fafc1                 -imul eax, ecx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 00527c8d  89461c                 -mov dword ptr [esi + 0x1c], eax
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00527c90  8b4620                 -mov eax, dword ptr [esi + 0x20]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 00527c93  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00527c95  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00527c98  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00527c9a  d98608010000           -fld dword ptr [esi + 0x108]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.esi + x86::reg32(264) /* 0x108 */)));
    // 00527ca0  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00527ca3  d95e04                 -fstp dword ptr [esi + 4]
    *app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00527ca6  8b860c010000           -mov eax, dword ptr [esi + 0x10c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(268) /* 0x10c */);
    // 00527cac  894608                 -mov dword ptr [esi + 8], eax
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00527caf  895e28                 -mov dword ptr [esi + 0x28], ebx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.ebx;
    // 00527cb2  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00527cb4  746d                   -je 0x527d23
    if (cpu.flags.zf)
    {
        goto L_0x00527d23;
    }
    // 00527cb6  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00527cb9  6bd00f                 -imul edx, eax, 0xf
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(15 /*0xf*/)));
    // 00527cbc  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00527cbe  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00527cc1  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00527cc3  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00527cc6  890e                   -mov dword ptr [esi], ecx
    *app->getMemory<x86::reg32>(cpu.esi) = cpu.ecx;
    // 00527cc8  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00527cca  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00527ccc  89560c                 -mov dword ptr [esi + 0xc], edx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00527ccf  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00527cd0  894610                 -mov dword ptr [esi + 0x10], eax
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00527cd3  e8b88efdff             -call 0x500b90
    cpu.esp -= 4;
    sub_500b90(app, cpu);
    if (cpu.terminate) return;
    // 00527cd8  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00527cdb  83c21c                 -add edx, 0x1c
    (cpu.edx) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00527cde  8b4e20                 -mov ecx, dword ptr [esi + 0x20]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 00527ce1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00527ce3  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00527ce6  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00527ce8  89442478               -mov dword ptr [esp + 0x78], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */) = cpu.eax;
    // 00527cec  b81c000000             -mov eax, 0x1c
    cpu.eax = 28 /*0x1c*/;
    // 00527cf1  8b5c2478               -mov ebx, dword ptr [esp + 0x78]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00527cf5  89561c                 -mov dword ptr [esi + 0x1c], edx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 00527cf8  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00527cfa  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00527cfc  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00527cff  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00527d01  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00527d03  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00527d05  7e1c                   -jle 0x527d23
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00527d23;
    }
    // 00527d07  8b5c2478               -mov ebx, dword ptr [esp + 0x78]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */);
L_0x00527d0b:
    // 00527d0b  8b4e28                 -mov ecx, dword ptr [esi + 0x28]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 00527d0e  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx)));
    // 00527d10  d95c8e2c               -fstp dword ptr [esi + ecx*4 + 0x2c]
    *app->getMemory<float>(cpu.esi + x86::reg32(44) /* 0x2c */ + cpu.ecx * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00527d14  8b4e28                 -mov ecx, dword ptr [esi + 0x28]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 00527d17  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00527d1a  41                     -inc ecx
    (cpu.ecx)++;
    // 00527d1b  40                     -inc eax
    (cpu.eax)++;
    // 00527d1c  894e28                 -mov dword ptr [esi + 0x28], ecx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.ecx;
    // 00527d1f  39d8                   +cmp eax, ebx
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
    // 00527d21  7ce8                   -jl 0x527d0b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00527d0b;
    }
L_0x00527d23:
    // 00527d23  8b442470               -mov eax, dword ptr [esp + 0x70]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */);
    // 00527d27  894610                 -mov dword ptr [esi + 0x10], eax
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00527d2a  e9c0feffff             -jmp 0x527bef
    goto L_0x00527bef;
L_0x00527d2f:
    // 00527d2f  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00527d32  8b4628                 -mov eax, dword ptr [esi + 0x28]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 00527d35  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx);
    // 00527d37  894c862c               -mov dword ptr [esi + eax*4 + 0x2c], ecx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */ + cpu.eax * 4) = cpu.ecx;
    // 00527d3b  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00527d3e  8b5e28                 -mov ebx, dword ptr [esi + 0x28]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 00527d41  83c104                 +add ecx, 4
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
    // 00527d44  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00527d45  894e10                 -mov dword ptr [esi + 0x10], ecx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00527d48  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00527d49  895e28                 -mov dword ptr [esi + 0x28], ebx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.ebx;
    // 00527d4c  e9affeffff             -jmp 0x527c00
    goto L_0x00527c00;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_527d54(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00527d54  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00527d55  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00527d56  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00527d57  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00527d58  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00527d5b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00527d5d  89542404               -mov dword ptr [esp + 4], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00527d61  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00527d63  895810                 -mov dword ptr [eax + 0x10], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 00527d66  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00527d68  3b4128                 +cmp eax, dword ptr [ecx + 0x28]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00527d6b  7f67                   -jg 0x527dd4
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00527dd4;
    }
    // 00527d6d  8b7c2404               -mov edi, dword ptr [esp + 4]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00527d71  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00527d73  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00527d75  7e21                   -jle 0x527d98
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00527d98;
    }
    // 00527d77  8b7c2404               -mov edi, dword ptr [esp + 4]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00527d7b  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
L_0x00527d7d:
    // 00527d7d  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00527d80  8b5a2c                 -mov ebx, dword ptr [edx + 0x2c]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(44) /* 0x2c */);
    // 00527d83  8919                   -mov dword ptr [ecx], ebx
    *app->getMemory<x86::reg32>(cpu.ecx) = cpu.ebx;
    // 00527d85  8b5e10                 -mov ebx, dword ptr [esi + 0x10]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00527d88  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00527d8b  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00527d8e  40                     -inc eax
    (cpu.eax)++;
    // 00527d8f  895e10                 -mov dword ptr [esi + 0x10], ebx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 00527d92  39f8                   +cmp eax, edi
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
    // 00527d94  7ce7                   -jl 0x527d7d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00527d7d;
    }
    // 00527d96  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x00527d98:
    // 00527d98  8b6e28                 -mov ebp, dword ptr [esi + 0x28]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 00527d9b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00527d9d  39e8                   +cmp eax, ebp
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
    // 00527d9f  7d23                   -jge 0x527dc4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00527dc4;
    }
    // 00527da1  8d0c8500000000         -lea ecx, [eax*4]
    cpu.ecx = x86::reg32(cpu.eax * 4);
    // 00527da8  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00527daa  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
L_0x00527dac:
    // 00527dac  d9412c                 -fld dword ptr [ecx + 0x2c]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.ecx + x86::reg32(44) /* 0x2c */)));
    // 00527daf  43                     -inc ebx
    (cpu.ebx)++;
    // 00527db0  40                     -inc eax
    (cpu.eax)++;
    // 00527db1  d95a2c                 -fstp dword ptr [edx + 0x2c]
    *app->getMemory<float>(cpu.edx + x86::reg32(44) /* 0x2c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00527db4  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00527db7  8b7e28                 -mov edi, dword ptr [esi + 0x28]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 00527dba  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00527dbd  39f8                   +cmp eax, edi
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
    // 00527dbf  7ceb                   -jl 0x527dac
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00527dac;
    }
    // 00527dc1  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x00527dc4:
    // 00527dc4  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00527dc9  895e28                 -mov dword ptr [esi + 0x28], ebx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.ebx;
    // 00527dcc  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00527dcf  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00527dd0  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00527dd1  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00527dd2  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00527dd3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00527dd4:
    // 00527dd4  8b5928                 -mov ebx, dword ptr [ecx + 0x28]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */);
    // 00527dd7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00527dd9  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00527ddb  7e1f                   -jle 0x527dfc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00527dfc;
    }
    // 00527ddd  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x00527ddf:
    // 00527ddf  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00527de2  d9402c                 -fld dword ptr [eax + 0x2c]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax + x86::reg32(44) /* 0x2c */)));
    // 00527de5  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00527de8  d919                   -fstp dword ptr [ecx]
    *app->getMemory<float>(cpu.ecx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00527dea  8b6e10                 -mov ebp, dword ptr [esi + 0x10]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00527ded  42                     -inc edx
    (cpu.edx)++;
    // 00527dee  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00527df1  8b4e28                 -mov ecx, dword ptr [esi + 0x28]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 00527df4  896e10                 -mov dword ptr [esi + 0x10], ebp
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ebp;
    // 00527df7  39ca                   +cmp edx, ecx
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
    // 00527df9  7ce4                   -jl 0x527ddf
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00527ddf;
    }
    // 00527dfb  90                     -nop 
    ;
L_0x00527dfc:
    // 00527dfc  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00527e00  8b4628                 -mov eax, dword ptr [esi + 0x28]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 00527e03  8b7e1c                 -mov edi, dword ptr [esi + 0x1c]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00527e06  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00527e08  8b4620                 -mov eax, dword ptr [esi + 0x20]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 00527e0b  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00527e0d  83e81b                 -sub eax, 0x1b
    (cpu.eax) -= x86::reg32(x86::sreg32(27 /*0x1b*/));
    // 00527e10  895c2404               -mov dword ptr [esp + 4], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00527e14  39d8                   +cmp eax, ebx
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
    // 00527e16  0f8eca000000           -jle 0x527ee6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00527ee6;
    }
    // 00527e1c  891c24                 -mov dword ptr [esp], ebx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
L_0x00527e1f:
    // 00527e1f  833c2400               +cmp dword ptr [esp], 0
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
    // 00527e23  0f8cc5000000           -jl 0x527eee
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00527eee;
    }
L_0x00527e29:
    // 00527e29  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 00527e2c  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00527e2f  8906                   -mov dword ptr [esi], eax
    *app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 00527e31  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00527e38  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00527e3a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00527e3c  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00527e3f  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00527e41  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00527e43  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 00527e48  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00527e4b  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00527e4d  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00527e50  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00527e52  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00527e53  89560c                 -mov dword ptr [esi + 0xc], edx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00527e56  e8358dfdff             -call 0x500b90
    cpu.esp -= 4;
    sub_500b90(app, cpu);
    if (cpu.terminate) return;
    // 00527e5b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00527e5e  8b4e1c                 -mov ecx, dword ptr [esi + 0x1c]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00527e61  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 00527e64  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00527e66  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00527e68  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi);
    // 00527e6a  894e1c                 -mov dword ptr [esi + 0x1c], ecx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00527e6d  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00527e6f  895e1c                 -mov dword ptr [esi + 0x1c], ebx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 00527e72  8b1e                   -mov ebx, dword ptr [esi]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi);
    // 00527e74  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00527e76  8d3c9d00000000         -lea edi, [ebx*4]
    cpu.edi = x86::reg32(cpu.ebx * 4);
    // 00527e7d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00527e7f  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00527e81  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00527e83  90                     -nop 
    ;
L_0x00527e84:
    // 00527e84  7c72                   -jl 0x527ef8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00527ef8;
    }
    // 00527e86  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 00527e89  8b6c2404               -mov ebp, dword ptr [esp + 4]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00527e8d  8b7e10                 -mov edi, dword ptr [esi + 0x10]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00527e90  894e28                 -mov dword ptr [esi + 0x28], ecx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.ecx;
    // 00527e93  29d7                   -sub edi, edx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00527e95  29c5                   -sub ebp, eax
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00527e97  8b4620                 -mov eax, dword ptr [esi + 0x20]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 00527e9a  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00527e9d  896c2404               -mov dword ptr [esp + 4], ebp
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 00527ea1  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00527ea3  897e10                 -mov dword ptr [esi + 0x10], edi
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.edi;
    // 00527ea6  83f81c                 +cmp eax, 0x1c
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
    // 00527ea9  7d2e                   -jge 0x527ed9
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00527ed9;
    }
    // 00527eab  d94604                 -fld dword ptr [esi + 4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 00527eae  8b8610010000           -mov eax, dword ptr [esi + 0x110]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(272) /* 0x110 */);
    // 00527eb4  d99e08010000           -fstp dword ptr [esi + 0x108]
    *app->getMemory<float>(cpu.esi + x86::reg32(264) /* 0x108 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00527eba  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00527ebd  89960c010000           -mov dword ptr [esi + 0x10c], edx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(268) /* 0x10c */) = cpu.edx;
    // 00527ec3  c7008c7b5200           -mov dword ptr [eax], 0x527b8c
    *app->getMemory<x86::reg32>(cpu.eax) = 5405580 /*0x527b8c*/;
    // 00527ec9  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00527ecb  7e0c                   -jle 0x527ed9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00527ed9;
    }
    // 00527ecd  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00527ecf  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00527ed1  8b5e10                 -mov ebx, dword ptr [esi + 0x10]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00527ed4  e8b3fcffff             -call 0x527b8c
    cpu.esp -= 4;
    sub_527b8c(app, cpu);
    if (cpu.terminate) return;
L_0x00527ed9:
    // 00527ed9  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00527ede  83c40c                 +add esp, 0xc
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
    // 00527ee1  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00527ee2  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00527ee3  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00527ee4  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00527ee5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00527ee6:
    // 00527ee6  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00527ee9  e931ffffff             -jmp 0x527e1f
    goto L_0x00527e1f;
L_0x00527eee:
    // 00527eee  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00527ef0  891424                 -mov dword ptr [esp], edx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00527ef3  e931ffffff             -jmp 0x527e29
    goto L_0x00527e29;
L_0x00527ef8:
    // 00527ef8  8b7e10                 -mov edi, dword ptr [esi + 0x10]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00527efb  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00527efd  43                     -inc ebx
    (cpu.ebx)++;
    // 00527efe  897c2408               -mov dword ptr [esp + 8], edi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 00527f02  41                     -inc ecx
    (cpu.ecx)++;
    // 00527f03  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00527f07  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00527f0a  8d3c16                 -lea edi, [esi + edx]
    cpu.edi = x86::reg32(cpu.esi + cpu.edx * 1);
    // 00527f0d  d94500                 -fld dword ptr [ebp]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.ebp)));
    // 00527f10  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00527f13  d95f2c                 -fstp dword ptr [edi + 0x2c]
    *app->getMemory<float>(cpu.edi + x86::reg32(44) /* 0x2c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00527f16  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00527f18  e967ffffff             -jmp 0x527e84
    goto L_0x00527e84;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_527f20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00527f20  c7421c00000000         -mov dword ptr [edx + 0x1c], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 00527f27  c7422800000000         -mov dword ptr [edx + 0x28], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
    // 00527f2e  c7420400000000         -mov dword ptr [edx + 4], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00527f35  c7420800000000         -mov dword ptr [edx + 8], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 00527f3c  895a14                 -mov dword ptr [edx + 0x14], ebx
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 00527f3f  894a18                 -mov dword ptr [edx + 0x18], ecx
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 00527f42  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00527f46  894a20                 -mov dword ptr [edx + 0x20], ecx
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00527f49  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00527f4d  894a24                 -mov dword ptr [edx + 0x24], ecx
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */) = cpu.ecx;
    // 00527f50  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00527f54  898a10010000           -mov dword ptr [edx + 0x110], ecx
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(272) /* 0x110 */) = cpu.ecx;
    // 00527f5a  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00527f5e  c701547d5200           -mov dword ptr [ecx], 0x527d54
    *app->getMemory<x86::reg32>(cpu.ecx) = 5406036 /*0x527d54*/;
    // 00527f64  b814010000             -mov eax, 0x114
    cpu.eax = 276 /*0x114*/;
    // 00527f69  c70200000000           -mov dword ptr [edx], 0
    *app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 00527f6f  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_527f80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00527f80  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00527f81  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00527f82  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00527f83  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00527f86  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00527f88  8b5014                 -mov edx, dword ptr [eax + 0x14]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 00527f8b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00527f8d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00527f8f  0f84b8000000           -je 0x52804d
    if (cpu.flags.zf)
    {
        goto L_0x0052804d;
    }
    // 00527f95  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00527f96  895810                 -mov dword ptr [eax + 0x10], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 00527f99  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00527f9b  0f8e8a000000           -jle 0x52802b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052802b;
    }
    // 00527fa1  8d6810                 -lea ebp, [eax + 0x10]
    cpu.ebp = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00527fa4  8d5024                 -lea edx, [eax + 0x24]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 00527fa7  89542408               -mov dword ptr [esp + 8], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00527fab  8d5018                 -lea edx, [eax + 0x18]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00527fae  83c014                 -add eax, 0x14
    (cpu.eax) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00527fb1  89542404               -mov dword ptr [esp + 4], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00527fb5  8944240c               -mov dword ptr [esp + 0xc], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x00527fb9:
    // 00527fb9  8b5e20                 -mov ebx, dword ptr [esi + 0x20]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 00527fbc  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00527fbe  0f8595000000           -jne 0x528059
    if (!cpu.flags.zf)
    {
        goto L_0x00528059;
    }
    // 00527fc4  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00527fc7  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00527fca  83c01b                 -add eax, 0x1b
    (cpu.eax) += x86::reg32(x86::sreg32(27 /*0x1b*/));
    // 00527fcd  39d0                   +cmp eax, edx
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
    // 00527fcf  0f8d9f000000           -jge 0x528074
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00528074;
    }
    // 00527fd5  2b561c                 -sub edx, dword ptr [esi + 0x1c]
    (cpu.edx) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */)));
    // 00527fd8  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 00527fdd  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00527fdf  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00527fe2  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00527fe4  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00527fe6  0fafd9                 -imul ebx, ecx
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 00527fe9  39df                   +cmp edi, ebx
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
    // 00527feb  7d0d                   -jge 0x527ffa
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00527ffa;
    }
    // 00527fed  8d571b                 -lea edx, [edi + 0x1b]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(27) /* 0x1b */);
    // 00527ff0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00527ff2  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00527ff5  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00527ff7  6bd81c                 -imul ebx, eax, 0x1c
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(28 /*0x1c*/)));
L_0x00527ffa:
    // 00527ffa  6b561c0f               -imul edx, dword ptr [esi + 0x1c], 0xf
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */))) * x86::sreg64(x86::sreg32(15 /*0xf*/)));
    // 00527ffe  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 00528003  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00528005  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00528008  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0052800a  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0052800d  891e                   -mov dword ptr [esi], ebx
    *app->getMemory<x86::reg32>(cpu.esi) = cpu.ebx;
    // 0052800f  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00528011  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00528012  89560c                 -mov dword ptr [esi + 0xc], edx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00528015  e8768bfdff             -call 0x500b90
    cpu.esp -= 4;
    sub_500b90(app, cpu);
    if (cpu.terminate) return;
    // 0052801a  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0052801d  29df                   -sub edi, ebx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0052801f  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00528021  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00528024  89561c                 -mov dword ptr [esi + 0x1c], edx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.edx;
L_0x00528027:
    // 00528027  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00528029  7f8e                   -jg 0x527fb9
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00527fb9;
    }
L_0x0052802b:
    // 0052802b  8d04bd00000000         -lea eax, [edi*4]
    cpu.eax = x86::reg32(cpu.edi * 4);
    // 00528032  014610                 -add dword ptr [esi + 0x10], eax
    (*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */)) += x86::reg32(x86::sreg32(cpu.eax));
    // 00528035  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x00528038:
    // 00528038  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0052803a  0f8cda000000           -jl 0x52811a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052811a;
    }
    // 00528040  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00528045  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528046  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00528049  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052804a  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052804b  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052804c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052804d:
    // 0052804d  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00528052  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00528055  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528056  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528057  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528058  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00528059:
    // 00528059  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052805d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052805f  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 00528061  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00528063  e8c8faffff             -call 0x527b30
    cpu.esp -= 4;
    sub_527b30(app, cpu);
    if (cpu.terminate) return;
    // 00528068  8b4e20                 -mov ecx, dword ptr [esi + 0x20]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 0052806b  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0052806d  29c7                   +sub edi, eax
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0052806f  894e20                 -mov dword ptr [esi + 0x20], ecx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00528072  ebb3                   -jmp 0x528027
    goto L_0x00528027;
L_0x00528074:
    // 00528074  837e1401               +cmp dword ptr [esi + 0x14], 1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00528078  744e                   -je 0x5280c8
    if (cpu.flags.zf)
    {
        goto L_0x005280c8;
    }
    // 0052807a  3b561c                 +cmp edx, dword ptr [esi + 0x1c]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052807d  7e49                   -jle 0x5280c8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x005280c8;
    }
    // 0052807f  6b561c0f               -imul edx, dword ptr [esi + 0x1c], 0xf
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */))) * x86::sreg64(x86::sreg32(15 /*0xf*/)));
    // 00528083  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 00528088  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0052808a  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0052808d  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0052808f  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00528092  c7061c000000           -mov dword ptr [esi], 0x1c
    *app->getMemory<x86::reg32>(cpu.esi) = 28 /*0x1c*/;
    // 00528098  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0052809a  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052809b  89560c                 -mov dword ptr [esi + 0xc], edx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0052809e  e8ed8afdff             -call 0x500b90
    cpu.esp -= 4;
    sub_500b90(app, cpu);
    if (cpu.terminate) return;
    // 005280a3  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 005280a6  b81c000000             -mov eax, 0x1c
    cpu.eax = 28 /*0x1c*/;
    // 005280ab  83c21c                 -add edx, 0x1c
    (cpu.edx) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 005280ae  8b4e18                 -mov ecx, dword ptr [esi + 0x18]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 005280b1  89561c                 -mov dword ptr [esi + 0x1c], edx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 005280b4  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 005280b6  8b5e10                 -mov ebx, dword ptr [esi + 0x10]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 005280b9  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 005280bb  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 005280be  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005280c1  29d3                   -sub ebx, edx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 005280c3  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 005280c5  895e10                 -mov dword ptr [esi + 0x10], ebx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ebx;
L_0x005280c8:
    // 005280c8  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 005280cc  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 005280d0  ff15b4785600           -call dword ptr [0x5678b4]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5666996) /* 0x5678b4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005280d6  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 005280d9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005280db  751d                   -jne 0x5280fa
    if (!cpu.flags.zf)
    {
        goto L_0x005280fa;
    }
L_0x005280dd:
    // 005280dd  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 005280df  0f8e42ffffff           -jle 0x528027
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00528027;
    }
    // 005280e5  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 005280e8  c70000000000           -mov dword ptr [eax], 0
    *app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 005280ee  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 005280f1  83c004                 +add eax, 4
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
    // 005280f4  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 005280f5  894610                 -mov dword ptr [esi + 0x10], eax
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 005280f8  ebe3                   -jmp 0x5280dd
    goto L_0x005280dd;
L_0x005280fa:
    // 005280fa  df00                   -fild word ptr [eax]
    cpu.fpu.push(x86::Float(x86::sreg16(*app->getMemory<x86::reg16>(cpu.eax))));
    // 005280fc  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 005280ff  d95e04                 -fstp dword ptr [esi + 4]
    *app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00528102  df4002                 -fild word ptr [eax + 2]
    cpu.fpu.push(x86::Float(x86::sreg16(*app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */))));
    // 00528105  c7461c00000000         -mov dword ptr [esi + 0x1c], 0
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 0052810c  83c208                 +add edx, 8
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
    // 0052810f  d95e08                 +fstp dword ptr [esi + 8]
    *app->getMemory<float>(cpu.esi + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00528112  895614                 -mov dword ptr [esi + 0x14], edx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 00528115  e90dffffff             -jmp 0x528027
    goto L_0x00528027;
L_0x0052811a:
    // 0052811a  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0052811d  8b4620                 -mov eax, dword ptr [esi + 0x20]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 00528120  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx);
    // 00528122  894c8624               -mov dword ptr [esi + eax*4 + 0x24], ecx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */ + cpu.eax * 4) = cpu.ecx;
    // 00528126  8b5e10                 -mov ebx, dword ptr [esi + 0x10]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00528129  8b6e20                 -mov ebp, dword ptr [esi + 0x20]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 0052812c  83c304                 +add ebx, 4
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
    // 0052812f  45                     +inc ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00528130  895e10                 -mov dword ptr [esi + 0x10], ebx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 00528133  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00528134  896e20                 -mov dword ptr [esi + 0x20], ebp
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = cpu.ebp;
    // 00528137  e9fcfeffff             -jmp 0x528038
    goto L_0x00528038;
}

/* align: skip  */
void Application::sub_52813c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052813c  c7421401000000         -mov dword ptr [edx + 0x14], 1
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = 1 /*0x1*/;
    // 00528143  c7421c00000000         -mov dword ptr [edx + 0x1c], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 0052814a  c7422000000000         -mov dword ptr [edx + 0x20], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 00528151  c7420400000000         -mov dword ptr [edx + 4], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00528158  c7420800000000         -mov dword ptr [edx + 8], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 0052815f  894a18                 -mov dword ptr [edx + 0x18], ecx
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 00528162  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00528166  c702807f5200           -mov dword ptr [edx], 0x527f80
    *app->getMemory<x86::reg32>(cpu.edx) = 5406592 /*0x527f80*/;
    // 0052816c  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00528170  b890000000             -mov eax, 0x90
    cpu.eax = 144 /*0x90*/;
    // 00528175  c70200000000           -mov dword ptr [edx], 0
    *app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 0052817b  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_528180(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00528180  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00528181  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00528182  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00528183  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00528184  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00528187  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00528189  89542404               -mov dword ptr [esp + 4], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0052818d  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0052818f  8b5028                 -mov edx, dword ptr [eax + 0x28]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 00528192  895810                 -mov dword ptr [eax + 0x10], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 00528195  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00528197  754a                   -jne 0x5281e3
    if (!cpu.flags.zf)
    {
        goto L_0x005281e3;
    }
L_0x00528199:
    // 00528199  8d7510                 -lea esi, [ebp + 0x10]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0052819c  8d452c                 -lea eax, [ebp + 0x2c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(44) /* 0x2c */);
    // 0052819f  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 005281a2  8d7d18                 -lea edi, [ebp + 0x18]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(24) /* 0x18 */);
L_0x005281a5:
    // 005281a5  837c240400             +cmp dword ptr [esp + 4], 0
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
    // 005281aa  0f8e85010000           -jle 0x528335
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00528335;
    }
    // 005281b0  8b5d20                 -mov ebx, dword ptr [ebp + 0x20]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 005281b3  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 005281b5  743d                   -je 0x5281f4
    if (cpu.flags.zf)
    {
        goto L_0x005281f4;
    }
    // 005281b7  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    // 005281ba  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 005281bc  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 005281be  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 005281c2  e869f9ffff             -call 0x527b30
    cpu.esp -= 4;
    sub_527b30(app, cpu);
    if (cpu.terminate) return;
    // 005281c7  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 005281cb  8b5d20                 -mov ebx, dword ptr [ebp + 0x20]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 005281ce  8b4d28                 -mov ecx, dword ptr [ebp + 0x28]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */);
    // 005281d1  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 005281d3  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 005281d5  01c1                   +add ecx, eax
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
    // 005281d7  895d20                 -mov dword ptr [ebp + 0x20], ebx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 005281da  89542404               -mov dword ptr [esp + 4], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 005281de  894d28                 -mov dword ptr [ebp + 0x28], ecx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */) = cpu.ecx;
    // 005281e1  ebc2                   -jmp 0x5281a5
    goto L_0x005281a5;
L_0x005281e3:
    // 005281e3  8b4024                 -mov eax, dword ptr [eax + 0x24]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 005281e6  e8ad97feff             -call 0x511998
    cpu.esp -= 4;
    sub_511998(app, cpu);
    if (cpu.terminate) return;
    // 005281eb  c7462800000000         -mov dword ptr [esi + 0x28], 0
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
    // 005281f2  eba5                   -jmp 0x528199
    goto L_0x00528199;
L_0x005281f4:
    // 005281f4  8b451c                 -mov eax, dword ptr [ebp + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 005281f7  8b5518                 -mov edx, dword ptr [ebp + 0x18]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 005281fa  83c01b                 -add eax, 0x1b
    (cpu.eax) += x86::reg32(x86::sreg32(27 /*0x1b*/));
    // 005281fd  39d0                   +cmp eax, edx
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
    // 005281ff  7d6e                   -jge 0x52826f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0052826f;
    }
    // 00528201  2b551c                 -sub edx, dword ptr [ebp + 0x1c]
    (cpu.edx) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */)));
    // 00528204  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 00528209  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0052820b  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0052820e  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00528210  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00528212  0fafd9                 -imul ebx, ecx
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 00528215  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00528219  39c3                   +cmp ebx, eax
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
    // 0052821b  7f43                   -jg 0x528260
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00528260;
    }
L_0x0052821d:
    // 0052821d  6b551c0f               -imul edx, dword ptr [ebp + 0x1c], 0xf
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */))) * x86::sreg64(x86::sreg32(15 /*0xf*/)));
    // 00528221  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 00528226  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00528228  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0052822b  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0052822d  8b5514                 -mov edx, dword ptr [ebp + 0x14]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00528230  895d00                 -mov dword ptr [ebp], ebx
    *app->getMemory<x86::reg32>(cpu.ebp) = cpu.ebx;
    // 00528233  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00528235  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00528236  89550c                 -mov dword ptr [ebp + 0xc], edx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00528239  e85289fdff             -call 0x500b90
    cpu.esp -= 4;
    sub_500b90(app, cpu);
    if (cpu.terminate) return;
    // 0052823e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00528241  8b451c                 -mov eax, dword ptr [ebp + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 00528244  8b4d28                 -mov ecx, dword ptr [ebp + 0x28]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */);
    // 00528247  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052824b  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0052824d  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0052824f  89451c                 -mov dword ptr [ebp + 0x1c], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00528252  29da                   +sub edx, ebx
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00528254  894d28                 -mov dword ptr [ebp + 0x28], ecx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */) = cpu.ecx;
    // 00528257  89542404               -mov dword ptr [esp + 4], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0052825b  e945ffffff             -jmp 0x5281a5
    goto L_0x005281a5;
L_0x00528260:
    // 00528260  8d501b                 -lea edx, [eax + 0x1b]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(27) /* 0x1b */);
    // 00528263  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00528265  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00528268  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0052826a  6bd81c                 +imul ebx, eax, 0x1c
    {
        x86::sreg64 tmp = x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(28 /*0x1c*/));
        cpu.ebx = static_cast<x86::reg32>(static_cast<x86::sreg32>(tmp));
        cpu.flags.of = cpu.flags.cf = (tmp != x86::sreg64(x86::sreg32(cpu.ebx)));
    }
    // 0052826d  ebae                   -jmp 0x52821d
    goto L_0x0052821d;
L_0x0052826f:
    // 0052826f  3b551c                 +cmp edx, dword ptr [ebp + 0x1c]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00528272  7e5c                   -jle 0x5282d0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x005282d0;
    }
    // 00528274  6b551c0f               -imul edx, dword ptr [ebp + 0x1c], 0xf
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */))) * x86::sreg64(x86::sreg32(15 /*0xf*/)));
    // 00528278  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 0052827d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0052827f  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00528282  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00528284  8b5514                 -mov edx, dword ptr [ebp + 0x14]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00528287  c745001c000000         -mov dword ptr [ebp], 0x1c
    *app->getMemory<x86::reg32>(cpu.ebp) = 28 /*0x1c*/;
    // 0052828e  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00528290  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00528291  89550c                 -mov dword ptr [ebp + 0xc], edx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00528294  e8f788fdff             -call 0x500b90
    cpu.esp -= 4;
    sub_500b90(app, cpu);
    if (cpu.terminate) return;
    // 00528299  8b451c                 -mov eax, dword ptr [ebp + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 0052829c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052829f  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 005282a2  8b5518                 -mov edx, dword ptr [ebp + 0x18]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 005282a5  89451c                 -mov dword ptr [ebp + 0x1c], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 005282a8  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 005282aa  8b5d10                 -mov ebx, dword ptr [ebp + 0x10]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 005282ad  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 005282af  b81c000000             -mov eax, 0x1c
    cpu.eax = 28 /*0x1c*/;
    // 005282b4  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 005282b8  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 005282ba  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 005282bd  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 005282bf  29d3                   -sub ebx, edx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 005282c1  8b5528                 -mov edx, dword ptr [ebp + 0x28]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */);
    // 005282c4  895d10                 -mov dword ptr [ebp + 0x10], ebx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 005282c7  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 005282c9  894c2404               -mov dword ptr [esp + 4], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 005282cd  895528                 -mov dword ptr [ebp + 0x28], edx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */) = cpu.edx;
L_0x005282d0:
    // 005282d0  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 005282d2  8b4524                 -mov eax, dword ptr [ebp + 0x24]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */);
    // 005282d5  e82296feff             -call 0x5118fc
    cpu.esp -= 4;
    sub_5118fc(app, cpu);
    if (cpu.terminate) return;
    // 005282da  894514                 -mov dword ptr [ebp + 0x14], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 005282dd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005282df  7420                   -je 0x528301
    if (cpu.flags.zf)
    {
        goto L_0x00528301;
    }
    // 005282e1  df00                   -fild word ptr [eax]
    cpu.fpu.push(x86::Float(x86::sreg16(*app->getMemory<x86::reg16>(cpu.eax))));
    // 005282e3  d95d04                 -fstp dword ptr [ebp + 4]
    *app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 005282e6  df4002                 -fild word ptr [eax + 2]
    cpu.fpu.push(x86::Float(x86::sreg16(*app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */))));
    // 005282e9  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 005282ec  c7451c00000000         -mov dword ptr [ebp + 0x1c], 0
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 005282f3  83c008                 +add eax, 8
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
    // 005282f6  d95d08                 +fstp dword ptr [ebp + 8]
    *app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 005282f9  894514                 -mov dword ptr [ebp + 0x14], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 005282fc  e9a4feffff             -jmp 0x5281a5
    goto L_0x005281a5;
L_0x00528301:
    // 00528301  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00528305  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00528307  0f8e98feffff           -jle 0x5281a5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x005281a5;
    }
    // 0052830d  837d2800               +cmp dword ptr [ebp + 0x28], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00528311  740d                   -je 0x528320
    if (cpu.flags.zf)
    {
        goto L_0x00528320;
    }
    // 00528313  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
    // 00528316  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00528319  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0052831b  e82083fbff             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
L_0x00528320:
    // 00528320  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00528324  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00528327  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0052832a  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0052832c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0052832e  897d10                 -mov dword ptr [ebp + 0x10], edi
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = cpu.edi;
    // 00528331  89442404               -mov dword ptr [esp + 4], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x00528335:
    // 00528335  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00528339  8b5510                 -mov edx, dword ptr [ebp + 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0052833c  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0052833f  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00528341  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00528345  895510                 -mov dword ptr [ebp + 0x10], edx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 00528348  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0052834a  7c0b                   -jl 0x528357
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00528357;
    }
    // 0052834c  8b4528                 -mov eax, dword ptr [ebp + 0x28]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */);
    // 0052834f  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00528352  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528353  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528354  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528355  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528356  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00528357:
    // 00528357  6bc1ff                 -imul eax, ecx, -1
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(-1 /*-0x1*/)));
    // 0052835a  8b7d20                 -mov edi, dword ptr [ebp + 0x20]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 0052835d  89442404               -mov dword ptr [esp + 4], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00528361  8d0c8500000000         -lea ecx, [eax*4]
    cpu.ecx = x86::reg32(cpu.eax * 4);
    // 00528368  c1e702                 -shl edi, 2
    cpu.edi <<= 2 /*0x2*/ % 32;
    // 0052836b  8d452c                 -lea eax, [ebp + 0x2c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(44) /* 0x2c */);
    // 0052836e  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00528370  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00528372  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00528373  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00528375  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00528378  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0052837a  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0052837c  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0052837f  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00528381  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528382  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00528386  8b7520                 -mov esi, dword ptr [ebp + 0x20]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 00528389  8b7d28                 -mov edi, dword ptr [ebp + 0x28]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */);
    // 0052838c  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0052838e  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00528390  897520                 -mov dword ptr [ebp + 0x20], esi
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */) = cpu.esi;
    // 00528393  897d28                 -mov dword ptr [ebp + 0x28], edi
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */) = cpu.edi;
    // 00528396  8b4528                 -mov eax, dword ptr [ebp + 0x28]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */);
    // 00528399  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0052839c  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052839d  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052839e  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052839f  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005283a0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_5283a4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005283a4  e8b74d0000             -call 0x52d160
    cpu.esp -= 4;
    sub_52d160(app, cpu);
    if (cpu.terminate) return;
    // 005283a9  c7421400000000         -mov dword ptr [edx + 0x14], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 005283b0  c7421c00000000         -mov dword ptr [edx + 0x1c], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 005283b7  c7422000000000         -mov dword ptr [edx + 0x20], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 005283be  c7420400000000         -mov dword ptr [edx + 4], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 005283c5  c7420800000000         -mov dword ptr [edx + 8], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 005283cc  c7422800000000         -mov dword ptr [edx + 0x28], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
    // 005283d3  894224                 -mov dword ptr [edx + 0x24], eax
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 005283d6  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 005283da  894a18                 -mov dword ptr [edx + 0x18], ecx
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 005283dd  c70080815200           -mov dword ptr [eax], 0x528180
    *app->getMemory<x86::reg32>(cpu.eax) = 5407104 /*0x528180*/;
    // 005283e3  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 005283e7  c70000000000           -mov dword ptr [eax], 0
    *app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 005283ed  b898000000             -mov eax, 0x98
    cpu.eax = 152 /*0x98*/;
    // 005283f2  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_528400(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00528400  8b4024                 -mov eax, dword ptr [eax + 0x24]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 00528403  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_528404(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00528404  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00528405  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00528406  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00528407  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00528408  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0052840a  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0052840c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052840e  8b5124                 -mov edx, dword ptr [ecx + 0x24]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */);
    // 00528411  8b7920                 -mov edi, dword ptr [ecx + 0x20]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00528414  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00528416  39fa                   +cmp edx, edi
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
    // 00528418  0f8d6b000000           -jge 0x528489
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00528489;
    }
    // 0052841e  894118                 -mov dword ptr [ecx + 0x18], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00528421  8b4128                 -mov eax, dword ptr [ecx + 0x28]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */);
    // 00528424  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00528426  39c6                   +cmp esi, eax
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
    // 00528428  7f69                   -jg 0x528493
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00528493;
    }
    // 0052842a  01f6                   -add esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi));
    // 0052842c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0052842e  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00528430  7e1e                   -jle 0x528450
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00528450;
    }
    // 00528432  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x00528434:
    // 00528434  8b4b18                 -mov ecx, dword ptr [ebx + 0x18]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 00528437  8b782c                 -mov edi, dword ptr [eax + 0x2c]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */);
    // 0052843a  8939                   -mov dword ptr [ecx], edi
    *app->getMemory<x86::reg32>(cpu.ecx) = cpu.edi;
    // 0052843c  8b4b18                 -mov ecx, dword ptr [ebx + 0x18]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 0052843f  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00528442  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00528445  42                     -inc edx
    (cpu.edx)++;
    // 00528446  894b18                 -mov dword ptr [ebx + 0x18], ecx
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 00528449  39f2                   +cmp edx, esi
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
    // 0052844b  7ce7                   -jl 0x528434
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00528434;
    }
    // 0052844d  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x00528450:
    // 00528450  8b7328                 -mov esi, dword ptr [ebx + 0x28]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */);
    // 00528453  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00528455  39f2                   +cmp edx, esi
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
    // 00528457  7d23                   -jge 0x52847c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0052847c;
    }
    // 00528459  8d349500000000         -lea esi, [edx*4]
    cpu.esi = x86::reg32(cpu.edx * 4);
    // 00528460  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00528462  01de                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
L_0x00528464:
    // 00528464  d9462c                 -fld dword ptr [esi + 0x2c]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.esi + x86::reg32(44) /* 0x2c */)));
    // 00528467  41                     -inc ecx
    (cpu.ecx)++;
    // 00528468  42                     -inc edx
    (cpu.edx)++;
    // 00528469  d9582c                 -fstp dword ptr [eax + 0x2c]
    *app->getMemory<float>(cpu.eax + x86::reg32(44) /* 0x2c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052846c  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052846f  8b7b28                 -mov edi, dword ptr [ebx + 0x28]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */);
    // 00528472  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00528475  39fa                   +cmp edx, edi
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
    // 00528477  7ceb                   -jl 0x528464
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00528464;
    }
    // 00528479  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x0052847c:
    // 0052847c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00528481  894b28                 -mov dword ptr [ebx + 0x28], ecx
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */) = cpu.ecx;
    // 00528484  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528485  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528486  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528487  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528488  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00528489:
    // 00528489  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0052848e  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052848f  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528490  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528491  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528492  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00528493:
    // 00528493  8b6928                 -mov ebp, dword ptr [ecx + 0x28]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */);
    // 00528496  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00528498  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0052849a  7e20                   -jle 0x5284bc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x005284bc;
    }
    // 0052849c  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
L_0x0052849e:
    // 0052849e  8b4b18                 -mov ecx, dword ptr [ebx + 0x18]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 005284a1  d9422c                 -fld dword ptr [edx + 0x2c]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(44) /* 0x2c */)));
    // 005284a4  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005284a7  d919                   -fstp dword ptr [ecx]
    *app->getMemory<float>(cpu.ecx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 005284a9  8b4b18                 -mov ecx, dword ptr [ebx + 0x18]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 005284ac  40                     -inc eax
    (cpu.eax)++;
    // 005284ad  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005284b0  8b7b28                 -mov edi, dword ptr [ebx + 0x28]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */);
    // 005284b3  894b18                 -mov dword ptr [ebx + 0x18], ecx
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 005284b6  39f8                   +cmp eax, edi
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
    // 005284b8  7ce4                   -jl 0x52849e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052849e;
    }
    // 005284ba  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x005284bc:
    // 005284bc  8b4328                 -mov eax, dword ptr [ebx + 0x28]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */);
    // 005284bf  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 005284c1  8b6b20                 -mov ebp, dword ptr [ebx + 0x20]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */);
    // 005284c4  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 005284c6  2b6b24                 -sub ebp, dword ptr [ebx + 0x24]
    (cpu.ebp) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */)));
    // 005284c9  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 005284cb  0f8c7d000000           -jl 0x52854e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052854e;
    }
L_0x005284d1:
    // 005284d1  39ee                   +cmp esi, ebp
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
    // 005284d3  0f8d7c000000           -jge 0x528555
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00528555;
    }
    // 005284d9  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
L_0x005284db:
    // 005284db  8b4324                 -mov eax, dword ptr [ebx + 0x24]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */);
    // 005284de  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 005284e0  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 005284e2  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 005284e5  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 005284e7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 005284e9  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 005284ee  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 005284f1  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 005284f3  8b531c                 -mov edx, dword ptr [ebx + 0x1c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */);
    // 005284f6  893b                   -mov dword ptr [ebx], edi
    *app->getMemory<x86::reg32>(cpu.ebx) = cpu.edi;
    // 005284f8  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 005284fa  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005284fb  895314                 -mov dword ptr [ebx + 0x14], edx
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 005284fe  e88d84fdff             -call 0x500990
    cpu.esp -= 4;
    sub_500990(app, cpu);
    if (cpu.terminate) return;
    // 00528503  8b5324                 -mov edx, dword ptr [ebx + 0x24]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */);
    // 00528506  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00528508  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx);
    // 0052850a  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0052850c  895324                 -mov dword ptr [ebx + 0x24], edx
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 0052850f  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00528511  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00528514  894b24                 -mov dword ptr [ebx + 0x24], ecx
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */) = cpu.ecx;
    // 00528517  39fd                   +cmp ebp, edi
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
    // 00528519  753e                   -jne 0x528559
    if (!cpu.flags.zf)
    {
        goto L_0x00528559;
    }
    // 0052851b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0052851d  29fe                   -sub esi, edi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0052851f  2b4320                 -sub eax, dword ptr [ebx + 0x20]
    (cpu.eax) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */)));
    // 00528522  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00528524  01f6                   -add esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi));
    // 00528526  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00528528  7e1a                   -jle 0x528544
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00528544;
    }
L_0x0052852a:
    // 0052852a  8b4318                 -mov eax, dword ptr [ebx + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 0052852d  c70000000000           -mov dword ptr [eax], 0
    *app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 00528533  8b6b18                 -mov ebp, dword ptr [ebx + 0x18]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 00528536  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00528539  4e                     -dec esi
    (cpu.esi)--;
    // 0052853a  896b18                 -mov dword ptr [ebx + 0x18], ebp
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */) = cpu.ebp;
    // 0052853d  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0052853f  7fe9                   -jg 0x52852a
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0052852a;
    }
    // 00528541  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x00528544:
    // 00528544  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00528549  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052854a  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052854b  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052854c  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052854d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052854e:
    // 0052854e  31ed                   +xor ebp, ebp
    cpu.clear_co();
    cpu.set_szp((cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp))));
    // 00528550  e97cffffff             -jmp 0x5284d1
    goto L_0x005284d1;
L_0x00528555:
    // 00528555  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 00528557  eb82                   -jmp 0x5284db
    goto L_0x005284db;
L_0x00528559:
    // 00528559  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 0052855e  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00528560  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00528562  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00528565  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00528567  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00528569  29d6                   -sub esi, edx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0052856b  6bf6ff                 -imul esi, esi, -1
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(-1 /*-0x1*/)));
    // 0052856e  83fee4                 +cmp esi, -0x1c
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-28 /*-0x1c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00528571  7502                   -jne 0x528575
    if (!cpu.flags.zf)
    {
        goto L_0x00528575;
    }
    // 00528573  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x00528575:
    // 00528575  01f6                   -add esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi));
    // 00528577  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00528579  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0052857b  7c0d                   -jl 0x52858a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052858a;
    }
    // 0052857d  894b28                 -mov dword ptr [ebx + 0x28], ecx
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */) = cpu.ecx;
    // 00528580  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00528585  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528586  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528587  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528588  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528589  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052858a:
    // 0052858a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052858c  8d14b500000000         -lea edx, [esi*4]
    cpu.edx = x86::reg32(cpu.esi * 4);
L_0x00528593:
    // 00528593  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00528596  46                     -inc esi
    (cpu.esi)++;
    // 00528597  8b7b18                 -mov edi, dword ptr [ebx + 0x18]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 0052859a  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052859d  41                     -inc ecx
    (cpu.ecx)++;
    // 0052859e  8b6c3afc               -mov ebp, dword ptr [edx + edi - 4]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */ + cpu.edi * 1);
    // 005285a2  896828                 -mov dword ptr [eax + 0x28], ebp
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */) = cpu.ebp;
    // 005285a5  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 005285a7  7cea                   -jl 0x528593
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00528593;
    }
    // 005285a9  894b28                 -mov dword ptr [ebx + 0x28], ecx
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */) = cpu.ecx;
    // 005285ac  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 005285b1  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005285b2  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005285b3  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005285b4  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005285b5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_5285b8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005285b8  c7422400000000         -mov dword ptr [edx + 0x24], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 005285bf  c7422800000000         -mov dword ptr [edx + 0x28], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
    // 005285c6  c7420400000000         -mov dword ptr [edx + 4], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 005285cd  c7420800000000         -mov dword ptr [edx + 8], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 005285d4  c7420c00000000         -mov dword ptr [edx + 0xc], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 005285db  c7421000000000         -mov dword ptr [edx + 0x10], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 005285e2  895a1c                 -mov dword ptr [edx + 0x1c], ebx
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 005285e5  894a20                 -mov dword ptr [edx + 0x20], ecx
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 005285e8  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 005285ec  c70204845200           -mov dword ptr [edx], 0x528404
    *app->getMemory<x86::reg32>(cpu.edx) = 5407748 /*0x528404*/;
    // 005285f2  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 005285f6  b804010000             -mov eax, 0x104
    cpu.eax = 260 /*0x104*/;
    // 005285fb  c70200845200           -mov dword ptr [edx], 0x528400
    *app->getMemory<x86::reg32>(cpu.edx) = 5407744 /*0x528400*/;
    // 00528601  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_528610(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00528610  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00528611  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00528612  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00528613  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00528616  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00528618  891424                 -mov dword ptr [esp], edx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0052861b  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 0052861d  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0052861f  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx);
    // 00528621  39d8                   +cmp eax, ebx
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
    // 00528623  7d02                   -jge 0x528627
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00528627;
    }
    // 00528625  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x00528627:
    // 00528627  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00528629  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0052862b  7e1f                   -jle 0x52864c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052864c;
    }
    // 0052862d  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
L_0x00528630:
    // 00528630  d901                   -fld dword ptr [ecx]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.ecx)));
    // 00528632  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00528635  83c108                 -add ecx, 8
    (cpu.ecx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00528638  40                     -inc eax
    (cpu.eax)++;
    // 00528639  d95afc                 -fstp dword ptr [edx - 4]
    *app->getMemory<float>(cpu.edx + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052863c  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052863f  8b59fc                 -mov ebx, dword ptr [ecx - 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */);
    // 00528642  895afc                 -mov dword ptr [edx - 4], ebx
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 00528645  39f8                   +cmp eax, edi
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
    // 00528647  7ce7                   -jl 0x528630
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00528630;
    }
    // 00528649  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x0052864c:
    // 0052864c  39f0                   +cmp eax, esi
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
    // 0052864e  7d24                   -jge 0x528674
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00528674;
    }
    // 00528650  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    // 00528653  8d1cc500000000         -lea ebx, [eax*8]
    cpu.ebx = x86::reg32(cpu.eax * 8);
    // 0052865a  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
L_0x0052865c:
    // 0052865c  d903                   -fld dword ptr [ebx]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.ebx)));
    // 0052865e  83c308                 -add ebx, 8
    (cpu.ebx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00528661  40                     -inc eax
    (cpu.eax)++;
    // 00528662  d919                   -fstp dword ptr [ecx]
    *app->getMemory<float>(cpu.ecx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00528664  83c108                 -add ecx, 8
    (cpu.ecx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00528667  d943fc                 -fld dword ptr [ebx - 4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.ebx + x86::reg32(-4) /* -0x4 */)));
    // 0052866a  d959fc                 -fstp dword ptr [ecx - 4]
    *app->getMemory<float>(cpu.ecx + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052866d  39f0                   +cmp eax, esi
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
    // 0052866f  7ceb                   -jl 0x52865c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052865c;
    }
    // 00528671  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x00528674:
    // 00528674  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00528676  895500                 -mov dword ptr [ebp], edx
    *app->getMemory<x86::reg32>(cpu.ebp) = cpu.edx;
    // 00528679  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052867c  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052867d  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052867e  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052867f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_528680(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00528680  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00528681  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00528682  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00528683  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00528684  81ecec000000           -sub esp, 0xec
    (cpu.esp) -= x86::reg32(x86::sreg32(236 /*0xec*/));
    // 0052868a  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0052868c  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0052868e  895818                 -mov dword ptr [eax + 0x18], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 00528691  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00528693  7e5c                   -jle 0x5286f1
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x005286f1;
    }
    // 00528695  8d5018                 -lea edx, [eax + 0x18]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00528698  899424e4000000         -mov dword ptr [esp + 0xe4], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(228) /* 0xe4 */) = cpu.edx;
    // 0052869f  8d6834                 -lea ebp, [eax + 0x34]
    cpu.ebp = x86::reg32(cpu.eax + x86::reg32(52) /* 0x34 */);
L_0x005286a2:
    // 005286a2  66837e3000             +cmp word ptr [esi + 0x30], 0
    {
        x86::reg16 tmp1 = *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(48) /* 0x30 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 005286a7  756b                   -jne 0x528714
    if (!cpu.flags.zf)
    {
        goto L_0x00528714;
    }
    // 005286a9  8b4624                 -mov eax, dword ptr [esi + 0x24]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 005286ac  8b4e2c                 -mov ecx, dword ptr [esi + 0x2c]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */);
    // 005286af  83c01b                 -add eax, 0x1b
    (cpu.eax) += x86::reg32(x86::sreg32(27 /*0x1b*/));
    // 005286b2  39c8                   +cmp eax, ecx
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
    // 005286b4  0f8d7e000000           -jge 0x528738
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00528738;
    }
    // 005286ba  6b56241e               -imul edx, dword ptr [esi + 0x24], 0x1e
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */))) * x86::sreg64(x86::sreg32(30 /*0x1e*/)));
    // 005286be  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 005286c3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 005286c5  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 005286c8  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 005286ca  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 005286cd  c7061c000000           -mov dword ptr [esi], 0x1c
    *app->getMemory<x86::reg32>(cpu.esi) = 28 /*0x1c*/;
    // 005286d3  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 005286d5  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005286d6  895614                 -mov dword ptr [esi + 0x14], edx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 005286d9  e8b282fdff             -call 0x500990
    cpu.esp -= 4;
    sub_500990(app, cpu);
    if (cpu.terminate) return;
    // 005286de  8b4624                 -mov eax, dword ptr [esi + 0x24]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 005286e1  83ef1c                 -sub edi, 0x1c
    (cpu.edi) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 005286e4  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 005286e7  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005286ea  894624                 -mov dword ptr [esi + 0x24], eax
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.eax;
L_0x005286ed:
    // 005286ed  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 005286ef  7fb1                   -jg 0x5286a2
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x005286a2;
    }
L_0x005286f1:
    // 005286f1  8d04fd00000000         -lea eax, [edi*8]
    cpu.eax = x86::reg32(cpu.edi * 8);
    // 005286f8  014618                 -add dword ptr [esi + 0x18], eax
    (*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */)) += x86::reg32(x86::sreg32(cpu.eax));
    // 005286fb  90                     -nop 
    ;
L_0x005286fc:
    // 005286fc  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 005286fe  0f8c73010000           -jl 0x528877
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00528877;
    }
    // 00528704  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00528709  81c4ec000000           -add esp, 0xec
    (cpu.esp) += x86::reg32(x86::sreg32(236 /*0xec*/));
    // 0052870f  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528710  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528711  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528712  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528713  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00528714:
    // 00528714  8b8c24e4000000         -mov ecx, dword ptr [esp + 0xe4]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(228) /* 0xe4 */);
    // 0052871b  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0052871d  8b462e                 -mov eax, dword ptr [esi + 0x2e]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(46) /* 0x2e */);
    // 00528720  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00528722  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00528725  e8e6feffff             -call 0x528610
    cpu.esp -= 4;
    sub_528610(app, cpu);
    if (cpu.terminate) return;
    // 0052872a  668b5e30               -mov bx, word ptr [esi + 0x30]
    cpu.bx = *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(48) /* 0x30 */);
    // 0052872e  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00528730  29c7                   +sub edi, eax
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00528732  66895e30               -mov word ptr [esi + 0x30], bx
    *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(48) /* 0x30 */) = cpu.bx;
    // 00528736  ebb5                   -jmp 0x5286ed
    goto L_0x005286ed;
L_0x00528738:
    // 00528738  6b56241e               -imul edx, dword ptr [esi + 0x24], 0x1e
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */))) * x86::sreg64(x86::sreg32(30 /*0x1e*/)));
    // 0052873c  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0052873f  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 00528744  898424e0000000         -mov dword ptr [esp + 0xe0], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(224) /* 0xe0 */) = cpu.eax;
    // 0052874b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0052874d  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00528750  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00528752  c7061c000000           -mov dword ptr [esi], 0x1c
    *app->getMemory<x86::reg32>(cpu.esi) = 28 /*0x1c*/;
    // 00528758  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0052875b  896e18                 -mov dword ptr [esi + 0x18], ebp
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ebp;
    // 0052875e  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00528760  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00528761  895614                 -mov dword ptr [esi + 0x14], edx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 00528764  e82782fdff             -call 0x500990
    cpu.esp -= 4;
    sub_500990(app, cpu);
    if (cpu.terminate) return;
    // 00528769  8346241c               -add dword ptr [esi + 0x24], 0x1c
    (*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */)) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0052876d  668b5e2c               -mov bx, word ptr [esi + 0x2c]
    cpu.bx = *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(44) /* 0x2c */);
    // 00528771  668b4624               -mov ax, word ptr [esi + 0x24]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 00528775  ba1c000000             -mov edx, 0x1c
    cpu.edx = 28 /*0x1c*/;
    // 0052877a  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0052877c  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0052877e  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00528780  8b4628                 -mov eax, dword ptr [esi + 0x28]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 00528783  66895630               -mov word ptr [esi + 0x30], dx
    *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(48) /* 0x30 */) = cpu.dx;
    // 00528787  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00528789  41                     -inc ecx
    (cpu.ecx)++;
    // 0052878a  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0052878d  66894e30               -mov word ptr [esi + 0x30], cx
    *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(48) /* 0x30 */) = cpu.cx;
    // 00528791  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 00528796  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00528798  0fafc1                 -imul eax, ecx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0052879b  894624                 -mov dword ptr [esi + 0x24], eax
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 0052879e  8b4628                 -mov eax, dword ptr [esi + 0x28]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 005287a1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 005287a3  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 005287a6  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 005287a8  d986ec010000           -fld dword ptr [esi + 0x1ec]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.esi + x86::reg32(492) /* 0x1ec */)));
    // 005287ae  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005287b1  d95e04                 -fstp dword ptr [esi + 4]
    *app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 005287b4  8b86f0010000           -mov eax, dword ptr [esi + 0x1f0]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(496) /* 0x1f0 */);
    // 005287ba  894608                 -mov dword ptr [esi + 8], eax
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 005287bd  8b86f4010000           -mov eax, dword ptr [esi + 0x1f4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(500) /* 0x1f4 */);
    // 005287c3  89460c                 -mov dword ptr [esi + 0xc], eax
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 005287c6  8b86f8010000           -mov eax, dword ptr [esi + 0x1f8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(504) /* 0x1f8 */);
    // 005287cc  894610                 -mov dword ptr [esi + 0x10], eax
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 005287cf  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 005287d1  0f8491000000           -je 0x528868
    if (cpu.flags.zf)
    {
        goto L_0x00528868;
    }
    // 005287d7  890e                   -mov dword ptr [esi], ecx
    *app->getMemory<x86::reg32>(cpu.esi) = cpu.ecx;
    // 005287d9  6b56241e               -imul edx, dword ptr [esi + 0x24], 0x1e
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */))) * x86::sreg64(x86::sreg32(30 /*0x1e*/)));
    // 005287dd  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 005287e2  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 005287e4  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 005287e7  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 005287e9  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 005287ec  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 005287ee  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 005287f0  895614                 -mov dword ptr [esi + 0x14], edx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 005287f3  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005287f4  894618                 -mov dword ptr [esi + 0x18], eax
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 005287f7  e89481fdff             -call 0x500990
    cpu.esp -= 4;
    sub_500990(app, cpu);
    if (cpu.terminate) return;
    // 005287fc  8b5e24                 -mov ebx, dword ptr [esi + 0x24]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 005287ff  83c31c                 -add ebx, 0x1c
    (cpu.ebx) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00528802  8b5628                 -mov edx, dword ptr [esi + 0x28]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 00528805  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00528807  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052880a  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0052880c  ba38000000             -mov edx, 0x38
    cpu.edx = 56 /*0x38*/;
    // 00528811  898424e8000000         -mov dword ptr [esp + 0xe8], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(232) /* 0xe8 */) = cpu.eax;
    // 00528818  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 0052881a  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0052881c  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00528823  895e24                 -mov dword ptr [esi + 0x24], ebx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 00528826  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00528828  8b8c24e8000000         -mov ecx, dword ptr [esp + 0xe8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(232) /* 0xe8 */);
    // 0052882f  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00528831  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00528833  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00528835  7e31                   -jle 0x528868
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00528868;
    }
L_0x00528837:
    // 00528837  8b4e2e                 -mov ecx, dword ptr [esi + 0x2e]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(46) /* 0x2e */);
    // 0052883a  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0052883d  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.eax);
    // 0052883f  895cce34               -mov dword ptr [esi + ecx*8 + 0x34], ebx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */ + cpu.ecx * 8) = cpu.ebx;
    // 00528843  8b4e2e                 -mov ecx, dword ptr [esi + 0x2e]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(46) /* 0x2e */);
    // 00528846  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00528849  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0052884c  8b58fc                 -mov ebx, dword ptr [eax - 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 0052884f  895cce38               -mov dword ptr [esi + ecx*8 + 0x38], ebx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(56) /* 0x38 */ + cpu.ecx * 8) = cpu.ebx;
    // 00528853  668b5e30               -mov bx, word ptr [esi + 0x30]
    cpu.bx = *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(48) /* 0x30 */);
    // 00528857  42                     -inc edx
    (cpu.edx)++;
    // 00528858  43                     -inc ebx
    (cpu.ebx)++;
    // 00528859  8b8c24e8000000         -mov ecx, dword ptr [esp + 0xe8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(232) /* 0xe8 */);
    // 00528860  66895e30               -mov word ptr [esi + 0x30], bx
    *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(48) /* 0x30 */) = cpu.bx;
    // 00528864  39ca                   +cmp edx, ecx
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
    // 00528866  7ccf                   -jl 0x528837
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00528837;
    }
L_0x00528868:
    // 00528868  8b8424e0000000         -mov eax, dword ptr [esp + 0xe0]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(224) /* 0xe0 */);
    // 0052886f  894618                 -mov dword ptr [esi + 0x18], eax
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00528872  e976feffff             -jmp 0x5286ed
    goto L_0x005286ed;
L_0x00528877:
    // 00528877  8b562e                 -mov edx, dword ptr [esi + 0x2e]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(46) /* 0x2e */);
    // 0052887a  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0052887d  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00528880  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax);
    // 00528882  894cd634               -mov dword ptr [esi + edx*8 + 0x34], ecx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */ + cpu.edx * 8) = cpu.ecx;
    // 00528886  8b462e                 -mov eax, dword ptr [esi + 0x2e]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(46) /* 0x2e */);
    // 00528889  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0052888c  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0052888f  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00528892  894cc638               -mov dword ptr [esi + eax*8 + 0x38], ecx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(56) /* 0x38 */ + cpu.eax * 8) = cpu.ecx;
    // 00528896  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00528899  668b4e30               -mov cx, word ptr [esi + 0x30]
    cpu.cx = *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(48) /* 0x30 */);
    // 0052889d  83c208                 +add edx, 8
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
    // 005288a0  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 005288a1  895618                 -mov dword ptr [esi + 0x18], edx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 005288a4  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 005288a5  66894e30               -mov word ptr [esi + 0x30], cx
    *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(48) /* 0x30 */) = cpu.cx;
    // 005288a9  e94efeffff             -jmp 0x5286fc
    goto L_0x005286fc;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_5288b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005288b0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005288b1  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005288b2  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005288b3  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005288b4  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 005288b7  891424                 -mov dword ptr [esp], edx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 005288ba  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    // 005288bd  8b502e                 -mov edx, dword ptr [eax + 0x2e]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(46) /* 0x2e */);
    // 005288c0  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 005288c2  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 005288c5  895818                 -mov dword ptr [eax + 0x18], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 005288c8  39ca                   +cmp edx, ecx
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
    // 005288ca  7d34                   -jge 0x528900
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00528900;
    }
    // 005288cc  bf08000000             -mov edi, 8
    cpu.edi = 8 /*0x8*/;
    // 005288d1  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x005288d3:
    // 005288d3  8b562e                 -mov edx, dword ptr [esi + 0x2e]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(46) /* 0x2e */);
    // 005288d6  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 005288d9  39d3                   +cmp ebx, edx
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
    // 005288db  0f8d8b000000           -jge 0x52896c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0052896c;
    }
    // 005288e1  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 005288e4  8b4834                 -mov ecx, dword ptr [eax + 0x34]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    // 005288e7  890a                   -mov dword ptr [edx], ecx
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 005288e9  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 005288ec  8b4838                 -mov ecx, dword ptr [eax + 0x38]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(56) /* 0x38 */);
    // 005288ef  894a04                 -mov dword ptr [edx + 4], ecx
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 005288f2  8b6e18                 -mov ebp, dword ptr [esi + 0x18]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 005288f5  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 005288f8  01fd                   +add ebp, edi
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 005288fa  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 005288fb  896e18                 -mov dword ptr [esi + 0x18], ebp
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ebp;
    // 005288fe  ebd3                   -jmp 0x5288d3
    goto L_0x005288d3;
L_0x00528900:
    // 00528900  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00528902  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00528904  7e26                   -jle 0x52892c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052892c;
    }
    // 00528906  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
L_0x00528909:
    // 00528909  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0052890c  8b4834                 -mov ecx, dword ptr [eax + 0x34]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    // 0052890f  890a                   -mov dword ptr [edx], ecx
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 00528911  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00528914  8b4838                 -mov ecx, dword ptr [eax + 0x38]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(56) /* 0x38 */);
    // 00528917  894a04                 -mov dword ptr [edx + 4], ecx
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0052891a  8b7e18                 -mov edi, dword ptr [esi + 0x18]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0052891d  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00528920  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00528923  43                     -inc ebx
    (cpu.ebx)++;
    // 00528924  897e18                 -mov dword ptr [esi + 0x18], edi
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 00528927  39eb                   +cmp ebx, ebp
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
    // 00528929  7cde                   -jl 0x528909
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00528909;
    }
    // 0052892b  90                     -nop 
    ;
L_0x0052892c:
    // 0052892c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052892e  8d14dd00000000         -lea edx, [ebx*8]
    cpu.edx = x86::reg32(cpu.ebx * 8);
    // 00528935  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00528937  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
L_0x00528939:
    // 00528939  8b4e2e                 -mov ecx, dword ptr [esi + 0x2e]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(46) /* 0x2e */);
    // 0052893c  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0052893f  39cb                   +cmp ebx, ecx
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
    // 00528941  7d16                   -jge 0x528959
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00528959;
    }
    // 00528943  d94234                 -fld dword ptr [edx + 0x34]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(52) /* 0x34 */)));
    // 00528946  47                     -inc edi
    (cpu.edi)++;
    // 00528947  83c208                 -add edx, 8
    (cpu.edx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0052894a  43                     -inc ebx
    (cpu.ebx)++;
    // 0052894b  d95834                 -fstp dword ptr [eax + 0x34]
    *app->getMemory<float>(cpu.eax + x86::reg32(52) /* 0x34 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052894e  83c008                 +add eax, 8
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
    // 00528951  8b4a30                 -mov ecx, dword ptr [edx + 0x30]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(48) /* 0x30 */);
    // 00528954  894830                 -mov dword ptr [eax + 0x30], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */) = cpu.ecx;
    // 00528957  ebe0                   -jmp 0x528939
    goto L_0x00528939;
L_0x00528959:
    // 00528959  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0052895e  66897e30               -mov word ptr [esi + 0x30], di
    *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(48) /* 0x30 */) = cpu.di;
    // 00528962  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00528964  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00528967  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528968  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528969  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052896a  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052896b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052896c:
    // 0052896c  8b7e28                 -mov edi, dword ptr [esi + 0x28]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 0052896f  8b4624                 -mov eax, dword ptr [esi + 0x24]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 00528972  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    // 00528975  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00528977  29d5                   -sub ebp, edx
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00528979  83ef1b                 -sub edi, 0x1b
    (cpu.edi) -= x86::reg32(x86::sreg32(27 /*0x1b*/));
    // 0052897c  892c24                 -mov dword ptr [esp], ebp
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 0052897f  39ef                   +cmp edi, ebp
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
    // 00528981  7e02                   -jle 0x528985
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00528985;
    }
    // 00528983  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
L_0x00528985:
    // 00528985  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00528987  0f8ccc000000           -jl 0x528a59
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00528a59;
    }
L_0x0052898d:
    // 0052898d  8b4624                 -mov eax, dword ptr [esi + 0x24]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 00528990  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 00528992  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00528994  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00528997  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00528999  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052899b  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 005289a0  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 005289a3  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 005289a5  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 005289a8  893e                   -mov dword ptr [esi], edi
    *app->getMemory<x86::reg32>(cpu.esi) = cpu.edi;
    // 005289aa  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 005289ac  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005289ad  895614                 -mov dword ptr [esi + 0x14], edx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 005289b0  e8db7ffdff             -call 0x500990
    cpu.esp -= 4;
    sub_500990(app, cpu);
    if (cpu.terminate) return;
    // 005289b5  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005289b8  8b4e24                 -mov ecx, dword ptr [esi + 0x24]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 005289bb  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi);
    // 005289bd  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 005289bf  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 005289c1  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 005289c3  894e24                 -mov dword ptr [esi + 0x24], ecx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.ecx;
    // 005289c6  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 005289c8  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi);
    // 005289ca  895e24                 -mov dword ptr [esi + 0x24], ebx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 005289cd  89442404               -mov dword ptr [esp + 4], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 005289d1  8d0cc500000000         -lea ecx, [eax*8]
    cpu.ecx = x86::reg32(cpu.eax * 8);
    // 005289d8  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 005289da  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 005289dc  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 005289de  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x005289e0:
    // 005289e0  0f8c7a000000           -jl 0x528a60
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00528a60;
    }
    // 005289e6  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 005289e9  8b6e18                 -mov ebp, dword ptr [esi + 0x18]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 005289ec  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 005289ee  29d5                   -sub ebp, edx
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.edx));
    // 005289f0  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 005289f3  8b5624                 -mov edx, dword ptr [esi + 0x24]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 005289f6  8b4628                 -mov eax, dword ptr [esi + 0x28]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 005289f9  66895e30               -mov word ptr [esi + 0x30], bx
    *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(48) /* 0x30 */) = cpu.bx;
    // 005289fd  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 005289ff  896e18                 -mov dword ptr [esi + 0x18], ebp
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ebp;
    // 00528a02  83f81c                 +cmp eax, 0x1c
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
    // 00528a05  7d43                   -jge 0x528a4a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00528a4a;
    }
    // 00528a07  d94604                 -fld dword ptr [esi + 4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 00528a0a  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    // 00528a0d  8b86fc010000           -mov eax, dword ptr [esi + 0x1fc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(508) /* 0x1fc */);
    // 00528a13  d99eec010000           -fstp dword ptr [esi + 0x1ec]
    *app->getMemory<float>(cpu.esi + x86::reg32(492) /* 0x1ec */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00528a19  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00528a1c  8996f0010000           -mov dword ptr [esi + 0x1f0], edx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(496) /* 0x1f0 */) = cpu.edx;
    // 00528a22  8b560c                 -mov edx, dword ptr [esi + 0xc]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00528a25  8996f4010000           -mov dword ptr [esi + 0x1f4], edx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(500) /* 0x1f4 */) = cpu.edx;
    // 00528a2b  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00528a2e  8996f8010000           -mov dword ptr [esi + 0x1f8], edx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(504) /* 0x1f8 */) = cpu.edx;
    // 00528a34  c70080865200           -mov dword ptr [eax], 0x528680
    *app->getMemory<x86::reg32>(cpu.eax) = 5408384 /*0x528680*/;
    // 00528a3a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00528a3c  7e0c                   -jle 0x528a4a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00528a4a;
    }
    // 00528a3e  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00528a40  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00528a42  8b5e18                 -mov ebx, dword ptr [esi + 0x18]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00528a45  e836fcffff             -call 0x528680
    cpu.esp -= 4;
    sub_528680(app, cpu);
    if (cpu.terminate) return;
L_0x00528a4a:
    // 00528a4a  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00528a4f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00528a51  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00528a54  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528a55  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528a56  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528a57  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528a58  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00528a59:
    // 00528a59  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 00528a5b  e92dffffff             -jmp 0x52898d
    goto L_0x0052898d;
L_0x00528a60:
    // 00528a60  8b4e18                 -mov ecx, dword ptr [esi + 0x18]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00528a63  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00528a65  894c2408               -mov dword ptr [esp + 8], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 00528a69  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00528a6d  8d0c16                 -lea ecx, [esi + edx]
    cpu.ecx = x86::reg32(cpu.esi + cpu.edx * 1);
    // 00528a70  d94500                 -fld dword ptr [ebp]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.ebp)));
    // 00528a73  d95934                 -fstp dword ptr [ecx + 0x34]
    *app->getMemory<float>(cpu.ecx + x86::reg32(52) /* 0x34 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00528a76  8b6e18                 -mov ebp, dword ptr [esi + 0x18]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00528a79  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 00528a7b  43                     -inc ebx
    (cpu.ebx)++;
    // 00528a7c  83c208                 -add edx, 8
    (cpu.edx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00528a7f  d94504                 -fld dword ptr [ebp + 4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */)));
    // 00528a82  d95938                 -fstp dword ptr [ecx + 0x38]
    *app->getMemory<float>(cpu.ecx + x86::reg32(56) /* 0x38 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00528a85  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00528a89  41                     -inc ecx
    (cpu.ecx)++;
    // 00528a8a  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00528a8d  894c2404               -mov dword ptr [esp + 4], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00528a91  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00528a93  e948ffffff             -jmp 0x5289e0
    goto L_0x005289e0;
}

/* align: skip  */
void Application::sub_528a98(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00528a98  c7422400000000         -mov dword ptr [edx + 0x24], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 00528a9f  66c742300000           -mov word ptr [edx + 0x30], 0
    *app->getMemory<x86::reg16>(cpu.edx + x86::reg32(48) /* 0x30 */) = 0 /*0x0*/;
    // 00528aa5  c7420400000000         -mov dword ptr [edx + 4], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00528aac  c7420800000000         -mov dword ptr [edx + 8], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 00528ab3  c7420c00000000         -mov dword ptr [edx + 0xc], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 00528aba  c7421000000000         -mov dword ptr [edx + 0x10], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 00528ac1  895a1c                 -mov dword ptr [edx + 0x1c], ebx
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 00528ac4  894a20                 -mov dword ptr [edx + 0x20], ecx
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00528ac7  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00528acb  894a28                 -mov dword ptr [edx + 0x28], ecx
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(40) /* 0x28 */) = cpu.ecx;
    // 00528ace  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00528ad2  894a2c                 -mov dword ptr [edx + 0x2c], ecx
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(44) /* 0x2c */) = cpu.ecx;
    // 00528ad5  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00528ad9  898afc010000           -mov dword ptr [edx + 0x1fc], ecx
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(508) /* 0x1fc */) = cpu.ecx;
    // 00528adf  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00528ae3  c701b0885200           -mov dword ptr [ecx], 0x5288b0
    *app->getMemory<x86::reg32>(cpu.ecx) = 5408944 /*0x5288b0*/;
    // 00528ae9  b800020000             -mov eax, 0x200
    cpu.eax = 512 /*0x200*/;
    // 00528aee  c70200000000           -mov dword ptr [edx], 0
    *app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 00528af4  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_528b00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00528b00  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00528b01  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00528b02  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00528b03  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00528b06  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00528b08  8b501c                 -mov edx, dword ptr [eax + 0x1c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00528b0b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00528b0d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00528b0f  0f8490000000           -je 0x528ba5
    if (cpu.flags.zf)
    {
        goto L_0x00528ba5;
    }
    // 00528b15  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00528b16  895818                 -mov dword ptr [eax + 0x18], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 00528b19  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00528b1b  7e67                   -jle 0x528b84
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00528b84;
    }
    // 00528b1d  8d5018                 -lea edx, [eax + 0x18]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00528b20  89542408               -mov dword ptr [esp + 8], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00528b24  8d502c                 -lea edx, [eax + 0x2c]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(44) /* 0x2c */);
    // 00528b27  8954240c               -mov dword ptr [esp + 0xc], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00528b2b  8d5020                 -lea edx, [eax + 0x20]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 00528b2e  89542404               -mov dword ptr [esp + 4], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00528b32  8d681c                 -lea ebp, [eax + 0x1c]
    cpu.ebp = x86::reg32(cpu.eax + x86::reg32(28) /* 0x1c */);
L_0x00528b35:
    // 00528b35  8b5e28                 -mov ebx, dword ptr [esi + 0x28]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 00528b38  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00528b3a  7570                   -jne 0x528bac
    if (!cpu.flags.zf)
    {
        goto L_0x00528bac;
    }
    // 00528b3c  8b4624                 -mov eax, dword ptr [esi + 0x24]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 00528b3f  8b5620                 -mov edx, dword ptr [esi + 0x20]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 00528b42  83c01b                 -add eax, 0x1b
    (cpu.eax) += x86::reg32(x86::sreg32(27 /*0x1b*/));
    // 00528b45  39d0                   +cmp eax, edx
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
    // 00528b47  0f8d7c000000           -jge 0x528bc9
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00528bc9;
    }
    // 00528b4d  6b56241e               -imul edx, dword ptr [esi + 0x24], 0x1e
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */))) * x86::sreg64(x86::sreg32(30 /*0x1e*/)));
    // 00528b51  bb1c000000             -mov ebx, 0x1c
    cpu.ebx = 28 /*0x1c*/;
    // 00528b56  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00528b58  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00528b5b  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00528b5d  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00528b60  c7061c000000           -mov dword ptr [esi], 0x1c
    *app->getMemory<x86::reg32>(cpu.esi) = 28 /*0x1c*/;
    // 00528b66  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00528b68  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00528b69  895614                 -mov dword ptr [esi + 0x14], edx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 00528b6c  e81f7efdff             -call 0x500990
    cpu.esp -= 4;
    sub_500990(app, cpu);
    if (cpu.terminate) return;
    // 00528b71  8b5e24                 -mov ebx, dword ptr [esi + 0x24]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 00528b74  83ef1c                 -sub edi, 0x1c
    (cpu.edi) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00528b77  83c31c                 -add ebx, 0x1c
    (cpu.ebx) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00528b7a  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00528b7d  895e24                 -mov dword ptr [esi + 0x24], ebx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.ebx;
L_0x00528b80:
    // 00528b80  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00528b82  7fb1                   -jg 0x528b35
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00528b35;
    }
L_0x00528b84:
    // 00528b84  8d04fd00000000         -lea eax, [edi*8]
    cpu.eax = x86::reg32(cpu.edi * 8);
    // 00528b8b  014618                 -add dword ptr [esi + 0x18], eax
    (*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */)) += x86::reg32(x86::sreg32(cpu.eax));
    // 00528b8e  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x00528b90:
    // 00528b90  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00528b92  0f8ce3000000           -jl 0x528c7b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00528c7b;
    }
    // 00528b98  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00528b9d  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00528b9e:
    // 00528b9e  83c40c                 +add esp, 0xc
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
    // 00528ba1  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528ba2  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528ba3  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528ba4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00528ba5:
    // 00528ba5  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00528baa  ebf2                   -jmp 0x528b9e
    goto L_0x00528b9e;
L_0x00528bac:
    // 00528bac  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00528bb0  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00528bb4  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00528bb6  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00528bb8  e853faffff             -call 0x528610
    cpu.esp -= 4;
    sub_528610(app, cpu);
    if (cpu.terminate) return;
    // 00528bbd  8b5628                 -mov edx, dword ptr [esi + 0x28]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 00528bc0  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00528bc2  29c7                   +sub edi, eax
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00528bc4  895628                 -mov dword ptr [esi + 0x28], edx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 00528bc7  ebb7                   -jmp 0x528b80
    goto L_0x00528b80;
L_0x00528bc9:
    // 00528bc9  837e1c01               +cmp dword ptr [esi + 0x1c], 1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00528bcd  7445                   -je 0x528c14
    if (cpu.flags.zf)
    {
        goto L_0x00528c14;
    }
    // 00528bcf  6b56241e               -imul edx, dword ptr [esi + 0x24], 0x1e
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */))) * x86::sreg64(x86::sreg32(30 /*0x1e*/)));
    // 00528bd3  bb1c000000             -mov ebx, 0x1c
    cpu.ebx = 28 /*0x1c*/;
    // 00528bd8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00528bda  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00528bdd  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00528bdf  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00528be2  c7061c000000           -mov dword ptr [esi], 0x1c
    *app->getMemory<x86::reg32>(cpu.esi) = 28 /*0x1c*/;
    // 00528be8  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00528bea  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00528beb  895614                 -mov dword ptr [esi + 0x14], edx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 00528bee  e89d7dfdff             -call 0x500990
    cpu.esp -= 4;
    sub_500990(app, cpu);
    if (cpu.terminate) return;
    // 00528bf3  8b4624                 -mov eax, dword ptr [esi + 0x24]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 00528bf6  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00528bf8  8b5620                 -mov edx, dword ptr [esi + 0x20]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 00528bfb  894624                 -mov dword ptr [esi + 0x24], eax
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 00528bfe  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00528c00  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00528c02  8b4e18                 -mov ecx, dword ptr [esi + 0x18]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00528c05  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00528c07  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00528c0a  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00528c0d  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00528c0f  29d7                   -sub edi, edx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00528c11  894e18                 -mov dword ptr [esi + 0x18], ecx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ecx;
L_0x00528c14:
    // 00528c14  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00528c18  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00528c1a  ff15b4785600           -call dword ptr [0x5678b4]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5666996) /* 0x5678b4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00528c20  8b5e1c                 -mov ebx, dword ptr [esi + 0x1c]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00528c23  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00528c25  742e                   -je 0x528c55
    if (cpu.flags.zf)
    {
        goto L_0x00528c55;
    }
    // 00528c27  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00528c29  df00                   -fild word ptr [eax]
    cpu.fpu.push(x86::Float(x86::sreg16(*app->getMemory<x86::reg16>(cpu.eax))));
    // 00528c2b  d95e04                 -fstp dword ptr [esi + 4]
    *app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00528c2e  df4002                 -fild word ptr [eax + 2]
    cpu.fpu.push(x86::Float(x86::sreg16(*app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */))));
    // 00528c31  d95e08                 -fstp dword ptr [esi + 8]
    *app->getMemory<float>(cpu.esi + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00528c34  df4004                 -fild word ptr [eax + 4]
    cpu.fpu.push(x86::Float(x86::sreg16(*app->getMemory<x86::reg16>(cpu.eax + x86::reg32(4) /* 0x4 */))));
    // 00528c37  d95e0c                 -fstp dword ptr [esi + 0xc]
    *app->getMemory<float>(cpu.esi + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00528c3a  df4006                 -fild word ptr [eax + 6]
    cpu.fpu.push(x86::Float(x86::sreg16(*app->getMemory<x86::reg16>(cpu.eax + x86::reg32(6) /* 0x6 */))));
    // 00528c3d  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00528c40  c7462400000000         -mov dword ptr [esi + 0x24], 0
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 00528c47  83c008                 +add eax, 8
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
    // 00528c4a  d95e10                 +fstp dword ptr [esi + 0x10]
    *app->getMemory<float>(cpu.esi + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00528c4d  89461c                 -mov dword ptr [esi + 0x1c], eax
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00528c50  e92bffffff             -jmp 0x528b80
    goto L_0x00528b80;
L_0x00528c55:
    // 00528c55  01ff                   -add edi, edi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edi));
    // 00528c57  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00528c59  0f8e21ffffff           -jle 0x528b80
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00528b80;
    }
L_0x00528c5f:
    // 00528c5f  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00528c62  c70000000000           -mov dword ptr [eax], 0
    *app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 00528c68  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00528c6b  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00528c6e  4f                     -dec edi
    (cpu.edi)--;
    // 00528c6f  894618                 -mov dword ptr [esi + 0x18], eax
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00528c72  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00528c74  7fe9                   -jg 0x528c5f
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00528c5f;
    }
    // 00528c76  e905ffffff             -jmp 0x528b80
    goto L_0x00528b80;
L_0x00528c7b:
    // 00528c7b  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00528c7e  8b4628                 -mov eax, dword ptr [esi + 0x28]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 00528c81  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx);
    // 00528c83  894cc62c               -mov dword ptr [esi + eax*8 + 0x2c], ecx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */ + cpu.eax * 8) = cpu.ecx;
    // 00528c87  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00528c8a  8b4628                 -mov eax, dword ptr [esi + 0x28]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 00528c8d  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00528c90  894cc630               -mov dword ptr [esi + eax*8 + 0x30], ecx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */ + cpu.eax * 8) = cpu.ecx;
    // 00528c94  8b4e18                 -mov ecx, dword ptr [esi + 0x18]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00528c97  8b5e28                 -mov ebx, dword ptr [esi + 0x28]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 00528c9a  83c108                 +add ecx, 8
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
    // 00528c9d  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00528c9e  894e18                 -mov dword ptr [esi + 0x18], ecx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 00528ca1  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00528ca2  895e28                 -mov dword ptr [esi + 0x28], ebx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.ebx;
    // 00528ca5  e9e6feffff             -jmp 0x528b90
    goto L_0x00528b90;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_528cac(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00528cac  c7421c01000000         -mov dword ptr [edx + 0x1c], 1
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */) = 1 /*0x1*/;
    // 00528cb3  c7422400000000         -mov dword ptr [edx + 0x24], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 00528cba  c7422800000000         -mov dword ptr [edx + 0x28], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
    // 00528cc1  c7420400000000         -mov dword ptr [edx + 4], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00528cc8  c7420800000000         -mov dword ptr [edx + 8], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 00528ccf  c7420c00000000         -mov dword ptr [edx + 0xc], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 00528cd6  c7421000000000         -mov dword ptr [edx + 0x10], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 00528cdd  894a20                 -mov dword ptr [edx + 0x20], ecx
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00528ce0  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00528ce4  c702008b5200           -mov dword ptr [edx], 0x528b00
    *app->getMemory<x86::reg32>(cpu.edx) = 5409536 /*0x528b00*/;
    // 00528cea  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00528cee  b804010000             -mov eax, 0x104
    cpu.eax = 260 /*0x104*/;
    // 00528cf3  c70200000000           -mov dword ptr [edx], 0
    *app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 00528cf9  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_528d00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00528d00  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00528d01  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00528d02  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00528d03  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00528d04  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00528d07  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00528d09  89542404               -mov dword ptr [esp + 4], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00528d0d  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00528d0f  8b5030                 -mov edx, dword ptr [eax + 0x30]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */);
    // 00528d12  895818                 -mov dword ptr [eax + 0x18], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 00528d15  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00528d17  754a                   -jne 0x528d63
    if (!cpu.flags.zf)
    {
        goto L_0x00528d63;
    }
L_0x00528d19:
    // 00528d19  8d4518                 -lea eax, [ebp + 0x18]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00528d1c  8d7d34                 -lea edi, [ebp + 0x34]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(52) /* 0x34 */);
    // 00528d1f  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00528d22  8d7520                 -lea esi, [ebp + 0x20]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(32) /* 0x20 */);
L_0x00528d25:
    // 00528d25  837c240400             +cmp dword ptr [esp + 4], 0
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
    // 00528d2a  0f8e70010000           -jle 0x528ea0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00528ea0;
    }
    // 00528d30  8b5d28                 -mov ebx, dword ptr [ebp + 0x28]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */);
    // 00528d33  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00528d35  743d                   -je 0x528d74
    if (cpu.flags.zf)
    {
        goto L_0x00528d74;
    }
    // 00528d37  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    // 00528d3a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00528d3c  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00528d3e  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00528d42  e8c9f8ffff             -call 0x528610
    cpu.esp -= 4;
    sub_528610(app, cpu);
    if (cpu.terminate) return;
    // 00528d47  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00528d4b  8b4d28                 -mov ecx, dword ptr [ebp + 0x28]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */);
    // 00528d4e  8b5530                 -mov edx, dword ptr [ebp + 0x30]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(48) /* 0x30 */);
    // 00528d51  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00528d53  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00528d55  01c2                   +add edx, eax
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
    // 00528d57  894d28                 -mov dword ptr [ebp + 0x28], ecx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */) = cpu.ecx;
    // 00528d5a  895c2404               -mov dword ptr [esp + 4], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00528d5e  895530                 -mov dword ptr [ebp + 0x30], edx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(48) /* 0x30 */) = cpu.edx;
    // 00528d61  ebc2                   -jmp 0x528d25
    goto L_0x00528d25;
L_0x00528d63:
    // 00528d63  8b402c                 -mov eax, dword ptr [eax + 0x2c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */);
    // 00528d66  e82d8cfeff             -call 0x511998
    cpu.esp -= 4;
    sub_511998(app, cpu);
    if (cpu.terminate) return;
    // 00528d6b  c7463000000000         -mov dword ptr [esi + 0x30], 0
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */) = 0 /*0x0*/;
    // 00528d72  eba5                   -jmp 0x528d19
    goto L_0x00528d19;
L_0x00528d74:
    // 00528d74  8b4524                 -mov eax, dword ptr [ebp + 0x24]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */);
    // 00528d77  8b5520                 -mov edx, dword ptr [ebp + 0x20]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 00528d7a  83c01b                 -add eax, 0x1b
    (cpu.eax) += x86::reg32(x86::sreg32(27 /*0x1b*/));
    // 00528d7d  39d0                   +cmp eax, edx
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
    // 00528d7f  7d4a                   -jge 0x528dcb
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00528dcb;
    }
    // 00528d81  6b55241e               -imul edx, dword ptr [ebp + 0x24], 0x1e
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */))) * x86::sreg64(x86::sreg32(30 /*0x1e*/)));
    // 00528d85  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 00528d8a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00528d8c  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00528d8f  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00528d91  8b551c                 -mov edx, dword ptr [ebp + 0x1c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 00528d94  c745001c000000         -mov dword ptr [ebp], 0x1c
    *app->getMemory<x86::reg32>(cpu.ebp) = 28 /*0x1c*/;
    // 00528d9b  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00528d9d  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00528d9e  895514                 -mov dword ptr [ebp + 0x14], edx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 00528da1  e8ea7bfdff             -call 0x500990
    cpu.esp -= 4;
    sub_500990(app, cpu);
    if (cpu.terminate) return;
    // 00528da6  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00528da9  8b5d24                 -mov ebx, dword ptr [ebp + 0x24]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */);
    // 00528dac  8b5530                 -mov edx, dword ptr [ebp + 0x30]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(48) /* 0x30 */);
    // 00528daf  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00528db3  83c31c                 -add ebx, 0x1c
    (cpu.ebx) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00528db6  83c21c                 -add edx, 0x1c
    (cpu.edx) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00528db9  895d24                 -mov dword ptr [ebp + 0x24], ebx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 00528dbc  83e81c                 +sub eax, 0x1c
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(28 /*0x1c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00528dbf  895530                 -mov dword ptr [ebp + 0x30], edx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(48) /* 0x30 */) = cpu.edx;
    // 00528dc2  89442404               -mov dword ptr [esp + 4], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00528dc6  e95affffff             -jmp 0x528d25
    goto L_0x00528d25;
L_0x00528dcb:
    // 00528dcb  837d1c00               +cmp dword ptr [ebp + 0x1c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00528dcf  745a                   -je 0x528e2b
    if (cpu.flags.zf)
    {
        goto L_0x00528e2b;
    }
    // 00528dd1  6b55241e               -imul edx, dword ptr [ebp + 0x24], 0x1e
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */))) * x86::sreg64(x86::sreg32(30 /*0x1e*/)));
    // 00528dd5  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 00528dda  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00528ddc  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00528ddf  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00528de1  8b551c                 -mov edx, dword ptr [ebp + 0x1c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 00528de4  c745001c000000         -mov dword ptr [ebp], 0x1c
    *app->getMemory<x86::reg32>(cpu.ebp) = 28 /*0x1c*/;
    // 00528deb  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00528ded  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00528dee  895514                 -mov dword ptr [ebp + 0x14], edx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 00528df1  e89a7bfdff             -call 0x500990
    cpu.esp -= 4;
    sub_500990(app, cpu);
    if (cpu.terminate) return;
    // 00528df6  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00528df9  8b4524                 -mov eax, dword ptr [ebp + 0x24]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */);
    // 00528dfc  8b5520                 -mov edx, dword ptr [ebp + 0x20]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 00528dff  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00528e02  8b5d18                 -mov ebx, dword ptr [ebp + 0x18]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00528e05  894524                 -mov dword ptr [ebp + 0x24], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 00528e08  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00528e0a  ba1c000000             -mov edx, 0x1c
    cpu.edx = 28 /*0x1c*/;
    // 00528e0f  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00528e13  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00528e15  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00528e18  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00528e1a  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00528e1c  8b4530                 -mov eax, dword ptr [ebp + 0x30]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(48) /* 0x30 */);
    // 00528e1f  895d18                 -mov dword ptr [ebp + 0x18], ebx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 00528e22  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00528e24  894c2404               -mov dword ptr [esp + 4], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00528e28  894530                 -mov dword ptr [ebp + 0x30], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(48) /* 0x30 */) = cpu.eax;
L_0x00528e2b:
    // 00528e2b  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00528e2d  8b452c                 -mov eax, dword ptr [ebp + 0x2c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(44) /* 0x2c */);
    // 00528e30  e8c78afeff             -call 0x5118fc
    cpu.esp -= 4;
    sub_5118fc(app, cpu);
    if (cpu.terminate) return;
    // 00528e35  89451c                 -mov dword ptr [ebp + 0x1c], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00528e38  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00528e3a  742c                   -je 0x528e68
    if (cpu.flags.zf)
    {
        goto L_0x00528e68;
    }
    // 00528e3c  df00                   -fild word ptr [eax]
    cpu.fpu.push(x86::Float(x86::sreg16(*app->getMemory<x86::reg16>(cpu.eax))));
    // 00528e3e  d95d04                 -fstp dword ptr [ebp + 4]
    *app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00528e41  df4002                 -fild word ptr [eax + 2]
    cpu.fpu.push(x86::Float(x86::sreg16(*app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */))));
    // 00528e44  d95d08                 -fstp dword ptr [ebp + 8]
    *app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00528e47  df4004                 -fild word ptr [eax + 4]
    cpu.fpu.push(x86::Float(x86::sreg16(*app->getMemory<x86::reg16>(cpu.eax + x86::reg32(4) /* 0x4 */))));
    // 00528e4a  d95d0c                 -fstp dword ptr [ebp + 0xc]
    *app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00528e4d  df4006                 -fild word ptr [eax + 6]
    cpu.fpu.push(x86::Float(x86::sreg16(*app->getMemory<x86::reg16>(cpu.eax + x86::reg32(6) /* 0x6 */))));
    // 00528e50  8b451c                 -mov eax, dword ptr [ebp + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 00528e53  c7452400000000         -mov dword ptr [ebp + 0x24], 0
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 00528e5a  83c008                 +add eax, 8
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
    // 00528e5d  d95d10                 +fstp dword ptr [ebp + 0x10]
    *app->getMemory<float>(cpu.ebp + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00528e60  89451c                 -mov dword ptr [ebp + 0x1c], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00528e63  e9bdfeffff             -jmp 0x528d25
    goto L_0x00528d25;
L_0x00528e68:
    // 00528e68  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00528e6c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00528e6e  0f8eb1feffff           -jle 0x528d25
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00528d25;
    }
    // 00528e74  837d3000               +cmp dword ptr [ebp + 0x30], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(48) /* 0x30 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00528e78  7411                   -je 0x528e8b
    if (cpu.flags.zf)
    {
        goto L_0x00528e8b;
    }
    // 00528e7a  8d1ccd00000000         -lea ebx, [ecx*8]
    cpu.ebx = x86::reg32(cpu.ecx * 8);
    // 00528e81  8b4518                 -mov eax, dword ptr [ebp + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00528e84  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00528e86  e8b577fbff             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
L_0x00528e8b:
    // 00528e8b  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00528e8f  8b7518                 -mov esi, dword ptr [ebp + 0x18]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00528e92  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00528e95  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00528e97  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00528e99  897c2404               -mov dword ptr [esp + 4], edi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 00528e9d  897518                 -mov dword ptr [ebp + 0x18], esi
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */) = cpu.esi;
L_0x00528ea0:
    // 00528ea0  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00528ea4  8b5518                 -mov edx, dword ptr [ebp + 0x18]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00528ea7  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00528eaa  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00528eac  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00528eb0  895518                 -mov dword ptr [ebp + 0x18], edx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 00528eb3  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00528eb5  7c0b                   -jl 0x528ec2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00528ec2;
    }
    // 00528eb7  8b4530                 -mov eax, dword ptr [ebp + 0x30]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(48) /* 0x30 */);
    // 00528eba  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00528ebd  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528ebe  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528ebf  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528ec0  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528ec1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00528ec2:
    // 00528ec2  6bc1ff                 -imul eax, ecx, -1
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(-1 /*-0x1*/)));
    // 00528ec5  8b7d28                 -mov edi, dword ptr [ebp + 0x28]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */);
    // 00528ec8  89442404               -mov dword ptr [esp + 4], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00528ecc  8d0cc500000000         -lea ecx, [eax*8]
    cpu.ecx = x86::reg32(cpu.eax * 8);
    // 00528ed3  c1e703                 -shl edi, 3
    cpu.edi <<= 3 /*0x3*/ % 32;
    // 00528ed6  8d4534                 -lea eax, [ebp + 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(52) /* 0x34 */);
    // 00528ed9  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00528edb  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00528edd  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00528ede  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00528ee0  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00528ee3  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00528ee5  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00528ee7  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00528eea  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00528eec  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528eed  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00528ef1  8b7528                 -mov esi, dword ptr [ebp + 0x28]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */);
    // 00528ef4  8b7d30                 -mov edi, dword ptr [ebp + 0x30]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(48) /* 0x30 */);
    // 00528ef7  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00528ef9  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00528efb  897528                 -mov dword ptr [ebp + 0x28], esi
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */) = cpu.esi;
    // 00528efe  897d30                 -mov dword ptr [ebp + 0x30], edi
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(48) /* 0x30 */) = cpu.edi;
    // 00528f01  8b4530                 -mov eax, dword ptr [ebp + 0x30]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(48) /* 0x30 */);
    // 00528f04  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00528f07  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528f08  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528f09  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528f0a  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528f0b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_528f0c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00528f0c  e84f420000             -call 0x52d160
    cpu.esp -= 4;
    sub_52d160(app, cpu);
    if (cpu.terminate) return;
    // 00528f11  c7421c00000000         -mov dword ptr [edx + 0x1c], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 00528f18  c7422400000000         -mov dword ptr [edx + 0x24], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 00528f1f  c7422800000000         -mov dword ptr [edx + 0x28], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
    // 00528f26  c7420400000000         -mov dword ptr [edx + 4], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00528f2d  c7420800000000         -mov dword ptr [edx + 8], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 00528f34  c7420c00000000         -mov dword ptr [edx + 0xc], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 00528f3b  c7421000000000         -mov dword ptr [edx + 0x10], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 00528f42  c7423000000000         -mov dword ptr [edx + 0x30], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(48) /* 0x30 */) = 0 /*0x0*/;
    // 00528f49  89422c                 -mov dword ptr [edx + 0x2c], eax
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 00528f4c  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00528f50  894a20                 -mov dword ptr [edx + 0x20], ecx
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00528f53  c700008d5200           -mov dword ptr [eax], 0x528d00
    *app->getMemory<x86::reg32>(cpu.eax) = 5410048 /*0x528d00*/;
    // 00528f59  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00528f5d  c70000000000           -mov dword ptr [eax], 0
    *app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 00528f63  b80c010000             -mov eax, 0x10c
    cpu.eax = 268 /*0x10c*/;
    // 00528f68  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_528f70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00528f70  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00528f73  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_528f74(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00528f74  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00528f75  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00528f76  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00528f77  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00528f78  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00528f7a  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00528f7c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00528f7e  8b5718                 -mov edx, dword ptr [edi + 0x18]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */);
    // 00528f81  8b4f14                 -mov ecx, dword ptr [edi + 0x14]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */);
    // 00528f84  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00528f86  39ca                   +cmp edx, ecx
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
    // 00528f88  7d3c                   -jge 0x528fc6
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00528fc6;
    }
    // 00528f8a  89470c                 -mov dword ptr [edi + 0xc], eax
    *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00528f8d  8b471a                 -mov eax, dword ptr [edi + 0x1a]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(26) /* 0x1a */);
    // 00528f90  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00528f93  39c6                   +cmp esi, eax
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
    // 00528f95  7e39                   -jle 0x528fd0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00528fd0;
    }
    // 00528f97  bd02000000             -mov ebp, 2
    cpu.ebp = 2 /*0x2*/;
    // 00528f9c  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00528f9e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00528fa0:
    // 00528fa0  8b7b1a                 -mov edi, dword ptr [ebx + 0x1a]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(26) /* 0x1a */);
    // 00528fa3  c1ff10                 -sar edi, 0x10
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (16 /*0x10*/ % 32));
    // 00528fa6  39f8                   +cmp eax, edi
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
    // 00528fa8  0f8d79000000           -jge 0x529027
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00529027;
    }
    // 00528fae  8b7b0c                 -mov edi, dword ptr [ebx + 0xc]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 00528fb1  668b4a1e               -mov cx, word ptr [edx + 0x1e]
    cpu.cx = *app->getMemory<x86::reg16>(cpu.edx + x86::reg32(30) /* 0x1e */);
    // 00528fb5  66890f                 -mov word ptr [edi], cx
    *app->getMemory<x86::reg16>(cpu.edi) = cpu.cx;
    // 00528fb8  8b7b0c                 -mov edi, dword ptr [ebx + 0xc]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 00528fbb  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00528fbe  01ef                   +add edi, ebp
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00528fc0  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00528fc1  897b0c                 -mov dword ptr [ebx + 0xc], edi
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 00528fc4  ebda                   -jmp 0x528fa0
    goto L_0x00528fa0;
L_0x00528fc6:
    // 00528fc6  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00528fcb  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528fcc  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528fcd  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528fce  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00528fcf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00528fd0:
    // 00528fd0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00528fd2  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00528fd4  7e1e                   -jle 0x528ff4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00528ff4;
    }
    // 00528fd6  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
L_0x00528fd8:
    // 00528fd8  8b7b0c                 -mov edi, dword ptr [ebx + 0xc]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 00528fdb  668b4a1e               -mov cx, word ptr [edx + 0x1e]
    cpu.cx = *app->getMemory<x86::reg16>(cpu.edx + x86::reg32(30) /* 0x1e */);
    // 00528fdf  66890f                 -mov word ptr [edi], cx
    *app->getMemory<x86::reg16>(cpu.edi) = cpu.cx;
    // 00528fe2  8b4b0c                 -mov ecx, dword ptr [ebx + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 00528fe5  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00528fe8  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00528feb  40                     -inc eax
    (cpu.eax)++;
    // 00528fec  894b0c                 -mov dword ptr [ebx + 0xc], ecx
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00528fef  39f0                   +cmp eax, esi
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
    // 00528ff1  7ce5                   -jl 0x528fd8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00528fd8;
    }
    // 00528ff3  90                     -nop 
    ;
L_0x00528ff4:
    // 00528ff4  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00528ff6  8d3400                 -lea esi, [eax + eax]
    cpu.esi = x86::reg32(cpu.eax + cpu.eax * 1);
    // 00528ff9  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00528ffb  01de                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
L_0x00528ffd:
    // 00528ffd  8b6b1a                 -mov ebp, dword ptr [ebx + 0x1a]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(26) /* 0x1a */);
    // 00529000  c1fd10                 -sar ebp, 0x10
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (16 /*0x10*/ % 32));
    // 00529003  39e8                   +cmp eax, ebp
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
    // 00529005  7d12                   -jge 0x529019
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00529019;
    }
    // 00529007  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0052900a  47                     -inc edi
    (cpu.edi)++;
    // 0052900b  668b4e1e               -mov cx, word ptr [esi + 0x1e]
    cpu.cx = *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(30) /* 0x1e */);
    // 0052900f  83c602                 +add esi, 2
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
    // 00529012  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00529013  66894a1c               -mov word ptr [edx + 0x1c], cx
    *app->getMemory<x86::reg16>(cpu.edx + x86::reg32(28) /* 0x1c */) = cpu.cx;
    // 00529017  ebe4                   -jmp 0x528ffd
    goto L_0x00528ffd;
L_0x00529019:
    // 00529019  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0052901e  66897b1c               -mov word ptr [ebx + 0x1c], di
    *app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(28) /* 0x1c */) = cpu.di;
    // 00529022  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529023  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529024  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529025  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529026  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00529027:
    // 00529027  8b6b14                 -mov ebp, dword ptr [ebx + 0x14]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 0052902a  29fe                   -sub esi, edi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0052902c  2b6b18                 -sub ebp, dword ptr [ebx + 0x18]
    (cpu.ebp) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */)));
    // 0052902f  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00529031  0f8c7f000000           -jl 0x5290b6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005290b6;
    }
L_0x00529037:
    // 00529037  39ee                   +cmp esi, ebp
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
    // 00529039  0f8d7e000000           -jge 0x5290bd
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x005290bd;
    }
    // 0052903f  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
L_0x00529041:
    // 00529041  8b5318                 -mov edx, dword ptr [ebx + 0x18]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 00529044  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0052904b  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0052904d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052904f  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00529052  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00529054  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00529056  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 0052905b  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0052905e  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00529060  8b5310                 -mov edx, dword ptr [ebx + 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 00529063  893b                   -mov dword ptr [ebx], edi
    *app->getMemory<x86::reg32>(cpu.ebx) = cpu.edi;
    // 00529065  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00529067  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00529068  895308                 -mov dword ptr [ebx + 8], edx
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0052906b  e830410000             -call 0x52d1a0
    cpu.esp -= 4;
    sub_52d1a0(app, cpu);
    if (cpu.terminate) return;
    // 00529070  017b18                 -add dword ptr [ebx + 0x18], edi
    (*app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */)) += x86::reg32(x86::sreg32(cpu.edi));
    // 00529073  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx);
    // 00529075  8b5318                 -mov edx, dword ptr [ebx + 0x18]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 00529078  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0052907a  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052907d  895318                 -mov dword ptr [ebx + 0x18], edx
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 00529080  39fd                   +cmp ebp, edi
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
    // 00529082  753d                   -jne 0x5290c1
    if (!cpu.flags.zf)
    {
        goto L_0x005290c1;
    }
    // 00529084  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00529086  8b4b14                 -mov ecx, dword ptr [ebx + 0x14]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 00529089  29fe                   -sub esi, edi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0052908b  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0052908d  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0052908f  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00529091  7e19                   -jle 0x5290ac
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x005290ac;
    }
    // 00529093  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00529095:
    // 00529095  8b430c                 -mov eax, dword ptr [ebx + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 00529098  668910                 -mov word ptr [eax], dx
    *app->getMemory<x86::reg16>(cpu.eax) = cpu.dx;
    // 0052909b  8b6b0c                 -mov ebp, dword ptr [ebx + 0xc]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 0052909e  83c502                 -add ebp, 2
    (cpu.ebp) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 005290a1  4e                     -dec esi
    (cpu.esi)--;
    // 005290a2  896b0c                 -mov dword ptr [ebx + 0xc], ebp
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 005290a5  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 005290a7  7fec                   -jg 0x529095
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00529095;
    }
    // 005290a9  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x005290ac:
    // 005290ac  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 005290b1  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005290b2  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005290b3  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005290b4  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005290b5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005290b6:
    // 005290b6  31ed                   +xor ebp, ebp
    cpu.clear_co();
    cpu.set_szp((cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp))));
    // 005290b8  e97affffff             -jmp 0x529037
    goto L_0x00529037;
L_0x005290bd:
    // 005290bd  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 005290bf  eb80                   -jmp 0x529041
    goto L_0x00529041;
L_0x005290c1:
    // 005290c1  8b3b                   -mov edi, dword ptr [ebx]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebx);
    // 005290c3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005290c5  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 005290c7  7c0e                   -jl 0x5290d7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005290d7;
    }
    // 005290c9  6689431c               -mov word ptr [ebx + 0x1c], ax
    *app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(28) /* 0x1c */) = cpu.ax;
    // 005290cd  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 005290d2  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005290d3  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005290d4  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005290d5  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005290d6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005290d7:
    // 005290d7  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 005290d9  8d343f                 -lea esi, [edi + edi]
    cpu.esi = x86::reg32(cpu.edi + cpu.edi * 1);
L_0x005290dc:
    // 005290dc  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 005290df  8b6b0c                 -mov ebp, dword ptr [ebx + 0xc]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 005290e2  47                     -inc edi
    (cpu.edi)++;
    // 005290e3  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 005290e6  668b4c2efe             -mov cx, word ptr [esi + ebp - 2]
    cpu.cx = *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(-2) /* -0x2 */ + cpu.ebp * 1);
    // 005290eb  40                     -inc eax
    (cpu.eax)++;
    // 005290ec  66894a1c               -mov word ptr [edx + 0x1c], cx
    *app->getMemory<x86::reg16>(cpu.edx + x86::reg32(28) /* 0x1c */) = cpu.cx;
    // 005290f0  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 005290f2  7ce8                   -jl 0x5290dc
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005290dc;
    }
    // 005290f4  6689431c               -mov word ptr [ebx + 0x1c], ax
    *app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(28) /* 0x1c */) = cpu.ax;
    // 005290f8  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 005290fd  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005290fe  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005290ff  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529100  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529101  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_529104(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00529104  c7421800000000         -mov dword ptr [edx + 0x18], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 0052910b  66c7421c0000           -mov word ptr [edx + 0x1c], 0
    *app->getMemory<x86::reg16>(cpu.edx + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 00529111  66c742060000           -mov word ptr [edx + 6], 0
    *app->getMemory<x86::reg16>(cpu.edx + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 00529117  66c742040000           -mov word ptr [edx + 4], 0
    *app->getMemory<x86::reg16>(cpu.edx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0052911d  895a10                 -mov dword ptr [edx + 0x10], ebx
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 00529120  894a14                 -mov dword ptr [edx + 0x14], ecx
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00529123  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00529127  c702748f5200           -mov dword ptr [edx], 0x528f74
    *app->getMemory<x86::reg32>(cpu.edx) = 5410676 /*0x528f74*/;
    // 0052912d  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00529131  b854000000             -mov eax, 0x54
    cpu.eax = 84 /*0x54*/;
    // 00529136  c702708f5200           -mov dword ptr [edx], 0x528f70
    *app->getMemory<x86::reg32>(cpu.edx) = 5410672 /*0x528f70*/;
    // 0052913c  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 */
void Application::sub_529140(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00529140  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00529141  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00529142  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00529143  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00529146  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00529148  89542404               -mov dword ptr [esp + 4], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0052914c  890c24                 -mov dword ptr [esp], ecx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 0052914f  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00529151  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx);
    // 00529153  39d8                   +cmp eax, ebx
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
    // 00529155  7d02                   -jge 0x529159
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00529159;
    }
    // 00529157  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x00529159:
    // 00529159  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0052915b  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0052915d  7e19                   -jle 0x529178
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00529178;
    }
    // 0052915f  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
L_0x00529163:
    // 00529163  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00529166  668b19                 -mov bx, word ptr [ecx]
    cpu.bx = *app->getMemory<x86::reg16>(cpu.ecx);
    // 00529169  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0052916c  40                     -inc eax
    (cpu.eax)++;
    // 0052916d  66895afe               -mov word ptr [edx - 2], bx
    *app->getMemory<x86::reg16>(cpu.edx + x86::reg32(-2) /* -0x2 */) = cpu.bx;
    // 00529171  39f8                   +cmp eax, edi
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
    // 00529173  7cee                   -jl 0x529163
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00529163;
    }
    // 00529175  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x00529178:
    // 00529178  39e8                   +cmp eax, ebp
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
    // 0052917a  7d1c                   -jge 0x529198
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00529198;
    }
    // 0052917c  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00529180  8d1c00                 -lea ebx, [eax + eax]
    cpu.ebx = x86::reg32(cpu.eax + cpu.eax * 1);
    // 00529183  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
L_0x00529185:
    // 00529185  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00529188  668b33                 -mov si, word ptr [ebx]
    cpu.si = *app->getMemory<x86::reg16>(cpu.ebx);
    // 0052918b  83c302                 -add ebx, 2
    (cpu.ebx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0052918e  40                     -inc eax
    (cpu.eax)++;
    // 0052918f  668971fe               -mov word ptr [ecx - 2], si
    *app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(-2) /* -0x2 */) = cpu.si;
    // 00529193  39e8                   +cmp eax, ebp
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
    // 00529195  7cee                   -jl 0x529185
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00529185;
    }
    // 00529197  90                     -nop 
    ;
L_0x00529198:
    // 00529198  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 0052919b  8910                   -mov dword ptr [eax], edx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0052919d  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0052919f  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 005291a2  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005291a3  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005291a4  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005291a5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_5291a8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005291a8  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005291a9  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005291aa  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005291ab  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005291ac  83ec44                 -sub esp, 0x44
    (cpu.esp) -= x86::reg32(x86::sreg32(68 /*0x44*/));
    // 005291af  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 005291b1  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 005291b3  89580c                 -mov dword ptr [eax + 0xc], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 005291b6  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 005291b8  7e55                   -jle 0x52920f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052920f;
    }
    // 005291ba  8d500c                 -lea edx, [eax + 0xc]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(12) /* 0xc */);
    // 005291bd  8954243c               -mov dword ptr [esp + 0x3c], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.edx;
    // 005291c1  8d6826                 -lea ebp, [eax + 0x26]
    cpu.ebp = x86::reg32(cpu.eax + x86::reg32(38) /* 0x26 */);
L_0x005291c4:
    // 005291c4  66837e2400             +cmp word ptr [esi + 0x24], 0
    {
        x86::reg16 tmp1 = *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(36) /* 0x24 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 005291c9  7562                   -jne 0x52922d
    if (!cpu.flags.zf)
    {
        goto L_0x0052922d;
    }
    // 005291cb  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 005291ce  8b4e20                 -mov ecx, dword ptr [esi + 0x20]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 005291d1  83c01b                 -add eax, 0x1b
    (cpu.eax) += x86::reg32(x86::sreg32(27 /*0x1b*/));
    // 005291d4  39c8                   +cmp eax, ecx
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
    // 005291d6  7d76                   -jge 0x52924e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0052924e;
    }
    // 005291d8  6b56180f               -imul edx, dword ptr [esi + 0x18], 0xf
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */))) * x86::sreg64(x86::sreg32(15 /*0xf*/)));
    // 005291dc  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 005291e1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 005291e3  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 005291e6  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 005291e8  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 005291eb  c7061c000000           -mov dword ptr [esi], 0x1c
    *app->getMemory<x86::reg32>(cpu.esi) = 28 /*0x1c*/;
    // 005291f1  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 005291f3  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005291f4  895608                 -mov dword ptr [esi + 8], edx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 005291f7  e8a43f0000             -call 0x52d1a0
    cpu.esp -= 4;
    sub_52d1a0(app, cpu);
    if (cpu.terminate) return;
    // 005291fc  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 005291ff  83ef1c                 -sub edi, 0x1c
    (cpu.edi) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00529202  83c21c                 -add edx, 0x1c
    (cpu.edx) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00529205  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00529208  895618                 -mov dword ptr [esi + 0x18], edx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.edx;
L_0x0052920b:
    // 0052920b  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0052920d  7fb5                   -jg 0x5291c4
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x005291c4;
    }
L_0x0052920f:
    // 0052920f  8d043f                 -lea eax, [edi + edi]
    cpu.eax = x86::reg32(cpu.edi + cpu.edi * 1);
    // 00529212  01460c                 -add dword ptr [esi + 0xc], eax
    (*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */)) += x86::reg32(x86::sreg32(cpu.eax));
    // 00529215  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x00529218:
    // 00529218  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0052921a  0f8c3e010000           -jl 0x52935e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052935e;
    }
    // 00529220  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00529225  83c444                 -add esp, 0x44
    (cpu.esp) += x86::reg32(x86::sreg32(68 /*0x44*/));
    // 00529228  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529229  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052922a  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052922b  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052922c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052922d:
    // 0052922d  8b4c243c               -mov ecx, dword ptr [esp + 0x3c]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00529231  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00529233  8b4622                 -mov eax, dword ptr [esi + 0x22]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(34) /* 0x22 */);
    // 00529236  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00529238  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0052923b  e800ffffff             -call 0x529140
    cpu.esp -= 4;
    sub_529140(app, cpu);
    if (cpu.terminate) return;
    // 00529240  668b5e24               -mov bx, word ptr [esi + 0x24]
    cpu.bx = *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 00529244  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00529246  29c7                   +sub edi, eax
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00529248  66895e24               -mov word ptr [esi + 0x24], bx
    *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.bx;
    // 0052924c  ebbd                   -jmp 0x52920b
    goto L_0x0052920b;
L_0x0052924e:
    // 0052924e  6b56180f               -imul edx, dword ptr [esi + 0x18], 0xf
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */))) * x86::sreg64(x86::sreg32(15 /*0xf*/)));
    // 00529252  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00529255  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 0052925a  89442438               -mov dword ptr [esp + 0x38], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 0052925e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00529260  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00529263  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00529265  c7061c000000           -mov dword ptr [esi], 0x1c
    *app->getMemory<x86::reg32>(cpu.esi) = 28 /*0x1c*/;
    // 0052926b  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0052926e  896e0c                 -mov dword ptr [esi + 0xc], ebp
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 00529271  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00529273  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00529274  895608                 -mov dword ptr [esi + 8], edx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00529277  e8243f0000             -call 0x52d1a0
    cpu.esp -= 4;
    sub_52d1a0(app, cpu);
    if (cpu.terminate) return;
    // 0052927c  8346181c               -add dword ptr [esi + 0x18], 0x1c
    (*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */)) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00529280  668b5e20               -mov bx, word ptr [esi + 0x20]
    cpu.bx = *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 00529284  668b4618               -mov ax, word ptr [esi + 0x18]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00529288  ba1c000000             -mov edx, 0x1c
    cpu.edx = 28 /*0x1c*/;
    // 0052928d  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0052928f  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00529291  668b8694000000         -mov ax, word ptr [esi + 0x94]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(148) /* 0x94 */);
    // 00529298  66895624               -mov word ptr [esi + 0x24], dx
    *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.dx;
    // 0052929c  66894606               -mov word ptr [esi + 6], ax
    *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */) = cpu.ax;
    // 005292a0  668b8696000000         -mov ax, word ptr [esi + 0x96]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(150) /* 0x96 */);
    // 005292a7  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 005292a9  66894604               -mov word ptr [esi + 4], ax
    *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.ax;
    // 005292ad  41                     -inc ecx
    (cpu.ecx)++;
    // 005292ae  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 005292b1  66894e24               -mov word ptr [esi + 0x24], cx
    *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.cx;
    // 005292b5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 005292b7  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 005292bc  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 005292bf  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 005292c1  0fafc1                 -imul eax, ecx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 005292c4  894618                 -mov dword ptr [esi + 0x18], eax
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 005292c7  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 005292ca  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 005292cc  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 005292cf  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 005292d1  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005292d4  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 005292d6  0f8476000000           -je 0x529352
    if (cpu.flags.zf)
    {
        goto L_0x00529352;
    }
    // 005292dc  890e                   -mov dword ptr [esi], ecx
    *app->getMemory<x86::reg32>(cpu.esi) = cpu.ecx;
    // 005292de  6b56180f               -imul edx, dword ptr [esi + 0x18], 0xf
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */))) * x86::sreg64(x86::sreg32(15 /*0xf*/)));
    // 005292e2  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 005292e7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 005292e9  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 005292ec  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 005292ee  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 005292f1  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 005292f3  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 005292f5  895608                 -mov dword ptr [esi + 8], edx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 005292f8  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005292f9  89460c                 -mov dword ptr [esi + 0xc], eax
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 005292fc  e89f3e0000             -call 0x52d1a0
    cpu.esp -= 4;
    sub_52d1a0(app, cpu);
    if (cpu.terminate) return;
    // 00529301  8b5e18                 -mov ebx, dword ptr [esi + 0x18]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00529304  83c31c                 -add ebx, 0x1c
    (cpu.ebx) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00529307  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0052930a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052930c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052930f  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00529311  89442440               -mov dword ptr [esp + 0x40], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = cpu.eax;
    // 00529315  b81c000000             -mov eax, 0x1c
    cpu.eax = 28 /*0x1c*/;
    // 0052931a  8b4c2440               -mov ecx, dword ptr [esp + 0x40]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0052931e  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00529320  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00529322  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 00529324  895e18                 -mov dword ptr [esi + 0x18], ebx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 00529327  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00529329  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0052932b  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0052932d  7e23                   -jle 0x529352
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00529352;
    }
L_0x0052932f:
    // 0052932f  8b4e22                 -mov ecx, dword ptr [esi + 0x22]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(34) /* 0x22 */);
    // 00529332  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00529335  668b18                 -mov bx, word ptr [eax]
    cpu.bx = *app->getMemory<x86::reg16>(cpu.eax);
    // 00529338  66895c4e26             -mov word ptr [esi + ecx*2 + 0x26], bx
    *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(38) /* 0x26 */ + cpu.ecx * 2) = cpu.bx;
    // 0052933d  668b5e24               -mov bx, word ptr [esi + 0x24]
    cpu.bx = *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 00529341  43                     -inc ebx
    (cpu.ebx)++;
    // 00529342  42                     -inc edx
    (cpu.edx)++;
    // 00529343  66895e24               -mov word ptr [esi + 0x24], bx
    *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.bx;
    // 00529347  8b5c2440               -mov ebx, dword ptr [esp + 0x40]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0052934b  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0052934e  39da                   +cmp edx, ebx
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
    // 00529350  7cdd                   -jl 0x52932f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052932f;
    }
L_0x00529352:
    // 00529352  8b442438               -mov eax, dword ptr [esp + 0x38]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 00529356  89460c                 -mov dword ptr [esi + 0xc], eax
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00529359  e9adfeffff             -jmp 0x52920b
    goto L_0x0052920b;
L_0x0052935e:
    // 0052935e  8b4622                 -mov eax, dword ptr [esi + 0x22]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(34) /* 0x22 */);
    // 00529361  8b560c                 -mov edx, dword ptr [esi + 0xc]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00529364  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00529367  668b12                 -mov dx, word ptr [edx]
    cpu.dx = *app->getMemory<x86::reg16>(cpu.edx);
    // 0052936a  6689544626             -mov word ptr [esi + eax*2 + 0x26], dx
    *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(38) /* 0x26 */ + cpu.eax * 2) = cpu.dx;
    // 0052936f  83460c02               +add dword ptr [esi + 0xc], 2
    {
        x86::reg32& tmp1 = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00529373  668b4e24               -mov cx, word ptr [esi + 0x24]
    cpu.cx = *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 00529377  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00529378  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00529379  66894e24               -mov word ptr [esi + 0x24], cx
    *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.cx;
    // 0052937d  e996feffff             -jmp 0x529218
    goto L_0x00529218;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_529384(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00529384  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00529385  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00529386  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00529387  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00529388  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0052938b  891424                 -mov dword ptr [esp], edx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0052938e  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    // 00529391  8b5022                 -mov edx, dword ptr [eax + 0x22]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(34) /* 0x22 */);
    // 00529394  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00529396  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00529399  89580c                 -mov dword ptr [eax + 0xc], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 0052939c  39ca                   +cmp edx, ecx
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
    // 0052939e  7d2d                   -jge 0x5293cd
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x005293cd;
    }
    // 005293a0  bf02000000             -mov edi, 2
    cpu.edi = 2 /*0x2*/;
    // 005293a5  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x005293a7:
    // 005293a7  8b5622                 -mov edx, dword ptr [esi + 0x22]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(34) /* 0x22 */);
    // 005293aa  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 005293ad  39d3                   +cmp ebx, edx
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
    // 005293af  0f8d75000000           -jge 0x52942a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0052942a;
    }
    // 005293b5  8b560c                 -mov edx, dword ptr [esi + 0xc]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 005293b8  668b4826               -mov cx, word ptr [eax + 0x26]
    cpu.cx = *app->getMemory<x86::reg16>(cpu.eax + x86::reg32(38) /* 0x26 */);
    // 005293bc  66890a                 -mov word ptr [edx], cx
    *app->getMemory<x86::reg16>(cpu.edx) = cpu.cx;
    // 005293bf  8b6e0c                 -mov ebp, dword ptr [esi + 0xc]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 005293c2  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 005293c5  01fd                   +add ebp, edi
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 005293c7  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 005293c8  896e0c                 -mov dword ptr [esi + 0xc], ebp
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 005293cb  ebda                   -jmp 0x5293a7
    goto L_0x005293a7;
L_0x005293cd:
    // 005293cd  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 005293cf  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 005293d1  7e21                   -jle 0x5293f4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x005293f4;
    }
    // 005293d3  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
L_0x005293d6:
    // 005293d6  8b560c                 -mov edx, dword ptr [esi + 0xc]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 005293d9  668b4826               -mov cx, word ptr [eax + 0x26]
    cpu.cx = *app->getMemory<x86::reg16>(cpu.eax + x86::reg32(38) /* 0x26 */);
    // 005293dd  66890a                 -mov word ptr [edx], cx
    *app->getMemory<x86::reg16>(cpu.edx) = cpu.cx;
    // 005293e0  8b7e0c                 -mov edi, dword ptr [esi + 0xc]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 005293e3  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 005293e6  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 005293e9  43                     -inc ebx
    (cpu.ebx)++;
    // 005293ea  897e0c                 -mov dword ptr [esi + 0xc], edi
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 005293ed  39eb                   +cmp ebx, ebp
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
    // 005293ef  7ce5                   -jl 0x5293d6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005293d6;
    }
    // 005293f1  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x005293f4:
    // 005293f4  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 005293f6  8d141b                 -lea edx, [ebx + ebx]
    cpu.edx = x86::reg32(cpu.ebx + cpu.ebx * 1);
    // 005293f9  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 005293fb  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
L_0x005293fd:
    // 005293fd  8b6e22                 -mov ebp, dword ptr [esi + 0x22]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(34) /* 0x22 */);
    // 00529400  c1fd10                 -sar ebp, 0x10
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (16 /*0x10*/ % 32));
    // 00529403  39eb                   +cmp ebx, ebp
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
    // 00529405  7d12                   -jge 0x529419
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00529419;
    }
    // 00529407  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0052940a  47                     -inc edi
    (cpu.edi)++;
    // 0052940b  668b4a26               -mov cx, word ptr [edx + 0x26]
    cpu.cx = *app->getMemory<x86::reg16>(cpu.edx + x86::reg32(38) /* 0x26 */);
    // 0052940f  83c202                 +add edx, 2
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00529412  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00529413  66894824               -mov word ptr [eax + 0x24], cx
    *app->getMemory<x86::reg16>(cpu.eax + x86::reg32(36) /* 0x24 */) = cpu.cx;
    // 00529417  ebe4                   -jmp 0x5293fd
    goto L_0x005293fd;
L_0x00529419:
    // 00529419  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0052941e  66897e24               -mov word ptr [esi + 0x24], di
    *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.di;
    // 00529422  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00529425  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529426  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529427  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529428  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529429  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052942a:
    // 0052942a  8b7e1c                 -mov edi, dword ptr [esi + 0x1c]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0052942d  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00529430  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    // 00529433  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00529435  29d5                   -sub ebp, edx
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00529437  83ef1b                 -sub edi, 0x1b
    (cpu.edi) -= x86::reg32(x86::sreg32(27 /*0x1b*/));
    // 0052943a  892c24                 -mov dword ptr [esp], ebp
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 0052943d  39ef                   +cmp edi, ebp
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
    // 0052943f  7e02                   -jle 0x529443
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00529443;
    }
    // 00529441  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
L_0x00529443:
    // 00529443  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00529445  0f8cba000000           -jl 0x529505
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00529505;
    }
L_0x0052944b:
    // 0052944b  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0052944e  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00529455  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00529457  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00529459  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0052945c  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0052945e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00529460  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 00529465  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00529468  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0052946a  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0052946d  893e                   -mov dword ptr [esi], edi
    *app->getMemory<x86::reg32>(cpu.esi) = cpu.edi;
    // 0052946f  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00529471  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00529472  895608                 -mov dword ptr [esi + 8], edx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00529475  e8263d0000             -call 0x52d1a0
    cpu.esp -= 4;
    sub_52d1a0(app, cpu);
    if (cpu.terminate) return;
    // 0052947a  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052947d  8b4e18                 -mov ecx, dword ptr [esi + 0x18]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00529480  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi);
    // 00529482  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00529484  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00529486  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00529488  894e18                 -mov dword ptr [esi + 0x18], ecx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 0052948b  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0052948d  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi);
    // 0052948f  895e18                 -mov dword ptr [esi + 0x18], ebx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 00529492  89442404               -mov dword ptr [esp + 4], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00529496  8d0c00                 -lea ecx, [eax + eax]
    cpu.ecx = x86::reg32(cpu.eax + cpu.eax * 1);
    // 00529499  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0052949b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0052949d  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0052949f  90                     -nop 
    ;
L_0x005294a0:
    // 005294a0  7c6a                   -jl 0x52950c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052950c;
    }
    // 005294a2  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 005294a5  8b6e0c                 -mov ebp, dword ptr [esi + 0xc]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 005294a8  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 005294aa  29d5                   -sub ebp, edx
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.edx));
    // 005294ac  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 005294af  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 005294b2  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 005294b5  66895e24               -mov word ptr [esi + 0x24], bx
    *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.bx;
    // 005294b9  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 005294bb  896e0c                 -mov dword ptr [esi + 0xc], ebp
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 005294be  83f81c                 +cmp eax, 0x1c
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
    // 005294c1  7d35                   -jge 0x5294f8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x005294f8;
    }
    // 005294c3  668b4606               -mov ax, word ptr [esi + 6]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 005294c7  66898694000000         -mov word ptr [esi + 0x94], ax
    *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(148) /* 0x94 */) = cpu.ax;
    // 005294ce  668b4604               -mov ax, word ptr [esi + 4]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 005294d2  66898696000000         -mov word ptr [esi + 0x96], ax
    *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(150) /* 0x96 */) = cpu.ax;
    // 005294d9  8b8698000000           -mov eax, dword ptr [esi + 0x98]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(152) /* 0x98 */);
    // 005294df  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    // 005294e2  c700a8915200           -mov dword ptr [eax], 0x5291a8
    *app->getMemory<x86::reg32>(cpu.eax) = 5411240 /*0x5291a8*/;
    // 005294e8  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 005294ea  7e0c                   -jle 0x5294f8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x005294f8;
    }
    // 005294ec  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 005294ee  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 005294f0  8b5e0c                 -mov ebx, dword ptr [esi + 0xc]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 005294f3  e8b0fcffff             -call 0x5291a8
    cpu.esp -= 4;
    sub_5291a8(app, cpu);
    if (cpu.terminate) return;
L_0x005294f8:
    // 005294f8  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 005294fd  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00529500  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529501  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529502  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529503  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529504  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00529505:
    // 00529505  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 00529507  e93fffffff             -jmp 0x52944b
    goto L_0x0052944b;
L_0x0052950c:
    // 0052950c  8b4e0c                 -mov ecx, dword ptr [esi + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0052950f  8d2c16                 -lea ebp, [esi + edx]
    cpu.ebp = x86::reg32(cpu.esi + cpu.edx * 1);
    // 00529512  668b0c01               -mov cx, word ptr [ecx + eax]
    cpu.cx = *app->getMemory<x86::reg16>(cpu.ecx + cpu.eax * 1);
    // 00529516  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00529519  66894d26               -mov word ptr [ebp + 0x26], cx
    *app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(38) /* 0x26 */) = cpu.cx;
    // 0052951d  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00529521  43                     -inc ebx
    (cpu.ebx)++;
    // 00529522  41                     -inc ecx
    (cpu.ecx)++;
    // 00529523  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00529526  894c2404               -mov dword ptr [esp + 4], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0052952a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052952c  e96fffffff             -jmp 0x5294a0
    goto L_0x005294a0;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_529534(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00529534  c7421800000000         -mov dword ptr [edx + 0x18], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 0052953b  66c742240000           -mov word ptr [edx + 0x24], 0
    *app->getMemory<x86::reg16>(cpu.edx + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 00529541  66c742060000           -mov word ptr [edx + 6], 0
    *app->getMemory<x86::reg16>(cpu.edx + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 00529547  66c742040000           -mov word ptr [edx + 4], 0
    *app->getMemory<x86::reg16>(cpu.edx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0052954d  895a10                 -mov dword ptr [edx + 0x10], ebx
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 00529550  894a14                 -mov dword ptr [edx + 0x14], ecx
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00529553  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00529557  894a1c                 -mov dword ptr [edx + 0x1c], ecx
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 0052955a  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052955e  894a20                 -mov dword ptr [edx + 0x20], ecx
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00529561  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00529565  898a98000000           -mov dword ptr [edx + 0x98], ecx
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(152) /* 0x98 */) = cpu.ecx;
    // 0052956b  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0052956f  c70184935200           -mov dword ptr [ecx], 0x529384
    *app->getMemory<x86::reg32>(cpu.ecx) = 5411716 /*0x529384*/;
    // 00529575  b89c000000             -mov eax, 0x9c
    cpu.eax = 156 /*0x9c*/;
    // 0052957a  c70200000000           -mov dword ptr [edx], 0
    *app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 00529580  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_529590(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00529590  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00529591  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00529592  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00529593  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00529596  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00529598  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0052959b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0052959d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0052959f  0f84cc000000           -je 0x529671
    if (cpu.flags.zf)
    {
        goto L_0x00529671;
    }
    // 005295a5  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005295a6  89580c                 -mov dword ptr [eax + 0xc], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 005295a9  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 005295ab  0f8ea2000000           -jle 0x529653
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00529653;
    }
    // 005295b1  8d680c                 -lea ebp, [eax + 0xc]
    cpu.ebp = x86::reg32(cpu.eax + x86::reg32(12) /* 0xc */);
    // 005295b4  8d501e                 -lea edx, [eax + 0x1e]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(30) /* 0x1e */);
    // 005295b7  8954240c               -mov dword ptr [esp + 0xc], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 005295bb  8d5014                 -lea edx, [eax + 0x14]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 005295be  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 005295c1  89542408               -mov dword ptr [esp + 8], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 005295c5  89442404               -mov dword ptr [esp + 4], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x005295c9:
    // 005295c9  66837e1c00             +cmp word ptr [esi + 0x1c], 0
    {
        x86::reg16 tmp1 = *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(28) /* 0x1c */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 005295ce  0f85a9000000           -jne 0x52967d
    if (!cpu.flags.zf)
    {
        goto L_0x0052967d;
    }
    // 005295d4  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 005295d7  8b4e14                 -mov ecx, dword ptr [esi + 0x14]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 005295da  83c01b                 -add eax, 0x1b
    (cpu.eax) += x86::reg32(x86::sreg32(27 /*0x1b*/));
    // 005295dd  39c8                   +cmp eax, ecx
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
    // 005295df  0f8dbf000000           -jge 0x5296a4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x005296a4;
    }
    // 005295e5  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 005295e7  2b5618                 -sub edx, dword ptr [esi + 0x18]
    (cpu.edx) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */)));
    // 005295ea  bb1c000000             -mov ebx, 0x1c
    cpu.ebx = 28 /*0x1c*/;
    // 005295ef  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 005295f1  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 005295f4  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 005295f6  89442410               -mov dword ptr [esp + 0x10], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 005295fa  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 005295fd  89442410               -mov dword ptr [esp + 0x10], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00529601  39c7                   +cmp edi, eax
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
    // 00529603  7d11                   -jge 0x529616
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00529616;
    }
    // 00529605  8d571b                 -lea edx, [edi + 0x1b]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(27) /* 0x1b */);
    // 00529608  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0052960a  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0052960d  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0052960f  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 00529612  89442410               -mov dword ptr [esp + 0x10], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
L_0x00529616:
    // 00529616  6b56180f               -imul edx, dword ptr [esi + 0x18], 0xf
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */))) * x86::sreg64(x86::sreg32(15 /*0xf*/)));
    // 0052961a  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0052961e  8906                   -mov dword ptr [esi], eax
    *app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 00529620  bb1c000000             -mov ebx, 0x1c
    cpu.ebx = 28 /*0x1c*/;
    // 00529625  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00529627  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0052962a  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0052962c  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0052962f  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00529631  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00529632  895608                 -mov dword ptr [esi + 8], edx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00529635  e8663b0000             -call 0x52d1a0
    cpu.esp -= 4;
    sub_52d1a0(app, cpu);
    if (cpu.terminate) return;
    // 0052963a  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052963d  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00529640  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00529644  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00529646  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00529648  895618                 -mov dword ptr [esi + 0x18], edx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.edx;
L_0x0052964b:
    // 0052964b  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0052964d  0f8f76ffffff           -jg 0x5295c9
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x005295c9;
    }
L_0x00529653:
    // 00529653  8d043f                 -lea eax, [edi + edi]
    cpu.eax = x86::reg32(cpu.edi + cpu.edi * 1);
    // 00529656  01460c                 -add dword ptr [esi + 0xc], eax
    (*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */)) += x86::reg32(x86::sreg32(cpu.eax));
    // 00529659  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x0052965c:
    // 0052965c  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0052965e  0f8ceb000000           -jl 0x52974f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052974f;
    }
    // 00529664  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00529669  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052966a  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0052966d  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052966e  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052966f  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529670  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00529671:
    // 00529671  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00529676  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00529679  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052967a  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052967b  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052967c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052967d:
    // 0052967d  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00529681  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 00529683  8b461a                 -mov eax, dword ptr [esi + 0x1a]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(26) /* 0x1a */);
    // 00529686  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00529688  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0052968b  e8b0faffff             -call 0x529140
    cpu.esp -= 4;
    sub_529140(app, cpu);
    if (cpu.terminate) return;
    // 00529690  89442410               -mov dword ptr [esp + 0x10], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00529694  668b5e1c               -mov bx, word ptr [esi + 0x1c]
    cpu.bx = *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00529698  2b5c2410               -sub ebx, dword ptr [esp + 0x10]
    (cpu.ebx) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 0052969c  29c7                   +sub edi, eax
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0052969e  66895e1c               -mov word ptr [esi + 0x1c], bx
    *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.bx;
    // 005296a2  eba7                   -jmp 0x52964b
    goto L_0x0052964b;
L_0x005296a4:
    // 005296a4  837e1001               +cmp dword ptr [esi + 0x10], 1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005296a8  744f                   -je 0x5296f9
    if (cpu.flags.zf)
    {
        goto L_0x005296f9;
    }
    // 005296aa  3b4e18                 +cmp ecx, dword ptr [esi + 0x18]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005296ad  7e4a                   -jle 0x5296f9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x005296f9;
    }
    // 005296af  6b56180f               -imul edx, dword ptr [esi + 0x18], 0xf
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */))) * x86::sreg64(x86::sreg32(15 /*0xf*/)));
    // 005296b3  bb1c000000             -mov ebx, 0x1c
    cpu.ebx = 28 /*0x1c*/;
    // 005296b8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 005296ba  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 005296bd  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 005296bf  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 005296c2  c7061c000000           -mov dword ptr [esi], 0x1c
    *app->getMemory<x86::reg32>(cpu.esi) = 28 /*0x1c*/;
    // 005296c8  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 005296ca  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005296cb  895608                 -mov dword ptr [esi + 8], edx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 005296ce  e8cd3a0000             -call 0x52d1a0
    cpu.esp -= 4;
    sub_52d1a0(app, cpu);
    if (cpu.terminate) return;
    // 005296d3  8b5e18                 -mov ebx, dword ptr [esi + 0x18]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 005296d6  83c31c                 -add ebx, 0x1c
    (cpu.ebx) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 005296d9  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 005296dc  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 005296de  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005296e1  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 005296e3  b81c000000             -mov eax, 0x1c
    cpu.eax = 28 /*0x1c*/;
    // 005296e8  8b4e0c                 -mov ecx, dword ptr [esi + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 005296eb  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 005296ed  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 005296ef  895e18                 -mov dword ptr [esi + 0x18], ebx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 005296f2  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 005296f4  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 005296f6  894e0c                 -mov dword ptr [esi + 0xc], ecx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.ecx;
L_0x005296f9:
    // 005296f9  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 005296fd  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00529701  ff15b4785600           -call dword ptr [0x5678b4]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5666996) /* 0x5678b4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00529707  8b5e10                 -mov ebx, dword ptr [esi + 0x10]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0052970a  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0052970c  7424                   -je 0x529732
    if (cpu.flags.zf)
    {
        goto L_0x00529732;
    }
    // 0052970e  668b13                 -mov dx, word ptr [ebx]
    cpu.dx = *app->getMemory<x86::reg16>(cpu.ebx);
    // 00529711  66895606               -mov word ptr [esi + 6], dx
    *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */) = cpu.dx;
    // 00529715  668b4302               -mov ax, word ptr [ebx + 2]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 00529719  66894604               -mov word ptr [esi + 4], ax
    *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.ax;
    // 0052971d  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00529720  c7461800000000         -mov dword ptr [esi + 0x18], 0
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 00529727  83c008                 +add eax, 8
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
    // 0052972a  894610                 -mov dword ptr [esi + 0x10], eax
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0052972d  e919ffffff             -jmp 0x52964b
    goto L_0x0052964b;
L_0x00529732:
    // 00529732  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00529735  01ff                   -add edi, edi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edi));
    // 00529737  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00529739  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0052973b  e8006ffbff             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 00529740  8b560c                 -mov edx, dword ptr [esi + 0xc]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00529743  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00529745  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 00529747  89560c                 -mov dword ptr [esi + 0xc], edx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0052974a  e904ffffff             -jmp 0x529653
    goto L_0x00529653;
L_0x0052974f:
    // 0052974f  8b461a                 -mov eax, dword ptr [esi + 0x1a]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(26) /* 0x1a */);
    // 00529752  8b560c                 -mov edx, dword ptr [esi + 0xc]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00529755  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00529758  668b12                 -mov dx, word ptr [edx]
    cpu.dx = *app->getMemory<x86::reg16>(cpu.edx);
    // 0052975b  668954461e             -mov word ptr [esi + eax*2 + 0x1e], dx
    *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(30) /* 0x1e */ + cpu.eax * 2) = cpu.dx;
    // 00529760  8b5e0c                 -mov ebx, dword ptr [esi + 0xc]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00529763  668b4e1c               -mov cx, word ptr [esi + 0x1c]
    cpu.cx = *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00529767  83c302                 +add ebx, 2
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0052976a  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0052976b  895e0c                 -mov dword ptr [esi + 0xc], ebx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 0052976e  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0052976f  66894e1c               -mov word ptr [esi + 0x1c], cx
    *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.cx;
    // 00529773  e9e4feffff             -jmp 0x52965c
    goto L_0x0052965c;
}

/* align: skip  */
void Application::sub_529778(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00529778  c7421001000000         -mov dword ptr [edx + 0x10], 1
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */) = 1 /*0x1*/;
    // 0052977f  c7421800000000         -mov dword ptr [edx + 0x18], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 00529786  66c7421c0000           -mov word ptr [edx + 0x1c], 0
    *app->getMemory<x86::reg16>(cpu.edx + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 0052978c  66c742060000           -mov word ptr [edx + 6], 0
    *app->getMemory<x86::reg16>(cpu.edx + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 00529792  66c742040000           -mov word ptr [edx + 4], 0
    *app->getMemory<x86::reg16>(cpu.edx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00529798  894a14                 -mov dword ptr [edx + 0x14], ecx
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 0052979b  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0052979f  c70290955200           -mov dword ptr [edx], 0x529590
    *app->getMemory<x86::reg32>(cpu.edx) = 5412240 /*0x529590*/;
    // 005297a5  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 005297a9  b854000000             -mov eax, 0x54
    cpu.eax = 84 /*0x54*/;
    // 005297ae  c70200000000           -mov dword ptr [edx], 0
    *app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 005297b4  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_5297c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005297c0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005297c1  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005297c2  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005297c3  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005297c4  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 005297c7  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 005297c9  89542408               -mov dword ptr [esp + 8], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 005297cd  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 005297cf  8b5020                 -mov edx, dword ptr [eax + 0x20]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 005297d2  89580c                 -mov dword ptr [eax + 0xc], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 005297d5  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 005297d7  7556                   -jne 0x52982f
    if (!cpu.flags.zf)
    {
        goto L_0x0052982f;
    }
L_0x005297d9:
    // 005297d9  8d450c                 -lea eax, [ebp + 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 005297dc  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 005297df  8d4526                 -lea eax, [ebp + 0x26]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(38) /* 0x26 */);
    // 005297e2  89442404               -mov dword ptr [esp + 4], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 005297e6  8d7d14                 -lea edi, [ebp + 0x14]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(20) /* 0x14 */);
L_0x005297e9:
    // 005297e9  837c240800             +cmp dword ptr [esp + 8], 0
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
    // 005297ee  0f8e91010000           -jle 0x529985
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00529985;
    }
    // 005297f4  66837d2400             +cmp word ptr [ebp + 0x24], 0
    {
        x86::reg16 tmp1 = *app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(36) /* 0x24 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 005297f9  7445                   -je 0x529840
    if (cpu.flags.zf)
    {
        goto L_0x00529840;
    }
    // 005297fb  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    // 005297fe  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00529802  8b4522                 -mov eax, dword ptr [ebp + 0x22]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(34) /* 0x22 */);
    // 00529805  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00529809  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0052980c  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00529810  e82bf9ffff             -call 0x529140
    cpu.esp -= 4;
    sub_529140(app, cpu);
    if (cpu.terminate) return;
    // 00529815  668b4d24               -mov cx, word ptr [ebp + 0x24]
    cpu.cx = *app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(36) /* 0x24 */);
    // 00529819  8b5520                 -mov edx, dword ptr [ebp + 0x20]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 0052981c  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0052981e  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00529820  01c2                   +add edx, eax
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
    // 00529822  66894d24               -mov word ptr [ebp + 0x24], cx
    *app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(36) /* 0x24 */) = cpu.cx;
    // 00529826  89742408               -mov dword ptr [esp + 8], esi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 0052982a  895520                 -mov dword ptr [ebp + 0x20], edx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 0052982d  ebba                   -jmp 0x5297e9
    goto L_0x005297e9;
L_0x0052982f:
    // 0052982f  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00529832  e86181feff             -call 0x511998
    cpu.esp -= 4;
    sub_511998(app, cpu);
    if (cpu.terminate) return;
    // 00529837  c7462000000000         -mov dword ptr [esi + 0x20], 0
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 0052983e  eb99                   -jmp 0x5297d9
    goto L_0x005297d9;
L_0x00529840:
    // 00529840  8b4518                 -mov eax, dword ptr [ebp + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00529843  8b5d14                 -mov ebx, dword ptr [ebp + 0x14]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00529846  83c01b                 -add eax, 0x1b
    (cpu.eax) += x86::reg32(x86::sreg32(27 /*0x1b*/));
    // 00529849  39d8                   +cmp eax, ebx
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
    // 0052984b  7d70                   -jge 0x5298bd
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x005298bd;
    }
    // 0052984d  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0052984f  2b5518                 -sub edx, dword ptr [ebp + 0x18]
    (cpu.edx) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */)));
    // 00529852  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 00529857  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00529859  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0052985c  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0052985e  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00529860  0faff1                 -imul esi, ecx
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 00529863  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00529867  39de                   +cmp esi, ebx
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
    // 00529869  7f43                   -jg 0x5298ae
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x005298ae;
    }
L_0x0052986b:
    // 0052986b  6b55180f               -imul edx, dword ptr [ebp + 0x18], 0xf
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */))) * x86::sreg64(x86::sreg32(15 /*0xf*/)));
    // 0052986f  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 00529874  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00529876  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00529879  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0052987b  8b5510                 -mov edx, dword ptr [ebp + 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0052987e  897500                 -mov dword ptr [ebp], esi
    *app->getMemory<x86::reg32>(cpu.ebp) = cpu.esi;
    // 00529881  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00529883  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00529884  895508                 -mov dword ptr [ebp + 8], edx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00529887  e814390000             -call 0x52d1a0
    cpu.esp -= 4;
    sub_52d1a0(app, cpu);
    if (cpu.terminate) return;
    // 0052988c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052988f  8b5518                 -mov edx, dword ptr [ebp + 0x18]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00529892  8b5d20                 -mov ebx, dword ptr [ebp + 0x20]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 00529895  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00529899  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0052989b  01f3                   -add ebx, esi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0052989d  895518                 -mov dword ptr [ebp + 0x18], edx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 005298a0  29f1                   +sub ecx, esi
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 005298a2  895d20                 -mov dword ptr [ebp + 0x20], ebx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 005298a5  894c2408               -mov dword ptr [esp + 8], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 005298a9  e93bffffff             -jmp 0x5297e9
    goto L_0x005297e9;
L_0x005298ae:
    // 005298ae  8d531b                 -lea edx, [ebx + 0x1b]
    cpu.edx = x86::reg32(cpu.ebx + x86::reg32(27) /* 0x1b */);
    // 005298b1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 005298b3  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 005298b6  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 005298b8  6bf01c                 +imul esi, eax, 0x1c
    {
        x86::sreg64 tmp = x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(28 /*0x1c*/));
        cpu.esi = static_cast<x86::reg32>(static_cast<x86::sreg32>(tmp));
        cpu.flags.of = cpu.flags.cf = (tmp != x86::sreg64(x86::sreg32(cpu.esi)));
    }
    // 005298bb  ebae                   -jmp 0x52986b
    goto L_0x0052986b;
L_0x005298bd:
    // 005298bd  3b5d18                 +cmp ebx, dword ptr [ebp + 0x18]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005298c0  7e5b                   -jle 0x52991d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052991d;
    }
    // 005298c2  6b55180f               -imul edx, dword ptr [ebp + 0x18], 0xf
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */))) * x86::sreg64(x86::sreg32(15 /*0xf*/)));
    // 005298c6  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 005298cb  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 005298cd  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 005298d0  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 005298d2  8b5510                 -mov edx, dword ptr [ebp + 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 005298d5  c745001c000000         -mov dword ptr [ebp], 0x1c
    *app->getMemory<x86::reg32>(cpu.ebp) = 28 /*0x1c*/;
    // 005298dc  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 005298de  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005298df  895508                 -mov dword ptr [ebp + 8], edx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 005298e2  e8b9380000             -call 0x52d1a0
    cpu.esp -= 4;
    sub_52d1a0(app, cpu);
    if (cpu.terminate) return;
    // 005298e7  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005298ea  8b5518                 -mov edx, dword ptr [ebp + 0x18]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 005298ed  8b4d14                 -mov ecx, dword ptr [ebp + 0x14]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 005298f0  83c21c                 -add edx, 0x1c
    (cpu.edx) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 005298f3  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 005298f6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 005298f8  895518                 -mov dword ptr [ebp + 0x18], edx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 005298fb  ba1c000000             -mov edx, 0x1c
    cpu.edx = 28 /*0x1c*/;
    // 00529900  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00529902  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00529906  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00529908  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 0052990a  29d3                   -sub ebx, edx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0052990c  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0052990e  8b4520                 -mov eax, dword ptr [ebp + 0x20]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 00529911  89750c                 -mov dword ptr [ebp + 0xc], esi
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 00529914  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00529916  895c2408               -mov dword ptr [esp + 8], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 0052991a  894520                 -mov dword ptr [ebp + 0x20], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */) = cpu.eax;
L_0x0052991d:
    // 0052991d  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0052991f  8b451c                 -mov eax, dword ptr [ebp + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 00529922  e8d57ffeff             -call 0x5118fc
    cpu.esp -= 4;
    sub_5118fc(app, cpu);
    if (cpu.terminate) return;
    // 00529927  894510                 -mov dword ptr [ebp + 0x10], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0052992a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052992c  7424                   -je 0x529952
    if (cpu.flags.zf)
    {
        goto L_0x00529952;
    }
    // 0052992e  668b10                 -mov dx, word ptr [eax]
    cpu.dx = *app->getMemory<x86::reg16>(cpu.eax);
    // 00529931  66895506               -mov word ptr [ebp + 6], dx
    *app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(6) /* 0x6 */) = cpu.dx;
    // 00529935  668b4002               -mov ax, word ptr [eax + 2]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00529939  66894504               -mov word ptr [ebp + 4], ax
    *app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(4) /* 0x4 */) = cpu.ax;
    // 0052993d  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00529940  c7451800000000         -mov dword ptr [ebp + 0x18], 0
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 00529947  83c008                 +add eax, 8
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
    // 0052994a  894510                 -mov dword ptr [ebp + 0x10], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0052994d  e997feffff             -jmp 0x5297e9
    goto L_0x005297e9;
L_0x00529952:
    // 00529952  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00529956  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00529958  0f8e8bfeffff           -jle 0x5297e9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x005297e9;
    }
    // 0052995e  837d2000               +cmp dword ptr [ebp + 0x20], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00529962  740d                   -je 0x529971
    if (cpu.flags.zf)
    {
        goto L_0x00529971;
    }
    // 00529964  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00529967  8d1c09                 -lea ebx, [ecx + ecx]
    cpu.ebx = x86::reg32(cpu.ecx + cpu.ecx * 1);
    // 0052996a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0052996c  e8cf6cfbff             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
L_0x00529971:
    // 00529971  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00529975  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00529978  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 0052997a  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0052997c  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0052997e  897c2408               -mov dword ptr [esp + 8], edi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 00529982  89750c                 -mov dword ptr [ebp + 0xc], esi
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.esi;
L_0x00529985:
    // 00529985  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00529989  8b550c                 -mov edx, dword ptr [ebp + 0xc]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0052998c  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 0052998e  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00529990  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00529994  89550c                 -mov dword ptr [ebp + 0xc], edx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00529997  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00529999  7c0b                   -jl 0x5299a6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005299a6;
    }
    // 0052999b  8b4520                 -mov eax, dword ptr [ebp + 0x20]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 0052999e  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 005299a1  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005299a2  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005299a3  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005299a4  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005299a5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005299a6:
    // 005299a6  6bc1ff                 -imul eax, ecx, -1
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(-1 /*-0x1*/)));
    // 005299a9  89442408               -mov dword ptr [esp + 8], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 005299ad  8d0c00                 -lea ecx, [eax + eax]
    cpu.ecx = x86::reg32(cpu.eax + cpu.eax * 1);
    // 005299b0  8b4522                 -mov eax, dword ptr [ebp + 0x22]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(34) /* 0x22 */);
    // 005299b3  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 005299b6  8d7d26                 -lea edi, [ebp + 0x26]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(38) /* 0x26 */);
    // 005299b9  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 005299bb  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 005299bd  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 005299bf  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005299c0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 005299c2  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 005299c5  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 005299c7  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 005299c9  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 005299cc  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 005299ce  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005299cf  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 005299d3  668b5d24               -mov bx, word ptr [ebp + 0x24]
    cpu.bx = *app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(36) /* 0x24 */);
    // 005299d7  8b7520                 -mov esi, dword ptr [ebp + 0x20]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 005299da  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 005299dc  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 005299e0  66895d24               -mov word ptr [ebp + 0x24], bx
    *app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(36) /* 0x24 */) = cpu.bx;
    // 005299e4  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 005299e6  897520                 -mov dword ptr [ebp + 0x20], esi
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */) = cpu.esi;
    // 005299e9  8b4520                 -mov eax, dword ptr [ebp + 0x20]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 005299ec  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 005299ef  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005299f0  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005299f1  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005299f2  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005299f3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_5299f4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005299f4  e867370000             -call 0x52d160
    cpu.esp -= 4;
    sub_52d160(app, cpu);
    if (cpu.terminate) return;
    // 005299f9  c7421000000000         -mov dword ptr [edx + 0x10], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 00529a00  c7421800000000         -mov dword ptr [edx + 0x18], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 00529a07  66c742240000           -mov word ptr [edx + 0x24], 0
    *app->getMemory<x86::reg16>(cpu.edx + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 00529a0d  66c742060000           -mov word ptr [edx + 6], 0
    *app->getMemory<x86::reg16>(cpu.edx + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 00529a13  66c742040000           -mov word ptr [edx + 4], 0
    *app->getMemory<x86::reg16>(cpu.edx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00529a19  c7422000000000         -mov dword ptr [edx + 0x20], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 00529a20  89421c                 -mov dword ptr [edx + 0x1c], eax
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00529a23  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00529a27  894a14                 -mov dword ptr [edx + 0x14], ecx
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00529a2a  c700c0975200           -mov dword ptr [eax], 0x5297c0
    *app->getMemory<x86::reg32>(cpu.eax) = 5412800 /*0x5297c0*/;
    // 00529a30  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00529a34  c70000000000           -mov dword ptr [eax], 0
    *app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 00529a3a  b85c000000             -mov eax, 0x5c
    cpu.eax = 92 /*0x5c*/;
    // 00529a3f  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_529a50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00529a50  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00529a53  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_529a54(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00529a54  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00529a55  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00529a56  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00529a57  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00529a58  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00529a5b  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00529a5d  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00529a5f  8b481c                 -mov ecx, dword ptr [eax + 0x1c]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00529a62  8b7818                 -mov edi, dword ptr [eax + 0x18]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00529a65  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00529a67  39f9                   +cmp ecx, edi
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
    // 00529a69  7d3c                   -jge 0x529aa7
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00529aa7;
    }
    // 00529a6b  895010                 -mov dword ptr [eax + 0x10], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 00529a6e  8b501e                 -mov edx, dword ptr [eax + 0x1e]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(30) /* 0x1e */);
    // 00529a71  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00529a74  d1fa                   -sar edx, 1
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (1 /*0x1*/ % 32));
    // 00529a76  39d6                   +cmp esi, edx
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
    // 00529a78  7e3a                   -jle 0x529ab4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00529ab4;
    }
    // 00529a7a  bd02000000             -mov ebp, 2
    cpu.ebp = 2 /*0x2*/;
    // 00529a7f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00529a81:
    // 00529a81  8b4b1e                 -mov ecx, dword ptr [ebx + 0x1e]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(30) /* 0x1e */);
    // 00529a84  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00529a87  39ca                   +cmp edx, ecx
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
    // 00529a89  0f8d8b000000           -jge 0x529b1a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00529b1a;
    }
    // 00529a8f  8b4b10                 -mov ecx, dword ptr [ebx + 0x10]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 00529a92  668b7824               -mov di, word ptr [eax + 0x24]
    cpu.di = *app->getMemory<x86::reg16>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 00529a96  668939                 -mov word ptr [ecx], di
    *app->getMemory<x86::reg16>(cpu.ecx) = cpu.di;
    // 00529a99  8b4b10                 -mov ecx, dword ptr [ebx + 0x10]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 00529a9c  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00529a9f  01e9                   +add ecx, ebp
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00529aa1  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00529aa2  894b10                 -mov dword ptr [ebx + 0x10], ecx
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00529aa5  ebda                   -jmp 0x529a81
    goto L_0x00529a81;
L_0x00529aa7:
    // 00529aa7  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00529aac  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00529aaf  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529ab0  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529ab1  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529ab2  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529ab3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00529ab4:
    // 00529ab4  01f6                   -add esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi));
    // 00529ab6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00529ab8  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00529aba  7e1c                   -jle 0x529ad8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00529ad8;
    }
L_0x00529abc:
    // 00529abc  8b4b10                 -mov ecx, dword ptr [ebx + 0x10]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 00529abf  668b7824               -mov di, word ptr [eax + 0x24]
    cpu.di = *app->getMemory<x86::reg16>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 00529ac3  668939                 -mov word ptr [ecx], di
    *app->getMemory<x86::reg16>(cpu.ecx) = cpu.di;
    // 00529ac6  8b6b10                 -mov ebp, dword ptr [ebx + 0x10]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 00529ac9  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00529acc  83c502                 -add ebp, 2
    (cpu.ebp) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00529acf  42                     -inc edx
    (cpu.edx)++;
    // 00529ad0  896b10                 -mov dword ptr [ebx + 0x10], ebp
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.ebp;
    // 00529ad3  39f2                   +cmp edx, esi
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
    // 00529ad5  7ce5                   -jl 0x529abc
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00529abc;
    }
    // 00529ad7  90                     -nop 
    ;
L_0x00529ad8:
    // 00529ad8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00529ada  8d3412                 -lea esi, [edx + edx]
    cpu.esi = x86::reg32(cpu.edx + cpu.edx * 1);
    // 00529add  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00529ae0  01de                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00529ae2  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x00529ae4:
    // 00529ae4  8b4b1e                 -mov ecx, dword ptr [ebx + 0x1e]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(30) /* 0x1e */);
    // 00529ae7  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00529aea  39ca                   +cmp edx, ecx
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
    // 00529aec  7d18                   -jge 0x529b06
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00529b06;
    }
    // 00529aee  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00529af1  668b4e24               -mov cx, word ptr [esi + 0x24]
    cpu.cx = *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 00529af5  66894822               -mov word ptr [eax + 0x22], cx
    *app->getMemory<x86::reg16>(cpu.eax + x86::reg32(34) /* 0x22 */) = cpu.cx;
    // 00529af9  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    // 00529afc  83c602                 +add esi, 2
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
    // 00529aff  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00529b00  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00529b01  890c24                 -mov dword ptr [esp], ecx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 00529b04  ebde                   -jmp 0x529ae4
    goto L_0x00529ae4;
L_0x00529b06:
    // 00529b06  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 00529b09  66894320               -mov word ptr [ebx + 0x20], ax
    *app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(32) /* 0x20 */) = cpu.ax;
    // 00529b0d  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00529b12  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00529b15  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529b16  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529b17  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529b18  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529b19  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00529b1a:
    // 00529b1a  8b6b18                 -mov ebp, dword ptr [ebx + 0x18]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 00529b1d  8b431c                 -mov eax, dword ptr [ebx + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */);
    // 00529b20  d1f9                   -sar ecx, 1
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (1 /*0x1*/ % 32));
    // 00529b22  29c5                   -sub ebp, eax
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00529b24  29ce                   -sub esi, ecx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00529b26  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00529b28  0f8c8b000000           -jl 0x529bb9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00529bb9;
    }
L_0x00529b2e:
    // 00529b2e  39ee                   +cmp esi, ebp
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
    // 00529b30  0f8d8a000000           -jge 0x529bc0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00529bc0;
    }
    // 00529b36  893424                 -mov dword ptr [esp], esi
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
L_0x00529b39:
    // 00529b39  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 00529b3c  8903                   -mov dword ptr [ebx], eax
    *app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 00529b3e  8b431c                 -mov eax, dword ptr [ebx + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */);
    // 00529b41  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 00529b43  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00529b45  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00529b48  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00529b4a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00529b4c  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 00529b51  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00529b54  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00529b56  8b5314                 -mov edx, dword ptr [ebx + 0x14]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 00529b59  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00529b5b  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00529b5c  89530c                 -mov dword ptr [ebx + 0xc], edx
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00529b5f  e8ec360000             -call 0x52d250
    cpu.esp -= 4;
    sub_52d250(app, cpu);
    if (cpu.terminate) return;
    // 00529b64  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00529b67  8b531c                 -mov edx, dword ptr [ebx + 0x1c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */);
    // 00529b6a  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 00529b6d  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00529b6f  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00529b71  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx);
    // 00529b73  89531c                 -mov dword ptr [ebx + 0x1c], edx
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 00529b76  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00529b78  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    // 00529b7b  894b1c                 -mov dword ptr [ebx + 0x1c], ecx
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00529b7e  39fd                   +cmp ebp, edi
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
    // 00529b80  7546                   -jne 0x529bc8
    if (!cpu.flags.zf)
    {
        goto L_0x00529bc8;
    }
    // 00529b82  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00529b84  8b5318                 -mov edx, dword ptr [ebx + 0x18]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 00529b87  29fe                   -sub esi, edi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00529b89  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00529b8b  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00529b8d  01f6                   -add esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi));
    // 00529b8f  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00529b91  7e19                   -jle 0x529bac
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00529bac;
    }
    // 00529b93  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00529b95:
    // 00529b95  8b4310                 -mov eax, dword ptr [ebx + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 00529b98  668910                 -mov word ptr [eax], dx
    *app->getMemory<x86::reg16>(cpu.eax) = cpu.dx;
    // 00529b9b  8b7b10                 -mov edi, dword ptr [ebx + 0x10]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 00529b9e  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00529ba1  4e                     -dec esi
    (cpu.esi)--;
    // 00529ba2  897b10                 -mov dword ptr [ebx + 0x10], edi
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.edi;
    // 00529ba5  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00529ba7  7fec                   -jg 0x529b95
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00529b95;
    }
    // 00529ba9  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x00529bac:
    // 00529bac  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00529bb1  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00529bb4  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529bb5  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529bb6  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529bb7  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529bb8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00529bb9:
    // 00529bb9  31ed                   +xor ebp, ebp
    cpu.clear_co();
    cpu.set_szp((cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp))));
    // 00529bbb  e96effffff             -jmp 0x529b2e
    goto L_0x00529b2e;
L_0x00529bc0:
    // 00529bc0  892c24                 -mov dword ptr [esp], ebp
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 00529bc3  e971ffffff             -jmp 0x529b39
    goto L_0x00529b39;
L_0x00529bc8:
    // 00529bc8  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 00529bcd  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00529bcf  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00529bd1  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00529bd4  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00529bd6  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00529bd8  29d6                   -sub esi, edx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00529bda  6bf6ff                 -imul esi, esi, -1
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(-1 /*-0x1*/)));
    // 00529bdd  83fee4                 +cmp esi, -0x1c
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-28 /*-0x1c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00529be0  7502                   -jne 0x529be4
    if (!cpu.flags.zf)
    {
        goto L_0x00529be4;
    }
    // 00529be2  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x00529be4:
    // 00529be4  01f6                   -add esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi));
    // 00529be6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00529be8  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00529bea  7c11                   -jl 0x529bfd
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00529bfd;
    }
    // 00529bec  66895320               -mov word ptr [ebx + 0x20], dx
    *app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(32) /* 0x20 */) = cpu.dx;
    // 00529bf0  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00529bf5  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00529bf8  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529bf9  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529bfa  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529bfb  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529bfc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00529bfd:
    // 00529bfd  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00529bff  8d0436                 -lea eax, [esi + esi]
    cpu.eax = x86::reg32(cpu.esi + cpu.esi * 1);
L_0x00529c02:
    // 00529c02  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00529c05  8b6b10                 -mov ebp, dword ptr [ebx + 0x10]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 00529c08  46                     -inc esi
    (cpu.esi)++;
    // 00529c09  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00529c0c  668b7c28fe             -mov di, word ptr [eax + ebp - 2]
    cpu.di = *app->getMemory<x86::reg16>(cpu.eax + x86::reg32(-2) /* -0x2 */ + cpu.ebp * 1);
    // 00529c11  42                     -inc edx
    (cpu.edx)++;
    // 00529c12  66897922               -mov word ptr [ecx + 0x22], di
    *app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(34) /* 0x22 */) = cpu.di;
    // 00529c16  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00529c18  7ce8                   -jl 0x529c02
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00529c02;
    }
    // 00529c1a  66895320               -mov word ptr [ebx + 0x20], dx
    *app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(32) /* 0x20 */) = cpu.dx;
    // 00529c1e  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00529c23  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00529c26  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529c27  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529c28  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529c29  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529c2a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_529c2c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00529c2c  c7421c00000000         -mov dword ptr [edx + 0x1c], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 00529c33  66c742200000           -mov word ptr [edx + 0x20], 0
    *app->getMemory<x86::reg16>(cpu.edx + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 00529c39  66c742060000           -mov word ptr [edx + 6], 0
    *app->getMemory<x86::reg16>(cpu.edx + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 00529c3f  66c742040000           -mov word ptr [edx + 4], 0
    *app->getMemory<x86::reg16>(cpu.edx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00529c45  66c7420a0000           -mov word ptr [edx + 0xa], 0
    *app->getMemory<x86::reg16>(cpu.edx + x86::reg32(10) /* 0xa */) = 0 /*0x0*/;
    // 00529c4b  66c742080000           -mov word ptr [edx + 8], 0
    *app->getMemory<x86::reg16>(cpu.edx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 00529c51  895a14                 -mov dword ptr [edx + 0x14], ebx
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 00529c54  894a18                 -mov dword ptr [edx + 0x18], ecx
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 00529c57  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00529c5b  c702549a5200           -mov dword ptr [edx], 0x529a54
    *app->getMemory<x86::reg32>(cpu.edx) = 5413460 /*0x529a54*/;
    // 00529c61  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00529c65  b890000000             -mov eax, 0x90
    cpu.eax = 144 /*0x90*/;
    // 00529c6a  c702509a5200           -mov dword ptr [edx], 0x529a50
    *app->getMemory<x86::reg32>(cpu.edx) = 5413456 /*0x529a50*/;
    // 00529c70  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_529c80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00529c80  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00529c81  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00529c82  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00529c83  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00529c86  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00529c88  89542404               -mov dword ptr [esp + 4], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00529c8c  890c24                 -mov dword ptr [esp], ecx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 00529c8f  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00529c91  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx);
    // 00529c93  39d8                   +cmp eax, ebx
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
    // 00529c95  7d02                   -jge 0x529c99
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00529c99;
    }
    // 00529c97  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x00529c99:
    // 00529c99  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00529c9b  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00529c9d  7e21                   -jle 0x529cc0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00529cc0;
    }
    // 00529c9f  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
L_0x00529ca3:
    // 00529ca3  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00529ca6  668b19                 -mov bx, word ptr [ecx]
    cpu.bx = *app->getMemory<x86::reg16>(cpu.ecx);
    // 00529ca9  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00529cac  66895afe               -mov word ptr [edx - 2], bx
    *app->getMemory<x86::reg16>(cpu.edx + x86::reg32(-2) /* -0x2 */) = cpu.bx;
    // 00529cb0  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00529cb3  668b59fe               -mov bx, word ptr [ecx - 2]
    cpu.bx = *app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(-2) /* -0x2 */);
    // 00529cb7  40                     -inc eax
    (cpu.eax)++;
    // 00529cb8  66895afe               -mov word ptr [edx - 2], bx
    *app->getMemory<x86::reg16>(cpu.edx + x86::reg32(-2) /* -0x2 */) = cpu.bx;
    // 00529cbc  39f8                   +cmp eax, edi
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
    // 00529cbe  7ce3                   -jl 0x529ca3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00529ca3;
    }
L_0x00529cc0:
    // 00529cc0  39e8                   +cmp eax, ebp
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
    // 00529cc2  7d28                   -jge 0x529cec
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00529cec;
    }
    // 00529cc4  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00529cc8  8d1c8500000000         -lea ebx, [eax*4]
    cpu.ebx = x86::reg32(cpu.eax * 4);
    // 00529ccf  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
L_0x00529cd1:
    // 00529cd1  668b33                 -mov si, word ptr [ebx]
    cpu.si = *app->getMemory<x86::reg16>(cpu.ebx);
    // 00529cd4  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00529cd7  668931                 -mov word ptr [ecx], si
    *app->getMemory<x86::reg16>(cpu.ecx) = cpu.si;
    // 00529cda  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00529cdd  668b73fe               -mov si, word ptr [ebx - 2]
    cpu.si = *app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(-2) /* -0x2 */);
    // 00529ce1  40                     -inc eax
    (cpu.eax)++;
    // 00529ce2  668971fe               -mov word ptr [ecx - 2], si
    *app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(-2) /* -0x2 */) = cpu.si;
    // 00529ce6  39e8                   +cmp eax, ebp
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
    // 00529ce8  7ce7                   -jl 0x529cd1
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00529cd1;
    }
    // 00529cea  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x00529cec:
    // 00529cec  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 00529cef  8910                   -mov dword ptr [eax], edx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00529cf1  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00529cf3  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00529cf6  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529cf7  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529cf8  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529cf9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_529cfc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00529cfc  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00529cfd  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00529cfe  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00529cff  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00529d00  83ec7c                 -sub esp, 0x7c
    (cpu.esp) -= x86::reg32(x86::sreg32(124 /*0x7c*/));
    // 00529d03  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00529d05  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00529d07  895810                 -mov dword ptr [eax + 0x10], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 00529d0a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00529d0c  7e59                   -jle 0x529d67
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00529d67;
    }
    // 00529d0e  8d5010                 -lea edx, [eax + 0x10]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00529d11  89542474               -mov dword ptr [esp + 0x74], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */) = cpu.edx;
    // 00529d15  8d682c                 -lea ebp, [eax + 0x2c]
    cpu.ebp = x86::reg32(cpu.eax + x86::reg32(44) /* 0x2c */);
L_0x00529d18:
    // 00529d18  66837e2800             +cmp word ptr [esi + 0x28], 0
    {
        x86::reg16 tmp1 = *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(40) /* 0x28 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00529d1d  756a                   -jne 0x529d89
    if (!cpu.flags.zf)
    {
        goto L_0x00529d89;
    }
    // 00529d1f  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00529d22  8b4e24                 -mov ecx, dword ptr [esi + 0x24]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 00529d25  83c01b                 -add eax, 0x1b
    (cpu.eax) += x86::reg32(x86::sreg32(27 /*0x1b*/));
    // 00529d28  39c8                   +cmp eax, ecx
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
    // 00529d2a  0f8d7a000000           -jge 0x529daa
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00529daa;
    }
    // 00529d30  6b561c1e               -imul edx, dword ptr [esi + 0x1c], 0x1e
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */))) * x86::sreg64(x86::sreg32(30 /*0x1e*/)));
    // 00529d34  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 00529d39  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00529d3b  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00529d3e  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00529d40  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00529d43  c7061c000000           -mov dword ptr [esi], 0x1c
    *app->getMemory<x86::reg32>(cpu.esi) = 28 /*0x1c*/;
    // 00529d49  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00529d4b  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00529d4c  89560c                 -mov dword ptr [esi + 0xc], edx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00529d4f  e8fc340000             -call 0x52d250
    cpu.esp -= 4;
    sub_52d250(app, cpu);
    if (cpu.terminate) return;
    // 00529d54  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00529d57  83ef1c                 -sub edi, 0x1c
    (cpu.edi) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00529d5a  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00529d5d  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00529d60  89461c                 -mov dword ptr [esi + 0x1c], eax
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.eax;
L_0x00529d63:
    // 00529d63  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00529d65  7fb1                   -jg 0x529d18
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00529d18;
    }
L_0x00529d67:
    // 00529d67  8d04bd00000000         -lea eax, [edi*4]
    cpu.eax = x86::reg32(cpu.edi * 4);
    // 00529d6e  014610                 -add dword ptr [esi + 0x10], eax
    (*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */)) += x86::reg32(x86::sreg32(cpu.eax));
    // 00529d71  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x00529d74:
    // 00529d74  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00529d76  0f8c66010000           -jl 0x529ee2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00529ee2;
    }
    // 00529d7c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00529d81  83c47c                 -add esp, 0x7c
    (cpu.esp) += x86::reg32(x86::sreg32(124 /*0x7c*/));
    // 00529d84  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529d85  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529d86  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529d87  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529d88  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00529d89:
    // 00529d89  8b4c2474               -mov ecx, dword ptr [esp + 0x74]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 00529d8d  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00529d8f  8b4626                 -mov eax, dword ptr [esi + 0x26]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(38) /* 0x26 */);
    // 00529d92  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00529d94  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00529d97  e8e4feffff             -call 0x529c80
    cpu.esp -= 4;
    sub_529c80(app, cpu);
    if (cpu.terminate) return;
    // 00529d9c  668b5e28               -mov bx, word ptr [esi + 0x28]
    cpu.bx = *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 00529da0  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00529da2  29c7                   +sub edi, eax
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00529da4  66895e28               -mov word ptr [esi + 0x28], bx
    *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.bx;
    // 00529da8  ebb9                   -jmp 0x529d63
    goto L_0x00529d63;
L_0x00529daa:
    // 00529daa  6b561c1e               -imul edx, dword ptr [esi + 0x1c], 0x1e
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */))) * x86::sreg64(x86::sreg32(30 /*0x1e*/)));
    // 00529dae  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00529db1  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 00529db6  89442470               -mov dword ptr [esp + 0x70], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */) = cpu.eax;
    // 00529dba  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00529dbc  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00529dbf  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00529dc1  c7061c000000           -mov dword ptr [esi], 0x1c
    *app->getMemory<x86::reg32>(cpu.esi) = 28 /*0x1c*/;
    // 00529dc7  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00529dca  896e10                 -mov dword ptr [esi + 0x10], ebp
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ebp;
    // 00529dcd  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00529dcf  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00529dd0  89560c                 -mov dword ptr [esi + 0xc], edx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00529dd3  e878340000             -call 0x52d250
    cpu.esp -= 4;
    sub_52d250(app, cpu);
    if (cpu.terminate) return;
    // 00529dd8  83461c1c               -add dword ptr [esi + 0x1c], 0x1c
    (*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */)) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00529ddc  668b5e24               -mov bx, word ptr [esi + 0x24]
    cpu.bx = *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 00529de0  668b461c               -mov ax, word ptr [esi + 0x1c]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00529de4  ba1c000000             -mov edx, 0x1c
    cpu.edx = 28 /*0x1c*/;
    // 00529de9  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00529deb  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00529ded  668b8608010000         -mov ax, word ptr [esi + 0x108]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(264) /* 0x108 */);
    // 00529df4  66895628               -mov word ptr [esi + 0x28], dx
    *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.dx;
    // 00529df8  66894606               -mov word ptr [esi + 6], ax
    *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */) = cpu.ax;
    // 00529dfc  668b860a010000         -mov ax, word ptr [esi + 0x10a]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(266) /* 0x10a */);
    // 00529e03  66894604               -mov word ptr [esi + 4], ax
    *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.ax;
    // 00529e07  668b860c010000         -mov ax, word ptr [esi + 0x10c]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(268) /* 0x10c */);
    // 00529e0e  6689460a               -mov word ptr [esi + 0xa], ax
    *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(10) /* 0xa */) = cpu.ax;
    // 00529e12  668b860e010000         -mov ax, word ptr [esi + 0x10e]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(270) /* 0x10e */);
    // 00529e19  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00529e1b  66894608               -mov word ptr [esi + 8], ax
    *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.ax;
    // 00529e1f  41                     -inc ecx
    (cpu.ecx)++;
    // 00529e20  8b4620                 -mov eax, dword ptr [esi + 0x20]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 00529e23  66894e28               -mov word ptr [esi + 0x28], cx
    *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.cx;
    // 00529e27  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00529e29  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 00529e2e  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00529e31  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00529e33  0fafc1                 -imul eax, ecx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 00529e36  89461c                 -mov dword ptr [esi + 0x1c], eax
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00529e39  8b4620                 -mov eax, dword ptr [esi + 0x20]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 00529e3c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00529e3e  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00529e41  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00529e43  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00529e46  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00529e48  0f8488000000           -je 0x529ed6
    if (cpu.flags.zf)
    {
        goto L_0x00529ed6;
    }
    // 00529e4e  890e                   -mov dword ptr [esi], ecx
    *app->getMemory<x86::reg32>(cpu.esi) = cpu.ecx;
    // 00529e50  6b561c1e               -imul edx, dword ptr [esi + 0x1c], 0x1e
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */))) * x86::sreg64(x86::sreg32(30 /*0x1e*/)));
    // 00529e54  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 00529e59  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00529e5b  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00529e5e  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00529e60  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00529e63  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00529e65  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00529e67  89560c                 -mov dword ptr [esi + 0xc], edx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00529e6a  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00529e6b  894610                 -mov dword ptr [esi + 0x10], eax
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00529e6e  e8dd330000             -call 0x52d250
    cpu.esp -= 4;
    sub_52d250(app, cpu);
    if (cpu.terminate) return;
    // 00529e73  8b5e1c                 -mov ebx, dword ptr [esi + 0x1c]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00529e76  83c31c                 -add ebx, 0x1c
    (cpu.ebx) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00529e79  8b5620                 -mov edx, dword ptr [esi + 0x20]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 00529e7c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00529e7e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00529e81  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00529e83  ba38000000             -mov edx, 0x38
    cpu.edx = 56 /*0x38*/;
    // 00529e88  89442478               -mov dword ptr [esp + 0x78], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */) = cpu.eax;
    // 00529e8c  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 00529e8e  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00529e90  8d0412                 -lea eax, [edx + edx]
    cpu.eax = x86::reg32(cpu.edx + cpu.edx * 1);
    // 00529e93  895e1c                 -mov dword ptr [esi + 0x1c], ebx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 00529e96  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00529e98  8b4c2478               -mov ecx, dword ptr [esp + 0x78]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00529e9c  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00529e9e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00529ea0  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00529ea2  7e32                   -jle 0x529ed6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00529ed6;
    }
L_0x00529ea4:
    // 00529ea4  8b4e26                 -mov ecx, dword ptr [esi + 0x26]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(38) /* 0x26 */);
    // 00529ea7  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00529eaa  668b18                 -mov bx, word ptr [eax]
    cpu.bx = *app->getMemory<x86::reg16>(cpu.eax);
    // 00529ead  66895c8e2c             -mov word ptr [esi + ecx*4 + 0x2c], bx
    *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(44) /* 0x2c */ + cpu.ecx * 4) = cpu.bx;
    // 00529eb2  8b4e26                 -mov ecx, dword ptr [esi + 0x26]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(38) /* 0x26 */);
    // 00529eb5  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00529eb8  668b5802               -mov bx, word ptr [eax + 2]
    cpu.bx = *app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00529ebc  66895c8e2e             -mov word ptr [esi + ecx*4 + 0x2e], bx
    *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(46) /* 0x2e */ + cpu.ecx * 4) = cpu.bx;
    // 00529ec1  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00529ec4  668b5e28               -mov bx, word ptr [esi + 0x28]
    cpu.bx = *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 00529ec8  42                     -inc edx
    (cpu.edx)++;
    // 00529ec9  43                     -inc ebx
    (cpu.ebx)++;
    // 00529eca  8b4c2478               -mov ecx, dword ptr [esp + 0x78]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00529ece  66895e28               -mov word ptr [esi + 0x28], bx
    *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.bx;
    // 00529ed2  39ca                   +cmp edx, ecx
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
    // 00529ed4  7cce                   -jl 0x529ea4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00529ea4;
    }
L_0x00529ed6:
    // 00529ed6  8b442470               -mov eax, dword ptr [esp + 0x70]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */);
    // 00529eda  894610                 -mov dword ptr [esi + 0x10], eax
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00529edd  e981feffff             -jmp 0x529d63
    goto L_0x00529d63;
L_0x00529ee2:
    // 00529ee2  8b4626                 -mov eax, dword ptr [esi + 0x26]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(38) /* 0x26 */);
    // 00529ee5  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00529ee8  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00529eeb  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00529eee  8d0c06                 -lea ecx, [esi + eax]
    cpu.ecx = x86::reg32(cpu.esi + cpu.eax * 1);
    // 00529ef1  668b02                 -mov ax, word ptr [edx]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.edx);
    // 00529ef4  6689412c               -mov word ptr [ecx + 0x2c], ax
    *app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(44) /* 0x2c */) = cpu.ax;
    // 00529ef8  8b5626                 -mov edx, dword ptr [esi + 0x26]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(38) /* 0x26 */);
    // 00529efb  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00529efe  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00529f01  668b4002               -mov ax, word ptr [eax + 2]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00529f05  668944962e             -mov word ptr [esi + edx*4 + 0x2e], ax
    *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(46) /* 0x2e */ + cpu.edx * 4) = cpu.ax;
    // 00529f0a  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00529f0d  668b4e28               -mov cx, word ptr [esi + 0x28]
    cpu.cx = *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 00529f11  83c204                 +add edx, 4
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
    // 00529f14  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00529f15  895610                 -mov dword ptr [esi + 0x10], edx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 00529f18  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00529f19  66894e28               -mov word ptr [esi + 0x28], cx
    *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.cx;
    // 00529f1d  e952feffff             -jmp 0x529d74
    goto L_0x00529d74;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_529f24(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00529f24  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00529f25  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00529f26  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00529f27  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00529f28  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00529f2b  891424                 -mov dword ptr [esp], edx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00529f2e  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    // 00529f31  8b5026                 -mov edx, dword ptr [eax + 0x26]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(38) /* 0x26 */);
    // 00529f34  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00529f36  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00529f39  895810                 -mov dword ptr [eax + 0x10], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 00529f3c  39ca                   +cmp edx, ecx
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
    // 00529f3e  7d38                   -jge 0x529f78
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00529f78;
    }
    // 00529f40  bd04000000             -mov ebp, 4
    cpu.ebp = 4 /*0x4*/;
    // 00529f45  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00529f47:
    // 00529f47  8b5626                 -mov edx, dword ptr [esi + 0x26]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(38) /* 0x26 */);
    // 00529f4a  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00529f4d  39d3                   +cmp ebx, edx
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
    // 00529f4f  0f8da7000000           -jge 0x529ffc
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00529ffc;
    }
    // 00529f55  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00529f58  668b502c               -mov dx, word ptr [eax + 0x2c]
    cpu.dx = *app->getMemory<x86::reg16>(cpu.eax + x86::reg32(44) /* 0x2c */);
    // 00529f5c  668911                 -mov word ptr [ecx], dx
    *app->getMemory<x86::reg16>(cpu.ecx) = cpu.dx;
    // 00529f5f  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00529f62  668b482e               -mov cx, word ptr [eax + 0x2e]
    cpu.cx = *app->getMemory<x86::reg16>(cpu.eax + x86::reg32(46) /* 0x2e */);
    // 00529f66  66894a02               -mov word ptr [edx + 2], cx
    *app->getMemory<x86::reg16>(cpu.edx + x86::reg32(2) /* 0x2 */) = cpu.cx;
    // 00529f6a  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00529f6d  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00529f70  01e9                   +add ecx, ebp
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00529f72  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00529f73  894e10                 -mov dword ptr [esi + 0x10], ecx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00529f76  ebcf                   -jmp 0x529f47
    goto L_0x00529f47;
L_0x00529f78:
    // 00529f78  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00529f7a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00529f7c  7e2a                   -jle 0x529fa8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00529fa8;
    }
    // 00529f7e  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
L_0x00529f81:
    // 00529f81  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00529f84  668b482c               -mov cx, word ptr [eax + 0x2c]
    cpu.cx = *app->getMemory<x86::reg16>(cpu.eax + x86::reg32(44) /* 0x2c */);
    // 00529f88  66890a                 -mov word ptr [edx], cx
    *app->getMemory<x86::reg16>(cpu.edx) = cpu.cx;
    // 00529f8b  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00529f8e  668b502e               -mov dx, word ptr [eax + 0x2e]
    cpu.dx = *app->getMemory<x86::reg16>(cpu.eax + x86::reg32(46) /* 0x2e */);
    // 00529f92  66895102               -mov word ptr [ecx + 2], dx
    *app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(2) /* 0x2 */) = cpu.dx;
    // 00529f96  8b7e10                 -mov edi, dword ptr [esi + 0x10]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00529f99  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00529f9c  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00529f9f  43                     -inc ebx
    (cpu.ebx)++;
    // 00529fa0  897e10                 -mov dword ptr [esi + 0x10], edi
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.edi;
    // 00529fa3  39eb                   +cmp ebx, ebp
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
    // 00529fa5  7cda                   -jl 0x529f81
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00529f81;
    }
    // 00529fa7  90                     -nop 
    ;
L_0x00529fa8:
    // 00529fa8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00529faa  8d149d00000000         -lea edx, [ebx*4]
    cpu.edx = x86::reg32(cpu.ebx * 4);
    // 00529fb1  89442408               -mov dword ptr [esp + 8], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00529fb5  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 00529fb7  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x00529fb9:
    // 00529fb9  8b4e26                 -mov ecx, dword ptr [esi + 0x26]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(38) /* 0x26 */);
    // 00529fbc  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00529fbf  39cb                   +cmp ebx, ecx
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
    // 00529fc1  7d22                   -jge 0x529fe5
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00529fe5;
    }
    // 00529fc3  668b4a2c               -mov cx, word ptr [edx + 0x2c]
    cpu.cx = *app->getMemory<x86::reg16>(cpu.edx + x86::reg32(44) /* 0x2c */);
    // 00529fc7  6689482c               -mov word ptr [eax + 0x2c], cx
    *app->getMemory<x86::reg16>(cpu.eax + x86::reg32(44) /* 0x2c */) = cpu.cx;
    // 00529fcb  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00529fce  668b4a2e               -mov cx, word ptr [edx + 0x2e]
    cpu.cx = *app->getMemory<x86::reg16>(cpu.edx + x86::reg32(46) /* 0x2e */);
    // 00529fd2  6689482a               -mov word ptr [eax + 0x2a], cx
    *app->getMemory<x86::reg16>(cpu.eax + x86::reg32(42) /* 0x2a */) = cpu.cx;
    // 00529fd6  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00529fda  83c204                 +add edx, 4
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
    // 00529fdd  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00529fde  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00529fdf  894c2408               -mov dword ptr [esp + 8], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 00529fe3  ebd4                   -jmp 0x529fb9
    goto L_0x00529fb9;
L_0x00529fe5:
    // 00529fe5  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00529fe9  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00529fee  66894628               -mov word ptr [esi + 0x28], ax
    *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.ax;
    // 00529ff2  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00529ff4  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00529ff7  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529ff8  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529ff9  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529ffa  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00529ffb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00529ffc:
    // 00529ffc  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    // 00529fff  8b4620                 -mov eax, dword ptr [esi + 0x20]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 0052a002  29d5                   -sub ebp, edx
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0052a004  2b461c                 -sub eax, dword ptr [esi + 0x1c]
    (cpu.eax) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */)));
    // 0052a007  83e81b                 -sub eax, 0x1b
    (cpu.eax) -= x86::reg32(x86::sreg32(27 /*0x1b*/));
    // 0052a00a  892c24                 -mov dword ptr [esp], ebp
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 0052a00d  39e8                   +cmp eax, ebp
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
    // 0052a00f  0f8ee7000000           -jle 0x52a0fc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052a0fc;
    }
    // 0052a015  896c2408               -mov dword ptr [esp + 8], ebp
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebp;
L_0x0052a019:
    // 0052a019  837c240800             +cmp dword ptr [esp + 8], 0
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
    // 0052a01e  0f8ce1000000           -jl 0x52a105
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052a105;
    }
L_0x0052a024:
    // 0052a024  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052a028  8906                   -mov dword ptr [esi], eax
    *app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0052a02a  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0052a02d  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 0052a02f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052a031  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0052a034  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0052a036  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052a038  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 0052a03d  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0052a040  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0052a042  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0052a045  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0052a047  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052a048  89560c                 -mov dword ptr [esi + 0xc], edx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0052a04b  e800320000             -call 0x52d250
    cpu.esp -= 4;
    sub_52d250(app, cpu);
    if (cpu.terminate) return;
    // 0052a050  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052a053  8b6e1c                 -mov ebp, dword ptr [esi + 0x1c]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0052a056  036c2408               -add ebp, dword ptr [esp + 8]
    (cpu.ebp) += x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 0052a05a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0052a05c  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0052a05e  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi);
    // 0052a060  896e1c                 -mov dword ptr [esi + 0x1c], ebp
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.ebp;
    // 0052a063  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0052a065  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi);
    // 0052a067  89561c                 -mov dword ptr [esi + 0x1c], edx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 0052a06a  89442404               -mov dword ptr [esp + 4], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0052a06e  8d0c8500000000         -lea ecx, [eax*4]
    cpu.ecx = x86::reg32(cpu.eax * 4);
    // 0052a075  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0052a077  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0052a079  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0052a07b  90                     -nop 
    ;
L_0x0052a07c:
    // 0052a07c  0f8c8e000000           -jl 0x52a110
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052a110;
    }
    // 0052a082  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052a086  8b6e10                 -mov ebp, dword ptr [esi + 0x10]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0052a089  8b4e1c                 -mov ecx, dword ptr [esi + 0x1c]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0052a08c  29d5                   -sub ebp, edx
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0052a08e  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    // 0052a091  66895e28               -mov word ptr [esi + 0x28], bx
    *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.bx;
    // 0052a095  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0052a097  8b4620                 -mov eax, dword ptr [esi + 0x20]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 0052a09a  896e10                 -mov dword ptr [esi + 0x10], ebp
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ebp;
    // 0052a09d  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0052a09f  891424                 -mov dword ptr [esp], edx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0052a0a2  83f81c                 +cmp eax, 0x1c
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
    // 0052a0a5  7d46                   -jge 0x52a0ed
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0052a0ed;
    }
    // 0052a0a7  668b4606               -mov ax, word ptr [esi + 6]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 0052a0ab  66898608010000         -mov word ptr [esi + 0x108], ax
    *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(264) /* 0x108 */) = cpu.ax;
    // 0052a0b2  668b4604               -mov ax, word ptr [esi + 4]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0052a0b6  6689860a010000         -mov word ptr [esi + 0x10a], ax
    *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(266) /* 0x10a */) = cpu.ax;
    // 0052a0bd  668b460a               -mov ax, word ptr [esi + 0xa]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(10) /* 0xa */);
    // 0052a0c1  6689860c010000         -mov word ptr [esi + 0x10c], ax
    *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(268) /* 0x10c */) = cpu.ax;
    // 0052a0c8  668b4608               -mov ax, word ptr [esi + 8]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0052a0cc  6689860e010000         -mov word ptr [esi + 0x10e], ax
    *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(270) /* 0x10e */) = cpu.ax;
    // 0052a0d3  8b8610010000           -mov eax, dword ptr [esi + 0x110]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(272) /* 0x110 */);
    // 0052a0d9  c700fc9c5200           -mov dword ptr [eax], 0x529cfc
    *app->getMemory<x86::reg32>(cpu.eax) = 5414140 /*0x529cfc*/;
    // 0052a0df  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0052a0e1  7e0a                   -jle 0x52a0ed
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052a0ed;
    }
    // 0052a0e3  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052a0e5  8b5e10                 -mov ebx, dword ptr [esi + 0x10]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0052a0e8  e80ffcffff             -call 0x529cfc
    cpu.esp -= 4;
    sub_529cfc(app, cpu);
    if (cpu.terminate) return;
L_0x0052a0ed:
    // 0052a0ed  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0052a0f2  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0052a0f4  83c40c                 +add esp, 0xc
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
    // 0052a0f7  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052a0f8  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052a0f9  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052a0fa  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052a0fb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052a0fc:
    // 0052a0fc  89442408               -mov dword ptr [esp + 8], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0052a100  e914ffffff             -jmp 0x52a019
    goto L_0x0052a019;
L_0x0052a105:
    // 0052a105  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 0052a107  897c2408               -mov dword ptr [esp + 8], edi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 0052a10b  e914ffffff             -jmp 0x52a024
    goto L_0x0052a024;
L_0x0052a110:
    // 0052a110  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0052a113  8d2c01                 -lea ebp, [ecx + eax]
    cpu.ebp = x86::reg32(cpu.ecx + cpu.eax * 1);
    // 0052a116  8d0c16                 -lea ecx, [esi + edx]
    cpu.ecx = x86::reg32(cpu.esi + cpu.edx * 1);
    // 0052a119  668b7d00               -mov di, word ptr [ebp]
    cpu.di = *app->getMemory<x86::reg16>(cpu.ebp);
    // 0052a11d  6689792c               -mov word ptr [ecx + 0x2c], di
    *app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(44) /* 0x2c */) = cpu.di;
    // 0052a121  8b6e10                 -mov ebp, dword ptr [esi + 0x10]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0052a124  668b7c2802             -mov di, word ptr [eax + ebp + 2]
    cpu.di = *app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */ + cpu.ebp * 1);
    // 0052a129  43                     -inc ebx
    (cpu.ebx)++;
    // 0052a12a  6689792e               -mov word ptr [ecx + 0x2e], di
    *app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(46) /* 0x2e */) = cpu.di;
    // 0052a12e  8b7c2404               -mov edi, dword ptr [esp + 4]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052a132  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052a135  47                     -inc edi
    (cpu.edi)++;
    // 0052a136  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052a139  897c2404               -mov dword ptr [esp + 4], edi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 0052a13d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052a13f  e938ffffff             -jmp 0x52a07c
    goto L_0x0052a07c;
}

/* align: skip  */
void Application::sub_52a144(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052a144  c7421c00000000         -mov dword ptr [edx + 0x1c], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 0052a14b  66c742280000           -mov word ptr [edx + 0x28], 0
    *app->getMemory<x86::reg16>(cpu.edx + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
    // 0052a151  66c742060000           -mov word ptr [edx + 6], 0
    *app->getMemory<x86::reg16>(cpu.edx + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 0052a157  66c742040000           -mov word ptr [edx + 4], 0
    *app->getMemory<x86::reg16>(cpu.edx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0052a15d  66c7420a0000           -mov word ptr [edx + 0xa], 0
    *app->getMemory<x86::reg16>(cpu.edx + x86::reg32(10) /* 0xa */) = 0 /*0x0*/;
    // 0052a163  66c742080000           -mov word ptr [edx + 8], 0
    *app->getMemory<x86::reg16>(cpu.edx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 0052a169  895a14                 -mov dword ptr [edx + 0x14], ebx
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 0052a16c  894a18                 -mov dword ptr [edx + 0x18], ecx
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 0052a16f  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052a173  894a20                 -mov dword ptr [edx + 0x20], ecx
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 0052a176  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052a17a  894a24                 -mov dword ptr [edx + 0x24], ecx
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */) = cpu.ecx;
    // 0052a17d  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0052a181  898a10010000           -mov dword ptr [edx + 0x110], ecx
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(272) /* 0x110 */) = cpu.ecx;
    // 0052a187  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0052a18b  c701249f5200           -mov dword ptr [ecx], 0x529f24
    *app->getMemory<x86::reg32>(cpu.ecx) = 5414692 /*0x529f24*/;
    // 0052a191  b814010000             -mov eax, 0x114
    cpu.eax = 276 /*0x114*/;
    // 0052a196  c70200000000           -mov dword ptr [edx], 0
    *app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 0052a19c  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 */
void Application::sub_52a1a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052a1a0  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052a1a1  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052a1a2  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052a1a3  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0052a1a6  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0052a1a8  8b5014                 -mov edx, dword ptr [eax + 0x14]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 0052a1ab  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0052a1ad  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0052a1af  0f8490000000           -je 0x52a245
    if (cpu.flags.zf)
    {
        goto L_0x0052a245;
    }
    // 0052a1b5  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052a1b6  895810                 -mov dword ptr [eax + 0x10], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 0052a1b9  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0052a1bb  7e67                   -jle 0x52a224
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052a224;
    }
    // 0052a1bd  8d5010                 -lea edx, [eax + 0x10]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0052a1c0  89542404               -mov dword ptr [esp + 4], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0052a1c4  8d5024                 -lea edx, [eax + 0x24]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 0052a1c7  8954240c               -mov dword ptr [esp + 0xc], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0052a1cb  8d5018                 -lea edx, [eax + 0x18]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0052a1ce  89542408               -mov dword ptr [esp + 8], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0052a1d2  8d6814                 -lea ebp, [eax + 0x14]
    cpu.ebp = x86::reg32(cpu.eax + x86::reg32(20) /* 0x14 */);
L_0x0052a1d5:
    // 0052a1d5  8b5e20                 -mov ebx, dword ptr [esi + 0x20]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 0052a1d8  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0052a1da  7570                   -jne 0x52a24c
    if (!cpu.flags.zf)
    {
        goto L_0x0052a24c;
    }
    // 0052a1dc  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0052a1df  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0052a1e2  83c01b                 -add eax, 0x1b
    (cpu.eax) += x86::reg32(x86::sreg32(27 /*0x1b*/));
    // 0052a1e5  39d0                   +cmp eax, edx
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
    // 0052a1e7  0f8d7c000000           -jge 0x52a269
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0052a269;
    }
    // 0052a1ed  6b561c1e               -imul edx, dword ptr [esi + 0x1c], 0x1e
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */))) * x86::sreg64(x86::sreg32(30 /*0x1e*/)));
    // 0052a1f1  bb1c000000             -mov ebx, 0x1c
    cpu.ebx = 28 /*0x1c*/;
    // 0052a1f6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0052a1f8  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0052a1fb  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0052a1fd  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0052a200  c7061c000000           -mov dword ptr [esi], 0x1c
    *app->getMemory<x86::reg32>(cpu.esi) = 28 /*0x1c*/;
    // 0052a206  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0052a208  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052a209  89560c                 -mov dword ptr [esi + 0xc], edx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0052a20c  e83f300000             -call 0x52d250
    cpu.esp -= 4;
    sub_52d250(app, cpu);
    if (cpu.terminate) return;
    // 0052a211  8b5e1c                 -mov ebx, dword ptr [esi + 0x1c]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0052a214  83ef1c                 -sub edi, 0x1c
    (cpu.edi) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0052a217  83c31c                 -add ebx, 0x1c
    (cpu.ebx) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0052a21a  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052a21d  895e1c                 -mov dword ptr [esi + 0x1c], ebx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.ebx;
L_0x0052a220:
    // 0052a220  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0052a222  7fb1                   -jg 0x52a1d5
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0052a1d5;
    }
L_0x0052a224:
    // 0052a224  8d04bd00000000         -lea eax, [edi*4]
    cpu.eax = x86::reg32(cpu.edi * 4);
    // 0052a22b  014610                 -add dword ptr [esi + 0x10], eax
    (*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */)) += x86::reg32(x86::sreg32(cpu.eax));
    // 0052a22e  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x0052a230:
    // 0052a230  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0052a232  0f8ce8000000           -jl 0x52a320
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052a320;
    }
    // 0052a238  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0052a23d  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0052a23e:
    // 0052a23e  83c40c                 +add esp, 0xc
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
    // 0052a241  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052a242  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052a243  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052a244  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052a245:
    // 0052a245  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0052a24a  ebf2                   -jmp 0x52a23e
    goto L_0x0052a23e;
L_0x0052a24c:
    // 0052a24c  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052a250  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0052a254  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052a256  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0052a258  e823faffff             -call 0x529c80
    cpu.esp -= 4;
    sub_529c80(app, cpu);
    if (cpu.terminate) return;
    // 0052a25d  8b5620                 -mov edx, dword ptr [esi + 0x20]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 0052a260  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0052a262  29c7                   +sub edi, eax
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0052a264  895620                 -mov dword ptr [esi + 0x20], edx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 0052a267  ebb7                   -jmp 0x52a220
    goto L_0x0052a220;
L_0x0052a269:
    // 0052a269  837e1401               +cmp dword ptr [esi + 0x14], 1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052a26d  7445                   -je 0x52a2b4
    if (cpu.flags.zf)
    {
        goto L_0x0052a2b4;
    }
    // 0052a26f  6b561c1e               -imul edx, dword ptr [esi + 0x1c], 0x1e
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */))) * x86::sreg64(x86::sreg32(30 /*0x1e*/)));
    // 0052a273  bb1c000000             -mov ebx, 0x1c
    cpu.ebx = 28 /*0x1c*/;
    // 0052a278  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0052a27a  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0052a27d  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0052a27f  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0052a282  c7061c000000           -mov dword ptr [esi], 0x1c
    *app->getMemory<x86::reg32>(cpu.esi) = 28 /*0x1c*/;
    // 0052a288  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0052a28a  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052a28b  89560c                 -mov dword ptr [esi + 0xc], edx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0052a28e  e8bd2f0000             -call 0x52d250
    cpu.esp -= 4;
    sub_52d250(app, cpu);
    if (cpu.terminate) return;
    // 0052a293  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0052a296  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0052a298  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0052a29b  89461c                 -mov dword ptr [esi + 0x1c], eax
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0052a29e  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0052a2a0  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0052a2a2  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0052a2a5  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0052a2a7  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0052a2aa  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052a2ad  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0052a2af  29d7                   -sub edi, edx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0052a2b1  894e10                 -mov dword ptr [esi + 0x10], ecx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ecx;
L_0x0052a2b4:
    // 0052a2b4  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052a2b8  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0052a2ba  ff15b4785600           -call dword ptr [0x5678b4]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5666996) /* 0x5678b4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052a2c0  8b5e14                 -mov ebx, dword ptr [esi + 0x14]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0052a2c3  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0052a2c5  7434                   -je 0x52a2fb
    if (cpu.flags.zf)
    {
        goto L_0x0052a2fb;
    }
    // 0052a2c7  668b13                 -mov dx, word ptr [ebx]
    cpu.dx = *app->getMemory<x86::reg16>(cpu.ebx);
    // 0052a2ca  66895606               -mov word ptr [esi + 6], dx
    *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */) = cpu.dx;
    // 0052a2ce  668b5302               -mov dx, word ptr [ebx + 2]
    cpu.dx = *app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 0052a2d2  66895604               -mov word ptr [esi + 4], dx
    *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.dx;
    // 0052a2d6  668b5304               -mov dx, word ptr [ebx + 4]
    cpu.dx = *app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0052a2da  6689560a               -mov word ptr [esi + 0xa], dx
    *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(10) /* 0xa */) = cpu.dx;
    // 0052a2de  668b4306               -mov ax, word ptr [ebx + 6]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(6) /* 0x6 */);
    // 0052a2e2  66894608               -mov word ptr [esi + 8], ax
    *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.ax;
    // 0052a2e6  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0052a2e9  c7461c00000000         -mov dword ptr [esi + 0x1c], 0
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 0052a2f0  83c008                 +add eax, 8
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
    // 0052a2f3  894614                 -mov dword ptr [esi + 0x14], eax
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0052a2f6  e925ffffff             -jmp 0x52a220
    goto L_0x0052a220;
L_0x0052a2fb:
    // 0052a2fb  01ff                   -add edi, edi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edi));
    // 0052a2fd  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0052a2ff  0f8e1bffffff           -jle 0x52a220
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052a220;
    }
L_0x0052a305:
    // 0052a305  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0052a308  66c7000000             -mov word ptr [eax], 0
    *app->getMemory<x86::reg16>(cpu.eax) = 0 /*0x0*/;
    // 0052a30d  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0052a310  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0052a313  4f                     -dec edi
    (cpu.edi)--;
    // 0052a314  894610                 -mov dword ptr [esi + 0x10], eax
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0052a317  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0052a319  7fea                   -jg 0x52a305
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0052a305;
    }
    // 0052a31b  e900ffffff             -jmp 0x52a220
    goto L_0x0052a220;
L_0x0052a320:
    // 0052a320  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0052a323  8b5620                 -mov edx, dword ptr [esi + 0x20]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 0052a326  668b00                 -mov ax, word ptr [eax]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.eax);
    // 0052a329  6689449624             -mov word ptr [esi + edx*4 + 0x24], ax
    *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(36) /* 0x24 */ + cpu.edx * 4) = cpu.ax;
    // 0052a32e  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0052a331  8b5620                 -mov edx, dword ptr [esi + 0x20]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 0052a334  668b4002               -mov ax, word ptr [eax + 2]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0052a338  6689449626             -mov word ptr [esi + edx*4 + 0x26], ax
    *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(38) /* 0x26 */ + cpu.edx * 4) = cpu.ax;
    // 0052a33d  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0052a340  8b5e20                 -mov ebx, dword ptr [esi + 0x20]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 0052a343  83c104                 +add ecx, 4
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
    // 0052a346  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0052a347  894e10                 -mov dword ptr [esi + 0x10], ecx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 0052a34a  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0052a34b  895e20                 -mov dword ptr [esi + 0x20], ebx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 0052a34e  e9ddfeffff             -jmp 0x52a230
    goto L_0x0052a230;
}

/* align: skip 0x90 */
void Application::sub_52a354(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052a354  c7421401000000         -mov dword ptr [edx + 0x14], 1
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = 1 /*0x1*/;
    // 0052a35b  c7421c00000000         -mov dword ptr [edx + 0x1c], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 0052a362  c7422000000000         -mov dword ptr [edx + 0x20], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 0052a369  66c742060000           -mov word ptr [edx + 6], 0
    *app->getMemory<x86::reg16>(cpu.edx + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 0052a36f  66c742040000           -mov word ptr [edx + 4], 0
    *app->getMemory<x86::reg16>(cpu.edx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0052a375  66c7420a0000           -mov word ptr [edx + 0xa], 0
    *app->getMemory<x86::reg16>(cpu.edx + x86::reg32(10) /* 0xa */) = 0 /*0x0*/;
    // 0052a37b  66c742080000           -mov word ptr [edx + 8], 0
    *app->getMemory<x86::reg16>(cpu.edx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 0052a381  894a18                 -mov dword ptr [edx + 0x18], ecx
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 0052a384  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0052a388  c702a0a15200           -mov dword ptr [edx], 0x52a1a0
    *app->getMemory<x86::reg32>(cpu.edx) = 5415328 /*0x52a1a0*/;
    // 0052a38e  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0052a392  b890000000             -mov eax, 0x90
    cpu.eax = 144 /*0x90*/;
    // 0052a397  c70200000000           -mov dword ptr [edx], 0
    *app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 0052a39d  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

}
