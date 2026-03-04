#include "softtria.h"
#include <lib/thread.h>

namespace softtria
{

/* align: skip 0x8d 0x40 0x00 */
void sub_a78698(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a78698  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a7869d  e9f6000000             -jmp 0xa78798
    return sub_a78798(app, cpu);
}

/* align: skip 0x8b 0xc0 */
void sub_a786a4(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a786a4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a786a5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a786a6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a786a7  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a786a9  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00a786ae  e875feffff             -call 0xa78528
    cpu.esp -= 4;
    sub_a78528(app, cpu);
    if (cpu.terminate) return;
    // 00a786b3  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a786b5  83f801                 +cmp eax, 1
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
    // 00a786b8  7425                   -je 0xa786df
    if (cpu.flags.zf)
    {
        goto L_0x00a786df;
    }
    // 00a786ba  83f802                 +cmp eax, 2
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
    // 00a786bd  7420                   -je 0xa786df
    if (cpu.flags.zf)
    {
        goto L_0x00a786df;
    }
    // 00a786bf  83f803                 +cmp eax, 3
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
    // 00a786c2  741b                   -je 0xa786df
    if (cpu.flags.zf)
    {
        goto L_0x00a786df;
    }
    // 00a786c4  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00a786c9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a786cb  e810feffff             -call 0xa784e0
    cpu.esp -= 4;
    sub_a784e0(app, cpu);
    if (cpu.terminate) return;
    // 00a786d0  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00a786d5  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00a786d7  ffd1                   -call ecx
    cpu.ip = cpu.ecx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a786d9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a786db  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a786dc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a786dd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a786de  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a786df:
    // 00a786df  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a786e4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a786e5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a786e6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a786e7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a786e8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a786e8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a786e9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a786ea  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a786eb  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a786ed  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00a786ef  83f801                 +cmp eax, 1
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
    // 00a786f2  7c05                   -jl 0xa786f9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a786f9;
    }
    // 00a786f4  83f80c                 +cmp eax, 0xc
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
    // 00a786f7  7e13                   -jle 0xa7870c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a7870c;
    }
L_0x00a786f9:
    // 00a786f9  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 00a786fe  e8bddcffff             -call 0xa763c0
    cpu.esp -= 4;
    sub_a763c0(app, cpu);
    if (cpu.terminate) return;
    // 00a78703  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 00a78708  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78709  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7870a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7870b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a7870c:
    // 00a7870c  c7057cd7a7009886a700   -mov dword ptr [0xa7d77c], 0xa78698
    app->getMemory<x86::reg32>(x86::reg32(10999676) /* 0xa7d77c */) = 10978968 /*0xa78698*/;
    // 00a78716  83f902                 +cmp ecx, 2
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
    // 00a78719  741f                   -je 0xa7873a
    if (cpu.flags.zf)
    {
        goto L_0x00a7873a;
    }
    // 00a7871b  83f903                 +cmp ecx, 3
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
    // 00a7871e  741a                   -je 0xa7873a
    if (cpu.flags.zf)
    {
        goto L_0x00a7873a;
    }
    // 00a78720  e827feffff             -call 0xa7854c
    cpu.esp -= 4;
    sub_a7854c(app, cpu);
    if (cpu.terminate) return;
    // 00a78725  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a78727  7411                   -je 0xa7873a
    if (cpu.flags.zf)
    {
        goto L_0x00a7873a;
    }
    // 00a78729  83fb02                 +cmp ebx, 2
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
    // 00a7872c  750c                   -jne 0xa7873a
    if (!cpu.flags.zf)
    {
        goto L_0x00a7873a;
    }
    // 00a7872e  ba9f000000             -mov edx, 0x9f
    cpu.edx = 159 /*0x9f*/;
    // 00a78733  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a78735  e826210000             -call 0xa7a860
    cpu.esp -= 4;
    sub_a7a860(app, cpu);
    if (cpu.terminate) return;
L_0x00a7873a:
    // 00a7873a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a7873c  e8e7fdffff             -call 0xa78528
    cpu.esp -= 4;
    sub_a78528(app, cpu);
    if (cpu.terminate) return;
    // 00a78741  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a78743  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a78745  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a78747  e894fdffff             -call 0xa784e0
    cpu.esp -= 4;
    sub_a784e0(app, cpu);
    if (cpu.terminate) return;
    // 00a7874c  e8a3feffff             -call 0xa785f4
    cpu.esp -= 4;
    sub_a785f4(app, cpu);
    if (cpu.terminate) return;
    // 00a78751  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a78753  7407                   -je 0xa7875c
    if (cpu.flags.zf)
    {
        goto L_0x00a7875c;
    }
    // 00a78755  e8d2feffff             -call 0xa7862c
    cpu.esp -= 4;
    sub_a7862c(app, cpu);
    if (cpu.terminate) return;
    // 00a7875a  eb05                   -jmp 0xa78761
    goto L_0x00a78761;
L_0x00a7875c:
    // 00a7875c  e8fbfeffff             -call 0xa7865c
    cpu.esp -= 4;
    sub_a7865c(app, cpu);
    if (cpu.terminate) return;
L_0x00a78761:
    // 00a78761  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a78763  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78764  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78765  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78766  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a78798(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00a78798  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a78799  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a7879a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a7879b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a7879d  e886fdffff             -call 0xa78528
    cpu.esp -= 4;
    sub_a78528(app, cpu);
    if (cpu.terminate) return;
    // 00a787a2  8d53ff                 -lea edx, [ebx - 1]
    cpu.edx = x86::reg32(cpu.ebx + x86::reg32(-1) /* -0x1 */);
    // 00a787a5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a787a7  83fa0b                 +cmp edx, 0xb
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
    // 00a787aa  774d                   -ja 0xa787f9
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a787f9;
    }
    // 00a787ac  2eff24956887a700       -jmp dword ptr cs:[edx*4 + 0xa78768]
    cpu.ip = app->getMemory<x86::reg32>(10979176 + cpu.edx * 4); goto dynamic_jump;
  case 0x00a787b4:
    // 00a787b4  b88c000000             -mov eax, 0x8c
    cpu.eax = 140 /*0x8c*/;
    // 00a787b9  e8e6feffff             -call 0xa786a4
    cpu.esp -= 4;
    sub_a786a4(app, cpu);
    if (cpu.terminate) return;
    // 00a787be  eb42                   -jmp 0xa78802
    goto L_0x00a78802;
  case 0x00a787c0:
    // 00a787c0  83f802                 +cmp eax, 2
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
    // 00a787c3  7505                   -jne 0xa787ca
    if (!cpu.flags.zf)
    {
        goto L_0x00a787ca;
    }
    // 00a787c5  e87e200000             -call 0xa7a848
    cpu.esp -= 4;
    sub_a7a848(app, cpu);
    if (cpu.terminate) return;
  [[fallthrough]];
  case 0x00a787ca:
L_0x00a787ca:
    // 00a787ca  83f901                 +cmp ecx, 1
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
    // 00a787cd  741a                   -je 0xa787e9
    if (cpu.flags.zf)
    {
        goto L_0x00a787e9;
    }
    // 00a787cf  83f902                 +cmp ecx, 2
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
    // 00a787d2  7415                   -je 0xa787e9
    if (cpu.flags.zf)
    {
        goto L_0x00a787e9;
    }
    // 00a787d4  83f903                 +cmp ecx, 3
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
    // 00a787d7  7410                   -je 0xa787e9
    if (cpu.flags.zf)
    {
        goto L_0x00a787e9;
    }
    // 00a787d9  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00a787de  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a787e0  e8fbfcffff             -call 0xa784e0
    cpu.esp -= 4;
    sub_a784e0(app, cpu);
    if (cpu.terminate) return;
    // 00a787e5  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a787e7  ffd1                   -call ecx
    cpu.ip = cpu.ecx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a787e9:
    // 00a787e9  e806feffff             -call 0xa785f4
    cpu.esp -= 4;
    sub_a785f4(app, cpu);
    if (cpu.terminate) return;
    // 00a787ee  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a787f0  7510                   -jne 0xa78802
    if (!cpu.flags.zf)
    {
        goto L_0x00a78802;
    }
    // 00a787f2  e865feffff             -call 0xa7865c
    cpu.esp -= 4;
    sub_a7865c(app, cpu);
    if (cpu.terminate) return;
    // 00a787f7  eb09                   -jmp 0xa78802
    goto L_0x00a78802;
L_0x00a787f9:
    // 00a787f9  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a787fe  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a787ff  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78800  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78801  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a78802:
    // 00a78802  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a78804  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78805  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78806  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78807  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void sub_a78808(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a78808  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a78809  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a7880a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a7880b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a7880c  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a7880d  ba08000000             -mov edx, 8
    cpu.edx = 8 /*0x8*/;
L_0x00a78812:
    // 00a78812  ff1594d2a700           -call dword ptr [0xa7d294]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10998420) /* 0xa7d294 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a78818  8d3410                 -lea esi, [eax + edx]
    cpu.esi = x86::reg32(cpu.eax + cpu.edx * 1);
    // 00a7881b  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a7881d  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a7881f  8d7e58                 -lea edi, [esi + 0x58]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(88) /* 0x58 */);
    // 00a78822  8db2e8d5a700           -lea esi, [edx + 0xa7d5e8]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(10999272) /* 0xa7d5e8 */);
    // 00a78828  83c208                 -add edx, 8
    (cpu.edx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a7882b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a7882c  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a7882d  83fa68                 +cmp edx, 0x68
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
    // 00a78830  75e0                   -jne 0xa78812
    if (!cpu.flags.zf)
    {
        goto L_0x00a78812;
    }
    // 00a78832  ba7085a700             -mov edx, 0xa78570
    cpu.edx = 10978672 /*0xa78570*/;
    // 00a78837  bb9887a700             -mov ebx, 0xa78798
    cpu.ebx = 10979224 /*0xa78798*/;
    // 00a7883c  8915a0d3a700           -mov dword ptr [0xa7d3a0], edx
    app->getMemory<x86::reg32>(x86::reg32(10998688) /* 0xa7d3a0 */) = cpu.edx;
    // 00a78842  891da4d3a700           -mov dword ptr [0xa7d3a4], ebx
    app->getMemory<x86::reg32>(x86::reg32(10998692) /* 0xa7d3a4 */) = cpu.ebx;
    // 00a78848  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a78849  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7884a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7884b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7884c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7884d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a78850(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a78850  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a78851  e89efdffff             -call 0xa785f4
    cpu.esp -= 4;
    sub_a785f4(app, cpu);
    if (cpu.terminate) return;
    // 00a78856  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a78858  7423                   -je 0xa7887d
    if (cpu.flags.zf)
    {
        goto L_0x00a7887d;
    }
    // 00a7885a  e8fdfdffff             -call 0xa7865c
    cpu.esp -= 4;
    sub_a7865c(app, cpu);
    if (cpu.terminate) return;
    // 00a7885f  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00a78864  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00a78869  e872fcffff             -call 0xa784e0
    cpu.esp -= 4;
    sub_a784e0(app, cpu);
    if (cpu.terminate) return;
    // 00a7886e  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00a78873  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 00a78878  e863fcffff             -call 0xa784e0
    cpu.esp -= 4;
    sub_a784e0(app, cpu);
    if (cpu.terminate) return;
L_0x00a7887d:
    // 00a7887d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7887e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a78880(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a78880  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a78881  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a78882  ba0888a700             -mov edx, 0xa78808
    cpu.edx = 10979336 /*0xa78808*/;
    // 00a78887  bb5088a700             -mov ebx, 0xa78850
    cpu.ebx = 10979408 /*0xa78850*/;
    // 00a7888c  8915d4d2a700           -mov dword ptr [0xa7d2d4], edx
    app->getMemory<x86::reg32>(x86::reg32(10998484) /* 0xa7d2d4 */) = cpu.edx;
    // 00a78892  891dd8d2a700           -mov dword ptr [0xa7d2d8], ebx
    app->getMemory<x86::reg32>(x86::reg32(10998488) /* 0xa7d2d8 */) = cpu.ebx;
    // 00a78898  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78899  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7889a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void sub_a788a0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a788a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a788a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a788a2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a788a3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a788a4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a788a5  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00a788a8  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a788aa  83f8ff                 +cmp eax, -1
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
    // 00a788ad  750e                   -jne 0xa788bd
    if (!cpu.flags.zf)
    {
        goto L_0x00a788bd;
    }
    // 00a788af  2eff15b4bda700         -call dword ptr cs:[0xa7bdb4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993076) /* 0xa7bdb4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a788b6  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a788b8  e998000000             -jmp 0xa78955
    goto L_0x00a78955;
L_0x00a788bd:
    // 00a788bd  83f8fe                 +cmp eax, -2
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
    // 00a788c0  750e                   -jne 0xa788d0
    if (!cpu.flags.zf)
    {
        goto L_0x00a788d0;
    }
    // 00a788c2  2eff15f4bda700         -call dword ptr cs:[0xa7bdf4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993140) /* 0xa7bdf4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a788c9  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a788cb  e985000000             -jmp 0xa78955
    goto L_0x00a78955;
L_0x00a788d0:
    // 00a788d0  83f8fd                 +cmp eax, -3
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
    // 00a788d3  7526                   -jne 0xa788fb
    if (!cpu.flags.zf)
    {
        goto L_0x00a788fb;
    }
    // 00a788d5  bb01010000             -mov ebx, 0x101
    cpu.ebx = 257 /*0x101*/;
    // 00a788da  b8000ea800             -mov eax, 0xa80e00
    cpu.eax = 11013632 /*0xa80e00*/;
    // 00a788df  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a788e1  e88ab2ffff             -call 0xa73b70
    cpu.esp -= 4;
    sub_a73b70(app, cpu);
    if (cpu.terminate) return;
    // 00a788e6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a788e8  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a788ea  8915f00da800           -mov dword ptr [0xa80df0], edx
    app->getMemory<x86::reg32>(x86::reg32(11013616) /* 0xa80df0 */) = cpu.edx;
    // 00a788f0  891554d6a700           -mov dword ptr [0xa7d654], edx
    app->getMemory<x86::reg32>(x86::reg32(10999380) /* 0xa7d654 */) = cpu.edx;
    // 00a788f6  e9ff000000             -jmp 0xa789fa
    goto L_0x00a789fa;
L_0x00a788fb:
    // 00a788fb  83f8fc                 +cmp eax, -4
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
    // 00a788fe  7555                   -jne 0xa78955
    if (!cpu.flags.zf)
    {
        goto L_0x00a78955;
    }
    // 00a78900  bb01010000             -mov ebx, 0x101
    cpu.ebx = 257 /*0x101*/;
    // 00a78905  b8000ea800             -mov eax, 0xa80e00
    cpu.eax = 11013632 /*0xa80e00*/;
    // 00a7890a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a7890c  e85fb2ffff             -call 0xa73b70
    cpu.esp -= 4;
    sub_a73b70(app, cpu);
    if (cpu.terminate) return;
    // 00a78911  b881000000             -mov eax, 0x81
    cpu.eax = 129 /*0x81*/;
    // 00a78916  b201                   -mov dl, 1
    cpu.dl = 1 /*0x1*/;
L_0x00a78918:
    // 00a78918  40                     -inc eax
    (cpu.eax)++;
    // 00a78919  8890000ea800           -mov byte ptr [eax + 0xa80e00], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(11013632) /* 0xa80e00 */) = cpu.dl;
    // 00a7891f  3d9f000000             +cmp eax, 0x9f
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
    // 00a78924  7ef2                   -jle 0xa78918
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a78918;
    }
    // 00a78926  b8e0000000             -mov eax, 0xe0
    cpu.eax = 224 /*0xe0*/;
    // 00a7892b  b601                   -mov dh, 1
    cpu.dh = 1 /*0x1*/;
L_0x00a7892d:
    // 00a7892d  40                     -inc eax
    (cpu.eax)++;
    // 00a7892e  88b0000ea800           -mov byte ptr [eax + 0xa80e00], dh
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(11013632) /* 0xa80e00 */) = cpu.dh;
    // 00a78934  3dfc000000             +cmp eax, 0xfc
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
    // 00a78939  7ef2                   -jle 0xa7892d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a7892d;
    }
    // 00a7893b  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 00a78940  b8a4030000             -mov eax, 0x3a4
    cpu.eax = 932 /*0x3a4*/;
    // 00a78945  892df00da800           -mov dword ptr [0xa80df0], ebp
    app->getMemory<x86::reg32>(x86::reg32(11013616) /* 0xa80df0 */) = cpu.ebp;
    // 00a7894b  a354d6a700             -mov dword ptr [0xa7d654], eax
    app->getMemory<x86::reg32>(x86::reg32(10999380) /* 0xa7d654 */) = cpu.eax;
    // 00a78950  e9a3000000             -jmp 0xa789f8
    goto L_0x00a789f8;
L_0x00a78955:
    // 00a78955  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a78957  7505                   -jne 0xa7895e
    if (!cpu.flags.zf)
    {
        goto L_0x00a7895e;
    }
    // 00a78959  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
L_0x00a7895e:
    // 00a7895e  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a78960  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a78961  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a78962  2eff15b8bda700         -call dword ptr cs:[0xa7bdb8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993080) /* 0xa7bdb8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a78969  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a7896b  750e                   -jne 0xa7897b
    if (!cpu.flags.zf)
    {
        goto L_0x00a7897b;
    }
    // 00a7896d  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a78972  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00a78975  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78976  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78977  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78978  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78979  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7897a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a7897b:
    // 00a7897b  bb01010000             -mov ebx, 0x101
    cpu.ebx = 257 /*0x101*/;
    // 00a78980  b8000ea800             -mov eax, 0xa80e00
    cpu.eax = 11013632 /*0xa80e00*/;
    // 00a78985  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a78987  e8e4b1ffff             -call 0xa73b70
    cpu.esp -= 4;
    sub_a73b70(app, cpu);
    if (cpu.terminate) return;
    // 00a7898c  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a7898e  8a642406               -mov ah, byte ptr [esp + 6]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(6) /* 0x6 */);
    // 00a78992  890df00da800           -mov dword ptr [0xa80df0], ecx
    app->getMemory<x86::reg32>(x86::reg32(11013616) /* 0xa80df0 */) = cpu.ecx;
    // 00a78998  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 00a7899a  740a                   -je 0xa789a6
    if (cpu.flags.zf)
    {
        goto L_0x00a789a6;
    }
    // 00a7899c  c705f00da80001000000   -mov dword ptr [0xa80df0], 1
    app->getMemory<x86::reg32>(x86::reg32(11013616) /* 0xa80df0 */) = 1 /*0x1*/;
L_0x00a789a6:
    // 00a789a6  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00a789a8  b101                   -mov cl, 1
    cpu.cl = 1 /*0x1*/;
    // 00a789aa  eb1c                   -jmp 0xa789c8
    goto L_0x00a789c8;
L_0x00a789ac:
    // 00a789ac  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a789ae  8a441c06               -mov al, byte ptr [esp + ebx + 6]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(6) /* 0x6 */ + cpu.ebx * 1);
    // 00a789b2  eb07                   -jmp 0xa789bb
    goto L_0x00a789bb;
L_0x00a789b4:
    // 00a789b4  40                     -inc eax
    (cpu.eax)++;
    // 00a789b5  8888000ea800           -mov byte ptr [eax + 0xa80e00], cl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(11013632) /* 0xa80e00 */) = cpu.cl;
L_0x00a789bb:
    // 00a789bb  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a789bd  8a541c07               -mov dl, byte ptr [esp + ebx + 7]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(7) /* 0x7 */ + cpu.ebx * 1);
    // 00a789c1  39d0                   +cmp eax, edx
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
    // 00a789c3  7eef                   -jle 0xa789b4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a789b4;
    }
    // 00a789c5  83c302                 -add ebx, 2
    (cpu.ebx) += x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x00a789c8:
    // 00a789c8  807c1c0600             +cmp byte ptr [esp + ebx + 6], 0
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
    // 00a789cd  75dd                   -jne 0xa789ac
    if (!cpu.flags.zf)
    {
        goto L_0x00a789ac;
    }
    // 00a789cf  807c1c0700             +cmp byte ptr [esp + ebx + 7], 0
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
    // 00a789d4  75d6                   -jne 0xa789ac
    if (!cpu.flags.zf)
    {
        goto L_0x00a789ac;
    }
    // 00a789d6  83fe01                 +cmp esi, 1
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
    // 00a789d9  7517                   -jne 0xa789f2
    if (!cpu.flags.zf)
    {
        goto L_0x00a789f2;
    }
    // 00a789db  2eff15f4bda700         -call dword ptr cs:[0xa7bdf4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993140) /* 0xa7bdf4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a789e2  a354d6a700             -mov dword ptr [0xa7d654], eax
    app->getMemory<x86::reg32>(x86::reg32(10999380) /* 0xa7d654 */) = cpu.eax;
    // 00a789e7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a789e9  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00a789ec  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a789ed  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a789ee  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a789ef  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a789f0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a789f1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a789f2:
    // 00a789f2  893554d6a700           -mov dword ptr [0xa7d654], esi
    app->getMemory<x86::reg32>(x86::reg32(10999380) /* 0xa7d654 */) = cpu.esi;
L_0x00a789f8:
    // 00a789f8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00a789fa:
    // 00a789fa  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00a789fd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a789fe  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a789ff  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78a00  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78a01  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78a02  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void sub_a78a04(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a78a04  09d2                   +or edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx |= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a78a06  781e                   -js 0xa78a26
    if (cpu.flags.sf)
    {
        goto L_0x00a78a26;
    }
    // 00a78a08  09c9                   +or ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00a78a0a  7806                   -js 0xa78a12
    if (cpu.flags.sf)
    {
        goto L_0x00a78a12;
    }
    // 00a78a0c  e848000000             -call 0xa78a59
    cpu.esp -= 4;
    sub_a78a59(app, cpu);
    if (cpu.terminate) return;
    // 00a78a11  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a78a12:
    // 00a78a12  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00a78a14  f7db                   +neg ebx
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
    // 00a78a16  83d900                 -sbb ecx, 0
    (cpu.ecx) -= x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 00a78a19  e83b000000             -call 0xa78a59
    cpu.esp -= 4;
    sub_a78a59(app, cpu);
    if (cpu.terminate) return;
    // 00a78a1e  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 00a78a20  f7d8                   +neg eax
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
    // 00a78a22  83da00                 -sbb edx, 0
    (cpu.edx) -= x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 00a78a25  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a78a26:
    // 00a78a26  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 00a78a28  f7d8                   +neg eax
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
    // 00a78a2a  83da00                 -sbb edx, 0
    (cpu.edx) -= x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 00a78a2d  09c9                   +or ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00a78a2f  7914                   -jns 0xa78a45
    if (!cpu.flags.sf)
    {
        goto L_0x00a78a45;
    }
    // 00a78a31  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00a78a33  f7db                   +neg ebx
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
    // 00a78a35  83d900                 -sbb ecx, 0
    (cpu.ecx) -= x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 00a78a38  e81c000000             -call 0xa78a59
    cpu.esp -= 4;
    sub_a78a59(app, cpu);
    if (cpu.terminate) return;
    // 00a78a3d  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00a78a3f  f7db                   +neg ebx
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
    // 00a78a41  83d900                 -sbb ecx, 0
    (cpu.ecx) -= x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 00a78a44  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a78a45:
    // 00a78a45  e80f000000             -call 0xa78a59
    cpu.esp -= 4;
    sub_a78a59(app, cpu);
    if (cpu.terminate) return;
    // 00a78a4a  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00a78a4c  f7db                   +neg ebx
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
    // 00a78a4e  83d900                 -sbb ecx, 0
    (cpu.ecx) -= x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 00a78a51  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 00a78a53  f7d8                   +neg eax
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
    // 00a78a55  83da00                 -sbb edx, 0
    (cpu.edx) -= x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 00a78a58  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a78a59(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a78a59  09c9                   +or ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00a78a5b  751a                   -jne 0xa78a77
    if (!cpu.flags.zf)
    {
        goto L_0x00a78a77;
    }
    // 00a78a5d  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a78a5e  7416                   -je 0xa78a76
    if (cpu.flags.zf)
    {
        goto L_0x00a78a76;
    }
    // 00a78a60  43                     -inc ebx
    (cpu.ebx)++;
    // 00a78a61  39d3                   +cmp ebx, edx
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
    // 00a78a63  7709                   -ja 0xa78a6e
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a78a6e;
    }
    // 00a78a65  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a78a67  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a78a69  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a78a6b  f7f3                   -div ebx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ebx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00a78a6d  91                     -xchg ecx, eax
    {
        x86::reg32 tmp = cpu.ecx;
        cpu.ecx = cpu.eax;
        cpu.eax = tmp;
    }
L_0x00a78a6e:
    // 00a78a6e  f7f3                   -div ebx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ebx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00a78a70  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00a78a72  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a78a74  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00a78a76:
    // 00a78a76  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a78a77:
    // 00a78a77  39d1                   +cmp ecx, edx
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
    // 00a78a79  721c                   -jb 0xa78a97
    if (cpu.flags.cf)
    {
        goto L_0x00a78a97;
    }
    // 00a78a7b  7512                   -jne 0xa78a8f
    if (!cpu.flags.zf)
    {
        goto L_0x00a78a8f;
    }
    // 00a78a7d  39c3                   +cmp ebx, eax
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
    // 00a78a7f  770e                   -ja 0xa78a8f
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a78a8f;
    }
    // 00a78a81  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a78a83  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a78a85  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a78a87  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a78a89  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a78a8e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a78a8f:
    // 00a78a8f  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a78a91  29db                   -sub ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a78a93  93                     -xchg ebx, eax
    {
        x86::reg32 tmp = cpu.ebx;
        cpu.ebx = cpu.eax;
        cpu.eax = tmp;
    }
    // 00a78a94  87ca                   -xchg edx, ecx
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.ecx;
        cpu.ecx = tmp;
    }
    // 00a78a96  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a78a97:
    // 00a78a97  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a78a98  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a78a99  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a78a9a  29f6                   -sub esi, esi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00a78a9c  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 00a78a9e  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
L_0x00a78aa0:
    // 00a78aa0  01db                   +add ebx, ebx
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
    // 00a78aa2  11c9                   +adc ecx, ecx
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
    // 00a78aa4  7213                   -jb 0xa78ab9
    if (cpu.flags.cf)
    {
        goto L_0x00a78ab9;
    }
    // 00a78aa6  45                     -inc ebp
    (cpu.ebp)++;
    // 00a78aa7  39d1                   +cmp ecx, edx
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
    // 00a78aa9  72f5                   -jb 0xa78aa0
    if (cpu.flags.cf)
    {
        goto L_0x00a78aa0;
    }
    // 00a78aab  7704                   -ja 0xa78ab1
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a78ab1;
    }
    // 00a78aad  39c3                   +cmp ebx, eax
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
    // 00a78aaf  76ef                   -jbe 0xa78aa0
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a78aa0;
    }
L_0x00a78ab1:
    // 00a78ab1  f8                     +clc 
    cpu.flags.cf = 0;
L_0x00a78ab2:
    // 00a78ab2  11f6                   +adc esi, esi
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
    // 00a78ab4  11ff                   +adc edi, edi
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
    // 00a78ab6  4d                     +dec ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a78ab7  7822                   -js 0xa78adb
    if (cpu.flags.sf)
    {
        goto L_0x00a78adb;
    }
L_0x00a78ab9:
    // 00a78ab9  d1d9                   +rcr ecx, 1
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
    // 00a78abb  d1db                   -rcr ebx, 1
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
    // 00a78abd  29d8                   +sub eax, ebx
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
    // 00a78abf  19ca                   +sbb edx, ecx
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
    // 00a78ac1  f5                     +cmc 
    cpu.flags.cf ^= 1;
    // 00a78ac2  72ee                   -jb 0xa78ab2
    if (cpu.flags.cf)
    {
        goto L_0x00a78ab2;
    }
L_0x00a78ac4:
    // 00a78ac4  01f6                   +add esi, esi
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
    // 00a78ac6  11ff                   +adc edi, edi
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
    // 00a78ac8  4d                     +dec ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a78ac9  780c                   -js 0xa78ad7
    if (cpu.flags.sf)
    {
        goto L_0x00a78ad7;
    }
    // 00a78acb  d1e9                   +shr ecx, 1
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
    // 00a78acd  d1db                   -rcr ebx, 1
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
    // 00a78acf  01d8                   +add eax, ebx
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
    // 00a78ad1  11ca                   +adc edx, ecx
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
    // 00a78ad3  73ef                   -jae 0xa78ac4
    if (!cpu.flags.cf)
    {
        goto L_0x00a78ac4;
    }
    // 00a78ad5  ebdb                   -jmp 0xa78ab2
    goto L_0x00a78ab2;
L_0x00a78ad7:
    // 00a78ad7  01d8                   +add eax, ebx
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
    // 00a78ad9  11ca                   -adc edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
L_0x00a78adb:
    // 00a78adb  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a78add  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00a78adf  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a78ae1  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00a78ae3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78ae4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78ae5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78ae6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a78ae7(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a78ae7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a78ae8  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00a78aea  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a78aeb  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a78aec  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a78aed  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a78aee  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00a78af1  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a78af3  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00a78af5  81fa00200000           +cmp edx, 0x2000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8192 /*0x2000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a78afb  7c05                   -jl 0xa78b02
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a78b02;
    }
    // 00a78afd  be00200000             -mov esi, 0x2000
    cpu.esi = 8192 /*0x2000*/;
L_0x00a78b02:
    // 00a78b02  b958d6a700             -mov ecx, 0xa7d658
    cpu.ecx = 10999384 /*0xa7d658*/;
    // 00a78b07  eb2e                   -jmp 0xa78b37
    goto L_0x00a78b37;
L_0x00a78b09:
    // 00a78b09  66f7c60100             +test si, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.si & 1 /*0x1*/));
    // 00a78b0e  7422                   -je 0xa78b32
    if (cpu.flags.zf)
    {
        goto L_0x00a78b32;
    }
    // 00a78b10  668b4108               -mov ax, word ptr [ecx + 8]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00a78b14  668945ec               -mov word ptr [ebp - 0x14], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ax;
    // 00a78b18  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00a78b1b  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
    // 00a78b1e  8d55e4                 -lea edx, [ebp - 0x1c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00a78b21  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00a78b23  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00a78b25  8945e4                 -mov dword ptr [ebp - 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.eax;
    // 00a78b28  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a78b2a  db28                   -fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 00a78b2c  db2a                   -fld xword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 00a78b2e  dec9                   -fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00a78b30  db3b                   -fstp xword ptr [ebx]
    app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x00a78b32:
    // 00a78b32  d1fe                   -sar esi, 1
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (1 /*0x1*/ % 32));
    // 00a78b34  83c10a                 -add ecx, 0xa
    (cpu.ecx) += x86::reg32(x86::sreg32(10 /*0xa*/));
L_0x00a78b37:
    // 00a78b37  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a78b39  7fce                   -jg 0xa78b09
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a78b09;
    }
    // 00a78b3b  8d65f0                 -lea esp, [ebp - 0x10]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a78b3e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78b3f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78b40  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78b41  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78b42  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78b43  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a78b3b(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a78b3b;
    // 00a78ae7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a78ae8  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00a78aea  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a78aeb  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a78aec  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a78aed  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a78aee  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00a78af1  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a78af3  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00a78af5  81fa00200000           +cmp edx, 0x2000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8192 /*0x2000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a78afb  7c05                   -jl 0xa78b02
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a78b02;
    }
    // 00a78afd  be00200000             -mov esi, 0x2000
    cpu.esi = 8192 /*0x2000*/;
L_0x00a78b02:
    // 00a78b02  b958d6a700             -mov ecx, 0xa7d658
    cpu.ecx = 10999384 /*0xa7d658*/;
    // 00a78b07  eb2e                   -jmp 0xa78b37
    goto L_0x00a78b37;
L_0x00a78b09:
    // 00a78b09  66f7c60100             +test si, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.si & 1 /*0x1*/));
    // 00a78b0e  7422                   -je 0xa78b32
    if (cpu.flags.zf)
    {
        goto L_0x00a78b32;
    }
    // 00a78b10  668b4108               -mov ax, word ptr [ecx + 8]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00a78b14  668945ec               -mov word ptr [ebp - 0x14], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ax;
    // 00a78b18  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00a78b1b  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
    // 00a78b1e  8d55e4                 -lea edx, [ebp - 0x1c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00a78b21  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00a78b23  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00a78b25  8945e4                 -mov dword ptr [ebp - 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.eax;
    // 00a78b28  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a78b2a  db28                   -fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 00a78b2c  db2a                   -fld xword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 00a78b2e  dec9                   -fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00a78b30  db3b                   -fstp xword ptr [ebx]
    app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x00a78b32:
    // 00a78b32  d1fe                   -sar esi, 1
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (1 /*0x1*/ % 32));
    // 00a78b34  83c10a                 -add ecx, 0xa
    (cpu.ecx) += x86::reg32(x86::sreg32(10 /*0xa*/));
L_0x00a78b37:
    // 00a78b37  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a78b39  7fce                   -jg 0xa78b09
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a78b09;
    }
L_entry_0x00a78b3b:
    // 00a78b3b  8d65f0                 -lea esp, [ebp - 0x10]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a78b3e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78b3f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78b40  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78b41  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78b42  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78b43  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a78b44(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a78b44  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a78b45  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00a78b47  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a78b48  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a78b49  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a78b4a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a78b4b  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00a78b4e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a78b50  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a78b52  74e7                   -je 0xa78b3b
    if (cpu.flags.zf)
    {
        return sub_a78b3b(app, cpu);
    }
    // 00a78b54  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a78b56  9b                     -wait 
    /*nothing*/;
    // 00a78b57  d93c24                 -fnstcw word ptr [esp]
    app->getMemory<x86::reg16>(cpu.esp) = cpu.fpu.control.word;
    // 00a78b5a  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78b5b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a78b5d  80cc03                 -or ah, 3
    cpu.ah |= x86::reg8(x86::sreg8(3 /*0x3*/));
    // 00a78b60  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00a78b65  bbff3f0000             -mov ebx, 0x3fff
    cpu.ebx = 16383 /*0x3fff*/;
    // 00a78b6a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a78b6b  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 00a78b6e  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78b6f  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00a78b71  66895dec               -mov word ptr [ebp - 0x14], bx
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.bx;
    // 00a78b75  bb00000080             -mov ebx, 0x80000000
    cpu.ebx = 2147483648 /*0x80000000*/;
    // 00a78b7a  897de4                 -mov dword ptr [ebp - 0x1c], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.edi;
    // 00a78b7d  895de8                 -mov dword ptr [ebp - 0x18], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.ebx;
    // 00a78b80  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a78b82  7d1b                   -jge 0xa78b9f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a78b9f;
    }
    // 00a78b84  8d45e4                 -lea eax, [ebp - 0x1c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00a78b87  f7da                   +neg edx
    {
        x86::reg32 tmp1 = 0;
        x86::reg32& tmp2 = cpu.edx;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp2 = result;
        cpu.set_szp(tmp2);
    }
    // 00a78b89  e859ffffff             -call 0xa78ae7
    cpu.esp -= 4;
    sub_a78ae7(app, cpu);
    if (cpu.terminate) return;
    // 00a78b8e  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00a78b90  8d55e4                 -lea edx, [ebp - 0x1c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00a78b93  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a78b95  db28                   +fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 00a78b97  db2a                   +fld xword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 00a78b99  def9                   +fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00a78b9b  db3b                   +fstp xword ptr [ebx]
    app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a78b9d  eb17                   -jmp 0xa78bb6
    goto L_0x00a78bb6;
L_0x00a78b9f:
    // 00a78b9f  8d45e4                 -lea eax, [ebp - 0x1c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00a78ba2  e840ffffff             -call 0xa78ae7
    cpu.esp -= 4;
    sub_a78ae7(app, cpu);
    if (cpu.terminate) return;
    // 00a78ba7  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00a78ba9  8d55e4                 -lea edx, [ebp - 0x1c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00a78bac  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a78bae  db28                   -fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 00a78bb0  db2a                   -fld xword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 00a78bb2  dec9                   -fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00a78bb4  db3b                   -fstp xword ptr [ebx]
    app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x00a78bb6:
    // 00a78bb6  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a78bb8  6689f0                 -mov ax, si
    cpu.ax = cpu.si;
    // 00a78bbb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a78bbc  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 00a78bbf  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78bc0  e976ffffff             -jmp 0xa78b3b
    return sub_a78b3b(app, cpu);
}

/* align: skip  */
void sub_a78bc5(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a78bc5  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a78bc6  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a78bc7  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a78bc9  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00a78bcb  81fa00100000           +cmp edx, 0x1000
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
    // 00a78bd1  7e12                   -jle 0xa78be5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a78be5;
    }
    // 00a78bd3  ba00100000             -mov edx, 0x1000
    cpu.edx = 4096 /*0x1000*/;
    // 00a78bd8  e867ffffff             -call 0xa78b44
    cpu.esp -= 4;
    sub_a78b44(app, cpu);
    if (cpu.terminate) return;
    // 00a78bdd  81eb00100000           +sub ebx, 0x1000
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
    // 00a78be3  eb18                   -jmp 0xa78bfd
    goto L_0x00a78bfd;
L_0x00a78be5:
    // 00a78be5  81fa00f0ffff           +cmp edx, 0xfffff000
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
    // 00a78beb  7d10                   -jge 0xa78bfd
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a78bfd;
    }
    // 00a78bed  ba00f0ffff             -mov edx, 0xfffff000
    cpu.edx = 4294963200 /*0xfffff000*/;
    // 00a78bf2  e84dffffff             -call 0xa78b44
    cpu.esp -= 4;
    sub_a78b44(app, cpu);
    if (cpu.terminate) return;
    // 00a78bf7  81c300100000           -add ebx, 0x1000
    (cpu.ebx) += x86::reg32(x86::sreg32(4096 /*0x1000*/));
L_0x00a78bfd:
    // 00a78bfd  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00a78bff  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a78c01  e83effffff             -call 0xa78b44
    cpu.esp -= 4;
    sub_a78b44(app, cpu);
    if (cpu.terminate) return;
    // 00a78c06  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78c07  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78c08  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
/* data blob: 8bc0b28ca700ee8ca700c08ca700de8ca700b28ca700 */
void sub_a78c1f(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00a78c1f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a78c20  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00a78c22  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a78c23  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a78c24  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a78c25  81ec8c000000           -sub esp, 0x8c
    (cpu.esp) -= x86::reg32(x86::sreg32(140 /*0x8c*/));
    // 00a78c2b  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a78c2d  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00a78c2f  895de0                 -mov dword ptr [ebp - 0x20], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.ebx;
    // 00a78c32  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a78c34  9b                     -wait 
    /*nothing*/;
    // 00a78c35  d93c24                 -fnstcw word ptr [esp]
    app->getMemory<x86::reg16>(cpu.esp) = cpu.fpu.control.word;
    // 00a78c38  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78c39  8945ec                 -mov dword ptr [ebp - 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
    // 00a78c3c  80cc03                 -or ah, 3
    cpu.ah |= x86::reg8(x86::sreg8(3 /*0x3*/));
    // 00a78c3f  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00a78c44  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a78c45  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 00a78c48  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78c49  c7421400000000         -mov dword ptr [edx + 0x14], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 00a78c50  668b4708               -mov ax, word ptr [edi + 8]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 00a78c54  668945d4               -mov word ptr [ebp - 0x2c], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-44) /* -0x2c */) = cpu.ax;
    // 00a78c58  8b4704                 -mov eax, dword ptr [edi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00a78c5b  8945d0                 -mov dword ptr [ebp - 0x30], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */) = cpu.eax;
    // 00a78c5e  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 00a78c60  8945cc                 -mov dword ptr [ebp - 0x34], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-52) /* -0x34 */) = cpu.eax;
    // 00a78c63  f645d580               +test byte ptr [ebp - 0x2b], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-43) /* -0x2b */) & 128 /*0x80*/));
    // 00a78c67  7407                   -je 0xa78c70
    if (cpu.flags.zf)
    {
        goto L_0x00a78c70;
    }
    // 00a78c69  c74214ffffffff         -mov dword ptr [edx + 0x14], 0xffffffff
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = 4294967295 /*0xffffffff*/;
L_0x00a78c70:
    // 00a78c70  8065d57f               -and byte ptr [ebp - 0x2b], 0x7f
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-43) /* -0x2b */) &= x86::reg8(x86::sreg8(127 /*0x7f*/));
    // 00a78c74  c7461c00000000         -mov dword ptr [esi + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 00a78c7b  c7462000000000         -mov dword ptr [esi + 0x20], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 00a78c82  c7462400000000         -mov dword ptr [esi + 0x24], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 00a78c89  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00a78c8c  c7462800000000         -mov dword ptr [esi + 0x28], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
    // 00a78c93  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00a78c95  c7461800000000         -mov dword ptr [esi + 0x18], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 00a78c9c  e80b1c0000             -call 0xa7a8ac
    cpu.esp -= 4;
    sub_a7a8ac(app, cpu);
    if (cpu.terminate) return;
    // 00a78ca1  83f804                 +cmp eax, 4
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
    // 00a78ca4  0f8749010000           -ja 0xa78df3
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a78df3;
    }
    // 00a78caa  2eff24850b8ca700       -jmp dword ptr cs:[eax*4 + 0xa78c0b]
    cpu.ip = app->getMemory<x86::reg32>(10980363 + cpu.eax * 4); goto dynamic_jump;
  case 0x00a78cb2:
    // 00a78cb2  c7461400000000         -mov dword ptr [esi + 0x14], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
L_0x00a78cb9:
    // 00a78cb9  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00a78cbb  e933010000             -jmp 0xa78df3
    goto L_0x00a78df3;
  case 0x00a78cc0:
    // 00a78cc0  8b45e0                 -mov eax, dword ptr [ebp - 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00a78cc3  c6006e                 -mov byte ptr [eax], 0x6e
    app->getMemory<x86::reg8>(cpu.eax) = 110 /*0x6e*/;
    // 00a78cc6  c6400161               -mov byte ptr [eax + 1], 0x61
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = 97 /*0x61*/;
    // 00a78cca  c640026e               -mov byte ptr [eax + 2], 0x6e
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */) = 110 /*0x6e*/;
L_0x00a78cce:
    // 00a78cce  c6400300               -mov byte ptr [eax + 3], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */) = 0 /*0x0*/;
    // 00a78cd2  c7461c03000000         -mov dword ptr [esi + 0x1c], 3
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = 3 /*0x3*/;
    // 00a78cd9  e970030000             -jmp 0xa7904e
    return sub_a7904e(app, cpu);
  case 0x00a78cde:
    // 00a78cde  8b45e0                 -mov eax, dword ptr [ebp - 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00a78ce1  c60069                 -mov byte ptr [eax], 0x69
    app->getMemory<x86::reg8>(cpu.eax) = 105 /*0x69*/;
    // 00a78ce4  c640016e               -mov byte ptr [eax + 1], 0x6e
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = 110 /*0x6e*/;
    // 00a78ce8  c6400266               -mov byte ptr [eax + 2], 0x66
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */) = 102 /*0x66*/;
    // 00a78cec  ebe0                   -jmp 0xa78cce
    goto L_0x00a78cce;
  case 0x00a78cee:
    // 00a78cee  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a78cf0  668b4dd4               -mov cx, word ptr [ebp - 0x2c]
    cpu.cx = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 00a78cf4  81e9fe3f0000           -sub ecx, 0x3ffe
    (cpu.ecx) -= x86::reg32(x86::sreg32(16382 /*0x3ffe*/));
    // 00a78cfa  69d197750000           -imul edx, ecx, 0x7597
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(30103 /*0x7597*/)));
    // 00a78d00  bba0860100             -mov ebx, 0x186a0
    cpu.ebx = 100000 /*0x186a0*/;
    // 00a78d05  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a78d07  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00a78d0a  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00a78d0c  8d48fc                 -lea ecx, [eax - 4]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 00a78d0f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a78d11  0f84dc000000           -je 0xa78df3
    if (cpu.flags.zf)
    {
        goto L_0x00a78df3;
    }
    // 00a78d17  7d0f                   -jge 0xa78d28
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a78d28;
    }
    // 00a78d19  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00a78d1b  83c103                 -add ecx, 3
    (cpu.ecx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00a78d1e  80e1fc                 -and cl, 0xfc
    cpu.cl &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 00a78d21  f7d9                   +neg ecx
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
    // 00a78d23  e9bf000000             -jmp 0xa78de7
    goto L_0x00a78de7;
L_0x00a78d28:
    // 00a78d28  8b55d4                 -mov edx, dword ptr [ebp - 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 00a78d2b  6681fa1940             +cmp dx, 0x4019
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
    // 00a78d30  7287                   -jb 0xa78cb9
    if (cpu.flags.cf)
    {
        goto L_0x00a78cb9;
    }
    // 00a78d32  750d                   -jne 0xa78d41
    if (!cpu.flags.zf)
    {
        goto L_0x00a78d41;
    }
    // 00a78d34  817dd00020bcbe         +cmp dword ptr [ebp - 0x30], 0xbebc2000
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
    // 00a78d3b  0f8278ffffff           -jb 0xa78cb9
    if (cpu.flags.cf)
    {
        goto L_0x00a78cb9;
    }
L_0x00a78d41:
    // 00a78d41  8b45d4                 -mov eax, dword ptr [ebp - 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 00a78d44  663d3440               +cmp ax, 0x4034
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
    // 00a78d48  7220                   -jb 0xa78d6a
    if (cpu.flags.cf)
    {
        goto L_0x00a78d6a;
    }
    // 00a78d4a  0f8594000000           -jne 0xa78de4
    if (!cpu.flags.zf)
    {
        goto L_0x00a78de4;
    }
    // 00a78d50  8b5dd0                 -mov ebx, dword ptr [ebp - 0x30]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */);
    // 00a78d53  81fbbfc91b8e           +cmp ebx, 0x8e1bc9bf
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
    // 00a78d59  720f                   -jb 0xa78d6a
    if (cpu.flags.cf)
    {
        goto L_0x00a78d6a;
    }
    // 00a78d5b  0f8583000000           -jne 0xa78de4
    if (!cpu.flags.zf)
    {
        goto L_0x00a78de4;
    }
    // 00a78d61  817dcc00000004         +cmp dword ptr [ebp - 0x34], 0x4000000
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
    // 00a78d68  737a                   -jae 0xa78de4
    if (!cpu.flags.cf)
    {
        goto L_0x00a78de4;
    }
L_0x00a78d6a:
    // 00a78d6a  bb19400000             -mov ebx, 0x4019
    cpu.ebx = 16409 /*0x4019*/;
    // 00a78d6f  8d55b4                 -lea edx, [ebp - 0x4c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-76) /* -0x4c */);
    // 00a78d72  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00a78d75  66895dbc               -mov word ptr [ebp - 0x44], bx
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-68) /* -0x44 */) = cpu.bx;
    // 00a78d79  bb0020bcbe             -mov ebx, 0xbebc2000
    cpu.ebx = 3200000000 /*0xbebc2000*/;
    // 00a78d7e  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a78d80  895db8                 -mov dword ptr [ebp - 0x48], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-72) /* -0x48 */) = cpu.ebx;
    // 00a78d83  8d5da8                 -lea ebx, [ebp - 0x58]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-88) /* -0x58 */);
    // 00a78d86  894db4                 -mov dword ptr [ebp - 0x4c], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-76) /* -0x4c */) = cpu.ecx;
    // 00a78d89  db28                   -fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 00a78d8b  db2a                   -fld xword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 00a78d8d  def9                   -fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00a78d8f  db3b                   -fstp xword ptr [ebx]
    app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a78d91  8d45a8                 -lea eax, [ebp - 0x58]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-88) /* -0x58 */);
    // 00a78d94  8d55a8                 -lea edx, [ebp - 0x58]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-88) /* -0x58 */);
    // 00a78d97  8d5db4                 -lea ebx, [ebp - 0x4c]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-76) /* -0x4c */);
    // 00a78d9a  db28                   -fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 00a78d9c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a78d9d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a78d9e  9b                     -wait 
    /*nothing*/;
    // 00a78d9f  d93c24                 -fnstcw word ptr [esp]
    app->getMemory<x86::reg16>(cpu.esp) = cpu.fpu.control.word;
    // 00a78da2  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78da3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a78da4  80cc0c                 +or ah, 0xc
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(12 /*0xc*/))));
    // 00a78da7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a78da8  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 00a78dab  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78dac  db5c2404               +fistp dword ptr [esp + 4]
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00a78db0  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 00a78db3  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78db4  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78db5  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a78db7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a78db8  db0424                 +fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 00a78dbb  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78dbc  db3a                   +fstp xword ptr [edx]
    app->getMemory<x86::IEEEf80>(cpu.edx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a78dbe  8d55b4                 -lea edx, [ebp - 0x4c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-76) /* -0x4c */);
    // 00a78dc1  8d45a8                 -lea eax, [ebp - 0x58]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-88) /* -0x58 */);
    // 00a78dc4  db28                   +fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 00a78dc6  db2a                   +fld xword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 00a78dc8  dec9                   +fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00a78dca  db3b                   +fstp xword ptr [ebx]
    app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a78dcc  8d5dcc                 -lea ebx, [ebp - 0x34]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00a78dcf  8d55b4                 -lea edx, [ebp - 0x4c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-76) /* -0x4c */);
    // 00a78dd2  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00a78dd5  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 00a78dda  db28                   +fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 00a78ddc  db2a                   +fld xword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 00a78dde  dee9                   +fsubp st(1)
    cpu.fpu.st(1) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00a78de0  db3b                   +fstp xword ptr [ebx]
    app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a78de2  eb0f                   -jmp 0xa78df3
    goto L_0x00a78df3;
L_0x00a78de4:
    // 00a78de4  80e1fc                 -and cl, 0xfc
    cpu.cl &= x86::reg8(x86::sreg8(252 /*0xfc*/));
L_0x00a78de7:
    // 00a78de7  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a78de9  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00a78dec  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 00a78dee  e8d2fdffff             -call 0xa78bc5
    cpu.esp -= 4;
    sub_a78bc5(app, cpu);
    if (cpu.terminate) return;
L_0x00a78df3:
    // 00a78df3  f6460802               +test byte ptr [esi + 8], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 2 /*0x2*/));
    // 00a78df7  7416                   -je 0xa78e0f
    if (cpu.flags.zf)
    {
        goto L_0x00a78e0f;
    }
    // 00a78df9  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00a78dfb  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a78dfd  83c00a                 -add eax, 0xa
    (cpu.eax) += x86::reg32(x86::sreg32(10 /*0xa*/));
    // 00a78e00  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
    // 00a78e03  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00a78e06  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a78e08  7e0d                   -jle 0xa78e17
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a78e17;
    }
    // 00a78e0a  0145e8                 +add dword ptr [ebp - 0x18], eax
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
    // 00a78e0d  eb08                   -jmp 0xa78e17
    goto L_0x00a78e17;
L_0x00a78e0f:
    // 00a78e0f  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00a78e11  83c007                 -add eax, 7
    (cpu.eax) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 00a78e14  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
L_0x00a78e17:
    // 00a78e17  8a5e08                 -mov bl, byte ptr [esi + 8]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00a78e1a  b80f000000             -mov eax, 0xf
    cpu.eax = 15 /*0xf*/;
    // 00a78e1f  f6c320                 +test bl, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 32 /*0x20*/));
    // 00a78e22  7405                   -je 0xa78e29
    if (cpu.flags.zf)
    {
        goto L_0x00a78e29;
    }
    // 00a78e24  b814000000             -mov eax, 0x14
    cpu.eax = 20 /*0x14*/;
L_0x00a78e29:
    // 00a78e29  f6460840               +test byte ptr [esi + 8], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 64 /*0x40*/));
    // 00a78e2d  7402                   -je 0xa78e31
    if (cpu.flags.zf)
    {
        goto L_0x00a78e31;
    }
    // 00a78e2f  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
L_0x00a78e31:
    // 00a78e31  8b5de8                 -mov ebx, dword ptr [ebp - 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a78e34  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a78e37  39d8                   +cmp eax, ebx
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
    // 00a78e39  7d03                   -jge 0xa78e3e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a78e3e;
    }
    // 00a78e3b  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
L_0x00a78e3e:
    // 00a78e3e  c68568ffffff30         -mov byte ptr [ebp - 0x98], 0x30
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-152) /* -0x98 */) = 48 /*0x30*/;
    // 00a78e45  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 00a78e47  88a569ffffff           -mov byte ptr [ebp - 0x97], ah
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-151) /* -0x97 */) = cpu.ah;
    // 00a78e4d  8d8569ffffff           -lea eax, [ebp - 0x97]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-151) /* -0x97 */);
    // 00a78e53  8945d8                 -mov dword ptr [ebp - 0x28], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = cpu.eax;
    // 00a78e56  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a78e58  8945dc                 -mov dword ptr [ebp - 0x24], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.eax;
    // 00a78e5b  8b55e8                 -mov edx, dword ptr [ebp - 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a78e5e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a78e60  0f8ee8000000           -jle 0xa78f4e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_a78f4e(app, cpu);
    }
    // 00a78e66  8d5af8                 -lea ebx, [edx - 8]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(-8) /* -0x8 */);
    // 00a78e69  895de8                 -mov dword ptr [ebp - 0x18], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.ebx;
    // 00a78e6c  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a78e6e  7572                   -jne 0xa78ee2
    if (!cpu.flags.zf)
    {
        goto L_0x00a78ee2;
    }
    // 00a78e70  66f745d4ff7f           +test word ptr [ebp - 0x2c], 0x7fff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-44) /* -0x2c */) & 32767 /*0x7fff*/));
    // 00a78e76  0f84d2000000           -je 0xa78f4e
    if (cpu.flags.zf)
    {
        return sub_a78f4e(app, cpu);
    }
    // 00a78e7c  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00a78e7f  db28                   -fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 00a78e81  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a78e82  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a78e83  9b                     -wait 
    /*nothing*/;
    // 00a78e84  d93c24                 -fnstcw word ptr [esp]
    app->getMemory<x86::reg16>(cpu.esp) = cpu.fpu.control.word;
    // 00a78e87  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78e88  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a78e89  80cc0c                 -or ah, 0xc
    cpu.ah |= x86::reg8(x86::sreg8(12 /*0xc*/));
    // 00a78e8c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a78e8d  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 00a78e90  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78e91  db5c2404               -fistp dword ptr [esp + 4]
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00a78e95  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 00a78e98  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78e99  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78e9a  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a78e9c  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a78e9e  7e42                   -jle 0xa78ee2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a78ee2;
    }
    // 00a78ea0  8d55c0                 -lea edx, [ebp - 0x40]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-64) /* -0x40 */);
    // 00a78ea3  8d5dcc                 -lea ebx, [ebp - 0x34]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00a78ea6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a78ea7  db0424                 -fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 00a78eaa  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78eab  db3a                   -fstp xword ptr [edx]
    app->getMemory<x86::IEEEf80>(cpu.edx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a78ead  8d55c0                 -lea edx, [ebp - 0x40]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-64) /* -0x40 */);
    // 00a78eb0  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00a78eb3  db28                   -fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 00a78eb5  db2a                   -fld xword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 00a78eb7  dee9                   -fsubp st(1)
    cpu.fpu.st(1) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00a78eb9  db3b                   -fstp xword ptr [ebx]
    app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a78ebb  b819400000             -mov eax, 0x4019
    cpu.eax = 16409 /*0x4019*/;
    // 00a78ec0  bb0020bcbe             -mov ebx, 0xbebc2000
    cpu.ebx = 3200000000 /*0xbebc2000*/;
    // 00a78ec5  8d55c0                 -lea edx, [ebp - 0x40]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-64) /* -0x40 */);
    // 00a78ec8  668945c8               -mov word ptr [ebp - 0x38], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-56) /* -0x38 */) = cpu.ax;
    // 00a78ecc  895dc4                 -mov dword ptr [ebp - 0x3c], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-60) /* -0x3c */) = cpu.ebx;
    // 00a78ecf  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a78ed1  8d5dcc                 -lea ebx, [ebp - 0x34]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00a78ed4  8945c0                 -mov dword ptr [ebp - 0x40], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-64) /* -0x40 */) = cpu.eax;
    // 00a78ed7  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00a78eda  db28                   +fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 00a78edc  db2a                   +fld xword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 00a78ede  dec9                   +fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00a78ee0  db3b                   +fstp xword ptr [ebx]
    app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x00a78ee2:
    // 00a78ee2  8b5dd8                 -mov ebx, dword ptr [ebp - 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 00a78ee5  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a78ee7  8b55dc                 -mov edx, dword ptr [ebp - 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 00a78eea  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a78eeb  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a78eec  e802000000             -call 0xa78ef3
    cpu.esp -= 4;
    sub_a78ef3(app, cpu);
    if (cpu.terminate) return;
    // 00a78ef1  eb45                   -jmp 0xa78f38
    return sub_a78f38(app, cpu);
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void sub_a78e5b(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    goto L_entry_0x00a78e5b;
    // 00a78c1f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a78c20  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00a78c22  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a78c23  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a78c24  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a78c25  81ec8c000000           -sub esp, 0x8c
    (cpu.esp) -= x86::reg32(x86::sreg32(140 /*0x8c*/));
    // 00a78c2b  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a78c2d  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00a78c2f  895de0                 -mov dword ptr [ebp - 0x20], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.ebx;
    // 00a78c32  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a78c34  9b                     -wait 
    /*nothing*/;
    // 00a78c35  d93c24                 -fnstcw word ptr [esp]
    app->getMemory<x86::reg16>(cpu.esp) = cpu.fpu.control.word;
    // 00a78c38  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78c39  8945ec                 -mov dword ptr [ebp - 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
    // 00a78c3c  80cc03                 -or ah, 3
    cpu.ah |= x86::reg8(x86::sreg8(3 /*0x3*/));
    // 00a78c3f  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00a78c44  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a78c45  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 00a78c48  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78c49  c7421400000000         -mov dword ptr [edx + 0x14], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 00a78c50  668b4708               -mov ax, word ptr [edi + 8]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 00a78c54  668945d4               -mov word ptr [ebp - 0x2c], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-44) /* -0x2c */) = cpu.ax;
    // 00a78c58  8b4704                 -mov eax, dword ptr [edi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00a78c5b  8945d0                 -mov dword ptr [ebp - 0x30], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */) = cpu.eax;
    // 00a78c5e  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 00a78c60  8945cc                 -mov dword ptr [ebp - 0x34], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-52) /* -0x34 */) = cpu.eax;
    // 00a78c63  f645d580               +test byte ptr [ebp - 0x2b], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-43) /* -0x2b */) & 128 /*0x80*/));
    // 00a78c67  7407                   -je 0xa78c70
    if (cpu.flags.zf)
    {
        goto L_0x00a78c70;
    }
    // 00a78c69  c74214ffffffff         -mov dword ptr [edx + 0x14], 0xffffffff
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = 4294967295 /*0xffffffff*/;
L_0x00a78c70:
    // 00a78c70  8065d57f               -and byte ptr [ebp - 0x2b], 0x7f
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-43) /* -0x2b */) &= x86::reg8(x86::sreg8(127 /*0x7f*/));
    // 00a78c74  c7461c00000000         -mov dword ptr [esi + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 00a78c7b  c7462000000000         -mov dword ptr [esi + 0x20], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 00a78c82  c7462400000000         -mov dword ptr [esi + 0x24], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 00a78c89  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00a78c8c  c7462800000000         -mov dword ptr [esi + 0x28], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
    // 00a78c93  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00a78c95  c7461800000000         -mov dword ptr [esi + 0x18], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 00a78c9c  e80b1c0000             -call 0xa7a8ac
    cpu.esp -= 4;
    sub_a7a8ac(app, cpu);
    if (cpu.terminate) return;
    // 00a78ca1  83f804                 +cmp eax, 4
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
    // 00a78ca4  0f8749010000           -ja 0xa78df3
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a78df3;
    }
    // 00a78caa  2eff24850b8ca700       -jmp dword ptr cs:[eax*4 + 0xa78c0b]
    cpu.ip = app->getMemory<x86::reg32>(10980363 + cpu.eax * 4); goto dynamic_jump;
  case 0x00a78cb2:
    // 00a78cb2  c7461400000000         -mov dword ptr [esi + 0x14], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
L_0x00a78cb9:
    // 00a78cb9  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00a78cbb  e933010000             -jmp 0xa78df3
    goto L_0x00a78df3;
  case 0x00a78cc0:
    // 00a78cc0  8b45e0                 -mov eax, dword ptr [ebp - 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00a78cc3  c6006e                 -mov byte ptr [eax], 0x6e
    app->getMemory<x86::reg8>(cpu.eax) = 110 /*0x6e*/;
    // 00a78cc6  c6400161               -mov byte ptr [eax + 1], 0x61
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = 97 /*0x61*/;
    // 00a78cca  c640026e               -mov byte ptr [eax + 2], 0x6e
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */) = 110 /*0x6e*/;
L_0x00a78cce:
    // 00a78cce  c6400300               -mov byte ptr [eax + 3], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */) = 0 /*0x0*/;
    // 00a78cd2  c7461c03000000         -mov dword ptr [esi + 0x1c], 3
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = 3 /*0x3*/;
    // 00a78cd9  e970030000             -jmp 0xa7904e
    return sub_a7904e(app, cpu);
  case 0x00a78cde:
    // 00a78cde  8b45e0                 -mov eax, dword ptr [ebp - 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00a78ce1  c60069                 -mov byte ptr [eax], 0x69
    app->getMemory<x86::reg8>(cpu.eax) = 105 /*0x69*/;
    // 00a78ce4  c640016e               -mov byte ptr [eax + 1], 0x6e
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = 110 /*0x6e*/;
    // 00a78ce8  c6400266               -mov byte ptr [eax + 2], 0x66
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */) = 102 /*0x66*/;
    // 00a78cec  ebe0                   -jmp 0xa78cce
    goto L_0x00a78cce;
  case 0x00a78cee:
    // 00a78cee  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a78cf0  668b4dd4               -mov cx, word ptr [ebp - 0x2c]
    cpu.cx = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 00a78cf4  81e9fe3f0000           -sub ecx, 0x3ffe
    (cpu.ecx) -= x86::reg32(x86::sreg32(16382 /*0x3ffe*/));
    // 00a78cfa  69d197750000           -imul edx, ecx, 0x7597
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(30103 /*0x7597*/)));
    // 00a78d00  bba0860100             -mov ebx, 0x186a0
    cpu.ebx = 100000 /*0x186a0*/;
    // 00a78d05  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a78d07  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00a78d0a  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00a78d0c  8d48fc                 -lea ecx, [eax - 4]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 00a78d0f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a78d11  0f84dc000000           -je 0xa78df3
    if (cpu.flags.zf)
    {
        goto L_0x00a78df3;
    }
    // 00a78d17  7d0f                   -jge 0xa78d28
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a78d28;
    }
    // 00a78d19  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00a78d1b  83c103                 -add ecx, 3
    (cpu.ecx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00a78d1e  80e1fc                 -and cl, 0xfc
    cpu.cl &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 00a78d21  f7d9                   +neg ecx
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
    // 00a78d23  e9bf000000             -jmp 0xa78de7
    goto L_0x00a78de7;
L_0x00a78d28:
    // 00a78d28  8b55d4                 -mov edx, dword ptr [ebp - 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 00a78d2b  6681fa1940             +cmp dx, 0x4019
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
    // 00a78d30  7287                   -jb 0xa78cb9
    if (cpu.flags.cf)
    {
        goto L_0x00a78cb9;
    }
    // 00a78d32  750d                   -jne 0xa78d41
    if (!cpu.flags.zf)
    {
        goto L_0x00a78d41;
    }
    // 00a78d34  817dd00020bcbe         +cmp dword ptr [ebp - 0x30], 0xbebc2000
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
    // 00a78d3b  0f8278ffffff           -jb 0xa78cb9
    if (cpu.flags.cf)
    {
        goto L_0x00a78cb9;
    }
L_0x00a78d41:
    // 00a78d41  8b45d4                 -mov eax, dword ptr [ebp - 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 00a78d44  663d3440               +cmp ax, 0x4034
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
    // 00a78d48  7220                   -jb 0xa78d6a
    if (cpu.flags.cf)
    {
        goto L_0x00a78d6a;
    }
    // 00a78d4a  0f8594000000           -jne 0xa78de4
    if (!cpu.flags.zf)
    {
        goto L_0x00a78de4;
    }
    // 00a78d50  8b5dd0                 -mov ebx, dword ptr [ebp - 0x30]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */);
    // 00a78d53  81fbbfc91b8e           +cmp ebx, 0x8e1bc9bf
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
    // 00a78d59  720f                   -jb 0xa78d6a
    if (cpu.flags.cf)
    {
        goto L_0x00a78d6a;
    }
    // 00a78d5b  0f8583000000           -jne 0xa78de4
    if (!cpu.flags.zf)
    {
        goto L_0x00a78de4;
    }
    // 00a78d61  817dcc00000004         +cmp dword ptr [ebp - 0x34], 0x4000000
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
    // 00a78d68  737a                   -jae 0xa78de4
    if (!cpu.flags.cf)
    {
        goto L_0x00a78de4;
    }
L_0x00a78d6a:
    // 00a78d6a  bb19400000             -mov ebx, 0x4019
    cpu.ebx = 16409 /*0x4019*/;
    // 00a78d6f  8d55b4                 -lea edx, [ebp - 0x4c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-76) /* -0x4c */);
    // 00a78d72  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00a78d75  66895dbc               -mov word ptr [ebp - 0x44], bx
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-68) /* -0x44 */) = cpu.bx;
    // 00a78d79  bb0020bcbe             -mov ebx, 0xbebc2000
    cpu.ebx = 3200000000 /*0xbebc2000*/;
    // 00a78d7e  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a78d80  895db8                 -mov dword ptr [ebp - 0x48], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-72) /* -0x48 */) = cpu.ebx;
    // 00a78d83  8d5da8                 -lea ebx, [ebp - 0x58]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-88) /* -0x58 */);
    // 00a78d86  894db4                 -mov dword ptr [ebp - 0x4c], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-76) /* -0x4c */) = cpu.ecx;
    // 00a78d89  db28                   -fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 00a78d8b  db2a                   -fld xword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 00a78d8d  def9                   -fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00a78d8f  db3b                   -fstp xword ptr [ebx]
    app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a78d91  8d45a8                 -lea eax, [ebp - 0x58]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-88) /* -0x58 */);
    // 00a78d94  8d55a8                 -lea edx, [ebp - 0x58]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-88) /* -0x58 */);
    // 00a78d97  8d5db4                 -lea ebx, [ebp - 0x4c]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-76) /* -0x4c */);
    // 00a78d9a  db28                   -fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 00a78d9c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a78d9d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a78d9e  9b                     -wait 
    /*nothing*/;
    // 00a78d9f  d93c24                 -fnstcw word ptr [esp]
    app->getMemory<x86::reg16>(cpu.esp) = cpu.fpu.control.word;
    // 00a78da2  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78da3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a78da4  80cc0c                 +or ah, 0xc
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(12 /*0xc*/))));
    // 00a78da7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a78da8  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 00a78dab  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78dac  db5c2404               +fistp dword ptr [esp + 4]
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00a78db0  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 00a78db3  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78db4  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78db5  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a78db7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a78db8  db0424                 +fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 00a78dbb  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78dbc  db3a                   +fstp xword ptr [edx]
    app->getMemory<x86::IEEEf80>(cpu.edx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a78dbe  8d55b4                 -lea edx, [ebp - 0x4c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-76) /* -0x4c */);
    // 00a78dc1  8d45a8                 -lea eax, [ebp - 0x58]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-88) /* -0x58 */);
    // 00a78dc4  db28                   +fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 00a78dc6  db2a                   +fld xword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 00a78dc8  dec9                   +fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00a78dca  db3b                   +fstp xword ptr [ebx]
    app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a78dcc  8d5dcc                 -lea ebx, [ebp - 0x34]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00a78dcf  8d55b4                 -lea edx, [ebp - 0x4c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-76) /* -0x4c */);
    // 00a78dd2  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00a78dd5  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 00a78dda  db28                   +fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 00a78ddc  db2a                   +fld xword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 00a78dde  dee9                   +fsubp st(1)
    cpu.fpu.st(1) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00a78de0  db3b                   +fstp xword ptr [ebx]
    app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a78de2  eb0f                   -jmp 0xa78df3
    goto L_0x00a78df3;
L_0x00a78de4:
    // 00a78de4  80e1fc                 -and cl, 0xfc
    cpu.cl &= x86::reg8(x86::sreg8(252 /*0xfc*/));
L_0x00a78de7:
    // 00a78de7  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a78de9  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00a78dec  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 00a78dee  e8d2fdffff             -call 0xa78bc5
    cpu.esp -= 4;
    sub_a78bc5(app, cpu);
    if (cpu.terminate) return;
L_0x00a78df3:
    // 00a78df3  f6460802               +test byte ptr [esi + 8], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 2 /*0x2*/));
    // 00a78df7  7416                   -je 0xa78e0f
    if (cpu.flags.zf)
    {
        goto L_0x00a78e0f;
    }
    // 00a78df9  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00a78dfb  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a78dfd  83c00a                 -add eax, 0xa
    (cpu.eax) += x86::reg32(x86::sreg32(10 /*0xa*/));
    // 00a78e00  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
    // 00a78e03  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00a78e06  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a78e08  7e0d                   -jle 0xa78e17
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a78e17;
    }
    // 00a78e0a  0145e8                 +add dword ptr [ebp - 0x18], eax
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
    // 00a78e0d  eb08                   -jmp 0xa78e17
    goto L_0x00a78e17;
L_0x00a78e0f:
    // 00a78e0f  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00a78e11  83c007                 -add eax, 7
    (cpu.eax) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 00a78e14  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
L_0x00a78e17:
    // 00a78e17  8a5e08                 -mov bl, byte ptr [esi + 8]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00a78e1a  b80f000000             -mov eax, 0xf
    cpu.eax = 15 /*0xf*/;
    // 00a78e1f  f6c320                 +test bl, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 32 /*0x20*/));
    // 00a78e22  7405                   -je 0xa78e29
    if (cpu.flags.zf)
    {
        goto L_0x00a78e29;
    }
    // 00a78e24  b814000000             -mov eax, 0x14
    cpu.eax = 20 /*0x14*/;
L_0x00a78e29:
    // 00a78e29  f6460840               +test byte ptr [esi + 8], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 64 /*0x40*/));
    // 00a78e2d  7402                   -je 0xa78e31
    if (cpu.flags.zf)
    {
        goto L_0x00a78e31;
    }
    // 00a78e2f  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
L_0x00a78e31:
    // 00a78e31  8b5de8                 -mov ebx, dword ptr [ebp - 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a78e34  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a78e37  39d8                   +cmp eax, ebx
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
    // 00a78e39  7d03                   -jge 0xa78e3e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a78e3e;
    }
    // 00a78e3b  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
L_0x00a78e3e:
    // 00a78e3e  c68568ffffff30         -mov byte ptr [ebp - 0x98], 0x30
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-152) /* -0x98 */) = 48 /*0x30*/;
    // 00a78e45  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 00a78e47  88a569ffffff           -mov byte ptr [ebp - 0x97], ah
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-151) /* -0x97 */) = cpu.ah;
    // 00a78e4d  8d8569ffffff           -lea eax, [ebp - 0x97]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-151) /* -0x97 */);
    // 00a78e53  8945d8                 -mov dword ptr [ebp - 0x28], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = cpu.eax;
    // 00a78e56  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a78e58  8945dc                 -mov dword ptr [ebp - 0x24], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.eax;
L_entry_0x00a78e5b:
    // 00a78e5b  8b55e8                 -mov edx, dword ptr [ebp - 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a78e5e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a78e60  0f8ee8000000           -jle 0xa78f4e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_a78f4e(app, cpu);
    }
    // 00a78e66  8d5af8                 -lea ebx, [edx - 8]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(-8) /* -0x8 */);
    // 00a78e69  895de8                 -mov dword ptr [ebp - 0x18], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.ebx;
    // 00a78e6c  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a78e6e  7572                   -jne 0xa78ee2
    if (!cpu.flags.zf)
    {
        goto L_0x00a78ee2;
    }
    // 00a78e70  66f745d4ff7f           +test word ptr [ebp - 0x2c], 0x7fff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-44) /* -0x2c */) & 32767 /*0x7fff*/));
    // 00a78e76  0f84d2000000           -je 0xa78f4e
    if (cpu.flags.zf)
    {
        return sub_a78f4e(app, cpu);
    }
    // 00a78e7c  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00a78e7f  db28                   -fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 00a78e81  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a78e82  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a78e83  9b                     -wait 
    /*nothing*/;
    // 00a78e84  d93c24                 -fnstcw word ptr [esp]
    app->getMemory<x86::reg16>(cpu.esp) = cpu.fpu.control.word;
    // 00a78e87  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78e88  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a78e89  80cc0c                 -or ah, 0xc
    cpu.ah |= x86::reg8(x86::sreg8(12 /*0xc*/));
    // 00a78e8c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a78e8d  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 00a78e90  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78e91  db5c2404               -fistp dword ptr [esp + 4]
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00a78e95  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 00a78e98  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78e99  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78e9a  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a78e9c  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a78e9e  7e42                   -jle 0xa78ee2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a78ee2;
    }
    // 00a78ea0  8d55c0                 -lea edx, [ebp - 0x40]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-64) /* -0x40 */);
    // 00a78ea3  8d5dcc                 -lea ebx, [ebp - 0x34]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00a78ea6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a78ea7  db0424                 -fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 00a78eaa  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78eab  db3a                   -fstp xword ptr [edx]
    app->getMemory<x86::IEEEf80>(cpu.edx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a78ead  8d55c0                 -lea edx, [ebp - 0x40]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-64) /* -0x40 */);
    // 00a78eb0  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00a78eb3  db28                   -fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 00a78eb5  db2a                   -fld xword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 00a78eb7  dee9                   -fsubp st(1)
    cpu.fpu.st(1) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00a78eb9  db3b                   -fstp xword ptr [ebx]
    app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a78ebb  b819400000             -mov eax, 0x4019
    cpu.eax = 16409 /*0x4019*/;
    // 00a78ec0  bb0020bcbe             -mov ebx, 0xbebc2000
    cpu.ebx = 3200000000 /*0xbebc2000*/;
    // 00a78ec5  8d55c0                 -lea edx, [ebp - 0x40]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-64) /* -0x40 */);
    // 00a78ec8  668945c8               -mov word ptr [ebp - 0x38], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-56) /* -0x38 */) = cpu.ax;
    // 00a78ecc  895dc4                 -mov dword ptr [ebp - 0x3c], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-60) /* -0x3c */) = cpu.ebx;
    // 00a78ecf  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a78ed1  8d5dcc                 -lea ebx, [ebp - 0x34]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00a78ed4  8945c0                 -mov dword ptr [ebp - 0x40], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-64) /* -0x40 */) = cpu.eax;
    // 00a78ed7  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00a78eda  db28                   +fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 00a78edc  db2a                   +fld xword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 00a78ede  dec9                   +fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00a78ee0  db3b                   +fstp xword ptr [ebx]
    app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x00a78ee2:
    // 00a78ee2  8b5dd8                 -mov ebx, dword ptr [ebp - 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 00a78ee5  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a78ee7  8b55dc                 -mov edx, dword ptr [ebp - 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 00a78eea  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a78eeb  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a78eec  e802000000             -call 0xa78ef3
    cpu.esp -= 4;
    sub_a78ef3(app, cpu);
    if (cpu.terminate) return;
    // 00a78ef1  eb45                   -jmp 0xa78f38
    return sub_a78f38(app, cpu);
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void sub_a78ef3(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a78ef3  b910270000             -mov ecx, 0x2710
    cpu.ecx = 10000 /*0x2710*/;
    // 00a78ef8  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a78efa  39c8                   +cmp eax, ecx
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
    // 00a78efc  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 00a78efd  7203                   -jb 0xa78f02
    if (cpu.flags.cf)
    {
        goto L_0x00a78f02;
    }
    // 00a78eff  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 00a78f00  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
L_0x00a78f02:
    // 00a78f02  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a78f03  e801000000             -call 0xa78f09
    cpu.esp -= 4;
    sub_a78f09(app, cpu);
    if (cpu.terminate) return;
    // 00a78f08  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78f09  b964000000             -mov ecx, 0x64
    cpu.ecx = 100 /*0x64*/;
    // 00a78f0e  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a78f10  39c8                   +cmp eax, ecx
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
    // 00a78f12  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 00a78f13  7204                   -jb 0xa78f19
    if (cpu.flags.cf)
    {
        goto L_0x00a78f19;
    }
    // 00a78f15  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 00a78f16  66f7f1                 -div cx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.cx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
L_0x00a78f19:
    // 00a78f19  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a78f1a  e801000000             -call 0xa78f20
    cpu.esp -= 4;
    sub_a78f20(app, cpu);
    if (cpu.terminate) return;
    // 00a78f1f  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78f20  b10a                   -mov cl, 0xa
    cpu.cl = 10 /*0xa*/;
    // 00a78f22  38c8                   +cmp al, cl
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
    // 00a78f24  86c4                   -xchg ah, al
    {
        x86::reg8 tmp = cpu.ah;
        cpu.ah = cpu.al;
        cpu.al = tmp;
    }
    // 00a78f26  7204                   -jb 0xa78f2c
    if (cpu.flags.cf)
    {
        goto L_0x00a78f2c;
    }
    // 00a78f28  86c4                   -xchg ah, al
    {
        x86::reg8 tmp = cpu.ah;
        cpu.ah = cpu.al;
        cpu.al = tmp;
    }
    // 00a78f2a  f6f1                   -div cl
    {
        x86::reg16 tmp = cpu.ax;
        x86::reg8 d = cpu.cl;
        cpu.ax /= d;
        cpu.ah = tmp % d;
    }
L_0x00a78f2c:
    // 00a78f2c  80c430                 -add ah, 0x30
    (cpu.ah) += x86::reg8(x86::sreg8(48 /*0x30*/));
    // 00a78f2f  0430                   -add al, 0x30
    (cpu.al) += x86::reg8(x86::sreg8(48 /*0x30*/));
    // 00a78f31  8803                   -mov byte ptr [ebx], al
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.al;
    // 00a78f33  43                     -inc ebx
    (cpu.ebx)++;
    // 00a78f34  8823                   -mov byte ptr [ebx], ah
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.ah;
    // 00a78f36  43                     -inc ebx
    (cpu.ebx)++;
    // 00a78f37  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a78f09(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a78f09;
    // 00a78ef3  b910270000             -mov ecx, 0x2710
    cpu.ecx = 10000 /*0x2710*/;
    // 00a78ef8  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a78efa  39c8                   +cmp eax, ecx
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
    // 00a78efc  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 00a78efd  7203                   -jb 0xa78f02
    if (cpu.flags.cf)
    {
        goto L_0x00a78f02;
    }
    // 00a78eff  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 00a78f00  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
L_0x00a78f02:
    // 00a78f02  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a78f03  e801000000             -call 0xa78f09
    cpu.esp -= 4;
    sub_a78f09(app, cpu);
    if (cpu.terminate) return;
    // 00a78f08  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_entry_0x00a78f09:
    // 00a78f09  b964000000             -mov ecx, 0x64
    cpu.ecx = 100 /*0x64*/;
    // 00a78f0e  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a78f10  39c8                   +cmp eax, ecx
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
    // 00a78f12  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 00a78f13  7204                   -jb 0xa78f19
    if (cpu.flags.cf)
    {
        goto L_0x00a78f19;
    }
    // 00a78f15  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 00a78f16  66f7f1                 -div cx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.cx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
L_0x00a78f19:
    // 00a78f19  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a78f1a  e801000000             -call 0xa78f20
    cpu.esp -= 4;
    sub_a78f20(app, cpu);
    if (cpu.terminate) return;
    // 00a78f1f  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78f20  b10a                   -mov cl, 0xa
    cpu.cl = 10 /*0xa*/;
    // 00a78f22  38c8                   +cmp al, cl
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
    // 00a78f24  86c4                   -xchg ah, al
    {
        x86::reg8 tmp = cpu.ah;
        cpu.ah = cpu.al;
        cpu.al = tmp;
    }
    // 00a78f26  7204                   -jb 0xa78f2c
    if (cpu.flags.cf)
    {
        goto L_0x00a78f2c;
    }
    // 00a78f28  86c4                   -xchg ah, al
    {
        x86::reg8 tmp = cpu.ah;
        cpu.ah = cpu.al;
        cpu.al = tmp;
    }
    // 00a78f2a  f6f1                   -div cl
    {
        x86::reg16 tmp = cpu.ax;
        x86::reg8 d = cpu.cl;
        cpu.ax /= d;
        cpu.ah = tmp % d;
    }
L_0x00a78f2c:
    // 00a78f2c  80c430                 -add ah, 0x30
    (cpu.ah) += x86::reg8(x86::sreg8(48 /*0x30*/));
    // 00a78f2f  0430                   -add al, 0x30
    (cpu.al) += x86::reg8(x86::sreg8(48 /*0x30*/));
    // 00a78f31  8803                   -mov byte ptr [ebx], al
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.al;
    // 00a78f33  43                     -inc ebx
    (cpu.ebx)++;
    // 00a78f34  8823                   -mov byte ptr [ebx], ah
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.ah;
    // 00a78f36  43                     -inc ebx
    (cpu.ebx)++;
    // 00a78f37  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a78f20(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a78f20;
    // 00a78ef3  b910270000             -mov ecx, 0x2710
    cpu.ecx = 10000 /*0x2710*/;
    // 00a78ef8  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a78efa  39c8                   +cmp eax, ecx
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
    // 00a78efc  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 00a78efd  7203                   -jb 0xa78f02
    if (cpu.flags.cf)
    {
        goto L_0x00a78f02;
    }
    // 00a78eff  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 00a78f00  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
L_0x00a78f02:
    // 00a78f02  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a78f03  e801000000             -call 0xa78f09
    cpu.esp -= 4;
    sub_a78f09(app, cpu);
    if (cpu.terminate) return;
    // 00a78f08  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78f09  b964000000             -mov ecx, 0x64
    cpu.ecx = 100 /*0x64*/;
    // 00a78f0e  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a78f10  39c8                   +cmp eax, ecx
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
    // 00a78f12  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 00a78f13  7204                   -jb 0xa78f19
    if (cpu.flags.cf)
    {
        goto L_0x00a78f19;
    }
    // 00a78f15  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 00a78f16  66f7f1                 -div cx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.cx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
L_0x00a78f19:
    // 00a78f19  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a78f1a  e801000000             -call 0xa78f20
    cpu.esp -= 4;
    sub_a78f20(app, cpu);
    if (cpu.terminate) return;
    // 00a78f1f  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_entry_0x00a78f20:
    // 00a78f20  b10a                   -mov cl, 0xa
    cpu.cl = 10 /*0xa*/;
    // 00a78f22  38c8                   +cmp al, cl
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
    // 00a78f24  86c4                   -xchg ah, al
    {
        x86::reg8 tmp = cpu.ah;
        cpu.ah = cpu.al;
        cpu.al = tmp;
    }
    // 00a78f26  7204                   -jb 0xa78f2c
    if (cpu.flags.cf)
    {
        goto L_0x00a78f2c;
    }
    // 00a78f28  86c4                   -xchg ah, al
    {
        x86::reg8 tmp = cpu.ah;
        cpu.ah = cpu.al;
        cpu.al = tmp;
    }
    // 00a78f2a  f6f1                   -div cl
    {
        x86::reg16 tmp = cpu.ax;
        x86::reg8 d = cpu.cl;
        cpu.ax /= d;
        cpu.ah = tmp % d;
    }
L_0x00a78f2c:
    // 00a78f2c  80c430                 -add ah, 0x30
    (cpu.ah) += x86::reg8(x86::sreg8(48 /*0x30*/));
    // 00a78f2f  0430                   -add al, 0x30
    (cpu.al) += x86::reg8(x86::sreg8(48 /*0x30*/));
    // 00a78f31  8803                   -mov byte ptr [ebx], al
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.al;
    // 00a78f33  43                     -inc ebx
    (cpu.ebx)++;
    // 00a78f34  8823                   -mov byte ptr [ebx], ah
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.ah;
    // 00a78f36  43                     -inc ebx
    (cpu.ebx)++;
    // 00a78f37  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a78f38(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a78f38  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78f39  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78f3a  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 00a78f3c  8803                   -mov byte ptr [ebx], al
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.al;
    // 00a78f3e  895dd8                 -mov dword ptr [ebp - 0x28], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = cpu.ebx;
    // 00a78f41  83c208                 -add edx, 8
    (cpu.edx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a78f44  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 00a78f46  8955dc                 -mov dword ptr [ebp - 0x24], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.edx;
    // 00a78f49  e90dffffff             -jmp 0xa78e5b
    return sub_a78e5b(app, cpu);
}

/* align: skip  */
void sub_a78f4e(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a78f4e  8b45dc                 -mov eax, dword ptr [ebp - 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 00a78f51  8d9569ffffff           -lea edx, [ebp - 0x97]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-151) /* -0x97 */);
    // 00a78f57  83c107                 -add ecx, 7
    (cpu.ecx) += x86::reg32(x86::sreg32(7 /*0x7*/));
L_0x00a78f5a:
    // 00a78f5a  803a30                 +cmp byte ptr [edx], 0x30
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
    // 00a78f5d  7505                   -jne 0xa78f64
    if (!cpu.flags.zf)
    {
        goto L_0x00a78f64;
    }
    // 00a78f5f  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a78f60  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a78f61  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a78f62  ebf6                   -jmp 0xa78f5a
    goto L_0x00a78f5a;
L_0x00a78f64:
    // 00a78f64  8a7e08                 -mov bh, byte ptr [esi + 8]
    cpu.bh = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00a78f67  8b3e                   -mov edi, dword ptr [esi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi);
    // 00a78f69  f6c702                 +test bh, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 2 /*0x2*/));
    // 00a78f6c  740a                   -je 0xa78f78
    if (cpu.flags.zf)
    {
        goto L_0x00a78f78;
    }
    // 00a78f6e  034e04                 -add ecx, dword ptr [esi + 4]
    (cpu.ecx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 00a78f71  8d5901                 -lea ebx, [ecx + 1]
    cpu.ebx = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 00a78f74  01df                   +add edi, ebx
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
    // 00a78f76  eb15                   -jmp 0xa78f8d
    goto L_0x00a78f8d;
L_0x00a78f78:
    // 00a78f78  f6c701                 +test bh, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 1 /*0x1*/));
    // 00a78f7b  7410                   -je 0xa78f8d
    if (cpu.flags.zf)
    {
        goto L_0x00a78f8d;
    }
    // 00a78f7d  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00a78f80  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a78f82  7e03                   -jle 0xa78f87
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a78f87;
    }
    // 00a78f84  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a78f85  eb02                   -jmp 0xa78f89
    goto L_0x00a78f89;
L_0x00a78f87:
    // 00a78f87  01df                   -add edi, ebx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebx));
L_0x00a78f89:
    // 00a78f89  41                     -inc ecx
    (cpu.ecx)++;
    // 00a78f8a  2b4e04                 -sub ecx, dword ptr [esi + 4]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
L_0x00a78f8d:
    // 00a78f8d  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a78f8f  0f8c65000000           -jl 0xa78ffa
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a78ffa;
    }
    // 00a78f95  39c7                   +cmp edi, eax
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
    // 00a78f97  7e02                   -jle 0xa78f9b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a78f9b;
    }
    // 00a78f99  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x00a78f9b:
    // 00a78f9b  bb0f000000             -mov ebx, 0xf
    cpu.ebx = 15 /*0xf*/;
    // 00a78fa0  f6460820               +test byte ptr [esi + 8], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 32 /*0x20*/));
    // 00a78fa4  7405                   -je 0xa78fab
    if (cpu.flags.zf)
    {
        goto L_0x00a78fab;
    }
    // 00a78fa6  bb14000000             -mov ebx, 0x14
    cpu.ebx = 20 /*0x14*/;
L_0x00a78fab:
    // 00a78fab  f6460840               +test byte ptr [esi + 8], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 64 /*0x40*/));
    // 00a78faf  7402                   -je 0xa78fb3
    if (cpu.flags.zf)
    {
        goto L_0x00a78fb3;
    }
    // 00a78fb1  01db                   -add ebx, ebx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebx));
L_0x00a78fb3:
    // 00a78fb3  39df                   +cmp edi, ebx
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
    // 00a78fb5  7e03                   -jle 0xa78fba
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a78fba;
    }
    // 00a78fb7  8d7b01                 -lea edi, [ebx + 1]
    cpu.edi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
L_0x00a78fba:
    // 00a78fba  c645f030               -mov byte ptr [ebp - 0x10], 0x30
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = 48 /*0x30*/;
    // 00a78fbe  39f8                   +cmp eax, edi
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
    // 00a78fc0  7e0a                   -jle 0xa78fcc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a78fcc;
    }
    // 00a78fc2  803c3a35               +cmp byte ptr [edx + edi], 0x35
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
    // 00a78fc6  7204                   -jb 0xa78fcc
    if (cpu.flags.cf)
    {
        goto L_0x00a78fcc;
    }
    // 00a78fc8  c645f039               -mov byte ptr [ebp - 0x10], 0x39
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = 57 /*0x39*/;
L_0x00a78fcc:
    // 00a78fcc  897de4                 -mov dword ptr [ebp - 0x1c], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.edi;
    // 00a78fcf  8d0417                 -lea eax, [edi + edx]
    cpu.eax = x86::reg32(cpu.edi + cpu.edx * 1);
L_0x00a78fd2:
    // 00a78fd2  8b5de4                 -mov ebx, dword ptr [ebp - 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00a78fd5  4b                     -dec ebx
    (cpu.ebx)--;
    // 00a78fd6  48                     -dec eax
    (cpu.eax)--;
    // 00a78fd7  895de4                 -mov dword ptr [ebp - 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.ebx;
    // 00a78fda  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a78fdc  8a7df0                 -mov bh, byte ptr [ebp - 0x10]
    cpu.bh = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a78fdf  38fb                   +cmp bl, bh
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
    // 00a78fe1  7503                   -jne 0xa78fe6
    if (!cpu.flags.zf)
    {
        goto L_0x00a78fe6;
    }
    // 00a78fe3  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a78fe4  ebec                   -jmp 0xa78fd2
    goto L_0x00a78fd2;
L_0x00a78fe6:
    // 00a78fe6  80ff39                 +cmp bh, 0x39
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
    // 00a78fe9  7506                   -jne 0xa78ff1
    if (!cpu.flags.zf)
    {
        goto L_0x00a78ff1;
    }
    // 00a78feb  88df                   -mov bh, bl
    cpu.bh = cpu.bl;
    // 00a78fed  fec7                   -inc bh
    (cpu.bh)++;
    // 00a78fef  8838                   -mov byte ptr [eax], bh
    app->getMemory<x86::reg8>(cpu.eax) = cpu.bh;
L_0x00a78ff1:
    // 00a78ff1  837de400               +cmp dword ptr [ebp - 0x1c], 0
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
    // 00a78ff5  7d03                   -jge 0xa78ffa
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a78ffa;
    }
    // 00a78ff7  4a                     -dec edx
    (cpu.edx)--;
    // 00a78ff8  47                     -inc edi
    (cpu.edi)++;
    // 00a78ff9  41                     -inc ecx
    (cpu.ecx)++;
L_0x00a78ffa:
    // 00a78ffa  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a78ffc  7f18                   -jg 0xa79016
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a79016;
    }
    // 00a78ffe  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 00a79003  b030                   -mov al, 0x30
    cpu.al = 48 /*0x30*/;
    // 00a79005  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a79007  888568ffffff           -mov byte ptr [ebp - 0x98], al
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-152) /* -0x98 */) = cpu.al;
    // 00a7900d  8d9568ffffff           -lea edx, [ebp - 0x98]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-152) /* -0x98 */);
    // 00a79013  894e14                 -mov dword ptr [esi + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.ecx;
L_0x00a79016:
    // 00a79016  8a6608                 -mov ah, byte ptr [esi + 8]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00a79019  f6c402                 +test ah, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 2 /*0x2*/));
    // 00a7901c  7514                   -jne 0xa79032
    if (!cpu.flags.zf)
    {
        goto L_0x00a79032;
    }
    // 00a7901e  f6c404                 +test ah, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 4 /*0x4*/));
    // 00a79021  741e                   -je 0xa79041
    if (cpu.flags.zf)
    {
        goto L_0x00a79041;
    }
    // 00a79023  83f9fc                 +cmp ecx, -4
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
    // 00a79026  7c04                   -jl 0xa7902c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a7902c;
    }
    // 00a79028  3b0e                   +cmp ecx, dword ptr [esi]
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
    // 00a7902a  7c06                   -jl 0xa79032
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a79032;
    }
L_0x00a7902c:
    // 00a7902c  f6460808               +test byte ptr [esi + 8], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 8 /*0x8*/));
    // 00a79030  740f                   -je 0xa79041
    if (cpu.flags.zf)
    {
        goto L_0x00a79041;
    }
L_0x00a79032:
    // 00a79032  8b5de0                 -mov ebx, dword ptr [ebp - 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00a79035  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a79036  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a79038  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00a7903a  e822000000             -call 0xa79061
    cpu.esp -= 4;
    sub_a79061(app, cpu);
    if (cpu.terminate) return;
    // 00a7903f  eb0d                   -jmp 0xa7904e
    goto L_0x00a7904e;
L_0x00a79041:
    // 00a79041  8b45e0                 -mov eax, dword ptr [ebp - 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00a79044  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a79045  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00a79047  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a79049  e831020000             -call 0xa7927f
    cpu.esp -= 4;
    sub_a7927f(app, cpu);
    if (cpu.terminate) return;
L_0x00a7904e:
    // 00a7904e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a79050  668b45ec               -mov ax, word ptr [ebp - 0x14]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00a79054  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a79055  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 00a79058  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79059  8d65f4                 -lea esp, [ebp - 0xc]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a7905c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7905d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7905e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7905f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79060  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a7904e(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a7904e;
    // 00a78f4e  8b45dc                 -mov eax, dword ptr [ebp - 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 00a78f51  8d9569ffffff           -lea edx, [ebp - 0x97]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-151) /* -0x97 */);
    // 00a78f57  83c107                 -add ecx, 7
    (cpu.ecx) += x86::reg32(x86::sreg32(7 /*0x7*/));
L_0x00a78f5a:
    // 00a78f5a  803a30                 +cmp byte ptr [edx], 0x30
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
    // 00a78f5d  7505                   -jne 0xa78f64
    if (!cpu.flags.zf)
    {
        goto L_0x00a78f64;
    }
    // 00a78f5f  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a78f60  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a78f61  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a78f62  ebf6                   -jmp 0xa78f5a
    goto L_0x00a78f5a;
L_0x00a78f64:
    // 00a78f64  8a7e08                 -mov bh, byte ptr [esi + 8]
    cpu.bh = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00a78f67  8b3e                   -mov edi, dword ptr [esi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi);
    // 00a78f69  f6c702                 +test bh, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 2 /*0x2*/));
    // 00a78f6c  740a                   -je 0xa78f78
    if (cpu.flags.zf)
    {
        goto L_0x00a78f78;
    }
    // 00a78f6e  034e04                 -add ecx, dword ptr [esi + 4]
    (cpu.ecx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 00a78f71  8d5901                 -lea ebx, [ecx + 1]
    cpu.ebx = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 00a78f74  01df                   +add edi, ebx
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
    // 00a78f76  eb15                   -jmp 0xa78f8d
    goto L_0x00a78f8d;
L_0x00a78f78:
    // 00a78f78  f6c701                 +test bh, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 1 /*0x1*/));
    // 00a78f7b  7410                   -je 0xa78f8d
    if (cpu.flags.zf)
    {
        goto L_0x00a78f8d;
    }
    // 00a78f7d  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00a78f80  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a78f82  7e03                   -jle 0xa78f87
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a78f87;
    }
    // 00a78f84  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a78f85  eb02                   -jmp 0xa78f89
    goto L_0x00a78f89;
L_0x00a78f87:
    // 00a78f87  01df                   -add edi, ebx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebx));
L_0x00a78f89:
    // 00a78f89  41                     -inc ecx
    (cpu.ecx)++;
    // 00a78f8a  2b4e04                 -sub ecx, dword ptr [esi + 4]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
L_0x00a78f8d:
    // 00a78f8d  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a78f8f  0f8c65000000           -jl 0xa78ffa
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a78ffa;
    }
    // 00a78f95  39c7                   +cmp edi, eax
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
    // 00a78f97  7e02                   -jle 0xa78f9b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a78f9b;
    }
    // 00a78f99  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x00a78f9b:
    // 00a78f9b  bb0f000000             -mov ebx, 0xf
    cpu.ebx = 15 /*0xf*/;
    // 00a78fa0  f6460820               +test byte ptr [esi + 8], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 32 /*0x20*/));
    // 00a78fa4  7405                   -je 0xa78fab
    if (cpu.flags.zf)
    {
        goto L_0x00a78fab;
    }
    // 00a78fa6  bb14000000             -mov ebx, 0x14
    cpu.ebx = 20 /*0x14*/;
L_0x00a78fab:
    // 00a78fab  f6460840               +test byte ptr [esi + 8], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 64 /*0x40*/));
    // 00a78faf  7402                   -je 0xa78fb3
    if (cpu.flags.zf)
    {
        goto L_0x00a78fb3;
    }
    // 00a78fb1  01db                   -add ebx, ebx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebx));
L_0x00a78fb3:
    // 00a78fb3  39df                   +cmp edi, ebx
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
    // 00a78fb5  7e03                   -jle 0xa78fba
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a78fba;
    }
    // 00a78fb7  8d7b01                 -lea edi, [ebx + 1]
    cpu.edi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
L_0x00a78fba:
    // 00a78fba  c645f030               -mov byte ptr [ebp - 0x10], 0x30
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = 48 /*0x30*/;
    // 00a78fbe  39f8                   +cmp eax, edi
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
    // 00a78fc0  7e0a                   -jle 0xa78fcc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a78fcc;
    }
    // 00a78fc2  803c3a35               +cmp byte ptr [edx + edi], 0x35
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
    // 00a78fc6  7204                   -jb 0xa78fcc
    if (cpu.flags.cf)
    {
        goto L_0x00a78fcc;
    }
    // 00a78fc8  c645f039               -mov byte ptr [ebp - 0x10], 0x39
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = 57 /*0x39*/;
L_0x00a78fcc:
    // 00a78fcc  897de4                 -mov dword ptr [ebp - 0x1c], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.edi;
    // 00a78fcf  8d0417                 -lea eax, [edi + edx]
    cpu.eax = x86::reg32(cpu.edi + cpu.edx * 1);
L_0x00a78fd2:
    // 00a78fd2  8b5de4                 -mov ebx, dword ptr [ebp - 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00a78fd5  4b                     -dec ebx
    (cpu.ebx)--;
    // 00a78fd6  48                     -dec eax
    (cpu.eax)--;
    // 00a78fd7  895de4                 -mov dword ptr [ebp - 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.ebx;
    // 00a78fda  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a78fdc  8a7df0                 -mov bh, byte ptr [ebp - 0x10]
    cpu.bh = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a78fdf  38fb                   +cmp bl, bh
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
    // 00a78fe1  7503                   -jne 0xa78fe6
    if (!cpu.flags.zf)
    {
        goto L_0x00a78fe6;
    }
    // 00a78fe3  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a78fe4  ebec                   -jmp 0xa78fd2
    goto L_0x00a78fd2;
L_0x00a78fe6:
    // 00a78fe6  80ff39                 +cmp bh, 0x39
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
    // 00a78fe9  7506                   -jne 0xa78ff1
    if (!cpu.flags.zf)
    {
        goto L_0x00a78ff1;
    }
    // 00a78feb  88df                   -mov bh, bl
    cpu.bh = cpu.bl;
    // 00a78fed  fec7                   -inc bh
    (cpu.bh)++;
    // 00a78fef  8838                   -mov byte ptr [eax], bh
    app->getMemory<x86::reg8>(cpu.eax) = cpu.bh;
L_0x00a78ff1:
    // 00a78ff1  837de400               +cmp dword ptr [ebp - 0x1c], 0
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
    // 00a78ff5  7d03                   -jge 0xa78ffa
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a78ffa;
    }
    // 00a78ff7  4a                     -dec edx
    (cpu.edx)--;
    // 00a78ff8  47                     -inc edi
    (cpu.edi)++;
    // 00a78ff9  41                     -inc ecx
    (cpu.ecx)++;
L_0x00a78ffa:
    // 00a78ffa  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a78ffc  7f18                   -jg 0xa79016
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a79016;
    }
    // 00a78ffe  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 00a79003  b030                   -mov al, 0x30
    cpu.al = 48 /*0x30*/;
    // 00a79005  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a79007  888568ffffff           -mov byte ptr [ebp - 0x98], al
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-152) /* -0x98 */) = cpu.al;
    // 00a7900d  8d9568ffffff           -lea edx, [ebp - 0x98]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-152) /* -0x98 */);
    // 00a79013  894e14                 -mov dword ptr [esi + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.ecx;
L_0x00a79016:
    // 00a79016  8a6608                 -mov ah, byte ptr [esi + 8]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00a79019  f6c402                 +test ah, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 2 /*0x2*/));
    // 00a7901c  7514                   -jne 0xa79032
    if (!cpu.flags.zf)
    {
        goto L_0x00a79032;
    }
    // 00a7901e  f6c404                 +test ah, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 4 /*0x4*/));
    // 00a79021  741e                   -je 0xa79041
    if (cpu.flags.zf)
    {
        goto L_0x00a79041;
    }
    // 00a79023  83f9fc                 +cmp ecx, -4
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
    // 00a79026  7c04                   -jl 0xa7902c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a7902c;
    }
    // 00a79028  3b0e                   +cmp ecx, dword ptr [esi]
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
    // 00a7902a  7c06                   -jl 0xa79032
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a79032;
    }
L_0x00a7902c:
    // 00a7902c  f6460808               +test byte ptr [esi + 8], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 8 /*0x8*/));
    // 00a79030  740f                   -je 0xa79041
    if (cpu.flags.zf)
    {
        goto L_0x00a79041;
    }
L_0x00a79032:
    // 00a79032  8b5de0                 -mov ebx, dword ptr [ebp - 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00a79035  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a79036  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a79038  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00a7903a  e822000000             -call 0xa79061
    cpu.esp -= 4;
    sub_a79061(app, cpu);
    if (cpu.terminate) return;
    // 00a7903f  eb0d                   -jmp 0xa7904e
    goto L_0x00a7904e;
L_0x00a79041:
    // 00a79041  8b45e0                 -mov eax, dword ptr [ebp - 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00a79044  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a79045  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00a79047  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a79049  e831020000             -call 0xa7927f
    cpu.esp -= 4;
    sub_a7927f(app, cpu);
    if (cpu.terminate) return;
L_0x00a7904e:
L_entry_0x00a7904e:
    // 00a7904e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a79050  668b45ec               -mov ax, word ptr [ebp - 0x14]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00a79054  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a79055  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 00a79058  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79059  8d65f4                 -lea esp, [ebp - 0xc]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a7905c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7905d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7905e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7905f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79060  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a79061(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a79061  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a79062  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00a79064  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a79065  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a79066  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a79069  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a7906a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a7906b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a7906c  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00a7906e  41                     -inc ecx
    (cpu.ecx)++;
    // 00a7906f  8955f4                 -mov dword ptr [ebp - 0xc], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edx;
    // 00a79072  894de8                 -mov dword ptr [ebp - 0x18], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.ecx;
    // 00a79075  8a6008                 -mov ah, byte ptr [eax + 8]
    cpu.ah = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a79078  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a7907a  f6c404                 +test ah, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 4 /*0x4*/));
    // 00a7907d  7425                   -je 0xa790a4
    if (cpu.flags.zf)
    {
        goto L_0x00a790a4;
    }
    // 00a7907f  3b5df4                 +cmp ebx, dword ptr [ebp - 0xc]
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
    // 00a79082  7d0c                   -jge 0xa79090
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a79090;
    }
    // 00a79084  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a79087  f6460810               +test byte ptr [esi + 8], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 16 /*0x10*/));
    // 00a7908b  7503                   -jne 0xa79090
    if (!cpu.flags.zf)
    {
        goto L_0x00a79090;
    }
    // 00a7908d  895df4                 -mov dword ptr [ebp - 0xc], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ebx;
L_0x00a79090:
    // 00a79090  8b75e8                 -mov esi, dword ptr [ebp - 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a79093  8b7df4                 -mov edi, dword ptr [ebp - 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a79096  29f7                   -sub edi, esi
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00a79098  897df4                 -mov dword ptr [ebp - 0xc], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edi;
    // 00a7909b  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a7909d  7d05                   -jge 0xa790a4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a790a4;
    }
    // 00a7909f  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a790a1  894df4                 -mov dword ptr [ebp - 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ecx;
L_0x00a790a4:
    // 00a790a4  8b75e8                 -mov esi, dword ptr [ebp - 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a790a7  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a790a9  0f8fa4000000           -jg 0xa79153
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a79153;
    }
    // 00a790af  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a790b2  f6460808               +test byte ptr [esi + 8], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 8 /*0x8*/));
    // 00a790b6  7526                   -jne 0xa790de
    if (!cpu.flags.zf)
    {
        goto L_0x00a790de;
    }
    // 00a790b8  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a790bb  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00a790bd  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 00a790bf  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a790c2  42                     -inc edx
    (cpu.edx)++;
    // 00a790c3  c60630                 -mov byte ptr [esi], 0x30
    app->getMemory<x86::reg8>(cpu.esi) = 48 /*0x30*/;
    // 00a790c6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a790c8  7f09                   -jg 0xa790d3
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a790d3;
    }
    // 00a790ca  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a790cd  f6460810               +test byte ptr [esi + 8], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 16 /*0x10*/));
    // 00a790d1  740b                   -je 0xa790de
    if (cpu.flags.zf)
    {
        goto L_0x00a790de;
    }
L_0x00a790d3:
    // 00a790d3  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a790d6  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00a790d8  01cf                   -add edi, ecx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a790da  42                     -inc edx
    (cpu.edx)++;
    // 00a790db  c6072e                 -mov byte ptr [edi], 0x2e
    app->getMemory<x86::reg8>(cpu.edi) = 46 /*0x2e*/;
L_0x00a790de:
    // 00a790de  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a790e1  89561c                 -mov dword ptr [esi + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 00a790e4  8b75e8                 -mov esi, dword ptr [ebp - 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a790e7  8b7df4                 -mov edi, dword ptr [ebp - 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a790ea  f7de                   -neg esi
    cpu.esi = ~cpu.esi + 1;
    // 00a790ec  39fe                   +cmp esi, edi
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
    // 00a790ee  7e0a                   -jle 0xa790fa
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a790fa;
    }
    // 00a790f0  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a790f2  897de8                 -mov dword ptr [ebp - 0x18], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.edi;
    // 00a790f5  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 00a790f7  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
L_0x00a790fa:
    // 00a790fa  8b7df0                 -mov edi, dword ptr [ebp - 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a790fd  8b75e8                 -mov esi, dword ptr [ebp - 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a79100  897718                 -mov dword ptr [edi + 0x18], esi
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 00a79103  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00a79105  897720                 -mov dword ptr [edi + 0x20], esi
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */) = cpu.esi;
    // 00a79108  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00a7910a  894f20                 -mov dword ptr [edi + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00a7910d  8b7df4                 -mov edi, dword ptr [ebp - 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a79110  01f7                   -add edi, esi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.esi));
    // 00a79112  897df4                 -mov dword ptr [ebp - 0xc], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edi;
    // 00a79115  39fb                   +cmp ebx, edi
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
    // 00a79117  7e02                   -jle 0xa7911b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a7911b;
    }
    // 00a79119  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
L_0x00a7911b:
    // 00a7911b  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a7911e  8b75ec                 -mov esi, dword ptr [ebp - 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00a79121  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00a79123  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a79125  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a79126  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a79128  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a7912a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a7912b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a7912d  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a79130  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a79132  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a79134  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a79137  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a79139  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7913a  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a7913b  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a7913e  895e24                 -mov dword ptr [esi + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 00a79141  8b75f4                 -mov esi, dword ptr [ebp - 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a79144  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00a79146  29de                   +sub esi, ebx
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
    // 00a79148  8b5df0                 -mov ebx, dword ptr [ebp - 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a7914b  897328                 -mov dword ptr [ebx + 0x28], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */) = cpu.esi;
    // 00a7914e  e90d010000             -jmp 0xa79260
    goto L_0x00a79260;
L_0x00a79153:
    // 00a79153  39f3                   +cmp ebx, esi
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
    // 00a79155  7d70                   -jge 0xa791c7
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a791c7;
    }
    // 00a79157  8b75ec                 -mov esi, dword ptr [ebp - 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00a7915a  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a7915d  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00a7915f  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a79160  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a79162  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a79164  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a79165  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a79167  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a7916a  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a7916c  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a7916e  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a79171  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a79173  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79174  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a79175  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a79178  895e1c                 -mov dword ptr [esi + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 00a7917b  8b75e8                 -mov esi, dword ptr [ebp - 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a7917e  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00a79180  29de                   -sub esi, ebx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a79182  8b5df0                 -mov ebx, dword ptr [ebp - 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a79185  897320                 -mov dword ptr [ebx + 0x20], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = cpu.esi;
    // 00a79188  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a7918b  8b5de8                 -mov ebx, dword ptr [ebp - 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a7918e  8a4e08                 -mov cl, byte ptr [esi + 8]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00a79191  895e18                 -mov dword ptr [esi + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 00a79194  f6c108                 +test cl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 8 /*0x8*/));
    // 00a79197  7520                   -jne 0xa791b9
    if (!cpu.flags.zf)
    {
        goto L_0x00a791b9;
    }
    // 00a79199  837df400               +cmp dword ptr [ebp - 0xc], 0
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
    // 00a7919d  7f05                   -jg 0xa791a4
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a791a4;
    }
    // 00a7919f  f6c110                 +test cl, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 16 /*0x10*/));
    // 00a791a2  7415                   -je 0xa791b9
    if (cpu.flags.zf)
    {
        goto L_0x00a791b9;
    }
L_0x00a791a4:
    // 00a791a4  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a791a7  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00a791a9  01cb                   +add ebx, ecx
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
    // 00a791ab  c6032e                 -mov byte ptr [ebx], 0x2e
    app->getMemory<x86::reg8>(cpu.ebx) = 46 /*0x2e*/;
    // 00a791ae  8b5df0                 -mov ebx, dword ptr [ebp - 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a791b1  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a791b2  c7432401000000         -mov dword ptr [ebx + 0x24], 1
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */) = 1 /*0x1*/;
L_0x00a791b9:
    // 00a791b9  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a791bc  8b5df4                 -mov ebx, dword ptr [ebp - 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a791bf  895e28                 -mov dword ptr [esi + 0x28], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.ebx;
    // 00a791c2  e999000000             -jmp 0xa79260
    goto L_0x00a79260;
L_0x00a791c7:
    // 00a791c7  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a791ca  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00a791cc  8b75ec                 -mov esi, dword ptr [ebp - 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00a791cf  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a791d0  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a791d2  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a791d4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a791d5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a791d7  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a791da  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a791dc  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a791de  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a791e1  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a791e3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a791e4  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a791e5  8b7df0                 -mov edi, dword ptr [ebp - 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a791e8  8b75e8                 -mov esi, dword ptr [ebp - 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a791eb  8a6f08                 -mov ch, byte ptr [edi + 8]
    cpu.ch = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 00a791ee  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 00a791f0  29f3                   -sub ebx, esi
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00a791f2  897718                 -mov dword ptr [edi + 0x18], esi
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 00a791f5  f6c508                 +test ch, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 8 /*0x8*/));
    // 00a791f8  7518                   -jne 0xa79212
    if (!cpu.flags.zf)
    {
        goto L_0x00a79212;
    }
    // 00a791fa  837df400               +cmp dword ptr [ebp - 0xc], 0
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
    // 00a791fe  7f05                   -jg 0xa79205
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a79205;
    }
    // 00a79200  f6c510                 +test ch, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 16 /*0x10*/));
    // 00a79203  741c                   -je 0xa79221
    if (cpu.flags.zf)
    {
        goto L_0x00a79221;
    }
L_0x00a79205:
    // 00a79205  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a79208  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00a7920a  01c7                   +add edi, eax
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
    // 00a7920c  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a7920d  c6072e                 -mov byte ptr [edi], 0x2e
    app->getMemory<x86::reg8>(cpu.edi) = 46 /*0x2e*/;
    // 00a79210  eb0f                   -jmp 0xa79221
    goto L_0x00a79221;
L_0x00a79212:
    // 00a79212  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a79215  803e30                 +cmp byte ptr [esi], 0x30
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
    // 00a79218  7507                   -jne 0xa79221
    if (!cpu.flags.zf)
    {
        goto L_0x00a79221;
    }
    // 00a7921a  c7471800000000         -mov dword ptr [edi + 0x18], 0
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
L_0x00a79221:
    // 00a79221  8b4df4                 -mov ecx, dword ptr [ebp - 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a79224  39cb                   +cmp ebx, ecx
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
    // 00a79226  7e02                   -jle 0xa7922a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a7922a;
    }
    // 00a79228  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
L_0x00a7922a:
    // 00a7922a  8b75ec                 -mov esi, dword ptr [ebp - 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00a7922d  0375e8                 -add esi, dword ptr [ebp - 0x18]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */)));
    // 00a79230  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a79233  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00a79235  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a79237  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a79238  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a7923a  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a7923c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a7923d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a7923f  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a79242  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a79244  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a79246  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a79249  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a7924b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7924c  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a7924d  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a79250  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00a79252  89561c                 -mov dword ptr [esi + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 00a79255  8b75f4                 -mov esi, dword ptr [ebp - 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a79258  29de                   -sub esi, ebx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a7925a  8b5df0                 -mov ebx, dword ptr [ebp - 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a7925d  897320                 -mov dword ptr [ebx + 0x20], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = cpu.esi;
L_0x00a79260:
    // 00a79260  035508                 -add edx, dword ptr [ebp + 8]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */)));
    // 00a79263  c60200                 -mov byte ptr [edx], 0
    app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
    // 00a79266  8d65f8                 -lea esp, [ebp - 8]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00a79269  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7926a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7926b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7926c  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void sub_a79266(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a79266;
    // 00a79061  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a79062  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00a79064  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a79065  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a79066  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a79069  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a7906a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a7906b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a7906c  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00a7906e  41                     -inc ecx
    (cpu.ecx)++;
    // 00a7906f  8955f4                 -mov dword ptr [ebp - 0xc], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edx;
    // 00a79072  894de8                 -mov dword ptr [ebp - 0x18], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.ecx;
    // 00a79075  8a6008                 -mov ah, byte ptr [eax + 8]
    cpu.ah = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a79078  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a7907a  f6c404                 +test ah, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 4 /*0x4*/));
    // 00a7907d  7425                   -je 0xa790a4
    if (cpu.flags.zf)
    {
        goto L_0x00a790a4;
    }
    // 00a7907f  3b5df4                 +cmp ebx, dword ptr [ebp - 0xc]
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
    // 00a79082  7d0c                   -jge 0xa79090
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a79090;
    }
    // 00a79084  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a79087  f6460810               +test byte ptr [esi + 8], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 16 /*0x10*/));
    // 00a7908b  7503                   -jne 0xa79090
    if (!cpu.flags.zf)
    {
        goto L_0x00a79090;
    }
    // 00a7908d  895df4                 -mov dword ptr [ebp - 0xc], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ebx;
L_0x00a79090:
    // 00a79090  8b75e8                 -mov esi, dword ptr [ebp - 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a79093  8b7df4                 -mov edi, dword ptr [ebp - 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a79096  29f7                   -sub edi, esi
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00a79098  897df4                 -mov dword ptr [ebp - 0xc], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edi;
    // 00a7909b  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a7909d  7d05                   -jge 0xa790a4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a790a4;
    }
    // 00a7909f  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a790a1  894df4                 -mov dword ptr [ebp - 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ecx;
L_0x00a790a4:
    // 00a790a4  8b75e8                 -mov esi, dword ptr [ebp - 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a790a7  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a790a9  0f8fa4000000           -jg 0xa79153
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a79153;
    }
    // 00a790af  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a790b2  f6460808               +test byte ptr [esi + 8], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 8 /*0x8*/));
    // 00a790b6  7526                   -jne 0xa790de
    if (!cpu.flags.zf)
    {
        goto L_0x00a790de;
    }
    // 00a790b8  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a790bb  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00a790bd  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 00a790bf  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a790c2  42                     -inc edx
    (cpu.edx)++;
    // 00a790c3  c60630                 -mov byte ptr [esi], 0x30
    app->getMemory<x86::reg8>(cpu.esi) = 48 /*0x30*/;
    // 00a790c6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a790c8  7f09                   -jg 0xa790d3
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a790d3;
    }
    // 00a790ca  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a790cd  f6460810               +test byte ptr [esi + 8], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 16 /*0x10*/));
    // 00a790d1  740b                   -je 0xa790de
    if (cpu.flags.zf)
    {
        goto L_0x00a790de;
    }
L_0x00a790d3:
    // 00a790d3  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a790d6  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00a790d8  01cf                   -add edi, ecx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a790da  42                     -inc edx
    (cpu.edx)++;
    // 00a790db  c6072e                 -mov byte ptr [edi], 0x2e
    app->getMemory<x86::reg8>(cpu.edi) = 46 /*0x2e*/;
L_0x00a790de:
    // 00a790de  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a790e1  89561c                 -mov dword ptr [esi + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 00a790e4  8b75e8                 -mov esi, dword ptr [ebp - 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a790e7  8b7df4                 -mov edi, dword ptr [ebp - 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a790ea  f7de                   -neg esi
    cpu.esi = ~cpu.esi + 1;
    // 00a790ec  39fe                   +cmp esi, edi
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
    // 00a790ee  7e0a                   -jle 0xa790fa
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a790fa;
    }
    // 00a790f0  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a790f2  897de8                 -mov dword ptr [ebp - 0x18], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.edi;
    // 00a790f5  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 00a790f7  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
L_0x00a790fa:
    // 00a790fa  8b7df0                 -mov edi, dword ptr [ebp - 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a790fd  8b75e8                 -mov esi, dword ptr [ebp - 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a79100  897718                 -mov dword ptr [edi + 0x18], esi
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 00a79103  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00a79105  897720                 -mov dword ptr [edi + 0x20], esi
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */) = cpu.esi;
    // 00a79108  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00a7910a  894f20                 -mov dword ptr [edi + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00a7910d  8b7df4                 -mov edi, dword ptr [ebp - 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a79110  01f7                   -add edi, esi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.esi));
    // 00a79112  897df4                 -mov dword ptr [ebp - 0xc], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edi;
    // 00a79115  39fb                   +cmp ebx, edi
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
    // 00a79117  7e02                   -jle 0xa7911b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a7911b;
    }
    // 00a79119  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
L_0x00a7911b:
    // 00a7911b  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a7911e  8b75ec                 -mov esi, dword ptr [ebp - 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00a79121  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00a79123  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a79125  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a79126  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a79128  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a7912a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a7912b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a7912d  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a79130  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a79132  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a79134  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a79137  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a79139  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7913a  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a7913b  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a7913e  895e24                 -mov dword ptr [esi + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 00a79141  8b75f4                 -mov esi, dword ptr [ebp - 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a79144  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00a79146  29de                   +sub esi, ebx
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
    // 00a79148  8b5df0                 -mov ebx, dword ptr [ebp - 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a7914b  897328                 -mov dword ptr [ebx + 0x28], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */) = cpu.esi;
    // 00a7914e  e90d010000             -jmp 0xa79260
    goto L_0x00a79260;
L_0x00a79153:
    // 00a79153  39f3                   +cmp ebx, esi
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
    // 00a79155  7d70                   -jge 0xa791c7
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a791c7;
    }
    // 00a79157  8b75ec                 -mov esi, dword ptr [ebp - 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00a7915a  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a7915d  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00a7915f  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a79160  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a79162  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a79164  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a79165  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a79167  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a7916a  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a7916c  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a7916e  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a79171  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a79173  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79174  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a79175  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a79178  895e1c                 -mov dword ptr [esi + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 00a7917b  8b75e8                 -mov esi, dword ptr [ebp - 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a7917e  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00a79180  29de                   -sub esi, ebx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a79182  8b5df0                 -mov ebx, dword ptr [ebp - 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a79185  897320                 -mov dword ptr [ebx + 0x20], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = cpu.esi;
    // 00a79188  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a7918b  8b5de8                 -mov ebx, dword ptr [ebp - 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a7918e  8a4e08                 -mov cl, byte ptr [esi + 8]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00a79191  895e18                 -mov dword ptr [esi + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 00a79194  f6c108                 +test cl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 8 /*0x8*/));
    // 00a79197  7520                   -jne 0xa791b9
    if (!cpu.flags.zf)
    {
        goto L_0x00a791b9;
    }
    // 00a79199  837df400               +cmp dword ptr [ebp - 0xc], 0
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
    // 00a7919d  7f05                   -jg 0xa791a4
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a791a4;
    }
    // 00a7919f  f6c110                 +test cl, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 16 /*0x10*/));
    // 00a791a2  7415                   -je 0xa791b9
    if (cpu.flags.zf)
    {
        goto L_0x00a791b9;
    }
L_0x00a791a4:
    // 00a791a4  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a791a7  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00a791a9  01cb                   +add ebx, ecx
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
    // 00a791ab  c6032e                 -mov byte ptr [ebx], 0x2e
    app->getMemory<x86::reg8>(cpu.ebx) = 46 /*0x2e*/;
    // 00a791ae  8b5df0                 -mov ebx, dword ptr [ebp - 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a791b1  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a791b2  c7432401000000         -mov dword ptr [ebx + 0x24], 1
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */) = 1 /*0x1*/;
L_0x00a791b9:
    // 00a791b9  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a791bc  8b5df4                 -mov ebx, dword ptr [ebp - 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a791bf  895e28                 -mov dword ptr [esi + 0x28], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.ebx;
    // 00a791c2  e999000000             -jmp 0xa79260
    goto L_0x00a79260;
L_0x00a791c7:
    // 00a791c7  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a791ca  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00a791cc  8b75ec                 -mov esi, dword ptr [ebp - 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00a791cf  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a791d0  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a791d2  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a791d4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a791d5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a791d7  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a791da  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a791dc  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a791de  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a791e1  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a791e3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a791e4  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a791e5  8b7df0                 -mov edi, dword ptr [ebp - 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a791e8  8b75e8                 -mov esi, dword ptr [ebp - 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a791eb  8a6f08                 -mov ch, byte ptr [edi + 8]
    cpu.ch = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 00a791ee  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 00a791f0  29f3                   -sub ebx, esi
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00a791f2  897718                 -mov dword ptr [edi + 0x18], esi
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 00a791f5  f6c508                 +test ch, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 8 /*0x8*/));
    // 00a791f8  7518                   -jne 0xa79212
    if (!cpu.flags.zf)
    {
        goto L_0x00a79212;
    }
    // 00a791fa  837df400               +cmp dword ptr [ebp - 0xc], 0
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
    // 00a791fe  7f05                   -jg 0xa79205
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a79205;
    }
    // 00a79200  f6c510                 +test ch, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 16 /*0x10*/));
    // 00a79203  741c                   -je 0xa79221
    if (cpu.flags.zf)
    {
        goto L_0x00a79221;
    }
L_0x00a79205:
    // 00a79205  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a79208  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00a7920a  01c7                   +add edi, eax
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
    // 00a7920c  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a7920d  c6072e                 -mov byte ptr [edi], 0x2e
    app->getMemory<x86::reg8>(cpu.edi) = 46 /*0x2e*/;
    // 00a79210  eb0f                   -jmp 0xa79221
    goto L_0x00a79221;
L_0x00a79212:
    // 00a79212  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a79215  803e30                 +cmp byte ptr [esi], 0x30
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
    // 00a79218  7507                   -jne 0xa79221
    if (!cpu.flags.zf)
    {
        goto L_0x00a79221;
    }
    // 00a7921a  c7471800000000         -mov dword ptr [edi + 0x18], 0
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
L_0x00a79221:
    // 00a79221  8b4df4                 -mov ecx, dword ptr [ebp - 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a79224  39cb                   +cmp ebx, ecx
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
    // 00a79226  7e02                   -jle 0xa7922a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a7922a;
    }
    // 00a79228  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
L_0x00a7922a:
    // 00a7922a  8b75ec                 -mov esi, dword ptr [ebp - 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00a7922d  0375e8                 -add esi, dword ptr [ebp - 0x18]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */)));
    // 00a79230  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a79233  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00a79235  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a79237  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a79238  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a7923a  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a7923c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a7923d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a7923f  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a79242  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a79244  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a79246  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a79249  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a7924b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7924c  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a7924d  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a79250  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00a79252  89561c                 -mov dword ptr [esi + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 00a79255  8b75f4                 -mov esi, dword ptr [ebp - 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a79258  29de                   -sub esi, ebx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a7925a  8b5df0                 -mov ebx, dword ptr [ebp - 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a7925d  897320                 -mov dword ptr [ebx + 0x20], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = cpu.esi;
L_0x00a79260:
    // 00a79260  035508                 -add edx, dword ptr [ebp + 8]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */)));
    // 00a79263  c60200                 -mov byte ptr [edx], 0
    app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
L_entry_0x00a79266:
    // 00a79266  8d65f8                 -lea esp, [ebp - 8]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00a79269  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7926a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7926b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7926c  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void sub_a7927f(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00a7927f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a79280  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00a79282  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a79283  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a79284  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00a79287  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a79288  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a79289  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a7928a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a7928b  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00a7928d  8945ec                 -mov dword ptr [ebp - 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
    // 00a79290  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a79293  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a79296  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a79298  7f05                   -jg 0xa7929f
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a7929f;
    }
    // 00a7929a  0155ec                 +add dword ptr [ebp - 0x14], edx
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
    // 00a7929d  eb0e                   -jmp 0xa792ad
    goto L_0x00a792ad;
L_0x00a7929f:
    // 00a7929f  8b5dec                 -mov ebx, dword ptr [ebp - 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00a792a2  29d3                   -sub ebx, edx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a792a4  895dec                 -mov dword ptr [ebp - 0x14], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ebx;
    // 00a792a7  8d4b01                 -lea ecx, [ebx + 1]
    cpu.ecx = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 00a792aa  894dec                 -mov dword ptr [ebp - 0x14], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ecx;
L_0x00a792ad:
    // 00a792ad  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a792b0  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00a792b2  8a5008                 -mov dl, byte ptr [eax + 8]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a792b5  897df4                 -mov dword ptr [ebp - 0xc], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edi;
    // 00a792b8  f6c204                 +test dl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 4 /*0x4*/));
    // 00a792bb  741b                   -je 0xa792d8
    if (cpu.flags.zf)
    {
        goto L_0x00a792d8;
    }
    // 00a792bd  8b45e0                 -mov eax, dword ptr [ebp - 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00a792c0  3b45ec                 +cmp eax, dword ptr [ebp - 0x14]
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
    // 00a792c3  7d03                   -jge 0xa792c8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a792c8;
    }
    // 00a792c5  8945ec                 -mov dword ptr [ebp - 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
L_0x00a792c8:
    // 00a792c8  8b5dec                 -mov ebx, dword ptr [ebp - 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00a792cb  4b                     -dec ebx
    (cpu.ebx)--;
    // 00a792cc  895dec                 -mov dword ptr [ebp - 0x14], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ebx;
    // 00a792cf  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a792d1  7d05                   -jge 0xa792d8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a792d8;
    }
    // 00a792d3  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00a792d5  8975ec                 -mov dword ptr [ebp - 0x14], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.esi;
L_0x00a792d8:
    // 00a792d8  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a792db  8b7804                 -mov edi, dword ptr [eax + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a792de  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a792e0  7f16                   -jg 0xa792f8
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a792f8;
    }
    // 00a792e2  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a792e5  8b5d08                 -mov ebx, dword ptr [ebp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a792e8  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a792eb  01d8                   +add eax, ebx
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
    // 00a792ed  8955f4                 -mov dword ptr [ebp - 0xc], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edx;
    // 00a792f0  c60030                 -mov byte ptr [eax], 0x30
    app->getMemory<x86::reg8>(cpu.eax) = 48 /*0x30*/;
    // 00a792f3  e97c000000             -jmp 0xa79374
    goto L_0x00a79374;
L_0x00a792f8:
    // 00a792f8  8b55e0                 -mov edx, dword ptr [ebp - 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00a792fb  897df0                 -mov dword ptr [ebp - 0x10], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edi;
    // 00a792fe  39d7                   +cmp edi, edx
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
    // 00a79300  7e03                   -jle 0xa79305
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a79305;
    }
    // 00a79302  8955f0                 -mov dword ptr [ebp - 0x10], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edx;
L_0x00a79305:
    // 00a79305  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a79308  8b5df4                 -mov ebx, dword ptr [ebp - 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a7930b  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a7930e  8b75e4                 -mov esi, dword ptr [ebp - 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00a79311  01df                   -add edi, ebx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00a79313  8b55e8                 -mov edx, dword ptr [ebp - 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a79316  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a79317  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a79319  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a7931b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a7931c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a7931e  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a79321  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a79323  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a79325  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a79328  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a7932a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7932b  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a7932c  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a7932f  8b75e4                 -mov esi, dword ptr [ebp - 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00a79332  8b7de0                 -mov edi, dword ptr [ebp - 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00a79335  8d0c03                 -lea ecx, [ebx + eax]
    cpu.ecx = x86::reg32(cpu.ebx + cpu.eax * 1);
    // 00a79338  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00a7933a  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00a7933c  894df4                 -mov dword ptr [ebp - 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ecx;
    // 00a7933f  8975e4                 -mov dword ptr [ebp - 0x1c], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.esi;
    // 00a79342  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00a79345  897de0                 -mov dword ptr [ebp - 0x20], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.edi;
    // 00a79348  39d8                   +cmp eax, ebx
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
    // 00a7934a  7d28                   -jge 0xa79374
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a79374;
    }
    // 00a7934c  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a7934f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a79351  8b75f4                 -mov esi, dword ptr [ebp - 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a79354  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a79356  ba30000000             -mov edx, 0x30
    cpu.edx = 48 /*0x30*/;
    // 00a7935b  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 00a7935e  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a79361  8b5df0                 -mov ebx, dword ptr [ebp - 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a79364  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00a79366  e805a8ffff             -call 0xa73b70
    cpu.esp -= 4;
    sub_a73b70(app, cpu);
    if (cpu.terminate) return;
    // 00a7936b  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a7936e  8d3c06                 -lea edi, [esi + eax]
    cpu.edi = x86::reg32(cpu.esi + cpu.eax * 1);
    // 00a79371  897df4                 -mov dword ptr [ebp - 0xc], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edi;
L_0x00a79374:
    // 00a79374  8b55e8                 -mov edx, dword ptr [ebp - 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a79377  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a7937a  894218                 -mov dword ptr [edx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00a7937d  f6420808               +test byte ptr [edx + 8], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(8) /* 0x8 */) & 8 /*0x8*/));
    // 00a79381  7520                   -jne 0xa793a3
    if (!cpu.flags.zf)
    {
        goto L_0x00a793a3;
    }
    // 00a79383  837dec00               +cmp dword ptr [ebp - 0x14], 0
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
    // 00a79387  7f09                   -jg 0xa79392
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a79392;
    }
    // 00a79389  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a7938c  f6400810               +test byte ptr [eax + 8], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8) /* 0x8 */) & 16 /*0x10*/));
    // 00a79390  7411                   -je 0xa793a3
    if (cpu.flags.zf)
    {
        goto L_0x00a793a3;
    }
L_0x00a79392:
    // 00a79392  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a79395  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a79398  8d7001                 -lea esi, [eax + 1]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a7939b  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 00a7939d  8975f4                 -mov dword ptr [ebp - 0xc], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.esi;
    // 00a793a0  c6002e                 -mov byte ptr [eax], 0x2e
    app->getMemory<x86::reg8>(cpu.eax) = 46 /*0x2e*/;
L_0x00a793a3:
    // 00a793a3  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a793a6  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a793a9  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a793ab  7d25                   -jge 0xa793d2
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a793d2;
    }
    // 00a793ad  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a793b0  8b4df4                 -mov ecx, dword ptr [ebp - 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a793b3  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00a793b5  8955f0                 -mov dword ptr [ebp - 0x10], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edx;
    // 00a793b8  ba30000000             -mov edx, 0x30
    cpu.edx = 48 /*0x30*/;
    // 00a793bd  f7db                   -neg ebx
    cpu.ebx = ~cpu.ebx + 1;
    // 00a793bf  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a793c1  895df0                 -mov dword ptr [ebp - 0x10], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.ebx;
    // 00a793c4  e8a7a7ffff             -call 0xa73b70
    cpu.esp -= 4;
    sub_a73b70(app, cpu);
    if (cpu.terminate) return;
    // 00a793c9  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a793cc  8d3401                 -lea esi, [ecx + eax]
    cpu.esi = x86::reg32(cpu.ecx + cpu.eax * 1);
    // 00a793cf  8975f4                 -mov dword ptr [ebp - 0xc], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.esi;
L_0x00a793d2:
    // 00a793d2  8b7dec                 -mov edi, dword ptr [ebp - 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00a793d5  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a793d7  7e49                   -jle 0xa79422
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a79422;
    }
    // 00a793d9  3b7de0                 +cmp edi, dword ptr [ebp - 0x20]
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
    // 00a793dc  7d03                   -jge 0xa793e1
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a793e1;
    }
    // 00a793de  897de0                 -mov dword ptr [ebp - 0x20], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.edi;
L_0x00a793e1:
    // 00a793e1  8b5de0                 -mov ebx, dword ptr [ebp - 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00a793e4  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a793e6  7426                   -je 0xa7940e
    if (cpu.flags.zf)
    {
        goto L_0x00a7940e;
    }
    // 00a793e8  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a793eb  8b4df4                 -mov ecx, dword ptr [ebp - 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a793ee  8b75e4                 -mov esi, dword ptr [ebp - 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00a793f1  01cf                   -add edi, ecx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a793f3  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00a793f5  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a793f6  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a793f8  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a793fa  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a793fb  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a793fd  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a79400  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a79402  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a79404  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a79407  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a79409  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7940a  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a7940b  015df4                 -add dword ptr [ebp - 0xc], ebx
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */)) += x86::reg32(x86::sreg32(cpu.ebx));
L_0x00a7940e:
    // 00a7940e  8b55e8                 -mov edx, dword ptr [ebp - 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a79411  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a79414  8b7de0                 -mov edi, dword ptr [ebp - 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00a79417  89421c                 -mov dword ptr [edx + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00a7941a  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00a7941d  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00a7941f  894220                 -mov dword ptr [edx + 0x20], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */) = cpu.eax;
L_0x00a79422:
    // 00a79422  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a79425  83780c00               +cmp dword ptr [eax + 0xc], 0
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
    // 00a79429  7416                   -je 0xa79441
    if (cpu.flags.zf)
    {
        goto L_0x00a79441;
    }
    // 00a7942b  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a7942e  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a79431  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a79434  8b55e8                 -mov edx, dword ptr [ebp - 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a79437  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a79439  8a520c                 -mov dl, byte ptr [edx + 0xc]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00a7943c  895df4                 -mov dword ptr [ebp - 0xc], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ebx;
    // 00a7943f  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
L_0x00a79441:
    // 00a79441  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a79444  8b75dc                 -mov esi, dword ptr [ebp - 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 00a79447  40                     -inc eax
    (cpu.eax)++;
    // 00a79448  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a7944a  7c0f                   -jl 0xa7945b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a7945b;
    }
    // 00a7944c  8b55f4                 -mov edx, dword ptr [ebp - 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a7944f  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 00a79452  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a79455  c604022b               -mov byte ptr [edx + eax], 0x2b
    app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1) = 43 /*0x2b*/;
    // 00a79459  eb14                   -jmp 0xa7946f
    goto L_0x00a7946f;
L_0x00a7945b:
    // 00a7945b  8b55f4                 -mov edx, dword ptr [ebp - 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a7945e  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 00a79460  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 00a79463  f7df                   -neg edi
    cpu.edi = ~cpu.edi + 1;
    // 00a79465  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a79468  897ddc                 -mov dword ptr [ebp - 0x24], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.edi;
    // 00a7946b  c604022d               -mov byte ptr [edx + eax], 0x2d
    app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1) = 45 /*0x2d*/;
L_0x00a7946f:
    // 00a7946f  8b5de8                 -mov ebx, dword ptr [ebp - 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a79472  8b5b10                 -mov ebx, dword ptr [ebx + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 00a79475  83fb03                 +cmp ebx, 3
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
    // 00a79478  773e                   -ja 0xa794b8
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a794b8;
    }
    // 00a7947a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a7947c  2eff24856f92a700       -jmp dword ptr cs:[eax*4 + 0xa7926f]
    cpu.ip = app->getMemory<x86::reg32>(10981999 + cpu.eax * 4); goto dynamic_jump;
  case 0x00a79484:
    // 00a79484  817ddce8030000         +cmp dword ptr [ebp - 0x24], 0x3e8
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
    // 00a7948b  7d26                   -jge 0xa794b3
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a794b3;
    }
    // 00a7948d  bb03000000             -mov ebx, 3
    cpu.ebx = 3 /*0x3*/;
    // 00a79492  eb24                   -jmp 0xa794b8
    goto L_0x00a794b8;
  case 0x00a79494:
    // 00a79494  837ddc0a               +cmp dword ptr [ebp - 0x24], 0xa
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
    // 00a79498  7c05                   -jl 0xa7949f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a7949f;
    }
    // 00a7949a  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
  [[fallthrough]];
  case 0x00a7949f:
L_0x00a7949f:
    // 00a7949f  837ddc64               +cmp dword ptr [ebp - 0x24], 0x64
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
    // 00a794a3  7c05                   -jl 0xa794aa
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a794aa;
    }
    // 00a794a5  bb03000000             -mov ebx, 3
    cpu.ebx = 3 /*0x3*/;
  [[fallthrough]];
  case 0x00a794aa:
L_0x00a794aa:
    // 00a794aa  817ddce8030000         +cmp dword ptr [ebp - 0x24], 0x3e8
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
    // 00a794b1  7c05                   -jl 0xa794b8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a794b8;
    }
L_0x00a794b3:
    // 00a794b3  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
L_0x00a794b8:
    // 00a794b8  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a794bb  895810                 -mov dword ptr [eax + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 00a794be  83fb04                 +cmp ebx, 4
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
    // 00a794c1  7c4b                   -jl 0xa7950e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a7950e;
    }
    // 00a794c3  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00a794c5  8b45dc                 -mov eax, dword ptr [ebp - 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 00a794c8  897df0                 -mov dword ptr [ebp - 0x10], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edi;
    // 00a794cb  3de8030000             +cmp eax, 0x3e8
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
    // 00a794d0  7c26                   -jl 0xa794f8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a794f8;
    }
    // 00a794d2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a794d4  bfe8030000             -mov edi, 0x3e8
    cpu.edi = 1000 /*0x3e8*/;
    // 00a794d9  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00a794dc  f7ff                   -idiv edi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.edi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00a794de  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 00a794e1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a794e3  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00a794e6  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a794e8  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00a794eb  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a794ed  8b55dc                 -mov edx, dword ptr [ebp - 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 00a794f0  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00a794f3  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00a794f5  8955dc                 -mov dword ptr [ebp - 0x24], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.edx;
L_0x00a794f8:
    // 00a794f8  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a794fb  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a794fe  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a79501  8a55f0                 -mov dl, byte ptr [ebp - 0x10]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a79504  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00a79506  80c230                 -add dl, 0x30
    (cpu.dl) += x86::reg8(x86::sreg8(48 /*0x30*/));
    // 00a79509  894df4                 -mov dword ptr [ebp - 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ecx;
    // 00a7950c  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
L_0x00a7950e:
    // 00a7950e  83fb03                 +cmp ebx, 3
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
    // 00a79511  7c49                   -jl 0xa7955c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a7955c;
    }
    // 00a79513  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00a79515  8b45dc                 -mov eax, dword ptr [ebp - 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 00a79518  897df0                 -mov dword ptr [ebp - 0x10], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edi;
    // 00a7951b  83f864                 +cmp eax, 0x64
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
    // 00a7951e  7c26                   -jl 0xa79546
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a79546;
    }
    // 00a79520  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a79522  bf64000000             -mov edi, 0x64
    cpu.edi = 100 /*0x64*/;
    // 00a79527  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00a7952a  f7ff                   -idiv edi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.edi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00a7952c  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 00a7952f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a79531  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00a79534  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a79536  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00a79539  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a7953b  8b55dc                 -mov edx, dword ptr [ebp - 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 00a7953e  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00a79541  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00a79543  8955dc                 -mov dword ptr [ebp - 0x24], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.edx;
L_0x00a79546:
    // 00a79546  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a79549  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a7954c  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a7954f  8a55f0                 -mov dl, byte ptr [ebp - 0x10]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a79552  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00a79554  80c230                 -add dl, 0x30
    (cpu.dl) += x86::reg8(x86::sreg8(48 /*0x30*/));
    // 00a79557  894df4                 -mov dword ptr [ebp - 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ecx;
    // 00a7955a  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
L_0x00a7955c:
    // 00a7955c  83fb02                 +cmp ebx, 2
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
    // 00a7955f  7c43                   -jl 0xa795a4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a795a4;
    }
    // 00a79561  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00a79563  8b45dc                 -mov eax, dword ptr [ebp - 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 00a79566  897df0                 -mov dword ptr [ebp - 0x10], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edi;
    // 00a79569  83f80a                 +cmp eax, 0xa
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
    // 00a7956c  7c20                   -jl 0xa7958e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a7958e;
    }
    // 00a7956e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a79570  bb0a000000             -mov ebx, 0xa
    cpu.ebx = 10 /*0xa*/;
    // 00a79575  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00a79578  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00a7957a  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 00a7957d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a7957f  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00a79582  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a79584  8b55dc                 -mov edx, dword ptr [ebp - 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 00a79587  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 00a79589  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00a7958b  8955dc                 -mov dword ptr [ebp - 0x24], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.edx;
L_0x00a7958e:
    // 00a7958e  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a79591  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a79594  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a79597  8a55f0                 -mov dl, byte ptr [ebp - 0x10]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a7959a  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a7959c  80c230                 -add dl, 0x30
    (cpu.dl) += x86::reg8(x86::sreg8(48 /*0x30*/));
    // 00a7959f  895df4                 -mov dword ptr [ebp - 0xc], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ebx;
    // 00a795a2  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
L_0x00a795a4:
    // 00a795a4  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a795a7  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a795aa  8d7001                 -lea esi, [eax + 1]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a795ad  8a55dc                 -mov dl, byte ptr [ebp - 0x24]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 00a795b0  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 00a795b2  80c230                 -add dl, 0x30
    (cpu.dl) += x86::reg8(x86::sreg8(48 /*0x30*/));
    // 00a795b5  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 00a795b7  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a795ba  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00a795bc  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00a795bf  29c2                   +sub edx, eax
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
    // 00a795c1  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a795c4  895024                 -mov dword ptr [eax + 0x24], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 00a795c7  8d0437                 -lea eax, [edi + esi]
    cpu.eax = x86::reg32(cpu.edi + cpu.esi * 1);
    // 00a795ca  8975f4                 -mov dword ptr [ebp - 0xc], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.esi;
    // 00a795cd  c60000                 -mov byte ptr [eax], 0
    app->getMemory<x86::reg8>(cpu.eax) = 0 /*0x0*/;
    // 00a795d0  e991fcffff             -jmp 0xa79266
    return sub_a79266(app, cpu);
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void sub_a795d5(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a795d5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a795d6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00a795d8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a795d9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a795da  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a795db  83ec34                 -sub esp, 0x34
    (cpu.esp) -= x86::reg32(x86::sreg32(52 /*0x34*/));
    // 00a795de  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00a795e0  895de8                 -mov dword ptr [ebp - 0x18], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.ebx;
    // 00a795e3  8945e0                 -mov dword ptr [ebp - 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.eax;
L_0x00a795e6:
    // 00a795e6  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a795e8  80fa20                 +cmp dl, 0x20
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
    // 00a795eb  740a                   -je 0xa795f7
    if (cpu.flags.zf)
    {
        goto L_0x00a795f7;
    }
    // 00a795ed  80fa09                 +cmp dl, 9
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
    // 00a795f0  7208                   -jb 0xa795fa
    if (cpu.flags.cf)
    {
        goto L_0x00a795fa;
    }
    // 00a795f2  80fa0d                 +cmp dl, 0xd
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
    // 00a795f5  7703                   -ja 0xa795fa
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a795fa;
    }
L_0x00a795f7:
    // 00a795f7  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a795f8  ebec                   -jmp 0xa795e6
    goto L_0x00a795e6;
L_0x00a795fa:
    // 00a795fa  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a795fd  30c9                   -xor cl, cl
    cpu.cl ^= x86::reg8(x86::sreg8(cpu.cl));
    // 00a795ff  80fa2b                 +cmp dl, 0x2b
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
    // 00a79602  7407                   -je 0xa7960b
    if (cpu.flags.zf)
    {
        goto L_0x00a7960b;
    }
    // 00a79604  80fa2d                 +cmp dl, 0x2d
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
    // 00a79607  7504                   -jne 0xa7960d
    if (!cpu.flags.zf)
    {
        goto L_0x00a7960d;
    }
    // 00a79609  b101                   -mov cl, 1
    cpu.cl = 1 /*0x1*/;
L_0x00a7960b:
    // 00a7960b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x00a7960d:
    // 00a7960d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a7960f  b630                   -mov dh, 0x30
    cpu.dh = 48 /*0x30*/;
    // 00a79611  895de4                 -mov dword ptr [ebp - 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.ebx;
L_0x00a79614:
    // 00a79614  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a79616  40                     -inc eax
    (cpu.eax)++;
    // 00a79617  80fa2e                 +cmp dl, 0x2e
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
    // 00a7961a  750a                   -jne 0xa79626
    if (!cpu.flags.zf)
    {
        goto L_0x00a79626;
    }
    // 00a7961c  f6c108                 +test cl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 8 /*0x8*/));
    // 00a7961f  752d                   -jne 0xa7964e
    if (!cpu.flags.zf)
    {
        goto L_0x00a7964e;
    }
    // 00a79621  80c908                 +or cl, 8
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(8 /*0x8*/))));
    // 00a79624  ebee                   -jmp 0xa79614
    goto L_0x00a79614;
L_0x00a79626:
    // 00a79626  80fa30                 +cmp dl, 0x30
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
    // 00a79629  7223                   -jb 0xa7964e
    if (cpu.flags.cf)
    {
        goto L_0x00a7964e;
    }
    // 00a7962b  80fa39                 +cmp dl, 0x39
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
    // 00a7962e  771e                   -ja 0xa7964e
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a7964e;
    }
    // 00a79630  f6c108                 +test cl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 8 /*0x8*/));
    // 00a79633  7403                   -je 0xa79638
    if (cpu.flags.zf)
    {
        goto L_0x00a79638;
    }
    // 00a79635  ff45e4                 -inc dword ptr [ebp - 0x1c]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */))++;
L_0x00a79638:
    // 00a79638  08d6                   -or dh, dl
    cpu.dh |= x86::reg8(x86::sreg8(cpu.dl));
    // 00a7963a  80fe30                 +cmp dh, 0x30
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
    // 00a7963d  740a                   -je 0xa79649
    if (cpu.flags.zf)
    {
        goto L_0x00a79649;
    }
    // 00a7963f  83fb13                 +cmp ebx, 0x13
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
    // 00a79642  7d04                   -jge 0xa79648
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a79648;
    }
    // 00a79644  88542bc0               -mov byte ptr [ebx + ebp - 0x40], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-64) /* -0x40 */ + cpu.ebp * 1) = cpu.dl;
L_0x00a79648:
    // 00a79648  43                     -inc ebx
    (cpu.ebx)++;
L_0x00a79649:
    // 00a79649  80c904                 +or cl, 4
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(4 /*0x4*/))));
    // 00a7964c  ebc6                   -jmp 0xa79614
    goto L_0x00a79614;
L_0x00a7964e:
    // 00a7964e  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00a79650  f6c104                 +test cl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 4 /*0x4*/));
    // 00a79653  0f8465000000           -je 0xa796be
    if (cpu.flags.zf)
    {
        goto L_0x00a796be;
    }
    // 00a79659  80fa65                 +cmp dl, 0x65
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
    // 00a7965c  7405                   -je 0xa79663
    if (cpu.flags.zf)
    {
        goto L_0x00a79663;
    }
    // 00a7965e  80fa45                 +cmp dl, 0x45
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
    // 00a79661  7557                   -jne 0xa796ba
    if (!cpu.flags.zf)
    {
        goto L_0x00a796ba;
    }
L_0x00a79663:
    // 00a79663  8d50ff                 -lea edx, [eax - 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 00a79666  8a28                   -mov ch, byte ptr [eax]
    cpu.ch = app->getMemory<x86::reg8>(cpu.eax);
    // 00a79668  8955f0                 -mov dword ptr [ebp - 0x10], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edx;
    // 00a7966b  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a7966e  80fd2b                 +cmp ch, 0x2b
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
    // 00a79671  7408                   -je 0xa7967b
    if (cpu.flags.zf)
    {
        goto L_0x00a7967b;
    }
    // 00a79673  80fd2d                 +cmp ch, 0x2d
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
    // 00a79676  7505                   -jne 0xa7967d
    if (!cpu.flags.zf)
    {
        goto L_0x00a7967d;
    }
    // 00a79678  80c902                 -or cl, 2
    cpu.cl |= x86::reg8(x86::sreg8(2 /*0x2*/));
L_0x00a7967b:
    // 00a7967b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x00a7967d:
    // 00a7967d  80e1fb                 -and cl, 0xfb
    cpu.cl &= x86::reg8(x86::sreg8(251 /*0xfb*/));
L_0x00a79680:
    // 00a79680  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a79682  80fa30                 +cmp dl, 0x30
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
    // 00a79685  7222                   -jb 0xa796a9
    if (cpu.flags.cf)
    {
        goto L_0x00a796a9;
    }
    // 00a79687  80fa39                 +cmp dl, 0x39
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
    // 00a7968a  771d                   -ja 0xa796a9
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a796a9;
    }
    // 00a7968c  81fee8030000           +cmp esi, 0x3e8
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
    // 00a79692  7d0f                   -jge 0xa796a3
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a796a3;
    }
    // 00a79694  6bf60a                 -imul esi, esi, 0xa
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(10 /*0xa*/)));
    // 00a79697  8975ec                 -mov dword ptr [ebp - 0x14], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.esi;
    // 00a7969a  0fb6f2                 -movzx esi, dl
    cpu.esi = x86::reg32(cpu.dl);
    // 00a7969d  0375ec                 -add esi, dword ptr [ebp - 0x14]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */)));
    // 00a796a0  83ee30                 -sub esi, 0x30
    (cpu.esi) -= x86::reg32(x86::sreg32(48 /*0x30*/));
L_0x00a796a3:
    // 00a796a3  80c904                 +or cl, 4
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(4 /*0x4*/))));
    // 00a796a6  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a796a7  ebd7                   -jmp 0xa79680
    goto L_0x00a79680;
L_0x00a796a9:
    // 00a796a9  f6c102                 +test cl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 2 /*0x2*/));
    // 00a796ac  7402                   -je 0xa796b0
    if (cpu.flags.zf)
    {
        goto L_0x00a796b0;
    }
    // 00a796ae  f7de                   -neg esi
    cpu.esi = ~cpu.esi + 1;
L_0x00a796b0:
    // 00a796b0  f6c104                 +test cl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 4 /*0x4*/));
    // 00a796b3  7506                   -jne 0xa796bb
    if (!cpu.flags.zf)
    {
        goto L_0x00a796bb;
    }
    // 00a796b5  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a796b8  eb01                   -jmp 0xa796bb
    goto L_0x00a796bb;
L_0x00a796ba:
    // 00a796ba  48                     -dec eax
    (cpu.eax)--;
L_0x00a796bb:
    // 00a796bb  8945e0                 -mov dword ptr [ebp - 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.eax;
L_0x00a796be:
    // 00a796be  837de800               +cmp dword ptr [ebp - 0x18], 0
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
    // 00a796c2  7408                   -je 0xa796cc
    if (cpu.flags.zf)
    {
        goto L_0x00a796cc;
    }
    // 00a796c4  8b55e8                 -mov edx, dword ptr [ebp - 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a796c7  8b45e0                 -mov eax, dword ptr [ebp - 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00a796ca  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
L_0x00a796cc:
    // 00a796cc  2b75e4                 -sub esi, dword ptr [ebp - 0x1c]
    (cpu.esi) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */)));
    // 00a796cf  83fb13                 +cmp ebx, 0x13
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
    // 00a796d2  7e0a                   -jle 0xa796de
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a796de;
    }
    // 00a796d4  83eb13                 -sub ebx, 0x13
    (cpu.ebx) -= x86::reg32(x86::sreg32(19 /*0x13*/));
    // 00a796d7  01de                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00a796d9  bb13000000             -mov ebx, 0x13
    cpu.ebx = 19 /*0x13*/;
L_0x00a796de:
    // 00a796de  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a796e0  7e0b                   -jle 0xa796ed
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a796ed;
    }
    // 00a796e2  807c2bbf30             +cmp byte ptr [ebx + ebp - 0x41], 0x30
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
    // 00a796e7  7504                   -jne 0xa796ed
    if (!cpu.flags.zf)
    {
        goto L_0x00a796ed;
    }
    // 00a796e9  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a796ea  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a796eb  ebf1                   -jmp 0xa796de
    goto L_0x00a796de;
L_0x00a796ed:
    // 00a796ed  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a796ef  7511                   -jne 0xa79702
    if (!cpu.flags.zf)
    {
        goto L_0x00a79702;
    }
    // 00a796f1  66c747080000           -mov word ptr [edi + 8], 0
    app->getMemory<x86::reg16>(cpu.edi + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 00a796f7  895f04                 -mov dword ptr [edi + 4], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00a796fa  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a796fc  891f                   -mov dword ptr [edi], ebx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.ebx;
    // 00a796fe  31f8                   +xor eax, edi
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 00a79700  eb5f                   -jmp 0xa79761
    goto L_0x00a79761;
L_0x00a79702:
    // 00a79702  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 00a79704  8d45c0                 -lea eax, [ebp - 0x40]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-64) /* -0x40 */);
    // 00a79707  88542bc0               -mov byte ptr [ebx + ebp - 0x40], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-64) /* -0x40 */ + cpu.ebp * 1) = cpu.dl;
    // 00a7970b  8d55d4                 -lea edx, [ebp - 0x2c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 00a7970e  e8e9110000             -call 0xa7a8fc
    cpu.esp -= 4;
    sub_a7a8fc(app, cpu);
    if (cpu.terminate) return;
    // 00a79713  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a79715  740a                   -je 0xa79721
    if (cpu.flags.zf)
    {
        goto L_0x00a79721;
    }
    // 00a79717  8d45d4                 -lea eax, [ebp - 0x2c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 00a7971a  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00a7971c  e8a4f4ffff             -call 0xa78bc5
    cpu.esp -= 4;
    sub_a78bc5(app, cpu);
    if (cpu.terminate) return;
L_0x00a79721:
    // 00a79721  f6c101                 +test cl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 1 /*0x1*/));
    // 00a79724  7404                   -je 0xa7972a
    if (cpu.flags.zf)
    {
        goto L_0x00a7972a;
    }
    // 00a79726  804ddd80               -or byte ptr [ebp - 0x23], 0x80
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-35) /* -0x23 */) |= x86::reg8(x86::sreg8(128 /*0x80*/));
L_0x00a7972a:
    // 00a7972a  8b45dc                 -mov eax, dword ptr [ebp - 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 00a7972d  66894708               -mov word ptr [edi + 8], ax
    app->getMemory<x86::reg16>(cpu.edi + x86::reg32(8) /* 0x8 */) = cpu.ax;
    // 00a79731  8b45d8                 -mov eax, dword ptr [ebp - 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 00a79734  894704                 -mov dword ptr [edi + 4], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00a79737  8b45d4                 -mov eax, dword ptr [ebp - 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 00a7973a  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 00a7973c  8d441eff               -lea eax, [esi + ebx - 1]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(-1) /* -0x1 */ + cpu.ebx * 1);
    // 00a79740  3d34010000             +cmp eax, 0x134
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
    // 00a79745  7e07                   -jle 0xa7974e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a7974e;
    }
    // 00a79747  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 00a7974c  eb13                   -jmp 0xa79761
    goto L_0x00a79761;
L_0x00a7974e:
    // 00a7974e  3dccfeffff             +cmp eax, 0xfffffecc
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
    // 00a79753  7d07                   -jge 0xa7975c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a7975c;
    }
    // 00a79755  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00a7975a  eb05                   -jmp 0xa79761
    goto L_0x00a79761;
L_0x00a7975c:
    // 00a7975c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00a79761:
    // 00a79761  8d65f4                 -lea esp, [ebp - 0xc]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a79764  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79765  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79766  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79767  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79768  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a79769(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a79769  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a7976a  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00a7976c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a7976d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a7976e  83ec24                 -sub esp, 0x24
    (cpu.esp) -= x86::reg32(x86::sreg32(36 /*0x24*/));
    // 00a79771  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00a79773  8d55d4                 -lea edx, [ebp - 0x2c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 00a79776  e85afeffff             -call 0xa795d5
    cpu.esp -= 4;
    sub_a795d5(app, cpu);
    if (cpu.terminate) return;
    // 00a7977b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a7977d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a7977f  750b                   -jne 0xa7978c
    if (!cpu.flags.zf)
    {
        goto L_0x00a7978c;
    }
    // 00a79781  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
L_0x00a79784:
    // 00a79784  8945ec                 -mov dword ptr [ebp - 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
    // 00a79787  e9ad000000             -jmp 0xa79839
    goto L_0x00a79839;
L_0x00a7978c:
    // 00a7978c  8b45dc                 -mov eax, dword ptr [ebp - 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 00a7978f  80e47f                 -and ah, 0x7f
    cpu.ah &= x86::reg8(x86::sreg8(127 /*0x7f*/));
    // 00a79792  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00a79797  3dff430000             +cmp eax, 0x43ff
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
    // 00a7979c  7c2a                   -jl 0xa797c8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a797c8;
    }
    // 00a7979e  e841ccffff             -call 0xa763e4
    cpu.esp -= 4;
    sub_a763e4(app, cpu);
    if (cpu.terminate) return;
    // 00a797a3  f645dd80               +test byte ptr [ebp - 0x23], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-35) /* -0x23 */) & 128 /*0x80*/));
    // 00a797a7  7410                   -je 0xa797b9
    if (cpu.flags.zf)
    {
        goto L_0x00a797b9;
    }
    // 00a797a9  dd0528e4a700           +fld qword ptr [0xa7e428]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(11002920) /* 0xa7e428 */)));
    // 00a797af  d9e0                   +fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 00a797b1  dd5de8                 +fstp qword ptr [ebp - 0x18]
    app->getMemory<double>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a797b4  e980000000             -jmp 0xa79839
    goto L_0x00a79839;
L_0x00a797b9:
    // 00a797b9  a128e4a700             -mov eax, dword ptr [0xa7e428]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11002920) /* 0xa7e428 */);
    // 00a797be  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
    // 00a797c1  a12ce4a700             -mov eax, dword ptr [0xa7e42c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11002924) /* 0xa7e42c */);
    // 00a797c6  ebbc                   -jmp 0xa79784
    goto L_0x00a79784;
L_0x00a797c8:
    // 00a797c8  3dcd3b0000             +cmp eax, 0x3bcd
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
    // 00a797cd  7d42                   -jge 0xa79811
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a79811;
    }
    // 00a797cf  83f8cc                 +cmp eax, -0x34
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
    // 00a797d2  7d0f                   -jge 0xa797e3
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a797e3;
    }
    // 00a797d4  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00a797d6  e809ccffff             -call 0xa763e4
    cpu.esp -= 4;
    sub_a763e4(app, cpu);
    if (cpu.terminate) return;
    // 00a797db  894de8                 -mov dword ptr [ebp - 0x18], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.ecx;
    // 00a797de  894dec                 -mov dword ptr [ebp - 0x14], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ecx;
    // 00a797e1  eb56                   -jmp 0xa79839
    goto L_0x00a79839;
L_0x00a797e3:
    // 00a797e3  8d55e8                 -lea edx, [ebp - 0x18]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a797e6  8d45d4                 -lea eax, [ebp - 0x2c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 00a797e9  db28                   -fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 00a797eb  dd1a                   -fstp qword ptr [edx]
    app->getMemory<double>(cpu.edx) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a797ed  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a797f0  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 00a797f3  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00a797f6  8b5de8                 -mov ebx, dword ptr [ebp - 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a797f9  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 00a797fc  a9ffffff7f             +test eax, 0x7fffffff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2147483647 /*0x7fffffff*/));
    // 00a79801  7504                   -jne 0xa79807
    if (!cpu.flags.zf)
    {
        goto L_0x00a79807;
    }
    // 00a79803  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a79805  742d                   -je 0xa79834
    if (cpu.flags.zf)
    {
        goto L_0x00a79834;
    }
L_0x00a79807:
    // 00a79807  66f745f6f07f           +test word ptr [ebp - 0xa], 0x7ff0
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-10) /* -0xa */) & 32752 /*0x7ff0*/));
    // 00a7980d  752a                   -jne 0xa79839
    if (!cpu.flags.zf)
    {
        goto L_0x00a79839;
    }
    // 00a7980f  eb23                   -jmp 0xa79834
    goto L_0x00a79834;
L_0x00a79811:
    // 00a79811  8d55e8                 -lea edx, [ebp - 0x18]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a79814  8d45d4                 -lea eax, [ebp - 0x2c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 00a79817  db28                   -fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 00a79819  dd1a                   -fstp qword ptr [edx]
    app->getMemory<double>(cpu.edx) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a7981b  83fb03                 +cmp ebx, 3
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
    // 00a7981e  7414                   -je 0xa79834
    if (cpu.flags.zf)
    {
        goto L_0x00a79834;
    }
    // 00a79820  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a79823  8945e0                 -mov dword ptr [ebp - 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.eax;
    // 00a79826  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00a79829  8945e4                 -mov dword ptr [ebp - 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.eax;
    // 00a7982c  66f745e6f07f           +test word ptr [ebp - 0x1a], 0x7ff0
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-26) /* -0x1a */) & 32752 /*0x7ff0*/));
    // 00a79832  7505                   -jne 0xa79839
    if (!cpu.flags.zf)
    {
        goto L_0x00a79839;
    }
L_0x00a79834:
    // 00a79834  e8abcbffff             -call 0xa763e4
    cpu.esp -= 4;
    sub_a763e4(app, cpu);
    if (cpu.terminate) return;
L_0x00a79839:
    // 00a79839  dd45e8                 -fld qword ptr [ebp - 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-24) /* -0x18 */)));
    // 00a7983c  8d65f8                 -lea esp, [ebp - 8]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00a7983f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79840  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79841  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79842  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a79850(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a79850  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a79851  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a79852  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a79854  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a79856  740f                   -je 0xa79867
    if (cpu.flags.zf)
    {
        goto L_0x00a79867;
    }
L_0x00a79858:
    // 00a79858  803a00                 +cmp byte ptr [edx], 0
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
    // 00a7985b  740a                   -je 0xa79867
    if (cpu.flags.zf)
    {
        goto L_0x00a79867;
    }
    // 00a7985d  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a7985e  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 00a79860  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a79861  8848ff                 -mov byte ptr [eax - 1], cl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-1) /* -0x1 */) = cpu.cl;
    // 00a79864  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a79865  75f1                   -jne 0xa79858
    if (!cpu.flags.zf)
    {
        goto L_0x00a79858;
    }
L_0x00a79867:
    // 00a79867  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00a79869:
    // 00a79869  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a7986b  7407                   -je 0xa79874
    if (cpu.flags.zf)
    {
        goto L_0x00a79874;
    }
    // 00a7986d  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a7986e  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a7986f  8850ff                 -mov byte ptr [eax - 1], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-1) /* -0x1 */) = cpu.dl;
    // 00a79872  ebf5                   -jmp 0xa79869
    goto L_0x00a79869;
L_0x00a79874:
    // 00a79874  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a79876  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79877  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79878  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a79880(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a79880  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a79881  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a79882  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a79883  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a79886  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00a7988a  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00a7988e  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00a79890  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 00a79894  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a79896  7402                   -je 0xa7989a
    if (cpu.flags.zf)
    {
        goto L_0x00a7989a;
    }
    // 00a79898  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
L_0x00a7989a:
    // 00a7989a  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
L_0x00a7989e:
    // 00a7989e  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 00a798a0  fec0                   -inc al
    (cpu.al)++;
    // 00a798a2  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a798a7  f6808cd1a70002         +test byte ptr [eax + 0xa7d18c], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(10998156) /* 0xa7d18c */) & 2 /*0x2*/));
    // 00a798ae  7403                   -je 0xa798b3
    if (cpu.flags.zf)
    {
        goto L_0x00a798b3;
    }
    // 00a798b0  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a798b1  ebeb                   -jmp 0xa7989e
    goto L_0x00a7989e;
L_0x00a798b3:
    // 00a798b3  8a2a                   -mov ch, byte ptr [edx]
    cpu.ch = app->getMemory<x86::reg8>(cpu.edx);
    // 00a798b5  80fd2b                 +cmp ch, 0x2b
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
    // 00a798b8  7405                   -je 0xa798bf
    if (cpu.flags.zf)
    {
        goto L_0x00a798bf;
    }
    // 00a798ba  80fd2d                 +cmp ch, 0x2d
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
    // 00a798bd  7501                   -jne 0xa798c0
    if (!cpu.flags.zf)
    {
        goto L_0x00a798c0;
    }
L_0x00a798bf:
    // 00a798bf  42                     -inc edx
    (cpu.edx)++;
L_0x00a798c0:
    // 00a798c0  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a798c2  752c                   -jne 0xa798f0
    if (!cpu.flags.zf)
    {
        goto L_0x00a798f0;
    }
    // 00a798c4  803a30                 +cmp byte ptr [edx], 0x30
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
    // 00a798c7  7514                   -jne 0xa798dd
    if (!cpu.flags.zf)
    {
        goto L_0x00a798dd;
    }
    // 00a798c9  8a4a01                 -mov cl, byte ptr [edx + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00a798cc  80f978                 +cmp cl, 0x78
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
    // 00a798cf  7405                   -je 0xa798d6
    if (cpu.flags.zf)
    {
        goto L_0x00a798d6;
    }
    // 00a798d1  80f958                 +cmp cl, 0x58
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
    // 00a798d4  7507                   -jne 0xa798dd
    if (!cpu.flags.zf)
    {
        goto L_0x00a798dd;
    }
L_0x00a798d6:
    // 00a798d6  be10000000             -mov esi, 0x10
    cpu.esi = 16 /*0x10*/;
    // 00a798db  eb33                   -jmp 0xa79910
    goto L_0x00a79910;
L_0x00a798dd:
    // 00a798dd  803a30                 +cmp byte ptr [edx], 0x30
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
    // 00a798e0  7507                   -jne 0xa798e9
    if (!cpu.flags.zf)
    {
        goto L_0x00a798e9;
    }
    // 00a798e2  be08000000             -mov esi, 8
    cpu.esi = 8 /*0x8*/;
    // 00a798e7  eb3c                   -jmp 0xa79925
    goto L_0x00a79925;
L_0x00a798e9:
    // 00a798e9  be0a000000             -mov esi, 0xa
    cpu.esi = 10 /*0xa*/;
    // 00a798ee  eb35                   -jmp 0xa79925
    goto L_0x00a79925;
L_0x00a798f0:
    // 00a798f0  83fe02                 +cmp esi, 2
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
    // 00a798f3  7c05                   -jl 0xa798fa
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a798fa;
    }
    // 00a798f5  83fe24                 +cmp esi, 0x24
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
    // 00a798f8  7e11                   -jle 0xa7990b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a7990b;
    }
L_0x00a798fa:
    // 00a798fa  b80d000000             -mov eax, 0xd
    cpu.eax = 13 /*0xd*/;
    // 00a798ff  e8bccaffff             -call 0xa763c0
    cpu.esp -= 4;
    sub_a763c0(app, cpu);
    if (cpu.terminate) return;
    // 00a79904  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a79906  e9c1000000             -jmp 0xa799cc
    goto L_0x00a799cc;
L_0x00a7990b:
    // 00a7990b  83fe10                 +cmp esi, 0x10
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
    // 00a7990e  7515                   -jne 0xa79925
    if (!cpu.flags.zf)
    {
        goto L_0x00a79925;
    }
L_0x00a79910:
    // 00a79910  803a30                 +cmp byte ptr [edx], 0x30
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
    // 00a79913  7510                   -jne 0xa79925
    if (!cpu.flags.zf)
    {
        goto L_0x00a79925;
    }
    // 00a79915  8a7a01                 -mov bh, byte ptr [edx + 1]
    cpu.bh = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00a79918  80ff78                 +cmp bh, 0x78
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
    // 00a7991b  7405                   -je 0xa79922
    if (cpu.flags.zf)
    {
        goto L_0x00a79922;
    }
    // 00a7991d  80ff58                 +cmp bh, 0x58
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
    // 00a79920  7503                   -jne 0xa79925
    if (!cpu.flags.zf)
    {
        goto L_0x00a79925;
    }
L_0x00a79922:
    // 00a79922  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x00a79925:
    // 00a79925  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00a79928  8d2cb500000000         -lea ebp, [esi*4]
    cpu.ebp = x86::reg32(cpu.esi * 4);
    // 00a7992f  30c9                   -xor cl, cl
    cpu.cl ^= x86::reg8(x86::sreg8(cpu.cl));
    // 00a79931  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00a79933:
    // 00a79933  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a79935  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 00a79937  e8b4000000             -call 0xa799f0
    cpu.esp -= 4;
    sub_a799f0(app, cpu);
    if (cpu.terminate) return;
    // 00a7993c  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a7993e  39f0                   +cmp eax, esi
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
    // 00a79940  7d1a                   -jge 0xa7995c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a7995c;
    }
    // 00a79942  3b9ddcd6a700           +cmp ebx, dword ptr [ebp + 0xa7d6dc]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(10999516) /* 0xa7d6dc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a79948  7602                   -jbe 0xa7994c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a7994c;
    }
    // 00a7994a  b101                   -mov cl, 1
    cpu.cl = 1 /*0x1*/;
L_0x00a7994c:
    // 00a7994c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a7994e  0fafde                 -imul ebx, esi
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 00a79951  01fb                   -add ebx, edi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00a79953  39c3                   +cmp ebx, eax
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
    // 00a79955  7302                   -jae 0xa79959
    if (!cpu.flags.cf)
    {
        goto L_0x00a79959;
    }
    // 00a79957  b101                   -mov cl, 1
    cpu.cl = 1 /*0x1*/;
L_0x00a79959:
    // 00a79959  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a7995a  ebd7                   -jmp 0xa79933
    goto L_0x00a79933;
L_0x00a7995c:
    // 00a7995c  3b1424                 +cmp edx, dword ptr [esp]
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
    // 00a7995f  7504                   -jne 0xa79965
    if (!cpu.flags.zf)
    {
        goto L_0x00a79965;
    }
    // 00a79961  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
L_0x00a79965:
    // 00a79965  8b7c2404               -mov edi, dword ptr [esp + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a79969  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a7996b  7402                   -je 0xa7996f
    if (cpu.flags.zf)
    {
        goto L_0x00a7996f;
    }
    // 00a7996d  8917                   -mov dword ptr [edi], edx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.edx;
L_0x00a7996f:
    // 00a7996f  837c240801             +cmp dword ptr [esp + 8], 1
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
    // 00a79974  750f                   -jne 0xa79985
    if (!cpu.flags.zf)
    {
        goto L_0x00a79985;
    }
    // 00a79976  81fb00000080           +cmp ebx, 0x80000000
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
    // 00a7997c  7207                   -jb 0xa79985
    if (cpu.flags.cf)
    {
        goto L_0x00a79985;
    }
    // 00a7997e  7509                   -jne 0xa79989
    if (!cpu.flags.zf)
    {
        goto L_0x00a79989;
    }
    // 00a79980  80fd2d                 +cmp ch, 0x2d
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
    // 00a79983  7504                   -jne 0xa79989
    if (!cpu.flags.zf)
    {
        goto L_0x00a79989;
    }
L_0x00a79985:
    // 00a79985  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 00a79987  743a                   -je 0xa799c3
    if (cpu.flags.zf)
    {
        goto L_0x00a799c3;
    }
L_0x00a79989:
    // 00a79989  b80e000000             -mov eax, 0xe
    cpu.eax = 14 /*0xe*/;
    // 00a7998e  e82dcaffff             -call 0xa763c0
    cpu.esp -= 4;
    sub_a763c0(app, cpu);
    if (cpu.terminate) return;
    // 00a79993  837c240800             +cmp dword ptr [esp + 8], 0
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
    // 00a79998  750c                   -jne 0xa799a6
    if (!cpu.flags.zf)
    {
        goto L_0x00a799a6;
    }
    // 00a7999a  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a7999f  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a799a2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a799a3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a799a4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a799a5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a799a6:
    // 00a799a6  80fd2d                 +cmp ch, 0x2d
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
    // 00a799a9  750c                   -jne 0xa799b7
    if (!cpu.flags.zf)
    {
        goto L_0x00a799b7;
    }
    // 00a799ab  b800000080             -mov eax, 0x80000000
    cpu.eax = 2147483648 /*0x80000000*/;
    // 00a799b0  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a799b3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a799b4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a799b5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a799b6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a799b7:
    // 00a799b7  b8ffffff7f             -mov eax, 0x7fffffff
    cpu.eax = 2147483647 /*0x7fffffff*/;
    // 00a799bc  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a799bf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a799c0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a799c1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a799c2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a799c3:
    // 00a799c3  80fd2d                 +cmp ch, 0x2d
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
    // 00a799c6  7502                   -jne 0xa799ca
    if (!cpu.flags.zf)
    {
        goto L_0x00a799ca;
    }
    // 00a799c8  f7db                   -neg ebx
    cpu.ebx = ~cpu.ebx + 1;
L_0x00a799ca:
    // 00a799ca  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x00a799cc:
    // 00a799cc  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a799cf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a799d0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a799d1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a799d2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a799d4(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a799d4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a799d5  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a799d7  e8a4feffff             -call 0xa79880
    cpu.esp -= 4;
    sub_a79880(app, cpu);
    if (cpu.terminate) return;
    // 00a799dc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a799dd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a799e0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a799e0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a799e1  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00a799e6  e895feffff             -call 0xa79880
    cpu.esp -= 4;
    sub_a79880(app, cpu);
    if (cpu.terminate) return;
    // 00a799eb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a799ec  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a799f0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a799f0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a799f1  3c30                   +cmp al, 0x30
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
    // 00a799f3  720e                   -jb 0xa79a03
    if (cpu.flags.cf)
    {
        goto L_0x00a79a03;
    }
    // 00a799f5  3c39                   +cmp al, 0x39
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
    // 00a799f7  770a                   -ja 0xa79a03
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a79a03;
    }
    // 00a799f9  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a799fe  83e830                 -sub eax, 0x30
    (cpu.eax) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 00a79a01  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79a02  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a79a03:
    // 00a79a03  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a79a08  e8930f0000             -call 0xa7a9a0
    cpu.esp -= 4;
    sub_a7a9a0(app, cpu);
    if (cpu.terminate) return;
    // 00a79a0d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a79a0f  3c61                   +cmp al, 0x61
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
    // 00a79a11  720d                   -jb 0xa79a20
    if (cpu.flags.cf)
    {
        goto L_0x00a79a20;
    }
    // 00a79a13  3c69                   +cmp al, 0x69
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
    // 00a79a15  7709                   -ja 0xa79a20
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a79a20;
    }
    // 00a79a17  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a79a19  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 00a79a1b  83e857                 -sub eax, 0x57
    (cpu.eax) -= x86::reg32(x86::sreg32(87 /*0x57*/));
    // 00a79a1e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79a1f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a79a20:
    // 00a79a20  3c6a                   +cmp al, 0x6a
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
    // 00a79a22  720e                   -jb 0xa79a32
    if (cpu.flags.cf)
    {
        goto L_0x00a79a32;
    }
    // 00a79a24  3c72                   +cmp al, 0x72
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
    // 00a79a26  770a                   -ja 0xa79a32
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a79a32;
    }
    // 00a79a28  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a79a2d  83e857                 -sub eax, 0x57
    (cpu.eax) -= x86::reg32(x86::sreg32(87 /*0x57*/));
    // 00a79a30  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79a31  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a79a32:
    // 00a79a32  3c73                   +cmp al, 0x73
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
    // 00a79a34  720e                   -jb 0xa79a44
    if (cpu.flags.cf)
    {
        goto L_0x00a79a44;
    }
    // 00a79a36  3c7a                   +cmp al, 0x7a
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
    // 00a79a38  770a                   -ja 0xa79a44
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a79a44;
    }
    // 00a79a3a  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a79a3f  83e857                 -sub eax, 0x57
    (cpu.eax) -= x86::reg32(x86::sreg32(87 /*0x57*/));
    // 00a79a42  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79a43  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a79a44:
    // 00a79a44  b825000000             -mov eax, 0x25
    cpu.eax = 37 /*0x25*/;
    // 00a79a49  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79a4a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void sub_a79a50(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a79a50  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a79a51  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a79a52  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a79a53  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a79a54  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a79a55  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a79a56  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00a79a59  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a79a5b  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00a79a60  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00a79a65  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00a79a68  ba3d000000             -mov edx, 0x3d
    cpu.edx = 61 /*0x3d*/;
    // 00a79a6d  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00a79a71  e83a0f0000             -call 0xa7a9b0
    cpu.esp -= 4;
    sub_a7a9b0(app, cpu);
    if (cpu.terminate) return;
    // 00a79a76  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a79a78  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a79a7a  750a                   -jne 0xa79a86
    if (!cpu.flags.zf)
    {
        goto L_0x00a79a86;
    }
    // 00a79a7c  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a79a81  e97c010000             -jmp 0xa79c02
    goto L_0x00a79c02;
L_0x00a79a86:
    // 00a79a86  39e8                   +cmp eax, ebp
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
    // 00a79a88  750f                   -jne 0xa79a99
    if (!cpu.flags.zf)
    {
        goto L_0x00a79a99;
    }
    // 00a79a8a  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a79a8f  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00a79a92  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79a93  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79a94  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79a95  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79a96  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79a97  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79a98  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a79a99:
    // 00a79a99  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00a79a9b  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00a79a9f  40                     -inc eax
    (cpu.eax)++;
    // 00a79aa0  e8dba1ffff             -call 0xa73c80
    cpu.esp -= 4;
    sub_a73c80(app, cpu);
    if (cpu.terminate) return;
    // 00a79aa5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a79aa7  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a79aab  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a79aad  750f                   -jne 0xa79abe
    if (!cpu.flags.zf)
    {
        goto L_0x00a79abe;
    }
    // 00a79aaf  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a79ab4  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00a79ab7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79ab8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79ab9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79aba  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79abb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79abc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79abd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a79abe:
    // 00a79abe  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00a79ac2  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
    // 00a79ac4  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a79ac6  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a79ac7  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a79ac9  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a79acb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a79acc  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a79ace  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a79ad1  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a79ad3  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a79ad5  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a79ad8  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a79ada  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79adb  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a79adc  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00a79ae0  8d7301                 -lea esi, [ebx + 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 00a79ae3  c6040200               -mov byte ptr [edx + eax], 0
    app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1) = 0 /*0x0*/;
    // 00a79ae7  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a79ae9  e8220f0000             -call 0xa7aa10
    cpu.esp -= 4;
    sub_a7aa10(app, cpu);
    if (cpu.terminate) return;
    // 00a79aee  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00a79af2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a79af4  744b                   -je 0xa79b41
    if (cpu.flags.zf)
    {
        goto L_0x00a79b41;
    }
    // 00a79af6  40                     -inc eax
    (cpu.eax)++;
    // 00a79af7  e884a1ffff             -call 0xa73c80
    cpu.esp -= 4;
    sub_a73c80(app, cpu);
    if (cpu.terminate) return;
    // 00a79afc  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a79afe  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00a79b02  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a79b04  7516                   -jne 0xa79b1c
    if (!cpu.flags.zf)
    {
        goto L_0x00a79b1c;
    }
    // 00a79b06  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a79b08  e863a2ffff             -call 0xa73d70
    cpu.esp -= 4;
    sub_a73d70(app, cpu);
    if (cpu.terminate) return;
    // 00a79b0d  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a79b12  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00a79b15  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79b16  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79b17  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79b18  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79b19  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79b1a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79b1b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a79b1c:
    // 00a79b1c  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00a79b20  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a79b22  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a79b23  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a79b25  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a79b27  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a79b28  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a79b2a  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a79b2d  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a79b2f  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a79b31  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a79b34  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a79b36  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79b37  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a79b38  035c2414               +add ebx, dword ptr [esp + 0x14]
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
    // 00a79b3c  c60300                 -mov byte ptr [ebx], 0
    app->getMemory<x86::reg8>(cpu.ebx) = 0 /*0x0*/;
    // 00a79b3f  eb04                   -jmp 0xa79b45
    goto L_0x00a79b45;
L_0x00a79b41:
    // 00a79b41  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x00a79b45:
    // 00a79b45  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a79b49  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a79b4a  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a79b4e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a79b4f  2eff1524bea700         -call dword ptr cs:[0xa7be24]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993188) /* 0xa7be24 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a79b56  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a79b58  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a79b5c  e80fa2ffff             -call 0xa73d70
    cpu.esp -= 4;
    sub_a73d70(app, cpu);
    if (cpu.terminate) return;
    // 00a79b61  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a79b65  e806a2ffff             -call 0xa73d70
    cpu.esp -= 4;
    sub_a73d70(app, cpu);
    if (cpu.terminate) return;
    // 00a79b6a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a79b6c  750f                   -jne 0xa79b7d
    if (!cpu.flags.zf)
    {
        goto L_0x00a79b7d;
    }
    // 00a79b6e  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a79b73  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00a79b76  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79b77  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79b78  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79b79  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79b7a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79b7b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79b7c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a79b7d:
    // 00a79b7d  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a79b7f  e888000000             -call 0xa79c0c
    cpu.esp -= 4;
    sub_a79c0c(app, cpu);
    if (cpu.terminate) return;
    // 00a79b84  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a79b86  740f                   -je 0xa79b97
    if (cpu.flags.zf)
    {
        goto L_0x00a79b97;
    }
    // 00a79b88  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a79b8d  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00a79b90  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79b91  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79b92  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79b93  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79b94  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79b95  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79b96  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a79b97:
    // 00a79b97  833d0800a80000         +cmp dword ptr [0xa80008], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11010056) /* 0xa80008 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a79b9e  7462                   -je 0xa79c02
    if (cpu.flags.zf)
    {
        goto L_0x00a79c02;
    }
    // 00a79ba0  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a79ba2  e8690e0000             -call 0xa7aa10
    cpu.esp -= 4;
    sub_a7aa10(app, cpu);
    if (cpu.terminate) return;
    // 00a79ba7  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a79baa  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00a79bad  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 00a79bb0  e8cba0ffff             -call 0xa73c80
    cpu.esp -= 4;
    sub_a73c80(app, cpu);
    if (cpu.terminate) return;
    // 00a79bb5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a79bb7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a79bb9  7519                   -jne 0xa79bd4
    if (!cpu.flags.zf)
    {
        goto L_0x00a79bd4;
    }
    // 00a79bbb  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 00a79bc0  e857e4ffff             -call 0xa7801c
    cpu.esp -= 4;
    sub_a7801c(app, cpu);
    if (cpu.terminate) return;
    // 00a79bc5  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a79bca  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00a79bcd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79bce  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79bcf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79bd0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79bd1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79bd2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79bd3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a79bd4:
    // 00a79bd4  0faf5c2404             -imul ebx, dword ptr [esp + 4]
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */))));
    // 00a79bd9  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00a79bdb  e8600e0000             -call 0xa7aa40
    cpu.esp -= 4;
    sub_a7aa40(app, cpu);
    if (cpu.terminate) return;
    // 00a79be0  83f8ff                 +cmp eax, -1
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
    // 00a79be3  7516                   -jne 0xa79bfb
    if (!cpu.flags.zf)
    {
        goto L_0x00a79bfb;
    }
    // 00a79be5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a79be7  e884a1ffff             -call 0xa73d70
    cpu.esp -= 4;
    sub_a73d70(app, cpu);
    if (cpu.terminate) return;
    // 00a79bec  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a79bf1  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00a79bf4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79bf5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79bf6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79bf7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79bf8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79bf9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79bfa  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a79bfb:
    // 00a79bfb  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a79bfd  e856100000             -call 0xa7ac58
    cpu.esp -= 4;
    sub_a7ac58(app, cpu);
    if (cpu.terminate) return;
L_0x00a79c02:
    // 00a79c02  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00a79c05  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79c06  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79c07  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79c08  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79c09  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79c0a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79c0b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a79c0c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a79c0c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a79c0d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a79c0e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a79c0f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a79c10  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a79c11  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a79c12  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00a79c15  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00a79c19  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a79c1b  750a                   -jne 0xa79c27
    if (!cpu.flags.zf)
    {
        goto L_0x00a79c27;
    }
    // 00a79c1d  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a79c22  e989010000             -jmp 0xa79db0
    goto L_0x00a79db0;
L_0x00a79c27:
    // 00a79c27  803800                 +cmp byte ptr [eax], 0
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
    // 00a79c2a  7415                   -je 0xa79c41
    if (cpu.flags.zf)
    {
        goto L_0x00a79c41;
    }
    // 00a79c2c  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a79c2f  803a00                 +cmp byte ptr [edx], 0
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
    // 00a79c32  740d                   -je 0xa79c41
    if (cpu.flags.zf)
    {
        goto L_0x00a79c41;
    }
L_0x00a79c34:
    // 00a79c34  803a3d                 +cmp byte ptr [edx], 0x3d
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
    // 00a79c37  7408                   -je 0xa79c41
    if (cpu.flags.zf)
    {
        goto L_0x00a79c41;
    }
    // 00a79c39  8a4a01                 -mov cl, byte ptr [edx + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00a79c3c  42                     -inc edx
    (cpu.edx)++;
    // 00a79c3d  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 00a79c3f  75f3                   -jne 0xa79c34
    if (!cpu.flags.zf)
    {
        goto L_0x00a79c34;
    }
L_0x00a79c41:
    // 00a79c41  803a00                 +cmp byte ptr [edx], 0
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
    // 00a79c44  750f                   -jne 0xa79c55
    if (!cpu.flags.zf)
    {
        goto L_0x00a79c55;
    }
    // 00a79c46  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a79c4b  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00a79c4e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79c4f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79c50  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79c51  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79c52  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79c53  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79c54  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a79c55:
    // 00a79c55  807a0100               +cmp byte ptr [edx + 1], 0
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
    // 00a79c59  0f94c0                 -sete al
    cpu.al = cpu.flags.zf;
    // 00a79c5c  0fb6e8                 -movzx ebp, al
    cpu.ebp = x86::reg32(cpu.al);
    // 00a79c5f  a10400a800             -mov eax, dword ptr [0xa80004]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11010052) /* 0xa80004 */);
    // 00a79c64  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a79c68  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a79c6a  7541                   -jne 0xa79cad
    if (!cpu.flags.zf)
    {
        goto L_0x00a79cad;
    }
    // 00a79c6c  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00a79c6e  0f853c010000           -jne 0xa79db0
    if (!cpu.flags.zf)
    {
        goto L_0x00a79db0;
    }
    // 00a79c74  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 00a79c79  e802a0ffff             -call 0xa73c80
    cpu.esp -= 4;
    sub_a73c80(app, cpu);
    if (cpu.terminate) return;
    // 00a79c7e  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a79c82  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a79c84  750f                   -jne 0xa79c95
    if (!cpu.flags.zf)
    {
        goto L_0x00a79c95;
    }
    // 00a79c86  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a79c8b  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00a79c8e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79c8f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79c90  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79c91  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79c92  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79c93  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79c94  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a79c95:
    // 00a79c95  a30400a800             -mov dword ptr [0xa80004], eax
    app->getMemory<x86::reg32>(x86::reg32(11010052) /* 0xa80004 */) = cpu.eax;
    // 00a79c9a  83c008                 +add eax, 8
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
    // 00a79c9d  8968f8                 -mov dword ptr [eax - 8], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-8) /* -0x8 */) = cpu.ebp;
    // 00a79ca0  8968fc                 -mov dword ptr [eax - 4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ebp;
    // 00a79ca3  a30000a800             -mov dword ptr [0xa80000], eax
    app->getMemory<x86::reg32>(x86::reg32(11010048) /* 0xa80000 */) = cpu.eax;
    // 00a79ca8  e9e5000000             -jmp 0xa79d92
    goto L_0x00a79d92;
L_0x00a79cad:
    // 00a79cad  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a79cb1  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00a79cb3  e804010000             -call 0xa79dbc
    cpu.esp -= 4;
    sub_a79dbc(app, cpu);
    if (cpu.terminate) return;
    // 00a79cb8  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00a79cba  0f85ee000000           -jne 0xa79dae
    if (!cpu.flags.zf)
    {
        goto L_0x00a79dae;
    }
    // 00a79cc0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a79cc2  0f8fc7000000           -jg 0xa79d8f
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a79d8f;
    }
    // 00a79cc8  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a79cca  f7dd                   -neg ebp
    cpu.ebp = ~cpu.ebp + 1;
    // 00a79ccc  8d5d01                 -lea ebx, [ebp + 1]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(1) /* 0x1 */);
    // 00a79ccf  8d0cad00000000         -lea ecx, [ebp*4]
    cpu.ecx = x86::reg32(cpu.ebp * 4);
    // 00a79cd6  8d4108                 -lea eax, [ecx + 8]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00a79cd9  8b350000a800           -mov esi, dword ptr [0xa80000]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(11010048) /* 0xa80000 */);
    // 00a79cdf  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00a79ce2  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00a79ce4  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a79ce6  754f                   -jne 0xa79d37
    if (!cpu.flags.zf)
    {
        goto L_0x00a79d37;
    }
    // 00a79ce8  e8939fffff             -call 0xa73c80
    cpu.esp -= 4;
    sub_a73c80(app, cpu);
    if (cpu.terminate) return;
    // 00a79ced  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a79cef  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a79cf3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a79cf5  750f                   -jne 0xa79d06
    if (!cpu.flags.zf)
    {
        goto L_0x00a79d06;
    }
    // 00a79cf7  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a79cfc  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00a79cff  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79d00  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79d01  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79d02  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79d03  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79d04  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79d05  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a79d06:
    // 00a79d06  8b350400a800           -mov esi, dword ptr [0xa80004]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(11010052) /* 0xa80004 */);
    // 00a79d0c  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a79d0e  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a79d0f  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a79d11  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a79d13  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a79d14  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a79d16  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a79d19  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a79d1b  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a79d1d  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a79d20  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a79d22  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79d23  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a79d24  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00a79d27  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a79d29  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a79d2b  a30000a800             -mov dword ptr [0xa80000], eax
    app->getMemory<x86::reg32>(x86::reg32(11010048) /* 0xa80000 */) = cpu.eax;
    // 00a79d30  e83b9effff             -call 0xa73b70
    cpu.esp -= 4;
    sub_a73b70(app, cpu);
    if (cpu.terminate) return;
    // 00a79d35  eb3c                   -jmp 0xa79d73
    goto L_0x00a79d73;
L_0x00a79d37:
    // 00a79d37  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a79d39  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a79d3d  e85ee3ffff             -call 0xa780a0
    cpu.esp -= 4;
    sub_a780a0(app, cpu);
    if (cpu.terminate) return;
    // 00a79d42  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a79d46  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a79d48  750f                   -jne 0xa79d59
    if (!cpu.flags.zf)
    {
        goto L_0x00a79d59;
    }
    // 00a79d4a  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a79d4f  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00a79d52  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79d53  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79d54  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79d55  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79d56  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79d57  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79d58  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a79d59:
    // 00a79d59  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 00a79d5c  8b150000a800           -mov edx, dword ptr [0xa80000]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11010048) /* 0xa80000 */);
    // 00a79d62  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00a79d64  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 00a79d66  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a79d68  e883110000             -call 0xa7aef0
    cpu.esp -= 4;
    sub_a7aef0(app, cpu);
    if (cpu.terminate) return;
    // 00a79d6d  890d0000a800           -mov dword ptr [0xa80000], ecx
    app->getMemory<x86::reg32>(x86::reg32(11010048) /* 0xa80000 */) = cpu.ecx;
L_0x00a79d73:
    // 00a79d73  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a79d77  8d04ad00000000         -lea eax, [ebp*4]
    cpu.eax = x86::reg32(cpu.ebp * 4);
    // 00a79d7e  01f8                   +add eax, edi
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
    // 00a79d80  893d0400a800           -mov dword ptr [0xa80004], edi
    app->getMemory<x86::reg32>(x86::reg32(11010052) /* 0xa80004 */) = cpu.edi;
    // 00a79d86  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00a79d8d  eb03                   -jmp 0xa79d92
    goto L_0x00a79d92;
L_0x00a79d8f:
    // 00a79d8f  8d68ff                 -lea ebp, [eax - 1]
    cpu.ebp = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
L_0x00a79d92:
    // 00a79d92  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a79d96  8d04ad00000000         -lea eax, [ebp*4]
    cpu.eax = x86::reg32(cpu.ebp * 4);
    // 00a79d9d  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a79d9f  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a79da3  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00a79da5  a10000a800             -mov eax, dword ptr [0xa80000]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11010048) /* 0xa80000 */);
    // 00a79daa  c6042800               -mov byte ptr [eax + ebp], 0
    app->getMemory<x86::reg8>(cpu.eax + cpu.ebp * 1) = 0 /*0x0*/;
L_0x00a79dae:
    // 00a79dae  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00a79db0:
    // 00a79db0  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00a79db3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79db4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79db5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79db6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79db7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79db8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79db9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a79dbc(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a79dbc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a79dbd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a79dbe  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a79dbf  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a79dc0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a79dc1  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a79dc3  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00a79dc5  8b350400a800           -mov esi, dword ptr [0xa80004]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(11010052) /* 0xa80004 */);
    // 00a79dcb  e9cb000000             -jmp 0xa79e9b
    goto L_0x00a79e9b;
L_0x00a79dd0:
    // 00a79dd0  8a27                   -mov ah, byte ptr [edi]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edi);
    // 00a79dd2  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00a79dd4  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 00a79dd6  0f84bc000000           -je 0xa79e98
    if (cpu.flags.zf)
    {
        goto L_0x00a79e98;
    }
L_0x00a79ddc:
    // 00a79ddc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a79dde  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 00a79de0  e8fbd7ffff             -call 0xa775e0
    cpu.esp -= 4;
    sub_a775e0(app, cpu);
    if (cpu.terminate) return;
    // 00a79de5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a79de7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a79de9  8a03                   -mov al, byte ptr [ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx);
    // 00a79deb  e8f0d7ffff             -call 0xa775e0
    cpu.esp -= 4;
    sub_a775e0(app, cpu);
    if (cpu.terminate) return;
    // 00a79df0  39c1                   +cmp ecx, eax
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
    // 00a79df2  0f85a0000000           -jne 0xa79e98
    if (!cpu.flags.zf)
    {
        goto L_0x00a79e98;
    }
    // 00a79df8  803a3d                 +cmp byte ptr [edx], 0x3d
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
    // 00a79dfb  0f858a000000           -jne 0xa79e8b
    if (!cpu.flags.zf)
    {
        goto L_0x00a79e8b;
    }
    // 00a79e01  8b150400a800           -mov edx, dword ptr [0xa80004]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11010052) /* 0xa80004 */);
    // 00a79e07  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 00a79e09  29d7                   -sub edi, edx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a79e0b  c1ff02                 -sar edi, 2
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (2 /*0x2*/ % 32));
    // 00a79e0e  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00a79e10  0f846c000000           -je 0xa79e82
    if (cpu.flags.zf)
    {
        goto L_0x00a79e82;
    }
    // 00a79e16  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00a79e18  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00a79e1a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a79e1c  740f                   -je 0xa79e2d
    if (cpu.flags.zf)
    {
        goto L_0x00a79e2d;
    }
L_0x00a79e1e:
    // 00a79e1e  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00a79e21  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 00a79e23  8b5904                 -mov ebx, dword ptr [ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00a79e26  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a79e29  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a79e2b  75f1                   -jne 0xa79e1e
    if (!cpu.flags.zf)
    {
        goto L_0x00a79e1e;
    }
L_0x00a79e2d:
    // 00a79e2d  8b350000a800           -mov esi, dword ptr [0xa80000]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(11010048) /* 0xa80000 */);
    // 00a79e33  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a79e35  7443                   -je 0xa79e7a
    if (cpu.flags.zf)
    {
        goto L_0x00a79e7a;
    }
    // 00a79e37  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a79e39  803c0700               +cmp byte ptr [edi + eax], 0
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
    // 00a79e3d  7407                   -je 0xa79e46
    if (cpu.flags.zf)
    {
        goto L_0x00a79e46;
    }
    // 00a79e3f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a79e41  e82a9fffff             -call 0xa73d70
    cpu.esp -= 4;
    sub_a73d70(app, cpu);
    if (cpu.terminate) return;
L_0x00a79e46:
    // 00a79e46  8b2d0400a800           -mov ebp, dword ptr [0xa80004]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(11010052) /* 0xa80004 */);
    // 00a79e4c  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00a79e4e  29ee                   -sub esi, ebp
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00a79e50  8b150000a800           -mov edx, dword ptr [0xa80000]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11010048) /* 0xa80000 */);
    // 00a79e56  c1fe02                 -sar esi, 2
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (2 /*0x2*/ % 32));
    // 00a79e59  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a79e5b  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00a79e5d  e88e100000             -call 0xa7aef0
    cpu.esp -= 4;
    sub_a7aef0(app, cpu);
    if (cpu.terminate) return;
    // 00a79e62  890d0000a800           -mov dword ptr [0xa80000], ecx
    app->getMemory<x86::reg32>(x86::reg32(11010048) /* 0xa80000 */) = cpu.ecx;
    // 00a79e68  39f7                   +cmp edi, esi
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
    // 00a79e6a  7d0e                   -jge 0xa79e7a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a79e7a;
    }
    // 00a79e6c  8d040f                 -lea eax, [edi + ecx]
    cpu.eax = x86::reg32(cpu.edi + cpu.ecx * 1);
L_0x00a79e6f:
    // 00a79e6f  40                     -inc eax
    (cpu.eax)++;
    // 00a79e70  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a79e72  47                     -inc edi
    (cpu.edi)++;
    // 00a79e73  8850ff                 -mov byte ptr [eax - 1], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-1) /* -0x1 */) = cpu.dl;
    // 00a79e76  39f7                   +cmp edi, esi
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
    // 00a79e78  7cf5                   -jl 0xa79e6f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a79e6f;
    }
L_0x00a79e7a:
    // 00a79e7a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a79e7c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79e7d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79e7e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79e7f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79e80  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79e81  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a79e82:
    // 00a79e82  8d4701                 -lea eax, [edi + 1]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 00a79e85  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79e86  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79e87  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79e88  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79e89  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79e8a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a79e8b:
    // 00a79e8b  42                     -inc edx
    (cpu.edx)++;
    // 00a79e8c  8a4b01                 -mov cl, byte ptr [ebx + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 00a79e8f  43                     -inc ebx
    (cpu.ebx)++;
    // 00a79e90  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 00a79e92  0f8544ffffff           -jne 0xa79ddc
    if (!cpu.flags.zf)
    {
        goto L_0x00a79ddc;
    }
L_0x00a79e98:
    // 00a79e98  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00a79e9b:
    // 00a79e9b  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00a79e9d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a79e9f  0f852bffffff           -jne 0xa79dd0
    if (!cpu.flags.zf)
    {
        goto L_0x00a79dd0;
    }
    // 00a79ea5  a10400a800             -mov eax, dword ptr [0xa80004]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11010052) /* 0xa80004 */);
    // 00a79eaa  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00a79eac  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 00a79eaf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79eb0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79eb1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79eb2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79eb3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79eb4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a79ec0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a79ec0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a79ec1  833df00da80000         +cmp dword ptr [0xa80df0], 0
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
    // 00a79ec8  7428                   -je 0xa79ef2
    if (cpu.flags.zf)
    {
        goto L_0x00a79ef2;
    }
    // 00a79eca  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a79ecc  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a79ece  8a92010ea800           -mov dl, byte ptr [edx + 0xa80e01]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(11013633) /* 0xa80e01 */);
    // 00a79ed4  80e201                 -and dl, 1
    cpu.dl &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00a79ed7  81e2ff000000           +and edx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00a79edd  7413                   -je 0xa79ef2
    if (cpu.flags.zf)
    {
        goto L_0x00a79ef2;
    }
    // 00a79edf  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a79ee1  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a79ee3  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 00a79ee6  8a4001                 -mov al, byte ptr [eax + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a79ee9  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a79eee  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 00a79ef0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79ef1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a79ef2:
    // 00a79ef2  8a00                   -mov al, byte ptr [eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax);
    // 00a79ef4  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a79ef9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79efa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void sub_a79f00(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a79f00  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a79f01  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a79f02  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a79f03  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a79f06  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a79f08  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00a79f0a  e861000000             -call 0xa79f70
    cpu.esp -= 4;
    sub_a79f70(app, cpu);
    if (cpu.terminate) return;
    // 00a79f0f  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a79f11  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 00a79f13  e838dcffff             -call 0xa77b50
    cpu.esp -= 4;
    sub_a77b50(app, cpu);
    if (cpu.terminate) return;
    // 00a79f18  881404                 -mov byte ptr [esp + eax], dl
    app->getMemory<x86::reg8>(cpu.esp + cpu.eax * 1) = cpu.dl;
    // 00a79f1b  813d54d6a700a4030000   +cmp dword ptr [0xa7d654], 0x3a4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10999380) /* 0xa7d654 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(932 /*0x3a4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a79f25  7526                   -jne 0xa79f4d
    if (!cpu.flags.zf)
    {
        goto L_0x00a79f4d;
    }
    // 00a79f27  833df00da80000         +cmp dword ptr [0xa80df0], 0
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
    // 00a79f2e  741d                   -je 0xa79f4d
    if (cpu.flags.zf)
    {
        goto L_0x00a79f4d;
    }
    // 00a79f30  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a79f32  8a0424                 -mov al, byte ptr [esp]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp);
    // 00a79f35  8a80010ea800           -mov al, byte ptr [eax + 0xa80e01]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(11013633) /* 0xa80e01 */);
    // 00a79f3b  2401                   -and al, 1
    cpu.al &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00a79f3d  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00a79f42  7409                   -je 0xa79f4d
    if (cpu.flags.zf)
    {
        goto L_0x00a79f4d;
    }
    // 00a79f44  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a79f46  e8f50f0000             -call 0xa7af40
    cpu.esp -= 4;
    sub_a7af40(app, cpu);
    if (cpu.terminate) return;
    // 00a79f4b  eb15                   -jmp 0xa79f62
    goto L_0x00a79f62;
L_0x00a79f4d:
    // 00a79f4d  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00a79f4f  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a79f53  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a79f54  2eff1568bda700         -call dword ptr cs:[0xa7bd68]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993000) /* 0xa7bd68 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a79f5b  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a79f5d  e85effffff             -call 0xa79ec0
    cpu.esp -= 4;
    sub_a79ec0(app, cpu);
    if (cpu.terminate) return;
L_0x00a79f62:
    // 00a79f62  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a79f65  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79f66  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79f67  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79f68  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a79f70(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a79f70  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a79f71  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a79f73  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a79f75  f6c7ff                 +test bh, 0xff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 255 /*0xff*/));
    // 00a79f78  740c                   -je 0xa79f86
    if (cpu.flags.zf)
    {
        goto L_0x00a79f86;
    }
    // 00a79f7a  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00a79f7c  885801                 -mov byte ptr [eax + 1], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = cpu.bl;
    // 00a79f7f  c1ea08                 -shr edx, 8
    cpu.edx >>= 8 /*0x8*/ % 32;
    // 00a79f82  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 00a79f84  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79f85  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a79f86:
    // 00a79f86  881a                   -mov byte ptr [edx], bl
    app->getMemory<x86::reg8>(cpu.edx) = cpu.bl;
    // 00a79f88  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79f89  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a79f90(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a79f90  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a79f91  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a79f92  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a79f93  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a79f95  ff1598d2a700           -call dword ptr [0xa7d298]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10998424) /* 0xa7d298 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a79f9b  833de0d2a70000         +cmp dword ptr [0xa7d2e0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10998496) /* 0xa7d2e0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a79fa2  741d                   -je 0xa79fc1
    if (cpu.flags.zf)
    {
        goto L_0x00a79fc1;
    }
    // 00a79fa4  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a79fa6  ff15e0d2a700           -call dword ptr [0xa7d2e0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10998496) /* 0xa7d2e0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a79fac  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a79fae  7411                   -je 0xa79fc1
    if (cpu.flags.zf)
    {
        goto L_0x00a79fc1;
    }
    // 00a79fb0  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a79fb2  ff159cd2a700           -call dword ptr [0xa7d29c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10998428) /* 0xa7d29c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a79fb8  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a79fbd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79fbe  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79fbf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79fc0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a79fc1:
    // 00a79fc1  a188d3a700             -mov eax, dword ptr [0xa7d388]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10998664) /* 0xa7d388 */);
    // 00a79fc6  8b0498                 -mov eax, dword ptr [eax + ebx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.ebx * 4);
    // 00a79fc9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a79fca  2eff15dcbda700         -call dword ptr cs:[0xa7bddc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993116) /* 0xa7bddc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a79fd1  83f802                 +cmp eax, 2
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
    // 00a79fd4  7511                   -jne 0xa79fe7
    if (!cpu.flags.zf)
    {
        goto L_0x00a79fe7;
    }
    // 00a79fd6  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a79fd8  ff159cd2a700           -call dword ptr [0xa7d29c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10998428) /* 0xa7d29c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a79fde  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a79fe3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79fe4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79fe5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79fe6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a79fe7:
    // 00a79fe7  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a79fe9  ff159cd2a700           -call dword ptr [0xa7d29c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10998428) /* 0xa7d29c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a79fef  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a79ff1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79ff2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79ff3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a79ff4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a7a000(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7a000  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a7a001  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a7a002  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00a7a004  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a7a005  2eff15d8bda700         -call dword ptr cs:[0xa7bdd8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993112) /* 0xa7bdd8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a7a00c  83f8ff                 +cmp eax, -1
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
    // 00a7a00f  7508                   -jne 0xa7a019
    if (!cpu.flags.zf)
    {
        goto L_0x00a7a019;
    }
    // 00a7a011  e86ee0ffff             -call 0xa78084
    cpu.esp -= 4;
    sub_a78084(app, cpu);
    if (cpu.terminate) return;
    // 00a7a016  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a017  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a018  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a7a019:
    // 00a7a019  f6c302                 +test bl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 2 /*0x2*/));
    // 00a7a01c  7411                   -je 0xa7a02f
    if (cpu.flags.zf)
    {
        goto L_0x00a7a02f;
    }
    // 00a7a01e  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 00a7a020  740d                   -je 0xa7a02f
    if (cpu.flags.zf)
    {
        goto L_0x00a7a02f;
    }
    // 00a7a022  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 00a7a027  e8f0dfffff             -call 0xa7801c
    cpu.esp -= 4;
    sub_a7801c(app, cpu);
    if (cpu.terminate) return;
    // 00a7a02c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a02d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a02e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a7a02f:
    // 00a7a02f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a7a031  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a032  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a033  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a7a040(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7a040  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a7a041  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a7a042  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a7a043  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a7a044  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a7a045  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a7a048  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a7a04a  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00a7a04c  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00a7a051  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a7a053  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00a7a055  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00a7a057  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 00a7a05a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a7a05c  740e                   -je 0xa7a06c
    if (cpu.flags.zf)
    {
        goto L_0x00a7a06c;
    }
    // 00a7a05e  3b1580d7a700           +cmp edx, dword ptr [0xa7d780]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(10999680) /* 0xa7d780 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a7a064  7504                   -jne 0xa7a06a
    if (!cpu.flags.zf)
    {
        goto L_0x00a7a06a;
    }
    // 00a7a066  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 00a7a068  eb02                   -jmp 0xa7a06c
    goto L_0x00a7a06c;
L_0x00a7a06a:
    // 00a7a06a  891e                   -mov dword ptr [esi], ebx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ebx;
L_0x00a7a06c:
    // 00a7a06c  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 00a7a06e  3c72                   +cmp al, 0x72
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
    // 00a7a070  7208                   -jb 0xa7a07a
    if (cpu.flags.cf)
    {
        goto L_0x00a7a07a;
    }
    // 00a7a072  760c                   -jbe 0xa7a080
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a7a080;
    }
    // 00a7a074  3c77                   +cmp al, 0x77
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
    // 00a7a076  740d                   -je 0xa7a085
    if (cpu.flags.zf)
    {
        goto L_0x00a7a085;
    }
    // 00a7a078  eb15                   -jmp 0xa7a08f
    goto L_0x00a7a08f;
L_0x00a7a07a:
    // 00a7a07a  3c61                   +cmp al, 0x61
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
    // 00a7a07c  740c                   -je 0xa7a08a
    if (cpu.flags.zf)
    {
        goto L_0x00a7a08a;
    }
    // 00a7a07e  eb0f                   -jmp 0xa7a08f
    goto L_0x00a7a08f;
L_0x00a7a080:
    // 00a7a080  80cb01                 +or bl, 1
    cpu.clear_co();
    cpu.set_szp((cpu.bl |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 00a7a083  eb1b                   -jmp 0xa7a0a0
    goto L_0x00a7a0a0;
L_0x00a7a085:
    // 00a7a085  80cb02                 +or bl, 2
    cpu.clear_co();
    cpu.set_szp((cpu.bl |= x86::reg8(x86::sreg8(2 /*0x2*/))));
    // 00a7a088  eb16                   -jmp 0xa7a0a0
    goto L_0x00a7a0a0;
L_0x00a7a08a:
    // 00a7a08a  80cb82                 +or bl, 0x82
    cpu.clear_co();
    cpu.set_szp((cpu.bl |= x86::reg8(x86::sreg8(130 /*0x82*/))));
    // 00a7a08d  eb11                   -jmp 0xa7a0a0
    goto L_0x00a7a0a0;
L_0x00a7a08f:
    // 00a7a08f  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 00a7a094  e827c3ffff             -call 0xa763c0
    cpu.esp -= 4;
    sub_a763c0(app, cpu);
    if (cpu.terminate) return;
    // 00a7a099  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a7a09b  e9cf000000             -jmp 0xa7a16f
    goto L_0x00a7a16f;
L_0x00a7a0a0:
    // 00a7a0a0  8a6101                 -mov ah, byte ptr [ecx + 1]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 00a7a0a3  41                     -inc ecx
    (cpu.ecx)++;
    // 00a7a0a4  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 00a7a0a6  0f84ae000000           -je 0xa7a15a
    if (cpu.flags.zf)
    {
        goto L_0x00a7a15a;
    }
L_0x00a7a0ac:
    // 00a7a0ac  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a7a0ae  0f84a6000000           -je 0xa7a15a
    if (cpu.flags.zf)
    {
        goto L_0x00a7a15a;
    }
    // 00a7a0b4  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 00a7a0b6  3c63                   +cmp al, 0x63
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
    // 00a7a0b8  721d                   -jb 0xa7a0d7
    if (cpu.flags.cf)
    {
        goto L_0x00a7a0d7;
    }
    // 00a7a0ba  0f8665000000           -jbe 0xa7a125
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a7a125;
    }
    // 00a7a0c0  3c6e                   +cmp al, 0x6e
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
    // 00a7a0c2  0f8286000000           -jb 0xa7a14e
    if (cpu.flags.cf)
    {
        goto L_0x00a7a14e;
    }
    // 00a7a0c8  0f866c000000           -jbe 0xa7a13a
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a7a13a;
    }
    // 00a7a0ce  3c74                   +cmp al, 0x74
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
    // 00a7a0d0  7432                   -je 0xa7a104
    if (cpu.flags.zf)
    {
        goto L_0x00a7a104;
    }
    // 00a7a0d2  e977000000             -jmp 0xa7a14e
    goto L_0x00a7a14e;
L_0x00a7a0d7:
    // 00a7a0d7  3c2b                   +cmp al, 0x2b
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
    // 00a7a0d9  0f826f000000           -jb 0xa7a14e
    if (cpu.flags.cf)
    {
        goto L_0x00a7a14e;
    }
    // 00a7a0df  7609                   -jbe 0xa7a0ea
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a7a0ea;
    }
    // 00a7a0e1  3c62                   +cmp al, 0x62
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
    // 00a7a0e3  742e                   -je 0xa7a113
    if (cpu.flags.zf)
    {
        goto L_0x00a7a113;
    }
    // 00a7a0e5  e964000000             -jmp 0xa7a14e
    goto L_0x00a7a14e;
L_0x00a7a0ea:
    // 00a7a0ea  833c2400               +cmp dword ptr [esp], 0
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
    // 00a7a0ee  7407                   -je 0xa7a0f7
    if (cpu.flags.zf)
    {
        goto L_0x00a7a0f7;
    }
    // 00a7a0f0  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a7a0f2  e957000000             -jmp 0xa7a14e
    goto L_0x00a7a14e;
L_0x00a7a0f7:
    // 00a7a0f7  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a7a0fc  80cb03                 +or bl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.bl |= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a7a0ff  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00a7a102  eb4a                   -jmp 0xa7a14e
    goto L_0x00a7a14e;
L_0x00a7a104:
    // 00a7a104  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a7a106  7404                   -je 0xa7a10c
    if (cpu.flags.zf)
    {
        goto L_0x00a7a10c;
    }
    // 00a7a108  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a7a10a  eb42                   -jmp 0xa7a14e
    goto L_0x00a7a14e;
L_0x00a7a10c:
    // 00a7a10c  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 00a7a111  eb3b                   -jmp 0xa7a14e
    goto L_0x00a7a14e;
L_0x00a7a113:
    // 00a7a113  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a7a115  7404                   -je 0xa7a11b
    if (cpu.flags.zf)
    {
        goto L_0x00a7a11b;
    }
    // 00a7a117  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a7a119  eb33                   -jmp 0xa7a14e
    goto L_0x00a7a14e;
L_0x00a7a11b:
    // 00a7a11b  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 00a7a120  80cb40                 +or bl, 0x40
    cpu.clear_co();
    cpu.set_szp((cpu.bl |= x86::reg8(x86::sreg8(64 /*0x40*/))));
    // 00a7a123  eb29                   -jmp 0xa7a14e
    goto L_0x00a7a14e;
L_0x00a7a125:
    // 00a7a125  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00a7a127  7404                   -je 0xa7a12d
    if (cpu.flags.zf)
    {
        goto L_0x00a7a12d;
    }
    // 00a7a129  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a7a12b  eb21                   -jmp 0xa7a14e
    goto L_0x00a7a14e;
L_0x00a7a12d:
    // 00a7a12d  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00a7a12f  0c01                   +or al, 1
    cpu.clear_co();
    cpu.set_szp((cpu.al |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 00a7a131  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 00a7a136  8806                   -mov byte ptr [esi], al
    app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
    // 00a7a138  eb14                   -jmp 0xa7a14e
    goto L_0x00a7a14e;
L_0x00a7a13a:
    // 00a7a13a  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00a7a13c  7404                   -je 0xa7a142
    if (cpu.flags.zf)
    {
        goto L_0x00a7a142;
    }
    // 00a7a13e  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a7a140  eb0c                   -jmp 0xa7a14e
    goto L_0x00a7a14e;
L_0x00a7a142:
    // 00a7a142  8a26                   -mov ah, byte ptr [esi]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esi);
    // 00a7a144  80e4fe                 -and ah, 0xfe
    cpu.ah &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 00a7a147  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 00a7a14c  8826                   -mov byte ptr [esi], ah
    app->getMemory<x86::reg8>(cpu.esi) = cpu.ah;
L_0x00a7a14e:
    // 00a7a14e  8a4101                 -mov al, byte ptr [ecx + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 00a7a151  41                     -inc ecx
    (cpu.ecx)++;
    // 00a7a152  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00a7a154  0f8552ffffff           -jne 0xa7a0ac
    if (!cpu.flags.zf)
    {
        goto L_0x00a7a0ac;
    }
L_0x00a7a15a:
    // 00a7a15a  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a7a15c  750f                   -jne 0xa7a16d
    if (!cpu.flags.zf)
    {
        goto L_0x00a7a16d;
    }
    // 00a7a15e  813d6cd1a70000020000   +cmp dword ptr [0xa7d16c], 0x200
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10998124) /* 0xa7d16c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(512 /*0x200*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a7a168  7503                   -jne 0xa7a16d
    if (!cpu.flags.zf)
    {
        goto L_0x00a7a16d;
    }
    // 00a7a16a  80cb40                 -or bl, 0x40
    cpu.bl |= x86::reg8(x86::sreg8(64 /*0x40*/));
L_0x00a7a16d:
    // 00a7a16d  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
L_0x00a7a16f:
    // 00a7a16f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a7a171  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a7a174  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a175  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a176  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a177  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a178  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a179  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a7a17c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7a17c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a7a17d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a7a17e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a7a17f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a7a181  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 00a7a183  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a7a185  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00a7a189  80610cfc               -and byte ptr [ecx + 0xc], 0xfc
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 00a7a18d  09590c                 -or dword ptr [ecx + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) |= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a7a190  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a7a195  e806080000             -call 0xa7a9a0
    cpu.esp -= 4;
    sub_a7a9a0(app, cpu);
    if (cpu.terminate) return;
    // 00a7a19a  3c72                   +cmp al, 0x72
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
    // 00a7a19c  7522                   -jne 0xa7a1c0
    if (!cpu.flags.zf)
    {
        goto L_0x00a7a1c0;
    }
    // 00a7a19e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a7a1a0  f6c302                 +test bl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 2 /*0x2*/));
    // 00a7a1a3  7405                   -je 0xa7a1aa
    if (cpu.flags.zf)
    {
        goto L_0x00a7a1aa;
    }
    // 00a7a1a5  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
L_0x00a7a1aa:
    // 00a7a1aa  f6c340                 +test bl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 64 /*0x40*/));
    // 00a7a1ad  7405                   -je 0xa7a1b4
    if (cpu.flags.zf)
    {
        goto L_0x00a7a1b4;
    }
    // 00a7a1af  80cc02                 +or ah, 2
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(2 /*0x2*/))));
    // 00a7a1b2  eb03                   -jmp 0xa7a1b7
    goto L_0x00a7a1b7;
L_0x00a7a1b4:
    // 00a7a1b4  80cc01                 +or ah, 1
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(1 /*0x1*/))));
L_0x00a7a1b7:
    // 00a7a1b7  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a7a1b9  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00a7a1bd  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a7a1be  eb30                   -jmp 0xa7a1f0
    goto L_0x00a7a1f0;
L_0x00a7a1c0:
    // 00a7a1c0  f6c301                 +test bl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 1 /*0x1*/));
    // 00a7a1c3  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 00a7a1c6  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a7a1cb  83c021                 -add eax, 0x21
    (cpu.eax) += x86::reg32(x86::sreg32(33 /*0x21*/));
    // 00a7a1ce  f6c380                 +test bl, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 128 /*0x80*/));
    // 00a7a1d1  7404                   -je 0xa7a1d7
    if (cpu.flags.zf)
    {
        goto L_0x00a7a1d7;
    }
    // 00a7a1d3  0c10                   +or al, 0x10
    cpu.clear_co();
    cpu.set_szp((cpu.al |= x86::reg8(x86::sreg8(16 /*0x10*/))));
    // 00a7a1d5  eb02                   -jmp 0xa7a1d9
    goto L_0x00a7a1d9;
L_0x00a7a1d7:
    // 00a7a1d7  0c40                   -or al, 0x40
    cpu.al |= x86::reg8(x86::sreg8(64 /*0x40*/));
L_0x00a7a1d9:
    // 00a7a1d9  f6c340                 +test bl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 64 /*0x40*/));
    // 00a7a1dc  7405                   -je 0xa7a1e3
    if (cpu.flags.zf)
    {
        goto L_0x00a7a1e3;
    }
    // 00a7a1de  80cc02                 +or ah, 2
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(2 /*0x2*/))));
    // 00a7a1e1  eb03                   -jmp 0xa7a1e6
    goto L_0x00a7a1e6;
L_0x00a7a1e3:
    // 00a7a1e3  80cc01                 -or ah, 1
    cpu.ah |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x00a7a1e6:
    // 00a7a1e6  6880010000             -push 0x180
    app->getMemory<x86::reg32>(cpu.esp-4) = 384 /*0x180*/;
    cpu.esp -= 4;
    // 00a7a1eb  8b6c2414               -mov ebp, dword ptr [esp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00a7a1ef  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
L_0x00a7a1f0:
    // 00a7a1f0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a7a1f1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a7a1f2  e89d0d0000             -call 0xa7af94
    cpu.esp -= 4;
    sub_a7af94(app, cpu);
    if (cpu.terminate) return;
    // 00a7a1f7  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a7a1fa  894110                 -mov dword ptr [ecx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00a7a1fd  837910ff               +cmp dword ptr [ecx + 0x10], -1
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
    // 00a7a201  750b                   -jne 0xa7a20e
    if (!cpu.flags.zf)
    {
        goto L_0x00a7a20e;
    }
    // 00a7a203  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a7a205  e87abeffff             -call 0xa76084
    cpu.esp -= 4;
    sub_a76084(app, cpu);
    if (cpu.terminate) return;
    // 00a7a20a  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a7a20c  eb4e                   -jmp 0xa7a25c
    goto L_0x00a7a25c;
L_0x00a7a20e:
    // 00a7a20e  c7410400000000         -mov dword ptr [ecx + 4], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00a7a215  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00a7a218  c7411400000000         -mov dword ptr [ecx + 0x14], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 00a7a21f  c7400c00000000         -mov dword ptr [eax + 0xc], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 00a7a226  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00a7a229  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 00a7a22c  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00a7a22f  c7401500000000         -mov dword ptr [eax + 0x15], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(21) /* 0x15 */) = 0 /*0x0*/;
    // 00a7a236  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00a7a239  c7400800000000         -mov dword ptr [eax + 8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 00a7a240  f6c380                 +test bl, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 128 /*0x80*/));
    // 00a7a243  740e                   -je 0xa7a253
    if (cpu.flags.zf)
    {
        goto L_0x00a7a253;
    }
    // 00a7a245  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 00a7a24a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a7a24c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a7a24e  e8f50f0000             -call 0xa7b248
    cpu.esp -= 4;
    sub_a7b248(app, cpu);
    if (cpu.terminate) return;
L_0x00a7a253:
    // 00a7a253  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a7a255  e8d6d9ffff             -call 0xa77c30
    cpu.esp -= 4;
    sub_a77c30(app, cpu);
    if (cpu.terminate) return;
    // 00a7a25a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x00a7a25c:
    // 00a7a25c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a25d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a25e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a25f  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a7a264(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7a264  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a7a265  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a7a266  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a7a267  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a7a26a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a7a26c  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00a7a26e  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00a7a270  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00a7a272  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a7a274  e8c7fdffff             -call 0xa7a040
    cpu.esp -= 4;
    sub_a7a040(app, cpu);
    if (cpu.terminate) return;
    // 00a7a279  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a7a27b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a7a27d  7422                   -je 0xa7a2a1
    if (cpu.flags.zf)
    {
        goto L_0x00a7a2a1;
    }
    // 00a7a27f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a7a281  e83abdffff             -call 0xa75fc0
    cpu.esp -= 4;
    sub_a75fc0(app, cpu);
    if (cpu.terminate) return;
    // 00a7a286  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a7a288  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a7a28a  7413                   -je 0xa7a29f
    if (cpu.flags.zf)
    {
        goto L_0x00a7a29f;
    }
    // 00a7a28c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a7a28d  31c2                   -xor edx, eax
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a7a28f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a7a290  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a7a292  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 00a7a294  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a7a298  e8dffeffff             -call 0xa7a17c
    cpu.esp -= 4;
    sub_a7a17c(app, cpu);
    if (cpu.terminate) return;
    // 00a7a29d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x00a7a29f:
    // 00a7a29f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x00a7a2a1:
    // 00a7a2a1  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a7a2a4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a2a5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a2a6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a2a7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a7a2a8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7a2a8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a7a2a9  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a7a2ab  e8b4ffffff             -call 0xa7a264
    cpu.esp -= 4;
    sub_a7a264(app, cpu);
    if (cpu.terminate) return;
    // 00a7a2b0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a2b1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a7a2b4(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7a2b4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a7a2b5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a7a2b6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a7a2b7  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a7a2b9  ff15a8d2a700           -call dword ptr [0xa7d2a8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10998440) /* 0xa7d2a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a7a2bf  a1e0ffa700             -mov eax, dword ptr [0xa7ffe0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11010016) /* 0xa7ffe0 */);
    // 00a7a2c4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a7a2c6  742b                   -je 0xa7a2f3
    if (cpu.flags.zf)
    {
        goto L_0x00a7a2f3;
    }
L_0x00a7a2c8:
    // 00a7a2c8  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a7a2cb  39d3                   +cmp ebx, edx
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
    // 00a7a2cd  751e                   -jne 0xa7a2ed
    if (!cpu.flags.zf)
    {
        goto L_0x00a7a2ed;
    }
    // 00a7a2cf  f6420c03               +test byte ptr [edx + 0xc], 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) & 3 /*0x3*/));
    // 00a7a2d3  740c                   -je 0xa7a2e1
    if (cpu.flags.zf)
    {
        goto L_0x00a7a2e1;
    }
    // 00a7a2d5  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00a7a2da  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a7a2dc  e823bfffff             -call 0xa76204
    cpu.esp -= 4;
    sub_a76204(app, cpu);
    if (cpu.terminate) return;
L_0x00a7a2e1:
    // 00a7a2e1  ff15acd2a700           -call dword ptr [0xa7d2ac]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10998444) /* 0xa7d2ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a7a2e7  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a7a2e9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a2ea  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a2eb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a2ec  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a7a2ed:
    // 00a7a2ed  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00a7a2ef  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a7a2f1  75d5                   -jne 0xa7a2c8
    if (!cpu.flags.zf)
    {
        goto L_0x00a7a2c8;
    }
L_0x00a7a2f3:
    // 00a7a2f3  bae4ffa700             -mov edx, 0xa7ffe4
    cpu.edx = 11010020 /*0xa7ffe4*/;
L_0x00a7a2f8:
    // 00a7a2f8  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00a7a2fa  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a7a2fc  7426                   -je 0xa7a324
    if (cpu.flags.zf)
    {
        goto L_0x00a7a324;
    }
    // 00a7a2fe  3b5804                 +cmp ebx, dword ptr [eax + 4]
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
    // 00a7a301  751d                   -jne 0xa7a320
    if (!cpu.flags.zf)
    {
        goto L_0x00a7a320;
    }
    // 00a7a303  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00a7a305  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 00a7a307  8b15e0ffa700           -mov edx, dword ptr [0xa7ffe0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11010016) /* 0xa7ffe0 */);
    // 00a7a30d  a3e0ffa700             -mov dword ptr [0xa7ffe0], eax
    app->getMemory<x86::reg32>(x86::reg32(11010016) /* 0xa7ffe0 */) = cpu.eax;
    // 00a7a312  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00a7a314  ff15acd2a700           -call dword ptr [0xa7d2ac]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10998444) /* 0xa7d2ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a7a31a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a7a31c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a31d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a31e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a31f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a7a320:
    // 00a7a320  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a7a322  ebd4                   -jmp 0xa7a2f8
    goto L_0x00a7a2f8;
L_0x00a7a324:
    // 00a7a324  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00a7a329  e892c0ffff             -call 0xa763c0
    cpu.esp -= 4;
    sub_a763c0(app, cpu);
    if (cpu.terminate) return;
    // 00a7a32e  ff15acd2a700           -call dword ptr [0xa7d2ac]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10998444) /* 0xa7d2ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a7a334  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a7a336  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a337  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a338  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a339  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a7a33c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7a33c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a7a33d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a7a33e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a7a33f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a7a340  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a7a343  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a7a345  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00a7a347  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00a7a349  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a7a34b  e8f0fcffff             -call 0xa7a040
    cpu.esp -= 4;
    sub_a7a040(app, cpu);
    if (cpu.terminate) return;
    // 00a7a350  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a7a352  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a7a354  7455                   -je 0xa7a3ab
    if (cpu.flags.zf)
    {
        goto L_0x00a7a3ab;
    }
    // 00a7a356  8b7310                 -mov esi, dword ptr [ebx + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 00a7a359  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a7a35b  ff1598d2a700           -call dword ptr [0xa7d298]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10998424) /* 0xa7d298 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a7a361  833de4d2a70000         +cmp dword ptr [0xa7d2e4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10998500) /* 0xa7d2e4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a7a368  7408                   -je 0xa7a372
    if (cpu.flags.zf)
    {
        goto L_0x00a7a372;
    }
    // 00a7a36a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a7a36c  ff15e4d2a700           -call dword ptr [0xa7d2e4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10998500) /* 0xa7d2e4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a7a372:
    // 00a7a372  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a7a374  e83bffffff             -call 0xa7a2b4
    cpu.esp -= 4;
    sub_a7a2b4(app, cpu);
    if (cpu.terminate) return;
    // 00a7a379  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a7a37b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a7a37d  7422                   -je 0xa7a3a1
    if (cpu.flags.zf)
    {
        goto L_0x00a7a3a1;
    }
    // 00a7a37f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a7a380  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00a7a383  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a7a385  81e300400000           -and ebx, 0x4000
    cpu.ebx &= x86::reg32(x86::sreg32(16384 /*0x4000*/));
    // 00a7a38b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a7a38d  89580c                 -mov dword ptr [eax + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 00a7a390  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 00a7a392  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a7a394  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 00a7a396  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a7a39a  e8ddfdffff             -call 0xa7a17c
    cpu.esp -= 4;
    sub_a7a17c(app, cpu);
    if (cpu.terminate) return;
    // 00a7a39f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x00a7a3a1:
    // 00a7a3a1  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a7a3a3  ff159cd2a700           -call dword ptr [0xa7d29c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10998428) /* 0xa7d29c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a7a3a9  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x00a7a3ab:
    // 00a7a3ab  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a7a3ae  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a3af  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a3b0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a3b1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a3b2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a7a3c0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7a3c0  ff1594d2a700           -call dword ptr [0xa7d294]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10998420) /* 0xa7d294 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a7a3c6  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a7a3c9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a7a3cc(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7a3cc  ff1594d2a700           -call dword ptr [0xa7d294]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10998420) /* 0xa7d294 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a7a3d2  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a7a3d5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a7a3e0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7a3e0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a7a3e1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a7a3e2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a7a3e3  2eff1514bea700         -call dword ptr cs:[0xa7be14]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993172) /* 0xa7be14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a7a3ea  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a7a3ec  7507                   -jne 0xa7a3f5
    if (!cpu.flags.zf)
    {
        goto L_0x00a7a3f5;
    }
    // 00a7a3ee  e891dcffff             -call 0xa78084
    cpu.esp -= 4;
    sub_a78084(app, cpu);
    if (cpu.terminate) return;
    // 00a7a3f3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a3f4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a7a3f5:
    // 00a7a3f5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a7a3f7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a3f8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a7a400(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7a400  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a7a401  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a7a402  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a7a403  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a7a406  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a7a408  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00a7a40a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a7a40c  7525                   -jne 0xa7a433
    if (!cpu.flags.zf)
    {
        goto L_0x00a7a433;
    }
    // 00a7a40e  bb04010000             -mov ebx, 0x104
    cpu.ebx = 260 /*0x104*/;
    // 00a7a413  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a7a415  e86698ffff             -call 0xa73c80
    cpu.esp -= 4;
    sub_a73c80(app, cpu);
    if (cpu.terminate) return;
    // 00a7a41a  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a7a41c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a7a41e  7511                   -jne 0xa7a431
    if (!cpu.flags.zf)
    {
        goto L_0x00a7a431;
    }
    // 00a7a420  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 00a7a425  e896bfffff             -call 0xa763c0
    cpu.esp -= 4;
    sub_a763c0(app, cpu);
    if (cpu.terminate) return;
    // 00a7a42a  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a7a42c  e974000000             -jmp 0xa7a4a5
    goto L_0x00a7a4a5;
L_0x00a7a431:
    // 00a7a431  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x00a7a433:
    // 00a7a433  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a7a435  7405                   -je 0xa7a43c
    if (cpu.flags.zf)
    {
        goto L_0x00a7a43c;
    }
    // 00a7a437  803900                 +cmp byte ptr [ecx], 0
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
    // 00a7a43a  7510                   -jne 0xa7a44c
    if (!cpu.flags.zf)
    {
        goto L_0x00a7a44c;
    }
L_0x00a7a43c:
    // 00a7a43c  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00a7a43e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a7a440  e86b000000             -call 0xa7a4b0
    cpu.esp -= 4;
    sub_a7a4b0(app, cpu);
    if (cpu.terminate) return;
    // 00a7a445  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a7a448  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a449  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a44a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a44b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a7a44c:
    // 00a7a44c  bafce3a700             -mov edx, 0xa7e3fc
    cpu.edx = 11002876 /*0xa7e3fc*/;
    // 00a7a451  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a7a453  e8680f0000             -call 0xa7b3c0
    cpu.esp -= 4;
    sub_a7b3c0(app, cpu);
    if (cpu.terminate) return;
    // 00a7a458  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a7a45a  7528                   -jne 0xa7a484
    if (!cpu.flags.zf)
    {
        goto L_0x00a7a484;
    }
    // 00a7a45c  83fb04                 +cmp ebx, 4
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
    // 00a7a45f  731a                   -jae 0xa7a47b
    if (!cpu.flags.cf)
    {
        goto L_0x00a7a47b;
    }
    // 00a7a461  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a7a463  e80899ffff             -call 0xa73d70
    cpu.esp -= 4;
    sub_a73d70(app, cpu);
    if (cpu.terminate) return;
    // 00a7a468  b80e000000             -mov eax, 0xe
    cpu.eax = 14 /*0xe*/;
    // 00a7a46d  e84ebfffff             -call 0xa763c0
    cpu.esp -= 4;
    sub_a763c0(app, cpu);
    if (cpu.terminate) return;
    // 00a7a472  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a7a474  83c404                 +add esp, 4
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
    // 00a7a477  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a478  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a479  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a47a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a7a47b:
    // 00a7a47b  a1fce3a700             -mov eax, dword ptr [0xa7e3fc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11002876) /* 0xa7e3fc */);
    // 00a7a480  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 00a7a482  eb1f                   -jmp 0xa7a4a3
    goto L_0x00a7a4a3;
L_0x00a7a484:
    // 00a7a484  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a7a486  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a7a487  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a7a488  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a7a489  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a7a48a  2eff15e0bda700         -call dword ptr cs:[0xa7bde0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993120) /* 0xa7bde0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a7a491  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a7a493  750e                   -jne 0xa7a4a3
    if (!cpu.flags.zf)
    {
        goto L_0x00a7a4a3;
    }
    // 00a7a495  e8eadbffff             -call 0xa78084
    cpu.esp -= 4;
    sub_a78084(app, cpu);
    if (cpu.terminate) return;
    // 00a7a49a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a7a49c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a7a49f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a4a0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a4a1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a4a2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a7a4a3:
    // 00a7a4a3  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x00a7a4a5:
    // 00a7a4a5  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a7a4a8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a4a9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a4aa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a4ab  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void sub_a7a4b0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7a4b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a7a4b1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a7a4b2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a7a4b3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a7a4b4  81ec04010000           -sub esp, 0x104
    (cpu.esp) -= x86::reg32(x86::sreg32(260 /*0x104*/));
    // 00a7a4ba  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a7a4bc  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00a7a4be  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a7a4c0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a7a4c1  6804010000             -push 0x104
    app->getMemory<x86::reg32>(cpu.esp-4) = 260 /*0x104*/;
    cpu.esp -= 4;
    // 00a7a4c6  2eff15c4bda700         -call dword ptr cs:[0xa7bdc4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993092) /* 0xa7bdc4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a7a4cd  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a7a4cf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a7a4d1  7509                   -jne 0xa7a4dc
    if (!cpu.flags.zf)
    {
        goto L_0x00a7a4dc;
    }
    // 00a7a4d3  e8acdbffff             -call 0xa78084
    cpu.esp -= 4;
    sub_a78084(app, cpu);
    if (cpu.terminate) return;
    // 00a7a4d8  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a7a4da  eb65                   -jmp 0xa7a541
    goto L_0x00a7a541;
L_0x00a7a4dc:
    // 00a7a4dc  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a7a4de  7529                   -jne 0xa7a509
    if (!cpu.flags.zf)
    {
        goto L_0x00a7a509;
    }
    // 00a7a4e0  40                     -inc eax
    (cpu.eax)++;
    // 00a7a4e1  39c6                   +cmp esi, eax
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
    // 00a7a4e3  7602                   -jbe 0xa7a4e7
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a7a4e7;
    }
    // 00a7a4e5  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x00a7a4e7:
    // 00a7a4e7  e89497ffff             -call 0xa73c80
    cpu.esp -= 4;
    sub_a73c80(app, cpu);
    if (cpu.terminate) return;
    // 00a7a4ec  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a7a4ee  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a7a4f0  7532                   -jne 0xa7a524
    if (!cpu.flags.zf)
    {
        goto L_0x00a7a524;
    }
    // 00a7a4f2  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 00a7a4f7  e8c4beffff             -call 0xa763c0
    cpu.esp -= 4;
    sub_a763c0(app, cpu);
    if (cpu.terminate) return;
    // 00a7a4fc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a7a4fe  81c404010000           -add esp, 0x104
    (cpu.esp) += x86::reg32(x86::sreg32(260 /*0x104*/));
    // 00a7a504  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a505  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a506  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a507  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a508  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a7a509:
    // 00a7a509  39f0                   +cmp eax, esi
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
    // 00a7a50b  7617                   -jbe 0xa7a524
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a7a524;
    }
    // 00a7a50d  b80e000000             -mov eax, 0xe
    cpu.eax = 14 /*0xe*/;
    // 00a7a512  e8a9beffff             -call 0xa763c0
    cpu.esp -= 4;
    sub_a763c0(app, cpu);
    if (cpu.terminate) return;
    // 00a7a517  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a7a519  81c404010000           -add esp, 0x104
    (cpu.esp) += x86::reg32(x86::sreg32(260 /*0x104*/));
    // 00a7a51f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a520  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a521  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a522  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a523  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a7a524:
    // 00a7a524  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00a7a526  41                     -inc ecx
    (cpu.ecx)++;
    // 00a7a527  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00a7a529  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a7a52a  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a7a52c  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a7a52e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a7a52f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a7a531  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a7a534  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a7a536  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a7a538  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a7a53b  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a7a53d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a53e  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a7a53f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x00a7a541:
    // 00a7a541  81c404010000           -add esp, 0x104
    (cpu.esp) += x86::reg32(x86::sreg32(260 /*0x104*/));
    // 00a7a547  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a548  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a549  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a54a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a54b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void sub_a7a550(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7a550  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a7a551  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a7a552  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a7a553  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a7a555  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a7a557  7c08                   -jl 0xa7a561
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a7a561;
    }
    // 00a7a559  3b0570d5a700           +cmp eax, dword ptr [0xa7d570]
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
    // 00a7a55f  7613                   -jbe 0xa7a574
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a7a574;
    }
L_0x00a7a561:
    // 00a7a561  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00a7a566  e855beffff             -call 0xa763c0
    cpu.esp -= 4;
    sub_a763c0(app, cpu);
    if (cpu.terminate) return;
    // 00a7a56b  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a7a570  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a571  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a572  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a573  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a7a574:
    // 00a7a574  8b1588d3a700           -mov edx, dword ptr [0xa7d388]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10998664) /* 0xa7d388 */);
    // 00a7a57a  8b149a                 -mov edx, dword ptr [edx + ebx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + cpu.ebx * 4);
    // 00a7a57d  ff1598d2a700           -call dword ptr [0xa7d298]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10998424) /* 0xa7d298 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a7a583  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00a7a585  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a7a587  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a7a589  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a7a58a  2eff1530bea700         -call dword ptr cs:[0xa7be30]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993200) /* 0xa7be30 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a7a591  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a7a593  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a7a595  ff159cd2a700           -call dword ptr [0xa7d29c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10998428) /* 0xa7d29c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a7a59b  83faff                 +cmp edx, -1
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
    // 00a7a59e  7505                   -jne 0xa7a5a5
    if (!cpu.flags.zf)
    {
        goto L_0x00a7a5a5;
    }
    // 00a7a5a0  e8dfdaffff             -call 0xa78084
    cpu.esp -= 4;
    sub_a78084(app, cpu);
    if (cpu.terminate) return;
L_0x00a7a5a5:
    // 00a7a5a5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a7a5a7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a5a8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a5a9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a5aa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void sub_a7a5b0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7a5b0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a7a5b1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a7a5b2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a7a5b3  2eff159cbda700         -call dword ptr cs:[0xa7bd9c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993052) /* 0xa7bd9c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a7a5ba  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a7a5bc  7508                   -jne 0xa7a5c6
    if (!cpu.flags.zf)
    {
        goto L_0x00a7a5c6;
    }
    // 00a7a5be  e8c1daffff             -call 0xa78084
    cpu.esp -= 4;
    sub_a78084(app, cpu);
    if (cpu.terminate) return;
    // 00a7a5c3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a5c4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a5c5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a7a5c6:
    // 00a7a5c6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a7a5c8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a5c9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a5ca  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void sub_a7a5d0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7a5d0  83e804                 -sub eax, 4
    (cpu.eax) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a7a5d3  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00a7a5d5  24fe                   -and al, 0xfe
    cpu.al &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 00a7a5d7  83e804                 -sub eax, 4
    (cpu.eax) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a7a5da  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void sub_a7a5e0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7a5e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a7a5e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a7a5e2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a7a5e3  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a7a5e6  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a7a5e8  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00a7a5ea  ff15b0d2a700           -call dword ptr [0xa7d2b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10998448) /* 0xa7d2b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a7a5f0  b878d1a700             -mov eax, 0xa7d178
    cpu.eax = 10998136 /*0xa7d178*/;
    // 00a7a5f5  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 00a7a5f7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a7a5f9  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 00a7a5fb  6689d0                 -mov ax, dx
    cpu.ax = cpu.dx;
    // 00a7a5fe  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00a7a600  e817000000             -call 0xa7a61c
    cpu.esp -= 4;
    sub_a7a61c(app, cpu);
    if (cpu.terminate) return;
    // 00a7a605  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a7a607  0f85bb010000           -jne 0xa7a7c8
    if (!cpu.flags.zf)
    {
        return sub_a7a7c8(app, cpu);
    }
    // 00a7a60d  ff15b8d2a700           -call dword ptr [0xa7d2b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10998456) /* 0xa7d2b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a7a613  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a7a615  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a7a618  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a619  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a61a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a61b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a7a61c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7a61c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a7a61d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a7a61e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a7a61f  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a7a622  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00a7a626  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00a7a628  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 00a7a62a  8d430b                 -lea eax, [ebx + 0xb]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(11) /* 0xb */);
    // 00a7a62d  24f8                   -and al, 0xf8
    cpu.al &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 00a7a62f  39d8                   +cmp eax, ebx
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
    // 00a7a631  7307                   -jae 0xa7a63a
    if (!cpu.flags.cf)
    {
        goto L_0x00a7a63a;
    }
    // 00a7a633  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a7a638  eb0a                   -jmp 0xa7a644
    goto L_0x00a7a644;
L_0x00a7a63a:
    // 00a7a63a  83f810                 +cmp eax, 0x10
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
    // 00a7a63d  7305                   -jae 0xa7a644
    if (!cpu.flags.cf)
    {
        goto L_0x00a7a644;
    }
    // 00a7a63f  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
L_0x00a7a644:
    // 00a7a644  8d57fc                 -lea edx, [edi - 4]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(-4) /* -0x4 */);
    // 00a7a647  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00a7a64a  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 00a7a64c  80e2fe                 -and dl, 0xfe
    cpu.dl &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 00a7a64f  39d0                   +cmp eax, edx
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
    // 00a7a651  0f860b010000           -jbe 0xa7a762
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a7a762;
    }
    // 00a7a657  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 00a7a65a  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a7a65c  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
L_0x00a7a65e:
    // 00a7a65e  894500                 -mov dword ptr [ebp], eax
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
    // 00a7a661  8b19                   -mov ebx, dword ptr [ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00a7a663  83fbff                 +cmp ebx, -1
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
    // 00a7a666  750a                   -jne 0xa7a672
    if (!cpu.flags.zf)
    {
        goto L_0x00a7a672;
    }
    // 00a7a668  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 00a7a66d  e94d010000             -jmp 0xa7a7bf
    goto L_0x00a7a7bf;
L_0x00a7a672:
    // 00a7a672  f6c301                 +test bl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 1 /*0x1*/));
    // 00a7a675  0f85d9000000           -jne 0xa7a754
    if (!cpu.flags.zf)
    {
        goto L_0x00a7a754;
    }
    // 00a7a67b  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00a7a67e  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a7a682  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00a7a685  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 00a7a687  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00a7a68b  b878d1a700             -mov eax, 0xa7d178
    cpu.eax = 10998136 /*0xa7d178*/;
    // 00a7a690  663b54240c             +cmp dx, word ptr [esp + 0xc]
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
    // 00a7a695  7521                   -jne 0xa7a6b8
    if (!cpu.flags.zf)
    {
        goto L_0x00a7a6b8;
    }
    // 00a7a697  8b3578d1a700           -mov esi, dword ptr [0xa7d178]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10998136) /* 0xa7d178 */);
    // 00a7a69d  837e0800               +cmp dword ptr [esi + 8], 0
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
    // 00a7a6a1  7415                   -je 0xa7a6b8
    if (cpu.flags.zf)
    {
        goto L_0x00a7a6b8;
    }
L_0x00a7a6a3:
    // 00a7a6a3  39fe                   +cmp esi, edi
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
    // 00a7a6a5  7708                   -ja 0xa7a6af
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a7a6af;
    }
    // 00a7a6a7  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00a7a6a9  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00a7a6ab  39f8                   +cmp eax, edi
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
    // 00a7a6ad  7709                   -ja 0xa7a6b8
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a7a6b8;
    }
L_0x00a7a6af:
    // 00a7a6af  8b7608                 -mov esi, dword ptr [esi + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00a7a6b2  837e0800               +cmp dword ptr [esi + 8], 0
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
    // 00a7a6b6  75eb                   -jne 0xa7a6a3
    if (!cpu.flags.zf)
    {
        goto L_0x00a7a6a3;
    }
L_0x00a7a6b8:
    // 00a7a6b8  8b560c                 -mov edx, dword ptr [esi + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00a7a6bb  39d1                   +cmp ecx, edx
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
    // 00a7a6bd  7506                   -jne 0xa7a6c5
    if (!cpu.flags.zf)
    {
        goto L_0x00a7a6c5;
    }
    // 00a7a6bf  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00a7a6c2  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x00a7a6c5:
    // 00a7a6c5  3b5d00                 +cmp ebx, dword ptr [ebp]
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
    // 00a7a6c8  720c                   -jb 0xa7a6d6
    if (cpu.flags.cf)
    {
        goto L_0x00a7a6d6;
    }
    // 00a7a6ca  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a7a6cc  8b5500                 -mov edx, dword ptr [ebp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp);
    // 00a7a6cf  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a7a6d1  83f810                 +cmp eax, 0x10
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
    // 00a7a6d4  7334                   -jae 0xa7a70a
    if (!cpu.flags.cf)
    {
        goto L_0x00a7a70a;
    }
L_0x00a7a6d6:
    // 00a7a6d6  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a7a6da  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a7a6de  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00a7a6e1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a7a6e3  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a7a6e7  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00a7a6ea  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00a7a6ed  0118                   -add dword ptr [eax], ebx
    (app->getMemory<x86::reg32>(cpu.eax)) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00a7a6ef  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00a7a6f2  48                     -dec eax
    (cpu.eax)--;
    // 00a7a6f3  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 00a7a6f5  89461c                 -mov dword ptr [esi + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00a7a6f8  88154106a800           -mov byte ptr [0xa80641], dl
    app->getMemory<x86::reg8>(x86::reg32(11011649) /* 0xa80641 */) = cpu.dl;
    // 00a7a6fe  8b5500                 -mov edx, dword ptr [ebp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp);
    // 00a7a701  39d3                   +cmp ebx, edx
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
    // 00a7a703  7244                   -jb 0xa7a749
    if (cpu.flags.cf)
    {
        goto L_0x00a7a749;
    }
    // 00a7a705  e9b3000000             -jmp 0xa7a7bd
    goto L_0x00a7a7bd;
L_0x00a7a70a:
    // 00a7a70a  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a7a70c  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 00a7a70e  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a7a712  894104                 -mov dword ptr [ecx + 4], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00a7a715  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a7a719  894108                 -mov dword ptr [ecx + 8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a7a71c  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a7a720  894808                 -mov dword ptr [eax + 8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 00a7a723  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a7a727  894804                 -mov dword ptr [eax + 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00a7a72a  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00a7a72d  8b4500                 -mov eax, dword ptr [ebp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp);
    // 00a7a730  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 00a7a732  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a7a734  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00a7a736  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 00a7a738  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 00a7a73a  88254106a800           -mov byte ptr [0xa80641], ah
    app->getMemory<x86::reg8>(x86::reg32(11011649) /* 0xa80641 */) = cpu.ah;
    // 00a7a740  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a7a742  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a7a745  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a746  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a747  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a748  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a7a749:
    // 00a7a749  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a7a74b  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a7a74d  01d9                   +add ecx, ebx
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
    // 00a7a74f  e90affffff             -jmp 0xa7a65e
    goto L_0x00a7a65e;
L_0x00a7a754:
    // 00a7a754  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00a7a759  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a7a75b  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a7a75e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a75f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a760  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a761  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a7a762:
    // 00a7a762  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00a7a764  83fa10                 +cmp edx, 0x10
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
    // 00a7a767  7254                   -jb 0xa7a7bd
    if (cpu.flags.cf)
    {
        goto L_0x00a7a7bd;
    }
    // 00a7a769  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a7a76b  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 00a7a76e  80cb01                 -or bl, 1
    cpu.bl |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00a7a771  80ca01                 -or dl, 1
    cpu.dl |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00a7a774  8919                   -mov dword ptr [ecx], ebx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.ebx;
    // 00a7a776  8d1c01                 -lea ebx, [ecx + eax]
    cpu.ebx = x86::reg32(cpu.ecx + cpu.eax * 1);
    // 00a7a779  b878d1a700             -mov eax, 0xa7d178
    cpu.eax = 10998136 /*0xa7d178*/;
    // 00a7a77e  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 00a7a781  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 00a7a783  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 00a7a785  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a7a789  6639da                 +cmp dx, bx
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
    // 00a7a78c  7521                   -jne 0xa7a7af
    if (!cpu.flags.zf)
    {
        goto L_0x00a7a7af;
    }
    // 00a7a78e  8b3578d1a700           -mov esi, dword ptr [0xa7d178]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10998136) /* 0xa7d178 */);
    // 00a7a794  837e0800               +cmp dword ptr [esi + 8], 0
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
    // 00a7a798  7415                   -je 0xa7a7af
    if (cpu.flags.zf)
    {
        goto L_0x00a7a7af;
    }
L_0x00a7a79a:
    // 00a7a79a  39fe                   +cmp esi, edi
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
    // 00a7a79c  7708                   -ja 0xa7a7a6
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a7a7a6;
    }
    // 00a7a79e  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00a7a7a0  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00a7a7a2  39f8                   +cmp eax, edi
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
    // 00a7a7a4  7709                   -ja 0xa7a7af
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a7a7af;
    }
L_0x00a7a7a6:
    // 00a7a7a6  8b7608                 -mov esi, dword ptr [esi + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00a7a7a9  837e0800               +cmp dword ptr [esi + 8], 0
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
    // 00a7a7ad  75eb                   -jne 0xa7a79a
    if (!cpu.flags.zf)
    {
        goto L_0x00a7a79a;
    }
L_0x00a7a7af:
    // 00a7a7af  ff4618                 -inc dword ptr [esi + 0x18]
    (app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */))++;
    // 00a7a7b2  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00a7a7b5  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a7a7b8  e8b395ffff             -call 0xa73d70
    cpu.esp -= 4;
    sub_a73d70(app, cpu);
    if (cpu.terminate) return;
L_0x00a7a7bd:
    // 00a7a7bd  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00a7a7bf:
    // 00a7a7bf  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a7a7c1  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a7a7c4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a7c5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a7c6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a7c7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a7a7c8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7a7c8  ff15b8d2a700           -call dword ptr [0xa7d2b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10998456) /* 0xa7d2b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a7a7ce  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a7a7d0  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a7a7d3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a7d4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a7d5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a7d6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a7a7e0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7a7e0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a7a7e2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a7a7e4(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7a7e4  ff1570d7a700           -call dword ptr [0xa7d770]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10999664) /* 0xa7d770 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a7a7ea  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a7a7ec(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7a7ec  ff1574d7a700           -call dword ptr [0xa7d774]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10999668) /* 0xa7d774 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a7a7f2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a7a7f4(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7a7f4  ff1578d7a700           -call dword ptr [0xa7d778]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10999672) /* 0xa7d778 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a7a7fa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a7a7fc(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7a7fc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a7a7fd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a7a7fe  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a7a800  7410                   -je 0xa7a812
    if (cpu.flags.zf)
    {
        goto L_0x00a7a812;
    }
    // 00a7a802  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00a7a804  8b3570d7a700           -mov esi, dword ptr [0xa7d770]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10999664) /* 0xa7d770 */);
    // 00a7a80a  890d70d7a700           -mov dword ptr [0xa7d770], ecx
    app->getMemory<x86::reg32>(x86::reg32(10999664) /* 0xa7d770 */) = cpu.ecx;
    // 00a7a810  8930                   -mov dword ptr [eax], esi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.esi;
L_0x00a7a812:
    // 00a7a812  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a7a814  740f                   -je 0xa7a825
    if (cpu.flags.zf)
    {
        goto L_0x00a7a825;
    }
    // 00a7a816  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00a7a818  8b0d74d7a700           -mov ecx, dword ptr [0xa7d774]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10999668) /* 0xa7d774 */);
    // 00a7a81e  a374d7a700             -mov dword ptr [0xa7d774], eax
    app->getMemory<x86::reg32>(x86::reg32(10999668) /* 0xa7d774 */) = cpu.eax;
    // 00a7a823  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
L_0x00a7a825:
    // 00a7a825  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a7a827  740f                   -je 0xa7a838
    if (cpu.flags.zf)
    {
        goto L_0x00a7a838;
    }
    // 00a7a829  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 00a7a82b  8b1578d7a700           -mov edx, dword ptr [0xa7d778]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10999672) /* 0xa7d778 */);
    // 00a7a831  a378d7a700             -mov dword ptr [0xa7d778], eax
    app->getMemory<x86::reg32>(x86::reg32(10999672) /* 0xa7d778 */) = cpu.eax;
    // 00a7a836  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
L_0x00a7a838:
    // 00a7a838  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a839  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a83a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void sub_a7a840(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7a840  ff157cd7a700           -call dword ptr [0xa7d77c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10999676) /* 0xa7d77c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a7a846  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
    // 00a7a848  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a7a849  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
    // 00a7a84e  b800e4a700             -mov eax, 0xa7e400
    cpu.eax = 11002880 /*0xa7e400*/;
    // 00a7a853  e844b7ffff             -call 0xa75f9c
    cpu.esp -= 4;
    sub_a75f9c(app, cpu);
    if (cpu.terminate) return;
    // 00a7a858  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a859  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a7a848(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a7a848;
    // 00a7a840  ff157cd7a700           -call dword ptr [0xa7d77c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10999676) /* 0xa7d77c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a7a846  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_entry_0x00a7a848:
    // 00a7a848  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a7a849  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
    // 00a7a84e  b800e4a700             -mov eax, 0xa7e400
    cpu.eax = 11002880 /*0xa7e400*/;
    // 00a7a853  e844b7ffff             -call 0xa75f9c
    cpu.esp -= 4;
    sub_a75f9c(app, cpu);
    if (cpu.terminate) return;
    // 00a7a858  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a859  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a7a860(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7a860  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a7a861  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a7a862  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a7a863  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a7a864  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a7a867  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a7a869  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a7a86b  8a2588d1a700           -mov ah, byte ptr [0xa7d188]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(10998152) /* 0xa7d188 */);
    // 00a7a871  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 00a7a874  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 00a7a876  7426                   -je 0xa7a89e
    if (cpu.flags.zf)
    {
        goto L_0x00a7a89e;
    }
    // 00a7a878  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00a7a87a  36d93f                 -fnstcw word ptr ss:[edi]
    app->getMemory<x86::reg16>(cpu.ess + cpu.edi) = cpu.fpu.control.word;
    // 00a7a87d  9b                     -wait 
    /*nothing*/;
    // 00a7a87e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a7a880  741c                   -je 0xa7a89e
    if (cpu.flags.zf)
    {
        goto L_0x00a7a89e;
    }
    // 00a7a882  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a7a884  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 00a7a887  f7d0                   -not eax
    cpu.eax = ~cpu.eax;
    // 00a7a889  21da                   -and edx, ebx
    cpu.edx &= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a7a88b  21f0                   -and eax, esi
    cpu.eax &= x86::reg32(x86::sreg32(cpu.esi));
    // 00a7a88d  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 00a7a88f  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00a7a891  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00a7a894  36d92f                 -fldcw word ptr ss:[edi]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.ess + cpu.edi);
    // 00a7a897  9b                     -wait 
    /*nothing*/;
    // 00a7a898  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00a7a89a  36d93f                 -fnstcw word ptr ss:[edi]
    app->getMemory<x86::reg16>(cpu.ess + cpu.edi) = cpu.fpu.control.word;
    // 00a7a89d  9b                     -wait 
    /*nothing*/;
L_0x00a7a89e:
    // 00a7a89e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a7a8a0  668b0424               -mov ax, word ptr [esp]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp);
    // 00a7a8a4  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a7a8a7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a8a8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a8a9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a8aa  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a8ab  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a7a8ac(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7a8ac  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a7a8ad  668b5008               -mov dx, word ptr [eax + 8]
    cpu.dx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a7a8b1  80e67f                 -and dh, 0x7f
    cpu.dh &= x86::reg8(x86::sreg8(127 /*0x7f*/));
    // 00a7a8b4  6681faff7f             +cmp dx, 0x7fff
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
    // 00a7a8b9  751c                   -jne 0xa7a8d7
    if (!cpu.flags.zf)
    {
        goto L_0x00a7a8d7;
    }
    // 00a7a8bb  81780400000080         +cmp dword ptr [eax + 4], 0x80000000
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
    // 00a7a8c2  750c                   -jne 0xa7a8d0
    if (!cpu.flags.zf)
    {
        goto L_0x00a7a8d0;
    }
    // 00a7a8c4  833800                 +cmp dword ptr [eax], 0
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
    // 00a7a8c7  7507                   -jne 0xa7a8d0
    if (!cpu.flags.zf)
    {
        goto L_0x00a7a8d0;
    }
    // 00a7a8c9  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 00a7a8ce  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a8cf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a7a8d0:
    // 00a7a8d0  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00a7a8d5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a8d6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a7a8d7:
    // 00a7a8d7  66f74008ff7f           +test word ptr [eax + 8], 0x7fff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(app->getMemory<x86::reg16>(cpu.eax + x86::reg32(8) /* 0x8 */) & 32767 /*0x7fff*/));
    // 00a7a8dd  7516                   -jne 0xa7a8f5
    if (!cpu.flags.zf)
    {
        goto L_0x00a7a8f5;
    }
    // 00a7a8df  83780400               +cmp dword ptr [eax + 4], 0
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
    // 00a7a8e3  7509                   -jne 0xa7a8ee
    if (!cpu.flags.zf)
    {
        goto L_0x00a7a8ee;
    }
    // 00a7a8e5  833800                 +cmp dword ptr [eax], 0
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
    // 00a7a8e8  7504                   -jne 0xa7a8ee
    if (!cpu.flags.zf)
    {
        goto L_0x00a7a8ee;
    }
    // 00a7a8ea  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a7a8ec  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a8ed  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a7a8ee:
    // 00a7a8ee  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00a7a8f3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a8f4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a7a8f5:
    // 00a7a8f5  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a7a8fa  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a8fb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a7a8fc(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7a8fc  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a7a8fd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a7a8fe  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a7a8ff  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a7a900  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a7a901  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a7a902  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a7a904  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a7a906  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a7a908  29ed                   -sub ebp, ebp
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00a7a90a  29c0                   -sub eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax));
L_0x00a7a90c:
    // 00a7a90c  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00a7a90e  3c00                   +cmp al, 0
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
    // 00a7a910  742f                   -je 0xa7a941
    if (cpu.flags.zf)
    {
        goto L_0x00a7a941;
    }
    // 00a7a912  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00a7a914  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00a7a916  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a7a918  01ed                   +add ebp, ebp
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
    // 00a7a91a  11c9                   +adc ecx, ecx
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
    // 00a7a91c  11d2                   -adc edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00a7a91e  01ed                   +add ebp, ebp
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
    // 00a7a920  11c9                   +adc ecx, ecx
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
    // 00a7a922  11d2                   -adc edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00a7a924  01c5                   +add ebp, eax
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
    // 00a7a926  11d9                   +adc ecx, ebx
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
    // 00a7a928  11fa                   -adc edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi) + cpu.flags.cf);
    // 00a7a92a  01ed                   +add ebp, ebp
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
    // 00a7a92c  11c9                   +adc ecx, ecx
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
    // 00a7a92e  11d2                   -adc edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00a7a930  29c0                   -sub eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00a7a932  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00a7a934  240f                   -and al, 0xf
    cpu.al &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 00a7a936  01c5                   +add ebp, eax
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
    // 00a7a938  83d100                 +adc ecx, 0
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
    // 00a7a93b  83d200                 +adc edx, 0
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
    // 00a7a93e  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a7a93f  ebcb                   -jmp 0xa7a90c
    goto L_0x00a7a90c;
L_0x00a7a941:
    // 00a7a941  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a7a943  bf5e400000             -mov edi, 0x405e
    cpu.edi = 16478 /*0x405e*/;
    // 00a7a948  e811000000             -call 0xa7a95e
    cpu.esp -= 4;
    sub_a7a95e(app, cpu);
    if (cpu.terminate) return;
    // 00a7a94d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a94e  895504                 -mov dword ptr [ebp + 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00a7a951  894500                 -mov dword ptr [ebp], eax
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
    // 00a7a954  66897508               -mov word ptr [ebp + 8], si
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.si;
    // 00a7a958  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a959  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a95a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a95b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a95c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7a95d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a7a95e(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7a95e  29f6                   -sub esi, esi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00a7a960  09c6                   -or esi, eax
    cpu.esi |= x86::reg32(x86::sreg32(cpu.eax));
    // 00a7a962  09d6                   -or esi, edx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.edx));
    // 00a7a964  09ee                   +or esi, ebp
    cpu.clear_co();
    cpu.set_szp((cpu.esi |= x86::reg32(x86::sreg32(cpu.ebp))));
    // 00a7a966  7436                   -je 0xa7a99e
    if (cpu.flags.zf)
    {
        goto L_0x00a7a99e;
    }
    // 00a7a968  09d2                   +or edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx |= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a7a96a  7509                   -jne 0xa7a975
    if (!cpu.flags.zf)
    {
        goto L_0x00a7a975;
    }
    // 00a7a96c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a7a96e  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a7a970  29ed                   -sub ebp, ebp
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00a7a972  83ef20                 -sub edi, 0x20
    (cpu.edi) -= x86::reg32(x86::sreg32(32 /*0x20*/));
L_0x00a7a975:
    // 00a7a975  09d2                   +or edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx |= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a7a977  7509                   -jne 0xa7a982
    if (!cpu.flags.zf)
    {
        goto L_0x00a7a982;
    }
    // 00a7a979  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a7a97b  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a7a97d  29ed                   -sub ebp, ebp
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00a7a97f  83ef20                 -sub edi, 0x20
    (cpu.edi) -= x86::reg32(x86::sreg32(32 /*0x20*/));
L_0x00a7a982:
    // 00a7a982  09d2                   +or edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx |= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a7a984  7809                   -js 0xa7a98f
    if (cpu.flags.sf)
    {
        goto L_0x00a7a98f;
    }
    // 00a7a986  4f                     -dec edi
    (cpu.edi)--;
    // 00a7a987  01ed                   +add ebp, ebp
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
    // 00a7a989  11c0                   +adc eax, eax
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
    // 00a7a98b  11d2                   +adc edx, edx
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
    // 00a7a98d  ebf3                   -jmp 0xa7a982
    goto L_0x00a7a982;
L_0x00a7a98f:
    // 00a7a98f  01ed                   +add ebp, ebp
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
    // 00a7a991  83d000                 +adc eax, 0
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
    // 00a7a994  83d200                 +adc edx, 0
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
    // 00a7a997  7303                   -jae 0xa7a99c
    if (!cpu.flags.cf)
    {
        goto L_0x00a7a99c;
    }
    // 00a7a999  d1da                   -rcr edx, 1
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
    // 00a7a99b  47                     -inc edi
    (cpu.edi)++;
L_0x00a7a99c:
    // 00a7a99c  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
L_0x00a7a99e:
    // 00a7a99e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void sub_a7a9a0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7a9a0  83f841                 +cmp eax, 0x41
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
    // 00a7a9a3  7c08                   -jl 0xa7a9ad
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a7a9ad;
    }
    // 00a7a9a5  83f85a                 +cmp eax, 0x5a
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
    // 00a7a9a8  7f03                   -jg 0xa7a9ad
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a7a9ad;
    }
    // 00a7a9aa  83c020                 -add eax, 0x20
    (cpu.eax) += x86::reg32(x86::sreg32(32 /*0x20*/));
L_0x00a7a9ad:
    // 00a7a9ad  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void sub_a7a9b0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7a9b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a7a9b1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a7a9b2  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a7a9b5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a7a9b7  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00a7a9b9  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00a7a9bb  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a7a9bd  e8aef5ffff             -call 0xa79f70
    cpu.esp -= 4;
    sub_a79f70(app, cpu);
    if (cpu.terminate) return;
    // 00a7a9c2  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a7a9c4  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 00a7a9c6  e885d1ffff             -call 0xa77b50
    cpu.esp -= 4;
    sub_a77b50(app, cpu);
    if (cpu.terminate) return;
    // 00a7a9cb  881404                 -mov byte ptr [esp + eax], dl
    app->getMemory<x86::reg8>(cpu.esp + cpu.eax * 1) = cpu.dl;
L_0x00a7a9ce:
    // 00a7a9ce  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a7a9d0  e80bb3ffff             -call 0xa75ce0
    cpu.esp -= 4;
    sub_a75ce0(app, cpu);
    if (cpu.terminate) return;
    // 00a7a9d5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a7a9d7  7518                   -jne 0xa7a9f1
    if (!cpu.flags.zf)
    {
        goto L_0x00a7a9f1;
    }
    // 00a7a9d9  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00a7a9db  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a7a9dd  e8eed1ffff             -call 0xa77bd0
    cpu.esp -= 4;
    sub_a77bd0(app, cpu);
    if (cpu.terminate) return;
    // 00a7a9e2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a7a9e4  740b                   -je 0xa7a9f1
    if (cpu.flags.zf)
    {
        goto L_0x00a7a9f1;
    }
    // 00a7a9e6  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a7a9e8  e893b3ffff             -call 0xa75d80
    cpu.esp -= 4;
    sub_a75d80(app, cpu);
    if (cpu.terminate) return;
    // 00a7a9ed  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a7a9ef  ebdd                   -jmp 0xa7a9ce
    goto L_0x00a7a9ce;
L_0x00a7a9f1:
    // 00a7a9f1  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a7a9f3  e8e8b2ffff             -call 0xa75ce0
    cpu.esp -= 4;
    sub_a75ce0(app, cpu);
    if (cpu.terminate) return;
    // 00a7a9f8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a7a9fa  7404                   -je 0xa7aa00
    if (cpu.flags.zf)
    {
        goto L_0x00a7aa00;
    }
    // 00a7a9fc  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a7a9fe  7504                   -jne 0xa7aa04
    if (!cpu.flags.zf)
    {
        goto L_0x00a7aa04;
    }
L_0x00a7aa00:
    // 00a7aa00  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a7aa02  eb02                   -jmp 0xa7aa06
    goto L_0x00a7aa06;
L_0x00a7aa04:
    // 00a7aa04  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00a7aa06:
    // 00a7aa06  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a7aa09  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7aa0a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7aa0b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void sub_a7aa10(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7aa10  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a7aa11  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a7aa12  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a7aa14  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00a7aa16:
    // 00a7aa16  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a7aa18  e8c3b2ffff             -call 0xa75ce0
    cpu.esp -= 4;
    sub_a75ce0(app, cpu);
    if (cpu.terminate) return;
    // 00a7aa1d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a7aa1f  750c                   -jne 0xa7aa2d
    if (!cpu.flags.zf)
    {
        goto L_0x00a7aa2d;
    }
    // 00a7aa21  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a7aa23  e858b3ffff             -call 0xa75d80
    cpu.esp -= 4;
    sub_a75d80(app, cpu);
    if (cpu.terminate) return;
    // 00a7aa28  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a7aa29  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a7aa2b  ebe9                   -jmp 0xa7aa16
    goto L_0x00a7aa16;
L_0x00a7aa2d:
    // 00a7aa2d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a7aa2f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7aa30  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7aa31  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a7aa40(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7aa40  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a7aa41  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a7aa42  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a7aa43  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a7aa44  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a7aa46  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00a7aa48  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 00a7aa4a  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00a7aa4c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a7aa4e  7438                   -je 0xa7aa88
    if (cpu.flags.zf)
    {
        goto L_0x00a7aa88;
    }
L_0x00a7aa50:
    // 00a7aa50  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00a7aa52  765a                   -jbe 0xa7aaae
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a7aaae;
    }
    // 00a7aa54  803900                 +cmp byte ptr [ecx], 0
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
    // 00a7aa57  7418                   -je 0xa7aa71
    if (cpu.flags.zf)
    {
        goto L_0x00a7aa71;
    }
    // 00a7aa59  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 00a7aa5e  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a7aa60  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a7aa62  e8490b0000             -call 0xa7b5b0
    cpu.esp -= 4;
    sub_a7b5b0(app, cpu);
    if (cpu.terminate) return;
    // 00a7aa67  83f8ff                 +cmp eax, -1
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
    // 00a7aa6a  750c                   -jne 0xa7aa78
    if (!cpu.flags.zf)
    {
        goto L_0x00a7aa78;
    }
    // 00a7aa6c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7aa6d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7aa6e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7aa6f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7aa70  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a7aa71:
    // 00a7aa71  66c7060000             -mov word ptr [esi], 0
    app->getMemory<x86::reg16>(cpu.esi) = 0 /*0x0*/;
    // 00a7aa76  eb36                   -jmp 0xa7aaae
    goto L_0x00a7aaae;
L_0x00a7aa78:
    // 00a7aa78  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a7aa7a  4d                     -dec ebp
    (cpu.ebp)--;
    // 00a7aa7b  e800b3ffff             -call 0xa75d80
    cpu.esp -= 4;
    sub_a75d80(app, cpu);
    if (cpu.terminate) return;
    // 00a7aa80  83c602                 +add esi, 2
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
    // 00a7aa83  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a7aa84  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a7aa86  ebc8                   -jmp 0xa7aa50
    goto L_0x00a7aa50;
L_0x00a7aa88:
    // 00a7aa88  be02000000             -mov esi, 2
    cpu.esi = 2 /*0x2*/;
L_0x00a7aa8d:
    // 00a7aa8d  803900                 +cmp byte ptr [ecx], 0
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
    // 00a7aa90  741c                   -je 0xa7aaae
    if (cpu.flags.zf)
    {
        goto L_0x00a7aaae;
    }
    // 00a7aa92  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00a7aa94  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a7aa96  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a7aa98  e8130b0000             -call 0xa7b5b0
    cpu.esp -= 4;
    sub_a7b5b0(app, cpu);
    if (cpu.terminate) return;
    // 00a7aa9d  83f8ff                 +cmp eax, -1
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
    // 00a7aaa0  740e                   -je 0xa7aab0
    if (cpu.flags.zf)
    {
        goto L_0x00a7aab0;
    }
    // 00a7aaa2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a7aaa4  e8d7b2ffff             -call 0xa75d80
    cpu.esp -= 4;
    sub_a75d80(app, cpu);
    if (cpu.terminate) return;
    // 00a7aaa9  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a7aaaa  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a7aaac  ebdf                   -jmp 0xa7aa8d
    goto L_0x00a7aa8d;
L_0x00a7aaae:
    // 00a7aaae  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x00a7aab0:
    // 00a7aab0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7aab1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7aab2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7aab3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7aab4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a7aac0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7aac0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a7aac1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a7aac2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a7aac3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a7aac4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a7aac5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a7aac6  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a7aac9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a7aacb  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00a7aad0  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00a7aad4  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00a7aad7  ba3d000000             -mov edx, 0x3d
    cpu.edx = 61 /*0x3d*/;
    // 00a7aadc  e86f0b0000             -call 0xa7b650
    cpu.esp -= 4;
    sub_a7b650(app, cpu);
    if (cpu.terminate) return;
    // 00a7aae1  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a7aae3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a7aae5  750a                   -jne 0xa7aaf1
    if (!cpu.flags.zf)
    {
        goto L_0x00a7aaf1;
    }
    // 00a7aae7  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a7aaec  e95a010000             -jmp 0xa7ac4b
    goto L_0x00a7ac4b;
L_0x00a7aaf1:
    // 00a7aaf1  39c8                   +cmp eax, ecx
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
    // 00a7aaf3  750f                   -jne 0xa7ab04
    if (!cpu.flags.zf)
    {
        goto L_0x00a7ab04;
    }
    // 00a7aaf5  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a7aafa  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a7aafd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7aafe  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7aaff  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7ab00  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7ab01  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7ab02  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7ab03  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a7ab04:
    // 00a7ab04  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a7ab06  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00a7ab08  8d2c4500000000         -lea ebp, [eax*2]
    cpu.ebp = x86::reg32(cpu.eax * 2);
    // 00a7ab0f  8d4502                 -lea eax, [ebp + 2]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(2) /* 0x2 */);
    // 00a7ab12  e86991ffff             -call 0xa73c80
    cpu.esp -= 4;
    sub_a73c80(app, cpu);
    if (cpu.terminate) return;
    // 00a7ab17  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a7ab19  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a7ab1d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a7ab1f  750f                   -jne 0xa7ab30
    if (!cpu.flags.zf)
    {
        goto L_0x00a7ab30;
    }
    // 00a7ab21  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a7ab26  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a7ab29  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7ab2a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7ab2b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7ab2c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7ab2d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7ab2e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7ab2f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a7ab30:
    // 00a7ab30  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 00a7ab32  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a7ab34  e8b7d8ffff             -call 0xa783f0
    cpu.esp -= 4;
    sub_a783f0(app, cpu);
    if (cpu.terminate) return;
    // 00a7ab39  8d5702                 -lea edx, [edi + 2]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 00a7ab3c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a7ab3e  66c7042e0000           -mov word ptr [esi + ebp], 0
    app->getMemory<x86::reg16>(cpu.esi + cpu.ebp * 1) = 0 /*0x0*/;
    // 00a7ab44  e887d8ffff             -call 0xa783d0
    cpu.esp -= 4;
    sub_a783d0(app, cpu);
    if (cpu.terminate) return;
    // 00a7ab49  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a7ab4b  7442                   -je 0xa7ab8f
    if (cpu.flags.zf)
    {
        goto L_0x00a7ab8f;
    }
    // 00a7ab4d  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 00a7ab4f  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00a7ab53  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a7ab56  e82591ffff             -call 0xa73c80
    cpu.esp -= 4;
    sub_a73c80(app, cpu);
    if (cpu.terminate) return;
    // 00a7ab5b  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a7ab5d  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a7ab5f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a7ab61  7516                   -jne 0xa7ab79
    if (!cpu.flags.zf)
    {
        goto L_0x00a7ab79;
    }
    // 00a7ab63  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a7ab65  e80692ffff             -call 0xa73d70
    cpu.esp -= 4;
    sub_a73d70(app, cpu);
    if (cpu.terminate) return;
    // 00a7ab6a  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a7ab6f  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a7ab72  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7ab73  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7ab74  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7ab75  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7ab76  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7ab77  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7ab78  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a7ab79:
    // 00a7ab79  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a7ab7d  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a7ab81  01f7                   +add edi, esi
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
    // 00a7ab83  e868d8ffff             -call 0xa783f0
    cpu.esp -= 4;
    sub_a783f0(app, cpu);
    if (cpu.terminate) return;
    // 00a7ab88  66c7070000             -mov word ptr [edi], 0
    app->getMemory<x86::reg16>(cpu.edi) = 0 /*0x0*/;
    // 00a7ab8d  eb02                   -jmp 0xa7ab91
    goto L_0x00a7ab91;
L_0x00a7ab8f:
    // 00a7ab8f  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
L_0x00a7ab91:
    // 00a7ab91  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a7ab95  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00a7ab97  e8e40a0000             -call 0xa7b680
    cpu.esp -= 4;
    sub_a7b680(app, cpu);
    if (cpu.terminate) return;
    // 00a7ab9c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a7ab9e  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a7aba2  e8c991ffff             -call 0xa73d70
    cpu.esp -= 4;
    sub_a73d70(app, cpu);
    if (cpu.terminate) return;
    // 00a7aba7  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a7aba9  e8c291ffff             -call 0xa73d70
    cpu.esp -= 4;
    sub_a73d70(app, cpu);
    if (cpu.terminate) return;
    // 00a7abae  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a7abb0  750f                   -jne 0xa7abc1
    if (!cpu.flags.zf)
    {
        goto L_0x00a7abc1;
    }
    // 00a7abb2  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a7abb7  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a7abba  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7abbb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7abbc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7abbd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7abbe  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7abbf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7abc0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a7abc1:
    // 00a7abc1  833d0800a80000         +cmp dword ptr [0xa80008], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11010056) /* 0xa80008 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a7abc8  7505                   -jne 0xa7abcf
    if (!cpu.flags.zf)
    {
        goto L_0x00a7abcf;
    }
    // 00a7abca  e8b10b0000             -call 0xa7b780
    cpu.esp -= 4;
    sub_a7b780(app, cpu);
    if (cpu.terminate) return;
L_0x00a7abcf:
    // 00a7abcf  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a7abd1  e882000000             -call 0xa7ac58
    cpu.esp -= 4;
    sub_a7ac58(app, cpu);
    if (cpu.terminate) return;
    // 00a7abd6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a7abd8  740f                   -je 0xa7abe9
    if (cpu.flags.zf)
    {
        goto L_0x00a7abe9;
    }
    // 00a7abda  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a7abdf  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a7abe2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7abe3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7abe4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7abe5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7abe6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7abe7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7abe8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a7abe9:
    // 00a7abe9  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a7abeb  e8e0d7ffff             -call 0xa783d0
    cpu.esp -= 4;
    sub_a783d0(app, cpu);
    if (cpu.terminate) return;
    // 00a7abf0  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a7abf3  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a7abf7  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 00a7abfa  e88190ffff             -call 0xa73c80
    cpu.esp -= 4;
    sub_a73c80(app, cpu);
    if (cpu.terminate) return;
    // 00a7abff  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a7ac01  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a7ac03  7519                   -jne 0xa7ac1e
    if (!cpu.flags.zf)
    {
        goto L_0x00a7ac1e;
    }
    // 00a7ac05  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 00a7ac0a  e80dd4ffff             -call 0xa7801c
    cpu.esp -= 4;
    sub_a7801c(app, cpu);
    if (cpu.terminate) return;
    // 00a7ac0f  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a7ac14  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a7ac17  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7ac18  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7ac19  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7ac1a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7ac1b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7ac1c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7ac1d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a7ac1e:
    // 00a7ac1e  0faf1c24               -imul ebx, dword ptr [esp]
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 00a7ac22  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a7ac24  e8b70b0000             -call 0xa7b7e0
    cpu.esp -= 4;
    sub_a7b7e0(app, cpu);
    if (cpu.terminate) return;
    // 00a7ac29  83f8ff                 +cmp eax, -1
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
    // 00a7ac2c  7516                   -jne 0xa7ac44
    if (!cpu.flags.zf)
    {
        goto L_0x00a7ac44;
    }
    // 00a7ac2e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a7ac30  e83b91ffff             -call 0xa73d70
    cpu.esp -= 4;
    sub_a73d70(app, cpu);
    if (cpu.terminate) return;
    // 00a7ac35  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a7ac3a  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a7ac3d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7ac3e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7ac3f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7ac40  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7ac41  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7ac42  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7ac43  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a7ac44:
    // 00a7ac44  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a7ac46  e8c1efffff             -call 0xa79c0c
    cpu.esp -= 4;
    sub_a79c0c(app, cpu);
    if (cpu.terminate) return;
L_0x00a7ac4b:
    // 00a7ac4b  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a7ac4e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7ac4f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7ac50  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7ac51  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7ac52  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7ac53  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7ac54  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a7ac58(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7ac58  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a7ac59  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a7ac5a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a7ac5b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a7ac5c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a7ac5d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a7ac5e  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a7ac61  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a7ac63  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a7ac65  750a                   -jne 0xa7ac71
    if (!cpu.flags.zf)
    {
        goto L_0x00a7ac71;
    }
    // 00a7ac67  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a7ac6c  e963010000             -jmp 0xa7add4
    goto L_0x00a7add4;
L_0x00a7ac71:
    // 00a7ac71  66833800               +cmp word ptr [eax], 0
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
    // 00a7ac75  741b                   -je 0xa7ac92
    if (cpu.flags.zf)
    {
        goto L_0x00a7ac92;
    }
    // 00a7ac77  8d5002                 -lea edx, [eax + 2]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00a7ac7a  66833a00               +cmp word ptr [edx], 0
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
    // 00a7ac7e  7412                   -je 0xa7ac92
    if (cpu.flags.zf)
    {
        goto L_0x00a7ac92;
    }
L_0x00a7ac80:
    // 00a7ac80  66833a3d               +cmp word ptr [edx], 0x3d
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
    // 00a7ac84  740c                   -je 0xa7ac92
    if (cpu.flags.zf)
    {
        goto L_0x00a7ac92;
    }
    // 00a7ac86  668b7202               -mov si, word ptr [edx + 2]
    cpu.si = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 00a7ac8a  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a7ac8d  6685f6                 +test si, si
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.si & cpu.si));
    // 00a7ac90  75ee                   -jne 0xa7ac80
    if (!cpu.flags.zf)
    {
        goto L_0x00a7ac80;
    }
L_0x00a7ac92:
    // 00a7ac92  66833a00               +cmp word ptr [edx], 0
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
    // 00a7ac96  750f                   -jne 0xa7aca7
    if (!cpu.flags.zf)
    {
        goto L_0x00a7aca7;
    }
    // 00a7ac98  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a7ac9d  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a7aca0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7aca1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7aca2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7aca3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7aca4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7aca5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7aca6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a7aca7:
    // 00a7aca7  66837a0200             +cmp word ptr [edx + 2], 0
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
    // 00a7acac  0f94c0                 -sete al
    cpu.al = cpu.flags.zf;
    // 00a7acaf  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a7acb1  8b0d0800a800           -mov ecx, dword ptr [0xa80008]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11010056) /* 0xa80008 */);
    // 00a7acb7  88c3                   -mov bl, al
    cpu.bl = cpu.al;
    // 00a7acb9  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a7acbb  7541                   -jne 0xa7acfe
    if (!cpu.flags.zf)
    {
        goto L_0x00a7acfe;
    }
    // 00a7acbd  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a7acbf  0f850d010000           -jne 0xa7add2
    if (!cpu.flags.zf)
    {
        goto L_0x00a7add2;
    }
    // 00a7acc5  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 00a7acca  e8b18fffff             -call 0xa73c80
    cpu.esp -= 4;
    sub_a73c80(app, cpu);
    if (cpu.terminate) return;
    // 00a7accf  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a7acd1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a7acd3  750f                   -jne 0xa7ace4
    if (!cpu.flags.zf)
    {
        goto L_0x00a7ace4;
    }
    // 00a7acd5  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a7acda  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a7acdd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7acde  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7acdf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7ace0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7ace1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7ace2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7ace3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a7ace4:
    // 00a7ace4  a30800a800             -mov dword ptr [0xa80008], eax
    app->getMemory<x86::reg32>(x86::reg32(11010056) /* 0xa80008 */) = cpu.eax;
    // 00a7ace9  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a7acec  8958f8                 -mov dword ptr [eax - 8], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-8) /* -0x8 */) = cpu.ebx;
    // 00a7acef  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 00a7acf1  8958fc                 -mov dword ptr [eax - 4], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 00a7acf4  a30000a800             -mov dword ptr [0xa80000], eax
    app->getMemory<x86::reg32>(x86::reg32(11010048) /* 0xa80000 */) = cpu.eax;
    // 00a7acf9  e9c8000000             -jmp 0xa7adc6
    goto L_0x00a7adc6;
L_0x00a7acfe:
    // 00a7acfe  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00a7ad00  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a7ad02  e8d9000000             -call 0xa7ade0
    cpu.esp -= 4;
    sub_a7ade0(app, cpu);
    if (cpu.terminate) return;
    // 00a7ad07  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a7ad09  0f85c3000000           -jne 0xa7add2
    if (!cpu.flags.zf)
    {
        goto L_0x00a7add2;
    }
    // 00a7ad0f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a7ad11  0f8fac000000           -jg 0xa7adc3
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a7adc3;
    }
    // 00a7ad17  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 00a7ad19  8b2d0000a800           -mov ebp, dword ptr [0xa80000]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(11010048) /* 0xa80000 */);
    // 00a7ad1f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a7ad21  40                     -inc eax
    (cpu.eax)++;
    // 00a7ad22  8d1cb500000000         -lea ebx, [esi*4]
    cpu.ebx = x86::reg32(cpu.esi * 4);
    // 00a7ad29  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00a7ad2c  8d4308                 -lea eax, [ebx + 8]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00a7ad2f  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00a7ad32  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00a7ad36  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a7ad38  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00a7ad3a  753e                   -jne 0xa7ad7a
    if (!cpu.flags.zf)
    {
        goto L_0x00a7ad7a;
    }
    // 00a7ad3c  e83f8fffff             -call 0xa73c80
    cpu.esp -= 4;
    sub_a73c80(app, cpu);
    if (cpu.terminate) return;
    // 00a7ad41  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a7ad43  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a7ad45  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a7ad47  750f                   -jne 0xa7ad58
    if (!cpu.flags.zf)
    {
        goto L_0x00a7ad58;
    }
    // 00a7ad49  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a7ad4e  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a7ad51  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7ad52  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7ad53  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7ad54  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7ad55  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7ad56  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7ad57  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a7ad58:
    // 00a7ad58  8b150800a800           -mov edx, dword ptr [0xa80008]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11010056) /* 0xa80008 */);
    // 00a7ad5e  e88dd6ffff             -call 0xa783f0
    cpu.esp -= 4;
    sub_a783f0(app, cpu);
    if (cpu.terminate) return;
    // 00a7ad63  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a7ad67  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 00a7ad6a  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00a7ad6c  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a7ad6e  a30000a800             -mov dword ptr [0xa80000], eax
    app->getMemory<x86::reg32>(x86::reg32(11010048) /* 0xa80000 */) = cpu.eax;
    // 00a7ad73  e8f88dffff             -call 0xa73b70
    cpu.esp -= 4;
    sub_a73b70(app, cpu);
    if (cpu.terminate) return;
    // 00a7ad78  eb39                   -jmp 0xa7adb3
    goto L_0x00a7adb3;
L_0x00a7ad7a:
    // 00a7ad7a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a7ad7c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a7ad7e  e81dd3ffff             -call 0xa780a0
    cpu.esp -= 4;
    sub_a780a0(app, cpu);
    if (cpu.terminate) return;
    // 00a7ad83  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a7ad85  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a7ad87  750f                   -jne 0xa7ad98
    if (!cpu.flags.zf)
    {
        goto L_0x00a7ad98;
    }
    // 00a7ad89  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a7ad8e  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a7ad91  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7ad92  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7ad93  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7ad94  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7ad95  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7ad96  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7ad97  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a7ad98:
    // 00a7ad98  8b6c2404               -mov ebp, dword ptr [esp + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a7ad9c  8b150000a800           -mov edx, dword ptr [0xa80000]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11010048) /* 0xa80000 */);
    // 00a7ada2  01c5                   +add ebp, eax
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
    // 00a7ada4  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00a7ada6  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a7ada8  e843010000             -call 0xa7aef0
    cpu.esp -= 4;
    sub_a7aef0(app, cpu);
    if (cpu.terminate) return;
    // 00a7adad  892d0000a800           -mov dword ptr [0xa80000], ebp
    app->getMemory<x86::reg32>(x86::reg32(11010048) /* 0xa80000 */) = cpu.ebp;
L_0x00a7adb3:
    // 00a7adb3  890d0800a800           -mov dword ptr [0xa80008], ecx
    app->getMemory<x86::reg32>(x86::reg32(11010056) /* 0xa80008 */) = cpu.ecx;
    // 00a7adb9  c744b10400000000       -mov dword ptr [ecx + esi*4 + 4], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.esi * 4) = 0 /*0x0*/;
    // 00a7adc1  eb03                   -jmp 0xa7adc6
    goto L_0x00a7adc6;
L_0x00a7adc3:
    // 00a7adc3  8d70ff                 -lea esi, [eax - 1]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
L_0x00a7adc6:
    // 00a7adc6  a10000a800             -mov eax, dword ptr [0xa80000]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11010048) /* 0xa80000 */);
    // 00a7adcb  893cb1                 -mov dword ptr [ecx + esi*4], edi
    app->getMemory<x86::reg32>(cpu.ecx + cpu.esi * 4) = cpu.edi;
    // 00a7adce  c6040600               -mov byte ptr [esi + eax], 0
    app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 0 /*0x0*/;
L_0x00a7add2:
    // 00a7add2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00a7add4:
    // 00a7add4  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a7add7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7add8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7add9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7adda  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7addb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7addc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7addd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a7ade0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7ade0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a7ade1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a7ade2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a7ade3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a7ade4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a7ade5  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a7ade7  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00a7ade9  8b350800a800           -mov esi, dword ptr [0xa80008]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(11010056) /* 0xa80008 */);
    // 00a7adef  e9d7000000             -jmp 0xa7aecb
    goto L_0x00a7aecb;
L_0x00a7adf4:
    // 00a7adf4  668b0f                 -mov cx, word ptr [edi]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edi);
    // 00a7adf7  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00a7adf9  6685c9                 +test cx, cx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.cx & cpu.cx));
    // 00a7adfc  0f84c6000000           -je 0xa7aec8
    if (cpu.flags.zf)
    {
        goto L_0x00a7aec8;
    }
L_0x00a7ae02:
    // 00a7ae02  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a7ae04  668b02                 -mov ax, word ptr [edx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edx);
    // 00a7ae07  e8940a0000             -call 0xa7b8a0
    cpu.esp -= 4;
    sub_a7b8a0(app, cpu);
    if (cpu.terminate) return;
    // 00a7ae0c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a7ae0e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a7ae10  668b03                 -mov ax, word ptr [ebx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebx);
    // 00a7ae13  e8880a0000             -call 0xa7b8a0
    cpu.esp -= 4;
    sub_a7b8a0(app, cpu);
    if (cpu.terminate) return;
    // 00a7ae18  6639c1                 +cmp cx, ax
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
    // 00a7ae1b  0f85a7000000           -jne 0xa7aec8
    if (!cpu.flags.zf)
    {
        goto L_0x00a7aec8;
    }
    // 00a7ae21  66833a3d               +cmp word ptr [edx], 0x3d
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
    // 00a7ae25  0f858a000000           -jne 0xa7aeb5
    if (!cpu.flags.zf)
    {
        goto L_0x00a7aeb5;
    }
    // 00a7ae2b  8b150800a800           -mov edx, dword ptr [0xa80008]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11010056) /* 0xa80008 */);
    // 00a7ae31  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 00a7ae33  29d7                   -sub edi, edx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a7ae35  c1ff02                 -sar edi, 2
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (2 /*0x2*/ % 32));
    // 00a7ae38  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00a7ae3a  0f846c000000           -je 0xa7aeac
    if (cpu.flags.zf)
    {
        goto L_0x00a7aeac;
    }
    // 00a7ae40  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00a7ae42  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00a7ae44  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a7ae46  740f                   -je 0xa7ae57
    if (cpu.flags.zf)
    {
        goto L_0x00a7ae57;
    }
L_0x00a7ae48:
    // 00a7ae48  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00a7ae4b  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 00a7ae4d  8b5904                 -mov ebx, dword ptr [ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00a7ae50  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a7ae53  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a7ae55  75f1                   -jne 0xa7ae48
    if (!cpu.flags.zf)
    {
        goto L_0x00a7ae48;
    }
L_0x00a7ae57:
    // 00a7ae57  8b350000a800           -mov esi, dword ptr [0xa80000]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(11010048) /* 0xa80000 */);
    // 00a7ae5d  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a7ae5f  7443                   -je 0xa7aea4
    if (cpu.flags.zf)
    {
        goto L_0x00a7aea4;
    }
    // 00a7ae61  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a7ae63  803c0700               +cmp byte ptr [edi + eax], 0
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
    // 00a7ae67  7407                   -je 0xa7ae70
    if (cpu.flags.zf)
    {
        goto L_0x00a7ae70;
    }
    // 00a7ae69  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a7ae6b  e8008fffff             -call 0xa73d70
    cpu.esp -= 4;
    sub_a73d70(app, cpu);
    if (cpu.terminate) return;
L_0x00a7ae70:
    // 00a7ae70  8b2d0800a800           -mov ebp, dword ptr [0xa80008]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(11010056) /* 0xa80008 */);
    // 00a7ae76  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00a7ae78  29ee                   -sub esi, ebp
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00a7ae7a  8b150000a800           -mov edx, dword ptr [0xa80000]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11010048) /* 0xa80000 */);
    // 00a7ae80  c1fe02                 -sar esi, 2
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (2 /*0x2*/ % 32));
    // 00a7ae83  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a7ae85  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00a7ae87  e864000000             -call 0xa7aef0
    cpu.esp -= 4;
    sub_a7aef0(app, cpu);
    if (cpu.terminate) return;
    // 00a7ae8c  890d0000a800           -mov dword ptr [0xa80000], ecx
    app->getMemory<x86::reg32>(x86::reg32(11010048) /* 0xa80000 */) = cpu.ecx;
    // 00a7ae92  39f7                   +cmp edi, esi
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
    // 00a7ae94  7d0e                   -jge 0xa7aea4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a7aea4;
    }
    // 00a7ae96  8d040f                 -lea eax, [edi + ecx]
    cpu.eax = x86::reg32(cpu.edi + cpu.ecx * 1);
L_0x00a7ae99:
    // 00a7ae99  40                     -inc eax
    (cpu.eax)++;
    // 00a7ae9a  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a7ae9c  47                     -inc edi
    (cpu.edi)++;
    // 00a7ae9d  8850ff                 -mov byte ptr [eax - 1], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-1) /* -0x1 */) = cpu.dl;
    // 00a7aea0  39f7                   +cmp edi, esi
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
    // 00a7aea2  7cf5                   -jl 0xa7ae99
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a7ae99;
    }
L_0x00a7aea4:
    // 00a7aea4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a7aea6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7aea7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7aea8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7aea9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7aeaa  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7aeab  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a7aeac:
    // 00a7aeac  8d4701                 -lea eax, [edi + 1]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 00a7aeaf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7aeb0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7aeb1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7aeb2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7aeb3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7aeb4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a7aeb5:
    // 00a7aeb5  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a7aeb8  668b4302               -mov ax, word ptr [ebx + 2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 00a7aebc  83c302                 -add ebx, 2
    (cpu.ebx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a7aebf  6685c0                 +test ax, ax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & cpu.ax));
    // 00a7aec2  0f853affffff           -jne 0xa7ae02
    if (!cpu.flags.zf)
    {
        goto L_0x00a7ae02;
    }
L_0x00a7aec8:
    // 00a7aec8  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00a7aecb:
    // 00a7aecb  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00a7aecd  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a7aecf  0f851fffffff           -jne 0xa7adf4
    if (!cpu.flags.zf)
    {
        goto L_0x00a7adf4;
    }
    // 00a7aed5  a10800a800             -mov eax, dword ptr [0xa80008]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11010056) /* 0xa80008 */);
    // 00a7aeda  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00a7aedc  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 00a7aedf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7aee0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7aee1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7aee2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7aee3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7aee4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a7aef0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7aef0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a7aef1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a7aef2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a7aef3  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00a7aef5  39c2                   +cmp edx, eax
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
    // 00a7aef7  7440                   -je 0xa7af39
    if (cpu.flags.zf)
    {
        goto L_0x00a7af39;
    }
    // 00a7aef9  7328                   -jae 0xa7af23
    if (!cpu.flags.cf)
    {
        goto L_0x00a7af23;
    }
    // 00a7aefb  8d3c1a                 -lea edi, [edx + ebx]
    cpu.edi = x86::reg32(cpu.edx + cpu.ebx * 1);
    // 00a7aefe  39c7                   +cmp edi, eax
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
    // 00a7af00  7621                   -jbe 0xa7af23
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a7af23;
    }
    // 00a7af02  8d77ff                 -lea esi, [edi - 1]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */);
    // 00a7af05  8d3c18                 -lea edi, [eax + ebx]
    cpu.edi = x86::reg32(cpu.eax + cpu.ebx * 1);
    // 00a7af08  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 00a7af0a  4f                     -dec edi
    (cpu.edi)--;
    // 00a7af0b  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a7af0c  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
    // 00a7af0e  fd                     -std 
    cpu.flags.df = 1;
    // 00a7af0f  4e                     -dec esi
    (cpu.esi)--;
    // 00a7af10  4f                     -dec edi
    (cpu.edi)--;
    // 00a7af11  d1e9                   +shr ecx, 1
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
    // 00a7af13  66f3a5                 -rep movsw word ptr es:[edi], word ptr [esi]
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
    // 00a7af16  11c9                   -adc ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 00a7af18  46                     -inc esi
    (cpu.esi)++;
    // 00a7af19  47                     -inc edi
    (cpu.edi)++;
    // 00a7af1a  66f3a4                 -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a7af1d  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a7af1e  fc                     -cld 
    cpu.flags.df = 0;
    // 00a7af1f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7af20  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7af21  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7af22  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a7af23:
    // 00a7af23  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00a7af25  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a7af27  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 00a7af29  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a7af2a  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
    // 00a7af2c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a7af2d  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a7af30  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a7af32  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7af33  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00a7af36  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a7af38  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
L_0x00a7af39:
    // 00a7af39  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7af3a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7af3b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7af3c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void sub_a7af40(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7af40  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a7af41  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a7af43  e868090000             -call 0xa7b8b0
    cpu.esp -= 4;
    sub_a7b8b0(app, cpu);
    if (cpu.terminate) return;
    // 00a7af48  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a7af4a  7403                   -je 0xa7af4f
    if (cpu.flags.zf)
    {
        goto L_0x00a7af4f;
    }
    // 00a7af4c  83ea21                 -sub edx, 0x21
    (cpu.edx) -= x86::reg32(x86::sreg32(33 /*0x21*/));
L_0x00a7af4f:
    // 00a7af4f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a7af51  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7af52  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a7af60(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7af60  c70580d7a70001000000   -mov dword ptr [0xa7d780], 1
    app->getMemory<x86::reg32>(x86::reg32(10999680) /* 0xa7d780 */) = 1 /*0x1*/;
    // 00a7af6a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void sub_a7af70(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7af70  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a7af71  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a7af72  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00a7af76  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a7af79  8b40fc                 -mov eax, dword ptr [eax - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 00a7af7c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a7af7d  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a7af7f  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00a7af83  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a7af84  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00a7af88  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a7af89  e806000000             -call 0xa7af94
    cpu.esp -= 4;
    sub_a7af94(app, cpu);
    if (cpu.terminate) return;
    // 00a7af8e  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a7af91  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7af92  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7af93  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a7af94(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7af94  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a7af95  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a7af96  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a7af97  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a7af9a  8d442420               -lea eax, [esp + 0x20]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00a7af9e  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 00a7afa0  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00a7afa4  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00a7afa8  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00a7afab  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00a7afaf  e808000000             -call 0xa7afbc
    cpu.esp -= 4;
    sub_a7afbc(app, cpu);
    if (cpu.terminate) return;
    // 00a7afb4  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a7afb7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7afb8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7afb9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7afba  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a7afbc(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7afbc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a7afbd  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a7afbe  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a7afbf  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00a7afc2  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a7afc4  8954241c               -mov dword ptr [esp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 00a7afc8  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 00a7afca  e831b5ffff             -call 0xa76500
    cpu.esp -= 4;
    sub_a76500(app, cpu);
    if (cpu.terminate) return;
    // 00a7afcf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a7afd1  7414                   -je 0xa7afe7
    if (cpu.flags.zf)
    {
        goto L_0x00a7afe7;
    }
    // 00a7afd3  b80b000000             -mov eax, 0xb
    cpu.eax = 11 /*0xb*/;
    // 00a7afd8  e8e3b3ffff             -call 0xa763c0
    cpu.esp -= 4;
    sub_a763c0(app, cpu);
    if (cpu.terminate) return;
    // 00a7afdd  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a7afe2  e9fe010000             -jmp 0xa7b1e5
    goto L_0x00a7b1e5;
L_0x00a7afe7:
    // 00a7afe7  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00a7afe9  8d5c2414               -lea ebx, [esp + 0x14]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00a7afed  83e607                 -and esi, 7
    cpu.esi &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 00a7aff0  8d542410               -lea edx, [esp + 0x10]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00a7aff4  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a7aff6  e835090000             -call 0xa7b930
    cpu.esp -= 4;
    sub_a7b930(app, cpu);
    if (cpu.terminate) return;
    // 00a7affb  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a7afff  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a7b001  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a7b003  09f0                   -or eax, esi
    cpu.eax |= x86::reg32(x86::sreg32(cpu.esi));
    // 00a7b005  bd80000000             -mov ebp, 0x80
    cpu.ebp = 128 /*0x80*/;
    // 00a7b00a  e855090000             -call 0xa7b964
    cpu.esp -= 4;
    sub_a7b964(app, cpu);
    if (cpu.terminate) return;
    // 00a7b00f  ba0c000000             -mov edx, 0xc
    cpu.edx = 12 /*0xc*/;
    // 00a7b014  8a64241c               -mov ah, byte ptr [esp + 0x1c]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00a7b018  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00a7b01c  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00a7b01f  f6c480                 +test ah, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 128 /*0x80*/));
    // 00a7b022  0f94c0                 -sete al
    cpu.al = cpu.flags.zf;
    // 00a7b025  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a7b02a  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a7b02e  833de8d2a70000         +cmp dword ptr [0xa7d2e8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10998504) /* 0xa7d2e8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a7b035  7434                   -je 0xa7b06b
    if (cpu.flags.zf)
    {
        goto L_0x00a7b06b;
    }
    // 00a7b037  ba18e4a700             -mov edx, 0xa7e418
    cpu.edx = 11002904 /*0xa7e418*/;
    // 00a7b03c  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a7b03e  e87d030000             -call 0xa7b3c0
    cpu.esp -= 4;
    sub_a7b3c0(app, cpu);
    if (cpu.terminate) return;
    // 00a7b043  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a7b045  7524                   -jne 0xa7b06b
    if (!cpu.flags.zf)
    {
        goto L_0x00a7b06b;
    }
    // 00a7b047  e8f4b6ffff             -call 0xa76740
    cpu.esp -= 4;
    sub_a76740(app, cpu);
    if (cpu.terminate) return;
    // 00a7b04c  ff15a0d2a700           -call dword ptr [0xa7d2a0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10998432) /* 0xa7d2a0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a7b052  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 00a7b054  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a7b055  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a7b056  ba00200000             -mov edx, 0x2000
    cpu.edx = 8192 /*0x2000*/;
    // 00a7b05b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a7b05d  ff15e8d2a700           -call dword ptr [0xa7d2e8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10998504) /* 0xa7d2e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a7b063  83c40c                 +add esp, 0xc
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
    // 00a7b066  e92a010000             -jmp 0xa7b195
    goto L_0x00a7b195;
L_0x00a7b06b:
    // 00a7b06b  8a54241c               -mov dl, byte ptr [esp + 0x1c]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00a7b06f  f6c220                 +test dl, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 32 /*0x20*/));
    // 00a7b072  0f8472000000           -je 0xa7b0ea
    if (cpu.flags.zf)
    {
        goto L_0x00a7b0ea;
    }
    // 00a7b078  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00a7b07a  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a7b07d  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 00a7b07f  8b42fc                 -mov eax, dword ptr [edx - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 00a7b082  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00a7b086  c70100000000           -mov dword ptr [ecx], 0
    app->getMemory<x86::reg32>(cpu.ecx) = 0 /*0x0*/;
    // 00a7b08c  a184d7a700             -mov eax, dword ptr [0xa7d784]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10999684) /* 0xa7d784 */);
    // 00a7b091  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00a7b095  f7d0                   -not eax
    cpu.eax = ~cpu.eax;
    // 00a7b097  21c3                   -and ebx, eax
    cpu.ebx &= x86::reg32(x86::sreg32(cpu.eax));
    // 00a7b099  895c2414               -mov dword ptr [esp + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 00a7b09d  f644241501             +test byte ptr [esp + 0x15], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(21) /* 0x15 */) & 1 /*0x1*/));
    // 00a7b0a2  740c                   -je 0xa7b0b0
    if (cpu.flags.zf)
    {
        goto L_0x00a7b0b0;
    }
    // 00a7b0a4  f644241480             +test byte ptr [esp + 0x14], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(20) /* 0x14 */) & 128 /*0x80*/));
    // 00a7b0a9  7505                   -jne 0xa7b0b0
    if (!cpu.flags.zf)
    {
        goto L_0x00a7b0b0;
    }
    // 00a7b0ab  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
L_0x00a7b0b0:
    // 00a7b0b0  f644241d04             +test byte ptr [esp + 0x1d], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(29) /* 0x1d */) & 4 /*0x4*/));
    // 00a7b0b5  740d                   -je 0xa7b0c4
    if (cpu.flags.zf)
    {
        goto L_0x00a7b0c4;
    }
    // 00a7b0b7  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00a7b0bc  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 00a7b0c0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a7b0c2  eb37                   -jmp 0xa7b0fb
    goto L_0x00a7b0fb;
L_0x00a7b0c4:
    // 00a7b0c4  f644241c40             +test byte ptr [esp + 0x1c], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(28) /* 0x1c */) & 64 /*0x40*/));
    // 00a7b0c9  740f                   -je 0xa7b0da
    if (cpu.flags.zf)
    {
        goto L_0x00a7b0da;
    }
    // 00a7b0cb  c744241802000000       -mov dword ptr [esp + 0x18], 2
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = 2 /*0x2*/;
    // 00a7b0d3  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a7b0d8  eb21                   -jmp 0xa7b0fb
    goto L_0x00a7b0fb;
L_0x00a7b0da:
    // 00a7b0da  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 00a7b0df  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 00a7b0e4  894c2418               -mov dword ptr [esp + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 00a7b0e8  eb11                   -jmp 0xa7b0fb
    goto L_0x00a7b0fb;
L_0x00a7b0ea:
    // 00a7b0ea  f6c240                 +test dl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 64 /*0x40*/));
    // 00a7b0ed  7407                   -je 0xa7b0f6
    if (cpu.flags.zf)
    {
        goto L_0x00a7b0f6;
    }
    // 00a7b0ef  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 00a7b0f4  eb05                   -jmp 0xa7b0fb
    goto L_0x00a7b0fb;
L_0x00a7b0f6:
    // 00a7b0f6  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
L_0x00a7b0fb:
    // 00a7b0fb  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a7b0fd  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a7b0fe  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a7b0ff  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a7b103  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a7b104  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00a7b108  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a7b109  8b4c2424               -mov ecx, dword ptr [esp + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00a7b10d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a7b10e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a7b10f  2eff1590bda700         -call dword ptr cs:[0xa7bd90]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993040) /* 0xa7bd90 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a7b116  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a7b118  83f8ff                 +cmp eax, -1
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
    // 00a7b11b  7536                   -jne 0xa7b153
    if (!cpu.flags.zf)
    {
        goto L_0x00a7b153;
    }
    // 00a7b11d  f644241c20             +test byte ptr [esp + 0x1c], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(28) /* 0x1c */) & 32 /*0x20*/));
    // 00a7b122  741e                   -je 0xa7b142
    if (cpu.flags.zf)
    {
        goto L_0x00a7b142;
    }
    // 00a7b124  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a7b126  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a7b127  8b6c2420               -mov ebp, dword ptr [esp + 0x20]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00a7b12b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a7b12c  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a7b12e  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00a7b132  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a7b133  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00a7b137  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a7b138  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a7b139  2eff1590bda700         -call dword ptr cs:[0xa7bd90]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993040) /* 0xa7bd90 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a7b140  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x00a7b142:
    // 00a7b142  83fbff                 +cmp ebx, -1
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
    // 00a7b145  750c                   -jne 0xa7b153
    if (!cpu.flags.zf)
    {
        goto L_0x00a7b153;
    }
    // 00a7b147  e838cfffff             -call 0xa78084
    cpu.esp -= 4;
    sub_a78084(app, cpu);
    if (cpu.terminate) return;
    // 00a7b14c  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00a7b14f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b150  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b151  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b152  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a7b153:
    // 00a7b153  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a7b155  ff15a0d2a700           -call dword ptr [0xa7d2a0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10998432) /* 0xa7d2a0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a7b15b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a7b15d  8b3d70d5a700           -mov edi, dword ptr [0xa7d570]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10999152) /* 0xa7d570 */);
    // 00a7b163  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a7b165  39f8                   +cmp eax, edi
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
    // 00a7b167  721e                   -jb 0xa7b187
    if (cpu.flags.cf)
    {
        goto L_0x00a7b187;
    }
    // 00a7b169  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a7b16a  2eff1588bda700         -call dword ptr cs:[0xa7bd88]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993032) /* 0xa7bd88 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a7b171  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 00a7b176  e845b2ffff             -call 0xa763c0
    cpu.esp -= 4;
    sub_a763c0(app, cpu);
    if (cpu.terminate) return;
    // 00a7b17b  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a7b180  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00a7b183  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b184  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b185  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b186  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a7b187:
    // 00a7b187  e804eeffff             -call 0xa79f90
    cpu.esp -= 4;
    sub_a79f90(app, cpu);
    if (cpu.terminate) return;
    // 00a7b18c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a7b18e  7405                   -je 0xa7b195
    if (cpu.flags.zf)
    {
        goto L_0x00a7b195;
    }
    // 00a7b190  ba00200000             -mov edx, 0x2000
    cpu.edx = 8192 /*0x2000*/;
L_0x00a7b195:
    // 00a7b195  83fe02                 +cmp esi, 2
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
    // 00a7b198  7505                   -jne 0xa7b19f
    if (!cpu.flags.zf)
    {
        goto L_0x00a7b19f;
    }
    // 00a7b19a  80ca03                 +or dl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.dl |= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a7b19d  eb11                   -jmp 0xa7b1b0
    goto L_0x00a7b1b0;
L_0x00a7b19f:
    // 00a7b19f  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a7b1a1  7505                   -jne 0xa7b1a8
    if (!cpu.flags.zf)
    {
        goto L_0x00a7b1a8;
    }
    // 00a7b1a3  80ca01                 +or dl, 1
    cpu.clear_co();
    cpu.set_szp((cpu.dl |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 00a7b1a6  eb08                   -jmp 0xa7b1b0
    goto L_0x00a7b1b0;
L_0x00a7b1a8:
    // 00a7b1a8  83fe01                 +cmp esi, 1
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
    // 00a7b1ab  7503                   -jne 0xa7b1b0
    if (!cpu.flags.zf)
    {
        goto L_0x00a7b1b0;
    }
    // 00a7b1ad  80ca02                 -or dl, 2
    cpu.dl |= x86::reg8(x86::sreg8(2 /*0x2*/));
L_0x00a7b1b0:
    // 00a7b1b0  f644241c10             +test byte ptr [esp + 0x1c], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(28) /* 0x1c */) & 16 /*0x10*/));
    // 00a7b1b5  7403                   -je 0xa7b1ba
    if (cpu.flags.zf)
    {
        goto L_0x00a7b1ba;
    }
    // 00a7b1b7  80ca80                 -or dl, 0x80
    cpu.dl |= x86::reg8(x86::sreg8(128 /*0x80*/));
L_0x00a7b1ba:
    // 00a7b1ba  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a7b1bc  8a5c241d               -mov bl, byte ptr [esp + 0x1d]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(29) /* 0x1d */);
    // 00a7b1c0  0c40                   -or al, 0x40
    cpu.al |= x86::reg8(x86::sreg8(64 /*0x40*/));
    // 00a7b1c2  f6c303                 +test bl, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 3 /*0x3*/));
    // 00a7b1c5  7407                   -je 0xa7b1ce
    if (cpu.flags.zf)
    {
        goto L_0x00a7b1ce;
    }
    // 00a7b1c7  f6c302                 +test bl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 2 /*0x2*/));
    // 00a7b1ca  7410                   -je 0xa7b1dc
    if (cpu.flags.zf)
    {
        goto L_0x00a7b1dc;
    }
    // 00a7b1cc  eb0c                   -jmp 0xa7b1da
    goto L_0x00a7b1da;
L_0x00a7b1ce:
    // 00a7b1ce  813d6cd1a70000020000   +cmp dword ptr [0xa7d16c], 0x200
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10998124) /* 0xa7d16c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(512 /*0x200*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a7b1d8  7502                   -jne 0xa7b1dc
    if (!cpu.flags.zf)
    {
        goto L_0x00a7b1dc;
    }
L_0x00a7b1da:
    // 00a7b1da  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x00a7b1dc:
    // 00a7b1dc  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a7b1de  e805ceffff             -call 0xa77fe8
    cpu.esp -= 4;
    sub_a77fe8(app, cpu);
    if (cpu.terminate) return;
    // 00a7b1e3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x00a7b1e5:
    // 00a7b1e5  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00a7b1e8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b1e9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b1ea  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b1eb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void sub_a7b1f0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7b1f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a7b1f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a7b1f2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a7b1f3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a7b1f4  3b4204                 +cmp eax, dword ptr [edx + 4]
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
    // 00a7b1f7  7f2c                   -jg 0xa7b225
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a7b225;
    }
    // 00a7b1f9  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00a7b1fc  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 00a7b1fe  8b5b08                 -mov ebx, dword ptr [ebx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00a7b201  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a7b203  39d8                   +cmp eax, ebx
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
    // 00a7b205  7c1e                   -jl 0xa7b225
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a7b225;
    }
    // 00a7b207  8a5a0c                 -mov bl, byte ptr [edx + 0xc]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00a7b20a  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 00a7b20c  8b7a04                 -mov edi, dword ptr [edx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00a7b20f  80e3ef                 -and bl, 0xef
    cpu.bl &= x86::reg8(x86::sreg8(239 /*0xef*/));
    // 00a7b212  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00a7b214  885a0c                 -mov byte ptr [edx + 0xc], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.bl;
    // 00a7b217  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00a7b219  8932                   -mov dword ptr [edx], esi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.esi;
    // 00a7b21b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a7b21d  897a04                 -mov dword ptr [edx + 4], edi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 00a7b220  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b221  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b222  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b223  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b224  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a7b225:
    // 00a7b225  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a7b22a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b22b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b22c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b22d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b22e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a7b230(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7b230  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a7b231  80600cef               -and byte ptr [eax + 0xc], 0xef
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(12) /* 0xc */) &= x86::reg8(x86::sreg8(239 /*0xef*/));
    // 00a7b235  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a7b238  8b5208                 -mov edx, dword ptr [edx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00a7b23b  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00a7b242  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00a7b244  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b245  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a7b248(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7b248  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a7b249  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a7b24a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a7b24b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a7b24d  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00a7b24f  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00a7b252  ff1598d2a700           -call dword ptr [0xa7d298]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10998424) /* 0xa7d298 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a7b258  8a610c                 -mov ah, byte ptr [ecx + 0xc]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00a7b25b  f6c406                 +test ah, 6
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 6 /*0x6*/));
    // 00a7b25e  0f8475000000           -je 0xa7b2d9
    if (cpu.flags.zf)
    {
        goto L_0x00a7b2d9;
    }
    // 00a7b264  f6410d10               +test byte ptr [ecx + 0xd], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */) & 16 /*0x10*/));
    // 00a7b268  742f                   -je 0xa7b299
    if (cpu.flags.zf)
    {
        goto L_0x00a7b299;
    }
    // 00a7b26a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a7b26c  e8af8fffff             -call 0xa74220
    cpu.esp -= 4;
    sub_a74220(app, cpu);
    if (cpu.terminate) return;
    // 00a7b271  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a7b273  743b                   -je 0xa7b2b0
    if (cpu.flags.zf)
    {
        goto L_0x00a7b2b0;
    }
    // 00a7b275  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a7b277  750e                   -jne 0xa7b287
    if (!cpu.flags.zf)
    {
        goto L_0x00a7b287;
    }
    // 00a7b279  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a7b27b  7d0a                   -jge 0xa7b287
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a7b287;
    }
L_0x00a7b27d:
    // 00a7b27d  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 00a7b282  e839b1ffff             -call 0xa763c0
    cpu.esp -= 4;
    sub_a763c0(app, cpu);
    if (cpu.terminate) return;
L_0x00a7b287:
    // 00a7b287  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00a7b28a  ff159cd2a700           -call dword ptr [0xa7d29c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10998428) /* 0xa7d29c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a7b290  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a7b295  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b296  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b297  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b298  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a7b299:
    // 00a7b299  83fb01                 +cmp ebx, 1
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
    // 00a7b29c  7503                   -jne 0xa7b2a1
    if (!cpu.flags.zf)
    {
        goto L_0x00a7b2a1;
    }
    // 00a7b29e  2b7104                 -sub esi, dword ptr [ecx + 4]
    (cpu.esi) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
L_0x00a7b2a1:
    // 00a7b2a1  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00a7b2a4  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a7b2a7  c7410400000000         -mov dword ptr [ecx + 4], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00a7b2ae  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
L_0x00a7b2b0:
    // 00a7b2b0  80610ceb               -and byte ptr [ecx + 0xc], 0xeb
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) &= x86::reg8(x86::sreg8(235 /*0xeb*/));
    // 00a7b2b4  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00a7b2b6  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00a7b2b9  e862b1ffff             -call 0xa76420
    cpu.esp -= 4;
    sub_a76420(app, cpu);
    if (cpu.terminate) return;
    // 00a7b2be  83f8ff                 +cmp eax, -1
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
    // 00a7b2c1  0f85e4000000           -jne 0xa7b3ab
    if (!cpu.flags.zf)
    {
        goto L_0x00a7b3ab;
    }
    // 00a7b2c7  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00a7b2ca  ff159cd2a700           -call dword ptr [0xa7d29c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10998428) /* 0xa7d29c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a7b2d0  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a7b2d5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b2d6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b2d7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b2d8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a7b2d9:
    // 00a7b2d9  83fb01                 +cmp ebx, 1
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
    // 00a7b2dc  720d                   -jb 0xa7b2eb
    if (cpu.flags.cf)
    {
        goto L_0x00a7b2eb;
    }
    // 00a7b2de  7611                   -jbe 0xa7b2f1
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a7b2f1;
    }
    // 00a7b2e0  83fb02                 +cmp ebx, 2
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
    // 00a7b2e3  0f848a000000           -je 0xa7b373
    if (cpu.flags.zf)
    {
        goto L_0x00a7b373;
    }
    // 00a7b2e9  eb92                   -jmp 0xa7b27d
    goto L_0x00a7b27d;
L_0x00a7b2eb:
    // 00a7b2eb  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a7b2ed  7445                   -je 0xa7b334
    if (cpu.flags.zf)
    {
        goto L_0x00a7b334;
    }
    // 00a7b2ef  eb8c                   -jmp 0xa7b27d
    goto L_0x00a7b27d;
L_0x00a7b2f1:
    // 00a7b2f1  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a7b2f3  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a7b2f5  8b7904                 -mov edi, dword ptr [ecx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00a7b2f8  e8f3feffff             -call 0xa7b1f0
    cpu.esp -= 4;
    sub_a7b1f0(app, cpu);
    if (cpu.terminate) return;
    // 00a7b2fd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a7b2ff  0f84a6000000           -je 0xa7b3ab
    if (cpu.flags.zf)
    {
        goto L_0x00a7b3ab;
    }
    // 00a7b305  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00a7b307  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00a7b30a  29fa                   -sub edx, edi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00a7b30c  e80fb1ffff             -call 0xa76420
    cpu.esp -= 4;
    sub_a76420(app, cpu);
    if (cpu.terminate) return;
    // 00a7b311  83f8ff                 +cmp eax, -1
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
    // 00a7b314  7512                   -jne 0xa7b328
    if (!cpu.flags.zf)
    {
        goto L_0x00a7b328;
    }
    // 00a7b316  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00a7b319  ff159cd2a700           -call dword ptr [0xa7d29c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10998428) /* 0xa7d29c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a7b31f  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a7b324  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b325  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b326  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b327  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a7b328:
    // 00a7b328  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a7b32a  e801ffffff             -call 0xa7b230
    cpu.esp -= 4;
    sub_a7b230(app, cpu);
    if (cpu.terminate) return;
    // 00a7b32f  e977000000             -jmp 0xa7b3ab
    goto L_0x00a7b3ab;
L_0x00a7b334:
    // 00a7b334  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00a7b337  e814f2ffff             -call 0xa7a550
    cpu.esp -= 4;
    sub_a7a550(app, cpu);
    if (cpu.terminate) return;
    // 00a7b33c  8b5104                 -mov edx, dword ptr [ecx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00a7b33f  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 00a7b341  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a7b343  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00a7b345  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a7b347  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a7b349  e8a2feffff             -call 0xa7b1f0
    cpu.esp -= 4;
    sub_a7b1f0(app, cpu);
    if (cpu.terminate) return;
    // 00a7b34e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a7b350  7459                   -je 0xa7b3ab
    if (cpu.flags.zf)
    {
        goto L_0x00a7b3ab;
    }
    // 00a7b352  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00a7b354  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00a7b357  e8c4b0ffff             -call 0xa76420
    cpu.esp -= 4;
    sub_a76420(app, cpu);
    if (cpu.terminate) return;
    // 00a7b35c  83f8ff                 +cmp eax, -1
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
    // 00a7b35f  75c7                   -jne 0xa7b328
    if (!cpu.flags.zf)
    {
        goto L_0x00a7b328;
    }
    // 00a7b361  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00a7b364  ff159cd2a700           -call dword ptr [0xa7d29c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10998428) /* 0xa7d29c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a7b36a  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a7b36f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b370  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b371  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b372  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a7b373:
    // 00a7b373  88e2                   -mov dl, ah
    cpu.dl = cpu.ah;
    // 00a7b375  80e2ef                 -and dl, 0xef
    cpu.dl &= x86::reg8(x86::sreg8(239 /*0xef*/));
    // 00a7b378  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00a7b37b  88510c                 -mov byte ptr [ecx + 0xc], dl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.dl;
    // 00a7b37e  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a7b381  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 00a7b383  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00a7b385  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00a7b388  c7410400000000         -mov dword ptr [ecx + 4], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00a7b38f  e88cb0ffff             -call 0xa76420
    cpu.esp -= 4;
    sub_a76420(app, cpu);
    if (cpu.terminate) return;
    // 00a7b394  83f8ff                 +cmp eax, -1
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
    // 00a7b397  7512                   -jne 0xa7b3ab
    if (!cpu.flags.zf)
    {
        goto L_0x00a7b3ab;
    }
    // 00a7b399  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00a7b39c  ff159cd2a700           -call dword ptr [0xa7d29c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10998428) /* 0xa7d29c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a7b3a2  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a7b3a7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b3a8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b3a9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b3aa  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a7b3ab:
    // 00a7b3ab  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00a7b3ae  ff159cd2a700           -call dword ptr [0xa7d29c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10998428) /* 0xa7d29c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a7b3b4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a7b3b6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b3b7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b3b8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b3b9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a7b3c0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7b3c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a7b3c1  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x00a7b3c3:
    // 00a7b3c3  8a03                   -mov al, byte ptr [ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx);
    // 00a7b3c5  8a22                   -mov ah, byte ptr [edx]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edx);
    // 00a7b3c7  3c41                   +cmp al, 0x41
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
    // 00a7b3c9  7206                   -jb 0xa7b3d1
    if (cpu.flags.cf)
    {
        goto L_0x00a7b3d1;
    }
    // 00a7b3cb  3c5a                   +cmp al, 0x5a
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
    // 00a7b3cd  7702                   -ja 0xa7b3d1
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a7b3d1;
    }
    // 00a7b3cf  0420                   -add al, 0x20
    (cpu.al) += x86::reg8(x86::sreg8(32 /*0x20*/));
L_0x00a7b3d1:
    // 00a7b3d1  80fc41                 +cmp ah, 0x41
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
    // 00a7b3d4  7208                   -jb 0xa7b3de
    if (cpu.flags.cf)
    {
        goto L_0x00a7b3de;
    }
    // 00a7b3d6  80fc5a                 +cmp ah, 0x5a
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
    // 00a7b3d9  7703                   -ja 0xa7b3de
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a7b3de;
    }
    // 00a7b3db  80c420                 -add ah, 0x20
    (cpu.ah) += x86::reg8(x86::sreg8(32 /*0x20*/));
L_0x00a7b3de:
    // 00a7b3de  38e0                   +cmp al, ah
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
    // 00a7b3e0  7508                   -jne 0xa7b3ea
    if (!cpu.flags.zf)
    {
        goto L_0x00a7b3ea;
    }
    // 00a7b3e2  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 00a7b3e4  7404                   -je 0xa7b3ea
    if (cpu.flags.zf)
    {
        goto L_0x00a7b3ea;
    }
    // 00a7b3e6  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a7b3e7  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a7b3e8  ebd9                   -jmp 0xa7b3c3
    goto L_0x00a7b3c3;
L_0x00a7b3ea:
    // 00a7b3ea  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a7b3ec  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 00a7b3ee  88e0                   -mov al, ah
    cpu.al = cpu.ah;
    // 00a7b3f0  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a7b3f5  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00a7b3f7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a7b3f9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b3fa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void sub_a7b400(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7b400  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a7b401  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a7b402  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a7b403  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a7b404  0fa0                   -push fs
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.fs;
    cpu.esp -= 4;
    // 00a7b406  0fa8                   -push gs
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.gs;
    cpu.esp -= 4;
    // 00a7b408  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a7b409  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00a7b40b  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00a7b40e  8b7520                 -mov esi, dword ptr [ebp + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 00a7b411  8b151000a800           -mov edx, dword ptr [0xa80010]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11010064) /* 0xa80010 */);
    // 00a7b417  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00a7b419  8b7e04                 -mov edi, dword ptr [esi + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00a7b41c  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 00a7b41f  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a7b421  7531                   -jne 0xa7b454
    if (!cpu.flags.zf)
    {
        goto L_0x00a7b454;
    }
    // 00a7b423  a1dcd5a700             -mov eax, dword ptr [0xa7d5dc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10999260) /* 0xa7d5dc */);
    // 00a7b428  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00a7b42b  24fc                   -and al, 0xfc
    cpu.al &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 00a7b42d  29c4                   -sub esp, eax
    (cpu.esp) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00a7b42f  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 00a7b431  8b1ddcd5a700           -mov ebx, dword ptr [0xa7d5dc]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10999260) /* 0xa7d5dc */);
    // 00a7b437  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a7b439  e83287ffff             -call 0xa73b70
    cpu.esp -= 4;
    sub_a73b70(app, cpu);
    if (cpu.terminate) return;
    // 00a7b43e  a1dcd5a700             -mov eax, dword ptr [0xa7d5dc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10999260) /* 0xa7d5dc */);
    // 00a7b443  8981f0000000           -mov dword ptr [ecx + 0xf0], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(240) /* 0xf0 */) = cpu.eax;
    // 00a7b449  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a7b44b  e888b6ffff             -call 0xa76ad8
    cpu.esp -= 4;
    sub_a76ad8(app, cpu);
    if (cpu.terminate) return;
    // 00a7b450  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a7b452  7431                   -je 0xa7b485
    if (cpu.flags.zf)
    {
        goto L_0x00a7b485;
    }
L_0x00a7b454:
    // 00a7b454  ff1594d2a700           -call dword ptr [0xa7d294]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10998420) /* 0xa7d294 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a7b45a  8b5e0c                 -mov ebx, dword ptr [esi + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00a7b45d  05de000000             -add eax, 0xde
    (cpu.eax) += x86::reg32(x86::sreg32(222 /*0xde*/));
    // 00a7b462  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a7b463  894610                 -mov dword ptr [esi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00a7b466  2eff152cbea700         -call dword ptr cs:[0xa7be2c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993196) /* 0xa7be2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a7b46d  8d45f4                 -lea eax, [ebp - 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a7b470  e8abbeffff             -call 0xa77320
    cpu.esp -= 4;
    sub_a77320(app, cpu);
    if (cpu.terminate) return;
    // 00a7b475  ff15d4d2a700           -call dword ptr [0xa7d2d4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10998484) /* 0xa7d2d4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a7b47b  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a7b47d  ff55fc                 -call dword ptr [ebp - 4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a7b480  e867f3ffff             -call 0xa7a7ec
    cpu.esp -= 4;
    sub_a7a7ec(app, cpu);
    if (cpu.terminate) return;
L_0x00a7b485:
    // 00a7b485  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00a7b487  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b488  0fa9                   -pop gs
    cpu.gs = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a7b48a  0fa1                   -pop fs
    cpu.fs = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a7b48c  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a7b48d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b48e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b48f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b490  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a7b494(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7b494  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a7b495  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a7b496  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a7b497  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a7b498  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a7b499  83ec38                 -sub esp, 0x38
    (cpu.esp) -= x86::reg32(x86::sreg32(56 /*0x38*/));
    // 00a7b49c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a7b49e  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00a7b4a0  833d90d2a700ff         +cmp dword ptr [0xa7d290], -1
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
    // 00a7b4a7  7512                   -jne 0xa7b4bb
    if (!cpu.flags.zf)
    {
        goto L_0x00a7b4bb;
    }
    // 00a7b4a9  e8cab5ffff             -call 0xa76a78
    cpu.esp -= 4;
    sub_a76a78(app, cpu);
    if (cpu.terminate) return;
    // 00a7b4ae  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a7b4b0  0f84be000000           -je 0xa7b574
    if (cpu.flags.zf)
    {
        goto L_0x00a7b574;
    }
    // 00a7b4b6  e8f9b6ffff             -call 0xa76bb4
    cpu.esp -= 4;
    sub_a76bb4(app, cpu);
    if (cpu.terminate) return;
L_0x00a7b4bb:
    // 00a7b4bb  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00a7b4bd  894c2420               -mov dword ptr [esp + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00a7b4c1  895c2424               -mov dword ptr [esp + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 00a7b4c5  2eff15d0bda700         -call dword ptr cs:[0xa7bdd0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993104) /* 0xa7bdd0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a7b4cc  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 00a7b4d0  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a7b4d2  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a7b4d4  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a7b4d6  be1ce4a700             -mov esi, 0xa7e41c
    cpu.esi = 11002908 /*0xa7e41c*/;
    // 00a7b4db  895c2430               -mov dword ptr [esp + 0x30], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.ebx;
    // 00a7b4df  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 00a7b4e4  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a7b4e5  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a7b4e6  a4                     -movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a7b4e7  2eff15ccbda700         -call dword ptr cs:[0xa7bdcc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993100) /* 0xa7bdcc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a7b4ee  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a7b4f2  e825bfffff             -call 0xa7741c
    cpu.esp -= 4;
    sub_a7741c(app, cpu);
    if (cpu.terminate) return;
    // 00a7b4f7  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a7b4f9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a7b4fa  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a7b4fc  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a7b4fe  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a7b500  2eff158cbda700         -call dword ptr cs:[0xa7bd8c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993036) /* 0xa7bd8c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a7b507  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 00a7b50b  8d442434               -lea eax, [esp + 0x34]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00a7b50f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a7b510  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a7b512  8d442428               -lea eax, [esp + 0x28]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00a7b516  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a7b517  81c5ff0f0000           -add ebp, 0xfff
    (cpu.ebp) += x86::reg32(x86::sreg32(4095 /*0xfff*/));
    // 00a7b51d  6800b4a700             -push 0xa7b400
    app->getMemory<x86::reg32>(cpu.esp-4) = 10990592 /*0xa7b400*/;
    cpu.esp -= 4;
    // 00a7b522  81e500f0ffff           -and ebp, 0xfffff000
    cpu.ebp &= x86::reg32(x86::sreg32(4294963200 /*0xfffff000*/));
    // 00a7b528  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a7b529  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a7b52b  2eff1594bda700         -call dword ptr cs:[0xa7bd94]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993044) /* 0xa7bd94 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a7b532  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a7b534  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a7b536  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a7b538  750a                   -jne 0xa7b544
    if (!cpu.flags.zf)
    {
        goto L_0x00a7b544;
    }
    // 00a7b53a  c7442434ffffffff       -mov dword ptr [esp + 0x34], 0xffffffff
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = 4294967295 /*0xffffffff*/;
    // 00a7b542  eb22                   -jmp 0xa7b566
    goto L_0x00a7b566;
L_0x00a7b544:
    // 00a7b544  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 00a7b546  8b4c2430               -mov ecx, dword ptr [esp + 0x30]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00a7b54a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a7b54b  2eff1564bea700         -call dword ptr cs:[0xa7be64]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993252) /* 0xa7be64 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a7b552  8b742430               -mov esi, dword ptr [esp + 0x30]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00a7b556  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a7b558  7404                   -je 0xa7b55e
    if (cpu.flags.zf)
    {
        goto L_0x00a7b55e;
    }
    // 00a7b55a  891e                   -mov dword ptr [esi], ebx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ebx;
    // 00a7b55c  eb08                   -jmp 0xa7b566
    goto L_0x00a7b566;
L_0x00a7b55e:
    // 00a7b55e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a7b55f  2eff1588bda700         -call dword ptr cs:[0xa7bd88]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993032) /* 0xa7bd88 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a7b566:
    // 00a7b566  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00a7b56a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a7b56b  2eff1588bda700         -call dword ptr cs:[0xa7bd88]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993032) /* 0xa7bd88 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a7b572  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
L_0x00a7b574:
    // 00a7b574  83c438                 -add esp, 0x38
    (cpu.esp) += x86::reg32(x86::sreg32(56 /*0x38*/));
    // 00a7b577  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b578  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a7b579  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b57a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b57b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b57c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a7b580(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7b580  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a7b581  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a7b582  ff15d8d2a700           -call dword ptr [0xa7d2d8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10998488) /* 0xa7d2d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a7b588  e8dfbdffff             -call 0xa7736c
    cpu.esp -= 4;
    sub_a7736c(app, cpu);
    if (cpu.terminate) return;
    // 00a7b58d  833d1000a80000         +cmp dword ptr [0xa80010], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11010064) /* 0xa80010 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a7b594  750a                   -jne 0xa7b5a0
    if (!cpu.flags.zf)
    {
        goto L_0x00a7b5a0;
    }
    // 00a7b596  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a7b59b  e88cb5ffff             -call 0xa76b2c
    cpu.esp -= 4;
    sub_a76b2c(app, cpu);
    if (cpu.terminate) return;
L_0x00a7b5a0:
    // 00a7b5a0  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a7b5a2  2eff15a8bda700         -call dword ptr cs:[0xa7bda8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993064) /* 0xa7bda8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a7b5a9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b5aa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b5ab  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void sub_a7b5b0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7b5b0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a7b5b1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a7b5b2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a7b5b3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a7b5b4  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00a7b5b6  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a7b5b9  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a7b5bb  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a7b5bd  7507                   -jne 0xa7b5c6
    if (!cpu.flags.zf)
    {
        goto L_0x00a7b5c6;
    }
    // 00a7b5bf  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a7b5c1  e983000000             -jmp 0xa7b649
    goto L_0x00a7b649;
L_0x00a7b5c6:
    // 00a7b5c6  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a7b5c8  0f8676000000           -jbe 0xa7b644
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a7b644;
    }
    // 00a7b5ce  803a00                 +cmp byte ptr [edx], 0
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
    // 00a7b5d1  7512                   -jne 0xa7b5e5
    if (!cpu.flags.zf)
    {
        goto L_0x00a7b5e5;
    }
    // 00a7b5d3  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a7b5d5  7405                   -je 0xa7b5dc
    if (cpu.flags.zf)
    {
        goto L_0x00a7b5dc;
    }
    // 00a7b5d7  66c7060000             -mov word ptr [esi], 0
    app->getMemory<x86::reg16>(cpu.esi) = 0 /*0x0*/;
L_0x00a7b5dc:
    // 00a7b5dc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a7b5de  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00a7b5e0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b5e1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b5e2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b5e3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b5e4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a7b5e5:
    // 00a7b5e5  833df00da80000         +cmp dword ptr [0xa80df0], 0
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
    // 00a7b5ec  7419                   -je 0xa7b607
    if (cpu.flags.zf)
    {
        goto L_0x00a7b607;
    }
    // 00a7b5ee  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a7b5f0  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 00a7b5f2  8a80010ea800           -mov al, byte ptr [eax + 0xa80e01]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(11013633) /* 0xa80e01 */);
    // 00a7b5f8  2401                   -and al, 1
    cpu.al &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00a7b5fa  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00a7b5ff  7406                   -je 0xa7b607
    if (cpu.flags.zf)
    {
        goto L_0x00a7b607;
    }
    // 00a7b601  807a0100               +cmp byte ptr [edx + 1], 0
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
    // 00a7b605  743d                   -je 0xa7b644
    if (cpu.flags.zf)
    {
        goto L_0x00a7b644;
    }
L_0x00a7b607:
    // 00a7b607  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a7b609  e842c5ffff             -call 0xa77b50
    cpu.esp -= 4;
    sub_a77b50(app, cpu);
    if (cpu.terminate) return;
    // 00a7b60e  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00a7b610  8d4dfc                 -lea ecx, [ebp - 4]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00a7b613  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a7b615  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a7b616  39c3                   +cmp ebx, eax
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
    // 00a7b618  7302                   -jae 0xa7b61c
    if (!cpu.flags.cf)
    {
        goto L_0x00a7b61c;
    }
    // 00a7b61a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x00a7b61c:
    // 00a7b61c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a7b61d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a7b61e  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 00a7b620  a154d6a700             -mov eax, dword ptr [0xa7d654]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10999380) /* 0xa7d654 */);
    // 00a7b625  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a7b626  2eff1518bea700         -call dword ptr cs:[0xa7be18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993176) /* 0xa7be18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a7b62d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a7b62f  7413                   -je 0xa7b644
    if (cpu.flags.zf)
    {
        goto L_0x00a7b644;
    }
    // 00a7b631  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a7b633  7406                   -je 0xa7b63b
    if (cpu.flags.zf)
    {
        goto L_0x00a7b63b;
    }
    // 00a7b635  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00a7b638  668906                 -mov word ptr [esi], ax
    app->getMemory<x86::reg16>(cpu.esi) = cpu.ax;
L_0x00a7b63b:
    // 00a7b63b  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a7b63d  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00a7b63f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b640  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b641  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b642  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b643  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a7b644:
    // 00a7b644  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
L_0x00a7b649:
    // 00a7b649  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00a7b64b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b64c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b64d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b64e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b64f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a7b650(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7b650  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a7b651  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a7b652  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a7b653  668b08                 -mov cx, word ptr [eax]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax);
    // 00a7b656  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00a7b658  6639ca                 +cmp dx, cx
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
    // 00a7b65b  7416                   -je 0xa7b673
    if (cpu.flags.zf)
    {
        goto L_0x00a7b673;
    }
L_0x00a7b65d:
    // 00a7b65d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a7b65f  668b3a                 -mov di, word ptr [edx]
    cpu.di = app->getMemory<x86::reg16>(cpu.edx);
    // 00a7b662  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a7b665  6685ff                 +test di, di
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.di & cpu.di));
    // 00a7b668  7407                   -je 0xa7b671
    if (cpu.flags.zf)
    {
        goto L_0x00a7b671;
    }
    // 00a7b66a  663b18                 +cmp bx, word ptr [eax]
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
    // 00a7b66d  7404                   -je 0xa7b673
    if (cpu.flags.zf)
    {
        goto L_0x00a7b673;
    }
    // 00a7b66f  ebec                   -jmp 0xa7b65d
    goto L_0x00a7b65d;
L_0x00a7b671:
    // 00a7b671  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00a7b673:
    // 00a7b673  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b674  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b675  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b676  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a7b680(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7b680  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a7b681  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a7b682  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a7b683  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a7b684  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a7b685  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a7b688  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00a7b68b  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00a7b68d  66813d71d3a7000080     +cmp word ptr [0xa7d371], 0x8000
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(10998641) /* 0xa7d371 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(32768 /*0x8000*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a7b696  730e                   -jae 0xa7b6a6
    if (!cpu.flags.cf)
    {
        goto L_0x00a7b6a6;
    }
    // 00a7b698  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a7b699  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a7b69a  2eff1528bea700         -call dword ptr cs:[0xa7be28]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993192) /* 0xa7be28 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a7b6a1  e9c3000000             -jmp 0xa7b769
    goto L_0x00a7b769;
L_0x00a7b6a6:
    // 00a7b6a6  e825cdffff             -call 0xa783d0
    cpu.esp -= 4;
    sub_a783d0(app, cpu);
    if (cpu.terminate) return;
    // 00a7b6ab  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 00a7b6ad  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a7b6b0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a7b6b2  e8c985ffff             -call 0xa73c80
    cpu.esp -= 4;
    sub_a73c80(app, cpu);
    if (cpu.terminate) return;
    // 00a7b6b7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a7b6b9  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a7b6bb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a7b6bd  0f84a6000000           -je 0xa7b769
    if (cpu.flags.zf)
    {
        goto L_0x00a7b769;
    }
    // 00a7b6c3  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a7b6c5  7504                   -jne 0xa7b6cb
    if (!cpu.flags.zf)
    {
        goto L_0x00a7b6cb;
    }
    // 00a7b6c7  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 00a7b6c9  eb2b                   -jmp 0xa7b6f6
    goto L_0x00a7b6f6;
L_0x00a7b6cb:
    // 00a7b6cb  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a7b6cd  e8feccffff             -call 0xa783d0
    cpu.esp -= 4;
    sub_a783d0(app, cpu);
    if (cpu.terminate) return;
    // 00a7b6d2  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 00a7b6d4  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a7b6d7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a7b6d9  e8a285ffff             -call 0xa73c80
    cpu.esp -= 4;
    sub_a73c80(app, cpu);
    if (cpu.terminate) return;
    // 00a7b6de  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a7b6e0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a7b6e2  7512                   -jne 0xa7b6f6
    if (!cpu.flags.zf)
    {
        goto L_0x00a7b6f6;
    }
    // 00a7b6e4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a7b6e6  e88586ffff             -call 0xa73d70
    cpu.esp -= 4;
    sub_a73d70(app, cpu);
    if (cpu.terminate) return;
    // 00a7b6eb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a7b6ed  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a7b6f0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b6f1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b6f2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b6f3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b6f4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b6f5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a7b6f6:
    // 00a7b6f6  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00a7b6f9  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00a7b6fb  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a7b6fd  e8de000000             -call 0xa7b7e0
    cpu.esp -= 4;
    sub_a7b7e0(app, cpu);
    if (cpu.terminate) return;
    // 00a7b702  83f8ff                 +cmp eax, -1
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
    // 00a7b705  751d                   -jne 0xa7b724
    if (!cpu.flags.zf)
    {
        goto L_0x00a7b724;
    }
    // 00a7b707  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a7b709  e86286ffff             -call 0xa73d70
    cpu.esp -= 4;
    sub_a73d70(app, cpu);
    if (cpu.terminate) return;
    // 00a7b70e  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a7b710  7407                   -je 0xa7b719
    if (cpu.flags.zf)
    {
        goto L_0x00a7b719;
    }
    // 00a7b712  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a7b714  e85786ffff             -call 0xa73d70
    cpu.esp -= 4;
    sub_a73d70(app, cpu);
    if (cpu.terminate) return;
L_0x00a7b719:
    // 00a7b719  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a7b71b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a7b71e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b71f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b720  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b721  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b722  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b723  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a7b724:
    // 00a7b724  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a7b726  7422                   -je 0xa7b74a
    if (cpu.flags.zf)
    {
        goto L_0x00a7b74a;
    }
    // 00a7b728  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00a7b72a  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00a7b72c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a7b72e  e8ad000000             -call 0xa7b7e0
    cpu.esp -= 4;
    sub_a7b7e0(app, cpu);
    if (cpu.terminate) return;
    // 00a7b733  83f8ff                 +cmp eax, -1
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
    // 00a7b736  7512                   -jne 0xa7b74a
    if (!cpu.flags.zf)
    {
        goto L_0x00a7b74a;
    }
    // 00a7b738  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a7b73a  e83186ffff             -call 0xa73d70
    cpu.esp -= 4;
    sub_a73d70(app, cpu);
    if (cpu.terminate) return;
    // 00a7b73f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a7b741  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a7b744  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b745  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b746  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b747  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b748  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b749  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a7b74a:
    // 00a7b74a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a7b74b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a7b74c  2eff1524bea700         -call dword ptr cs:[0xa7be24]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993188) /* 0xa7be24 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a7b753  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a7b755  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a7b757  e81486ffff             -call 0xa73d70
    cpu.esp -= 4;
    sub_a73d70(app, cpu);
    if (cpu.terminate) return;
    // 00a7b75c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a7b75e  7407                   -je 0xa7b767
    if (cpu.flags.zf)
    {
        goto L_0x00a7b767;
    }
    // 00a7b760  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a7b762  e80986ffff             -call 0xa73d70
    cpu.esp -= 4;
    sub_a73d70(app, cpu);
    if (cpu.terminate) return;
L_0x00a7b767:
    // 00a7b767  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x00a7b769:
    // 00a7b769  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a7b76c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b76d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b76e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b76f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b770  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b771  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a7b780(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7b780  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a7b781  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a7b782  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a7b783  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a7b784  8b350400a800           -mov esi, dword ptr [0xa80004]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(11010052) /* 0xa80004 */);
    // 00a7b78a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a7b78c  7441                   -je 0xa7b7cf
    if (cpu.flags.zf)
    {
        goto L_0x00a7b7cf;
    }
L_0x00a7b78e:
    // 00a7b78e  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00a7b790  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a7b793  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a7b795  7438                   -je 0xa7b7cf
    if (cpu.flags.zf)
    {
        goto L_0x00a7b7cf;
    }
    // 00a7b797  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a7b799  e872f2ffff             -call 0xa7aa10
    cpu.esp -= 4;
    sub_a7aa10(app, cpu);
    if (cpu.terminate) return;
    // 00a7b79e  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a7b7a1  8d045d00000000         -lea eax, [ebx*2]
    cpu.eax = x86::reg32(cpu.ebx * 2);
    // 00a7b7a8  e8d384ffff             -call 0xa73c80
    cpu.esp -= 4;
    sub_a73c80(app, cpu);
    if (cpu.terminate) return;
    // 00a7b7ad  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a7b7af  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a7b7b1  74db                   -je 0xa7b78e
    if (cpu.flags.zf)
    {
        goto L_0x00a7b78e;
    }
    // 00a7b7b3  e888f2ffff             -call 0xa7aa40
    cpu.esp -= 4;
    sub_a7aa40(app, cpu);
    if (cpu.terminate) return;
    // 00a7b7b8  83f8ff                 +cmp eax, -1
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
    // 00a7b7bb  7409                   -je 0xa7b7c6
    if (cpu.flags.zf)
    {
        goto L_0x00a7b7c6;
    }
    // 00a7b7bd  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a7b7bf  e894f4ffff             -call 0xa7ac58
    cpu.esp -= 4;
    sub_a7ac58(app, cpu);
    if (cpu.terminate) return;
    // 00a7b7c4  ebc8                   -jmp 0xa7b78e
    goto L_0x00a7b78e;
L_0x00a7b7c6:
    // 00a7b7c6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a7b7c8  e8a385ffff             -call 0xa73d70
    cpu.esp -= 4;
    sub_a73d70(app, cpu);
    if (cpu.terminate) return;
    // 00a7b7cd  ebbf                   -jmp 0xa7b78e
    goto L_0x00a7b78e;
L_0x00a7b7cf:
    // 00a7b7cf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b7d0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b7d1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b7d2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b7d3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a7b7e0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7b7e0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a7b7e1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a7b7e2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a7b7e3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a7b7e4  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00a7b7e7  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00a7b7eb  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00a7b7ed  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 00a7b7f0  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a7b7f2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a7b7f4  0f8471000000           -je 0xa7b86b
    if (cpu.flags.zf)
    {
        goto L_0x00a7b86b;
    }
L_0x00a7b7fa:
    // 00a7b7fa  833c2400               +cmp dword ptr [esp], 0
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
    // 00a7b7fe  0f8689000000           -jbe 0xa7b88d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a7b88d;
    }
    // 00a7b804  668b4d00               -mov cx, word ptr [ebp]
    cpu.cx = app->getMemory<x86::reg16>(cpu.ebp);
    // 00a7b808  6685c9                 +test cx, cx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.cx & cpu.cx));
    // 00a7b80b  7420                   -je 0xa7b82d
    if (cpu.flags.zf)
    {
        goto L_0x00a7b82d;
    }
    // 00a7b80d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a7b80f  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a7b813  6689ca                 -mov dx, cx
    cpu.dx = cpu.cx;
    // 00a7b816  e875bbffff             -call 0xa77390
    cpu.esp -= 4;
    sub_a77390(app, cpu);
    if (cpu.terminate) return;
    // 00a7b81b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a7b81d  83f8ff                 +cmp eax, -1
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
    // 00a7b820  0f8469000000           -je 0xa7b88f
    if (cpu.flags.zf)
    {
        goto L_0x00a7b88f;
    }
    // 00a7b826  3b0424                 +cmp eax, dword ptr [esp]
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
    // 00a7b829  7762                   -ja 0xa7b88d
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a7b88d;
    }
    // 00a7b82b  eb09                   -jmp 0xa7b836
    goto L_0x00a7b836;
L_0x00a7b82d:
    // 00a7b82d  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a7b831  c60000                 -mov byte ptr [eax], 0
    app->getMemory<x86::reg8>(cpu.eax) = 0 /*0x0*/;
    // 00a7b834  eb57                   -jmp 0xa7b88d
    goto L_0x00a7b88d;
L_0x00a7b836:
    // 00a7b836  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a7b83a  8b7c2404               -mov edi, dword ptr [esp + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a7b83e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a7b840  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a7b841  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a7b843  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a7b845  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a7b846  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a7b848  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a7b84b  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a7b84d  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a7b84f  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a7b852  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a7b854  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b855  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a7b856  83c502                 -add ebp, 2
    (cpu.ebp) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a7b859  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a7b85b  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00a7b85e  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a7b860  29d0                   +sub eax, edx
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
    // 00a7b862  897c2404               -mov dword ptr [esp + 4], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 00a7b866  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00a7b869  eb8f                   -jmp 0xa7b7fa
    goto L_0x00a7b7fa;
L_0x00a7b86b:
    // 00a7b86b  66837d0000             +cmp word ptr [ebp], 0
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
    // 00a7b870  741b                   -je 0xa7b88d
    if (cpu.flags.zf)
    {
        goto L_0x00a7b88d;
    }
    // 00a7b872  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a7b874  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a7b878  668b5500               -mov dx, word ptr [ebp]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ebp);
    // 00a7b87c  e80fbbffff             -call 0xa77390
    cpu.esp -= 4;
    sub_a77390(app, cpu);
    if (cpu.terminate) return;
    // 00a7b881  83f8ff                 +cmp eax, -1
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
    // 00a7b884  7409                   -je 0xa7b88f
    if (cpu.flags.zf)
    {
        goto L_0x00a7b88f;
    }
    // 00a7b886  83c502                 -add ebp, 2
    (cpu.ebp) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a7b889  01c3                   +add ebx, eax
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
    // 00a7b88b  ebde                   -jmp 0xa7b86b
    goto L_0x00a7b86b;
L_0x00a7b88d:
    // 00a7b88d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x00a7b88f:
    // 00a7b88f  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00a7b892  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b893  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b894  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b895  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b896  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a7b8a0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7b8a0  663d6100               +cmp ax, 0x61
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
    // 00a7b8a4  7209                   -jb 0xa7b8af
    if (cpu.flags.cf)
    {
        goto L_0x00a7b8af;
    }
    // 00a7b8a6  663d7a00               +cmp ax, 0x7a
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
    // 00a7b8aa  7703                   -ja 0xa7b8af
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a7b8af;
    }
    // 00a7b8ac  83e820                 -sub eax, 0x20
    (cpu.eax) -= x86::reg32(x86::sreg32(32 /*0x20*/));
L_0x00a7b8af:
    // 00a7b8af  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a7b8b0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7b8b0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a7b8b1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a7b8b3  e808010000             -call 0xa7b9c0
    cpu.esp -= 4;
    sub_a7b9c0(app, cpu);
    if (cpu.terminate) return;
    // 00a7b8b8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a7b8ba  741f                   -je 0xa7b8db
    if (cpu.flags.zf)
    {
        goto L_0x00a7b8db;
    }
    // 00a7b8bc  81fa81820000           +cmp edx, 0x8281
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
    // 00a7b8c2  7211                   -jb 0xa7b8d5
    if (cpu.flags.cf)
    {
        goto L_0x00a7b8d5;
    }
    // 00a7b8c4  81fa9a820000           +cmp edx, 0x829a
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
    // 00a7b8ca  7709                   -ja 0xa7b8d5
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a7b8d5;
    }
    // 00a7b8cc  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00a7b8d1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a7b8d3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b8d4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a7b8d5:
    // 00a7b8d5  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a7b8d7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a7b8d9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b8da  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a7b8db:
    // 00a7b8db  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 00a7b8dd  fec0                   -inc al
    (cpu.al)++;
    // 00a7b8df  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a7b8e4  8a808cd1a700           -mov al, byte ptr [eax + 0xa7d18c]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(10998156) /* 0xa7d18c */);
    // 00a7b8ea  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a7b8ec  2480                   -and al, 0x80
    cpu.al &= x86::reg8(x86::sreg8(128 /*0x80*/));
    // 00a7b8ee  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 00a7b8f0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a7b8f2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b8f3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a7b900(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7b900  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 00a7b902  740e                   -je 0xa7b912
    if (cpu.flags.zf)
    {
        goto L_0x00a7b912;
    }
    // 00a7b904  c70200000080           -mov dword ptr [edx], 0x80000000
    app->getMemory<x86::reg32>(cpu.edx) = 2147483648 /*0x80000000*/;
    // 00a7b90a  c70301000000           -mov dword ptr [ebx], 1
    app->getMemory<x86::reg32>(cpu.ebx) = 1 /*0x1*/;
    // 00a7b910  eb0c                   -jmp 0xa7b91e
    goto L_0x00a7b91e;
L_0x00a7b912:
    // 00a7b912  c702000000c0           -mov dword ptr [edx], 0xc0000000
    app->getMemory<x86::reg32>(cpu.edx) = 3221225472 /*0xc0000000*/;
    // 00a7b918  c70380000000           -mov dword ptr [ebx], 0x80
    app->getMemory<x86::reg32>(cpu.ebx) = 128 /*0x80*/;
L_0x00a7b91e:
    // 00a7b91e  a802                   +test al, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 2 /*0x2*/));
    // 00a7b920  7403                   -je 0xa7b925
    if (cpu.flags.zf)
    {
        goto L_0x00a7b925;
    }
    // 00a7b922  800b02                 -or byte ptr [ebx], 2
    app->getMemory<x86::reg8>(cpu.ebx) |= x86::reg8(x86::sreg8(2 /*0x2*/));
L_0x00a7b925:
    // 00a7b925  a804                   +test al, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 4 /*0x4*/));
    // 00a7b927  7403                   -je 0xa7b92c
    if (cpu.flags.zf)
    {
        goto L_0x00a7b92c;
    }
    // 00a7b929  800b04                 -or byte ptr [ebx], 4
    app->getMemory<x86::reg8>(cpu.ebx) |= x86::reg8(x86::sreg8(4 /*0x4*/));
L_0x00a7b92c:
    // 00a7b92c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a7b930(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7b930  83f802                 +cmp eax, 2
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
    // 00a7b933  750d                   -jne 0xa7b942
    if (!cpu.flags.zf)
    {
        goto L_0x00a7b942;
    }
    // 00a7b935  c702000000c0           -mov dword ptr [edx], 0xc0000000
    app->getMemory<x86::reg32>(cpu.edx) = 3221225472 /*0xc0000000*/;
    // 00a7b93b  c70380000000           -mov dword ptr [ebx], 0x80
    app->getMemory<x86::reg32>(cpu.ebx) = 128 /*0x80*/;
    // 00a7b941  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a7b942:
    // 00a7b942  83f801                 +cmp eax, 1
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
    // 00a7b945  750d                   -jne 0xa7b954
    if (!cpu.flags.zf)
    {
        goto L_0x00a7b954;
    }
    // 00a7b947  c70200000040           -mov dword ptr [edx], 0x40000000
    app->getMemory<x86::reg32>(cpu.edx) = 1073741824 /*0x40000000*/;
    // 00a7b94d  c70380000000           -mov dword ptr [ebx], 0x80
    app->getMemory<x86::reg32>(cpu.ebx) = 128 /*0x80*/;
    // 00a7b953  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a7b954:
    // 00a7b954  c70200000080           -mov dword ptr [edx], 0x80000000
    app->getMemory<x86::reg32>(cpu.edx) = 2147483648 /*0x80000000*/;
    // 00a7b95a  c70301000000           -mov dword ptr [ebx], 1
    app->getMemory<x86::reg32>(cpu.ebx) = 1 /*0x1*/;
    // 00a7b960  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a7b964(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7b964  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a7b965  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a7b967  83e070                 -and eax, 0x70
    cpu.eax &= x86::reg32(x86::sreg32(112 /*0x70*/));
    // 00a7b96a  83e307                 -and ebx, 7
    cpu.ebx &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 00a7b96d  83f820                 +cmp eax, 0x20
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
    // 00a7b970  7210                   -jb 0xa7b982
    if (cpu.flags.cf)
    {
        goto L_0x00a7b982;
    }
    // 00a7b972  7638                   -jbe 0xa7b9ac
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a7b9ac;
    }
    // 00a7b974  83f830                 +cmp eax, 0x30
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
    // 00a7b977  7241                   -jb 0xa7b9ba
    if (cpu.flags.cf)
    {
        goto L_0x00a7b9ba;
    }
    // 00a7b979  7629                   -jbe 0xa7b9a4
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a7b9a4;
    }
    // 00a7b97b  83f840                 +cmp eax, 0x40
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
    // 00a7b97e  7434                   -je 0xa7b9b4
    if (cpu.flags.zf)
    {
        goto L_0x00a7b9b4;
    }
    // 00a7b980  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b981  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a7b982:
    // 00a7b982  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a7b984  7607                   -jbe 0xa7b98d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a7b98d;
    }
    // 00a7b986  83f810                 +cmp eax, 0x10
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
    // 00a7b989  7411                   -je 0xa7b99c
    if (cpu.flags.zf)
    {
        goto L_0x00a7b99c;
    }
    // 00a7b98b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b98c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a7b98d:
    // 00a7b98d  c70201000000           -mov dword ptr [edx], 1
    app->getMemory<x86::reg32>(cpu.edx) = 1 /*0x1*/;
    // 00a7b993  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a7b995  7523                   -jne 0xa7b9ba
    if (!cpu.flags.zf)
    {
        goto L_0x00a7b9ba;
    }
    // 00a7b997  800a02                 -or byte ptr [edx], 2
    app->getMemory<x86::reg8>(cpu.edx) |= x86::reg8(x86::sreg8(2 /*0x2*/));
    // 00a7b99a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b99b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a7b99c:
    // 00a7b99c  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 00a7b9a2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b9a3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a7b9a4:
    // 00a7b9a4  c70202000000           -mov dword ptr [edx], 2
    app->getMemory<x86::reg32>(cpu.edx) = 2 /*0x2*/;
    // 00a7b9aa  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b9ab  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a7b9ac:
    // 00a7b9ac  c70201000000           -mov dword ptr [edx], 1
    app->getMemory<x86::reg32>(cpu.edx) = 1 /*0x1*/;
    // 00a7b9b2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b9b3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a7b9b4:
    // 00a7b9b4  c70203000000           -mov dword ptr [edx], 3
    app->getMemory<x86::reg32>(cpu.edx) = 3 /*0x3*/;
L_0x00a7b9ba:
    // 00a7b9ba  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b9bb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void sub_a7b9c0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7b9c0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a7b9c1  833df00da80000         +cmp dword ptr [0xa80df0], 0
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
    // 00a7b9c8  7431                   -je 0xa7b9fb
    if (cpu.flags.zf)
    {
        goto L_0x00a7b9fb;
    }
    // 00a7b9ca  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a7b9cc  c1ea08                 -shr edx, 8
    cpu.edx >>= 8 /*0x8*/ % 32;
    // 00a7b9cf  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a7b9d5  8a92010ea800           -mov dl, byte ptr [edx + 0xa80e01]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(11013633) /* 0xa80e01 */);
    // 00a7b9db  80e201                 -and dl, 1
    cpu.dl &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00a7b9de  81e2ff000000           +and edx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00a7b9e4  7415                   -je 0xa7b9fb
    if (cpu.flags.zf)
    {
        goto L_0x00a7b9fb;
    }
    // 00a7b9e6  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a7b9eb  e810000000             -call 0xa7ba00
    cpu.esp -= 4;
    sub_a7ba00(app, cpu);
    if (cpu.terminate) return;
    // 00a7b9f0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a7b9f2  7407                   -je 0xa7b9fb
    if (cpu.flags.zf)
    {
        goto L_0x00a7b9fb;
    }
    // 00a7b9f4  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a7b9f9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b9fa  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a7b9fb:
    // 00a7b9fb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a7b9fd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7b9fe  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void sub_a7ba00(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7ba00  833df00da80000         +cmp dword ptr [0xa80df0], 0
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
    // 00a7ba07  7429                   -je 0xa7ba32
    if (cpu.flags.zf)
    {
        goto L_0x00a7ba32;
    }
    // 00a7ba09  813d54d6a700a4030000   +cmp dword ptr [0xa7d654], 0x3a4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10999380) /* 0xa7d654 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(932 /*0x3a4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a7ba13  740a                   -je 0xa7ba1f
    if (cpu.flags.zf)
    {
        goto L_0x00a7ba1f;
    }
    // 00a7ba15  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a7ba17  741b                   -je 0xa7ba34
    if (cpu.flags.zf)
    {
        goto L_0x00a7ba34;
    }
    // 00a7ba19  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a7ba1e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a7ba1f:
    // 00a7ba1f  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a7ba24  8a8089d7a700           -mov al, byte ptr [eax + 0xa7d789]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(10999689) /* 0xa7d789 */);
    // 00a7ba2a  2408                   -and al, 8
    cpu.al &= x86::reg8(x86::sreg8(8 /*0x8*/));
    // 00a7ba2c  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a7ba31  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a7ba32:
    // 00a7ba32  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00a7ba34:
    // 00a7ba34  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
