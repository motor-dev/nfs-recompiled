#include "nfs2se.h"
#include <lib/thread.h>

namespace nfs2se
{

/* align: skip  */
void Application::sub_488f88(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00488f88  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00488f89  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00488f8a  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 00488f8c  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00488f8e  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00488f90  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00488f92  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00488f94  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00488f96  e821fcffff             -call 0x488bbc
    cpu.esp -= 4;
    sub_488bbc(app, cpu);
    if (cpu.terminate) return;
    // 00488f9b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00488f9d  7507                   -jne 0x488fa6
    if (!cpu.flags.zf)
    {
        goto L_0x00488fa6;
    }
    // 00488f9f  c6450000               -mov byte ptr [ebp], 0
    *app->getMemory<x86::reg8>(cpu.ebp) = 0 /*0x0*/;
    // 00488fa3  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488fa4  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488fa5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00488fa6:
    // 00488fa6  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00488fa7  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00488fa8  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00488faa  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 00488fac  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00488fad:
    // 00488fad  8a06                   -mov al, byte ptr [esi]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esi);
    // 00488faf  8807                   -mov byte ptr [edi], al
    *app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00488fb1  3c00                   +cmp al, 0
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
    // 00488fb3  7410                   -je 0x488fc5
    if (cpu.flags.zf)
    {
        goto L_0x00488fc5;
    }
    // 00488fb5  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00488fb8  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00488fbb  884701                 -mov byte ptr [edi + 1], al
    *app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00488fbe  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00488fc1  3c00                   +cmp al, 0
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
    // 00488fc3  75e8                   -jne 0x488fad
    if (!cpu.flags.zf)
    {
        goto L_0x00488fad;
    }
L_0x00488fc5:
    // 00488fc5  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488fc6  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00488fc8  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488fc9  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488fca  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488fcb  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488fcc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_488fd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00488fd0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00488fd1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00488fd2  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00488fd4  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00488fd6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00488fd8  09c9                   +or ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00488fda  7d05                   -jge 0x488fe1
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00488fe1;
    }
    // 00488fdc  83cb08                 -or ebx, 8
    cpu.ebx |= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00488fdf  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
L_0x00488fe1:
    // 00488fe1  09d2                   +or edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx |= x86::reg32(x86::sreg32(cpu.edx))));
    // 00488fe3  7d05                   -jge 0x488fea
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00488fea;
    }
    // 00488fe5  83cb10                 -or ebx, 0x10
    cpu.ebx |= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00488fe8  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
L_0x00488fea:
    // 00488fea  39ca                   +cmp edx, ecx
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
    // 00488fec  7c07                   -jl 0x488ff5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00488ff5;
    }
    // 00488fee  741d                   -je 0x48900d
    if (cpu.flags.zf)
    {
        goto L_0x0048900d;
    }
    // 00488ff0  87d1                   -xchg ecx, edx
    {
        x86::reg32 tmp = cpu.ecx;
        cpu.ecx = cpu.edx;
        cpu.edx = tmp;
    }
    // 00488ff2  83cb04                 -or ebx, 4
    cpu.ebx |= x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00488ff5:
    // 00488ff5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00488ff7  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00488ff9  c1e818                 +shr eax, 0x18
    {
        x86::reg8 tmp = 24 /*0x18*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 00488ffc  83d000                 +adc eax, 0
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
    // 00488fff  0fb6805cc34c00         -movzx eax, byte ptr [eax + 0x4cc35c]
    cpu.eax = x86::reg32(*app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5030748) /* 0x4cc35c */));
    // 00489006  2effa319904800         -jmp dword ptr cs:[ebx + 0x489019]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ebx + 4755481); goto dynamic_jump;
L_0x0048900d:
    // 0048900d  b880000000             -mov eax, 0x80
    cpu.eax = 128 /*0x80*/;
    // 00489012  2effa319904800         -jmp dword ptr cs:[ebx + 0x489019]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ebx + 4755481); goto dynamic_jump;
  case 0x00489039:
    // 00489039  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 0048903b  0500010000             -add eax, 0x100
    (cpu.eax) += x86::reg32(x86::sreg32(256 /*0x100*/));
  [[fallthrough]];
  case 0x00489040:
    // 00489040  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489041  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489042  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00489043:
    // 00489043  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 00489045  0500020000             -add eax, 0x200
    (cpu.eax) += x86::reg32(x86::sreg32(512 /*0x200*/));
    // 0048904a  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048904b  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048904c  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0048904d:
    // 0048904d  0500010000             -add eax, 0x100
    (cpu.eax) += x86::reg32(x86::sreg32(256 /*0x100*/));
    // 00489052  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489053  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489054  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00489055:
    // 00489055  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 00489057  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489058  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489059  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0048905a:
    // 0048905a  2d00010000             -sub eax, 0x100
    (cpu.eax) -= x86::reg32(x86::sreg32(256 /*0x100*/));
    // 0048905f  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489060  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489061  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00489062:
    // 00489062  2d00020000             -sub eax, 0x200
    (cpu.eax) -= x86::reg32(x86::sreg32(512 /*0x200*/));
    // 00489067  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489068  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489069  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0048906a:
    // 0048906a  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 0048906c  2d00010000             -sub eax, 0x100
    (cpu.eax) -= x86::reg32(x86::sreg32(256 /*0x100*/));
    // 00489071  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489072  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489073  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_489080(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00489080  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00489081  39d0                   +cmp eax, edx
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
    // 00489083  7526                   -jne 0x4890ab
    if (!cpu.flags.zf)
    {
        goto L_0x004890ab;
    }
    // 00489085  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00489088  8b520c                 -mov edx, dword ptr [edx + 0xc]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0048908b  89480c                 -mov dword ptr [eax + 0xc], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0048908e  895004                 -mov dword ptr [eax + 4], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00489091  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00489094  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00489097  894818                 -mov dword ptr [eax + 0x18], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 0048909a  895008                 -mov dword ptr [eax + 8], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0048909d  8b4814                 -mov ecx, dword ptr [eax + 0x14]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004890a0  8b501c                 -mov edx, dword ptr [eax + 0x1c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004890a3  89481c                 -mov dword ptr [eax + 0x1c], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 004890a6  895014                 -mov dword ptr [eax + 0x14], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004890a9  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004890aa  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004890ab:
    // 004890ab  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax);
    // 004890ad  890a                   -mov dword ptr [edx], ecx
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 004890af  8b480c                 -mov ecx, dword ptr [eax + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004890b2  894a04                 -mov dword ptr [edx + 4], ecx
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004890b5  8b4818                 -mov ecx, dword ptr [eax + 0x18]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004890b8  894a08                 -mov dword ptr [edx + 8], ecx
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 004890bb  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004890be  894a0c                 -mov dword ptr [edx + 0xc], ecx
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004890c1  8b4810                 -mov ecx, dword ptr [eax + 0x10]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004890c4  894a10                 -mov dword ptr [edx + 0x10], ecx
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 004890c7  8b481c                 -mov ecx, dword ptr [eax + 0x1c]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004890ca  894a14                 -mov dword ptr [edx + 0x14], ecx
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 004890cd  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004890d0  894a18                 -mov dword ptr [edx + 0x18], ecx
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 004890d3  8b4814                 -mov ecx, dword ptr [eax + 0x14]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004890d6  894a1c                 -mov dword ptr [edx + 0x1c], ecx
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 004890d9  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004890dc  894220                 -mov dword ptr [edx + 0x20], eax
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 004890df  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004890e0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4890f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004890f0  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004890f1  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004890f2  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004890f3  81ec00010000           -sub esp, 0x100
    (cpu.esp) -= x86::reg32(x86::sreg32(256 /*0x100*/));
    // 004890f9  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004890fb  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004890fd  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004890ff  e8c425ffff             -call 0x47b6c8
    cpu.esp -= 4;
    sub_47b6c8(app, cpu);
    if (cpu.terminate) return;
    // 00489104  8d43f8                 -lea eax, [ebx - 8]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(-8) /* -0x8 */);
    // 00489107  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00489109  3d00010000             +cmp eax, 0x100
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
    // 0048910e  7d05                   -jge 0x489115
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00489115;
    }
    // 00489110  83f808                 +cmp eax, 8
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00489113  7e35                   -jle 0x48914a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048914a;
    }
L_0x00489115:
    // 00489115  8d45f8                 -lea eax, [ebp - 8]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00489118  3d00010000             +cmp eax, 0x100
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
    // 0048911d  7d24                   -jge 0x489143
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00489143;
    }
L_0x0048911f:
    // 0048911f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x00489121:
    // 00489121  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00489123  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00489125  e88e25ffff             -call 0x47b6b8
    cpu.esp -= 4;
    sub_47b6b8(app, cpu);
    if (cpu.terminate) return;
    // 0048912a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048912c  7523                   -jne 0x489151
    if (!cpu.flags.zf)
    {
        goto L_0x00489151;
    }
L_0x0048912e:
    // 0048912e  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00489130  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00489132  e89125ffff             -call 0x47b6c8
    cpu.esp -= 4;
    sub_47b6c8(app, cpu);
    if (cpu.terminate) return;
    // 00489137  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00489139  81c400010000           +add esp, 0x100
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(256 /*0x100*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048913f  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489140  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489141  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489142  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00489143:
    // 00489143  b800010000             -mov eax, 0x100
    cpu.eax = 256 /*0x100*/;
    // 00489148  ebd5                   -jmp 0x48911f
    goto L_0x0048911f;
L_0x0048914a:
    // 0048914a  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 0048914f  ebd0                   -jmp 0x489121
    goto L_0x00489121;
L_0x00489151:
    // 00489151  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00489153  e80c100000             -call 0x48a164
    cpu.esp -= 4;
    sub_48a164(app, cpu);
    if (cpu.terminate) return;
    // 00489158  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048915a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048915c  75d0                   -jne 0x48912e
    if (!cpu.flags.zf)
    {
        goto L_0x0048912e;
    }
    // 0048915e  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 00489160  ebcc                   -jmp 0x48912e
    goto L_0x0048912e;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_489164(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00489164  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00489165  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0048916a  e811000000             -call 0x489180
    cpu.esp -= 4;
    sub_489180(app, cpu);
    if (cpu.terminate) return;
    // 0048916f  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489170  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_489174(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00489174  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00489175  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00489177  e804000000             -call 0x489180
    cpu.esp -= 4;
    sub_489180(app, cpu);
    if (cpu.terminate) return;
    // 0048917c  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048917d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_489180(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00489180  e823000000             -call 0x4891a8
    cpu.esp -= 4;
    sub_4891a8(app, cpu);
    if (cpu.terminate) return;
    // 00489185  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00489187  7402                   -je 0x48918b
    if (cpu.flags.zf)
    {
        goto L_0x0048918b;
    }
    // 00489189  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
L_0x0048918b:
    // 0048918b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48918c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048918c  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048918d  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00489192  e811000000             -call 0x4891a8
    cpu.esp -= 4;
    sub_4891a8(app, cpu);
    if (cpu.terminate) return;
    // 00489197  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489198  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48919c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048919c  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048919d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048919f  e804000000             -call 0x4891a8
    cpu.esp -= 4;
    sub_4891a8(app, cpu);
    if (cpu.terminate) return;
    // 004891a4  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004891a5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4891a8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004891a8  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004891a9  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004891aa  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004891ab  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004891ac  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004891af  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004891b1  8954240c               -mov dword ptr [esp + 0xc], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004891b5  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004891b7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004891b9  89542408               -mov dword ptr [esp + 8], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004891bd  e8f2a90000             -call 0x493bb4
    cpu.esp -= 4;
    sub_493bb4(app, cpu);
    if (cpu.terminate) return;
    // 004891c2  89442410               -mov dword ptr [esp + 0x10], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004891c6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004891c8  7419                   -je 0x4891e3
    if (cpu.flags.zf)
    {
        goto L_0x004891e3;
    }
L_0x004891ca:
    // 004891ca  833d3cac4c0000         +cmp dword ptr [0x4cac3c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5024828) /* 0x4cac3c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004891d1  0f85a1000000           -jne 0x489278
    if (!cpu.flags.zf)
    {
        goto L_0x00489278;
    }
    // 004891d7  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004891db  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004891de  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004891df  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004891e0  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004891e1  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004891e2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004891e3:
    // 004891e3  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004891e7  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004891e9  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004891ea  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004891ec  8d5c2408               -lea ebx, [esp + 8]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004891f0  e8bf23ffff             -call 0x47b5b4
    cpu.esp -= 4;
    sub_47b5b4(app, cpu);
    if (cpu.terminate) return;
    // 004891f5  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004891f7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004891f9  74cf                   -je 0x4891ca
    if (cpu.flags.zf)
    {
        goto L_0x004891ca;
    }
    // 004891fb  e8640f0000             -call 0x48a164
    cpu.esp -= 4;
    sub_48a164(app, cpu);
    if (cpu.terminate) return;
    // 00489200  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00489202  7540                   -jne 0x489244
    if (!cpu.flags.zf)
    {
        goto L_0x00489244;
    }
    // 00489204  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00489206  7432                   -je 0x48923a
    if (cpu.flags.zf)
    {
        goto L_0x0048923a;
    }
    // 00489208  837c240800             +cmp dword ptr [esp + 8], 0
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
    // 0048920d  742b                   -je 0x48923a
    if (cpu.flags.zf)
    {
        goto L_0x0048923a;
    }
    // 0048920f  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00489213  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00489217  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00489219  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048921b  e884f4feff             -call 0x4786a4
    cpu.esp -= 4;
    sub_4786a4(app, cpu);
    if (cpu.terminate) return;
    // 00489220  89442410               -mov dword ptr [esp + 0x10], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00489224  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00489226  7412                   -je 0x48923a
    if (cpu.flags.zf)
    {
        goto L_0x0048923a;
    }
    // 00489228  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048922c  e86ff4feff             -call 0x4786a0
    cpu.esp -= 4;
    sub_4786a0(app, cpu);
    if (cpu.terminate) return;
    // 00489231  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00489233  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00489235  e81675ffff             -call 0x480750
    cpu.esp -= 4;
    sub_480750(app, cpu);
    if (cpu.terminate) return;
L_0x0048923a:
    // 0048923a  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 0048923d  e86e24ffff             -call 0x47b6b0
    cpu.esp -= 4;
    sub_47b6b0(app, cpu);
    if (cpu.terminate) return;
    // 00489242  eb86                   -jmp 0x4891ca
    goto L_0x004891ca;
L_0x00489244:
    // 00489244  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00489248  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0048924a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048924c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048924e  e851f4feff             -call 0x4786a4
    cpu.esp -= 4;
    sub_4786a4(app, cpu);
    if (cpu.terminate) return;
    // 00489253  89442410               -mov dword ptr [esp + 0x10], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00489257  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00489259  74df                   -je 0x48923a
    if (cpu.flags.zf)
    {
        goto L_0x0048923a;
    }
    // 0048925b  e840f4feff             -call 0x4786a0
    cpu.esp -= 4;
    sub_4786a0(app, cpu);
    if (cpu.terminate) return;
    // 00489260  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00489262  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00489264  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00489266  e8450e0000             -call 0x48a0b0
    cpu.esp -= 4;
    sub_48a0b0(app, cpu);
    if (cpu.terminate) return;
    // 0048926b  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 0048926e  e83d24ffff             -call 0x47b6b0
    cpu.esp -= 4;
    sub_47b6b0(app, cpu);
    if (cpu.terminate) return;
    // 00489273  e952ffffff             -jmp 0x4891ca
    goto L_0x004891ca;
L_0x00489278:
    // 00489278  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048927c  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00489280  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00489282  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00489284  ff153cac4c00           -call dword ptr [0x4cac3c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5024828) /* 0x4cac3c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048928a  89442410               -mov dword ptr [esp + 0x10], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0048928e  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00489292  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00489295  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489296  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489297  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489298  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489299  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4892a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004892a0  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004892a1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004892a3  803d6cab4c0000         +cmp byte ptr [0x4cab6c], 0
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
    // 004892aa  7410                   -je 0x4892bc
    if (cpu.flags.zf)
    {
        goto L_0x004892bc;
    }
    // 004892ac  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004892ae  7c05                   -jl 0x4892b5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004892b5;
    }
    // 004892b0  83fa7f                 +cmp edx, 0x7f
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
    // 004892b3  7e0e                   -jle 0x4892c3
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004892c3;
    }
L_0x004892b5:
    // 004892b5  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 004892ba  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004892bb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004892bc:
    // 004892bc  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 004892c1  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004892c2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004892c3:
    // 004892c3  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004892c4  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004892c5  e826b60000             -call 0x4948f0
    cpu.esp -= 4;
    sub_4948f0(app, cpu);
    if (cpu.terminate) return;
    // 004892ca  bb00845200             -mov ebx, 0x528400
    cpu.ebx = 5407744 /*0x528400*/;
    // 004892cf  88155d8a5200           -mov byte ptr [0x528a5d], dl
    *app->getMemory<x86::reg8>(x86::reg32(5409373) /* 0x528a5d */) = cpu.dl;
    // 004892d5  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004892d7:
    // 004892d7  807b0c01               +cmp byte ptr [ebx + 0xc], 1
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(12) /* 0xc */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004892db  7519                   -jne 0x4892f6
    if (!cpu.flags.zf)
    {
        goto L_0x004892f6;
    }
    // 004892dd  833b00                 +cmp dword ptr [ebx], 0
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
    // 004892e0  7c14                   -jl 0x4892f6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004892f6;
    }
    // 004892e2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004892e4  e8a7fb0000             -call 0x498e90
    cpu.esp -= 4;
    sub_498e90(app, cpu);
    if (cpu.terminate) return;
    // 004892e9  8b532e                 -mov edx, dword ptr [ebx + 0x2e]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(46) /* 0x2e */);
    // 004892ec  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004892ee  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004892f1  e86e52ffff             -call 0x47e564
    cpu.esp -= 4;
    sub_47e564(app, cpu);
    if (cpu.terminate) return;
L_0x004892f6:
    // 004892f6  41                     -inc ecx
    (cpu.ecx)++;
    // 004892f7  83c360                 -add ebx, 0x60
    (cpu.ebx) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 004892fa  83f910                 +cmp ecx, 0x10
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
    // 004892fd  7cd8                   -jl 0x4892d7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004892d7;
    }
    // 004892ff  e800b60000             -call 0x494904
    cpu.esp -= 4;
    sub_494904(app, cpu);
    if (cpu.terminate) return;
    // 00489304  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00489306  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489307  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489308  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489309  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_489310(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00489310  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00489311  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00489313:
    // 00489313  8b8200845200           -mov eax, dword ptr [edx + 0x528400]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5407744) /* 0x528400 */);
    // 00489319  83c260                 -add edx, 0x60
    (cpu.edx) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 0048931c  e8df55ffff             -call 0x47e900
    cpu.esp -= 4;
    sub_47e900(app, cpu);
    if (cpu.terminate) return;
    // 00489321  81fa00060000           +cmp edx, 0x600
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1536 /*0x600*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00489327  75ea                   -jne 0x489313
    if (!cpu.flags.zf)
    {
        goto L_0x00489313;
    }
    // 00489329  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048932a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_489330(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00489330  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00489331  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00489332  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00489333  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00489335  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00489337  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00489339  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0048933b  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0048933f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00489341  7c05                   -jl 0x489348
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00489348;
    }
    // 00489343  83f801                 +cmp eax, 1
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
    // 00489346  7c0b                   -jl 0x489353
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00489353;
    }
L_0x00489348:
    // 00489348  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
L_0x0048934d:
    // 0048934d  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048934e  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048934f  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489350  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00489353:
    // 00489353  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00489356  05f0835200             -add eax, 0x5283f0
    (cpu.eax) += x86::reg32(x86::sreg32(5407728 /*0x5283f0*/));
    // 0048935b  8938                   -mov dword ptr [eax], edi
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.edi;
    // 0048935d  895808                 -mov dword ptr [eax + 8], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00489360  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00489362  89480c                 -mov dword ptr [eax + 0xc], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00489365  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00489367  e87848ffff             -call 0x47dbe4
    cpu.esp -= 4;
    sub_47dbe4(app, cpu);
    if (cpu.terminate) return;
    // 0048936c  803d6cab4c0000         +cmp byte ptr [0x4cab6c], 0
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
    // 00489373  7419                   -je 0x48938e
    if (cpu.flags.zf)
    {
        goto L_0x0048938e;
    }
    // 00489375  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00489377  7cd4                   -jl 0x48934d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048934d;
    }
L_0x00489379:
    // 00489379  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0048937b  7502                   -jne 0x48937f
    if (!cpu.flags.zf)
    {
        goto L_0x0048937f;
    }
    // 0048937d  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
L_0x0048937f:
    // 0048937f  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00489381  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00489383  e810000000             -call 0x489398
    cpu.esp -= 4;
    sub_489398(app, cpu);
    if (cpu.terminate) return;
    // 00489388  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489389  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048938a  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048938b  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0048938e:
    // 0048938e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00489390  7de7                   -jge 0x489379
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00489379;
    }
    // 00489392  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489393  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489394  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489395  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_489398(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00489398  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00489399  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0048939b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048939d  7c0e                   -jl 0x4893ad
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004893ad;
    }
    // 0048939f  83f801                 +cmp eax, 1
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
    // 004893a2  7d09                   -jge 0x4893ad
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004893ad;
    }
    // 004893a4  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004893a6  7c05                   -jl 0x4893ad
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004893ad;
    }
    // 004893a8  83fa7f                 +cmp edx, 0x7f
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
    // 004893ab  7e07                   -jle 0x4893b4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004893b4;
    }
L_0x004893ad:
    // 004893ad  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
L_0x004893b2:
    // 004893b2  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004893b3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004893b4:
    // 004893b4  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004893b7  8990f4835200           -mov dword ptr [eax + 0x5283f4], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5407732) /* 0x5283f4 */) = cpu.edx;
    // 004893bd  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004893bf  e82c48ffff             -call 0x47dbf0
    cpu.esp -= 4;
    sub_47dbf0(app, cpu);
    if (cpu.terminate) return;
    // 004893c4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004893c6  7cea                   -jl 0x4893b2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004893b2;
    }
    // 004893c8  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004893c9  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004893ca  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004893cb  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 004893cd  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004893cf:
    // 004893cf  6bc160                 -imul eax, ecx, 0x60
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(96 /*0x60*/)));
    // 004893d2  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004893d4  8b9e36845200           -mov ebx, dword ptr [esi + 0x528436]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5407798) /* 0x528436 */);
    // 004893da  83c660                 -add esi, 0x60
    (cpu.esi) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 004893dd  c1fb18                 -sar ebx, 0x18
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (24 /*0x18*/ % 32));
    // 004893e0  8b8000845200           -mov eax, dword ptr [eax + 0x528400]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5407744) /* 0x528400 */);
    // 004893e6  41                     -inc ecx
    (cpu.ecx)++;
    // 004893e7  e824300100             -call 0x49c410
    cpu.esp -= 4;
    sub_49c410(app, cpu);
    if (cpu.terminate) return;
    // 004893ec  83f910                 +cmp ecx, 0x10
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
    // 004893ef  7cde                   -jl 0x4893cf
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004893cf;
    }
    // 004893f1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004893f3  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004893f4  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004893f5  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004893f6  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004893f7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_489400(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00489400  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00489401  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00489402  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00489403  66833dd8a24c0000       +cmp word ptr [0x4ca2d8], 0
    {
        x86::reg16 tmp1 = *app->getMemory<x86::reg16>(x86::reg32(5022424) /* 0x4ca2d8 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0048940b  0f8cc3000000           -jl 0x4894d4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004894d4;
    }
    // 00489411  0fbf0548a24c00         -movsx eax, word ptr [0x4ca248]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(*app->getMemory<x86::reg16>(x86::reg32(5022280) /* 0x4ca248 */)));
    // 00489418  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0048941b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048941d  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00489420  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00489422  8b15e4a24c00           -mov edx, dword ptr [0x4ca2e4]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5022436) /* 0x4ca2e4 */);
    // 00489428  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048942a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048942c  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax);
    // 0048942e  a1e0a24c00             -mov eax, dword ptr [0x4ca2e0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5022432) /* 0x4ca2e0 */);
    // 00489433  8a4007                 -mov al, byte ptr [eax + 7]
    cpu.al = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(7) /* 0x7 */);
    // 00489436  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0048943b  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0048943e  0fbf15d8a24c00         -movsx edx, word ptr [0x4ca2d8]
    cpu.edx = x86::reg32(static_cast<x86::sreg16>(*app->getMemory<x86::reg16>(x86::reg32(5022424) /* 0x4ca2d8 */)));
    // 00489445  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00489447  8b1550a24c00           -mov edx, dword ptr [0x4ca250]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5022288) /* 0x4ca250 */);
    // 0048944d  8a0402                 -mov al, byte ptr [edx + eax]
    cpu.al = *app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1);
    // 00489450  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 00489452  66a348a24c00           -mov word ptr [0x4ca248], ax
    *app->getMemory<x86::reg16>(x86::reg32(5022280) /* 0x4ca248 */) = cpu.ax;
    // 00489458  a1dca24c00             -mov eax, dword ptr [0x4ca2dc]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5022428) /* 0x4ca2dc */);
    // 0048945d  a3d8a24c00             -mov dword ptr [0x4ca2d8], eax
    *app->getMemory<x86::reg32>(x86::reg32(5022424) /* 0x4ca2d8 */) = cpu.eax;
    // 00489462  66c705dca24c00ffff     -mov word ptr [0x4ca2dc], 0xffff
    *app->getMemory<x86::reg16>(x86::reg32(5022428) /* 0x4ca2dc */) = 65535 /*0xffff*/;
    // 0048946b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048946d  66890ddea24c00         -mov word ptr [0x4ca2de], cx
    *app->getMemory<x86::reg16>(x86::reg32(5022430) /* 0x4ca2de */) = cpu.cx;
L_0x00489474:
    // 00489474  ff054ca24c00           -inc dword ptr [0x4ca24c]
    (*app->getMemory<x86::reg32>(x86::reg32(5022284) /* 0x4ca24c */))++;
    // 0048947a  0fbf0548a24c00         -movsx eax, word ptr [0x4ca248]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(*app->getMemory<x86::reg16>(x86::reg32(5022280) /* 0x4ca248 */)));
    // 00489481  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00489484  8b1554a24c00           -mov edx, dword ptr [0x4ca254]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5022292) /* 0x4ca254 */);
    // 0048948a  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0048948f  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00489491  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 00489493  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 00489495  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00489497  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0048949e  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 004894a0  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004894a2  b858a24c00             -mov eax, 0x4ca258
    cpu.eax = 5022296 /*0x4ca258*/;
    // 004894a7  e830d7ffff             -call 0x486bdc
    cpu.esp -= 4;
    sub_486bdc(app, cpu);
    if (cpu.terminate) return;
    // 004894ac  0fbf0548a24c00         -movsx eax, word ptr [0x4ca248]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(*app->getMemory<x86::reg16>(x86::reg32(5022280) /* 0x4ca248 */)));
    // 004894b3  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004894b6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004894b8  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004894bb  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004894bd  8b15e4a24c00           -mov edx, dword ptr [0x4ca2e4]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5022436) /* 0x4ca2e4 */);
    // 004894c3  807c020100             +cmp byte ptr [edx + eax + 1], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */ + cpu.eax * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004894c8  0f869a000000           -jbe 0x489568
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00489568;
    }
L_0x004894ce:
    // 004894ce  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004894d0  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004894d1  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004894d2  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004894d3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004894d4:
    // 004894d4  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004894d6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004894d8:
    // 004894d8  0fbf0d48a24c00         -movsx ecx, word ptr [0x4ca248]
    cpu.ecx = x86::reg32(static_cast<x86::sreg16>(*app->getMemory<x86::reg16>(x86::reg32(5022280) /* 0x4ca248 */)));
    // 004894df  6bc91c                 -imul ecx, ecx, 0x1c
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(28 /*0x1c*/)));
    // 004894e2  8b1de4a24c00           -mov ebx, dword ptr [0x4ca2e4]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5022436) /* 0x4ca2e4 */);
    // 004894e8  8a4c1901               -mov cl, byte ptr [ecx + ebx + 1]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */ + cpu.ebx * 1);
    // 004894ec  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004894f2  39ca                   +cmp edx, ecx
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
    // 004894f4  0f8d7affffff           -jge 0x489474
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00489474;
    }
    // 004894fa  0fbf0d48a24c00         -movsx ecx, word ptr [0x4ca248]
    cpu.ecx = x86::reg32(static_cast<x86::sreg16>(*app->getMemory<x86::reg16>(x86::reg32(5022280) /* 0x4ca248 */)));
    // 00489501  6bc91c                 -imul ecx, ecx, 0x1c
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(28 /*0x1c*/)));
    // 00489504  8b1de4a24c00           -mov ebx, dword ptr [0x4ca2e4]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5022436) /* 0x4ca2e4 */);
    // 0048950a  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0048950c  8a1d4aa24c00           -mov bl, byte ptr [0x4ca24a]
    cpu.bl = *app->getMemory<x86::reg8>(x86::reg32(5022282) /* 0x4ca24a */);
    // 00489512  3a5c0104               +cmp bl, byte ptr [ecx + eax + 4]
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(*app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.eax * 1)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00489516  7d06                   -jge 0x48951e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048951e;
    }
L_0x00489518:
    // 00489518  83c003                 +add eax, 3
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048951b  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0048951c  ebba                   -jmp 0x4894d8
    goto L_0x004894d8;
L_0x0048951e:
    // 0048951e  0fbf1d48a24c00         -movsx ebx, word ptr [0x4ca248]
    cpu.ebx = x86::reg32(static_cast<x86::sreg16>(*app->getMemory<x86::reg16>(x86::reg32(5022280) /* 0x4ca248 */)));
    // 00489525  6bdb1c                 -imul ebx, ebx, 0x1c
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(28 /*0x1c*/)));
    // 00489528  8b0de4a24c00           -mov ecx, dword ptr [0x4ca2e4]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5022436) /* 0x4ca2e4 */);
    // 0048952e  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00489530  8a1d4aa24c00           -mov bl, byte ptr [0x4ca24a]
    cpu.bl = *app->getMemory<x86::reg8>(x86::reg32(5022282) /* 0x4ca24a */);
    // 00489536  3a5c0105               +cmp bl, byte ptr [ecx + eax + 5]
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(*app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5) /* 0x5 */ + cpu.eax * 1)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048953a  7fdc                   -jg 0x489518
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00489518;
    }
    // 0048953c  0fbf1548a24c00         -movsx edx, word ptr [0x4ca248]
    cpu.edx = x86::reg32(static_cast<x86::sreg16>(*app->getMemory<x86::reg16>(x86::reg32(5022280) /* 0x4ca248 */)));
    // 00489543  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 00489546  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00489548  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 0048954b  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048954d  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0048954f  8b15e4a24c00           -mov edx, dword ptr [0x4ca2e4]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5022436) /* 0x4ca2e4 */);
    // 00489555  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00489557  8a440206               -mov al, byte ptr [edx + eax + 6]
    cpu.al = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(6) /* 0x6 */ + cpu.eax * 1);
    // 0048955b  30e4                   +xor ah, ah
    cpu.clear_co();
    cpu.set_szp((cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah))));
    // 0048955d  66a348a24c00           -mov word ptr [0x4ca248], ax
    *app->getMemory<x86::reg16>(x86::reg32(5022280) /* 0x4ca248 */) = cpu.ax;
    // 00489563  e90cffffff             -jmp 0x489474
    goto L_0x00489474;
L_0x00489568:
    // 00489568  66833dd8a24c0000       +cmp word ptr [0x4ca2d8], 0
    {
        x86::reg16 tmp1 = *app->getMemory<x86::reg16>(x86::reg32(5022424) /* 0x4ca2d8 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00489570  0f8d58ffffff           -jge 0x4894ce
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004894ce;
    }
    // 00489576  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00489578  890d78ab4c00           -mov dword ptr [0x4cab78], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5024632) /* 0x4cab78 */) = cpu.ecx;
    // 0048957e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00489580  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489581  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489582  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489583  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_489584(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00489584  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00489585  e8f6dcffff             -call 0x487280
    cpu.esp -= 4;
    sub_487280(app, cpu);
    if (cpu.terminate) return;
    // 0048958a  3b054ca24c00           +cmp eax, dword ptr [0x4ca24c]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5022284) /* 0x4ca24c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00489590  7d02                   -jge 0x489594
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00489594;
    }
L_0x00489592:
    // 00489592  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489593  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00489594:
    // 00489594  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00489596  668b1546a24c00         -mov dx, word ptr [0x4ca246]
    cpu.dx = *app->getMemory<x86::reg16>(x86::reg32(5022278) /* 0x4ca246 */);
    // 0048959d  e876d8ffff             -call 0x486e18
    cpu.esp -= 4;
    sub_486e18(app, cpu);
    if (cpu.terminate) return;
    // 004895a2  39d0                   +cmp eax, edx
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
    // 004895a4  7dec                   -jge 0x489592
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00489592;
    }
    // 004895a6  e855feffff             -call 0x489400
    cpu.esp -= 4;
    sub_489400(app, cpu);
    if (cpu.terminate) return;
    // 004895ab  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004895ac  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4895b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004895b0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004895b2  7506                   -jne 0x4895ba
    if (!cpu.flags.zf)
    {
        goto L_0x004895ba;
    }
    // 004895b4  66a144a24c00           -mov ax, word ptr [0x4ca244]
    cpu.ax = *app->getMemory<x86::reg16>(x86::reg32(5022276) /* 0x4ca244 */);
L_0x004895ba:
    // 004895ba  66a346a24c00           -mov word ptr [0x4ca246], ax
    *app->getMemory<x86::reg16>(x86::reg32(5022278) /* 0x4ca246 */) = cpu.ax;
    // 004895c0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4895c4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004895c4  803d6cab4c0000         +cmp byte ptr [0x4cab6c], 0
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
    // 004895cb  7422                   -je 0x4895ef
    if (cpu.flags.zf)
    {
        goto L_0x004895ef;
    }
    // 004895cd  833de0a24c0000         +cmp dword ptr [0x4ca2e0], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5022432) /* 0x4ca2e0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004895d4  751f                   -jne 0x4895f5
    if (!cpu.flags.zf)
    {
        goto L_0x004895f5;
    }
    // 004895d6  a3e0a24c00             -mov dword ptr [0x4ca2e0], eax
    *app->getMemory<x86::reg32>(x86::reg32(5022432) /* 0x4ca2e0 */) = cpu.eax;
    // 004895db  813850464478           +cmp dword ptr [eax], 0x78444650
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2017740368 /*0x78444650*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004895e1  7518                   -jne 0x4895fb
    if (!cpu.flags.zf)
    {
        goto L_0x004895fb;
    }
    // 004895e3  80780400               +cmp byte ptr [eax + 4], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004895e7  7418                   -je 0x489601
    if (cpu.flags.zf)
    {
        goto L_0x00489601;
    }
    // 004895e9  b8f5ffffff             -mov eax, 0xfffffff5
    cpu.eax = 4294967285 /*0xfffffff5*/;
    // 004895ee  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004895ef:
    // 004895ef  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 004895f4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004895f5:
    // 004895f5  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004895fa  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004895fb:
    // 004895fb  b8f9ffffff             -mov eax, 0xfffffff9
    cpu.eax = 4294967289 /*0xfffffff9*/;
    // 00489600  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00489601:
    // 00489601  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00489602  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00489603  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00489604  8d500c                 -lea edx, [eax + 0xc]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00489607  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00489609  8915e4a24c00           -mov dword ptr [0x4ca2e4], edx
    *app->getMemory<x86::reg32>(x86::reg32(5022436) /* 0x4ca2e4 */) = cpu.edx;
    // 0048960f  8a4806                 -mov cl, byte ptr [eax + 6]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 00489612  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 00489615  8d14cd00000000         -lea edx, [ecx*8]
    cpu.edx = x86::reg32(cpu.ecx * 8);
    // 0048961c  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048961e  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00489620  8b15e4a24c00           -mov edx, dword ptr [0x4ca2e4]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5022436) /* 0x4ca2e4 */);
    // 00489626  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00489628  891550a24c00           -mov dword ptr [0x4ca250], edx
    *app->getMemory<x86::reg32>(x86::reg32(5022288) /* 0x4ca250 */) = cpu.edx;
    // 0048962e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00489630  8a500b                 -mov dl, byte ptr [eax + 0xb]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(11) /* 0xb */);
    // 00489633  8a4007                 -mov al, byte ptr [eax + 7]
    cpu.al = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(7) /* 0x7 */);
    // 00489636  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0048963b  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0048963e  8b1550a24c00           -mov edx, dword ptr [0x4ca250]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5022288) /* 0x4ca250 */);
    // 00489644  bbdc974800             -mov ebx, 0x4897dc
    cpu.ebx = 4757468 /*0x4897dc*/;
    // 00489649  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048964b  891d98ab4c00           -mov dword ptr [0x4cab98], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5024664) /* 0x4cab98 */) = cpu.ebx;
    // 00489651  891554a24c00           -mov dword ptr [0x4ca254], edx
    *app->getMemory<x86::reg32>(x86::reg32(5022292) /* 0x4ca254 */) = cpu.edx;
    // 00489657  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00489659  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048965a  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048965b  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048965c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_489660(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00489660  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00489661  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00489664  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00489666  803d6cab4c0000         +cmp byte ptr [0x4cab6c], 0
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
    // 0048966d  0f84bc000000           -je 0x48972f
    if (cpu.flags.zf)
    {
        goto L_0x0048972f;
    }
    // 00489673  a3e8a24c00             -mov dword ptr [0x4ca2e8], eax
    *app->getMemory<x86::reg32>(x86::reg32(5022440) /* 0x4ca2e8 */) = cpu.eax;
    // 00489678  66891d44a24c00         -mov word ptr [0x4ca244], bx
    *app->getMemory<x86::reg16>(x86::reg32(5022276) /* 0x4ca244 */) = cpu.bx;
    // 0048967f  66891d46a24c00         -mov word ptr [0x4ca246], bx
    *app->getMemory<x86::reg16>(x86::reg32(5022278) /* 0x4ca246 */) = cpu.bx;
    // 00489686  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 0048968b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0048968d:
    // 0048968d  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00489690  668990d4a24c00         -mov word ptr [eax + 0x4ca2d4], dx
    *app->getMemory<x86::reg16>(cpu.eax + x86::reg32(5022420) /* 0x4ca2d4 */) = cpu.dx;
    // 00489697  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00489699  668998d6a24c00         -mov word ptr [eax + 0x4ca2d6], bx
    *app->getMemory<x86::reg16>(cpu.eax + x86::reg32(5022422) /* 0x4ca2d6 */) = cpu.bx;
    // 004896a0  83f808                 +cmp eax, 8
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004896a3  75e8                   -jne 0x48968d
    if (!cpu.flags.zf)
    {
        goto L_0x0048968d;
    }
    // 004896a5  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004896a6  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004896a7  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 004896a9  88354aa24c00           -mov byte ptr [0x4ca24a], dh
    *app->getMemory<x86::reg8>(x86::reg32(5022282) /* 0x4ca24a */) = cpu.dh;
    // 004896af  a1e0a24c00             -mov eax, dword ptr [0x4ca2e0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5022432) /* 0x4ca2e0 */);
    // 004896b4  8a4005                 -mov al, byte ptr [eax + 5]
    cpu.al = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */);
    // 004896b7  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 004896b9  66a348a24c00           -mov word ptr [0x4ca248], ax
    *app->getMemory<x86::reg16>(x86::reg32(5022280) /* 0x4ca248 */) = cpu.ax;
    // 004896bf  e8bcdbffff             -call 0x487280
    cpu.esp -= 4;
    sub_487280(app, cpu);
    if (cpu.terminate) return;
    // 004896c4  a34ca24c00             -mov dword ptr [0x4ca24c], eax
    *app->getMemory<x86::reg32>(x86::reg32(5022284) /* 0x4ca24c */) = cpu.eax;
    // 004896c9  bf58a24c00             -mov edi, 0x4ca258
    cpu.edi = 5022296 /*0x4ca258*/;
    // 004896ce  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004896d0  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x004896d1:
    // 004896d1  8a06                   -mov al, byte ptr [esi]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esi);
    // 004896d3  8807                   -mov byte ptr [edi], al
    *app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004896d5  3c00                   +cmp al, 0
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
    // 004896d7  7410                   -je 0x4896e9
    if (cpu.flags.zf)
    {
        goto L_0x004896e9;
    }
    // 004896d9  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004896dc  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004896df  884701                 -mov byte ptr [edi + 1], al
    *app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004896e2  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004896e5  3c00                   +cmp al, 0
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
    // 004896e7  75e8                   -jne 0x4896d1
    if (!cpu.flags.zf)
    {
        goto L_0x004896d1;
    }
L_0x004896e9:
    // 004896e9  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004896ea  ff054ca24c00           -inc dword ptr [0x4ca24c]
    (*app->getMemory<x86::reg32>(x86::reg32(5022284) /* 0x4ca24c */))++;
    // 004896f0  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004896f4  e8a7fbfeff             -call 0x4792a0
    cpu.esp -= 4;
    sub_4792a0(app, cpu);
    if (cpu.terminate) return;
    // 004896f9  a1e8a24c00             -mov eax, dword ptr [0x4ca2e8]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5022440) /* 0x4ca2e8 */);
    // 004896fe  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00489702  e8b9d3ffff             -call 0x486ac0
    cpu.esp -= 4;
    sub_486ac0(app, cpu);
    if (cpu.terminate) return;
    // 00489707  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00489709  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048970b  bbb0954800             -mov ebx, 0x4895b0
    cpu.ebx = 4756912 /*0x4895b0*/;
    // 00489710  e8c7d4ffff             -call 0x486bdc
    cpu.esp -= 4;
    sub_486bdc(app, cpu);
    if (cpu.terminate) return;
    // 00489715  b984954800             -mov ecx, 0x489584
    cpu.ecx = 4756868 /*0x489584*/;
    // 0048971a  891db8a14c00           -mov dword ptr [0x4ca1b8], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5022136) /* 0x4ca1b8 */) = cpu.ebx;
    // 00489720  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00489722  890d78ab4c00           -mov dword ptr [0x4cab78], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5024632) /* 0x4cab78 */) = cpu.ecx;
    // 00489728  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489729  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048972a  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0048972d  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048972e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048972f:
    // 0048972f  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 00489734  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00489737  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489738  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48973c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048973c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048973e  7c05                   -jl 0x489745
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00489745;
    }
    // 00489740  83f87f                 +cmp eax, 0x7f
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(127 /*0x7f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00489743  7e06                   -jle 0x48974b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048974b;
    }
L_0x00489745:
    // 00489745  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 0048974a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048974b:
    // 0048974b  a24aa24c00             -mov byte ptr [0x4ca24a], al
    *app->getMemory<x86::reg8>(x86::reg32(5022282) /* 0x4ca24a */) = cpu.al;
    // 00489750  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00489752  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_489754(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00489754  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00489755  803d6cab4c0000         +cmp byte ptr [0x4cab6c], 0
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
    // 0048975c  7437                   -je 0x489795
    if (cpu.flags.zf)
    {
        goto L_0x00489795;
    }
    // 0048975e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00489760  7c3a                   -jl 0x48979c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048979c;
    }
    // 00489762  8b0de0a24c00           -mov ecx, dword ptr [0x4ca2e0]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5022432) /* 0x4ca2e0 */);
    // 00489768  8a4907                 -mov cl, byte ptr [ecx + 7]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(7) /* 0x7 */);
    // 0048976b  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00489771  39c8                   +cmp eax, ecx
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
    // 00489773  7d27                   -jge 0x48979c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048979c;
    }
    // 00489775  83fa01                 +cmp edx, 1
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
    // 00489778  7429                   -je 0x4897a3
    if (cpu.flags.zf)
    {
        goto L_0x004897a3;
    }
    // 0048977a  66833ddaa24c0001       +cmp word ptr [0x4ca2da], 1
    {
        x86::reg16 tmp1 = *app->getMemory<x86::reg16>(x86::reg32(5022426) /* 0x4ca2da */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(1 /*0x1*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00489782  7544                   -jne 0x4897c8
    if (!cpu.flags.zf)
    {
        goto L_0x004897c8;
    }
    // 00489784  66a3dca24c00           -mov word ptr [0x4ca2dc], ax
    *app->getMemory<x86::reg16>(x86::reg32(5022428) /* 0x4ca2dc */) = cpu.ax;
    // 0048978a  668915dea24c00         -mov word ptr [0x4ca2de], dx
    *app->getMemory<x86::reg16>(x86::reg32(5022430) /* 0x4ca2de */) = cpu.dx;
    // 00489791  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00489793  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489794  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00489795:
    // 00489795  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 0048979a  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048979b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048979c:
    // 0048979c  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 004897a1  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004897a2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004897a3:
    // 004897a3  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004897a4  66a3d8a24c00           -mov word ptr [0x4ca2d8], ax
    *app->getMemory<x86::reg16>(x86::reg32(5022424) /* 0x4ca2d8 */) = cpu.ax;
    // 004897aa  668915daa24c00         -mov word ptr [0x4ca2da], dx
    *app->getMemory<x86::reg16>(x86::reg32(5022426) /* 0x4ca2da */) = cpu.dx;
    // 004897b1  66c705dca24c00ffff     -mov word ptr [0x4ca2dc], 0xffff
    *app->getMemory<x86::reg16>(x86::reg32(5022428) /* 0x4ca2dc */) = 65535 /*0xffff*/;
    // 004897ba  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004897bc  668935dea24c00         -mov word ptr [0x4ca2de], si
    *app->getMemory<x86::reg16>(x86::reg32(5022430) /* 0x4ca2de */) = cpu.si;
    // 004897c3  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004897c4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004897c6  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004897c7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004897c8:
    // 004897c8  66a3d8a24c00           -mov word ptr [0x4ca2d8], ax
    *app->getMemory<x86::reg16>(x86::reg32(5022424) /* 0x4ca2d8 */) = cpu.ax;
    // 004897ce  668915daa24c00         -mov word ptr [0x4ca2da], dx
    *app->getMemory<x86::reg16>(x86::reg32(5022426) /* 0x4ca2da */) = cpu.dx;
    // 004897d5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004897d7  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004897d8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4897dc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004897dc  803d6cab4c0000         +cmp byte ptr [0x4cab6c], 0
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
    // 004897e3  7506                   -jne 0x4897eb
    if (!cpu.flags.zf)
    {
        goto L_0x004897eb;
    }
    // 004897e5  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 004897ea  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004897eb:
    // 004897eb  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004897ec  e88fd3ffff             -call 0x486b80
    cpu.esp -= 4;
    sub_486b80(app, cpu);
    if (cpu.terminate) return;
    // 004897f1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004897f3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004897f5  891578ab4c00           -mov dword ptr [0x4cab78], edx
    *app->getMemory<x86::reg32>(x86::reg32(5024632) /* 0x4cab78 */) = cpu.edx;
    // 004897fb  8915e0a24c00           -mov dword ptr [0x4ca2e0], edx
    *app->getMemory<x86::reg32>(x86::reg32(5022432) /* 0x4ca2e0 */) = cpu.edx;
    // 00489801  8915b8a14c00           -mov dword ptr [0x4ca1b8], edx
    *app->getMemory<x86::reg32>(x86::reg32(5022136) /* 0x4ca1b8 */) = cpu.edx;
    // 00489807  891598ab4c00           -mov dword ptr [0x4cab98], edx
    *app->getMemory<x86::reg32>(x86::reg32(5024664) /* 0x4cab98 */) = cpu.edx;
    // 0048980d  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048980e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_489810(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00489810  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00489811  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00489812  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00489813  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00489814  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00489817  891424                 -mov dword ptr [esp], edx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0048981a  e8ddb40000             -call 0x494cfc
    cpu.esp -= 4;
    sub_494cfc(app, cpu);
    if (cpu.terminate) return;
    // 0048981f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00489821  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00489823  7c5a                   -jl 0x48987f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048987f;
    }
    // 00489825  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 0048982c  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0048982e  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 00489831  81c200845200           -add edx, 0x528400
    (cpu.edx) += x86::reg32(x86::sreg32(5407744 /*0x528400*/));
    // 00489837  0fb6723b               -movzx esi, byte ptr [edx + 0x3b]
    cpu.esi = x86::reg32(*app->getMemory<x86::reg8>(cpu.edx + x86::reg32(59) /* 0x3b */));
    // 0048983b  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0048983d  0f8466000000           -je 0x4898a9
    if (cpu.flags.zf)
    {
        goto L_0x004898a9;
    }
    // 00489843  b900845200             -mov ecx, 0x528400
    cpu.ecx = 5407744 /*0x528400*/;
    // 00489848  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    // 0048984b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0048984d:
    // 0048984d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048984f  8a513b                 -mov dl, byte ptr [ecx + 0x3b]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(59) /* 0x3b */);
    // 00489852  39f2                   +cmp edx, esi
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
    // 00489854  7514                   -jne 0x48986a
    if (!cpu.flags.zf)
    {
        goto L_0x0048986a;
    }
    // 00489856  80790c01               +cmp byte ptr [ecx + 0xc], 1
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
    // 0048985a  750e                   -jne 0x48986a
    if (!cpu.flags.zf)
    {
        goto L_0x0048986a;
    }
    // 0048985c  833900                 +cmp dword ptr [ecx], 0
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
    // 0048985f  7c09                   -jl 0x48986a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048986a;
    }
    // 00489861  31f2                   -xor edx, esi
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00489863  8a5133                 -mov dl, byte ptr [ecx + 0x33]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(51) /* 0x33 */);
    // 00489866  39ea                   +cmp edx, ebp
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
    // 00489868  751c                   -jne 0x489886
    if (!cpu.flags.zf)
    {
        goto L_0x00489886;
    }
L_0x0048986a:
    // 0048986a  43                     -inc ebx
    (cpu.ebx)++;
    // 0048986b  83c160                 -add ecx, 0x60
    (cpu.ecx) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 0048986e  83fb10                 +cmp ebx, 0x10
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
    // 00489871  7cda                   -jl 0x48984d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048984d;
    }
L_0x00489873:
    // 00489873  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00489875:
    // 00489875  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00489877  83c404                 +add esp, 4
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
    // 0048987a  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048987b  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048987c  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048987d  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048987e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048987f:
    // 0048987f  baf8ffffff             -mov edx, 0xfffffff8
    cpu.edx = 4294967288 /*0xfffffff8*/;
    // 00489884  ebef                   -jmp 0x489875
    goto L_0x00489875;
L_0x00489886:
    // 00489886  6683794200             +cmp word ptr [ecx + 0x42], 0
    {
        x86::reg16 tmp1 = *app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(66) /* 0x42 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0048988b  74dd                   -je 0x48986a
    if (cpu.flags.zf)
    {
        goto L_0x0048986a;
    }
    // 0048988d  8a0424                 -mov al, byte ptr [esp]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esp);
    // 00489890  884133                 -mov byte ptr [ecx + 0x33], al
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(51) /* 0x33 */) = cpu.al;
    // 00489893  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00489895  e8c62c0100             -call 0x49c560
    cpu.esp -= 4;
    sub_49c560(app, cpu);
    if (cpu.terminate) return;
    // 0048989a  8b5110                 -mov edx, dword ptr [ecx + 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0048989d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048989f  c1fa10                 +sar edx, 0x10
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
    // 004898a2  e8a94effff             -call 0x47e750
    cpu.esp -= 4;
    sub_47e750(app, cpu);
    if (cpu.terminate) return;
    // 004898a7  ebc1                   -jmp 0x48986a
    goto L_0x0048986a;
L_0x004898a9:
    // 004898a9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004898ab  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    // 004898ae  8a4233                 -mov al, byte ptr [edx + 0x33]
    cpu.al = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(51) /* 0x33 */);
    // 004898b1  39d8                   +cmp eax, ebx
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
    // 004898b3  74be                   -je 0x489873
    if (cpu.flags.zf)
    {
        goto L_0x00489873;
    }
    // 004898b5  66837a4200             +cmp word ptr [edx + 0x42], 0
    {
        x86::reg16 tmp1 = *app->getMemory<x86::reg16>(cpu.edx + x86::reg32(66) /* 0x42 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004898ba  74b7                   -je 0x489873
    if (cpu.flags.zf)
    {
        goto L_0x00489873;
    }
    // 004898bc  8a0424                 -mov al, byte ptr [esp]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esp);
    // 004898bf  884233                 -mov byte ptr [edx + 0x33], al
    *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(51) /* 0x33 */) = cpu.al;
    // 004898c2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004898c4  e8972c0100             -call 0x49c560
    cpu.esp -= 4;
    sub_49c560(app, cpu);
    if (cpu.terminate) return;
    // 004898c9  8b5210                 -mov edx, dword ptr [edx + 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004898cc  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004898ce  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004898d1  e87a4effff             -call 0x47e750
    cpu.esp -= 4;
    sub_47e750(app, cpu);
    if (cpu.terminate) return;
    // 004898d6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004898d8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004898da  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004898dd  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004898de  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004898df  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004898e0  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004898e1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4898e4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004898e4  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004898e5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004898e7  803d6cab4c0000         +cmp byte ptr [0x4cab6c], 0
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
    // 004898ee  7410                   -je 0x489900
    if (cpu.flags.zf)
    {
        goto L_0x00489900;
    }
    // 004898f0  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004898f2  7c05                   -jl 0x4898f9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004898f9;
    }
    // 004898f4  83fa7f                 +cmp edx, 0x7f
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
    // 004898f7  7e0e                   -jle 0x489907
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00489907;
    }
L_0x004898f9:
    // 004898f9  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 004898fe  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004898ff  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00489900:
    // 00489900  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 00489905  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489906  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00489907:
    // 00489907  e8e4af0000             -call 0x4948f0
    cpu.esp -= 4;
    sub_4948f0(app, cpu);
    if (cpu.terminate) return;
    // 0048990c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048990e  e8fdfeffff             -call 0x489810
    cpu.esp -= 4;
    sub_489810(app, cpu);
    if (cpu.terminate) return;
    // 00489913  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00489915  e8eaaf0000             -call 0x494904
    cpu.esp -= 4;
    sub_494904(app, cpu);
    if (cpu.terminate) return;
    // 0048991a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048991c  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048991d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_489920(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00489920  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00489921  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00489922  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00489923  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00489926  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00489928  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0048992a  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0048992c  8a256cab4c00           -mov ah, byte ptr [0x4cab6c]
    cpu.ah = *app->getMemory<x86::reg8>(x86::reg32(5024620) /* 0x4cab6c */);
    // 00489932  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00489934  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 00489936  750c                   -jne 0x489944
    if (!cpu.flags.zf)
    {
        goto L_0x00489944;
    }
    // 00489938  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 0048993d  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00489940  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489941  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489942  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489943  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00489944:
    // 00489944  e8a7af0000             -call 0x4948f0
    cpu.esp -= 4;
    sub_4948f0(app, cpu);
    if (cpu.terminate) return;
    // 00489949  81e7ffff0000           -and edi, 0xffff
    cpu.edi &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0048994f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00489951  81e5ffff0000           -and ebp, 0xffff
    cpu.ebp &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00489957  e8a0b30000             -call 0x494cfc
    cpu.esp -= 4;
    sub_494cfc(app, cpu);
    if (cpu.terminate) return;
    // 0048995c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048995e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00489960  7c60                   -jl 0x4899c2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004899c2;
    }
    // 00489962  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00489963  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00489966  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00489968  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 0048996b  0500845200             -add eax, 0x528400
    (cpu.eax) += x86::reg32(x86::sreg32(5407744 /*0x528400*/));
    // 00489970  8a403b                 -mov al, byte ptr [eax + 0x3b]
    cpu.al = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(59) /* 0x3b */);
    // 00489973  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00489978  89442404               -mov dword ptr [esp + 4], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0048997c  7455                   -je 0x4899d3
    if (cpu.flags.zf)
    {
        goto L_0x004899d3;
    }
    // 0048997e  be00845200             -mov esi, 0x528400
    cpu.esi = 5407744 /*0x528400*/;
    // 00489983  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00489985:
    // 00489985  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00489987  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048998b  8a463b                 -mov al, byte ptr [esi + 0x3b]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(59) /* 0x3b */);
    // 0048998e  39d8                   +cmp eax, ebx
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
    // 00489990  7518                   -jne 0x4899aa
    if (!cpu.flags.zf)
    {
        goto L_0x004899aa;
    }
    // 00489992  807e0c01               +cmp byte ptr [esi + 0xc], 1
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(12) /* 0xc */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00489996  7512                   -jne 0x4899aa
    if (!cpu.flags.zf)
    {
        goto L_0x004899aa;
    }
    // 00489998  833e00                 +cmp dword ptr [esi], 0
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
    // 0048999b  7c0d                   -jl 0x4899aa
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004899aa;
    }
    // 0048999d  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0048999f  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004899a1  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004899a3  e81c4bffff             -call 0x47e4c4
    cpu.esp -= 4;
    sub_47e4c4(app, cpu);
    if (cpu.terminate) return;
    // 004899a8  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x004899aa:
    // 004899aa  41                     -inc ecx
    (cpu.ecx)++;
    // 004899ab  83c660                 -add esi, 0x60
    (cpu.esi) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 004899ae  83f910                 +cmp ecx, 0x10
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
    // 004899b1  7cd2                   -jl 0x489985
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00489985;
    }
    // 004899b3  e84caf0000             -call 0x494904
    cpu.esp -= 4;
    sub_494904(app, cpu);
    if (cpu.terminate) return;
    // 004899b8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004899ba  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004899bb  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004899be  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004899bf  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004899c0  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004899c1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004899c2:
    // 004899c2  e83daf0000             -call 0x494904
    cpu.esp -= 4;
    sub_494904(app, cpu);
    if (cpu.terminate) return;
    // 004899c7  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 004899cc  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004899cf  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004899d0  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004899d1  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004899d2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004899d3:
    // 004899d3  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 004899d5  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004899d7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004899d9  e8e64affff             -call 0x47e4c4
    cpu.esp -= 4;
    sub_47e4c4(app, cpu);
    if (cpu.terminate) return;
    // 004899de  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004899e0  e81faf0000             -call 0x494904
    cpu.esp -= 4;
    sub_494904(app, cpu);
    if (cpu.terminate) return;
    // 004899e5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004899e7  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004899e8  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004899eb  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004899ec  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004899ed  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004899ee  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4899f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004899f0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004899f1  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004899f2  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004899f5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004899f7  89542404               -mov dword ptr [esp + 4], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004899fb  803d6cab4c0000         +cmp byte ptr [0x4cab6c], 0
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
    // 00489a02  7416                   -je 0x489a1a
    if (cpu.flags.zf)
    {
        goto L_0x00489a1a;
    }
    // 00489a04  83fa7f                 +cmp edx, 0x7f
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
    // 00489a07  7f04                   -jg 0x489a0d
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00489a0d;
    }
    // 00489a09  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00489a0b  7d14                   -jge 0x489a21
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00489a21;
    }
L_0x00489a0d:
    // 00489a0d  baf8ffffff             -mov edx, 0xfffffff8
    cpu.edx = 4294967288 /*0xfffffff8*/;
L_0x00489a12:
    // 00489a12  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00489a14  83c408                 +add esp, 8
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
    // 00489a17  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489a18  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489a19  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00489a1a:
    // 00489a1a  baf6ffffff             -mov edx, 0xfffffff6
    cpu.edx = 4294967286 /*0xfffffff6*/;
    // 00489a1f  ebf1                   -jmp 0x489a12
    goto L_0x00489a12;
L_0x00489a21:
    // 00489a21  e8caae0000             -call 0x4948f0
    cpu.esp -= 4;
    sub_4948f0(app, cpu);
    if (cpu.terminate) return;
    // 00489a26  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00489a28  e8cfb20000             -call 0x494cfc
    cpu.esp -= 4;
    sub_494cfc(app, cpu);
    if (cpu.terminate) return;
    // 00489a2d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00489a2f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00489a31  0f8ca2000000           -jl 0x489ad9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00489ad9;
    }
    // 00489a37  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00489a38  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00489a39  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00489a3a  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00489a3d  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00489a3f  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00489a42  0500845200             -add eax, 0x528400
    (cpu.eax) += x86::reg32(x86::sreg32(5407744 /*0x528400*/));
    // 00489a47  0fb6783b               -movzx edi, byte ptr [eax + 0x3b]
    cpu.edi = x86::reg32(*app->getMemory<x86::reg8>(cpu.eax + x86::reg32(59) /* 0x3b */));
    // 00489a4b  83ea40                 -sub edx, 0x40
    (cpu.edx) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00489a4e  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00489a50  0f849d000000           -je 0x489af3
    if (cpu.flags.zf)
    {
        goto L_0x00489af3;
    }
    // 00489a56  b900845200             -mov ecx, 0x528400
    cpu.ecx = 5407744 /*0x528400*/;
    // 00489a5b  8954240c               -mov dword ptr [esp + 0xc], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00489a5f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00489a61  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
L_0x00489a63:
    // 00489a63  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00489a65  8a413b                 -mov al, byte ptr [ecx + 0x3b]
    cpu.al = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(59) /* 0x3b */);
    // 00489a68  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00489a6a  39f8                   +cmp eax, edi
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
    // 00489a6c  7550                   -jne 0x489abe
    if (!cpu.flags.zf)
    {
        goto L_0x00489abe;
    }
    // 00489a6e  80790c01               +cmp byte ptr [ecx + 0xc], 1
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
    // 00489a72  754a                   -jne 0x489abe
    if (!cpu.flags.zf)
    {
        goto L_0x00489abe;
    }
    // 00489a74  3b29                   +cmp ebp, dword ptr [ecx]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ecx)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00489a76  7f46                   -jg 0x489abe
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00489abe;
    }
    // 00489a78  8a6137                 -mov ah, byte ptr [ecx + 0x37]
    cpu.ah = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(55) /* 0x37 */);
    // 00489a7b  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00489a7f  80fc01                 +cmp ah, 1
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00489a82  7410                   -je 0x489a94
    if (cpu.flags.zf)
    {
        goto L_0x00489a94;
    }
    // 00489a84  8b5134                 -mov edx, dword ptr [ecx + 0x34]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(52) /* 0x34 */);
    // 00489a87  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00489a8b  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 00489a8e  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 00489a91  83c240                 -add edx, 0x40
    (cpu.edx) += x86::reg32(x86::sreg32(64 /*0x40*/));
L_0x00489a94:
    // 00489a94  8b462f                 -mov eax, dword ptr [esi + 0x2f]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(47) /* 0x2f */);
    // 00489a97  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 00489a9a  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00489a9c  83ea40                 -sub edx, 0x40
    (cpu.edx) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00489a9f  83fa7f                 +cmp edx, 0x7f
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
    // 00489aa2  7e47                   -jle 0x489aeb
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00489aeb;
    }
    // 00489aa4  ba7f000000             -mov edx, 0x7f
    cpu.edx = 127 /*0x7f*/;
L_0x00489aa9:
    // 00489aa9  8b4650                 -mov eax, dword ptr [esi + 0x50]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(80) /* 0x50 */);
    // 00489aac  39c5                   +cmp ebp, eax
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00489aae  7404                   -je 0x489ab4
    if (cpu.flags.zf)
    {
        goto L_0x00489ab4;
    }
    // 00489ab0  0fbe1402               -movsx edx, byte ptr [edx + eax]
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(*app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1)));
L_0x00489ab4:
    // 00489ab4  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00489ab6  88560f                 -mov byte ptr [esi + 0xf], dl
    *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(15) /* 0xf */) = cpu.dl;
    // 00489ab9  e85649ffff             -call 0x47e414
    cpu.esp -= 4;
    sub_47e414(app, cpu);
    if (cpu.terminate) return;
L_0x00489abe:
    // 00489abe  43                     -inc ebx
    (cpu.ebx)++;
    // 00489abf  83c160                 -add ecx, 0x60
    (cpu.ecx) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 00489ac2  83fb10                 +cmp ebx, 0x10
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
    // 00489ac5  7c9c                   -jl 0x489a63
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00489a63;
    }
    // 00489ac7  e838ae0000             -call 0x494904
    cpu.esp -= 4;
    sub_494904(app, cpu);
    if (cpu.terminate) return;
    // 00489acc  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00489ace  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489acf  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489ad0  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489ad1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00489ad3  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00489ad6  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489ad7  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489ad8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00489ad9:
    // 00489ad9  e826ae0000             -call 0x494904
    cpu.esp -= 4;
    sub_494904(app, cpu);
    if (cpu.terminate) return;
    // 00489ade  baf8ffffff             -mov edx, 0xfffffff8
    cpu.edx = 4294967288 /*0xfffffff8*/;
    // 00489ae3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00489ae5  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00489ae8  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489ae9  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489aea  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00489aeb:
    // 00489aeb  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00489aed  7dba                   -jge 0x489aa9
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00489aa9;
    }
    // 00489aef  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00489af1  ebb6                   -jmp 0x489aa9
    goto L_0x00489aa9;
L_0x00489af3:
    // 00489af3  80783701               +cmp byte ptr [eax + 0x37], 1
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(55) /* 0x37 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00489af7  7410                   -je 0x489b09
    if (cpu.flags.zf)
    {
        goto L_0x00489b09;
    }
    // 00489af9  8b5834                 -mov ebx, dword ptr [eax + 0x34]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    // 00489afc  c1fb18                 -sar ebx, 0x18
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (24 /*0x18*/ % 32));
    // 00489aff  0fafd3                 -imul edx, ebx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 00489b02  83c240                 -add edx, 0x40
    (cpu.edx) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00489b05  89542410               -mov dword ptr [esp + 0x10], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
L_0x00489b09:
    // 00489b09  8b502f                 -mov edx, dword ptr [eax + 0x2f]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(47) /* 0x2f */);
    // 00489b0c  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00489b10  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 00489b13  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 00489b15  83ea40                 -sub edx, 0x40
    (cpu.edx) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00489b18  89542410               -mov dword ptr [esp + 0x10], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 00489b1c  83fa7f                 +cmp edx, 0x7f
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
    // 00489b1f  7e41                   -jle 0x489b62
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00489b62;
    }
    // 00489b21  c74424107f000000       -mov dword ptr [esp + 0x10], 0x7f
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = 127 /*0x7f*/;
L_0x00489b29:
    // 00489b29  8b7050                 -mov esi, dword ptr [eax + 0x50]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(80) /* 0x50 */);
    // 00489b2c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00489b2e  740e                   -je 0x489b3e
    if (cpu.flags.zf)
    {
        goto L_0x00489b3e;
    }
    // 00489b30  8b7c2410               -mov edi, dword ptr [esp + 0x10]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00489b34  8d143e                 -lea edx, [esi + edi]
    cpu.edx = x86::reg32(cpu.esi + cpu.edi * 1);
    // 00489b37  0fbe12                 -movsx edx, byte ptr [edx]
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(*app->getMemory<x86::reg8>(cpu.edx)));
    // 00489b3a  89542410               -mov dword ptr [esp + 0x10], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
L_0x00489b3e:
    // 00489b3e  8a542410               -mov dl, byte ptr [esp + 0x10]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00489b42  88500f                 -mov byte ptr [eax + 0xf], dl
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(15) /* 0xf */) = cpu.dl;
    // 00489b45  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00489b49  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00489b4b  e8c448ffff             -call 0x47e414
    cpu.esp -= 4;
    sub_47e414(app, cpu);
    if (cpu.terminate) return;
    // 00489b50  e8afad0000             -call 0x494904
    cpu.esp -= 4;
    sub_494904(app, cpu);
    if (cpu.terminate) return;
    // 00489b55  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00489b57  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489b58  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489b59  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489b5a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00489b5c  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00489b5f  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489b60  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489b61  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00489b62:
    // 00489b62  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00489b64  7dc3                   -jge 0x489b29
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00489b29;
    }
    // 00489b66  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00489b68  89542410               -mov dword ptr [esp + 0x10], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 00489b6c  ebbb                   -jmp 0x489b29
    goto L_0x00489b29;
}

/* align: skip 0x00 0x00 */
void Application::sub_489b70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00489b70  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00489b71  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00489b76  e811000000             -call 0x489b8c
    cpu.esp -= 4;
    sub_489b8c(app, cpu);
    if (cpu.terminate) return;
    // 00489b7b  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489b7c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_489b80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00489b80  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00489b81  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00489b83  e804000000             -call 0x489b8c
    cpu.esp -= 4;
    sub_489b8c(app, cpu);
    if (cpu.terminate) return;
    // 00489b88  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489b89  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_489b8c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00489b8c  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00489b8d  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00489b8e  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00489b91  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00489b95  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00489b96  8d5c2408               -lea ebx, [esp + 8]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00489b9a  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00489b9e  e82518ffff             -call 0x47b3c8
    cpu.esp -= 4;
    sub_47b3c8(app, cpu);
    if (cpu.terminate) return;
    // 00489ba3  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    // 00489ba6  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00489ba8  750a                   -jne 0x489bb4
    if (!cpu.flags.zf)
    {
        goto L_0x00489bb4;
    }
    // 00489baa  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00489bae  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00489bb1  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489bb2  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489bb3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00489bb4:
    // 00489bb4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00489bb6  e8f51affff             -call 0x47b6b0
    cpu.esp -= 4;
    sub_47b6b0(app, cpu);
    if (cpu.terminate) return;
    // 00489bbb  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00489bbf  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00489bc2  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489bc3  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489bc4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_489bd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00489bd0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00489bd1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00489bd2  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00489bd3  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00489bd4  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00489bd6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00489bd8  7f07                   -jg 0x489be1
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00489be1;
    }
    // 00489bda  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00489bdc:
    // 00489bdc  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489bdd  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489bde  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489bdf  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489be0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00489be1:
    // 00489be1  8d500c                 -lea edx, [eax + 0xc]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00489be4  bb00030000             -mov ebx, 0x300
    cpu.ebx = 768 /*0x300*/;
    // 00489be9  b88ceb4b00             -mov eax, 0x4beb8c
    cpu.eax = 4975500 /*0x4beb8c*/;
    // 00489bee  e875eafeff             -call 0x478668
    cpu.esp -= 4;
    sub_478668(app, cpu);
    if (cpu.terminate) return;
    // 00489bf3  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00489bf5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00489bf7  74e3                   -je 0x489bdc
    if (cpu.flags.zf)
    {
        goto L_0x00489bdc;
    }
    // 00489bf9  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 00489bfe  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00489c00  b8a8eb4b00             -mov eax, 0x4beba8
    cpu.eax = 4975528 /*0x4beba8*/;
    // 00489c05  83c108                 -add ecx, 8
    (cpu.ecx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00489c08  e8436bffff             -call 0x480750
    cpu.esp -= 4;
    sub_480750(app, cpu);
    if (cpu.terminate) return;
    // 00489c0d  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 00489c12  b8b0eb4b00             -mov eax, 0x4bebb0
    cpu.eax = 4975536 /*0x4bebb0*/;
    // 00489c17  8d1431                 -lea edx, [ecx + esi]
    cpu.edx = x86::reg32(cpu.ecx + cpu.esi * 1);
    // 00489c1a  8971fc                 -mov dword ptr [ecx - 4], esi
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */) = cpu.esi;
    // 00489c1d  e82e6bffff             -call 0x480750
    cpu.esp -= 4;
    sub_480750(app, cpu);
    if (cpu.terminate) return;
    // 00489c22  8b15eca24c00           -mov edx, dword ptr [0x4ca2ec]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5022444) /* 0x4ca2ec */);
    // 00489c28  42                     -inc edx
    (cpu.edx)++;
    // 00489c29  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00489c2b  8915eca24c00           -mov dword ptr [0x4ca2ec], edx
    *app->getMemory<x86::reg32>(x86::reg32(5022444) /* 0x4ca2ec */) = cpu.edx;
    // 00489c31  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489c32  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489c33  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489c34  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489c35  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_489c38(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00489c38  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00489c39  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00489c3a  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00489c3b  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00489c3c  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00489c3d  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00489c3e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00489c40  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 00489c45  bfa8eb4b00             -mov edi, 0x4beba8
    cpu.edi = 4975528 /*0x4beba8*/;
    // 00489c4a  8d70f8                 -lea esi, [eax - 8]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(-8) /* -0x8 */);
    // 00489c4d  8b58fc                 -mov ebx, dword ptr [eax - 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 00489c50  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00489c52  f3a6                   +repe cmpsb byte ptr [esi], byte ptr es:[edi]
    while (cpu.ecx)
    {
        {
            x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.esi);
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
            cpu.esi -= 1;
        }
        else
        {
            cpu.edi += 1;
            cpu.esi += 1;
        }
        --cpu.ecx;
        if (!cpu.flags.zf)
            break;
    }
    // 00489c54  7405                   -je 0x489c5b
    if (cpu.flags.zf)
    {
        goto L_0x00489c5b;
    }
    // 00489c56  19c0                   +sbb eax, eax
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax)) + cpu.flags.cf;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00489c58  83d8ff                 -sbb eax, -1
    (cpu.eax) -= x86::reg32(x86::sreg32(-1 /*-0x1*/) + cpu.flags.cf);
L_0x00489c5b:
    // 00489c5b  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00489c5d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00489c5f  7557                   -jne 0x489cb8
    if (!cpu.flags.zf)
    {
        goto L_0x00489cb8;
    }
    // 00489c61  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00489c63  7e53                   -jle 0x489cb8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00489cb8;
    }
    // 00489c65  81fb00000002           +cmp ebx, 0x2000000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(33554432 /*0x2000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00489c6b  7d4b                   -jge 0x489cb8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00489cb8;
    }
    // 00489c6d  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 00489c72  bfb0eb4b00             -mov edi, 0x4bebb0
    cpu.edi = 4975536 /*0x4bebb0*/;
    // 00489c77  8d341a                 -lea esi, [edx + ebx]
    cpu.esi = x86::reg32(cpu.edx + cpu.ebx * 1);
    // 00489c7a  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00489c7c  f3a6                   +repe cmpsb byte ptr [esi], byte ptr es:[edi]
    while (cpu.ecx)
    {
        {
            x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.esi);
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
            cpu.esi -= 1;
        }
        else
        {
            cpu.edi += 1;
            cpu.esi += 1;
        }
        --cpu.ecx;
        if (!cpu.flags.zf)
            break;
    }
    // 00489c7e  7405                   -je 0x489c85
    if (cpu.flags.zf)
    {
        goto L_0x00489c85;
    }
    // 00489c80  19c0                   +sbb eax, eax
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax)) + cpu.flags.cf;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00489c82  83d8ff                 -sbb eax, -1
    (cpu.eax) -= x86::reg32(x86::sreg32(-1 /*-0x1*/) + cpu.flags.cf);
L_0x00489c85:
    // 00489c85  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00489c87  752f                   -jne 0x489cb8
    if (!cpu.flags.zf)
    {
        goto L_0x00489cb8;
    }
    // 00489c89  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
L_0x00489c8e:
    // 00489c8e  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 00489c93  8d4af8                 -lea ecx, [edx - 8]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(-8) /* -0x8 */);
    // 00489c96  b8b8eb4b00             -mov eax, 0x4bebb8
    cpu.eax = 4975544 /*0x4bebb8*/;
    // 00489c9b  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00489c9d  e8ae6affff             -call 0x480750
    cpu.esp -= 4;
    sub_480750(app, cpu);
    if (cpu.terminate) return;
    // 00489ca2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00489ca4  e823eefeff             -call 0x478acc
    cpu.esp -= 4;
    sub_478acc(app, cpu);
    if (cpu.terminate) return;
    // 00489ca9  ff0deca24c00           -dec dword ptr [0x4ca2ec]
    (*app->getMemory<x86::reg32>(x86::reg32(5022444) /* 0x4ca2ec */))--;
    // 00489caf  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00489cb1  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489cb2  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489cb3  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489cb4  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489cb5  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489cb6  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489cb7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00489cb8:
    // 00489cb8  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00489cba  75d2                   -jne 0x489c8e
    if (!cpu.flags.zf)
    {
        goto L_0x00489c8e;
    }
    // 00489cbc  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 00489cc1  bfb8eb4b00             -mov edi, 0x4bebb8
    cpu.edi = 4975544 /*0x4bebb8*/;
    // 00489cc6  8d72f8                 -lea esi, [edx - 8]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(-8) /* -0x8 */);
    // 00489cc9  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00489ccb  f3a6                   +repe cmpsb byte ptr [esi], byte ptr es:[edi]
    while (cpu.ecx)
    {
        {
            x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.esi);
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
            cpu.esi -= 1;
        }
        else
        {
            cpu.edi += 1;
            cpu.esi += 1;
        }
        --cpu.ecx;
        if (!cpu.flags.zf)
            break;
    }
    // 00489ccd  7405                   -je 0x489cd4
    if (cpu.flags.zf)
    {
        goto L_0x00489cd4;
    }
    // 00489ccf  19c0                   +sbb eax, eax
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax)) + cpu.flags.cf;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00489cd1  83d8ff                 -sbb eax, -1
    (cpu.eax) -= x86::reg32(x86::sreg32(-1 /*-0x1*/) + cpu.flags.cf);
L_0x00489cd4:
    // 00489cd4  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00489cd6  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489cd7  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489cd8  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489cd9  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489cda  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489cdb  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489cdc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_489ce0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00489ce0  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00489ce3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_489ce4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00489ce4  3b5008                 +cmp edx, dword ptr [eax + 8]
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
    // 00489ce7  7305                   -jae 0x489cee
    if (!cpu.flags.cf)
    {
        goto L_0x00489cee;
    }
    // 00489ce9  0344d014               -add eax, dword ptr [eax + edx*8 + 0x14]
    (cpu.eax) += x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */ + cpu.edx * 8)));
    // 00489ced  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00489cee:
    // 00489cee  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00489cf0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_489cf1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00489cf1  3b5008                 +cmp edx, dword ptr [eax + 8]
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
    // 00489cf4  7307                   -jae 0x489cfd
    if (!cpu.flags.cf)
    {
        goto L_0x00489cfd;
    }
    // 00489cf6  8b44d010               -mov eax, dword ptr [eax + edx*8 + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */ + cpu.edx * 8);
    // 00489cfa  8903                   -mov dword ptr [ebx], eax
    *app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 00489cfc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00489cfd:
    // 00489cfd  c70300000000           -mov dword ptr [ebx], 0
    *app->getMemory<x86::reg32>(cpu.ebx) = 0 /*0x0*/;
    // 00489d03  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_489d30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00489d30  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00489d31  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00489d32  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00489d35  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00489d37  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00489d39  7c1f                   -jl 0x489d5a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00489d5a;
    }
L_0x00489d3b:
    // 00489d3b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00489d3d  7c24                   -jl 0x489d63
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00489d63;
    }
L_0x00489d3f:
    // 00489d3f  39d0                   +cmp eax, edx
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
    // 00489d41  7527                   -jne 0x489d6a
    if (!cpu.flags.zf)
    {
        goto L_0x00489d6a;
    }
    // 00489d43  b800200000             -mov eax, 0x2000
    cpu.eax = 8192 /*0x2000*/;
    // 00489d48  83f907                 +cmp ecx, 7
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00489d4b  7707                   -ja 0x489d54
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00489d54;
    }
    // 00489d4d  ff248d109d4800         -jmp dword ptr [ecx*4 + 0x489d10]
    cpu.ip = *app->getMemory<x86::reg32>(4758800 + cpu.ecx * 4); goto dynamic_jump;
  case 0x00489d54:
L_0x00489d54:
    // 00489d54  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00489d57  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489d58  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489d59  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00489d5a:
    // 00489d5a  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 00489d5f  f7da                   +neg edx
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
    // 00489d61  ebd8                   -jmp 0x489d3b
    goto L_0x00489d3b;
L_0x00489d63:
    // 00489d63  80c904                 -or cl, 4
    cpu.cl |= x86::reg8(x86::sreg8(4 /*0x4*/));
    // 00489d66  f7d8                   +neg eax
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
    // 00489d68  ebd5                   -jmp 0x489d3f
    goto L_0x00489d3f;
L_0x00489d6a:
    // 00489d6a  39c2                   +cmp edx, eax
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
    // 00489d6c  7d09                   -jge 0x489d77
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00489d77;
    }
    // 00489d6e  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00489d70  80c901                 -or cl, 1
    cpu.cl |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00489d73  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00489d75  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
L_0x00489d77:
    // 00489d77  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00489d78  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00489d79  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00489d7d  ba20000000             -mov edx, 0x20
    cpu.edx = 32 /*0x20*/;
    // 00489d82  e8c12c0100             -call 0x49ca48
    cpu.esp -= 4;
    sub_49ca48(app, cpu);
    if (cpu.terminate) return;
    // 00489d87  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00489d8b  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00489d8c  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00489d90  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00489d91  e82e290100             -call 0x49c6c4
    cpu.esp -= 4;
    sub_49c6c4(app, cpu);
    if (cpu.terminate) return;
    // 00489d96  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00489d98  c1e818                 -shr eax, 0x18
    cpu.eax >>= 24 /*0x18*/ % 32;
    // 00489d9b  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 00489da2  c1ee08                 -shr esi, 8
    cpu.esi >>= 8 /*0x8*/ % 32;
    // 00489da5  8b8260c44c00           -mov eax, dword ptr [edx + 0x4cc460]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5031008) /* 0x4cc460 */);
    // 00489dab  8b9264c44c00           -mov edx, dword ptr [edx + 0x4cc464]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5031012) /* 0x4cc464 */);
    // 00489db1  81e6ffff0000           -and esi, 0xffff
    cpu.esi &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00489db7  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00489db9  0fafd6                 -imul edx, esi
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 00489dbc  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 00489dbf  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00489dc1  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489dc2  83f907                 +cmp ecx, 7
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00489dc5  778d                   -ja 0x489d54
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00489d54;
    }
    // 00489dc7  ff248d109d4800         -jmp dword ptr [ecx*4 + 0x489d10]
    cpu.ip = *app->getMemory<x86::reg32>(4758800 + cpu.ecx * 4); goto dynamic_jump;
  case 0x00489dce:
    // 00489dce  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
  [[fallthrough]];
  case 0x00489dd0:
    // 00489dd0  0500400000             -add eax, 0x4000
    (cpu.eax) += x86::reg32(x86::sreg32(16384 /*0x4000*/));
    // 00489dd5  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00489dd8  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489dd9  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489dda  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00489ddb:
    // 00489ddb  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 00489ddd  0500800000             -add eax, 0x8000
    (cpu.eax) += x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 00489de2  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00489de5  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489de6  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489de7  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00489de8:
    // 00489de8  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 00489dea  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00489ded  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489dee  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489def  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00489df0:
    // 00489df0  2d00400000             -sub eax, 0x4000
    (cpu.eax) -= x86::reg32(x86::sreg32(16384 /*0x4000*/));
    // 00489df5  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00489df8  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489df9  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489dfa  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00489dfb:
    // 00489dfb  050080ffff             -add eax, 0xffff8000
    (cpu.eax) += x86::reg32(x86::sreg32(4294934528 /*0xffff8000*/));
    // 00489e00  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00489e03  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489e04  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489e05  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00489e06:
    // 00489e06  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 00489e08  2d00400000             -sub eax, 0x4000
    (cpu.eax) -= x86::reg32(x86::sreg32(16384 /*0x4000*/));
    // 00489e0d  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00489e10  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489e11  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489e12  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_489e20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00489e20  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00489e21  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00489e22  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00489e25  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00489e27  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00489e29  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00489e2b  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00489e2f  e8cc2c0100             -call 0x49cb00
    cpu.esp -= 4;
    sub_49cb00(app, cpu);
    if (cpu.terminate) return;
    // 00489e34  c70100000100           -mov dword ptr [ecx], 0x10000
    *app->getMemory<x86::reg32>(cpu.ecx) = 65536 /*0x10000*/;
    // 00489e3a  c7410400000000         -mov dword ptr [ecx + 4], 0
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00489e41  c7410800000000         -mov dword ptr [ecx + 8], 0
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 00489e48  c7410c00000000         -mov dword ptr [ecx + 0xc], 0
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 00489e4f  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 00489e52  894110                 -mov dword ptr [ecx + 0x10], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00489e55  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00489e59  c7411800000000         -mov dword ptr [ecx + 0x18], 0
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 00489e60  894114                 -mov dword ptr [ecx + 0x14], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00489e63  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00489e67  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00489e69  89411c                 -mov dword ptr [ecx + 0x1c], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00489e6c  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 00489e6e  89511c                 -mov dword ptr [ecx + 0x1c], edx
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 00489e71  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 00489e74  894120                 -mov dword ptr [ecx + 0x20], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 00489e77  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00489e7a  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489e7b  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489e7c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_489e80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00489e80  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00489e81  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00489e82  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00489e85  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00489e87  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00489e89  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00489e8b  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00489e8f  e86c2c0100             -call 0x49cb00
    cpu.esp -= 4;
    sub_49cb00(app, cpu);
    if (cpu.terminate) return;
    // 00489e94  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 00489e97  c7410400000000         -mov dword ptr [ecx + 4], 0
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00489e9e  8901                   -mov dword ptr [ecx], eax
    *app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 00489ea0  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00489ea4  c7410c00000000         -mov dword ptr [ecx + 0xc], 0
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 00489eab  c7411000000100         -mov dword ptr [ecx + 0x10], 0x10000
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = 65536 /*0x10000*/;
    // 00489eb2  c7411400000000         -mov dword ptr [ecx + 0x14], 0
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 00489eb9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00489ebb  894108                 -mov dword ptr [ecx + 8], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00489ebe  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 00489ec0  895108                 -mov dword ptr [ecx + 8], edx
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00489ec3  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00489ec7  c7411c00000000         -mov dword ptr [ecx + 0x1c], 0
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 00489ece  894118                 -mov dword ptr [ecx + 0x18], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00489ed1  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 00489ed4  894120                 -mov dword ptr [ecx + 0x20], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 00489ed7  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00489eda  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489edb  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489edc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_489ee0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00489ee0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00489ee1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00489ee2  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00489ee5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00489ee7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00489ee9  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00489eeb  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00489eef  e80c2c0100             -call 0x49cb00
    cpu.esp -= 4;
    sub_49cb00(app, cpu);
    if (cpu.terminate) return;
    // 00489ef4  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 00489ef7  8901                   -mov dword ptr [ecx], eax
    *app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 00489ef9  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00489efd  c7410800000000         -mov dword ptr [ecx + 8], 0
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 00489f04  894104                 -mov dword ptr [ecx + 4], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00489f07  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00489f0b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00489f0d  89410c                 -mov dword ptr [ecx + 0xc], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00489f10  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 00489f12  89510c                 -mov dword ptr [ecx + 0xc], edx
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00489f15  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 00489f18  c7411400000000         -mov dword ptr [ecx + 0x14], 0
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 00489f1f  c7411800000000         -mov dword ptr [ecx + 0x18], 0
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 00489f26  c7411c00000000         -mov dword ptr [ecx + 0x1c], 0
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 00489f2d  c7412000000100         -mov dword ptr [ecx + 0x20], 0x10000
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = 65536 /*0x10000*/;
    // 00489f34  894110                 -mov dword ptr [ecx + 0x10], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00489f37  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00489f3a  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489f3b  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489f3c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_489f40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00489f40  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00489f41  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00489f42  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00489f43  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00489f44  83ec34                 -sub esp, 0x34
    (cpu.esp) -= x86::reg32(x86::sreg32(52 /*0x34*/));
    // 00489f47  89542428               -mov dword ptr [esp + 0x28], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 00489f4b  895c2424               -mov dword ptr [esp + 0x24], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 00489f4f  8b6c2428               -mov ebp, dword ptr [esp + 0x28]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00489f53  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00489f55  8944242c               -mov dword ptr [esp + 0x2c], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 00489f59  89542430               -mov dword ptr [esp + 0x30], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.edx;
    // 00489f5d  83c50c                 -add ebp, 0xc
    (cpu.ebp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x00489f60:
    // 00489f60  8b74242c               -mov esi, dword ptr [esp + 0x2c]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00489f64  8b7c2430               -mov edi, dword ptr [esp + 0x30]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00489f68  8b4c2428               -mov ecx, dword ptr [esp + 0x28]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00489f6c  c1e702                 -shl edi, 2
    cpu.edi <<= 2 /*0x2*/ % 32;
L_0x00489f6f:
    // 00489f6f  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx);
    // 00489f71  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi);
    // 00489f73  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00489f75  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00489f78  c1e810                 +shr eax, 0x10
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
    // 00489f7b  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00489f7d  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00489f7f  8b510c                 -mov edx, dword ptr [ecx + 0xc]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00489f82  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00489f85  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00489f87  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00489f8a  c1e810                 +shr eax, 0x10
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
    // 00489f8d  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00489f8f  8b5118                 -mov edx, dword ptr [ecx + 0x18]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 00489f92  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00489f94  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00489f97  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00489f9a  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00489f9c  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00489f9f  c1e810                 +shr eax, 0x10
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
    // 00489fa2  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00489fa4  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00489fa6  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00489fa9  895c3cfc               -mov dword ptr [esp + edi - 4], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(-4) /* -0x4 */ + cpu.edi * 1) = cpu.ebx;
    // 00489fad  39e9                   +cmp ecx, ebp
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
    // 00489faf  75be                   -jne 0x489f6f
    if (!cpu.flags.zf)
    {
        goto L_0x00489f6f;
    }
    // 00489fb1  8b4c242c               -mov ecx, dword ptr [esp + 0x2c]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00489fb5  8b5c2430               -mov ebx, dword ptr [esp + 0x30]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00489fb9  83c10c                 -add ecx, 0xc
    (cpu.ecx) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00489fbc  83c303                 -add ebx, 3
    (cpu.ebx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00489fbf  894c242c               -mov dword ptr [esp + 0x2c], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.ecx;
    // 00489fc3  895c2430               -mov dword ptr [esp + 0x30], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.ebx;
    // 00489fc7  83fb09                 +cmp ebx, 9
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9 /*0x9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00489fca  7c94                   -jl 0x489f60
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00489f60;
    }
    // 00489fcc  bb24000000             -mov ebx, 0x24
    cpu.ebx = 36 /*0x24*/;
    // 00489fd1  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00489fd5  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00489fd7  e87467ffff             -call 0x480750
    cpu.esp -= 4;
    sub_480750(app, cpu);
    if (cpu.terminate) return;
    // 00489fdc  83c434                 -add esp, 0x34
    (cpu.esp) += x86::reg32(x86::sreg32(52 /*0x34*/));
    // 00489fdf  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489fe0  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489fe1  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489fe2  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489fe3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_489ff0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00489ff0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00489ff1  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00489ff2  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00489ff3  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00489ff6  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00489ff8  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00489ffa  e8a99b0000             -call 0x493ba8
    cpu.esp -= 4;
    sub_493ba8(app, cpu);
    if (cpu.terminate) return;
    // 00489fff  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048a001  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048a003  752c                   -jne 0x48a031
    if (!cpu.flags.zf)
    {
        goto L_0x0048a031;
    }
    // 0048a005  b890010000             -mov eax, 0x190
    cpu.eax = 400 /*0x190*/;
    // 0048a00a  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 0048a00c  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048a010  e89fa60000             -call 0x4946b4
    cpu.esp -= 4;
    sub_4946b4(app, cpu);
    if (cpu.terminate) return;
    // 0048a015  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048a016  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048a018  8d5c2408               -lea ebx, [esp + 8]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048a01c  e8a713ffff             -call 0x47b3c8
    cpu.esp -= 4;
    sub_47b3c8(app, cpu);
    if (cpu.terminate) return;
    // 0048a021  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    // 0048a024  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048a026  7522                   -jne 0x48a04a
    if (!cpu.flags.zf)
    {
        goto L_0x0048a04a;
    }
    // 0048a028  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0048a02a:
    // 0048a02a  83c40c                 +add esp, 0xc
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
    // 0048a02d  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a02e  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a02f  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a030  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048a031:
    // 0048a031  e82eeffeff             -call 0x478f64
    cpu.esp -= 4;
    sub_478f64(app, cpu);
    if (cpu.terminate) return;
    // 0048a036  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048a038  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048a03a  e81167ffff             -call 0x480750
    cpu.esp -= 4;
    sub_480750(app, cpu);
    if (cpu.terminate) return;
    // 0048a03f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048a041  e886eafeff             -call 0x478acc
    cpu.esp -= 4;
    sub_478acc(app, cpu);
    if (cpu.terminate) return;
    // 0048a046  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048a048  ebe0                   -jmp 0x48a02a
    goto L_0x0048a02a;
L_0x0048a04a:
    // 0048a04a  b9c2010000             -mov ecx, 0x1c2
    cpu.ecx = 450 /*0x1c2*/;
    // 0048a04f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048a051  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0048a054  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0048a056  0590010000             -add eax, 0x190
    (cpu.eax) += x86::reg32(x86::sreg32(400 /*0x190*/));
    // 0048a05b  e854a60000             -call 0x4946b4
    cpu.esp -= 4;
    sub_4946b4(app, cpu);
    if (cpu.terminate) return;
    // 0048a060  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0048a062  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    // 0048a065  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048a069  e84a16ffff             -call 0x47b6b8
    cpu.esp -= 4;
    sub_47b6b8(app, cpu);
    if (cpu.terminate) return;
    // 0048a06e  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 0048a071  a354824c00             -mov dword ptr [0x4c8254], eax
    *app->getMemory<x86::reg32>(x86::reg32(5014100) /* 0x4c8254 */) = cpu.eax;
    // 0048a076  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048a07a  e83116ffff             -call 0x47b6b0
    cpu.esp -= 4;
    sub_47b6b0(app, cpu);
    if (cpu.terminate) return;
    // 0048a07f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048a081  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0048a084  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a085  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a086  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a087  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48a088(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048a088  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048a089  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0048a08e  e85dffffff             -call 0x489ff0
    cpu.esp -= 4;
    sub_489ff0(app, cpu);
    if (cpu.terminate) return;
    // 0048a093  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a094  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48a098(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048a098  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048a099  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048a09b  e850ffffff             -call 0x489ff0
    cpu.esp -= 4;
    sub_489ff0(app, cpu);
    if (cpu.terminate) return;
    // 0048a0a0  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a0a1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_48a0b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048a0b0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048a0b1  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048a0b2  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048a0b3  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0048a0b5  b903000000             -mov ecx, 3
    cpu.ecx = 3 /*0x3*/;
    // 0048a0ba  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048a0bc  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0048a0bf  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 0048a0c1  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0048a0c3  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0048a0c5  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0048a0cc  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0048a0ce  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048a0d0  8a6701                 -mov ah, byte ptr [edi + 1]
    cpu.ah = *app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 0048a0d3  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048a0d5  80fcfb                 +cmp ah, 0xfb
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(251 /*0xfb*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048a0d8  7518                   -jne 0x48a0f2
    if (!cpu.flags.zf)
    {
        goto L_0x0048a0f2;
    }
L_0x0048a0da:
    // 0048a0da  8a06                   -mov al, byte ptr [esi]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esi);
    // 0048a0dc  24fe                   -and al, 0xfe
    cpu.al &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 0048a0de  3c32                   +cmp al, 0x32
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(50 /*0x32*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048a0e0  7317                   -jae 0x48a0f9
    if (!cpu.flags.cf)
    {
        goto L_0x0048a0f9;
    }
    // 0048a0e2  3c10                   +cmp al, 0x10
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048a0e4  7206                   -jb 0x48a0ec
    if (cpu.flags.cf)
    {
        goto L_0x0048a0ec;
    }
    // 0048a0e6  763c                   -jbe 0x48a124
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0048a124;
    }
    // 0048a0e8  3c30                   +cmp al, 0x30
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
    // 0048a0ea  7417                   -je 0x48a103
    if (cpu.flags.zf)
    {
        goto L_0x0048a103;
    }
L_0x0048a0ec:
    // 0048a0ec  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048a0ee  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a0ef  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a0f0  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a0f1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048a0f2:
    // 0048a0f2  80fc32                 +cmp ah, 0x32
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(50 /*0x32*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048a0f5  74e3                   -je 0x48a0da
    if (cpu.flags.zf)
    {
        goto L_0x0048a0da;
    }
    // 0048a0f7  ebf3                   -jmp 0x48a0ec
    goto L_0x0048a0ec;
L_0x0048a0f9:
    // 0048a0f9  7608                   -jbe 0x48a103
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0048a103;
    }
    // 0048a0fb  3c46                   +cmp al, 0x46
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(70 /*0x46*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048a0fd  7314                   -jae 0x48a113
    if (!cpu.flags.cf)
    {
        goto L_0x0048a113;
    }
    // 0048a0ff  3c34                   +cmp al, 0x34
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(52 /*0x34*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048a101  75e9                   -jne 0x48a0ec
    if (!cpu.flags.zf)
    {
        goto L_0x0048a0ec;
    }
L_0x0048a103:
    // 0048a103  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0048a108  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048a10a  e8512a0100             -call 0x49cb60
    cpu.esp -= 4;
    sub_49cb60(app, cpu);
    if (cpu.terminate) return;
    // 0048a10f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048a111  ebd9                   -jmp 0x48a0ec
    goto L_0x0048a0ec;
L_0x0048a113:
    // 0048a113  7623                   -jbe 0x48a138
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0048a138;
    }
    // 0048a115  3c4a                   +cmp al, 0x4a
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(74 /*0x4a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048a117  75d3                   -jne 0x48a0ec
    if (!cpu.flags.zf)
    {
        goto L_0x0048a0ec;
    }
    // 0048a119  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048a11b  e8003e0100             -call 0x49df20
    cpu.esp -= 4;
    sub_49df20(app, cpu);
    if (cpu.terminate) return;
    // 0048a120  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0048a122  ebc8                   -jmp 0x48a0ec
    goto L_0x0048a0ec;
L_0x0048a124:
    // 0048a124  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0048a129  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048a12b  e8843f0100             -call 0x49e0b4
    cpu.esp -= 4;
    sub_49e0b4(app, cpu);
    if (cpu.terminate) return;
    // 0048a130  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048a132  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048a134  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a135  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a136  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a137  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048a138:
    // 0048a138  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048a13a  e829410100             -call 0x49e268
    cpu.esp -= 4;
    sub_49e268(app, cpu);
    if (cpu.terminate) return;
    // 0048a13f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048a141  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048a143  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a144  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a145  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a146  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48a148(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048a148  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048a149  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0048a14e  e85dffffff             -call 0x48a0b0
    cpu.esp -= 4;
    sub_48a0b0(app, cpu);
    if (cpu.terminate) return;
    // 0048a153  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a154  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48a158(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048a158  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048a159  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048a15b  e850ffffff             -call 0x48a0b0
    cpu.esp -= 4;
    sub_48a0b0(app, cpu);
    if (cpu.terminate) return;
    // 0048a160  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a161  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48a164(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048a164  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048a165  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048a166  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048a167  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048a168  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048a16a  b903000000             -mov ecx, 3
    cpu.ecx = 3 /*0x3*/;
    // 0048a16f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048a171  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0048a174  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 0048a176  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0048a178  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0048a17a  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0048a181  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0048a183  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048a185  8a6201                 -mov ah, byte ptr [edx + 1]
    cpu.ah = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0048a188  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048a18a  80fcfb                 +cmp ah, 0xfb
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(251 /*0xfb*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048a18d  7519                   -jne 0x48a1a8
    if (!cpu.flags.zf)
    {
        goto L_0x0048a1a8;
    }
L_0x0048a18f:
    // 0048a18f  8a06                   -mov al, byte ptr [esi]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esi);
    // 0048a191  24fe                   -and al, 0xfe
    cpu.al &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 0048a193  3c34                   +cmp al, 0x34
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(52 /*0x34*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048a195  7318                   -jae 0x48a1af
    if (!cpu.flags.cf)
    {
        goto L_0x0048a1af;
    }
    // 0048a197  3c30                   +cmp al, 0x30
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
    // 0048a199  7324                   -jae 0x48a1bf
    if (!cpu.flags.cf)
    {
        goto L_0x0048a1bf;
    }
    // 0048a19b  3c10                   +cmp al, 0x10
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048a19d  7502                   -jne 0x48a1a1
    if (!cpu.flags.zf)
    {
        goto L_0x0048a1a1;
    }
L_0x0048a19f:
    // 0048a19f  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
L_0x0048a1a1:
    // 0048a1a1  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048a1a3  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a1a4  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a1a5  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a1a6  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a1a7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048a1a8:
    // 0048a1a8  80fc32                 +cmp ah, 0x32
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(50 /*0x32*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048a1ab  74e2                   -je 0x48a18f
    if (cpu.flags.zf)
    {
        goto L_0x0048a18f;
    }
    // 0048a1ad  ebf2                   -jmp 0x48a1a1
    goto L_0x0048a1a1;
L_0x0048a1af:
    // 0048a1af  76ee                   -jbe 0x48a19f
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0048a19f;
    }
    // 0048a1b1  3c4a                   +cmp al, 0x4a
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(74 /*0x4a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048a1b3  7306                   -jae 0x48a1bb
    if (!cpu.flags.cf)
    {
        goto L_0x0048a1bb;
    }
    // 0048a1b5  3c46                   +cmp al, 0x46
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(70 /*0x46*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048a1b7  74e6                   -je 0x48a19f
    if (cpu.flags.zf)
    {
        goto L_0x0048a19f;
    }
    // 0048a1b9  ebe6                   -jmp 0x48a1a1
    goto L_0x0048a1a1;
L_0x0048a1bb:
    // 0048a1bb  76e2                   -jbe 0x48a19f
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0048a19f;
    }
    // 0048a1bd  ebe2                   -jmp 0x48a1a1
    goto L_0x0048a1a1;
L_0x0048a1bf:
    // 0048a1bf  76de                   -jbe 0x48a19f
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0048a19f;
    }
    // 0048a1c1  3c32                   +cmp al, 0x32
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(50 /*0x32*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048a1c3  74da                   -je 0x48a19f
    if (cpu.flags.zf)
    {
        goto L_0x0048a19f;
    }
    // 0048a1c5  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048a1c7  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a1c8  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a1c9  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a1ca  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a1cb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_48a1e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 0048a1e0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048a1e1  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048a1e2  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048a1e4  c1f908                 -sar ecx, 8
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (8 /*0x8*/ % 32));
    // 0048a1e7  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0048a1ea  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0048a1ef  83f903                 +cmp ecx, 3
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
    // 0048a1f2  7720                   -ja 0x48a214
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0048a214;
    }
    // 0048a1f4  ff248dd0a14800         -jmp dword ptr [ecx*4 + 0x48a1d0]
    cpu.ip = *app->getMemory<x86::reg32>(4760016 + cpu.ecx * 4); goto dynamic_jump;
  case 0x0048a1fb:
    // 0048a1fb  8b0c8514894c00         -mov ecx, dword ptr [eax*4 + 0x4c8914]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5015828) /* 0x4c8914 */ + cpu.eax * 4);
    // 0048a202  890a                   -mov dword ptr [edx], ecx
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 0048a204  ba00010000             -mov edx, 0x100
    cpu.edx = 256 /*0x100*/;
    // 0048a209  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0048a20b  8b049514894c00         -mov eax, dword ptr [edx*4 + 0x4c8914]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5015828) /* 0x4c8914 */ + cpu.edx * 4);
    // 0048a212  8903                   -mov dword ptr [ebx], eax
    *app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
L_0x0048a214:
    // 0048a214  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a215  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a216  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0048a217:
    // 0048a217  b900010000             -mov ecx, 0x100
    cpu.ecx = 256 /*0x100*/;
    // 0048a21c  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0048a21e  8b0c8d14894c00         -mov ecx, dword ptr [ecx*4 + 0x4c8914]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5015828) /* 0x4c8914 */ + cpu.ecx * 4);
    // 0048a225  890a                   -mov dword ptr [edx], ecx
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 0048a227  8b048514894c00         -mov eax, dword ptr [eax*4 + 0x4c8914]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5015828) /* 0x4c8914 */ + cpu.eax * 4);
    // 0048a22e  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0048a230  8903                   -mov dword ptr [ebx], eax
    *app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 0048a232  f7dd                   -neg ebp
    cpu.ebp = ~cpu.ebp + 1;
    // 0048a234  892b                   -mov dword ptr [ebx], ebp
    *app->getMemory<x86::reg32>(cpu.ebx) = cpu.ebp;
    // 0048a236  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a237  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a238  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0048a239:
    // 0048a239  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048a23a  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048a23b  8b0c8514894c00         -mov ecx, dword ptr [eax*4 + 0x4c8914]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5015828) /* 0x4c8914 */ + cpu.eax * 4);
    // 0048a242  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0048a244  890a                   -mov dword ptr [edx], ecx
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 0048a246  f7de                   -neg esi
    cpu.esi = ~cpu.esi + 1;
    // 0048a248  8932                   -mov dword ptr [edx], esi
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.esi;
    // 0048a24a  ba00010000             -mov edx, 0x100
    cpu.edx = 256 /*0x100*/;
    // 0048a24f  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0048a251  8b049514894c00         -mov eax, dword ptr [edx*4 + 0x4c8914]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5015828) /* 0x4c8914 */ + cpu.edx * 4);
    // 0048a258  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0048a25a  8903                   -mov dword ptr [ebx], eax
    *app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 0048a25c  f7df                   -neg edi
    cpu.edi = ~cpu.edi + 1;
    // 0048a25e  893b                   -mov dword ptr [ebx], edi
    *app->getMemory<x86::reg32>(cpu.ebx) = cpu.edi;
    // 0048a260  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a261  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a262  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a263  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a264  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0048a265:
    // 0048a265  b900010000             -mov ecx, 0x100
    cpu.ecx = 256 /*0x100*/;
    // 0048a26a  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0048a26c  8b0c8d14894c00         -mov ecx, dword ptr [ecx*4 + 0x4c8914]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5015828) /* 0x4c8914 */ + cpu.ecx * 4);
    // 0048a273  890a                   -mov dword ptr [edx], ecx
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 0048a275  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0048a277  890a                   -mov dword ptr [edx], ecx
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 0048a279  8b048514894c00         -mov eax, dword ptr [eax*4 + 0x4c8914]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5015828) /* 0x4c8914 */ + cpu.eax * 4);
    // 0048a280  8903                   -mov dword ptr [ebx], eax
    *app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 0048a282  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a283  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a284  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_48a288(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048a288  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048a289  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048a28a  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048a28b  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048a28c  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048a28e  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0048a290  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi);
    // 0048a292  f72f                   -imul dword ptr [edi]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(cpu.edi))));
    // 0048a294  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0048a296  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0048a299  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0048a29b  f76f0c                 -imul dword ptr [edi + 0xc]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */))));
    // 0048a29e  01c5                   +add ebp, eax
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
    // 0048a2a0  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0048a2a3  11d1                   -adc ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0048a2a5  f76f18                 -imul dword ptr [edi + 0x18]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */))));
    // 0048a2a8  01e8                   +add eax, ebp
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048a2aa  11ca                   -adc edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 0048a2ac  0facd010               -shrd eax, edx, 0x10
    {
        x86::reg32& destination = cpu.eax;
        destination >>= (16 /*0x10*/ % 32);
        destination |= cpu.edx  << (32 - (16 /*0x10*/ % 32));
    }
    // 0048a2b0  8903                   -mov dword ptr [ebx], eax
    *app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 0048a2b2  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi);
    // 0048a2b4  f76f04                 -imul dword ptr [edi + 4]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */))));
    // 0048a2b7  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0048a2b9  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0048a2bc  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0048a2be  f76f10                 -imul dword ptr [edi + 0x10]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */))));
    // 0048a2c1  01c5                   +add ebp, eax
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
    // 0048a2c3  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0048a2c6  11d1                   -adc ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0048a2c8  f76f1c                 -imul dword ptr [edi + 0x1c]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */))));
    // 0048a2cb  01e8                   +add eax, ebp
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048a2cd  11ca                   -adc edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 0048a2cf  0facd010               -shrd eax, edx, 0x10
    {
        x86::reg32& destination = cpu.eax;
        destination >>= (16 /*0x10*/ % 32);
        destination |= cpu.edx  << (32 - (16 /*0x10*/ % 32));
    }
    // 0048a2d3  894304                 -mov dword ptr [ebx + 4], eax
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0048a2d6  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi);
    // 0048a2d8  f76f08                 -imul dword ptr [edi + 8]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */))));
    // 0048a2db  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0048a2dd  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0048a2e0  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0048a2e2  f76f14                 -imul dword ptr [edi + 0x14]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */))));
    // 0048a2e5  01c5                   +add ebp, eax
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
    // 0048a2e7  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0048a2ea  11d1                   -adc ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0048a2ec  f76f20                 -imul dword ptr [edi + 0x20]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */))));
    // 0048a2ef  01e8                   +add eax, ebp
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048a2f1  11ca                   -adc edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 0048a2f3  0facd010               -shrd eax, edx, 0x10
    {
        x86::reg32& destination = cpu.eax;
        destination >>= (16 /*0x10*/ % 32);
        destination |= cpu.edx  << (32 - (16 /*0x10*/ % 32));
    }
    // 0048a2f7  894308                 -mov dword ptr [ebx + 8], eax
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0048a2fa  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a2fb  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a2fc  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a2fd  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a2fe  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_48a300(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048a300  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048a301  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048a302  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048a303  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048a304  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048a306  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0048a308  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0048a30a  8d7024                 -lea esi, [eax + 0x24]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(36) /* 0x24 */);
L_0x0048a30d:
    // 0048a30d  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048a310  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax);
    // 0048a312  8b29                   -mov ebp, dword ptr [ecx]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.ecx);
    // 0048a314  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048a317  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0048a319  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048a31c  8953fc                 -mov dword ptr [ebx - 4], edx
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 0048a31f  39f0                   +cmp eax, esi
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
    // 0048a321  75ea                   -jne 0x48a30d
    if (!cpu.flags.zf)
    {
        goto L_0x0048a30d;
    }
    // 0048a323  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048a325  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a326  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a327  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a328  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a329  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48a32c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048a32c  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048a32d  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048a32e  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048a32f  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048a330  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048a332  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0048a334  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0048a336  8d7024                 -lea esi, [eax + 0x24]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(36) /* 0x24 */);
L_0x0048a339:
    // 0048a339  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048a33c  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax);
    // 0048a33e  8b29                   -mov ebp, dword ptr [ecx]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.ecx);
    // 0048a340  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048a343  29ea                   -sub edx, ebp
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0048a345  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048a348  8953fc                 -mov dword ptr [ebx - 4], edx
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 0048a34b  39f0                   +cmp eax, esi
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
    // 0048a34d  75ea                   -jne 0x48a339
    if (!cpu.flags.zf)
    {
        goto L_0x0048a339;
    }
    // 0048a34f  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048a351  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a352  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a353  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a354  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a355  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48a358(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048a358  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048a359  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048a35a  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048a35b  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048a35c  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0048a35e  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0048a360  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048a362  8d7824                 -lea edi, [eax + 0x24]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(36) /* 0x24 */);
L_0x0048a365:
    // 0048a365  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0048a367  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx);
    // 0048a369  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048a36c  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0048a36e  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0048a371  c1e810                 +shr eax, 0x10
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
    // 0048a374  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0048a376  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048a379  8943fc                 -mov dword ptr [ebx - 4], eax
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0048a37c  39f9                   +cmp ecx, edi
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
    // 0048a37e  75e5                   -jne 0x48a365
    if (!cpu.flags.zf)
    {
        goto L_0x0048a365;
    }
    // 0048a380  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048a382  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a383  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a384  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a385  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a386  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48a388(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048a388  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048a389  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048a38a  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048a38b  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048a38c  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048a38d  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048a38e  81ecbc000000           -sub esp, 0xbc
    (cpu.esp) -= x86::reg32(x86::sreg32(188 /*0xbc*/));
    // 0048a394  898424b8000000         -mov dword ptr [esp + 0xb8], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(184) /* 0xb8 */) = cpu.eax;
    // 0048a39b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048a39d  899424b4000000         -mov dword ptr [esp + 0xb4], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(180) /* 0xb4 */) = cpu.edx;
L_0x0048a3a4:
    // 0048a3a4  8d542448               -lea edx, [esp + 0x48]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0048a3a8  8b8424b8000000         -mov eax, dword ptr [esp + 0xb8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 0048a3af  8d9c2490000000         -lea ebx, [esp + 0x90]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(144) /* 0x90 */);
    // 0048a3b6  b909000000             -mov ecx, 9
    cpu.ecx = 9 /*0x9*/;
    // 0048a3bb  e8c0ecffff             -call 0x489080
    cpu.esp -= 4;
    sub_489080(app, cpu);
    if (cpu.terminate) return;
    // 0048a3c0  8b9424b8000000         -mov edx, dword ptr [esp + 0xb8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 0048a3c7  8d442448               -lea eax, [esp + 0x48]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0048a3cb  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 0048a3cd  e86efbffff             -call 0x489f40
    cpu.esp -= 4;
    sub_489f40(app, cpu);
    if (cpu.terminate) return;
    // 0048a3d2  8d5c246c               -lea ebx, [esp + 0x6c]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(108) /* 0x6c */);
    // 0048a3d6  baf0a24c00             -mov edx, 0x4ca2f0
    cpu.edx = 5022448 /*0x4ca2f0*/;
    // 0048a3db  8d842490000000         -lea eax, [esp + 0x90]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(144) /* 0x90 */);
    // 0048a3e2  bef0a24c00             -mov esi, 0x4ca2f0
    cpu.esi = 5022448 /*0x4ca2f0*/;
    // 0048a3e7  e840ffffff             -call 0x48a32c
    cpu.esp -= 4;
    sub_48a32c(app, cpu);
    if (cpu.terminate) return;
    // 0048a3ec  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048a3ee  b909000000             -mov ecx, 9
    cpu.ecx = 9 /*0x9*/;
    // 0048a3f3  8d7c2424               -lea edi, [esp + 0x24]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0048a3f7  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0048a3f9  bd04000000             -mov ebp, 4
    cpu.ebp = 4 /*0x4*/;
    // 0048a3fe  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
L_0x0048a400:
    // 0048a400  8d5c2448               -lea ebx, [esp + 0x48]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0048a404  8d54246c               -lea edx, [esp + 0x6c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(108) /* 0x6c */);
    // 0048a408  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0048a40a  b909000000             -mov ecx, 9
    cpu.ecx = 9 /*0x9*/;
    // 0048a40f  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 0048a411  8d742448               -lea esi, [esp + 0x48]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0048a415  e826fbffff             -call 0x489f40
    cpu.esp -= 4;
    sub_489f40(app, cpu);
    if (cpu.terminate) return;
    // 0048a41a  8d9c2490000000         -lea ebx, [esp + 0x90]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(144) /* 0x90 */);
    // 0048a421  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0048a423  8b9514a34c00           -mov edx, dword ptr [ebp + 0x4ca314]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(5022484) /* 0x4ca314 */);
    // 0048a429  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048a42b  e828ffffff             -call 0x48a358
    cpu.esp -= 4;
    sub_48a358(app, cpu);
    if (cpu.terminate) return;
    // 0048a430  8d5c2424               -lea ebx, [esp + 0x24]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0048a434  8d942490000000         -lea edx, [esp + 0x90]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(144) /* 0x90 */);
    // 0048a43b  8d442424               -lea eax, [esp + 0x24]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0048a43f  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048a442  e8b9feffff             -call 0x48a300
    cpu.esp -= 4;
    sub_48a300(app, cpu);
    if (cpu.terminate) return;
    // 0048a447  83fd10                 +cmp ebp, 0x10
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
    // 0048a44a  75b4                   -jne 0x48a400
    if (!cpu.flags.zf)
    {
        goto L_0x0048a400;
    }
    // 0048a44c  b909000000             -mov ecx, 9
    cpu.ecx = 9 /*0x9*/;
    // 0048a451  8d7c2448               -lea edi, [esp + 0x48]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0048a455  8bb424b8000000         -mov esi, dword ptr [esp + 0xb8]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 0048a45c  8b9c24b8000000         -mov ebx, dword ptr [esp + 0xb8]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 0048a463  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048a465  8d542424               -lea edx, [esp + 0x24]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0048a469  8b8c24b4000000         -mov ecx, dword ptr [esp + 0xb4]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(180) /* 0xb4 */);
    // 0048a470  8d442448               -lea eax, [esp + 0x48]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0048a474  41                     -inc ecx
    (cpu.ecx)++;
    // 0048a475  e8c6faffff             -call 0x489f40
    cpu.esp -= 4;
    sub_489f40(app, cpu);
    if (cpu.terminate) return;
    // 0048a47a  898c24b4000000         -mov dword ptr [esp + 0xb4], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(180) /* 0xb4 */) = cpu.ecx;
    // 0048a481  83f904                 +cmp ecx, 4
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
    // 0048a484  0f8c1affffff           -jl 0x48a3a4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048a3a4;
    }
    // 0048a48a  81c4bc000000           -add esp, 0xbc
    (cpu.esp) += x86::reg32(x86::sreg32(188 /*0xbc*/));
    // 0048a490  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a491  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a492  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a493  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a494  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a495  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a496  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48a498(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048a498  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048a499  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048a49a  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048a49b  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048a49c  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0048a49f  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0048a4a1  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0048a4a3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048a4a5  8d8800010000           -lea ecx, [eax + 0x100]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(256) /* 0x100 */);
    // 0048a4ab  c0e507                 +shl ch, 7
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
    // 0048a4ae  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0048a4b0  00ed                   +add ch, ch
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
    // 0048a4b2  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 0048a4b4  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048a4b6  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0048a4bb  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048a4bd  8b048514894c00         -mov eax, dword ptr [eax*4 + 0x4c8914]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5015828) /* 0x4c8914 */ + cpu.eax * 4);
    // 0048a4c4  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048a4c6  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048a4c8  89442414               -mov dword ptr [esp + 0x14], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0048a4cc  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048a4ce  c0e407                 +shl ah, 7
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
    // 0048a4d1  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0048a4d3  00e4                   +add ah, ah
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
    // 0048a4d5  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 0048a4d7  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048a4d9  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0048a4de  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048a4e0  8b048514894c00         -mov eax, dword ptr [eax*4 + 0x4c8914]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5015828) /* 0x4c8914 */ + cpu.eax * 4);
    // 0048a4e7  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048a4e9  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048a4eb  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048a4ed  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0048a4ef  7518                   -jne 0x48a509
    if (!cpu.flags.zf)
    {
        goto L_0x0048a509;
    }
    // 0048a4f1  b909000000             -mov ecx, 9
    cpu.ecx = 9 /*0x9*/;
    // 0048a4f6  bef0a24c00             -mov esi, 0x4ca2f0
    cpu.esi = 5022448 /*0x4ca2f0*/;
    // 0048a4fb  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0048a4fd  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048a4ff  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048a501  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0048a504  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a505  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a506  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a507  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a508  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048a509:
    // 0048a509  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0048a50b  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048a50d  e8fe3e0100             -call 0x49e410
    cpu.esp -= 4;
    sub_49e410(app, cpu);
    if (cpu.terminate) return;
    // 0048a512  bd00000100             -mov ebp, 0x10000
    cpu.ebp = 65536 /*0x10000*/;
    // 0048a517  2b6c2414               -sub ebp, dword ptr [esp + 0x14]
    (cpu.ebp) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 0048a51b  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    // 0048a51e  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048a520  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0048a522  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0048a525  c1e810                 +shr eax, 0x10
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
    // 0048a528  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0048a52a  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048a52e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048a530  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048a532  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0048a534  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0048a537  c1e810                 +shr eax, 0x10
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
    // 0048a53a  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0048a53c  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048a540  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0048a542  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048a544  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0048a546  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0048a549  c1e810                 +shr eax, 0x10
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
    // 0048a54c  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0048a54e  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    // 0048a551  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0048a553  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048a555  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0048a557  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0048a55a  c1e810                 +shr eax, 0x10
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
    // 0048a55d  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0048a55f  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048a563  8944240c               -mov dword ptr [esp + 0xc], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0048a567  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048a569  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0048a56b  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0048a56e  c1e810                 +shr eax, 0x10
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
    // 0048a571  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0048a573  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048a577  89442410               -mov dword ptr [esp + 0x10], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0048a57b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048a57d  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0048a57f  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0048a582  c1e810                 +shr eax, 0x10
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
    // 0048a585  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0048a587  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    // 0048a58a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048a58c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048a58e  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0048a590  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0048a593  c1e810                 +shr eax, 0x10
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
    // 0048a596  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0048a598  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0048a59c  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048a59e  8913                   -mov dword ptr [ebx], edx
    *app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 0048a5a0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048a5a2  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048a5a6  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0048a5a8  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0048a5ab  c1e810                 +shr eax, 0x10
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
    // 0048a5ae  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0048a5b0  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0048a5b2  894304                 -mov dword ptr [ebx + 4], eax
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0048a5b5  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048a5b9  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048a5bb  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0048a5bf  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0048a5c1  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0048a5c4  c1e810                 +shr eax, 0x10
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
    // 0048a5c7  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0048a5c9  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048a5cb  894308                 -mov dword ptr [ebx + 8], eax
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0048a5ce  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    // 0048a5d1  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048a5d3  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0048a5d5  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0048a5d8  c1e810                 +shr eax, 0x10
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
    // 0048a5db  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0048a5dd  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0048a5df  89430c                 -mov dword ptr [ebx + 0xc], eax
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0048a5e2  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048a5e6  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048a5e8  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0048a5ea  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0048a5ed  c1e810                 +shr eax, 0x10
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
    // 0048a5f0  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0048a5f2  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0048a5f6  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048a5f8  895310                 -mov dword ptr [ebx + 0x10], edx
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0048a5fb  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048a5fd  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048a601  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0048a603  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0048a606  c1e810                 +shr eax, 0x10
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
    // 0048a609  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0048a60b  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048a60f  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048a611  895314                 -mov dword ptr [ebx + 0x14], edx
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 0048a614  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048a616  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    // 0048a619  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0048a61b  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0048a61e  c1e810                 +shr eax, 0x10
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
    // 0048a621  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0048a623  8d1401                 -lea edx, [ecx + eax]
    cpu.edx = x86::reg32(cpu.ecx + cpu.eax * 1);
    // 0048a626  895318                 -mov dword ptr [ebx + 0x18], edx
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 0048a629  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048a62b  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048a62f  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048a633  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0048a635  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0048a638  c1e810                 +shr eax, 0x10
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
    // 0048a63b  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0048a63d  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0048a63f  89431c                 -mov dword ptr [ebx + 0x1c], eax
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0048a642  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048a646  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048a648  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0048a64a  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0048a64d  c1e810                 +shr eax, 0x10
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
    // 0048a650  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0048a652  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0048a656  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048a658  895320                 -mov dword ptr [ebx + 0x20], edx
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 0048a65b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048a65d  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0048a660  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a661  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a662  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a663  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a664  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48a665(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048a665  ff1544c14c00           -call dword ptr [0x4cc144]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5030212) /* 0x4cc144 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048a66b  83c00c                 -add eax, 0xc
    (cpu.eax) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0048a66e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48a66f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048a66f  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048a670  e8f0ffffff             -call 0x48a665
    cpu.esp -= 4;
    sub_48a665(app, cpu);
    if (cpu.terminate) return;
    // 0048a675  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048a677  7418                   -je 0x48a691
    if (cpu.flags.zf)
    {
        goto L_0x0048a691;
    }
    // 0048a679  69106d4ec641           -imul edx, dword ptr [eax], 0x41c64e6d
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(cpu.eax))) * x86::sreg64(x86::sreg32(1103515245 /*0x41c64e6d*/)));
    // 0048a67f  81c239300000           -add edx, 0x3039
    (cpu.edx) += x86::reg32(x86::sreg32(12345 /*0x3039*/));
    // 0048a685  8910                   -mov dword ptr [eax], edx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0048a687  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048a689  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 0048a68c  25ff7f0000             -and eax, 0x7fff
    cpu.eax &= x86::reg32(x86::sreg32(32767 /*0x7fff*/));
L_0x0048a691:
    // 0048a691  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a692  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48a693(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048a693  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048a694  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048a696  e8caffffff             -call 0x48a665
    cpu.esp -= 4;
    sub_48a665(app, cpu);
    if (cpu.terminate) return;
    // 0048a69b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048a69d  7402                   -je 0x48a6a1
    if (cpu.flags.zf)
    {
        goto L_0x0048a6a1;
    }
    // 0048a69f  8910                   -mov dword ptr [eax], edx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
L_0x0048a6a1:
    // 0048a6a1  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a6a2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48a6a3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048a6a3  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
L_0x0048a6a4:
    // 0048a6a4  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0048a6a6  7504                   -jne 0x48a6ac
    if (!cpu.flags.zf)
    {
        goto L_0x0048a6ac;
    }
L_0x0048a6a8:
    // 0048a6a8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048a6aa  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a6ab  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048a6ac:
    // 0048a6ac  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.eax);
    // 0048a6ae  8a2a                   -mov ch, byte ptr [edx]
    cpu.ch = *app->getMemory<x86::reg8>(cpu.edx);
    // 0048a6b0  38e9                   +cmp cl, ch
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.ch));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048a6b2  740e                   -je 0x48a6c2
    if (cpu.flags.zf)
    {
        goto L_0x0048a6c2;
    }
    // 0048a6b4  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048a6b6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048a6b8  88cb                   -mov bl, cl
    cpu.bl = cpu.cl;
    // 0048a6ba  88e8                   -mov al, ch
    cpu.al = cpu.ch;
    // 0048a6bc  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0048a6be  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048a6c0  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a6c1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048a6c2:
    // 0048a6c2  803800                 +cmp byte ptr [eax], 0
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
    // 0048a6c5  74e1                   -je 0x48a6a8
    if (cpu.flags.zf)
    {
        goto L_0x0048a6a8;
    }
    // 0048a6c7  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0048a6c8  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0048a6c9  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0048a6ca  ebd8                   -jmp 0x48a6a4
    goto L_0x0048a6a4;
}

/* align: skip  */
void Application::sub_48a6cc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048a6cc  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048a6cd  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048a6ce  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048a6cf  06                     -push es
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0048a6d0  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048a6d1  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0048a6d3  81ec84000000           -sub esp, 0x84
    (cpu.esp) -= x86::reg32(x86::sreg32(132 /*0x84*/));
    // 0048a6d9  81ed82000000           -sub ebp, 0x82
    (cpu.ebp) -= x86::reg32(x86::sreg32(130 /*0x82*/));
    // 0048a6df  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0048a6e1  8b3520605200           -mov esi, dword ptr [0x526020]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(5398560) /* 0x526020 */);
    // 0048a6e7  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0048a6ec  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0048a6ee  740d                   -je 0x48a6fd
    if (cpu.flags.zf)
    {
        goto L_0x0048a6fd;
    }
    // 0048a6f0  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0048a6f2  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0048a6f7  893d20605200           -mov dword ptr [0x526020], edi
    *app->getMemory<x86::reg32>(x86::reg32(5398560) /* 0x526020 */) = cpu.edi;
L_0x0048a6fd:
    // 0048a6fd  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048a6fe  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048a6ff  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048a700  6828ec4b00             -push 0x4bec28
    *app->getMemory<x86::reg32>(cpu.esp-4) = 4975656 /*0x4bec28*/;
    cpu.esp -= 4;
    // 0048a705  6880000000             -push 0x80
    *app->getMemory<x86::reg32>(cpu.esp-4) = 128 /*0x80*/;
    cpu.esp -= 4;
    // 0048a70a  8d45fe                 -lea eax, [ebp - 2]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-2) /* -0x2 */);
    // 0048a70d  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048a70e  e83f3e0100             -call 0x49e552
    cpu.esp -= 4;
    sub_49e552(app, cpu);
    if (cpu.terminate) return;
    // 0048a713  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0048a716  803d68c84c0000         +cmp byte ptr [0x4cc868], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(x86::reg32(5032040) /* 0x4cc868 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048a71d  0f84f8000000           -je 0x48a81b
    if (cpu.flags.zf)
    {
        goto L_0x0048a81b;
    }
    // 0048a723  8d7dfe                 -lea edi, [ebp - 2]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-2) /* -0x2 */);
    // 0048a726  06                     -push es
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0048a727  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0048a729  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 0048a72b  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048a72d  49                     -dec ecx
    (cpu.ecx)--;
    // 0048a72e  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0048a730  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0048a732  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0048a734  49                     -dec ecx
    (cpu.ecx)--;
    // 0048a735  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0048a736  8d5117                 -lea edx, [ecx + 0x17]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(23) /* 0x17 */);
    // 0048a739  80e2fc                 -and dl, 0xfc
    cpu.dl &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 0048a73c  e83c3e0100             -call 0x49e57d
    cpu.esp -= 4;
    sub_49e57d(app, cpu);
    if (cpu.terminate) return;
    // 0048a741  39c2                   +cmp edx, eax
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
    // 0048a743  733c                   -jae 0x48a781
    if (!cpu.flags.cf)
    {
        goto L_0x0048a781;
    }
    // 0048a745  8d7dfe                 -lea edi, [ebp - 2]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-2) /* -0x2 */);
    // 0048a748  06                     -push es
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0048a749  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0048a74b  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 0048a74d  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048a74f  49                     -dec ecx
    (cpu.ecx)--;
    // 0048a750  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0048a752  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0048a754  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0048a756  49                     -dec ecx
    (cpu.ecx)--;
    // 0048a757  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0048a758  8d4117                 -lea eax, [ecx + 0x17]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(23) /* 0x17 */);
    // 0048a75b  24fc                   -and al, 0xfc
    cpu.al &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 0048a75d  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048a75e  8d7dfe                 -lea edi, [ebp - 2]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-2) /* -0x2 */);
    // 0048a761  e8663e0100             -call 0x49e5cc
    cpu.esp -= 4;
    sub_49e5cc(app, cpu);
    if (cpu.terminate) return;
    // 0048a766  06                     -push es
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0048a767  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0048a769  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 0048a76b  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048a76d  49                     -dec ecx
    (cpu.ecx)--;
    // 0048a76e  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0048a770  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0048a772  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0048a774  49                     -dec ecx
    (cpu.ecx)--;
    // 0048a775  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0048a776  8d4117                 -lea eax, [ecx + 0x17]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(23) /* 0x17 */);
    // 0048a779  24fc                   -and al, 0xfc
    cpu.al &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 0048a77b  29c4                   +sub esp, eax
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048a77d  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 0048a77f  eb02                   -jmp 0x48a783
    goto L_0x0048a783;
L_0x0048a781:
    // 0048a781  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0048a783:
    // 0048a783  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0048a785  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0048a787  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 0048a789  be40ec4b00             -mov esi, 0x4bec40
    cpu.esi = 4975680 /*0x4bec40*/;
    // 0048a78e  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048a78f  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048a790  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048a791  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048a792  66a5                   -movsw word ptr es:[edi], word ptr [esi]
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
    // 0048a794  a4                     -movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0048a795  8d75fe                 -lea esi, [ebp - 2]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-2) /* -0x2 */);
    // 0048a798  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0048a79a  894d7e                 -mov dword ptr [ebp + 0x7e], ecx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */) = cpu.ecx;
    // 0048a79d  06                     -push es
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0048a79e  1e                     -push ds
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.ds;
    cpu.esp -= 4;
    // 0048a79f  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0048a7a0  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048a7a1  2bc9                   +sub ecx, ecx
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
    // 0048a7a3  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0048a7a4  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 0048a7a6  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0048a7a8  4f                     -dec edi
    (cpu.edi)--;
L_0x0048a7a9:
    // 0048a7a9  8a06                   -mov al, byte ptr [esi]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esi);
    // 0048a7ab  8807                   -mov byte ptr [edi], al
    *app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0048a7ad  3c00                   +cmp al, 0
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
    // 0048a7af  7410                   -je 0x48a7c1
    if (cpu.flags.zf)
    {
        goto L_0x0048a7c1;
    }
    // 0048a7b1  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0048a7b4  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0048a7b7  884701                 -mov byte ptr [edi + 1], al
    *app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0048a7ba  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0048a7bd  3c00                   +cmp al, 0
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
    // 0048a7bf  75e8                   -jne 0x48a7a9
    if (!cpu.flags.zf)
    {
        goto L_0x0048a7a9;
    }
L_0x0048a7c1:
    // 0048a7c1  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a7c2  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0048a7c3  e8b53d0100             -call 0x49e57d
    cpu.esp -= 4;
    sub_49e57d(app, cpu);
    if (cpu.terminate) return;
    // 0048a7c8  83f814                 +cmp eax, 0x14
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(20 /*0x14*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048a7cb  7612                   -jbe 0x48a7df
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0048a7df;
    }
    // 0048a7cd  6a14                   -push 0x14
    *app->getMemory<x86::reg32>(cpu.esp-4) = 20 /*0x14*/;
    cpu.esp -= 4;
    // 0048a7cf  e8f83d0100             -call 0x49e5cc
    cpu.esp -= 4;
    sub_49e5cc(app, cpu);
    if (cpu.terminate) return;
    // 0048a7d4  b814000000             -mov eax, 0x14
    cpu.eax = 20 /*0x14*/;
    // 0048a7d9  29c4                   +sub esp, eax
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048a7db  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 0048a7dd  eb02                   -jmp 0x48a7e1
    goto L_0x0048a7e1;
L_0x0048a7df:
    // 0048a7df  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0048a7e1:
    // 0048a7e1  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048a7e2  6853ec4b00             -push 0x4bec53
    *app->getMemory<x86::reg32>(cpu.esp-4) = 4975699 /*0x4bec53*/;
    cpu.esp -= 4;
    // 0048a7e7  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048a7e8  e834fcfeff             -call 0x47a421
    cpu.esp -= 4;
    sub_47a421(app, cpu);
    if (cpu.terminate) return;
    // 0048a7ed  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0048a7f0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048a7f1  2eff1524554b00         -call dword ptr cs:[0x4b5524]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936996) /* 0x4b5524 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048a7f8  803d68c84c0000         +cmp byte ptr [0x4cc868], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(x86::reg32(5032040) /* 0x4cc868 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048a7ff  7436                   -je 0x48a837
    if (cpu.flags.zf)
    {
        goto L_0x0048a837;
    }
    // 0048a801  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0048a803  25ffff0000             +and eax, 0xffff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/))));
    // 0048a808  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048a809  8b457e                 -mov eax, dword ptr [ebp + 0x7e]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 0048a80c  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048a80d  cc                     -int3 
    NFS2_ASSERT(false);
    // 0048a80e  eb06                   -jmp 0x48a816
    goto L_0x0048a816;
    // 0048a810  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048a811  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048a812  49                     -dec ecx
    (cpu.ecx)--;
    // 0048a813  44                     -inc esp
    (cpu.esp)++;
    // 0048a814  45                     -inc ebp
    (cpu.ebp)++;
    // 0048a815  4f                     -dec edi
    (cpu.edi)--;
L_0x0048a816:
    // 0048a816  83c408                 +add esp, 8
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
    // 0048a819  eb1c                   -jmp 0x48a837
    goto L_0x0048a837;
L_0x0048a81b:
    // 0048a81b  6800200000             -push 0x2000
    *app->getMemory<x86::reg32>(cpu.esp-4) = 8192 /*0x2000*/;
    cpu.esp -= 4;
    // 0048a820  6864ec4b00             -push 0x4bec64
    *app->getMemory<x86::reg32>(cpu.esp-4) = 4975716 /*0x4bec64*/;
    cpu.esp -= 4;
    // 0048a825  8d45fe                 -lea eax, [ebp - 2]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-2) /* -0x2 */);
    // 0048a828  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048a829  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048a82b  2eff15d4534b00         -call dword ptr cs:[0x4b53d4]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936660) /* 0x4b53d4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048a832  e8c93d0100             -call 0x49e600
    cpu.esp -= 4;
    sub_49e600(app, cpu);
    if (cpu.terminate) return;
L_0x0048a837:
    // 0048a837  8da582000000           -lea esp, [ebp + 0x82]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(130) /* 0x82 */);
    // 0048a83d  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a83e  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0048a83f  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a840  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a841  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a842  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48a843(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048a843  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048a844  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048a846  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048a848  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0048a84a  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0048a84c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0048a84e  750f                   -jne 0x48a85f
    if (!cpu.flags.zf)
    {
        goto L_0x0048a85f;
    }
    // 0048a850  c7052060520001000000   -mov dword ptr [0x526020], 1
    *app->getMemory<x86::reg32>(x86::reg32(5398560) /* 0x526020 */) = 1 /*0x1*/;
    // 0048a85a  e86dfeffff             -call 0x48a6cc
    cpu.esp -= 4;
    sub_48a6cc(app, cpu);
    if (cpu.terminate) return;
L_0x0048a85f:
    // 0048a85f  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a860  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_48a870(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048a870  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048a871  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048a872  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048a873  81ec04040000           -sub esp, 0x404
    (cpu.esp) -= x86::reg32(x86::sreg32(1028 /*0x404*/));
    // 0048a879  8b842414040000         -mov eax, dword ptr [esp + 0x414]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1044) /* 0x414 */);
    // 0048a880  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048a882  7415                   -je 0x48a899
    if (cpu.flags.zf)
    {
        goto L_0x0048a899;
    }
    // 0048a884  8b942418040000         -mov edx, dword ptr [esp + 0x418]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1048) /* 0x418 */);
    // 0048a88b  3b10                   +cmp edx, dword ptr [eax]
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
    // 0048a88d  7e0a                   -jle 0x48a899
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048a899;
    }
L_0x0048a88f:
    // 0048a88f  81c404040000           -add esp, 0x404
    (cpu.esp) += x86::reg32(x86::sreg32(1028 /*0x404*/));
    // 0048a895  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a896  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a897  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a898  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048a899:
    // 0048a899  8d842420040000         -lea eax, [esp + 0x420]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(1056) /* 0x420 */);
    // 0048a8a0  8d9c2400040000         -lea ebx, [esp + 0x400]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(1024) /* 0x400 */);
    // 0048a8a7  8b94241c040000         -mov edx, dword ptr [esp + 0x41c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1052) /* 0x41c */);
    // 0048a8ae  89842400040000         -mov dword ptr [esp + 0x400], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1024) /* 0x400 */) = cpu.eax;
    // 0048a8b5  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0048a8b7  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048a8b9  e8588d0000             -call 0x493616
    cpu.esp -= 4;
    sub_493616(app, cpu);
    if (cpu.terminate) return;
    // 0048a8be  a144a44c00             -mov eax, dword ptr [0x4ca444]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5022788) /* 0x4ca444 */);
    // 0048a8c3  898c2400040000         -mov dword ptr [esp + 0x400], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1024) /* 0x400 */) = cpu.ecx;
    // 0048a8ca  83f802                 +cmp eax, 2
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
    // 0048a8cd  7319                   -jae 0x48a8e8
    if (!cpu.flags.cf)
    {
        goto L_0x0048a8e8;
    }
    // 0048a8cf  83f801                 +cmp eax, 1
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
    // 0048a8d2  75bb                   -jne 0x48a88f
    if (!cpu.flags.zf)
    {
        goto L_0x0048a88f;
    }
    // 0048a8d4  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0048a8d6  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048a8d7  2eff1524554b00         -call dword ptr cs:[0x4b5524]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936996) /* 0x4b5524 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048a8de  81c404040000           +add esp, 0x404
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1028 /*0x404*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048a8e4  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a8e5  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a8e6  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a8e7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048a8e8:
    // 0048a8e8  761a                   -jbe 0x48a904
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0048a904;
    }
    // 0048a8ea  83f803                 +cmp eax, 3
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
    // 0048a8ed  75a0                   -jne 0x48a88f
    if (!cpu.flags.zf)
    {
        goto L_0x0048a88f;
    }
    // 0048a8ef  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0048a8f1  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048a8f2  e8b95effff             -call 0x4807b0
    cpu.esp -= 4;
    sub_4807b0(app, cpu);
    if (cpu.terminate) return;
    // 0048a8f7  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048a8fa  81c404040000           -add esp, 0x404
    (cpu.esp) += x86::reg32(x86::sreg32(1028 /*0x404*/));
    // 0048a900  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a901  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a902  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a903  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048a904:
    // 0048a904  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0048a906  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048a907  e8d58c0000             -call 0x4935e1
    cpu.esp -= 4;
    sub_4935e1(app, cpu);
    if (cpu.terminate) return;
    // 0048a90c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048a90f  b84abf4c00             -mov eax, 0x4cbf4a
    cpu.eax = 5029706 /*0x4cbf4a*/;
    // 0048a914  e8ff3c0100             -call 0x49e618
    cpu.esp -= 4;
    sub_49e618(app, cpu);
    if (cpu.terminate) return;
    // 0048a919  81c404040000           -add esp, 0x404
    (cpu.esp) += x86::reg32(x86::sreg32(1028 /*0x404*/));
    // 0048a91f  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a920  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a921  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a922  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48a923(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048a923  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048a924  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x0048a926:
    // 0048a926  8a03                   -mov al, byte ptr [ebx]
    cpu.al = *app->getMemory<x86::reg8>(cpu.ebx);
    // 0048a928  8a22                   -mov ah, byte ptr [edx]
    cpu.ah = *app->getMemory<x86::reg8>(cpu.edx);
    // 0048a92a  3c41                   +cmp al, 0x41
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
    // 0048a92c  7206                   -jb 0x48a934
    if (cpu.flags.cf)
    {
        goto L_0x0048a934;
    }
    // 0048a92e  3c5a                   +cmp al, 0x5a
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
    // 0048a930  7702                   -ja 0x48a934
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0048a934;
    }
    // 0048a932  0420                   -add al, 0x20
    (cpu.al) += x86::reg8(x86::sreg8(32 /*0x20*/));
L_0x0048a934:
    // 0048a934  80fc41                 +cmp ah, 0x41
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
    // 0048a937  7208                   -jb 0x48a941
    if (cpu.flags.cf)
    {
        goto L_0x0048a941;
    }
    // 0048a939  80fc5a                 +cmp ah, 0x5a
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
    // 0048a93c  7703                   -ja 0x48a941
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0048a941;
    }
    // 0048a93e  80c420                 -add ah, 0x20
    (cpu.ah) += x86::reg8(x86::sreg8(32 /*0x20*/));
L_0x0048a941:
    // 0048a941  38e0                   +cmp al, ah
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
    // 0048a943  7508                   -jne 0x48a94d
    if (!cpu.flags.zf)
    {
        goto L_0x0048a94d;
    }
    // 0048a945  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 0048a947  7404                   -je 0x48a94d
    if (cpu.flags.zf)
    {
        goto L_0x0048a94d;
    }
    // 0048a949  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0048a94a  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0048a94b  ebd9                   -jmp 0x48a926
    goto L_0x0048a926;
L_0x0048a94d:
    // 0048a94d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048a94f  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 0048a951  88e0                   -mov al, ah
    cpu.al = cpu.ah;
    // 0048a953  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0048a958  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0048a95a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048a95c  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a95d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_48a960(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048a960  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048a961  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048a962  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048a963  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048a964  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048a965  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048a967  83e63f                 -and esi, 0x3f
    cpu.esi &= x86::reg32(x86::sreg32(63 /*0x3f*/));
    // 0048a96a  69f67e480600           -imul esi, esi, 0x6487e
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(411774 /*0x6487e*/)));
    // 0048a970  c1f806                 -sar eax, 6
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (6 /*0x6*/ % 32));
    // 0048a973  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048a975  c0e407                 +shl ah, 7
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
    // 0048a978  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0048a97a  00e4                   +add ah, ah
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
    // 0048a97c  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 0048a97e  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048a980  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0048a985  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048a987  8b048514894c00         -mov eax, dword ptr [eax*4 + 0x4c8914]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5015828) /* 0x4c8914 */ + cpu.eax * 4);
    // 0048a98e  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048a990  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048a992  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0048a994  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048a996  8d8800010000           -lea ecx, [eax + 0x100]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(256) /* 0x100 */);
    // 0048a99c  c0e507                 +shl ch, 7
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
    // 0048a99f  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0048a9a1  00ed                   +add ch, ch
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
    // 0048a9a3  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 0048a9a5  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048a9a7  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0048a9ac  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048a9ae  8b048514894c00         -mov eax, dword ptr [eax*4 + 0x4c8914]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5015828) /* 0x4c8914 */ + cpu.eax * 4);
    // 0048a9b5  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048a9b7  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048a9b9  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 0048a9bc  c1fe09                 -sar esi, 9
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (9 /*0x9*/ % 32));
    // 0048a9bf  0fafc6                 -imul eax, esi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 0048a9c2  c1f815                 -sar eax, 0x15
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (21 /*0x15*/ % 32));
    // 0048a9c5  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 0048a9c7  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a9c8  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a9c9  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a9ca  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a9cb  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a9cc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48a9d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048a9d0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048a9d1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048a9d2  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048a9d3  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048a9d4  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048a9d5  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048a9d7  83e63f                 -and esi, 0x3f
    cpu.esi &= x86::reg32(x86::sreg32(63 /*0x3f*/));
    // 0048a9da  69f67e480600           -imul esi, esi, 0x6487e
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(411774 /*0x6487e*/)));
    // 0048a9e0  c1f806                 -sar eax, 6
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (6 /*0x6*/ % 32));
    // 0048a9e3  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048a9e5  8d8800010000           -lea ecx, [eax + 0x100]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(256) /* 0x100 */);
    // 0048a9eb  c0e507                 +shl ch, 7
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
    // 0048a9ee  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0048a9f0  00ed                   +add ch, ch
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
    // 0048a9f2  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 0048a9f4  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048a9f6  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0048a9fb  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048a9fd  8b048514894c00         -mov eax, dword ptr [eax*4 + 0x4c8914]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5015828) /* 0x4c8914 */ + cpu.eax * 4);
    // 0048aa04  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048aa06  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048aa08  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0048aa0a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048aa0c  c0e407                 +shl ah, 7
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
    // 0048aa0f  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0048aa11  00e4                   +add ah, ah
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
    // 0048aa13  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 0048aa15  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048aa17  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0048aa1c  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048aa1e  8b048514894c00         -mov eax, dword ptr [eax*4 + 0x4c8914]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5015828) /* 0x4c8914 */ + cpu.eax * 4);
    // 0048aa25  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048aa27  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048aa29  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 0048aa2b  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 0048aa2e  c1fe09                 -sar esi, 9
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (9 /*0x9*/ % 32));
    // 0048aa31  0fafc6                 -imul eax, esi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 0048aa34  c1f815                 -sar eax, 0x15
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (21 /*0x15*/ % 32));
    // 0048aa37  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 0048aa39  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048aa3a  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048aa3b  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048aa3c  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048aa3d  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048aa3e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_48aa40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048aa40  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048aa41  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048aa42  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048aa43  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0048aa46  89442408               -mov dword ptr [esp + 8], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0048aa4a  891424                 -mov dword ptr [esp], edx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0048aa4d  894c2404               -mov dword ptr [esp + 4], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0048aa51  b808000000             -mov eax, 8
    cpu.eax = 8 /*0x8*/;
    // 0048aa56  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048aa58  88d9                   -mov cl, bl
    cpu.cl = cpu.bl;
    // 0048aa5a  8944240c               -mov dword ptr [esp + 0xc], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0048aa5e  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048aa63  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0048aa68  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0048aa6a  8a4c240c               -mov cl, byte ptr [esp + 0xc]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048aa6e  a338605200             -mov dword ptr [0x526038], eax
    *app->getMemory<x86::reg32>(x86::reg32(5398584) /* 0x526038 */) = cpu.eax;
    // 0048aa73  d3e3                   -shl ebx, cl
    cpu.ebx <<= cpu.cl % 32;
    // 0048aa75  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048aa79  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048aa7e  01c9                   -add ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0048aa80  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0048aa82  a33c605200             -mov dword ptr [0x52603c], eax
    *app->getMemory<x86::reg32>(x86::reg32(5398588) /* 0x52603c */) = cpu.eax;
    // 0048aa87  a138605200             -mov eax, dword ptr [0x526038]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5398584) /* 0x526038 */);
    // 0048aa8c  a37c605200             -mov dword ptr [0x52607c], eax
    *app->getMemory<x86::reg32>(x86::reg32(5398652) /* 0x52607c */) = cpu.eax;
    // 0048aa91  0fafc0                 -imul eax, eax
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0048aa94  8b1538605200           -mov edx, dword ptr [0x526038]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5398584) /* 0x526038 */);
    // 0048aa9a  891d34605200           -mov dword ptr [0x526034], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5398580) /* 0x526034 */) = cpu.ebx;
    // 0048aaa0  a380605200             -mov dword ptr [0x526080], eax
    *app->getMemory<x86::reg32>(x86::reg32(5398656) /* 0x526080 */) = cpu.eax;
    // 0048aaa5  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048aaa9  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048aaad  e872070000             -call 0x48b224
    cpu.esp -= 4;
    sub_48b224(app, cpu);
    if (cpu.terminate) return;
    // 0048aab2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048aab4  8b1d34605200           -mov ebx, dword ptr [0x526034]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5398580) /* 0x526034 */);
    // 0048aaba  891530605200           -mov dword ptr [0x526030], edx
    *app->getMemory<x86::reg32>(x86::reg32(5398576) /* 0x526030 */) = cpu.edx;
    // 0048aac0  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048aac2  7e23                   -jle 0x48aae7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048aae7;
    }
L_0x0048aac4:
    // 0048aac4  a130605200             -mov eax, dword ptr [0x526030]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5398576) /* 0x526030 */);
    // 0048aac9  80b8cc824c0000         +cmp byte ptr [eax + 0x4c82cc], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5014220) /* 0x4c82cc */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048aad0  7524                   -jne 0x48aaf6
    if (!cpu.flags.zf)
    {
        goto L_0x0048aaf6;
    }
L_0x0048aad2:
    // 0048aad2  8b3530605200           -mov esi, dword ptr [0x526030]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(5398576) /* 0x526030 */);
    // 0048aad8  46                     -inc esi
    (cpu.esi)++;
    // 0048aad9  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048aadd  893530605200           -mov dword ptr [0x526030], esi
    *app->getMemory<x86::reg32>(x86::reg32(5398576) /* 0x526030 */) = cpu.esi;
    // 0048aae3  39fe                   +cmp esi, edi
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
    // 0048aae5  7cdd                   -jl 0x48aac4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048aac4;
    }
L_0x0048aae7:
    // 0048aae7  891d34605200           -mov dword ptr [0x526034], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5398580) /* 0x526034 */) = cpu.ebx;
    // 0048aaed  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0048aaf0  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048aaf1  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048aaf2  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048aaf3  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0048aaf6:
    // 0048aaf6  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    // 0048aaf9  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0048aafc  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048aafe  0fb67702               -movzx esi, byte ptr [edi + 2]
    cpu.esi = x86::reg32(*app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */));
    // 0048ab02  8a4c240c               -mov cl, byte ptr [esp + 0xc]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048ab06  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048ab08  d3f8                   -sar eax, cl
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (cpu.cl % 32));
    // 0048ab0a  0fb66f01               -movzx ebp, byte ptr [edi + 1]
    cpu.ebp = x86::reg32(*app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */));
    // 0048ab0e  a368605200             -mov dword ptr [0x526068], eax
    *app->getMemory<x86::reg32>(x86::reg32(5398632) /* 0x526068 */) = cpu.eax;
    // 0048ab13  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048ab15  d3f8                   -sar eax, cl
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (cpu.cl % 32));
    // 0048ab17  0fb63f                 -movzx edi, byte ptr [edi]
    cpu.edi = x86::reg32(*app->getMemory<x86::reg8>(cpu.edi));
    // 0048ab1a  a358605200             -mov dword ptr [0x526058], eax
    *app->getMemory<x86::reg32>(x86::reg32(5398616) /* 0x526058 */) = cpu.eax;
    // 0048ab1f  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048ab21  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0048ab23  d3f8                   -sar eax, cl
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (cpu.cl % 32));
    // 0048ab25  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0048ab28  a35c605200             -mov dword ptr [0x52605c], eax
    *app->getMemory<x86::reg32>(x86::reg32(5398620) /* 0x52605c */) = cpu.eax;
    // 0048ab2d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048ab2f  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048ab31  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0048ab33  8b0d68605200           -mov ecx, dword ptr [0x526068]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5398632) /* 0x526068 */);
    // 0048ab39  0fafcb                 -imul ecx, ebx
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0048ab3c  8d1401                 -lea edx, [ecx + eax]
    cpu.edx = x86::reg32(cpu.ecx + cpu.eax * 1);
    // 0048ab3f  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0048ab41  0faff3                 -imul esi, ebx
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0048ab44  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048ab46  8b1558605200           -mov edx, dword ptr [0x526058]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5398616) /* 0x526058 */);
    // 0048ab4c  0fafd3                 -imul edx, ebx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0048ab4f  890d6c605200           -mov dword ptr [0x52606c], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5398636) /* 0x52606c */) = cpu.ecx;
    // 0048ab55  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0048ab57  0fafeb                 -imul ebp, ebx
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0048ab5a  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048ab5c  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048ab5e  8b155c605200           -mov edx, dword ptr [0x52605c]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5398620) /* 0x52605c */);
    // 0048ab64  0fafd3                 -imul edx, ebx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0048ab67  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048ab69  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0048ab6b  0faffb                 -imul edi, ebx
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0048ab6e  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0048ab70  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048ab72  0fafc1                 -imul eax, ecx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0048ab75  891564605200           -mov dword ptr [0x526064], edx
    *app->getMemory<x86::reg32>(x86::reg32(5398628) /* 0x526064 */) = cpu.edx;
    // 0048ab7b  8b156c605200           -mov edx, dword ptr [0x52606c]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5398636) /* 0x52606c */);
    // 0048ab81  0fafd2                 -imul edx, edx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0048ab84  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048ab86  a164605200             -mov eax, dword ptr [0x526064]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5398628) /* 0x526064 */);
    // 0048ab8b  0fafc0                 -imul eax, eax
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0048ab8e  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048ab90  a168605200             -mov eax, dword ptr [0x526068]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5398632) /* 0x526068 */);
    // 0048ab95  891564605200           -mov dword ptr [0x526064], edx
    *app->getMemory<x86::reg32>(x86::reg32(5398628) /* 0x526064 */) = cpu.edx;
    // 0048ab9b  8b153c605200           -mov edx, dword ptr [0x52603c]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5398588) /* 0x52603c */);
    // 0048aba1  40                     -inc eax
    (cpu.eax)++;
    // 0048aba2  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0048aba5  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0048aba7  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048aba9  a340605200             -mov dword ptr [0x526040], eax
    *app->getMemory<x86::reg32>(x86::reg32(5398592) /* 0x526040 */) = cpu.eax;
    // 0048abae  a158605200             -mov eax, dword ptr [0x526058]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5398616) /* 0x526058 */);
    // 0048abb3  40                     -inc eax
    (cpu.eax)++;
    // 0048abb4  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0048abb7  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0048abb9  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048abbb  a348605200             -mov dword ptr [0x526048], eax
    *app->getMemory<x86::reg32>(x86::reg32(5398600) /* 0x526048 */) = cpu.eax;
    // 0048abc0  a15c605200             -mov eax, dword ptr [0x52605c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5398620) /* 0x52605c */);
    // 0048abc5  40                     -inc eax
    (cpu.eax)++;
    // 0048abc6  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0048abc9  8b3568605200           -mov esi, dword ptr [0x526068]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(5398632) /* 0x526068 */);
    // 0048abcf  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0048abd1  0faf3580605200         -imul esi, dword ptr [0x526080]
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5398656) /* 0x526080 */))));
    // 0048abd8  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048abda  a344605200             -mov dword ptr [0x526044], eax
    *app->getMemory<x86::reg32>(x86::reg32(5398596) /* 0x526044 */) = cpu.eax;
    // 0048abdf  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048abe3  8d2cb500000000         -lea ebp, [esi*4]
    cpu.ebp = x86::reg32(cpu.esi * 4);
    // 0048abea  8b157c605200           -mov edx, dword ptr [0x52607c]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5398652) /* 0x52607c */);
    // 0048abf0  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048abf2  a158605200             -mov eax, dword ptr [0x526058]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5398616) /* 0x526058 */);
    // 0048abf7  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0048abfa  890d78605200           -mov dword ptr [0x526078], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5398648) /* 0x526078 */) = cpu.ecx;
    // 0048ac00  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0048ac04  891d34605200           -mov dword ptr [0x526034], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5398580) /* 0x526034 */) = cpu.ebx;
    // 0048ac0a  01ce                   -add esi, ecx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0048ac0c  8d3c8500000000         -lea edi, [eax*4]
    cpu.edi = x86::reg32(cpu.eax * 4);
    // 0048ac13  8b155c605200           -mov edx, dword ptr [0x52605c]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5398620) /* 0x52605c */);
    // 0048ac19  01fd                   -add ebp, edi
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edi));
    // 0048ac1b  8b3d5c605200           -mov edi, dword ptr [0x52605c]
    cpu.edi = *app->getMemory<x86::reg32>(x86::reg32(5398620) /* 0x52605c */);
    // 0048ac21  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0048ac23  c1e702                 -shl edi, 2
    cpu.edi <<= 2 /*0x2*/ % 32;
    // 0048ac26  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048ac28  01fd                   +add ebp, edi
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
    // 0048ac2a  891554605200           -mov dword ptr [0x526054], edx
    *app->getMemory<x86::reg32>(x86::reg32(5398612) /* 0x526054 */) = cpu.edx;
    // 0048ac30  892d50605200           -mov dword ptr [0x526050], ebp
    *app->getMemory<x86::reg32>(x86::reg32(5398608) /* 0x526050 */) = cpu.ebp;
    // 0048ac36  e80d000000             -call 0x48ac48
    cpu.esp -= 4;
    sub_48ac48(app, cpu);
    if (cpu.terminate) return;
    // 0048ac3b  8b1d34605200           -mov ebx, dword ptr [0x526034]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5398580) /* 0x526034 */);
    // 0048ac41  e98cfeffff             -jmp 0x48aad2
    goto L_0x0048aad2;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48ac48(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048ac48  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048ac49  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048ac4a  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048ac4b  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048ac4c  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048ac4d  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048ac4e  8b1d3c605200           -mov ebx, dword ptr [0x52603c]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5398588) /* 0x52603c */);
    // 0048ac54  8b0d68605200           -mov ecx, dword ptr [0x526068]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5398632) /* 0x526068 */);
    // 0048ac5a  a164605200             -mov eax, dword ptr [0x526064]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5398628) /* 0x526064 */);
    // 0048ac5f  8b3540605200           -mov esi, dword ptr [0x526040]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(5398592) /* 0x526040 */);
    // 0048ac65  8b3d38605200           -mov edi, dword ptr [0x526038]
    cpu.edi = *app->getMemory<x86::reg32>(x86::reg32(5398584) /* 0x526038 */);
    // 0048ac6b  a36c605200             -mov dword ptr [0x52606c], eax
    *app->getMemory<x86::reg32>(x86::reg32(5398636) /* 0x52606c */) = cpu.eax;
    // 0048ac70  a150605200             -mov eax, dword ptr [0x526050]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5398608) /* 0x526050 */);
    // 0048ac75  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048ac77  a34c605200             -mov dword ptr [0x52604c], eax
    *app->getMemory<x86::reg32>(x86::reg32(5398604) /* 0x52604c */) = cpu.eax;
    // 0048ac7c  a154605200             -mov eax, dword ptr [0x526054]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5398612) /* 0x526054 */);
    // 0048ac81  01db                   -add ebx, ebx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0048ac83  a370605200             -mov dword ptr [0x526070], eax
    *app->getMemory<x86::reg32>(x86::reg32(5398640) /* 0x526070 */) = cpu.eax;
    // 0048ac88  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048ac8d  39f9                   +cmp ecx, edi
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
    // 0048ac8f  0f8cc0000000           -jl 0x48ad55
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048ad55;
    }
L_0x0048ac95:
    // 0048ac95  8b3540605200           -mov esi, dword ptr [0x526040]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(5398592) /* 0x526040 */);
    // 0048ac9b  a164605200             -mov eax, dword ptr [0x526064]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5398628) /* 0x526064 */);
    // 0048aca0  29de                   -sub esi, ebx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048aca2  8b3d80605200           -mov edi, dword ptr [0x526080]
    cpu.edi = *app->getMemory<x86::reg32>(x86::reg32(5398656) /* 0x526080 */);
    // 0048aca8  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0048acaa  c1e702                 -shl edi, 2
    cpu.edi <<= 2 /*0x2*/ % 32;
    // 0048acad  a36c605200             -mov dword ptr [0x52606c], eax
    *app->getMemory<x86::reg32>(x86::reg32(5398636) /* 0x52606c */) = cpu.eax;
    // 0048acb2  a150605200             -mov eax, dword ptr [0x526050]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5398608) /* 0x526050 */);
    // 0048acb7  8b0d68605200           -mov ecx, dword ptr [0x526068]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5398632) /* 0x526068 */);
    // 0048acbd  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0048acbf  8b2d80605200           -mov ebp, dword ptr [0x526080]
    cpu.ebp = *app->getMemory<x86::reg32>(x86::reg32(5398656) /* 0x526080 */);
    // 0048acc5  a34c605200             -mov dword ptr [0x52604c], eax
    *app->getMemory<x86::reg32>(x86::reg32(5398604) /* 0x52604c */) = cpu.eax;
    // 0048acca  a154605200             -mov eax, dword ptr [0x526054]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5398612) /* 0x526054 */);
    // 0048accf  49                     -dec ecx
    (cpu.ecx)--;
    // 0048acd0  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0048acd2  893584605200           -mov dword ptr [0x526084], esi
    *app->getMemory<x86::reg32>(x86::reg32(5398660) /* 0x526084 */) = cpu.esi;
    // 0048acd8  a370605200             -mov dword ptr [0x526070], eax
    *app->getMemory<x86::reg32>(x86::reg32(5398640) /* 0x526070 */) = cpu.eax;
    // 0048acdd  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048ace2  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048ace4  7c60                   -jl 0x48ad46
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048ad46;
    }
L_0x0048ace6:
    // 0048ace6  e8f5000000             -call 0x48ade0
    cpu.esp -= 4;
    sub_48ade0(app, cpu);
    if (cpu.terminate) return;
    // 0048aceb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048aced  0f84dd000000           -je 0x48add0
    if (cpu.flags.zf)
    {
        goto L_0x0048add0;
    }
    // 0048acf3  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x0048acf8:
    // 0048acf8  a180605200             -mov eax, dword ptr [0x526080]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5398656) /* 0x526080 */);
    // 0048acfd  8b354c605200           -mov esi, dword ptr [0x52604c]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(5398604) /* 0x52604c */);
    // 0048ad03  8b3d70605200           -mov edi, dword ptr [0x526070]
    cpu.edi = *app->getMemory<x86::reg32>(x86::reg32(5398640) /* 0x526070 */);
    // 0048ad09  8b2d6c605200           -mov ebp, dword ptr [0x52606c]
    cpu.ebp = *app->getMemory<x86::reg32>(x86::reg32(5398636) /* 0x52606c */);
    // 0048ad0f  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0048ad12  49                     -dec ecx
    (cpu.ecx)--;
    // 0048ad13  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0048ad15  a180605200             -mov eax, dword ptr [0x526080]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5398656) /* 0x526080 */);
    // 0048ad1a  89354c605200           -mov dword ptr [0x52604c], esi
    *app->getMemory<x86::reg32>(x86::reg32(5398604) /* 0x52604c */) = cpu.esi;
    // 0048ad20  8b3584605200           -mov esi, dword ptr [0x526084]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(5398660) /* 0x526084 */);
    // 0048ad26  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0048ad28  29de                   -sub esi, ebx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048ad2a  893d70605200           -mov dword ptr [0x526070], edi
    *app->getMemory<x86::reg32>(x86::reg32(5398640) /* 0x526070 */) = cpu.edi;
    // 0048ad30  893584605200           -mov dword ptr [0x526084], esi
    *app->getMemory<x86::reg32>(x86::reg32(5398660) /* 0x526084 */) = cpu.esi;
    // 0048ad36  29f5                   -sub ebp, esi
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0048ad38  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048ad3a  892d6c605200           -mov dword ptr [0x52606c], ebp
    *app->getMemory<x86::reg32>(x86::reg32(5398636) /* 0x52606c */) = cpu.ebp;
    // 0048ad40  31f0                   -xor eax, esi
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0048ad42  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048ad44  7da0                   -jge 0x48ace6
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048ace6;
    }
L_0x0048ad46:
    // 0048ad46  8b3584605200           -mov esi, dword ptr [0x526084]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(5398660) /* 0x526084 */);
    // 0048ad4c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048ad4e  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ad4f  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ad50  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ad51  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ad52  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ad53  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ad54  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048ad55:
    // 0048ad55  893584605200           -mov dword ptr [0x526084], esi
    *app->getMemory<x86::reg32>(x86::reg32(5398660) /* 0x526084 */) = cpu.esi;
L_0x0048ad5b:
    // 0048ad5b  e880000000             -call 0x48ade0
    cpu.esp -= 4;
    sub_48ade0(app, cpu);
    if (cpu.terminate) return;
    // 0048ad60  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048ad62  745c                   -je 0x48adc0
    if (cpu.flags.zf)
    {
        goto L_0x0048adc0;
    }
    // 0048ad64  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0048ad69  8b3584605200           -mov esi, dword ptr [0x526084]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(5398660) /* 0x526084 */);
L_0x0048ad6f:
    // 0048ad6f  a180605200             -mov eax, dword ptr [0x526080]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5398656) /* 0x526080 */);
    // 0048ad74  8b2d4c605200           -mov ebp, dword ptr [0x52604c]
    cpu.ebp = *app->getMemory<x86::reg32>(x86::reg32(5398604) /* 0x52604c */);
    // 0048ad7a  8b3d70605200           -mov edi, dword ptr [0x526070]
    cpu.edi = *app->getMemory<x86::reg32>(x86::reg32(5398640) /* 0x526070 */);
    // 0048ad80  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0048ad83  41                     -inc ecx
    (cpu.ecx)++;
    // 0048ad84  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048ad86  a180605200             -mov eax, dword ptr [0x526080]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5398656) /* 0x526080 */);
    // 0048ad8b  892d4c605200           -mov dword ptr [0x52604c], ebp
    *app->getMemory<x86::reg32>(x86::reg32(5398604) /* 0x52604c */) = cpu.ebp;
    // 0048ad91  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048ad93  8b2d6c605200           -mov ebp, dword ptr [0x52606c]
    cpu.ebp = *app->getMemory<x86::reg32>(x86::reg32(5398636) /* 0x52606c */);
    // 0048ad99  893d70605200           -mov dword ptr [0x526070], edi
    *app->getMemory<x86::reg32>(x86::reg32(5398640) /* 0x526070 */) = cpu.edi;
    // 0048ad9f  01f5                   -add ebp, esi
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.esi));
    // 0048ada1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048ada3  8b3d38605200           -mov edi, dword ptr [0x526038]
    cpu.edi = *app->getMemory<x86::reg32>(x86::reg32(5398584) /* 0x526038 */);
    // 0048ada9  01de                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0048adab  892d6c605200           -mov dword ptr [0x52606c], ebp
    *app->getMemory<x86::reg32>(x86::reg32(5398636) /* 0x52606c */) = cpu.ebp;
    // 0048adb1  893584605200           -mov dword ptr [0x526084], esi
    *app->getMemory<x86::reg32>(x86::reg32(5398660) /* 0x526084 */) = cpu.esi;
    // 0048adb7  39f9                   +cmp ecx, edi
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
    // 0048adb9  7ca0                   -jl 0x48ad5b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048ad5b;
    }
    // 0048adbb  e9d5feffff             -jmp 0x48ac95
    goto L_0x0048ac95;
L_0x0048adc0:
    // 0048adc0  8b3584605200           -mov esi, dword ptr [0x526084]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(5398660) /* 0x526084 */);
    // 0048adc6  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048adc8  0f85c7feffff           -jne 0x48ac95
    if (!cpu.flags.zf)
    {
        goto L_0x0048ac95;
    }
    // 0048adce  eb9f                   -jmp 0x48ad6f
    goto L_0x0048ad6f;
L_0x0048add0:
    // 0048add0  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048add2  0f856effffff           -jne 0x48ad46
    if (!cpu.flags.zf)
    {
        goto L_0x0048ad46;
    }
    // 0048add8  e91bffffff             -jmp 0x48acf8
    goto L_0x0048acf8;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48ade0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048ade0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048ade1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048ade2  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048ade3  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048ade4  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048ade5  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048ade6  8b353c605200           -mov esi, dword ptr [0x52603c]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(5398588) /* 0x52603c */);
    // 0048adec  01f6                   -add esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi));
    // 0048adee  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048adf0  0f855d020000           -jne 0x48b053
    if (!cpu.flags.zf)
    {
        goto L_0x0048b053;
    }
L_0x0048adf6:
    // 0048adf6  8b0d88605200           -mov ecx, dword ptr [0x526088]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5398664) /* 0x526088 */);
    // 0048adfc  a16c605200             -mov eax, dword ptr [0x52606c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5398636) /* 0x52606c */);
    // 0048ae01  8b1d94605200           -mov ebx, dword ptr [0x526094]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5398676) /* 0x526094 */);
    // 0048ae07  a378605200             -mov dword ptr [0x526078], eax
    *app->getMemory<x86::reg32>(x86::reg32(5398648) /* 0x526078 */) = cpu.eax;
    // 0048ae0c  a39c605200             -mov dword ptr [0x52609c], eax
    *app->getMemory<x86::reg32>(x86::reg32(5398684) /* 0x52609c */) = cpu.eax;
    // 0048ae11  a14c605200             -mov eax, dword ptr [0x52604c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5398604) /* 0x52604c */);
    // 0048ae16  8b3d90605200           -mov edi, dword ptr [0x526090]
    cpu.edi = *app->getMemory<x86::reg32>(x86::reg32(5398672) /* 0x526090 */);
    // 0048ae1c  a360605200             -mov dword ptr [0x526060], eax
    *app->getMemory<x86::reg32>(x86::reg32(5398624) /* 0x526060 */) = cpu.eax;
    // 0048ae21  a3a0605200             -mov dword ptr [0x5260a0], eax
    *app->getMemory<x86::reg32>(x86::reg32(5398688) /* 0x5260a0 */) = cpu.eax;
    // 0048ae26  a170605200             -mov eax, dword ptr [0x526070]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5398640) /* 0x526070 */);
    // 0048ae2b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048ae2d  a374605200             -mov dword ptr [0x526074], eax
    *app->getMemory<x86::reg32>(x86::reg32(5398644) /* 0x526074 */) = cpu.eax;
    // 0048ae32  a3a4605200             -mov dword ptr [0x5260a4], eax
    *app->getMemory<x86::reg32>(x86::reg32(5398692) /* 0x5260a4 */) = cpu.eax;
    // 0048ae37  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048ae3c  39f9                   +cmp ecx, edi
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
    // 0048ae3e  0f8fce000000           -jg 0x48af12
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048af12;
    }
    // 0048ae44  891d98605200           -mov dword ptr [0x526098], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5398680) /* 0x526098 */) = cpu.ebx;
L_0x0048ae4a:
    // 0048ae4a  e84d020000             -call 0x48b09c
    cpu.esp -= 4;
    sub_48b09c(app, cpu);
    if (cpu.terminate) return;
    // 0048ae4f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048ae51  0f8428020000           -je 0x48b07f
    if (cpu.flags.zf)
    {
        goto L_0x0048b07f;
    }
    // 0048ae57  8b1d98605200           -mov ebx, dword ptr [0x526098]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5398680) /* 0x526098 */);
    // 0048ae5d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048ae5f  7537                   -jne 0x48ae98
    if (!cpu.flags.zf)
    {
        goto L_0x0048ae98;
    }
    // 0048ae61  3b0d88605200           +cmp ecx, dword ptr [0x526088]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5398664) /* 0x526088 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048ae67  7e2a                   -jle 0x48ae93
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048ae93;
    }
    // 0048ae69  a1a0605200             -mov eax, dword ptr [0x5260a0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5398688) /* 0x5260a0 */);
    // 0048ae6e  a34c605200             -mov dword ptr [0x52604c], eax
    *app->getMemory<x86::reg32>(x86::reg32(5398604) /* 0x52604c */) = cpu.eax;
    // 0048ae73  a1a4605200             -mov eax, dword ptr [0x5260a4]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5398692) /* 0x5260a4 */);
    // 0048ae78  890d88605200           -mov dword ptr [0x526088], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5398664) /* 0x526088 */) = cpu.ecx;
    // 0048ae7e  a370605200             -mov dword ptr [0x526070], eax
    *app->getMemory<x86::reg32>(x86::reg32(5398640) /* 0x526070 */) = cpu.eax;
    // 0048ae83  a19c605200             -mov eax, dword ptr [0x52609c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5398684) /* 0x52609c */);
    // 0048ae88  891d94605200           -mov dword ptr [0x526094], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5398676) /* 0x526094 */) = cpu.ebx;
    // 0048ae8e  a36c605200             -mov dword ptr [0x52606c], eax
    *app->getMemory<x86::reg32>(x86::reg32(5398636) /* 0x52606c */) = cpu.eax;
L_0x0048ae93:
    // 0048ae93  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x0048ae98:
    // 0048ae98  a17c605200             -mov eax, dword ptr [0x52607c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5398652) /* 0x52607c */);
    // 0048ae9d  8b2d60605200           -mov ebp, dword ptr [0x526060]
    cpu.ebp = *app->getMemory<x86::reg32>(x86::reg32(5398624) /* 0x526060 */);
    // 0048aea3  8b3da0605200           -mov edi, dword ptr [0x5260a0]
    cpu.edi = *app->getMemory<x86::reg32>(x86::reg32(5398688) /* 0x5260a0 */);
    // 0048aea9  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0048aeac  41                     -inc ecx
    (cpu.ecx)++;
    // 0048aead  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048aeaf  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048aeb1  a17c605200             -mov eax, dword ptr [0x52607c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5398652) /* 0x52607c */);
    // 0048aeb6  892d60605200           -mov dword ptr [0x526060], ebp
    *app->getMemory<x86::reg32>(x86::reg32(5398624) /* 0x526060 */) = cpu.ebp;
    // 0048aebc  893da0605200           -mov dword ptr [0x5260a0], edi
    *app->getMemory<x86::reg32>(x86::reg32(5398688) /* 0x5260a0 */) = cpu.edi;
    // 0048aec2  8b2d74605200           -mov ebp, dword ptr [0x526074]
    cpu.ebp = *app->getMemory<x86::reg32>(x86::reg32(5398644) /* 0x526074 */);
    // 0048aec8  8b3da4605200           -mov edi, dword ptr [0x5260a4]
    cpu.edi = *app->getMemory<x86::reg32>(x86::reg32(5398692) /* 0x5260a4 */);
    // 0048aece  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048aed0  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048aed2  892d74605200           -mov dword ptr [0x526074], ebp
    *app->getMemory<x86::reg32>(x86::reg32(5398644) /* 0x526074 */) = cpu.ebp;
    // 0048aed8  893da4605200           -mov dword ptr [0x5260a4], edi
    *app->getMemory<x86::reg32>(x86::reg32(5398692) /* 0x5260a4 */) = cpu.edi;
    // 0048aede  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048aee0  8b2d78605200           -mov ebp, dword ptr [0x526078]
    cpu.ebp = *app->getMemory<x86::reg32>(x86::reg32(5398648) /* 0x526078 */);
    // 0048aee6  8b3d9c605200           -mov edi, dword ptr [0x52609c]
    cpu.edi = *app->getMemory<x86::reg32>(x86::reg32(5398684) /* 0x52609c */);
    // 0048aeec  01dd                   -add ebp, ebx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0048aeee  01df                   -add edi, ebx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0048aef0  892d78605200           -mov dword ptr [0x526078], ebp
    *app->getMemory<x86::reg32>(x86::reg32(5398648) /* 0x526078 */) = cpu.ebp;
    // 0048aef6  893d9c605200           -mov dword ptr [0x52609c], edi
    *app->getMemory<x86::reg32>(x86::reg32(5398684) /* 0x52609c */) = cpu.edi;
    // 0048aefc  01f3                   -add ebx, esi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0048aefe  8b2d90605200           -mov ebp, dword ptr [0x526090]
    cpu.ebp = *app->getMemory<x86::reg32>(x86::reg32(5398672) /* 0x526090 */);
    // 0048af04  891d98605200           -mov dword ptr [0x526098], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5398680) /* 0x526098 */) = cpu.ebx;
    // 0048af0a  39e9                   +cmp ecx, ebp
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
    // 0048af0c  0f8e38ffffff           -jle 0x48ae4a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048ae4a;
    }
L_0x0048af12:
    // 0048af12  8b0d88605200           -mov ecx, dword ptr [0x526088]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5398664) /* 0x526088 */);
    // 0048af18  8b1d94605200           -mov ebx, dword ptr [0x526094]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5398676) /* 0x526094 */);
    // 0048af1e  a16c605200             -mov eax, dword ptr [0x52606c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5398636) /* 0x52606c */);
    // 0048af23  29f3                   -sub ebx, esi
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0048af25  8b3d7c605200           -mov edi, dword ptr [0x52607c]
    cpu.edi = *app->getMemory<x86::reg32>(x86::reg32(5398652) /* 0x52607c */);
    // 0048af2b  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048af2d  c1e702                 -shl edi, 2
    cpu.edi <<= 2 /*0x2*/ % 32;
    // 0048af30  a378605200             -mov dword ptr [0x526078], eax
    *app->getMemory<x86::reg32>(x86::reg32(5398648) /* 0x526078 */) = cpu.eax;
    // 0048af35  a39c605200             -mov dword ptr [0x52609c], eax
    *app->getMemory<x86::reg32>(x86::reg32(5398684) /* 0x52609c */) = cpu.eax;
    // 0048af3a  a14c605200             -mov eax, dword ptr [0x52604c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5398604) /* 0x52604c */);
    // 0048af3f  8b2d8c605200           -mov ebp, dword ptr [0x52608c]
    cpu.ebp = *app->getMemory<x86::reg32>(x86::reg32(5398668) /* 0x52608c */);
    // 0048af45  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0048af47  8b3d7c605200           -mov edi, dword ptr [0x52607c]
    cpu.edi = *app->getMemory<x86::reg32>(x86::reg32(5398652) /* 0x52607c */);
    // 0048af4d  a360605200             -mov dword ptr [0x526060], eax
    *app->getMemory<x86::reg32>(x86::reg32(5398624) /* 0x526060 */) = cpu.eax;
    // 0048af52  a3a0605200             -mov dword ptr [0x5260a0], eax
    *app->getMemory<x86::reg32>(x86::reg32(5398688) /* 0x5260a0 */) = cpu.eax;
    // 0048af57  a170605200             -mov eax, dword ptr [0x526070]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5398640) /* 0x526070 */);
    // 0048af5c  49                     -dec ecx
    (cpu.ecx)--;
    // 0048af5d  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0048af5f  891d98605200           -mov dword ptr [0x526098], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5398680) /* 0x526098 */) = cpu.ebx;
    // 0048af65  a374605200             -mov dword ptr [0x526074], eax
    *app->getMemory<x86::reg32>(x86::reg32(5398644) /* 0x526074 */) = cpu.eax;
    // 0048af6a  a3a4605200             -mov dword ptr [0x5260a4], eax
    *app->getMemory<x86::reg32>(x86::reg32(5398692) /* 0x5260a4 */) = cpu.eax;
    // 0048af6f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048af74  39e9                   +cmp ecx, ebp
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
    // 0048af76  0f8cc8000000           -jl 0x48b044
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048b044;
    }
L_0x0048af7c:
    // 0048af7c  e81b010000             -call 0x48b09c
    cpu.esp -= 4;
    sub_48b09c(app, cpu);
    if (cpu.terminate) return;
    // 0048af81  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048af83  0f8409010000           -je 0x48b092
    if (cpu.flags.zf)
    {
        goto L_0x0048b092;
    }
    // 0048af89  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048af8b  7535                   -jne 0x48afc2
    if (!cpu.flags.zf)
    {
        goto L_0x0048afc2;
    }
    // 0048af8d  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0048af92  a1a0605200             -mov eax, dword ptr [0x5260a0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5398688) /* 0x5260a0 */);
    // 0048af97  8b1d98605200           -mov ebx, dword ptr [0x526098]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5398680) /* 0x526098 */);
    // 0048af9d  a34c605200             -mov dword ptr [0x52604c], eax
    *app->getMemory<x86::reg32>(x86::reg32(5398604) /* 0x52604c */) = cpu.eax;
    // 0048afa2  a1a4605200             -mov eax, dword ptr [0x5260a4]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5398692) /* 0x5260a4 */);
    // 0048afa7  890d88605200           -mov dword ptr [0x526088], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5398664) /* 0x526088 */) = cpu.ecx;
    // 0048afad  a370605200             -mov dword ptr [0x526070], eax
    *app->getMemory<x86::reg32>(x86::reg32(5398640) /* 0x526070 */) = cpu.eax;
    // 0048afb2  a19c605200             -mov eax, dword ptr [0x52609c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5398684) /* 0x52609c */);
    // 0048afb7  891d94605200           -mov dword ptr [0x526094], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5398676) /* 0x526094 */) = cpu.ebx;
    // 0048afbd  a36c605200             -mov dword ptr [0x52606c], eax
    *app->getMemory<x86::reg32>(x86::reg32(5398636) /* 0x52606c */) = cpu.eax;
L_0x0048afc2:
    // 0048afc2  a17c605200             -mov eax, dword ptr [0x52607c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5398652) /* 0x52607c */);
    // 0048afc7  8b1d60605200           -mov ebx, dword ptr [0x526060]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5398624) /* 0x526060 */);
    // 0048afcd  8b3da0605200           -mov edi, dword ptr [0x5260a0]
    cpu.edi = *app->getMemory<x86::reg32>(x86::reg32(5398688) /* 0x5260a0 */);
    // 0048afd3  8b2d74605200           -mov ebp, dword ptr [0x526074]
    cpu.ebp = *app->getMemory<x86::reg32>(x86::reg32(5398644) /* 0x526074 */);
    // 0048afd9  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0048afdc  49                     -dec ecx
    (cpu.ecx)--;
    // 0048afdd  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0048afdf  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0048afe1  a17c605200             -mov eax, dword ptr [0x52607c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5398652) /* 0x52607c */);
    // 0048afe6  891d60605200           -mov dword ptr [0x526060], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5398624) /* 0x526060 */) = cpu.ebx;
    // 0048afec  893da0605200           -mov dword ptr [0x5260a0], edi
    *app->getMemory<x86::reg32>(x86::reg32(5398688) /* 0x5260a0 */) = cpu.edi;
    // 0048aff2  8b1da4605200           -mov ebx, dword ptr [0x5260a4]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5398692) /* 0x5260a4 */);
    // 0048aff8  8b3d78605200           -mov edi, dword ptr [0x526078]
    cpu.edi = *app->getMemory<x86::reg32>(x86::reg32(5398648) /* 0x526078 */);
    // 0048affe  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0048b000  29c5                   -sub ebp, eax
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0048b002  891da4605200           -mov dword ptr [0x5260a4], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5398692) /* 0x5260a4 */) = cpu.ebx;
    // 0048b008  8b1d98605200           -mov ebx, dword ptr [0x526098]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5398680) /* 0x526098 */);
    // 0048b00e  892d74605200           -mov dword ptr [0x526074], ebp
    *app->getMemory<x86::reg32>(x86::reg32(5398644) /* 0x526074 */) = cpu.ebp;
    // 0048b014  29f3                   -sub ebx, esi
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0048b016  8b2d9c605200           -mov ebp, dword ptr [0x52609c]
    cpu.ebp = *app->getMemory<x86::reg32>(x86::reg32(5398684) /* 0x52609c */);
    // 0048b01c  891d98605200           -mov dword ptr [0x526098], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5398680) /* 0x526098 */) = cpu.ebx;
    // 0048b022  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048b024  29df                   -sub edi, ebx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048b026  29dd                   -sub ebp, ebx
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048b028  893d78605200           -mov dword ptr [0x526078], edi
    *app->getMemory<x86::reg32>(x86::reg32(5398648) /* 0x526078 */) = cpu.edi;
    // 0048b02e  892d9c605200           -mov dword ptr [0x52609c], ebp
    *app->getMemory<x86::reg32>(x86::reg32(5398684) /* 0x52609c */) = cpu.ebp;
    // 0048b034  8b3d8c605200           -mov edi, dword ptr [0x52608c]
    cpu.edi = *app->getMemory<x86::reg32>(x86::reg32(5398668) /* 0x52608c */);
    // 0048b03a  31d8                   -xor eax, ebx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048b03c  39f9                   +cmp ecx, edi
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
    // 0048b03e  0f8d38ffffff           -jge 0x48af7c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048af7c;
    }
L_0x0048b044:
    // 0048b044  8b1d98605200           -mov ebx, dword ptr [0x526098]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5398680) /* 0x526098 */);
    // 0048b04a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048b04c  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b04d  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b04e  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b04f  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b050  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b051  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b052  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048b053:
    // 0048b053  a158605200             -mov eax, dword ptr [0x526058]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5398616) /* 0x526058 */);
    // 0048b058  a388605200             -mov dword ptr [0x526088], eax
    *app->getMemory<x86::reg32>(x86::reg32(5398664) /* 0x526088 */) = cpu.eax;
    // 0048b05d  a138605200             -mov eax, dword ptr [0x526038]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5398584) /* 0x526038 */);
    // 0048b062  48                     -dec eax
    (cpu.eax)--;
    // 0048b063  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0048b065  a390605200             -mov dword ptr [0x526090], eax
    *app->getMemory<x86::reg32>(x86::reg32(5398672) /* 0x526090 */) = cpu.eax;
    // 0048b06a  a148605200             -mov eax, dword ptr [0x526048]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5398600) /* 0x526048 */);
    // 0048b06f  890d8c605200           -mov dword ptr [0x52608c], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5398668) /* 0x52608c */) = cpu.ecx;
    // 0048b075  a394605200             -mov dword ptr [0x526094], eax
    *app->getMemory<x86::reg32>(x86::reg32(5398676) /* 0x526094 */) = cpu.eax;
    // 0048b07a  e977fdffff             -jmp 0x48adf6
    goto L_0x0048adf6;
L_0x0048b07f:
    // 0048b07f  8b1d98605200           -mov ebx, dword ptr [0x526098]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5398680) /* 0x526098 */);
    // 0048b085  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048b087  0f8585feffff           -jne 0x48af12
    if (!cpu.flags.zf)
    {
        goto L_0x0048af12;
    }
    // 0048b08d  e906feffff             -jmp 0x48ae98
    goto L_0x0048ae98;
L_0x0048b092:
    // 0048b092  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048b094  75ae                   -jne 0x48b044
    if (!cpu.flags.zf)
    {
        goto L_0x0048b044;
    }
    // 0048b096  e927ffffff             -jmp 0x48afc2
    goto L_0x0048afc2;
}

/* align: skip 0x90 */
void Application::sub_48b09c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b09c  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048b09d  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048b09e  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048b09f  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048b0a0  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048b0a1  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048b0a2  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0048b0a5  8b1530605200           -mov edx, dword ptr [0x526030]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5398576) /* 0x526030 */);
    // 0048b0ab  8b2d3c605200           -mov ebp, dword ptr [0x52603c]
    cpu.ebp = *app->getMemory<x86::reg32>(x86::reg32(5398588) /* 0x52603c */);
    // 0048b0b1  89542404               -mov dword ptr [esp + 4], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0048b0b5  01ed                   -add ebp, ebp
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0048b0b7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048b0b9  0f8582000000           -jne 0x48b141
    if (!cpu.flags.zf)
    {
        goto L_0x0048b141;
    }
L_0x0048b0bf:
    // 0048b0bf  8b0da8605200           -mov ecx, dword ptr [0x5260a8]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5398696) /* 0x5260a8 */);
    // 0048b0c5  8b1578605200           -mov edx, dword ptr [0x526078]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5398648) /* 0x526078 */);
    // 0048b0cb  8b35b4605200           -mov esi, dword ptr [0x5260b4]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(5398708) /* 0x5260b4 */);
    // 0048b0d1  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048b0d3  a160605200             -mov eax, dword ptr [0x526060]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5398624) /* 0x526060 */);
    // 0048b0d8  891c24                 -mov dword ptr [esp], ebx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0048b0db  8b1db0605200           -mov ebx, dword ptr [0x5260b0]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5398704) /* 0x5260b0 */);
    // 0048b0e1  8b3d74605200           -mov edi, dword ptr [0x526074]
    cpu.edi = *app->getMemory<x86::reg32>(x86::reg32(5398644) /* 0x526074 */);
    // 0048b0e7  895c240c               -mov dword ptr [esp + 0xc], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 0048b0eb  39d9                   +cmp ecx, ebx
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
    // 0048b0ed  7f34                   -jg 0x48b123
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048b123;
    }
L_0x0048b0ef:
    // 0048b0ef  3b10                   +cmp edx, dword ptr [eax]
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
    // 0048b0f1  0f8376000000           -jae 0x48b16d
    if (!cpu.flags.cf)
    {
        goto L_0x0048b16d;
    }
    // 0048b0f7  3b0da8605200           +cmp ecx, dword ptr [0x5260a8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5398696) /* 0x5260a8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048b0fd  7e1d                   -jle 0x48b11c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048b11c;
    }
    // 0048b0ff  890da8605200           -mov dword ptr [0x5260a8], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5398696) /* 0x5260a8 */) = cpu.ecx;
    // 0048b105  a360605200             -mov dword ptr [0x526060], eax
    *app->getMemory<x86::reg32>(x86::reg32(5398624) /* 0x526060 */) = cpu.eax;
    // 0048b10a  893d74605200           -mov dword ptr [0x526074], edi
    *app->getMemory<x86::reg32>(x86::reg32(5398644) /* 0x526074 */) = cpu.edi;
    // 0048b110  891578605200           -mov dword ptr [0x526078], edx
    *app->getMemory<x86::reg32>(x86::reg32(5398648) /* 0x526078 */) = cpu.edx;
    // 0048b116  8935b4605200           -mov dword ptr [0x5260b4], esi
    *app->getMemory<x86::reg32>(x86::reg32(5398708) /* 0x5260b4 */) = cpu.esi;
L_0x0048b11c:
    // 0048b11c  c7042401000000         -mov dword ptr [esp], 1
    *app->getMemory<x86::reg32>(cpu.esp) = 1 /*0x1*/;
L_0x0048b123:
    // 0048b123  3b4c240c               +cmp ecx, dword ptr [esp + 0xc]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048b127  7f5b                   -jg 0x48b184
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048b184;
    }
    // 0048b129  3b10                   +cmp edx, dword ptr [eax]
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
    // 0048b12b  7357                   -jae 0x48b184
    if (!cpu.flags.cf)
    {
        goto L_0x0048b184;
    }
    // 0048b12d  8a5c2404               -mov bl, byte ptr [esp + 4]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048b131  41                     -inc ecx
    (cpu.ecx)++;
    // 0048b132  47                     -inc edi
    (cpu.edi)++;
    // 0048b133  8910                   -mov dword ptr [eax], edx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0048b135  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048b138  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0048b13a  885fff                 -mov byte ptr [edi - 1], bl
    *app->getMemory<x86::reg8>(cpu.edi + x86::reg32(-1) /* -0x1 */) = cpu.bl;
    // 0048b13d  01ee                   +add esi, ebp
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048b13f  ebe2                   -jmp 0x48b123
    goto L_0x0048b123;
L_0x0048b141:
    // 0048b141  a15c605200             -mov eax, dword ptr [0x52605c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5398620) /* 0x52605c */);
    // 0048b146  a3a8605200             -mov dword ptr [0x5260a8], eax
    *app->getMemory<x86::reg32>(x86::reg32(5398696) /* 0x5260a8 */) = cpu.eax;
    // 0048b14b  a138605200             -mov eax, dword ptr [0x526038]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5398584) /* 0x526038 */);
    // 0048b150  48                     -dec eax
    (cpu.eax)--;
    // 0048b151  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0048b153  a3b0605200             -mov dword ptr [0x5260b0], eax
    *app->getMemory<x86::reg32>(x86::reg32(5398704) /* 0x5260b0 */) = cpu.eax;
    // 0048b158  a144605200             -mov eax, dword ptr [0x526044]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5398596) /* 0x526044 */);
    // 0048b15d  890dac605200           -mov dword ptr [0x5260ac], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5398700) /* 0x5260ac */) = cpu.ecx;
    // 0048b163  a3b4605200             -mov dword ptr [0x5260b4], eax
    *app->getMemory<x86::reg32>(x86::reg32(5398708) /* 0x5260b4 */) = cpu.eax;
    // 0048b168  e952ffffff             -jmp 0x48b0bf
    goto L_0x0048b0bf;
L_0x0048b16d:
    // 0048b16d  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048b171  41                     -inc ecx
    (cpu.ecx)++;
    // 0048b172  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048b175  47                     -inc edi
    (cpu.edi)++;
    // 0048b176  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0048b178  01ee                   -add esi, ebp
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0048b17a  39d9                   +cmp ecx, ebx
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
    // 0048b17c  0f8e6dffffff           -jle 0x48b0ef
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048b0ef;
    }
    // 0048b182  eb9f                   -jmp 0x48b123
    goto L_0x0048b123;
L_0x0048b184:
    // 0048b184  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    // 0048b187  a1ac605200             -mov eax, dword ptr [0x5260ac]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5398700) /* 0x5260ac */);
    // 0048b18c  8b35a8605200           -mov esi, dword ptr [0x5260a8]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(5398696) /* 0x5260a8 */);
    // 0048b192  8b0db4605200           -mov ecx, dword ptr [0x5260b4]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5398708) /* 0x5260b4 */);
    // 0048b198  8b1560605200           -mov edx, dword ptr [0x526060]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5398624) /* 0x526060 */);
    // 0048b19e  8b3d74605200           -mov edi, dword ptr [0x526074]
    cpu.edi = *app->getMemory<x86::reg32>(x86::reg32(5398644) /* 0x526074 */);
    // 0048b1a4  89442408               -mov dword ptr [esp + 8], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0048b1a8  4e                     -dec esi
    (cpu.esi)--;
    // 0048b1a9  83ea04                 -sub edx, 4
    (cpu.edx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048b1ac  29e9                   -sub ecx, ebp
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0048b1ae  a178605200             -mov eax, dword ptr [0x526078]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5398648) /* 0x526078 */);
    // 0048b1b3  4f                     -dec edi
    (cpu.edi)--;
    // 0048b1b4  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048b1b6  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0048b1b8  7506                   -jne 0x48b1c0
    if (!cpu.flags.zf)
    {
        goto L_0x0048b1c0;
    }
L_0x0048b1ba:
    // 0048b1ba  3b742408               +cmp esi, dword ptr [esp + 8]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048b1be  7d1e                   -jge 0x48b1de
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048b1de;
    }
L_0x0048b1c0:
    // 0048b1c0  3b742408               +cmp esi, dword ptr [esp + 8]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048b1c4  7c4e                   -jl 0x48b214
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048b214;
    }
    // 0048b1c6  3b02                   +cmp eax, dword ptr [edx]
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
    // 0048b1c8  734a                   -jae 0x48b214
    if (!cpu.flags.cf)
    {
        goto L_0x0048b214;
    }
    // 0048b1ca  8a5c2404               -mov bl, byte ptr [esp + 4]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048b1ce  4e                     -dec esi
    (cpu.esi)--;
    // 0048b1cf  4f                     -dec edi
    (cpu.edi)--;
    // 0048b1d0  29e9                   -sub ecx, ebp
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0048b1d2  8902                   -mov dword ptr [edx], eax
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 0048b1d4  83ea04                 -sub edx, 4
    (cpu.edx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048b1d7  29c8                   +sub eax, ecx
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048b1d9  885f01                 -mov byte ptr [edi + 1], bl
    *app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.bl;
    // 0048b1dc  ebe2                   -jmp 0x48b1c0
    goto L_0x0048b1c0;
L_0x0048b1de:
    // 0048b1de  3b02                   +cmp eax, dword ptr [edx]
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
    // 0048b1e0  720b                   -jb 0x48b1ed
    if (cpu.flags.cf)
    {
        goto L_0x0048b1ed;
    }
    // 0048b1e2  4e                     -dec esi
    (cpu.esi)--;
    // 0048b1e3  83ea04                 -sub edx, 4
    (cpu.edx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048b1e6  29e9                   -sub ecx, ebp
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0048b1e8  4f                     -dec edi
    (cpu.edi)--;
    // 0048b1e9  29c8                   +sub eax, ecx
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048b1eb  ebcd                   -jmp 0x48b1ba
    goto L_0x0048b1ba;
L_0x0048b1ed:
    // 0048b1ed  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0048b1f2  8935a8605200           -mov dword ptr [0x5260a8], esi
    *app->getMemory<x86::reg32>(x86::reg32(5398696) /* 0x5260a8 */) = cpu.esi;
    // 0048b1f8  891560605200           -mov dword ptr [0x526060], edx
    *app->getMemory<x86::reg32>(x86::reg32(5398624) /* 0x526060 */) = cpu.edx;
    // 0048b1fe  893d74605200           -mov dword ptr [0x526074], edi
    *app->getMemory<x86::reg32>(x86::reg32(5398644) /* 0x526074 */) = cpu.edi;
    // 0048b204  a378605200             -mov dword ptr [0x526078], eax
    *app->getMemory<x86::reg32>(x86::reg32(5398648) /* 0x526078 */) = cpu.eax;
    // 0048b209  890db4605200           -mov dword ptr [0x5260b4], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5398708) /* 0x5260b4 */) = cpu.ecx;
    // 0048b20f  891c24                 -mov dword ptr [esp], ebx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0048b212  ebac                   -jmp 0x48b1c0
    goto L_0x0048b1c0;
L_0x0048b214:
    // 0048b214  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 0048b217  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0048b21a  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b21b  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b21c  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b21d  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b21e  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b21f  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b220  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48b224(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b224  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048b225  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048b227  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048b229  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0048b22c  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0048b22f  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0048b231  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048b233  7e0f                   -jle 0x48b244
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048b244;
    }
L_0x0048b235:
    // 0048b235  48                     -dec eax
    (cpu.eax)--;
    // 0048b236  c702ffffffff           -mov dword ptr [edx], 0xffffffff
    *app->getMemory<x86::reg32>(cpu.edx) = 4294967295 /*0xffffffff*/;
    // 0048b23c  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048b23f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048b241  7ff2                   -jg 0x48b235
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048b235;
    }
    // 0048b243  90                     -nop 
    ;
L_0x0048b244:
    // 0048b244  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b245  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48b248(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b248  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048b249  8b15c8824c00           -mov edx, dword ptr [0x4c82c8]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5014216) /* 0x4c82c8 */);
    // 0048b24f  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048b251  7502                   -jne 0x48b255
    if (!cpu.flags.zf)
    {
        goto L_0x0048b255;
    }
    // 0048b253  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b254  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048b255:
    // 0048b255  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048b256  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048b258  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048b25a  e86dd8feff             -call 0x478acc
    cpu.esp -= 4;
    sub_478acc(app, cpu);
    if (cpu.terminate) return;
    // 0048b25f  890dc8824c00           -mov dword ptr [0x4c82c8], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5014216) /* 0x4c82c8 */) = cpu.ecx;
    // 0048b265  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b266  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b267  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48b268(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b268  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048b269  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048b26a  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048b26b  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048b26c  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048b26d  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048b26e  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0048b270  ba00800000             -mov edx, 0x8000
    cpu.edx = 32768 /*0x8000*/;
    // 0048b275  b878ec4b00             -mov eax, 0x4bec78
    cpu.eax = 4975736 /*0x4bec78*/;
    // 0048b27a  8b1d50824c00           -mov ebx, dword ptr [0x4c8250]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5014096) /* 0x4c8250 */);
    // 0048b280  e8fbd3feff             -call 0x478680
    cpu.esp -= 4;
    sub_478680(app, cpu);
    if (cpu.terminate) return;
    // 0048b285  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048b287  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0048b289  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048b28b  7509                   -jne 0x48b296
    if (!cpu.flags.zf)
    {
        goto L_0x0048b296;
    }
    // 0048b28d  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048b28f  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b290  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b291  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b292  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b293  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b294  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b295  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048b296:
    // 0048b296  ba00000200             -mov edx, 0x20000
    cpu.edx = 131072 /*0x20000*/;
    // 0048b29b  b884ec4b00             -mov eax, 0x4bec84
    cpu.eax = 4975748 /*0x4bec84*/;
    // 0048b2a0  8b1d50824c00           -mov ebx, dword ptr [0x4c8250]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5014096) /* 0x4c8250 */);
    // 0048b2a6  e8d5d3feff             -call 0x478680
    cpu.esp -= 4;
    sub_478680(app, cpu);
    if (cpu.terminate) return;
    // 0048b2ab  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048b2ad  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048b2af  750b                   -jne 0x48b2bc
    if (!cpu.flags.zf)
    {
        goto L_0x0048b2bc;
    }
    // 0048b2b1  31cf                   -xor edi, ecx
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048b2b3  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048b2b5  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b2b6  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b2b7  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b2b8  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b2b9  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b2ba  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b2bb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048b2bc:
    // 0048b2bc  bb05000000             -mov ebx, 5
    cpu.ebx = 5 /*0x5*/;
    // 0048b2c1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048b2c2  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0048b2c4  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048b2c6  b800010000             -mov eax, 0x100
    cpu.eax = 256 /*0x100*/;
    // 0048b2cb  e870f7ffff             -call 0x48aa40
    cpu.esp -= 4;
    sub_48aa40(app, cpu);
    if (cpu.terminate) return;
    // 0048b2d0  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048b2d2  e8f5d7feff             -call 0x478acc
    cpu.esp -= 4;
    sub_478acc(app, cpu);
    if (cpu.terminate) return;
    // 0048b2d7  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048b2d9  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b2da  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b2db  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b2dc  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b2dd  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b2de  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b2df  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48b2e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b2e0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048b2e1  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048b2e2  81ec00040000           -sub esp, 0x400
    (cpu.esp) -= x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 0048b2e8  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0048b2ea  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048b2ec  b800010000             -mov eax, 0x100
    cpu.eax = 256 /*0x100*/;
    // 0048b2f1  e8aa330100             -call 0x49e6a0
    cpu.esp -= 4;
    sub_49e6a0(app, cpu);
    if (cpu.terminate) return;
    // 0048b2f6  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0048b2f8  e86bffffff             -call 0x48b268
    cpu.esp -= 4;
    sub_48b268(app, cpu);
    if (cpu.terminate) return;
    // 0048b2fd  81c400040000           -add esp, 0x400
    (cpu.esp) += x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 0048b303  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b304  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b305  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48b308(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b308  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048b309  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048b30a  81ec00040000           -sub esp, 0x400
    (cpu.esp) -= x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 0048b310  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0048b312  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048b314  b800010000             -mov eax, 0x100
    cpu.eax = 256 /*0x100*/;
    // 0048b319  e876340100             -call 0x49e794
    cpu.esp -= 4;
    sub_49e794(app, cpu);
    if (cpu.terminate) return;
    // 0048b31e  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0048b320  e843ffffff             -call 0x48b268
    cpu.esp -= 4;
    sub_48b268(app, cpu);
    if (cpu.terminate) return;
    // 0048b325  81c400040000           -add esp, 0x400
    (cpu.esp) += x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 0048b32b  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b32c  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b32d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48b330(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b330  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048b331  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048b332  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048b333  81ec00040000           -sub esp, 0x400
    (cpu.esp) -= x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 0048b339  e80affffff             -call 0x48b248
    cpu.esp -= 4;
    sub_48b248(app, cpu);
    if (cpu.terminate) return;
    // 0048b33e  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0048b340  ba00010000             -mov edx, 0x100
    cpu.edx = 256 /*0x100*/;
    // 0048b345  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048b347  e87c260000             -call 0x48d9c8
    cpu.esp -= 4;
    sub_48d9c8(app, cpu);
    if (cpu.terminate) return;
    // 0048b34c  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0048b34e  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048b350  e813ffffff             -call 0x48b268
    cpu.esp -= 4;
    sub_48b268(app, cpu);
    if (cpu.terminate) return;
    // 0048b355  a3c8824c00             -mov dword ptr [0x4c82c8], eax
    *app->getMemory<x86::reg32>(x86::reg32(5014216) /* 0x4c82c8 */) = cpu.eax;
    // 0048b35a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048b35c  7405                   -je 0x48b363
    if (cpu.flags.zf)
    {
        goto L_0x0048b363;
    }
    // 0048b35e  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
L_0x0048b363:
    // 0048b363  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048b365  81c400040000           -add esp, 0x400
    (cpu.esp) += x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 0048b36b  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b36c  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b36d  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b36e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_48b370(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b370  e90e350100             -jmp 0x49e883
    return sub_49e883(app, cpu);
}

/* align: skip  */
/* data blob: 03104000574154434f4d20432f432b2b33322052756e2d54696d652073797374656d2e2028632920436f7079726967687420627920574154434f4d20496e7465726e6174696f6e616c20436f72702e20313938382d313939352e20416c6c207269676874732072657365727665642e */
void Application::sub_48b3e4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b3e4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48b3e5(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b3e5  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048b3e6  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048b3e7  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048b3e9  ff1548a44c00           -call dword ptr [0x4ca448]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5022792) /* 0x4ca448 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048b3ef  803dfc2b540000         +cmp byte ptr [0x542bfc], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(x86::reg32(5516284) /* 0x542bfc */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048b3f6  750f                   -jne 0x48b407
    if (!cpu.flags.zf)
    {
        goto L_0x0048b407;
    }
    // 0048b3f8  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
    // 0048b3fd  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
    // 0048b402  e804370100             -call 0x49eb0b
    cpu.esp -= 4;
    sub_49eb0b(app, cpu);
    if (cpu.terminate) return;
L_0x0048b407:
    // 0048b407  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048b409  e803000000             -call 0x48b411
    cpu.esp -= 4;
    sub_48b411(app, cpu);
    if (cpu.terminate) return;
    // 0048b40e  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b40f  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b410  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48b411(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b411  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048b412  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048b414  ff1548a44c00           -call dword ptr [0x4ca448]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5022792) /* 0x4ca448 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048b41a  ff154ca44c00           -call dword ptr [0x4ca44c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5022796) /* 0x4ca44c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048b420  833dd0c14c0000         +cmp dword ptr [0x4cc1d0], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5030352) /* 0x4cc1d0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048b427  7406                   -je 0x48b42f
    if (cpu.flags.zf)
    {
        goto L_0x0048b42f;
    }
    // 0048b429  ff15d0c14c00           -call dword ptr [0x4cc1d0]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5030352) /* 0x4cc1d0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0048b42f:
    // 0048b42f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048b431  e998e20000             -jmp 0x4996ce
    return sub_4996ce(app, cpu);
}

/* align: skip  */
void Application::sub_48b436(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b436  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048b437  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048b438  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
L_0x0048b439:
    // 0048b439  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax);
    // 0048b43b  fec2                   -inc dl
    (cpu.dl)++;
    // 0048b43d  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0048b443  f68284c84c0002         +test byte ptr [edx + 0x4cc884], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5032068) /* 0x4cc884 */) & 2 /*0x2*/));
    // 0048b44a  7403                   -je 0x48b44f
    if (cpu.flags.zf)
    {
        goto L_0x0048b44f;
    }
    // 0048b44c  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0048b44d  ebea                   -jmp 0x48b439
    goto L_0x0048b439;
L_0x0048b44f:
    // 0048b44f  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.eax);
    // 0048b451  80f92b                 +cmp cl, 0x2b
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(43 /*0x2b*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048b454  7405                   -je 0x48b45b
    if (cpu.flags.zf)
    {
        goto L_0x0048b45b;
    }
    // 0048b456  80f92d                 +cmp cl, 0x2d
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(45 /*0x2d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048b459  7501                   -jne 0x48b45c
    if (!cpu.flags.zf)
    {
        goto L_0x0048b45c;
    }
L_0x0048b45b:
    // 0048b45b  40                     -inc eax
    (cpu.eax)++;
L_0x0048b45c:
    // 0048b45c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0048b45e:
    // 0048b45e  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax);
    // 0048b460  fec2                   -inc dl
    (cpu.dl)++;
    // 0048b462  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0048b468  f68284c84c0020         +test byte ptr [edx + 0x4cc884], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5032068) /* 0x4cc884 */) & 32 /*0x20*/));
    // 0048b46f  740f                   -je 0x48b480
    if (cpu.flags.zf)
    {
        goto L_0x0048b480;
    }
    // 0048b471  6bdb0a                 -imul ebx, ebx, 0xa
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(10 /*0xa*/)));
    // 0048b474  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048b476  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax);
    // 0048b478  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048b47a  40                     -inc eax
    (cpu.eax)++;
    // 0048b47b  83eb30                 +sub ebx, 0x30
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(48 /*0x30*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048b47e  ebde                   -jmp 0x48b45e
    goto L_0x0048b45e;
L_0x0048b480:
    // 0048b480  80f92d                 +cmp cl, 0x2d
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(45 /*0x2d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048b483  7502                   -jne 0x48b487
    if (!cpu.flags.zf)
    {
        goto L_0x0048b487;
    }
    // 0048b485  f7db                   -neg ebx
    cpu.ebx = ~cpu.ebx + 1;
L_0x0048b487:
    // 0048b487  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048b489  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b48a  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b48b  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b48c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_48b490(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b490  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048b491  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048b492  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048b493  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048b494  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048b496  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0048b498  8915c8605200           -mov dword ptr [0x5260c8], edx
    *app->getMemory<x86::reg32>(x86::reg32(5398728) /* 0x5260c8 */) = cpu.edx;
    // 0048b49e  c7403000000000         -mov dword ptr [eax + 0x30], 0
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */) = 0 /*0x0*/;
    // 0048b4a5  8b4034                 -mov eax, dword ptr [eax + 0x34]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    // 0048b4a8  e87f66ffff             -call 0x481b2c
    cpu.esp -= 4;
    sub_481b2c(app, cpu);
    if (cpu.terminate) return;
    // 0048b4ad  8b4634                 -mov eax, dword ptr [esi + 0x34]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */);
    // 0048b4b0  e83762ffff             -call 0x4816ec
    cpu.esp -= 4;
    sub_4816ec(app, cpu);
    if (cpu.terminate) return;
    // 0048b4b5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048b4b7  7508                   -jne 0x48b4c1
    if (!cpu.flags.zf)
    {
        goto L_0x0048b4c1;
    }
    // 0048b4b9  8b4730                 -mov eax, dword ptr [edi + 0x30]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(48) /* 0x30 */);
    // 0048b4bc  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b4bd  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b4be  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b4bf  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b4c0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048b4c1:
    // 0048b4c1  8b5648                 -mov edx, dword ptr [esi + 0x48]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */);
    // 0048b4c4  8b4e44                 -mov ecx, dword ptr [esi + 0x44]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(68) /* 0x44 */);
    // 0048b4c7  8b5e40                 -mov ebx, dword ptr [esi + 0x40]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(64) /* 0x40 */);
    // 0048b4ca  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048b4cb  8b4634                 -mov eax, dword ptr [esi + 0x34]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */);
    // 0048b4ce  8b563c                 -mov edx, dword ptr [esi + 0x3c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(60) /* 0x3c */);
    // 0048b4d1  e87668ffff             -call 0x481d4c
    cpu.esp -= 4;
    sub_481d4c(app, cpu);
    if (cpu.terminate) return;
    // 0048b4d6  8b4634                 -mov eax, dword ptr [esi + 0x34]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */);
    // 0048b4d9  e8b263ffff             -call 0x481890
    cpu.esp -= 4;
    sub_481890(app, cpu);
    if (cpu.terminate) return;
    // 0048b4de  8b4634                 -mov eax, dword ptr [esi + 0x34]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */);
    // 0048b4e1  e8ca63ffff             -call 0x4818b0
    cpu.esp -= 4;
    sub_4818b0(app, cpu);
    if (cpu.terminate) return;
    // 0048b4e6  8b4634                 -mov eax, dword ptr [esi + 0x34]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */);
    // 0048b4e9  e8325cffff             -call 0x481120
    cpu.esp -= 4;
    sub_481120(app, cpu);
    if (cpu.terminate) return;
    // 0048b4ee  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048b4f0  750f                   -jne 0x48b501
    if (!cpu.flags.zf)
    {
        goto L_0x0048b501;
    }
    // 0048b4f2  c7463001000000         -mov dword ptr [esi + 0x30], 1
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */) = 1 /*0x1*/;
    // 0048b4f9  8b4730                 -mov eax, dword ptr [edi + 0x30]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(48) /* 0x30 */);
    // 0048b4fc  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b4fd  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b4fe  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b4ff  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b500  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048b501:
    // 0048b501  8b4634                 -mov eax, dword ptr [esi + 0x34]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */);
    // 0048b504  e8c763ffff             -call 0x4818d0
    cpu.esp -= 4;
    sub_4818d0(app, cpu);
    if (cpu.terminate) return;
    // 0048b509  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048b50b  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b50c  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b50d  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b50e  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b50f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48b510(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b510  c7403000000000         -mov dword ptr [eax + 0x30], 0
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */) = 0 /*0x0*/;
    // 0048b517  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048b51c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48b520(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b520  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048b521  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048b522  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048b523  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048b525  8b1dc8605200           -mov ebx, dword ptr [0x5260c8]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5398728) /* 0x5260c8 */);
    // 0048b52b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048b52d  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0048b52f  7507                   -jne 0x48b538
    if (!cpu.flags.zf)
    {
        goto L_0x0048b538;
    }
L_0x0048b531:
    // 0048b531  8b4130                 -mov eax, dword ptr [ecx + 0x30]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(48) /* 0x30 */);
    // 0048b534  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b535  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b536  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b537  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048b538:
    // 0048b538  8b4034                 -mov eax, dword ptr [eax + 0x34]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    // 0048b53b  e85869ffff             -call 0x481e98
    cpu.esp -= 4;
    sub_481e98(app, cpu);
    if (cpu.terminate) return;
    // 0048b540  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048b542  74ed                   -je 0x48b531
    if (cpu.flags.zf)
    {
        goto L_0x0048b531;
    }
    // 0048b544  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048b546  ff15c8605200           -call dword ptr [0x5260c8]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5398728) /* 0x5260c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048b54c  8b4130                 -mov eax, dword ptr [ecx + 0x30]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(48) /* 0x30 */);
    // 0048b54f  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b550  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b551  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b552  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48b554(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b554  8b4034                 -mov eax, dword ptr [eax + 0x34]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    // 0048b557  e99069ffff             -jmp 0x481eec
    return sub_481eec(app, cpu);
}

/* align: skip  */
void Application::sub_48b55c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b55c  8b4034                 -mov eax, dword ptr [eax + 0x34]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    // 0048b55f  e93469ffff             -jmp 0x481e98
    return sub_481e98(app, cpu);
}

/* align: skip  */
void Application::sub_48b564(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b564  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048b565  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048b567  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048b569  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0048b56b  8b4934                 -mov ecx, dword ptr [ecx + 0x34]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(52) /* 0x34 */);
    // 0048b56e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048b570  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048b572  e8916affff             -call 0x482008
    cpu.esp -= 4;
    sub_482008(app, cpu);
    if (cpu.terminate) return;
    // 0048b577  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048b579  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048b57b  7c04                   -jl 0x48b581
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048b581;
    }
    // 0048b57d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048b57f  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b580  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048b581:
    // 0048b581  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 0048b583  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048b585  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b586  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48b588(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b588  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048b589  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048b58b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048b58d  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0048b58f  8b4934                 -mov ecx, dword ptr [ecx + 0x34]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(52) /* 0x34 */);
    // 0048b592  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048b594  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048b596  e8fd65ffff             -call 0x481b98
    cpu.esp -= 4;
    sub_481b98(app, cpu);
    if (cpu.terminate) return;
    // 0048b59b  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b59c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48b5a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b5a0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048b5a1  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048b5a2  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048b5a4  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0048b5a6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048b5a8  745b                   -je 0x48b605
    if (cpu.flags.zf)
    {
        goto L_0x0048b605;
    }
    // 0048b5aa  83782400               +cmp dword ptr [eax + 0x24], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048b5ae  7516                   -jne 0x48b5c6
    if (!cpu.flags.zf)
    {
        goto L_0x0048b5c6;
    }
    // 0048b5b0  8b1534824c00           -mov edx, dword ptr [0x4c8234]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5014068) /* 0x4c8234 */);
    // 0048b5b6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048b5b8  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0048b5bb  c1e204                 +shl edx, 4
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
    // 0048b5be  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0048b5c0  c1f804                 -sar eax, 4
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (4 /*0x4*/ % 32));
    // 0048b5c3  894624                 -mov dword ptr [esi + 0x24], eax
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.eax;
L_0x0048b5c6:
    // 0048b5c6  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048b5c7  837e2800               +cmp dword ptr [esi + 0x28], 0
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
    // 0048b5cb  7515                   -jne 0x48b5e2
    if (!cpu.flags.zf)
    {
        goto L_0x0048b5e2;
    }
    // 0048b5cd  8b1534824c00           -mov edx, dword ptr [0x4c8234]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5014068) /* 0x4c8234 */);
    // 0048b5d3  bf0a000000             -mov edi, 0xa
    cpu.edi = 10 /*0xa*/;
    // 0048b5d8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048b5da  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0048b5dd  f7ff                   -idiv edi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.edi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0048b5df  894628                 -mov dword ptr [esi + 0x28], eax
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.eax;
L_0x0048b5e2:
    // 0048b5e2  837e2c00               +cmp dword ptr [esi + 0x2c], 0
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
    // 0048b5e6  7515                   -jne 0x48b5fd
    if (!cpu.flags.zf)
    {
        goto L_0x0048b5fd;
    }
    // 0048b5e8  8b1534824c00           -mov edx, dword ptr [0x4c8234]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5014068) /* 0x4c8234 */);
    // 0048b5ee  bf0a000000             -mov edi, 0xa
    cpu.edi = 10 /*0xa*/;
    // 0048b5f3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048b5f5  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0048b5f8  f7ff                   -idiv edi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.edi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0048b5fa  89462c                 -mov dword ptr [esi + 0x2c], eax
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */) = cpu.eax;
L_0x0048b5fd:
    // 0048b5fd  c7460803000000         -mov dword ptr [esi + 8], 3
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = 3 /*0x3*/;
    // 0048b604  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0048b605:
    // 0048b605  ba94274c00             -mov edx, 0x4c2794
    cpu.edx = 4990868 /*0x4c2794*/;
    // 0048b60a  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048b60b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048b60d  bb50a44c00             -mov ebx, 0x4ca450
    cpu.ebx = 5022800 /*0x4ca450*/;
    // 0048b612  e8313cffff             -call 0x47f248
    cpu.esp -= 4;
    sub_47f248(app, cpu);
    if (cpu.terminate) return;
    // 0048b617  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b618  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b619  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_48b61c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b61c  e93b350100             -jmp 0x49eb5c
    return sub_49eb5c(app, cpu);
}

/* align: skip  */
void Application::sub_48b621(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b621  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048b623  e8bdfdffff             -call 0x48b3e5
    cpu.esp -= 4;
    sub_48b3e5(app, cpu);
    if (cpu.terminate) return;
    // 0048b628  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048b62a  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048b62c  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048b62e  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048b630  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048b631  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048b632  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048b634  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0048b636  803d6cab4c0000         +cmp byte ptr [0x4cab6c], 0
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
    // 0048b63d  7405                   -je 0x48b644
    if (cpu.flags.zf)
    {
        goto L_0x0048b644;
    }
    // 0048b63f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048b641  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b642  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b643  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048b644:
    // 0048b644  e86f39ffff             -call 0x47efb8
    cpu.esp -= 4;
    sub_47efb8(app, cpu);
    if (cpu.terminate) return;
    // 0048b649  a3508a5200             -mov dword ptr [0x528a50], eax
    *app->getMemory<x86::reg32>(x86::reg32(5409360) /* 0x528a50 */) = cpu.eax;
    // 0048b64e  e8c5000000             -call 0x48b718
    cpu.esp -= 4;
    sub_48b718(app, cpu);
    if (cpu.terminate) return;
    // 0048b653  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048b655  e802010000             -call 0x48b75c
    cpu.esp -= 4;
    sub_48b75c(app, cpu);
    if (cpu.terminate) return;
    // 0048b65a  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0048b65c  e89325ffff             -call 0x47dbf4
    cpu.esp -= 4;
    sub_47dbf4(app, cpu);
    if (cpu.terminate) return;
    // 0048b661  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048b663  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048b665  7c0d                   -jl 0x48b674
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048b674;
    }
    // 0048b667  b201                   -mov dl, 1
    cpu.dl = 1 /*0x1*/;
    // 0048b669  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048b66b  88156cab4c00           -mov byte ptr [0x4cab6c], dl
    *app->getMemory<x86::reg8>(x86::reg32(5024620) /* 0x4cab6c */) = cpu.dl;
    // 0048b671  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b672  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b673  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048b674:
    // 0048b674  e8eb25ffff             -call 0x47dc64
    cpu.esp -= 4;
    sub_47dc64(app, cpu);
    if (cpu.terminate) return;
    // 0048b679  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048b67b  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b67c  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b67d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48b630(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0048b630;
    // 0048b621  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048b623  e8bdfdffff             -call 0x48b3e5
    cpu.esp -= 4;
    sub_48b3e5(app, cpu);
    if (cpu.terminate) return;
    // 0048b628  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048b62a  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048b62c  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048b62e  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
L_entry_0x0048b630:
    // 0048b630  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048b631  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048b632  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048b634  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0048b636  803d6cab4c0000         +cmp byte ptr [0x4cab6c], 0
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
    // 0048b63d  7405                   -je 0x48b644
    if (cpu.flags.zf)
    {
        goto L_0x0048b644;
    }
    // 0048b63f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048b641  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b642  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b643  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048b644:
    // 0048b644  e86f39ffff             -call 0x47efb8
    cpu.esp -= 4;
    sub_47efb8(app, cpu);
    if (cpu.terminate) return;
    // 0048b649  a3508a5200             -mov dword ptr [0x528a50], eax
    *app->getMemory<x86::reg32>(x86::reg32(5409360) /* 0x528a50 */) = cpu.eax;
    // 0048b64e  e8c5000000             -call 0x48b718
    cpu.esp -= 4;
    sub_48b718(app, cpu);
    if (cpu.terminate) return;
    // 0048b653  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048b655  e802010000             -call 0x48b75c
    cpu.esp -= 4;
    sub_48b75c(app, cpu);
    if (cpu.terminate) return;
    // 0048b65a  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0048b65c  e89325ffff             -call 0x47dbf4
    cpu.esp -= 4;
    sub_47dbf4(app, cpu);
    if (cpu.terminate) return;
    // 0048b661  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048b663  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048b665  7c0d                   -jl 0x48b674
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048b674;
    }
    // 0048b667  b201                   -mov dl, 1
    cpu.dl = 1 /*0x1*/;
    // 0048b669  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048b66b  88156cab4c00           -mov byte ptr [0x4cab6c], dl
    *app->getMemory<x86::reg8>(x86::reg32(5024620) /* 0x4cab6c */) = cpu.dl;
    // 0048b671  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b672  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b673  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048b674:
    // 0048b674  e8eb25ffff             -call 0x47dc64
    cpu.esp -= 4;
    sub_47dc64(app, cpu);
    if (cpu.terminate) return;
    // 0048b679  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048b67b  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b67c  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b67d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48b680(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b680  803d6cab4c0000         +cmp byte ptr [0x4cab6c], 0
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
    // 0048b687  7506                   -jne 0x48b68f
    if (!cpu.flags.zf)
    {
        goto L_0x0048b68f;
    }
    // 0048b689  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 0048b68e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048b68f:
    // 0048b68f  e87cdcffff             -call 0x489310
    cpu.esp -= 4;
    sub_489310(app, cpu);
    if (cpu.terminate) return;
    // 0048b694  833d8cab4c0000         +cmp dword ptr [0x4cab8c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5024652) /* 0x4cab8c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048b69b  7406                   -je 0x48b6a3
    if (cpu.flags.zf)
    {
        goto L_0x0048b6a3;
    }
    // 0048b69d  ff158cab4c00           -call dword ptr [0x4cab8c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5024652) /* 0x4cab8c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0048b6a3:
    // 0048b6a3  833d90ab4c0000         +cmp dword ptr [0x4cab90], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5024656) /* 0x4cab90 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048b6aa  7406                   -je 0x48b6b2
    if (cpu.flags.zf)
    {
        goto L_0x0048b6b2;
    }
    // 0048b6ac  ff1590ab4c00           -call dword ptr [0x4cab90]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5024656) /* 0x4cab90 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0048b6b2:
    // 0048b6b2  833d94ab4c0000         +cmp dword ptr [0x4cab94], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5024660) /* 0x4cab94 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048b6b9  7406                   -je 0x48b6c1
    if (cpu.flags.zf)
    {
        goto L_0x0048b6c1;
    }
    // 0048b6bb  ff1594ab4c00           -call dword ptr [0x4cab94]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5024660) /* 0x4cab94 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0048b6c1:
    // 0048b6c1  833d84ab4c0000         +cmp dword ptr [0x4cab84], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5024644) /* 0x4cab84 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048b6c8  740b                   -je 0x48b6d5
    if (cpu.flags.zf)
    {
        goto L_0x0048b6d5;
    }
    // 0048b6ca  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0048b6cf  ff1584ab4c00           -call dword ptr [0x4cab84]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5024644) /* 0x4cab84 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0048b6d5:
    // 0048b6d5  833d98ab4c0000         +cmp dword ptr [0x4cab98], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5024664) /* 0x4cab98 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048b6dc  7406                   -je 0x48b6e4
    if (cpu.flags.zf)
    {
        goto L_0x0048b6e4;
    }
    // 0048b6de  ff1598ab4c00           -call dword ptr [0x4cab98]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5024664) /* 0x4cab98 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0048b6e4:
    // 0048b6e4  833d88ab4c0000         +cmp dword ptr [0x4cab88], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5024648) /* 0x4cab88 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048b6eb  7406                   -je 0x48b6f3
    if (cpu.flags.zf)
    {
        goto L_0x0048b6f3;
    }
    // 0048b6ed  ff1588ab4c00           -call dword ptr [0x4cab88]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5024648) /* 0x4cab88 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0048b6f3:
    // 0048b6f3  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048b6f4  e86b25ffff             -call 0x47dc64
    cpu.esp -= 4;
    sub_47dc64(app, cpu);
    if (cpu.terminate) return;
    // 0048b6f9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048b6fb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048b6fd  7c0a                   -jl 0x48b709
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048b709;
    }
    // 0048b6ff  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048b700  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 0048b702  881d6cab4c00           -mov byte ptr [0x4cab6c], bl
    *app->getMemory<x86::reg8>(x86::reg32(5024620) /* 0x4cab6c */) = cpu.bl;
    // 0048b708  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0048b709:
    // 0048b709  a1508a5200             -mov eax, dword ptr [0x528a50]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5409360) /* 0x528a50 */);
    // 0048b70e  e82139ffff             -call 0x47f034
    cpu.esp -= 4;
    sub_47f034(app, cpu);
    if (cpu.terminate) return;
    // 0048b713  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048b715  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b716  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48b718(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b718  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048b719  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0048b71b:
    // 0048b71b  83c060                 -add eax, 0x60
    (cpu.eax) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 0048b71e  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 0048b720  8890ac835200           -mov byte ptr [eax + 0x5283ac], dl
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5407660) /* 0x5283ac */) = cpu.dl;
    // 0048b726  3d00060000             +cmp eax, 0x600
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1536 /*0x600*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048b72b  75ee                   -jne 0x48b71b
    if (!cpu.flags.zf)
    {
        goto L_0x0048b71b;
    }
    // 0048b72d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0048b72f:
    // 0048b72f  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0048b732  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048b734  8990f8895200           -mov dword ptr [eax + 0x5289f8], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5409272) /* 0x5289f8 */) = cpu.edx;
    // 0048b73a  8990fc895200           -mov dword ptr [eax + 0x5289fc], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5409276) /* 0x5289fc */) = cpu.edx;
    // 0048b740  83f850                 +cmp eax, 0x50
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
    // 0048b743  75ea                   -jne 0x48b72f
    if (!cpu.flags.zf)
    {
        goto L_0x0048b72f;
    }
    // 0048b745  8915588a5200           -mov dword ptr [0x528a58], edx
    *app->getMemory<x86::reg32>(x86::reg32(5409368) /* 0x528a58 */) = cpu.edx;
    // 0048b74b  8915548a5200           -mov dword ptr [0x528a54], edx
    *app->getMemory<x86::reg32>(x86::reg32(5409364) /* 0x528a54 */) = cpu.edx;
    // 0048b751  c6055d8a52007f         -mov byte ptr [0x528a5d], 0x7f
    *app->getMemory<x86::reg8>(x86::reg32(5409373) /* 0x528a5d */) = 127 /*0x7f*/;
    // 0048b758  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b759  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48b75c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b75c  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048b75d  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048b75e  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048b75f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048b761  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048b763  e89421ffff             -call 0x47d8fc
    cpu.esp -= 4;
    sub_47d8fc(app, cpu);
    if (cpu.terminate) return;
    // 0048b768  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048b76a  83fbff                 +cmp ebx, -1
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
    // 0048b76d  754c                   -jne 0x48b7bb
    if (!cpu.flags.zf)
    {
        goto L_0x0048b7bb;
    }
L_0x0048b76f:
    // 0048b76f  21d0                   -and eax, edx
    cpu.eax &= x86::reg32(x86::sreg32(cpu.edx));
    // 0048b771  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048b773  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048b775  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048b777  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0048b77d  81e200ff0000           -and edx, 0xff00
    cpu.edx &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 0048b783  81e60000ff00           -and esi, 0xff0000
    cpu.esi &= x86::reg32(x86::sreg32(16711680 /*0xff0000*/));
    // 0048b789  83fbff                 +cmp ebx, -1
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
    // 0048b78c  7502                   -jne 0x48b790
    if (!cpu.flags.zf)
    {
        goto L_0x0048b790;
    }
    // 0048b78e  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x0048b790:
    // 0048b790  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048b792  742b                   -je 0x48b7bf
    if (cpu.flags.zf)
    {
        goto L_0x0048b7bf;
    }
    // 0048b794  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048b796  7427                   -je 0x48b7bf
    if (cpu.flags.zf)
    {
        goto L_0x0048b7bf;
    }
    // 0048b798  f6c108                 +test cl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 8 /*0x8*/));
    // 0048b79b  7428                   -je 0x48b7c5
    if (cpu.flags.zf)
    {
        goto L_0x0048b7c5;
    }
    // 0048b79d  b808000000             -mov eax, 8
    cpu.eax = 8 /*0x8*/;
L_0x0048b7a2:
    // 0048b7a2  f6c608                 +test dh, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 8 /*0x8*/));
    // 0048b7a5  743d                   -je 0x48b7e4
    if (cpu.flags.zf)
    {
        goto L_0x0048b7e4;
    }
    // 0048b7a7  80cc08                 -or ah, 8
    cpu.ah |= x86::reg8(x86::sreg8(8 /*0x8*/));
L_0x0048b7aa:
    // 0048b7aa  f7c600000200           +test esi, 0x20000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & 131072 /*0x20000*/));
    // 0048b7b0  7405                   -je 0x48b7b7
    if (cpu.flags.zf)
    {
        goto L_0x0048b7b7;
    }
    // 0048b7b2  0d00000200             +or eax, 0x20000
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(131072 /*0x20000*/))));
L_0x0048b7b7:
    // 0048b7b7  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b7b8  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b7b9  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b7ba  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048b7bb:
    // 0048b7bb  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048b7bd  ebb0                   -jmp 0x48b76f
    goto L_0x0048b76f;
L_0x0048b7bf:
    // 0048b7bf  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048b7c1  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b7c2  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b7c3  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b7c4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048b7c5:
    // 0048b7c5  f6c102                 +test cl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 2 /*0x2*/));
    // 0048b7c8  7407                   -je 0x48b7d1
    if (cpu.flags.zf)
    {
        goto L_0x0048b7d1;
    }
    // 0048b7ca  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0048b7cf  ebd1                   -jmp 0x48b7a2
    goto L_0x0048b7a2;
L_0x0048b7d1:
    // 0048b7d1  f6c104                 +test cl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 4 /*0x4*/));
    // 0048b7d4  7407                   -je 0x48b7dd
    if (cpu.flags.zf)
    {
        goto L_0x0048b7dd;
    }
    // 0048b7d6  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 0048b7db  ebc5                   -jmp 0x48b7a2
    goto L_0x0048b7a2;
L_0x0048b7dd:
    // 0048b7dd  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048b7e2  ebbe                   -jmp 0x48b7a2
    goto L_0x0048b7a2;
L_0x0048b7e4:
    // 0048b7e4  f6c610                 +test dh, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 16 /*0x10*/));
    // 0048b7e7  7405                   -je 0x48b7ee
    if (cpu.flags.zf)
    {
        goto L_0x0048b7ee;
    }
    // 0048b7e9  80cc10                 +or ah, 0x10
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(16 /*0x10*/))));
    // 0048b7ec  ebbc                   -jmp 0x48b7aa
    goto L_0x0048b7aa;
L_0x0048b7ee:
    // 0048b7ee  f6c604                 +test dh, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 4 /*0x4*/));
    // 0048b7f1  7405                   -je 0x48b7f8
    if (cpu.flags.zf)
    {
        goto L_0x0048b7f8;
    }
    // 0048b7f3  80cc04                 +or ah, 4
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(4 /*0x4*/))));
    // 0048b7f6  ebb2                   -jmp 0x48b7aa
    goto L_0x0048b7aa;
L_0x0048b7f8:
    // 0048b7f8  f6c620                 +test dh, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 32 /*0x20*/));
    // 0048b7fb  7405                   -je 0x48b802
    if (cpu.flags.zf)
    {
        goto L_0x0048b802;
    }
    // 0048b7fd  80cc20                 +or ah, 0x20
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(32 /*0x20*/))));
    // 0048b800  eba8                   -jmp 0x48b7aa
    goto L_0x0048b7aa;
L_0x0048b802:
    // 0048b802  f6c602                 +test dh, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 2 /*0x2*/));
    // 0048b805  7405                   -je 0x48b80c
    if (cpu.flags.zf)
    {
        goto L_0x0048b80c;
    }
    // 0048b807  80cc02                 +or ah, 2
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(2 /*0x2*/))));
    // 0048b80a  eb9e                   -jmp 0x48b7aa
    goto L_0x0048b7aa;
L_0x0048b80c:
    // 0048b80c  80cc01                 +or ah, 1
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 0048b80f  eb99                   -jmp 0x48b7aa
    goto L_0x0048b7aa;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_48b820(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b820  803d6cab4c0000         +cmp byte ptr [0x4cab6c], 0
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
    // 0048b827  7506                   -jne 0x48b82f
    if (!cpu.flags.zf)
    {
        goto L_0x0048b82f;
    }
    // 0048b829  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 0048b82e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048b82f:
    // 0048b82f  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048b830  a144a04c00             -mov eax, dword ptr [0x4ca044]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5021764) /* 0x4ca044 */);
    // 0048b835  e896330100             -call 0x49ebd0
    cpu.esp -= 4;
    sub_49ebd0(app, cpu);
    if (cpu.terminate) return;
    // 0048b83a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048b83c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048b83e  7c04                   -jl 0x48b844
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048b844;
    }
    // 0048b840  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048b842  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b843  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048b844:
    // 0048b844  0fbe15b6a04c00         -movsx edx, byte ptr [0x4ca0b6]
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(*app->getMemory<x86::reg8>(x86::reg32(5021878) /* 0x4ca0b6 */)));
    // 0048b84b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048b84d  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b84e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48b84f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b84f  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048b850  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048b851  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048b852  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0048b855  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048b856  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048b857  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0048b859  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 0048b85b  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0048b85e  ff1548c14c00           -call dword ptr [0x4cc148]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5030216) /* 0x4cc148 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048b864  f6410c02               +test byte ptr [ecx + 0xc], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) & 2 /*0x2*/));
    // 0048b868  751e                   -jne 0x48b888
    if (!cpu.flags.zf)
    {
        goto L_0x0048b888;
    }
    // 0048b86a  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 0048b86f  e8cca30000             -call 0x495c40
    cpu.esp -= 4;
    sub_495c40(app, cpu);
    if (cpu.terminate) return;
    // 0048b874  80490c20               -or byte ptr [ecx + 0xc], 0x20
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) |= x86::reg8(x86::sreg8(32 /*0x20*/));
    // 0048b878  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0048b87b  ff154cc14c00           -call dword ptr [0x4cc14c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5030220) /* 0x4cc14c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048b881  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0048b883  e9c6010000             -jmp 0x48ba4e
    goto L_0x0048ba4e;
L_0x0048b888:
    // 0048b888  0faffa                 -imul edi, edx
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0048b88b  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0048b88d  7510                   -jne 0x48b89f
    if (!cpu.flags.zf)
    {
        goto L_0x0048b89f;
    }
    // 0048b88f  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0048b892  ff154cc14c00           -call dword ptr [0x4cc14c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5030220) /* 0x4cc14c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048b898  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048b89a  e9af010000             -jmp 0x48ba4e
    goto L_0x0048ba4e;
L_0x0048b89f:
    // 0048b89f  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0048b8a2  83780800               +cmp dword ptr [eax + 8], 0
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
    // 0048b8a6  7507                   -jne 0x48b8af
    if (!cpu.flags.zf)
    {
        goto L_0x0048b8af;
    }
    // 0048b8a8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048b8aa  e86c330100             -call 0x49ec1b
    cpu.esp -= 4;
    sub_49ec1b(app, cpu);
    if (cpu.terminate) return;
L_0x0048b8af:
    // 0048b8af  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0048b8b2  8a550c                 -mov dl, byte ptr [ebp + 0xc]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0048b8b5  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048b8b7  83e030                 -and eax, 0x30
    cpu.eax &= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 0048b8ba  80e2cf                 -and dl, 0xcf
    cpu.dl &= x86::reg8(x86::sreg8(207 /*0xcf*/));
    // 0048b8bd  894c240c               -mov dword ptr [esp + 0xc], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0048b8c1  89442408               -mov dword ptr [esp + 8], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0048b8c5  88550c                 -mov byte ptr [ebp + 0xc], dl
    *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.dl;
    // 0048b8c8  f6c240                 +test dl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 64 /*0x40*/));
    // 0048b8cb  0f84e1000000           -je 0x48b9b2
    if (cpu.flags.zf)
    {
        goto L_0x0048b9b2;
    }
    // 0048b8d1  897c2410               -mov dword ptr [esp + 0x10], edi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edi;
L_0x0048b8d5:
    // 0048b8d5  837d0400               +cmp dword ptr [ebp + 4], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048b8d9  7544                   -jne 0x48b91f
    if (!cpu.flags.zf)
    {
        goto L_0x0048b91f;
    }
    // 0048b8db  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0048b8df  3b4514                 +cmp eax, dword ptr [ebp + 0x14]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048b8e2  723b                   -jb 0x48b91f
    if (cpu.flags.cf)
    {
        goto L_0x0048b91f;
    }
    // 0048b8e4  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048b8e6  30c3                   -xor bl, al
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.al));
    // 0048b8e8  80e7fe                 -and bh, 0xfe
    cpu.bh &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 0048b8eb  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0048b8ed  7502                   -jne 0x48b8f1
    if (!cpu.flags.zf)
    {
        goto L_0x0048b8f1;
    }
    // 0048b8ef  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x0048b8f1:
    // 0048b8f1  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048b8f5  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0048b8f8  e8a5330100             -call 0x49eca2
    cpu.esp -= 4;
    sub_49eca2(app, cpu);
    if (cpu.terminate) return;
    // 0048b8fd  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048b8ff  83f8ff                 +cmp eax, -1
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
    // 0048b902  7415                   -je 0x48b919
    if (cpu.flags.zf)
    {
        goto L_0x0048b919;
    }
    // 0048b904  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048b906  0f8573000000           -jne 0x48b97f
    if (!cpu.flags.zf)
    {
        goto L_0x0048b97f;
    }
    // 0048b90c  ff1544c14c00           -call dword ptr [0x4cc144]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5030212) /* 0x4cc144 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048b912  c740040c000000         -mov dword ptr [eax + 4], 0xc
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 12 /*0xc*/;
L_0x0048b919:
    // 0048b919  804d0c20               +or byte ptr [ebp + 0xc], 0x20
    cpu.clear_co();
    cpu.set_szp((*app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(12) /* 0xc */) |= x86::reg8(x86::sreg8(32 /*0x20*/))));
    // 0048b91d  eb60                   -jmp 0x48b97f
    goto L_0x0048b97f;
L_0x0048b91f:
    // 0048b91f  8b5514                 -mov edx, dword ptr [ebp + 0x14]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0048b922  8b7504                 -mov esi, dword ptr [ebp + 4]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 0048b925  8b7c2410               -mov edi, dword ptr [esp + 0x10]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0048b929  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0048b92b  39fa                   +cmp edx, edi
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
    // 0048b92d  7602                   -jbe 0x48b931
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0048b931;
    }
    // 0048b92f  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
L_0x0048b931:
    // 0048b931  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048b935  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0048b937  8b7d00                 -mov edi, dword ptr [ebp]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebp);
    // 0048b93a  06                     -push es
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0048b93b  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0048b93d  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 0048b93f  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048b940  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048b942  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0048b945  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048b947  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0048b949  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0048b94c  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0048b94e  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b94f  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0048b950  8b5d04                 -mov ebx, dword ptr [ebp + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 0048b953  8b4500                 -mov eax, dword ptr [ebp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp);
    // 0048b956  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048b958  8b4d14                 -mov ecx, dword ptr [ebp + 0x14]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0048b95b  895d04                 -mov dword ptr [ebp + 4], ebx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0048b95e  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048b960  8a7d0d                 -mov bh, byte ptr [ebp + 0xd]
    cpu.bh = *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(13) /* 0xd */);
    // 0048b963  894500                 -mov dword ptr [ebp], eax
    *app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
    // 0048b966  80cf10                 -or bh, 0x10
    cpu.bh |= x86::reg8(x86::sreg8(16 /*0x10*/));
    // 0048b969  8b4504                 -mov eax, dword ptr [ebp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 0048b96c  887d0d                 -mov byte ptr [ebp + 0xd], bh
    *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(13) /* 0xd */) = cpu.bh;
    // 0048b96f  39c8                   +cmp eax, ecx
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
    // 0048b971  7405                   -je 0x48b978
    if (cpu.flags.zf)
    {
        goto L_0x0048b978;
    }
    // 0048b973  f6c704                 +test bh, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 4 /*0x4*/));
    // 0048b976  7407                   -je 0x48b97f
    if (cpu.flags.zf)
    {
        goto L_0x0048b97f;
    }
L_0x0048b978:
    // 0048b978  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048b97a  e861f00000             -call 0x49a9e0
    cpu.esp -= 4;
    sub_49a9e0(app, cpu);
    if (cpu.terminate) return;
L_0x0048b97f:
    // 0048b97f  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048b983  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048b987  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0048b98b  01d6                   -add esi, edx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048b98d  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048b98f  89742404               -mov dword ptr [esp + 4], esi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 0048b993  897c240c               -mov dword ptr [esp + 0xc], edi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 0048b997  29d0                   +sub eax, edx
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
    // 0048b999  89442410               -mov dword ptr [esp + 0x10], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0048b99d  0f847f000000           -je 0x48ba22
    if (cpu.flags.zf)
    {
        goto L_0x0048ba22;
    }
    // 0048b9a3  f6450c20               +test byte ptr [ebp + 0xc], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(12) /* 0xc */) & 32 /*0x20*/));
    // 0048b9a7  0f8428ffffff           -je 0x48b8d5
    if (cpu.flags.zf)
    {
        goto L_0x0048b8d5;
    }
    // 0048b9ad  e970000000             -jmp 0x48ba22
    goto L_0x0048ba22;
L_0x0048b9b2:
    // 0048b9b2  8a5d0d                 -mov bl, byte ptr [ebp + 0xd]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(13) /* 0xd */);
    // 0048b9b5  f6c304                 +test bl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 4 /*0x4*/));
    // 0048b9b8  7414                   -je 0x48b9ce
    if (cpu.flags.zf)
    {
        goto L_0x0048b9ce;
    }
    // 0048b9ba  88df                   -mov bh, bl
    cpu.bh = cpu.bl;
    // 0048b9bc  80e7fa                 -and bh, 0xfa
    cpu.bh &= x86::reg8(x86::sreg8(250 /*0xfa*/));
    // 0048b9bf  88f8                   -mov al, bh
    cpu.al = cpu.bh;
    // 0048b9c1  887d0d                 -mov byte ptr [ebp + 0xd], bh
    *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(13) /* 0xd */) = cpu.bh;
    // 0048b9c4  0c01                   -or al, 1
    cpu.al |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 0048b9c6  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0048b9cb  88450d                 -mov byte ptr [ebp + 0xd], al
    *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(13) /* 0xd */) = cpu.al;
L_0x0048b9ce:
    // 0048b9ce  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0048b9d1  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048b9d5  8b700c                 -mov esi, dword ptr [eax + 0xc]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0048b9d8  c7400c01000000         -mov dword ptr [eax + 0xc], 1
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 1 /*0x1*/;
L_0x0048b9df:
    // 0048b9df  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048b9e1  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0048b9e3  8a03                   -mov al, byte ptr [ebx]
    cpu.al = *app->getMemory<x86::reg8>(cpu.ebx);
    // 0048b9e5  e882330100             -call 0x49ed6c
    cpu.esp -= 4;
    sub_49ed6c(app, cpu);
    if (cpu.terminate) return;
    // 0048b9ea  8a550c                 -mov dl, byte ptr [ebp + 0xc]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0048b9ed  43                     -inc ebx
    (cpu.ebx)++;
    // 0048b9ee  f6c230                 +test dl, 0x30
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 48 /*0x30*/));
    // 0048b9f1  750d                   -jne 0x48ba00
    if (!cpu.flags.zf)
    {
        goto L_0x0048ba00;
    }
    // 0048b9f3  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048b9f7  40                     -inc eax
    (cpu.eax)++;
    // 0048b9f8  8944240c               -mov dword ptr [esp + 0xc], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0048b9fc  39c7                   +cmp edi, eax
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
    // 0048b9fe  75df                   -jne 0x48b9df
    if (!cpu.flags.zf)
    {
        goto L_0x0048b9df;
    }
L_0x0048ba00:
    // 0048ba00  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0048ba03  89700c                 -mov dword ptr [eax + 0xc], esi
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 0048ba06  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048ba08  7418                   -je 0x48ba22
    if (cpu.flags.zf)
    {
        goto L_0x0048ba22;
    }
    // 0048ba0a  8a750d                 -mov dh, byte ptr [ebp + 0xd]
    cpu.dh = *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(13) /* 0xd */);
    // 0048ba0d  80e6fa                 -and dh, 0xfa
    cpu.dh &= x86::reg8(x86::sreg8(250 /*0xfa*/));
    // 0048ba10  88f3                   -mov bl, dh
    cpu.bl = cpu.dh;
    // 0048ba12  88750d                 -mov byte ptr [ebp + 0xd], dh
    *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(13) /* 0xd */) = cpu.dh;
    // 0048ba15  80cb04                 -or bl, 4
    cpu.bl |= x86::reg8(x86::sreg8(4 /*0x4*/));
    // 0048ba18  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048ba1a  885d0d                 -mov byte ptr [ebp + 0xd], bl
    *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(13) /* 0xd */) = cpu.bl;
    // 0048ba1d  e8beef0000             -call 0x49a9e0
    cpu.esp -= 4;
    sub_49a9e0(app, cpu);
    if (cpu.terminate) return;
L_0x0048ba22:
    // 0048ba22  f6450c20               +test byte ptr [ebp + 0xc], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(12) /* 0xc */) & 32 /*0x20*/));
    // 0048ba26  7406                   -je 0x48ba2e
    if (cpu.flags.zf)
    {
        goto L_0x0048ba2e;
    }
    // 0048ba28  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048ba2a  895c240c               -mov dword ptr [esp + 0xc], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
L_0x0048ba2e:
    // 0048ba2e  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048ba32  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    // 0048ba35  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0048ba38  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048ba3a  09c1                   -or ecx, eax
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0048ba3c  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0048ba3f  894d0c                 -mov dword ptr [ebp + 0xc], ecx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0048ba42  ff154cc14c00           -call dword ptr [0x4cc14c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5030220) /* 0x4cc14c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048ba48  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048ba4c  f7f6                   -div esi
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.esi;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
L_0x0048ba4e:
    // 0048ba4e  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0048ba51  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ba52  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ba53  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ba54  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_48ba60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048ba60  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048ba61  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048ba62  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048ba65  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0048ba68  66f7442402ffff         +test word ptr [esp + 2], 0xffff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(*app->getMemory<x86::reg16>(cpu.esp + x86::reg32(2) /* 0x2 */) & 65535 /*0xffff*/));
    // 0048ba6f  0f8476000000           -je 0x48baeb
    if (cpu.flags.zf)
    {
        goto L_0x0048baeb;
    }
    // 0048ba75  f6442403ff             +test byte ptr [esp + 3], 0xff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.esp + x86::reg32(3) /* 0x3 */) & 255 /*0xff*/));
    // 0048ba7a  7443                   -je 0x48babf
    if (cpu.flags.zf)
    {
        goto L_0x0048babf;
    }
    // 0048ba7c  c1e818                 -shr eax, 0x18
    cpu.eax >>= 24 /*0x18*/ % 32;
    // 0048ba7f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048ba81  8a9087c94c00           -mov dl, byte ptr [eax + 0x4cc987]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5032327) /* 0x4cc987 */);
    // 0048ba87  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 0048ba8a  8a8088c94c00           -mov al, byte ptr [eax + 0x4cc988]
    cpu.al = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5032328) /* 0x4cc988 */);
    // 0048ba90  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0048ba95  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0048ba98  8d8800010000           -lea ecx, [eax + 0x100]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(256) /* 0x100 */);
L_0x0048ba9e:
    // 0048ba9e  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048ba9f  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048baa0  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
L_0x0048baa4:
    // 0048baa4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048baa6  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048baa8  83f801                 +cmp eax, 1
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
    // 0048baab  7634                   -jbe 0x48bae1
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0048bae1;
    }
    // 0048baad  8d040a                 -lea eax, [edx + ecx]
    cpu.eax = x86::reg32(cpu.edx + cpu.ecx * 1);
    // 0048bab0  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 0048bab2  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048bab4  0fafd8                 -imul ebx, eax
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0048bab7  39f3                   +cmp ebx, esi
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
    // 0048bab9  7622                   -jbe 0x48badd
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0048badd;
    }
    // 0048babb  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048babd  ebe5                   -jmp 0x48baa4
    goto L_0x0048baa4;
L_0x0048babf:
    // 0048babf  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 0048bac2  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048bac4  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048bac6  8a8888c94c00           -mov cl, byte ptr [eax + 0x4cc988]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5032328) /* 0x4cc988 */);
    // 0048bacc  8a9087c94c00           -mov dl, byte ptr [eax + 0x4cc987]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5032327) /* 0x4cc987 */);
    // 0048bad2  c1e104                 -shl ecx, 4
    cpu.ecx <<= 4 /*0x4*/ % 32;
    // 0048bad5  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 0048bad8  83c110                 +add ecx, 0x10
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048badb  ebc1                   -jmp 0x48ba9e
    goto L_0x0048ba9e;
L_0x0048badd:
    // 0048badd  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048badf  ebc3                   -jmp 0x48baa4
    goto L_0x0048baa4;
L_0x0048bae1:
    // 0048bae1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048bae3  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bae4  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0048bae5:
    // 0048bae5  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048bae8  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bae9  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048baea  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048baeb:
    // 0048baeb  8a642401               -mov ah, byte ptr [esp + 1]
    cpu.ah = *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */);
    // 0048baef  f6c4ff                 +test ah, 0xff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 255 /*0xff*/));
    // 0048baf2  0f84b0000000           -je 0x48bba8
    if (cpu.flags.zf)
    {
        goto L_0x0048bba8;
    }
    // 0048baf8  f6c4f0                 +test ah, 0xf0
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 240 /*0xf0*/));
    // 0048bafb  745f                   -je 0x48bb5c
    if (cpu.flags.zf)
    {
        goto L_0x0048bb5c;
    }
    // 0048bafd  f6c4c0                 +test ah, 0xc0
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 192 /*0xc0*/));
    // 0048bb00  743a                   -je 0x48bb3c
    if (cpu.flags.zf)
    {
        goto L_0x0048bb3c;
    }
    // 0048bb02  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    // 0048bb05  c1ea08                 -shr edx, 8
    cpu.edx >>= 8 /*0x8*/ % 32;
    // 0048bb08  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048bb0a  8a8287c94c00           -mov al, byte ptr [edx + 0x4cc987]
    cpu.al = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5032327) /* 0x4cc987 */);
    // 0048bb10  8a9288c94c00           -mov dl, byte ptr [edx + 0x4cc988]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5032328) /* 0x4cc988 */);
    // 0048bb16  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
L_0x0048bb1c:
    // 0048bb1c  42                     -inc edx
    (cpu.edx)++;
    // 0048bb1d  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0048bb1f  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0048bb21  83f901                 +cmp ecx, 1
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
    // 0048bb24  76bf                   -jbe 0x48bae5
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0048bae5;
    }
    // 0048bb26  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048bb28  d1ea                   -shr edx, 1
    cpu.edx >>= 1 /*0x1*/ % 32;
    // 0048bb2a  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0048bb2c  0fafca                 -imul ecx, edx
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0048bb2f  3b0c24                 +cmp ecx, dword ptr [esp]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esp)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048bb32  77b1                   -ja 0x48bae5
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0048bae5;
    }
    // 0048bb34  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048bb36  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048bb39  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bb3a  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bb3b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048bb3c:
    // 0048bb3c  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    // 0048bb3f  c1ea06                 -shr edx, 6
    cpu.edx >>= 6 /*0x6*/ % 32;
    // 0048bb42  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048bb44  8a8287c94c00           -mov al, byte ptr [edx + 0x4cc987]
    cpu.al = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5032327) /* 0x4cc987 */);
    // 0048bb4a  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0048bb4c  8a9288c94c00           -mov dl, byte ptr [edx + 0x4cc988]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5032328) /* 0x4cc988 */);
    // 0048bb52  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0048bb58  d1fa                   +sar edx, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 0048bb5a  ebc0                   -jmp 0x48bb1c
    goto L_0x0048bb1c;
L_0x0048bb5c:
    // 0048bb5c  f6c40c                 +test ah, 0xc
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 12 /*0xc*/));
    // 0048bb5f  7422                   -je 0x48bb83
    if (cpu.flags.zf)
    {
        goto L_0x0048bb83;
    }
    // 0048bb61  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    // 0048bb64  c1ea04                 -shr edx, 4
    cpu.edx >>= 4 /*0x4*/ % 32;
    // 0048bb67  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048bb69  8a8287c94c00           -mov al, byte ptr [edx + 0x4cc987]
    cpu.al = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5032327) /* 0x4cc987 */);
    // 0048bb6f  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 0048bb72  8a9288c94c00           -mov dl, byte ptr [edx + 0x4cc988]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5032328) /* 0x4cc988 */);
    // 0048bb78  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0048bb7e  c1fa02                 +sar edx, 2
    {
        x86::reg8 tmp = 2 /*0x2*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 0048bb81  eb99                   -jmp 0x48bb1c
    goto L_0x0048bb1c;
L_0x0048bb83:
    // 0048bb83  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    // 0048bb86  c1ea02                 -shr edx, 2
    cpu.edx >>= 2 /*0x2*/ % 32;
    // 0048bb89  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048bb8b  8a8287c94c00           -mov al, byte ptr [edx + 0x4cc987]
    cpu.al = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5032327) /* 0x4cc987 */);
    // 0048bb91  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 0048bb94  8a9288c94c00           -mov dl, byte ptr [edx + 0x4cc988]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5032328) /* 0x4cc988 */);
    // 0048bb9a  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0048bba0  c1fa03                 +sar edx, 3
    {
        x86::reg8 tmp = 3 /*0x3*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 0048bba3  e974ffffff             -jmp 0x48bb1c
    goto L_0x0048bb1c;
L_0x0048bba8:
    // 0048bba8  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    // 0048bbab  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048bbad  7411                   -je 0x48bbc0
    if (cpu.flags.zf)
    {
        goto L_0x0048bbc0;
    }
    // 0048bbaf  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048bbb1  8a8287c94c00           -mov al, byte ptr [edx + 0x4cc987]
    cpu.al = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5032327) /* 0x4cc987 */);
    // 0048bbb7  c1f804                 -sar eax, 4
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (4 /*0x4*/ % 32));
    // 0048bbba  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048bbbd  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bbbe  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bbbf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048bbc0:
    // 0048bbc0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048bbc2  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048bbc5  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bbc6  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bbc7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_48bbd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048bbd0  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048bbd1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048bbd3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048bbd5  7504                   -jne 0x48bbdb
    if (!cpu.flags.zf)
    {
        goto L_0x0048bbdb;
    }
L_0x0048bbd7:
    // 0048bbd7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048bbd9  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bbda  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048bbdb:
    // 0048bbdb  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 0048bbdd  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 0048bbe0  8a8090a84c00           -mov al, byte ptr [eax + 0x4ca890]
    cpu.al = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5023888) /* 0x4ca890 */);
    // 0048bbe6  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048bbe8  74ed                   -je 0x48bbd7
    if (cpu.flags.zf)
    {
        goto L_0x0048bbd7;
    }
L_0x0048bbea:
    // 0048bbea  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx);
    // 0048bbec  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0048bbf1  83f822                 +cmp eax, 0x22
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(34 /*0x22*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048bbf4  7438                   -je 0x48bc2e
    if (cpu.flags.zf)
    {
        goto L_0x0048bc2e;
    }
    // 0048bbf6  83f824                 +cmp eax, 0x24
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(36 /*0x24*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048bbf9  7433                   -je 0x48bc2e
    if (cpu.flags.zf)
    {
        goto L_0x0048bc2e;
    }
    // 0048bbfb  83f823                 +cmp eax, 0x23
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(35 /*0x23*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048bbfe  742e                   -je 0x48bc2e
    if (cpu.flags.zf)
    {
        goto L_0x0048bc2e;
    }
    // 0048bc00  83f829                 +cmp eax, 0x29
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(41 /*0x29*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048bc03  7429                   -je 0x48bc2e
    if (cpu.flags.zf)
    {
        goto L_0x0048bc2e;
    }
    // 0048bc05  83f82a                 +cmp eax, 0x2a
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(42 /*0x2a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048bc08  7424                   -je 0x48bc2e
    if (cpu.flags.zf)
    {
        goto L_0x0048bc2e;
    }
    // 0048bc0a  83f82c                 +cmp eax, 0x2c
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(44 /*0x2c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048bc0d  741f                   -je 0x48bc2e
    if (cpu.flags.zf)
    {
        goto L_0x0048bc2e;
    }
    // 0048bc0f  83f82d                 +cmp eax, 0x2d
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(45 /*0x2d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048bc12  741a                   -je 0x48bc2e
    if (cpu.flags.zf)
    {
        goto L_0x0048bc2e;
    }
    // 0048bc14  83f82e                 +cmp eax, 0x2e
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(46 /*0x2e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048bc17  7415                   -je 0x48bc2e
    if (cpu.flags.zf)
    {
        goto L_0x0048bc2e;
    }
    // 0048bc19  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx);
    // 0048bc1b  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 0048bc1e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048bc20  7402                   -je 0x48bc24
    if (cpu.flags.zf)
    {
        goto L_0x0048bc24;
    }
    // 0048bc22  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
L_0x0048bc24:
    // 0048bc24  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048bc26  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048bc28  75c0                   -jne 0x48bbea
    if (!cpu.flags.zf)
    {
        goto L_0x0048bbea;
    }
    // 0048bc2a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048bc2c  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bc2d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048bc2e:
    // 0048bc2e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048bc30  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bc31  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48bc34(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048bc34  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048bc35  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048bc37  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048bc39  7504                   -jne 0x48bc3f
    if (!cpu.flags.zf)
    {
        goto L_0x0048bc3f;
    }
L_0x0048bc3b:
    // 0048bc3b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048bc3d  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bc3e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048bc3f:
    // 0048bc3f  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 0048bc41  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 0048bc44  8a8090a84c00           -mov al, byte ptr [eax + 0x4ca890]
    cpu.al = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5023888) /* 0x4ca890 */);
    // 0048bc4a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048bc4c  74ed                   -je 0x48bc3b
    if (cpu.flags.zf)
    {
        goto L_0x0048bc3b;
    }
L_0x0048bc4e:
    // 0048bc4e  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx);
    // 0048bc50  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0048bc55  83f87c                 +cmp eax, 0x7c
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(124 /*0x7c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048bc58  7415                   -je 0x48bc6f
    if (cpu.flags.zf)
    {
        goto L_0x0048bc6f;
    }
    // 0048bc5a  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx);
    // 0048bc5c  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 0048bc5f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048bc61  7402                   -je 0x48bc65
    if (cpu.flags.zf)
    {
        goto L_0x0048bc65;
    }
    // 0048bc63  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
L_0x0048bc65:
    // 0048bc65  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048bc67  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048bc69  75e3                   -jne 0x48bc4e
    if (!cpu.flags.zf)
    {
        goto L_0x0048bc4e;
    }
    // 0048bc6b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048bc6d  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bc6e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048bc6f:
    // 0048bc6f  8d4208                 -lea eax, [edx + 8]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0048bc72  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bc73  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48bc74(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048bc74  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048bc75  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048bc77  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048bc79  7504                   -jne 0x48bc7f
    if (!cpu.flags.zf)
    {
        goto L_0x0048bc7f;
    }
L_0x0048bc7b:
    // 0048bc7b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048bc7d  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bc7e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048bc7f:
    // 0048bc7f  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 0048bc81  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 0048bc84  8a8090a84c00           -mov al, byte ptr [eax + 0x4ca890]
    cpu.al = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5023888) /* 0x4ca890 */);
    // 0048bc8a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048bc8c  74ed                   -je 0x48bc7b
    if (cpu.flags.zf)
    {
        goto L_0x0048bc7b;
    }
L_0x0048bc8e:
    // 0048bc8e  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx);
    // 0048bc90  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0048bc95  83f86f                 +cmp eax, 0x6f
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(111 /*0x6f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048bc98  7415                   -je 0x48bcaf
    if (cpu.flags.zf)
    {
        goto L_0x0048bcaf;
    }
    // 0048bc9a  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx);
    // 0048bc9c  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 0048bc9f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048bca1  7402                   -je 0x48bca5
    if (cpu.flags.zf)
    {
        goto L_0x0048bca5;
    }
    // 0048bca3  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
L_0x0048bca5:
    // 0048bca5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048bca7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048bca9  75e3                   -jne 0x48bc8e
    if (!cpu.flags.zf)
    {
        goto L_0x0048bc8e;
    }
    // 0048bcab  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048bcad  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bcae  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048bcaf:
    // 0048bcaf  8d4208                 -lea eax, [edx + 8]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0048bcb2  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bcb3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_48bcc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048bcc0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048bcc1  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048bcc5  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048bcc9  8b15cc605200           -mov edx, dword ptr [0x5260cc]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5398732) /* 0x5260cc */);
    // 0048bccf  a1f0844c00             -mov eax, dword ptr [0x4c84f0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5014768) /* 0x4c84f0 */);
    // 0048bcd4  83c210                 -add edx, 0x10
    (cpu.edx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0048bcd7  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0048bcd9  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0048bcdd  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0048bcdf  e869310100             -call 0x49ee4d
    cpu.esp -= 4;
    sub_49ee4d(app, cpu);
    if (cpu.terminate) return;
    // 0048bce4  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bce5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48bce8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048bce8  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048bce9  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048bcea  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0048bcee  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0048bcf2  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048bcf6  8b15cc605200           -mov edx, dword ptr [0x5260cc]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5398732) /* 0x5260cc */);
    // 0048bcfc  a1f0844c00             -mov eax, dword ptr [0x4c84f0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5014768) /* 0x4c84f0 */);
    // 0048bd01  83c210                 -add edx, 0x10
    (cpu.edx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0048bd04  01db                   -add ebx, ebx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0048bd06  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0048bd08  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0048bd0a  e83e310100             -call 0x49ee4d
    cpu.esp -= 4;
    sub_49ee4d(app, cpu);
    if (cpu.terminate) return;
    // 0048bd0f  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bd10  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bd11  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
