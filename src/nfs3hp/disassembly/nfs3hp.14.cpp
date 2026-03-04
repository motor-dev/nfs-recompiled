#include "nfs3hp.h"
#include <lib/thread.h>

namespace nfs3hp
{

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_44f670(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044f670  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0044f671  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0044f672  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044f673  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044f675  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0044f677  bb03000000             -mov ebx, 3
    cpu.ebx = 3 /*0x3*/;
    // 0044f67c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0044f67e  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0044f681  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0044f683  69da34560100           -imul ebx, edx, 0x15634
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(87604 /*0x15634*/)));
    // 0044f689  8b1508945500           -mov edx, dword ptr [0x559408]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5608456) /* 0x559408 */);
    // 0044f68f  8d82e0160000           -lea eax, [edx + 0x16e0]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(5856) /* 0x16e0 */);
    // 0044f695  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0044f697  69c11c1f0000           -imul eax, ecx, 0x1f1c
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(7964 /*0x1f1c*/)));
    // 0044f69d  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0044f69f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044f6a1  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 0044f6a4  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0044f6a6  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0044f6a9  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0044f6ab  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0044f6ae  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0044f6b1  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0044f6b3  891d0c945500           -mov dword ptr [0x55940c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5608460) /* 0x55940c */) = cpu.ebx;
    // 0044f6b9  891510945500           -mov dword ptr [0x559410], edx
    app->getMemory<x86::reg32>(x86::reg32(5608464) /* 0x559410 */) = cpu.edx;
    // 0044f6bf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044f6c0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044f6c1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044f6c2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_44f6e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 0044f6e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0044f6e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0044f6e2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0044f6e3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0044f6e4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044f6e5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044f6e7  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0044f6e9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0044f6eb  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0044f6ed  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 0044f6ef  a114945500             -mov eax, dword ptr [0x559414]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5608468) /* 0x559414 */);
    // 0044f6f4  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0044f6f6  83f806                 +cmp eax, 6
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
    // 0044f6f9  0f87e6000000           -ja 0x44f7e5
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0044f7e5;
    }
    // 0044f6ff  ff2485c4f64400         -jmp dword ptr [eax*4 + 0x44f6c4]
    cpu.ip = app->getMemory<x86::reg32>(4519620 + cpu.eax * 4); goto dynamic_jump;
  case 0x0044f706:
    // 0044f706  8b8316030000           -mov eax, dword ptr [ebx + 0x316]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(790) /* 0x316 */);
    // 0044f70c  8bb116030000           -mov esi, dword ptr [ecx + 0x316]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(790) /* 0x316 */);
    // 0044f712  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0044f715  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 0044f718  39c6                   +cmp esi, eax
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
    // 0044f71a  7d05                   -jge 0x44f721
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0044f721;
    }
    // 0044f71c  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x0044f721:
    // 0044f721  8bb316030000           -mov esi, dword ptr [ebx + 0x316]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(790) /* 0x316 */);
    // 0044f727  8b8116030000           -mov eax, dword ptr [ecx + 0x316]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(790) /* 0x316 */);
    // 0044f72d  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 0044f730  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0044f733  39f0                   +cmp eax, esi
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
    // 0044f735  7e05                   -jle 0x44f73c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0044f73c;
    }
    // 0044f737  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
L_0x0044f73c:
    // 0044f73c  668bb318030000         -mov si, word ptr [ebx + 0x318]
    cpu.si = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(792) /* 0x318 */);
    // 0044f743  663bb118030000         +cmp si, word ptr [ecx + 0x318]
    {
        x86::reg16 tmp1 = cpu.si;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(792) /* 0x318 */)));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0044f74a  0f8595000000           -jne 0x44f7e5
    if (!cpu.flags.zf)
    {
        goto L_0x0044f7e5;
    }
    // 0044f750  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0044f752  e98e000000             -jmp 0x44f7e5
    goto L_0x0044f7e5;
  case 0x0044f757:
    // 0044f757  d98114030000           +fld dword ptr [ecx + 0x314]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(788) /* 0x314 */)));
    // 0044f75d  d89b14030000           +fcomp dword ptr [ebx + 0x314]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ebx + x86::reg32(788) /* 0x314 */)));
    cpu.fpu.pop();
    // 0044f763  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0044f765  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0044f766  7305                   -jae 0x44f76d
    if (!cpu.flags.cf)
    {
        goto L_0x0044f76d;
    }
    // 0044f768  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x0044f76d:
    // 0044f76d  d98114030000           +fld dword ptr [ecx + 0x314]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(788) /* 0x314 */)));
    // 0044f773  d89b14030000           +fcomp dword ptr [ebx + 0x314]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ebx + x86::reg32(788) /* 0x314 */)));
    cpu.fpu.pop();
    // 0044f779  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0044f77b  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0044f77c  7605                   -jbe 0x44f783
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0044f783;
    }
    // 0044f77e  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
L_0x0044f783:
    // 0044f783  d98114030000           +fld dword ptr [ecx + 0x314]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(788) /* 0x314 */)));
    // 0044f789  d89b14030000           +fcomp dword ptr [ebx + 0x314]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ebx + x86::reg32(788) /* 0x314 */)));
    cpu.fpu.pop();
    // 0044f78f  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0044f791  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0044f792  7551                   -jne 0x44f7e5
    if (!cpu.flags.zf)
    {
        goto L_0x0044f7e5;
    }
    // 0044f794  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0044f796  eb4d                   -jmp 0x44f7e5
    goto L_0x0044f7e5;
  case 0x0044f798:
    // 0044f798  8bb310030000           -mov esi, dword ptr [ebx + 0x310]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(784) /* 0x310 */);
    // 0044f79e  3bb110030000           +cmp esi, dword ptr [ecx + 0x310]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(784) /* 0x310 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044f7a4  7e05                   -jle 0x44f7ab
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0044f7ab;
    }
    // 0044f7a6  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
L_0x0044f7ab:
    // 0044f7ab  8bbb10030000           -mov edi, dword ptr [ebx + 0x310]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(784) /* 0x310 */);
    // 0044f7b1  3bb910030000           +cmp edi, dword ptr [ecx + 0x310]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(784) /* 0x310 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044f7b7  7d05                   -jge 0x44f7be
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0044f7be;
    }
    // 0044f7b9  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x0044f7be:
    // 0044f7be  8bb310030000           -mov esi, dword ptr [ebx + 0x310]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(784) /* 0x310 */);
    // 0044f7c4  3bb110030000           +cmp esi, dword ptr [ecx + 0x310]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(784) /* 0x310 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044f7ca  7519                   -jne 0x44f7e5
    if (!cpu.flags.zf)
    {
        goto L_0x0044f7e5;
    }
    // 0044f7cc  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0044f7ce  eb15                   -jmp 0x44f7e5
    goto L_0x0044f7e5;
  case 0x0044f7d0:
    // 0044f7d0  8d530f                 -lea edx, [ebx + 0xf]
    cpu.edx = x86::reg32(cpu.ebx + x86::reg32(15) /* 0xf */);
    // 0044f7d3  8d410f                 -lea eax, [ecx + 0xf]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(15) /* 0xf */);
    // 0044f7d6  eb06                   -jmp 0x44f7de
    goto L_0x0044f7de;
  case 0x0044f7d8:
    // 0044f7d8  8d5304                 -lea edx, [ebx + 4]
    cpu.edx = x86::reg32(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0044f7db  8d4104                 -lea eax, [ecx + 4]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(4) /* 0x4 */);
L_0x0044f7de:
    // 0044f7de  e8dda60900             -call 0x4e9ec0
    cpu.esp -= 4;
    sub_4e9ec0(app, cpu);
    if (cpu.terminate) return;
    // 0044f7e3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
  [[fallthrough]];
  case 0x0044f7e5:
L_0x0044f7e5:
    // 0044f7e5  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0044f7e7  7536                   -jne 0x44f81f
    if (!cpu.flags.zf)
    {
        goto L_0x0044f81f;
    }
    // 0044f7e9  8bbb10030000           -mov edi, dword ptr [ebx + 0x310]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(784) /* 0x310 */);
    // 0044f7ef  3bb910030000           +cmp edi, dword ptr [ecx + 0x310]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(784) /* 0x310 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044f7f5  7e05                   -jle 0x44f7fc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0044f7fc;
    }
    // 0044f7f7  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
L_0x0044f7fc:
    // 0044f7fc  8bb310030000           -mov esi, dword ptr [ebx + 0x310]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(784) /* 0x310 */);
    // 0044f802  3bb110030000           +cmp esi, dword ptr [ecx + 0x310]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(784) /* 0x310 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044f808  7d05                   -jge 0x44f80f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0044f80f;
    }
    // 0044f80a  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x0044f80f:
    // 0044f80f  8bbb10030000           -mov edi, dword ptr [ebx + 0x310]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(784) /* 0x310 */);
    // 0044f815  3bb910030000           +cmp edi, dword ptr [ecx + 0x310]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(784) /* 0x310 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044f81b  7502                   -jne 0x44f81f
    if (!cpu.flags.zf)
    {
        goto L_0x0044f81f;
    }
    // 0044f81d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0044f81f:
    // 0044f81f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0044f821  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044f822  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044f823  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044f824  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044f825  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044f826  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_44f830(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044f830  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0044f831  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0044f832  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0044f833  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0044f834  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044f835  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044f837  83ec28                 -sub esp, 0x28
    (cpu.esp) -= x86::reg32(x86::sreg32(40 /*0x28*/));
    // 0044f83a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0044f83c  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0044f83e  eb05                   -jmp 0x44f845
    goto L_0x0044f845;
L_0x0044f840:
    // 0044f840  83f80a                 +cmp eax, 0xa
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
    // 0044f843  7d22                   -jge 0x44f867
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0044f867;
    }
L_0x0044f845:
    // 0044f845  66c70445d0456600ffff   -mov word ptr [eax*2 + 0x6645d0], 0xffff
    app->getMemory<x86::reg16>(x86::reg32(6702544) /* 0x6645d0 */ + cpu.eax * 2) = 65535 /*0xffff*/;
    // 0044f84f  69d81c030000           -imul ebx, eax, 0x31c
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(796 /*0x31c*/)));
    // 0044f855  8b0d0c945500           -mov ecx, dword ptr [0x55940c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5608460) /* 0x55940c */);
    // 0044f85b  8d7104                 -lea esi, [ecx + 4]
    cpu.esi = x86::reg32(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0044f85e  40                     -inc eax
    (cpu.eax)++;
    // 0044f85f  01de                   +add esi, ebx
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
    // 0044f861  897485d4               -mov dword ptr [ebp + eax*4 - 0x2c], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */ + cpu.eax * 4) = cpu.esi;
    // 0044f865  ebd9                   -jmp 0x44f840
    goto L_0x0044f840;
L_0x0044f867:
    // 0044f867  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 0044f86c  8d45d8                 -lea eax, [ebp - 0x28]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 0044f86f  891514945500           -mov dword ptr [0x559414], edx
    app->getMemory<x86::reg32>(x86::reg32(5608468) /* 0x559414 */) = cpu.edx;
    // 0044f875  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0044f877  b9e0f64400             -mov ecx, 0x44f6e0
    cpu.ecx = 4519648 /*0x44f6e0*/;
    // 0044f87c  e877ec0900             -call 0x4ee4f8
    cpu.esp -= 4;
    sub_4ee4f8(app, cpu);
    if (cpu.terminate) return;
    // 0044f881  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0044f883:
    // 0044f883  8b150c945500           -mov edx, dword ptr [0x55940c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5608460) /* 0x55940c */);
    // 0044f889  3b02                   +cmp eax, dword ptr [edx]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044f88b  7d2d                   -jge 0x44f8ba
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0044f8ba;
    }
    // 0044f88d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0044f88f:
    // 0044f88f  8b0d0c945500           -mov ecx, dword ptr [0x55940c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5608460) /* 0x55940c */);
    // 0044f895  3b11                   +cmp edx, dword ptr [ecx]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044f897  7d1e                   -jge 0x44f8b7
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0044f8b7;
    }
    // 0044f899  69da1c030000           -imul ebx, edx, 0x31c
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(796 /*0x31c*/)));
    // 0044f89f  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0044f8a2  8b7485d8               -mov esi, dword ptr [ebp + eax*4 - 0x28]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */ + cpu.eax * 4);
    // 0044f8a6  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0044f8a8  39f3                   +cmp ebx, esi
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
    // 0044f8aa  7508                   -jne 0x44f8b4
    if (!cpu.flags.zf)
    {
        goto L_0x0044f8b4;
    }
    // 0044f8ac  66891445d0456600       -mov word ptr [eax*2 + 0x6645d0], dx
    app->getMemory<x86::reg16>(x86::reg32(6702544) /* 0x6645d0 */ + cpu.eax * 2) = cpu.dx;
L_0x0044f8b4:
    // 0044f8b4  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0044f8b5  ebd8                   -jmp 0x44f88f
    goto L_0x0044f88f;
L_0x0044f8b7:
    // 0044f8b7  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0044f8b8  ebc9                   -jmp 0x44f883
    goto L_0x0044f883;
L_0x0044f8ba:
    // 0044f8ba  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0044f8bc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044f8bd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044f8be  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044f8bf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044f8c0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044f8c1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_44f8d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044f8d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0044f8d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0044f8d2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044f8d3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044f8d5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0044f8d7  bb03000000             -mov ebx, 3
    cpu.ebx = 3 /*0x3*/;
    // 0044f8dc  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0044f8de  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0044f8e1  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0044f8e3  69d234560100           -imul edx, edx, 0x15634
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(87604 /*0x15634*/)));
    // 0044f8e9  a108945500             -mov eax, dword ptr [0x559408]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5608456) /* 0x559408 */);
    // 0044f8ee  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0044f8f0  69c11c1f0000           -imul eax, ecx, 0x1f1c
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(7964 /*0x1f1c*/)));
    // 0044f8f6  8b8402e0160000         -mov eax, dword ptr [edx + eax + 0x16e0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5856) /* 0x16e0 */ + cpu.eax * 1);
    // 0044f8fd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044f8fe  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044f8ff  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044f900  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_44f910(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044f910  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0044f911  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044f912  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044f914  833d0894550000         +cmp dword ptr [0x559408], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5608456) /* 0x559408 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044f91b  7405                   -je 0x44f922
    if (cpu.flags.zf)
    {
        goto L_0x0044f922;
    }
    // 0044f91d  83f80a                 +cmp eax, 0xa
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
    // 0044f920  7e05                   -jle 0x44f927
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0044f927;
    }
L_0x0044f922:
    // 0044f922  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044f924  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044f925  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044f926  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0044f927:
    // 0044f927  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 0044f929  6683b8d045660000       +cmp word ptr [eax + 0x6645d0], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(6702544) /* 0x6645d0 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0044f931  7c12                   -jl 0x44f945
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0044f945;
    }
    // 0044f933  8b90ce456600           -mov edx, dword ptr [eax + 0x6645ce]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6702542) /* 0x6645ce */);
    // 0044f939  a10c945500             -mov eax, dword ptr [0x55940c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5608460) /* 0x55940c */);
    // 0044f93e  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0044f941  3b10                   +cmp edx, dword ptr [eax]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044f943  7e05                   -jle 0x44f94a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0044f94a;
    }
L_0x0044f945:
    // 0044f945  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044f947  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044f948  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044f949  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0044f94a:
    // 0044f94a  69d21c030000           -imul edx, edx, 0x31c
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(796 /*0x31c*/)));
    // 0044f950  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0044f953  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0044f955  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044f956  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044f957  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_44f960(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044f960  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0044f961  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044f962  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044f964  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0044f966  a10c945500             -mov eax, dword ptr [0x55940c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5608460) /* 0x55940c */);
    // 0044f96b  83380a                 +cmp dword ptr [eax], 0xa
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10 /*0xa*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044f96e  7d08                   -jge 0x44f978
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0044f978;
    }
    // 0044f970  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0044f975  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044f976  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044f977  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0044f978:
    // 0044f978  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 0044f97d  e8aefeffff             -call 0x44f830
    cpu.esp -= 4;
    sub_44f830(app, cpu);
    if (cpu.terminate) return;
    // 0044f982  a10c945500             -mov eax, dword ptr [0x55940c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5608460) /* 0x55940c */);
    // 0044f987  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0044f989  48                     -dec eax
    (cpu.eax)--;
    // 0044f98a  e881ffffff             -call 0x44f910
    cpu.esp -= 4;
    sub_44f910(app, cpu);
    if (cpu.terminate) return;
    // 0044f98f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044f991  7508                   -jne 0x44f99b
    if (!cpu.flags.zf)
    {
        goto L_0x0044f99b;
    }
    // 0044f993  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0044f998  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044f999  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044f99a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0044f99b:
    // 0044f99b  3b9010030000           +cmp edx, dword ptr [eax + 0x310]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(784) /* 0x310 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044f9a1  7d08                   -jge 0x44f9ab
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0044f9ab;
    }
    // 0044f9a3  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0044f9a8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044f9a9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044f9aa  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0044f9ab:
    // 0044f9ab  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044f9ad  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044f9ae  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044f9af  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_44f9b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044f9b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0044f9b1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0044f9b2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0044f9b3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044f9b4  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044f9b6  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0044f9b8  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0044f9ba  eb22                   -jmp 0x44f9de
    goto L_0x0044f9de;
L_0x0044f9bc:
    // 0044f9bc  83fa0a                 +cmp edx, 0xa
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10 /*0xa*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044f9bf  7d17                   -jge 0x44f9d8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0044f9d8;
    }
L_0x0044f9c1:
    // 0044f9c1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0044f9c3  e848ffffff             -call 0x44f910
    cpu.esp -= 4;
    sub_44f910(app, cpu);
    if (cpu.terminate) return;
    // 0044f9c8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044f9ca  7409                   -je 0x44f9d5
    if (cpu.flags.zf)
    {
        goto L_0x0044f9d5;
    }
    // 0044f9cc  66c7801a0300000000     -mov word ptr [eax + 0x31a], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(794) /* 0x31a */) = 0 /*0x0*/;
L_0x0044f9d5:
    // 0044f9d5  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0044f9d6  ebe4                   -jmp 0x44f9bc
    goto L_0x0044f9bc;
L_0x0044f9d8:
    // 0044f9d8  41                     -inc ecx
    (cpu.ecx)++;
    // 0044f9d9  83f90b                 +cmp ecx, 0xb
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(11 /*0xb*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044f9dc  7d23                   -jge 0x44fa01
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0044fa01;
    }
L_0x0044f9de:
    // 0044f9de  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0044f9e0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044f9e2  e889fcffff             -call 0x44f670
    cpu.esp -= 4;
    sub_44f670(app, cpu);
    if (cpu.terminate) return;
    // 0044f9e7  a110945500             -mov eax, dword ptr [0x559410]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5608464) /* 0x559410 */);
    // 0044f9ec  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0044f9f3  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 0044f9f8  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0044f9fa  e831feffff             -call 0x44f830
    cpu.esp -= 4;
    sub_44f830(app, cpu);
    if (cpu.terminate) return;
    // 0044f9ff  ebc0                   -jmp 0x44f9c1
    goto L_0x0044f9c1;
L_0x0044fa01:
    // 0044fa01  43                     -inc ebx
    (cpu.ebx)++;
    // 0044fa02  83fb03                 +cmp ebx, 3
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
    // 0044fa05  7d04                   -jge 0x44fa0b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0044fa0b;
    }
    // 0044fa07  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0044fa09  ebd3                   -jmp 0x44f9de
    goto L_0x0044f9de;
L_0x0044fa0b:
    // 0044fa0b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044fa0c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044fa0d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044fa0e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044fa0f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_44fa10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044fa10  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0044fa11  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0044fa12  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0044fa13  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0044fa14  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044fa15  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044fa17  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 0044fa1c  e80ffeffff             -call 0x44f830
    cpu.esp -= 4;
    sub_44f830(app, cpu);
    if (cpu.terminate) return;
    // 0044fa21  a10c945500             -mov eax, dword ptr [0x55940c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5608460) /* 0x55940c */);
    // 0044fa26  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0044fa28  83fa0a                 +cmp edx, 0xa
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10 /*0xa*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044fa2b  7518                   -jne 0x44fa45
    if (!cpu.flags.zf)
    {
        goto L_0x0044fa45;
    }
    // 0044fa2d  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 0044fa32  b9c7000000             -mov ecx, 0xc7
    cpu.ecx = 199 /*0xc7*/;
    // 0044fa37  8d7518                 -lea esi, [ebp + 0x18]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 0044fa3a  e8d1feffff             -call 0x44f910
    cpu.esp -= 4;
    sub_44f910(app, cpu);
    if (cpu.terminate) return;
    // 0044fa3f  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0044fa41  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0044fa43  eb17                   -jmp 0x44fa5c
    goto L_0x0044fa5c;
L_0x0044fa45:
    // 0044fa45  69d21c030000           -imul edx, edx, 0x31c
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(796 /*0x31c*/)));
    // 0044fa4b  b9c7000000             -mov ecx, 0xc7
    cpu.ecx = 199 /*0xc7*/;
    // 0044fa50  8d7804                 -lea edi, [eax + 4]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0044fa53  8d7518                 -lea esi, [ebp + 0x18]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 0044fa56  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 0044fa58  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0044fa5a  ff00                   -inc dword ptr [eax]
    (app->getMemory<x86::reg32>(cpu.eax))++;
L_0x0044fa5c:
    // 0044fa5c  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 0044fa61  e8cafdffff             -call 0x44f830
    cpu.esp -= 4;
    sub_44f830(app, cpu);
    if (cpu.terminate) return;
    // 0044fa66  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0044fa68  eb05                   -jmp 0x44fa6f
    goto L_0x0044fa6f;
L_0x0044fa6a:
    // 0044fa6a  83fa0a                 +cmp edx, 0xa
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10 /*0xa*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044fa6d  7d10                   -jge 0x44fa7f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0044fa7f;
    }
L_0x0044fa6f:
    // 0044fa6f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0044fa71  e89afeffff             -call 0x44f910
    cpu.esp -= 4;
    sub_44f910(app, cpu);
    if (cpu.terminate) return;
    // 0044fa76  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044fa78  7405                   -je 0x44fa7f
    if (cpu.flags.zf)
    {
        goto L_0x0044fa7f;
    }
    // 0044fa7a  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0044fa7c  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0044fa7d  ebeb                   -jmp 0x44fa6a
    goto L_0x0044fa6a;
L_0x0044fa7f:
    // 0044fa7f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044fa80  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044fa81  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044fa82  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044fa83  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044fa84  c21c03                 -ret 0x31c
    cpu.esp += 4+796 /*0x31c*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_44fa90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044fa90  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0044fa91  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0044fa92  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044fa93  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044fa95  8b3510945500           -mov esi, dword ptr [0x559410]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5608464) /* 0x559410 */);
    // 0044fa9b  833e00                 +cmp dword ptr [esi], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044fa9e  746a                   -je 0x44fb0a
    if (cpu.flags.zf)
    {
        goto L_0x0044fb0a;
    }
    // 0044faa0  83c608                 -add esi, 8
    (cpu.esi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0044faa3  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0044faa5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0044faa6:
    // 0044faa6  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0044faa8  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0044faaa  3c00                   +cmp al, 0
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
    // 0044faac  7410                   -je 0x44fabe
    if (cpu.flags.zf)
    {
        goto L_0x0044fabe;
    }
    // 0044faae  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0044fab1  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0044fab4  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0044fab7  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0044faba  3c00                   +cmp al, 0
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
    // 0044fabc  75e8                   -jne 0x44faa6
    if (!cpu.flags.zf)
    {
        goto L_0x0044faa6;
    }
L_0x0044fabe:
    // 0044fabe  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044fabf  a110945500             -mov eax, dword ptr [0x559410]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5608464) /* 0x559410 */);
    // 0044fac4  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0044fac6  8d7013                 -lea esi, [eax + 0x13]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(19) /* 0x13 */);
    // 0044fac9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0044faca:
    // 0044faca  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0044facc  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0044face  3c00                   +cmp al, 0
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
    // 0044fad0  7410                   -je 0x44fae2
    if (cpu.flags.zf)
    {
        goto L_0x0044fae2;
    }
    // 0044fad2  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0044fad5  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0044fad8  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0044fadb  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0044fade  3c00                   +cmp al, 0
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
    // 0044fae0  75e8                   -jne 0x44faca
    if (!cpu.flags.zf)
    {
        goto L_0x0044faca;
    }
L_0x0044fae2:
    // 0044fae2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044fae3  a110945500             -mov eax, dword ptr [0x559410]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5608464) /* 0x559410 */);
    // 0044fae8  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0044faea  8db013010000           -lea esi, [eax + 0x113]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(275) /* 0x113 */);
    // 0044faf0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0044faf1:
    // 0044faf1  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0044faf3  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0044faf5  3c00                   +cmp al, 0
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
    // 0044faf7  7410                   -je 0x44fb09
    if (cpu.flags.zf)
    {
        goto L_0x0044fb09;
    }
    // 0044faf9  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0044fafc  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0044faff  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0044fb02  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0044fb05  3c00                   +cmp al, 0
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
    // 0044fb07  75e8                   -jne 0x44faf1
    if (!cpu.flags.zf)
    {
        goto L_0x0044faf1;
    }
L_0x0044fb09:
    // 0044fb09  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0044fb0a:
    // 0044fb0a  a110945500             -mov eax, dword ptr [0x559410]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5608464) /* 0x559410 */);
    // 0044fb0f  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0044fb11  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044fb12  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044fb13  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044fb14  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_44fb20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044fb20  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044fb21  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044fb23  a110945500             -mov eax, dword ptr [0x559410]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5608464) /* 0x559410 */);
    // 0044fb28  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0044fb2b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044fb2c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_44fb30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044fb30  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0044fb31  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0044fb32  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044fb33  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044fb35  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0044fb37  a110945500             -mov eax, dword ptr [0x559410]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5608464) /* 0x559410 */);
    // 0044fb3c  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 0044fb3e  8b4d10                 -mov ecx, dword ptr [ebp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0044fb41  8d7808                 -lea edi, [eax + 8]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0044fb44  894804                 -mov dword ptr [eax + 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0044fb47  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0044fb48:
    // 0044fb48  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0044fb4a  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0044fb4c  3c00                   +cmp al, 0
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
    // 0044fb4e  7410                   -je 0x44fb60
    if (cpu.flags.zf)
    {
        goto L_0x0044fb60;
    }
    // 0044fb50  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0044fb53  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0044fb56  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0044fb59  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0044fb5c  3c00                   +cmp al, 0
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
    // 0044fb5e  75e8                   -jne 0x44fb48
    if (!cpu.flags.zf)
    {
        goto L_0x0044fb48;
    }
L_0x0044fb60:
    // 0044fb60  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044fb61  a110945500             -mov eax, dword ptr [0x559410]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5608464) /* 0x559410 */);
    // 0044fb66  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0044fb68  8d7813                 -lea edi, [eax + 0x13]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(19) /* 0x13 */);
    // 0044fb6b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0044fb6c:
    // 0044fb6c  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0044fb6e  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0044fb70  3c00                   +cmp al, 0
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
    // 0044fb72  7410                   -je 0x44fb84
    if (cpu.flags.zf)
    {
        goto L_0x0044fb84;
    }
    // 0044fb74  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0044fb77  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0044fb7a  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0044fb7d  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0044fb80  3c00                   +cmp al, 0
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
    // 0044fb82  75e8                   -jne 0x44fb6c
    if (!cpu.flags.zf)
    {
        goto L_0x0044fb6c;
    }
L_0x0044fb84:
    // 0044fb84  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044fb85  a110945500             -mov eax, dword ptr [0x559410]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5608464) /* 0x559410 */);
    // 0044fb8a  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0044fb8c  8db813010000           -lea edi, [eax + 0x113]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(275) /* 0x113 */);
    // 0044fb92  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0044fb93:
    // 0044fb93  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0044fb95  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0044fb97  3c00                   +cmp al, 0
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
    // 0044fb99  7410                   -je 0x44fbab
    if (cpu.flags.zf)
    {
        goto L_0x0044fbab;
    }
    // 0044fb9b  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0044fb9e  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0044fba1  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0044fba4  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0044fba7  3c00                   +cmp al, 0
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
    // 0044fba9  75e8                   -jne 0x44fb93
    if (!cpu.flags.zf)
    {
        goto L_0x0044fb93;
    }
L_0x0044fbab:
    // 0044fbab  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044fbac  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044fbad  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044fbae  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044fbaf  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_44fbc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044fbc0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044fbc1  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044fbc3  a10c945500             -mov eax, dword ptr [0x55940c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5608460) /* 0x55940c */);
    // 0044fbc8  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 0044fbce  a110945500             -mov eax, dword ptr [0x559410]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5608464) /* 0x559410 */);
    // 0044fbd3  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 0044fbd9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044fbda  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_44fc00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 0044fc00  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0044fc01  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0044fc02  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044fc03  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044fc05  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0044fc07  668b80b6000000         -mov ax, word ptr [eax + 0xb6]
    cpu.ax = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(182) /* 0xb6 */);
    // 0044fc0e  48                     -dec eax
    (cpu.eax)--;
    // 0044fc0f  663d0500               +cmp ax, 5
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(5 /*0x5*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0044fc13  770c                   -ja 0x44fc21
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0044fc21;
    }
    // 0044fc15  25ffff0000             +and eax, 0xffff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/))));
    // 0044fc1a  ff2485dcfb4400         -jmp dword ptr [eax*4 + 0x44fbdc]
    cpu.ip = app->getMemory<x86::reg32>(4520924 + cpu.eax * 4); goto dynamic_jump;
  case 0x0044fc21:
L_0x0044fc21:
    // 0044fc21  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0044fc23  eb21                   -jmp 0x44fc46
    goto L_0x0044fc46;
  case 0x0044fc25:
    // 0044fc25  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 0044fc2a  eb1a                   -jmp 0x44fc46
    goto L_0x0044fc46;
  case 0x0044fc2c:
    // 0044fc2c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0044fc31  eb13                   -jmp 0x44fc46
    goto L_0x0044fc46;
  case 0x0044fc33:
    // 0044fc33  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0044fc38  eb0c                   -jmp 0x44fc46
    goto L_0x0044fc46;
  case 0x0044fc3a:
    // 0044fc3a  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 0044fc3f  eb05                   -jmp 0x44fc46
    goto L_0x0044fc46;
  case 0x0044fc41:
    // 0044fc41  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
L_0x0044fc46:
    // 0044fc46  8b91ae000000           -mov edx, dword ptr [ecx + 0xae]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(174) /* 0xae */);
    // 0044fc4c  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0044fc4f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0044fc50  8b54c150               -mov edx, dword ptr [ecx + eax*8 + 0x50]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(80) /* 0x50 */ + cpu.eax * 8);
    // 0044fc54  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0044fc55  8b5cc14c               -mov ebx, dword ptr [ecx + eax*8 + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(76) /* 0x4c */ + cpu.eax * 8);
    // 0044fc59  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0044fc5a  e881d00100             -call 0x46cce0
    cpu.esp -= 4;
    sub_46cce0(app, cpu);
    if (cpu.terminate) return;
    // 0044fc5f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044fc60  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044fc61  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044fc62  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_44fc70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044fc70  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0044fc71  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0044fc72  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0044fc73  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0044fc74  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044fc75  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044fc77  81ec80050000           -sub esp, 0x580
    (cpu.esp) -= x86::reg32(x86::sreg32(1408 /*0x580*/));
    // 0044fc7d  81ed82000000           -sub ebp, 0x82
    (cpu.ebp) -= x86::reg32(x86::sreg32(130 /*0x82*/));
    // 0044fc83  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0044fc85  895536                 -mov dword ptr [ebp + 0x36], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(54) /* 0x36 */) = cpu.edx;
    // 0044fc88  ba18000000             -mov edx, 0x18
    cpu.edx = 24 /*0x18*/;
    // 0044fc8d  89457e                 -mov dword ptr [ebp + 0x7e], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */) = cpu.eax;
    // 0044fc90  e8cba9ffff             -call 0x44a660
    cpu.esp -= 4;
    sub_44a660(app, cpu);
    if (cpu.terminate) return;
    // 0044fc95  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044fc97  0f84b80a0000           -je 0x450755
    if (cpu.flags.zf)
    {
        goto L_0x00450755;
    }
    // 0044fc9d  6683b9b800000002       +cmp word ptr [ecx + 0xb8], 2
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(184) /* 0xb8 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(2 /*0x2*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0044fca5  752a                   -jne 0x44fcd1
    if (!cpu.flags.zf)
    {
        goto L_0x0044fcd1;
    }
    // 0044fca7  668b99ba000000         -mov bx, word ptr [ecx + 0xba]
    cpu.bx = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(186) /* 0xba */);
    // 0044fcae  83c314                 -add ebx, 0x14
    (cpu.ebx) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0044fcb1  668999ba000000         -mov word ptr [ecx + 0xba], bx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(186) /* 0xba */) = cpu.bx;
    // 0044fcb8  6681fba802             +cmp bx, 0x2a8
    {
        x86::reg16 tmp1 = cpu.bx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(680 /*0x2a8*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0044fcbd  7c12                   -jl 0x44fcd1
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0044fcd1;
    }
    // 0044fcbf  66c781ba000000a802     -mov word ptr [ecx + 0xba], 0x2a8
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(186) /* 0xba */) = 680 /*0x2a8*/;
    // 0044fcc8  66c781b80000000300     -mov word ptr [ecx + 0xb8], 3
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(184) /* 0xb8 */) = 3 /*0x3*/;
L_0x0044fcd1:
    // 0044fcd1  8b457e                 -mov eax, dword ptr [ebp + 0x7e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 0044fcd4  6683b8b800000001       +cmp word ptr [eax + 0xb8], 1
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(184) /* 0xb8 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(1 /*0x1*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0044fcdc  7535                   -jne 0x44fd13
    if (!cpu.flags.zf)
    {
        goto L_0x0044fd13;
    }
    // 0044fcde  6683a8ba00000014       -sub word ptr [eax + 0xba], 0x14
    (app->getMemory<x86::reg16>(cpu.eax + x86::reg32(186) /* 0xba */)) -= x86::reg16(x86::sreg16(20 /*0x14*/));
    // 0044fce6  8b90b8000000           -mov edx, dword ptr [eax + 0xb8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(184) /* 0xb8 */);
    // 0044fcec  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0044fcef  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0044fcf2  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0044fcf5  39c2                   +cmp edx, eax
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
    // 0044fcf7  7f1a                   -jg 0x44fd13
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0044fd13;
    }
    // 0044fcf9  8b457e                 -mov eax, dword ptr [ebp + 0x7e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 0044fcfc  66c780b80000000000     -mov word ptr [eax + 0xb8], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(184) /* 0xb8 */) = 0 /*0x0*/;
    // 0044fd05  8b557e                 -mov edx, dword ptr [ebp + 0x7e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 0044fd08  668b4006               -mov ax, word ptr [eax + 6]
    cpu.ax = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 0044fd0c  668982ba000000         -mov word ptr [edx + 0xba], ax
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(186) /* 0xba */) = cpu.ax;
L_0x0044fd13:
    // 0044fd13  8b457e                 -mov eax, dword ptr [ebp + 0x7e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 0044fd16  6683b8b800000003       +cmp word ptr [eax + 0xb8], 3
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(184) /* 0xb8 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(3 /*0x3*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0044fd1e  0f842f0a0000           -je 0x450753
    if (cpu.flags.zf)
    {
        goto L_0x00450753;
    }
    // 0044fd24  e8c7a0ffff             -call 0x449df0
    cpu.esp -= 4;
    sub_449df0(app, cpu);
    if (cpu.terminate) return;
    // 0044fd29  89457a                 -mov dword ptr [ebp + 0x7a], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(122) /* 0x7a */) = cpu.eax;
    // 0044fd2c  8b457e                 -mov eax, dword ptr [ebp + 0x7e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 0044fd2f  8b80a2000000           -mov eax, dword ptr [eax + 0xa2]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(162) /* 0xa2 */);
    // 0044fd35  8b1518945500           -mov edx, dword ptr [0x559418]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5608472) /* 0x559418 */);
    // 0044fd3b  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0044fd3e  39d0                   +cmp eax, edx
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
    // 0044fd40  7516                   -jne 0x44fd58
    if (!cpu.flags.zf)
    {
        goto L_0x0044fd58;
    }
    // 0044fd42  8b457e                 -mov eax, dword ptr [ebp + 0x7e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 0044fd45  8b80a4000000           -mov eax, dword ptr [eax + 0xa4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(164) /* 0xa4 */);
    // 0044fd4b  8b1d1c945500           -mov ebx, dword ptr [0x55941c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5608476) /* 0x55941c */);
    // 0044fd51  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0044fd54  39d8                   +cmp eax, ebx
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
    // 0044fd56  740c                   -je 0x44fd64
    if (cpu.flags.zf)
    {
        goto L_0x0044fd64;
    }
L_0x0044fd58:
    // 0044fd58  8b457e                 -mov eax, dword ptr [ebp + 0x7e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 0044fd5b  66c780b40000000000     -mov word ptr [eax + 0xb4], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(180) /* 0xb4 */) = 0 /*0x0*/;
L_0x0044fd64:
    // 0044fd64  8b557e                 -mov edx, dword ptr [ebp + 0x7e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 0044fd67  66a118945500           -mov ax, word ptr [0x559418]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5608472) /* 0x559418 */);
    // 0044fd6d  668982a4000000         -mov word ptr [edx + 0xa4], ax
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(164) /* 0xa4 */) = cpu.ax;
    // 0044fd74  66a11c945500           -mov ax, word ptr [0x55941c]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5608476) /* 0x55941c */);
    // 0044fd7a  668982a6000000         -mov word ptr [edx + 0xa6], ax
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(166) /* 0xa6 */) = cpu.ax;
    // 0044fd81  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044fd83  e8e80b0000             -call 0x450970
    cpu.esp -= 4;
    sub_450970(app, cpu);
    if (cpu.terminate) return;
    // 0044fd88  8b151c945500           -mov edx, dword ptr [0x55941c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5608476) /* 0x55941c */);
    // 0044fd8e  a118945500             -mov eax, dword ptr [0x559418]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5608472) /* 0x559418 */);
    // 0044fd93  e8d8f8ffff             -call 0x44f670
    cpu.esp -= 4;
    sub_44f670(app, cpu);
    if (cpu.terminate) return;
    // 0044fd98  8b457e                 -mov eax, dword ptr [ebp + 0x7e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 0044fd9b  8b80b4000000           -mov eax, dword ptr [eax + 0xb4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */);
    // 0044fda1  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0044fda4  e887faffff             -call 0x44f830
    cpu.esp -= 4;
    sub_44f830(app, cpu);
    if (cpu.terminate) return;
    // 0044fda9  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0044fdab  89456a                 -mov dword ptr [ebp + 0x6a], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(106) /* 0x6a */) = cpu.eax;
    // 0044fdae  eb05                   -jmp 0x44fdb5
    goto L_0x0044fdb5;
L_0x0044fdb0:
    // 0044fdb0  83f806                 +cmp eax, 6
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
    // 0044fdb3  7d19                   -jge 0x44fdce
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0044fdce;
    }
L_0x0044fdb5:
    // 0044fdb5  8b7d7e                 -mov edi, dword ptr [ebp + 0x7e]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 0044fdb8  8d1400                 -lea edx, [eax + eax]
    cpu.edx = x86::reg32(cpu.eax + cpu.eax * 1);
    // 0044fdbb  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0044fdbd  8b523a                 -mov edx, dword ptr [edx + 0x3a]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(58) /* 0x3a */);
    // 0044fdc0  8b4d6a                 -mov ecx, dword ptr [ebp + 0x6a]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(106) /* 0x6a */);
    // 0044fdc3  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0044fdc6  01d1                   +add ecx, edx
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
    // 0044fdc8  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0044fdc9  894d6a                 -mov dword ptr [ebp + 0x6a], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(106) /* 0x6a */) = cpu.ecx;
    // 0044fdcc  ebe2                   -jmp 0x44fdb0
    goto L_0x0044fdb0;
L_0x0044fdce:
    // 0044fdce  8b457e                 -mov eax, dword ptr [ebp + 0x7e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 0044fdd1  8b557e                 -mov edx, dword ptr [ebp + 0x7e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 0044fdd4  8b4048                 -mov eax, dword ptr [eax + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    // 0044fdd7  8b5246                 -mov edx, dword ptr [edx + 0x46]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(70) /* 0x46 */);
    // 0044fdda  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0044fddd  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0044fde0  40                     -inc eax
    (cpu.eax)++;
    // 0044fde1  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0044fde4  a118945500             -mov eax, dword ptr [0x559418]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5608472) /* 0x559418 */);
    // 0044fde9  895566                 -mov dword ptr [ebp + 0x66], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(102) /* 0x66 */) = cpu.edx;
    // 0044fdec  8b151c945500           -mov edx, dword ptr [0x55941c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5608476) /* 0x55941c */);
    // 0044fdf2  e8d9faffff             -call 0x44f8d0
    cpu.esp -= 4;
    sub_44f8d0(app, cpu);
    if (cpu.terminate) return;
    // 0044fdf7  894556                 -mov dword ptr [ebp + 0x56], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(86) /* 0x56 */) = cpu.eax;
    // 0044fdfa  83f801                 +cmp eax, 1
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
    // 0044fdfd  7e07                   -jle 0x44fe06
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0044fe06;
    }
    // 0044fdff  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0044fe04  eb02                   -jmp 0x44fe08
    goto L_0x0044fe08;
L_0x0044fe06:
    // 0044fe06  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0044fe08:
    // 0044fe08  bfaa0000ff             -mov edi, 0xff0000aa
    cpu.edi = 4278190250 /*0xff0000aa*/;
    // 0044fe0d  8b756a                 -mov esi, dword ptr [ebp + 0x6a]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(106) /* 0x6a */);
    // 0044fe10  8b557e                 -mov edx, dword ptr [ebp + 0x7e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 0044fe13  8b457e                 -mov eax, dword ptr [ebp + 0x7e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 0044fe16  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0044fe1b  895d46                 -mov dword ptr [ebp + 0x46], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(70) /* 0x46 */) = cpu.ebx;
    // 0044fe1e  bb2894d5ff             -mov ebx, 0xffd59428
    cpu.ebx = 4292187176 /*0xffd59428*/;
    // 0044fe23  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0044fe24  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0044fe27  8b5206                 -mov edx, dword ptr [edx + 6]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(6) /* 0x6 */);
    // 0044fe2a  8b80b8000000           -mov eax, dword ptr [eax + 0xb8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(184) /* 0xb8 */);
    // 0044fe30  895d62                 -mov dword ptr [ebp + 0x62], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(98) /* 0x62 */) = cpu.ebx;
    // 0044fe33  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0044fe34  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0044fe37  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0044fe38  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0044fe3b  83ea02                 -sub edx, 2
    (cpu.edx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0044fe3e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0044fe3f  83e802                 -sub eax, 2
    (cpu.eax) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0044fe42  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0044fe44  e8178a0800             -call 0x4d8860
    cpu.esp -= 4;
    sub_4d8860(app, cpu);
    if (cpu.terminate) return;
    // 0044fe49  8b457e                 -mov eax, dword ptr [ebp + 0x7e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 0044fe4c  8b4006                 -mov eax, dword ptr [eax + 6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 0044fe4f  8b5566                 -mov edx, dword ptr [ebp + 0x66]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(102) /* 0x66 */);
    // 0044fe52  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0044fe55  682894d5ff             -push 0xffd59428
    app->getMemory<x86::reg32>(cpu.esp-4) = 4292187176 /*0xffd59428*/;
    cpu.esp -= 4;
    // 0044fe5a  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0044fe5c  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0044fe61  8d5002                 -lea edx, [eax + 2]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0044fe64  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0044fe66  8b457e                 -mov eax, dword ptr [ebp + 0x7e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 0044fe69  682894d5ff             -push 0xffd59428
    app->getMemory<x86::reg32>(cpu.esp-4) = 4292187176 /*0xffd59428*/;
    cpu.esp -= 4;
    // 0044fe6e  8b7566                 -mov esi, dword ptr [ebp + 0x66]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(102) /* 0x66 */);
    // 0044fe71  8b80b8000000           -mov eax, dword ptr [eax + 0xb8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(184) /* 0xb8 */);
    // 0044fe77  682894d5ff             -push 0xffd59428
    app->getMemory<x86::reg32>(cpu.esp-4) = 4292187176 /*0xffd59428*/;
    cpu.esp -= 4;
    // 0044fe7c  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0044fe7f  682894d5ff             -push 0xffd59428
    app->getMemory<x86::reg32>(cpu.esp-4) = 4292187176 /*0xffd59428*/;
    cpu.esp -= 4;
    // 0044fe84  83e802                 -sub eax, 2
    (cpu.eax) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0044fe87  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0044fe8a  e8d1890800             -call 0x4d8860
    cpu.esp -= 4;
    sub_4d8860(app, cpu);
    if (cpu.terminate) return;
    // 0044fe8f  682894d5ff             -push 0xffd59428
    app->getMemory<x86::reg32>(cpu.esp-4) = 4292187176 /*0xffd59428*/;
    cpu.esp -= 4;
    // 0044fe94  8b557e                 -mov edx, dword ptr [ebp + 0x7e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 0044fe97  8b457e                 -mov eax, dword ptr [ebp + 0x7e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 0044fe9a  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0044fe9f  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0044fea1  682894d5ff             -push 0xffd59428
    app->getMemory<x86::reg32>(cpu.esp-4) = 4292187176 /*0xffd59428*/;
    cpu.esp -= 4;
    // 0044fea6  8b5206                 -mov edx, dword ptr [edx + 6]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(6) /* 0x6 */);
    // 0044fea9  8b80b8000000           -mov eax, dword ptr [eax + 0xb8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(184) /* 0xb8 */);
    // 0044feaf  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0044feb0  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0044feb3  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0044feb6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0044feb7  83ea02                 -sub edx, 2
    (cpu.edx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0044feba  83e802                 -sub eax, 2
    (cpu.eax) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0044febd  e89e890800             -call 0x4d8860
    cpu.esp -= 4;
    sub_4d8860(app, cpu);
    if (cpu.terminate) return;
    // 0044fec2  682894d5ff             -push 0xffd59428
    app->getMemory<x86::reg32>(cpu.esp-4) = 4292187176 /*0xffd59428*/;
    cpu.esp -= 4;
    // 0044fec7  8b557e                 -mov edx, dword ptr [ebp + 0x7e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 0044feca  8b457e                 -mov eax, dword ptr [ebp + 0x7e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 0044fecd  8b4d6a                 -mov ecx, dword ptr [ebp + 0x6a]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(106) /* 0x6a */);
    // 0044fed0  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0044fed5  682894d5ff             -push 0xffd59428
    app->getMemory<x86::reg32>(cpu.esp-4) = 4292187176 /*0xffd59428*/;
    cpu.esp -= 4;
    // 0044feda  8b5206                 -mov edx, dword ptr [edx + 6]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(6) /* 0x6 */);
    // 0044fedd  8b80b8000000           -mov eax, dword ptr [eax + 0xb8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(184) /* 0xb8 */);
    // 0044fee3  682894d5ff             -push 0xffd59428
    app->getMemory<x86::reg32>(cpu.esp-4) = 4292187176 /*0xffd59428*/;
    cpu.esp -= 4;
    // 0044fee8  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0044feeb  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0044feee  682894d5ff             -push 0xffd59428
    app->getMemory<x86::reg32>(cpu.esp-4) = 4292187176 /*0xffd59428*/;
    cpu.esp -= 4;
    // 0044fef3  83ea02                 -sub edx, 2
    (cpu.edx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0044fef6  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0044fef8  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0044fefa  e861890800             -call 0x4d8860
    cpu.esp -= 4;
    sub_4d8860(app, cpu);
    if (cpu.terminate) return;
    // 0044feff  8b557e                 -mov edx, dword ptr [ebp + 0x7e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 0044ff02  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0044ff03  8b457e                 -mov eax, dword ptr [ebp + 0x7e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 0044ff06  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0044ff0b  682894d5ff             -push 0xffd59428
    app->getMemory<x86::reg32>(cpu.esp-4) = 4292187176 /*0xffd59428*/;
    cpu.esp -= 4;
    // 0044ff10  8b5206                 -mov edx, dword ptr [edx + 6]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(6) /* 0x6 */);
    // 0044ff13  8b4046                 -mov eax, dword ptr [eax + 0x46]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(70) /* 0x46 */);
    // 0044ff16  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0044ff19  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0044ff1c  682894d5ff             -push 0xffd59428
    app->getMemory<x86::reg32>(cpu.esp-4) = 4292187176 /*0xffd59428*/;
    cpu.esp -= 4;
    // 0044ff21  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0044ff23  8b457e                 -mov eax, dword ptr [ebp + 0x7e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 0044ff26  8b5d6a                 -mov ebx, dword ptr [ebp + 0x6a]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(106) /* 0x6a */);
    // 0044ff29  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0044ff2a  8b80b8000000           -mov eax, dword ptr [eax + 0xb8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(184) /* 0xb8 */);
    // 0044ff30  4a                     -dec edx
    (cpu.edx)--;
    // 0044ff31  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0044ff34  e827890800             -call 0x4d8860
    cpu.esp -= 4;
    sub_4d8860(app, cpu);
    if (cpu.terminate) return;
    // 0044ff39  8b457e                 -mov eax, dword ptr [ebp + 0x7e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 0044ff3c  8b4048                 -mov eax, dword ptr [eax + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    // 0044ff3f  8b5d56                 -mov ebx, dword ptr [ebp + 0x56]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(86) /* 0x56 */);
    // 0044ff42  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0044ff45  39d8                   +cmp eax, ebx
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
    // 0044ff47  7d27                   -jge 0x44ff70
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0044ff70;
    }
    // 0044ff49  682894d5ff             -push 0xffd59428
    app->getMemory<x86::reg32>(cpu.esp-4) = 4292187176 /*0xffd59428*/;
    cpu.esp -= 4;
    // 0044ff4e  8b557e                 -mov edx, dword ptr [ebp + 0x7e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 0044ff51  8b457e                 -mov eax, dword ptr [ebp + 0x7e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 0044ff54  bb12000000             -mov ebx, 0x12
    cpu.ebx = 18 /*0x12*/;
    // 0044ff59  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0044ff5b  8b527a                 -mov edx, dword ptr [edx + 0x7a]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(122) /* 0x7a */);
    // 0044ff5e  8b407c                 -mov eax, dword ptr [eax + 0x7c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(124) /* 0x7c */);
    // 0044ff61  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0044ff64  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0044ff67  4a                     -dec edx
    (cpu.edx)--;
    // 0044ff68  83e803                 -sub eax, 3
    (cpu.eax) -= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0044ff6b  e8c0890800             -call 0x4d8930
    cpu.esp -= 4;
    sub_4d8930(app, cpu);
    if (cpu.terminate) return;
L_0x0044ff70:
    // 0044ff70  8b557e                 -mov edx, dword ptr [ebp + 0x7e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 0044ff73  8b457e                 -mov eax, dword ptr [ebp + 0x7e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 0044ff76  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0044ff78  8b5206                 -mov edx, dword ptr [edx + 6]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(6) /* 0x6 */);
    // 0044ff7b  8b4046                 -mov eax, dword ptr [eax + 0x46]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(70) /* 0x46 */);
    // 0044ff7e  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0044ff81  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0044ff84  897552                 -mov dword ptr [ebp + 0x52], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(82) /* 0x52 */) = cpu.esi;
    // 0044ff87  8d3402                 -lea esi, [edx + eax]
    cpu.esi = x86::reg32(cpu.edx + cpu.eax * 1);
L_0x0044ff8a:
    // 0044ff8a  8b457e                 -mov eax, dword ptr [ebp + 0x7e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 0044ff8d  8b4048                 -mov eax, dword ptr [eax + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    // 0044ff90  8b5552                 -mov edx, dword ptr [ebp + 0x52]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(82) /* 0x52 */);
    // 0044ff93  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0044ff96  39d0                   +cmp eax, edx
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
    // 0044ff98  7e32                   -jle 0x44ffcc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0044ffcc;
    }
    // 0044ff9a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0044ff9b  8b4d62                 -mov ecx, dword ptr [ebp + 0x62]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(98) /* 0x62 */);
    // 0044ff9e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0044ff9f  8b457e                 -mov eax, dword ptr [ebp + 0x7e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 0044ffa2  8b5d6a                 -mov ebx, dword ptr [ebp + 0x6a]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(106) /* 0x6a */);
    // 0044ffa5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0044ffa6  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0044ffa8  8b80b8000000           -mov eax, dword ptr [eax + 0xb8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(184) /* 0xb8 */);
    // 0044ffae  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0044ffaf  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0044ffb2  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0044ffb7  e8a4880800             -call 0x4d8860
    cpu.esp -= 4;
    sub_4d8860(app, cpu);
    if (cpu.terminate) return;
    // 0044ffbc  8b457e                 -mov eax, dword ptr [ebp + 0x7e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 0044ffbf  8b4046                 -mov eax, dword ptr [eax + 0x46]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(70) /* 0x46 */);
    // 0044ffc2  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0044ffc5  01c6                   +add esi, eax
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0044ffc7  ff4552                 +inc dword ptr [ebp + 0x52]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(82) /* 0x52 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0044ffca  ebbe                   -jmp 0x44ff8a
    goto L_0x0044ff8a;
L_0x0044ffcc:
    // 0044ffcc  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0044ffd1  8b457e                 -mov eax, dword ptr [ebp + 0x7e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 0044ffd4  89555a                 -mov dword ptr [ebp + 0x5a], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(90) /* 0x5a */) = cpu.edx;
    // 0044ffd7  8b557e                 -mov edx, dword ptr [ebp + 0x7e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 0044ffda  8b403a                 -mov eax, dword ptr [eax + 0x3a]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(58) /* 0x3a */);
    // 0044ffdd  8b92b8000000           -mov edx, dword ptr [edx + 0xb8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(184) /* 0xb8 */);
    // 0044ffe3  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0044ffe6  c1fa10                 +sar edx, 0x10
    {
        x86::reg8 tmp = 16 /*0x10*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 0044ffe9  8d3402                 -lea esi, [edx + eax]
    cpu.esi = x86::reg32(cpu.edx + cpu.eax * 1);
    // 0044ffec  eb06                   -jmp 0x44fff4
    goto L_0x0044fff4;
L_0x0044ffee:
    // 0044ffee  837d5a06               +cmp dword ptr [ebp + 0x5a], 6
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(90) /* 0x5a */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044fff2  7d3d                   -jge 0x450031
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00450031;
    }
L_0x0044fff4:
    // 0044fff4  8b5d62                 -mov ebx, dword ptr [ebp + 0x62]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(98) /* 0x62 */);
    // 0044fff7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0044fff8  8b4d66                 -mov ecx, dword ptr [ebp + 0x66]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(102) /* 0x66 */);
    // 0044fffb  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0044fffc  8b557e                 -mov edx, dword ptr [ebp + 0x7e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 0044ffff  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00450001  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00450002  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00450005  8b5206                 -mov edx, dword ptr [edx + 6]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(6) /* 0x6 */);
    // 00450008  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00450009  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0045000c  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00450011  e84a880800             -call 0x4d8860
    cpu.esp -= 4;
    sub_4d8860(app, cpu);
    if (cpu.terminate) return;
    // 00450016  8b455a                 -mov eax, dword ptr [ebp + 0x5a]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(90) /* 0x5a */);
    // 00450019  8b557e                 -mov edx, dword ptr [ebp + 0x7e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 0045001c  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 0045001e  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00450020  8b4d5a                 -mov ecx, dword ptr [ebp + 0x5a]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(90) /* 0x5a */);
    // 00450023  8b403a                 -mov eax, dword ptr [eax + 0x3a]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(58) /* 0x3a */);
    // 00450026  41                     -inc ecx
    (cpu.ecx)++;
    // 00450027  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0045002a  894d5a                 -mov dword ptr [ebp + 0x5a], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(90) /* 0x5a */) = cpu.ecx;
    // 0045002d  01c6                   +add esi, eax
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0045002f  ebbd                   -jmp 0x44ffee
    goto L_0x0044ffee;
L_0x00450031:
    // 00450031  8b457e                 -mov eax, dword ptr [ebp + 0x7e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 00450034  6683b8b800000000       +cmp word ptr [eax + 0xb8], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(184) /* 0xb8 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0045003c  750e                   -jne 0x45004c
    if (!cpu.flags.zf)
    {
        goto L_0x0045004c;
    }
    // 0045003e  837d4600               +cmp dword ptr [ebp + 0x46], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(70) /* 0x46 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00450042  7408                   -je 0x45004c
    if (cpu.flags.zf)
    {
        goto L_0x0045004c;
    }
    // 00450044  8b5566                 -mov edx, dword ptr [ebp + 0x66]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(102) /* 0x66 */);
    // 00450047  e8b4fbffff             -call 0x44fc00
    cpu.esp -= 4;
    sub_44fc00(app, cpu);
    if (cpu.terminate) return;
L_0x0045004c:
    // 0045004c  bf03000000             -mov edi, 3
    cpu.edi = 3 /*0x3*/;
    // 00450051  be05000000             -mov esi, 5
    cpu.esi = 5 /*0x5*/;
    // 00450056  8b557e                 -mov edx, dword ptr [ebp + 0x7e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 00450059  897d1e                 -mov dword ptr [ebp + 0x1e], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(30) /* 0x1e */) = cpu.edi;
    // 0045005c  897d22                 -mov dword ptr [ebp + 0x22], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(34) /* 0x22 */) = cpu.edi;
    // 0045005f  897526                 -mov dword ptr [ebp + 0x26], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(38) /* 0x26 */) = cpu.esi;
    // 00450062  89752a                 -mov dword ptr [ebp + 0x2a], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(42) /* 0x2a */) = cpu.esi;
    // 00450065  89752e                 -mov dword ptr [ebp + 0x2e], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(46) /* 0x2e */) = cpu.esi;
    // 00450068  89751a                 -mov dword ptr [ebp + 0x1a], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(26) /* 0x1a */) = cpu.esi;
    // 0045006b  8b523a                 -mov edx, dword ptr [edx + 0x3a]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(58) /* 0x3a */);
    // 0045006e  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00450071  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00450073  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00450076  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00450078  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0045007a  897d06                 -mov dword ptr [ebp + 6], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(6) /* 0x6 */) = cpu.edi;
    // 0045007d  8b557e                 -mov edx, dword ptr [ebp + 0x7e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 00450080  897d0a                 -mov dword ptr [ebp + 0xa], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(10) /* 0xa */) = cpu.edi;
    // 00450083  894502                 -mov dword ptr [ebp + 2], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(2) /* 0x2 */) = cpu.eax;
    // 00450086  8b5240                 -mov edx, dword ptr [edx + 0x40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(64) /* 0x40 */);
    // 00450089  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0045008c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045008e  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00450091  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00450093  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00450095  8b557e                 -mov edx, dword ptr [ebp + 0x7e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 00450098  89450e                 -mov dword ptr [ebp + 0xe], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(14) /* 0xe */) = cpu.eax;
    // 0045009b  8b5242                 -mov edx, dword ptr [edx + 0x42]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(66) /* 0x42 */);
    // 0045009e  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004500a1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004500a3  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004500a6  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004500a8  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004500aa  8b557e                 -mov edx, dword ptr [ebp + 0x7e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 004500ad  894512                 -mov dword ptr [ebp + 0x12], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(18) /* 0x12 */) = cpu.eax;
    // 004500b0  8b5244                 -mov edx, dword ptr [edx + 0x44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(68) /* 0x44 */);
    // 004500b3  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004500b6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004500b8  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004500bb  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004500bd  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004500bf  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 004500c1  31fe                   +xor esi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 004500c3  894516                 -mov dword ptr [ebp + 0x16], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(22) /* 0x16 */) = cpu.eax;
    // 004500c6  e99f000000             -jmp 0x45016a
    goto L_0x0045016a;
L_0x004500cb:
    // 004500cb  8b5d4a                 -mov ebx, dword ptr [ebp + 0x4a]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(74) /* 0x4a */);
    // 004500ce  83c04c                 -add eax, 0x4c
    (cpu.eax) += x86::reg32(x86::sreg32(76 /*0x4c*/));
    // 004500d1  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004500d3  e818c10400             -call 0x49c1f0
    cpu.esp -= 4;
    sub_49c1f0(app, cpu);
    if (cpu.terminate) return;
    // 004500d8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004500da  7407                   -je 0x4500e3
    if (cpu.flags.zf)
    {
        goto L_0x004500e3;
    }
    // 004500dc  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004500e1  eb02                   -jmp 0x4500e5
    goto L_0x004500e5;
L_0x004500e3:
    // 004500e3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004500e5:
    // 004500e5  89453e                 -mov dword ptr [ebp + 0x3e], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(62) /* 0x3e */) = cpu.eax;
    // 004500e8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004500ea  7441                   -je 0x45012d
    if (cpu.flags.zf)
    {
        goto L_0x0045012d;
    }
    // 004500ec  8b457e                 -mov eax, dword ptr [ebp + 0x7e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 004500ef  8d14f500000000         -lea edx, [esi*8]
    cpu.edx = x86::reg32(cpu.esi * 8);
    // 004500f6  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004500f8  8b4250                 -mov eax, dword ptr [edx + 0x50]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(80) /* 0x50 */);
    // 004500fb  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004500fe  48                     -dec eax
    (cpu.eax)--;
    // 004500ff  894532                 -mov dword ptr [ebp + 0x32], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(50) /* 0x32 */) = cpu.eax;
    // 00450102  8b424e                 -mov eax, dword ptr [edx + 0x4e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(78) /* 0x4e */);
    // 00450105  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00450108  8d58ff                 -lea ebx, [eax - 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 0045010b  8b424a                 -mov eax, dword ptr [edx + 0x4a]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(74) /* 0x4a */);
    // 0045010e  8b524c                 -mov edx, dword ptr [edx + 0x4c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(76) /* 0x4c */);
    // 00450111  6840e4ffff             -push 0xffffe440
    app->getMemory<x86::reg32>(cpu.esp-4) = 4294960192 /*0xffffe440*/;
    cpu.esp -= 4;
    // 00450116  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00450119  8b4d32                 -mov ecx, dword ptr [ebp + 0x32]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(50) /* 0x32 */);
    // 0045011c  42                     -inc edx
    (cpu.edx)++;
    // 0045011d  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00450120  895532                 -mov dword ptr [ebp + 0x32], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(50) /* 0x32 */) = cpu.edx;
    // 00450123  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00450125  8b4532                 -mov eax, dword ptr [ebp + 0x32]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(50) /* 0x32 */);
    // 00450128  e803880800             -call 0x4d8930
    cpu.esp -= 4;
    sub_4d8930(app, cpu);
    if (cpu.terminate) return;
L_0x0045012d:
    // 0045012d  837d7a00               +cmp dword ptr [ebp + 0x7a], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(122) /* 0x7a */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00450131  7407                   -je 0x45013a
    if (cpu.flags.zf)
    {
        goto L_0x0045013a;
    }
    // 00450133  b8964a0000             -mov eax, 0x4a96
    cpu.eax = 19094 /*0x4a96*/;
    // 00450138  eb12                   -jmp 0x45014c
    goto L_0x0045014c;
L_0x0045013a:
    // 0045013a  837d3e00               +cmp dword ptr [ebp + 0x3e], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(62) /* 0x3e */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045013e  7507                   -jne 0x450147
    if (!cpu.flags.zf)
    {
        goto L_0x00450147;
    }
    // 00450140  b82894d5ff             -mov eax, 0xffd59428
    cpu.eax = 4292187176 /*0xffd59428*/;
    // 00450145  eb05                   -jmp 0x45014c
    goto L_0x0045014c;
L_0x00450147:
    // 00450147  b840e4ff00             -mov eax, 0xffe440
    cpu.eax = 16770112 /*0xffe440*/;
L_0x0045014c:
    // 0045014c  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 00450151  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00450152  8b5cb51a               -mov ebx, dword ptr [ebp + esi*4 + 0x1a]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(26) /* 0x1a */ + cpu.esi * 4);
    // 00450156  8b5542                 -mov edx, dword ptr [ebp + 0x42]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(66) /* 0x42 */);
    // 00450159  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045015a  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0045015c  8b5d3a                 -mov ebx, dword ptr [ebp + 0x3a]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(58) /* 0x3a */);
    // 0045015f  46                     -inc esi
    (cpu.esi)++;
    // 00450160  e82b200000             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
    // 00450165  83fe06                 +cmp esi, 6
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
    // 00450168  7d5f                   -jge 0x4501c9
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004501c9;
    }
L_0x0045016a:
    // 0045016a  8b4d7e                 -mov ecx, dword ptr [ebp + 0x7e]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 0045016d  8d04f500000000         -lea eax, [esi*8]
    cpu.eax = x86::reg32(cpu.esi * 8);
    // 00450174  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00450176  89454a                 -mov dword ptr [ebp + 0x4a], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(74) /* 0x4a */) = cpu.eax;
    // 00450179  8b414c                 -mov eax, dword ptr [ecx + 0x4c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(76) /* 0x4c */);
    // 0045017c  8b54b502               -mov edx, dword ptr [ebp + esi*4 + 2]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(2) /* 0x2 */ + cpu.esi * 4);
    // 00450180  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00450183  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00450185  895542                 -mov dword ptr [ebp + 0x42], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(66) /* 0x42 */) = cpu.edx;
    // 00450188  8b5150                 -mov edx, dword ptr [ecx + 0x50]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(80) /* 0x50 */);
    // 0045018b  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0045018e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00450190  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00450193  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00450195  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00450197  8b514a                 -mov edx, dword ptr [ecx + 0x4a]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(74) /* 0x4a */);
    // 0045019a  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0045019d  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0045019f  83e805                 -sub eax, 5
    (cpu.eax) -= x86::reg32(x86::sreg32(5 /*0x5*/));
    // 004501a2  89453a                 -mov dword ptr [ebp + 0x3a], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(58) /* 0x3a */) = cpu.eax;
    // 004501a5  8b457e                 -mov eax, dword ptr [ebp + 0x7e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 004501a8  8b5546                 -mov edx, dword ptr [ebp + 0x46]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(70) /* 0x46 */);
    // 004501ab  8bbcb08c000000         -mov edi, dword ptr [eax + esi*4 + 0x8c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(140) /* 0x8c */ + cpu.esi * 4);
    // 004501b2  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004501b4  0f8429ffffff           -je 0x4500e3
    if (cpu.flags.zf)
    {
        goto L_0x004500e3;
    }
    // 004501ba  837d3600               +cmp dword ptr [ebp + 0x36], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(54) /* 0x36 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004501be  0f8507ffffff           -jne 0x4500cb
    if (!cpu.flags.zf)
    {
        goto L_0x004500cb;
    }
    // 004501c4  e91affffff             -jmp 0x4500e3
    goto L_0x004500e3;
L_0x004501c9:
    // 004501c9  8b557e                 -mov edx, dword ptr [ebp + 0x7e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 004501cc  8b457e                 -mov eax, dword ptr [ebp + 0x7e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 004501cf  8b5246                 -mov edx, dword ptr [edx + 0x46]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(70) /* 0x46 */);
    // 004501d2  8b4006                 -mov eax, dword ptr [eax + 6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 004501d5  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004501d8  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004501db  8d0c10                 -lea ecx, [eax + edx]
    cpu.ecx = x86::reg32(cpu.eax + cpu.edx * 1);
    // 004501de  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004501e0  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004501e3  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004501e5  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004501e7  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004501e9  83e805                 -sub eax, 5
    (cpu.eax) -= x86::reg32(x86::sreg32(5 /*0x5*/));
    // 004501ec  894576                 -mov dword ptr [ebp + 0x76], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(118) /* 0x76 */) = cpu.eax;
    // 004501ef  8b457e                 -mov eax, dword ptr [ebp + 0x7e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 004501f2  8b80b2000000           -mov eax, dword ptr [eax + 0xb2]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(178) /* 0xb2 */);
    // 004501f8  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004501fa  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004501fd  89754e                 -mov dword ptr [ebp + 0x4e], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(78) /* 0x4e */) = cpu.esi;
    // 00450200  89455e                 -mov dword ptr [ebp + 0x5e], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(94) /* 0x5e */) = cpu.eax;
L_0x00450203:
    // 00450203  8b457e                 -mov eax, dword ptr [ebp + 0x7e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 00450206  8b4048                 -mov eax, dword ptr [eax + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    // 00450209  8b7d4e                 -mov edi, dword ptr [ebp + 0x4e]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(78) /* 0x4e */);
    // 0045020c  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0045020f  39f8                   +cmp eax, edi
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
    // 00450211  0f8ea4030000           -jle 0x4505bb
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004505bb;
    }
    // 00450217  8b455e                 -mov eax, dword ptr [ebp + 0x5e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(94) /* 0x5e */);
    // 0045021a  83f80a                 +cmp eax, 0xa
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
    // 0045021d  0f8d98030000           -jge 0x4505bb
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004505bb;
    }
    // 00450223  e8e8f6ffff             -call 0x44f910
    cpu.esp -= 4;
    sub_44f910(app, cpu);
    if (cpu.terminate) return;
    // 00450228  894572                 -mov dword ptr [ebp + 0x72], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(114) /* 0x72 */) = cpu.eax;
    // 0045022b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045022d  0f8488030000           -je 0x4505bb
    if (cpu.flags.zf)
    {
        goto L_0x004505bb;
    }
    // 00450233  8b557e                 -mov edx, dword ptr [ebp + 0x7e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 00450236  8b92b8000000           -mov edx, dword ptr [edx + 0xb8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(184) /* 0xb8 */);
    // 0045023c  8b4d02                 -mov ecx, dword ptr [ebp + 2]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(2) /* 0x2 */);
    // 0045023f  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00450242  8b5d7a                 -mov ebx, dword ptr [ebp + 0x7a]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(122) /* 0x7a */);
    // 00450245  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00450247  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00450249  7407                   -je 0x450252
    if (cpu.flags.zf)
    {
        goto L_0x00450252;
    }
    // 0045024b  b8964a0000             -mov eax, 0x4a96
    cpu.eax = 19094 /*0x4a96*/;
    // 00450250  eb05                   -jmp 0x450257
    goto L_0x00450257;
L_0x00450252:
    // 00450252  b8fd9d64ff             -mov eax, 0xff649dfd
    cpu.eax = 4284784125 /*0xff649dfd*/;
L_0x00450257:
    // 00450257  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00450258  8b4572                 -mov eax, dword ptr [ebp + 0x72]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(114) /* 0x72 */);
    // 0045025b  8b751a                 -mov esi, dword ptr [ebp + 0x1a]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(26) /* 0x1a */);
    // 0045025e  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 00450263  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00450265  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00450266  83c030                 -add eax, 0x30
    (cpu.eax) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 00450269  8b5d76                 -mov ebx, dword ptr [ebp + 0x76]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(118) /* 0x76 */);
    // 0045026c  e8df150800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00450271  e81a1f0000             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
    // 00450276  8b557e                 -mov edx, dword ptr [ebp + 0x7e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 00450279  8b457e                 -mov eax, dword ptr [ebp + 0x7e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 0045027c  8b92b8000000           -mov edx, dword ptr [edx + 0xb8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(184) /* 0xb8 */);
    // 00450282  8b403a                 -mov eax, dword ptr [eax + 0x3a]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(58) /* 0x3a */);
    // 00450285  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00450288  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0045028b  8b7d06                 -mov edi, dword ptr [ebp + 6]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(6) /* 0x6 */);
    // 0045028e  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00450290  a168296600             -mov eax, dword ptr [0x662968]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6695272) /* 0x662968 */);
    // 00450295  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00450297  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00450299  743c                   -je 0x4502d7
    if (cpu.flags.zf)
    {
        goto L_0x004502d7;
    }
    // 0045029b  8b4572                 -mov eax, dword ptr [ebp + 0x72]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(114) /* 0x72 */);
    // 0045029e  6683b81a03000000       +cmp word ptr [eax + 0x31a], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(794) /* 0x31a */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004502a6  742f                   -je 0x4502d7
    if (cpu.flags.zf)
    {
        goto L_0x004502d7;
    }
    // 004502a8  8b457e                 -mov eax, dword ptr [ebp + 0x7e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 004502ab  8b403c                 -mov eax, dword ptr [eax + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(60) /* 0x3c */);
    // 004502ae  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004502b1  83e803                 -sub eax, 3
    (cpu.eax) -= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004502b4  8b4d7a                 -mov ecx, dword ptr [ebp + 0x7a]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(122) /* 0x7a */);
    // 004502b7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004502b8  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004502ba  7407                   -je 0x4502c3
    if (cpu.flags.zf)
    {
        goto L_0x004502c3;
    }
    // 004502bc  b8964a0000             -mov eax, 0x4a96
    cpu.eax = 19094 /*0x4a96*/;
    // 004502c1  eb05                   -jmp 0x4502c8
    goto L_0x004502c8;
L_0x004502c3:
    // 004502c3  b840e4ff00             -mov eax, 0xffe440
    cpu.eax = 16770112 /*0xffe440*/;
L_0x004502c8:
    // 004502c8  8b5d1e                 -mov ebx, dword ptr [ebp + 0x1e]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(30) /* 0x1e */);
    // 004502cb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004502cc  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 004502d1  8b4572                 -mov eax, dword ptr [ebp + 0x72]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(114) /* 0x72 */);
    // 004502d4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004502d5  eb2d                   -jmp 0x450304
    goto L_0x00450304;
L_0x004502d7:
    // 004502d7  8b457e                 -mov eax, dword ptr [ebp + 0x7e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 004502da  8b403c                 -mov eax, dword ptr [eax + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(60) /* 0x3c */);
    // 004502dd  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004502e0  83e803                 -sub eax, 3
    (cpu.eax) -= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004502e3  8b757a                 -mov esi, dword ptr [ebp + 0x7a]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(122) /* 0x7a */);
    // 004502e6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004502e7  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004502e9  7407                   -je 0x4502f2
    if (cpu.flags.zf)
    {
        goto L_0x004502f2;
    }
    // 004502eb  b8964a0000             -mov eax, 0x4a96
    cpu.eax = 19094 /*0x4a96*/;
    // 004502f0  eb05                   -jmp 0x4502f7
    goto L_0x004502f7;
L_0x004502f2:
    // 004502f2  b8fd9d64ff             -mov eax, 0xff649dfd
    cpu.eax = 4284784125 /*0xff649dfd*/;
L_0x004502f7:
    // 004502f7  8b7d1e                 -mov edi, dword ptr [ebp + 0x1e]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(30) /* 0x1e */);
    // 004502fa  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004502fb  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 00450300  8b4572                 -mov eax, dword ptr [ebp + 0x72]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(114) /* 0x72 */);
    // 00450303  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00450304:
    // 00450304  8b5d76                 -mov ebx, dword ptr [ebp + 0x76]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(118) /* 0x76 */);
    // 00450307  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0045030a  e8111e0000             -call 0x452120
    cpu.esp -= 4;
    sub_452120(app, cpu);
    if (cpu.terminate) return;
    // 0045030f  8b557e                 -mov edx, dword ptr [ebp + 0x7e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 00450312  8b457e                 -mov eax, dword ptr [ebp + 0x7e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 00450315  8b92b8000000           -mov edx, dword ptr [edx + 0xb8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(184) /* 0xb8 */);
    // 0045031b  8b403a                 -mov eax, dword ptr [eax + 0x3a]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(58) /* 0x3a */);
    // 0045031e  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00450321  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00450324  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00450326  8b457e                 -mov eax, dword ptr [ebp + 0x7e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 00450329  8b403c                 -mov eax, dword ptr [eax + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(60) /* 0x3c */);
    // 0045032c  8b7572                 -mov esi, dword ptr [ebp + 0x72]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(114) /* 0x72 */);
    // 0045032f  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00450332  8dbd02fdffff           -lea edi, [ebp - 0x2fe]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-766) /* -0x2fe */);
    // 00450338  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0045033a  8b550a                 -mov edx, dword ptr [ebp + 0xa]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(10) /* 0xa */);
    // 0045033d  81c60f010000           -add esi, 0x10f
    (cpu.esi) += x86::reg32(x86::sreg32(271 /*0x10f*/));
    // 00450343  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00450345  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00450346:
    // 00450346  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00450348  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0045034a  3c00                   +cmp al, 0
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
    // 0045034c  7410                   -je 0x45035e
    if (cpu.flags.zf)
    {
        goto L_0x0045035e;
    }
    // 0045034e  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00450351  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00450354  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00450357  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0045035a  3c00                   +cmp al, 0
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
    // 0045035c  75e8                   -jne 0x450346
    if (!cpu.flags.zf)
    {
        goto L_0x00450346;
    }
L_0x0045035e:
    // 0045035e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045035f  8b457e                 -mov eax, dword ptr [ebp + 0x7e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 00450362  8b403e                 -mov eax, dword ptr [eax + 0x3e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(62) /* 0x3e */);
    // 00450365  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00450368  83e803                 -sub eax, 3
    (cpu.eax) -= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0045036b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0045036c  8b457a                 -mov eax, dword ptr [ebp + 0x7a]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(122) /* 0x7a */);
    // 0045036f  89556e                 -mov dword ptr [ebp + 0x6e], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(110) /* 0x6e */) = cpu.edx;
    // 00450372  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00450374  7407                   -je 0x45037d
    if (cpu.flags.zf)
    {
        goto L_0x0045037d;
    }
    // 00450376  b8964a0000             -mov eax, 0x4a96
    cpu.eax = 19094 /*0x4a96*/;
    // 0045037b  eb05                   -jmp 0x450382
    goto L_0x00450382;
L_0x0045037d:
    // 0045037d  b8fd9d64ff             -mov eax, 0xff649dfd
    cpu.eax = 4284784125 /*0xff649dfd*/;
L_0x00450382:
    // 00450382  8b5522                 -mov edx, dword ptr [ebp + 0x22]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(34) /* 0x22 */);
    // 00450385  8b5d76                 -mov ebx, dword ptr [ebp + 0x76]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(118) /* 0x76 */);
    // 00450388  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 0045038d  8b7572                 -mov esi, dword ptr [ebp + 0x72]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(114) /* 0x72 */);
    // 00450390  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00450391  8dbd02fdffff           -lea edi, [ebp - 0x2fe]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-766) /* -0x2fe */);
    // 00450397  8d8502fdffff           -lea eax, [ebp - 0x2fe]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-766) /* -0x2fe */);
    // 0045039d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045039e  83eb0a                 -sub ebx, 0xa
    (cpu.ebx) -= x86::reg32(x86::sreg32(10 /*0xa*/));
    // 004503a1  8b556e                 -mov edx, dword ptr [ebp + 0x6e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(110) /* 0x6e */);
    // 004503a4  81c60f020000           -add esi, 0x20f
    (cpu.esi) += x86::reg32(x86::sreg32(527 /*0x20f*/));
    // 004503aa  e8711d0000             -call 0x452120
    cpu.esp -= 4;
    sub_452120(app, cpu);
    if (cpu.terminate) return;
    // 004503af  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x004503b0:
    // 004503b0  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004503b2  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004503b4  3c00                   +cmp al, 0
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
    // 004503b6  7410                   -je 0x4503c8
    if (cpu.flags.zf)
    {
        goto L_0x004503c8;
    }
    // 004503b8  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004503bb  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004503be  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004503c1  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004503c4  3c00                   +cmp al, 0
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
    // 004503c6  75e8                   -jne 0x4503b0
    if (!cpu.flags.zf)
    {
        goto L_0x004503b0;
    }
L_0x004503c8:
    // 004503c8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004503c9  8b457e                 -mov eax, dword ptr [ebp + 0x7e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 004503cc  8b403e                 -mov eax, dword ptr [eax + 0x3e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(62) /* 0x3e */);
    // 004503cf  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004503d2  83e803                 -sub eax, 3
    (cpu.eax) -= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004503d5  8b4d7a                 -mov ecx, dword ptr [ebp + 0x7a]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(122) /* 0x7a */);
    // 004503d8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004503d9  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004503db  7407                   -je 0x4503e4
    if (cpu.flags.zf)
    {
        goto L_0x004503e4;
    }
    // 004503dd  b8964a0000             -mov eax, 0x4a96
    cpu.eax = 19094 /*0x4a96*/;
    // 004503e2  eb05                   -jmp 0x4503e9
    goto L_0x004503e9;
L_0x004503e4:
    // 004503e4  b8fd9d64ff             -mov eax, 0xff649dfd
    cpu.eax = 4284784125 /*0xff649dfd*/;
L_0x004503e9:
    // 004503e9  8b5d22                 -mov ebx, dword ptr [ebp + 0x22]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(34) /* 0x22 */);
    // 004503ec  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004503ed  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 004503f2  8b556e                 -mov edx, dword ptr [ebp + 0x6e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(110) /* 0x6e */);
    // 004503f5  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004503f6  8b5d76                 -mov ebx, dword ptr [ebp + 0x76]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(118) /* 0x76 */);
    // 004503f9  8d8502fdffff           -lea eax, [ebp - 0x2fe]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-766) /* -0x2fe */);
    // 004503ff  83c305                 -add ebx, 5
    (cpu.ebx) += x86::reg32(x86::sreg32(5 /*0x5*/));
    // 00450402  e8191d0000             -call 0x452120
    cpu.esp -= 4;
    sub_452120(app, cpu);
    if (cpu.terminate) return;
    // 00450407  8b4572                 -mov eax, dword ptr [ebp + 0x72]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(114) /* 0x72 */);
    // 0045040a  8d9502fdffff           -lea edx, [ebp - 0x2fe]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-766) /* -0x2fe */);
    // 00450410  8b8010030000           -mov eax, dword ptr [eax + 0x310]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(784) /* 0x310 */);
    // 00450416  e825ea0700             -call 0x4cee40
    cpu.esp -= 4;
    sub_4cee40(app, cpu);
    if (cpu.terminate) return;
    // 0045041b  8b557e                 -mov edx, dword ptr [ebp + 0x7e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 0045041e  8b457e                 -mov eax, dword ptr [ebp + 0x7e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 00450421  8b92b8000000           -mov edx, dword ptr [edx + 0xb8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(184) /* 0xb8 */);
    // 00450427  8b403a                 -mov eax, dword ptr [eax + 0x3a]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(58) /* 0x3a */);
    // 0045042a  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0045042d  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00450430  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00450432  8b557e                 -mov edx, dword ptr [ebp + 0x7e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 00450435  8b523c                 -mov edx, dword ptr [edx + 0x3c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(60) /* 0x3c */);
    // 00450438  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0045043b  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0045043d  8b457e                 -mov eax, dword ptr [ebp + 0x7e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 00450440  8b403e                 -mov eax, dword ptr [eax + 0x3e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(62) /* 0x3e */);
    // 00450443  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00450446  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00450448  8b550e                 -mov edx, dword ptr [ebp + 0xe]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(14) /* 0xe */);
    // 0045044b  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0045044d  8b757a                 -mov esi, dword ptr [ebp + 0x7a]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(122) /* 0x7a */);
    // 00450450  89556e                 -mov dword ptr [ebp + 0x6e], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(110) /* 0x6e */) = cpu.edx;
    // 00450453  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00450455  7407                   -je 0x45045e
    if (cpu.flags.zf)
    {
        goto L_0x0045045e;
    }
    // 00450457  b8964a0000             -mov eax, 0x4a96
    cpu.eax = 19094 /*0x4a96*/;
    // 0045045c  eb05                   -jmp 0x450463
    goto L_0x00450463;
L_0x0045045e:
    // 0045045e  b8fd9d64ff             -mov eax, 0xff649dfd
    cpu.eax = 4284784125 /*0xff649dfd*/;
L_0x00450463:
    // 00450463  8b7d26                 -mov edi, dword ptr [ebp + 0x26]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(38) /* 0x26 */);
    // 00450466  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00450467  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 0045046c  8b5d76                 -mov ebx, dword ptr [ebp + 0x76]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(118) /* 0x76 */);
    // 0045046f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00450470  8b556e                 -mov edx, dword ptr [ebp + 0x6e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(110) /* 0x6e */);
    // 00450473  8d8502fdffff           -lea eax, [ebp - 0x2fe]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-766) /* -0x2fe */);
    // 00450479  e8121d0000             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
    // 0045047e  8d8502fdffff           -lea eax, [ebp - 0x2fe]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-766) /* -0x2fe */);
    // 00450484  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00450485  8b4572                 -mov eax, dword ptr [ebp + 0x72]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(114) /* 0x72 */);
    // 00450488  ffb014030000           -push dword ptr [eax + 0x314]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(788) /* 0x314 */);
    cpu.esp -= 4;
    // 0045048e  8b557e                 -mov edx, dword ptr [ebp + 0x7e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 00450491  e83ae90700             -call 0x4cedd0
    cpu.esp -= 4;
    sub_4cedd0(app, cpu);
    if (cpu.terminate) return;
    // 00450496  8b457e                 -mov eax, dword ptr [ebp + 0x7e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 00450499  8b92b8000000           -mov edx, dword ptr [edx + 0xb8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(184) /* 0xb8 */);
    // 0045049f  8b403a                 -mov eax, dword ptr [eax + 0x3a]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(58) /* 0x3a */);
    // 004504a2  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004504a5  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004504a8  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004504aa  8b557e                 -mov edx, dword ptr [ebp + 0x7e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 004504ad  8b523c                 -mov edx, dword ptr [edx + 0x3c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(60) /* 0x3c */);
    // 004504b0  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004504b3  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004504b5  8b557e                 -mov edx, dword ptr [ebp + 0x7e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 004504b8  8b523e                 -mov edx, dword ptr [edx + 0x3e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(62) /* 0x3e */);
    // 004504bb  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004504be  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004504c0  8b457e                 -mov eax, dword ptr [ebp + 0x7e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 004504c3  8b4040                 -mov eax, dword ptr [eax + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */);
    // 004504c6  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004504c9  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004504cb  8b5512                 -mov edx, dword ptr [ebp + 0x12]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(18) /* 0x12 */);
    // 004504ce  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004504d0  8b457a                 -mov eax, dword ptr [ebp + 0x7a]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(122) /* 0x7a */);
    // 004504d3  89556e                 -mov dword ptr [ebp + 0x6e], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(110) /* 0x6e */) = cpu.edx;
    // 004504d6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004504d8  7407                   -je 0x4504e1
    if (cpu.flags.zf)
    {
        goto L_0x004504e1;
    }
    // 004504da  b8964a0000             -mov eax, 0x4a96
    cpu.eax = 19094 /*0x4a96*/;
    // 004504df  eb05                   -jmp 0x4504e6
    goto L_0x004504e6;
L_0x004504e1:
    // 004504e1  b8fd9d64ff             -mov eax, 0xff649dfd
    cpu.eax = 4284784125 /*0xff649dfd*/;
L_0x004504e6:
    // 004504e6  8b552a                 -mov edx, dword ptr [ebp + 0x2a]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(42) /* 0x2a */);
    // 004504e9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004504ea  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 004504ef  8b5d76                 -mov ebx, dword ptr [ebp + 0x76]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(118) /* 0x76 */);
    // 004504f2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004504f3  8d8502fdffff           -lea eax, [ebp - 0x2fe]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-766) /* -0x2fe */);
    // 004504f9  8b556e                 -mov edx, dword ptr [ebp + 0x6e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(110) /* 0x6e */);
    // 004504fc  e88f1c0000             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
    // 00450501  8b557e                 -mov edx, dword ptr [ebp + 0x7e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 00450504  8b457e                 -mov eax, dword ptr [ebp + 0x7e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 00450507  8b92b8000000           -mov edx, dword ptr [edx + 0xb8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(184) /* 0xb8 */);
    // 0045050d  8b403a                 -mov eax, dword ptr [eax + 0x3a]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(58) /* 0x3a */);
    // 00450510  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00450513  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00450516  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00450518  8b557e                 -mov edx, dword ptr [ebp + 0x7e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 0045051b  8b523c                 -mov edx, dword ptr [edx + 0x3c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(60) /* 0x3c */);
    // 0045051e  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00450521  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00450523  8b457e                 -mov eax, dword ptr [ebp + 0x7e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 00450526  8b403e                 -mov eax, dword ptr [eax + 0x3e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(62) /* 0x3e */);
    // 00450529  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0045052c  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0045052e  8b557e                 -mov edx, dword ptr [ebp + 0x7e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 00450531  8b5240                 -mov edx, dword ptr [edx + 0x40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(64) /* 0x40 */);
    // 00450534  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00450537  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00450539  8b457e                 -mov eax, dword ptr [ebp + 0x7e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 0045053c  8b4042                 -mov eax, dword ptr [eax + 0x42]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(66) /* 0x42 */);
    // 0045053f  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00450542  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00450544  8b5516                 -mov edx, dword ptr [ebp + 0x16]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(22) /* 0x16 */);
    // 00450547  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00450549  8b4d7a                 -mov ecx, dword ptr [ebp + 0x7a]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(122) /* 0x7a */);
    // 0045054c  89556e                 -mov dword ptr [ebp + 0x6e], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(110) /* 0x6e */) = cpu.edx;
    // 0045054f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00450551  7407                   -je 0x45055a
    if (cpu.flags.zf)
    {
        goto L_0x0045055a;
    }
    // 00450553  b8964a0000             -mov eax, 0x4a96
    cpu.eax = 19094 /*0x4a96*/;
    // 00450558  eb05                   -jmp 0x45055f
    goto L_0x0045055f;
L_0x0045055a:
    // 0045055a  b8fd9d64ff             -mov eax, 0xff649dfd
    cpu.eax = 4284784125 /*0xff649dfd*/;
L_0x0045055f:
    // 0045055f  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 00450564  8b5d76                 -mov ebx, dword ptr [ebp + 0x76]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(118) /* 0x76 */);
    // 00450567  8b556e                 -mov edx, dword ptr [ebp + 0x6e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(110) /* 0x6e */);
    // 0045056a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0045056b  8b4572                 -mov eax, dword ptr [ebp + 0x72]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(114) /* 0x72 */);
    // 0045056e  8b752e                 -mov esi, dword ptr [ebp + 0x2e]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(46) /* 0x2e */);
    // 00450571  6a05                   -push 5
    app->getMemory<x86::reg32>(cpu.esp-4) = 5 /*0x5*/;
    cpu.esp -= 4;
    // 00450573  668bb818030000         -mov di, word ptr [eax + 0x318]
    cpu.di = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(792) /* 0x318 */);
    // 0045057a  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0045057c  6685ff                 +test di, di
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.di & cpu.di));
    // 0045057f  7407                   -je 0x450588
    if (cpu.flags.zf)
    {
        goto L_0x00450588;
    }
    // 00450581  b8c4000000             -mov eax, 0xc4
    cpu.eax = 196 /*0xc4*/;
    // 00450586  eb05                   -jmp 0x45058d
    goto L_0x0045058d;
L_0x00450588:
    // 00450588  b8c5000000             -mov eax, 0xc5
    cpu.eax = 197 /*0xc5*/;
L_0x0045058d:
    // 0045058d  e8be120800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00450592  e8f91b0000             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
    // 00450597  8b457e                 -mov eax, dword ptr [ebp + 0x7e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 0045059a  8b7d76                 -mov edi, dword ptr [ebp + 0x76]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(118) /* 0x76 */);
    // 0045059d  8b4046                 -mov eax, dword ptr [eax + 0x46]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(70) /* 0x46 */);
    // 004505a0  8b555e                 -mov edx, dword ptr [ebp + 0x5e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(94) /* 0x5e */);
    // 004505a3  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004505a6  42                     -inc edx
    (cpu.edx)++;
    // 004505a7  01c7                   +add edi, eax
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
    // 004505a9  8b454e                 -mov eax, dword ptr [ebp + 0x4e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(78) /* 0x4e */);
    // 004505ac  89555e                 -mov dword ptr [ebp + 0x5e], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(94) /* 0x5e */) = cpu.edx;
    // 004505af  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004505b0  897d76                 -mov dword ptr [ebp + 0x76], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(118) /* 0x76 */) = cpu.edi;
    // 004505b3  89454e                 -mov dword ptr [ebp + 0x4e], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(78) /* 0x4e */) = cpu.eax;
    // 004505b6  e948fcffff             -jmp 0x450203
    goto L_0x00450203;
L_0x004505bb:
    // 004505bb  8d9d02ffffff           -lea ebx, [ebp - 0xfe]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-254) /* -0xfe */);
    // 004505c1  8d9502fcffff           -lea edx, [ebp - 0x3fe]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-1022) /* -0x3fe */);
    // 004505c7  8d8502feffff           -lea eax, [ebp - 0x1fe]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-510) /* -0x1fe */);
    // 004505cd  e8bef4ffff             -call 0x44fa90
    cpu.esp -= 4;
    sub_44fa90(app, cpu);
    if (cpu.terminate) return;
    // 004505d2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004505d4  0f84c5000000           -je 0x45069f
    if (cpu.flags.zf)
    {
        goto L_0x0045069f;
    }
    // 004505da  8d9502fdffff           -lea edx, [ebp - 0x2fe]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-766) /* -0x2fe */);
    // 004505e0  e85be80700             -call 0x4cee40
    cpu.esp -= 4;
    sub_4cee40(app, cpu);
    if (cpu.terminate) return;
    // 004505e5  8d8502fdffff           -lea eax, [ebp - 0x2fe]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-766) /* -0x2fe */);
    // 004505eb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004505ec  8d8502ffffff           -lea eax, [ebp - 0xfe]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-254) /* -0xfe */);
    // 004505f2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004505f3  8d8502feffff           -lea eax, [ebp - 0x1fe]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-510) /* -0x1fe */);
    // 004505f9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004505fa  b8ea000000             -mov eax, 0xea
    cpu.eax = 234 /*0xea*/;
    // 004505ff  e84c120800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00450604  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00450605  688c955300             -push 0x53958c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5477772 /*0x53958c*/;
    cpu.esp -= 4;
    // 0045060a  8d8502fbffff           -lea eax, [ebp - 0x4fe]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-1278) /* -0x4fe */);
    // 00450610  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00450611  e87af00800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00450616  8b457e                 -mov eax, dword ptr [ebp + 0x7e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 00450619  8b80b8000000           -mov eax, dword ptr [eax + 0xb8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(184) /* 0xb8 */);
    // 0045061f  8b756a                 -mov esi, dword ptr [ebp + 0x6a]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(106) /* 0x6a */);
    // 00450622  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00450625  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00450627  8b457e                 -mov eax, dword ptr [ebp + 0x7e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 0045062a  8b4006                 -mov eax, dword ptr [eax + 6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 0045062d  8b4d66                 -mov ecx, dword ptr [ebp + 0x66]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(102) /* 0x66 */);
    // 00450630  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00450633  8b3d68296600           -mov edi, dword ptr [0x662968]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(6695272) /* 0x662968 */);
    // 00450639  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0045063b  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0045063e  8d5818                 -lea ebx, [eax + 0x18]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00450641  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00450643  7433                   -je 0x450678
    if (cpu.flags.zf)
    {
        goto L_0x00450678;
    }
    // 00450645  e8d6f4ffff             -call 0x44fb20
    cpu.esp -= 4;
    sub_44fb20(app, cpu);
    if (cpu.terminate) return;
    // 0045064a  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 0045064c  742a                   -je 0x450678
    if (cpu.flags.zf)
    {
        goto L_0x00450678;
    }
    // 0045064e  a1a4c17900             -mov eax, dword ptr [0x79c1a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7979428) /* 0x79c1a4 */);
    // 00450653  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00450655  b980000000             -mov ecx, 0x80
    cpu.ecx = 128 /*0x80*/;
    // 0045065a  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0045065d  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0045065f  83fa40                 +cmp edx, 0x40
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
    // 00450662  7d14                   -jge 0x450678
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00450678;
    }
    // 00450664  837d7a00               +cmp dword ptr [ebp + 0x7a], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(122) /* 0x7a */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00450668  7407                   -je 0x450671
    if (cpu.flags.zf)
    {
        goto L_0x00450671;
    }
    // 0045066a  b8964a0000             -mov eax, 0x4a96
    cpu.eax = 19094 /*0x4a96*/;
    // 0045066f  eb19                   -jmp 0x45068a
    goto L_0x0045068a;
L_0x00450671:
    // 00450671  b840e4ff00             -mov eax, 0xffe440
    cpu.eax = 16770112 /*0xffe440*/;
    // 00450676  eb12                   -jmp 0x45068a
    goto L_0x0045068a;
L_0x00450678:
    // 00450678  837d7a00               +cmp dword ptr [ebp + 0x7a], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(122) /* 0x7a */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045067c  7407                   -je 0x450685
    if (cpu.flags.zf)
    {
        goto L_0x00450685;
    }
    // 0045067e  b8964a0000             -mov eax, 0x4a96
    cpu.eax = 19094 /*0x4a96*/;
    // 00450683  eb05                   -jmp 0x45068a
    goto L_0x0045068a;
L_0x00450685:
    // 00450685  b82894d5ff             -mov eax, 0xffd59428
    cpu.eax = 4292187176 /*0xffd59428*/;
L_0x0045068a:
    // 0045068a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0045068b  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 00450690  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00450692  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00450694  8d8502fbffff           -lea eax, [ebp - 0x4fe]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-1278) /* -0x4fe */);
    // 0045069a  e8f11a0000             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
L_0x0045069f:
    // 0045069f  8b457e                 -mov eax, dword ptr [ebp + 0x7e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 004506a2  8b4048                 -mov eax, dword ptr [eax + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    // 004506a5  8b4d56                 -mov ecx, dword ptr [ebp + 0x56]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(86) /* 0x56 */);
    // 004506a8  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004506ab  39c8                   +cmp eax, ecx
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
    // 004506ad  0f8da0000000           -jge 0x450753
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00450753;
    }
    // 004506b3  8b457e                 -mov eax, dword ptr [ebp + 0x7e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 004506b6  6683b8b400000000       +cmp word ptr [eax + 0xb4], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(180) /* 0xb4 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004506be  743d                   -je 0x4506fd
    if (cpu.flags.zf)
    {
        goto L_0x004506fd;
    }
    // 004506c0  8b407a                 -mov eax, dword ptr [eax + 0x7a]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(122) /* 0x7a */);
    // 004506c3  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004506c6  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004506c9  8b557e                 -mov edx, dword ptr [ebp + 0x7e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 004506cc  8b457e                 -mov eax, dword ptr [ebp + 0x7e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 004506cf  8b527c                 -mov edx, dword ptr [edx + 0x7c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(124) /* 0x7c */);
    // 004506d2  83c07c                 -add eax, 0x7c
    (cpu.eax) += x86::reg32(x86::sreg32(124 /*0x7c*/));
    // 004506d5  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004506d8  e813bb0400             -call 0x49c1f0
    cpu.esp -= 4;
    sub_49c1f0(app, cpu);
    if (cpu.terminate) return;
    // 004506dd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004506df  740c                   -je 0x4506ed
    if (cpu.flags.zf)
    {
        goto L_0x004506ed;
    }
    // 004506e1  8b457e                 -mov eax, dword ptr [ebp + 0x7e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 004506e4  668b80ac000000         -mov ax, word ptr [eax + 0xac]
    cpu.ax = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 004506eb  eb0a                   -jmp 0x4506f7
    goto L_0x004506f7;
L_0x004506ed:
    // 004506ed  8b457e                 -mov eax, dword ptr [ebp + 0x7e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 004506f0  668b80a8000000         -mov ax, word ptr [eax + 0xa8]
    cpu.ax = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(168) /* 0xa8 */);
L_0x004506f7:
    // 004506f7  98                     -cwde 
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.ax));
    // 004506f8  e893720800             -call 0x4d7990
    cpu.esp -= 4;
    sub_4d7990(app, cpu);
    if (cpu.terminate) return;
L_0x004506fd:
    // 004506fd  8b457e                 -mov eax, dword ptr [ebp + 0x7e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 00450700  8b557e                 -mov edx, dword ptr [ebp + 0x7e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 00450703  8b4048                 -mov eax, dword ptr [eax + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    // 00450706  8b92b2000000           -mov edx, dword ptr [edx + 0xb2]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(178) /* 0xb2 */);
    // 0045070c  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0045070f  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00450712  8b5d56                 -mov ebx, dword ptr [ebp + 0x56]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(86) /* 0x56 */);
    // 00450715  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00450717  39d8                   +cmp eax, ebx
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
    // 00450719  7d38                   -jge 0x450753
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00450753;
    }
    // 0045071b  8b457e                 -mov eax, dword ptr [ebp + 0x7e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 0045071e  0584000000             -add eax, 0x84
    (cpu.eax) += x86::reg32(x86::sreg32(132 /*0x84*/));
    // 00450723  8b58fe                 -mov ebx, dword ptr [eax - 2]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-2) /* -0x2 */);
    // 00450726  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00450728  e8c3ba0400             -call 0x49c1f0
    cpu.esp -= 4;
    sub_49c1f0(app, cpu);
    if (cpu.terminate) return;
    // 0045072d  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00450730  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 00450733  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00450735  740c                   -je 0x450743
    if (cpu.flags.zf)
    {
        goto L_0x00450743;
    }
    // 00450737  8b457e                 -mov eax, dword ptr [ebp + 0x7e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 0045073a  668b80ae000000         -mov ax, word ptr [eax + 0xae]
    cpu.ax = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(174) /* 0xae */);
    // 00450741  eb0a                   -jmp 0x45074d
    goto L_0x0045074d;
L_0x00450743:
    // 00450743  8b457e                 -mov eax, dword ptr [ebp + 0x7e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 00450746  668b80aa000000         -mov ax, word ptr [eax + 0xaa]
    cpu.ax = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(170) /* 0xaa */);
L_0x0045074d:
    // 0045074d  98                     -cwde 
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.ax));
    // 0045074e  e83d720800             -call 0x4d7990
    cpu.esp -= 4;
    sub_4d7990(app, cpu);
    if (cpu.terminate) return;
L_0x00450753:
    // 00450753  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00450755:
    // 00450755  8da582000000           -lea esp, [ebp + 0x82]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(130) /* 0x82 */);
    // 0045075b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045075c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045075d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045075e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045075f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00450760  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_450770(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00450770  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00450771  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00450772  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00450773  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00450774  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00450776  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00450778  ba18000000             -mov edx, 0x18
    cpu.edx = 24 /*0x18*/;
    // 0045077d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0045077f  e8dc9effff             -call 0x44a660
    cpu.esp -= 4;
    sub_44a660(app, cpu);
    if (cpu.terminate) return;
    // 00450784  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00450786  0f84bc010000           -je 0x450948
    if (cpu.flags.zf)
    {
        goto L_0x00450948;
    }
    // 0045078c  e87fedffff             -call 0x44f510
    cpu.esp -= 4;
    sub_44f510(app, cpu);
    if (cpu.terminate) return;
    // 00450791  a1acd46f00             -mov eax, dword ptr [0x6fd4ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328940) /* 0x6fd4ac */);
    // 00450796  a318945500             -mov dword ptr [0x559418], eax
    app->getMemory<x86::reg32>(x86::reg32(5608472) /* 0x559418 */) = cpu.eax;
    // 0045079b  a1b2d46f00             -mov eax, dword ptr [0x6fd4b2]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328946) /* 0x6fd4b2 */);
    // 004507a0  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004507a3  e8b8e90700             -call 0x4cf160
    cpu.esp -= 4;
    sub_4cf160(app, cpu);
    if (cpu.terminate) return;
    // 004507a8  98                     -cwde 
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.ax));
    // 004507a9  a31c945500             -mov dword ptr [0x55941c], eax
    app->getMemory<x86::reg32>(x86::reg32(5608476) /* 0x55941c */) = cpu.eax;
    // 004507ae  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004507b0  a118945500             -mov eax, dword ptr [0x559418]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5608472) /* 0x559418 */);
    // 004507b5  e8b6eeffff             -call 0x44f670
    cpu.esp -= 4;
    sub_44f670(app, cpu);
    if (cpu.terminate) return;
    // 004507ba  66a118945500           -mov ax, word ptr [0x559418]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5608472) /* 0x559418 */);
    // 004507c0  668983a4000000         -mov word ptr [ebx + 0xa4], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(164) /* 0xa4 */) = cpu.ax;
    // 004507c7  66a11c945500           -mov ax, word ptr [0x55941c]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5608476) /* 0x55941c */);
    // 004507cd  668b534a               -mov dx, word ptr [ebx + 0x4a]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(74) /* 0x4a */);
    // 004507d1  668983a6000000         -mov word ptr [ebx + 0xa6], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(166) /* 0xa6 */) = cpu.ax;
    // 004507d8  6683fa0a               +cmp dx, 0xa
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(10 /*0xa*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004507dc  7d08                   -jge 0x4507e6
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004507e6;
    }
    // 004507de  8b4348                 -mov eax, dword ptr [ebx + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(72) /* 0x48 */);
    // 004507e1  c1f810                 +sar eax, 0x10
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
    // 004507e4  eb05                   -jmp 0x4507eb
    goto L_0x004507eb;
L_0x004507e6:
    // 004507e6  b80a000000             -mov eax, 0xa
    cpu.eax = 10 /*0xa*/;
L_0x004507eb:
    // 004507eb  6689414a               -mov word ptr [ecx + 0x4a], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(74) /* 0x4a */) = cpu.ax;
    // 004507ef  b8e3000000             -mov eax, 0xe3
    cpu.eax = 227 /*0xe3*/;
    // 004507f4  e857100800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 004507f9  89818c000000           -mov dword ptr [ecx + 0x8c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(140) /* 0x8c */) = cpu.eax;
    // 004507ff  b8c3000000             -mov eax, 0xc3
    cpu.eax = 195 /*0xc3*/;
    // 00450804  e847100800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00450809  898190000000           -mov dword ptr [ecx + 0x90], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(144) /* 0x90 */) = cpu.eax;
    // 0045080f  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00450814  e837100800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00450819  898194000000           -mov dword ptr [ecx + 0x94], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(148) /* 0x94 */) = cpu.eax;
    // 0045081f  b828000000             -mov eax, 0x28
    cpu.eax = 40 /*0x28*/;
    // 00450824  e827100800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00450829  898198000000           -mov dword ptr [ecx + 0x98], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(152) /* 0x98 */) = cpu.eax;
    // 0045082f  b829000000             -mov eax, 0x29
    cpu.eax = 41 /*0x29*/;
    // 00450834  e817100800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00450839  89819c000000           -mov dword ptr [ecx + 0x9c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(156) /* 0x9c */) = cpu.eax;
    // 0045083f  b892010000             -mov eax, 0x192
    cpu.eax = 402 /*0x192*/;
    // 00450844  e807100800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00450849  8981a0000000           -mov dword ptr [ecx + 0xa0], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(160) /* 0xa0 */) = cpu.eax;
    // 0045084f  b8a0955300             -mov eax, 0x5395a0
    cpu.eax = 5477792 /*0x5395a0*/;
    // 00450854  e857550800             -call 0x4d5db0
    cpu.esp -= 4;
    sub_4d5db0(app, cpu);
    if (cpu.terminate) return;
    // 00450859  668981a8000000         -mov word ptr [ecx + 0xa8], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(168) /* 0xa8 */) = cpu.ax;
    // 00450860  b8a8955300             -mov eax, 0x5395a8
    cpu.eax = 5477800 /*0x5395a8*/;
    // 00450865  e846550800             -call 0x4d5db0
    cpu.esp -= 4;
    sub_4d5db0(app, cpu);
    if (cpu.terminate) return;
    // 0045086a  668981aa000000         -mov word ptr [ecx + 0xaa], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(170) /* 0xaa */) = cpu.ax;
    // 00450871  b8b0955300             -mov eax, 0x5395b0
    cpu.eax = 5477808 /*0x5395b0*/;
    // 00450876  e835550800             -call 0x4d5db0
    cpu.esp -= 4;
    sub_4d5db0(app, cpu);
    if (cpu.terminate) return;
    // 0045087b  668981ac000000         -mov word ptr [ecx + 0xac], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(172) /* 0xac */) = cpu.ax;
    // 00450882  b8b8955300             -mov eax, 0x5395b8
    cpu.eax = 5477816 /*0x5395b8*/;
    // 00450887  e824550800             -call 0x4d5db0
    cpu.esp -= 4;
    sub_4d5db0(app, cpu);
    if (cpu.terminate) return;
    // 0045088c  668981ae000000         -mov word ptr [ecx + 0xae], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(174) /* 0xae */) = cpu.ax;
    // 00450893  b8a8955300             -mov eax, 0x5395a8
    cpu.eax = 5477800 /*0x5395a8*/;
    // 00450898  e813550800             -call 0x4d5db0
    cpu.esp -= 4;
    sub_4d5db0(app, cpu);
    if (cpu.terminate) return;
    // 0045089d  668981b0000000         -mov word ptr [ecx + 0xb0], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(176) /* 0xb0 */) = cpu.ax;
    // 004508a4  b8a0955300             -mov eax, 0x5395a0
    cpu.eax = 5477792 /*0x5395a0*/;
    // 004508a9  e802550800             -call 0x4d5db0
    cpu.esp -= 4;
    sub_4d5db0(app, cpu);
    if (cpu.terminate) return;
    // 004508ae  668981b2000000         -mov word ptr [ecx + 0xb2], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(178) /* 0xb2 */) = cpu.ax;
    // 004508b5  66c781b40000000000     -mov word ptr [ecx + 0xb4], 0
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(180) /* 0xb4 */) = 0 /*0x0*/;
    // 004508be  668b99ba000000         -mov bx, word ptr [ecx + 0xba]
    cpu.bx = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(186) /* 0xba */);
    // 004508c5  66c781b60000000100     -mov word ptr [ecx + 0xb6], 1
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(182) /* 0xb6 */) = 1 /*0x1*/;
    // 004508ce  6685db                 +test bx, bx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.bx & cpu.bx));
    // 004508d1  7512                   -jne 0x4508e5
    if (!cpu.flags.zf)
    {
        goto L_0x004508e5;
    }
    // 004508d3  668b4106               -mov ax, word ptr [ecx + 6]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(6) /* 0x6 */);
    // 004508d7  668999b8000000         -mov word ptr [ecx + 0xb8], bx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(184) /* 0xb8 */) = cpu.bx;
    // 004508de  668981ba000000         -mov word ptr [ecx + 0xba], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(186) /* 0xba */) = cpu.ax;
L_0x004508e5:
    // 004508e5  833d6829660000         +cmp dword ptr [0x662968], 0
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
    // 004508ec  745a                   -je 0x450948
    if (cpu.flags.zf)
    {
        goto L_0x00450948;
    }
    // 004508ee  8b151c945500           -mov edx, dword ptr [0x55941c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5608476) /* 0x55941c */);
    // 004508f4  a118945500             -mov eax, dword ptr [0x559418]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5608472) /* 0x559418 */);
    // 004508f9  e8d2efffff             -call 0x44f8d0
    cpu.esp -= 4;
    sub_44f8d0(app, cpu);
    if (cpu.terminate) return;
    // 004508fe  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00450900  8b81b4000000           -mov eax, dword ptr [ecx + 0xb4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(180) /* 0xb4 */);
    // 00450906  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00450909  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0045090b  e820efffff             -call 0x44f830
    cpu.esp -= 4;
    sub_44f830(app, cpu);
    if (cpu.terminate) return;
L_0x00450910:
    // 00450910  39d3                   +cmp ebx, edx
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
    // 00450912  7d34                   -jge 0x450948
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00450948;
    }
    // 00450914  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00450916  e8f5efffff             -call 0x44f910
    cpu.esp -= 4;
    sub_44f910(app, cpu);
    if (cpu.terminate) return;
    // 0045091b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045091d  7429                   -je 0x450948
    if (cpu.flags.zf)
    {
        goto L_0x00450948;
    }
    // 0045091f  f6801a03000001         +test byte ptr [eax + 0x31a], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(794) /* 0x31a */) & 1 /*0x1*/));
    // 00450926  741d                   -je 0x450945
    if (cpu.flags.zf)
    {
        goto L_0x00450945;
    }
    // 00450928  8b4148                 -mov eax, dword ptr [ecx + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(72) /* 0x48 */);
    // 0045092b  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0045092e  39c3                   +cmp ebx, eax
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
    // 00450930  7c13                   -jl 0x450945
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00450945;
    }
    // 00450932  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00450934  662b414a               +sub ax, word ptr [ecx + 0x4a]
    {
        x86::reg16& tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(74) /* 0x4a */)));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00450938  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00450939  668981b4000000         -mov word ptr [ecx + 0xb4], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(180) /* 0xb4 */) = cpu.ax;
    // 00450940  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00450941  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00450942  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00450943  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00450944  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00450945:
    // 00450945  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00450946  ebc8                   -jmp 0x450910
    goto L_0x00450910;
L_0x00450948:
    // 00450948  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00450949  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045094a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045094b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045094c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_450950(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00450950  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00450951  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00450952  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00450954  ba18000000             -mov edx, 0x18
    cpu.edx = 24 /*0x18*/;
    // 00450959  e8029dffff             -call 0x44a660
    cpu.esp -= 4;
    sub_44a660(app, cpu);
    if (cpu.terminate) return;
    // 0045095e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00450960  7405                   -je 0x450967
    if (cpu.flags.zf)
    {
        goto L_0x00450967;
    }
    // 00450962  e889ecffff             -call 0x44f5f0
    cpu.esp -= 4;
    sub_44f5f0(app, cpu);
    if (cpu.terminate) return;
L_0x00450967:
    // 00450967  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00450968  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00450969  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_450970(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00450970  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00450971  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00450972  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00450973  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00450974  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00450975  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00450977  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0045097a  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0045097c  ba18000000             -mov edx, 0x18
    cpu.edx = 24 /*0x18*/;
    // 00450981  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00450983  e8d89cffff             -call 0x44a660
    cpu.esp -= 4;
    sub_44a660(app, cpu);
    if (cpu.terminate) return;
    // 00450988  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045098a  0f84e0000000           -je 0x450a70
    if (cpu.flags.zf)
    {
        goto L_0x00450a70;
    }
    // 00450990  8b83b8000000           -mov eax, dword ptr [ebx + 0xb8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(184) /* 0xb8 */);
    // 00450996  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00450999  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0045099b  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0045099e  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004509a0  eb05                   -jmp 0x4509a7
    goto L_0x004509a7;
L_0x004509a2:
    // 004509a2  83fa06                 +cmp edx, 6
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
    // 004509a5  7d38                   -jge 0x4509df
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004509df;
    }
L_0x004509a7:
    // 004509a7  8b75fc                 -mov esi, dword ptr [ebp - 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004509aa  668974d14e             -mov word ptr [ecx + edx*8 + 0x4e], si
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(78) /* 0x4e */ + cpu.edx * 8) = cpu.si;
    // 004509af  668b7108               -mov si, word ptr [ecx + 8]
    cpu.si = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004509b3  668974d14c             -mov word ptr [ecx + edx*8 + 0x4c], si
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(76) /* 0x4c */ + cpu.edx * 8) = cpu.si;
    // 004509b8  668b74513c             -mov si, word ptr [ecx + edx*2 + 0x3c]
    cpu.si = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(60) /* 0x3c */ + cpu.edx * 2);
    // 004509bd  668974d150             -mov word ptr [ecx + edx*8 + 0x50], si
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(80) /* 0x50 */ + cpu.edx * 8) = cpu.si;
    // 004509c2  8b5cd14e               -mov ebx, dword ptr [ecx + edx*8 + 0x4e]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(78) /* 0x4e */ + cpu.edx * 8);
    // 004509c6  668b7148               -mov si, word ptr [ecx + 0x48]
    cpu.si = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(72) /* 0x48 */);
    // 004509ca  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 004509cd  668974d152             -mov word ptr [ecx + edx*8 + 0x52], si
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(82) /* 0x52 */ + cpu.edx * 8) = cpu.si;
    // 004509d2  8b75fc                 -mov esi, dword ptr [ebp - 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004509d5  42                     -inc edx
    (cpu.edx)++;
    // 004509d6  01de                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004509d8  01d8                   +add eax, ebx
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
    // 004509da  8975fc                 -mov dword ptr [ebp - 4], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.esi;
    // 004509dd  ebc3                   -jmp 0x4509a2
    goto L_0x004509a2;
L_0x004509df:
    // 004509df  8b5148                 -mov edx, dword ptr [ecx + 0x48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(72) /* 0x48 */);
    // 004509e2  8b5946                 -mov ebx, dword ptr [ecx + 0x46]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(70) /* 0x46 */);
    // 004509e5  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004509e8  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 004509eb  42                     -inc edx
    (cpu.edx)++;
    // 004509ec  0fafd3                 -imul edx, ebx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004509ef  668b99ba000000         -mov bx, word ptr [ecx + 0xba]
    cpu.bx = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(186) /* 0xba */);
    // 004509f6  6689591c               -mov word ptr [ecx + 0x1c], bx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(28) /* 0x1c */) = cpu.bx;
    // 004509fa  668b5908               -mov bx, word ptr [ecx + 8]
    cpu.bx = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004509fe  6689591a               -mov word ptr [ecx + 0x1a], bx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(26) /* 0x1a */) = cpu.bx;
    // 00450a02  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00450a04  83c316                 -add ebx, 0x16
    (cpu.ebx) += x86::reg32(x86::sreg32(22 /*0x16*/));
    // 00450a07  6689591e               -mov word ptr [ecx + 0x1e], bx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(30) /* 0x1e */) = cpu.bx;
    // 00450a0b  668b99ba000000         -mov bx, word ptr [ecx + 0xba]
    cpu.bx = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(186) /* 0xba */);
    // 00450a12  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00450a14  66c781800000000c00     -mov word ptr [ecx + 0x80], 0xc
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(128) /* 0x80 */) = 12 /*0xc*/;
    // 00450a1d  83c30a                 -add ebx, 0xa
    (cpu.ebx) += x86::reg32(x86::sreg32(10 /*0xa*/));
    // 00450a20  6689597e               -mov word ptr [ecx + 0x7e], bx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(126) /* 0x7e */) = cpu.bx;
    // 00450a24  668b5908               -mov bx, word ptr [ecx + 8]
    cpu.bx = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00450a28  6689597c               -mov word ptr [ecx + 0x7c], bx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(124) /* 0x7c */) = cpu.bx;
    // 00450a2c  668b99ba000000         -mov bx, word ptr [ecx + 0xba]
    cpu.bx = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(186) /* 0xba */);
    // 00450a33  66c781820000000c00     -mov word ptr [ecx + 0x82], 0xc
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(130) /* 0x82 */) = 12 /*0xc*/;
    // 00450a3c  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00450a3e  66c781880000000c00     -mov word ptr [ecx + 0x88], 0xc
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(136) /* 0x88 */) = 12 /*0xc*/;
    // 00450a47  050a000000             -add eax, 0xa
    (cpu.eax) += x86::reg32(x86::sreg32(10 /*0xa*/));
    // 00450a4c  66898186000000         -mov word ptr [ecx + 0x86], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(134) /* 0x86 */) = cpu.ax;
    // 00450a53  668b4108               -mov ax, word ptr [ecx + 8]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00450a57  66c7818a0000000c00     -mov word ptr [ecx + 0x8a], 0xc
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(138) /* 0x8a */) = 12 /*0xc*/;
    // 00450a60  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00450a62  66895120               -mov word ptr [ecx + 0x20], dx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.dx;
    // 00450a66  83e80c                 -sub eax, 0xc
    (cpu.eax) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00450a69  66898184000000         -mov word ptr [ecx + 0x84], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(132) /* 0x84 */) = cpu.ax;
L_0x00450a70:
    // 00450a70  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00450a72  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00450a73  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00450a74  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00450a75  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00450a76  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00450a77  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_450a90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00450a90  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00450a91  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00450a92  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00450a93  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00450a94  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00450a96  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00450a99  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00450a9b  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 00450aa0  ba18000000             -mov edx, 0x18
    cpu.edx = 24 /*0x18*/;
    // 00450aa5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00450aa7  e8b49bffff             -call 0x44a660
    cpu.esp -= 4;
    sub_44a660(app, cpu);
    if (cpu.terminate) return;
    // 00450aac  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00450aae  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00450ab0  7507                   -jne 0x450ab9
    if (!cpu.flags.zf)
    {
        goto L_0x00450ab9;
    }
    // 00450ab2  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00450ab4  e968030000             -jmp 0x450e21
    goto L_0x00450e21;
L_0x00450ab9:
    // 00450ab9  8b151c945500           -mov edx, dword ptr [0x55941c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5608476) /* 0x55941c */);
    // 00450abf  a118945500             -mov eax, dword ptr [0x559418]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5608472) /* 0x559418 */);
    // 00450ac4  e807eeffff             -call 0x44f8d0
    cpu.esp -= 4;
    sub_44f8d0(app, cpu);
    if (cpu.terminate) return;
    // 00450ac9  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 00450acc  83f802                 +cmp eax, 2
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
    // 00450acf  7d0b                   -jge 0x450adc
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00450adc;
    }
    // 00450ad1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00450ad3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00450ad5  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00450ad7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00450ad8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00450ad9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00450ada  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00450adb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00450adc:
    // 00450adc  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00450ade  eb06                   -jmp 0x450ae6
    goto L_0x00450ae6;
L_0x00450ae0:
    // 00450ae0  42                     -inc edx
    (cpu.edx)++;
    // 00450ae1  83fa06                 +cmp edx, 6
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
    // 00450ae4  7d1b                   -jge 0x450b01
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00450b01;
    }
L_0x00450ae6:
    // 00450ae6  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 00450aed  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 00450af0  8d414c                 -lea eax, [ecx + 0x4c]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(76) /* 0x4c */);
    // 00450af3  0345f8                 -add eax, dword ptr [ebp - 8]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 00450af6  e8f5b60400             -call 0x49c1f0
    cpu.esp -= 4;
    sub_49c1f0(app, cpu);
    if (cpu.terminate) return;
    // 00450afb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00450afd  74e1                   -je 0x450ae0
    if (cpu.flags.zf)
    {
        goto L_0x00450ae0;
    }
    // 00450aff  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
L_0x00450b01:
    // 00450b01  6683ff0d               +cmp di, 0xd
    {
        x86::reg16 tmp1 = cpu.di;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(13 /*0xd*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00450b05  7551                   -jne 0x450b58
    if (!cpu.flags.zf)
    {
        goto L_0x00450b58;
    }
    // 00450b07  83fb05                 +cmp ebx, 5
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00450b0a  7747                   -ja 0x450b53
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00450b53;
    }
    // 00450b0c  ff249d780a4500         -jmp dword ptr [ebx*4 + 0x450a78]
    cpu.ip = app->getMemory<x86::reg32>(4524664 + cpu.ebx * 4); goto dynamic_jump;
  case 0x00450b13:
    // 00450b13  66c781b60000000100     -mov word ptr [ecx + 0xb6], 1
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(182) /* 0xb6 */) = 1 /*0x1*/;
    // 00450b1c  eb35                   -jmp 0x450b53
    goto L_0x00450b53;
  case 0x00450b1e:
    // 00450b1e  66c781b60000000400     -mov word ptr [ecx + 0xb6], 4
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(182) /* 0xb6 */) = 4 /*0x4*/;
    // 00450b27  eb2a                   -jmp 0x450b53
    goto L_0x00450b53;
  case 0x00450b29:
    // 00450b29  66c781b60000000200     -mov word ptr [ecx + 0xb6], 2
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(182) /* 0xb6 */) = 2 /*0x2*/;
    // 00450b32  eb1f                   -jmp 0x450b53
    goto L_0x00450b53;
  case 0x00450b34:
    // 00450b34  66c781b60000000300     -mov word ptr [ecx + 0xb6], 3
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(182) /* 0xb6 */) = 3 /*0x3*/;
    // 00450b3d  eb14                   -jmp 0x450b53
    goto L_0x00450b53;
  case 0x00450b3f:
    // 00450b3f  66c781b60000000500     -mov word ptr [ecx + 0xb6], 5
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(182) /* 0xb6 */) = 5 /*0x5*/;
    // 00450b48  eb09                   -jmp 0x450b53
    goto L_0x00450b53;
  case 0x00450b4a:
    // 00450b4a  66c781b60000000600     -mov word ptr [ecx + 0xb6], 6
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(182) /* 0xb6 */) = 6 /*0x6*/;
L_0x00450b53:
    // 00450b53  be02000000             -mov esi, 2
    cpu.esi = 2 /*0x2*/;
L_0x00450b58:
    // 00450b58  6681ff004d             +cmp di, 0x4d00
    {
        x86::reg16 tmp1 = cpu.di;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(19712 /*0x4d00*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00450b5d  0f8577000000           -jne 0x450bda
    if (!cpu.flags.zf)
    {
        goto L_0x00450bda;
    }
    // 00450b63  43                     -inc ebx
    (cpu.ebx)++;
    // 00450b64  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00450b66  7d04                   -jge 0x450b6c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00450b6c;
    }
    // 00450b68  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00450b6a  eb0e                   -jmp 0x450b7a
    goto L_0x00450b7a;
L_0x00450b6c:
    // 00450b6c  83fb05                 +cmp ebx, 5
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00450b6f  7e07                   -jle 0x450b78
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00450b78;
    }
    // 00450b71  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 00450b76  eb02                   -jmp 0x450b7a
    goto L_0x00450b7a;
L_0x00450b78:
    // 00450b78  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x00450b7a:
    // 00450b7a  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00450b7c  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00450b7f  8d3401                 -lea esi, [ecx + eax]
    cpu.esi = x86::reg32(cpu.ecx + cpu.eax * 1);
    // 00450b82  8b464e                 -mov eax, dword ptr [esi + 0x4e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(78) /* 0x4e */);
    // 00450b85  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00450b88  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 00450b8f  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00450b91  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00450b93  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00450b96  c1e202                 +shl edx, 2
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
    // 00450b99  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00450b9b  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 00450b9e  8b564c                 -mov edx, dword ptr [esi + 0x4c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(76) /* 0x4c */);
    // 00450ba1  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00450ba4  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00450ba6  8915e4e55500           -mov dword ptr [0x55e5e4], edx
    app->getMemory<x86::reg32>(x86::reg32(5629412) /* 0x55e5e4 */) = cpu.edx;
    // 00450bac  8b5650                 -mov edx, dword ptr [esi + 0x50]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(80) /* 0x50 */);
    // 00450baf  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00450bb2  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00450bb4  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00450bb7  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00450bb9  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00450bbb  8b764a                 -mov esi, dword ptr [esi + 0x4a]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(74) /* 0x4a */);
    // 00450bbe  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 00450bc1  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00450bc3  a1e4e55500             -mov eax, dword ptr [0x55e5e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5629412) /* 0x55e5e4 */);
    // 00450bc8  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00450bca  8935e8e55500           -mov dword ptr [0x55e5e8], esi
    app->getMemory<x86::reg32>(x86::reg32(5629416) /* 0x55e5e8 */) = cpu.esi;
    // 00450bd0  e8ebb30400             -call 0x49bfc0
    cpu.esp -= 4;
    sub_49bfc0(app, cpu);
    if (cpu.terminate) return;
    // 00450bd5  be02000000             -mov esi, 2
    cpu.esi = 2 /*0x2*/;
L_0x00450bda:
    // 00450bda  6681ff004b             +cmp di, 0x4b00
    {
        x86::reg16 tmp1 = cpu.di;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(19200 /*0x4b00*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00450bdf  756d                   -jne 0x450c4e
    if (!cpu.flags.zf)
    {
        goto L_0x00450c4e;
    }
    // 00450be1  4b                     -dec ebx
    (cpu.ebx)--;
    // 00450be2  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00450be4  7d04                   -jge 0x450bea
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00450bea;
    }
    // 00450be6  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00450be8  eb0a                   -jmp 0x450bf4
    goto L_0x00450bf4;
L_0x00450bea:
    // 00450bea  83fb05                 +cmp ebx, 5
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00450bed  7e05                   -jle 0x450bf4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00450bf4;
    }
    // 00450bef  bb05000000             -mov ebx, 5
    cpu.ebx = 5 /*0x5*/;
L_0x00450bf4:
    // 00450bf4  8b44d94e               -mov eax, dword ptr [ecx + ebx*8 + 0x4e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(78) /* 0x4e */ + cpu.ebx * 8);
    // 00450bf8  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00450bfb  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 00450c02  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00450c04  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00450c06  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00450c09  c1e202                 +shl edx, 2
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
    // 00450c0c  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00450c0e  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 00450c11  8b54d94c               -mov edx, dword ptr [ecx + ebx*8 + 0x4c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(76) /* 0x4c */ + cpu.ebx * 8);
    // 00450c15  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00450c18  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00450c1a  8915e4e55500           -mov dword ptr [0x55e5e4], edx
    app->getMemory<x86::reg32>(x86::reg32(5629412) /* 0x55e5e4 */) = cpu.edx;
    // 00450c20  8b54d950               -mov edx, dword ptr [ecx + ebx*8 + 0x50]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(80) /* 0x50 */ + cpu.ebx * 8);
    // 00450c24  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00450c27  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00450c29  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00450c2c  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00450c2e  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00450c30  8b54d94a               -mov edx, dword ptr [ecx + ebx*8 + 0x4a]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(74) /* 0x4a */ + cpu.ebx * 8);
    // 00450c34  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00450c37  be02000000             -mov esi, 2
    cpu.esi = 2 /*0x2*/;
    // 00450c3c  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00450c3e  a1e4e55500             -mov eax, dword ptr [0x55e5e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5629412) /* 0x55e5e4 */);
    // 00450c43  8915e8e55500           -mov dword ptr [0x55e5e8], edx
    app->getMemory<x86::reg32>(x86::reg32(5629416) /* 0x55e5e8 */) = cpu.edx;
    // 00450c49  e872b30400             -call 0x49bfc0
    cpu.esp -= 4;
    sub_49bfc0(app, cpu);
    if (cpu.terminate) return;
L_0x00450c4e:
    // 00450c4e  8b4148                 -mov eax, dword ptr [ecx + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(72) /* 0x48 */);
    // 00450c51  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00450c54  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00450c57  39d0                   +cmp eax, edx
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
    // 00450c59  0f8dc0010000           -jge 0x450e1f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00450e1f;
    }
    // 00450c5f  6681ff0049             +cmp di, 0x4900
    {
        x86::reg16 tmp1 = cpu.di;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(18688 /*0x4900*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00450c64  0f8581000000           -jne 0x450ceb
    if (!cpu.flags.zf)
    {
        goto L_0x00450ceb;
    }
    // 00450c6a  6683b9b400000000       +cmp word ptr [ecx + 0xb4], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(180) /* 0xb4 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00450c72  7477                   -je 0x450ceb
    if (cpu.flags.zf)
    {
        goto L_0x00450ceb;
    }
    // 00450c74  ba7f000000             -mov edx, 0x7f
    cpu.edx = 127 /*0x7f*/;
    // 00450c79  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00450c7e  e84d75fcff             -call 0x4181d0
    cpu.esp -= 4;
    sub_4181d0(app, cpu);
    if (cpu.terminate) return;
    // 00450c83  8b417e                 -mov eax, dword ptr [ecx + 0x7e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(126) /* 0x7e */);
    // 00450c86  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00450c89  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 00450c90  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00450c92  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00450c94  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00450c97  c1e202                 +shl edx, 2
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
    // 00450c9a  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00450c9c  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 00450c9f  8b517c                 -mov edx, dword ptr [ecx + 0x7c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(124) /* 0x7c */);
    // 00450ca2  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00450ca5  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00450ca7  8915e4e55500           -mov dword ptr [0x55e5e4], edx
    app->getMemory<x86::reg32>(x86::reg32(5629412) /* 0x55e5e4 */) = cpu.edx;
    // 00450cad  8b9180000000           -mov edx, dword ptr [ecx + 0x80]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(128) /* 0x80 */);
    // 00450cb3  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00450cb6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00450cb8  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00450cbb  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00450cbd  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00450cbf  be02000000             -mov esi, 2
    cpu.esi = 2 /*0x2*/;
    // 00450cc4  668b99b4000000         -mov bx, word ptr [ecx + 0xb4]
    cpu.bx = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(180) /* 0xb4 */);
    // 00450ccb  8b517a                 -mov edx, dword ptr [ecx + 0x7a]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(122) /* 0x7a */);
    // 00450cce  4b                     -dec ebx
    (cpu.ebx)--;
    // 00450ccf  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00450cd2  668999b4000000         -mov word ptr [ecx + 0xb4], bx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(180) /* 0xb4 */) = cpu.bx;
    // 00450cd9  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00450cdb  a1e4e55500             -mov eax, dword ptr [0x55e5e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5629412) /* 0x55e5e4 */);
    // 00450ce0  8915e8e55500           -mov dword ptr [0x55e5e8], edx
    app->getMemory<x86::reg32>(x86::reg32(5629416) /* 0x55e5e8 */) = cpu.edx;
    // 00450ce6  e8d5b20400             -call 0x49bfc0
    cpu.esp -= 4;
    sub_49bfc0(app, cpu);
    if (cpu.terminate) return;
L_0x00450ceb:
    // 00450ceb  6681ff0051             +cmp di, 0x5100
    {
        x86::reg16 tmp1 = cpu.di;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(20736 /*0x5100*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00450cf0  0f859c000000           -jne 0x450d92
    if (!cpu.flags.zf)
    {
        goto L_0x00450d92;
    }
    // 00450cf6  8b4148                 -mov eax, dword ptr [ecx + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(72) /* 0x48 */);
    // 00450cf9  8b91b2000000           -mov edx, dword ptr [ecx + 0xb2]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(178) /* 0xb2 */);
    // 00450cff  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00450d02  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00450d05  8b5dfc                 -mov ebx, dword ptr [ebp - 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00450d08  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00450d0a  39d8                   +cmp eax, ebx
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
    // 00450d0c  0f8d80000000           -jge 0x450d92
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00450d92;
    }
    // 00450d12  ba7f000000             -mov edx, 0x7f
    cpu.edx = 127 /*0x7f*/;
    // 00450d17  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00450d1c  e8af74fcff             -call 0x4181d0
    cpu.esp -= 4;
    sub_4181d0(app, cpu);
    if (cpu.terminate) return;
    // 00450d21  8b8186000000           -mov eax, dword ptr [ecx + 0x86]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(134) /* 0x86 */);
    // 00450d27  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00450d2a  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 00450d31  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00450d33  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00450d35  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00450d38  c1e202                 +shl edx, 2
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
    // 00450d3b  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00450d3d  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 00450d40  8b9184000000           -mov edx, dword ptr [ecx + 0x84]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(132) /* 0x84 */);
    // 00450d46  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00450d49  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00450d4b  8915e4e55500           -mov dword ptr [0x55e5e4], edx
    app->getMemory<x86::reg32>(x86::reg32(5629412) /* 0x55e5e4 */) = cpu.edx;
    // 00450d51  8b9188000000           -mov edx, dword ptr [ecx + 0x88]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(136) /* 0x88 */);
    // 00450d57  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00450d5a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00450d5c  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00450d5f  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00450d61  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00450d63  668bb1b4000000         -mov si, word ptr [ecx + 0xb4]
    cpu.si = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(180) /* 0xb4 */);
    // 00450d6a  46                     -inc esi
    (cpu.esi)++;
    // 00450d6b  8b9182000000           -mov edx, dword ptr [ecx + 0x82]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(130) /* 0x82 */);
    // 00450d71  6689b1b4000000         -mov word ptr [ecx + 0xb4], si
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(180) /* 0xb4 */) = cpu.si;
    // 00450d78  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00450d7b  be02000000             -mov esi, 2
    cpu.esi = 2 /*0x2*/;
    // 00450d80  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00450d82  a1e4e55500             -mov eax, dword ptr [0x55e5e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5629412) /* 0x55e5e4 */);
    // 00450d87  8915e8e55500           -mov dword ptr [0x55e5e8], edx
    app->getMemory<x86::reg32>(x86::reg32(5629416) /* 0x55e5e8 */) = cpu.edx;
    // 00450d8d  e82eb20400             -call 0x49bfc0
    cpu.esp -= 4;
    sub_49bfc0(app, cpu);
    if (cpu.terminate) return;
L_0x00450d92:
    // 00450d92  6683ff0d               +cmp di, 0xd
    {
        x86::reg16 tmp1 = cpu.di;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(13 /*0xd*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00450d96  0f8583000000           -jne 0x450e1f
    if (!cpu.flags.zf)
    {
        goto L_0x00450e1f;
    }
    // 00450d9c  8d417c                 -lea eax, [ecx + 0x7c]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(124) /* 0x7c */);
    // 00450d9f  e84cb40400             -call 0x49c1f0
    cpu.esp -= 4;
    sub_49c1f0(app, cpu);
    if (cpu.terminate) return;
    // 00450da4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00450da6  742d                   -je 0x450dd5
    if (cpu.flags.zf)
    {
        goto L_0x00450dd5;
    }
    // 00450da8  6683b9b400000000       +cmp word ptr [ecx + 0xb4], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(180) /* 0xb4 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00450db0  7423                   -je 0x450dd5
    if (cpu.flags.zf)
    {
        goto L_0x00450dd5;
    }
    // 00450db2  ba7f000000             -mov edx, 0x7f
    cpu.edx = 127 /*0x7f*/;
    // 00450db7  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00450dbc  e80f74fcff             -call 0x4181d0
    cpu.esp -= 4;
    sub_4181d0(app, cpu);
    if (cpu.terminate) return;
    // 00450dc1  668b81b4000000         -mov ax, word ptr [ecx + 0xb4]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(180) /* 0xb4 */);
    // 00450dc8  48                     -dec eax
    (cpu.eax)--;
    // 00450dc9  be02000000             -mov esi, 2
    cpu.esi = 2 /*0x2*/;
    // 00450dce  668981b4000000         -mov word ptr [ecx + 0xb4], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(180) /* 0xb4 */) = cpu.ax;
L_0x00450dd5:
    // 00450dd5  8d8184000000           -lea eax, [ecx + 0x84]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(132) /* 0x84 */);
    // 00450ddb  e810b40400             -call 0x49c1f0
    cpu.esp -= 4;
    sub_49c1f0(app, cpu);
    if (cpu.terminate) return;
    // 00450de0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00450de2  743b                   -je 0x450e1f
    if (cpu.flags.zf)
    {
        goto L_0x00450e1f;
    }
    // 00450de4  8b4148                 -mov eax, dword ptr [ecx + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(72) /* 0x48 */);
    // 00450de7  8b91b2000000           -mov edx, dword ptr [ecx + 0xb2]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(178) /* 0xb2 */);
    // 00450ded  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00450df0  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00450df3  8b7dfc                 -mov edi, dword ptr [ebp - 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00450df6  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00450df8  39f8                   +cmp eax, edi
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
    // 00450dfa  7d23                   -jge 0x450e1f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00450e1f;
    }
    // 00450dfc  ba7f000000             -mov edx, 0x7f
    cpu.edx = 127 /*0x7f*/;
    // 00450e01  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00450e06  e8c573fcff             -call 0x4181d0
    cpu.esp -= 4;
    sub_4181d0(app, cpu);
    if (cpu.terminate) return;
    // 00450e0b  668b91b4000000         -mov dx, word ptr [ecx + 0xb4]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(180) /* 0xb4 */);
    // 00450e12  42                     -inc edx
    (cpu.edx)++;
    // 00450e13  be02000000             -mov esi, 2
    cpu.esi = 2 /*0x2*/;
    // 00450e18  668991b4000000         -mov word ptr [ecx + 0xb4], dx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(180) /* 0xb4 */) = cpu.dx;
L_0x00450e1f:
    // 00450e1f  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
L_0x00450e21:
    // 00450e21  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00450e23  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00450e25  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00450e26  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00450e27  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00450e28  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00450e29  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_450e30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00450e30  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00450e31  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00450e32  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00450e34  ba18000000             -mov edx, 0x18
    cpu.edx = 24 /*0x18*/;
    // 00450e39  e82298ffff             -call 0x44a660
    cpu.esp -= 4;
    sub_44a660(app, cpu);
    if (cpu.terminate) return;
    // 00450e3e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00450e40  7402                   -je 0x450e44
    if (cpu.flags.zf)
    {
        goto L_0x00450e44;
    }
    // 00450e42  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00450e44:
    // 00450e44  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00450e45  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00450e46  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_450e50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00450e50  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00450e51  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00450e52  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00450e54  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00450e56  83f801                 +cmp eax, 1
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
    // 00450e59  7240                   -jb 0x450e9b
    if (cpu.flags.cf)
    {
        goto L_0x00450e9b;
    }
    // 00450e5b  7607                   -jbe 0x450e64
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00450e64;
    }
    // 00450e5d  83f803                 +cmp eax, 3
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
    // 00450e60  7428                   -je 0x450e8a
    if (cpu.flags.zf)
    {
        goto L_0x00450e8a;
    }
    // 00450e62  eb37                   -jmp 0x450e9b
    goto L_0x00450e9b;
L_0x00450e64:
    // 00450e64  e85738ffff             -call 0x4446c0
    cpu.esp -= 4;
    sub_4446c0(app, cpu);
    if (cpu.terminate) return;
    // 00450e69  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00450e6b  7607                   -jbe 0x450e74
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00450e74;
    }
    // 00450e6d  83f801                 +cmp eax, 1
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
    // 00450e70  7407                   -je 0x450e79
    if (cpu.flags.zf)
    {
        goto L_0x00450e79;
    }
    // 00450e72  eb05                   -jmp 0x450e79
    goto L_0x00450e79;
L_0x00450e74:
    // 00450e74  e847edffff             -call 0x44fbc0
    cpu.esp -= 4;
    sub_44fbc0(app, cpu);
    if (cpu.terminate) return;
L_0x00450e79:
    // 00450e79  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00450e7b  7403                   -je 0x450e80
    if (cpu.flags.zf)
    {
        goto L_0x00450e80;
    }
    // 00450e7d  c60201                 -mov byte ptr [edx], 1
    app->getMemory<x86::reg8>(cpu.edx) = 1 /*0x1*/;
L_0x00450e80:
    // 00450e80  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 00450e85  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00450e87  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00450e88  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00450e89  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00450e8a:
    // 00450e8a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00450e8c  7403                   -je 0x450e91
    if (cpu.flags.zf)
    {
        goto L_0x00450e91;
    }
    // 00450e8e  c60201                 -mov byte ptr [edx], 1
    app->getMemory<x86::reg8>(cpu.edx) = 1 /*0x1*/;
L_0x00450e91:
    // 00450e91  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 00450e96  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00450e98  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00450e99  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00450e9a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00450e9b:
    // 00450e9b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00450e9d  7403                   -je 0x450ea2
    if (cpu.flags.zf)
    {
        goto L_0x00450ea2;
    }
    // 00450e9f  c60200                 -mov byte ptr [edx], 0
    app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
L_0x00450ea2:
    // 00450ea2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00450ea4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00450ea5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00450ea6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_450eb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00450eb0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00450eb1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00450eb2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00450eb3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00450eb4  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00450eb6  b8c4000000             -mov eax, 0xc4
    cpu.eax = 196 /*0xc4*/;
    // 00450ebb  e890090800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00450ec0  a3e4456600             -mov dword ptr [0x6645e4], eax
    app->getMemory<x86::reg32>(x86::reg32(6702564) /* 0x6645e4 */) = cpu.eax;
    // 00450ec5  b8c5000000             -mov eax, 0xc5
    cpu.eax = 197 /*0xc5*/;
    // 00450eca  e881090800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00450ecf  a3e8456600             -mov dword ptr [0x6645e8], eax
    app->getMemory<x86::reg32>(x86::reg32(6702568) /* 0x6645e8 */) = cpu.eax;
    // 00450ed4  b845010000             -mov eax, 0x145
    cpu.eax = 325 /*0x145*/;
    // 00450ed9  e872090800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00450ede  68500e4500             -push 0x450e50
    app->getMemory<x86::reg32>(cpu.esp-4) = 4525648 /*0x450e50*/;
    cpu.esp -= 4;
    // 00450ee3  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00450ee5  b9e4456600             -mov ecx, 0x6645e4
    cpu.ecx = 6702564 /*0x6645e4*/;
    // 00450eea  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00450eec  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 00450ef1  baec456600             -mov edx, 0x6645ec
    cpu.edx = 6702572 /*0x6645ec*/;
    // 00450ef6  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00450ef8  a3ec456600             -mov dword ptr [0x6645ec], eax
    app->getMemory<x86::reg32>(x86::reg32(6702572) /* 0x6645ec */) = cpu.eax;
    // 00450efd  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00450f02  e8c937ffff             -call 0x4446d0
    cpu.esp -= 4;
    sub_4446d0(app, cpu);
    if (cpu.terminate) return;
    // 00450f07  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00450f0c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00450f0d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00450f0e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00450f0f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00450f10  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_450f20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00450f20  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00450f21  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00450f22  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00450f24  833d2494550000         +cmp dword ptr [0x559424], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5608484) /* 0x559424 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00450f2b  7434                   -je 0x450f61
    if (cpu.flags.zf)
    {
        goto L_0x00450f61;
    }
    // 00450f2d  e89ee6ffff             -call 0x44f5d0
    cpu.esp -= 4;
    sub_44f5d0(app, cpu);
    if (cpu.terminate) return;
    // 00450f32  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00450f34  7422                   -je 0x450f58
    if (cpu.flags.zf)
    {
        goto L_0x00450f58;
    }
    // 00450f36  8b151c945500           -mov edx, dword ptr [0x55941c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5608476) /* 0x55941c */);
    // 00450f3c  a118945500             -mov eax, dword ptr [0x559418]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5608472) /* 0x559418 */);
    // 00450f41  e88ae9ffff             -call 0x44f8d0
    cpu.esp -= 4;
    sub_44f8d0(app, cpu);
    if (cpu.terminate) return;
    // 00450f46  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00450f48  740e                   -je 0x450f58
    if (cpu.flags.zf)
    {
        goto L_0x00450f58;
    }
    // 00450f4a  a124945500             -mov eax, dword ptr [0x559424]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5608484) /* 0x559424 */);
    // 00450f4f  806004fe               -and byte ptr [eax + 4], 0xfe
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 00450f53  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00450f55  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00450f56  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00450f57  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00450f58:
    // 00450f58  a124945500             -mov eax, dword ptr [0x559424]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5608484) /* 0x559424 */);
    // 00450f5d  80480401               -or byte ptr [eax + 4], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x00450f61:
    // 00450f61  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00450f63  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00450f64  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00450f65  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_450f70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00450f70  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00450f71  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00450f72  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00450f73  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00450f75  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00450f77  bac0955300             -mov edx, 0x5395c0
    cpu.edx = 5477824 /*0x5395c0*/;
    // 00450f7c  e8bf1affff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00450f81  a324945500             -mov dword ptr [0x559424], eax
    app->getMemory<x86::reg32>(x86::reg32(5608484) /* 0x559424 */) = cpu.eax;
    // 00450f86  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00450f88  7407                   -je 0x450f91
    if (cpu.flags.zf)
    {
        goto L_0x00450f91;
    }
    // 00450f8a  c74064b00e4500         -mov dword ptr [eax + 0x64], 0x450eb0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(100) /* 0x64 */) = 4525744 /*0x450eb0*/;
L_0x00450f91:
    // 00450f91  8b154cbb6f00           -mov edx, dword ptr [0x6fbb4c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(7322444) /* 0x6fbb4c */);
    // 00450f97  83fa01                 +cmp edx, 1
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
    // 00450f9a  7405                   -je 0x450fa1
    if (cpu.flags.zf)
    {
        goto L_0x00450fa1;
    }
    // 00450f9c  83fa05                 +cmp edx, 5
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
    // 00450f9f  7522                   -jne 0x450fc3
    if (!cpu.flags.zf)
    {
        goto L_0x00450fc3;
    }
L_0x00450fa1:
    // 00450fa1  bad0955300             -mov edx, 0x5395d0
    cpu.edx = 5477840 /*0x5395d0*/;
    // 00450fa6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00450fa8  e8931affff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00450fad  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00450faf  7412                   -je 0x450fc3
    if (cpu.flags.zf)
    {
        goto L_0x00450fc3;
    }
    // 00450fb1  66c740445900           -mov word ptr [eax + 0x44], 0x59
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(68) /* 0x44 */) = 89 /*0x59*/;
    // 00450fb7  66c740462a00           -mov word ptr [eax + 0x46], 0x2a
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(70) /* 0x46 */) = 42 /*0x2a*/;
    // 00450fbd  66c740424800           -mov word ptr [eax + 0x42], 0x48
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(66) /* 0x42 */) = 72 /*0x48*/;
L_0x00450fc3:
    // 00450fc3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00450fc5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00450fc6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00450fc7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00450fc8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_450fd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00450fd0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00450fd1  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00450fd3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00450fd5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00450fd6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_450fe0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00450fe0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00450fe1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00450fe2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00450fe3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00450fe4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00450fe5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00450fe6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00450fe8  81ec30070000           -sub esp, 0x730
    (cpu.esp) -= x86::reg32(x86::sreg32(1840 /*0x730*/));
    // 00450fee  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 00450ff1  8b90f0010000           -mov edx, dword ptr [eax + 0x1f0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(496) /* 0x1f0 */);
    // 00450ff7  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00450ffe  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00451000  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00451003  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00451005  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00451008  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0045100a  ba2cd56f00             -mov edx, 0x6fd52c
    cpu.edx = 7329068 /*0x6fd52c*/;
    // 0045100f  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00451011  8d9decfdffff           -lea ebx, [ebp - 0x214]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-532) /* -0x214 */);
    // 00451017  8b4214                 -mov eax, dword ptr [edx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 0045101a  8955ec                 -mov dword ptr [ebp - 0x14], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.edx;
    // 0045101d  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 00451020  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00451022  8d85ecfdffff           -lea eax, [ebp - 0x214]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-532) /* -0x214 */);
    // 00451028  8955f4                 -mov dword ptr [ebp - 0xc], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edx;
    // 0045102b  8955f8                 -mov dword ptr [ebp - 8], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edx;
    // 0045102e  8d95ecfdffff           -lea edx, [ebp - 0x214]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-532) /* -0x214 */);
    // 00451034  e857eaffff             -call 0x44fa90
    cpu.esp -= 4;
    sub_44fa90(app, cpu);
    if (cpu.terminate) return;
    // 00451039  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0045103b  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0045103e  8b8020020000           -mov eax, dword ptr [eax + 0x220]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(544) /* 0x220 */);
    // 00451044  8b3530dc6f00           -mov esi, dword ptr [0x6fdc30]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(7330864) /* 0x6fdc30 */);
    // 0045104a  8b4014                 -mov eax, dword ptr [eax + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 0045104d  39f0                   +cmp eax, esi
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
    // 0045104f  7507                   -jne 0x451058
    if (!cpu.flags.zf)
    {
        goto L_0x00451058;
    }
    // 00451051  31f0                   +xor eax, esi
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 00451053  e981020000             -jmp 0x4512d9
    goto L_0x004512d9;
L_0x00451058:
    // 00451058  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0045105b  f6800002000001         +test byte ptr [eax + 0x200], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(512) /* 0x200 */) & 1 /*0x1*/));
    // 00451062  750b                   -jne 0x45106f
    if (!cpu.flags.zf)
    {
        goto L_0x0045106f;
    }
    // 00451064  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00451066  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00451068  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00451069  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045106a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045106b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045106c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045106d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045106e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045106f:
    // 0045106f  8b8038020000           -mov eax, dword ptr [eax + 0x238]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(568) /* 0x238 */);
    // 00451075  e8e6e8ffff             -call 0x44f960
    cpu.esp -= 4;
    sub_44f960(app, cpu);
    if (cpu.terminate) return;
    // 0045107a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045107c  0f8459010000           -je 0x4511db
    if (cpu.flags.zf)
    {
        goto L_0x004511db;
    }
    // 00451082  8b75ec                 -mov esi, dword ptr [ebp - 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00451085  8dbdd4f8ffff           -lea edi, [ebp - 0x72c]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-1836) /* -0x72c */);
    // 0045108b  83c634                 -add esi, 0x34
    (cpu.esi) += x86::reg32(x86::sreg32(52 /*0x34*/));
    // 0045108e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0045108f:
    // 0045108f  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00451091  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00451093  3c00                   +cmp al, 0
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
    // 00451095  7410                   -je 0x4510a7
    if (cpu.flags.zf)
    {
        goto L_0x004510a7;
    }
    // 00451097  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0045109a  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0045109d  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004510a0  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004510a3  3c00                   +cmp al, 0
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
    // 004510a5  75e8                   -jne 0x45108f
    if (!cpu.flags.zf)
    {
        goto L_0x0045108f;
    }
L_0x004510a7:
    // 004510a7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004510a8  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004510ab  8dbddff8ffff           -lea edi, [ebp - 0x721]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-1825) /* -0x721 */);
    // 004510b1  e89a81feff             -call 0x439250
    cpu.esp -= 4;
    sub_439250(app, cpu);
    if (cpu.terminate) return;
    // 004510b6  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004510b8  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004510ba  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x004510bb:
    // 004510bb  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004510bd  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004510bf  3c00                   +cmp al, 0
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
    // 004510c1  7410                   -je 0x4510d3
    if (cpu.flags.zf)
    {
        goto L_0x004510d3;
    }
    // 004510c3  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004510c6  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004510c9  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004510cc  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004510cf  3c00                   +cmp al, 0
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
    // 004510d1  75e8                   -jne 0x4510bb
    if (!cpu.flags.zf)
    {
        goto L_0x004510bb;
    }
L_0x004510d3:
    // 004510d3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004510d4  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004510d7  8dbddff9ffff           -lea edi, [ebp - 0x621]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-1569) /* -0x621 */);
    // 004510dd  e8ce89feff             -call 0x439ab0
    cpu.esp -= 4;
    sub_439ab0(app, cpu);
    if (cpu.terminate) return;
    // 004510e2  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004510e4  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004510e9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x004510ea:
    // 004510ea  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004510ec  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004510ee  3c00                   +cmp al, 0
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
    // 004510f0  7410                   -je 0x451102
    if (cpu.flags.zf)
    {
        goto L_0x00451102;
    }
    // 004510f2  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004510f5  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004510f8  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004510fb  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004510fe  3c00                   +cmp al, 0
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
    // 00451100  75e8                   -jne 0x4510ea
    if (!cpu.flags.zf)
    {
        goto L_0x004510ea;
    }
L_0x00451102:
    // 00451102  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00451103  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00451106  8dbddffaffff           -lea edi, [ebp - 0x521]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-1313) /* -0x521 */);
    // 0045110c  e89f89feff             -call 0x439ab0
    cpu.esp -= 4;
    sub_439ab0(app, cpu);
    if (cpu.terminate) return;
    // 00451111  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00451113  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00451114:
    // 00451114  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00451116  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00451118  3c00                   +cmp al, 0
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
    // 0045111a  7410                   -je 0x45112c
    if (cpu.flags.zf)
    {
        goto L_0x0045112c;
    }
    // 0045111c  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0045111f  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00451122  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00451125  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00451128  3c00                   +cmp al, 0
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
    // 0045112a  75e8                   -jne 0x451114
    if (!cpu.flags.zf)
    {
        goto L_0x00451114;
    }
L_0x0045112c:
    // 0045112c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045112d  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00451130  8b8038020000           -mov eax, dword ptr [eax + 0x238]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(568) /* 0x238 */);
    // 00451136  8985e0fbffff           -mov dword ptr [ebp - 0x420], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-1056) /* -0x420 */) = cpu.eax;
    // 0045113c  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0045113f  8b80b8020000           -mov eax, dword ptr [eax + 0x2b8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(696) /* 0x2b8 */);
    // 00451145  668b1594d46f00         -mov dx, word ptr [0x6fd494]
    cpu.dx = app->getMemory<x86::reg16>(x86::reg32(7328916) /* 0x6fd494 */);
    // 0045114c  8985e4fbffff           -mov dword ptr [ebp - 0x41c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-1052) /* -0x41c */) = cpu.eax;
    // 00451152  66a190d46f00           -mov ax, word ptr [0x6fd490]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(7328912) /* 0x6fd490 */);
    // 00451158  668b0d98d46f00         -mov cx, word ptr [0x6fd498]
    cpu.cx = app->getMemory<x86::reg16>(x86::reg32(7328920) /* 0x6fd498 */);
    // 0045115f  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 00451161  668b359cd46f00         -mov si, word ptr [0x6fd49c]
    cpu.si = app->getMemory<x86::reg16>(x86::reg32(7328924) /* 0x6fd49c */);
    // 00451168  09c8                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0045116a  668b3da0d46f00         -mov di, word ptr [0x6fd4a0]
    cpu.di = app->getMemory<x86::reg16>(x86::reg32(7328928) /* 0x6fd4a0 */);
    // 00451171  09f0                   -or eax, esi
    cpu.eax |= x86::reg32(x86::sreg32(cpu.esi));
    // 00451173  668b15a4d46f00         -mov dx, word ptr [0x6fd4a4]
    cpu.dx = app->getMemory<x86::reg16>(x86::reg32(7328932) /* 0x6fd4a4 */);
    // 0045117a  09f8                   -or eax, edi
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edi));
    // 0045117c  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0045117e  66c785eafbffff0100     -mov word ptr [ebp - 0x416], 1
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-1046) /* -0x416 */) = 1 /*0x1*/;
    // 00451187  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 0045118c  668995e8fbffff         -mov word ptr [ebp - 0x418], dx
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-1048) /* -0x418 */) = cpu.dx;
    // 00451193  e898e6ffff             -call 0x44f830
    cpu.esp -= 4;
    sub_44f830(app, cpu);
    if (cpu.terminate) return;
    // 00451198  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045119a  e871e7ffff             -call 0x44f910
    cpu.esp -= 4;
    sub_44f910(app, cpu);
    if (cpu.terminate) return;
    // 0045119f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004511a1  741a                   -je 0x4511bd
    if (cpu.flags.zf)
    {
        goto L_0x004511bd;
    }
    // 004511a3  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004511a6  8bb810030000           -mov edi, dword ptr [eax + 0x310]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(784) /* 0x310 */);
    // 004511ac  3bba38020000           +cmp edi, dword ptr [edx + 0x238]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(568) /* 0x238 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004511b2  7e09                   -jle 0x4511bd
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004511bd;
    }
    // 004511b4  c745f802000000         -mov dword ptr [ebp - 8], 2
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = 2 /*0x2*/;
    // 004511bb  eb04                   -jmp 0x4511c1
    goto L_0x004511c1;
L_0x004511bd:
    // 004511bd  804df804               -or byte ptr [ebp - 8], 4
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-8) /* -0x8 */) |= x86::reg8(x86::sreg8(4 /*0x4*/));
L_0x004511c1:
    // 004511c1  b9c7000000             -mov ecx, 0xc7
    cpu.ecx = 199 /*0xc7*/;
    // 004511c6  81ec1c030000           -sub esp, 0x31c
    (cpu.esp) -= x86::reg32(x86::sreg32(796 /*0x31c*/));
    // 004511cc  8db5d0f8ffff           -lea esi, [ebp - 0x730]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-1840) /* -0x730 */);
    // 004511d2  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 004511d4  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004511d6  e835e8ffff             -call 0x44fa10
    cpu.esp -= 4;
    sub_44fa10(app, cpu);
    if (cpu.terminate) return;
L_0x004511db:
    // 004511db  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004511dd:
    // 004511dd  3b05b4d46f00           +cmp eax, dword ptr [0x6fd4b4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(7328948) /* 0x6fd4b4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004511e3  7d39                   -jge 0x45121e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0045121e;
    }
    // 004511e5  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004511e8  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 004511ef  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004511f1  8bb240020000           -mov esi, dword ptr [edx + 0x240]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(576) /* 0x240 */);
    // 004511f7  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004511f9  7420                   -je 0x45121b
    if (cpu.flags.zf)
    {
        goto L_0x0045121b;
    }
    // 004511fb  8b7df4                 -mov edi, dword ptr [ebp - 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004511fe  39fe                   +cmp esi, edi
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
    // 00451200  7c04                   -jl 0x451206
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00451206;
    }
    // 00451202  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00451204  7515                   -jne 0x45121b
    if (!cpu.flags.zf)
    {
        goto L_0x0045121b;
    }
L_0x00451206:
    // 00451206  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00451209  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 00451210  01ca                   +add edx, ecx
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00451212  8b9240020000           -mov edx, dword ptr [edx + 0x240]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(576) /* 0x240 */);
    // 00451218  8955f4                 -mov dword ptr [ebp - 0xc], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edx;
L_0x0045121b:
    // 0045121b  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0045121c  ebbf                   -jmp 0x4511dd
    goto L_0x004511dd;
L_0x0045121e:
    // 0045121e  8b75f4                 -mov esi, dword ptr [ebp - 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00451221  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00451223  0f84ad000000           -je 0x4512d6
    if (cpu.flags.zf)
    {
        goto L_0x004512d6;
    }
    // 00451229  39f3                   +cmp ebx, esi
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
    // 0045122b  7f08                   -jg 0x451235
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00451235;
    }
    // 0045122d  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0045122f  0f85a1000000           -jne 0x4512d6
    if (!cpu.flags.zf)
    {
        goto L_0x004512d6;
    }
L_0x00451235:
    // 00451235  8b75ec                 -mov esi, dword ptr [ebp - 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00451238  8dbdecfbffff           -lea edi, [ebp - 0x414]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-1044) /* -0x414 */);
    // 0045123e  8b4df4                 -mov ecx, dword ptr [ebp - 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00451241  83c634                 -add esi, 0x34
    (cpu.esi) += x86::reg32(x86::sreg32(52 /*0x34*/));
    // 00451244  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00451246  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00451247:
    // 00451247  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00451249  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0045124b  3c00                   +cmp al, 0
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
    // 0045124d  7410                   -je 0x45125f
    if (cpu.flags.zf)
    {
        goto L_0x0045125f;
    }
    // 0045124f  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00451252  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00451255  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00451258  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0045125b  3c00                   +cmp al, 0
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
    // 0045125d  75e8                   -jne 0x451247
    if (!cpu.flags.zf)
    {
        goto L_0x00451247;
    }
L_0x0045125f:
    // 0045125f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00451260  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00451263  8dbdecfeffff           -lea edi, [ebp - 0x114]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-276) /* -0x114 */);
    // 00451269  e84288feff             -call 0x439ab0
    cpu.esp -= 4;
    sub_439ab0(app, cpu);
    if (cpu.terminate) return;
    // 0045126e  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00451270  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00451275  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00451276:
    // 00451276  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00451278  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0045127a  3c00                   +cmp al, 0
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
    // 0045127c  7410                   -je 0x45128e
    if (cpu.flags.zf)
    {
        goto L_0x0045128e;
    }
    // 0045127e  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00451281  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00451284  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00451287  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0045128a  3c00                   +cmp al, 0
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
    // 0045128c  75e8                   -jne 0x451276
    if (!cpu.flags.zf)
    {
        goto L_0x00451276;
    }
L_0x0045128e:
    // 0045128e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045128f  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00451292  8dbdecfcffff           -lea edi, [ebp - 0x314]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-788) /* -0x314 */);
    // 00451298  e81388feff             -call 0x439ab0
    cpu.esp -= 4;
    sub_439ab0(app, cpu);
    if (cpu.terminate) return;
    // 0045129d  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0045129f  8d9decfcffff           -lea ebx, [ebp - 0x314]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-788) /* -0x314 */);
    // 004512a5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x004512a6:
    // 004512a6  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004512a8  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004512aa  3c00                   +cmp al, 0
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
    // 004512ac  7410                   -je 0x4512be
    if (cpu.flags.zf)
    {
        goto L_0x004512be;
    }
    // 004512ae  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004512b1  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004512b4  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004512b7  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004512ba  3c00                   +cmp al, 0
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
    // 004512bc  75e8                   -jne 0x4512a6
    if (!cpu.flags.zf)
    {
        goto L_0x004512a6;
    }
L_0x004512be:
    // 004512be  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004512bf  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004512c1  8d95ecfeffff           -lea edx, [ebp - 0x114]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-276) /* -0x114 */);
    // 004512c7  8d85ecfbffff           -lea eax, [ebp - 0x414]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-1044) /* -0x414 */);
    // 004512cd  e85ee8ffff             -call 0x44fb30
    cpu.esp -= 4;
    sub_44fb30(app, cpu);
    if (cpu.terminate) return;
    // 004512d2  804df801               -or byte ptr [ebp - 8], 1
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-8) /* -0x8 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x004512d6:
    // 004512d6  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
L_0x004512d9:
    // 004512d9  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004512db  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004512dc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004512dd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004512de  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004512df  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004512e0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004512e1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_4512f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004512f0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004512f1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004512f2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004512f3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004512f5  a1b2d46f00             -mov eax, dword ptr [0x6fd4b2]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328946) /* 0x6fd4b2 */);
    // 004512fa  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004512fd  e85ede0700             -call 0x4cf160
    cpu.esp -= 4;
    sub_4cf160(app, cpu);
    if (cpu.terminate) return;
    // 00451302  0fbfd0                 -movsx edx, ax
    cpu.edx = x86::reg32(static_cast<x86::sreg16>(cpu.ax));
    // 00451305  a1acd46f00             -mov eax, dword ptr [0x6fd4ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328940) /* 0x6fd4ac */);
    // 0045130a  e861e3ffff             -call 0x44f670
    cpu.esp -= 4;
    sub_44f670(app, cpu);
    if (cpu.terminate) return;
    // 0045130f  8b15f4d46f00           -mov edx, dword ptr [0x6fd4f4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(7329012) /* 0x6fd4f4 */);
    // 00451315  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00451317  e8c4410000             -call 0x4554e0
    cpu.esp -= 4;
    sub_4554e0(app, cpu);
    if (cpu.terminate) return;
    // 0045131c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045131e  743f                   -je 0x45135f
    if (cpu.flags.zf)
    {
        goto L_0x0045135f;
    }
    // 00451320  83b8c402000004         +cmp dword ptr [eax + 0x2c4], 4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(708) /* 0x2c4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00451327  7436                   -je 0x45135f
    if (cpu.flags.zf)
    {
        goto L_0x0045135f;
    }
    // 00451329  e8b2fcffff             -call 0x450fe0
    cpu.esp -= 4;
    sub_450fe0(app, cpu);
    if (cpu.terminate) return;
    // 0045132e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00451330  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 00451332  7409                   -je 0x45133d
    if (cpu.flags.zf)
    {
        goto L_0x0045133d;
    }
    // 00451334  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00451336  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00451338  e8b3d4ffff             -call 0x44e7f0
    cpu.esp -= 4;
    sub_44e7f0(app, cpu);
    if (cpu.terminate) return;
L_0x0045133d:
    // 0045133d  f6c104                 +test cl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 4 /*0x4*/));
    // 00451340  740c                   -je 0x45134e
    if (cpu.flags.zf)
    {
        goto L_0x0045134e;
    }
    // 00451342  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00451347  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00451349  e8a2d4ffff             -call 0x44e7f0
    cpu.esp -= 4;
    sub_44e7f0(app, cpu);
    if (cpu.terminate) return;
L_0x0045134e:
    // 0045134e  f6c102                 +test cl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 2 /*0x2*/));
    // 00451351  740c                   -je 0x45135f
    if (cpu.flags.zf)
    {
        goto L_0x0045135f;
    }
    // 00451353  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00451358  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0045135a  e891d4ffff             -call 0x44e7f0
    cpu.esp -= 4;
    sub_44e7f0(app, cpu);
    if (cpu.terminate) return;
L_0x0045135f:
    // 0045135f  8b0db0d36f00           -mov ecx, dword ptr [0x6fd3b0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */);
    // 00451365  83f901                 +cmp ecx, 1
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
    // 00451368  7552                   -jne 0x4513bc
    if (!cpu.flags.zf)
    {
        goto L_0x004513bc;
    }
    // 0045136a  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0045136c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045136e  e86d410000             -call 0x4554e0
    cpu.esp -= 4;
    sub_4554e0(app, cpu);
    if (cpu.terminate) return;
    // 00451373  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00451375  7445                   -je 0x4513bc
    if (cpu.flags.zf)
    {
        goto L_0x004513bc;
    }
    // 00451377  83b8c402000004         +cmp dword ptr [eax + 0x2c4], 4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(708) /* 0x2c4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045137e  743c                   -je 0x4513bc
    if (cpu.flags.zf)
    {
        goto L_0x004513bc;
    }
    // 00451380  e85bfcffff             -call 0x450fe0
    cpu.esp -= 4;
    sub_450fe0(app, cpu);
    if (cpu.terminate) return;
    // 00451385  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00451387  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 00451389  740c                   -je 0x451397
    if (cpu.flags.zf)
    {
        goto L_0x00451397;
    }
    // 0045138b  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00451390  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00451392  e859d4ffff             -call 0x44e7f0
    cpu.esp -= 4;
    sub_44e7f0(app, cpu);
    if (cpu.terminate) return;
L_0x00451397:
    // 00451397  f6c104                 +test cl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 4 /*0x4*/));
    // 0045139a  740f                   -je 0x4513ab
    if (cpu.flags.zf)
    {
        goto L_0x004513ab;
    }
    // 0045139c  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004513a1  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 004513a6  e845d4ffff             -call 0x44e7f0
    cpu.esp -= 4;
    sub_44e7f0(app, cpu);
    if (cpu.terminate) return;
L_0x004513ab:
    // 004513ab  f6c102                 +test cl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 2 /*0x2*/));
    // 004513ae  740c                   -je 0x4513bc
    if (cpu.flags.zf)
    {
        goto L_0x004513bc;
    }
    // 004513b0  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004513b5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004513b7  e834d4ffff             -call 0x44e7f0
    cpu.esp -= 4;
    sub_44e7f0(app, cpu);
    if (cpu.terminate) return;
L_0x004513bc:
    // 004513bc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004513bd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004513be  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004513bf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4513c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004513c0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004513c1  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004513c3  833d3492550000         +cmp dword ptr [0x559234], 0
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
    // 004513ca  7407                   -je 0x4513d3
    if (cpu.flags.zf)
    {
        goto L_0x004513d3;
    }
    // 004513cc  a3341b5600             -mov dword ptr [0x561b34], eax
    app->getMemory<x86::reg32>(x86::reg32(5643060) /* 0x561b34 */) = cpu.eax;
    // 004513d1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004513d2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004513d3:
    // 004513d3  a334945500             -mov dword ptr [0x559434], eax
    app->getMemory<x86::reg32>(x86::reg32(5608500) /* 0x559434 */) = cpu.eax;
    // 004513d8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004513d9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_4513e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004513e0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004513e1  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004513e3  833d3492550000         +cmp dword ptr [0x559234], 0
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
    // 004513ea  7407                   -je 0x4513f3
    if (cpu.flags.zf)
    {
        goto L_0x004513f3;
    }
    // 004513ec  a3381b5600             -mov dword ptr [0x561b38], eax
    app->getMemory<x86::reg32>(x86::reg32(5643064) /* 0x561b38 */) = cpu.eax;
    // 004513f1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004513f2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004513f3:
    // 004513f3  a338945500             -mov dword ptr [0x559438], eax
    app->getMemory<x86::reg32>(x86::reg32(5608504) /* 0x559438 */) = cpu.eax;
    // 004513f8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004513f9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_451400(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00451400  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00451401  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00451402  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00451403  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00451404  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00451405  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00451407  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0045140a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0045140c  8d4df4                 -lea ecx, [ebp - 0xc]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0045140f  8d5df0                 -lea ebx, [ebp - 0x10]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00451412  8d55fc                 -lea edx, [ebp - 4]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00451415  8d45f8                 -lea eax, [ebp - 8]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00451418  e863d70600             -call 0x4beb80
    cpu.esp -= 4;
    sub_4beb80(app, cpu);
    if (cpu.terminate) return;
    // 0045141d  0faf75f0               -imul esi, dword ptr [ebp - 0x10]
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */))));
    // 00451421  b980020000             -mov ecx, 0x280
    cpu.ecx = 640 /*0x280*/;
    // 00451426  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00451428  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0045142a  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0045142d  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0045142f  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00451431  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00451432  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00451433  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00451434  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00451435  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00451436  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_451440(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00451440  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00451441  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00451442  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00451443  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00451444  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00451445  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00451447  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0045144a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0045144c  8d4df4                 -lea ecx, [ebp - 0xc]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0045144f  8d5df0                 -lea ebx, [ebp - 0x10]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00451452  8d55fc                 -lea edx, [ebp - 4]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00451455  8d45f8                 -lea eax, [ebp - 8]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00451458  e823d70600             -call 0x4beb80
    cpu.esp -= 4;
    sub_4beb80(app, cpu);
    if (cpu.terminate) return;
    // 0045145d  0faf75f4               -imul esi, dword ptr [ebp - 0xc]
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */))));
    // 00451461  b9e0010000             -mov ecx, 0x1e0
    cpu.ecx = 480 /*0x1e0*/;
    // 00451466  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00451468  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0045146a  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0045146d  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0045146f  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00451471  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00451472  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00451473  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00451474  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00451475  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00451476  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_451480(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00451480  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00451481  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00451482  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00451483  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00451484  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00451485  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00451487  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0045148a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0045148c  8d4df4                 -lea ecx, [ebp - 0xc]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0045148f  8d5df0                 -lea ebx, [ebp - 0x10]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00451492  8d55fc                 -lea edx, [ebp - 4]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00451495  8d45f8                 -lea eax, [ebp - 8]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00451498  e8e3d60600             -call 0x4beb80
    cpu.esp -= 4;
    sub_4beb80(app, cpu);
    if (cpu.terminate) return;
    // 0045149d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0045149f  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 004514a2  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004514a4  c1e607                 -shl esi, 7
    cpu.esi <<= 7 /*0x7*/ % 32;
    // 004514a7  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004514aa  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004514ac  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004514ae  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004514b1  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004514b3  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004514b5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004514b6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004514b7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004514b8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004514b9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004514ba  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_4514c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004514c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004514c1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004514c2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004514c3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004514c4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004514c5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004514c7  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004514ca  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004514cc  8d4df4                 -lea ecx, [ebp - 0xc]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004514cf  8d5df0                 -lea ebx, [ebp - 0x10]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004514d2  8d55fc                 -lea edx, [ebp - 4]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004514d5  8d45f8                 -lea eax, [ebp - 8]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004514d8  c1e605                 -shl esi, 5
    cpu.esi <<= 5 /*0x5*/ % 32;
    // 004514db  e8a0d60600             -call 0x4beb80
    cpu.esp -= 4;
    sub_4beb80(app, cpu);
    if (cpu.terminate) return;
    // 004514e0  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004514e2  c1e604                 -shl esi, 4
    cpu.esi <<= 4 /*0x4*/ % 32;
    // 004514e5  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004514e7  8b4df4                 -mov ecx, dword ptr [ebp - 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004514ea  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004514ec  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004514ee  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004514f1  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004514f3  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004514f5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004514f6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004514f7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004514f8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004514f9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004514fa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_451500(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00451500  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00451501  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00451502  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00451503  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00451505  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00451507  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00451509  e8023efeff             -call 0x435310
    cpu.esp -= 4;
    sub_435310(app, cpu);
    if (cpu.terminate) return;
    // 0045150e  833d3492550000         +cmp dword ptr [0x559234], 0
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
    // 00451515  7412                   -je 0x451529
    if (cpu.flags.zf)
    {
        goto L_0x00451529;
    }
    // 00451517  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 00451519  e862ffffff             -call 0x451480
    cpu.esp -= 4;
    sub_451480(app, cpu);
    if (cpu.terminate) return;
    // 0045151e  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 00451520  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00451522  e899ffffff             -call 0x4514c0
    cpu.esp -= 4;
    sub_4514c0(app, cpu);
    if (cpu.terminate) return;
    // 00451527  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
L_0x00451529:
    // 00451529  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045152a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045152b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045152c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_451530(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00451530  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00451531  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00451533  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00451536  833d3492550000         +cmp dword ptr [0x559234], 0
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
    // 0045153d  7436                   -je 0x451575
    if (cpu.flags.zf)
    {
        goto L_0x00451575;
    }
    // 0045153f  d94508                 +fld dword ptr [ebp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */)));
    // 00451542  d9e8                   +fld1 
    cpu.fpu.push(1.0);
    // 00451544  d9c9                   +fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00451546  dd5df8                 +fstp qword ptr [ebp - 8]
    app->getMemory<double>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00451549  dc5df8                 +fcomp qword ptr [ebp - 8]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    cpu.fpu.pop();
    // 0045154c  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0045154e  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0045154f  7707                   -ja 0x451558
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00451558;
    }
    // 00451551  a1501b7900             -mov eax, dword ptr [0x791b50]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7936848) /* 0x791b50 */);
    // 00451556  eb1a                   -jmp 0x451572
    goto L_0x00451572;
L_0x00451558:
    // 00451558  dd45f8                 +fld qword ptr [ebp - 8]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 0045155b  dc1de0955300           +fcomp qword ptr [0x5395e0]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(5477856) /* 0x5395e0 */)));
    cpu.fpu.pop();
    // 00451561  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00451563  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00451564  7207                   -jb 0x45156d
    if (cpu.flags.cf)
    {
        goto L_0x0045156d;
    }
    // 00451566  a1541b7900             -mov eax, dword ptr [0x791b54]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7936852) /* 0x791b54 */);
    // 0045156b  eb05                   -jmp 0x451572
    goto L_0x00451572;
L_0x0045156d:
    // 0045156d  a14c1b7900             -mov eax, dword ptr [0x791b4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7936844) /* 0x791b4c */);
L_0x00451572:
    // 00451572  894508                 -mov dword ptr [ebp + 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.eax;
L_0x00451575:
    // 00451575  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00451578  e813fe0700             -call 0x4d1390
    cpu.esp -= 4;
    sub_4d1390(app, cpu);
    if (cpu.terminate) return;
    // 0045157d  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0045157f  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00451581  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00451582  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_451590(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00451590  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00451591  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00451592  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00451593  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00451595  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00451597  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00451599  833d3492550000         +cmp dword ptr [0x559234], 0
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
    // 004515a0  7422                   -je 0x4515c4
    if (cpu.flags.zf)
    {
        goto L_0x004515c4;
    }
    // 004515a2  e859feffff             -call 0x451400
    cpu.esp -= 4;
    sub_451400(app, cpu);
    if (cpu.terminate) return;
    // 004515a7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004515a9  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004515ab  e890feffff             -call 0x451440
    cpu.esp -= 4;
    sub_451440(app, cpu);
    if (cpu.terminate) return;
    // 004515b0  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004515b2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004515b4  e847fa0700             -call 0x4d1000
    cpu.esp -= 4;
    sub_4d1000(app, cpu);
    if (cpu.terminate) return;
    // 004515b9  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004515bb  e880fd0700             -call 0x4d1340
    cpu.esp -= 4;
    sub_4d1340(app, cpu);
    if (cpu.terminate) return;
    // 004515c0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004515c1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004515c2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004515c3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004515c4:
    // 004515c4  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004515c6  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004515c8  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004515ca  e8d18e0800             -call 0x4da4a0
    cpu.esp -= 4;
    sub_4da4a0(app, cpu);
    if (cpu.terminate) return;
    // 004515cf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004515d0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004515d1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004515d2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4515e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004515e0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004515e1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004515e2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004515e3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004515e5  8b7d14                 -mov edi, dword ptr [ebp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004515e8  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004515ea  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004515ec  833d3492550000         +cmp dword ptr [0x559234], 0
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
    // 004515f3  742c                   -je 0x451621
    if (cpu.flags.zf)
    {
        goto L_0x00451621;
    }
    // 004515f5  e806feffff             -call 0x451400
    cpu.esp -= 4;
    sub_451400(app, cpu);
    if (cpu.terminate) return;
    // 004515fa  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004515fc  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004515fe  e83dfeffff             -call 0x451440
    cpu.esp -= 4;
    sub_451440(app, cpu);
    if (cpu.terminate) return;
    // 00451603  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00451604  8b5d10                 -mov ebx, dword ptr [ebp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00451607  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00451608  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0045160a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0045160c  e8dffb0700             -call 0x4d11f0
    cpu.esp -= 4;
    sub_4d11f0(app, cpu);
    if (cpu.terminate) return;
    // 00451611  f6052deb550020         +test byte ptr [0x55eb2d], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(5630765) /* 0x55eb2d */) & 32 /*0x20*/));
    // 00451618  7418                   -je 0x451632
    if (cpu.flags.zf)
    {
        goto L_0x00451632;
    }
    // 0045161a  e821fd0700             -call 0x4d1340
    cpu.esp -= 4;
    sub_4d1340(app, cpu);
    if (cpu.terminate) return;
    // 0045161f  eb11                   -jmp 0x451632
    goto L_0x00451632;
L_0x00451621:
    // 00451621  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00451622  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00451625  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00451626  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00451628  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00451629  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0045162b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0045162d  e88e920800             -call 0x4da8c0
    cpu.esp -= 4;
    sub_4da8c0(app, cpu);
    if (cpu.terminate) return;
L_0x00451632:
    // 00451632  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00451633  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00451634  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00451635  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_451640(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00451640  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00451641  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00451642  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00451643  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00451645  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00451647  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00451649  740a                   -je 0x451655
    if (cpu.flags.zf)
    {
        goto L_0x00451655;
    }
    // 0045164b  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0045164d  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0045164e  bb0b000000             -mov ebx, 0xb
    cpu.ebx = 11 /*0xb*/;
    // 00451653  eb08                   -jmp 0x45165d
    goto L_0x0045165d;
L_0x00451655:
    // 00451655  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00451657  42                     -inc edx
    (cpu.edx)++;
    // 00451658  bb0a000000             -mov ebx, 0xa
    cpu.ebx = 10 /*0xa*/;
L_0x0045165d:
    // 0045165d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045165f  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00451662  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00451664  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 00451666  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00451667  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00451668  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00451669  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_451670(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00451670  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00451671  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00451672  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00451673  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00451675  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00451677  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00451679  740c                   -je 0x451687
    if (cpu.flags.zf)
    {
        goto L_0x00451687;
    }
    // 0045167b  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0045167d  83c20a                 +add edx, 0xa
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10 /*0xa*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00451680  bb0b000000             -mov ebx, 0xb
    cpu.ebx = 11 /*0xb*/;
    // 00451685  eb0a                   -jmp 0x451691
    goto L_0x00451691;
L_0x00451687:
    // 00451687  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00451689  83c209                 -add edx, 9
    (cpu.edx) += x86::reg32(x86::sreg32(9 /*0x9*/));
    // 0045168c  bb0a000000             -mov ebx, 0xa
    cpu.ebx = 10 /*0xa*/;
L_0x00451691:
    // 00451691  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00451693  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00451696  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00451698  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 0045169a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045169b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045169c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045169d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4516a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004516a0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004516a1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004516a2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004516a3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004516a5  81ec0c010000           -sub esp, 0x10c
    (cpu.esp) -= x86::reg32(x86::sreg32(268 /*0x10c*/));
    // 004516ab  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004516ad  bafa000000             -mov edx, 0xfa
    cpu.edx = 250 /*0xfa*/;
    // 004516b2  8d85f4feffff           -lea eax, [ebp - 0x10c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-268) /* -0x10c */);
    // 004516b8  e873f00900             -call 0x4f0730
    cpu.esp -= 4;
    sub_4f0730(app, cpu);
    if (cpu.terminate) return;
    // 004516bd  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004516bf  8a85f4feffff           -mov al, byte ptr [ebp - 0x10c]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-268) /* -0x10c */);
    // 004516c5  8d55f0                 -lea edx, [ebp - 0x10]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004516c8  83e840                 -sub eax, 0x40
    (cpu.eax) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 004516cb  e800f10900             -call 0x4f07d0
    cpu.esp -= 4;
    sub_4f07d0(app, cpu);
    if (cpu.terminate) return;
    // 004516d0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004516d2  7404                   -je 0x4516d8
    if (cpu.flags.zf)
    {
        goto L_0x004516d8;
    }
    // 004516d4  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004516d6  eb1c                   -jmp 0x4516f4
    goto L_0x004516f4;
L_0x004516d8:
    // 004516d8  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004516db  0faf45fc               -imul eax, dword ptr [ebp - 4]
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 004516df  0faf45f8               -imul eax, dword ptr [ebp - 8]
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */))));
    // 004516e3  39c8                   +cmp eax, ecx
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
    // 004516e5  7d08                   -jge 0x4516ef
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004516ef;
    }
    // 004516e7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004516e9  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004516eb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004516ec  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004516ed  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004516ee  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004516ef:
    // 004516ef  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004516f4:
    // 004516f4  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004516f6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004516f7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004516f8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004516f9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_451700(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00451700  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00451701  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00451702  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00451703  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00451704  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00451706  81ec84000000           -sub esp, 0x84
    (cpu.esp) -= x86::reg32(x86::sreg32(132 /*0x84*/));
    // 0045170c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045170e  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00451710  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00451711  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00451712  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00451713  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00451714  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_451715(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00451715  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00451717:
    // 00451717  3b0d04d26f00           +cmp ecx, dword ptr [0x6fd204]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(7328260) /* 0x6fd204 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045171d  0f8d9c000000           -jge 0x4517bf
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004517bf;
    }
    // 00451723  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00451725  0f8594000000           -jne 0x4517bf
    if (!cpu.flags.zf)
    {
        goto L_0x004517bf;
    }
    // 0045172b  8d957cffffff           -lea edx, [ebp - 0x84]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-132) /* -0x84 */);
    // 00451731  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00451733  e8b841feff             -call 0x4358f0
    cpu.esp -= 4;
    sub_4358f0(app, cpu);
    if (cpu.terminate) return;
    // 00451738  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045173a  0f8479000000           -je 0x4517b9
    if (cpu.flags.zf)
    {
        goto L_0x004517b9;
    }
    // 00451740  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00451742  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00451745  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00451747  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0045174a  83b870c96f0000         +cmp dword ptr [eax + 0x6fc970], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(7326064) /* 0x6fc970 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00451751  0f8462000000           -je 0x4517b9
    if (cpu.flags.zf)
    {
        goto L_0x004517b9;
    }
    // 00451757  837dec00               +cmp dword ptr [ebp - 0x14], 0
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
    // 0045175b  7407                   -je 0x451764
    if (cpu.flags.zf)
    {
        goto L_0x00451764;
    }
    // 0045175d  bb0d000000             -mov ebx, 0xd
    cpu.ebx = 13 /*0xd*/;
    // 00451762  eb55                   -jmp 0x4517b9
    goto L_0x004517b9;
L_0x00451764:
    // 00451764  f680b0c96f0001         +test byte ptr [eax + 0x6fc9b0], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(7326128) /* 0x6fc9b0 */) & 1 /*0x1*/));
    // 0045176b  741f                   -je 0x45178c
    if (cpu.flags.zf)
    {
        goto L_0x0045178c;
    }
    // 0045176d  8b857cffffff           -mov eax, dword ptr [ebp - 0x84]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-132) /* -0x84 */);
    // 00451773  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 00451776  3dc0000000             +cmp eax, 0xc0
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(192 /*0xc0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045177b  7c05                   -jl 0x451782
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00451782;
    }
    // 0045177d  bb004d0000             -mov ebx, 0x4d00
    cpu.ebx = 19712 /*0x4d00*/;
L_0x00451782:
    // 00451782  83f840                 +cmp eax, 0x40
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
    // 00451785  7f05                   -jg 0x45178c
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0045178c;
    }
    // 00451787  bb004b0000             -mov ebx, 0x4b00
    cpu.ebx = 19200 /*0x4b00*/;
L_0x0045178c:
    // 0045178c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045178e  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00451791  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00451793  f604c5b0c96f0002       +test byte ptr [eax*8 + 0x6fc9b0], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(7326128) /* 0x6fc9b0 */ + cpu.eax * 8) & 2 /*0x2*/));
    // 0045179b  741c                   -je 0x4517b9
    if (cpu.flags.zf)
    {
        goto L_0x004517b9;
    }
    // 0045179d  8b4580                 -mov eax, dword ptr [ebp - 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-128) /* -0x80 */);
    // 004517a0  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 004517a3  3dc0000000             +cmp eax, 0xc0
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(192 /*0xc0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004517a8  7c05                   -jl 0x4517af
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004517af;
    }
    // 004517aa  bb00500000             -mov ebx, 0x5000
    cpu.ebx = 20480 /*0x5000*/;
L_0x004517af:
    // 004517af  83f840                 +cmp eax, 0x40
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
    // 004517b2  7f05                   -jg 0x4517b9
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004517b9;
    }
    // 004517b4  bb00480000             -mov ebx, 0x4800
    cpu.ebx = 18432 /*0x4800*/;
L_0x004517b9:
    // 004517b9  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004517ba  e958ffffff             -jmp 0x451717
    goto L_0x00451717;
L_0x004517bf:
    // 004517bf  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004517c1  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004517c3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004517c4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004517c5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004517c6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004517c7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4517d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004517d0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004517d1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004517d2  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004517d4  833d4cbb6f0000         +cmp dword ptr [0x6fbb4c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7322444) /* 0x6fbb4c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004517db  7407                   -je 0x4517e4
    if (cpu.flags.zf)
    {
        goto L_0x004517e4;
    }
    // 004517dd  b903000000             -mov ecx, 3
    cpu.ecx = 3 /*0x3*/;
    // 004517e2  eb05                   -jmp 0x4517e9
    goto L_0x004517e9;
L_0x004517e4:
    // 004517e4  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
L_0x004517e9:
    // 004517e9  890d54c16f00           -mov dword ptr [0x6fc154], ecx
    app->getMemory<x86::reg32>(x86::reg32(7323988) /* 0x6fc154 */) = cpu.ecx;
    // 004517ef  890df8c26f00           -mov dword ptr [0x6fc2f8], ecx
    app->getMemory<x86::reg32>(x86::reg32(7324408) /* 0x6fc2f8 */) = cpu.ecx;
    // 004517f5  890d0cbe6f00           -mov dword ptr [0x6fbe0c], ecx
    app->getMemory<x86::reg32>(x86::reg32(7323148) /* 0x6fbe0c */) = cpu.ecx;
    // 004517fb  890db0bf6f00           -mov dword ptr [0x6fbfb0], ecx
    app->getMemory<x86::reg32>(x86::reg32(7323568) /* 0x6fbfb0 */) = cpu.ecx;
    // 00451801  890d9cc46f00           -mov dword ptr [0x6fc49c], ecx
    app->getMemory<x86::reg32>(x86::reg32(7324828) /* 0x6fc49c */) = cpu.ecx;
    // 00451807  890d68bc6f00           -mov dword ptr [0x6fbc68], ecx
    app->getMemory<x86::reg32>(x86::reg32(7322728) /* 0x6fbc68 */) = cpu.ecx;
    // 0045180d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045180e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045180f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_451810(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00451810  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00451811  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00451813  b838000000             -mov eax, 0x38
    cpu.eax = 56 /*0x38*/;
    // 00451818  e8a3990900             -call 0x4eb1c0
    cpu.esp -= 4;
    sub_4eb1c0(app, cpu);
    if (cpu.terminate) return;
    // 0045181d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045181f  7413                   -je 0x451834
    if (cpu.flags.zf)
    {
        goto L_0x00451834;
    }
    // 00451821  b819000000             -mov eax, 0x19
    cpu.eax = 25 /*0x19*/;
    // 00451826  e895990900             -call 0x4eb1c0
    cpu.esp -= 4;
    sub_4eb1c0(app, cpu);
    if (cpu.terminate) return;
    // 0045182b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045182d  7405                   -je 0x451834
    if (cpu.flags.zf)
    {
        goto L_0x00451834;
    }
    // 0045182f  e8dc0b0000             -call 0x452410
    cpu.esp -= 4;
    sub_452410(app, cpu);
    if (cpu.terminate) return;
L_0x00451834:
    // 00451834  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00451835  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_451840(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00451840  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00451841  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00451842  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00451844  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00451846  3d00480000             +cmp eax, 0x4800
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(18432 /*0x4800*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045184b  7223                   -jb 0x451870
    if (cpu.flags.cf)
    {
        goto L_0x00451870;
    }
    // 0045184d  7646                   -jbe 0x451895
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00451895;
    }
    // 0045184f  3d004d0000             +cmp eax, 0x4d00
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(19712 /*0x4d00*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00451854  720e                   -jb 0x451864
    if (cpu.flags.cf)
    {
        goto L_0x00451864;
    }
    // 00451856  765b                   -jbe 0x4518b3
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004518b3;
    }
    // 00451858  3d00500000             +cmp eax, 0x5000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(20480 /*0x5000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045185d  7440                   -je 0x45189f
    if (cpu.flags.zf)
    {
        goto L_0x0045189f;
    }
    // 0045185f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00451861  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00451862  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00451863  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00451864:
    // 00451864  3d004b0000             +cmp eax, 0x4b00
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(19200 /*0x4b00*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00451869  743e                   -je 0x4518a9
    if (cpu.flags.zf)
    {
        goto L_0x004518a9;
    }
    // 0045186b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045186d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045186e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045186f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00451870:
    // 00451870  83f80d                 +cmp eax, 0xd
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(13 /*0xd*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00451873  7243                   -jb 0x4518b8
    if (cpu.flags.cf)
    {
        goto L_0x004518b8;
    }
    // 00451875  760a                   -jbe 0x451881
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00451881;
    }
    // 00451877  83f81b                 +cmp eax, 0x1b
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(27 /*0x1b*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045187a  740f                   -je 0x45188b
    if (cpu.flags.zf)
    {
        goto L_0x0045188b;
    }
    // 0045187c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045187e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045187f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00451880  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00451881:
    // 00451881  ba1c000000             -mov edx, 0x1c
    cpu.edx = 28 /*0x1c*/;
    // 00451886  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00451888  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00451889  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045188a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045188b:
    // 0045188b  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00451890  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00451892  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00451893  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00451894  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00451895:
    // 00451895  ba48000000             -mov edx, 0x48
    cpu.edx = 72 /*0x48*/;
    // 0045189a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045189c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045189d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045189e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045189f:
    // 0045189f  ba50000000             -mov edx, 0x50
    cpu.edx = 80 /*0x50*/;
    // 004518a4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004518a6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004518a7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004518a8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004518a9:
    // 004518a9  ba4b000000             -mov edx, 0x4b
    cpu.edx = 75 /*0x4b*/;
    // 004518ae  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004518b0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004518b1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004518b2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004518b3:
    // 004518b3  ba4d000000             -mov edx, 0x4d
    cpu.edx = 77 /*0x4d*/;
L_0x004518b8:
    // 004518b8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004518ba  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004518bb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004518bc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4518c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004518c0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004518c1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004518c2  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004518c4  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004518c6  83f848                 +cmp eax, 0x48
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(72 /*0x48*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004518c9  721d                   -jb 0x4518e8
    if (cpu.flags.cf)
    {
        goto L_0x004518e8;
    }
    // 004518cb  7640                   -jbe 0x45190d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0045190d;
    }
    // 004518cd  83f84d                 +cmp eax, 0x4d
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(77 /*0x4d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004518d0  720c                   -jb 0x4518de
    if (cpu.flags.cf)
    {
        goto L_0x004518de;
    }
    // 004518d2  7657                   -jbe 0x45192b
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0045192b;
    }
    // 004518d4  83f850                 +cmp eax, 0x50
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(80 /*0x50*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004518d7  743e                   -je 0x451917
    if (cpu.flags.zf)
    {
        goto L_0x00451917;
    }
    // 004518d9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004518db  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004518dc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004518dd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004518de:
    // 004518de  83f84b                 +cmp eax, 0x4b
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(75 /*0x4b*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004518e1  743e                   -je 0x451921
    if (cpu.flags.zf)
    {
        goto L_0x00451921;
    }
    // 004518e3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004518e5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004518e6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004518e7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004518e8:
    // 004518e8  83f801                 +cmp eax, 1
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
    // 004518eb  7243                   -jb 0x451930
    if (cpu.flags.cf)
    {
        goto L_0x00451930;
    }
    // 004518ed  7614                   -jbe 0x451903
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00451903;
    }
    // 004518ef  83f81c                 +cmp eax, 0x1c
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
    // 004518f2  7405                   -je 0x4518f9
    if (cpu.flags.zf)
    {
        goto L_0x004518f9;
    }
    // 004518f4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004518f6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004518f7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004518f8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004518f9:
    // 004518f9  ba0d000000             -mov edx, 0xd
    cpu.edx = 13 /*0xd*/;
    // 004518fe  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00451900  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00451901  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00451902  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00451903:
    // 00451903  ba1b000000             -mov edx, 0x1b
    cpu.edx = 27 /*0x1b*/;
    // 00451908  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045190a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045190b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045190c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045190d:
    // 0045190d  ba00480000             -mov edx, 0x4800
    cpu.edx = 18432 /*0x4800*/;
    // 00451912  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00451914  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00451915  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00451916  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00451917:
    // 00451917  ba00500000             -mov edx, 0x5000
    cpu.edx = 20480 /*0x5000*/;
    // 0045191c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045191e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045191f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00451920  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00451921:
    // 00451921  ba004b0000             -mov edx, 0x4b00
    cpu.edx = 19200 /*0x4b00*/;
    // 00451926  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00451928  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00451929  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045192a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045192b:
    // 0045192b  ba004d0000             -mov edx, 0x4d00
    cpu.edx = 19712 /*0x4d00*/;
L_0x00451930:
    // 00451930  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00451932  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00451933  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00451934  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_451940(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00451940  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00451941  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00451943  a348466600             -mov dword ptr [0x664648], eax
    app->getMemory<x86::reg32>(x86::reg32(6702664) /* 0x664648 */) = cpu.eax;
L_0x00451948:
    // 00451948  e823b00700             -call 0x4cc970
    cpu.esp -= 4;
    sub_4cc970(app, cpu);
    if (cpu.terminate) return;
    // 0045194d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045194f  75f7                   -jne 0x451948
    if (!cpu.flags.zf)
    {
        goto L_0x00451948;
    }
    // 00451951  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00451952  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_451960(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00451960  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00451961  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00451962  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00451963  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00451964  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00451965  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00451967  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00451969  e8a2feffff             -call 0x451810
    cpu.esp -= 4;
    sub_451810(app, cpu);
    if (cpu.terminate) return;
    // 0045196e  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00451973  e888a60400             -call 0x49c000
    cpu.esp -= 4;
    sub_49c000(app, cpu);
    if (cpu.terminate) return;
    // 00451978  891d58466600           -mov dword ptr [0x664658], ebx
    app->getMemory<x86::reg32>(x86::reg32(6702680) /* 0x664658 */) = cpu.ebx;
    // 0045197e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00451980  750a                   -jne 0x45198c
    if (!cpu.flags.zf)
    {
        goto L_0x0045198c;
    }
    // 00451982  a358466600             -mov dword ptr [0x664658], eax
    app->getMemory<x86::reg32>(x86::reg32(6702680) /* 0x664658 */) = cpu.eax;
    // 00451987  e8e4af0700             -call 0x4cc970
    cpu.esp -= 4;
    sub_4cc970(app, cpu);
    if (cpu.terminate) return;
L_0x0045198c:
    // 0045198c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045198e  7520                   -jne 0x4519b0
    if (!cpu.flags.zf)
    {
        goto L_0x004519b0;
    }
    // 00451990  8b15a4c17900           -mov edx, dword ptr [0x79c1a4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(7979428) /* 0x79c1a4 */);
    // 00451996  3b153c945500           +cmp edx, dword ptr [0x55943c]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5608508) /* 0x55943c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045199c  7e12                   -jle 0x4519b0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004519b0;
    }
    // 0045199e  a1a4c17900             -mov eax, dword ptr [0x79c1a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7979428) /* 0x79c1a4 */);
    // 004519a3  83c028                 -add eax, 0x28
    (cpu.eax) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 004519a6  a33c945500             -mov dword ptr [0x55943c], eax
    app->getMemory<x86::reg32>(x86::reg32(5608508) /* 0x55943c */) = cpu.eax;
    // 004519ab  e850fdffff             -call 0x451700
    cpu.esp -= 4;
    sub_451700(app, cpu);
    if (cpu.terminate) return;
L_0x004519b0:
    // 004519b0  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004519b2  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004519b4  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004519b7  81e3ffff0000           -and ebx, 0xffff
    cpu.ebx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004519bd  83fa1a                 +cmp edx, 0x1a
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(26 /*0x1a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004519c0  750b                   -jne 0x4519cd
    if (!cpu.flags.zf)
    {
        goto L_0x004519cd;
    }
    // 004519c2  83fb1b                 +cmp ebx, 0x1b
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(27 /*0x1b*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004519c5  7506                   -jne 0x4519cd
    if (!cpu.flags.zf)
    {
        goto L_0x004519cd;
    }
    // 004519c7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004519c9  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 004519cb  eb10                   -jmp 0x4519dd
    goto L_0x004519dd;
L_0x004519cd:
    // 004519cd  83fa0e                 +cmp edx, 0xe
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(14 /*0xe*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004519d0  750b                   -jne 0x4519dd
    if (!cpu.flags.zf)
    {
        goto L_0x004519dd;
    }
    // 004519d2  83fb7f                 +cmp ebx, 0x7f
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(127 /*0x7f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004519d5  7506                   -jne 0x4519dd
    if (!cpu.flags.zf)
    {
        goto L_0x004519dd;
    }
    // 004519d7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004519d9  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 004519db  eb11                   -jmp 0x4519ee
    goto L_0x004519ee;
L_0x004519dd:
    // 004519dd  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004519df  740d                   -je 0x4519ee
    if (cpu.flags.zf)
    {
        goto L_0x004519ee;
    }
    // 004519e1  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004519e3  7509                   -jne 0x4519ee
    if (!cpu.flags.zf)
    {
        goto L_0x004519ee;
    }
    // 004519e5  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004519e7  e854feffff             -call 0x451840
    cpu.esp -= 4;
    sub_451840(app, cpu);
    if (cpu.terminate) return;
    // 004519ec  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x004519ee:
    // 004519ee  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004519f0  740d                   -je 0x4519ff
    if (cpu.flags.zf)
    {
        goto L_0x004519ff;
    }
    // 004519f2  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004519f4  7509                   -jne 0x4519ff
    if (!cpu.flags.zf)
    {
        goto L_0x004519ff;
    }
    // 004519f6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004519f8  e8c3feffff             -call 0x4518c0
    cpu.esp -= 4;
    sub_4518c0(app, cpu);
    if (cpu.terminate) return;
    // 004519fd  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x004519ff:
    // 004519ff  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00451a01  7405                   -je 0x451a08
    if (cpu.flags.zf)
    {
        goto L_0x00451a08;
    }
    // 00451a03  e85880ffff             -call 0x449a60
    cpu.esp -= 4;
    sub_449a60(app, cpu);
    if (cpu.terminate) return;
L_0x00451a08:
    // 00451a08  891d54466600           -mov dword ptr [0x664654], ebx
    app->getMemory<x86::reg32>(x86::reg32(6702676) /* 0x664654 */) = cpu.ebx;
    // 00451a0e  89155c466600           -mov dword ptr [0x66465c], edx
    app->getMemory<x86::reg32>(x86::reg32(6702684) /* 0x66465c */) = cpu.edx;
    // 00451a14  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00451a16  7406                   -je 0x451a1e
    if (cpu.flags.zf)
    {
        goto L_0x00451a1e;
    }
    // 00451a18  891d4c466600           -mov dword ptr [0x66464c], ebx
    app->getMemory<x86::reg32>(x86::reg32(6702668) /* 0x66464c */) = cpu.ebx;
L_0x00451a1e:
    // 00451a1e  83fb0d                 +cmp ebx, 0xd
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
    // 00451a21  750f                   -jne 0x451a32
    if (!cpu.flags.zf)
    {
        goto L_0x00451a32;
    }
    // 00451a23  ba7f000000             -mov edx, 0x7f
    cpu.edx = 127 /*0x7f*/;
    // 00451a28  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00451a2d  e89e67fcff             -call 0x4181d0
    cpu.esp -= 4;
    sub_4181d0(app, cpu);
    if (cpu.terminate) return;
L_0x00451a32:
    // 00451a32  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00451a34  0f84b5000000           -je 0x451aef
    if (cpu.flags.zf)
    {
        goto L_0x00451aef;
    }
    // 00451a3a  a148466600             -mov eax, dword ptr [0x664648]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6702664) /* 0x664648 */);
    // 00451a3f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00451a41  0f84a8000000           -je 0x451aef
    if (cpu.flags.zf)
    {
        goto L_0x00451aef;
    }
    // 00451a47  83f80d                 +cmp eax, 0xd
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(13 /*0xd*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00451a4a  752a                   -jne 0x451a76
    if (!cpu.flags.zf)
    {
        goto L_0x00451a76;
    }
    // 00451a4c  39c3                   +cmp ebx, eax
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
    // 00451a4e  7416                   -je 0x451a66
    if (cpu.flags.zf)
    {
        goto L_0x00451a66;
    }
    // 00451a50  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00451a51  2eff1538475300         -call dword ptr cs:[0x534738]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457720) /* 0x534738 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00451a58  98                     -cwde 
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.ax));
    // 00451a59  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 00451a5c  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00451a61  6685c0                 +test ax, ax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & cpu.ax));
    // 00451a64  7410                   -je 0x451a76
    if (cpu.flags.zf)
    {
        goto L_0x00451a76;
    }
L_0x00451a66:
    // 00451a66  e805af0700             -call 0x4cc970
    cpu.esp -= 4;
    sub_4cc970(app, cpu);
    if (cpu.terminate) return;
    // 00451a6b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00451a6d  75f7                   -jne 0x451a66
    if (!cpu.flags.zf)
    {
        goto L_0x00451a66;
    }
    // 00451a6f  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00451a71  e99d000000             -jmp 0x451b13
    goto L_0x00451b13;
L_0x00451a76:
    // 00451a76  8b3548466600           -mov esi, dword ptr [0x664648]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(6702664) /* 0x664648 */);
    // 00451a7c  83fe1b                 +cmp esi, 0x1b
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(27 /*0x1b*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00451a7f  752d                   -jne 0x451aae
    if (!cpu.flags.zf)
    {
        goto L_0x00451aae;
    }
    // 00451a81  39f3                   +cmp ebx, esi
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
    // 00451a83  7416                   -je 0x451a9b
    if (cpu.flags.zf)
    {
        goto L_0x00451a9b;
    }
    // 00451a85  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00451a86  2eff1538475300         -call dword ptr cs:[0x534738]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457720) /* 0x534738 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00451a8d  98                     -cwde 
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.ax));
    // 00451a8e  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 00451a91  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00451a96  6685c0                 +test ax, ax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & cpu.ax));
    // 00451a99  7413                   -je 0x451aae
    if (cpu.flags.zf)
    {
        goto L_0x00451aae;
    }
L_0x00451a9b:
    // 00451a9b  e8d0ae0700             -call 0x4cc970
    cpu.esp -= 4;
    sub_4cc970(app, cpu);
    if (cpu.terminate) return;
    // 00451aa0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00451aa2  75f7                   -jne 0x451a9b
    if (!cpu.flags.zf)
    {
        goto L_0x00451a9b;
    }
    // 00451aa4  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00451aa6  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00451aa8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00451aa9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00451aaa  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00451aab  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00451aac  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00451aad  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00451aae:
    // 00451aae  3b1d48466600           +cmp ebx, dword ptr [0x664648]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6702664) /* 0x664648 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00451ab4  7539                   -jne 0x451aef
    if (!cpu.flags.zf)
    {
        goto L_0x00451aef;
    }
    // 00451ab6  a1a4c17900             -mov eax, dword ptr [0x79c1a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7979428) /* 0x79c1a4 */);
    // 00451abb  3b0544466600           +cmp eax, dword ptr [0x664644]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6702660) /* 0x664644 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00451ac1  7d0a                   -jge 0x451acd
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00451acd;
    }
L_0x00451ac3:
    // 00451ac3  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00451ac5  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00451ac7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00451ac8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00451ac9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00451aca  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00451acb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00451acc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00451acd:
    // 00451acd  a1a4c17900             -mov eax, dword ptr [0x79c1a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7979428) /* 0x79c1a4 */);
    // 00451ad2  3b0540945500           +cmp eax, dword ptr [0x559440]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5608512) /* 0x559440 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00451ad8  7ee9                   -jle 0x451ac3
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00451ac3;
    }
    // 00451ada  a1a4c17900             -mov eax, dword ptr [0x79c1a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7979428) /* 0x79c1a4 */);
    // 00451adf  83c00f                 -add eax, 0xf
    (cpu.eax) += x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00451ae2  a340945500             -mov dword ptr [0x559440], eax
    app->getMemory<x86::reg32>(x86::reg32(5608512) /* 0x559440 */) = cpu.eax;
    // 00451ae7  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00451ae9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00451aea  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00451aeb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00451aec  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00451aed  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00451aee  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00451aef:
    // 00451aef  891d48466600           -mov dword ptr [0x664648], ebx
    app->getMemory<x86::reg32>(x86::reg32(6702664) /* 0x664648 */) = cpu.ebx;
    // 00451af5  a1a4c17900             -mov eax, dword ptr [0x79c1a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7979428) /* 0x79c1a4 */);
    // 00451afa  83c02d                 -add eax, 0x2d
    (cpu.eax) += x86::reg32(x86::sreg32(45 /*0x2d*/));
    // 00451afd  a344466600             -mov dword ptr [0x664644], eax
    app->getMemory<x86::reg32>(x86::reg32(6702660) /* 0x664644 */) = cpu.eax;
    // 00451b02  83c00f                 -add eax, 0xf
    (cpu.eax) += x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00451b05  a340945500             -mov dword ptr [0x559440], eax
    app->getMemory<x86::reg32>(x86::reg32(5608512) /* 0x559440 */) = cpu.eax;
    // 00451b0a  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00451b0c  7405                   -je 0x451b13
    if (cpu.flags.zf)
    {
        goto L_0x00451b13;
    }
    // 00451b0e  e8cd460400             -call 0x4961e0
    cpu.esp -= 4;
    sub_4961e0(app, cpu);
    if (cpu.terminate) return;
L_0x00451b13:
    // 00451b13  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00451b15  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00451b16  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00451b17  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00451b18  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00451b19  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00451b1a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_451b20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00451b20  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00451b21  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00451b22  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00451b23  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00451b25  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00451b27  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 00451b2c  891544466600           -mov dword ptr [0x664644], edx
    app->getMemory<x86::reg32>(x86::reg32(6702660) /* 0x664644 */) = cpu.edx;
    // 00451b32  891d50466600           -mov dword ptr [0x664650], ebx
    app->getMemory<x86::reg32>(x86::reg32(6702672) /* 0x664650 */) = cpu.ebx;
    // 00451b38  891548466600           -mov dword ptr [0x664648], edx
    app->getMemory<x86::reg32>(x86::reg32(6702664) /* 0x664648 */) = cpu.edx;
    // 00451b3e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00451b3f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00451b40  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00451b41  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_451b50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00451b50  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00451b51  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00451b52  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00451b53  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00451b54  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00451b55  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00451b57  83ec3c                 -sub esp, 0x3c
    (cpu.esp) -= x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 00451b5a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00451b5c  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00451b5e  8a00                   -mov al, byte ptr [eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax);
    // 00451b60  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00451b62  3c09                   +cmp al, 9
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(9 /*0x9*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00451b64  720e                   -jb 0x451b74
    if (cpu.flags.cf)
    {
        goto L_0x00451b74;
    }
    // 00451b66  7629                   -jbe 0x451b91
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00451b91;
    }
    // 00451b68  3c0d                   +cmp al, 0xd
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(13 /*0xd*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00451b6a  7241                   -jb 0x451bad
    if (cpu.flags.cf)
    {
        goto L_0x00451bad;
    }
    // 00451b6c  7610                   -jbe 0x451b7e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00451b7e;
    }
    // 00451b6e  3c20                   +cmp al, 0x20
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
    // 00451b70  741f                   -je 0x451b91
    if (cpu.flags.zf)
    {
        goto L_0x00451b91;
    }
    // 00451b72  eb39                   -jmp 0x451bad
    goto L_0x00451bad;
L_0x00451b74:
    // 00451b74  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00451b76  0f8466000000           -je 0x451be2
    if (cpu.flags.zf)
    {
        goto L_0x00451be2;
    }
    // 00451b7c  eb2f                   -jmp 0x451bad
    goto L_0x00451bad;
L_0x00451b7e:
    // 00451b7e  8803                   -mov byte ptr [ebx], al
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.al;
    // 00451b80  8d4601                 -lea eax, [esi + 1]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00451b83  8d5301                 -lea edx, [ebx + 1]
    cpu.edx = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 00451b86  8a00                   -mov al, byte ptr [eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax);
    // 00451b88  8802                   -mov byte ptr [edx], al
    app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
    // 00451b8a  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00451b8f  eb51                   -jmp 0x451be2
    goto L_0x00451be2;
L_0x00451b91:
    // 00451b91  8d0416                 -lea eax, [esi + edx]
    cpu.eax = x86::reg32(cpu.esi + cpu.edx * 1);
    // 00451b94  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 00451b96  80f920                 +cmp cl, 0x20
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
    // 00451b99  7405                   -je 0x451ba0
    if (cpu.flags.zf)
    {
        goto L_0x00451ba0;
    }
    // 00451b9b  80f909                 +cmp cl, 9
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(9 /*0x9*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00451b9e  7542                   -jne 0x451be2
    if (!cpu.flags.zf)
    {
        goto L_0x00451be2;
    }
L_0x00451ba0:
    // 00451ba0  8d0416                 -lea eax, [esi + edx]
    cpu.eax = x86::reg32(cpu.esi + cpu.edx * 1);
    // 00451ba3  8d3c13                 -lea edi, [ebx + edx]
    cpu.edi = x86::reg32(cpu.ebx + cpu.edx * 1);
    // 00451ba6  8a00                   -mov al, byte ptr [eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax);
    // 00451ba8  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00451ba9  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00451bab  ebe4                   -jmp 0x451b91
    goto L_0x00451b91;
L_0x00451bad:
    // 00451bad  8d0416                 -lea eax, [esi + edx]
    cpu.eax = x86::reg32(cpu.esi + cpu.edx * 1);
    // 00451bb0  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 00451bb2  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 00451bb4  742c                   -je 0x451be2
    if (cpu.flags.zf)
    {
        goto L_0x00451be2;
    }
    // 00451bb6  80f920                 +cmp cl, 0x20
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
    // 00451bb9  7427                   -je 0x451be2
    if (cpu.flags.zf)
    {
        goto L_0x00451be2;
    }
    // 00451bbb  80f909                 +cmp cl, 9
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(9 /*0x9*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00451bbe  7508                   -jne 0x451bc8
    if (!cpu.flags.zf)
    {
        goto L_0x00451bc8;
    }
    // 00451bc0  8d0413                 -lea eax, [ebx + edx]
    cpu.eax = x86::reg32(cpu.ebx + cpu.edx * 1);
    // 00451bc3  c60000                 -mov byte ptr [eax], 0
    app->getMemory<x86::reg8>(cpu.eax) = 0 /*0x0*/;
    // 00451bc6  eb2c                   -jmp 0x451bf4
    goto L_0x00451bf4;
L_0x00451bc8:
    // 00451bc8  80f90d                 +cmp cl, 0xd
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(13 /*0xd*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00451bcb  7415                   -je 0x451be2
    if (cpu.flags.zf)
    {
        goto L_0x00451be2;
    }
    // 00451bcd  80f90a                 +cmp cl, 0xa
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(10 /*0xa*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00451bd0  7508                   -jne 0x451bda
    if (!cpu.flags.zf)
    {
        goto L_0x00451bda;
    }
    // 00451bd2  8d0413                 -lea eax, [ebx + edx]
    cpu.eax = x86::reg32(cpu.ebx + cpu.edx * 1);
    // 00451bd5  c60000                 -mov byte ptr [eax], 0
    app->getMemory<x86::reg8>(cpu.eax) = 0 /*0x0*/;
    // 00451bd8  eb1a                   -jmp 0x451bf4
    goto L_0x00451bf4;
L_0x00451bda:
    // 00451bda  8d3c13                 -lea edi, [ebx + edx]
    cpu.edi = x86::reg32(cpu.ebx + cpu.edx * 1);
    // 00451bdd  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00451bde  880f                   -mov byte ptr [edi], cl
    app->getMemory<x86::reg8>(cpu.edi) = cpu.cl;
    // 00451be0  ebcb                   -jmp 0x451bad
    goto L_0x00451bad;
L_0x00451be2:
    // 00451be2  8d0413                 -lea eax, [ebx + edx]
    cpu.eax = x86::reg32(cpu.ebx + cpu.edx * 1);
    // 00451be5  c60000                 -mov byte ptr [eax], 0
    app->getMemory<x86::reg8>(cpu.eax) = 0 /*0x0*/;
    // 00451be8  eb0a                   -jmp 0x451bf4
    goto L_0x00451bf4;
L_0x00451bea:
    // 00451bea  837df800               +cmp dword ptr [ebp - 8], 0
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
    // 00451bee  0f84ce000000           -je 0x451cc2
    if (cpu.flags.zf)
    {
        goto L_0x00451cc2;
    }
L_0x00451bf4:
    // 00451bf4  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00451bf6  8975fc                 -mov dword ptr [ebp - 4], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.esi;
    // 00451bf9  8975f8                 -mov dword ptr [ebp - 8], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.esi;
L_0x00451bfc:
    // 00451bfc  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00451bff  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00451c01  8a28                   -mov ch, byte ptr [eax]
    cpu.ch = app->getMemory<x86::reg8>(cpu.eax);
    // 00451c03  84ed                   +test ch, ch
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & cpu.ch));
    // 00451c05  7413                   -je 0x451c1a
    if (cpu.flags.zf)
    {
        goto L_0x00451c1a;
    }
    // 00451c07  80fd09                 +cmp ch, 9
    {
        x86::reg8 tmp1 = cpu.ch;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(9 /*0x9*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00451c0a  7509                   -jne 0x451c15
    if (!cpu.flags.zf)
    {
        goto L_0x00451c15;
    }
    // 00451c0c  c745f801000000         -mov dword ptr [ebp - 8], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = 1 /*0x1*/;
    // 00451c13  eb0b                   -jmp 0x451c20
    goto L_0x00451c20;
L_0x00451c15:
    // 00451c15  ff45fc                 +inc dword ptr [ebp - 4]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00451c18  ebe2                   -jmp 0x451bfc
    goto L_0x00451bfc;
L_0x00451c1a:
    // 00451c1a  837df800               +cmp dword ptr [ebp - 8], 0
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
    // 00451c1e  74ca                   -je 0x451bea
    if (cpu.flags.zf)
    {
        goto L_0x00451bea;
    }
L_0x00451c20:
    // 00451c20  8b7dfc                 -mov edi, dword ptr [ebp - 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00451c23  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00451c25  7417                   -je 0x451c3e
    if (cpu.flags.zf)
    {
        goto L_0x00451c3e;
    }
    // 00451c27  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00451c29  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00451c2b  8d7dc4                 -lea edi, [ebp - 0x3c]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-60) /* -0x3c */);
    // 00451c2e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00451c2f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00451c31  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00451c34  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00451c36  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00451c38  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00451c3b  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00451c3d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00451c3e:
    // 00451c3e  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00451c41  bee8955300             -mov esi, 0x5395e8
    cpu.esi = 5477864 /*0x5395e8*/;
    // 00451c46  30ed                   -xor ch, ch
    cpu.ch ^= x86::reg8(x86::sreg8(cpu.ch));
    // 00451c48  8d7dc4                 -lea edi, [ebp - 0x3c]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-60) /* -0x3c */);
    // 00451c4b  886c28c4               -mov byte ptr [eax + ebp - 0x3c], ch
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-60) /* -0x3c */ + cpu.ebp * 1) = cpu.ch;
    // 00451c4f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00451c50  2bc9                   +sub ecx, ecx
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
    // 00451c52  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00451c53  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 00451c55  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00451c57  4f                     -dec edi
    (cpu.edi)--;
L_0x00451c58:
    // 00451c58  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00451c5a  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00451c5c  3c00                   +cmp al, 0
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
    // 00451c5e  7410                   -je 0x451c70
    if (cpu.flags.zf)
    {
        goto L_0x00451c70;
    }
    // 00451c60  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00451c63  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00451c66  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00451c69  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00451c6c  3c00                   +cmp al, 0
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
    // 00451c6e  75e8                   -jne 0x451c58
    if (!cpu.flags.zf)
    {
        goto L_0x00451c58;
    }
L_0x00451c70:
    // 00451c70  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00451c71  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00451c74  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00451c76  8d7dc4                 -lea edi, [ebp - 0x3c]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-60) /* -0x3c */);
    // 00451c79  8d7001                 -lea esi, [eax + 1]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00451c7c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00451c7d  2bc9                   +sub ecx, ecx
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
    // 00451c7f  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00451c80  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 00451c82  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00451c84  4f                     -dec edi
    (cpu.edi)--;
L_0x00451c85:
    // 00451c85  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00451c87  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00451c89  3c00                   +cmp al, 0
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
    // 00451c8b  7410                   -je 0x451c9d
    if (cpu.flags.zf)
    {
        goto L_0x00451c9d;
    }
    // 00451c8d  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00451c90  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00451c93  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00451c96  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00451c99  3c00                   +cmp al, 0
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
    // 00451c9b  75e8                   -jne 0x451c85
    if (!cpu.flags.zf)
    {
        goto L_0x00451c85;
    }
L_0x00451c9d:
    // 00451c9d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00451c9e  8d75c4                 -lea esi, [ebp - 0x3c]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-60) /* -0x3c */);
    // 00451ca1  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00451ca3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00451ca4:
    // 00451ca4  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00451ca6  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00451ca8  3c00                   +cmp al, 0
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
    // 00451caa  7410                   -je 0x451cbc
    if (cpu.flags.zf)
    {
        goto L_0x00451cbc;
    }
    // 00451cac  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00451caf  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00451cb2  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00451cb5  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00451cb8  3c00                   +cmp al, 0
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
    // 00451cba  75e8                   -jne 0x451ca4
    if (!cpu.flags.zf)
    {
        goto L_0x00451ca4;
    }
L_0x00451cbc:
    // 00451cbc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00451cbd  e928ffffff             -jmp 0x451bea
    goto L_0x00451bea;
L_0x00451cc2:
    // 00451cc2  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00451cc4  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00451cc6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00451cc7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00451cc8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00451cc9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00451cca  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00451ccb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_451cd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00451cd0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00451cd1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00451cd2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00451cd3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00451cd5  81ec90040000           -sub esp, 0x490
    (cpu.esp) -= x86::reg32(x86::sreg32(1168 /*0x490*/));
    // 00451cdb  83ed62                 -sub ebp, 0x62
    (cpu.ebp) -= x86::reg32(x86::sreg32(98 /*0x62*/));
    // 00451cde  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00451ce0  895d42                 -mov dword ptr [ebp + 0x42], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(66) /* 0x42 */) = cpu.ebx;
    // 00451ce3  894d46                 -mov dword ptr [ebp + 0x46], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(70) /* 0x46 */) = cpu.ecx;
    // 00451ce6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00451ce8  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00451cea  8b4d7a                 -mov ecx, dword ptr [ebp + 0x7a]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(122) /* 0x7a */);
    // 00451ced  895536                 -mov dword ptr [ebp + 0x36], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(54) /* 0x36 */) = cpu.edx;
    // 00451cf0  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00451cf2  7406                   -je 0x451cfa
    if (cpu.flags.zf)
    {
        goto L_0x00451cfa;
    }
    // 00451cf4  c70105000000           -mov dword ptr [ecx], 5
    app->getMemory<x86::reg32>(cpu.ecx) = 5 /*0x5*/;
L_0x00451cfa:
    // 00451cfa  8b5d7e                 -mov ebx, dword ptr [ebp + 0x7e]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 00451cfd  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00451cff  7413                   -je 0x451d14
    if (cpu.flags.zf)
    {
        goto L_0x00451d14;
    }
    // 00451d01  d90550945500           -fld dword ptr [0x559450]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5608528) /* 0x559450 */)));
    // 00451d07  d80dec955300           -fmul dword ptr [0x5395ec]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5477868) /* 0x5395ec */));
    // 00451d0d  e844e00800             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 00451d12  db1b                   -fistp dword ptr [ebx]
    app->getMemory<x86::reg32>(cpu.ebx) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
L_0x00451d14:
    // 00451d14  e8e7030000             -call 0x452100
    cpu.esp -= 4;
    sub_452100(app, cpu);
    if (cpu.terminate) return;
    // 00451d19  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00451d1b  0f8492020000           -je 0x451fb3
    if (cpu.flags.zf)
    {
        goto L_0x00451fb3;
    }
    // 00451d21  8b3d34925500           -mov edi, dword ptr [0x559234]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
    // 00451d27  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00451d29  7420                   -je 0x451d4b
    if (cpu.flags.zf)
    {
        goto L_0x00451d4b;
    }
    // 00451d2b  837d7a00               +cmp dword ptr [ebp + 0x7a], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(122) /* 0x7a */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00451d2f  0f847e020000           -je 0x451fb3
    if (cpu.flags.zf)
    {
        goto L_0x00451fb3;
    }
    // 00451d35  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00451d37  e844f70700             -call 0x4d1480
    cpu.esp -= 4;
    sub_4d1480(app, cpu);
    if (cpu.terminate) return;
    // 00451d3c  8b457a                 -mov eax, dword ptr [ebp + 0x7a]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(122) /* 0x7a */);
    // 00451d3f  e812e00800             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 00451d44  db18                   +fistp dword ptr [eax]
    app->getMemory<x86::reg32>(cpu.eax) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00451d46  e968020000             -jmp 0x451fb3
    goto L_0x00451fb3;
L_0x00451d4b:
    // 00451d4b  8b9d8e000000           -mov ebx, dword ptr [ebp + 0x8e]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(142) /* 0x8e */);
    // 00451d51  897d5a                 -mov dword ptr [ebp + 0x5a], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(90) /* 0x5a */) = cpu.edi;
    // 00451d54  897d56                 -mov dword ptr [ebp + 0x56], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(86) /* 0x56 */) = cpu.edi;
    // 00451d57  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 00451d59  897552                 -mov dword ptr [ebp + 0x52], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(82) /* 0x52 */) = cpu.esi;
    // 00451d5c  88a5d2fbffff           -mov byte ptr [ebp - 0x42e], ah
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-1070) /* -0x42e */) = cpu.ah;
    // 00451d62  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00451d64  7f14                   -jg 0x451d7a
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00451d7a;
    }
    // 00451d66  8bb58a000000           -mov esi, dword ptr [ebp + 0x8a]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(138) /* 0x8a */);
    // 00451d6c  8d0433                 -lea eax, [ebx + esi]
    cpu.eax = x86::reg32(cpu.ebx + cpu.esi * 1);
    // 00451d6f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00451d71  7e07                   -jle 0x451d7a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00451d7a;
    }
    // 00451d73  c7455601000000         -mov dword ptr [ebp + 0x56], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(86) /* 0x56 */) = 1 /*0x1*/;
L_0x00451d7a:
    // 00451d7a  8b4552                 -mov eax, dword ptr [ebp + 0x52]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(82) /* 0x52 */);
    // 00451d7d  803800                 +cmp byte ptr [eax], 0
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
    // 00451d80  0f84a6010000           -je 0x451f2c
    if (cpu.flags.zf)
    {
        goto L_0x00451f2c;
    }
    // 00451d86  8d55d2                 -lea edx, [ebp - 0x2e]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-46) /* -0x2e */);
    // 00451d89  e8c2fdffff             -call 0x451b50
    cpu.esp -= 4;
    sub_451b50(app, cpu);
    if (cpu.terminate) return;
    // 00451d8e  89453a                 -mov dword ptr [ebp + 0x3a], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(58) /* 0x3a */) = cpu.eax;
    // 00451d91  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00451d93  8a75d2                 -mov dh, byte ptr [ebp - 0x2e]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-46) /* -0x2e */);
    // 00451d96  89454a                 -mov dword ptr [ebp + 0x4a], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(74) /* 0x4a */) = cpu.eax;
    // 00451d99  80fe0d                 +cmp dh, 0xd
    {
        x86::reg8 tmp1 = cpu.dh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(13 /*0xd*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00451d9c  750d                   -jne 0x451dab
    if (!cpu.flags.zf)
    {
        goto L_0x00451dab;
    }
    // 00451d9e  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00451da3  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 00451da5  89554a                 -mov dword ptr [ebp + 0x4a], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(74) /* 0x4a */) = cpu.edx;
    // 00451da8  885dd2                 -mov byte ptr [ebp - 0x2e], bl
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-46) /* -0x2e */) = cpu.bl;
L_0x00451dab:
    // 00451dab  8dbdd2fbffff           -lea edi, [ebp - 0x42e]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-1070) /* -0x42e */);
    // 00451db1  8d75d2                 -lea esi, [ebp - 0x2e]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-46) /* -0x2e */);
    // 00451db4  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00451db6  49                     -dec ecx
    (cpu.ecx)--;
    // 00451db7  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00451db9  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00451dbb  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00451dbd  49                     -dec ecx
    (cpu.ecx)--;
    // 00451dbe  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00451dc0  8d85d2fbffff           -lea eax, [ebp - 0x42e]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-1070) /* -0x42e */);
    // 00451dc6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00451dc8  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00451dca  8dbdd2fbffff           -lea edi, [ebp - 0x42e]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-1070) /* -0x42e */);
    // 00451dd0  89453e                 -mov dword ptr [ebp + 0x3e], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(62) /* 0x3e */) = cpu.eax;
    // 00451dd3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00451dd4  2bc9                   +sub ecx, ecx
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
    // 00451dd6  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00451dd7  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 00451dd9  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00451ddb  4f                     -dec edi
    (cpu.edi)--;
L_0x00451ddc:
    // 00451ddc  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00451dde  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00451de0  3c00                   +cmp al, 0
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
    // 00451de2  7410                   -je 0x451df4
    if (cpu.flags.zf)
    {
        goto L_0x00451df4;
    }
    // 00451de4  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00451de7  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00451dea  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00451ded  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00451df0  3c00                   +cmp al, 0
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
    // 00451df2  75e8                   -jne 0x451ddc
    if (!cpu.flags.zf)
    {
        goto L_0x00451ddc;
    }
L_0x00451df4:
    // 00451df4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00451df5  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00451dfa  8d85d2fbffff           -lea eax, [ebp - 0x42e]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-1070) /* -0x42e */);
    // 00451e00  e89b860800             -call 0x4da4a0
    cpu.esp -= 4;
    sub_4da4a0(app, cpu);
    if (cpu.terminate) return;
    // 00451e05  89455e                 -mov dword ptr [ebp + 0x5e], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(94) /* 0x5e */) = cpu.eax;
    // 00451e08  db455e                 -fild dword ptr [ebp + 0x5e]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(94) /* 0x5e */))));
    // 00451e0b  d80d50945500           -fmul dword ptr [0x559450]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5608528) /* 0x559450 */));
    // 00451e11  8b4d76                 -mov ecx, dword ptr [ebp + 0x76]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(118) /* 0x76 */);
    // 00451e14  e83ddf0800             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 00451e19  db5d4e                 -fistp dword ptr [ebp + 0x4e]
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(78) /* 0x4e */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00451e1c  3b4d4e                 +cmp ecx, dword ptr [ebp + 0x4e]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(78) /* 0x4e */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00451e1f  7c0a                   -jl 0x451e2b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00451e2b;
    }
    // 00451e21  837d4a00               +cmp dword ptr [ebp + 0x4a], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(74) /* 0x4a */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00451e25  0f84f6000000           -je 0x451f21
    if (cpu.flags.zf)
    {
        goto L_0x00451f21;
    }
L_0x00451e2b:
    // 00451e2b  8b454e                 -mov eax, dword ptr [ebp + 0x4e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(78) /* 0x4e */);
    // 00451e2e  3b4576                 +cmp eax, dword ptr [ebp + 0x76]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(118) /* 0x76 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00451e31  7e24                   -jle 0x451e57
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00451e57;
    }
    // 00451e33  8b453e                 -mov eax, dword ptr [ebp + 0x3e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(62) /* 0x3e */);
    // 00451e36  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00451e3b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00451e3d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00451e3f  c60000                 -mov byte ptr [eax], 0
    app->getMemory<x86::reg8>(cpu.eax) = 0 /*0x0*/;
    // 00451e42  8d85d2fbffff           -lea eax, [ebp - 0x42e]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-1070) /* -0x42e */);
    // 00451e48  8b7d36                 -mov edi, dword ptr [ebp + 0x36]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(54) /* 0x36 */);
    // 00451e4b  e850860800             -call 0x4da4a0
    cpu.esp -= 4;
    sub_4da4a0(app, cpu);
    if (cpu.terminate) return;
    // 00451e50  39f8                   +cmp eax, edi
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
    // 00451e52  7e03                   -jle 0x451e57
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00451e57;
    }
    // 00451e54  894536                 -mov dword ptr [ebp + 0x36], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(54) /* 0x36 */) = cpu.eax;
L_0x00451e57:
    // 00451e57  83bd8600000000         +cmp dword ptr [ebp + 0x86], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(134) /* 0x86 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00451e5e  7529                   -jne 0x451e89
    if (!cpu.flags.zf)
    {
        goto L_0x00451e89;
    }
    // 00451e60  837d5600               +cmp dword ptr [ebp + 0x56], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(86) /* 0x56 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00451e64  7423                   -je 0x451e89
    if (cpu.flags.zf)
    {
        goto L_0x00451e89;
    }
    // 00451e66  8b4542                 -mov eax, dword ptr [ebp + 0x42]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(66) /* 0x42 */);
    // 00451e69  0305a43a5600           -add eax, dword ptr [0x563aa4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5651108) /* 0x563aa4 */)));
    // 00451e6f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00451e70  8b5d72                 -mov ebx, dword ptr [ebp + 0x72]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(114) /* 0x72 */);
    // 00451e73  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00451e75  8b5546                 -mov edx, dword ptr [ebp + 0x46]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(70) /* 0x46 */);
    // 00451e78  8d85d2fbffff           -lea eax, [ebp - 0x42e]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-1070) /* -0x42e */);
    // 00451e7e  ff3550945500           -push dword ptr [0x559450]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(5608528) /* 0x559450 */);
    cpu.esp -= 4;
    // 00451e84  e897820800             -call 0x4da120
    cpu.esp -= 4;
    sub_4da120(app, cpu);
    if (cpu.terminate) return;
L_0x00451e89:
    // 00451e89  8b5d5a                 -mov ebx, dword ptr [ebp + 0x5a]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(90) /* 0x5a */);
    // 00451e8c  43                     -inc ebx
    (cpu.ebx)++;
    // 00451e8d  8b7556                 -mov esi, dword ptr [ebp + 0x56]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(86) /* 0x56 */);
    // 00451e90  895d5a                 -mov dword ptr [ebp + 0x5a], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(90) /* 0x5a */) = cpu.ebx;
    // 00451e93  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00451e95  741f                   -je 0x451eb6
    if (cpu.flags.zf)
    {
        goto L_0x00451eb6;
    }
    // 00451e97  d90550945500           -fld dword ptr [0x559450]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5608528) /* 0x559450 */)));
    // 00451e9d  8b4572                 -mov eax, dword ptr [ebp + 0x72]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(114) /* 0x72 */);
    // 00451ea0  d80dec955300           -fmul dword ptr [0x5395ec]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5477868) /* 0x5395ec */));
    // 00451ea6  89455e                 -mov dword ptr [ebp + 0x5e], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(94) /* 0x5e */) = cpu.eax;
    // 00451ea9  db455e                 -fild dword ptr [ebp + 0x5e]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(94) /* 0x5e */))));
    // 00451eac  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00451eae  e8a3de0800             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 00451eb3  db5d72                 -fistp dword ptr [ebp + 0x72]
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(114) /* 0x72 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
L_0x00451eb6:
    // 00451eb6  8b455a                 -mov eax, dword ptr [ebp + 0x5a]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(90) /* 0x5a */);
    // 00451eb9  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00451ebb  8b958e000000           -mov edx, dword ptr [ebp + 0x8e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(142) /* 0x8e */);
    // 00451ec1  897d56                 -mov dword ptr [ebp + 0x56], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(86) /* 0x56 */) = cpu.edi;
    // 00451ec4  39d0                   +cmp eax, edx
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
    // 00451ec6  7c17                   -jl 0x451edf
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00451edf;
    }
    // 00451ec8  8b8d8a000000           -mov ecx, dword ptr [ebp + 0x8a]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(138) /* 0x8a */);
    // 00451ece  8b5d5a                 -mov ebx, dword ptr [ebp + 0x5a]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(90) /* 0x5a */);
    // 00451ed1  8d040a                 -lea eax, [edx + ecx]
    cpu.eax = x86::reg32(cpu.edx + cpu.ecx * 1);
    // 00451ed4  39d8                   +cmp eax, ebx
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
    // 00451ed6  7e07                   -jle 0x451edf
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00451edf;
    }
    // 00451ed8  c7455601000000         -mov dword ptr [ebp + 0x56], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(86) /* 0x56 */) = 1 /*0x1*/;
L_0x00451edf:
    // 00451edf  8b454e                 -mov eax, dword ptr [ebp + 0x4e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(78) /* 0x4e */);
    // 00451ee2  30ff                   -xor bh, bh
    cpu.bh ^= x86::reg8(x86::sreg8(cpu.bh));
    // 00451ee4  8b7d76                 -mov edi, dword ptr [ebp + 0x76]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(118) /* 0x76 */);
    // 00451ee7  88bdd2fbffff           -mov byte ptr [ebp - 0x42e], bh
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-1070) /* -0x42e */) = cpu.bh;
    // 00451eed  39f8                   +cmp eax, edi
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
    // 00451eef  7e30                   -jle 0x451f21
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00451f21;
    }
    // 00451ef1  8a4dd2                 -mov cl, byte ptr [ebp - 0x2e]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-46) /* -0x2e */);
    // 00451ef4  80f920                 +cmp cl, 0x20
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
    // 00451ef7  7428                   -je 0x451f21
    if (cpu.flags.zf)
    {
        goto L_0x00451f21;
    }
    // 00451ef9  80f909                 +cmp cl, 9
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(9 /*0x9*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00451efc  7423                   -je 0x451f21
    if (cpu.flags.zf)
    {
        goto L_0x00451f21;
    }
    // 00451efe  8d75d2                 -lea esi, [ebp - 0x2e]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-46) /* -0x2e */);
    // 00451f01  8dbdd2fbffff           -lea edi, [ebp - 0x42e]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-1070) /* -0x42e */);
    // 00451f07  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00451f08:
    // 00451f08  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00451f0a  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00451f0c  3c00                   +cmp al, 0
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
    // 00451f0e  7410                   -je 0x451f20
    if (cpu.flags.zf)
    {
        goto L_0x00451f20;
    }
    // 00451f10  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00451f13  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00451f16  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00451f19  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00451f1c  3c00                   +cmp al, 0
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
    // 00451f1e  75e8                   -jne 0x451f08
    if (!cpu.flags.zf)
    {
        goto L_0x00451f08;
    }
L_0x00451f20:
    // 00451f20  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00451f21:
    // 00451f21  8b453a                 -mov eax, dword ptr [ebp + 0x3a]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(58) /* 0x3a */);
    // 00451f24  014552                 +add dword ptr [ebp + 0x52], eax
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(82) /* 0x52 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00451f27  e94efeffff             -jmp 0x451d7a
    goto L_0x00451d7a;
L_0x00451f2c:
    // 00451f2c  8b4d7e                 -mov ecx, dword ptr [ebp + 0x7e]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 00451f2f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00451f31  7420                   -je 0x451f53
    if (cpu.flags.zf)
    {
        goto L_0x00451f53;
    }
    // 00451f33  8b455a                 -mov eax, dword ptr [ebp + 0x5a]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(90) /* 0x5a */);
    // 00451f36  40                     -inc eax
    (cpu.eax)++;
    // 00451f37  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 00451f39  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00451f3b  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00451f3e  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00451f40  89455e                 -mov dword ptr [ebp + 0x5e], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(94) /* 0x5e */) = cpu.eax;
    // 00451f43  db455e                 -fild dword ptr [ebp + 0x5e]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(94) /* 0x5e */))));
    // 00451f46  d80d50945500           -fmul dword ptr [0x559450]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5608528) /* 0x559450 */));
    // 00451f4c  e805de0800             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 00451f51  db19                   -fistp dword ptr [ecx]
    app->getMemory<x86::reg32>(cpu.ecx) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
L_0x00451f53:
    // 00451f53  8b5d7a                 -mov ebx, dword ptr [ebp + 0x7a]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(122) /* 0x7a */);
    // 00451f56  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00451f58  7405                   -je 0x451f5f
    if (cpu.flags.zf)
    {
        goto L_0x00451f5f;
    }
    // 00451f5a  8b4536                 -mov eax, dword ptr [ebp + 0x36]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(54) /* 0x36 */);
    // 00451f5d  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
L_0x00451f5f:
    // 00451f5f  8bb586000000           -mov esi, dword ptr [ebp + 0x86]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(134) /* 0x86 */);
    // 00451f65  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00451f67  7528                   -jne 0x451f91
    if (!cpu.flags.zf)
    {
        goto L_0x00451f91;
    }
    // 00451f69  837d5600               +cmp dword ptr [ebp + 0x56], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(86) /* 0x56 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00451f6d  7422                   -je 0x451f91
    if (cpu.flags.zf)
    {
        goto L_0x00451f91;
    }
    // 00451f6f  8b4542                 -mov eax, dword ptr [ebp + 0x42]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(66) /* 0x42 */);
    // 00451f72  0305a43a5600           -add eax, dword ptr [0x563aa4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5651108) /* 0x563aa4 */)));
    // 00451f78  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00451f79  8b5d72                 -mov ebx, dword ptr [ebp + 0x72]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(114) /* 0x72 */);
    // 00451f7c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00451f7d  8b5546                 -mov edx, dword ptr [ebp + 0x46]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(70) /* 0x46 */);
    // 00451f80  8d85d2fbffff           -lea eax, [ebp - 0x42e]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-1070) /* -0x42e */);
    // 00451f86  ff3550945500           -push dword ptr [0x559450]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(5608528) /* 0x559450 */);
    cpu.esp -= 4;
    // 00451f8c  e88f810800             -call 0x4da120
    cpu.esp -= 4;
    sub_4da120(app, cpu);
    if (cpu.terminate) return;
L_0x00451f91:
    // 00451f91  837d5a00               +cmp dword ptr [ebp + 0x5a], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(90) /* 0x5a */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00451f95  750c                   -jne 0x451fa3
    if (!cpu.flags.zf)
    {
        goto L_0x00451fa3;
    }
    // 00451f97  8b5d7a                 -mov ebx, dword ptr [ebp + 0x7a]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(122) /* 0x7a */);
    // 00451f9a  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00451f9c  7405                   -je 0x451fa3
    if (cpu.flags.zf)
    {
        goto L_0x00451fa3;
    }
    // 00451f9e  8b454e                 -mov eax, dword ptr [ebp + 0x4e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(78) /* 0x4e */);
    // 00451fa1  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
L_0x00451fa3:
    // 00451fa3  8bb582000000           -mov esi, dword ptr [ebp + 0x82]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(130) /* 0x82 */);
    // 00451fa9  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00451fab  7406                   -je 0x451fb3
    if (cpu.flags.zf)
    {
        goto L_0x00451fb3;
    }
    // 00451fad  8b455a                 -mov eax, dword ptr [ebp + 0x5a]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(90) /* 0x5a */);
    // 00451fb0  40                     -inc eax
    (cpu.eax)++;
    // 00451fb1  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
L_0x00451fb3:
    // 00451fb3  8d6562                 -lea esp, [ebp + 0x62]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(98) /* 0x62 */);
    // 00451fb6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00451fb7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00451fb8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00451fb9  c22000                 -ret 0x20
    cpu.esp += 4+32 /*0x20*/;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_451fc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00451fc0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00451fc1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00451fc2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00451fc3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00451fc5  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00451fc7  6800040000             -push 0x400
    app->getMemory<x86::reg32>(cpu.esp-4) = 1024 /*0x400*/;
    cpu.esp -= 4;
    // 00451fcc  8b7524                 -mov esi, dword ptr [ebp + 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */);
    // 00451fcf  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00451fd0  8b7d20                 -mov edi, dword ptr [ebp + 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 00451fd3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00451fd4  8b751c                 -mov esi, dword ptr [ebp + 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 00451fd7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00451fd8  8b7d18                 -mov edi, dword ptr [ebp + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00451fdb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00451fdc  8b7514                 -mov esi, dword ptr [ebp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00451fdf  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00451fe0  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00451fe3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00451fe4  e8e7fcffff             -call 0x451cd0
    cpu.esp -= 4;
    sub_451cd0(app, cpu);
    if (cpu.terminate) return;
    // 00451fe9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00451fea  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00451feb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00451fec  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip 0x90 */
void Application::sub_451ff0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00451ff0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00451ff1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00451ff2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00451ff3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00451ff5  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00451ff7  6800040000             -push 0x400
    app->getMemory<x86::reg32>(cpu.esp-4) = 1024 /*0x400*/;
    cpu.esp -= 4;
    // 00451ffc  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00451ffe  8b7514                 -mov esi, dword ptr [ebp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00452001  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00452002  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00452005  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00452006  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00452007  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00452008  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0045200a  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0045200c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0045200e  e8bdfcffff             -call 0x451cd0
    cpu.esp -= 4;
    sub_451cd0(app, cpu);
    if (cpu.terminate) return;
    // 00452013  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00452014  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00452015  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00452016  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_452020(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00452020  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00452021  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00452022  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00452023  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00452024  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00452026  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00452029  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0045202b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045202d  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0045202f  7509                   -jne 0x45203a
    if (!cpu.flags.zf)
    {
        goto L_0x0045203a;
    }
    // 00452031  c745fc05000000         -mov dword ptr [ebp - 4], 5
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 5 /*0x5*/;
    // 00452038  eb48                   -jmp 0x452082
    goto L_0x00452082;
L_0x0045203a:
    // 0045203a  e8c1000000             -call 0x452100
    cpu.esp -= 4;
    sub_452100(app, cpu);
    if (cpu.terminate) return;
    // 0045203f  833d3492550000         +cmp dword ptr [0x559234], 0
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
    // 00452046  7427                   -je 0x45206f
    if (cpu.flags.zf)
    {
        goto L_0x0045206f;
    }
    // 00452048  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0045204a  e8e1f30700             -call 0x4d1430
    cpu.esp -= 4;
    sub_4d1430(app, cpu);
    if (cpu.terminate) return;
    // 0045204f  d80df0955300           -fmul dword ptr [0x5395f0]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5477872) /* 0x5395f0 */));
    // 00452055  db05c8da7c00           -fild dword ptr [0x7cdac8]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(8182472) /* 0x7cdac8 */))));
    // 0045205b  def9                   -fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0045205d  e8f4dc0800             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 00452062  db5dfc                 -fistp dword ptr [ebp - 4]
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00452065  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00452068  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0045206a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045206b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045206c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045206d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045206e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045206f:
    // 0045206f  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00452074  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00452076  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00452078  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0045207a  e821840800             -call 0x4da4a0
    cpu.esp -= 4;
    sub_4da4a0(app, cpu);
    if (cpu.terminate) return;
    // 0045207f  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
L_0x00452082:
    // 00452082  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00452085  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00452087  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00452088  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00452089  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045208a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045208b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_452090(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00452090  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00452091  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00452092  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00452093  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00452094  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00452096  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00452099  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0045209b  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 0045209e  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004520a0  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004520a2  49                     -dec ecx
    (cpu.ecx)--;
    // 004520a3  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004520a5  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004520a7  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004520a9  49                     -dec ecx
    (cpu.ecx)--;
    // 004520aa  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004520ac  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004520ae  e84d000000             -call 0x452100
    cpu.esp -= 4;
    sub_452100(app, cpu);
    if (cpu.terminate) return;
    // 004520b3  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004520b5  e866ffffff             -call 0x452020
    cpu.esp -= 4;
    sub_452020(app, cpu);
    if (cpu.terminate) return;
    // 004520ba  3b45fc                 +cmp eax, dword ptr [ebp - 4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004520bd  7e37                   -jle 0x4520f6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004520f6;
    }
L_0x004520bf:
    // 004520bf  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004520c1  7419                   -je 0x4520dc
    if (cpu.flags.zf)
    {
        goto L_0x004520dc;
    }
    // 004520c3  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004520c5  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004520c7  8b7dfc                 -mov edi, dword ptr [ebp - 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004520ca  e851ffffff             -call 0x452020
    cpu.esp -= 4;
    sub_452020(app, cpu);
    if (cpu.terminate) return;
    // 004520cf  39f8                   +cmp eax, edi
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
    // 004520d1  7e09                   -jle 0x4520dc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004520dc;
    }
    // 004520d3  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004520d4  8d040e                 -lea eax, [esi + ecx]
    cpu.eax = x86::reg32(cpu.esi + cpu.ecx * 1);
    // 004520d7  c60000                 -mov byte ptr [eax], 0
    app->getMemory<x86::reg8>(cpu.eax) = 0 /*0x0*/;
    // 004520da  ebe3                   -jmp 0x4520bf
    goto L_0x004520bf;
L_0x004520dc:
    // 004520dc  83f903                 +cmp ecx, 3
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
    // 004520df  7e15                   -jle 0x4520f6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004520f6;
    }
    // 004520e1  49                     -dec ecx
    (cpu.ecx)--;
    // 004520e2  8d040e                 -lea eax, [esi + ecx]
    cpu.eax = x86::reg32(cpu.esi + cpu.ecx * 1);
    // 004520e5  49                     -dec ecx
    (cpu.ecx)--;
    // 004520e6  c6002e                 -mov byte ptr [eax], 0x2e
    app->getMemory<x86::reg8>(cpu.eax) = 46 /*0x2e*/;
    // 004520e9  8d040e                 -lea eax, [esi + ecx]
    cpu.eax = x86::reg32(cpu.esi + cpu.ecx * 1);
    // 004520ec  49                     -dec ecx
    (cpu.ecx)--;
    // 004520ed  c6002e                 -mov byte ptr [eax], 0x2e
    app->getMemory<x86::reg8>(cpu.eax) = 46 /*0x2e*/;
    // 004520f0  8d040e                 -lea eax, [esi + ecx]
    cpu.eax = x86::reg32(cpu.esi + cpu.ecx * 1);
    // 004520f3  c6002e                 -mov byte ptr [eax], 0x2e
    app->getMemory<x86::reg8>(cpu.eax) = 46 /*0x2e*/;
L_0x004520f6:
    // 004520f6  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004520f8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004520f9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004520fa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004520fb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004520fc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_452100(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00452100  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00452101  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00452103  a350466600             -mov dword ptr [0x664650], eax
    app->getMemory<x86::reg32>(x86::reg32(6702672) /* 0x664650 */) = cpu.eax;
    // 00452108  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00452109  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_452110(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00452110  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00452111  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00452113  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00452114  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_452120(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00452120  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00452121  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00452122  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00452123  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00452125  81ec08010000           -sub esp, 0x108
    (cpu.esp) -= x86::reg32(x86::sreg32(264 /*0x108*/));
    // 0045212b  8955f8                 -mov dword ptr [ebp - 8], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edx;
    // 0045212e  895dfc                 -mov dword ptr [ebp - 4], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 00452131  8b5518                 -mov edx, dword ptr [ebp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00452134  8dbdf8feffff           -lea edi, [ebp - 0x108]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-264) /* -0x108 */);
    // 0045213a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0045213c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0045213d:
    // 0045213d  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0045213f  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00452141  3c00                   +cmp al, 0
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
    // 00452143  7410                   -je 0x452155
    if (cpu.flags.zf)
    {
        goto L_0x00452155;
    }
    // 00452145  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00452148  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0045214b  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0045214e  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00452151  3c00                   +cmp al, 0
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
    // 00452153  75e8                   -jne 0x45213d
    if (!cpu.flags.zf)
    {
        goto L_0x0045213d;
    }
L_0x00452155:
    // 00452155  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00452156  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00452158  8d85f8feffff           -lea eax, [ebp - 0x108]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-264) /* -0x108 */);
    // 0045215e  e82dffffff             -call 0x452090
    cpu.esp -= 4;
    sub_452090(app, cpu);
    if (cpu.terminate) return;
    // 00452163  8b5514                 -mov edx, dword ptr [ebp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00452166  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00452167  8b5d10                 -mov ebx, dword ptr [ebp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0045216a  8d85f8feffff           -lea eax, [ebp - 0x108]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-264) /* -0x108 */);
    // 00452170  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00452171  8b55f8                 -mov edx, dword ptr [ebp - 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00452174  8b5dfc                 -mov ebx, dword ptr [ebp - 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00452177  e814000000             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
    // 0045217c  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0045217e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045217f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00452180  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00452181  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_452190(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00452190  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00452191  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00452192  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00452193  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00452195  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00452198  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0045219b  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0045219d  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0045219f  8b5d10                 -mov ebx, dword ptr [ebp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004521a2  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004521a4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004521a6  0f8468000000           -je 0x452214
    if (cpu.flags.zf)
    {
        goto L_0x00452214;
    }
    // 004521ac  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004521ae  e84dffffff             -call 0x452100
    cpu.esp -= 4;
    sub_452100(app, cpu);
    if (cpu.terminate) return;
    // 004521b3  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004521b6  83fb01                 +cmp ebx, 1
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
    // 004521b9  7405                   -je 0x4521c0
    if (cpu.flags.zf)
    {
        goto L_0x004521c0;
    }
    // 004521bb  83fb04                 +cmp ebx, 4
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
    // 004521be  7509                   -jne 0x4521c9
    if (!cpu.flags.zf)
    {
        goto L_0x004521c9;
    }
L_0x004521c0:
    // 004521c0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004521c2  e859feffff             -call 0x452020
    cpu.esp -= 4;
    sub_452020(app, cpu);
    if (cpu.terminate) return;
    // 004521c7  eb1a                   -jmp 0x4521e3
    goto L_0x004521e3;
L_0x004521c9:
    // 004521c9  83fb02                 +cmp ebx, 2
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
    // 004521cc  7405                   -je 0x4521d3
    if (cpu.flags.zf)
    {
        goto L_0x004521d3;
    }
    // 004521ce  83fb05                 +cmp ebx, 5
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004521d1  7512                   -jne 0x4521e5
    if (!cpu.flags.zf)
    {
        goto L_0x004521e5;
    }
L_0x004521d3:
    // 004521d3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004521d5  e846feffff             -call 0x452020
    cpu.esp -= 4;
    sub_452020(app, cpu);
    if (cpu.terminate) return;
    // 004521da  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004521dc  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004521df  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004521e1  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
L_0x004521e3:
    // 004521e3  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
L_0x004521e5:
    // 004521e5  83fb02                 +cmp ebx, 2
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
    // 004521e8  7e17                   -jle 0x452201
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00452201;
    }
    // 004521ea  b808000000             -mov eax, 8
    cpu.eax = 8 /*0x8*/;
    // 004521ef  e8ccf1ffff             -call 0x4513c0
    cpu.esp -= 4;
    sub_4513c0(app, cpu);
    if (cpu.terminate) return;
    // 004521f4  8d5f01                 -lea ebx, [edi + 1]
    cpu.ebx = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 004521f7  8d5601                 -lea edx, [esi + 1]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004521fa  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004521fc  e88ff3ffff             -call 0x451590
    cpu.esp -= 4;
    sub_451590(app, cpu);
    if (cpu.terminate) return;
L_0x00452201:
    // 00452201  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00452204  e8b7f1ffff             -call 0x4513c0
    cpu.esp -= 4;
    sub_4513c0(app, cpu);
    if (cpu.terminate) return;
    // 00452209  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0045220b  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0045220d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045220f  e87cf3ffff             -call 0x451590
    cpu.esp -= 4;
    sub_451590(app, cpu);
    if (cpu.terminate) return;
L_0x00452214:
    // 00452214  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00452216  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00452217  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00452218  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00452219  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_452220(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00452220  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00452221  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00452222  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00452223  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00452225  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00452228  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0045222a  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0045222c  895dfc                 -mov dword ptr [ebp - 4], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 0045222f  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00452231  8b4d10                 -mov ecx, dword ptr [ebp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00452234  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00452236  e8c5feffff             -call 0x452100
    cpu.esp -= 4;
    sub_452100(app, cpu);
    if (cpu.terminate) return;
    // 0045223b  83f901                 +cmp ecx, 1
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
    // 0045223e  7405                   -je 0x452245
    if (cpu.flags.zf)
    {
        goto L_0x00452245;
    }
    // 00452240  83f904                 +cmp ecx, 4
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
    // 00452243  7509                   -jne 0x45224e
    if (!cpu.flags.zf)
    {
        goto L_0x0045224e;
    }
L_0x00452245:
    // 00452245  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00452247  e8d4fdffff             -call 0x452020
    cpu.esp -= 4;
    sub_452020(app, cpu);
    if (cpu.terminate) return;
    // 0045224c  eb1a                   -jmp 0x452268
    goto L_0x00452268;
L_0x0045224e:
    // 0045224e  83f902                 +cmp ecx, 2
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
    // 00452251  7405                   -je 0x452258
    if (cpu.flags.zf)
    {
        goto L_0x00452258;
    }
    // 00452253  83f905                 +cmp ecx, 5
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00452256  7512                   -jne 0x45226a
    if (!cpu.flags.zf)
    {
        goto L_0x0045226a;
    }
L_0x00452258:
    // 00452258  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0045225a  e8c1fdffff             -call 0x452020
    cpu.esp -= 4;
    sub_452020(app, cpu);
    if (cpu.terminate) return;
    // 0045225f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00452261  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00452264  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00452266  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
L_0x00452268:
    // 00452268  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
L_0x0045226a:
    // 0045226a  83f902                 +cmp ecx, 2
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
    // 0045226d  7e18                   -jle 0x452287
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00452287;
    }
    // 0045226f  b808000000             -mov eax, 8
    cpu.eax = 8 /*0x8*/;
    // 00452274  8b5dfc                 -mov ebx, dword ptr [ebp - 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00452277  e844f1ffff             -call 0x4513c0
    cpu.esp -= 4;
    sub_4513c0(app, cpu);
    if (cpu.terminate) return;
    // 0045227c  8d5701                 -lea edx, [edi + 1]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 0045227f  43                     -inc ebx
    (cpu.ebx)++;
    // 00452280  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00452282  e809f3ffff             -call 0x451590
    cpu.esp -= 4;
    sub_451590(app, cpu);
    if (cpu.terminate) return;
L_0x00452287:
    // 00452287  8b4520                 -mov eax, dword ptr [ebp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 0045228a  8b5524                 -mov edx, dword ptr [ebp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */);
    // 0045228d  e84ef1ffff             -call 0x4513e0
    cpu.esp -= 4;
    sub_4513e0(app, cpu);
    if (cpu.terminate) return;
    // 00452292  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00452295  8b4d1c                 -mov ecx, dword ptr [ebp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 00452298  e823f1ffff             -call 0x4513c0
    cpu.esp -= 4;
    sub_4513c0(app, cpu);
    if (cpu.terminate) return;
    // 0045229d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0045229e  8b5dfc                 -mov ebx, dword ptr [ebp - 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004522a1  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004522a3  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004522a4  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004522a6  8b4d18                 -mov ecx, dword ptr [ebp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 004522a9  e832f3ffff             -call 0x4515e0
    cpu.esp -= 4;
    sub_4515e0(app, cpu);
    if (cpu.terminate) return;
    // 004522ae  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004522b0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004522b1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004522b2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004522b3  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_4522c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004522c0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004522c1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004522c2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004522c3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004522c5  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004522c8  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
    // 004522cb  668955f4               -mov word ptr [ebp - 0xc], dx
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.dx;
    // 004522cf  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004522d1  66894df8               -mov word ptr [ebp - 8], cx
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.cx;
    // 004522d5  8b45f6                 -mov eax, dword ptr [ebp - 0xa]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-10) /* -0xa */);
    // 004522d8  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004522db  e820feffff             -call 0x452100
    cpu.esp -= 4;
    sub_452100(app, cpu);
    if (cpu.terminate) return;
    // 004522e0  e85be50900             -call 0x4f0840
    cpu.esp -= 4;
    sub_4f0840(app, cpu);
    if (cpu.terminate) return;
    // 004522e5  8945ec                 -mov dword ptr [ebp - 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
    // 004522e8  db45ec                 -fild dword ptr [ebp - 0x14]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */))));
    // 004522eb  dc0df8955300           -fmul qword ptr [0x5395f8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5477880) /* 0x5395f8 */));
    // 004522f1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004522f3  8b7de8                 -mov edi, dword ptr [ebp - 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004522f6  8955e4                 -mov dword ptr [ebp - 0x1c], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.edx;
    // 004522f9  8b5510                 -mov edx, dword ptr [ebp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004522fc  e855da0800             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 00452301  db5de4                 -fistp dword ptr [ebp - 0x1c]
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00452304  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00452306  49                     -dec ecx
    (cpu.ecx)--;
    // 00452307  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00452309  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0045230b  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0045230d  49                     -dec ecx
    (cpu.ecx)--;
    // 0045230e  66894dfc               -mov word ptr [ebp - 4], cx
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.cx;
    // 00452312  6683fa01               +cmp dx, 1
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(1 /*0x1*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00452316  7406                   -je 0x45231e
    if (cpu.flags.zf)
    {
        goto L_0x0045231e;
    }
    // 00452318  6683fa04               +cmp dx, 4
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(4 /*0x4*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0045231c  750b                   -jne 0x452329
    if (!cpu.flags.zf)
    {
        goto L_0x00452329;
    }
L_0x0045231e:
    // 0045231e  8b45e4                 -mov eax, dword ptr [ebp - 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00452321  0faf45fc               -imul eax, dword ptr [ebp - 4]
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 00452325  29c6                   +sub esi, eax
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
    // 00452327  eb28                   -jmp 0x452351
    goto L_0x00452351;
L_0x00452329:
    // 00452329  6683fa02               +cmp dx, 2
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(2 /*0x2*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0045232d  7406                   -je 0x452335
    if (cpu.flags.zf)
    {
        goto L_0x00452335;
    }
    // 0045232f  6683fa05               +cmp dx, 5
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(5 /*0x5*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00452333  751c                   -jne 0x452351
    if (!cpu.flags.zf)
    {
        goto L_0x00452351;
    }
L_0x00452335:
    // 00452335  8b55fa                 -mov edx, dword ptr [ebp - 6]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-6) /* -0x6 */);
    // 00452338  8b4de4                 -mov ecx, dword ptr [ebp - 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 0045233b  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0045233e  0fafd1                 -imul edx, ecx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 00452341  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00452343  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00452346  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00452348  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0045234a  0fbfd6                 -movsx edx, si
    cpu.edx = x86::reg32(static_cast<x86::sreg16>(cpu.si));
    // 0045234d  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0045234f  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
L_0x00452351:
    // 00452351  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00452353:
    // 00452353  8b45fa                 -mov eax, dword ptr [ebp - 6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-6) /* -0x6 */);
    // 00452356  0fbff9                 -movsx edi, cx
    cpu.edi = x86::reg32(static_cast<x86::sreg16>(cpu.cx));
    // 00452359  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0045235c  39c7                   +cmp edi, eax
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
    // 0045235e  0f8da1000000           -jge 0x452405
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00452405;
    }
    // 00452364  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00452369  8b55e8                 -mov edx, dword ptr [ebp - 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 0045236c  8d45f0                 -lea eax, [ebp - 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0045236f  e8bcea0800             -call 0x4e0e30
    cpu.esp -= 4;
    sub_4e0e30(app, cpu);
    if (cpu.terminate) return;
    // 00452374  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00452377  8a0407                 -mov al, byte ptr [edi + eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + cpu.eax * 1);
    // 0045237a  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0045237f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00452380  68f4955300             -push 0x5395f4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5477876 /*0x5395f4*/;
    cpu.esp -= 4;
    // 00452385  8d45f0                 -lea eax, [ebp - 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00452388  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00452389  8b55f6                 -mov edx, dword ptr [ebp - 0xa]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-10) /* -0xa */);
    // 0045238c  e8ffd20800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00452391  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00452394  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00452397  8d45f0                 -lea eax, [ebp - 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0045239a  e881fcffff             -call 0x452020
    cpu.esp -= 4;
    sub_452020(app, cpu);
    if (cpu.terminate) return;
    // 0045239f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004523a1  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004523a4  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004523a6  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004523a8  8b55f2                 -mov edx, dword ptr [ebp - 0xe]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-14) /* -0xe */);
    // 004523ab  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004523ae  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004523b0  8955e0                 -mov dword ptr [ebp - 0x20], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.edx;
    // 004523b3  66837d1002             +cmp word ptr [ebp + 0x10], 2
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(16) /* 0x10 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(2 /*0x2*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004523b8  7e24                   -jle 0x4523de
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004523de;
    }
    // 004523ba  8b55e4                 -mov edx, dword ptr [ebp - 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004523bd  0fafd7                 -imul edx, edi
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 004523c0  b808000000             -mov eax, 8
    cpu.eax = 8 /*0x8*/;
    // 004523c5  e8f6efffff             -call 0x4513c0
    cpu.esp -= 4;
    sub_4513c0(app, cpu);
    if (cpu.terminate) return;
    // 004523ca  0fbfc6                 -movsx eax, si
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.si));
    // 004523cd  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004523cf  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004523d2  8b55e0                 -mov edx, dword ptr [ebp - 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 004523d5  8d45f0                 -lea eax, [ebp - 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004523d8  42                     -inc edx
    (cpu.edx)++;
    // 004523d9  e8b2f1ffff             -call 0x451590
    cpu.esp -= 4;
    sub_451590(app, cpu);
    if (cpu.terminate) return;
L_0x004523de:
    // 004523de  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004523e1  8b5de4                 -mov ebx, dword ptr [ebp - 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004523e4  e8d7efffff             -call 0x4513c0
    cpu.esp -= 4;
    sub_4513c0(app, cpu);
    if (cpu.terminate) return;
    // 004523e9  0fbfc1                 -movsx eax, cx
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.cx));
    // 004523ec  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004523ef  0fbfde                 -movsx ebx, si
    cpu.ebx = x86::reg32(static_cast<x86::sreg16>(cpu.si));
    // 004523f2  8b55e0                 -mov edx, dword ptr [ebp - 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 004523f5  01c3                   +add ebx, eax
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
    // 004523f7  8d45f0                 -lea eax, [ebp - 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004523fa  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004523fb  e890f1ffff             -call 0x451590
    cpu.esp -= 4;
    sub_451590(app, cpu);
    if (cpu.terminate) return;
    // 00452400  e94effffff             -jmp 0x452353
    goto L_0x00452353;
L_0x00452405:
    // 00452405  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00452407  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00452408  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00452409  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045240a  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_452410(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00452410  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00452411  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00452413  e878200700             -call 0x4c4490
    cpu.esp -= 4;
    sub_4c4490(app, cpu);
    if (cpu.terminate) return;
    // 00452418  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00452419  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_452420(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00452420  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00452421  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00452422  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00452424  e8b7c90900             -call 0x4eede0
    cpu.esp -= 4;
    sub_4eede0(app, cpu);
    if (cpu.terminate) return;
    // 00452429  8d4809                 -lea ecx, [eax + 9]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(9) /* 0x9 */);
    // 0045242c  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0045242e  8a0403                 -mov al, byte ptr [ebx + eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.eax * 1);
    // 00452431  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00452436  39c1                   +cmp ecx, eax
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
    // 00452438  740b                   -je 0x452445
    if (cpu.flags.zf)
    {
        goto L_0x00452445;
    }
    // 0045243a  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 00452440  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00452442  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00452443  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00452444  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00452445:
    // 00452445  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 00452447  41                     -inc ecx
    (cpu.ecx)++;
    // 00452448  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0045244a  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 0045244c  803b00                 +cmp byte ptr [ebx], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0045244f  7508                   -jne 0x452459
    if (!cpu.flags.zf)
    {
        goto L_0x00452459;
    }
    // 00452451  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00452456  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00452457  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00452458  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00452459:
    // 00452459  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045245b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045245c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045245d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4524e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 004524e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004524e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004524e2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004524e3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004524e4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004524e5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004524e6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004524e8  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004524eb  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004524ed  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004524ef  0f840c040000           -je 0x452901
    if (cpu.flags.zf)
    {
        goto L_0x00452901;
    }
    // 004524f5  8b15b0d36f00           -mov edx, dword ptr [0x6fd3b0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */);
    // 004524fb  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004524fd  7409                   -je 0x452508
    if (cpu.flags.zf)
    {
        goto L_0x00452508;
    }
    // 004524ff  83fa01                 +cmp edx, 1
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
    // 00452502  0f85f9030000           -jne 0x452901
    if (!cpu.flags.zf)
    {
        goto L_0x00452901;
    }
L_0x00452508:
    // 00452508  8b35b8d36f00           -mov esi, dword ptr [0x6fd3b8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */);
    // 0045250e  83fe03                 +cmp esi, 3
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
    // 00452511  7408                   -je 0x45251b
    if (cpu.flags.zf)
    {
        goto L_0x0045251b;
    }
    // 00452513  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00452515  0f85e6030000           -jne 0x452901
    if (!cpu.flags.zf)
    {
        goto L_0x00452901;
    }
L_0x0045251b:
    // 0045251b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045251d  e8bec80900             -call 0x4eede0
    cpu.esp -= 4;
    sub_4eede0(app, cpu);
    if (cpu.terminate) return;
    // 00452522  8b3538955500           -mov esi, dword ptr [0x559538]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5608760) /* 0x559538 */);
    // 00452528  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0045252a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0045252c  83fe03                 +cmp esi, 3
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
    // 0045252f  0f87d0000000           -ja 0x452605
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00452605;
    }
    // 00452535  ff24b560244500         -jmp dword ptr [esi*4 + 0x452460]
    cpu.ip = app->getMemory<x86::reg32>(4531296 + cpu.esi * 4); goto dynamic_jump;
  case 0x0045253c:
    // 0045253c  83f947                 +cmp ecx, 0x47
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(71 /*0x47*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045253f  0f85c0000000           -jne 0x452605
    if (!cpu.flags.zf)
    {
        goto L_0x00452605;
    }
    // 00452545  ff0538955500           -inc dword ptr [0x559538]
    (app->getMemory<x86::reg32>(x86::reg32(5608760) /* 0x559538 */))++;
    // 0045254b  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 0045254d  8975fc                 -mov dword ptr [ebp - 4], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.esi;
    // 00452550  e9c1000000             -jmp 0x452616
    goto L_0x00452616;
  case 0x00452555:
    // 00452555  83f84f                 +cmp eax, 0x4f
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(79 /*0x4f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00452558  7511                   -jne 0x45256b
    if (!cpu.flags.zf)
    {
        goto L_0x0045256b;
    }
    // 0045255a  46                     -inc esi
    (cpu.esi)++;
    // 0045255b  893538955500           -mov dword ptr [0x559538], esi
    app->getMemory<x86::reg32>(x86::reg32(5608760) /* 0x559538 */) = cpu.esi;
    // 00452561  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 00452563  8975fc                 -mov dword ptr [ebp - 4], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.esi;
    // 00452566  e9ab000000             -jmp 0x452616
    goto L_0x00452616;
L_0x0045256b:
    // 0045256b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0045256d  891d38955500           -mov dword ptr [0x559538], ebx
    app->getMemory<x86::reg32>(x86::reg32(5608760) /* 0x559538 */) = cpu.ebx;
    // 00452573  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 00452575  8975fc                 -mov dword ptr [ebp - 4], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.esi;
    // 00452578  e999000000             -jmp 0x452616
    goto L_0x00452616;
  case 0x0045257d:
    // 0045257d  83f830                 +cmp eax, 0x30
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
    // 00452580  7c29                   -jl 0x4525ab
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004525ab;
    }
    // 00452582  83f839                 +cmp eax, 0x39
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
    // 00452585  7f24                   -jg 0x4525ab
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004525ab;
    }
    // 00452587  8d50d0                 -lea edx, [eax - 0x30]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(-48) /* -0x30 */);
    // 0045258a  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00452591  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00452593  46                     -inc esi
    (cpu.esi)++;
    // 00452594  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 00452596  893538955500           -mov dword ptr [0x559538], esi
    app->getMemory<x86::reg32>(x86::reg32(5608760) /* 0x559538 */) = cpu.esi;
    // 0045259c  a33c955500             -mov dword ptr [0x55953c], eax
    app->getMemory<x86::reg32>(x86::reg32(5608764) /* 0x55953c */) = cpu.eax;
    // 004525a1  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 004525a3  8975fc                 -mov dword ptr [ebp - 4], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.esi;
    // 004525a6  e96b000000             -jmp 0x452616
    goto L_0x00452616;
L_0x004525ab:
    // 004525ab  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004525ad  893538955500           -mov dword ptr [0x559538], esi
    app->getMemory<x86::reg32>(x86::reg32(5608760) /* 0x559538 */) = cpu.esi;
    // 004525b3  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 004525b5  8975fc                 -mov dword ptr [ebp - 4], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.esi;
    // 004525b8  eb5c                   -jmp 0x452616
    goto L_0x00452616;
  case 0x004525ba:
    // 004525ba  83f830                 +cmp eax, 0x30
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
    // 004525bd  7c3f                   -jl 0x4525fe
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004525fe;
    }
    // 004525bf  83f839                 +cmp eax, 0x39
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
    // 004525c2  7f3a                   -jg 0x4525fe
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004525fe;
    }
    // 004525c4  8b153c955500           -mov edx, dword ptr [0x55953c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5608764) /* 0x55953c */);
    // 004525ca  83e830                 -sub eax, 0x30
    (cpu.eax) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 004525cd  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004525cf  89153c955500           -mov dword ptr [0x55953c], edx
    app->getMemory<x86::reg32>(x86::reg32(5608764) /* 0x55953c */) = cpu.edx;
    // 004525d5  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004525d7  7c25                   -jl 0x4525fe
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004525fe;
    }
    // 004525d9  83fa15                 +cmp edx, 0x15
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(21 /*0x15*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004525dc  7f20                   -jg 0x4525fe
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004525fe;
    }
    // 004525de  ba7f000000             -mov edx, 0x7f
    cpu.edx = 127 /*0x7f*/;
    // 004525e3  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 004525e8  e8e35bfcff             -call 0x4181d0
    cpu.esp -= 4;
    sub_4181d0(app, cpu);
    if (cpu.terminate) return;
    // 004525ed  800dfcd46f0002         -or byte ptr [0x6fd4fc], 2
    app->getMemory<x86::reg8>(x86::reg32(7329020) /* 0x6fd4fc */) |= x86::reg8(x86::sreg8(2 /*0x2*/));
    // 004525f4  a13c955500             -mov eax, dword ptr [0x55953c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5608764) /* 0x55953c */);
    // 004525f9  a300d56f00             -mov dword ptr [0x6fd500], eax
    app->getMemory<x86::reg32>(x86::reg32(7329024) /* 0x6fd500 */) = cpu.eax;
L_0x004525fe:
    // 004525fe  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00452600  a338955500             -mov dword ptr [0x559538], eax
    app->getMemory<x86::reg32>(x86::reg32(5608760) /* 0x559538 */) = cpu.eax;
L_0x00452605:
    // 00452605  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 00452607  8975fc                 -mov dword ptr [ebp - 4], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.esi;
    // 0045260a  eb0a                   -jmp 0x452616
    goto L_0x00452616;
L_0x0045260c:
    // 0045260c  837dfc15               +cmp dword ptr [ebp - 4], 0x15
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(21 /*0x15*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00452610  0f8d5a020000           -jge 0x452870
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00452870;
    }
L_0x00452616:
    // 00452616  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00452619  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0045261c  baf0456600             -mov edx, 0x6645f0
    cpu.edx = 6702576 /*0x6645f0*/;
    // 00452621  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 00452624  8b98e4945500           -mov ebx, dword ptr [eax + 0x5594e4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5608676) /* 0x5594e4 */);
    // 0045262a  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0045262c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045262e  e8edfdffff             -call 0x452420
    cpu.esp -= 4;
    sub_452420(app, cpu);
    if (cpu.terminate) return;
    // 00452633  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00452635  0f842d020000           -je 0x452868
    if (cpu.flags.zf)
    {
        goto L_0x00452868;
    }
    // 0045263b  837dfc14               +cmp dword ptr [ebp - 4], 0x14
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(20 /*0x14*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045263f  0f8723020000           -ja 0x452868
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00452868;
    }
    // 00452645  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00452648  ffa070244500           -jmp dword ptr [eax + 0x452470]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + 4531312); goto dynamic_jump;
  case 0x0045264e:
    // 0045264e  f605a8d26f0001         +test byte ptr [0x6fd2a8], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(7328424) /* 0x6fd2a8 */) & 1 /*0x1*/));
    // 00452655  0f850d020000           -jne 0x452868
    if (!cpu.flags.zf)
    {
        goto L_0x00452868;
    }
    // 0045265b  ba7f000000             -mov edx, 0x7f
    cpu.edx = 127 /*0x7f*/;
    // 00452660  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 00452665  e8665bfcff             -call 0x4181d0
    cpu.esp -= 4;
    sub_4181d0(app, cpu);
    if (cpu.terminate) return;
    // 0045266a  8a35a8d26f00           -mov dh, byte ptr [0x6fd2a8]
    cpu.dh = app->getMemory<x86::reg8>(x86::reg32(7328424) /* 0x6fd2a8 */);
    // 00452670  80ce01                 +or dh, 1
    cpu.clear_co();
    cpu.set_szp((cpu.dh |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 00452673  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 00452678  8835a8d26f00           -mov byte ptr [0x6fd2a8], dh
    app->getMemory<x86::reg8>(x86::reg32(7328424) /* 0x6fd2a8 */) = cpu.dh;
    // 0045267e  ff45fc                 +inc dword ptr [ebp - 4]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00452681  eb89                   -jmp 0x45260c
    goto L_0x0045260c;
  case 0x00452683:
    // 00452683  f605a8d26f0002         +test byte ptr [0x6fd2a8], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(7328424) /* 0x6fd2a8 */) & 2 /*0x2*/));
    // 0045268a  0f85d8010000           -jne 0x452868
    if (!cpu.flags.zf)
    {
        goto L_0x00452868;
    }
    // 00452690  ba7f000000             -mov edx, 0x7f
    cpu.edx = 127 /*0x7f*/;
    // 00452695  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 0045269a  e8315bfcff             -call 0x4181d0
    cpu.esp -= 4;
    sub_4181d0(app, cpu);
    if (cpu.terminate) return;
    // 0045269f  8a3da8d26f00           -mov bh, byte ptr [0x6fd2a8]
    cpu.bh = app->getMemory<x86::reg8>(x86::reg32(7328424) /* 0x6fd2a8 */);
    // 004526a5  80cf02                 +or bh, 2
    cpu.clear_co();
    cpu.set_szp((cpu.bh |= x86::reg8(x86::sreg8(2 /*0x2*/))));
    // 004526a8  be02000000             -mov esi, 2
    cpu.esi = 2 /*0x2*/;
    // 004526ad  883da8d26f00           -mov byte ptr [0x6fd2a8], bh
    app->getMemory<x86::reg8>(x86::reg32(7328424) /* 0x6fd2a8 */) = cpu.bh;
    // 004526b3  ff45fc                 +inc dword ptr [ebp - 4]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004526b6  e951ffffff             -jmp 0x45260c
    goto L_0x0045260c;
  case 0x004526bb:
    // 004526bb  f605a8d26f0004         +test byte ptr [0x6fd2a8], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(7328424) /* 0x6fd2a8 */) & 4 /*0x4*/));
    // 004526c2  0f85a0010000           -jne 0x452868
    if (!cpu.flags.zf)
    {
        goto L_0x00452868;
    }
    // 004526c8  ba7f000000             -mov edx, 0x7f
    cpu.edx = 127 /*0x7f*/;
    // 004526cd  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 004526d2  e8f95afcff             -call 0x4181d0
    cpu.esp -= 4;
    sub_4181d0(app, cpu);
    if (cpu.terminate) return;
    // 004526d7  8a25a8d26f00           -mov ah, byte ptr [0x6fd2a8]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(7328424) /* 0x6fd2a8 */);
    // 004526dd  80cc04                 +or ah, 4
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(4 /*0x4*/))));
    // 004526e0  be03000000             -mov esi, 3
    cpu.esi = 3 /*0x3*/;
    // 004526e5  8825a8d26f00           -mov byte ptr [0x6fd2a8], ah
    app->getMemory<x86::reg8>(x86::reg32(7328424) /* 0x6fd2a8 */) = cpu.ah;
    // 004526eb  ff45fc                 +inc dword ptr [ebp - 4]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004526ee  e919ffffff             -jmp 0x45260c
    goto L_0x0045260c;
  case 0x004526f3:
    // 004526f3  f605a8d26f0008         +test byte ptr [0x6fd2a8], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(7328424) /* 0x6fd2a8 */) & 8 /*0x8*/));
    // 004526fa  0f8568010000           -jne 0x452868
    if (!cpu.flags.zf)
    {
        goto L_0x00452868;
    }
    // 00452700  ba7f000000             -mov edx, 0x7f
    cpu.edx = 127 /*0x7f*/;
    // 00452705  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 0045270a  e8c15afcff             -call 0x4181d0
    cpu.esp -= 4;
    sub_4181d0(app, cpu);
    if (cpu.terminate) return;
    // 0045270f  8a35a8d26f00           -mov dh, byte ptr [0x6fd2a8]
    cpu.dh = app->getMemory<x86::reg8>(x86::reg32(7328424) /* 0x6fd2a8 */);
    // 00452715  80ce08                 +or dh, 8
    cpu.clear_co();
    cpu.set_szp((cpu.dh |= x86::reg8(x86::sreg8(8 /*0x8*/))));
    // 00452718  be04000000             -mov esi, 4
    cpu.esi = 4 /*0x4*/;
    // 0045271d  8835a8d26f00           -mov byte ptr [0x6fd2a8], dh
    app->getMemory<x86::reg8>(x86::reg32(7328424) /* 0x6fd2a8 */) = cpu.dh;
    // 00452723  ff45fc                 +inc dword ptr [ebp - 4]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00452726  e9e1feffff             -jmp 0x45260c
    goto L_0x0045260c;
  case 0x0045272b:
    // 0045272b  f605a8d26f0010         +test byte ptr [0x6fd2a8], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(7328424) /* 0x6fd2a8 */) & 16 /*0x10*/));
    // 00452732  0f8530010000           -jne 0x452868
    if (!cpu.flags.zf)
    {
        goto L_0x00452868;
    }
    // 00452738  ba7f000000             -mov edx, 0x7f
    cpu.edx = 127 /*0x7f*/;
    // 0045273d  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 00452742  e8895afcff             -call 0x4181d0
    cpu.esp -= 4;
    sub_4181d0(app, cpu);
    if (cpu.terminate) return;
    // 00452747  8a3da8d26f00           -mov bh, byte ptr [0x6fd2a8]
    cpu.bh = app->getMemory<x86::reg8>(x86::reg32(7328424) /* 0x6fd2a8 */);
    // 0045274d  80cf10                 +or bh, 0x10
    cpu.clear_co();
    cpu.set_szp((cpu.bh |= x86::reg8(x86::sreg8(16 /*0x10*/))));
    // 00452750  be05000000             -mov esi, 5
    cpu.esi = 5 /*0x5*/;
    // 00452755  883da8d26f00           -mov byte ptr [0x6fd2a8], bh
    app->getMemory<x86::reg8>(x86::reg32(7328424) /* 0x6fd2a8 */) = cpu.bh;
    // 0045275b  ff45fc                 +inc dword ptr [ebp - 4]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0045275e  e9a9feffff             -jmp 0x45260c
    goto L_0x0045260c;
  case 0x00452763:
    // 00452763  ba7f000000             -mov edx, 0x7f
    cpu.edx = 127 /*0x7f*/;
    // 00452768  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 0045276d  e85e5afcff             -call 0x4181d0
    cpu.esp -= 4;
    sub_4181d0(app, cpu);
    if (cpu.terminate) return;
    // 00452772  a0a8d26f00             -mov al, byte ptr [0x6fd2a8]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(7328424) /* 0x6fd2a8 */);
    // 00452777  0c1f                   +or al, 0x1f
    cpu.clear_co();
    cpu.set_szp((cpu.al |= x86::reg8(x86::sreg8(31 /*0x1f*/))));
    // 00452779  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 0045277e  a2a8d26f00             -mov byte ptr [0x6fd2a8], al
    app->getMemory<x86::reg8>(x86::reg32(7328424) /* 0x6fd2a8 */) = cpu.al;
    // 00452783  ff45fc                 +inc dword ptr [ebp - 4]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00452786  e981feffff             -jmp 0x45260c
    goto L_0x0045260c;
  case 0x0045278b:
    // 0045278b  ba7f000000             -mov edx, 0x7f
    cpu.edx = 127 /*0x7f*/;
    // 00452790  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 00452795  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0045279a  e8315afcff             -call 0x4181d0
    cpu.esp -= 4;
    sub_4181d0(app, cpu);
    if (cpu.terminate) return;
    // 0045279f  b808000000             -mov eax, 8
    cpu.eax = 8 /*0x8*/;
    // 004527a4  891dacd26f00           -mov dword ptr [0x6fd2ac], ebx
    app->getMemory<x86::reg32>(x86::reg32(7328428) /* 0x6fd2ac */) = cpu.ebx;
    // 004527aa  a3acd46f00             -mov dword ptr [0x6fd4ac], eax
    app->getMemory<x86::reg32>(x86::reg32(7328940) /* 0x6fd4ac */) = cpu.eax;
    // 004527af  e8ac03ffff             -call 0x442b60
    cpu.esp -= 4;
    sub_442b60(app, cpu);
    if (cpu.terminate) return;
    // 004527b4  ff45fc                 +inc dword ptr [ebp - 4]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004527b7  e950feffff             -jmp 0x45260c
    goto L_0x0045260c;
  case 0x004527bc:
    // 004527bc  ba7f000000             -mov edx, 0x7f
    cpu.edx = 127 /*0x7f*/;
    // 004527c1  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 004527c6  e8055afcff             -call 0x4181d0
    cpu.esp -= 4;
    sub_4181d0(app, cpu);
    if (cpu.terminate) return;
    // 004527cb  800dfcd46f0001         +or byte ptr [0x6fd4fc], 1
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(x86::reg32(7329020) /* 0x6fd4fc */) |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 004527d2  ff45fc                 +inc dword ptr [ebp - 4]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004527d5  e932feffff             -jmp 0x45260c
    goto L_0x0045260c;
  case 0x004527da:
    // 004527da  ba7f000000             -mov edx, 0x7f
    cpu.edx = 127 /*0x7f*/;
    // 004527df  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 004527e4  e8e759fcff             -call 0x4181d0
    cpu.esp -= 4;
    sub_4181d0(app, cpu);
    if (cpu.terminate) return;
    // 004527e9  800dfcd46f0002         +or byte ptr [0x6fd4fc], 2
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(x86::reg32(7329020) /* 0x6fd4fc */) |= x86::reg8(x86::sreg8(2 /*0x2*/))));
    // 004527f0  ff45fc                 +inc dword ptr [ebp - 4]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004527f3  e914feffff             -jmp 0x45260c
    goto L_0x0045260c;
  case 0x004527f8:
    // 004527f8  ba7f000000             -mov edx, 0x7f
    cpu.edx = 127 /*0x7f*/;
    // 004527fd  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 00452802  e8c959fcff             -call 0x4181d0
    cpu.esp -= 4;
    sub_4181d0(app, cpu);
    if (cpu.terminate) return;
    // 00452807  800dfcd46f0004         +or byte ptr [0x6fd4fc], 4
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(x86::reg32(7329020) /* 0x6fd4fc */) |= x86::reg8(x86::sreg8(4 /*0x4*/))));
    // 0045280e  ff45fc                 +inc dword ptr [ebp - 4]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00452811  e9f6fdffff             -jmp 0x45260c
    goto L_0x0045260c;
  case 0x00452816:
    // 00452816  ba7f000000             -mov edx, 0x7f
    cpu.edx = 127 /*0x7f*/;
    // 0045281b  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 00452820  e8ab59fcff             -call 0x4181d0
    cpu.esp -= 4;
    sub_4181d0(app, cpu);
    if (cpu.terminate) return;
    // 00452825  800dfcd46f0008         +or byte ptr [0x6fd4fc], 8
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(x86::reg32(7329020) /* 0x6fd4fc */) |= x86::reg8(x86::sreg8(8 /*0x8*/))));
    // 0045282c  ff45fc                 +inc dword ptr [ebp - 4]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0045282f  e9d8fdffff             -jmp 0x45260c
    goto L_0x0045260c;
  case 0x00452834:
    // 00452834  ba7f000000             -mov edx, 0x7f
    cpu.edx = 127 /*0x7f*/;
    // 00452839  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 0045283e  e88d59fcff             -call 0x4181d0
    cpu.esp -= 4;
    sub_4181d0(app, cpu);
    if (cpu.terminate) return;
    // 00452843  800dfcd46f0010         +or byte ptr [0x6fd4fc], 0x10
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(x86::reg32(7329020) /* 0x6fd4fc */) |= x86::reg8(x86::sreg8(16 /*0x10*/))));
    // 0045284a  ff45fc                 +inc dword ptr [ebp - 4]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0045284d  e9bafdffff             -jmp 0x45260c
    goto L_0x0045260c;
  case 0x00452852:
    // 00452852  ba7f000000             -mov edx, 0x7f
    cpu.edx = 127 /*0x7f*/;
    // 00452857  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 0045285c  e86f59fcff             -call 0x4181d0
    cpu.esp -= 4;
    sub_4181d0(app, cpu);
    if (cpu.terminate) return;
    // 00452861  800dfcd46f0020         +or byte ptr [0x6fd4fc], 0x20
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(x86::reg32(7329020) /* 0x6fd4fc */) |= x86::reg8(x86::sreg8(32 /*0x20*/))));
  [[fallthrough]];
  case 0x00452868:
L_0x00452868:
    // 00452868  ff45fc                 +inc dword ptr [ebp - 4]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0045286b  e99cfdffff             -jmp 0x45260c
    goto L_0x0045260c;
L_0x00452870:
    // 00452870  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00452872  0f8489000000           -je 0x452901
    if (cpu.flags.zf)
    {
        goto L_0x00452901;
    }
    // 00452878  e81375feff             -call 0x439d90
    cpu.esp -= 4;
    sub_439d90(app, cpu);
    if (cpu.terminate) return;
    // 0045287d  8d46ff                 -lea eax, [esi - 1]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(-1) /* -0x1 */);
    // 00452880  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00452882  83f804                 +cmp eax, 4
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
    // 00452885  775f                   -ja 0x4528e6
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004528e6;
    }
    // 00452887  ff2485c4244500         -jmp dword ptr [eax*4 + 0x4524c4]
    cpu.ip = app->getMemory<x86::reg32>(4531396 + cpu.eax * 4); goto dynamic_jump;
  case 0x0045288e:
    // 0045288e  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00452893  bf27000000             -mov edi, 0x27
    cpu.edi = 39 /*0x27*/;
    // 00452898  eb4c                   -jmp 0x4528e6
    goto L_0x004528e6;
  case 0x0045289a:
    // 0045289a  8b0db8d36f00           -mov ecx, dword ptr [0x6fd3b8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */);
    // 004528a0  bf12000000             -mov edi, 0x12
    cpu.edi = 18 /*0x12*/;
    // 004528a5  83f903                 +cmp ecx, 3
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
    // 004528a8  7537                   -jne 0x4528e1
    if (!cpu.flags.zf)
    {
        goto L_0x004528e1;
    }
    // 004528aa  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004528ac  eb38                   -jmp 0x4528e6
    goto L_0x004528e6;
  case 0x004528ae:
    // 004528ae  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004528b3  bf11000000             -mov edi, 0x11
    cpu.edi = 17 /*0x11*/;
    // 004528b8  eb2c                   -jmp 0x4528e6
    goto L_0x004528e6;
  case 0x004528ba:
    // 004528ba  8b1db8d36f00           -mov ebx, dword ptr [0x6fd3b8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */);
    // 004528c0  bf24000000             -mov edi, 0x24
    cpu.edi = 36 /*0x24*/;
    // 004528c5  83fb03                 +cmp ebx, 3
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
    // 004528c8  751c                   -jne 0x4528e6
    if (!cpu.flags.zf)
    {
        goto L_0x004528e6;
    }
    // 004528ca  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004528cf  eb15                   -jmp 0x4528e6
    goto L_0x004528e6;
  case 0x004528d1:
    // 004528d1  8b35b8d36f00           -mov esi, dword ptr [0x6fd3b8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */);
    // 004528d7  bf31000000             -mov edi, 0x31
    cpu.edi = 49 /*0x31*/;
    // 004528dc  83fe03                 +cmp esi, 3
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
    // 004528df  7505                   -jne 0x4528e6
    if (!cpu.flags.zf)
    {
        goto L_0x004528e6;
    }
L_0x004528e1:
    // 004528e1  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
L_0x004528e6:
    // 004528e6  8d45e8                 -lea eax, [ebp - 0x18]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004528e9  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004528eb  e8e061feff             -call 0x438ad0
    cpu.esp -= 4;
    sub_438ad0(app, cpu);
    if (cpu.terminate) return;
    // 004528f0  8d45e8                 -lea eax, [ebp - 0x18]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004528f3  e89870feff             -call 0x439990
    cpu.esp -= 4;
    sub_439990(app, cpu);
    if (cpu.terminate) return;
    // 004528f8  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004528fa  7405                   -je 0x452901
    if (cpu.flags.zf)
    {
        goto L_0x00452901;
    }
    // 004528fc  a3bcd26f00             -mov dword ptr [0x6fd2bc], eax
    app->getMemory<x86::reg32>(x86::reg32(7328444) /* 0x6fd2bc */) = cpu.eax;
L_0x00452901:
    // 00452901  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00452903  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00452904  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00452905  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00452906  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00452907  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00452908  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00452909  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_452910(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00452910  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00452911  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00452913  e8e8edffff             -call 0x451700
    cpu.esp -= 4;
    sub_451700(app, cpu);
    if (cpu.terminate) return;
    // 00452918  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045291a  0f8573000000           -jne 0x452993
    if (!cpu.flags.zf)
    {
        goto L_0x00452993;
    }
    // 00452920  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00452925  e896880900             -call 0x4eb1c0
    cpu.esp -= 4;
    sub_4eb1c0(app, cpu);
    if (cpu.terminate) return;
    // 0045292a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045292c  0f8561000000           -jne 0x452993
    if (!cpu.flags.zf)
    {
        goto L_0x00452993;
    }
    // 00452932  b839000000             -mov eax, 0x39
    cpu.eax = 57 /*0x39*/;
    // 00452937  e884880900             -call 0x4eb1c0
    cpu.esp -= 4;
    sub_4eb1c0(app, cpu);
    if (cpu.terminate) return;
    // 0045293c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045293e  0f854f000000           -jne 0x452993
    if (!cpu.flags.zf)
    {
        goto L_0x00452993;
    }
    // 00452944  b81c000000             -mov eax, 0x1c
    cpu.eax = 28 /*0x1c*/;
    // 00452949  e872880900             -call 0x4eb1c0
    cpu.esp -= 4;
    sub_4eb1c0(app, cpu);
    if (cpu.terminate) return;
    // 0045294e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00452950  7541                   -jne 0x452993
    if (!cpu.flags.zf)
    {
        goto L_0x00452993;
    }
    // 00452952  b848000000             -mov eax, 0x48
    cpu.eax = 72 /*0x48*/;
    // 00452957  e864880900             -call 0x4eb1c0
    cpu.esp -= 4;
    sub_4eb1c0(app, cpu);
    if (cpu.terminate) return;
    // 0045295c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045295e  7533                   -jne 0x452993
    if (!cpu.flags.zf)
    {
        goto L_0x00452993;
    }
    // 00452960  b850000000             -mov eax, 0x50
    cpu.eax = 80 /*0x50*/;
    // 00452965  e856880900             -call 0x4eb1c0
    cpu.esp -= 4;
    sub_4eb1c0(app, cpu);
    if (cpu.terminate) return;
    // 0045296a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045296c  7525                   -jne 0x452993
    if (!cpu.flags.zf)
    {
        goto L_0x00452993;
    }
    // 0045296e  b84b000000             -mov eax, 0x4b
    cpu.eax = 75 /*0x4b*/;
    // 00452973  e848880900             -call 0x4eb1c0
    cpu.esp -= 4;
    sub_4eb1c0(app, cpu);
    if (cpu.terminate) return;
    // 00452978  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045297a  7517                   -jne 0x452993
    if (!cpu.flags.zf)
    {
        goto L_0x00452993;
    }
    // 0045297c  b84d000000             -mov eax, 0x4d
    cpu.eax = 77 /*0x4d*/;
    // 00452981  e83a880900             -call 0x4eb1c0
    cpu.esp -= 4;
    sub_4eb1c0(app, cpu);
    if (cpu.terminate) return;
    // 00452986  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00452988  7509                   -jne 0x452993
    if (!cpu.flags.zf)
    {
        goto L_0x00452993;
    }
    // 0045298a  833dece5550000         +cmp dword ptr [0x55e5ec], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5629420) /* 0x55e5ec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00452991  7405                   -je 0x452998
    if (cpu.flags.zf)
    {
        goto L_0x00452998;
    }
L_0x00452993:
    // 00452993  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00452998:
    // 00452998  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00452999  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_4529a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004529a0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004529a1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004529a2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004529a3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004529a4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004529a5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004529a7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004529a9  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004529ab  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004529ad  49                     -dec ecx
    (cpu.ecx)--;
    // 004529ae  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004529b0  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004529b2  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004529b4  49                     -dec ecx
    (cpu.ecx)--;
    // 004529b5  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004529b7  7413                   -je 0x4529cc
    if (cpu.flags.zf)
    {
        goto L_0x004529cc;
    }
    // 004529b9  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004529bb  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004529bd  49                     -dec ecx
    (cpu.ecx)--;
    // 004529be  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004529c0  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004529c2  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004529c4  49                     -dec ecx
    (cpu.ecx)--;
    // 004529c5  807c11ff5c             +cmp byte ptr [ecx + edx - 1], 0x5c
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-1) /* -0x1 */ + cpu.edx * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(92 /*0x5c*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004529ca  7429                   -je 0x4529f5
    if (cpu.flags.zf)
    {
        goto L_0x004529f5;
    }
L_0x004529cc:
    // 004529cc  be00965300             -mov esi, 0x539600
    cpu.esi = 5477888 /*0x539600*/;
    // 004529d1  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004529d3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004529d4  2bc9                   +sub ecx, ecx
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
    // 004529d6  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004529d7  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 004529d9  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004529db  4f                     -dec edi
    (cpu.edi)--;
L_0x004529dc:
    // 004529dc  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004529de  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004529e0  3c00                   +cmp al, 0
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
    // 004529e2  7410                   -je 0x4529f4
    if (cpu.flags.zf)
    {
        goto L_0x004529f4;
    }
    // 004529e4  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004529e7  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004529ea  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004529ed  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004529f0  3c00                   +cmp al, 0
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
    // 004529f2  75e8                   -jne 0x4529dc
    if (!cpu.flags.zf)
    {
        goto L_0x004529dc;
    }
L_0x004529f4:
    // 004529f4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004529f5:
    // 004529f5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004529f6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004529f7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004529f8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004529f9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004529fa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_452a00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00452a00  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00452a01  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00452a02  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00452a03  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00452a04  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00452a05  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00452a07  81ec08020000           -sub esp, 0x208
    (cpu.esp) -= x86::reg32(x86::sreg32(520 /*0x208*/));
    // 00452a0d  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00452a0f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00452a11  ba04965300             -mov edx, 0x539604
    cpu.edx = 5477892 /*0x539604*/;
    // 00452a16  e8cdb50900             -call 0x4edfe8
    cpu.esp -= 4;
    sub_4edfe8(app, cpu);
    if (cpu.terminate) return;
    // 00452a1b  ba08965300             -mov edx, 0x539608
    cpu.edx = 5477896 /*0x539608*/;
    // 00452a20  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00452a22  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00452a24  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00452a26  e8bdb50900             -call 0x4edfe8
    cpu.esp -= 4;
    sub_4edfe8(app, cpu);
    if (cpu.terminate) return;
    // 00452a2b  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 00452a2e  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00452a30  7404                   -je 0x452a36
    if (cpu.flags.zf)
    {
        goto L_0x00452a36;
    }
    // 00452a32  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00452a34  7507                   -jne 0x452a3d
    if (!cpu.flags.zf)
    {
        goto L_0x00452a3d;
    }
L_0x00452a36:
    // 00452a36  beffffffff             -mov esi, 0xffffffff
    cpu.esi = 4294967295 /*0xffffffff*/;
    // 00452a3b  eb54                   -jmp 0x452a91
    goto L_0x00452a91;
L_0x00452a3d:
    // 00452a3d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00452a3f  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
L_0x00452a42:
    // 00452a42  bb00020000             -mov ebx, 0x200
    cpu.ebx = 512 /*0x200*/;
    // 00452a47  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00452a4c  8d85f8fdffff           -lea eax, [ebp - 0x208]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-520) /* -0x208 */);
    // 00452a52  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00452a54  e8a7670900             -call 0x4e9200
    cpu.esp -= 4;
    sub_4e9200(app, cpu);
    if (cpu.terminate) return;
    // 00452a59  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00452a5b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00452a5d  7420                   -je 0x452a7f
    if (cpu.flags.zf)
    {
        goto L_0x00452a7f;
    }
    // 00452a5f  8b4df8                 -mov ecx, dword ptr [ebp - 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00452a62  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00452a67  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00452a69  8d85f8fdffff           -lea eax, [ebp - 0x208]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-520) /* -0x208 */);
    // 00452a6f  e85cc10900             -call 0x4eebd0
    cpu.esp -= 4;
    sub_4eebd0(app, cpu);
    if (cpu.terminate) return;
    // 00452a74  39c6                   +cmp esi, eax
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
    // 00452a76  74ca                   -je 0x452a42
    if (cpu.flags.zf)
    {
        goto L_0x00452a42;
    }
    // 00452a78  c745fc01000000         -mov dword ptr [ebp - 4], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 1 /*0x1*/;
L_0x00452a7f:
    // 00452a7f  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00452a81  e87ab60900             -call 0x4ee100
    cpu.esp -= 4;
    sub_4ee100(app, cpu);
    if (cpu.terminate) return;
    // 00452a86  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00452a89  8b75fc                 -mov esi, dword ptr [ebp - 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00452a8c  e86fb60900             -call 0x4ee100
    cpu.esp -= 4;
    sub_4ee100(app, cpu);
    if (cpu.terminate) return;
L_0x00452a91:
    // 00452a91  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00452a93  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00452a95  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00452a96  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00452a97  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00452a98  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00452a99  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00452a9a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_452ac0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00452ac0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00452ac1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00452ac2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00452ac3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00452ac4  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00452ac6  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00452ac8  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00452aca  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00452acc  83f801                 +cmp eax, 1
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
    // 00452acf  0f82d1000000           -jb 0x452ba6
    if (cpu.flags.cf)
    {
        goto L_0x00452ba6;
    }
    // 00452ad5  760e                   -jbe 0x452ae5
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00452ae5;
    }
    // 00452ad7  83f803                 +cmp eax, 3
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
    // 00452ada  0f84b3000000           -je 0x452b93
    if (cpu.flags.zf)
    {
        goto L_0x00452b93;
    }
    // 00452ae0  e9c1000000             -jmp 0x452ba6
    goto L_0x00452ba6;
L_0x00452ae5:
    // 00452ae5  e8d61bffff             -call 0x4446c0
    cpu.esp -= 4;
    sub_4446c0(app, cpu);
    if (cpu.terminate) return;
    // 00452aea  83f804                 +cmp eax, 4
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
    // 00452aed  0f87b3000000           -ja 0x452ba6
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00452ba6;
    }
    // 00452af3  ff2485a02a4500         -jmp dword ptr [eax*4 + 0x452aa0]
    cpu.ip = app->getMemory<x86::reg32>(4532896 + cpu.eax * 4); goto dynamic_jump;
  case 0x00452afa:
    // 00452afa  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00452afc  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00452b01  8915b8d36f00           -mov dword ptr [0x6fd3b8], edx
    app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */) = cpu.edx;
    // 00452b07  ba05000000             -mov edx, 5
    cpu.edx = 5 /*0x5*/;
    // 00452b0c  e995000000             -jmp 0x452ba6
    goto L_0x00452ba6;
  case 0x00452b11:
    // 00452b11  833d0cd56f0000         +cmp dword ptr [0x6fd50c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7329036) /* 0x6fd50c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00452b18  740c                   -je 0x452b26
    if (cpu.flags.zf)
    {
        goto L_0x00452b26;
    }
    // 00452b1a  c705b8d36f0002000000   -mov dword ptr [0x6fd3b8], 2
    app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */) = 2 /*0x2*/;
    // 00452b24  eb0a                   -jmp 0x452b30
    goto L_0x00452b30;
L_0x00452b26:
    // 00452b26  c705b8d36f0003000000   -mov dword ptr [0x6fd3b8], 3
    app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */) = 3 /*0x3*/;
L_0x00452b30:
    // 00452b30  ba05000000             -mov edx, 5
    cpu.edx = 5 /*0x5*/;
    // 00452b35  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00452b3a  e967000000             -jmp 0x452ba6
    goto L_0x00452ba6;
  case 0x00452b3f:
    // 00452b3f  833d0cd56f0000         +cmp dword ptr [0x6fd50c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7329036) /* 0x6fd50c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00452b46  740c                   -je 0x452b54
    if (cpu.flags.zf)
    {
        goto L_0x00452b54;
    }
    // 00452b48  c705b8d36f0001000000   -mov dword ptr [0x6fd3b8], 1
    app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */) = 1 /*0x1*/;
    // 00452b52  eb0a                   -jmp 0x452b5e
    goto L_0x00452b5e;
L_0x00452b54:
    // 00452b54  c705b8d36f0002000000   -mov dword ptr [0x6fd3b8], 2
    app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */) = 2 /*0x2*/;
L_0x00452b5e:
    // 00452b5e  ba05000000             -mov edx, 5
    cpu.edx = 5 /*0x5*/;
    // 00452b63  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00452b68  eb3c                   -jmp 0x452ba6
    goto L_0x00452ba6;
  case 0x00452b6a:
    // 00452b6a  833d0cd56f0000         +cmp dword ptr [0x6fd50c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7329036) /* 0x6fd50c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00452b71  7514                   -jne 0x452b87
    if (!cpu.flags.zf)
    {
        goto L_0x00452b87;
    }
    // 00452b73  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 00452b78  ba05000000             -mov edx, 5
    cpu.edx = 5 /*0x5*/;
    // 00452b7d  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00452b7f  893db8d36f00           -mov dword ptr [0x6fd3b8], edi
    app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */) = cpu.edi;
    // 00452b85  eb1f                   -jmp 0x452ba6
    goto L_0x00452ba6;
  case 0x00452b87:
L_0x00452b87:
    // 00452b87  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00452b8c  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00452b91  eb13                   -jmp 0x452ba6
    goto L_0x00452ba6;
L_0x00452b93:
    // 00452b93  833d4095550000         +cmp dword ptr [0x559540], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5608768) /* 0x559540 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00452b9a  740a                   -je 0x452ba6
    if (cpu.flags.zf)
    {
        goto L_0x00452ba6;
    }
    // 00452b9c  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00452ba1  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
L_0x00452ba6:
    // 00452ba6  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00452ba8  7402                   -je 0x452bac
    if (cpu.flags.zf)
    {
        goto L_0x00452bac;
    }
    // 00452baa  880b                   -mov byte ptr [ebx], cl
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.cl;
L_0x00452bac:
    // 00452bac  833db0d36f0001         +cmp dword ptr [0x6fd3b0], 1
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
    // 00452bb3  7e05                   -jle 0x452bba
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00452bba;
    }
    // 00452bb5  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
L_0x00452bba:
    // 00452bba  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00452bbc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00452bbd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00452bbe  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00452bbf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00452bc0  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_452bd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00452bd0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00452bd1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00452bd2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00452bd3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00452bd4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00452bd5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00452bd6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00452bd8  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00452bdb  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00452bdd  833d0cd56f0000         +cmp dword ptr [0x6fd50c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7329036) /* 0x6fd50c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00452be4  7407                   -je 0x452bed
    if (cpu.flags.zf)
    {
        goto L_0x00452bed;
    }
    // 00452be6  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00452beb  eb02                   -jmp 0x452bef
    goto L_0x00452bef;
L_0x00452bed:
    // 00452bed  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00452bef:
    // 00452bef  b848955500             -mov eax, 0x559548
    cpu.eax = 5608776 /*0x559548*/;
    // 00452bf4  bf04000000             -mov edi, 4
    cpu.edi = 4 /*0x4*/;
    // 00452bf9  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00452bfb  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00452bfd  891d44955500           -mov dword ptr [0x559544], ebx
    app->getMemory<x86::reg32>(x86::reg32(5608772) /* 0x559544 */) = cpu.ebx;
    // 00452c03  bb14000000             -mov ebx, 0x14
    cpu.ebx = 20 /*0x14*/;
    // 00452c08  893540955500           -mov dword ptr [0x559540], esi
    app->getMemory<x86::reg32>(x86::reg32(5608768) /* 0x559540 */) = cpu.esi;
    // 00452c0e  e82dda0800             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 00452c13  bb14000000             -mov ebx, 0x14
    cpu.ebx = 20 /*0x14*/;
    // 00452c18  b85c955500             -mov eax, 0x55955c
    cpu.eax = 5608796 /*0x55955c*/;
    // 00452c1d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00452c1f  894dfc                 -mov dword ptr [ebp - 4], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
    // 00452c22  e819da0800             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 00452c27  b80f010000             -mov eax, 0x10f
    cpu.eax = 271 /*0x10f*/;
    // 00452c2c  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 00452c31  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 00452c36  e815ec0700             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00452c3b  a344955500             -mov dword ptr [0x559544], eax
    app->getMemory<x86::reg32>(x86::reg32(5608772) /* 0x559544 */) = cpu.eax;
    // 00452c40  b8d5000000             -mov eax, 0xd5
    cpu.eax = 213 /*0xd5*/;
    // 00452c45  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00452c47  e804ec0700             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00452c4c  a348955500             -mov dword ptr [0x559548], eax
    app->getMemory<x86::reg32>(x86::reg32(5608776) /* 0x559548 */) = cpu.eax;
    // 00452c51  b8dc000000             -mov eax, 0xdc
    cpu.eax = 220 /*0xdc*/;
    // 00452c56  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00452c58  e8f3eb0700             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00452c5d  a34c955500             -mov dword ptr [0x55954c], eax
    app->getMemory<x86::reg32>(x86::reg32(5608780) /* 0x55954c */) = cpu.eax;
    // 00452c62  b8d7000000             -mov eax, 0xd7
    cpu.eax = 215 /*0xd7*/;
    // 00452c67  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 00452c6a  e8e1eb0700             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00452c6f  89049d48955500         -mov dword ptr [ebx*4 + 0x559548], eax
    app->getMemory<x86::reg32>(x86::reg32(5608776) /* 0x559548 */ + cpu.ebx * 4) = cpu.eax;
    // 00452c76  b8d6000000             -mov eax, 0xd6
    cpu.eax = 214 /*0xd6*/;
    // 00452c7b  29cf                   -sub edi, ecx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00452c7d  e8ceeb0700             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00452c82  898248955500           -mov dword ptr [edx + 0x559548], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5608776) /* 0x559548 */) = cpu.eax;
    // 00452c88  b8c6000000             -mov eax, 0xc6
    cpu.eax = 198 /*0xc6*/;
    // 00452c8d  8d0cbd00000000         -lea ecx, [edi*4]
    cpu.ecx = x86::reg32(cpu.edi * 4);
    // 00452c94  e8b7eb0700             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00452c99  898148955500           -mov dword ptr [ecx + 0x559548], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5608776) /* 0x559548 */) = cpu.eax;
    // 00452c9f  b881010000             -mov eax, 0x181
    cpu.eax = 385 /*0x181*/;
    // 00452ca4  e8a7eb0700             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00452ca9  a35c955500             -mov dword ptr [0x55955c], eax
    app->getMemory<x86::reg32>(x86::reg32(5608796) /* 0x55955c */) = cpu.eax;
    // 00452cae  b884010000             -mov eax, 0x184
    cpu.eax = 388 /*0x184*/;
    // 00452cb3  e898eb0700             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00452cb8  a360955500             -mov dword ptr [0x559560], eax
    app->getMemory<x86::reg32>(x86::reg32(5608800) /* 0x559560 */) = cpu.eax;
    // 00452cbd  b883010000             -mov eax, 0x183
    cpu.eax = 387 /*0x183*/;
    // 00452cc2  e889eb0700             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00452cc7  89049d5c955500         -mov dword ptr [ebx*4 + 0x55955c], eax
    app->getMemory<x86::reg32>(x86::reg32(5608796) /* 0x55955c */ + cpu.ebx * 4) = cpu.eax;
    // 00452cce  b882010000             -mov eax, 0x182
    cpu.eax = 386 /*0x182*/;
    // 00452cd3  e878eb0700             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00452cd8  68c02a4500             -push 0x452ac0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4532928 /*0x452ac0*/;
    cpu.esp -= 4;
    // 00452cdd  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00452cdf  89825c955500           -mov dword ptr [edx + 0x55955c], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5608796) /* 0x55955c */) = cpu.eax;
    // 00452ce5  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00452ce7  89b95c955500           -mov dword ptr [ecx + 0x55955c], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5608796) /* 0x55955c */) = cpu.edi;
    // 00452ced  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00452cef  7407                   -je 0x452cf8
    if (cpu.flags.zf)
    {
        goto L_0x00452cf8;
    }
    // 00452cf1  a1b8d36f00             -mov eax, dword ptr [0x6fd3b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */);
    // 00452cf6  eb02                   -jmp 0x452cfa
    goto L_0x00452cfa;
L_0x00452cf8:
    // 00452cf8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00452cfa:
    // 00452cfa  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00452cfb  b948955500             -mov ecx, 0x559548
    cpu.ecx = 5608776 /*0x559548*/;
    // 00452d00  685c955500             -push 0x55955c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5608796 /*0x55955c*/;
    cpu.esp -= 4;
    // 00452d05  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00452d07  7407                   -je 0x452d10
    if (cpu.flags.zf)
    {
        goto L_0x00452d10;
    }
    // 00452d09  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00452d0e  eb02                   -jmp 0x452d12
    goto L_0x00452d12;
L_0x00452d10:
    // 00452d10  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00452d12:
    // 00452d12  8d5804                 -lea ebx, [eax + 4]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00452d15  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00452d18  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00452d1d  29d3                   -sub ebx, edx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00452d1f  ba44955500             -mov edx, 0x559544
    cpu.edx = 5608772 /*0x559544*/;
    // 00452d24  e8a719ffff             -call 0x4446d0
    cpu.esp -= 4;
    sub_4446d0(app, cpu);
    if (cpu.terminate) return;
    // 00452d29  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00452d2b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00452d2c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00452d2d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00452d2e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00452d2f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00452d30  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00452d31  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_452d40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00452d40  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00452d41  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00452d42  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00452d43  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00452d45  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00452d4a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00452d4f  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00452d51  8915b0d36f00           -mov dword ptr [0x6fd3b0], edx
    app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */) = cpu.edx;
    // 00452d57  890d0cd56f00           -mov dword ptr [0x6fd50c], ecx
    app->getMemory<x86::reg32>(x86::reg32(7329036) /* 0x6fd50c */) = cpu.ecx;
    // 00452d5d  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00452d62  890de0227a00           -mov dword ptr [0x7a22e0], ecx
    app->getMemory<x86::reg32>(x86::reg32(8004320) /* 0x7a22e0 */) = cpu.ecx;
    // 00452d68  668915da227a00         -mov word ptr [0x7a22da], dx
    app->getMemory<x86::reg16>(x86::reg32(8004314) /* 0x7a22da */) = cpu.dx;
    // 00452d6f  e85cfeffff             -call 0x452bd0
    cpu.esp -= 4;
    sub_452bd0(app, cpu);
    if (cpu.terminate) return;
    // 00452d74  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00452d79  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00452d7a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00452d7b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00452d7c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_452d80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00452d80  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00452d81  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00452d82  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00452d84  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00452d86  83f801                 +cmp eax, 1
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
    // 00452d89  7218                   -jb 0x452da3
    if (cpu.flags.cf)
    {
        goto L_0x00452da3;
    }
    // 00452d8b  7605                   -jbe 0x452d92
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00452d92;
    }
    // 00452d8d  83f803                 +cmp eax, 3
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
    // 00452d90  7511                   -jne 0x452da3
    if (!cpu.flags.zf)
    {
        goto L_0x00452da3;
    }
L_0x00452d92:
    // 00452d92  e82919ffff             -call 0x4446c0
    cpu.esp -= 4;
    sub_4446c0(app, cpu);
    if (cpu.terminate) return;
    // 00452d97  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00452d99  7403                   -je 0x452d9e
    if (cpu.flags.zf)
    {
        goto L_0x00452d9e;
    }
    // 00452d9b  c60201                 -mov byte ptr [edx], 1
    app->getMemory<x86::reg8>(cpu.edx) = 1 /*0x1*/;
L_0x00452d9e:
    // 00452d9e  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
L_0x00452da3:
    // 00452da3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00452da5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00452da6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00452da7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_452db0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00452db0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00452db1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00452db2  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00452db4  e8f780ffff             -call 0x44aeb0
    cpu.esp -= 4;
    sub_44aeb0(app, cpu);
    if (cpu.terminate) return;
    // 00452db9  ba0c965300             -mov edx, 0x53960c
    cpu.edx = 5477900 /*0x53960c*/;
    // 00452dbe  8b4014                 -mov eax, dword ptr [eax + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 00452dc1  e8fa700900             -call 0x4e9ec0
    cpu.esp -= 4;
    sub_4e9ec0(app, cpu);
    if (cpu.terminate) return;
    // 00452dc6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00452dc8  7508                   -jne 0x452dd2
    if (!cpu.flags.zf)
    {
        goto L_0x00452dd2;
    }
    // 00452dca  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00452dcf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00452dd0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00452dd1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00452dd2:
    // 00452dd2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00452dd4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00452dd5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00452dd6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_452de0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00452de0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00452de1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00452de2  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00452de4  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00452de6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00452de8  83f901                 +cmp ecx, 1
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
    // 00452deb  0f825e000000           -jb 0x452e4f
    if (cpu.flags.cf)
    {
        goto L_0x00452e4f;
    }
    // 00452df1  7608                   -jbe 0x452dfb
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00452dfb;
    }
    // 00452df3  83f903                 +cmp ecx, 3
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
    // 00452df6  744b                   -je 0x452e43
    if (cpu.flags.zf)
    {
        goto L_0x00452e43;
    }
    // 00452df8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00452df9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00452dfa  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00452dfb:
    // 00452dfb  e8c018ffff             -call 0x4446c0
    cpu.esp -= 4;
    sub_4446c0(app, cpu);
    if (cpu.terminate) return;
    // 00452e00  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00452e02  7522                   -jne 0x452e26
    if (!cpu.flags.zf)
    {
        goto L_0x00452e26;
    }
    // 00452e04  e8a7ffffff             -call 0x452db0
    cpu.esp -= 4;
    sub_452db0(app, cpu);
    if (cpu.terminate) return;
    // 00452e09  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00452e0b  7407                   -je 0x452e14
    if (cpu.flags.zf)
    {
        goto L_0x00452e14;
    }
    // 00452e0d  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00452e12  eb05                   -jmp 0x452e19
    goto L_0x00452e19;
L_0x00452e14:
    // 00452e14  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
L_0x00452e19:
    // 00452e19  a394e85500             -mov dword ptr [0x55e894], eax
    app->getMemory<x86::reg32>(x86::reg32(5630100) /* 0x55e894 */) = cpu.eax;
    // 00452e1e  b80a000000             -mov eax, 0xa
    cpu.eax = 10 /*0xa*/;
    // 00452e23  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00452e24  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00452e25  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00452e26:
    // 00452e26  83f801                 +cmp eax, 1
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
    // 00452e29  7509                   -jne 0x452e34
    if (!cpu.flags.zf)
    {
        goto L_0x00452e34;
    }
    // 00452e2b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00452e2d  740c                   -je 0x452e3b
    if (cpu.flags.zf)
    {
        goto L_0x00452e3b;
    }
    // 00452e2f  c60201                 -mov byte ptr [edx], 1
    app->getMemory<x86::reg8>(cpu.edx) = 1 /*0x1*/;
    // 00452e32  eb07                   -jmp 0x452e3b
    goto L_0x00452e3b;
L_0x00452e34:
    // 00452e34  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00452e36  7403                   -je 0x452e3b
    if (cpu.flags.zf)
    {
        goto L_0x00452e3b;
    }
    // 00452e38  c60200                 -mov byte ptr [edx], 0
    app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
L_0x00452e3b:
    // 00452e3b  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00452e40  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00452e41  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00452e42  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00452e43:
    // 00452e43  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00452e45  7403                   -je 0x452e4a
    if (cpu.flags.zf)
    {
        goto L_0x00452e4a;
    }
    // 00452e47  c60201                 -mov byte ptr [edx], 1
    app->getMemory<x86::reg8>(cpu.edx) = 1 /*0x1*/;
L_0x00452e4a:
    // 00452e4a  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
L_0x00452e4f:
    // 00452e4f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00452e50  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00452e51  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_452e60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00452e60  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00452e61  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00452e62  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00452e63  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00452e64  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00452e66  e825c90400             -call 0x49f790
    cpu.esp -= 4;
    sub_49f790(app, cpu);
    if (cpu.terminate) return;
    // 00452e6b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00452e6d  7509                   -jne 0x452e78
    if (!cpu.flags.zf)
    {
        goto L_0x00452e78;
    }
    // 00452e6f  e80cca0400             -call 0x49f880
    cpu.esp -= 4;
    sub_49f880(app, cpu);
    if (cpu.terminate) return;
    // 00452e74  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00452e76  7458                   -je 0x452ed0
    if (cpu.flags.zf)
    {
        goto L_0x00452ed0;
    }
L_0x00452e78:
    // 00452e78  b8c0010000             -mov eax, 0x1c0
    cpu.eax = 448 /*0x1c0*/;
    // 00452e7d  e8cee90700             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00452e82  a360466600             -mov dword ptr [0x664660], eax
    app->getMemory<x86::reg32>(x86::reg32(6702688) /* 0x664660 */) = cpu.eax;
    // 00452e87  b8c1010000             -mov eax, 0x1c1
    cpu.eax = 449 /*0x1c1*/;
    // 00452e8c  e8bfe90700             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00452e91  a364466600             -mov dword ptr [0x664664], eax
    app->getMemory<x86::reg32>(x86::reg32(6702692) /* 0x664664 */) = cpu.eax;
    // 00452e96  b8c4000000             -mov eax, 0xc4
    cpu.eax = 196 /*0xc4*/;
    // 00452e9b  e8b0e90700             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00452ea0  a36c466600             -mov dword ptr [0x66466c], eax
    app->getMemory<x86::reg32>(x86::reg32(6702700) /* 0x66466c */) = cpu.eax;
    // 00452ea5  b8c5000000             -mov eax, 0xc5
    cpu.eax = 197 /*0xc5*/;
    // 00452eaa  e8a1e90700             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00452eaf  68e02d4500             -push 0x452de0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4533728 /*0x452de0*/;
    cpu.esp -= 4;
    // 00452eb4  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00452eb6  b96c466600             -mov ecx, 0x66466c
    cpu.ecx = 6702700 /*0x66466c*/;
    // 00452ebb  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00452ebd  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 00452ec2  ba60466600             -mov edx, 0x664660
    cpu.edx = 6702688 /*0x664660*/;
    // 00452ec7  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00452ec9  a370466600             -mov dword ptr [0x664670], eax
    app->getMemory<x86::reg32>(x86::reg32(6702704) /* 0x664670 */) = cpu.eax;
    // 00452ece  eb38                   -jmp 0x452f08
    goto L_0x00452f08;
L_0x00452ed0:
    // 00452ed0  b8c2010000             -mov eax, 0x1c2
    cpu.eax = 450 /*0x1c2*/;
    // 00452ed5  e876e90700             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00452eda  a360466600             -mov dword ptr [0x664660], eax
    app->getMemory<x86::reg32>(x86::reg32(6702688) /* 0x664660 */) = cpu.eax;
    // 00452edf  b8f9000000             -mov eax, 0xf9
    cpu.eax = 249 /*0xf9*/;
    // 00452ee4  e867e90700             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00452ee9  68802d4500             -push 0x452d80
    app->getMemory<x86::reg32>(cpu.esp-4) = 4533632 /*0x452d80*/;
    cpu.esp -= 4;
    // 00452eee  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00452ef0  b96c466600             -mov ecx, 0x66466c
    cpu.ecx = 6702700 /*0x66466c*/;
    // 00452ef5  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00452ef7  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00452efc  ba60466600             -mov edx, 0x664660
    cpu.edx = 6702688 /*0x664660*/;
    // 00452f01  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00452f03  a36c466600             -mov dword ptr [0x66466c], eax
    app->getMemory<x86::reg32>(x86::reg32(6702700) /* 0x66466c */) = cpu.eax;
L_0x00452f08:
    // 00452f08  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00452f0a  e8c117ffff             -call 0x4446d0
    cpu.esp -= 4;
    sub_4446d0(app, cpu);
    if (cpu.terminate) return;
    // 00452f0f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00452f11  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00452f12  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00452f13  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00452f14  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00452f15  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_452f20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00452f20  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00452f21  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00452f22  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00452f23  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00452f25  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00452f2a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00452f2c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00452f2e  8915b0d36f00           -mov dword ptr [0x6fd3b0], edx
    app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */) = cpu.edx;
    // 00452f34  89150cd56f00           -mov dword ptr [0x6fd50c], edx
    app->getMemory<x86::reg32>(x86::reg32(7329036) /* 0x6fd50c */) = cpu.edx;
    // 00452f3a  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00452f3f  891de0227a00           -mov dword ptr [0x7a22e0], ebx
    app->getMemory<x86::reg32>(x86::reg32(8004320) /* 0x7a22e0 */) = cpu.ebx;
    // 00452f45  668915da227a00         -mov word ptr [0x7a22da], dx
    app->getMemory<x86::reg16>(x86::reg32(8004314) /* 0x7a22da */) = cpu.dx;
    // 00452f4c  e87ffcffff             -call 0x452bd0
    cpu.esp -= 4;
    sub_452bd0(app, cpu);
    if (cpu.terminate) return;
    // 00452f51  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00452f56  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00452f57  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00452f58  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00452f59  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_452f60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00452f60  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00452f61  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00452f63  e898320400             -call 0x496200
    cpu.esp -= 4;
    sub_496200(app, cpu);
    if (cpu.terminate) return;
    // 00452f68  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00452f6a  7405                   -je 0x452f71
    if (cpu.flags.zf)
    {
        goto L_0x00452f71;
    }
    // 00452f6c  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
L_0x00452f71:
    // 00452f71  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00452f72  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_452f80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00452f80  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00452f81  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00452f82  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00452f83  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00452f84  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00452f85  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00452f86  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00452f88  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00452f8a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00452f8c  8b0de0227a00           -mov ecx, dword ptr [0x7a22e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(8004320) /* 0x7a22e0 */);
    // 00452f92  8915b0d36f00           -mov dword ptr [0x6fd3b0], edx
    app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */) = cpu.edx;
    // 00452f98  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00452f9a  7405                   -je 0x452fa1
    if (cpu.flags.zf)
    {
        goto L_0x00452fa1;
    }
    // 00452f9c  e83f360500             -call 0x4a65e0
    cpu.esp -= 4;
    sub_4a65e0(app, cpu);
    if (cpu.terminate) return;
L_0x00452fa1:
    // 00452fa1  66833dde227a0000       +cmp word ptr [0x7a22de], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(8004318) /* 0x7a22de */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00452fa9  7430                   -je 0x452fdb
    if (cpu.flags.zf)
    {
        goto L_0x00452fdb;
    }
    // 00452fab  b814010000             -mov eax, 0x114
    cpu.eax = 276 /*0x114*/;
    // 00452fb0  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00452fb5  bb00020000             -mov ebx, 0x200
    cpu.ebx = 512 /*0x200*/;
    // 00452fba  ba74466600             -mov edx, 0x664674
    cpu.edx = 6702708 /*0x664674*/;
    // 00452fbf  e88ce80700             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00452fc4  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00452fc6  a374466600             -mov dword ptr [0x664674], eax
    app->getMemory<x86::reg32>(x86::reg32(6702708) /* 0x664674 */) = cpu.eax;
    // 00452fcb  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00452fcd  e8ae1affff             -call 0x444a80
    cpu.esp -= 4;
    sub_444a80(app, cpu);
    if (cpu.terminate) return;
    // 00452fd2  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00452fd4  66891dde227a00         -mov word ptr [0x7a22de], bx
    app->getMemory<x86::reg16>(x86::reg32(8004318) /* 0x7a22de */) = cpu.bx;
L_0x00452fdb:
    // 00452fdb  ba14965300             -mov edx, 0x539614
    cpu.edx = 5477908 /*0x539614*/;
    // 00452fe0  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00452fe2  e859fafeff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00452fe7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00452fe9  744f                   -je 0x45303a
    if (cpu.flags.zf)
    {
        goto L_0x0045303a;
    }
    // 00452feb  8a152eeb5500           -mov dl, byte ptr [0x55eb2e]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5630766) /* 0x55eb2e */);
    // 00452ff1  f6c220                 +test dl, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 32 /*0x20*/));
    // 00452ff4  740c                   -je 0x453002
    if (cpu.flags.zf)
    {
        goto L_0x00453002;
    }
    // 00452ff6  c705b8d36f0003000000   -mov dword ptr [0x6fd3b8], 3
    app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */) = 3 /*0x3*/;
    // 00453000  eb38                   -jmp 0x45303a
    goto L_0x0045303a;
L_0x00453002:
    // 00453002  f6c210                 +test dl, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 16 /*0x10*/));
    // 00453005  742c                   -je 0x453033
    if (cpu.flags.zf)
    {
        goto L_0x00453033;
    }
    // 00453007  bf03000000             -mov edi, 3
    cpu.edi = 3 /*0x3*/;
    // 0045300c  8a1d2feb5500           -mov bl, byte ptr [0x55eb2f]
    cpu.bl = app->getMemory<x86::reg8>(x86::reg32(5630767) /* 0x55eb2f */);
    // 00453012  893db8d36f00           -mov dword ptr [0x6fd3b8], edi
    app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */) = cpu.edi;
    // 00453018  f6c304                 +test bl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 4 /*0x4*/));
    // 0045301b  741d                   -je 0x45303a
    if (cpu.flags.zf)
    {
        goto L_0x0045303a;
    }
    // 0045301d  ba2c965300             -mov edx, 0x53962c
    cpu.edx = 5477932 /*0x53962c*/;
    // 00453022  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00453024  e817fafeff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00453029  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045302b  740d                   -je 0x45303a
    if (cpu.flags.zf)
    {
        goto L_0x0045303a;
    }
    // 0045302d  80480401               +or byte ptr [eax + 4], 1
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 00453031  eb07                   -jmp 0x45303a
    goto L_0x0045303a;
L_0x00453033:
    // 00453033  c74064202f4500         -mov dword ptr [eax + 0x64], 0x452f20
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(100) /* 0x64 */) = 4534048 /*0x452f20*/;
L_0x0045303a:
    // 0045303a  ba44965300             -mov edx, 0x539644
    cpu.edx = 5477956 /*0x539644*/;
    // 0045303f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00453041  e8faf9feff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00453046  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00453048  7407                   -je 0x453051
    if (cpu.flags.zf)
    {
        goto L_0x00453051;
    }
    // 0045304a  c74064402d4500         -mov dword ptr [eax + 0x64], 0x452d40
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(100) /* 0x64 */) = 4533568 /*0x452d40*/;
L_0x00453051:
    // 00453051  ba5c965300             -mov edx, 0x53965c
    cpu.edx = 5477980 /*0x53965c*/;
    // 00453056  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00453058  e8e3f9feff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0045305d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045305f  7407                   -je 0x453068
    if (cpu.flags.zf)
    {
        goto L_0x00453068;
    }
    // 00453061  c74064602e4500         -mov dword ptr [eax + 0x64], 0x452e60
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(100) /* 0x64 */) = 4533856 /*0x452e60*/;
L_0x00453068:
    // 00453068  833d54bb6f0000         +cmp dword ptr [0x6fbb54], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7322452) /* 0x6fbb54 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045306f  743c                   -je 0x4530ad
    if (cpu.flags.zf)
    {
        goto L_0x004530ad;
    }
    // 00453071  ba14965300             -mov edx, 0x539614
    cpu.edx = 5477908 /*0x539614*/;
    // 00453076  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00453078  e8c3f9feff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0045307d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045307f  7404                   -je 0x453085
    if (cpu.flags.zf)
    {
        goto L_0x00453085;
    }
    // 00453081  80480401               -or byte ptr [eax + 4], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x00453085:
    // 00453085  ba44965300             -mov edx, 0x539644
    cpu.edx = 5477956 /*0x539644*/;
    // 0045308a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0045308c  e8aff9feff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00453091  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00453093  7404                   -je 0x453099
    if (cpu.flags.zf)
    {
        goto L_0x00453099;
    }
    // 00453095  80480401               -or byte ptr [eax + 4], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x00453099:
    // 00453099  ba70965300             -mov edx, 0x539670
    cpu.edx = 5478000 /*0x539670*/;
    // 0045309e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004530a0  e89bf9feff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 004530a5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004530a7  7404                   -je 0x4530ad
    if (cpu.flags.zf)
    {
        goto L_0x004530ad;
    }
    // 004530a9  80480401               -or byte ptr [eax + 4], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x004530ad:
    // 004530ad  e82e310400             -call 0x4961e0
    cpu.esp -= 4;
    sub_4961e0(app, cpu);
    if (cpu.terminate) return;
    // 004530b2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004530b4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004530b5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004530b6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004530b7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004530b8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004530b9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004530ba  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4530c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004530c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004530c1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004530c2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004530c3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004530c4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004530c5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004530c7  81ec00010000           -sub esp, 0x100
    (cpu.esp) -= x86::reg32(x86::sreg32(256 /*0x100*/));
    // 004530cd  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004530cf  e8dc61feff             -call 0x4392b0
    cpu.esp -= 4;
    sub_4392b0(app, cpu);
    if (cpu.terminate) return;
    // 004530d4  8b3554bb6f00           -mov esi, dword ptr [0x6fbb54]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(7322452) /* 0x6fbb54 */);
    // 004530da  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004530dc  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004530de  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004530e0  7404                   -je 0x4530e6
    if (cpu.flags.zf)
    {
        goto L_0x004530e6;
    }
    // 004530e2  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004530e4  eb63                   -jmp 0x453149
    goto L_0x00453149;
L_0x004530e6:
    // 004530e6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004530e8  745d                   -je 0x453147
    if (cpu.flags.zf)
    {
        goto L_0x00453147;
    }
    // 004530ea  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004530ec  e8cf64feff             -call 0x4395c0
    cpu.esp -= 4;
    sub_4395c0(app, cpu);
    if (cpu.terminate) return;
    // 004530f1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004530f3  7424                   -je 0x453119
    if (cpu.flags.zf)
    {
        goto L_0x00453119;
    }
    // 004530f5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004530f7  e89461feff             -call 0x439290
    cpu.esp -= 4;
    sub_439290(app, cpu);
    if (cpu.terminate) return;
    // 004530fc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004530fd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004530fe  68b4287a00             -push 0x7a28b4
    app->getMemory<x86::reg32>(cpu.esp-4) = 8005812 /*0x7a28b4*/;
    cpu.esp -= 4;
    // 00453103  6884965300             -push 0x539684
    app->getMemory<x86::reg32>(cpu.esp-4) = 5478020 /*0x539684*/;
    cpu.esp -= 4;
    // 00453108  8d8500ffffff           -lea eax, [ebp - 0x100]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-256) /* -0x100 */);
    // 0045310e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0045310f  e87cc50800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00453114  83c414                 +add esp, 0x14
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(20 /*0x14*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00453117  eb1a                   -jmp 0x453133
    goto L_0x00453133;
L_0x00453119:
    // 00453119  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045311a  6834327a00             -push 0x7a3234
    app->getMemory<x86::reg32>(cpu.esp-4) = 8008244 /*0x7a3234*/;
    cpu.esp -= 4;
    // 0045311f  6894965300             -push 0x539694
    app->getMemory<x86::reg32>(cpu.esp-4) = 5478036 /*0x539694*/;
    cpu.esp -= 4;
    // 00453124  8d8500ffffff           -lea eax, [ebp - 0x100]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-256) /* -0x100 */);
    // 0045312a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0045312b  e860c50800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00453130  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x00453133:
    // 00453133  8d8500ffffff           -lea eax, [ebp - 0x100]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-256) /* -0x100 */);
    // 00453139  e822dd0800             -call 0x4e0e60
    cpu.esp -= 4;
    sub_4e0e60(app, cpu);
    if (cpu.terminate) return;
    // 0045313e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00453140  7405                   -je 0x453147
    if (cpu.flags.zf)
    {
        goto L_0x00453147;
    }
    // 00453142  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
L_0x00453147:
    // 00453147  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x00453149:
    // 00453149  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0045314b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045314c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045314d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045314e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045314f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453150  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_453160(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00453160  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00453161  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00453162  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00453163  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00453164  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00453165  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00453167  81ec00010000           -sub esp, 0x100
    (cpu.esp) -= x86::reg32(x86::sreg32(256 /*0x100*/));
    // 0045316d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0045316f  e83c61feff             -call 0x4392b0
    cpu.esp -= 4;
    sub_4392b0(app, cpu);
    if (cpu.terminate) return;
    // 00453174  8b3554bb6f00           -mov esi, dword ptr [0x6fbb54]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(7322452) /* 0x6fbb54 */);
    // 0045317a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0045317c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0045317e  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00453180  7404                   -je 0x453186
    if (cpu.flags.zf)
    {
        goto L_0x00453186;
    }
    // 00453182  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00453184  eb6b                   -jmp 0x4531f1
    goto L_0x004531f1;
L_0x00453186:
    // 00453186  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00453188  7508                   -jne 0x453192
    if (!cpu.flags.zf)
    {
        goto L_0x00453192;
    }
    // 0045318a  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0045318c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045318d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045318e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045318f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453190  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453191  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00453192:
    // 00453192  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00453194  e82764feff             -call 0x4395c0
    cpu.esp -= 4;
    sub_4395c0(app, cpu);
    if (cpu.terminate) return;
    // 00453199  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045319b  7424                   -je 0x4531c1
    if (cpu.flags.zf)
    {
        goto L_0x004531c1;
    }
    // 0045319d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045319f  e8ec60feff             -call 0x439290
    cpu.esp -= 4;
    sub_439290(app, cpu);
    if (cpu.terminate) return;
    // 004531a4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004531a5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004531a6  68b4287a00             -push 0x7a28b4
    app->getMemory<x86::reg32>(cpu.esp-4) = 8005812 /*0x7a28b4*/;
    cpu.esp -= 4;
    // 004531ab  68a0965300             -push 0x5396a0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5478048 /*0x5396a0*/;
    cpu.esp -= 4;
    // 004531b0  8d8500ffffff           -lea eax, [ebp - 0x100]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-256) /* -0x100 */);
    // 004531b6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004531b7  e8d4c40800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 004531bc  83c414                 +add esp, 0x14
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(20 /*0x14*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004531bf  eb1a                   -jmp 0x4531db
    goto L_0x004531db;
L_0x004531c1:
    // 004531c1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004531c2  6834327a00             -push 0x7a3234
    app->getMemory<x86::reg32>(cpu.esp-4) = 8008244 /*0x7a3234*/;
    cpu.esp -= 4;
    // 004531c7  68b0965300             -push 0x5396b0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5478064 /*0x5396b0*/;
    cpu.esp -= 4;
    // 004531cc  8d8500ffffff           -lea eax, [ebp - 0x100]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-256) /* -0x100 */);
    // 004531d2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004531d3  e8b8c40800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 004531d8  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x004531db:
    // 004531db  8d8500ffffff           -lea eax, [ebp - 0x100]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-256) /* -0x100 */);
    // 004531e1  e87adc0800             -call 0x4e0e60
    cpu.esp -= 4;
    sub_4e0e60(app, cpu);
    if (cpu.terminate) return;
    // 004531e6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004531e8  7405                   -je 0x4531ef
    if (cpu.flags.zf)
    {
        goto L_0x004531ef;
    }
    // 004531ea  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
L_0x004531ef:
    // 004531ef  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x004531f1:
    // 004531f1  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004531f3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004531f4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004531f5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004531f6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004531f7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004531f8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_453200(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00453200  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00453201  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00453202  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00453203  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00453204  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00453206  81ec00010000           -sub esp, 0x100
    (cpu.esp) -= x86::reg32(x86::sreg32(256 /*0x100*/));
    // 0045320c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0045320e  e89d60feff             -call 0x4392b0
    cpu.esp -= 4;
    sub_4392b0(app, cpu);
    if (cpu.terminate) return;
    // 00453213  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00453215  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00453217  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00453219  745d                   -je 0x453278
    if (cpu.flags.zf)
    {
        goto L_0x00453278;
    }
    // 0045321b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0045321d  e89e63feff             -call 0x4395c0
    cpu.esp -= 4;
    sub_4395c0(app, cpu);
    if (cpu.terminate) return;
    // 00453222  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00453224  7424                   -je 0x45324a
    if (cpu.flags.zf)
    {
        goto L_0x0045324a;
    }
    // 00453226  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00453228  e86360feff             -call 0x439290
    cpu.esp -= 4;
    sub_439290(app, cpu);
    if (cpu.terminate) return;
    // 0045322d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0045322e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045322f  68b4287a00             -push 0x7a28b4
    app->getMemory<x86::reg32>(cpu.esp-4) = 8005812 /*0x7a28b4*/;
    cpu.esp -= 4;
    // 00453234  68bc965300             -push 0x5396bc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5478076 /*0x5396bc*/;
    cpu.esp -= 4;
    // 00453239  8d8500ffffff           -lea eax, [ebp - 0x100]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-256) /* -0x100 */);
    // 0045323f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00453240  e84bc40800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00453245  83c414                 +add esp, 0x14
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(20 /*0x14*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00453248  eb1a                   -jmp 0x453264
    goto L_0x00453264;
L_0x0045324a:
    // 0045324a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0045324b  6834327a00             -push 0x7a3234
    app->getMemory<x86::reg32>(cpu.esp-4) = 8008244 /*0x7a3234*/;
    cpu.esp -= 4;
    // 00453250  68cc965300             -push 0x5396cc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5478092 /*0x5396cc*/;
    cpu.esp -= 4;
    // 00453255  8d8500ffffff           -lea eax, [ebp - 0x100]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-256) /* -0x100 */);
    // 0045325b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0045325c  e82fc40800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00453261  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x00453264:
    // 00453264  8d8500ffffff           -lea eax, [ebp - 0x100]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-256) /* -0x100 */);
    // 0045326a  e8f1db0800             -call 0x4e0e60
    cpu.esp -= 4;
    sub_4e0e60(app, cpu);
    if (cpu.terminate) return;
    // 0045326f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00453271  7405                   -je 0x453278
    if (cpu.flags.zf)
    {
        goto L_0x00453278;
    }
    // 00453273  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
L_0x00453278:
    // 00453278  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0045327a  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0045327c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045327d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045327e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045327f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453280  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_453290(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00453290  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00453291  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00453292  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00453293  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00453294  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00453296  81ec00010000           -sub esp, 0x100
    (cpu.esp) -= x86::reg32(x86::sreg32(256 /*0x100*/));
    // 0045329c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0045329e  e80d60feff             -call 0x4392b0
    cpu.esp -= 4;
    sub_4392b0(app, cpu);
    if (cpu.terminate) return;
    // 004532a3  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004532a5  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004532a7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004532a9  745d                   -je 0x453308
    if (cpu.flags.zf)
    {
        goto L_0x00453308;
    }
    // 004532ab  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004532ad  e80e63feff             -call 0x4395c0
    cpu.esp -= 4;
    sub_4395c0(app, cpu);
    if (cpu.terminate) return;
    // 004532b2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004532b4  7424                   -je 0x4532da
    if (cpu.flags.zf)
    {
        goto L_0x004532da;
    }
    // 004532b6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004532b8  e8d35ffeff             -call 0x439290
    cpu.esp -= 4;
    sub_439290(app, cpu);
    if (cpu.terminate) return;
    // 004532bd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004532be  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004532bf  68b4287a00             -push 0x7a28b4
    app->getMemory<x86::reg32>(cpu.esp-4) = 8005812 /*0x7a28b4*/;
    cpu.esp -= 4;
    // 004532c4  68dc965300             -push 0x5396dc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5478108 /*0x5396dc*/;
    cpu.esp -= 4;
    // 004532c9  8d8500ffffff           -lea eax, [ebp - 0x100]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-256) /* -0x100 */);
    // 004532cf  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004532d0  e8bbc30800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 004532d5  83c414                 +add esp, 0x14
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(20 /*0x14*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004532d8  eb1a                   -jmp 0x4532f4
    goto L_0x004532f4;
L_0x004532da:
    // 004532da  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004532db  6834327a00             -push 0x7a3234
    app->getMemory<x86::reg32>(cpu.esp-4) = 8008244 /*0x7a3234*/;
    cpu.esp -= 4;
    // 004532e0  68ec965300             -push 0x5396ec
    app->getMemory<x86::reg32>(cpu.esp-4) = 5478124 /*0x5396ec*/;
    cpu.esp -= 4;
    // 004532e5  8d8500ffffff           -lea eax, [ebp - 0x100]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-256) /* -0x100 */);
    // 004532eb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004532ec  e89fc30800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 004532f1  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x004532f4:
    // 004532f4  8d8500ffffff           -lea eax, [ebp - 0x100]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-256) /* -0x100 */);
    // 004532fa  e861db0800             -call 0x4e0e60
    cpu.esp -= 4;
    sub_4e0e60(app, cpu);
    if (cpu.terminate) return;
    // 004532ff  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00453301  7405                   -je 0x453308
    if (cpu.flags.zf)
    {
        goto L_0x00453308;
    }
    // 00453303  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
L_0x00453308:
    // 00453308  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0045330a  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0045330c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045330d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045330e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045330f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453310  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_453320(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00453320  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00453321  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00453322  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00453323  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00453324  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00453325  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00453326  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00453328  83ec54                 -sub esp, 0x54
    (cpu.esp) -= x86::reg32(x86::sreg32(84 /*0x54*/));
    // 0045332b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0045332d  a194476600             -mov eax, dword ptr [0x664794]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6702996) /* 0x664794 */);
    // 00453332  e8795ffeff             -call 0x4392b0
    cpu.esp -= 4;
    sub_4392b0(app, cpu);
    if (cpu.terminate) return;
    // 00453337  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00453339  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045333b  0f84ef000000           -je 0x453430
    if (cpu.flags.zf)
    {
        goto L_0x00453430;
    }
    // 00453341  a194476600             -mov eax, dword ptr [0x664794]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6702996) /* 0x664794 */);
    // 00453346  e87562feff             -call 0x4395c0
    cpu.esp -= 4;
    sub_4395c0(app, cpu);
    if (cpu.terminate) return;
    // 0045334b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045334d  7424                   -je 0x453373
    if (cpu.flags.zf)
    {
        goto L_0x00453373;
    }
    // 0045334f  a194476600             -mov eax, dword ptr [0x664794]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6702996) /* 0x664794 */);
    // 00453354  e8375ffeff             -call 0x439290
    cpu.esp -= 4;
    sub_439290(app, cpu);
    if (cpu.terminate) return;
    // 00453359  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0045335a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0045335b  68b4287a00             -push 0x7a28b4
    app->getMemory<x86::reg32>(cpu.esp-4) = 8005812 /*0x7a28b4*/;
    cpu.esp -= 4;
    // 00453360  6884965300             -push 0x539684
    app->getMemory<x86::reg32>(cpu.esp-4) = 5478020 /*0x539684*/;
    cpu.esp -= 4;
    // 00453365  8d45ac                 -lea eax, [ebp - 0x54]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-84) /* -0x54 */);
    // 00453368  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00453369  e822c30800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 0045336e  83c414                 +add esp, 0x14
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(20 /*0x14*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00453371  eb17                   -jmp 0x45338a
    goto L_0x0045338a;
L_0x00453373:
    // 00453373  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00453374  6834327a00             -push 0x7a3234
    app->getMemory<x86::reg32>(cpu.esp-4) = 8008244 /*0x7a3234*/;
    cpu.esp -= 4;
    // 00453379  6894965300             -push 0x539694
    app->getMemory<x86::reg32>(cpu.esp-4) = 5478036 /*0x539694*/;
    cpu.esp -= 4;
    // 0045337e  8d45ac                 -lea eax, [ebp - 0x54]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-84) /* -0x54 */);
    // 00453381  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00453382  e809c30800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00453387  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x0045338a:
    // 0045338a  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 0045338f  8d45ac                 -lea eax, [ebp - 0x54]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-84) /* -0x54 */);
    // 00453392  e859230400             -call 0x4956f0
    cpu.esp -= 4;
    sub_4956f0(app, cpu);
    if (cpu.terminate) return;
    // 00453397  baf8965300             -mov edx, 0x5396f8
    cpu.edx = 5478136 /*0x5396f8*/;
    // 0045339c  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0045339e  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004533a0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004533a2  e899f6feff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 004533a7  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004533a9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004533ab  7437                   -je 0x4533e4
    if (cpu.flags.zf)
    {
        goto L_0x004533e4;
    }
    // 004533ad  a17c955500             -mov eax, dword ptr [0x55957c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5608828) /* 0x55957c */);
    // 004533b2  40                     -inc eax
    (cpu.eax)++;
    // 004533b3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004533b4  6808975300             -push 0x539708
    app->getMemory<x86::reg32>(cpu.esp-4) = 5478152 /*0x539708*/;
    cpu.esp -= 4;
    // 004533b9  8d45ac                 -lea eax, [ebp - 0x54]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-84) /* -0x54 */);
    // 004533bc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004533bd  e8cec20800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 004533c2  8b4742                 -mov eax, dword ptr [edi + 0x42]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(66) /* 0x42 */);
    // 004533c5  8d55ac                 -lea edx, [ebp - 0x54]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-84) /* -0x54 */);
    // 004533c8  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004533cb  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004533ce  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004533d1  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004533d3  e808be0900             -call 0x4ef1e0
    cpu.esp -= 4;
    sub_4ef1e0(app, cpu);
    if (cpu.terminate) return;
    // 004533d8  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004533db  e8b02f0800             -call 0x4d6390
    cpu.esp -= 4;
    sub_4d6390(app, cpu);
    if (cpu.terminate) return;
    // 004533e0  66894744               -mov word ptr [edi + 0x44], ax
    app->getMemory<x86::reg16>(cpu.edi + x86::reg32(68) /* 0x44 */) = cpu.ax;
L_0x004533e4:
    // 004533e4  ba10975300             -mov edx, 0x539710
    cpu.edx = 5478160 /*0x539710*/;
    // 004533e9  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004533eb  e850f6feff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 004533f0  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004533f2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004533f4  7433                   -je 0x453429
    if (cpu.flags.zf)
    {
        goto L_0x00453429;
    }
    // 004533f6  a17c955500             -mov eax, dword ptr [0x55957c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5608828) /* 0x55957c */);
    // 004533fb  40                     -inc eax
    (cpu.eax)++;
    // 004533fc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004533fd  6820975300             -push 0x539720
    app->getMemory<x86::reg32>(cpu.esp-4) = 5478176 /*0x539720*/;
    cpu.esp -= 4;
    // 00453402  8d45ac                 -lea eax, [ebp - 0x54]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-84) /* -0x54 */);
    // 00453405  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00453406  8d55ac                 -lea edx, [ebp - 0x54]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-84) /* -0x54 */);
    // 00453409  e882c20800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 0045340e  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00453411  8b5942                 -mov ebx, dword ptr [ecx + 0x42]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(66) /* 0x42 */);
    // 00453414  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00453416  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 00453419  e8c2bd0900             -call 0x4ef1e0
    cpu.esp -= 4;
    sub_4ef1e0(app, cpu);
    if (cpu.terminate) return;
    // 0045341e  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00453420  e86b2f0800             -call 0x4d6390
    cpu.esp -= 4;
    sub_4d6390(app, cpu);
    if (cpu.terminate) return;
    // 00453425  66894144               -mov word ptr [ecx + 0x44], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(68) /* 0x44 */) = cpu.ax;
L_0x00453429:
    // 00453429  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0045342b  e860e40800             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
L_0x00453430:
    // 00453430  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00453432  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453433  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453434  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453435  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453436  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453437  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453438  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_453440(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00453440  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00453441  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00453442  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00453443  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00453445  833d7c95550000         +cmp dword ptr [0x55957c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5608828) /* 0x55957c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045344c  7413                   -je 0x453461
    if (cpu.flags.zf)
    {
        goto L_0x00453461;
    }
    // 0045344e  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00453453  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00453455  891d80955500           -mov dword ptr [0x559580], ebx
    app->getMemory<x86::reg32>(x86::reg32(5608832) /* 0x559580 */) = cpu.ebx;
    // 0045345b  890d7c955500           -mov dword ptr [0x55957c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5608828) /* 0x55957c */) = cpu.ecx;
L_0x00453461:
    // 00453461  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00453463  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453464  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453465  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453466  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_453470(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00453470  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00453471  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00453472  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00453474  833d7c95550001         +cmp dword ptr [0x55957c], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5608828) /* 0x55957c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045347b  7411                   -je 0x45348e
    if (cpu.flags.zf)
    {
        goto L_0x0045348e;
    }
    // 0045347d  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00453482  890d80955500           -mov dword ptr [0x559580], ecx
    app->getMemory<x86::reg32>(x86::reg32(5608832) /* 0x559580 */) = cpu.ecx;
    // 00453488  890d7c955500           -mov dword ptr [0x55957c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5608828) /* 0x55957c */) = cpu.ecx;
L_0x0045348e:
    // 0045348e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00453490  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453491  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453492  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4534a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004534a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004534a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004534a2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004534a3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004534a5  833d7c95550002         +cmp dword ptr [0x55957c], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5608828) /* 0x55957c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004534ac  7416                   -je 0x4534c4
    if (cpu.flags.zf)
    {
        goto L_0x004534c4;
    }
    // 004534ae  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004534b3  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 004534b8  891d80955500           -mov dword ptr [0x559580], ebx
    app->getMemory<x86::reg32>(x86::reg32(5608832) /* 0x559580 */) = cpu.ebx;
    // 004534be  890d7c955500           -mov dword ptr [0x55957c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5608828) /* 0x55957c */) = cpu.ecx;
L_0x004534c4:
    // 004534c4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004534c6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004534c7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004534c8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004534c9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_4534d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004534d0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004534d1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004534d2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004534d3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004534d5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004534d7  ba28975300             -mov edx, 0x539728
    cpu.edx = 5478184 /*0x539728*/;
    // 004534dc  e82fae0900             -call 0x4ee310
    cpu.esp -= 4;
    sub_4ee310(app, cpu);
    if (cpu.terminate) return;
    // 004534e1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004534e3  7416                   -je 0x4534fb
    if (cpu.flags.zf)
    {
        goto L_0x004534fb;
    }
    // 004534e5  ba30975300             -mov edx, 0x539730
    cpu.edx = 5478192 /*0x539730*/;
    // 004534ea  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004534ec  e81fae0900             -call 0x4ee310
    cpu.esp -= 4;
    sub_4ee310(app, cpu);
    if (cpu.terminate) return;
    // 004534f1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004534f3  7406                   -je 0x4534fb
    if (cpu.flags.zf)
    {
        goto L_0x004534fb;
    }
    // 004534f5  890d78955500           -mov dword ptr [0x559578], ecx
    app->getMemory<x86::reg32>(x86::reg32(5608824) /* 0x559578 */) = cpu.ecx;
L_0x004534fb:
    // 004534fb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004534fc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004534fd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004534fe  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_453500(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00453500  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00453501  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00453502  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00453503  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00453505  ba3c975300             -mov edx, 0x53973c
    cpu.edx = 5478204 /*0x53973c*/;
    // 0045350a  a178955500             -mov eax, dword ptr [0x559578]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5608824) /* 0x559578 */);
    // 0045350f  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 00453514  e8f7ad0900             -call 0x4ee310
    cpu.esp -= 4;
    sub_4ee310(app, cpu);
    if (cpu.terminate) return;
    // 00453519  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045351b  750b                   -jne 0x453528
    if (!cpu.flags.zf)
    {
        goto L_0x00453528;
    }
    // 0045351d  8b0dbcd26f00           -mov ecx, dword ptr [0x6fd2bc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(7328444) /* 0x6fd2bc */);
    // 00453523  e9a8000000             -jmp 0x4535d0
    goto L_0x004535d0;
L_0x00453528:
    // 00453528  ba44975300             -mov edx, 0x539744
    cpu.edx = 5478212 /*0x539744*/;
    // 0045352d  a178955500             -mov eax, dword ptr [0x559578]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5608824) /* 0x559578 */);
    // 00453532  e8d9ad0900             -call 0x4ee310
    cpu.esp -= 4;
    sub_4ee310(app, cpu);
    if (cpu.terminate) return;
    // 00453537  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00453539  7512                   -jne 0x45354d
    if (!cpu.flags.zf)
    {
        goto L_0x0045354d;
    }
    // 0045353b  8b0d28d36f00           -mov ecx, dword ptr [0x6fd328]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(7328552) /* 0x6fd328 */);
    // 00453541  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00453543  890da8955500           -mov dword ptr [0x5595a8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5608872) /* 0x5595a8 */) = cpu.ecx;
    // 00453549  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045354a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045354b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045354c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045354d:
    // 0045354d  ba4c975300             -mov edx, 0x53974c
    cpu.edx = 5478220 /*0x53974c*/;
    // 00453552  a178955500             -mov eax, dword ptr [0x559578]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5608824) /* 0x559578 */);
    // 00453557  e8b4ad0900             -call 0x4ee310
    cpu.esp -= 4;
    sub_4ee310(app, cpu);
    if (cpu.terminate) return;
    // 0045355c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045355e  752c                   -jne 0x45358c
    if (!cpu.flags.zf)
    {
        goto L_0x0045358c;
    }
    // 00453560  8b15d4d46f00           -mov edx, dword ptr [0x6fd4d4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(7328980) /* 0x6fd4d4 */);
    // 00453566  83fa03                 +cmp edx, 3
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
    // 00453569  7e0f                   -jle 0x45357a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0045357a;
    }
    // 0045356b  8d4afc                 -lea ecx, [edx - 4]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 0045356e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00453570  890da8955500           -mov dword ptr [0x5595a8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5608872) /* 0x5595a8 */) = cpu.ecx;
    // 00453576  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453577  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453578  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453579  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045357a:
    // 0045357a  8b0dbcd26f00           -mov ecx, dword ptr [0x6fd2bc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(7328444) /* 0x6fd2bc */);
    // 00453580  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00453582  890da8955500           -mov dword ptr [0x5595a8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5608872) /* 0x5595a8 */) = cpu.ecx;
    // 00453588  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453589  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045358a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045358b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0045358c:
    // 0045358c  ba58975300             -mov edx, 0x539758
    cpu.edx = 5478232 /*0x539758*/;
    // 00453591  a178955500             -mov eax, dword ptr [0x559578]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5608824) /* 0x559578 */);
    // 00453596  e875ad0900             -call 0x4ee310
    cpu.esp -= 4;
    sub_4ee310(app, cpu);
    if (cpu.terminate) return;
    // 0045359b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045359d  750c                   -jne 0x4535ab
    if (!cpu.flags.zf)
    {
        goto L_0x004535ab;
    }
    // 0045359f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004535a1  890da8955500           -mov dword ptr [0x5595a8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5608872) /* 0x5595a8 */) = cpu.ecx;
    // 004535a7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004535a8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004535a9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004535aa  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004535ab:
    // 004535ab  ba64975300             -mov edx, 0x539764
    cpu.edx = 5478244 /*0x539764*/;
    // 004535b0  a178955500             -mov eax, dword ptr [0x559578]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5608824) /* 0x559578 */);
    // 004535b5  e856ad0900             -call 0x4ee310
    cpu.esp -= 4;
    sub_4ee310(app, cpu);
    if (cpu.terminate) return;
    // 004535ba  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004535bc  750c                   -jne 0x4535ca
    if (!cpu.flags.zf)
    {
        goto L_0x004535ca;
    }
    // 004535be  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004535c0  890da8955500           -mov dword ptr [0x5595a8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5608872) /* 0x5595a8 */) = cpu.ecx;
    // 004535c6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004535c7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004535c8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004535c9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004535ca:
    // 004535ca  8b0da8955500           -mov ecx, dword ptr [0x5595a8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5608872) /* 0x5595a8 */);
L_0x004535d0:
    // 004535d0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004535d2  890da8955500           -mov dword ptr [0x5595a8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5608872) /* 0x5595a8 */) = cpu.ecx;
    // 004535d8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004535d9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004535da  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004535db  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_4535e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004535e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004535e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004535e2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004535e3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004535e4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004535e5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004535e6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004535e8  83ec50                 -sub esp, 0x50
    (cpu.esp) -= x86::reg32(x86::sreg32(80 /*0x50*/));
    // 004535eb  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004535ed  e86ecefbff             -call 0x410460
    cpu.esp -= 4;
    sub_410460(app, cpu);
    if (cpu.terminate) return;
    // 004535f2  e809ffffff             -call 0x453500
    cpu.esp -= 4;
    sub_453500(app, cpu);
    if (cpu.terminate) return;
    // 004535f7  83f8ff                 +cmp eax, -1
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
    // 004535fa  740a                   -je 0x453606
    if (cpu.flags.zf)
    {
        goto L_0x00453606;
    }
    // 004535fc  e8fffeffff             -call 0x453500
    cpu.esp -= 4;
    sub_453500(app, cpu);
    if (cpu.terminate) return;
    // 00453601  a394476600             -mov dword ptr [0x664794], eax
    app->getMemory<x86::reg32>(x86::reg32(6702996) /* 0x664794 */) = cpu.eax;
L_0x00453606:
    // 00453606  a194476600             -mov eax, dword ptr [0x664794]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6702996) /* 0x664794 */);
    // 0045360b  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00453610  e89b5cfeff             -call 0x4392b0
    cpu.esp -= 4;
    sub_4392b0(app, cpu);
    if (cpu.terminate) return;
    // 00453615  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00453617  a194476600             -mov eax, dword ptr [0x664794]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6702996) /* 0x664794 */);
    // 0045361c  891588955500           -mov dword ptr [0x559588], edx
    app->getMemory<x86::reg32>(x86::reg32(5608840) /* 0x559588 */) = cpu.edx;
    // 00453622  a398476600             -mov dword ptr [0x664798], eax
    app->getMemory<x86::reg32>(x86::reg32(6703000) /* 0x664798 */) = cpu.eax;
    // 00453627  a17c955500             -mov eax, dword ptr [0x55957c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5608828) /* 0x55957c */);
    // 0045362c  ba64975300             -mov edx, 0x539764
    cpu.edx = 5478244 /*0x539764*/;
    // 00453631  a384955500             -mov dword ptr [0x559584], eax
    app->getMemory<x86::reg32>(x86::reg32(5608836) /* 0x559584 */) = cpu.eax;
    // 00453636  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00453638  e803f4feff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0045363d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0045363f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00453641  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00453643  7421                   -je 0x453666
    if (cpu.flags.zf)
    {
        goto L_0x00453666;
    }
    // 00453645  a198476600             -mov eax, dword ptr [0x664798]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6703000) /* 0x664798 */);
    // 0045364a  e811fbffff             -call 0x453160
    cpu.esp -= 4;
    sub_453160(app, cpu);
    if (cpu.terminate) return;
    // 0045364f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00453651  740f                   -je 0x453662
    if (cpu.flags.zf)
    {
        goto L_0x00453662;
    }
    // 00453653  833de0227a0000         +cmp dword ptr [0x7a22e0], 0
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
    // 0045365a  7506                   -jne 0x453662
    if (!cpu.flags.zf)
    {
        goto L_0x00453662;
    }
    // 0045365c  806204fe               +and byte ptr [edx + 4], 0xfe
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4) /* 0x4 */) &= x86::reg8(x86::sreg8(254 /*0xfe*/))));
    // 00453660  eb04                   -jmp 0x453666
    goto L_0x00453666;
L_0x00453662:
    // 00453662  804e0401               -or byte ptr [esi + 4], 1
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x00453666:
    // 00453666  ba70975300             -mov edx, 0x539770
    cpu.edx = 5478256 /*0x539770*/;
    // 0045366b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045366d  e8cef3feff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00453672  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00453674  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00453676  7418                   -je 0x453690
    if (cpu.flags.zf)
    {
        goto L_0x00453690;
    }
    // 00453678  a198476600             -mov eax, dword ptr [0x664798]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6703000) /* 0x664798 */);
    // 0045367d  e87efbffff             -call 0x453200
    cpu.esp -= 4;
    sub_453200(app, cpu);
    if (cpu.terminate) return;
    // 00453682  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00453684  7406                   -je 0x45368c
    if (cpu.flags.zf)
    {
        goto L_0x0045368c;
    }
    // 00453686  806204fe               +and byte ptr [edx + 4], 0xfe
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4) /* 0x4 */) &= x86::reg8(x86::sreg8(254 /*0xfe*/))));
    // 0045368a  eb04                   -jmp 0x453690
    goto L_0x00453690;
L_0x0045368c:
    // 0045368c  804a0401               -or byte ptr [edx + 4], 1
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x00453690:
    // 00453690  ba78975300             -mov edx, 0x539778
    cpu.edx = 5478264 /*0x539778*/;
    // 00453695  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00453697  e8a4f3feff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0045369c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0045369e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004536a0  7418                   -je 0x4536ba
    if (cpu.flags.zf)
    {
        goto L_0x004536ba;
    }
    // 004536a2  a198476600             -mov eax, dword ptr [0x664798]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6703000) /* 0x664798 */);
    // 004536a7  e8e4fbffff             -call 0x453290
    cpu.esp -= 4;
    sub_453290(app, cpu);
    if (cpu.terminate) return;
    // 004536ac  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004536ae  7406                   -je 0x4536b6
    if (cpu.flags.zf)
    {
        goto L_0x004536b6;
    }
    // 004536b0  806204fe               +and byte ptr [edx + 4], 0xfe
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4) /* 0x4 */) &= x86::reg8(x86::sreg8(254 /*0xfe*/))));
    // 004536b4  eb04                   -jmp 0x4536ba
    goto L_0x004536ba;
L_0x004536b6:
    // 004536b6  804a0401               -or byte ptr [edx + 4], 1
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x004536ba:
    // 004536ba  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004536bc  0f84df000000           -je 0x4537a1
    if (cpu.flags.zf)
    {
        goto L_0x004537a1;
    }
    // 004536c2  a194476600             -mov eax, dword ptr [0x664794]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6702996) /* 0x664794 */);
    // 004536c7  e8f45efeff             -call 0x4395c0
    cpu.esp -= 4;
    sub_4395c0(app, cpu);
    if (cpu.terminate) return;
    // 004536cc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004536ce  7424                   -je 0x4536f4
    if (cpu.flags.zf)
    {
        goto L_0x004536f4;
    }
    // 004536d0  a194476600             -mov eax, dword ptr [0x664794]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6702996) /* 0x664794 */);
    // 004536d5  e8b65bfeff             -call 0x439290
    cpu.esp -= 4;
    sub_439290(app, cpu);
    if (cpu.terminate) return;
    // 004536da  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004536db  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004536dc  68b4287a00             -push 0x7a28b4
    app->getMemory<x86::reg32>(cpu.esp-4) = 8005812 /*0x7a28b4*/;
    cpu.esp -= 4;
    // 004536e1  6884965300             -push 0x539684
    app->getMemory<x86::reg32>(cpu.esp-4) = 5478020 /*0x539684*/;
    cpu.esp -= 4;
    // 004536e6  8d45b0                 -lea eax, [ebp - 0x50]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-80) /* -0x50 */);
    // 004536e9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004536ea  e8a1bf0800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 004536ef  83c414                 +add esp, 0x14
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(20 /*0x14*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004536f2  eb17                   -jmp 0x45370b
    goto L_0x0045370b;
L_0x004536f4:
    // 004536f4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004536f5  6834327a00             -push 0x7a3234
    app->getMemory<x86::reg32>(cpu.esp-4) = 8008244 /*0x7a3234*/;
    cpu.esp -= 4;
    // 004536fa  6894965300             -push 0x539694
    app->getMemory<x86::reg32>(cpu.esp-4) = 5478036 /*0x539694*/;
    cpu.esp -= 4;
    // 004536ff  8d45b0                 -lea eax, [ebp - 0x50]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-80) /* -0x50 */);
    // 00453702  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00453703  e888bf0800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00453708  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x0045370b:
    // 0045370b  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 00453710  8d45b0                 -lea eax, [ebp - 0x50]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-80) /* -0x50 */);
    // 00453713  e8d81f0400             -call 0x4956f0
    cpu.esp -= 4;
    sub_4956f0(app, cpu);
    if (cpu.terminate) return;
    // 00453718  baf8965300             -mov edx, 0x5396f8
    cpu.edx = 5478136 /*0x5396f8*/;
    // 0045371d  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0045371f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00453721  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00453723  e818f3feff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00453728  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0045372a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045372c  742d                   -je 0x45375b
    if (cpu.flags.zf)
    {
        goto L_0x0045375b;
    }
    // 0045372e  a17c955500             -mov eax, dword ptr [0x55957c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5608828) /* 0x55957c */);
    // 00453733  40                     -inc eax
    (cpu.eax)++;
    // 00453734  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00453735  6808975300             -push 0x539708
    app->getMemory<x86::reg32>(cpu.esp-4) = 5478152 /*0x539708*/;
    cpu.esp -= 4;
    // 0045373a  8d45b0                 -lea eax, [ebp - 0x50]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-80) /* -0x50 */);
    // 0045373d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0045373e  e84dbf0800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00453743  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00453746  8d55b0                 -lea edx, [ebp - 0x50]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-80) /* -0x50 */);
    // 00453749  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0045374b  e890ba0900             -call 0x4ef1e0
    cpu.esp -= 4;
    sub_4ef1e0(app, cpu);
    if (cpu.terminate) return;
    // 00453750  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00453752  e8392c0800             -call 0x4d6390
    cpu.esp -= 4;
    sub_4d6390(app, cpu);
    if (cpu.terminate) return;
    // 00453757  66894744               -mov word ptr [edi + 0x44], ax
    app->getMemory<x86::reg16>(cpu.edi + x86::reg32(68) /* 0x44 */) = cpu.ax;
L_0x0045375b:
    // 0045375b  ba10975300             -mov edx, 0x539710
    cpu.edx = 5478160 /*0x539710*/;
    // 00453760  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00453762  e8d9f2feff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00453767  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00453769  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045376b  742d                   -je 0x45379a
    if (cpu.flags.zf)
    {
        goto L_0x0045379a;
    }
    // 0045376d  a17c955500             -mov eax, dword ptr [0x55957c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5608828) /* 0x55957c */);
    // 00453772  40                     -inc eax
    (cpu.eax)++;
    // 00453773  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00453774  6820975300             -push 0x539720
    app->getMemory<x86::reg32>(cpu.esp-4) = 5478176 /*0x539720*/;
    cpu.esp -= 4;
    // 00453779  8d45b0                 -lea eax, [ebp - 0x50]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-80) /* -0x50 */);
    // 0045377c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0045377d  e80ebf0800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00453782  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00453785  8d55b0                 -lea edx, [ebp - 0x50]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-80) /* -0x50 */);
    // 00453788  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0045378a  e851ba0900             -call 0x4ef1e0
    cpu.esp -= 4;
    sub_4ef1e0(app, cpu);
    if (cpu.terminate) return;
    // 0045378f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00453791  e8fa2b0800             -call 0x4d6390
    cpu.esp -= 4;
    sub_4d6390(app, cpu);
    if (cpu.terminate) return;
    // 00453796  66894144               -mov word ptr [ecx + 0x44], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(68) /* 0x44 */) = cpu.ax;
L_0x0045379a:
    // 0045379a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0045379c  e8efe00800             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
L_0x004537a1:
    // 004537a1  ba32000000             -mov edx, 0x32
    cpu.edx = 50 /*0x32*/;
    // 004537a6  8b1d4cbb6f00           -mov ebx, dword ptr [0x6fbb4c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(7322444) /* 0x6fbb4c */);
    // 004537ac  a198476600             -mov eax, dword ptr [0x664798]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6703000) /* 0x664798 */);
    // 004537b1  e83a5e0700             -call 0x4c95f0
    cpu.esp -= 4;
    sub_4c95f0(app, cpu);
    if (cpu.terminate) return;
    // 004537b6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004537b8  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004537ba  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004537bb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004537bc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004537bd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004537be  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004537bf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004537c0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_4537d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004537d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004537d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004537d2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004537d3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004537d4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004537d5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004537d6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004537d8  8b0d7c955500           -mov ecx, dword ptr [0x55957c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5608828) /* 0x55957c */);
    // 004537de  8b1d84955500           -mov ebx, dword ptr [0x559584]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5608836) /* 0x559584 */);
    // 004537e4  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004537e6  39d9                   +cmp ecx, ebx
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
    // 004537e8  7411                   -je 0x4537fb
    if (cpu.flags.zf)
    {
        goto L_0x004537fb;
    }
    // 004537ea  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 004537ef  890d84955500           -mov dword ptr [0x559584], ecx
    app->getMemory<x86::reg32>(x86::reg32(5608836) /* 0x559584 */) = cpu.ecx;
    // 004537f5  893580955500           -mov dword ptr [0x559580], esi
    app->getMemory<x86::reg32>(x86::reg32(5608832) /* 0x559580 */) = cpu.esi;
L_0x004537fb:
    // 004537fb  8b3d94476600           -mov edi, dword ptr [0x664794]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(6702996) /* 0x664794 */);
    // 00453801  3b3d98476600           +cmp edi, dword ptr [0x664798]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6703000) /* 0x664798 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00453807  7407                   -je 0x453810
    if (cpu.flags.zf)
    {
        goto L_0x00453810;
    }
    // 00453809  ba09000000             -mov edx, 9
    cpu.edx = 9 /*0x9*/;
    // 0045380e  eb16                   -jmp 0x453826
    goto L_0x00453826;
L_0x00453810:
    // 00453810  833d8095550000         +cmp dword ptr [0x559580], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5608832) /* 0x559580 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00453817  740d                   -je 0x453826
    if (cpu.flags.zf)
    {
        goto L_0x00453826;
    }
    // 00453819  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0045381b  891d80955500           -mov dword ptr [0x559580], ebx
    app->getMemory<x86::reg32>(x86::reg32(5608832) /* 0x559580 */) = cpu.ebx;
    // 00453821  e8fafaffff             -call 0x453320
    cpu.esp -= 4;
    sub_453320(app, cpu);
    if (cpu.terminate) return;
L_0x00453826:
    // 00453826  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00453828  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453829  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045382a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045382b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045382c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045382d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045382e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_453830(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00453830  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00453831  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00453833  e8585c0700             -call 0x4c9490
    cpu.esp -= 4;
    sub_4c9490(app, cpu);
    if (cpu.terminate) return;
    // 00453838  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0045383a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045383b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_453840(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00453840  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00453841  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00453842  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00453844  8b1588955500           -mov edx, dword ptr [0x559588]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5608840) /* 0x559588 */);
    // 0045384a  42                     -inc edx
    (cpu.edx)++;
    // 0045384b  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 00453850  891588955500           -mov dword ptr [0x559588], edx
    app->getMemory<x86::reg32>(x86::reg32(5608840) /* 0x559588 */) = cpu.edx;
    // 00453856  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453857  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453858  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_453860(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00453860  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00453861  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00453862  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00453863  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00453864  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00453865  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00453867  81ec0c010000           -sub esp, 0x10c
    (cpu.esp) -= x86::reg32(x86::sreg32(268 /*0x10c*/));
    // 0045386d  a198476600             -mov eax, dword ptr [0x664798]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6703000) /* 0x664798 */);
    // 00453872  e8395afeff             -call 0x4392b0
    cpu.esp -= 4;
    sub_4392b0(app, cpu);
    if (cpu.terminate) return;
    // 00453877  8b0d88955500           -mov ecx, dword ptr [0x559588]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5608840) /* 0x559588 */);
    // 0045387d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0045387f  83f901                 +cmp ecx, 1
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
    // 00453882  7e0e                   -jle 0x453892
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00453892;
    }
    // 00453884  8d59ff                 -lea ebx, [ecx - 1]
    cpu.ebx = x86::reg32(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 00453887  891d88955500           -mov dword ptr [0x559588], ebx
    app->getMemory<x86::reg32>(x86::reg32(5608840) /* 0x559588 */) = cpu.ebx;
    // 0045388d  e99f000000             -jmp 0x453931
    goto L_0x00453931;
L_0x00453892:
    // 00453892  c7058895550014000000   -mov dword ptr [0x559588], 0x14
    app->getMemory<x86::reg32>(x86::reg32(5608840) /* 0x559588 */) = 20 /*0x14*/;
L_0x0045389c:
    // 0045389c  8b3d88955500           -mov edi, dword ptr [0x559588]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5608840) /* 0x559588 */);
    // 004538a2  4f                     -dec edi
    (cpu.edi)--;
    // 004538a3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004538a4  6880975300             -push 0x539780
    app->getMemory<x86::reg32>(cpu.esp-4) = 5478272 /*0x539780*/;
    cpu.esp -= 4;
    // 004538a9  8d45f4                 -lea eax, [ebp - 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004538ac  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004538ad  893d88955500           -mov dword ptr [0x559588], edi
    app->getMemory<x86::reg32>(x86::reg32(5608840) /* 0x559588 */) = cpu.edi;
    // 004538b3  e8d8bd0800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 004538b8  8a65f4                 -mov ah, byte ptr [ebp - 0xc]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004538bb  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004538be  80fc20                 +cmp ah, 0x20
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(32 /*0x20*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004538c1  7504                   -jne 0x4538c7
    if (!cpu.flags.zf)
    {
        goto L_0x004538c7;
    }
    // 004538c3  c645f430               -mov byte ptr [ebp - 0xc], 0x30
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-12) /* -0xc */) = 48 /*0x30*/;
L_0x004538c7:
    // 004538c7  a198476600             -mov eax, dword ptr [0x664798]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6703000) /* 0x664798 */);
    // 004538cc  e8ef5cfeff             -call 0x4395c0
    cpu.esp -= 4;
    sub_4395c0(app, cpu);
    if (cpu.terminate) return;
    // 004538d1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004538d3  742b                   -je 0x453900
    if (cpu.flags.zf)
    {
        goto L_0x00453900;
    }
    // 004538d5  8d45f4                 -lea eax, [ebp - 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004538d8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004538d9  a198476600             -mov eax, dword ptr [0x664798]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6703000) /* 0x664798 */);
    // 004538de  e8ad59feff             -call 0x439290
    cpu.esp -= 4;
    sub_439290(app, cpu);
    if (cpu.terminate) return;
    // 004538e3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004538e4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004538e5  68b4287a00             -push 0x7a28b4
    app->getMemory<x86::reg32>(cpu.esp-4) = 8005812 /*0x7a28b4*/;
    cpu.esp -= 4;
    // 004538ea  6884975300             -push 0x539784
    app->getMemory<x86::reg32>(cpu.esp-4) = 5478276 /*0x539784*/;
    cpu.esp -= 4;
    // 004538ef  8d85f4feffff           -lea eax, [ebp - 0x10c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-268) /* -0x10c */);
    // 004538f5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004538f6  e895bd0800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 004538fb  83c418                 +add esp, 0x18
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004538fe  eb1e                   -jmp 0x45391e
    goto L_0x0045391e;
L_0x00453900:
    // 00453900  8d45f4                 -lea eax, [ebp - 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00453903  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00453904  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00453905  6834327a00             -push 0x7a3234
    app->getMemory<x86::reg32>(cpu.esp-4) = 8008244 /*0x7a3234*/;
    cpu.esp -= 4;
    // 0045390a  6894975300             -push 0x539794
    app->getMemory<x86::reg32>(cpu.esp-4) = 5478292 /*0x539794*/;
    cpu.esp -= 4;
    // 0045390f  8d85f4feffff           -lea eax, [ebp - 0x10c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-268) /* -0x10c */);
    // 00453915  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00453916  e875bd0800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 0045391b  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
L_0x0045391e:
    // 0045391e  8d85f4feffff           -lea eax, [ebp - 0x10c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-268) /* -0x10c */);
    // 00453924  e837d50800             -call 0x4e0e60
    cpu.esp -= 4;
    sub_4e0e60(app, cpu);
    if (cpu.terminate) return;
    // 00453929  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045392b  0f846bffffff           -je 0x45389c
    if (cpu.flags.zf)
    {
        goto L_0x0045389c;
    }
L_0x00453931:
    // 00453931  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 00453936  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00453938  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453939  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045393a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045393b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045393c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045393d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_453940(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00453940  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00453941  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00453942  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00453943  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00453944  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00453945  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00453946  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00453948  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0045394b  e8a064ffff             -call 0x449df0
    cpu.esp -= 4;
    sub_449df0(app, cpu);
    if (cpu.terminate) return;
    // 00453950  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00453952  f605583a7a0002         +test byte ptr [0x7a3a58], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(8010328) /* 0x7a3a58 */) & 2 /*0x2*/));
    // 00453959  740f                   -je 0x45396a
    if (cpu.flags.zf)
    {
        goto L_0x0045396a;
    }
    // 0045395b  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00453960  b806000000             -mov eax, 6
    cpu.eax = 6 /*0x6*/;
    // 00453965  e896dffdff             -call 0x431900
    cpu.esp -= 4;
    sub_431900(app, cpu);
    if (cpu.terminate) return;
L_0x0045396a:
    // 0045396a  a17c955500             -mov eax, dword ptr [0x55957c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5608828) /* 0x55957c */);
    // 0045396f  83f801                 +cmp eax, 1
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
    // 00453972  7214                   -jb 0x453988
    if (cpu.flags.cf)
    {
        goto L_0x00453988;
    }
    // 00453974  0f86a7000000           -jbe 0x453a21
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00453a21;
    }
    // 0045397a  83f802                 +cmp eax, 2
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
    // 0045397d  0f84e2010000           -je 0x453b65
    if (cpu.flags.zf)
    {
        goto L_0x00453b65;
    }
    // 00453983  e967020000             -jmp 0x453bef
    goto L_0x00453bef;
L_0x00453988:
    // 00453988  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045398a  7409                   -je 0x453995
    if (cpu.flags.zf)
    {
        goto L_0x00453995;
    }
    // 0045398c  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0045398e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045398f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453990  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453991  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453992  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453993  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453994  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00453995:
    // 00453995  be9a000000             -mov esi, 0x9a
    cpu.esi = 154 /*0x9a*/;
    // 0045399a  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 0045399d  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0045399f  7407                   -je 0x4539a8
    if (cpu.flags.zf)
    {
        goto L_0x004539a8;
    }
    // 004539a1  b8964a0000             -mov eax, 0x4a96
    cpu.eax = 19094 /*0x4a96*/;
    // 004539a6  eb05                   -jmp 0x4539ad
    goto L_0x004539ad;
L_0x004539a8:
    // 004539a8  b8ffffff00             -mov eax, 0xffffff
    cpu.eax = 16777215 /*0xffffff*/;
L_0x004539ad:
    // 004539ad  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 004539b2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004539b3  bab4000000             -mov edx, 0xb4
    cpu.edx = 180 /*0xb4*/;
    // 004539b8  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004539bb  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004539bd  0560010000             -add eax, 0x160
    (cpu.eax) += x86::reg32(x86::sreg32(352 /*0x160*/));
    // 004539c2  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004539c4  e887de0700             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 004539c9  e8c2e7ffff             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
    // 004539ce  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004539d0  7407                   -je 0x4539d9
    if (cpu.flags.zf)
    {
        goto L_0x004539d9;
    }
    // 004539d2  b8964a0000             -mov eax, 0x4a96
    cpu.eax = 19094 /*0x4a96*/;
    // 004539d7  eb05                   -jmp 0x4539de
    goto L_0x004539de;
L_0x004539d9:
    // 004539d9  b8ffffff00             -mov eax, 0xffffff
    cpu.eax = 16777215 /*0xffffff*/;
L_0x004539de:
    // 004539de  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004539df  8b55f0                 -mov edx, dword ptr [ebp - 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004539e2  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 004539e7  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004539e9  a198476600             -mov eax, dword ptr [0x664798]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6703000) /* 0x664798 */);
    // 004539ee  83c203                 -add edx, 3
    (cpu.edx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004539f1  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004539f3  e8b860feff             -call 0x439ab0
    cpu.esp -= 4;
    sub_439ab0(app, cpu);
    if (cpu.terminate) return;
    // 004539f8  bad6010000             -mov edx, 0x1d6
    cpu.edx = 470 /*0x1d6*/;
    // 004539fd  e88ee7ffff             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
    // 00453a02  8b5df0                 -mov ebx, dword ptr [ebp - 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00453a05  43                     -inc ebx
    (cpu.ebx)++;
    // 00453a06  83c60f                 -add esi, 0xf
    (cpu.esi) += x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00453a09  895df0                 -mov dword ptr [ebp - 0x10], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.ebx;
    // 00453a0c  837df007               +cmp dword ptr [ebp - 0x10], 7
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00453a10  0f8dd9010000           -jge 0x453bef
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00453bef;
    }
    // 00453a16  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00453a18  748e                   -je 0x4539a8
    if (cpu.flags.zf)
    {
        goto L_0x004539a8;
    }
    // 00453a1a  b8964a0000             -mov eax, 0x4a96
    cpu.eax = 19094 /*0x4a96*/;
    // 00453a1f  eb8c                   -jmp 0x4539ad
    goto L_0x004539ad;
L_0x00453a21:
    // 00453a21  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00453a23  be9a000000             -mov esi, 0x9a
    cpu.esi = 154 /*0x9a*/;
    // 00453a28  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 00453a2b  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00453a2d  7407                   -je 0x453a36
    if (cpu.flags.zf)
    {
        goto L_0x00453a36;
    }
    // 00453a2f  b8964a0000             -mov eax, 0x4a96
    cpu.eax = 19094 /*0x4a96*/;
    // 00453a34  eb05                   -jmp 0x453a3b
    goto L_0x00453a3b;
L_0x00453a36:
    // 00453a36  b8ffffff00             -mov eax, 0xffffff
    cpu.eax = 16777215 /*0xffffff*/;
L_0x00453a3b:
    // 00453a3b  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 00453a40  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00453a41  bab4000000             -mov edx, 0xb4
    cpu.edx = 180 /*0xb4*/;
    // 00453a46  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00453a49  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00453a4b  0568010000             -add eax, 0x168
    (cpu.eax) += x86::reg32(x86::sreg32(360 /*0x168*/));
    // 00453a50  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00453a52  e8f9dd0700             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00453a57  e834e7ffff             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
    // 00453a5c  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00453a5e  7407                   -je 0x453a67
    if (cpu.flags.zf)
    {
        goto L_0x00453a67;
    }
    // 00453a60  b8964a0000             -mov eax, 0x4a96
    cpu.eax = 19094 /*0x4a96*/;
    // 00453a65  eb05                   -jmp 0x453a6c
    goto L_0x00453a6c;
L_0x00453a67:
    // 00453a67  b8ffffff00             -mov eax, 0xffffff
    cpu.eax = 16777215 /*0xffffff*/;
L_0x00453a6c:
    // 00453a6c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00453a6d  8b55f4                 -mov edx, dword ptr [ebp - 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00453a70  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 00453a75  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00453a77  a198476600             -mov eax, dword ptr [0x664798]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6703000) /* 0x664798 */);
    // 00453a7c  83c211                 -add edx, 0x11
    (cpu.edx) += x86::reg32(x86::sreg32(17 /*0x11*/));
    // 00453a7f  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00453a81  e82a60feff             -call 0x439ab0
    cpu.esp -= 4;
    sub_439ab0(app, cpu);
    if (cpu.terminate) return;
    // 00453a86  bad6010000             -mov edx, 0x1d6
    cpu.edx = 470 /*0x1d6*/;
    // 00453a8b  e800e7ffff             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
    // 00453a90  8b4df4                 -mov ecx, dword ptr [ebp - 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00453a93  41                     -inc ecx
    (cpu.ecx)++;
    // 00453a94  83c60f                 -add esi, 0xf
    (cpu.esi) += x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00453a97  894df4                 -mov dword ptr [ebp - 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ecx;
    // 00453a9a  837df403               +cmp dword ptr [ebp - 0xc], 3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00453a9e  7d0b                   -jge 0x453aab
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00453aab;
    }
    // 00453aa0  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00453aa2  7492                   -je 0x453a36
    if (cpu.flags.zf)
    {
        goto L_0x00453a36;
    }
    // 00453aa4  b8964a0000             -mov eax, 0x4a96
    cpu.eax = 19094 /*0x4a96*/;
    // 00453aa9  eb90                   -jmp 0x453a3b
    goto L_0x00453a3b;
L_0x00453aab:
    // 00453aab  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00453aad  7407                   -je 0x453ab6
    if (cpu.flags.zf)
    {
        goto L_0x00453ab6;
    }
    // 00453aaf  b8964a0000             -mov eax, 0x4a96
    cpu.eax = 19094 /*0x4a96*/;
    // 00453ab4  eb05                   -jmp 0x453abb
    goto L_0x00453abb;
L_0x00453ab6:
    // 00453ab6  b840e4ff00             -mov eax, 0xffe440
    cpu.eax = 16770112 /*0xffe440*/;
L_0x00453abb:
    // 00453abb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00453abc  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 00453ac1  baa2000000             -mov edx, 0xa2
    cpu.edx = 162 /*0xa2*/;
    // 00453ac6  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00453ac8  b86b010000             -mov eax, 0x16b
    cpu.eax = 363 /*0x16b*/;
    // 00453acd  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00453acf  e87cdd0700             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00453ad4  e8b7e6ffff             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
    // 00453ad9  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00453adb  83c60f                 -add esi, 0xf
    (cpu.esi) += x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00453ade  895df8                 -mov dword ptr [ebp - 8], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ebx;
    // 00453ae1  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00453ae3  7407                   -je 0x453aec
    if (cpu.flags.zf)
    {
        goto L_0x00453aec;
    }
    // 00453ae5  b8964a0000             -mov eax, 0x4a96
    cpu.eax = 19094 /*0x4a96*/;
    // 00453aea  eb05                   -jmp 0x453af1
    goto L_0x00453af1;
L_0x00453aec:
    // 00453aec  b8ffffff00             -mov eax, 0xffffff
    cpu.eax = 16777215 /*0xffffff*/;
L_0x00453af1:
    // 00453af1  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 00453af6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00453af7  bab4000000             -mov edx, 0xb4
    cpu.edx = 180 /*0xb4*/;
    // 00453afc  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00453aff  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00453b01  056c010000             -add eax, 0x16c
    (cpu.eax) += x86::reg32(x86::sreg32(364 /*0x16c*/));
    // 00453b06  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00453b08  e843dd0700             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00453b0d  e87ee6ffff             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
    // 00453b12  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00453b14  7407                   -je 0x453b1d
    if (cpu.flags.zf)
    {
        goto L_0x00453b1d;
    }
    // 00453b16  b8964a0000             -mov eax, 0x4a96
    cpu.eax = 19094 /*0x4a96*/;
    // 00453b1b  eb05                   -jmp 0x453b22
    goto L_0x00453b22;
L_0x00453b1d:
    // 00453b1d  b8ffffff00             -mov eax, 0xffffff
    cpu.eax = 16777215 /*0xffffff*/;
L_0x00453b22:
    // 00453b22  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00453b23  8b55f8                 -mov edx, dword ptr [ebp - 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00453b26  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 00453b2b  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00453b2d  a198476600             -mov eax, dword ptr [0x664798]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6703000) /* 0x664798 */);
    // 00453b32  83c214                 -add edx, 0x14
    (cpu.edx) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00453b35  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00453b37  e8745ffeff             -call 0x439ab0
    cpu.esp -= 4;
    sub_439ab0(app, cpu);
    if (cpu.terminate) return;
    // 00453b3c  bad6010000             -mov edx, 0x1d6
    cpu.edx = 470 /*0x1d6*/;
    // 00453b41  e84ae6ffff             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
    // 00453b46  8b55f8                 -mov edx, dword ptr [ebp - 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00453b49  42                     -inc edx
    (cpu.edx)++;
    // 00453b4a  83c60f                 -add esi, 0xf
    (cpu.esi) += x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00453b4d  8955f8                 -mov dword ptr [ebp - 8], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edx;
    // 00453b50  837df802               +cmp dword ptr [ebp - 8], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00453b54  0f8d95000000           -jge 0x453bef
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00453bef;
    }
    // 00453b5a  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00453b5c  748e                   -je 0x453aec
    if (cpu.flags.zf)
    {
        goto L_0x00453aec;
    }
    // 00453b5e  b8964a0000             -mov eax, 0x4a96
    cpu.eax = 19094 /*0x4a96*/;
    // 00453b63  eb8c                   -jmp 0x453af1
    goto L_0x00453af1;
L_0x00453b65:
    // 00453b65  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00453b67  be9a000000             -mov esi, 0x9a
    cpu.esi = 154 /*0x9a*/;
    // 00453b6c  894dfc                 -mov dword ptr [ebp - 4], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
    // 00453b6f  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00453b71  7407                   -je 0x453b7a
    if (cpu.flags.zf)
    {
        goto L_0x00453b7a;
    }
    // 00453b73  b8964a0000             -mov eax, 0x4a96
    cpu.eax = 19094 /*0x4a96*/;
    // 00453b78  eb05                   -jmp 0x453b7f
    goto L_0x00453b7f;
L_0x00453b7a:
    // 00453b7a  b8ffffff00             -mov eax, 0xffffff
    cpu.eax = 16777215 /*0xffffff*/;
L_0x00453b7f:
    // 00453b7f  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 00453b84  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00453b85  bab4000000             -mov edx, 0xb4
    cpu.edx = 180 /*0xb4*/;
    // 00453b8a  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00453b8d  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00453b8f  056f010000             -add eax, 0x16f
    (cpu.eax) += x86::reg32(x86::sreg32(367 /*0x16f*/));
    // 00453b94  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00453b96  e8b5dc0700             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00453b9b  e8f0e5ffff             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
    // 00453ba0  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00453ba2  7407                   -je 0x453bab
    if (cpu.flags.zf)
    {
        goto L_0x00453bab;
    }
    // 00453ba4  b8964a0000             -mov eax, 0x4a96
    cpu.eax = 19094 /*0x4a96*/;
    // 00453ba9  eb05                   -jmp 0x453bb0
    goto L_0x00453bb0;
L_0x00453bab:
    // 00453bab  b8ffffff00             -mov eax, 0xffffff
    cpu.eax = 16777215 /*0xffffff*/;
L_0x00453bb0:
    // 00453bb0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00453bb1  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00453bb4  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 00453bb9  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00453bbb  a198476600             -mov eax, dword ptr [0x664798]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6703000) /* 0x664798 */);
    // 00453bc0  83c20a                 -add edx, 0xa
    (cpu.edx) += x86::reg32(x86::sreg32(10 /*0xa*/));
    // 00453bc3  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00453bc5  e8e65efeff             -call 0x439ab0
    cpu.esp -= 4;
    sub_439ab0(app, cpu);
    if (cpu.terminate) return;
    // 00453bca  bad6010000             -mov edx, 0x1d6
    cpu.edx = 470 /*0x1d6*/;
    // 00453bcf  e8bce5ffff             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
    // 00453bd4  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00453bd7  40                     -inc eax
    (cpu.eax)++;
    // 00453bd8  83c60f                 -add esi, 0xf
    (cpu.esi) += x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00453bdb  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 00453bde  837dfc07               +cmp dword ptr [ebp - 4], 7
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00453be2  7d0b                   -jge 0x453bef
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00453bef;
    }
    // 00453be4  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00453be6  7492                   -je 0x453b7a
    if (cpu.flags.zf)
    {
        goto L_0x00453b7a;
    }
    // 00453be8  b8964a0000             -mov eax, 0x4a96
    cpu.eax = 19094 /*0x4a96*/;
    // 00453bed  eb90                   -jmp 0x453b7f
    goto L_0x00453b7f;
L_0x00453bef:
    // 00453bef  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00453bf1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453bf2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453bf3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453bf4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453bf5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453bf6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453bf7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_453c00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00453c00  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00453c01  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00453c02  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00453c03  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00453c04  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00453c05  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00453c06  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00453c08  83ec64                 -sub esp, 0x64
    (cpu.esp) -= x86::reg32(x86::sreg32(100 /*0x64*/));
    // 00453c0b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00453c0d  a198476600             -mov eax, dword ptr [0x664798]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6703000) /* 0x664798 */);
    // 00453c12  baa4975300             -mov edx, 0x5397a4
    cpu.edx = 5478308 /*0x5397a4*/;
    // 00453c17  e89456feff             -call 0x4392b0
    cpu.esp -= 4;
    sub_4392b0(app, cpu);
    if (cpu.terminate) return;
    // 00453c1c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00453c1e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00453c20  e81beefeff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00453c25  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00453c27  7407                   -je 0x453c30
    if (cpu.flags.zf)
    {
        goto L_0x00453c30;
    }
    // 00453c29  c7406440384500         -mov dword ptr [eax + 0x64], 0x453840
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(100) /* 0x64 */) = 4536384 /*0x453840*/;
L_0x00453c30:
    // 00453c30  bab0975300             -mov edx, 0x5397b0
    cpu.edx = 5478320 /*0x5397b0*/;
    // 00453c35  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00453c37  e804eefeff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00453c3c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00453c3e  7407                   -je 0x453c47
    if (cpu.flags.zf)
    {
        goto L_0x00453c47;
    }
    // 00453c40  c7406460384500         -mov dword ptr [eax + 0x64], 0x453860
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(100) /* 0x64 */) = 4536416 /*0x453860*/;
L_0x00453c47:
    // 00453c47  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00453c49  0f8488020000           -je 0x453ed7
    if (cpu.flags.zf)
    {
        goto L_0x00453ed7;
    }
    // 00453c4f  8b1588955500           -mov edx, dword ptr [0x559588]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5608840) /* 0x559588 */);
    // 00453c55  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00453c56  6880975300             -push 0x539780
    app->getMemory<x86::reg32>(cpu.esp-4) = 5478272 /*0x539780*/;
    cpu.esp -= 4;
    // 00453c5b  8d45ec                 -lea eax, [ebp - 0x14]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00453c5e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00453c5f  e82cba0800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00453c64  8a65ec                 -mov ah, byte ptr [ebp - 0x14]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00453c67  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00453c6a  80fc20                 +cmp ah, 0x20
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(32 /*0x20*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00453c6d  7504                   -jne 0x453c73
    if (!cpu.flags.zf)
    {
        goto L_0x00453c73;
    }
    // 00453c6f  c645ec30               -mov byte ptr [ebp - 0x14], 0x30
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = 48 /*0x30*/;
L_0x00453c73:
    // 00453c73  a198476600             -mov eax, dword ptr [0x664798]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6703000) /* 0x664798 */);
    // 00453c78  e84359feff             -call 0x4395c0
    cpu.esp -= 4;
    sub_4395c0(app, cpu);
    if (cpu.terminate) return;
    // 00453c7d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00453c7f  7428                   -je 0x453ca9
    if (cpu.flags.zf)
    {
        goto L_0x00453ca9;
    }
    // 00453c81  8d45ec                 -lea eax, [ebp - 0x14]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00453c84  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00453c85  a198476600             -mov eax, dword ptr [0x664798]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6703000) /* 0x664798 */);
    // 00453c8a  e80156feff             -call 0x439290
    cpu.esp -= 4;
    sub_439290(app, cpu);
    if (cpu.terminate) return;
    // 00453c8f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00453c90  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00453c91  68b4287a00             -push 0x7a28b4
    app->getMemory<x86::reg32>(cpu.esp-4) = 8005812 /*0x7a28b4*/;
    cpu.esp -= 4;
    // 00453c96  6884975300             -push 0x539784
    app->getMemory<x86::reg32>(cpu.esp-4) = 5478276 /*0x539784*/;
    cpu.esp -= 4;
    // 00453c9b  8d459c                 -lea eax, [ebp - 0x64]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-100) /* -0x64 */);
    // 00453c9e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00453c9f  e8ecb90800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00453ca4  83c418                 +add esp, 0x18
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00453ca7  eb1b                   -jmp 0x453cc4
    goto L_0x00453cc4;
L_0x00453ca9:
    // 00453ca9  8d45ec                 -lea eax, [ebp - 0x14]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00453cac  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00453cad  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00453cae  6834327a00             -push 0x7a3234
    app->getMemory<x86::reg32>(cpu.esp-4) = 8008244 /*0x7a3234*/;
    cpu.esp -= 4;
    // 00453cb3  6894975300             -push 0x539794
    app->getMemory<x86::reg32>(cpu.esp-4) = 5478292 /*0x539794*/;
    cpu.esp -= 4;
    // 00453cb8  8d459c                 -lea eax, [ebp - 0x64]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-100) /* -0x64 */);
    // 00453cbb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00453cbc  e8cfb90800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00453cc1  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
L_0x00453cc4:
    // 00453cc4  8d459c                 -lea eax, [ebp - 0x64]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-100) /* -0x64 */);
    // 00453cc7  e894d10800             -call 0x4e0e60
    cpu.esp -= 4;
    sub_4e0e60(app, cpu);
    if (cpu.terminate) return;
    // 00453ccc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00453cce  0f857a000000           -jne 0x453d4e
    if (!cpu.flags.zf)
    {
        goto L_0x00453d4e;
    }
    // 00453cd4  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00453cd9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00453cda  6880975300             -push 0x539780
    app->getMemory<x86::reg32>(cpu.esp-4) = 5478272 /*0x539780*/;
    cpu.esp -= 4;
    // 00453cdf  8d45ec                 -lea eax, [ebp - 0x14]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00453ce2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00453ce3  891d88955500           -mov dword ptr [0x559588], ebx
    app->getMemory<x86::reg32>(x86::reg32(5608840) /* 0x559588 */) = cpu.ebx;
    // 00453ce9  e8a2b90800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00453cee  8a75ec                 -mov dh, byte ptr [ebp - 0x14]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00453cf1  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00453cf4  80fe20                 +cmp dh, 0x20
    {
        x86::reg8 tmp1 = cpu.dh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(32 /*0x20*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00453cf7  7504                   -jne 0x453cfd
    if (!cpu.flags.zf)
    {
        goto L_0x00453cfd;
    }
    // 00453cf9  c645ec30               -mov byte ptr [ebp - 0x14], 0x30
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = 48 /*0x30*/;
L_0x00453cfd:
    // 00453cfd  a198476600             -mov eax, dword ptr [0x664798]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6703000) /* 0x664798 */);
    // 00453d02  e8b958feff             -call 0x4395c0
    cpu.esp -= 4;
    sub_4395c0(app, cpu);
    if (cpu.terminate) return;
    // 00453d07  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00453d09  7428                   -je 0x453d33
    if (cpu.flags.zf)
    {
        goto L_0x00453d33;
    }
    // 00453d0b  8d45ec                 -lea eax, [ebp - 0x14]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00453d0e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00453d0f  a198476600             -mov eax, dword ptr [0x664798]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6703000) /* 0x664798 */);
    // 00453d14  e87755feff             -call 0x439290
    cpu.esp -= 4;
    sub_439290(app, cpu);
    if (cpu.terminate) return;
    // 00453d19  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00453d1a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00453d1b  68b4287a00             -push 0x7a28b4
    app->getMemory<x86::reg32>(cpu.esp-4) = 8005812 /*0x7a28b4*/;
    cpu.esp -= 4;
    // 00453d20  6884975300             -push 0x539784
    app->getMemory<x86::reg32>(cpu.esp-4) = 5478276 /*0x539784*/;
    cpu.esp -= 4;
    // 00453d25  8d459c                 -lea eax, [ebp - 0x64]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-100) /* -0x64 */);
    // 00453d28  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00453d29  e862b90800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00453d2e  83c418                 +add esp, 0x18
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00453d31  eb1b                   -jmp 0x453d4e
    goto L_0x00453d4e;
L_0x00453d33:
    // 00453d33  8d45ec                 -lea eax, [ebp - 0x14]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00453d36  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00453d37  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00453d38  6834327a00             -push 0x7a3234
    app->getMemory<x86::reg32>(cpu.esp-4) = 8008244 /*0x7a3234*/;
    cpu.esp -= 4;
    // 00453d3d  6894975300             -push 0x539794
    app->getMemory<x86::reg32>(cpu.esp-4) = 5478292 /*0x539794*/;
    cpu.esp -= 4;
    // 00453d42  8d459c                 -lea eax, [ebp - 0x64]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-100) /* -0x64 */);
    // 00453d45  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00453d46  e845b90800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00453d4b  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
L_0x00453d4e:
    // 00453d4e  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 00453d53  8d459c                 -lea eax, [ebp - 0x64]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-100) /* -0x64 */);
    // 00453d56  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 00453d5b  e890190400             -call 0x4956f0
    cpu.esp -= 4;
    sub_4956f0(app, cpu);
    if (cpu.terminate) return;
    // 00453d60  babc975300             -mov edx, 0x5397bc
    cpu.edx = 5478332 /*0x5397bc*/;
    // 00453d65  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00453d67  e874b40900             -call 0x4ef1e0
    cpu.esp -= 4;
    sub_4ef1e0(app, cpu);
    if (cpu.terminate) return;
    // 00453d6c  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00453d6e  bae0010000             -mov edx, 0x1e0
    cpu.edx = 480 /*0x1e0*/;
    // 00453d73  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 00453d76  b880020000             -mov eax, 0x280
    cpu.eax = 640 /*0x280*/;
    // 00453d7b  e810b40900             -call 0x4ef190
    cpu.esp -= 4;
    sub_4ef190(app, cpu);
    if (cpu.terminate) return;
    // 00453d80  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 00453d83  e818700900             -call 0x4eada0
    cpu.esp -= 4;
    sub_4eada0(app, cpu);
    if (cpu.terminate) return;
    // 00453d88  803d1050560008         +cmp byte ptr [0x565010], 8
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5656592) /* 0x565010 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(8 /*0x8*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00453d8f  7507                   -jne 0x453d98
    if (!cpu.flags.zf)
    {
        goto L_0x00453d98;
    }
    // 00453d91  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
    // 00453d96  eb02                   -jmp 0x453d9a
    goto L_0x00453d9a;
L_0x00453d98:
    // 00453d98  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00453d9a:
    // 00453d9a  e811b40900             -call 0x4ef1b0
    cpu.esp -= 4;
    sub_4ef1b0(app, cpu);
    if (cpu.terminate) return;
    // 00453d9f  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00453da2  e869cc0900             -call 0x4f0a10
    cpu.esp -= 4;
    sub_4f0a10(app, cpu);
    if (cpu.terminate) return;
    // 00453da7  833d8895550001         +cmp dword ptr [0x559588], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5608840) /* 0x559588 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00453dae  0f8e92000000           -jle 0x453e46
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00453e46;
    }
    // 00453db4  68ad4121ff             -push 0xff2141ad
    app->getMemory<x86::reg32>(cpu.esp-4) = 4280369581 /*0xff2141ad*/;
    cpu.esp -= 4;
    // 00453db9  b903000000             -mov ecx, 3
    cpu.ecx = 3 /*0x3*/;
    // 00453dbe  bb80020000             -mov ebx, 0x280
    cpu.ebx = 640 /*0x280*/;
    // 00453dc3  ba39000000             -mov edx, 0x39
    cpu.edx = 57 /*0x39*/;
    // 00453dc8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00453dca  e8c1cc0900             -call 0x4f0a90
    cpu.esp -= 4;
    sub_4f0a90(app, cpu);
    if (cpu.terminate) return;
    // 00453dcf  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00453dd1  e8bada0800             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 00453dd6  6834327a00             -push 0x7a3234
    app->getMemory<x86::reg32>(cpu.esp-4) = 8008244 /*0x7a3234*/;
    cpu.esp -= 4;
    // 00453ddb  68c4975300             -push 0x5397c4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5478340 /*0x5397c4*/;
    cpu.esp -= 4;
    // 00453de0  8d459c                 -lea eax, [ebp - 0x64]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-100) /* -0x64 */);
    // 00453de3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00453de4  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 00453de9  e8a2b80800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00453dee  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00453df1  8d459c                 -lea eax, [ebp - 0x64]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-100) /* -0x64 */);
    // 00453df4  bb82010000             -mov ebx, 0x182
    cpu.ebx = 386 /*0x182*/;
    // 00453df9  e8f2180400             -call 0x4956f0
    cpu.esp -= 4;
    sub_4956f0(app, cpu);
    if (cpu.terminate) return;
    // 00453dfe  bad0975300             -mov edx, 0x5397d0
    cpu.edx = 5478352 /*0x5397d0*/;
    // 00453e03  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00453e05  e8d6b30900             -call 0x4ef1e0
    cpu.esp -= 4;
    sub_4ef1e0(app, cpu);
    if (cpu.terminate) return;
    // 00453e0a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00453e0c  e8afcb0900             -call 0x4f09c0
    cpu.esp -= 4;
    sub_4f09c0(app, cpu);
    if (cpu.terminate) return;
    // 00453e11  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00453e13  bad8975300             -mov edx, 0x5397d8
    cpu.edx = 5478360 /*0x5397d8*/;
    // 00453e18  e873da0800             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 00453e1d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00453e1f  e81cecfeff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00453e24  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00453e26  7406                   -je 0x453e2e
    if (cpu.flags.zf)
    {
        goto L_0x00453e2e;
    }
    // 00453e28  66c740440000           -mov word ptr [eax + 0x44], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(68) /* 0x44 */) = 0 /*0x0*/;
L_0x00453e2e:
    // 00453e2e  bae0975300             -mov edx, 0x5397e0
    cpu.edx = 5478368 /*0x5397e0*/;
    // 00453e33  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00453e35  e806ecfeff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00453e3a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00453e3c  7469                   -je 0x453ea7
    if (cpu.flags.zf)
    {
        goto L_0x00453ea7;
    }
    // 00453e3e  66c740440000           -mov word ptr [eax + 0x44], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(68) /* 0x44 */) = 0 /*0x0*/;
    // 00453e44  eb61                   -jmp 0x453ea7
    goto L_0x00453ea7;
L_0x00453e46:
    // 00453e46  bad8975300             -mov edx, 0x5397d8
    cpu.edx = 5478360 /*0x5397d8*/;
    // 00453e4b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00453e4d  e8eeebfeff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00453e52  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00453e54  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00453e56  741b                   -je 0x453e73
    if (cpu.flags.zf)
    {
        goto L_0x00453e73;
    }
    // 00453e58  bad8975300             -mov edx, 0x5397d8
    cpu.edx = 5478360 /*0x5397d8*/;
    // 00453e5d  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00453e5f  e87cb30900             -call 0x4ef1e0
    cpu.esp -= 4;
    sub_4ef1e0(app, cpu);
    if (cpu.terminate) return;
    // 00453e64  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00453e66  e825250800             -call 0x4d6390
    cpu.esp -= 4;
    sub_4d6390(app, cpu);
    if (cpu.terminate) return;
    // 00453e6b  66894144               -mov word ptr [ecx + 0x44], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(68) /* 0x44 */) = cpu.ax;
    // 00453e6f  806105ef               -and byte ptr [ecx + 5], 0xef
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5) /* 0x5 */) &= x86::reg8(x86::sreg8(239 /*0xef*/));
L_0x00453e73:
    // 00453e73  bae0975300             -mov edx, 0x5397e0
    cpu.edx = 5478368 /*0x5397e0*/;
    // 00453e78  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00453e7a  e8c1ebfeff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00453e7f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00453e81  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00453e83  741b                   -je 0x453ea0
    if (cpu.flags.zf)
    {
        goto L_0x00453ea0;
    }
    // 00453e85  bae8975300             -mov edx, 0x5397e8
    cpu.edx = 5478376 /*0x5397e8*/;
    // 00453e8a  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00453e8c  e84fb30900             -call 0x4ef1e0
    cpu.esp -= 4;
    sub_4ef1e0(app, cpu);
    if (cpu.terminate) return;
    // 00453e91  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00453e93  e8f8240800             -call 0x4d6390
    cpu.esp -= 4;
    sub_4d6390(app, cpu);
    if (cpu.terminate) return;
    // 00453e98  66894144               -mov word ptr [ecx + 0x44], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(68) /* 0x44 */) = cpu.ax;
    // 00453e9c  80490510               -or byte ptr [ecx + 5], 0x10
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5) /* 0x5 */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
L_0x00453ea0:
    // 00453ea0  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00453ea2  e8e9d90800             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
L_0x00453ea7:
    // 00453ea7  ba70975300             -mov edx, 0x539770
    cpu.edx = 5478256 /*0x539770*/;
    // 00453eac  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00453eae  e88debfeff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00453eb3  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00453eb5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00453eb7  7411                   -je 0x453eca
    if (cpu.flags.zf)
    {
        goto L_0x00453eca;
    }
    // 00453eb9  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00453ebc  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00453ebe  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 00453ec1  e8ca240800             -call 0x4d6390
    cpu.esp -= 4;
    sub_4d6390(app, cpu);
    if (cpu.terminate) return;
    // 00453ec6  66894144               -mov word ptr [ecx + 0x44], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(68) /* 0x44 */) = cpu.ax;
L_0x00453eca:
    // 00453eca  e8c16e0900             -call 0x4ead90
    cpu.esp -= 4;
    sub_4ead90(app, cpu);
    if (cpu.terminate) return;
    // 00453ecf  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00453ed2  e829c00900             -call 0x4eff00
    cpu.esp -= 4;
    sub_4eff00(app, cpu);
    if (cpu.terminate) return;
L_0x00453ed7:
    // 00453ed7  a1a4c17900             -mov eax, dword ptr [0x79c1a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7979428) /* 0x79c1a4 */);
    // 00453edc  a394955500             -mov dword ptr [0x559594], eax
    app->getMemory<x86::reg32>(x86::reg32(5608852) /* 0x559594 */) = cpu.eax;
    // 00453ee1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00453ee3  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00453ee5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453ee6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453ee7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453ee8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453ee9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453eea  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453eeb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_453ef0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00453ef0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00453ef1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00453ef2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00453ef3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00453ef4  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00453ef6  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00453ef8  a1a4c17900             -mov eax, dword ptr [0x79c1a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7979428) /* 0x79c1a4 */);
    // 00453efd  8b1594955500           -mov edx, dword ptr [0x559594]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5608852) /* 0x559594 */);
    // 00453f03  81c2c8000000           -add edx, 0xc8
    (cpu.edx) += x86::reg32(x86::sreg32(200 /*0xc8*/));
    // 00453f09  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00453f0b  39d0                   +cmp eax, edx
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
    // 00453f0d  7e32                   -jle 0x453f41
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00453f41;
    }
    // 00453f0f  bad8975300             -mov edx, 0x5397d8
    cpu.edx = 5478360 /*0x5397d8*/;
    // 00453f14  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00453f16  e825ebfeff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00453f1b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00453f1d  7404                   -je 0x453f23
    if (cpu.flags.zf)
    {
        goto L_0x00453f23;
    }
    // 00453f1f  80700510               -xor byte ptr [eax + 5], 0x10
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */) ^= x86::reg8(x86::sreg8(16 /*0x10*/));
L_0x00453f23:
    // 00453f23  bae0975300             -mov edx, 0x5397e0
    cpu.edx = 5478368 /*0x5397e0*/;
    // 00453f28  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00453f2a  e811ebfeff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00453f2f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00453f31  7404                   -je 0x453f37
    if (cpu.flags.zf)
    {
        goto L_0x00453f37;
    }
    // 00453f33  80700510               -xor byte ptr [eax + 5], 0x10
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */) ^= x86::reg8(x86::sreg8(16 /*0x10*/));
L_0x00453f37:
    // 00453f37  a1a4c17900             -mov eax, dword ptr [0x79c1a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7979428) /* 0x79c1a4 */);
    // 00453f3c  a394955500             -mov dword ptr [0x559594], eax
    app->getMemory<x86::reg32>(x86::reg32(5608852) /* 0x559594 */) = cpu.eax;
L_0x00453f41:
    // 00453f41  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00453f43  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453f44  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453f45  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453f46  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453f47  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_453f50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00453f50  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00453f51  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00453f53  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00453f55  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453f56  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_453f60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00453f60  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00453f61  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00453f62  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00453f63  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00453f64  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00453f65  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00453f66  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00453f68  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00453f6b  e8805effff             -call 0x449df0
    cpu.esp -= 4;
    sub_449df0(app, cpu);
    if (cpu.terminate) return;
    // 00453f70  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 00453f73  f605583a7a0002         +test byte ptr [0x7a3a58], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(8010328) /* 0x7a3a58 */) & 2 /*0x2*/));
    // 00453f7a  740f                   -je 0x453f8b
    if (cpu.flags.zf)
    {
        goto L_0x00453f8b;
    }
    // 00453f7c  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00453f81  b806000000             -mov eax, 6
    cpu.eax = 6 /*0x6*/;
    // 00453f86  e875d9fdff             -call 0x431900
    cpu.esp -= 4;
    sub_431900(app, cpu);
    if (cpu.terminate) return;
L_0x00453f8b:
    // 00453f8b  bf87000000             -mov edi, 0x87
    cpu.edi = 135 /*0x87*/;
    // 00453f90  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00453f92  837dfc00               +cmp dword ptr [ebp - 4], 0
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
    // 00453f96  7407                   -je 0x453f9f
    if (cpu.flags.zf)
    {
        goto L_0x00453f9f;
    }
    // 00453f98  b8964a0000             -mov eax, 0x4a96
    cpu.eax = 19094 /*0x4a96*/;
    // 00453f9d  eb14                   -jmp 0x453fb3
    goto L_0x00453fb3;
L_0x00453f9f:
    // 00453f9f  3b358c955500           +cmp esi, dword ptr [0x55958c]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5608844) /* 0x55958c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00453fa5  7507                   -jne 0x453fae
    if (!cpu.flags.zf)
    {
        goto L_0x00453fae;
    }
    // 00453fa7  b840e4ff00             -mov eax, 0xffe440
    cpu.eax = 16770112 /*0xffe440*/;
    // 00453fac  eb05                   -jmp 0x453fb3
    goto L_0x00453fb3;
L_0x00453fae:
    // 00453fae  b8ffffff00             -mov eax, 0xffffff
    cpu.eax = 16777215 /*0xffffff*/;
L_0x00453fb3:
    // 00453fb3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00453fb4  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 00453fb9  8d5617                 -lea edx, [esi + 0x17]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(23) /* 0x17 */);
    // 00453fbc  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00453fbe  a198476600             -mov eax, dword ptr [0x664798]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6703000) /* 0x664798 */);
    // 00453fc3  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00453fc5  e8e65afeff             -call 0x439ab0
    cpu.esp -= 4;
    sub_439ab0(app, cpu);
    if (cpu.terminate) return;
    // 00453fca  83c70f                 -add edi, 0xf
    (cpu.edi) += x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00453fcd  bad6010000             -mov edx, 0x1d6
    cpu.edx = 470 /*0x1d6*/;
    // 00453fd2  46                     -inc esi
    (cpu.esi)++;
    // 00453fd3  e8b8e1ffff             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
    // 00453fd8  83fe07                 +cmp esi, 7
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00453fdb  7d0d                   -jge 0x453fea
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00453fea;
    }
    // 00453fdd  837dfc00               +cmp dword ptr [ebp - 4], 0
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
    // 00453fe1  74bc                   -je 0x453f9f
    if (cpu.flags.zf)
    {
        goto L_0x00453f9f;
    }
    // 00453fe3  b8964a0000             -mov eax, 0x4a96
    cpu.eax = 19094 /*0x4a96*/;
    // 00453fe8  ebc9                   -jmp 0x453fb3
    goto L_0x00453fb3;
L_0x00453fea:
    // 00453fea  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00453fec  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453fed  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453fee  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453fef  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453ff0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453ff1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00453ff2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_454000(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00454000  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00454001  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00454002  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00454003  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00454004  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00454005  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00454007  81ec10010000           -sub esp, 0x110
    (cpu.esp) -= x86::reg32(x86::sreg32(272 /*0x110*/));
    // 0045400d  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0045400f  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 00454012  a198476600             -mov eax, dword ptr [0x664798]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6703000) /* 0x664798 */);
    // 00454017  e89452feff             -call 0x4392b0
    cpu.esp -= 4;
    sub_4392b0(app, cpu);
    if (cpu.terminate) return;
    // 0045401c  8b158c955500           -mov edx, dword ptr [0x55958c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5608844) /* 0x55958c */);
    // 00454022  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 00454025  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 00454028  a198476600             -mov eax, dword ptr [0x664798]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6703000) /* 0x664798 */);
    // 0045402d  83c217                 -add edx, 0x17
    (cpu.edx) += x86::reg32(x86::sreg32(23 /*0x17*/));
    // 00454030  e87b5afeff             -call 0x439ab0
    cpu.esp -= 4;
    sub_439ab0(app, cpu);
    if (cpu.terminate) return;
    // 00454035  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 00454038  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045403a  7406                   -je 0x454042
    if (cpu.flags.zf)
    {
        goto L_0x00454042;
    }
    // 0045403c  837df800               +cmp dword ptr [ebp - 8], 0
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
    // 00454040  7507                   -jne 0x454049
    if (!cpu.flags.zf)
    {
        goto L_0x00454049;
    }
L_0x00454042:
    // 00454042  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00454044  e9b9010000             -jmp 0x454202
    goto L_0x00454202;
L_0x00454049:
    // 00454049  bb05000000             -mov ebx, 5
    cpu.ebx = 5 /*0x5*/;
    // 0045404e  baf0975300             -mov edx, 0x5397f0
    cpu.edx = 5478384 /*0x5397f0*/;
    // 00454053  e838730900             -call 0x4eb390
    cpu.esp -= 4;
    sub_4eb390(app, cpu);
    if (cpu.terminate) return;
    // 00454058  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045405a  7508                   -jne 0x454064
    if (!cpu.flags.zf)
    {
        goto L_0x00454064;
    }
    // 0045405c  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0045405e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045405f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454060  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454061  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454062  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454063  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00454064:
    // 00454064  8b7df4                 -mov edi, dword ptr [ebp - 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00454067  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00454069  49                     -dec ecx
    (cpu.ecx)--;
    // 0045406a  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0045406c  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0045406e  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00454070  49                     -dec ecx
    (cpu.ecx)--;
    // 00454071  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00454073  83f904                 +cmp ecx, 4
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
    // 00454076  7d0a                   -jge 0x454082
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00454082;
    }
    // 00454078  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0045407a  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0045407c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045407d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045407e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045407f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454080  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454081  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00454082:
    // 00454082  8b5df4                 -mov ebx, dword ptr [ebp - 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00454085  8d0419                 -lea eax, [ecx + ebx]
    cpu.eax = x86::reg32(cpu.ecx + cpu.ebx * 1);
    // 00454088  8d78fe                 -lea edi, [eax - 2]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(-2) /* -0x2 */);
    // 0045408b  a198476600             -mov eax, dword ptr [0x664798]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6703000) /* 0x664798 */);
    // 00454090  e82b55feff             -call 0x4395c0
    cpu.esp -= 4;
    sub_4395c0(app, cpu);
    if (cpu.terminate) return;
    // 00454095  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00454097  742a                   -je 0x4540c3
    if (cpu.flags.zf)
    {
        goto L_0x004540c3;
    }
    // 00454099  a198476600             -mov eax, dword ptr [0x664798]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6703000) /* 0x664798 */);
    // 0045409e  e8ed51feff             -call 0x439290
    cpu.esp -= 4;
    sub_439290(app, cpu);
    if (cpu.terminate) return;
    // 004540a3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004540a4  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004540a7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004540a8  68b4287a00             -push 0x7a28b4
    app->getMemory<x86::reg32>(cpu.esp-4) = 8005812 /*0x7a28b4*/;
    cpu.esp -= 4;
    // 004540ad  68dc965300             -push 0x5396dc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5478108 /*0x5396dc*/;
    cpu.esp -= 4;
    // 004540b2  8d85f0feffff           -lea eax, [ebp - 0x110]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-272) /* -0x110 */);
    // 004540b8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004540b9  e8d2b50800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 004540be  83c414                 +add esp, 0x14
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(20 /*0x14*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004540c1  eb1d                   -jmp 0x4540e0
    goto L_0x004540e0;
L_0x004540c3:
    // 004540c3  8b55f8                 -mov edx, dword ptr [ebp - 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004540c6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004540c7  6834327a00             -push 0x7a3234
    app->getMemory<x86::reg32>(cpu.esp-4) = 8008244 /*0x7a3234*/;
    cpu.esp -= 4;
    // 004540cc  68ec965300             -push 0x5396ec
    app->getMemory<x86::reg32>(cpu.esp-4) = 5478124 /*0x5396ec*/;
    cpu.esp -= 4;
    // 004540d1  8d85f0feffff           -lea eax, [ebp - 0x110]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-272) /* -0x110 */);
    // 004540d7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004540d8  e8b3b50800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 004540dd  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x004540e0:
    // 004540e0  8d85f0feffff           -lea eax, [ebp - 0x110]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-272) /* -0x110 */);
    // 004540e6  e875cd0800             -call 0x4e0e60
    cpu.esp -= 4;
    sub_4e0e60(app, cpu);
    if (cpu.terminate) return;
    // 004540eb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004540ed  7508                   -jne 0x4540f7
    if (!cpu.flags.zf)
    {
        goto L_0x004540f7;
    }
    // 004540ef  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004540f1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004540f2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004540f3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004540f4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004540f5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004540f6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004540f7:
    // 004540f7  8d85f0feffff           -lea eax, [ebp - 0x110]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-272) /* -0x110 */);
    // 004540fd  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004540ff  e8ec150400             -call 0x4956f0
    cpu.esp -= 4;
    sub_4956f0(app, cpu);
    if (cpu.terminate) return;
    // 00454104  baf8975300             -mov edx, 0x5397f8
    cpu.edx = 5478392 /*0x5397f8*/;
    // 00454109  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0045410b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0045410d  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00454110  e8fba10900             -call 0x4ee310
    cpu.esp -= 4;
    sub_4ee310(app, cpu);
    if (cpu.terminate) return;
    // 00454115  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00454117  7523                   -jne 0x45413c
    if (!cpu.flags.zf)
    {
        goto L_0x0045413c;
    }
    // 00454119  833d8c95550003         +cmp dword ptr [0x55958c], 3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5608844) /* 0x55958c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00454120  751a                   -jne 0x45413c
    if (!cpu.flags.zf)
    {
        goto L_0x0045413c;
    }
    // 00454122  ba00985300             -mov edx, 0x539800
    cpu.edx = 5478400 /*0x539800*/;
    // 00454127  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00454129  e842b10900             -call 0x4ef270
    cpu.esp -= 4;
    sub_4ef270(app, cpu);
    if (cpu.terminate) return;
    // 0045412e  ba08985300             -mov edx, 0x539808
    cpu.edx = 5478408 /*0x539808*/;
    // 00454133  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 00454135  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00454137  e970000000             -jmp 0x4541ac
    goto L_0x004541ac;
L_0x0045413c:
    // 0045413c  baf8975300             -mov edx, 0x5397f8
    cpu.edx = 5478392 /*0x5397f8*/;
    // 00454141  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00454144  e8c7a10900             -call 0x4ee310
    cpu.esp -= 4;
    sub_4ee310(app, cpu);
    if (cpu.terminate) return;
    // 00454149  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045414b  751e                   -jne 0x45416b
    if (!cpu.flags.zf)
    {
        goto L_0x0045416b;
    }
    // 0045414d  833d8c95550004         +cmp dword ptr [0x55958c], 4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5608844) /* 0x55958c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00454154  7515                   -jne 0x45416b
    if (!cpu.flags.zf)
    {
        goto L_0x0045416b;
    }
    // 00454156  ba10985300             -mov edx, 0x539810
    cpu.edx = 5478416 /*0x539810*/;
    // 0045415b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045415d  e80eb10900             -call 0x4ef270
    cpu.esp -= 4;
    sub_4ef270(app, cpu);
    if (cpu.terminate) return;
    // 00454162  ba18985300             -mov edx, 0x539818
    cpu.edx = 5478424 /*0x539818*/;
    // 00454167  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 00454169  eb3f                   -jmp 0x4541aa
    goto L_0x004541aa;
L_0x0045416b:
    // 0045416b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045416c  6820985300             -push 0x539820
    app->getMemory<x86::reg32>(cpu.esp-4) = 5478432 /*0x539820*/;
    cpu.esp -= 4;
    // 00454171  8d85f0feffff           -lea eax, [ebp - 0x110]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-272) /* -0x110 */);
    // 00454177  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00454178  e813b50800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 0045417d  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00454180  8d95f0feffff           -lea edx, [ebp - 0x110]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-272) /* -0x110 */);
    // 00454186  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00454188  e8e3b00900             -call 0x4ef270
    cpu.esp -= 4;
    sub_4ef270(app, cpu);
    if (cpu.terminate) return;
    // 0045418d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0045418e  6828985300             -push 0x539828
    app->getMemory<x86::reg32>(cpu.esp-4) = 5478440 /*0x539828*/;
    cpu.esp -= 4;
    // 00454193  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 00454195  8d85f0feffff           -lea eax, [ebp - 0x110]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-272) /* -0x110 */);
    // 0045419b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0045419c  e8efb40800             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 004541a1  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004541a4  8d95f0feffff           -lea edx, [ebp - 0x110]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-272) /* -0x110 */);
L_0x004541aa:
    // 004541aa  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x004541ac:
    // 004541ac  e8bfb00900             -call 0x4ef270
    cpu.esp -= 4;
    sub_4ef270(app, cpu);
    if (cpu.terminate) return;
    // 004541b1  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004541b4  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004541b6  833e00                 +cmp dword ptr [esi], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004541b9  7408                   -je 0x4541c3
    if (cpu.flags.zf)
    {
        goto L_0x004541c3;
    }
    // 004541bb  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004541be  833800                 +cmp dword ptr [eax], 0
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
    // 004541c1  751f                   -jne 0x4541e2
    if (!cpu.flags.zf)
    {
        goto L_0x004541e2;
    }
L_0x004541c3:
    // 004541c3  babc975300             -mov edx, 0x5397bc
    cpu.edx = 5478332 /*0x5397bc*/;
    // 004541c8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004541ca  e8a1b00900             -call 0x4ef270
    cpu.esp -= 4;
    sub_4ef270(app, cpu);
    if (cpu.terminate) return;
    // 004541cf  ba30985300             -mov edx, 0x539830
    cpu.edx = 5478448 /*0x539830*/;
    // 004541d4  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 004541d6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004541d8  e893b00900             -call 0x4ef270
    cpu.esp -= 4;
    sub_4ef270(app, cpu);
    if (cpu.terminate) return;
    // 004541dd  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004541e0  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
L_0x004541e2:
    // 004541e2  833e00                 +cmp dword ptr [esi], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004541e5  7408                   -je 0x4541ef
    if (cpu.flags.zf)
    {
        goto L_0x004541ef;
    }
    // 004541e7  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004541ea  833800                 +cmp dword ptr [eax], 0
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
    // 004541ed  7511                   -jne 0x454200
    if (!cpu.flags.zf)
    {
        goto L_0x00454200;
    }
L_0x004541ef:
    // 004541ef  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004541f1  e89ad60800             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 004541f6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004541f8  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004541fa  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004541fb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004541fc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004541fd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004541fe  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004541ff  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00454200:
    // 00454200  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x00454202:
    // 00454202  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00454204  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454205  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454206  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454207  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454208  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454209  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_454210(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00454210  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00454211  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00454212  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00454213  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00454214  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00454216  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00454218  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0045421a  8b358c955500           -mov esi, dword ptr [0x55958c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5608844) /* 0x55958c */);
L_0x00454220:
    // 00454220  e8dbfdffff             -call 0x454000
    cpu.esp -= 4;
    sub_454000(app, cpu);
    if (cpu.terminate) return;
    // 00454225  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00454227  7531                   -jne 0x45425a
    if (!cpu.flags.zf)
    {
        goto L_0x0045425a;
    }
    // 00454229  8b158c955500           -mov edx, dword ptr [0x55958c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5608844) /* 0x55958c */);
    // 0045422f  42                     -inc edx
    (cpu.edx)++;
    // 00454230  89158c955500           -mov dword ptr [0x55958c], edx
    app->getMemory<x86::reg32>(x86::reg32(5608844) /* 0x55958c */) = cpu.edx;
    // 00454236  83fa06                 +cmp edx, 6
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
    // 00454239  7e0a                   -jle 0x454245
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00454245;
    }
    // 0045423b  c7058c95550001000000   -mov dword ptr [0x55958c], 1
    app->getMemory<x86::reg32>(x86::reg32(5608844) /* 0x55958c */) = 1 /*0x1*/;
L_0x00454245:
    // 00454245  3b358c955500           +cmp esi, dword ptr [0x55958c]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5608844) /* 0x55958c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0045424b  7507                   -jne 0x454254
    if (!cpu.flags.zf)
    {
        goto L_0x00454254;
    }
    // 0045424d  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0045424f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454250  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454251  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454252  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454253  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00454254:
    // 00454254  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00454256  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00454258  ebc6                   -jmp 0x454220
    goto L_0x00454220;
L_0x0045425a:
    // 0045425a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045425b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045425c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045425d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0045425e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_454260(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00454260  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00454261  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00454262  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00454263  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00454264  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00454265  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00454267  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0045426a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0045426c  a194476600             -mov eax, dword ptr [0x664794]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6702996) /* 0x664794 */);
    // 00454271  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00454276  a398476600             -mov dword ptr [0x664798], eax
    app->getMemory<x86::reg32>(x86::reg32(6703000) /* 0x664798 */) = cpu.eax;
    // 0045427b  89158c955500           -mov dword ptr [0x55958c], edx
    app->getMemory<x86::reg32>(x86::reg32(5608844) /* 0x55958c */) = cpu.edx;
    // 00454281  8d55fc                 -lea edx, [ebp - 4]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00454284  8d45f8                 -lea eax, [ebp - 8]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00454287  e884ffffff             -call 0x454210
    cpu.esp -= 4;
    sub_454210(app, cpu);
    if (cpu.terminate) return;
    // 0045428c  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0045428e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00454290  7447                   -je 0x4542d9
    if (cpu.flags.zf)
    {
        goto L_0x004542d9;
    }
    // 00454292  ba38985300             -mov edx, 0x539838
    cpu.edx = 5478456 /*0x539838*/;
    // 00454297  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00454299  e8a2e7feff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0045429e  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004542a0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004542a2  740e                   -je 0x4542b2
    if (cpu.flags.zf)
    {
        goto L_0x004542b2;
    }
    // 004542a4  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004542a7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004542a9  e8e2200800             -call 0x4d6390
    cpu.esp -= 4;
    sub_4d6390(app, cpu);
    if (cpu.terminate) return;
    // 004542ae  66894344               -mov word ptr [ebx + 0x44], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(68) /* 0x44 */) = cpu.ax;
L_0x004542b2:
    // 004542b2  ba44985300             -mov edx, 0x539844
    cpu.edx = 5478468 /*0x539844*/;
    // 004542b7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004542b9  e882e7feff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 004542be  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004542c0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004542c2  740e                   -je 0x4542d2
    if (cpu.flags.zf)
    {
        goto L_0x004542d2;
    }
    // 004542c4  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004542c7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004542c9  e8c2200800             -call 0x4d6390
    cpu.esp -= 4;
    sub_4d6390(app, cpu);
    if (cpu.terminate) return;
    // 004542ce  66894144               -mov word ptr [ecx + 0x44], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(68) /* 0x44 */) = cpu.ax;
L_0x004542d2:
    // 004542d2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004542d4  e8b7d50800             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
L_0x004542d9:
    // 004542d9  a1a4c17900             -mov eax, dword ptr [0x79c1a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7979428) /* 0x79c1a4 */);
    // 004542de  ba34000000             -mov edx, 0x34
    cpu.edx = 52 /*0x34*/;
    // 004542e3  8b1d4cbb6f00           -mov ebx, dword ptr [0x6fbb4c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(7322444) /* 0x6fbb4c */);
    // 004542e9  a390955500             -mov dword ptr [0x559590], eax
    app->getMemory<x86::reg32>(x86::reg32(5608848) /* 0x559590 */) = cpu.eax;
    // 004542ee  a198476600             -mov eax, dword ptr [0x664798]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6703000) /* 0x664798 */);
    // 004542f3  e8f8520700             -call 0x4c95f0
    cpu.esp -= 4;
    sub_4c95f0(app, cpu);
    if (cpu.terminate) return;
    // 004542f8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004542fa  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004542fc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004542fd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004542fe  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004542ff  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454300  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00454301  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_454310(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00454310  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00454311  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00454312  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00454313  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00454314  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00454315  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00454316  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00454318  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0045431b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0045431d  a198476600             -mov eax, dword ptr [0x664798]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6703000) /* 0x664798 */);
    // 00454322  8b1594476600           -mov edx, dword ptr [0x664794]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6702996) /* 0x664794 */);
    // 00454328  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0045432a  39d0                   +cmp eax, edx
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
    // 0045432c  740a                   -je 0x454338
    if (cpu.flags.zf)
    {
        goto L_0x00454338;
    }
    // 0045432e  be09000000             -mov esi, 9
    cpu.esi = 9 /*0x9*/;
    // 00454333  e990000000             -jmp 0x4543c8
    goto L_0x004543c8;
L_0x00454338:
    // 00454338  a1a4c17900             -mov eax, dword ptr [0x79c1a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7979428) /* 0x79c1a4 */);
    // 0045433d  8b1590955500           -mov edx, dword ptr [0x559590]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5608848) /* 0x559590 */);
    // 00454343  81c258020000           -add edx, 0x258
    (cpu.edx) += x86::reg32(x86::sreg32(600 /*0x258*/));
    // 00454349  39d0                   +cmp eax, edx
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
    // 0045434b  0f8e77000000           -jle 0x4543c8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004543c8;
    }
    // 00454351  8b1d8c955500           -mov ebx, dword ptr [0x55958c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5608844) /* 0x55958c */);
    // 00454357  8d55fc                 -lea edx, [ebp - 4]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0045435a  43                     -inc ebx
    (cpu.ebx)++;
    // 0045435b  8d45f8                 -lea eax, [ebp - 8]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0045435e  891d8c955500           -mov dword ptr [0x55958c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5608844) /* 0x55958c */) = cpu.ebx;
    // 00454364  e8a7feffff             -call 0x454210
    cpu.esp -= 4;
    sub_454210(app, cpu);
    if (cpu.terminate) return;
    // 00454369  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0045436b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045436d  744f                   -je 0x4543be
    if (cpu.flags.zf)
    {
        goto L_0x004543be;
    }
    // 0045436f  ba38985300             -mov edx, 0x539838
    cpu.edx = 5478456 /*0x539838*/;
    // 00454374  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00454376  e8c5e6feff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0045437b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0045437d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0045437f  7412                   -je 0x454393
    if (cpu.flags.zf)
    {
        goto L_0x00454393;
    }
    // 00454381  8b5042                 -mov edx, dword ptr [eax + 0x42]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(66) /* 0x42 */);
    // 00454384  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00454387  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0045438a  e801200800             -call 0x4d6390
    cpu.esp -= 4;
    sub_4d6390(app, cpu);
    if (cpu.terminate) return;
    // 0045438f  66894344               -mov word ptr [ebx + 0x44], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(68) /* 0x44 */) = cpu.ax;
L_0x00454393:
    // 00454393  ba44985300             -mov edx, 0x539844
    cpu.edx = 5478468 /*0x539844*/;
    // 00454398  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0045439a  e8a1e6feff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0045439f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004543a1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004543a3  7412                   -je 0x4543b7
    if (cpu.flags.zf)
    {
        goto L_0x004543b7;
    }
    // 004543a5  8b5042                 -mov edx, dword ptr [eax + 0x42]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(66) /* 0x42 */);
    // 004543a8  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004543ab  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004543ae  e8dd1f0800             -call 0x4d6390
    cpu.esp -= 4;
    sub_4d6390(app, cpu);
    if (cpu.terminate) return;
    // 004543b3  66894144               -mov word ptr [ecx + 0x44], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(68) /* 0x44 */) = cpu.ax;
L_0x004543b7:
    // 004543b7  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004543b9  e8d2d40800             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
L_0x004543be:
    // 004543be  a1a4c17900             -mov eax, dword ptr [0x79c1a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7979428) /* 0x79c1a4 */);
    // 004543c3  a390955500             -mov dword ptr [0x559590], eax
    app->getMemory<x86::reg32>(x86::reg32(5608848) /* 0x559590 */) = cpu.eax;
L_0x004543c8:
    // 004543c8  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004543ca  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004543cc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004543cd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004543ce  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004543cf  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004543d0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004543d1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004543d2  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
