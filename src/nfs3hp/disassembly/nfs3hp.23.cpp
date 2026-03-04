#include "nfs3hp.h"
#include <lib/thread.h>

namespace nfs3hp
{

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_49c1f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049c1f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049c1f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049c1f2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049c1f3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049c1f4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049c1f5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049c1f7  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0049c1f9  8b0de4e55500           -mov ecx, dword ptr [0x55e5e4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5629412) /* 0x55e5e4 */);
    // 0049c1ff  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0049c202  39ca                   +cmp edx, ecx
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
    // 0049c204  7d32                   -jge 0x49c238
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049c238;
    }
    // 0049c206  8b4802                 -mov ecx, dword ptr [eax + 2]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0049c209  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0049c20c  8b1de4e55500           -mov ebx, dword ptr [0x55e5e4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5629412) /* 0x55e5e4 */);
    // 0049c212  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049c214  39da                   +cmp edx, ebx
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
    // 0049c216  7e20                   -jle 0x49c238
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049c238;
    }
    // 0049c218  8b35e8e55500           -mov esi, dword ptr [0x55e5e8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5629416) /* 0x55e5e8 */);
    // 0049c21e  0fbf10                 -movsx edx, word ptr [eax]
    cpu.edx = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.eax)));
    // 0049c221  39f2                   +cmp edx, esi
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
    // 0049c223  7d13                   -jge 0x49c238
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049c238;
    }
    // 0049c225  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049c228  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0049c22b  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049c22d  39f0                   +cmp eax, esi
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
    // 0049c22f  7e07                   -jle 0x49c238
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049c238;
    }
    // 0049c231  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049c236  eb02                   -jmp 0x49c23a
    goto L_0x0049c23a;
L_0x0049c238:
    // 0049c238  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0049c23a:
    // 0049c23a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c23b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c23c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c23d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c23e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c23f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49c240(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049c240  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049c241  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049c242  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049c244  8b35e8e55500           -mov esi, dword ptr [0x55e5e8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5629416) /* 0x55e5e8 */);
    // 0049c24a  39f2                   +cmp edx, esi
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
    // 0049c24c  7d1e                   -jge 0x49c26c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049c26c;
    }
    // 0049c24e  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049c250  39f2                   +cmp edx, esi
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
    // 0049c252  7e18                   -jle 0x49c26c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049c26c;
    }
    // 0049c254  8b15e4e55500           -mov edx, dword ptr [0x55e5e4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5629412) /* 0x55e5e4 */);
    // 0049c25a  39d0                   +cmp eax, edx
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
    // 0049c25c  7d0e                   -jge 0x49c26c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049c26c;
    }
    // 0049c25e  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0049c260  39d0                   +cmp eax, edx
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
    // 0049c262  7e08                   -jle 0x49c26c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049c26c;
    }
    // 0049c264  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049c269  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c26a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c26b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049c26c:
    // 0049c26c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049c26e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c26f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c270  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_49c280(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049c280  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049c281  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049c282  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049c284  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049c286  891500e65500           -mov dword ptr [0x55e600], edx
    app->getMemory<x86::reg32>(x86::reg32(5629440) /* 0x55e600 */) = cpu.edx;
    // 0049c28c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c28d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c28e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_49c290(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049c290  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049c291  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049c293  c70500e6550001000000   -mov dword ptr [0x55e600], 1
    app->getMemory<x86::reg32>(x86::reg32(5629440) /* 0x55e600 */) = 1 /*0x1*/;
    // 0049c29d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c29e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_49c2a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049c2a0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049c2a1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049c2a2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049c2a3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049c2a5  8b15fce55500           -mov edx, dword ptr [0x55e5fc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5629436) /* 0x55e5fc */);
    // 0049c2ab  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049c2ad  740f                   -je 0x49c2be
    if (cpu.flags.zf)
    {
        goto L_0x0049c2be;
    }
    // 0049c2af  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049c2b1  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049c2b3  e8d8550400             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 0049c2b8  890dfce55500           -mov dword ptr [0x55e5fc], ecx
    app->getMemory<x86::reg32>(x86::reg32(5629436) /* 0x55e5fc */) = cpu.ecx;
L_0x0049c2be:
    // 0049c2be  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c2bf  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c2c0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c2c1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_49c2d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049c2d0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049c2d1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049c2d2  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049c2d4  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049c2d6  663d4f00               +cmp ax, 0x4f
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(79 /*0x4f*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0049c2da  7731                   -ja 0x49c30d
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0049c30d;
    }
    // 0049c2dc  6683fa18               +cmp dx, 0x18
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(24 /*0x18*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0049c2e0  772b                   -ja 0x49c30d
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0049c30d;
    }
    // 0049c2e2  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0049c2e8  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0049c2ef  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049c2f1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049c2f3  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0049c2f6  6689ca                 -mov dx, cx
    cpu.dx = cpu.cx;
    // 0049c2f9  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049c2fb  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049c2fd  8d9000000b00           -lea edx, [eax + 0xb0000]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(720896) /* 0xb0000 */);
    // 0049c303  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 0049c305  88d8                   -mov al, bl
    cpu.al = cpu.bl;
    // 0049c307  80c40f                 -add ah, 0xf
    (cpu.ah) += x86::reg8(x86::sreg8(15 /*0xf*/));
    // 0049c30a  668902                 -mov word ptr [edx], ax
    app->getMemory<x86::reg16>(cpu.edx) = cpu.ax;
L_0x0049c30d:
    // 0049c30d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c30e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c30f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49c310(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049c310  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049c311  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049c312  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049c313  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049c314  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049c315  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049c317  81ec04010000           -sub esp, 0x104
    (cpu.esp) -= x86::reg32(x86::sreg32(260 /*0x104*/));
    // 0049c31d  8d451c                 -lea eax, [ebp + 0x1c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 0049c320  8d5dfc                 -lea ebx, [ebp - 4]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0049c323  8b5518                 -mov edx, dword ptr [ebp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 0049c326  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0049c329  8d85fcfeffff           -lea eax, [ebp - 0x104]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-260) /* -0x104 */);
    // 0049c32f  8d8dfcfeffff           -lea ecx, [ebp - 0x104]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(-260) /* -0x104 */);
    // 0049c335  e83a330400             -call 0x4df674
    cpu.esp -= 4;
    sub_4df674(app, cpu);
    if (cpu.terminate) return;
L_0x0049c33a:
    // 0049c33a  8a21                   -mov ah, byte ptr [ecx]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx);
    // 0049c33c  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 0049c33e  7461                   -je 0x49c3a1
    if (cpu.flags.zf)
    {
        goto L_0x0049c3a1;
    }
    // 0049c340  833d04e655004f         +cmp dword ptr [0x55e604], 0x4f
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5629444) /* 0x55e604 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(79 /*0x4f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c347  7f05                   -jg 0x49c34e
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049c34e;
    }
    // 0049c349  80fc0a                 +cmp ah, 0xa
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(10 /*0xa*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049c34c  7515                   -jne 0x49c363
    if (!cpu.flags.zf)
    {
        goto L_0x0049c363;
    }
L_0x0049c34e:
    // 0049c34e  8b3508e65500           -mov esi, dword ptr [0x55e608]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5629448) /* 0x55e608 */);
    // 0049c354  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049c356  46                     -inc esi
    (cpu.esi)++;
    // 0049c357  891d04e65500           -mov dword ptr [0x55e604], ebx
    app->getMemory<x86::reg32>(x86::reg32(5629444) /* 0x55e604 */) = cpu.ebx;
    // 0049c35d  893508e65500           -mov dword ptr [0x55e608], esi
    app->getMemory<x86::reg32>(x86::reg32(5629448) /* 0x55e608 */) = cpu.esi;
L_0x0049c363:
    // 0049c363  833d08e6550018         +cmp dword ptr [0x55e608], 0x18
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5629448) /* 0x55e608 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c36a  7e07                   -jle 0x49c373
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049c373;
    }
    // 0049c36c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049c36e  a308e65500             -mov dword ptr [0x55e608], eax
    app->getMemory<x86::reg32>(x86::reg32(5629448) /* 0x55e608 */) = cpu.eax;
L_0x0049c373:
    // 0049c373  8a31                   -mov dh, byte ptr [ecx]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ecx);
    // 0049c375  80fe0a                 +cmp dh, 0xa
    {
        x86::reg8 tmp1 = cpu.dh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(10 /*0xa*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049c378  7424                   -je 0x49c39e
    if (cpu.flags.zf)
    {
        goto L_0x0049c39e;
    }
    // 0049c37a  84f6                   +test dh, dh
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & cpu.dh));
    // 0049c37c  7420                   -je 0x49c39e
    if (cpu.flags.zf)
    {
        goto L_0x0049c39e;
    }
    // 0049c37e  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049c380  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049c382  88f3                   -mov bl, dh
    cpu.bl = cpu.dh;
    // 0049c384  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0049c386  66a104e65500           -mov ax, word ptr [0x55e604]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5629444) /* 0x55e604 */);
    // 0049c38c  668b1508e65500         -mov dx, word ptr [0x55e608]
    cpu.dx = app->getMemory<x86::reg16>(x86::reg32(5629448) /* 0x55e608 */);
    // 0049c393  e838ffffff             -call 0x49c2d0
    cpu.esp -= 4;
    sub_49c2d0(app, cpu);
    if (cpu.terminate) return;
    // 0049c398  ff0504e65500           +inc dword ptr [0x55e604]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5629444) /* 0x55e604 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
L_0x0049c39e:
    // 0049c39e  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0049c39f  eb99                   -jmp 0x49c33a
    goto L_0x0049c33a;
L_0x0049c3a1:
    // 0049c3a1  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0049c3a3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c3a4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c3a5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c3a6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c3a7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c3a8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_49c3b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049c3b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049c3b1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049c3b2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049c3b3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049c3b5  bb00800000             -mov ebx, 0x8000
    cpu.ebx = 32768 /*0x8000*/;
    // 0049c3ba  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049c3bc  b800000b00             -mov eax, 0xb0000
    cpu.eax = 720896 /*0xb0000*/;
    // 0049c3c1  891504e65500           -mov dword ptr [0x55e604], edx
    app->getMemory<x86::reg32>(x86::reg32(5629444) /* 0x55e604 */) = cpu.edx;
    // 0049c3c7  891508e65500           -mov dword ptr [0x55e608], edx
    app->getMemory<x86::reg32>(x86::reg32(5629448) /* 0x55e608 */) = cpu.edx;
    // 0049c3cd  e86e420400             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 0049c3d2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c3d3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c3d4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c3d5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
/* data blob: 0000803f0000000000000000000000000000803f0000000000000000000000000000803f8d80000000008d9200000000 */
void Application::sub_49c410(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049c410  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049c411  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049c413  e808fb0100             -call 0x4bbf20
    cpu.esp -= 4;
    sub_4bbf20(app, cpu);
    if (cpu.terminate) return;
    // 0049c418  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c419  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_49c420(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049c420  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049c421  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049c422  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049c423  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049c424  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049c425  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049c427  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049c42a  833d603a7a0000         +cmp dword ptr [0x7a3a60], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(8010336) /* 0x7a3a60 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c431  7511                   -jne 0x49c444
    if (!cpu.flags.zf)
    {
        goto L_0x0049c444;
    }
    // 0049c433  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049c436  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0049c439  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049c43a  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 0049c43c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049c43d  e8beaf0200             -call 0x4c7400
    cpu.esp -= 4;
    sub_4c7400(app, cpu);
    if (cpu.terminate) return;
    // 0049c442  eb0c                   -jmp 0x49c450
    goto L_0x0049c450;
L_0x0049c444:
    // 0049c444  8b7a04                 -mov edi, dword ptr [edx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049c447  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049c448  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 0049c44a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049c44b  e88085f9ff             -call 0x4349d0
    cpu.esp -= 4;
    sub_4349d0(app, cpu);
    if (cpu.terminate) return;
L_0x0049c450:
    // 0049c450  8d75f8                 -lea esi, [ebp - 8]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0049c453  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0049c455  e816fa0100             -call 0x4bbe70
    cpu.esp -= 4;
    sub_4bbe70(app, cpu);
    if (cpu.terminate) return;
    // 0049c45a  8d75f8                 -lea esi, [ebp - 8]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0049c45d  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049c45e  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049c45f  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0049c461  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c462  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c463  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c464  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c465  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c466  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_49c470(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049c470  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049c471  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049c472  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049c473  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049c475  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049c478  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0049c47a  8d75f8                 -lea esi, [ebp - 8]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0049c47d  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0049c47f  e83cfb0100             -call 0x4bbfc0
    cpu.esp -= 4;
    sub_4bbfc0(app, cpu);
    if (cpu.terminate) return;
    // 0049c484  8d75f8                 -lea esi, [ebp - 8]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0049c487  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049c488  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049c489  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049c48b  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0049c48d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c48e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c48f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c490  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_49c4a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049c4a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049c4a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049c4a2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049c4a3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049c4a4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049c4a5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049c4a7  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0049c4aa  8975f4                 -mov dword ptr [ebp - 0xc], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.esi;
    // 0049c4ad  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049c4af  8b1d083d7a00           -mov ebx, dword ptr [0x7a3d08]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(8011016) /* 0x7a3d08 */);
    // 0049c4b5  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 0049c4b8  8955f8                 -mov dword ptr [ebp - 8], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edx;
    // 0049c4bb  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049c4bd  7402                   -je 0x49c4c1
    if (cpu.flags.zf)
    {
        goto L_0x0049c4c1;
    }
    // 0049c4bf  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
L_0x0049c4c1:
    // 0049c4c1  8b1d0c3d7a00           -mov ebx, dword ptr [0x7a3d0c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(8011020) /* 0x7a3d0c */);
L_0x0049c4c7:
    // 0049c4c7  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049c4c9  0f847f000000           -je 0x49c54e
    if (cpu.flags.zf)
    {
        goto L_0x0049c54e;
    }
    // 0049c4cf  ba04010000             -mov edx, 0x104
    cpu.edx = 260 /*0x104*/;
    // 0049c4d4  8d45f0                 -lea eax, [ebp - 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0049c4d7  b921000000             -mov ecx, 0x21
    cpu.ecx = 33 /*0x21*/;
    // 0049c4dc  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0049c4de  e8fdf80100             -call 0x4bbde0
    cpu.esp -= 4;
    sub_4bbde0(app, cpu);
    if (cpu.terminate) return;
    // 0049c4e3  8b7df0                 -mov edi, dword ptr [ebp - 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0049c4e6  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049c4e8  837df800               +cmp dword ptr [ebp - 8], 0
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
    // 0049c4ec  740a                   -je 0x49c4f8
    if (cpu.flags.zf)
    {
        goto L_0x0049c4f8;
    }
    // 0049c4ee  8b75fc                 -mov esi, dword ptr [ebp - 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0049c4f1  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0049c4f4  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0049c4f6  eb06                   -jmp 0x49c4fe
    goto L_0x0049c4fe;
L_0x0049c4f8:
    // 0049c4f8  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0049c4fb  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
L_0x0049c4fe:
    // 0049c4fe  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0049c501  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0049c504  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0049c507  0584000000             +add eax, 0x84
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(132 /*0x84*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049c50c  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0049c50f  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0049c512  8d5020                 -lea edx, [eax + 0x20]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0049c515  89560c                 -mov dword ptr [esi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0049c518  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0049c51b  8d5040                 -lea edx, [eax + 0x40]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(64) /* 0x40 */);
    // 0049c51e  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 0049c523  895610                 -mov dword ptr [esi + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0049c526  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049c528  8b7308                 -mov esi, dword ptr [ebx + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0049c52b  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049c52d  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 0049c532  8b730c                 -mov esi, dword ptr [ebx + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 0049c535  8d7820                 -lea edi, [eax + 0x20]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0049c538  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049c53a  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 0049c53f  8b7310                 -mov esi, dword ptr [ebx + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 0049c542  8d7840                 -lea edi, [eax + 0x40]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(64) /* 0x40 */);
    // 0049c545  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049c547  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0049c549  e979ffffff             -jmp 0x49c4c7
    goto L_0x0049c4c7;
L_0x0049c54e:
    // 0049c54e  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0049c551  8b7df4                 -mov edi, dword ptr [ebp - 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0049c554  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
    // 0049c557  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0049c55a  8d75e8                 -lea esi, [ebp - 0x18]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 0049c55d  8945ec                 -mov dword ptr [ebp - 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
    // 0049c560  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049c561  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049c562  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0049c565  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0049c567  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c568  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c569  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c56a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c56b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c56c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49c570(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049c570  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049c571  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049c572  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049c573  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049c574  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049c576  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049c578  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0049c57a  ff1538f99e00           -call dword ptr [0x9ef938]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10418488) /* 0x9ef938 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049c580  ff1570f99e00           -call dword ptr [0x9ef970]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10418544) /* 0x9ef970 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049c586  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049c587  ff1534f99e00           -call dword ptr [0x9ef934]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10418484) /* 0x9ef934 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049c58d  688ce65500             -push 0x55e68c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5629580 /*0x55e68c*/;
    cpu.esp -= 4;
    // 0049c592  680ce65500             -push 0x55e60c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5629452 /*0x55e60c*/;
    cpu.esp -= 4;
    // 0049c597  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0049c599  ff1530f99e00           -call dword ptr [0x9ef930]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10418480) /* 0x9ef930 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049c59f  ff1550f99e00           -call dword ptr [0x9ef950]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10418512) /* 0x9ef950 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049c5a5  ff1540f99e00           -call dword ptr [0x9ef940]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10418496) /* 0x9ef940 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049c5ab  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049c5ad  ff1548f99e00           -call dword ptr [0x9ef948]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10418504) /* 0x9ef948 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049c5b3  e8683b0500             -call 0x4f0120
    cpu.esp -= 4;
    sub_4f0120(app, cpu);
    if (cpu.terminate) return;
    // 0049c5b8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c5b9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c5ba  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c5bb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c5bc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49c5c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049c5c0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049c5c1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049c5c2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049c5c3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049c5c5  ff1580f99e00           -call dword ptr [0x9ef980]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10418560) /* 0x9ef980 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049c5cb  8b4030                 -mov eax, dword ptr [eax + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */);
    // 0049c5ce  f6400c01               +test byte ptr [eax + 0xc], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(12) /* 0xc */) & 1 /*0x1*/));
    // 0049c5d2  751c                   -jne 0x49c5f0
    if (!cpu.flags.zf)
    {
        goto L_0x0049c5f0;
    }
    // 0049c5d4  f6401c01               +test byte ptr [eax + 0x1c], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(28) /* 0x1c */) & 1 /*0x1*/));
    // 0049c5d8  750d                   -jne 0x49c5e7
    if (!cpu.flags.zf)
    {
        goto L_0x0049c5e7;
    }
    // 0049c5da  68f0c55300             -push 0x53c5f0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5490160 /*0x53c5f0*/;
    cpu.esp -= 4;
    // 0049c5df  e82c4af6ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0049c5e4  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0049c5e7:
    // 0049c5e7  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 0049c5ec  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c5ed  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c5ee  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c5ef  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049c5f0:
    // 0049c5f0  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 0049c5f5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c5f6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c5f7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c5f8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_49c600(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049c600  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049c601  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049c602  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049c604  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049c606  e8b5ffffff             -call 0x49c5c0
    cpu.esp -= 4;
    sub_49c5c0(app, cpu);
    if (cpu.terminate) return;
    // 0049c60b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049c60d  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049c60f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049c610  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049c611  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049c612  ff1568f99e00           -call dword ptr [0x9ef968]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10418536) /* 0x9ef968 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049c618  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c619  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c61a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_49c620(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049c620  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049c621  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049c622  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049c623  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049c625  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049c628  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049c62a  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0049c62c  e88fffffff             -call 0x49c5c0
    cpu.esp -= 4;
    sub_49c5c0(app, cpu);
    if (cpu.terminate) return;
    // 0049c631  83f803                 +cmp eax, 3
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
    // 0049c634  750f                   -jne 0x49c645
    if (!cpu.flags.zf)
    {
        goto L_0x0049c645;
    }
    // 0049c636  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049c638  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049c639  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049c63a  ff1564f99e00           -call dword ptr [0x9ef964]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10418532) /* 0x9ef964 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049c640  e9a6000000             -jmp 0x49c6eb
    goto L_0x0049c6eb;
L_0x0049c645:
    // 0049c645  83f807                 +cmp eax, 7
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
    // 0049c648  0f8590000000           -jne 0x49c6de
    if (!cpu.flags.zf)
    {
        goto L_0x0049c6de;
    }
    // 0049c64e  0fafd9                 -imul ebx, ecx
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0049c651  b80cc65300             -mov eax, 0x53c60c
    cpu.eax = 5490188 /*0x53c60c*/;
    // 0049c656  895df4                 -mov dword ptr [ebp - 0xc], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ebx;
    // 0049c659  8d141b                 -lea edx, [ebx + ebx]
    cpu.edx = x86::reg32(cpu.ebx + cpu.ebx * 1);
    // 0049c65c  897dfc                 -mov dword ptr [ebp - 4], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edi;
    // 0049c65f  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 0049c664  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049c666  e8b54f0400             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 0049c66b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049c66d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x0049c66f:
    // 0049c66f  3b4df4                 +cmp ecx, dword ptr [ebp - 0xc]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c672  7d53                   -jge 0x49c6c7
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049c6c7;
    }
    // 0049c674  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0049c677  0fbf00                 -movsx eax, word ptr [eax]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.eax)));
    // 0049c67a  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049c67c  c1ff0f                 -sar edi, 0xf
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (15 /*0xf*/ % 32));
    // 0049c67f  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049c681  7507                   -jne 0x49c68a
    if (!cpu.flags.zf)
    {
        goto L_0x0049c68a;
    }
    // 0049c683  66c7020000             -mov word ptr [edx], 0
    app->getMemory<x86::reg16>(cpu.edx) = 0 /*0x0*/;
    // 0049c688  eb2e                   -jmp 0x49c6b8
    goto L_0x0049c6b8;
L_0x0049c68a:
    // 0049c68a  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049c68c  c1ff03                 -sar edi, 3
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (3 /*0x3*/ % 32));
    // 0049c68f  81e700ff0000           -and edi, 0xff00
    cpu.edi &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 0049c695  897df0                 -mov dword ptr [ebp - 0x10], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edi;
    // 0049c698  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049c69a  c1ff02                 -sar edi, 2
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (2 /*0x2*/ % 32));
    // 0049c69d  81e7f0f00000           -and edi, 0xf0f0
    cpu.edi &= x86::reg32(x86::sreg32(61680 /*0xf0f0*/));
    // 0049c6a3  897df8                 -mov dword ptr [ebp - 8], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edi;
    // 0049c6a6  8b7df0                 -mov edi, dword ptr [ebp - 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0049c6a9  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0049c6ab  0b7df8                 -or edi, dword ptr [ebp - 8]
    cpu.edi |= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 0049c6ae  250ff00000             -and eax, 0xf00f
    cpu.eax &= x86::reg32(x86::sreg32(61455 /*0xf00f*/));
    // 0049c6b3  09c7                   -or edi, eax
    cpu.edi |= x86::reg32(x86::sreg32(cpu.eax));
    // 0049c6b5  66893a                 -mov word ptr [edx], di
    app->getMemory<x86::reg16>(cpu.edx) = cpu.di;
L_0x0049c6b8:
    // 0049c6b8  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0049c6bb  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049c6be  83c002                 +add eax, 2
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049c6c1  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0049c6c2  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0049c6c5  eba8                   -jmp 0x49c66f
    goto L_0x0049c66f;
L_0x0049c6c7:
    // 0049c6c7  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049c6c9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049c6ca  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049c6cb  ff1564f99e00           -call dword ptr [0x9ef964]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10418532) /* 0x9ef964 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049c6d1  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049c6d3  e8b8510400             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 0049c6d8  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0049c6da  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c6db  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c6dc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c6dd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049c6de:
    // 0049c6de  6810c65300             -push 0x53c610
    app->getMemory<x86::reg32>(cpu.esp-4) = 5490192 /*0x53c610*/;
    cpu.esp -= 4;
    // 0049c6e3  e82849f6ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0049c6e8  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0049c6eb:
    // 0049c6eb  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0049c6ed  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c6ee  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c6ef  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c6f0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_49c700(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049c700  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049c701  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049c702  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049c703  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049c705  81ec54020000           -sub esp, 0x254
    (cpu.esp) -= x86::reg32(x86::sreg32(596 /*0x254*/));
    // 0049c70b  895df4                 -mov dword ptr [ebp - 0xc], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ebx;
    // 0049c70e  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0049c710  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049c711  8d5df8                 -lea ebx, [ebp - 8]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0049c714  682cc65300             -push 0x53c62c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5490220 /*0x53c62c*/;
    cpu.esp -= 4;
    // 0049c719  8d85acfdffff           -lea eax, [ebp - 0x254]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-596) /* -0x254 */);
    // 0049c71f  8955f0                 -mov dword ptr [ebp - 0x10], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edx;
    // 0049c722  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049c723  c70100000000           -mov dword ptr [ecx], 0
    app->getMemory<x86::reg32>(cpu.ecx) = 0 /*0x0*/;
    // 0049c729  8d55ec                 -lea edx, [ebp - 0x14]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0049c72c  e85f2f0400             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 0049c731  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0049c734  8d85acfdffff           -lea eax, [ebp - 0x254]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-596) /* -0x254 */);
    // 0049c73a  8d4dfc                 -lea ecx, [ebp - 4]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0049c73d  e8eef0f9ff             -call 0x43b830
    cpu.esp -= 4;
    sub_43b830(app, cpu);
    if (cpu.terminate) return;
    // 0049c742  ba34c65300             -mov edx, 0x53c634
    cpu.edx = 5490228 /*0x53c634*/;
    // 0049c747  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049c749  e882f2f9ff             -call 0x43b9d0
    cpu.esp -= 4;
    sub_43b9d0(app, cpu);
    if (cpu.terminate) return;
    // 0049c74e  837dfc00               +cmp dword ptr [ebp - 4], 0
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
    // 0049c752  752a                   -jne 0x49c77e
    if (!cpu.flags.zf)
    {
        goto L_0x0049c77e;
    }
    // 0049c754  8d55ec                 -lea edx, [ebp - 0x14]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0049c757  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049c759  e852f2f9ff             -call 0x43b9b0
    cpu.esp -= 4;
    sub_43b9b0(app, cpu);
    if (cpu.terminate) return;
    // 0049c75e  6804010000             -push 0x104
    app->getMemory<x86::reg32>(cpu.esp-4) = 260 /*0x104*/;
    cpu.esp -= 4;
    // 0049c763  683cc65300             -push 0x53c63c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5490236 /*0x53c63c*/;
    cpu.esp -= 4;
    // 0049c768  6858c65300             -push 0x53c658
    app->getMemory<x86::reg32>(cpu.esp-4) = 5490264 /*0x53c658*/;
    cpu.esp -= 4;
    // 0049c76d  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0049c76f  6a5a                   -push 0x5a
    app->getMemory<x86::reg32>(cpu.esp-4) = 90 /*0x5a*/;
    cpu.esp -= 4;
    // 0049c771  e89a0df9ff             -call 0x42d510
    cpu.esp -= 4;
    sub_42d510(app, cpu);
    if (cpu.terminate) return;
    // 0049c776  83c414                 +add esp, 0x14
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
    // 0049c779  e9f5000000             -jmp 0x49c873
    goto L_0x0049c873;
L_0x0049c77e:
    // 0049c77e  8b55f8                 -mov edx, dword ptr [ebp - 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0049c781  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0049c784  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049c786  e8fdc80400             -call 0x4e9088
    cpu.esp -= 4;
    sub_4e9088(app, cpu);
    if (cpu.terminate) return;
    // 0049c78b  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0049c790  bafc070000             -mov edx, 0x7fc
    cpu.edx = 2044 /*0x7fc*/;
    // 0049c795  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0049c798  e8ebc80400             -call 0x4e9088
    cpu.esp -= 4;
    sub_4e9088(app, cpu);
    if (cpu.terminate) return;
    // 0049c79d  8b4dec                 -mov ecx, dword ptr [ebp - 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0049c7a0  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0049c7a5  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 0049c7aa  8d45e8                 -lea eax, [ebp - 0x18]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 0049c7ad  e84eca0400             -call 0x4e9200
    cpu.esp -= 4;
    sub_4e9200(app, cpu);
    if (cpu.terminate) return;
    // 0049c7b2  8b55f8                 -mov edx, dword ptr [ebp - 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0049c7b5  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0049c7b8  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049c7ba  e8c9c80400             -call 0x4e9088
    cpu.esp -= 4;
    sub_4e9088(app, cpu);
    if (cpu.terminate) return;
    // 0049c7bf  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0049c7c4  ba00080000             -mov edx, 0x800
    cpu.edx = 2048 /*0x800*/;
    // 0049c7c9  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0049c7cc  e8b7c80400             -call 0x4e9088
    cpu.esp -= 4;
    sub_4e9088(app, cpu);
    if (cpu.terminate) return;
    // 0049c7d1  8b4dec                 -mov ecx, dword ptr [ebp - 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0049c7d4  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0049c7d9  ba00010000             -mov edx, 0x100
    cpu.edx = 256 /*0x100*/;
    // 0049c7de  8d85d8feffff           -lea eax, [ebp - 0x128]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-296) /* -0x128 */);
    // 0049c7e4  e817ca0400             -call 0x4e9200
    cpu.esp -= 4;
    sub_4e9200(app, cpu);
    if (cpu.terminate) return;
    // 0049c7e9  8b55f8                 -mov edx, dword ptr [ebp - 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0049c7ec  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0049c7ef  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049c7f1  e892c80400             -call 0x4e9088
    cpu.esp -= 4;
    sub_4e9088(app, cpu);
    if (cpu.terminate) return;
    // 0049c7f6  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0049c7fb  ba28000000             -mov edx, 0x28
    cpu.edx = 40 /*0x28*/;
    // 0049c800  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0049c803  e880c80400             -call 0x4e9088
    cpu.esp -= 4;
    sub_4e9088(app, cpu);
    if (cpu.terminate) return;
    // 0049c808  8b4dec                 -mov ecx, dword ptr [ebp - 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0049c80b  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0049c810  ba0c000000             -mov edx, 0xc
    cpu.edx = 12 /*0xc*/;
    // 0049c815  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0049c818  e8e3c90400             -call 0x4e9200
    cpu.esp -= 4;
    sub_4e9200(app, cpu);
    if (cpu.terminate) return;
    // 0049c81d  8d55ec                 -lea edx, [ebp - 0x14]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0049c820  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049c822  e889f1f9ff             -call 0x43b9b0
    cpu.esp -= 4;
    sub_43b9b0(app, cpu);
    if (cpu.terminate) return;
    // 0049c827  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0049c829:
    // 0049c829  3b4df4                 +cmp ecx, dword ptr [ebp - 0xc]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c82c  7d40                   -jge 0x49c86e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049c86e;
    }
    // 0049c82e  83f910                 +cmp ecx, 0x10
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
    // 0049c831  733b                   -jae 0x49c86e
    if (!cpu.flags.cf)
    {
        goto L_0x0049c86e;
    }
    // 0049c833  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0049c835  8d85d8feffff           -lea eax, [ebp - 0x128]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-296) /* -0x128 */);
    // 0049c83b  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 0049c83e  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049c840  8d55d8                 -lea edx, [ebp - 0x28]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 0049c843  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0049c846  e805020000             -call 0x49ca50
    cpu.esp -= 4;
    sub_49ca50(app, cpu);
    if (cpu.terminate) return;
    // 0049c84b  8d148d00000000         -lea edx, [ecx*4]
    cpu.edx = x86::reg32(cpu.ecx * 4);
    // 0049c852  01f2                   +add edx, esi
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049c854  8a45d8                 -mov al, byte ptr [ebp - 0x28]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 0049c857  8802                   -mov byte ptr [edx], al
    app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
    // 0049c859  8a45dc                 -mov al, byte ptr [ebp - 0x24]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 0049c85c  884201                 -mov byte ptr [edx + 1], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0049c85f  8a45e0                 -mov al, byte ptr [ebp - 0x20]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 0049c862  884202                 -mov byte ptr [edx + 2], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 0049c865  8a45e4                 -mov al, byte ptr [ebp - 0x1c]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 0049c868  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0049c869  884203                 -mov byte ptr [edx + 3], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(3) /* 0x3 */) = cpu.al;
    // 0049c86c  ebbb                   -jmp 0x49c829
    goto L_0x0049c829;
L_0x0049c86e:
    // 0049c86e  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 0049c871  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
L_0x0049c873:
    // 0049c873  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0049c875  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c876  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c877  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049c878  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_49c880(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049c880  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049c881  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049c882  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049c883  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049c884  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049c885  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049c887  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049c889  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0049c88b  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0049c88e  3b5004                 +cmp edx, dword ptr [eax + 4]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c891  7d05                   -jge 0x49c898
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049c898;
    }
    // 0049c893  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0049c896  eb02                   -jmp 0x49c89a
    goto L_0x0049c89a;
L_0x0049c898:
    // 0049c898  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x0049c89a:
    // 0049c89a  8b0b                   -mov ecx, dword ptr [ebx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0049c89c  39c8                   +cmp eax, ecx
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
    // 0049c89e  7d04                   -jge 0x49c8a4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049c8a4;
    }
    // 0049c8a0  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0049c8a2  eb0c                   -jmp 0x49c8b0
    goto L_0x0049c8b0;
L_0x0049c8a4:
    // 0049c8a4  8b7b08                 -mov edi, dword ptr [ebx + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0049c8a7  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0049c8aa  39f8                   +cmp eax, edi
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
    // 0049c8ac  7e02                   -jle 0x49c8b0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049c8b0;
    }
    // 0049c8ae  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x0049c8b0:
    // 0049c8b0  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0049c8b3  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0049c8b6  39d0                   +cmp eax, edx
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
    // 0049c8b8  7c02                   -jl 0x49c8bc
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049c8bc;
    }
    // 0049c8ba  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x0049c8bc:
    // 0049c8bc  8b0b                   -mov ecx, dword ptr [ebx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0049c8be  39c8                   +cmp eax, ecx
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
    // 0049c8c0  7e04                   -jle 0x49c8c6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049c8c6;
    }
    // 0049c8c2  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0049c8c4  eb0c                   -jmp 0x49c8d2
    goto L_0x0049c8d2;
L_0x0049c8c6:
    // 0049c8c6  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0049c8c9  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0049c8cc  39d0                   +cmp eax, edx
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
    // 0049c8ce  7d02                   -jge 0x49c8d2
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049c8d2;
    }
    // 0049c8d0  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x0049c8d2:
    // 0049c8d2  8b430c                 -mov eax, dword ptr [ebx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 0049c8d5  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 0049c8db  c7460400000000         -mov dword ptr [esi + 4], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0049c8e2  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0049c8e4  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0049c8e7  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049c8e9  897e08                 -mov dword ptr [esi + 8], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 0049c8ec  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049c8ee  0f84a4000000           -je 0x49c998
    if (cpu.flags.zf)
    {
        goto L_0x0049c998;
    }
    // 0049c8f4  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049c8f6  0f849c000000           -je 0x49c998
    if (cpu.flags.zf)
    {
        goto L_0x0049c998;
    }
    // 0049c8fc  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0049c8fe  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 0049c901  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049c903  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0049c906  f7ff                   -idiv edi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.edi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0049c908  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0049c90b  3b3b                   +cmp edi, dword ptr [ebx]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c90d  7521                   -jne 0x49c930
    if (!cpu.flags.zf)
    {
        goto L_0x0049c930;
    }
    // 0049c90f  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0049c912  8b7b08                 -mov edi, dword ptr [ebx + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0049c915  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0049c917  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0049c919  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 0049c91a  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0049c91c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049c91e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049c920  0facd010               -shrd eax, edx, 0x10
    {
        x86::reg32& destination = cpu.eax;
        destination >>= (16 /*0x10*/ % 32);
        destination |= cpu.edx  << (32 - (16 /*0x10*/ % 32));
    }
    // 0049c924  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0049c927  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0049c929  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 0049c92c  01c8                   +add eax, ecx
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
    // 0049c92e  eb4e                   -jmp 0x49c97e
    goto L_0x0049c97e;
L_0x0049c930:
    // 0049c930  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0049c933  39c7                   +cmp edi, eax
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
    // 0049c935  7525                   -jne 0x49c95c
    if (!cpu.flags.zf)
    {
        goto L_0x0049c95c;
    }
    // 0049c937  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0049c93a  8b3b                   -mov edi, dword ptr [ebx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx);
    // 0049c93c  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0049c93e  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0049c940  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 0049c941  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0049c943  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049c945  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049c947  0facd010               -shrd eax, edx, 0x10
    {
        x86::reg32& destination = cpu.eax;
        destination >>= (16 /*0x10*/ % 32);
        destination |= cpu.edx  << (32 - (16 /*0x10*/ % 32));
    }
    // 0049c94b  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0049c94e  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0049c950  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 0049c953  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049c955  0500000200             +add eax, 0x20000
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(131072 /*0x20000*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049c95a  eb22                   -jmp 0x49c97e
    goto L_0x0049c97e;
L_0x0049c95c:
    // 0049c95c  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0049c95e  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049c960  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0049c962  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049c964  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 0049c965  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0049c967  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049c969  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049c96b  0facd010               -shrd eax, edx, 0x10
    {
        x86::reg32& destination = cpu.eax;
        destination >>= (16 /*0x10*/ % 32);
        destination |= cpu.edx  << (32 - (16 /*0x10*/ % 32));
    }
    // 0049c96f  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0049c972  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0049c974  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 0049c977  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049c979  0500000400             -add eax, 0x40000
    (cpu.eax) += x86::reg32(x86::sreg32(262144 /*0x40000*/));
L_0x0049c97e:
    // 0049c97e  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0049c980  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0049c982  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049c984  b906000000             -mov ecx, 6
    cpu.ecx = 6 /*0x6*/;
    // 0049c989  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0049c98c  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0049c98e  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0049c990  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049c992  7d04                   -jge 0x49c998
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049c998;
    }
    // 0049c994  66ff4602               -inc word ptr [esi + 2]
    (app->getMemory<x86::reg16>(cpu.esi + x86::reg32(2) /* 0x2 */))++;
L_0x0049c998:
    // 0049c998  b800010000             -mov eax, 0x100
    cpu.eax = 256 /*0x100*/;
    // 0049c99d  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 0049c99f  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0049c9a1  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0049c9a4  c1e810                 +shr eax, 0x10
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
    // 0049c9a7  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0049c9a9  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0049c9ab  3dff000000             +cmp eax, 0xff
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(255 /*0xff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c9b0  7f08                   -jg 0x49c9ba
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049c9ba;
    }
    // 0049c9b2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049c9b4  7d04                   -jge 0x49c9ba
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049c9ba;
    }
    // 0049c9b6  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0049c9b8  eb13                   -jmp 0x49c9cd
    goto L_0x0049c9cd;
L_0x0049c9ba:
    // 0049c9ba  8b1e                   -mov ebx, dword ptr [esi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi);
    // 0049c9bc  81fbff000000           +cmp ebx, 0xff
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(255 /*0xff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c9c2  7e07                   -jle 0x49c9cb
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049c9cb;
    }
    // 0049c9c4  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
    // 0049c9c9  eb02                   -jmp 0x49c9cd
    goto L_0x0049c9cd;
L_0x0049c9cb:
    // 0049c9cb  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x0049c9cd:
    // 0049c9cd  8b7e04                 -mov edi, dword ptr [esi + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0049c9d0  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0049c9d2  81ffff000000           +cmp edi, 0xff
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
    // 0049c9d8  7f0a                   -jg 0x49c9e4
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049c9e4;
    }
    // 0049c9da  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049c9dc  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049c9de  7d04                   -jge 0x49c9e4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049c9e4;
    }
    // 0049c9e0  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0049c9e2  eb13                   -jmp 0x49c9f7
    goto L_0x0049c9f7;
L_0x0049c9e4:
    // 0049c9e4  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0049c9e7  3dff000000             +cmp eax, 0xff
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(255 /*0xff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049c9ec  7e07                   -jle 0x49c9f5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049c9f5;
    }
    // 0049c9ee  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
    // 0049c9f3  eb02                   -jmp 0x49c9f7
    goto L_0x0049c9f7;
L_0x0049c9f5:
    // 0049c9f5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x0049c9f7:
    // 0049c9f7  895604                 -mov dword ptr [esi + 4], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0049c9fa  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0049c9fd  81faff000000           +cmp edx, 0xff
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(255 /*0xff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049ca03  7f0a                   -jg 0x49ca0f
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049ca0f;
    }
    // 0049ca05  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049ca07  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049ca09  7d04                   -jge 0x49ca0f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049ca0f;
    }
    // 0049ca0b  31d0                   +xor eax, edx
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0049ca0d  eb1b                   -jmp 0x49ca2a
    goto L_0x0049ca2a;
L_0x0049ca0f:
    // 0049ca0f  8b4e08                 -mov ecx, dword ptr [esi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0049ca12  81f9ff000000           +cmp ecx, 0xff
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
    // 0049ca18  7e0e                   -jle 0x49ca28
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049ca28;
    }
    // 0049ca1a  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
    // 0049ca1f  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0049ca22  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ca23  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ca24  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ca25  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ca26  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ca27  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049ca28:
    // 0049ca28  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x0049ca2a:
    // 0049ca2a  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0049ca2d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ca2e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ca2f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ca30  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ca31  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ca32  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_49ca50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 0049ca50  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049ca51  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049ca52  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049ca53  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049ca54  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049ca55  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049ca57  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0049ca5a  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049ca5c  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0049ca5e  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0049ca61  89420c                 -mov dword ptr [edx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0049ca64  8b5708                 -mov edx, dword ptr [edi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0049ca67  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049ca69  7f19                   -jg 0x49ca84
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049ca84;
    }
    // 0049ca6b  c7460400000000         -mov dword ptr [esi + 4], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0049ca72  c7460800000000         -mov dword ptr [esi + 8], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 0049ca79  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 0049ca7f  e934010000             -jmp 0x49cbb8
    goto L_0x0049cbb8;
L_0x0049ca84:
    // 0049ca84  837f0400               +cmp dword ptr [edi + 4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049ca88  7f1b                   -jg 0x49caa5
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049caa5;
    }
    // 0049ca8a  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 0049ca8c  895604                 -mov dword ptr [esi + 4], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0049ca8f  895608                 -mov dword ptr [esi + 8], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0049ca92  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0049ca94  81f9ff000000           +cmp ecx, 0xff
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
    // 0049ca9a  0f8e22010000           -jle 0x49cbc2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049cbc2;
    }
    // 0049caa0  e927010000             -jmp 0x49cbcc
    goto L_0x0049cbcc;
L_0x0049caa5:
    // 0049caa5  8b17                   -mov edx, dword ptr [edi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi);
    // 0049caa7  db07                   -fild dword ptr [edi]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi))));
    // 0049caa9  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0049cab0  dc0d60c65300           -fmul qword ptr [0x53c660]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5490272) /* 0x53c660 */));
    // 0049cab6  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049cab8  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049caba  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 0049cabd  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 0049cac0  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0049cac3  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0049cac6  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 0049cac9  dee9                   -fsubp st(1)
    cpu.fpu.st(1) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0049cacb  bb00010000             -mov ebx, 0x100
    cpu.ebx = 256 /*0x100*/;
    // 0049cad0  e881320400             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 0049cad5  db5dfc                 -fistp dword ptr [ebp - 4]
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 0049cad8  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0049cadb  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 0049cadc  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0049cade  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049cae0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049cae2  0facd010               -shrd eax, edx, 0x10
    {
        x86::reg32& destination = cpu.eax;
        destination >>= (16 /*0x10*/ % 32);
        destination |= cpu.edx  << (32 - (16 /*0x10*/ % 32));
    }
    // 0049cae6  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0049cae9  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0049caeb  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 0049caee  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049caf0  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049caf2  8b5704                 -mov edx, dword ptr [edi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0049caf5  b800010000             -mov eax, 0x100
    cpu.eax = 256 /*0x100*/;
    // 0049cafa  8b4f08                 -mov ecx, dword ptr [edi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0049cafd  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049caff  0fafc8                 -imul ecx, eax
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0049cb02  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049cb04  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0049cb06  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0049cb08  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0049cb0b  c1e810                 +shr eax, 0x10
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
    // 0049cb0e  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0049cb10  ba00010000             -mov edx, 0x100
    cpu.edx = 256 /*0x100*/;
    // 0049cb15  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049cb17  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049cb19  0faf4708               -imul eax, dword ptr [edi + 8]
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */))));
    // 0049cb1d  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 0049cb20  ba00000100             -mov edx, 0x10000
    cpu.edx = 65536 /*0x10000*/;
    // 0049cb25  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 0049cb28  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049cb2a  8b4704                 -mov eax, dword ptr [edi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0049cb2d  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0049cb2f  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0049cb32  c1e810                 +shr eax, 0x10
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
    // 0049cb35  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0049cb37  ba00010000             -mov edx, 0x100
    cpu.edx = 256 /*0x100*/;
    // 0049cb3c  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049cb3e  8b5f08                 -mov ebx, dword ptr [edi + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0049cb41  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049cb43  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0049cb46  c1f908                 -sar ecx, 8
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (8 /*0x8*/ % 32));
    // 0049cb49  8b55f8                 -mov edx, dword ptr [ebp - 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0049cb4c  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 0049cb4f  83fa05                 +cmp edx, 5
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
    // 0049cb52  7764                   -ja 0x49cbb8
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0049cbb8;
    }
    // 0049cb54  ff249534ca4900         -jmp dword ptr [edx*4 + 0x49ca34]
    cpu.ip = app->getMemory<x86::reg32>(4835892 + cpu.edx * 4); goto dynamic_jump;
  case 0x0049cb5b:
    // 0049cb5b  8b5708                 -mov edx, dword ptr [edi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0049cb5e  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 0049cb60  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0049cb63  894e08                 -mov dword ptr [esi + 8], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0049cb66  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0049cb68  81f9ff000000           +cmp ecx, 0xff
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
    // 0049cb6e  7e52                   -jle 0x49cbc2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049cbc2;
    }
    // 0049cb70  eb5a                   -jmp 0x49cbcc
    goto L_0x0049cbcc;
  case 0x0049cb72:
    // 0049cb72  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0049cb75  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0049cb77  8b4708                 -mov eax, dword ptr [edi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0049cb7a  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0049cb7d  894e08                 -mov dword ptr [esi + 8], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0049cb80  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0049cb82  81f9ff000000           +cmp ecx, 0xff
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
    // 0049cb88  7e38                   -jle 0x49cbc2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049cbc2;
    }
    // 0049cb8a  eb40                   -jmp 0x49cbcc
    goto L_0x0049cbcc;
  case 0x0049cb8c:
    // 0049cb8c  890e                   -mov dword ptr [esi], ecx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ecx;
    // 0049cb8e  8b5708                 -mov edx, dword ptr [edi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0049cb91  895604                 -mov dword ptr [esi + 4], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0049cb94  eb1f                   -jmp 0x49cbb5
    goto L_0x0049cbb5;
  case 0x0049cb96:
    // 0049cb96  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0049cb99  890e                   -mov dword ptr [esi], ecx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ecx;
    // 0049cb9b  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0049cb9e  8b4708                 -mov eax, dword ptr [edi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0049cba1  eb12                   -jmp 0x49cbb5
    goto L_0x0049cbb5;
  case 0x0049cba3:
    // 0049cba3  894e04                 -mov dword ptr [esi + 4], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0049cba6  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0049cba8  8b4708                 -mov eax, dword ptr [edi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0049cbab  eb08                   -jmp 0x49cbb5
    goto L_0x0049cbb5;
  case 0x0049cbad:
    // 0049cbad  891e                   -mov dword ptr [esi], ebx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ebx;
    // 0049cbaf  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0049cbb2  894e04                 -mov dword ptr [esi + 4], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.ecx;
L_0x0049cbb5:
    // 0049cbb5  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
L_0x0049cbb8:
    // 0049cbb8  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0049cbba  81f9ff000000           +cmp ecx, 0xff
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
    // 0049cbc0  7f0a                   -jg 0x49cbcc
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049cbcc;
    }
L_0x0049cbc2:
    // 0049cbc2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049cbc4  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049cbc6  7d04                   -jge 0x49cbcc
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049cbcc;
    }
    // 0049cbc8  31c8                   +xor eax, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0049cbca  eb13                   -jmp 0x49cbdf
    goto L_0x0049cbdf;
L_0x0049cbcc:
    // 0049cbcc  8b1e                   -mov ebx, dword ptr [esi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi);
    // 0049cbce  81fbff000000           +cmp ebx, 0xff
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(255 /*0xff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049cbd4  7e07                   -jle 0x49cbdd
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049cbdd;
    }
    // 0049cbd6  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
    // 0049cbdb  eb02                   -jmp 0x49cbdf
    goto L_0x0049cbdf;
L_0x0049cbdd:
    // 0049cbdd  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x0049cbdf:
    // 0049cbdf  8b7e04                 -mov edi, dword ptr [esi + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0049cbe2  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0049cbe4  81ffff000000           +cmp edi, 0xff
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
    // 0049cbea  7f0a                   -jg 0x49cbf6
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049cbf6;
    }
    // 0049cbec  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049cbee  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049cbf0  7d04                   -jge 0x49cbf6
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049cbf6;
    }
    // 0049cbf2  31f8                   +xor eax, edi
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 0049cbf4  eb0f                   -jmp 0x49cc05
    goto L_0x0049cc05;
L_0x0049cbf6:
    // 0049cbf6  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0049cbf9  3dff000000             +cmp eax, 0xff
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(255 /*0xff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049cbfe  7e05                   -jle 0x49cc05
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049cc05;
    }
    // 0049cc00  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
L_0x0049cc05:
    // 0049cc05  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0049cc08  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0049cc0b  81faff000000           +cmp edx, 0xff
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(255 /*0xff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049cc11  7f0a                   -jg 0x49cc1d
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049cc1d;
    }
    // 0049cc13  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049cc15  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049cc17  7d04                   -jge 0x49cc1d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049cc1d;
    }
    // 0049cc19  31d0                   +xor eax, edx
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0049cc1b  eb1d                   -jmp 0x49cc3a
    goto L_0x0049cc3a;
L_0x0049cc1d:
    // 0049cc1d  8b4e08                 -mov ecx, dword ptr [esi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0049cc20  81f9ff000000           +cmp ecx, 0xff
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
    // 0049cc26  7e10                   -jle 0x49cc38
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049cc38;
    }
    // 0049cc28  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
    // 0049cc2d  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0049cc30  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0049cc32  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cc33  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cc34  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cc35  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cc36  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cc37  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049cc38:
    // 0049cc38  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x0049cc3a:
    // 0049cc3a  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0049cc3d  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0049cc3f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cc40  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cc41  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cc42  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cc43  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cc44  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_49cc50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049cc50  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049cc51  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049cc52  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049cc54  83ec30                 -sub esp, 0x30
    (cpu.esp) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 0049cc57  f6c480                 +test ah, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 128 /*0x80*/));
    // 0049cc5a  7507                   -jne 0x49cc63
    if (!cpu.flags.zf)
    {
        goto L_0x0049cc63;
    }
    // 0049cc5c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049cc5e  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0049cc60  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cc61  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cc62  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049cc63:
    // 0049cc63  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0049cc68  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0049cc6b  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049cc70  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0049cc73  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0049cc76  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 0049cc79  d95df8                 -fstp dword ptr [ebp - 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049cc7c  81f9ff000000           +cmp ecx, 0xff
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
    // 0049cc82  740f                   -je 0x49cc93
    if (cpu.flags.zf)
    {
        goto L_0x0049cc93;
    }
    // 0049cc84  db420c                 -fild dword ptr [edx + 0xc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */))));
    // 0049cc87  dc2d68c65300           -fsubr qword ptr [0x53c668]
    cpu.fpu.st(0) = app->getMemory<double>(x86::reg32(5490280) /* 0x53c668 */) - cpu.fpu.st(0);
    // 0049cc8d  d87df8                 -fdivr dword ptr [ebp - 8]
    cpu.fpu.st(0) = x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */)) / cpu.fpu.st(0);
    // 0049cc90  d95df8                 -fstp dword ptr [ebp - 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x0049cc93:
    // 0049cc93  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0049cc95  8945e0                 -mov dword ptr [ebp - 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.eax;
    // 0049cc98  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049cc9b  8945e4                 -mov dword ptr [ebp - 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.eax;
    // 0049cc9e  db4208                 -fild dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */))));
    // 0049cca1  d84df8                 -fmul dword ptr [ebp - 8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */));
    // 0049cca4  e8ad300400             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 0049cca9  db5de8                 -fistp dword ptr [ebp - 0x18]
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 0049ccac  817de8ff000000         +cmp dword ptr [ebp - 0x18], 0xff
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(255 /*0xff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049ccb3  7e07                   -jle 0x49ccbc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049ccbc;
    }
    // 0049ccb5  c745e8ff000000         -mov dword ptr [ebp - 0x18], 0xff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = 255 /*0xff*/;
L_0x0049ccbc:
    // 0049ccbc  8b420c                 -mov eax, dword ptr [edx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0049ccbf  8d55d0                 -lea edx, [ebp - 0x30]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-48) /* -0x30 */);
    // 0049ccc2  8945ec                 -mov dword ptr [ebp - 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
    // 0049ccc5  8d45e0                 -lea eax, [ebp - 0x20]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 0049ccc8  e883fdffff             -call 0x49ca50
    cpu.esp -= 4;
    sub_49ca50(app, cpu);
    if (cpu.terminate) return;
    // 0049cccd  8b45d0                 -mov eax, dword ptr [ebp - 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */);
    // 0049ccd0  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 0049ccd3  c1e00a                 -shl eax, 0xa
    cpu.eax <<= 10 /*0xa*/ % 32;
    // 0049ccd6  80cc80                 -or ah, 0x80
    cpu.ah |= x86::reg8(x86::sreg8(128 /*0x80*/));
    // 0049ccd9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049ccdb  8b45d4                 -mov eax, dword ptr [ebp - 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 0049ccde  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 0049cce1  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 0049cce4  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0049cce6  8b45d8                 -mov eax, dword ptr [ebp - 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 0049cce9  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 0049ccec  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 0049ccee  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0049ccf0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ccf1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ccf2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_49cd00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049cd00  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049cd01  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049cd02  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049cd03  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049cd05  83ec30                 -sub esp, 0x30
    (cpu.esp) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 0049cd08  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049cd0a  8955e0                 -mov dword ptr [ebp - 0x20], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.edx;
    // 0049cd0d  895dec                 -mov dword ptr [ebp - 0x14], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ebx;
    // 0049cd10  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0049cd13  895dd8                 -mov dword ptr [ebp - 0x28], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = cpu.ebx;
    // 0049cd16  8945d4                 -mov dword ptr [ebp - 0x2c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */) = cpu.eax;
    // 0049cd19  db45d8                 -fild dword ptr [ebp - 0x28]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */))));
    // 0049cd1c  db45d4                 -fild dword ptr [ebp - 0x2c]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */))));
    // 0049cd1f  def9                   -fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0049cd21  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0049cd24  894dd4                 -mov dword ptr [ebp - 0x2c], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */) = cpu.ecx;
    // 0049cd27  8945d8                 -mov dword ptr [ebp - 0x28], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = cpu.eax;
    // 0049cd2a  db45d4                 -fild dword ptr [ebp - 0x2c]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */))));
    // 0049cd2d  db45d8                 -fild dword ptr [ebp - 0x28]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */))));
    // 0049cd30  def9                   -fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0049cd32  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049cd34  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0049cd36  d95de4                 -fstp dword ptr [ebp - 0x1c]
    app->getMemory<float>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049cd39  d95de8                 -fstp dword ptr [ebp - 0x18]
    app->getMemory<float>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x0049cd3c:
    // 0049cd3c  3b4d14                 +cmp ecx, dword ptr [ebp + 0x14]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049cd3f  0f8d52010000           -jge 0x49ce97
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049ce97;
    }
    // 0049cd45  894dd8                 -mov dword ptr [ebp - 0x28], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = cpu.ecx;
    // 0049cd48  db45d8                 -fild dword ptr [ebp - 0x28]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */))));
    // 0049cd4b  d84de8                 -fmul dword ptr [ebp - 0x18]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-24) /* -0x18 */));
    // 0049cd4e  8b7dec                 -mov edi, dword ptr [ebp - 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0049cd51  e800300400             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 0049cd56  db5dd4                 -fistp dword ptr [ebp - 0x2c]
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 0049cd59  8b45d4                 -mov eax, dword ptr [ebp - 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 0049cd5c  0fafc7                 -imul eax, edi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 0049cd5f  8b55e0                 -mov edx, dword ptr [ebp - 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 0049cd62  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049cd64  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049cd67  895df4                 -mov dword ptr [ebp - 0xc], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ebx;
    // 0049cd6a  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049cd6c  895ddc                 -mov dword ptr [ebp - 0x24], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.ebx;
    // 0049cd6f  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
L_0x0049cd72:
    // 0049cd72  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0049cd75  3b4510                 +cmp eax, dword ptr [ebp + 0x10]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049cd78  0f8d13010000           -jge 0x49ce91
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049ce91;
    }
    // 0049cd7e  d945dc                 -fld dword ptr [ebp - 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-36) /* -0x24 */)));
    // 0049cd81  e8d02f0400             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 0049cd86  db5dd4                 -fistp dword ptr [ebp - 0x2c]
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 0049cd89  8b45d4                 -mov eax, dword ptr [ebp - 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 0049cd8c  8b5dfc                 -mov ebx, dword ptr [ebp - 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0049cd8f  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049cd92  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0049cd94  80780300               +cmp byte ptr [eax + 3], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049cd98  7407                   -je 0x49cda1
    if (cpu.flags.zf)
    {
        goto L_0x0049cda1;
    }
    // 0049cd9a  ba00800000             -mov edx, 0x8000
    cpu.edx = 32768 /*0x8000*/;
    // 0049cd9f  eb02                   -jmp 0x49cda3
    goto L_0x0049cda3;
L_0x0049cda1:
    // 0049cda1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0049cda3:
    // 0049cda3  d945dc                 -fld dword ptr [ebp - 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-36) /* -0x24 */)));
    // 0049cda6  e8ab2f0400             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 0049cdab  db5dd0                 -fistp dword ptr [ebp - 0x30]
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 0049cdae  8b45d0                 -mov eax, dword ptr [ebp - 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */);
    // 0049cdb1  8b7dfc                 -mov edi, dword ptr [ebp - 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0049cdb4  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049cdb7  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 0049cdb9  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049cdbb  8a5802                 -mov bl, byte ptr [eax + 2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0049cdbe  0fb638                 -movzx edi, byte ptr [eax]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.eax));
    // 0049cdc1  c1fb03                 -sar ebx, 3
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (3 /*0x3*/ % 32));
    // 0049cdc4  895df0                 -mov dword ptr [ebp - 0x10], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.ebx;
    // 0049cdc7  c1ff03                 -sar edi, 3
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (3 /*0x3*/ % 32));
    // 0049cdca  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049cdcc  897df8                 -mov dword ptr [ebp - 8], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edi;
    // 0049cdcf  8a5801                 -mov bl, byte ptr [eax + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0049cdd2  8b7d18                 -mov edi, dword ptr [ebp + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 0049cdd5  c1fb03                 -sar ebx, 3
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (3 /*0x3*/ % 32));
    // 0049cdd8  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049cdda  7426                   -je 0x49ce02
    if (cpu.flags.zf)
    {
        goto L_0x0049ce02;
    }
    // 0049cddc  80780380               +cmp byte ptr [eax + 3], 0x80
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(128 /*0x80*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049cde0  7320                   -jae 0x49ce02
    if (!cpu.flags.cf)
    {
        goto L_0x0049ce02;
    }
    // 0049cde2  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0049cde5  c1e00a                 -shl eax, 0xa
    cpu.eax <<= 10 /*0xa*/ % 32;
    // 0049cde8  c1e305                 -shl ebx, 5
    cpu.ebx <<= 5 /*0x5*/ % 32;
    // 0049cdeb  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 0049cded  8b55f8                 -mov edx, dword ptr [ebp - 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0049cdf0  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049cdf2  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 0049cdf4  25ffff0000             +and eax, 0xffff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/))));
    // 0049cdf9  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0049cdfb  e850feffff             -call 0x49cc50
    cpu.esp -= 4;
    sub_49cc50(app, cpu);
    if (cpu.terminate) return;
    // 0049ce00  eb57                   -jmp 0x49ce59
    goto L_0x0049ce59;
L_0x0049ce02:
    // 0049ce02  837d1c00               +cmp dword ptr [ebp + 0x1c], 0
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
    // 0049ce06  743f                   -je 0x49ce47
    if (cpu.flags.zf)
    {
        goto L_0x0049ce47;
    }
    // 0049ce08  d945dc                 -fld dword ptr [ebp - 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-36) /* -0x24 */)));
    // 0049ce0b  e8462f0400             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 0049ce10  db5dd8                 -fistp dword ptr [ebp - 0x28]
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 0049ce13  8b45d8                 -mov eax, dword ptr [ebp - 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 0049ce16  8b7dfc                 -mov edi, dword ptr [ebp - 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0049ce19  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049ce1c  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 0049ce1e  807803ff               +cmp byte ptr [eax + 3], 0xff
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049ce22  7323                   -jae 0x49ce47
    if (!cpu.flags.cf)
    {
        goto L_0x0049ce47;
    }
    // 0049ce24  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0049ce27  c1e00a                 -shl eax, 0xa
    cpu.eax <<= 10 /*0xa*/ % 32;
    // 0049ce2a  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0049ce2c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049ce2e  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 0049ce31  8b5df8                 -mov ebx, dword ptr [ebp - 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0049ce34  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 0049ce36  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049ce38  8b551c                 -mov edx, dword ptr [ebp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 0049ce3b  25ffff0000             +and eax, 0xffff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/))));
    // 0049ce40  e80bfeffff             -call 0x49cc50
    cpu.esp -= 4;
    sub_49cc50(app, cpu);
    if (cpu.terminate) return;
    // 0049ce45  eb12                   -jmp 0x49ce59
    goto L_0x0049ce59;
L_0x0049ce47:
    // 0049ce47  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0049ce4a  c1e00a                 -shl eax, 0xa
    cpu.eax <<= 10 /*0xa*/ % 32;
    // 0049ce4d  c1e305                 -shl ebx, 5
    cpu.ebx <<= 5 /*0x5*/ % 32;
    // 0049ce50  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0049ce52  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0049ce55  09da                   -or edx, ebx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049ce57  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
L_0x0049ce59:
    // 0049ce59  668906                 -mov word ptr [esi], ax
    app->getMemory<x86::reg16>(cpu.esi) = cpu.ax;
    // 0049ce5c  66813e0080             +cmp word ptr [esi], 0x8000
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esi);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(32768 /*0x8000*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0049ce61  7507                   -jne 0x49ce6a
    if (!cpu.flags.zf)
    {
        goto L_0x0049ce6a;
    }
    // 0049ce63  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049ce68  eb02                   -jmp 0x49ce6c
    goto L_0x0049ce6c;
L_0x0049ce6a:
    // 0049ce6a  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
L_0x0049ce6c:
    // 0049ce6c  85056c3a7a00           -test dword ptr [0x7a3a6c], eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(app->getMemory<x86::reg32>(x86::reg32(8010348) /* 0x7a3a6c */) & cpu.eax));
    // 0049ce72  7405                   -je 0x49ce79
    if (cpu.flags.zf)
    {
        goto L_0x0049ce79;
    }
    // 0049ce74  66c7060180             -mov word ptr [esi], 0x8001
    app->getMemory<x86::reg16>(cpu.esi) = 32769 /*0x8001*/;
L_0x0049ce79:
    // 0049ce79  d945dc                 -fld dword ptr [ebp - 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-36) /* -0x24 */)));
    // 0049ce7c  8b5df4                 -mov ebx, dword ptr [ebp - 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0049ce7f  83c602                 +add esi, 2
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
    // 0049ce82  d845e4                 +fadd dword ptr [ebp - 0x1c]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-28) /* -0x1c */));
    // 0049ce85  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0049ce86  d95ddc                 +fstp dword ptr [ebp - 0x24]
    app->getMemory<float>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049ce89  895df4                 -mov dword ptr [ebp - 0xc], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ebx;
    // 0049ce8c  e9e1feffff             -jmp 0x49cd72
    goto L_0x0049cd72;
L_0x0049ce91:
    // 0049ce91  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0049ce92  e9a5feffff             -jmp 0x49cd3c
    goto L_0x0049cd3c;
L_0x0049ce97:
    // 0049ce97  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0049ce99  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ce9a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ce9b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ce9c  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x90 */
void Application::sub_49cea0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049cea0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049cea1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049cea2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049cea3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049cea5  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0049cea8  8d7008                 -lea esi, [eax + 8]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0049ceab  39fb                   +cmp ebx, edi
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
    // 0049cead  7e0a                   -jle 0x49ceb9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049ceb9;
    }
    // 0049ceaf  897804                 -mov dword ptr [eax + 4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 0049ceb2  8938                   -mov dword ptr [eax], edi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edi;
    // 0049ceb4  e9bc000000             -jmp 0x49cf75
    goto L_0x0049cf75;
L_0x0049ceb9:
    // 0049ceb9  81fb00010000           +cmp ebx, 0x100
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(256 /*0x100*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049cebf  7c12                   -jl 0x49ced3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049ced3;
    }
    // 0049cec1  c7400400010000         -mov dword ptr [eax + 4], 0x100
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 256 /*0x100*/;
    // 0049cec8  c70000010000           -mov dword ptr [eax], 0x100
    app->getMemory<x86::reg32>(cpu.eax) = 256 /*0x100*/;
    // 0049cece  e9a2000000             -jmp 0x49cf75
    goto L_0x0049cf75;
L_0x0049ced3:
    // 0049ced3  81fb80000000           +cmp ebx, 0x80
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(128 /*0x80*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049ced9  7c12                   -jl 0x49ceed
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049ceed;
    }
    // 0049cedb  c7400480000000         -mov dword ptr [eax + 4], 0x80
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 128 /*0x80*/;
    // 0049cee2  c70080000000           -mov dword ptr [eax], 0x80
    app->getMemory<x86::reg32>(cpu.eax) = 128 /*0x80*/;
    // 0049cee8  e988000000             -jmp 0x49cf75
    goto L_0x0049cf75;
L_0x0049ceed:
    // 0049ceed  83fb40                 +cmp ebx, 0x40
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(64 /*0x40*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049cef0  7c12                   -jl 0x49cf04
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049cf04;
    }
    // 0049cef2  c7400440000000         -mov dword ptr [eax + 4], 0x40
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 64 /*0x40*/;
    // 0049cef9  c70040000000           -mov dword ptr [eax], 0x40
    app->getMemory<x86::reg32>(cpu.eax) = 64 /*0x40*/;
    // 0049ceff  e971000000             -jmp 0x49cf75
    goto L_0x0049cf75;
L_0x0049cf04:
    // 0049cf04  83fb20                 +cmp ebx, 0x20
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
    // 0049cf07  7c0f                   -jl 0x49cf18
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049cf18;
    }
    // 0049cf09  c7400420000000         -mov dword ptr [eax + 4], 0x20
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 32 /*0x20*/;
    // 0049cf10  c70020000000           -mov dword ptr [eax], 0x20
    app->getMemory<x86::reg32>(cpu.eax) = 32 /*0x20*/;
    // 0049cf16  eb5d                   -jmp 0x49cf75
    goto L_0x0049cf75;
L_0x0049cf18:
    // 0049cf18  83fb10                 +cmp ebx, 0x10
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
    // 0049cf1b  7c0f                   -jl 0x49cf2c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049cf2c;
    }
    // 0049cf1d  c7400410000000         -mov dword ptr [eax + 4], 0x10
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 16 /*0x10*/;
    // 0049cf24  c70010000000           -mov dword ptr [eax], 0x10
    app->getMemory<x86::reg32>(cpu.eax) = 16 /*0x10*/;
    // 0049cf2a  eb49                   -jmp 0x49cf75
    goto L_0x0049cf75;
L_0x0049cf2c:
    // 0049cf2c  83fb08                 +cmp ebx, 8
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
    // 0049cf2f  7c0f                   -jl 0x49cf40
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049cf40;
    }
    // 0049cf31  c7400408000000         -mov dword ptr [eax + 4], 8
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 8 /*0x8*/;
    // 0049cf38  c70008000000           -mov dword ptr [eax], 8
    app->getMemory<x86::reg32>(cpu.eax) = 8 /*0x8*/;
    // 0049cf3e  eb35                   -jmp 0x49cf75
    goto L_0x0049cf75;
L_0x0049cf40:
    // 0049cf40  83fb04                 +cmp ebx, 4
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
    // 0049cf43  7c0f                   -jl 0x49cf54
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049cf54;
    }
    // 0049cf45  c7400404000000         -mov dword ptr [eax + 4], 4
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 4 /*0x4*/;
    // 0049cf4c  c70004000000           -mov dword ptr [eax], 4
    app->getMemory<x86::reg32>(cpu.eax) = 4 /*0x4*/;
    // 0049cf52  eb21                   -jmp 0x49cf75
    goto L_0x0049cf75;
L_0x0049cf54:
    // 0049cf54  83fb02                 +cmp ebx, 2
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
    // 0049cf57  7c0f                   -jl 0x49cf68
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049cf68;
    }
    // 0049cf59  c7400402000000         -mov dword ptr [eax + 4], 2
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 2 /*0x2*/;
    // 0049cf60  c70002000000           -mov dword ptr [eax], 2
    app->getMemory<x86::reg32>(cpu.eax) = 2 /*0x2*/;
    // 0049cf66  eb0d                   -jmp 0x49cf75
    goto L_0x0049cf75;
L_0x0049cf68:
    // 0049cf68  c7400401000000         -mov dword ptr [eax + 4], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 1 /*0x1*/;
    // 0049cf6f  c70001000000           -mov dword ptr [eax], 1
    app->getMemory<x86::reg32>(cpu.eax) = 1 /*0x1*/;
L_0x0049cf75:
    // 0049cf75  8b7d18                 -mov edi, dword ptr [ebp + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 0049cf78  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049cf79  8b7d14                 -mov edi, dword ptr [ebp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0049cf7c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049cf7d  8b7804                 -mov edi, dword ptr [eax + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049cf80  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049cf81  8b38                   -mov edi, dword ptr [eax]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax);
    // 0049cf83  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049cf84  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049cf86  e875fdffff             -call 0x49cd00
    cpu.esp -= 4;
    sub_49cd00(app, cpu);
    if (cpu.terminate) return;
    // 0049cf8b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cf8c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cf8d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049cf8e  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_49cfa0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049cfa0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049cfa1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049cfa2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049cfa3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049cfa4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049cfa5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049cfa6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049cfa8  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0049cfab  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049cfad  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049cfb0  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049cfb2  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049cfb4  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 0049cfb7  81c6041f0000           -add esi, 0x1f04
    (cpu.esi) += x86::reg32(x86::sreg32(7940 /*0x1f04*/));
    // 0049cfbd  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049cfbf  8b8604e1ffff           -mov eax, dword ptr [esi - 0x1efc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-7932) /* -0x1efc */);
    // 0049cfc5  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0049cfc8  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049cfcb  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049cfcd  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049cfcf  b80cc65300             -mov eax, 0x53c60c
    cpu.eax = 5490188 /*0x53c60c*/;
    // 0049cfd4  8975f0                 -mov dword ptr [ebp - 0x10], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.esi;
    // 0049cfd7  e844460400             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 0049cfdc  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049cfde  8986fce0ffff           -mov dword ptr [esi - 0x1f04], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-7940) /* -0x1f04 */) = cpu.eax;
L_0x0049cfe4:
    // 0049cfe4  3b99f8000000           +cmp ebx, dword ptr [ecx + 0xf8]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(248) /* 0xf8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049cfea  0f8d2f010000           -jge 0x49d11f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049d11f;
    }
    // 0049cff0  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0049cff3  8b711c                 -mov esi, dword ptr [ecx + 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 0049cff6  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0049cff8  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0049cffb  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 0049d002  8d3401                 -lea esi, [ecx + eax]
    cpu.esi = x86::reg32(cpu.ecx + cpu.eax * 1);
    // 0049d005  8b86fc030000           -mov eax, dword ptr [esi + 0x3fc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1020) /* 0x3fc */);
    // 0049d00b  8b7dfc                 -mov edi, dword ptr [ebp - 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0049d00e  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 0049d011  8b55f0                 -mov edx, dword ptr [ebp - 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0049d014  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049d016  035118                 -add edx, dword ptr [ecx + 0x18]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */)));
    // 0049d019  8b86fc050000           -mov eax, dword ptr [esi + 0x5fc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1532) /* 0x5fc */);
    // 0049d01f  8945ec                 -mov dword ptr [ebp - 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
    // 0049d022  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0049d025  8945ec                 -mov dword ptr [ebp - 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
    // 0049d028  897dfc                 -mov dword ptr [ebp - 4], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edi;
    // 0049d02b  8b7dec                 -mov edi, dword ptr [ebp - 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0049d02e  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0049d031  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0049d033  8bb6fc050000           -mov esi, dword ptr [esi + 0x5fc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1532) /* 0x5fc */);
    // 0049d039  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049d03b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049d03d  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 0049d040  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049d042  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 0049d045  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 0049d047  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0049d049  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0049d04b  8975f8                 -mov dword ptr [ebp - 8], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.esi;
L_0x0049d04e:
    // 0049d04e  8b7df8                 -mov edi, dword ptr [ebp - 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0049d051  3bbc99fc040000         +cmp edi, dword ptr [ecx + ebx*4 + 0x4fc]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1276) /* 0x4fc */ + cpu.ebx * 4)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049d058  7d16                   -jge 0x49d070
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049d070;
    }
    // 0049d05a  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 0049d05c  8b7dfc                 -mov edi, dword ptr [ebp - 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0049d05f  c1e605                 -shl esi, 5
    cpu.esi <<= 5 /*0x5*/ % 32;
    // 0049d062  01fe                   +add esi, edi
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049d064  c7461400000000         -mov dword ptr [esi + 0x14], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 0049d06b  ff45f8                 +inc dword ptr [ebp - 8]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0049d06e  ebde                   -jmp 0x49d04e
    goto L_0x0049d04e;
L_0x0049d070:
    // 0049d070  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x0049d072:
    // 0049d072  897df4                 -mov dword ptr [ebp - 0xc], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edi;
    // 0049d075  8b7df4                 -mov edi, dword ptr [ebp - 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0049d078  3bbc99fc060000         +cmp edi, dword ptr [ecx + ebx*4 + 0x6fc]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1788) /* 0x6fc */ + cpu.ebx * 4)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049d07f  0f8d94000000           -jge 0x49d119
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049d119;
    }
    // 0049d085  8b7204                 -mov esi, dword ptr [edx + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049d088  8b7dfc                 -mov edi, dword ptr [ebp - 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0049d08b  c1e605                 -shl esi, 5
    cpu.esi <<= 5 /*0x5*/ % 32;
    // 0049d08e  01f7                   -add edi, esi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.esi));
    // 0049d090  897808                 -mov dword ptr [eax + 8], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 0049d093  8b7208                 -mov esi, dword ptr [edx + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0049d096  8b7dfc                 -mov edi, dword ptr [ebp - 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0049d099  c1e605                 -shl esi, 5
    cpu.esi <<= 5 /*0x5*/ % 32;
    // 0049d09c  01f7                   -add edi, esi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.esi));
    // 0049d09e  89780c                 -mov dword ptr [eax + 0xc], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 0049d0a1  8b720c                 -mov esi, dword ptr [edx + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0049d0a4  8b7dfc                 -mov edi, dword ptr [ebp - 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0049d0a7  c1e605                 -shl esi, 5
    cpu.esi <<= 5 /*0x5*/ % 32;
    // 0049d0aa  66c740040300           -mov word ptr [eax + 4], 3
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(4) /* 0x4 */) = 3 /*0x3*/;
    // 0049d0b0  01f7                   -add edi, esi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.esi));
    // 0049d0b2  897810                 -mov dword ptr [eax + 0x10], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edi;
    // 0049d0b5  8b7220                 -mov esi, dword ptr [edx + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 0049d0b8  897020                 -mov dword ptr [eax + 0x20], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.esi;
    // 0049d0bb  8b722c                 -mov esi, dword ptr [edx + 0x2c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(44) /* 0x2c */);
    // 0049d0be  897024                 -mov dword ptr [eax + 0x24], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = cpu.esi;
    // 0049d0c1  8b7224                 -mov esi, dword ptr [edx + 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */);
    // 0049d0c4  897028                 -mov dword ptr [eax + 0x28], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */) = cpu.esi;
    // 0049d0c7  8b7230                 -mov esi, dword ptr [edx + 0x30]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(48) /* 0x30 */);
    // 0049d0ca  89702c                 -mov dword ptr [eax + 0x2c], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */) = cpu.esi;
    // 0049d0cd  8b7228                 -mov esi, dword ptr [edx + 0x28]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(40) /* 0x28 */);
    // 0049d0d0  897030                 -mov dword ptr [eax + 0x30], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */) = cpu.esi;
    // 0049d0d3  8b7234                 -mov esi, dword ptr [edx + 0x34]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(52) /* 0x34 */);
    // 0049d0d6  897034                 -mov dword ptr [eax + 0x34], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */) = cpu.esi;
    // 0049d0d9  668b32                 -mov si, word ptr [edx]
    cpu.si = app->getMemory<x86::reg16>(cpu.edx);
    // 0049d0dc  66897006               -mov word ptr [eax + 6], si
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(6) /* 0x6 */) = cpu.si;
    // 0049d0e0  f6421c04               +test byte ptr [edx + 0x1c], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(28) /* 0x1c */) & 4 /*0x4*/));
    // 0049d0e4  7404                   -je 0x49d0ea
    if (cpu.flags.zf)
    {
        goto L_0x0049d0ea;
    }
    // 0049d0e6  80480701               -or byte ptr [eax + 7], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(7) /* 0x7 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x0049d0ea:
    // 0049d0ea  f6421c08               +test byte ptr [edx + 0x1c], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(28) /* 0x1c */) & 8 /*0x8*/));
    // 0049d0ee  7404                   -je 0x49d0f4
    if (cpu.flags.zf)
    {
        goto L_0x0049d0f4;
    }
    // 0049d0f0  80480702               -or byte ptr [eax + 7], 2
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(7) /* 0x7 */) |= x86::reg8(x86::sreg8(2 /*0x2*/));
L_0x0049d0f4:
    // 0049d0f4  f6421c01               +test byte ptr [edx + 0x1c], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(28) /* 0x1c */) & 1 /*0x1*/));
    // 0049d0f8  7404                   -je 0x49d0fe
    if (cpu.flags.zf)
    {
        goto L_0x0049d0fe;
    }
    // 0049d0fa  80480704               -or byte ptr [eax + 7], 4
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(7) /* 0x7 */) |= x86::reg8(x86::sreg8(4 /*0x4*/));
L_0x0049d0fe:
    // 0049d0fe  f6421c02               +test byte ptr [edx + 0x1c], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(28) /* 0x1c */) & 2 /*0x2*/));
    // 0049d102  7404                   -je 0x49d108
    if (cpu.flags.zf)
    {
        goto L_0x0049d108;
    }
    // 0049d104  80480708               -or byte ptr [eax + 7], 8
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(7) /* 0x7 */) |= x86::reg8(x86::sreg8(8 /*0x8*/));
L_0x0049d108:
    // 0049d108  8b7df4                 -mov edi, dword ptr [ebp - 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0049d10b  83c238                 -add edx, 0x38
    (cpu.edx) += x86::reg32(x86::sreg32(56 /*0x38*/));
    // 0049d10e  47                     -inc edi
    (cpu.edi)++;
    // 0049d10f  0584000000             +add eax, 0x84
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(132 /*0x84*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049d114  e959ffffff             -jmp 0x49d072
    goto L_0x0049d072;
L_0x0049d119:
    // 0049d119  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0049d11a  e9c5feffff             -jmp 0x49cfe4
    goto L_0x0049cfe4;
L_0x0049d11f:
    // 0049d11f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049d121  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0049d123  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d124  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d125  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d126  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d127  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d128  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d129  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_49d130(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049d130  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049d131  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049d132  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049d133  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049d135  83ec1c                 -sub esp, 0x1c
    (cpu.esp) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0049d138  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0049d13b  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0049d13d  895df4                 -mov dword ptr [ebp - 0xc], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ebx;
    // 0049d140  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0049d142  0fafd3                 -imul edx, ebx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0049d145  b80cc65300             -mov eax, 0x53c60c
    cpu.eax = 5490188 /*0x53c60c*/;
    // 0049d14a  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049d14c  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 0049d151  83c208                 -add edx, 8
    (cpu.edx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049d154  e8c7440400             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 0049d159  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049d15b  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0049d15e  8b9000090000           -mov edx, dword ptr [eax + 0x900]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(2304) /* 0x900 */);
    // 0049d164  894de8                 -mov dword ptr [ebp - 0x18], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.ecx;
    // 0049d167  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049d169  740a                   -je 0x49d175
    if (cpu.flags.zf)
    {
        goto L_0x0049d175;
    }
    // 0049d16b  0504090000             +add eax, 0x904
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2308 /*0x904*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049d170  8945ec                 -mov dword ptr [ebp - 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
    // 0049d173  eb03                   -jmp 0x49d178
    goto L_0x0049d178;
L_0x0049d175:
    // 0049d175  8955ec                 -mov dword ptr [ebp - 0x14], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.edx;
L_0x0049d178:
    // 0049d178  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0049d17b  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0049d17e  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 0049d181  83f801                 +cmp eax, 1
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
    // 0049d184  0f8ea4000000           -jle 0x49d22e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049d22e;
    }
    // 0049d18a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049d18c  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
L_0x0049d18f:
    // 0049d18f  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0049d192  3b45f0                 +cmp eax, dword ptr [ebp - 0x10]
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
    // 0049d195  0f8d88000000           -jge 0x49d223
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049d223;
    }
    // 0049d19b  8b0f                   -mov ecx, dword ptr [edi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi);
    // 0049d19d  897de4                 -mov dword ptr [ebp - 0x1c], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.edi;
    // 0049d1a0  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049d1a2  744b                   -je 0x49d1ef
    if (cpu.flags.zf)
    {
        goto L_0x0049d1ef;
    }
    // 0049d1a4  8b5f04                 -mov ebx, dword ptr [edi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0049d1a7  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049d1a9  7444                   -je 0x49d1ef
    if (cpu.flags.zf)
    {
        goto L_0x0049d1ef;
    }
    // 0049d1ab  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0049d1ae  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049d1af  8b55e8                 -mov edx, dword ptr [ebp - 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 0049d1b2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049d1b3  8b4df4                 -mov ecx, dword ptr [ebp - 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0049d1b6  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049d1b8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049d1b9  8d5708                 -lea edx, [edi + 8]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0049d1bc  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0049d1be  8b1f                   -mov ebx, dword ptr [edi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi);
    // 0049d1c0  e8dbfcffff             -call 0x49cea0
    cpu.esp -= 4;
    sub_49cea0(app, cpu);
    if (cpu.terminate) return;
    // 0049d1c5  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0049d1c8  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0049d1ca  e831f4ffff             -call 0x49c600
    cpu.esp -= 4;
    sub_49c600(app, cpu);
    if (cpu.terminate) return;
    // 0049d1cf  8b55f8                 -mov edx, dword ptr [ebp - 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0049d1d2  8b5dfc                 -mov ebx, dword ptr [ebp - 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0049d1d5  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0049d1d8  01da                   +add edx, ebx
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049d1da  8982041e0000           -mov dword ptr [edx + 0x1e04], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(7684) /* 0x1e04 */) = cpu.eax;
    // 0049d1e0  8d5608                 -lea edx, [esi + 8]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0049d1e3  8b4e04                 -mov ecx, dword ptr [esi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0049d1e6  8b1e                   -mov ebx, dword ptr [esi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi);
    // 0049d1e8  e833f4ffff             -call 0x49c620
    cpu.esp -= 4;
    sub_49c620(app, cpu);
    if (cpu.terminate) return;
    // 0049d1ed  eb15                   -jmp 0x49d204
    goto L_0x0049d204;
L_0x0049d1ef:
    // 0049d1ef  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0049d1f2  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0049d1f5  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049d1f8  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049d1fa  c780041e000000000000   -mov dword ptr [eax + 0x1e04], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(7684) /* 0x1e04 */) = 0 /*0x0*/;
L_0x0049d204:
    // 0049d204  8b4f04                 -mov ecx, dword ptr [edi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0049d207  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0049d209  0fafc1                 -imul eax, ecx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0049d20c  8b5df8                 -mov ebx, dword ptr [ebp - 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0049d20f  8b7de4                 -mov edi, dword ptr [ebp - 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 0049d212  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049d215  43                     -inc ebx
    (cpu.ebx)++;
    // 0049d216  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049d219  895df8                 -mov dword ptr [ebp - 8], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ebx;
    // 0049d21c  01c7                   +add edi, eax
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
    // 0049d21e  e96cffffff             -jmp 0x49d18f
    goto L_0x0049d18f;
L_0x0049d223:
    // 0049d223  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049d225  7407                   -je 0x49d22e
    if (cpu.flags.zf)
    {
        goto L_0x0049d22e;
    }
    // 0049d227  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049d229  e862460400             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
L_0x0049d22e:
    // 0049d22e  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0049d230  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d231  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d232  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d233  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_49d240(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049d240  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049d241  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049d242  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049d243  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049d244  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049d245  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049d247  83ec44                 -sub esp, 0x44
    (cpu.esp) -= x86::reg32(x86::sreg32(68 /*0x44*/));
    // 0049d24a  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049d24c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049d24e  c745f800007a44         -mov dword ptr [ebp - 8], 0x447a0000
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = 1148846080 /*0x447a0000*/;
    // 0049d255  8d55bc                 -lea edx, [ebp - 0x44]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-68) /* -0x44 */);
    // 0049d258  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049d25a  e8f1f7ffff             -call 0x49ca50
    cpu.esp -= 4;
    sub_49ca50(app, cpu);
    if (cpu.terminate) return;
    // 0049d25f  8b45bc                 -mov eax, dword ptr [ebp - 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-68) /* -0x44 */);
    // 0049d262  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0049d264  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0049d267  894df4                 -mov dword ptr [ebp - 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ecx;
    // 0049d26a  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 0049d26d  8b45c0                 -mov eax, dword ptr [ebp - 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-64) /* -0x40 */);
    // 0049d270  d95dd8                 -fstp dword ptr [ebp - 0x28]
    app->getMemory<float>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049d273  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0049d276  8b45c4                 -mov eax, dword ptr [ebp - 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-60) /* -0x3c */);
    // 0049d279  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 0049d27c  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0049d27f  d95ddc                 -fstp dword ptr [ebp - 0x24]
    app->getMemory<float>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049d282  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 0049d285  d95de0                 -fstp dword ptr [ebp - 0x20]
    app->getMemory<float>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x0049d288:
    // 0049d288  3bb7fc070000           +cmp esi, dword ptr [edi + 0x7fc]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(2044) /* 0x7fc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049d28e  0f8d73000000           -jge 0x49d307
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049d307;
    }
    // 0049d294  3bb700090000           +cmp esi, dword ptr [edi + 0x900]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(2304) /* 0x900 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049d29a  7d6b                   -jge 0x49d307
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049d307;
    }
    // 0049d29c  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0049d29e  8d8700080000           -lea eax, [edi + 0x800]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(2048) /* 0x800 */);
    // 0049d2a4  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 0049d2a7  01d0                   +add eax, edx
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
    // 0049d2a9  8d55bc                 -lea edx, [ebp - 0x44]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-68) /* -0x44 */);
    // 0049d2ac  8d4dcc                 -lea ecx, [ebp - 0x34]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 0049d2af  e89cf7ffff             -call 0x49ca50
    cpu.esp -= 4;
    sub_49ca50(app, cpu);
    if (cpu.terminate) return;
    // 0049d2b4  8b45bc                 -mov eax, dword ptr [ebp - 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-68) /* -0x44 */);
    // 0049d2b7  8d5de4                 -lea ebx, [ebp - 0x1c]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 0049d2ba  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0049d2bd  8d55d8                 -lea edx, [ebp - 0x28]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 0049d2c0  db45fc                 +fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 0049d2c3  8b45c0                 -mov eax, dword ptr [ebp - 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-64) /* -0x40 */);
    // 0049d2c6  d95de4                 +fstp dword ptr [ebp - 0x1c]
    app->getMemory<float>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049d2c9  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0049d2cc  8b45c4                 -mov eax, dword ptr [ebp - 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-60) /* -0x3c */);
    // 0049d2cf  db45fc                 +fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 0049d2d2  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0049d2d5  d95de8                 +fstp dword ptr [ebp - 0x18]
    app->getMemory<float>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049d2d8  db45fc                 +fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 0049d2db  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049d2e0  d95dec                 +fstp dword ptr [ebp - 0x14]
    app->getMemory<float>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049d2e3  e8182d0400             -call 0x4e0000
    cpu.esp -= 4;
    sub_4e0000(app, cpu);
    if (cpu.terminate) return;
    // 0049d2e8  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 0049d2eb  e8b0330400             -call 0x4e06a0
    cpu.esp -= 4;
    sub_4e06a0(app, cpu);
    if (cpu.terminate) return;
    // 0049d2f0  d955f0                 +fst dword ptr [ebp - 0x10]
    app->getMemory<float>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = float(cpu.fpu.st(0));
    // 0049d2f3  d85df8                 +fcomp dword ptr [ebp - 8]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    cpu.fpu.pop();
    // 0049d2f6  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0049d2f8  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0049d2f9  7309                   -jae 0x49d304
    if (!cpu.flags.cf)
    {
        goto L_0x0049d304;
    }
    // 0049d2fb  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0049d2fe  8975f4                 -mov dword ptr [ebp - 0xc], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.esi;
    // 0049d301  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
L_0x0049d304:
    // 0049d304  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0049d305  eb81                   -jmp 0x49d288
    goto L_0x0049d288;
L_0x0049d307:
    // 0049d307  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0049d30a  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0049d30c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d30d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d30e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d30f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d310  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d311  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_49d320(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049d320  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049d321  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049d322  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049d323  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049d325  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0049d328  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049d32a  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 0049d32d  895df4                 -mov dword ptr [ebp - 0xc], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ebx;
    // 0049d330  894df8                 -mov dword ptr [ebp - 8], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ecx;
    // 0049d333  8b4d10                 -mov ecx, dword ptr [ebp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0049d336  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049d338  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0049d33b  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049d33d  8d5008                 -lea edx, [eax + 8]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0049d340  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 0049d345  b80cc65300             -mov eax, 0x53c60c
    cpu.eax = 5490188 /*0x53c60c*/;
    // 0049d34a  894de8                 -mov dword ptr [ebp - 0x18], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.ecx;
    // 0049d34d  e8ce420400             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 0049d352  8b9f00090000           -mov ebx, dword ptr [edi + 0x900]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(2304) /* 0x900 */);
    // 0049d358  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049d35a  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049d35c  7421                   -je 0x49d37f
    if (cpu.flags.zf)
    {
        goto L_0x0049d37f;
    }
    // 0049d35e  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049d360  740b                   -je 0x49d36d
    if (cpu.flags.zf)
    {
        goto L_0x0049d36d;
    }
    // 0049d362  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0049d364  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049d366  e8d5feffff             -call 0x49d240
    cpu.esp -= 4;
    sub_49d240(app, cpu);
    if (cpu.terminate) return;
    // 0049d36b  eb02                   -jmp 0x49d36f
    goto L_0x0049d36f;
L_0x0049d36d:
    // 0049d36d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0049d36f:
    // 0049d36f  8d9704090000           -lea edx, [edi + 0x904]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(2308) /* 0x904 */);
    // 0049d375  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0049d378  01c2                   +add edx, eax
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
    // 0049d37a  8955f0                 -mov dword ptr [ebp - 0x10], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edx;
    // 0049d37d  eb03                   -jmp 0x49d382
    goto L_0x0049d382;
L_0x0049d37f:
    // 0049d37f  895df0                 -mov dword ptr [ebp - 0x10], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.ebx;
L_0x0049d382:
    // 0049d382  8b470c                 -mov eax, dword ptr [edi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 0049d385  83f801                 +cmp eax, 1
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
    // 0049d388  0f8590000000           -jne 0x49d41e
    if (!cpu.flags.zf)
    {
        goto L_0x0049d41e;
    }
    // 0049d38e  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0049d391  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049d393  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0049d396  8a580d                 -mov bl, byte ptr [eax + 0xd]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */);
    // 0049d399  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049d39b  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 0049d39e  8a420c                 -mov al, byte ptr [edx + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0049d3a1  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049d3a3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049d3a5  8a420f                 -mov al, byte ptr [edx + 0xf]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(15) /* 0xf */);
    // 0049d3a8  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0049d3ab  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049d3ad  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049d3af  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 0049d3b2  8a410e                 -mov al, byte ptr [ecx + 0xe]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(14) /* 0xe */);
    // 0049d3b5  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049d3b7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049d3b9  8955ec                 -mov dword ptr [ebp - 0x14], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.edx;
    // 0049d3bc  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 0049d3be  8d5112                 -lea edx, [ecx + 0x12]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(18) /* 0x12 */);
    // 0049d3c1  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049d3c3  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049d3c5  744d                   -je 0x49d414
    if (cpu.flags.zf)
    {
        goto L_0x0049d414;
    }
    // 0049d3c7  837dec00               +cmp dword ptr [ebp - 0x14], 0
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
    // 0049d3cb  7447                   -je 0x49d414
    if (cpu.flags.zf)
    {
        goto L_0x0049d414;
    }
    // 0049d3cd  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0049d3d0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049d3d1  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 0049d3d4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049d3d5  8b4df4                 -mov ecx, dword ptr [ebp - 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0049d3d8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049d3d9  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049d3db  8b4dec                 -mov ecx, dword ptr [ebp - 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0049d3de  e8bdfaffff             -call 0x49cea0
    cpu.esp -= 4;
    sub_49cea0(app, cpu);
    if (cpu.terminate) return;
    // 0049d3e3  837df800               +cmp dword ptr [ebp - 8], 0
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
    // 0049d3e7  750d                   -jne 0x49d3f6
    if (!cpu.flags.zf)
    {
        goto L_0x0049d3f6;
    }
    // 0049d3e9  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0049d3ec  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0049d3ee  e80df2ffff             -call 0x49c600
    cpu.esp -= 4;
    sub_49c600(app, cpu);
    if (cpu.terminate) return;
    // 0049d3f3  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
L_0x0049d3f6:
    // 0049d3f6  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0049d3f9  8987041e0000           -mov dword ptr [edi + 0x1e04], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(7684) /* 0x1e04 */) = cpu.eax;
    // 0049d3ff  837d1400               +cmp dword ptr [ebp + 0x14], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049d403  7419                   -je 0x49d41e
    if (cpu.flags.zf)
    {
        goto L_0x0049d41e;
    }
    // 0049d405  8d5608                 -lea edx, [esi + 8]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0049d408  8b4e04                 -mov ecx, dword ptr [esi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0049d40b  8b1e                   -mov ebx, dword ptr [esi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi);
    // 0049d40d  e80ef2ffff             -call 0x49c620
    cpu.esp -= 4;
    sub_49c620(app, cpu);
    if (cpu.terminate) return;
    // 0049d412  eb0a                   -jmp 0x49d41e
    goto L_0x0049d41e;
L_0x0049d414:
    // 0049d414  c787041e000000000000   -mov dword ptr [edi + 0x1e04], 0
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(7684) /* 0x1e04 */) = 0 /*0x0*/;
L_0x0049d41e:
    // 0049d41e  837d1800               +cmp dword ptr [ebp + 0x18], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049d422  7415                   -je 0x49d439
    if (cpu.flags.zf)
    {
        goto L_0x0049d439;
    }
    // 0049d424  8b1e                   -mov ebx, dword ptr [esi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi);
    // 0049d426  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0049d429  01db                   -add ebx, ebx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0049d42b  0fafda                 -imul ebx, edx
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0049d42e  8d4608                 -lea eax, [esi + 8]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0049d431  8b5518                 -mov edx, dword ptr [ebp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 0049d434  e8b7d00400             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
L_0x0049d439:
    // 0049d439  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049d43b  7407                   -je 0x49d444
    if (cpu.flags.zf)
    {
        goto L_0x0049d444;
    }
    // 0049d43d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049d43f  e84c440400             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
L_0x0049d444:
    // 0049d444  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0049d446  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d447  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d448  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d449  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_49d450(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049d450  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049d451  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049d452  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049d453  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049d454  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049d456  81ecd8000000           -sub esp, 0xd8
    (cpu.esp) -= x86::reg32(x86::sreg32(216 /*0xd8*/));
    // 0049d45c  81ed82000000           -sub ebp, 0x82
    (cpu.ebp) -= x86::reg32(x86::sreg32(130 /*0x82*/));
    // 0049d462  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049d464  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0049d466  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049d467  6870c65300             -push 0x53c670
    app->getMemory<x86::reg32>(cpu.esp-4) = 5490288 /*0x53c670*/;
    cpu.esp -= 4;
    // 0049d46c  8d45aa                 -lea eax, [ebp - 0x56]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-86) /* -0x56 */);
    // 0049d46f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049d470  e81b220400             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 0049d475  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0049d478  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049d47a  8d45aa                 -lea eax, [ebp - 0x56]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-86) /* -0x56 */);
    // 0049d47d  e83e3a0400             -call 0x4e0ec0
    cpu.esp -= 4;
    sub_4e0ec0(app, cpu);
    if (cpu.terminate) return;
    // 0049d482  e819fbffff             -call 0x49cfa0
    cpu.esp -= 4;
    sub_49cfa0(app, cpu);
    if (cpu.terminate) return;
    // 0049d487  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049d488  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049d48a  6878c65300             -push 0x53c678
    app->getMemory<x86::reg32>(cpu.esp-4) = 5490296 /*0x53c678*/;
    cpu.esp -= 4;
    // 0049d48f  89457e                 -mov dword ptr [ebp + 0x7e], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */) = cpu.eax;
    // 0049d492  8d45aa                 -lea eax, [ebp - 0x56]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-86) /* -0x56 */);
    // 0049d495  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049d496  e8f5210400             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 0049d49b  8b560c                 -mov edx, dword ptr [esi + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0049d49e  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0049d4a1  83fa01                 +cmp edx, 1
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
    // 0049d4a4  0f8571000000           -jne 0x49d51b
    if (!cpu.flags.zf)
    {
        goto L_0x0049d51b;
    }
    // 0049d4aa  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049d4ac  e8af390400             -call 0x4e0e60
    cpu.esp -= 4;
    sub_4e0e60(app, cpu);
    if (cpu.terminate) return;
    // 0049d4b1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049d4b3  7466                   -je 0x49d51b
    if (cpu.flags.zf)
    {
        goto L_0x0049d51b;
    }
    // 0049d4b5  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 0049d4ba  8d45aa                 -lea eax, [ebp - 0x56]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-86) /* -0x56 */);
    // 0049d4bd  e8fe390400             -call 0x4e0ec0
    cpu.esp -= 4;
    sub_4e0ec0(app, cpu);
    if (cpu.terminate) return;
    // 0049d4c2  89457a                 -mov dword ptr [ebp + 0x7a], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(122) /* 0x7a */) = cpu.eax;
    // 0049d4c5  8b8efc070000           -mov ecx, dword ptr [esi + 0x7fc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(2044) /* 0x7fc */);
    // 0049d4cb  894576                 -mov dword ptr [ebp + 0x76], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(118) /* 0x76 */) = cpu.eax;
    // 0049d4ce  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049d4d0  7e22                   -jle 0x49d4f4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049d4f4;
    }
    // 0049d4d2  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0049d4d4  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049d4d6  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0049d4d9  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0049d4db  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049d4dd  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0049d4df  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 0049d4e2  8d8600080000           -lea eax, [esi + 0x800]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(2048) /* 0x800 */);
    // 0049d4e8  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0049d4ea  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049d4ec  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0049d4ee  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049d4ef  8b557a                 -mov edx, dword ptr [ebp + 0x7a]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(122) /* 0x7a */);
    // 0049d4f2  eb0c                   -jmp 0x49d500
    goto L_0x0049d500;
L_0x0049d4f4:
    // 0049d4f4  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049d4f6  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0049d4f8  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0049d4fa  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049d4fc  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049d4fe  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0049d500:
    // 0049d500  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049d502  e819feffff             -call 0x49d320
    cpu.esp -= 4;
    sub_49d320(app, cpu);
    if (cpu.terminate) return;
    // 0049d507  8b7576                 -mov esi, dword ptr [ebp + 0x76]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(118) /* 0x76 */);
    // 0049d50a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049d50c  0f8477000000           -je 0x49d589
    if (cpu.flags.zf)
    {
        goto L_0x0049d589;
    }
    // 0049d512  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049d514  e877430400             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 0049d519  eb6e                   -jmp 0x49d589
    goto L_0x0049d589;
L_0x0049d51b:
    // 0049d51b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049d51c  6884c65300             -push 0x53c684
    app->getMemory<x86::reg32>(cpu.esp-4) = 5490308 /*0x53c684*/;
    cpu.esp -= 4;
    // 0049d521  8d45aa                 -lea eax, [ebp - 0x56]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-86) /* -0x56 */);
    // 0049d524  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049d525  e866210400             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 0049d52a  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0049d52d  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 0049d532  8d45aa                 -lea eax, [ebp - 0x56]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-86) /* -0x56 */);
    // 0049d535  e886390400             -call 0x4e0ec0
    cpu.esp -= 4;
    sub_4e0ec0(app, cpu);
    if (cpu.terminate) return;
    // 0049d53a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049d53c  894572                 -mov dword ptr [ebp + 0x72], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(114) /* 0x72 */) = cpu.eax;
    // 0049d53f  8b457e                 -mov eax, dword ptr [ebp + 0x7e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 0049d542  83b8fc07000000         +cmp dword ptr [eax + 0x7fc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(2044) /* 0x7fc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049d549  7e25                   -jle 0x49d570
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049d570;
    }
    // 0049d54b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049d54d  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0049d54f  8b5d7e                 -mov ebx, dword ptr [ebp + 0x7e]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 0049d552  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0049d555  f7bbfc070000           -idiv dword ptr [ebx + 0x7fc]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(2044) /* 0x7fc */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0049d55b  c1e204                 +shl edx, 4
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
    // 0049d55e  8d8300080000           -lea eax, [ebx + 0x800]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(2048) /* 0x800 */);
    // 0049d564  8d0c10                 -lea ecx, [eax + edx]
    cpu.ecx = x86::reg32(cpu.eax + cpu.edx * 1);
    // 0049d567  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0049d569  8b457e                 -mov eax, dword ptr [ebp + 0x7e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 0049d56c  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0049d56e  eb06                   -jmp 0x49d576
    goto L_0x0049d576;
L_0x0049d570:
    // 0049d570  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0049d572  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0049d574  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0049d576:
    // 0049d576  e8b5fbffff             -call 0x49d130
    cpu.esp -= 4;
    sub_49d130(app, cpu);
    if (cpu.terminate) return;
    // 0049d57b  8b5d72                 -mov ebx, dword ptr [ebp + 0x72]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(114) /* 0x72 */);
    // 0049d57e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049d580  7407                   -je 0x49d589
    if (cpu.flags.zf)
    {
        goto L_0x0049d589;
    }
    // 0049d582  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049d584  e807430400             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
L_0x0049d589:
    // 0049d589  8b457e                 -mov eax, dword ptr [ebp + 0x7e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 0049d58c  8da582000000           -lea esp, [ebp + 0x82]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(130) /* 0x82 */);
    // 0049d592  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d593  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d594  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d595  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d596  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_49d5a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049d5a0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049d5a1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049d5a2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049d5a3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049d5a5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049d5a7  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0049d5a9  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049d5ab  7407                   -je 0x49d5b4
    if (cpu.flags.zf)
    {
        goto L_0x0049d5b4;
    }
    // 0049d5ad  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049d5af  e8dc420400             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
L_0x0049d5b4:
    // 0049d5b4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049d5b6  e8d5420400             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 0049d5bb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d5bc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d5bd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d5be  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_49d5c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049d5c0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049d5c1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049d5c2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049d5c3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049d5c5  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0049d5c8  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049d5ca  8955f0                 -mov dword ptr [ebp - 0x10], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edx;
    // 0049d5cd  895dec                 -mov dword ptr [ebp - 0x14], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ebx;
    // 0049d5d0  894df4                 -mov dword ptr [ebp - 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ecx;
    // 0049d5d3  ba00ff7f47             -mov edx, 0x477fff00
    cpu.edx = 1199570688 /*0x477fff00*/;
    // 0049d5d8  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0049d5da  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
L_0x0049d5dd:
    // 0049d5dd  3bb7f8000000           +cmp esi, dword ptr [edi + 0xf8]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(248) /* 0xf8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049d5e3  7d47                   -jge 0x49d62c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049d62c;
    }
    // 0049d5e5  8b5d14                 -mov ebx, dword ptr [ebp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0049d5e8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049d5e9  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0049d5ec  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049d5ed  8b55f4                 -mov edx, dword ptr [ebp - 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0049d5f0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049d5f1  8b4dec                 -mov ecx, dword ptr [ebp - 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0049d5f4  8b5df0                 -mov ebx, dword ptr [ebp - 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0049d5f7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049d5f8  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0049d5fa  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 0049d601  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049d602  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0049d604  8d8ffc000000           -lea ecx, [edi + 0xfc]
    cpu.ecx = x86::reg32(cpu.edi + x86::reg32(252) /* 0xfc */);
    // 0049d60a  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049d60d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049d60f  01c1                   +add ecx, eax
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
    // 0049d611  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049d613  e808080000             -call 0x49de20
    cpu.esp -= 4;
    sub_49de20(app, cpu);
    if (cpu.terminate) return;
    // 0049d618  d955f8                 +fst dword ptr [ebp - 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = float(cpu.fpu.st(0));
    // 0049d61b  d85dfc                 +fcomp dword ptr [ebp - 4]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
    cpu.fpu.pop();
    // 0049d61e  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0049d620  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0049d621  7306                   -jae 0x49d629
    if (!cpu.flags.cf)
    {
        goto L_0x0049d629;
    }
    // 0049d623  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0049d626  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
L_0x0049d629:
    // 0049d629  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0049d62a  ebb1                   -jmp 0x49d5dd
    goto L_0x0049d5dd;
L_0x0049d62c:
    // 0049d62c  d945fc                 -fld dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
    // 0049d62f  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0049d631  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d632  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d633  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d634  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_49d640(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049d640  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049d641  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049d642  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049d643  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049d644  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049d645  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049d646  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049d648  ba7f000000             -mov edx, 0x7f
    cpu.edx = 127 /*0x7f*/;
    // 0049d64d  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 0049d652  bb000000ff             -mov ebx, 0xff000000
    cpu.ebx = 4278190080 /*0xff000000*/;
    // 0049d657  bf0000803f             -mov edi, 0x3f800000
    cpu.edi = 1065353216 /*0x3f800000*/;
    // 0049d65c  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0049d65e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049d660  8915b0e65500           -mov dword ptr [0x55e6b0], edx
    app->getMemory<x86::reg32>(x86::reg32(5629616) /* 0x55e6b0 */) = cpu.edx;
    // 0049d666  8915b4e65500           -mov dword ptr [0x55e6b4], edx
    app->getMemory<x86::reg32>(x86::reg32(5629620) /* 0x55e6b4 */) = cpu.edx;
    // 0049d66c  8915ace65500           -mov dword ptr [0x55e6ac], edx
    app->getMemory<x86::reg32>(x86::reg32(5629612) /* 0x55e6ac */) = cpu.edx;
    // 0049d672  8935b8e65500           -mov dword ptr [0x55e6b8], esi
    app->getMemory<x86::reg32>(x86::reg32(5629624) /* 0x55e6b8 */) = cpu.esi;
    // 0049d678  8935bce65500           -mov dword ptr [0x55e6bc], esi
    app->getMemory<x86::reg32>(x86::reg32(5629628) /* 0x55e6bc */) = cpu.esi;
    // 0049d67e  8935c0e65500           -mov dword ptr [0x55e6c0], esi
    app->getMemory<x86::reg32>(x86::reg32(5629632) /* 0x55e6c0 */) = cpu.esi;
    // 0049d684  890de0e65500           -mov dword ptr [0x55e6e0], ecx
    app->getMemory<x86::reg32>(x86::reg32(5629664) /* 0x55e6e0 */) = cpu.ecx;
    // 0049d68a  891de4e65500           -mov dword ptr [0x55e6e4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5629668) /* 0x55e6e4 */) = cpu.ebx;
    // 0049d690  893dece65500           -mov dword ptr [0x55e6ec], edi
    app->getMemory<x86::reg32>(x86::reg32(5629676) /* 0x55e6ec */) = cpu.edi;
    // 0049d696  a3f0e65500             -mov dword ptr [0x55e6f0], eax
    app->getMemory<x86::reg32>(x86::reg32(5629680) /* 0x55e6f0 */) = cpu.eax;
    // 0049d69b  a3f4e65500             -mov dword ptr [0x55e6f4], eax
    app->getMemory<x86::reg32>(x86::reg32(5629684) /* 0x55e6f4 */) = cpu.eax;
    // 0049d6a0  a3f8e65500             -mov dword ptr [0x55e6f8], eax
    app->getMemory<x86::reg32>(x86::reg32(5629688) /* 0x55e6f8 */) = cpu.eax;
    // 0049d6a5  893dfce65500           -mov dword ptr [0x55e6fc], edi
    app->getMemory<x86::reg32>(x86::reg32(5629692) /* 0x55e6fc */) = cpu.edi;
    // 0049d6ab  a300e75500             -mov dword ptr [0x55e700], eax
    app->getMemory<x86::reg32>(x86::reg32(5629696) /* 0x55e700 */) = cpu.eax;
    // 0049d6b0  a304e75500             -mov dword ptr [0x55e704], eax
    app->getMemory<x86::reg32>(x86::reg32(5629700) /* 0x55e704 */) = cpu.eax;
    // 0049d6b5  a308e75500             -mov dword ptr [0x55e708], eax
    app->getMemory<x86::reg32>(x86::reg32(5629704) /* 0x55e708 */) = cpu.eax;
    // 0049d6ba  893d0ce75500           -mov dword ptr [0x55e70c], edi
    app->getMemory<x86::reg32>(x86::reg32(5629708) /* 0x55e70c */) = cpu.edi;
    // 0049d6c0  a39ce65500             -mov dword ptr [0x55e69c], eax
    app->getMemory<x86::reg32>(x86::reg32(5629596) /* 0x55e69c */) = cpu.eax;
    // 0049d6c5  a3a0e65500             -mov dword ptr [0x55e6a0], eax
    app->getMemory<x86::reg32>(x86::reg32(5629600) /* 0x55e6a0 */) = cpu.eax;
    // 0049d6ca  a3a8e65500             -mov dword ptr [0x55e6a8], eax
    app->getMemory<x86::reg32>(x86::reg32(5629608) /* 0x55e6a8 */) = cpu.eax;
    // 0049d6cf  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
    // 0049d6d4  beffffff7f             -mov esi, 0x7fffffff
    cpu.esi = 2147483647 /*0x7fffffff*/;
    // 0049d6d9  8915c4e65500           -mov dword ptr [0x55e6c4], edx
    app->getMemory<x86::reg32>(x86::reg32(5629636) /* 0x55e6c4 */) = cpu.edx;
    // 0049d6df  8915c8e65500           -mov dword ptr [0x55e6c8], edx
    app->getMemory<x86::reg32>(x86::reg32(5629640) /* 0x55e6c8 */) = cpu.edx;
    // 0049d6e5  8915cce65500           -mov dword ptr [0x55e6cc], edx
    app->getMemory<x86::reg32>(x86::reg32(5629644) /* 0x55e6cc */) = cpu.edx;
    // 0049d6eb  8915d0e65500           -mov dword ptr [0x55e6d0], edx
    app->getMemory<x86::reg32>(x86::reg32(5629648) /* 0x55e6d0 */) = cpu.edx;
    // 0049d6f1  8915d4e65500           -mov dword ptr [0x55e6d4], edx
    app->getMemory<x86::reg32>(x86::reg32(5629652) /* 0x55e6d4 */) = cpu.edx;
    // 0049d6f7  8915d8e65500           -mov dword ptr [0x55e6d8], edx
    app->getMemory<x86::reg32>(x86::reg32(5629656) /* 0x55e6d8 */) = cpu.edx;
    // 0049d6fd  8935e8e65500           -mov dword ptr [0x55e6e8], esi
    app->getMemory<x86::reg32>(x86::reg32(5629672) /* 0x55e6e8 */) = cpu.esi;
    // 0049d703  ba7f7f7f7f             -mov edx, 0x7f7f7f7f
    cpu.edx = 2139062143 /*0x7f7f7f7f*/;
    // 0049d708  be000080bf             -mov esi, 0xbf800000
    cpu.esi = 3212836864 /*0xbf800000*/;
    // 0049d70d  8915dce65500           -mov dword ptr [0x55e6dc], edx
    app->getMemory<x86::reg32>(x86::reg32(5629660) /* 0x55e6dc */) = cpu.edx;
    // 0049d713  8935a4e65500           -mov dword ptr [0x55e6a4], esi
    app->getMemory<x86::reg32>(x86::reg32(5629604) /* 0x55e6a4 */) = cpu.esi;
    // 0049d719  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d71a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d71b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d71c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d71d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d71e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d71f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49d720(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049d720  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049d721  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049d723  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049d728  c1e018                 -shl eax, 0x18
    cpu.eax <<= 24 /*0x18*/ % 32;
    // 0049d72b  a3e4e65500             -mov dword ptr [0x55e6e4], eax
    app->getMemory<x86::reg32>(x86::reg32(5629668) /* 0x55e6e4 */) = cpu.eax;
    // 0049d730  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049d732  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 0049d734  c1e018                 -shl eax, 0x18
    cpu.eax <<= 24 /*0x18*/ % 32;
    // 0049d737  0dffffff00             -or eax, 0xffffff
    cpu.eax |= x86::reg32(x86::sreg32(16777215 /*0xffffff*/));
    // 0049d73c  a3e8e65500             -mov dword ptr [0x55e6e8], eax
    app->getMemory<x86::reg32>(x86::reg32(5629672) /* 0x55e6e8 */) = cpu.eax;
    // 0049d741  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d742  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_49d750(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049d750  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049d751  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049d753  a39ce65500             -mov dword ptr [0x55e69c], eax
    app->getMemory<x86::reg32>(x86::reg32(5629596) /* 0x55e69c */) = cpu.eax;
    // 0049d758  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d759  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_49d760(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049d760  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049d761  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049d762  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049d763  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049d765  bfa0e65500             -mov edi, 0x55e6a0
    cpu.edi = 5629600 /*0x55e6a0*/;
    // 0049d76a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049d76c  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049d76d  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049d76e  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049d76f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d770  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d771  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d772  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_49d780(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049d780  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049d781  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049d782  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049d783  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049d785  83ec54                 -sub esp, 0x54
    (cpu.esp) -= x86::reg32(x86::sreg32(84 /*0x54*/));
    // 0049d788  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049d78a  ff7008                 -push dword ptr [eax + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0049d78d  ff30                   -push dword ptr [eax]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.eax);
    cpu.esp -= 4;
    // 0049d78f  e82cd20400             -call 0x4ea9c0
    cpu.esp -= 4;
    sub_4ea9c0(app, cpu);
    if (cpu.terminate) return;
    // 0049d794  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 0049d797  d8c8                   -fmul st(0)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(0));
    // 0049d799  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 0049d79b  d8c8                   -fmul st(0)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(0));
    // 0049d79d  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049d7a0  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0049d7a2  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0049d7a4  d8058cc65300           -fadd dword ptr [0x53c68c]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5490316) /* 0x53c68c */));
    // 0049d7aa  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0049d7ac  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049d7af  d95df4                 -fstp dword ptr [ebp - 0xc]
    app->getMemory<float>(cpu.ebp + x86::reg32(-12) /* -0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049d7b2  e869d10400             -call 0x4ea920
    cpu.esp -= 4;
    sub_4ea920(app, cpu);
    if (cpu.terminate) return;
    // 0049d7b7  ff7204                 -push dword ptr [edx + 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    // 0049d7ba  d95df8                 -fstp dword ptr [ebp - 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049d7bd  ff75f8                 -push dword ptr [ebp - 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    cpu.esp -= 4;
    // 0049d7c0  bbece65500             -mov ebx, 0x55e6ec
    cpu.ebx = 5629676 /*0x55e6ec*/;
    // 0049d7c5  e8f6d10400             -call 0x4ea9c0
    cpu.esp -= 4;
    sub_4ea9c0(app, cpu);
    if (cpu.terminate) return;
    // 0049d7ca  ff75f4                 -push dword ptr [ebp - 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    cpu.esp -= 4;
    // 0049d7cd  dc0590c65300           -fadd qword ptr [0x53c690]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(5490320) /* 0x53c690 */));
    // 0049d7d3  8d45d0                 -lea eax, [ebp - 0x30]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-48) /* -0x30 */);
    // 0049d7d6  d95dfc                 -fstp dword ptr [ebp - 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049d7d9  e802260400             -call 0x4dfde0
    cpu.esp -= 4;
    sub_4dfde0(app, cpu);
    if (cpu.terminate) return;
    // 0049d7de  ff75fc                 -push dword ptr [ebp - 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    cpu.esp -= 4;
    // 0049d7e1  8d45ac                 -lea eax, [ebp - 0x54]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-84) /* -0x54 */);
    // 0049d7e4  8d55ac                 -lea edx, [ebp - 0x54]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-84) /* -0x54 */);
    // 0049d7e7  e894250400             -call 0x4dfd80
    cpu.esp -= 4;
    sub_4dfd80(app, cpu);
    if (cpu.terminate) return;
    // 0049d7ec  8d45d0                 -lea eax, [ebp - 0x30]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-48) /* -0x30 */);
    // 0049d7ef  e88c2a0400             -call 0x4e0280
    cpu.esp -= 4;
    sub_4e0280(app, cpu);
    if (cpu.terminate) return;
    // 0049d7f4  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0049d7f6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d7f7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d7f8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d7f9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_49d800(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049d800  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049d801  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049d802  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049d803  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049d804  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049d805  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049d807  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049d80a  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049d80c  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0049d80e  f605583a7a0040         +test byte ptr [0x7a3a58], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(8010328) /* 0x7a3a58 */) & 64 /*0x40*/));
    // 0049d815  0f84bc000000           -je 0x49d8d7
    if (cpu.flags.zf)
    {
        goto L_0x0049d8d7;
    }
    // 0049d81b  d9e8                   +fld1 
    cpu.fpu.push(1.0);
    // 0049d81d  d90538bc6f00           +fld dword ptr [0x6fbc38]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(7322680) /* 0x6fbc38 */)));
    // 0049d823  dd5df8                 +fstp qword ptr [ebp - 8]
    app->getMemory<double>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049d826  dc5df8                 +fcomp qword ptr [ebp - 8]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    cpu.fpu.pop();
    // 0049d829  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0049d82b  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0049d82c  0f86a5000000           -jbe 0x49d8d7
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049d8d7;
    }
    // 0049d832  dd45f8                 -fld qword ptr [ebp - 8]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 0049d835  dc0d98c65300           -fmul qword ptr [0x53c698]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5490328) /* 0x53c698 */));
    // 0049d83b  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049d83e  db1c24                 -fistp dword ptr [esp]
    app->getMemory<x86::reg32>(cpu.esp) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 0049d841  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d842  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049d844  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049d846  81f900000100           +cmp ecx, 0x10000
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049d84c  7c05                   -jl 0x49d853
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049d853;
    }
    // 0049d84e  b9ffff0000             -mov ecx, 0xffff
    cpu.ecx = 65535 /*0xffff*/;
L_0x0049d853:
    // 0049d853  c1e908                 -shr ecx, 8
    cpu.ecx >>= 8 /*0x8*/ % 32;
    // 0049d856  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049d858  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049d85e  81e300ff00ff           -and ebx, 0xff00ff00
    cpu.ebx &= x86::reg32(x86::sreg32(4278255360 /*0xff00ff00*/));
    // 0049d864  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 0049d867  25ff00ff00             -and eax, 0xff00ff
    cpu.eax &= x86::reg32(x86::sreg32(16711935 /*0xff00ff*/));
    // 0049d86c  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 0049d86e  93                     -xchg ebx, eax
    {
        x86::reg32 tmp = cpu.ebx;
        cpu.ebx = cpu.eax;
        cpu.eax = tmp;
    }
    // 0049d86f  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 0049d871  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 0049d874  2500ff00ff             -and eax, 0xff00ff00
    cpu.eax &= x86::reg32(x86::sreg32(4278255360 /*0xff00ff00*/));
    // 0049d879  81e3ff00ff00           -and ebx, 0xff00ff
    cpu.ebx &= x86::reg32(x86::sreg32(16711935 /*0xff00ff*/));
    // 0049d87f  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049d881  d90538bc6f00           -fld dword ptr [0x6fbc38]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(7322680) /* 0x6fbc38 */)));
    // 0049d887  dc0d98c65300           -fmul qword ptr [0x53c698]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5490328) /* 0x53c698 */));
    // 0049d88d  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049d88f  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049d892  db1c24                 -fistp dword ptr [esp]
    app->getMemory<x86::reg32>(cpu.esp) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 0049d895  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d896  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049d898  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049d89a  81f900000100           +cmp ecx, 0x10000
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049d8a0  7c05                   -jl 0x49d8a7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049d8a7;
    }
    // 0049d8a2  b9ffff0000             -mov ecx, 0xffff
    cpu.ecx = 65535 /*0xffff*/;
L_0x0049d8a7:
    // 0049d8a7  c1e908                 -shr ecx, 8
    cpu.ecx >>= 8 /*0x8*/ % 32;
    // 0049d8aa  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049d8ac  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049d8b2  81e300ff00ff           -and ebx, 0xff00ff00
    cpu.ebx &= x86::reg32(x86::sreg32(4278255360 /*0xff00ff00*/));
    // 0049d8b8  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 0049d8bb  25ff00ff00             -and eax, 0xff00ff
    cpu.eax &= x86::reg32(x86::sreg32(16711935 /*0xff00ff*/));
    // 0049d8c0  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 0049d8c2  93                     -xchg ebx, eax
    {
        x86::reg32 tmp = cpu.ebx;
        cpu.ebx = cpu.eax;
        cpu.eax = tmp;
    }
    // 0049d8c3  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 0049d8c5  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 0049d8c8  2500ff00ff             -and eax, 0xff00ff00
    cpu.eax &= x86::reg32(x86::sreg32(4278255360 /*0xff00ff00*/));
    // 0049d8cd  81e3ff00ff00           -and ebx, 0xff00ff
    cpu.ebx &= x86::reg32(x86::sreg32(16711935 /*0xff00ff*/));
    // 0049d8d3  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049d8d5  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x0049d8d7:
    // 0049d8d7  8935e0e65500           -mov dword ptr [0x55e6e0], esi
    app->getMemory<x86::reg32>(x86::reg32(5629664) /* 0x55e6e0 */) = cpu.esi;
    // 0049d8dd  893ddce65500           -mov dword ptr [0x55e6dc], edi
    app->getMemory<x86::reg32>(x86::reg32(5629660) /* 0x55e6dc */) = cpu.edi;
    // 0049d8e3  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0049d8e5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d8e6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d8e7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d8e8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d8e9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d8ea  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_49d8f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049d8f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049d8f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049d8f2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049d8f3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049d8f4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049d8f5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049d8f6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049d8f8  b903000000             -mov ecx, 3
    cpu.ecx = 3 /*0x3*/;
    // 0049d8fd  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049d8ff  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049d901  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 0049d904  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049d906  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049d90c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049d90e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049d910  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 0049d912  c1fe08                 -sar esi, 8
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (8 /*0x8*/ % 32));
    // 0049d915  81e6ff000000           -and esi, 0xff
    cpu.esi &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049d91b  a3b8e65500             -mov dword ptr [0x55e6b8], eax
    app->getMemory<x86::reg32>(x86::reg32(5629624) /* 0x55e6b8 */) = cpu.eax;
    // 0049d920  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049d922  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049d924  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 0049d926  81e7ff000000           -and edi, 0xff
    cpu.edi &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049d92c  a3bce65500             -mov dword ptr [0x55e6bc], eax
    app->getMemory<x86::reg32>(x86::reg32(5629628) /* 0x55e6bc */) = cpu.eax;
    // 0049d931  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049d933  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 0049d935  a3c0e65500             -mov dword ptr [0x55e6c0], eax
    app->getMemory<x86::reg32>(x86::reg32(5629632) /* 0x55e6c0 */) = cpu.eax;
    // 0049d93a  8d041b                 -lea eax, [ebx + ebx]
    cpu.eax = x86::reg32(cpu.ebx + cpu.ebx * 1);
    // 0049d93d  3dff000000             +cmp eax, 0xff
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(255 /*0xff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049d942  7605                   -jbe 0x49d949
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049d949;
    }
    // 0049d944  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
L_0x0049d949:
    // 0049d949  a3c4e65500             -mov dword ptr [0x55e6c4], eax
    app->getMemory<x86::reg32>(x86::reg32(5629636) /* 0x55e6c4 */) = cpu.eax;
    // 0049d94e  8d0436                 -lea eax, [esi + esi]
    cpu.eax = x86::reg32(cpu.esi + cpu.esi * 1);
    // 0049d951  3dff000000             +cmp eax, 0xff
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(255 /*0xff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049d956  7605                   -jbe 0x49d95d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049d95d;
    }
    // 0049d958  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
L_0x0049d95d:
    // 0049d95d  a3c8e65500             -mov dword ptr [0x55e6c8], eax
    app->getMemory<x86::reg32>(x86::reg32(5629640) /* 0x55e6c8 */) = cpu.eax;
    // 0049d962  8d043f                 -lea eax, [edi + edi]
    cpu.eax = x86::reg32(cpu.edi + cpu.edi * 1);
    // 0049d965  3dff000000             +cmp eax, 0xff
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(255 /*0xff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049d96a  7605                   -jbe 0x49d971
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049d971;
    }
    // 0049d96c  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
L_0x0049d971:
    // 0049d971  8b15c4e65500           -mov edx, dword ptr [0x55e6c4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5629636) /* 0x55e6c4 */);
    // 0049d977  2b15b8e65500           -sub edx, dword ptr [0x55e6b8]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5629624) /* 0x55e6b8 */)));
    // 0049d97d  8b0dbce65500           -mov ecx, dword ptr [0x55e6bc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5629628) /* 0x55e6bc */);
    // 0049d983  8915d0e65500           -mov dword ptr [0x55e6d0], edx
    app->getMemory<x86::reg32>(x86::reg32(5629648) /* 0x55e6d0 */) = cpu.edx;
    // 0049d989  8b15c8e65500           -mov edx, dword ptr [0x55e6c8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5629640) /* 0x55e6c8 */);
    // 0049d98f  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049d991  8915d4e65500           -mov dword ptr [0x55e6d4], edx
    app->getMemory<x86::reg32>(x86::reg32(5629652) /* 0x55e6d4 */) = cpu.edx;
    // 0049d997  8b15c0e65500           -mov edx, dword ptr [0x55e6c0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5629632) /* 0x55e6c0 */);
    // 0049d99d  a3cce65500             -mov dword ptr [0x55e6cc], eax
    app->getMemory<x86::reg32>(x86::reg32(5629644) /* 0x55e6cc */) = cpu.eax;
    // 0049d9a2  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049d9a4  a3d8e65500             -mov dword ptr [0x55e6d8], eax
    app->getMemory<x86::reg32>(x86::reg32(5629656) /* 0x55e6d8 */) = cpu.eax;
    // 0049d9a9  893db4e65500           -mov dword ptr [0x55e6b4], edi
    app->getMemory<x86::reg32>(x86::reg32(5629620) /* 0x55e6b4 */) = cpu.edi;
    // 0049d9af  8935b0e65500           -mov dword ptr [0x55e6b0], esi
    app->getMemory<x86::reg32>(x86::reg32(5629616) /* 0x55e6b0 */) = cpu.esi;
    // 0049d9b5  891dace65500           -mov dword ptr [0x55e6ac], ebx
    app->getMemory<x86::reg32>(x86::reg32(5629612) /* 0x55e6ac */) = cpu.ebx;
    // 0049d9bb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d9bc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d9bd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d9be  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d9bf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d9c0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049d9c1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_49d9d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049d9d0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049d9d1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049d9d2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049d9d3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049d9d5  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049d9d8  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049d9da  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0049d9dc  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0049d9de  8b4d10                 -mov ecx, dword ptr [ebp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0049d9e1  b800ff7f47             -mov eax, 0x477fff00
    cpu.eax = 1199570688 /*0x477fff00*/;
    // 0049d9e6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049d9e7  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0049d9ea  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049d9ec  e8cf1a0200             -call 0x4bf4c0
    cpu.esp -= 4;
    sub_4bf4c0(app, cpu);
    if (cpu.terminate) return;
    // 0049d9f1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0049d9f3:
    // 0049d9f3  39f2                   +cmp edx, esi
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
    // 0049d9f5  7d21                   -jge 0x49da18
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049da18;
    }
    // 0049d9f7  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0049d9f9  c1e305                 -shl ebx, 5
    cpu.ebx <<= 5 /*0x5*/ % 32;
    // 0049d9fc  01fb                   +add ebx, edi
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049d9fe  8b4d14                 -mov ecx, dword ptr [ebp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0049da01  d94308                 +fld dword ptr [ebx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebx + x86::reg32(8) /* 0x8 */)));
    // 0049da04  894b10                 -mov dword ptr [ebx + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 0049da07  d85dfc                 +fcomp dword ptr [ebp - 4]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
    cpu.fpu.pop();
    // 0049da0a  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0049da0c  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0049da0d  7306                   -jae 0x49da15
    if (!cpu.flags.cf)
    {
        goto L_0x0049da15;
    }
    // 0049da0f  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0049da12  894dfc                 -mov dword ptr [ebp - 4], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
L_0x0049da15:
    // 0049da15  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0049da16  ebdb                   -jmp 0x49d9f3
    goto L_0x0049d9f3;
L_0x0049da18:
    // 0049da18  d945fc                 -fld dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
    // 0049da1b  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0049da1d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049da1e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049da1f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049da20  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_49da30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049da30  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049da31  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049da32  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049da33  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049da35  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0049da38  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0049da3a  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0049da3c  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0049da3e  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049da41  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 0049da43  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049da45  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 0049da48  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049da4a  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049da4d  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049da4f  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0049da51  895df8                 -mov dword ptr [ebp - 8], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ebx;
    // 0049da54  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049da56  8b5d14                 -mov ebx, dword ptr [ebp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0049da59  e852290400             -call 0x4e03b0
    cpu.esp -= 4;
    sub_4e03b0(app, cpu);
    if (cpu.terminate) return;
    // 0049da5e  8b4df8                 -mov ecx, dword ptr [ebp - 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0049da61  bba0e65500             -mov ebx, 0x55e6a0
    cpu.ebx = 5629600 /*0x55e6a0*/;
    // 0049da66  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0049da68  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049da6a  e8a1270400             -call 0x4e0210
    cpu.esp -= 4;
    sub_4e0210(app, cpu);
    if (cpu.terminate) return;
    // 0049da6f  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0049da72  8b55f8                 -mov edx, dword ptr [ebp - 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
L_0x0049da75:
    // 0049da75  4e                     -dec esi
    (cpu.esi)--;
    // 0049da76  83feff                 +cmp esi, -1
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
    // 0049da79  0f84df000000           -je 0x49db5e
    if (cpu.flags.zf)
    {
        goto L_0x0049db5e;
    }
    // 0049da7f  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 0049da81  d902                   +fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 0049da83  dd5dec                 +fstp qword ptr [ebp - 0x14]
    app->getMemory<double>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049da86  dc5dec                 +fcomp qword ptr [ebp - 0x14]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-20) /* -0x14 */)));
    cpu.fpu.pop();
    // 0049da89  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0049da8b  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0049da8c  0f839c000000           -jae 0x49db2e
    if (!cpu.flags.cf)
    {
        goto L_0x0049db2e;
    }
    // 0049da92  dd45ec                 -fld qword ptr [ebp - 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-20) /* -0x14 */)));
    // 0049da95  dc0da0c65300           -fmul qword ptr [0x53c6a0]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5490336) /* 0x53c6a0 */));
    // 0049da9b  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049da9e  db1c24                 -fistp dword ptr [esp]
    app->getMemory<x86::reg32>(cpu.esp) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 0049daa1  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049daa2  8b0dd0e65500           -mov ecx, dword ptr [0x55e6d0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5629648) /* 0x55e6d0 */);
    // 0049daa8  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049daaa  0fafc1                 -imul eax, ecx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0049daad  8b0db8e65500           -mov ecx, dword ptr [0x55e6b8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5629624) /* 0x55e6b8 */);
    // 0049dab3  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 0049dab6  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049dab8  a1c4e65500             -mov eax, dword ptr [0x55e6c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5629636) /* 0x55e6c4 */);
    // 0049dabd  39c1                   +cmp ecx, eax
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
    // 0049dabf  7602                   -jbe 0x49dac3
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049dac3;
    }
    // 0049dac1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x0049dac3:
    // 0049dac3  a1d4e65500             -mov eax, dword ptr [0x55e6d4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5629652) /* 0x55e6d4 */);
    // 0049dac8  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0049dacb  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 0049dace  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 0049dad1  a1bce65500             -mov eax, dword ptr [0x55e6bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5629628) /* 0x55e6bc */);
    // 0049dad6  0345f4                 -add eax, dword ptr [ebp - 0xc]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */)));
    // 0049dad9  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0049dadc  3b05c8e65500           +cmp eax, dword ptr [0x55e6c8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5629640) /* 0x55e6c8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049dae2  7608                   -jbe 0x49daec
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049daec;
    }
    // 0049dae4  a1c8e65500             -mov eax, dword ptr [0x55e6c8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5629640) /* 0x55e6c8 */);
    // 0049dae9  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
L_0x0049daec:
    // 0049daec  a1d8e65500             -mov eax, dword ptr [0x55e6d8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5629656) /* 0x55e6d8 */);
    // 0049daf1  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0049daf4  8b1dc0e65500           -mov ebx, dword ptr [0x55e6c0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5629632) /* 0x55e6c0 */);
    // 0049dafa  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 0049dafd  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0049daff  8b1dcce65500           -mov ebx, dword ptr [0x55e6cc]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5629644) /* 0x55e6cc */);
    // 0049db05  39d8                   +cmp eax, ebx
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
    // 0049db07  7602                   -jbe 0x49db0b
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049db0b;
    }
    // 0049db09  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x0049db0b:
    // 0049db0b  8b1de4e65500           -mov ebx, dword ptr [0x55e6e4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5629668) /* 0x55e6e4 */);
    // 0049db11  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 0049db14  09d9                   -or ecx, ebx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049db16  8b5dfc                 -mov ebx, dword ptr [ebp - 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0049db19  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 0049db1c  09d9                   -or ecx, ebx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049db1e  09c1                   -or ecx, eax
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0049db20  894f10                 -mov dword ptr [edi + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 0049db23  83c720                 -add edi, 0x20
    (cpu.edi) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0049db26  83c204                 +add edx, 4
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
    // 0049db29  e947ffffff             -jmp 0x49da75
    goto L_0x0049da75;
L_0x0049db2e:
    // 0049db2e  a1b8e65500             -mov eax, dword ptr [0x55e6b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5629624) /* 0x55e6b8 */);
    // 0049db33  8b0de4e65500           -mov ecx, dword ptr [0x55e6e4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5629668) /* 0x55e6e4 */);
    // 0049db39  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0049db3c  09c1                   -or ecx, eax
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0049db3e  a1bce65500             -mov eax, dword ptr [0x55e6bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5629628) /* 0x55e6bc */);
    // 0049db43  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0049db46  09c8                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049db48  8b0dc0e65500           -mov ecx, dword ptr [0x55e6c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5629632) /* 0x55e6c0 */);
    // 0049db4e  09c8                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049db50  894710                 -mov dword ptr [edi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0049db53  83c720                 -add edi, 0x20
    (cpu.edi) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0049db56  83c204                 +add edx, 4
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
    // 0049db59  e917ffffff             -jmp 0x49da75
    goto L_0x0049da75;
L_0x0049db5e:
    // 0049db5e  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0049db60  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049db61  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049db62  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049db63  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_49db70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049db70  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049db71  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049db72  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049db73  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049db75  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0049db78  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049db7a  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0049db7c  894df8                 -mov dword ptr [ebp - 8], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ecx;
    // 0049db7f  8b5d10                 -mov ebx, dword ptr [ebp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0049db82  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0049db84  e827280400             -call 0x4e03b0
    cpu.esp -= 4;
    sub_4e03b0(app, cpu);
    if (cpu.terminate) return;
    // 0049db89  8b4df8                 -mov ecx, dword ptr [ebp - 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0049db8c  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
L_0x0049db8e:
    // 0049db8e  4e                     -dec esi
    (cpu.esi)--;
    // 0049db8f  83feff                 +cmp esi, -1
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
    // 0049db92  7454                   -je 0x49dbe8
    if (cpu.flags.zf)
    {
        goto L_0x0049dbe8;
    }
    // 0049db94  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 0049db96  d85a08                 +fcomp dword ptr [edx + 8]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    cpu.fpu.pop();
    // 0049db99  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0049db9b  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0049db9c  760a                   -jbe 0x49dba8
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049dba8;
    }
    // 0049db9e  d94208                 +fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 0049dba1  d9e0                   +fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 0049dba3  d95dfc                 +fstp dword ptr [ebp - 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049dba6  eb06                   -jmp 0x49dbae
    goto L_0x0049dbae;
L_0x0049dba8:
    // 0049dba8  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0049dbab  895dfc                 -mov dword ptr [ebp - 4], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
L_0x0049dbae:
    // 0049dbae  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 0049dbb0  d845fc                 -fadd dword ptr [ebp - 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */));
    // 0049dbb3  d80da8c65300           -fmul dword ptr [0x53c6a8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5490344) /* 0x53c6a8 */));
    // 0049dbb9  d9fa                   -fsqrt 
    cpu.fpu.st(0) = cpu.fpu.sqrt(cpu.fpu.st(0));
    // 0049dbbb  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 0049dbbd  def1                   -fdivrp st(1)
    cpu.fpu.st(1) = cpu.fpu.st(0) / x86::Float(cpu.fpu.st(1));
    cpu.fpu.pop();
    // 0049dbbf  dc0db0c65300           -fmul qword ptr [0x53c6b0]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5490352) /* 0x53c6b0 */));
    // 0049dbc5  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 0049dbc7  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 0049dbc9  d905b8c65300           -fld dword ptr [0x53c6b8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5490360) /* 0x53c6b8 */)));
    // 0049dbcf  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0049dbd1  d8c1                   -fadd st(1)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(1));
    // 0049dbd3  d95918                 -fstp dword ptr [ecx + 0x18]
    app->getMemory<float>(cpu.ecx + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049dbd6  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 0049dbd9  deca                   -fmulp st(2)
    cpu.fpu.st(2) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0049dbdb  83c120                 -add ecx, 0x20
    (cpu.ecx) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0049dbde  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0049dbe0  83c20c                 +add edx, 0xc
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049dbe3  d959fc                 +fstp dword ptr [ecx - 4]
    app->getMemory<float>(cpu.ecx + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049dbe6  eba6                   -jmp 0x49db8e
    goto L_0x0049db8e;
L_0x0049dbe8:
    // 0049dbe8  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0049dbea  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049dbeb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049dbec  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049dbed  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_49dbf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049dbf0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049dbf1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049dbf2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049dbf3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049dbf4  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049dbf6  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0049dbf9  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049dbfb  895df0                 -mov dword ptr [ebp - 0x10], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.ebx;
    // 0049dbfe  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0049dc05  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0049dc07  8b90fc060000           -mov edx, dword ptr [eax + 0x6fc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1788) /* 0x6fc */);
    // 0049dc0d  8955f8                 -mov dword ptr [ebp - 8], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edx;
    // 0049dc10  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049dc12  0f84f5010000           -je 0x49de0d
    if (cpu.flags.zf)
    {
        goto L_0x0049de0d;
    }
    // 0049dc18  8b80fc050000           -mov eax, dword ptr [eax + 0x5fc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1532) /* 0x5fc */);
    // 0049dc1e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049dc20  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 0049dc23  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049dc25  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0049dc28  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0049dc2a  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049dc2c  8a6207                 -mov ah, byte ptr [edx + 7]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(7) /* 0x7 */);
    // 0049dc2f  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0049dc31  f6c401                 +test ah, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 1 /*0x1*/));
    // 0049dc34  753b                   -jne 0x49dc71
    if (!cpu.flags.zf)
    {
        goto L_0x0049dc71;
    }
    // 0049dc36  8b4a10                 -mov ecx, dword ptr [edx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0049dc39  8b420c                 -mov eax, dword ptr [edx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0049dc3c  d94104                 +fld dword ptr [ecx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
    // 0049dc3f  d86004                 +fsub dword ptr [eax + 4]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */));
    // 0049dc42  8b7a08                 -mov edi, dword ptr [edx + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0049dc45  d907                   +fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 0049dc47  d820                   +fsub dword ptr [eax]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.eax));
    // 0049dc49  dec9                   +fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0049dc4b  d94704                 +fld dword ptr [edi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */)));
    // 0049dc4e  d86004                 +fsub dword ptr [eax + 4]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */));
    // 0049dc51  d901                   +fld dword ptr [ecx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx)));
    // 0049dc53  d820                   +fsub dword ptr [eax]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.eax));
    // 0049dc55  dec9                   +fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0049dc57  ded9                   +fcompp 
    cpu.fpu.compare(cpu.fpu.st(0), cpu.fpu.st(1));
    cpu.fpu.pop();
    cpu.fpu.pop();
    // 0049dc59  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0049dc5b  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0049dc5c  7607                   -jbe 0x49dc65
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049dc65;
    }
    // 0049dc5e  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049dc63  eb02                   -jmp 0x49dc67
    goto L_0x0049dc67;
L_0x0049dc65:
    // 0049dc65  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0049dc67:
    // 0049dc67  8b0d4c4e5500           -mov ecx, dword ptr [0x554e4c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5590604) /* 0x554e4c */);
    // 0049dc6d  31c1                   +xor ecx, eax
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0049dc6f  eb02                   -jmp 0x49dc73
    goto L_0x0049dc73;
L_0x0049dc71:
    // 0049dc71  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0049dc73:
    // 0049dc73  894df4                 -mov dword ptr [ebp - 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ecx;
    // 0049dc76  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0049dc78:
    // 0049dc78  8b7df8                 -mov edi, dword ptr [ebp - 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0049dc7b  39f9                   +cmp ecx, edi
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
    // 0049dc7d  0f8d8a010000           -jge 0x49de0d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049de0d;
    }
    // 0049dc83  8d47ff                 -lea eax, [edi - 1]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */);
    // 0049dc86  39c1                   +cmp ecx, eax
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
    // 0049dc88  7d5c                   -jge 0x49dce6
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049dce6;
    }
    // 0049dc8a  8a838b000000           -mov al, byte ptr [ebx + 0x8b]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(139) /* 0x8b */);
    // 0049dc90  81c384000000           -add ebx, 0x84
    (cpu.ebx) += x86::reg32(x86::sreg32(132 /*0x84*/));
    // 0049dc96  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 0049dc98  7547                   -jne 0x49dce1
    if (!cpu.flags.zf)
    {
        goto L_0x0049dce1;
    }
    // 0049dc9a  8b4310                 -mov eax, dword ptr [ebx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 0049dc9d  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0049dca0  8b7dfc                 -mov edi, dword ptr [ebp - 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0049dca3  8b430c                 -mov eax, dword ptr [ebx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 0049dca6  d94704                 +fld dword ptr [edi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */)));
    // 0049dca9  d86004                 +fsub dword ptr [eax + 4]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */));
    // 0049dcac  8b7b08                 -mov edi, dword ptr [ebx + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0049dcaf  d907                   +fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 0049dcb1  d820                   +fsub dword ptr [eax]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.eax));
    // 0049dcb3  dec9                   +fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0049dcb5  d94704                 +fld dword ptr [edi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */)));
    // 0049dcb8  d86004                 +fsub dword ptr [eax + 4]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */));
    // 0049dcbb  8b7dfc                 -mov edi, dword ptr [ebp - 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0049dcbe  d907                   +fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 0049dcc0  d820                   +fsub dword ptr [eax]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.eax));
    // 0049dcc2  dec9                   +fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0049dcc4  ded9                   +fcompp 
    cpu.fpu.compare(cpu.fpu.st(0), cpu.fpu.st(1));
    cpu.fpu.pop();
    cpu.fpu.pop();
    // 0049dcc6  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0049dcc8  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0049dcc9  7607                   -jbe 0x49dcd2
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049dcd2;
    }
    // 0049dccb  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049dcd0  eb02                   -jmp 0x49dcd4
    goto L_0x0049dcd4;
L_0x0049dcd2:
    // 0049dcd2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0049dcd4:
    // 0049dcd4  8b3d4c4e5500           -mov edi, dword ptr [0x554e4c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5590604) /* 0x554e4c */);
    // 0049dcda  31c7                   +xor edi, eax
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0049dcdc  897dec                 -mov dword ptr [ebp - 0x14], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.edi;
    // 0049dcdf  eb05                   -jmp 0x49dce6
    goto L_0x0049dce6;
L_0x0049dce1:
    // 0049dce1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049dce3  8945ec                 -mov dword ptr [ebp - 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
L_0x0049dce6:
    // 0049dce6  837df400               +cmp dword ptr [ebp - 0xc], 0
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
    // 0049dcea  0f850f010000           -jne 0x49ddff
    if (!cpu.flags.zf)
    {
        goto L_0x0049ddff;
    }
    // 0049dcf0  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0049dcf3  8a4014                 -mov al, byte ptr [eax + 0x14]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 0049dcf6  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049dcfb  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0049dcfe  8b420c                 -mov eax, dword ptr [edx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0049dd01  8a4014                 -mov al, byte ptr [eax + 0x14]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 0049dd04  8b7dfc                 -mov edi, dword ptr [ebp - 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0049dd07  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049dd0c  21c7                   -and edi, eax
    cpu.edi &= x86::reg32(x86::sreg32(cpu.eax));
    // 0049dd0e  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0049dd11  8a4014                 -mov al, byte ptr [eax + 0x14]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 0049dd14  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 0049dd19  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0049dd1c  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049dd1e  8545fc                 -test dword ptr [ebp - 4], eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) & cpu.eax));
    // 0049dd21  0f85d8000000           -jne 0x49ddff
    if (!cpu.flags.zf)
    {
        goto L_0x0049ddff;
    }
    // 0049dd27  833d0c3d7a0000         +cmp dword ptr [0x7a3d0c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(8011020) /* 0x7a3d0c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049dd2e  7508                   -jne 0x49dd38
    if (!cpu.flags.zf)
    {
        goto L_0x0049dd38;
    }
    // 0049dd30  89150c3d7a00           -mov dword ptr [0x7a3d0c], edx
    app->getMemory<x86::reg32>(x86::reg32(8011020) /* 0x7a3d0c */) = cpu.edx;
    // 0049dd36  eb07                   -jmp 0x49dd3f
    goto L_0x0049dd3f;
L_0x0049dd38:
    // 0049dd38  a1083d7a00             -mov eax, dword ptr [0x7a3d08]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8011016) /* 0x7a3d08 */);
    // 0049dd3d  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
L_0x0049dd3f:
    // 0049dd3f  804a0780               -or byte ptr [edx + 7], 0x80
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(7) /* 0x7 */) |= x86::reg8(x86::sreg8(128 /*0x80*/));
    // 0049dd43  668b4206               -mov ax, word ptr [edx + 6]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(6) /* 0x6 */);
    // 0049dd47  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 0049dd49  8915083d7a00           -mov dword ptr [0x7a3d08], edx
    app->getMemory<x86::reg32>(x86::reg32(8011016) /* 0x7a3d08 */) = cpu.edx;
    // 0049dd4f  243f                   -and al, 0x3f
    cpu.al &= x86::reg8(x86::sreg8(63 /*0x3f*/));
    // 0049dd51  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0049dd56  8b8486041e0000         -mov eax, dword ptr [esi + eax*4 + 0x1e04]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(7684) /* 0x1e04 */ + cpu.eax * 4);
    // 0049dd5d  894218                 -mov dword ptr [edx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0049dd60  f6420702               +test byte ptr [edx + 7], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(7) /* 0x7 */) & 2 /*0x2*/));
    // 0049dd64  751a                   -jne 0x49dd80
    if (!cpu.flags.zf)
    {
        goto L_0x0049dd80;
    }
    // 0049dd66  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0049dd69  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0049dd6c  894240                 -mov dword ptr [edx + 0x40], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(64) /* 0x40 */) = cpu.eax;
    // 0049dd6f  8b420c                 -mov eax, dword ptr [edx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0049dd72  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0049dd75  894244                 -mov dword ptr [edx + 0x44], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(68) /* 0x44 */) = cpu.eax;
    // 0049dd78  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0049dd7b  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0049dd7e  eb0b                   -jmp 0x49dd8b
    goto L_0x0049dd8b;
L_0x0049dd80:
    // 0049dd80  a1e8e65500             -mov eax, dword ptr [0x55e6e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5629672) /* 0x55e6e8 */);
    // 0049dd85  894240                 -mov dword ptr [edx + 0x40], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(64) /* 0x40 */) = cpu.eax;
    // 0049dd88  894244                 -mov dword ptr [edx + 0x44], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(68) /* 0x44 */) = cpu.eax;
L_0x0049dd8b:
    // 0049dd8b  894248                 -mov dword ptr [edx + 0x48], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(72) /* 0x48 */) = cpu.eax;
    // 0049dd8e  8b7df0                 -mov edi, dword ptr [ebp - 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0049dd91  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049dd93  7506                   -jne 0x49dd9b
    if (!cpu.flags.zf)
    {
        goto L_0x0049dd9b;
    }
    // 0049dd95  806207bf               +and byte ptr [edx + 7], 0xbf
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.edx + x86::reg32(7) /* 0x7 */) &= x86::reg8(x86::sreg8(191 /*0xbf*/))));
    // 0049dd99  eb64                   -jmp 0x49ddff
    goto L_0x0049ddff;
L_0x0049dd9b:
    // 0049dd9b  8a4207                 -mov al, byte ptr [edx + 7]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(7) /* 0x7 */);
    // 0049dd9e  a804                   +test al, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 4 /*0x4*/));
    // 0049dda0  755d                   -jne 0x49ddff
    if (!cpu.flags.zf)
    {
        goto L_0x0049ddff;
    }
    // 0049dda2  88c4                   -mov ah, al
    cpu.ah = cpu.al;
    // 0049dda4  80cc40                 -or ah, 0x40
    cpu.ah |= x86::reg8(x86::sreg8(64 /*0x40*/));
    // 0049dda7  886207                 -mov byte ptr [edx + 7], ah
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(7) /* 0x7 */) = cpu.ah;
    // 0049ddaa  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0049ddad  d94018                 -fld dword ptr [eax + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */)));
    // 0049ddb0  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0049ddb3  d95a54                 -fstp dword ptr [edx + 0x54]
    app->getMemory<float>(cpu.edx + x86::reg32(84) /* 0x54 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049ddb6  d9401c                 -fld dword ptr [eax + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(28) /* 0x1c */)));
    // 0049ddb9  8b420c                 -mov eax, dword ptr [edx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0049ddbc  d95a58                 -fstp dword ptr [edx + 0x58]
    app->getMemory<float>(cpu.edx + x86::reg32(88) /* 0x58 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049ddbf  d94018                 -fld dword ptr [eax + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */)));
    // 0049ddc2  8b420c                 -mov eax, dword ptr [edx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0049ddc5  d95a5c                 -fstp dword ptr [edx + 0x5c]
    app->getMemory<float>(cpu.edx + x86::reg32(92) /* 0x5c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049ddc8  d9401c                 -fld dword ptr [eax + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(28) /* 0x1c */)));
    // 0049ddcb  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0049ddce  d95a60                 -fstp dword ptr [edx + 0x60]
    app->getMemory<float>(cpu.edx + x86::reg32(96) /* 0x60 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049ddd1  d94018                 -fld dword ptr [eax + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(24) /* 0x18 */)));
    // 0049ddd4  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0049ddd7  d95a64                 -fstp dword ptr [edx + 0x64]
    app->getMemory<float>(cpu.edx + x86::reg32(100) /* 0x64 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049ddda  d9401c                 -fld dword ptr [eax + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(28) /* 0x1c */)));
    // 0049dddd  d95a68                 -fstp dword ptr [edx + 0x68]
    app->getMemory<float>(cpu.edx + x86::reg32(104) /* 0x68 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049dde0  8a4207                 -mov al, byte ptr [edx + 7]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(7) /* 0x7 */);
    // 0049dde3  897a50                 -mov dword ptr [edx + 0x50], edi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(80) /* 0x50 */) = cpu.edi;
    // 0049dde6  a808                   +test al, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 8 /*0x8*/));
    // 0049dde8  7407                   -je 0x49ddf1
    if (cpu.flags.zf)
    {
        goto L_0x0049ddf1;
    }
    // 0049ddea  a1e0e65500             -mov eax, dword ptr [0x55e6e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5629664) /* 0x55e6e0 */);
    // 0049ddef  eb05                   -jmp 0x49ddf6
    goto L_0x0049ddf6;
L_0x0049ddf1:
    // 0049ddf1  a1dce65500             -mov eax, dword ptr [0x55e6dc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5629660) /* 0x55e6dc */);
L_0x0049ddf6:
    // 0049ddf6  894274                 -mov dword ptr [edx + 0x74], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(116) /* 0x74 */) = cpu.eax;
    // 0049ddf9  894278                 -mov dword ptr [edx + 0x78], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(120) /* 0x78 */) = cpu.eax;
    // 0049ddfc  89427c                 -mov dword ptr [edx + 0x7c], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(124) /* 0x7c */) = cpu.eax;
L_0x0049ddff:
    // 0049ddff  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0049de02  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0049de03  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0049de05  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 0049de08  e96bfeffff             -jmp 0x49dc78
    goto L_0x0049dc78;
L_0x0049de0d:
    // 0049de0d  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0049de0f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049de10  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049de11  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049de12  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049de13  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_49de20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049de20  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049de21  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049de22  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049de23  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049de25  81ece0000000           -sub esp, 0xe0
    (cpu.esp) -= x86::reg32(x86::sreg32(224 /*0xe0*/));
    // 0049de2b  83ed6e                 -sub ebp, 0x6e
    (cpu.ebp) -= x86::reg32(x86::sreg32(110 /*0x6e*/));
    // 0049de2e  89456a                 -mov dword ptr [ebp + 0x6a], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(106) /* 0x6a */) = cpu.eax;
    // 0049de31  895562                 -mov dword ptr [ebp + 0x62], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(98) /* 0x62 */) = cpu.edx;
    // 0049de34  895d5e                 -mov dword ptr [ebp + 0x5e], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(94) /* 0x5e */) = cpu.ebx;
    // 0049de37  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0049de39  8b0dace65500           -mov ecx, dword ptr [0x55e6ac]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5629612) /* 0x55e6ac */);
    // 0049de3f  a1b0e65500             -mov eax, dword ptr [0x55e6b0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5629616) /* 0x55e6b0 */);
    // 0049de44  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 0049de47  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0049de4a  81c9000000ff           -or ecx, 0xff000000
    cpu.ecx |= x86::reg32(x86::sreg32(4278190080 /*0xff000000*/));
    // 0049de50  09c8                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049de52  8b0db4e65500           -mov ecx, dword ptr [0x55e6b4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5629620) /* 0x55e6b4 */);
    // 0049de58  8d7d8e                 -lea edi, [ebp - 0x72]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-114) /* -0x72 */);
    // 0049de5b  09c1                   -or ecx, eax
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0049de5d  bee0c34900             -mov esi, 0x49c3e0
    cpu.esi = 4834272 /*0x49c3e0*/;
    // 0049de62  894d4a                 -mov dword ptr [ebp + 0x4a], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(74) /* 0x4a */) = cpu.ecx;
    // 0049de65  b909000000             -mov ecx, 9
    cpu.ecx = 9 /*0x9*/;
    // 0049de6a  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049de6c  b909000000             -mov ecx, 9
    cpu.ecx = 9 /*0x9*/;
    // 0049de71  8d7dfa                 -lea edi, [ebp - 6]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-6) /* -0x6 */);
    // 0049de74  be98445600             -mov esi, 0x564498
    cpu.esi = 5653656 /*0x564498*/;
    // 0049de79  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049de7b  8d7d2a                 -lea edi, [ebp + 0x2a]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(42) /* 0x2a */);
    // 0049de7e  be8c445600             -mov esi, 0x56448c
    cpu.esi = 5653644 /*0x56448c*/;
    // 0049de83  8b4d6a                 -mov ecx, dword ptr [ebp + 0x6a]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(106) /* 0x6a */);
    // 0049de86  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049de87  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049de88  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049de89  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049de8b  7508                   -jne 0x49de95
    if (!cpu.flags.zf)
    {
        goto L_0x0049de95;
    }
    // 0049de8d  894d5a                 -mov dword ptr [ebp + 0x5a], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(90) /* 0x5a */) = cpu.ecx;
    // 0049de90  e9b8010000             -jmp 0x49e04d
    goto L_0x0049e04d;
L_0x0049de95:
    // 0049de95  8b4562                 -mov eax, dword ptr [ebp + 0x62]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(98) /* 0x62 */);
    // 0049de98  3b81f8000000           +cmp eax, dword ptr [ecx + 0xf8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(248) /* 0xf8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049de9e  7c11                   -jl 0x49deb1
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049deb1;
    }
    // 0049dea0  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0049dea2  897d5a                 -mov dword ptr [ebp + 0x5a], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(90) /* 0x5a */) = cpu.edi;
    // 0049dea5  d9455a                 -fld dword ptr [ebp + 0x5a]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(90) /* 0x5a */)));
    // 0049dea8  8d656e                 -lea esp, [ebp + 0x6e]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(110) /* 0x6e */);
    // 0049deab  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049deac  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049dead  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049deae  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
L_0x0049deb1:
    // 0049deb1  8b5d6a                 -mov ebx, dword ptr [ebp + 0x6a]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(106) /* 0x6a */);
    // 0049deb4  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049deb7  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049deb9  8b83fc040000           -mov eax, dword ptr [ebx + 0x4fc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1276) /* 0x4fc */);
    // 0049debf  894552                 -mov dword ptr [ebp + 0x52], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(82) /* 0x52 */) = cpu.eax;
    // 0049dec2  8b456a                 -mov eax, dword ptr [ebp + 0x6a]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(106) /* 0x6a */);
    // 0049dec5  81c1041f0000           -add ecx, 0x1f04
    (cpu.ecx) += x86::reg32(x86::sreg32(7940 /*0x1f04*/));
    // 0049decb  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0049dece  895d42                 -mov dword ptr [ebp + 0x42], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(66) /* 0x42 */) = cpu.ebx;
    // 0049ded1  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049ded3  8b9bfc030000           -mov ebx, dword ptr [ebx + 0x3fc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1020) /* 0x3fc */);
    // 0049ded9  894556                 -mov dword ptr [ebp + 0x56], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(86) /* 0x56 */) = cpu.eax;
    // 0049dedc  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 0049dee3  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049dee5  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049dee8  8b5d56                 -mov ebx, dword ptr [ebp + 0x56]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(86) /* 0x56 */);
    // 0049deeb  894546                 -mov dword ptr [ebp + 0x46], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(70) /* 0x46 */) = cpu.eax;
    // 0049deee  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049def0  8b456a                 -mov eax, dword ptr [ebp + 0x6a]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(106) /* 0x6a */);
    // 0049def3  8b7814                 -mov edi, dword ptr [eax + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 0049def6  8b7546                 -mov esi, dword ptr [ebp + 0x46]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(70) /* 0x46 */);
    // 0049def9  01cf                   -add edi, ecx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049defb  01f7                   -add edi, esi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.esi));
    // 0049defd  8b701c                 -mov esi, dword ptr [eax + 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0049df00  8b4024                 -mov eax, dword ptr [eax + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 0049df03  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049df05  894566                 -mov dword ptr [ebp + 0x66], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(102) /* 0x66 */) = cpu.eax;
    // 0049df08  8b4542                 -mov eax, dword ptr [ebp + 0x42]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(66) /* 0x42 */);
    // 0049df0b  8b80fc030000           -mov eax, dword ptr [eax + 0x3fc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1020) /* 0x3fc */);
    // 0049df11  01ce                   -add esi, ecx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049df13  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 0049df16  8b4d66                 -mov ecx, dword ptr [ebp + 0x66]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(102) /* 0x66 */);
    // 0049df19  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049df1b  8b4546                 -mov eax, dword ptr [ebp + 0x46]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(70) /* 0x46 */);
    // 0049df1e  895d56                 -mov dword ptr [ebp + 0x56], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(86) /* 0x56 */) = cpu.ebx;
    // 0049df21  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049df23  8b5d5e                 -mov ebx, dword ptr [ebp + 0x5e]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(94) /* 0x5e */);
    // 0049df26  894d66                 -mov dword ptr [ebp + 0x66], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(102) /* 0x66 */) = cpu.ecx;
    // 0049df29  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049df2b  7506                   -jne 0x49df33
    if (!cpu.flags.zf)
    {
        goto L_0x0049df33;
    }
    // 0049df2d  8d45fa                 -lea eax, [ebp - 6]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-6) /* -0x6 */);
    // 0049df30  89455e                 -mov dword ptr [ebp + 0x5e], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(94) /* 0x5e */) = cpu.eax;
L_0x0049df33:
    // 0049df33  837d7e00               +cmp dword ptr [ebp + 0x7e], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049df37  7506                   -jne 0x49df3f
    if (!cpu.flags.zf)
    {
        goto L_0x0049df3f;
    }
    // 0049df39  8d45fa                 -lea eax, [ebp - 6]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-6) /* -0x6 */);
    // 0049df3c  89457e                 -mov dword ptr [ebp + 0x7e], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */) = cpu.eax;
L_0x0049df3f:
    // 0049df3f  83bd8600000000         +cmp dword ptr [ebp + 0x86], 0
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
    // 0049df46  7509                   -jne 0x49df51
    if (!cpu.flags.zf)
    {
        goto L_0x0049df51;
    }
    // 0049df48  8d45fa                 -lea eax, [ebp - 6]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-6) /* -0x6 */);
    // 0049df4b  898586000000           -mov dword ptr [ebp + 0x86], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(134) /* 0x86 */) = cpu.eax;
L_0x0049df51:
    // 0049df51  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049df53  7503                   -jne 0x49df58
    if (!cpu.flags.zf)
    {
        goto L_0x0049df58;
    }
    // 0049df55  8d552a                 -lea edx, [ebp + 0x2a]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(42) /* 0x2a */);
L_0x0049df58:
    // 0049df58  83bd8200000000         +cmp dword ptr [ebp + 0x82], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(130) /* 0x82 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049df5f  7509                   -jne 0x49df6a
    if (!cpu.flags.zf)
    {
        goto L_0x0049df6a;
    }
    // 0049df61  8d452a                 -lea eax, [ebp + 0x2a]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(42) /* 0x2a */);
    // 0049df64  898582000000           -mov dword ptr [ebp + 0x82], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(130) /* 0x82 */) = cpu.eax;
L_0x0049df6a:
    // 0049df6a  83bd8a00000000         +cmp dword ptr [ebp + 0x8a], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(138) /* 0x8a */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049df71  7509                   -jne 0x49df7c
    if (!cpu.flags.zf)
    {
        goto L_0x0049df7c;
    }
    // 0049df73  8d452a                 -lea eax, [ebp + 0x2a]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(42) /* 0x2a */);
    // 0049df76  89858a000000           -mov dword ptr [ebp + 0x8a], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(138) /* 0x8a */) = cpu.eax;
L_0x0049df7c:
    // 0049df7c  8d451e                 -lea eax, [ebp + 0x1e]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(30) /* 0x1e */);
    // 0049df7f  8b8d82000000           -mov ecx, dword ptr [ebp + 0x82]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(130) /* 0x82 */);
    // 0049df85  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049df86  8b5d7e                 -mov ebx, dword ptr [ebp + 0x7e]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 0049df89  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049df8e  e89d240400             -call 0x4e0430
    cpu.esp -= 4;
    sub_4e0430(app, cpu);
    if (cpu.terminate) return;
    // 0049df93  8d4536                 -lea eax, [ebp + 0x36]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(54) /* 0x36 */);
    // 0049df96  8b8d8a000000           -mov ecx, dword ptr [ebp + 0x8a]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(138) /* 0x8a */);
    // 0049df9c  8b9d86000000           -mov ebx, dword ptr [ebp + 0x86]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(134) /* 0x86 */);
    // 0049dfa2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049dfa3  8d551e                 -lea edx, [ebp + 0x1e]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(30) /* 0x1e */);
    // 0049dfa6  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049dfab  e880240400             -call 0x4e0430
    cpu.esp -= 4;
    sub_4e0430(app, cpu);
    if (cpu.terminate) return;
    // 0049dfb0  8d5db2                 -lea ebx, [ebp - 0x4e]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-78) /* -0x4e */);
    // 0049dfb3  8b557e                 -mov edx, dword ptr [ebp + 0x7e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 0049dfb6  8b455e                 -mov eax, dword ptr [ebp + 0x5e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(94) /* 0x5e */);
    // 0049dfb9  e8c2220400             -call 0x4e0280
    cpu.esp -= 4;
    sub_4e0280(app, cpu);
    if (cpu.terminate) return;
    // 0049dfbe  8d5d8e                 -lea ebx, [ebp - 0x72]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-114) /* -0x72 */);
    // 0049dfc1  8b9586000000           -mov edx, dword ptr [ebp + 0x86]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(134) /* 0x86 */);
    // 0049dfc7  8d45b2                 -lea eax, [ebp - 0x4e]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-78) /* -0x4e */);
    // 0049dfca  e8b1220400             -call 0x4e0280
    cpu.esp -= 4;
    sub_4e0280(app, cpu);
    if (cpu.terminate) return;
    // 0049dfcf  8b554a                 -mov edx, dword ptr [ebp + 0x4a]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(74) /* 0x4a */);
    // 0049dfd2  8d4d8e                 -lea ecx, [ebp - 0x72]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(-114) /* -0x72 */);
    // 0049dfd5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049dfd6  8d4536                 -lea eax, [ebp + 0x36]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(54) /* 0x36 */);
    // 0049dfd9  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0049dfdb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049dfdc  8b5556                 -mov edx, dword ptr [ebp + 0x56]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(86) /* 0x56 */);
    // 0049dfdf  8b4552                 -mov eax, dword ptr [ebp + 0x52]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(82) /* 0x52 */);
    // 0049dfe2  e8e9f9ffff             -call 0x49d9d0
    cpu.esp -= 4;
    sub_49d9d0(app, cpu);
    if (cpu.terminate) return;
    // 0049dfe7  8b0d9ce65500           -mov ecx, dword ptr [0x55e69c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5629596) /* 0x55e69c */);
    // 0049dfed  d95d4e                 -fstp dword ptr [ebp + 0x4e]
    app->getMemory<float>(cpu.ebp + x86::reg32(78) /* 0x4e */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049dff0  83f901                 +cmp ecx, 1
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
    // 0049dff3  7515                   -jne 0x49e00a
    if (!cpu.flags.zf)
    {
        goto L_0x0049e00a;
    }
    // 0049dff5  8d45b2                 -lea eax, [ebp - 0x4e]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-78) /* -0x4e */);
    // 0049dff8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049dff9  8b4d66                 -mov ecx, dword ptr [ebp + 0x66]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(102) /* 0x66 */);
    // 0049dffc  8b5552                 -mov edx, dword ptr [ebp + 0x52]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(82) /* 0x52 */);
    // 0049dfff  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049e000  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0049e002  8b456a                 -mov eax, dword ptr [ebp + 0x6a]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(106) /* 0x6a */);
    // 0049e005  e826faffff             -call 0x49da30
    cpu.esp -= 4;
    sub_49da30(app, cpu);
    if (cpu.terminate) return;
L_0x0049e00a:
    // 0049e00a  83bd8e00000000         +cmp dword ptr [ebp + 0x8e], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(142) /* 0x8e */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049e011  7423                   -je 0x49e036
    if (cpu.flags.zf)
    {
        goto L_0x0049e036;
    }
    // 0049e013  8d5dd6                 -lea ebx, [ebp - 0x2a]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-42) /* -0x2a */);
    // 0049e016  baece65500             -mov edx, 0x55e6ec
    cpu.edx = 5629676 /*0x55e6ec*/;
    // 0049e01b  8d45b2                 -lea eax, [ebp - 0x4e]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-78) /* -0x4e */);
    // 0049e01e  e85d220400             -call 0x4e0280
    cpu.esp -= 4;
    sub_4e0280(app, cpu);
    if (cpu.terminate) return;
    // 0049e023  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0049e025  8d45d6                 -lea eax, [ebp - 0x2a]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-42) /* -0x2a */);
    // 0049e028  8b5d66                 -mov ebx, dword ptr [ebp + 0x66]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(102) /* 0x66 */);
    // 0049e02b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049e02c  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0049e02e  8b4552                 -mov eax, dword ptr [ebp + 0x52]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(82) /* 0x52 */);
    // 0049e031  e83afbffff             -call 0x49db70
    cpu.esp -= 4;
    sub_49db70(app, cpu);
    if (cpu.terminate) return;
L_0x0049e036:
    // 0049e036  8b9d8e000000           -mov ebx, dword ptr [ebp + 0x8e]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(142) /* 0x8e */);
    // 0049e03c  8b5562                 -mov edx, dword ptr [ebp + 0x62]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(98) /* 0x62 */);
    // 0049e03f  8b456a                 -mov eax, dword ptr [ebp + 0x6a]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(106) /* 0x6a */);
    // 0049e042  e8a9fbffff             -call 0x49dbf0
    cpu.esp -= 4;
    sub_49dbf0(app, cpu);
    if (cpu.terminate) return;
    // 0049e047  8b454e                 -mov eax, dword ptr [ebp + 0x4e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(78) /* 0x4e */);
    // 0049e04a  89455a                 -mov dword ptr [ebp + 0x5a], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(90) /* 0x5a */) = cpu.eax;
L_0x0049e04d:
    // 0049e04d  d9455a                 -fld dword ptr [ebp + 0x5a]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(90) /* 0x5a */)));
    // 0049e050  8d656e                 -lea esp, [ebp + 0x6e]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(110) /* 0x6e */);
    // 0049e053  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e054  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e055  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e056  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
/* data blob: 00000000000000000000000000000000000000000000008d80000000008d5200 */
void Application::sub_49e080(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049e080  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049e081  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049e082  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049e083  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049e084  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049e085  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049e086  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049e088  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 0049e08d  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0049e092  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0049e097  be04000000             -mov esi, 4
    cpu.esi = 4 /*0x4*/;
    // 0049e09c  b401                   -mov ah, 1
    cpu.ah = 1 /*0x1*/;
    // 0049e09e  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0049e0a0  8915e0227a00           -mov dword ptr [0x7a22e0], edx
    app->getMemory<x86::reg32>(x86::reg32(8004320) /* 0x7a22e0 */) = cpu.edx;
    // 0049e0a6  890de4227a00           -mov dword ptr [0x7a22e4], ecx
    app->getMemory<x86::reg32>(x86::reg32(8004324) /* 0x7a22e4 */) = cpu.ecx;
    // 0049e0ac  891d0cd56f00           -mov dword ptr [0x6fd50c], ebx
    app->getMemory<x86::reg32>(x86::reg32(7329036) /* 0x6fd50c */) = cpu.ebx;
    // 0049e0b2  8935b0d36f00           -mov dword ptr [0x6fd3b0], esi
    app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */) = cpu.esi;
    // 0049e0b8  893d1ce75500           -mov dword ptr [0x55e71c], edi
    app->getMemory<x86::reg32>(x86::reg32(5629724) /* 0x55e71c */) = cpu.edi;
    // 0049e0be  882514227a00           -mov byte ptr [0x7a2214], ah
    app->getMemory<x86::reg8>(x86::reg32(8004116) /* 0x7a2214 */) = cpu.ah;
    // 0049e0c4  befcd26f00             -mov esi, 0x6fd2fc
    cpu.esi = 7328508 /*0x6fd2fc*/;
    // 0049e0c9  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049e0cb  bf15227a00             -mov edi, 0x7a2215
    cpu.edi = 8004117 /*0x7a2215*/;
    // 0049e0d0  6689157a227a00         -mov word ptr [0x7a227a], dx
    app->getMemory<x86::reg16>(x86::reg32(8004218) /* 0x7a227a */) = cpu.dx;
    // 0049e0d7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0049e0d8:
    // 0049e0d8  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0049e0da  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0049e0dc  3c00                   +cmp al, 0
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
    // 0049e0de  7410                   -je 0x49e0f0
    if (cpu.flags.zf)
    {
        goto L_0x0049e0f0;
    }
    // 0049e0e0  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0049e0e3  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049e0e6  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0049e0e9  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049e0ec  3c00                   +cmp al, 0
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
    // 0049e0ee  75e8                   -jne 0x49e0d8
    if (!cpu.flags.zf)
    {
        goto L_0x0049e0d8;
    }
L_0x0049e0f0:
    // 0049e0f0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e0f1  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049e0f3  40                     -inc eax
    (cpu.eax)++;
    // 0049e0f4  66c7044578227a00ffff   -mov word ptr [eax*2 + 0x7a2278], 0xffff
    app->getMemory<x86::reg16>(x86::reg32(8004216) /* 0x7a2278 */ + cpu.eax * 2) = 65535 /*0xffff*/;
L_0x0049e0fe:
    // 0049e0fe  83f808                 +cmp eax, 8
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
    // 0049e101  7d0d                   -jge 0x49e110
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049e110;
    }
    // 0049e103  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0049e104  66c7044578227a00ffff   -mov word ptr [eax*2 + 0x7a2278], 0xffff
    app->getMemory<x86::reg16>(x86::reg32(8004216) /* 0x7a2278 */ + cpu.eax * 2) = 65535 /*0xffff*/;
    // 0049e10e  ebee                   -jmp 0x49e0fe
    goto L_0x0049e0fe;
L_0x0049e110:
    // 0049e110  e83b150000             -call 0x49f650
    cpu.esp -= 4;
    sub_49f650(app, cpu);
    if (cpu.terminate) return;
    // 0049e115  e8e6830000             -call 0x4a6500
    cpu.esp -= 4;
    sub_4a6500(app, cpu);
    if (cpu.terminate) return;
    // 0049e11a  e871f6f8ff             -call 0x42d790
    cpu.esp -= 4;
    sub_42d790(app, cpu);
    if (cpu.terminate) return;
    // 0049e11f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049e124  bfa01f7a00             -mov edi, 0x7a1fa0
    cpu.edi = 8003488 /*0x7a1fa0*/;
    // 0049e129  a360e85500             -mov dword ptr [0x55e860], eax
    app->getMemory<x86::reg32>(x86::reg32(5630048) /* 0x55e860 */) = cpu.eax;
    // 0049e12e  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049e130  49                     -dec ecx
    (cpu.ecx)--;
    // 0049e131  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0049e133  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0049e135  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0049e137  49                     -dec ecx
    (cpu.ecx)--;
    // 0049e138  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049e13a  0f84a8000000           -je 0x49e1e8
    if (cpu.flags.zf)
    {
        goto L_0x0049e1e8;
    }
    // 0049e140  bee01f7a00             -mov esi, 0x7a1fe0
    cpu.esi = 8003552 /*0x7a1fe0*/;
    // 0049e145  bffcd26f00             -mov edi, 0x6fd2fc
    cpu.edi = 7328508 /*0x6fd2fc*/;
    // 0049e14a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0049e14b:
    // 0049e14b  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0049e14d  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0049e14f  3c00                   +cmp al, 0
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
    // 0049e151  7410                   -je 0x49e163
    if (cpu.flags.zf)
    {
        goto L_0x0049e163;
    }
    // 0049e153  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0049e156  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049e159  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0049e15c  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049e15f  3c00                   +cmp al, 0
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
    // 0049e161  75e8                   -jne 0x49e14b
    if (!cpu.flags.zf)
    {
        goto L_0x0049e14b;
    }
L_0x0049e163:
    // 0049e163  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e164  a100207a00             -mov eax, dword ptr [0x7a2000]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8003584) /* 0x7a2000 */);
    // 0049e169  a3b8d36f00             -mov dword ptr [0x6fd3b8], eax
    app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */) = cpu.eax;
    // 0049e16e  a104207a00             -mov eax, dword ptr [0x7a2004]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8003588) /* 0x7a2004 */);
    // 0049e173  a3acd46f00             -mov dword ptr [0x6fd4ac], eax
    app->getMemory<x86::reg32>(x86::reg32(7328940) /* 0x6fd4ac */) = cpu.eax;
    // 0049e178  a10c207a00             -mov eax, dword ptr [0x7a200c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8003596) /* 0x7a200c */);
    // 0049e17d  a3b4d46f00             -mov dword ptr [0x6fd4b4], eax
    app->getMemory<x86::reg32>(x86::reg32(7328948) /* 0x6fd4b4 */) = cpu.eax;
    // 0049e182  83f808                 +cmp eax, 8
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
    // 0049e185  7507                   -jne 0x49e18e
    if (!cpu.flags.zf)
    {
        goto L_0x0049e18e;
    }
    // 0049e187  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0049e18c  eb0e                   -jmp 0x49e19c
    goto L_0x0049e19c;
L_0x0049e18e:
    // 0049e18e  83f804                 +cmp eax, 4
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
    // 0049e191  7507                   -jne 0x49e19a
    if (!cpu.flags.zf)
    {
        goto L_0x0049e19a;
    }
    // 0049e193  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049e198  eb02                   -jmp 0x49e19c
    goto L_0x0049e19c;
L_0x0049e19a:
    // 0049e19a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0049e19c:
    // 0049e19c  a3b0d46f00             -mov dword ptr [0x6fd4b0], eax
    app->getMemory<x86::reg32>(x86::reg32(7328944) /* 0x6fd4b0 */) = cpu.eax;
    // 0049e1a1  a110207a00             -mov eax, dword ptr [0x7a2010]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8003600) /* 0x7a2010 */);
    // 0049e1a6  a370d46f00             -mov dword ptr [0x6fd470], eax
    app->getMemory<x86::reg32>(x86::reg32(7328880) /* 0x6fd470 */) = cpu.eax;
    // 0049e1ab  a114207a00             -mov eax, dword ptr [0x7a2014]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8003604) /* 0x7a2014 */);
    // 0049e1b0  bba01f7a00             -mov ebx, 0x7a1fa0
    cpu.ebx = 8003488 /*0x7a1fa0*/;
    // 0049e1b5  a3d4d46f00             -mov dword ptr [0x6fd4d4], eax
    app->getMemory<x86::reg32>(x86::reg32(7328980) /* 0x6fd4d4 */) = cpu.eax;
    // 0049e1ba  a108207a00             -mov eax, dword ptr [0x7a2008]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8003592) /* 0x7a2008 */);
    // 0049e1bf  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049e1c1  e84ab8f9ff             -call 0x439a10
    cpu.esp -= 4;
    sub_439a10(app, cpu);
    if (cpu.terminate) return;
    // 0049e1c6  b8fcd26f00             -mov eax, 0x6fd2fc
    cpu.eax = 7328508 /*0x6fd2fc*/;
    // 0049e1cb  8b0ddc1f7a00           -mov ecx, dword ptr [0x7a1fdc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(8003548) /* 0x7a1fdc */);
    // 0049e1d1  668b15fc1f7a00         -mov dx, word ptr [0x7a1ffc]
    cpu.dx = app->getMemory<x86::reg16>(x86::reg32(8003580) /* 0x7a1ffc */);
    // 0049e1d8  e823790000             -call 0x4a5b00
    cpu.esp -= 4;
    sub_4a5b00(app, cpu);
    if (cpu.terminate) return;
    // 0049e1dd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049e1df  7428                   -je 0x49e209
    if (cpu.flags.zf)
    {
        goto L_0x0049e209;
    }
    // 0049e1e1  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049e1e6  eb23                   -jmp 0x49e20b
    goto L_0x0049e20b;
L_0x0049e1e8:
    // 0049e1e8  b90a1a0000             -mov ecx, 0x1a0a
    cpu.ecx = 6666 /*0x1a0a*/;
    // 0049e1ed  bbbcc65300             -mov ebx, 0x53c6bc
    cpu.ebx = 5490364 /*0x53c6bc*/;
    // 0049e1f2  b8fcd26f00             -mov eax, 0x6fd2fc
    cpu.eax = 7328508 /*0x6fd2fc*/;
    // 0049e1f7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049e1f9  e802790000             -call 0x4a5b00
    cpu.esp -= 4;
    sub_4a5b00(app, cpu);
    if (cpu.terminate) return;
    // 0049e1fe  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049e200  7407                   -je 0x49e209
    if (cpu.flags.zf)
    {
        goto L_0x0049e209;
    }
    // 0049e202  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049e207  eb02                   -jmp 0x49e20b
    goto L_0x0049e20b;
L_0x0049e209:
    // 0049e209  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0049e20b:
    // 0049e20b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e20c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e20d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e20e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e20f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e210  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e211  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_49e220(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049e220  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049e221  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049e222  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049e223  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049e225  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049e22a  bbfeffffff             -mov ebx, 0xfffffffe
    cpu.ebx = 4294967294 /*0xfffffffe*/;
    // 0049e22f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049e231  e85a810000             -call 0x4a6390
    cpu.esp -= 4;
    sub_4a6390(app, cpu);
    if (cpu.terminate) return;
    // 0049e236  668915da227a00         -mov word ptr [0x7a22da], dx
    app->getMemory<x86::reg16>(x86::reg32(8004314) /* 0x7a22da */) = cpu.dx;
    // 0049e23d  66891d78227a00         -mov word ptr [0x7a2278], bx
    app->getMemory<x86::reg16>(x86::reg32(8004216) /* 0x7a2278 */) = cpu.bx;
    // 0049e244  66891576227a00         -mov word ptr [0x7a2276], dx
    app->getMemory<x86::reg16>(x86::reg32(8004214) /* 0x7a2276 */) = cpu.dx;
    // 0049e24b  e830feffff             -call 0x49e080
    cpu.esp -= 4;
    sub_49e080(app, cpu);
    if (cpu.terminate) return;
    // 0049e250  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049e252  0f8476000000           -je 0x49e2ce
    if (cpu.flags.zf)
    {
        goto L_0x0049e2ce;
    }
L_0x0049e258:
    // 0049e258  66833d96227a0000       +cmp word ptr [0x7a2296], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(8004246) /* 0x7a2296 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0049e260  7531                   -jne 0x49e293
    if (!cpu.flags.zf)
    {
        goto L_0x0049e293;
    }
    // 0049e262  e849830000             -call 0x4a65b0
    cpu.esp -= 4;
    sub_4a65b0(app, cpu);
    if (cpu.terminate) return;
    // 0049e267  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049e269  750a                   -jne 0x49e275
    if (!cpu.flags.zf)
    {
        goto L_0x0049e275;
    }
    // 0049e26b  66833ddc227a0000       +cmp word ptr [0x7a22dc], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(8004316) /* 0x7a22dc */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0049e273  74e3                   -je 0x49e258
    if (cpu.flags.zf)
    {
        goto L_0x0049e258;
    }
L_0x0049e275:
    // 0049e275  b8c2000000             -mov eax, 0xc2
    cpu.eax = 194 /*0xc2*/;
    // 0049e27a  e86169faff             -call 0x444be0
    cpu.esp -= 4;
    sub_444be0(app, cpu);
    if (cpu.terminate) return;
    // 0049e27f  66c705dc227a000100     -mov word ptr [0x7a22dc], 1
    app->getMemory<x86::reg16>(x86::reg32(8004316) /* 0x7a22dc */) = 1 /*0x1*/;
    // 0049e288  e853830000             -call 0x4a65e0
    cpu.esp -= 4;
    sub_4a65e0(app, cpu);
    if (cpu.terminate) return;
    // 0049e28d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049e28f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e290  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e291  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e292  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049e293:
    // 0049e293  a18c227a00             -mov eax, dword ptr [0x7a228c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8004236) /* 0x7a228c */);
    // 0049e298  a3e4227a00             -mov dword ptr [0x7a22e4], eax
    app->getMemory<x86::reg32>(x86::reg32(8004324) /* 0x7a22e4 */) = cpu.eax;
    // 0049e29d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049e29f  e83c8a0000             -call 0x4a6ce0
    cpu.esp -= 4;
    sub_4a6ce0(app, cpu);
    if (cpu.terminate) return;
    // 0049e2a4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049e2a6  7521                   -jne 0x49e2c9
    if (!cpu.flags.zf)
    {
        goto L_0x0049e2c9;
    }
    // 0049e2a8  b8c2000000             -mov eax, 0xc2
    cpu.eax = 194 /*0xc2*/;
    // 0049e2ad  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0049e2b2  e82969faff             -call 0x444be0
    cpu.esp -= 4;
    sub_444be0(app, cpu);
    if (cpu.terminate) return;
    // 0049e2b7  668915dc227a00         -mov word ptr [0x7a22dc], dx
    app->getMemory<x86::reg16>(x86::reg32(8004316) /* 0x7a22dc */) = cpu.dx;
    // 0049e2be  e81d830000             -call 0x4a65e0
    cpu.esp -= 4;
    sub_4a65e0(app, cpu);
    if (cpu.terminate) return;
    // 0049e2c3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049e2c5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e2c6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e2c7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e2c8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049e2c9:
    // 0049e2c9  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0049e2ce:
    // 0049e2ce  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e2cf  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e2d0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e2d1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_49e2e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049e2e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049e2e1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049e2e2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049e2e3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049e2e5  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049e2ea  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0049e2ef  e89c800000             -call 0x4a6390
    cpu.esp -= 4;
    sub_4a6390(app, cpu);
    if (cpu.terminate) return;
    // 0049e2f4  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049e2f6  668915da227a00         -mov word ptr [0x7a22da], dx
    app->getMemory<x86::reg16>(x86::reg32(8004314) /* 0x7a22da */) = cpu.dx;
    // 0049e2fd  66891d78227a00         -mov word ptr [0x7a2278], bx
    app->getMemory<x86::reg16>(x86::reg32(8004216) /* 0x7a2278 */) = cpu.bx;
    // 0049e304  66891576227a00         -mov word ptr [0x7a2276], dx
    app->getMemory<x86::reg16>(x86::reg32(8004214) /* 0x7a2276 */) = cpu.dx;
    // 0049e30b  e870fdffff             -call 0x49e080
    cpu.esp -= 4;
    sub_49e080(app, cpu);
    if (cpu.terminate) return;
    // 0049e310  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049e312  7405                   -je 0x49e319
    if (cpu.flags.zf)
    {
        goto L_0x0049e319;
    }
    // 0049e314  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0049e319:
    // 0049e319  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e31a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e31b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e31c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49e320(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049e320  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049e321  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049e322  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049e323  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049e325  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0049e328  8855ec                 -mov byte ptr [ebp - 0x14], dl
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.dl;
    // 0049e32b  833d10e7550000         +cmp dword ptr [0x55e710], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5629712) /* 0x55e710 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049e332  7523                   -jne 0x49e357
    if (!cpu.flags.zf)
    {
        goto L_0x0049e357;
    }
    // 0049e334  8b0de0017a00           -mov ecx, dword ptr [0x7a01e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(7995872) /* 0x7a01e0 */);
    // 0049e33a  83f907                 +cmp ecx, 7
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
    // 0049e33d  7d18                   -jge 0x49e357
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049e357;
    }
    // 0049e33f  8d5901                 -lea ebx, [ecx + 1]
    cpu.ebx = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 0049e342  8d55ec                 -lea edx, [ebp - 0x14]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0049e345  891de0017a00           -mov dword ptr [0x7a01e0], ebx
    app->getMemory<x86::reg32>(x86::reg32(7995872) /* 0x7a01e0 */) = cpu.ebx;
    // 0049e34b  e850130000             -call 0x49f6a0
    cpu.esp -= 4;
    sub_49f6a0(app, cpu);
    if (cpu.terminate) return;
    // 0049e350  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049e355  eb02                   -jmp 0x49e359
    goto L_0x0049e359;
L_0x0049e357:
    // 0049e357  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0049e359:
    // 0049e359  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0049e35b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e35c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e35d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e35e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_49e360(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049e360  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049e361  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049e362  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049e363  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049e365  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049e367  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0049e369:
    // 0049e369  3b1518e75500           +cmp edx, dword ptr [0x55e718]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5629720) /* 0x55e718 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049e36f  7d23                   -jge 0x49e394
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049e394;
    }
    // 0049e371  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0049e378  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049e37a  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049e37d  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049e37f  3b1c8534e75500         +cmp ebx, dword ptr [eax*4 + 0x55e734]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5629748) /* 0x55e734 */ + cpu.eax * 4)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049e386  7509                   -jne 0x49e391
    if (!cpu.flags.zf)
    {
        goto L_0x0049e391;
    }
    // 0049e388  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049e38d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e38e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e38f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e390  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049e391:
    // 0049e391  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0049e392  ebd5                   -jmp 0x49e369
    goto L_0x0049e369;
L_0x0049e394:
    // 0049e394  e8b70d0000             -call 0x49f150
    cpu.esp -= 4;
    sub_49f150(app, cpu);
    if (cpu.terminate) return;
    // 0049e399  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0049e39b:
    // 0049e39b  3b1518e75500           +cmp edx, dword ptr [0x55e718]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5629720) /* 0x55e718 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049e3a1  7d23                   -jge 0x49e3c6
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049e3c6;
    }
    // 0049e3a3  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0049e3aa  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049e3ac  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049e3af  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049e3b1  3b1c8534e75500         +cmp ebx, dword ptr [eax*4 + 0x55e734]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5629748) /* 0x55e734 */ + cpu.eax * 4)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049e3b8  7509                   -jne 0x49e3c3
    if (!cpu.flags.zf)
    {
        goto L_0x0049e3c3;
    }
    // 0049e3ba  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049e3bf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e3c0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e3c1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e3c2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049e3c3:
    // 0049e3c3  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0049e3c4  ebd5                   -jmp 0x49e39b
    goto L_0x0049e39b;
L_0x0049e3c6:
    // 0049e3c6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049e3c8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e3c9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e3ca  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e3cb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_49e3d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049e3d0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049e3d1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049e3d2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049e3d3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049e3d5  83ec74                 -sub esp, 0x74
    (cpu.esp) -= x86::reg32(x86::sreg32(116 /*0x74*/));
    // 0049e3d8  8945ec                 -mov dword ptr [ebp - 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
    // 0049e3db  895df4                 -mov dword ptr [ebp - 0xc], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ebx;
    // 0049e3de  894de8                 -mov dword ptr [ebp - 0x18], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.ecx;
    // 0049e3e1  8d7dd8                 -lea edi, [ebp - 0x28]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 0049e3e4  be60e04900             -mov esi, 0x49e060
    cpu.esi = 4841568 /*0x49e060*/;
    // 0049e3e9  a06ae04900             -mov al, byte ptr [0x49e06a]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(4841578) /* 0x49e06a */);
    // 0049e3ee  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049e3f0  8845fc                 -mov byte ptr [ebp - 4], al
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.al;
    // 0049e3f3  66891d58e85500         -mov word ptr [0x55e858], bx
    app->getMemory<x86::reg16>(x86::reg32(5630040) /* 0x55e858 */) = cpu.bx;
    // 0049e3fa  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049e3fb  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049e3fc  66a5                   -movsw word ptr es:[edi], word ptr [esi]
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
    // 0049e3fe  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0049e401  8b5df4                 -mov ebx, dword ptr [ebp - 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0049e404  e8b70d0000             -call 0x49f1c0
    cpu.esp -= 4;
    sub_49f1c0(app, cpu);
    if (cpu.terminate) return;
    // 0049e409  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049e40b  a11ce75500             -mov eax, dword ptr [0x55e71c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5629724) /* 0x55e71c */);
    // 0049e410  39d8                   +cmp eax, ebx
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
    // 0049e412  7458                   -je 0x49e46c
    if (cpu.flags.zf)
    {
        goto L_0x0049e46c;
    }
    // 0049e414  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049e416  740a                   -je 0x49e422
    if (cpu.flags.zf)
    {
        goto L_0x0049e422;
    }
    // 0049e418  b890037a00             -mov eax, 0x7a0390
    cpu.eax = 7996304 /*0x7a0390*/;
    // 0049e41d  e83e6a0500             -call 0x4f4e60
    cpu.esp -= 4;
    sub_4f4e60(app, cpu);
    if (cpu.terminate) return;
L_0x0049e422:
    // 0049e422  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049e423  8d45d8                 -lea eax, [ebp - 0x28]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 0049e426  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049e427  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 0049e42e  bb68e85500             -mov ebx, 0x55e868
    cpu.ebx = 5630056 /*0x55e868*/;
    // 0049e433  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049e435  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0049e437  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049e43a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049e43c  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049e43e  b924e75500             -mov ecx, 0x55e724
    cpu.ecx = 5629732 /*0x55e724*/;
    // 0049e443  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049e446  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049e447  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049e449  b890037a00             -mov eax, 0x7a0390
    cpu.eax = 7996304 /*0x7a0390*/;
    // 0049e44e  83c118                 -add ecx, 0x18
    (cpu.ecx) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0049e451  893d1ce75500           -mov dword ptr [0x55e71c], edi
    app->getMemory<x86::reg32>(x86::reg32(5629724) /* 0x55e71c */) = cpu.edi;
    // 0049e457  e8b4680500             -call 0x4f4d10
    cpu.esp -= 4;
    sub_4f4d10(app, cpu);
    if (cpu.terminate) return;
    // 0049e45c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049e45e  0f847f010000           -je 0x49e5e3
    if (cpu.flags.zf)
    {
        goto L_0x0049e5e3;
    }
    // 0049e464  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0049e467  a31ce75500             -mov dword ptr [0x55e71c], eax
    app->getMemory<x86::reg32>(x86::reg32(5629724) /* 0x55e71c */) = cpu.eax;
L_0x0049e46c:
    // 0049e46c  b8e0fc7900             -mov eax, 0x79fce0
    cpu.eax = 7994592 /*0x79fce0*/;
    // 0049e471  8b55e8                 -mov edx, dword ptr [ebp - 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 0049e474  a35ce85500             -mov dword ptr [0x55e85c], eax
    app->getMemory<x86::reg32>(x86::reg32(5630044) /* 0x55e85c */) = cpu.eax;
    // 0049e479  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049e47b  740f                   -je 0x49e48c
    if (cpu.flags.zf)
    {
        goto L_0x0049e48c;
    }
    // 0049e47d  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 0049e482  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 0049e485  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049e487  e894900400             -call 0x4e7520
    cpu.esp -= 4;
    sub_4e7520(app, cpu);
    if (cpu.terminate) return;
L_0x0049e48c:
    // 0049e48c  8d4dfc                 -lea ecx, [ebp - 4]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0049e48f  8b5dec                 -mov ebx, dword ptr [ebp - 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0049e492  ba80f34900             -mov edx, 0x49f380
    cpu.edx = 4846464 /*0x49f380*/;
    // 0049e497  b890037a00             -mov eax, 0x7a0390
    cpu.eax = 7996304 /*0x7a0390*/;
    // 0049e49c  e80f6a0500             -call 0x4f4eb0
    cpu.esp -= 4;
    sub_4f4eb0(app, cpu);
    if (cpu.terminate) return;
    // 0049e4a1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049e4a3  7517                   -jne 0x49e4bc
    if (!cpu.flags.zf)
    {
        goto L_0x0049e4bc;
    }
    // 0049e4a5  8b4de8                 -mov ecx, dword ptr [ebp - 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 0049e4a8  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049e4aa  0f8433010000           -je 0x49e5e3
    if (cpu.flags.zf)
    {
        goto L_0x0049e5e3;
    }
    // 0049e4b0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049e4b2  e829910400             -call 0x4e75e0
    cpu.esp -= 4;
    sub_4e75e0(app, cpu);
    if (cpu.terminate) return;
    // 0049e4b7  e927010000             -jmp 0x49e5e3
    goto L_0x0049e5e3;
L_0x0049e4bc:
    // 0049e4bc  8b5de8                 -mov ebx, dword ptr [ebp - 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 0049e4bf  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049e4c1  7407                   -je 0x49e4ca
    if (cpu.flags.zf)
    {
        goto L_0x0049e4ca;
    }
    // 0049e4c3  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049e4c5  e816910400             -call 0x4e75e0
    cpu.esp -= 4;
    sub_4e75e0(app, cpu);
    if (cpu.terminate) return;
L_0x0049e4ca:
    // 0049e4ca  66833d58e8550001       +cmp word ptr [0x55e858], 1
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(5630040) /* 0x55e858 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(1 /*0x1*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0049e4d2  0f8e0b010000           -jle 0x49e5e3
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049e5e3;
    }
    // 0049e4d8  a156e85500             -mov eax, dword ptr [0x55e856]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5630038) /* 0x55e856 */);
    // 0049e4dd  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0049e4e0  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049e4e2  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
L_0x0049e4e5:
    // 0049e4e5  3b5df0                 +cmp ebx, dword ptr [ebp - 0x10]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049e4e8  0f8df5000000           -jge 0x49e5e3
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049e5e3;
    }
    // 0049e4ee  8d7dcc                 -lea edi, [ebp - 0x34]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 0049e4f1  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049e4f3  8b155ce85500           -mov edx, dword ptr [0x55e85c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5630044) /* 0x55e85c */);
    // 0049e4f9  c1e006                 -shl eax, 6
    cpu.eax <<= 6 /*0x6*/ % 32;
    // 0049e4fc  895df8                 -mov dword ptr [ebp - 8], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ebx;
    // 0049e4ff  8d3402                 -lea esi, [edx + eax]
    cpu.esi = x86::reg32(cpu.edx + cpu.eax * 1);
    // 0049e502  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0049e504  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0049e505:
    // 0049e505  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0049e507  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0049e509  3c00                   +cmp al, 0
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
    // 0049e50b  7410                   -je 0x49e51d
    if (cpu.flags.zf)
    {
        goto L_0x0049e51d;
    }
    // 0049e50d  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0049e510  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049e513  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0049e516  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049e519  3c00                   +cmp al, 0
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
    // 0049e51b  75e8                   -jne 0x49e505
    if (!cpu.flags.zf)
    {
        goto L_0x0049e505;
    }
L_0x0049e51d:
    // 0049e51d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0049e51e:
    // 0049e51e  3b4df0                 +cmp ecx, dword ptr [ebp - 0x10]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049e521  7d43                   -jge 0x49e566
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049e566;
    }
    // 0049e523  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0049e525  8b155ce85500           -mov edx, dword ptr [0x55e85c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5630044) /* 0x55e85c */);
    // 0049e52b  c1e606                 -shl esi, 6
    cpu.esi <<= 6 /*0x6*/ % 32;
    // 0049e52e  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 0049e531  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0049e533  e8d8fd0400             -call 0x4ee310
    cpu.esp -= 4;
    sub_4ee310(app, cpu);
    if (cpu.terminate) return;
    // 0049e538  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049e53a  7e27                   -jle 0x49e563
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049e563;
    }
    // 0049e53c  a15ce85500             -mov eax, dword ptr [0x55e85c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5630044) /* 0x55e85c */);
    // 0049e541  8d7dcc                 -lea edi, [ebp - 0x34]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 0049e544  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049e546  894df8                 -mov dword ptr [ebp - 8], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ecx;
    // 0049e549  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0049e54a:
    // 0049e54a  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0049e54c  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0049e54e  3c00                   +cmp al, 0
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
    // 0049e550  7410                   -je 0x49e562
    if (cpu.flags.zf)
    {
        goto L_0x0049e562;
    }
    // 0049e552  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0049e555  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049e558  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0049e55b  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049e55e  3c00                   +cmp al, 0
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
    // 0049e560  75e8                   -jne 0x49e54a
    if (!cpu.flags.zf)
    {
        goto L_0x0049e54a;
    }
L_0x0049e562:
    // 0049e562  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0049e563:
    // 0049e563  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0049e564  ebb8                   -jmp 0x49e51e
    goto L_0x0049e51e;
L_0x0049e566:
    // 0049e566  3b5df8                 +cmp ebx, dword ptr [ebp - 8]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049e569  7472                   -je 0x49e5dd
    if (cpu.flags.zf)
    {
        goto L_0x0049e5dd;
    }
    // 0049e56b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049e56d  c1e006                 -shl eax, 6
    cpu.eax <<= 6 /*0x6*/ % 32;
    // 0049e570  b940000000             -mov ecx, 0x40
    cpu.ecx = 64 /*0x40*/;
    // 0049e575  8945e4                 -mov dword ptr [ebp - 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.eax;
    // 0049e578  8d7d8c                 -lea edi, [ebp - 0x74]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-116) /* -0x74 */);
    // 0049e57b  8b75e4                 -mov esi, dword ptr [ebp - 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 0049e57e  a15ce85500             -mov eax, dword ptr [0x55e85c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5630044) /* 0x55e85c */);
    // 0049e583  8b55f8                 -mov edx, dword ptr [ebp - 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0049e586  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049e588  c1e206                 -shl edx, 6
    cpu.edx <<= 6 /*0x6*/ % 32;
    // 0049e58b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049e58c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049e58e  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0049e591  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049e593  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0049e595  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0049e598  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0049e59a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e59b  a15ce85500             -mov eax, dword ptr [0x55e85c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5630044) /* 0x55e85c */);
    // 0049e5a0  8b7de4                 -mov edi, dword ptr [ebp - 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 0049e5a3  8d3410                 -lea esi, [eax + edx]
    cpu.esi = x86::reg32(cpu.eax + cpu.edx * 1);
    // 0049e5a6  b940000000             -mov ecx, 0x40
    cpu.ecx = 64 /*0x40*/;
    // 0049e5ab  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049e5ad  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049e5ae  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049e5b0  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0049e5b3  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049e5b5  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0049e5b7  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0049e5ba  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0049e5bc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e5bd  b940000000             -mov ecx, 0x40
    cpu.ecx = 64 /*0x40*/;
    // 0049e5c2  a15ce85500             -mov eax, dword ptr [0x55e85c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5630044) /* 0x55e85c */);
    // 0049e5c7  8d758c                 -lea esi, [ebp - 0x74]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-116) /* -0x74 */);
    // 0049e5ca  8d3c10                 -lea edi, [eax + edx]
    cpu.edi = x86::reg32(cpu.eax + cpu.edx * 1);
    // 0049e5cd  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049e5ce  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049e5d0  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0049e5d3  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049e5d5  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0049e5d7  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0049e5da  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0049e5dc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0049e5dd:
    // 0049e5dd  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0049e5de  e902ffffff             -jmp 0x49e4e5
    goto L_0x0049e4e5;
L_0x0049e5e3:
    // 0049e5e3  b858e85500             -mov eax, 0x55e858
    cpu.eax = 5630040 /*0x55e858*/;
    // 0049e5e8  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0049e5ea  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e5eb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e5ec  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e5ed  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_49e5f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049e5f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049e5f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049e5f2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049e5f3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049e5f4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049e5f5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049e5f7  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0049e5fa  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049e5fc  8955f8                 -mov dword ptr [ebp - 8], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edx;
    // 0049e5ff  a06be04900             -mov al, byte ptr [0x49e06b]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(4841579) /* 0x49e06b */);
    // 0049e604  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 0049e609  8845fc                 -mov byte ptr [ebp - 4], al
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.al;
    // 0049e60c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049e60e  bf15227a00             -mov edi, 0x7a2215
    cpu.edi = 8004117 /*0x7a2215*/;
    // 0049e613  e8a80b0000             -call 0x49f1c0
    cpu.esp -= 4;
    sub_49f1c0(app, cpu);
    if (cpu.terminate) return;
    // 0049e618  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049e61a  e8010f0000             -call 0x49f520
    cpu.esp -= 4;
    sub_49f520(app, cpu);
    if (cpu.terminate) return;
    // 0049e61f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049e624  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 0049e629  e8627d0000             -call 0x4a6390
    cpu.esp -= 4;
    sub_4a6390(app, cpu);
    if (cpu.terminate) return;
    // 0049e62e  b401                   -mov ah, 1
    cpu.ah = 1 /*0x1*/;
    // 0049e630  8915e0227a00           -mov dword ptr [0x7a22e0], edx
    app->getMemory<x86::reg32>(x86::reg32(8004320) /* 0x7a22e0 */) = cpu.edx;
    // 0049e636  66893576227a00         -mov word ptr [0x7a2276], si
    app->getMemory<x86::reg16>(x86::reg32(8004214) /* 0x7a2276 */) = cpu.si;
    // 0049e63d  882514227a00           -mov byte ptr [0x7a2214], ah
    app->getMemory<x86::reg8>(x86::reg32(8004116) /* 0x7a2214 */) = cpu.ah;
    // 0049e643  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049e645  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0049e647  66891578227a00         -mov word ptr [0x7a2278], dx
    app->getMemory<x86::reg16>(x86::reg32(8004216) /* 0x7a2278 */) = cpu.dx;
    // 0049e64e  6689157a227a00         -mov word ptr [0x7a227a], dx
    app->getMemory<x86::reg16>(x86::reg32(8004218) /* 0x7a227a */) = cpu.dx;
    // 0049e655  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0049e656:
    // 0049e656  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0049e658  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0049e65a  3c00                   +cmp al, 0
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
    // 0049e65c  7410                   -je 0x49e66e
    if (cpu.flags.zf)
    {
        goto L_0x0049e66e;
    }
    // 0049e65e  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0049e661  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049e664  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0049e667  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049e66a  3c00                   +cmp al, 0
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
    // 0049e66c  75e8                   -jne 0x49e656
    if (!cpu.flags.zf)
    {
        goto L_0x0049e656;
    }
L_0x0049e66e:
    // 0049e66e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e66f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049e674  eb06                   -jmp 0x49e67c
    goto L_0x0049e67c;
L_0x0049e676:
    // 0049e676  663d0800               +cmp ax, 8
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(8 /*0x8*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0049e67a  7d13                   -jge 0x49e68f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049e68f;
    }
L_0x0049e67c:
    // 0049e67c  beffffffff             -mov esi, 0xffffffff
    cpu.esi = 4294967295 /*0xffffffff*/;
    // 0049e681  0fbfd0                 -movsx edx, ax
    cpu.edx = x86::reg32(static_cast<x86::sreg16>(cpu.ax));
    // 0049e684  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0049e685  668934557a227a00       -mov word ptr [edx*2 + 0x7a227a], si
    app->getMemory<x86::reg16>(x86::reg32(8004218) /* 0x7a227a */ + cpu.edx * 2) = cpu.si;
    // 0049e68d  ebe7                   -jmp 0x49e676
    goto L_0x0049e676;
L_0x0049e68f:
    // 0049e68f  bf3c047a00             -mov edi, 0x7a043c
    cpu.edi = 7996476 /*0x7a043c*/;
    // 0049e694  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0049e696  e8b50f0000             -call 0x49f650
    cpu.esp -= 4;
    sub_49f650(app, cpu);
    if (cpu.terminate) return;
    // 0049e69b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0049e69c:
    // 0049e69c  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0049e69e  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0049e6a0  3c00                   +cmp al, 0
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
    // 0049e6a2  7410                   -je 0x49e6b4
    if (cpu.flags.zf)
    {
        goto L_0x0049e6b4;
    }
    // 0049e6a4  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0049e6a7  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049e6aa  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0049e6ad  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049e6b0  3c00                   +cmp al, 0
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
    // 0049e6b2  75e8                   -jne 0x49e69c
    if (!cpu.flags.zf)
    {
        goto L_0x0049e69c;
    }
L_0x0049e6b4:
    // 0049e6b4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e6b5  833de4227a0000         +cmp dword ptr [0x7a22e4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(8004324) /* 0x7a22e4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049e6bc  750c                   -jne 0x49e6ca
    if (!cpu.flags.zf)
    {
        goto L_0x0049e6ca;
    }
    // 0049e6be  c7056c047a0002000000   -mov dword ptr [0x7a046c], 2
    app->getMemory<x86::reg32>(x86::reg32(7996524) /* 0x7a046c */) = 2 /*0x2*/;
    // 0049e6c8  eb0a                   -jmp 0x49e6d4
    goto L_0x0049e6d4;
L_0x0049e6ca:
    // 0049e6ca  c7056c047a0008000000   -mov dword ptr [0x7a046c], 8
    app->getMemory<x86::reg32>(x86::reg32(7996524) /* 0x7a046c */) = 8 /*0x8*/;
L_0x0049e6d4:
    // 0049e6d4  8b151ce75500           -mov edx, dword ptr [0x55e71c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5629724) /* 0x55e71c */);
    // 0049e6da  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049e6dc  740a                   -je 0x49e6e8
    if (cpu.flags.zf)
    {
        goto L_0x0049e6e8;
    }
    // 0049e6de  b890037a00             -mov eax, 0x7a0390
    cpu.eax = 7996304 /*0x7a0390*/;
    // 0049e6e3  e878670500             -call 0x4f4e60
    cpu.esp -= 4;
    sub_4f4e60(app, cpu);
    if (cpu.terminate) return;
L_0x0049e6e8:
    // 0049e6e8  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 0049e6ef  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049e6f1  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049e6f4  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0049e6f6  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049e6f8  89351ce75500           -mov dword ptr [0x55e71c], esi
    app->getMemory<x86::reg32>(x86::reg32(5629724) /* 0x55e71c */) = cpu.esi;
    // 0049e6fe  833c8538e7550000       +cmp dword ptr [eax*4 + 0x55e738], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5629752) /* 0x55e738 */ + cpu.eax * 4);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049e706  7404                   -je 0x49e70c
    if (cpu.flags.zf)
    {
        goto L_0x0049e70c;
    }
    // 0049e708  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0049e70a  eb0a                   -jmp 0x49e716
    goto L_0x0049e716;
L_0x0049e70c:
    // 0049e70c  b806040000             -mov eax, 0x406
    cpu.eax = 1030 /*0x406*/;
    // 0049e711  beb0f44900             -mov esi, 0x49f4b0
    cpu.esi = 4846768 /*0x49f4b0*/;
L_0x0049e716:
    // 0049e716  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049e717  8d3c9d00000000         -lea edi, [ebx*4]
    cpu.edi = x86::reg32(cpu.ebx * 4);
    // 0049e71e  8d55ec                 -lea edx, [ebp - 0x14]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0049e721  29df                   -sub edi, ebx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049e723  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049e724  c1e702                 -shl edi, 2
    cpu.edi <<= 2 /*0x2*/ % 32;
    // 0049e727  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049e728  29df                   -sub edi, ebx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049e72a  b824e75500             -mov eax, 0x55e724
    cpu.eax = 5629732 /*0x55e724*/;
    // 0049e72f  c1e702                 -shl edi, 2
    cpu.edi <<= 2 /*0x2*/ % 32;
    // 0049e732  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 0049e734  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0049e736  8d4818                 -lea ecx, [eax + 0x18]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0049e739  bb68e85500             -mov ebx, 0x55e868
    cpu.ebx = 5630056 /*0x55e868*/;
    // 0049e73e  b890037a00             -mov eax, 0x7a0390
    cpu.eax = 7996304 /*0x7a0390*/;
    // 0049e743  e8c8650500             -call 0x4f4d10
    cpu.esp -= 4;
    sub_4f4d10(app, cpu);
    if (cpu.terminate) return;
    // 0049e748  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049e74a  7518                   -jne 0x49e764
    if (!cpu.flags.zf)
    {
        goto L_0x0049e764;
    }
    // 0049e74c  b8c2000000             -mov eax, 0xc2
    cpu.eax = 194 /*0xc2*/;
    // 0049e751  e88a64faff             -call 0x444be0
    cpu.esp -= 4;
    sub_444be0(app, cpu);
    if (cpu.terminate) return;
    // 0049e756  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049e758  e8337c0000             -call 0x4a6390
    cpu.esp -= 4;
    sub_4a6390(app, cpu);
    if (cpu.terminate) return;
    // 0049e75d  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0049e75f  e986000000             -jmp 0x49e7ea
    goto L_0x0049e7ea;
L_0x0049e764:
    // 0049e764  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0049e767  a31ce75500             -mov dword ptr [0x55e71c], eax
    app->getMemory<x86::reg32>(x86::reg32(5629724) /* 0x55e71c */) = cpu.eax;
    // 0049e76c  e88f7d0000             -call 0x4a6500
    cpu.esp -= 4;
    sub_4a6500(app, cpu);
    if (cpu.terminate) return;
    // 0049e771  e81af0f8ff             -call 0x42d790
    cpu.esp -= 4;
    sub_42d790(app, cpu);
    if (cpu.terminate) return;
    // 0049e776  8b8738e75500           -mov eax, dword ptr [edi + 0x55e738]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5629752) /* 0x55e738 */);
    // 0049e77c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049e77e  745d                   -je 0x49e7dd
    if (cpu.flags.zf)
    {
        goto L_0x0049e7dd;
    }
    // 0049e780  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 0049e785  b970f44900             -mov ecx, 0x49f470
    cpu.ecx = 4846704 /*0x49f470*/;
    // 0049e78a  8d5dfc                 -lea ebx, [ebp - 4]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0049e78d  b890037a00             -mov eax, 0x7a0390
    cpu.eax = 7996304 /*0x7a0390*/;
    // 0049e792  8915f4435600           -mov dword ptr [0x5643f4], edx
    app->getMemory<x86::reg32>(x86::reg32(5653492) /* 0x5643f4 */) = cpu.edx;
    // 0049e798  ba3c047a00             -mov edx, 0x7a043c
    cpu.edx = 7996476 /*0x7a043c*/;
    // 0049e79d  e86e670500             -call 0x4f4f10
    cpu.esp -= 4;
    sub_4f4f10(app, cpu);
    if (cpu.terminate) return;
    // 0049e7a2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049e7a4  752f                   -jne 0x49e7d5
    if (!cpu.flags.zf)
    {
        goto L_0x0049e7d5;
    }
    // 0049e7a6  a3f4435600             -mov dword ptr [0x5643f4], eax
    app->getMemory<x86::reg32>(x86::reg32(5653492) /* 0x5643f4 */) = cpu.eax;
    // 0049e7ab  b8c2000000             -mov eax, 0xc2
    cpu.eax = 194 /*0xc2*/;
    // 0049e7b0  e82b64faff             -call 0x444be0
    cpu.esp -= 4;
    sub_444be0(app, cpu);
    if (cpu.terminate) return;
    // 0049e7b5  e8c66a0500             -call 0x4f5280
    cpu.esp -= 4;
    sub_4f5280(app, cpu);
    if (cpu.terminate) return;
    // 0049e7ba  e831f0f8ff             -call 0x42d7f0
    cpu.esp -= 4;
    sub_42d7f0(app, cpu);
    if (cpu.terminate) return;
    // 0049e7bf  e80cbdffff             -call 0x49a4d0
    cpu.esp -= 4;
    sub_49a4d0(app, cpu);
    if (cpu.terminate) return;
    // 0049e7c4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049e7c6  e8c57b0000             -call 0x4a6390
    cpu.esp -= 4;
    sub_4a6390(app, cpu);
    if (cpu.terminate) return;
    // 0049e7cb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049e7cd  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0049e7cf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e7d0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e7d1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e7d2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e7d3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e7d4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049e7d5:
    // 0049e7d5  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049e7d7  891df4435600           -mov dword ptr [0x5643f4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5653492) /* 0x5643f4 */) = cpu.ebx;
L_0x0049e7dd:
    // 0049e7dd  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 0049e7e2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049e7e4  893560e85500           -mov dword ptr [0x55e860], esi
    app->getMemory<x86::reg32>(x86::reg32(5630048) /* 0x55e860 */) = cpu.esi;
L_0x0049e7ea:
    // 0049e7ea  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0049e7ec  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e7ed  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e7ee  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e7ef  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e7f0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e7f1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_49e800(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049e800  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049e801  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049e802  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049e803  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049e804  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049e805  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049e806  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049e808  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049e80b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049e80d  a06ce04900             -mov al, byte ptr [0x49e06c]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(4841580) /* 0x49e06c */);
    // 0049e812  8845fc                 -mov byte ptr [ebp - 4], al
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.al;
    // 0049e815  a11ce75500             -mov eax, dword ptr [0x55e71c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5629724) /* 0x55e71c */);
    // 0049e81a  e8a1090000             -call 0x49f1c0
    cpu.esp -= 4;
    sub_49f1c0(app, cpu);
    if (cpu.terminate) return;
    // 0049e81f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049e821  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049e826  e8657b0000             -call 0x4a6390
    cpu.esp -= 4;
    sub_4a6390(app, cpu);
    if (cpu.terminate) return;
    // 0049e82b  c60514227a0001         -mov byte ptr [0x7a2214], 1
    app->getMemory<x86::reg8>(x86::reg32(8004116) /* 0x7a2214 */) = 1 /*0x1*/;
    // 0049e832  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049e834  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049e837  bbfeffffff             -mov ebx, 0xfffffffe
    cpu.ebx = 4294967294 /*0xfffffffe*/;
    // 0049e83c  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049e83e  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0049e840  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049e843  66891d78227a00         -mov word ptr [0x7a2278], bx
    app->getMemory<x86::reg16>(x86::reg32(8004216) /* 0x7a2278 */) = cpu.bx;
    // 0049e84a  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049e84c  668935da227a00         -mov word ptr [0x7a22da], si
    app->getMemory<x86::reg16>(x86::reg32(8004314) /* 0x7a22da */) = cpu.si;
    // 0049e853  bb03000000             -mov ebx, 3
    cpu.ebx = 3 /*0x3*/;
    // 0049e858  8b348538e75500         -mov esi, dword ptr [eax*4 + 0x55e738]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5629752) /* 0x55e738 */ + cpu.eax * 4);
    // 0049e85f  891de0227a00           -mov dword ptr [0x7a22e0], ebx
    app->getMemory<x86::reg32>(x86::reg32(8004320) /* 0x7a22e0 */) = cpu.ebx;
    // 0049e865  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049e867  744e                   -je 0x49e8b7
    if (cpu.flags.zf)
    {
        goto L_0x0049e8b7;
    }
    // 0049e869  8d5dfc                 -lea ebx, [ebp - 4]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0049e86c  b890037a00             -mov eax, 0x7a0390
    cpu.eax = 7996304 /*0x7a0390*/;
    // 0049e871  e85a660500             -call 0x4f4ed0
    cpu.esp -= 4;
    sub_4f4ed0(app, cpu);
    if (cpu.terminate) return;
    // 0049e876  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049e878  7f18                   -jg 0x49e892
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049e892;
    }
    // 0049e87a  b8c2000000             -mov eax, 0xc2
    cpu.eax = 194 /*0xc2*/;
    // 0049e87f  e85c63faff             -call 0x444be0
    cpu.esp -= 4;
    sub_444be0(app, cpu);
    if (cpu.terminate) return;
    // 0049e884  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049e886  e8057b0000             -call 0x4a6390
    cpu.esp -= 4;
    sub_4a6390(app, cpu);
    if (cpu.terminate) return;
    // 0049e88b  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0049e88d  e930010000             -jmp 0x49e9c2
    goto L_0x0049e9c2;
L_0x0049e892:
    // 0049e892  833d34047a0000         +cmp dword ptr [0x7a0434], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7996468) /* 0x7a0434 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049e899  751c                   -jne 0x49e8b7
    if (!cpu.flags.zf)
    {
        goto L_0x0049e8b7;
    }
    // 0049e89b  e8107d0000             -call 0x4a65b0
    cpu.esp -= 4;
    sub_4a65b0(app, cpu);
    if (cpu.terminate) return;
    // 0049e8a0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049e8a2  74ee                   -je 0x49e892
    if (cpu.flags.zf)
    {
        goto L_0x0049e892;
    }
    // 0049e8a4  e827060000             -call 0x49eed0
    cpu.esp -= 4;
    sub_49eed0(app, cpu);
    if (cpu.terminate) return;
    // 0049e8a9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049e8ab  e8e07a0000             -call 0x4a6390
    cpu.esp -= 4;
    sub_4a6390(app, cpu);
    if (cpu.terminate) return;
    // 0049e8b0  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0049e8b2  e90b010000             -jmp 0x49e9c2
    goto L_0x0049e9c2;
L_0x0049e8b7:
    // 0049e8b7  e8447c0000             -call 0x4a6500
    cpu.esp -= 4;
    sub_4a6500(app, cpu);
    if (cpu.terminate) return;
    // 0049e8bc  b8ac037a00             -mov eax, 0x7a03ac
    cpu.eax = 7996332 /*0x7a03ac*/;
    // 0049e8c1  b990037a00             -mov ecx, 0x7a0390
    cpu.ecx = 7996304 /*0x7a0390*/;
    // 0049e8c6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049e8c8  bb07000000             -mov ebx, 7
    cpu.ebx = 7 /*0x7*/;
    // 0049e8cd  e8de060000             -call 0x49efb0
    cpu.esp -= 4;
    sub_49efb0(app, cpu);
    if (cpu.terminate) return;
    // 0049e8d2  bad2000000             -mov edx, 0xd2
    cpu.edx = 210 /*0xd2*/;
    // 0049e8d7  e8746f0500             -call 0x4f5850
    cpu.esp -= 4;
    sub_4f5850(app, cpu);
    if (cpu.terminate) return;
    // 0049e8dc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049e8de  753f                   -jne 0x49e91f
    if (!cpu.flags.zf)
    {
        goto L_0x0049e91f;
    }
    // 0049e8e0  b8c2000000             -mov eax, 0xc2
    cpu.eax = 194 /*0xc2*/;
    // 0049e8e5  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 0049e8ea  e8f162faff             -call 0x444be0
    cpu.esp -= 4;
    sub_444be0(app, cpu);
    if (cpu.terminate) return;
    // 0049e8ef  66893ddc227a00         -mov word ptr [0x7a22dc], di
    app->getMemory<x86::reg16>(x86::reg32(8004316) /* 0x7a22dc */) = cpu.di;
    // 0049e8f6  e8d5050000             -call 0x49eed0
    cpu.esp -= 4;
    sub_49eed0(app, cpu);
    if (cpu.terminate) return;
    // 0049e8fb  e880690500             -call 0x4f5280
    cpu.esp -= 4;
    sub_4f5280(app, cpu);
    if (cpu.terminate) return;
    // 0049e900  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049e902  66a3dc227a00           -mov word ptr [0x7a22dc], ax
    app->getMemory<x86::reg16>(x86::reg32(8004316) /* 0x7a22dc */) = cpu.ax;
    // 0049e908  e8c3bbffff             -call 0x49a4d0
    cpu.esp -= 4;
    sub_49a4d0(app, cpu);
    if (cpu.terminate) return;
    // 0049e90d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049e90f  e87c7a0000             -call 0x4a6390
    cpu.esp -= 4;
    sub_4a6390(app, cpu);
    if (cpu.terminate) return;
    // 0049e914  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049e916  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0049e918  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e919  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e91a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e91b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e91c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e91d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e91e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049e91f:
    // 0049e91f  66833d96227a0000       +cmp word ptr [0x7a2296], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(8004246) /* 0x7a2296 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0049e927  7547                   -jne 0x49e970
    if (!cpu.flags.zf)
    {
        goto L_0x0049e970;
    }
    // 0049e929  e8827c0000             -call 0x4a65b0
    cpu.esp -= 4;
    sub_4a65b0(app, cpu);
    if (cpu.terminate) return;
    // 0049e92e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049e930  750a                   -jne 0x49e93c
    if (!cpu.flags.zf)
    {
        goto L_0x0049e93c;
    }
    // 0049e932  66833ddc227a0000       +cmp word ptr [0x7a22dc], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(8004316) /* 0x7a22dc */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0049e93a  74e3                   -je 0x49e91f
    if (cpu.flags.zf)
    {
        goto L_0x0049e91f;
    }
L_0x0049e93c:
    // 0049e93c  b8c2000000             -mov eax, 0xc2
    cpu.eax = 194 /*0xc2*/;
    // 0049e941  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0049e946  e89562faff             -call 0x444be0
    cpu.esp -= 4;
    sub_444be0(app, cpu);
    if (cpu.terminate) return;
    // 0049e94b  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0049e94d  66890ddc227a00         -mov word ptr [0x7a22dc], cx
    app->getMemory<x86::reg16>(x86::reg32(8004316) /* 0x7a22dc */) = cpu.cx;
    // 0049e954  e827690500             -call 0x4f5280
    cpu.esp -= 4;
    sub_4f5280(app, cpu);
    if (cpu.terminate) return;
    // 0049e959  668935dc227a00         -mov word ptr [0x7a22dc], si
    app->getMemory<x86::reg16>(x86::reg32(8004316) /* 0x7a22dc */) = cpu.si;
    // 0049e960  e87b7c0000             -call 0x4a65e0
    cpu.esp -= 4;
    sub_4a65e0(app, cpu);
    if (cpu.terminate) return;
    // 0049e965  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049e967  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0049e969  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e96a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e96b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e96c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e96d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e96e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e96f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049e970:
    // 0049e970  a18c227a00             -mov eax, dword ptr [0x7a228c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8004236) /* 0x7a228c */);
    // 0049e975  a3e4227a00             -mov dword ptr [0x7a22e4], eax
    app->getMemory<x86::reg32>(x86::reg32(8004324) /* 0x7a22e4 */) = cpu.eax;
    // 0049e97a  e811eef8ff             -call 0x42d790
    cpu.esp -= 4;
    sub_42d790(app, cpu);
    if (cpu.terminate) return;
    // 0049e97f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049e981  e85a830000             -call 0x4a6ce0
    cpu.esp -= 4;
    sub_4a6ce0(app, cpu);
    if (cpu.terminate) return;
    // 0049e986  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049e988  7533                   -jne 0x49e9bd
    if (!cpu.flags.zf)
    {
        goto L_0x0049e9bd;
    }
    // 0049e98a  b8c2000000             -mov eax, 0xc2
    cpu.eax = 194 /*0xc2*/;
    // 0049e98f  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 0049e994  e84762faff             -call 0x444be0
    cpu.esp -= 4;
    sub_444be0(app, cpu);
    if (cpu.terminate) return;
    // 0049e999  66893ddc227a00         -mov word ptr [0x7a22dc], di
    app->getMemory<x86::reg16>(x86::reg32(8004316) /* 0x7a22dc */) = cpu.di;
    // 0049e9a0  e8db680500             -call 0x4f5280
    cpu.esp -= 4;
    sub_4f5280(app, cpu);
    if (cpu.terminate) return;
    // 0049e9a5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049e9a7  66a3dc227a00           -mov word ptr [0x7a22dc], ax
    app->getMemory<x86::reg16>(x86::reg32(8004316) /* 0x7a22dc */) = cpu.ax;
    // 0049e9ad  e82e7c0000             -call 0x4a65e0
    cpu.esp -= 4;
    sub_4a65e0(app, cpu);
    if (cpu.terminate) return;
    // 0049e9b2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049e9b4  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0049e9b6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e9b7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e9b8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e9b9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e9ba  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e9bb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e9bc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049e9bd:
    // 0049e9bd  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0049e9c2:
    // 0049e9c2  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0049e9c4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e9c5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e9c6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e9c7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e9c8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e9c9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049e9ca  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_49e9d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049e9d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049e9d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049e9d2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049e9d3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049e9d4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049e9d5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049e9d6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049e9d8  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0049e9db  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049e9dd  8d7df4                 -lea edi, [ebp - 0xc]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0049e9e0  be6de04900             -mov esi, 0x49e06d
    cpu.esi = 4841581 /*0x49e06d*/;
    // 0049e9e5  8b0d1ce75500           -mov ecx, dword ptr [0x55e71c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5629724) /* 0x55e71c */);
    // 0049e9eb  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049e9ec  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049e9ed  66a5                   -movsw word ptr es:[edi], word ptr [esi]
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
    // 0049e9ef  83f902                 +cmp ecx, 2
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
    // 0049e9f2  746e                   -je 0x49ea62
    if (cpu.flags.zf)
    {
        goto L_0x0049ea62;
    }
    // 0049e9f4  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049e9f6  740a                   -je 0x49ea02
    if (cpu.flags.zf)
    {
        goto L_0x0049ea02;
    }
    // 0049e9f8  b890037a00             -mov eax, 0x7a0390
    cpu.eax = 7996304 /*0x7a0390*/;
    // 0049e9fd  e85e640500             -call 0x4f4e60
    cpu.esp -= 4;
    sub_4f4e60(app, cpu);
    if (cpu.terminate) return;
L_0x0049ea02:
    // 0049ea02  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049ea03  8d45f4                 -lea eax, [ebp - 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0049ea06  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049ea07  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0049ea09  6806040000             -push 0x406
    app->getMemory<x86::reg32>(cpu.esp-4) = 1030 /*0x406*/;
    cpu.esp -= 4;
    // 0049ea0e  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0049ea13  89351ce75500           -mov dword ptr [0x55e71c], esi
    app->getMemory<x86::reg32>(x86::reg32(5629724) /* 0x55e71c */) = cpu.esi;
    // 0049ea19  e8a2070000             -call 0x49f1c0
    cpu.esp -= 4;
    sub_49f1c0(app, cpu);
    if (cpu.terminate) return;
    // 0049ea1e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049ea20  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049ea23  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049ea25  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049ea28  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049ea2a  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049ea2d  0524e75500             -add eax, 0x55e724
    (cpu.eax) += x86::reg32(x86::sreg32(5629732 /*0x55e724*/));
    // 0049ea32  bb68e85500             -mov ebx, 0x55e868
    cpu.ebx = 5630056 /*0x55e868*/;
    // 0049ea37  8d4818                 -lea ecx, [eax + 0x18]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0049ea3a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049ea3c  b890037a00             -mov eax, 0x7a0390
    cpu.eax = 7996304 /*0x7a0390*/;
    // 0049ea41  e8ca620500             -call 0x4f4d10
    cpu.esp -= 4;
    sub_4f4d10(app, cpu);
    if (cpu.terminate) return;
    // 0049ea46  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049ea48  750e                   -jne 0x49ea58
    if (!cpu.flags.zf)
    {
        goto L_0x0049ea58;
    }
    // 0049ea4a  b8c2000000             -mov eax, 0xc2
    cpu.eax = 194 /*0xc2*/;
    // 0049ea4f  e88c61faff             -call 0x444be0
    cpu.esp -= 4;
    sub_444be0(app, cpu);
    if (cpu.terminate) return;
    // 0049ea54  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0049ea56  eb0f                   -jmp 0x49ea67
    goto L_0x0049ea67;
L_0x0049ea58:
    // 0049ea58  c7051ce7550002000000   -mov dword ptr [0x55e71c], 2
    app->getMemory<x86::reg32>(x86::reg32(5629724) /* 0x55e71c */) = 2 /*0x2*/;
L_0x0049ea62:
    // 0049ea62  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0049ea67:
    // 0049ea67  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0049ea69  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ea6a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ea6b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ea6c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ea6d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ea6e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ea6f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49ea70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049ea70  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049ea71  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049ea72  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049ea73  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049ea74  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049ea75  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049ea77  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0049ea79  833d1ce7550002         +cmp dword ptr [0x55e71c], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5629724) /* 0x55e71c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049ea80  7549                   -jne 0x49eacb
    if (!cpu.flags.zf)
    {
        goto L_0x0049eacb;
    }
    // 0049ea82  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049ea84  7447                   -je 0x49eacd
    if (cpu.flags.zf)
    {
        goto L_0x0049eacd;
    }
    // 0049ea86  b9ac037a00             -mov ecx, 0x7a03ac
    cpu.ecx = 7996332 /*0x7a03ac*/;
    // 0049ea8b  bb06040000             -mov ebx, 0x406
    cpu.ebx = 1030 /*0x406*/;
    // 0049ea90  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049ea92  b890037a00             -mov eax, 0x7a0390
    cpu.eax = 7996304 /*0x7a0390*/;
    // 0049ea97  e8b4650500             -call 0x4f5050
    cpu.esp -= 4;
    sub_4f5050(app, cpu);
    if (cpu.terminate) return;
    // 0049ea9c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049ea9e  7421                   -je 0x49eac1
    if (cpu.flags.zf)
    {
        goto L_0x0049eac1;
    }
    // 0049eaa0  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 0049eaa5  beac037a00             -mov esi, 0x7a03ac
    cpu.esi = 7996332 /*0x7a03ac*/;
    // 0049eaaa  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049eaab  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049eaad  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0049eab0  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049eab2  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0049eab4  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0049eab7  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0049eab9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049eaba  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049eabf  eb0c                   -jmp 0x49eacd
    goto L_0x0049eacd;
L_0x0049eac1:
    // 0049eac1  b8c2000000             -mov eax, 0xc2
    cpu.eax = 194 /*0xc2*/;
    // 0049eac6  e81561faff             -call 0x444be0
    cpu.esp -= 4;
    sub_444be0(app, cpu);
    if (cpu.terminate) return;
L_0x0049eacb:
    // 0049eacb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0049eacd:
    // 0049eacd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049eace  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049eacf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ead0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ead1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ead2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_49eae0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049eae0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049eae1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049eae2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049eae3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049eae4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049eae5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049eae6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049eae8  83ec24                 -sub esp, 0x24
    (cpu.esp) -= x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0049eaeb  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049eaed  668955fc               -mov word ptr [ebp - 4], dx
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.dx;
    // 0049eaf1  833de0227a0003         +cmp dword ptr [0x7a22e0], 3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(8004320) /* 0x7a22e0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049eaf8  7407                   -je 0x49eb01
    if (cpu.flags.zf)
    {
        goto L_0x0049eb01;
    }
    // 0049eafa  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0049eafc  e960010000             -jmp 0x49ec61
    goto L_0x0049ec61;
L_0x0049eb01:
    // 0049eb01  66833dda227a0000       +cmp word ptr [0x7a22da], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(8004314) /* 0x7a22da */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0049eb09  750e                   -jne 0x49eb19
    if (!cpu.flags.zf)
    {
        goto L_0x0049eb19;
    }
    // 0049eb0b  e8b07e0000             -call 0x4a69c0
    cpu.esp -= 4;
    sub_4a69c0(app, cpu);
    if (cpu.terminate) return;
    // 0049eb10  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0049eb12  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049eb13  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049eb14  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049eb15  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049eb16  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049eb17  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049eb18  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049eb19:
    // 0049eb19  833de4227a0002         +cmp dword ptr [0x7a22e4], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(8004324) /* 0x7a22e4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049eb20  7448                   -je 0x49eb6a
    if (cpu.flags.zf)
    {
        goto L_0x0049eb6a;
    }
    // 0049eb22  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0049eb24  eb1a                   -jmp 0x49eb40
    goto L_0x0049eb40;
L_0x0049eb26:
    // 0049eb26  05e8227a00             -add eax, 0x7a22e8
    (cpu.eax) += x86::reg32(x86::sreg32(8004328 /*0x7a22e8*/));
    // 0049eb2b  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0049eb30  e87b010000             -call 0x49ecb0
    cpu.esp -= 4;
    sub_49ecb0(app, cpu);
    if (cpu.terminate) return;
    // 0049eb35  66894dfc               -mov word ptr [ebp - 4], cx
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.cx;
L_0x0049eb39:
    // 0049eb39  42                     -inc edx
    (cpu.edx)++;
    // 0049eb3a  6683fa07               +cmp dx, 7
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(7 /*0x7*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0049eb3e  7d2a                   -jge 0x49eb6a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049eb6a;
    }
L_0x0049eb40:
    // 0049eb40  0fbfca                 -movsx ecx, dx
    cpu.ecx = x86::reg32(static_cast<x86::sreg16>(cpu.dx));
    // 0049eb43  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 0049eb4a  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049eb4c  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049eb4f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049eb51  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0049eb54  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049eb56  83b80c237a0000         +cmp dword ptr [eax + 0x7a230c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8004364) /* 0x7a230c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049eb5d  75da                   -jne 0x49eb39
    if (!cpu.flags.zf)
    {
        goto L_0x0049eb39;
    }
    // 0049eb5f  83b8f8227a0000         +cmp dword ptr [eax + 0x7a22f8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8004344) /* 0x7a22f8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049eb66  75be                   -jne 0x49eb26
    if (!cpu.flags.zf)
    {
        goto L_0x0049eb26;
    }
    // 0049eb68  ebcf                   -jmp 0x49eb39
    goto L_0x0049eb39;
L_0x0049eb6a:
    // 0049eb6a  e8110b0000             -call 0x49f680
    cpu.esp -= 4;
    sub_49f680(app, cpu);
    if (cpu.terminate) return;
    // 0049eb6f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049eb71  0f85cd000000           -jne 0x49ec44
    if (!cpu.flags.zf)
    {
        goto L_0x0049ec44;
    }
    // 0049eb77  8d45dc                 -lea eax, [ebp - 0x24]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 0049eb7a  e8b10b0000             -call 0x49f730
    cpu.esp -= 4;
    sub_49f730(app, cpu);
    if (cpu.terminate) return;
    // 0049eb7f  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0049eb81  eb07                   -jmp 0x49eb8a
    goto L_0x0049eb8a;
L_0x0049eb83:
    // 0049eb83  42                     -inc edx
    (cpu.edx)++;
    // 0049eb84  6683fa08               +cmp dx, 8
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(8 /*0x8*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0049eb88  7d4d                   -jge 0x49ebd7
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049ebd7;
    }
L_0x0049eb8a:
    // 0049eb8a  0fbff2                 -movsx esi, dx
    cpu.esi = x86::reg32(static_cast<x86::sreg16>(cpu.dx));
    // 0049eb8d  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 0049eb94  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0049eb96  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049eb99  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049eb9b  83bcc10c237a0000       +cmp dword ptr [ecx + eax*8 + 0x7a230c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8004364) /* 0x7a230c */ + cpu.eax * 8);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049eba3  75de                   -jne 0x49eb83
    if (!cpu.flags.zf)
    {
        goto L_0x0049eb83;
    }
    // 0049eba5  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 0049ebac  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0049ebae  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049ebb1  bfdc257a00             -mov edi, 0x7a25dc
    cpu.edi = 8005084 /*0x7a25dc*/;
    // 0049ebb6  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0049ebb8  8d75dc                 -lea esi, [ebp - 0x24]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 0049ebbb  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049ebbd  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0049ebbe:
    // 0049ebbe  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0049ebc0  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0049ebc2  3c00                   +cmp al, 0
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
    // 0049ebc4  7410                   -je 0x49ebd6
    if (cpu.flags.zf)
    {
        goto L_0x0049ebd6;
    }
    // 0049ebc6  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0049ebc9  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049ebcc  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0049ebcf  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049ebd2  3c00                   +cmp al, 0
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
    // 0049ebd4  75e8                   -jne 0x49ebbe
    if (!cpu.flags.zf)
    {
        goto L_0x0049ebbe;
    }
L_0x0049ebd6:
    // 0049ebd6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0049ebd7:
    // 0049ebd7  a1a4c17900             -mov eax, dword ptr [0x79c1a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7979428) /* 0x79c1a4 */);
    // 0049ebdc  0580020000             -add eax, 0x280
    (cpu.eax) += x86::reg32(x86::sreg32(640 /*0x280*/));
    // 0049ebe1  0fbfd2                 -movsx edx, dx
    cpu.edx = x86::reg32(static_cast<x86::sreg16>(cpu.dx));
    // 0049ebe4  a314e75500             -mov dword ptr [0x55e714], eax
    app->getMemory<x86::reg32>(x86::reg32(5629716) /* 0x55e714 */) = cpu.eax;
    // 0049ebe9  8d45e7                 -lea eax, [ebp - 0x19]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-25) /* -0x19 */);
    // 0049ebec  e8bf030000             -call 0x49efb0
    cpu.esp -= 4;
    sub_49efb0(app, cpu);
    if (cpu.terminate) return;
    // 0049ebf1  8b15e4227a00           -mov edx, dword ptr [0x7a22e4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(8004324) /* 0x7a22e4 */);
    // 0049ebf7  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049ebf9  83fa02                 +cmp edx, 2
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
    // 0049ebfc  7420                   -je 0x49ec1e
    if (cpu.flags.zf)
    {
        goto L_0x0049ec1e;
    }
    // 0049ebfe  b990037a00             -mov ecx, 0x7a0390
    cpu.ecx = 7996304 /*0x7a0390*/;
    // 0049ec03  bb07000000             -mov ebx, 7
    cpu.ebx = 7 /*0x7*/;
    // 0049ec08  bad2000000             -mov edx, 0xd2
    cpu.edx = 210 /*0xd2*/;
    // 0049ec0d  e83e6c0500             -call 0x4f5850
    cpu.esp -= 4;
    sub_4f5850(app, cpu);
    if (cpu.terminate) return;
    // 0049ec12  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049ec14  7508                   -jne 0x49ec1e
    if (!cpu.flags.zf)
    {
        goto L_0x0049ec1e;
    }
    // 0049ec16  ff0de0017a00           +dec dword ptr [0x7a01e0]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(7995872) /* 0x7a01e0 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0049ec1c  eb17                   -jmp 0x49ec35
    goto L_0x0049ec35;
L_0x0049ec1e:
    // 0049ec1e  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 0049ec23  66013d76227a00         +add word ptr [0x7a2276], di
    {
        auto tmp1 = app->getMemory<x86::reg16>(x86::reg32(8004214) /* 0x7a2276 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(cpu.di));
        x86::reg16 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) == (1 & (tmp2 >> 15));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049ec2a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049ec2c  66897dfc               -mov word ptr [ebp - 4], di
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.di;
    // 0049ec30  e8ab800000             -call 0x4a6ce0
    cpu.esp -= 4;
    sub_4a6ce0(app, cpu);
    if (cpu.terminate) return;
L_0x0049ec35:
    // 0049ec35  c70514e75500ffffff0f   -mov dword ptr [0x55e714], 0xfffffff
    app->getMemory<x86::reg32>(x86::reg32(5629716) /* 0x55e714 */) = 268435455 /*0xfffffff*/;
    // 0049ec3f  e926ffffff             -jmp 0x49eb6a
    goto L_0x0049eb6a;
L_0x0049ec44:
    // 0049ec44  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0049ec47  66a196227a00           -mov ax, word ptr [0x7a2296]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(8004246) /* 0x7a2296 */);
    // 0049ec4d  6609c2                 +or dx, ax
    cpu.clear_co();
    cpu.set_szp((cpu.dx |= x86::reg16(x86::sreg16(cpu.ax))));
    // 0049ec50  668955fc               -mov word ptr [ebp - 4], dx
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.dx;
    // 0049ec54  7405                   -je 0x49ec5b
    if (cpu.flags.zf)
    {
        goto L_0x0049ec5b;
    }
    // 0049ec56  e8657a0000             -call 0x4a66c0
    cpu.esp -= 4;
    sub_4a66c0(app, cpu);
    if (cpu.terminate) return;
L_0x0049ec5b:
    // 0049ec5b  8b45fa                 -mov eax, dword ptr [ebp - 6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-6) /* -0x6 */);
    // 0049ec5e  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
L_0x0049ec61:
    // 0049ec61  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0049ec63  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ec64  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ec65  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ec66  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ec67  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ec68  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ec69  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_49ec70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049ec70  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049ec71  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049ec72  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049ec73  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049ec74  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049ec76  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x0049ec7b:
    // 0049ec7b  3b1514d56f00           +cmp edx, dword ptr [0x6fd514]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(7329044) /* 0x6fd514 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049ec81  7d28                   -jge 0x49ecab
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049ecab;
    }
    // 0049ec83  8d0c12                 -lea ecx, [edx + edx]
    cpu.ecx = x86::reg32(cpu.edx + cpu.edx * 1);
    // 0049ec86  6683b9ca227a0002       +cmp word ptr [ecx + 0x7a22ca], 2
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(8004298) /* 0x7a22ca */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(2 /*0x2*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0049ec8e  7518                   -jne 0x49eca8
    if (!cpu.flags.zf)
    {
        goto L_0x0049eca8;
    }
    // 0049ec90  8b0495f0217a00         -mov eax, dword ptr [edx*4 + 0x7a21f0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8004080) /* 0x7a21f0 */ + cpu.edx * 4);
    // 0049ec97  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 0049ec9c  e80f000000             -call 0x49ecb0
    cpu.esp -= 4;
    sub_49ecb0(app, cpu);
    if (cpu.terminate) return;
    // 0049eca1  6689b1ca227a00         -mov word ptr [ecx + 0x7a22ca], si
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(8004298) /* 0x7a22ca */) = cpu.si;
L_0x0049eca8:
    // 0049eca8  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0049eca9  ebd0                   -jmp 0x49ec7b
    goto L_0x0049ec7b;
L_0x0049ecab:
    // 0049ecab  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ecac  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ecad  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ecae  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ecaf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49ecb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049ecb0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049ecb1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049ecb2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049ecb3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049ecb5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049ecb7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049ecb9  7431                   -je 0x49ecec
    if (cpu.flags.zf)
    {
        goto L_0x0049ecec;
    }
    // 0049ecbb  83781000               +cmp dword ptr [eax + 0x10], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049ecbf  742b                   -je 0x49ecec
    if (cpu.flags.zf)
    {
        goto L_0x0049ecec;
    }
    // 0049ecc1  e86a660500             -call 0x4f5330
    cpu.esp -= 4;
    sub_4f5330(app, cpu);
    if (cpu.terminate) return;
    // 0049ecc6  b890037a00             -mov eax, 0x7a0390
    cpu.eax = 7996304 /*0x7a0390*/;
    // 0049eccb  83c234                 -add edx, 0x34
    (cpu.edx) += x86::reg32(x86::sreg32(52 /*0x34*/));
    // 0049ecce  e81d630500             -call 0x4f4ff0
    cpu.esp -= 4;
    sub_4f4ff0(app, cpu);
    if (cpu.terminate) return;
    // 0049ecd3  8b1de0017a00           -mov ebx, dword ptr [0x7a01e0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(7995872) /* 0x7a01e0 */);
    // 0049ecd9  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0049ecde  4b                     -dec ebx
    (cpu.ebx)--;
    // 0049ecdf  66891596227a00         -mov word ptr [0x7a2296], dx
    app->getMemory<x86::reg16>(x86::reg32(8004246) /* 0x7a2296 */) = cpu.dx;
    // 0049ece6  891de0017a00           -mov dword ptr [0x7a01e0], ebx
    app->getMemory<x86::reg32>(x86::reg32(7995872) /* 0x7a01e0 */) = cpu.ebx;
L_0x0049ecec:
    // 0049ecec  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049eced  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ecee  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ecef  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49ecf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049ecf0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049ecf1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049ecf2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049ecf3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049ecf4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049ecf5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049ecf6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049ecf8  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0049ecfb  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049ecfd  8b0485f0217a00         -mov eax, dword ptr [eax*4 + 0x7a21f0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8004080) /* 0x7a21f0 */ + cpu.eax * 4);
    // 0049ed04  83c034                 -add eax, 0x34
    (cpu.eax) += x86::reg32(x86::sreg32(52 /*0x34*/));
    // 0049ed07  e844080000             -call 0x49f550
    cpu.esp -= 4;
    sub_49f550(app, cpu);
    if (cpu.terminate) return;
    // 0049ed0c  833d60e8550000         +cmp dword ptr [0x55e860], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5630048) /* 0x55e860 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049ed13  0f858d000000           -jne 0x49eda6
    if (!cpu.flags.zf)
    {
        goto L_0x0049eda6;
    }
    // 0049ed19  83fb07                 +cmp ebx, 7
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049ed1c  0f8f84000000           -jg 0x49eda6
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049eda6;
    }
    // 0049ed22  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049ed24  0f8c7c000000           -jl 0x49eda6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049eda6;
    }
    // 0049ed2a  8b0d64e85500           -mov ecx, dword ptr [0x55e864]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5630052) /* 0x55e864 */);
    // 0049ed30  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049ed31  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049ed37  8d041b                 -lea eax, [ebx + ebx]
    cpu.eax = x86::reg32(cpu.ebx + cpu.ebx * 1);
    // 0049ed3a  6683b8ca227a0000       +cmp word ptr [eax + 0x7a22ca], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(8004298) /* 0x7a22ca */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0049ed42  7555                   -jne 0x49ed99
    if (!cpu.flags.zf)
    {
        goto L_0x0049ed99;
    }
    // 0049ed44  66c780ca227a000200     -mov word ptr [eax + 0x7a22ca], 2
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(8004298) /* 0x7a22ca */) = 2 /*0x2*/;
    // 0049ed4d  8b1d64e85500           -mov ebx, dword ptr [0x55e864]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5630052) /* 0x55e864 */);
    // 0049ed53  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049ed54  beca227a00             -mov esi, 0x7a22ca
    cpu.esi = 8004298 /*0x7a22ca*/;
    // 0049ed59  8d7dee                 -lea edi, [ebp - 0x12]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-18) /* -0x12 */);
    // 0049ed5c  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049ed62  b40e                   -mov ah, 0xe
    cpu.ah = 14 /*0xe*/;
    // 0049ed64  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 0049ed69  bb12000000             -mov ebx, 0x12
    cpu.ebx = 18 /*0x12*/;
    // 0049ed6e  8d55ec                 -lea edx, [ebp - 0x14]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0049ed71  8865ec                 -mov byte ptr [ebp - 0x14], ah
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ah;
    // 0049ed74  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049ed75  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049ed77  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0049ed7a  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049ed7c  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0049ed7e  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0049ed81  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0049ed83  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ed84  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0049ed89  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0049ed8b  66890d96227a00         -mov word ptr [0x7a2296], cx
    app->getMemory<x86::reg16>(x86::reg32(8004246) /* 0x7a2296 */) = cpu.cx;
    // 0049ed92  e849730000             -call 0x4a60e0
    cpu.esp -= 4;
    sub_4a60e0(app, cpu);
    if (cpu.terminate) return;
    // 0049ed97  eb0d                   -jmp 0x49eda6
    goto L_0x0049eda6;
L_0x0049ed99:
    // 0049ed99  8b3564e85500           -mov esi, dword ptr [0x55e864]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5630052) /* 0x55e864 */);
    // 0049ed9f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049eda0  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0049eda6:
    // 0049eda6  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0049eda8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049eda9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049edaa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049edab  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049edac  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049edad  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049edae  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_49edb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049edb0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049edb1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049edb2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049edb3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049edb4  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049edb6  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 0049edbb  bfca227a00             -mov edi, 0x7a22ca
    cpu.edi = 8004298 /*0x7a22ca*/;
    // 0049edc0  8d7202                 -lea esi, [edx + 2]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0049edc3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049edc4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049edc6  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0049edc9  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049edcb  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0049edcd  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0049edd0  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0049edd2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049edd3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049edd4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049edd5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049edd6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049edd7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_49ede0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049ede0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049ede1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049ede2  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049ede4  66833dda227a0000       +cmp word ptr [0x7a22da], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(8004314) /* 0x7a22da */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0049edec  0f845b000000           -je 0x49ee4d
    if (cpu.flags.zf)
    {
        goto L_0x0049ee4d;
    }
    // 0049edf2  66833ddc227a0000       +cmp word ptr [0x7a22dc], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(8004316) /* 0x7a22dc */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0049edfa  7551                   -jne 0x49ee4d
    if (!cpu.flags.zf)
    {
        goto L_0x0049ee4d;
    }
    // 0049edfc  833d60e8550000         +cmp dword ptr [0x55e860], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5630048) /* 0x55e860 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049ee03  7548                   -jne 0x49ee4d
    if (!cpu.flags.zf)
    {
        goto L_0x0049ee4d;
    }
    // 0049ee05  833de0227a0003         +cmp dword ptr [0x7a22e0], 3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(8004320) /* 0x7a22e0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049ee0c  753f                   -jne 0x49ee4d
    if (!cpu.flags.zf)
    {
        goto L_0x0049ee4d;
    }
    // 0049ee0e  833de4227a0002         +cmp dword ptr [0x7a22e4], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(8004324) /* 0x7a22e4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049ee15  742c                   -je 0x49ee43
    if (cpu.flags.zf)
    {
        goto L_0x0049ee43;
    }
    // 0049ee17  a11ce75500             -mov eax, dword ptr [0x55e71c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5629724) /* 0x55e71c */);
    // 0049ee1c  e89f030000             -call 0x49f1c0
    cpu.esp -= 4;
    sub_49f1c0(app, cpu);
    if (cpu.terminate) return;
    // 0049ee21  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049ee23  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049ee26  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049ee28  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049ee2b  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049ee2d  833c8538e7550000       +cmp dword ptr [eax*4 + 0x55e738], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5629752) /* 0x55e738 */ + cpu.eax * 4);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049ee35  740c                   -je 0x49ee43
    if (cpu.flags.zf)
    {
        goto L_0x0049ee43;
    }
    // 0049ee37  b890037a00             -mov eax, 0x7a0390
    cpu.eax = 7996304 /*0x7a0390*/;
    // 0049ee3c  e82f610500             -call 0x4f4f70
    cpu.esp -= 4;
    sub_4f4f70(app, cpu);
    if (cpu.terminate) return;
    // 0049ee41  85c0                   -test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
L_0x0049ee43:
    // 0049ee43  c70560e8550001000000   -mov dword ptr [0x55e860], 1
    app->getMemory<x86::reg32>(x86::reg32(5630048) /* 0x55e860 */) = 1 /*0x1*/;
L_0x0049ee4d:
    // 0049ee4d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ee4e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ee4f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49ee50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049ee50  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049ee51  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049ee52  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049ee53  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049ee55  66833dda227a0000       +cmp word ptr [0x7a22da], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(8004314) /* 0x7a22da */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0049ee5d  0f8461000000           -je 0x49eec4
    if (cpu.flags.zf)
    {
        goto L_0x0049eec4;
    }
    // 0049ee63  66833ddc227a0000       +cmp word ptr [0x7a22dc], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(8004316) /* 0x7a22dc */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0049ee6b  7557                   -jne 0x49eec4
    if (!cpu.flags.zf)
    {
        goto L_0x0049eec4;
    }
    // 0049ee6d  833d60e8550000         +cmp dword ptr [0x55e860], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5630048) /* 0x55e860 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049ee74  744e                   -je 0x49eec4
    if (cpu.flags.zf)
    {
        goto L_0x0049eec4;
    }
    // 0049ee76  833de0227a0003         +cmp dword ptr [0x7a22e0], 3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(8004320) /* 0x7a22e0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049ee7d  7545                   -jne 0x49eec4
    if (!cpu.flags.zf)
    {
        goto L_0x0049eec4;
    }
    // 0049ee7f  833de4227a0002         +cmp dword ptr [0x7a22e4], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(8004324) /* 0x7a22e4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049ee86  742e                   -je 0x49eeb6
    if (cpu.flags.zf)
    {
        goto L_0x0049eeb6;
    }
    // 0049ee88  a11ce75500             -mov eax, dword ptr [0x55e71c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5629724) /* 0x55e71c */);
    // 0049ee8d  e82e030000             -call 0x49f1c0
    cpu.esp -= 4;
    sub_49f1c0(app, cpu);
    if (cpu.terminate) return;
    // 0049ee92  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049ee94  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049ee97  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049ee99  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049ee9c  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049ee9e  833c8538e7550000       +cmp dword ptr [eax*4 + 0x55e738], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5629752) /* 0x55e738 */ + cpu.eax * 4);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049eea6  740e                   -je 0x49eeb6
    if (cpu.flags.zf)
    {
        goto L_0x0049eeb6;
    }
    // 0049eea8  b890037a00             -mov eax, 0x7a0390
    cpu.eax = 7996304 /*0x7a0390*/;
    // 0049eead  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049eeaf  e89c600500             -call 0x4f4f50
    cpu.esp -= 4;
    sub_4f4f50(app, cpu);
    if (cpu.terminate) return;
    // 0049eeb4  85c0                   -test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
L_0x0049eeb6:
    // 0049eeb6  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0049eeb8  893d10e75500           -mov dword ptr [0x55e710], edi
    app->getMemory<x86::reg32>(x86::reg32(5629712) /* 0x55e710 */) = cpu.edi;
    // 0049eebe  893d60e85500           -mov dword ptr [0x55e860], edi
    app->getMemory<x86::reg32>(x86::reg32(5630048) /* 0x55e860 */) = cpu.edi;
L_0x0049eec4:
    // 0049eec4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049eec5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049eec6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049eec7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_49eed0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049eed0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049eed1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049eed2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049eed3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049eed5  833de0227a0003         +cmp dword ptr [0x7a22e0], 3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(8004320) /* 0x7a22e0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049eedc  0f85bb000000           -jne 0x49ef9d
    if (!cpu.flags.zf)
    {
        goto L_0x0049ef9d;
    }
    // 0049eee2  833de4227a0002         +cmp dword ptr [0x7a22e4], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(8004324) /* 0x7a22e4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049eee9  0f84a6000000           -je 0x49ef95
    if (cpu.flags.zf)
    {
        goto L_0x0049ef95;
    }
    // 0049eeef  66833dda227a0000       +cmp word ptr [0x7a22da], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(8004314) /* 0x7a22da */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0049eef7  0f846c000000           -je 0x49ef69
    if (cpu.flags.zf)
    {
        goto L_0x0049ef69;
    }
    // 0049eefd  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0049eeff  eb05                   -jmp 0x49ef06
    goto L_0x0049ef06;
L_0x0049ef01:
    // 0049ef01  83fa07                 +cmp edx, 7
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
    // 0049ef04  7d29                   -jge 0x49ef2f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049ef2f;
    }
L_0x0049ef06:
    // 0049ef06  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0049ef0d  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049ef0f  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049ef12  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049ef14  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0049ef17  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049ef19  83b8f8227a0000         +cmp dword ptr [eax + 0x7a22f8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8004344) /* 0x7a22f8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049ef20  740a                   -je 0x49ef2c
    if (cpu.flags.zf)
    {
        goto L_0x0049ef2c;
    }
    // 0049ef22  05e8227a00             +add eax, 0x7a22e8
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8004328 /*0x7a22e8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049ef27  e884fdffff             -call 0x49ecb0
    cpu.esp -= 4;
    sub_49ecb0(app, cpu);
    if (cpu.terminate) return;
L_0x0049ef2c:
    // 0049ef2c  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0049ef2d  ebd2                   -jmp 0x49ef01
    goto L_0x0049ef01;
L_0x0049ef2f:
    // 0049ef2f  833d60e8550000         +cmp dword ptr [0x55e860], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5630048) /* 0x55e860 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049ef36  7431                   -je 0x49ef69
    if (cpu.flags.zf)
    {
        goto L_0x0049ef69;
    }
    // 0049ef38  a11ce75500             -mov eax, dword ptr [0x55e71c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5629724) /* 0x55e71c */);
    // 0049ef3d  e87e020000             -call 0x49f1c0
    cpu.esp -= 4;
    sub_49f1c0(app, cpu);
    if (cpu.terminate) return;
    // 0049ef42  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049ef44  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049ef47  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049ef49  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049ef4c  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049ef4e  833c8538e7550000       +cmp dword ptr [eax*4 + 0x55e738], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5629752) /* 0x55e738 */ + cpu.eax * 4);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049ef56  7411                   -je 0x49ef69
    if (cpu.flags.zf)
    {
        goto L_0x0049ef69;
    }
    // 0049ef58  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0049ef5d  b890037a00             -mov eax, 0x7a0390
    cpu.eax = 7996304 /*0x7a0390*/;
    // 0049ef62  e8e95f0500             -call 0x4f4f50
    cpu.esp -= 4;
    sub_4f4f50(app, cpu);
    if (cpu.terminate) return;
    // 0049ef67  85c0                   -test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
L_0x0049ef69:
    // 0049ef69  a11ce75500             -mov eax, dword ptr [0x55e71c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5629724) /* 0x55e71c */);
    // 0049ef6e  e84d020000             -call 0x49f1c0
    cpu.esp -= 4;
    sub_49f1c0(app, cpu);
    if (cpu.terminate) return;
    // 0049ef73  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049ef75  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049ef78  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049ef7a  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049ef7d  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049ef7f  833c8538e7550000       +cmp dword ptr [eax*4 + 0x55e738], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5629752) /* 0x55e738 */ + cpu.eax * 4);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049ef87  740c                   -je 0x49ef95
    if (cpu.flags.zf)
    {
        goto L_0x0049ef95;
    }
    // 0049ef89  b890037a00             -mov eax, 0x7a0390
    cpu.eax = 7996304 /*0x7a0390*/;
    // 0049ef8e  e8fd5f0500             -call 0x4f4f90
    cpu.esp -= 4;
    sub_4f4f90(app, cpu);
    if (cpu.terminate) return;
    // 0049ef93  85c0                   -test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
L_0x0049ef95:
    // 0049ef95  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049ef97  890d60e85500           -mov dword ptr [0x55e860], ecx
    app->getMemory<x86::reg32>(x86::reg32(5630048) /* 0x55e860 */) = cpu.ecx;
L_0x0049ef9d:
    // 0049ef9d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ef9e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ef9f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049efa0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_49efb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049efb0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049efb1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049efb2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049efb3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049efb4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049efb5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049efb7  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049efb9  0fbfd2                 -movsx edx, dx
    cpu.edx = x86::reg32(static_cast<x86::sreg16>(cpu.dx));
    // 0049efbc  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0049efc3  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049efc5  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049efc8  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049efca  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0049efcd  bbe8227a00             -mov ebx, 0x7a22e8
    cpu.ebx = 8004328 /*0x7a22e8*/;
    // 0049efd2  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049efd4  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049efd6  a1d8435600             -mov eax, dword ptr [0x5643d8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653464) /* 0x5643d8 */);
    // 0049efdb  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049efdd  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0049efe0  c1e202                 +shl edx, 2
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
    // 0049efe3  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0049efe5  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 0049efe8  6689432a               -mov word ptr [ebx + 0x2a], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(42) /* 0x2a */) = cpu.ax;
    // 0049efec  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 0049eff1  6689432c               -mov word ptr [ebx + 0x2c], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(44) /* 0x2c */) = cpu.ax;
    // 0049eff5  8d7b34                 -lea edi, [ebx + 0x34]
    cpu.edi = x86::reg32(cpu.ebx + x86::reg32(52) /* 0x34 */);
    // 0049eff8  6689432e               -mov word ptr [ebx + 0x2e], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(46) /* 0x2e */) = cpu.ax;
    // 0049effc  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049effd  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049efff  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0049f002  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049f004  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0049f006  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0049f009  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0049f00b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f00c  833de4227a0002         +cmp dword ptr [0x7a22e4], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(8004324) /* 0x7a22e4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049f013  7507                   -jne 0x49f01c
    if (!cpu.flags.zf)
    {
        goto L_0x0049f01c;
    }
    // 0049f015  c7432401000000         -mov dword ptr [ebx + 0x24], 1
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */) = 1 /*0x1*/;
L_0x0049f01c:
    // 0049f01c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049f01e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f01f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f020  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f021  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f022  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f023  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_49f030(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049f030  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049f031  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049f032  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049f033  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049f034  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049f036  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049f038  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049f03a  e8f1850400             -call 0x4e7630
    cpu.esp -= 4;
    sub_4e7630(app, cpu);
    if (cpu.terminate) return;
    // 0049f03f  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049f041  b800f24900             -mov eax, 0x49f200
    cpu.eax = 4846080 /*0x49f200*/;
    // 0049f046  890d18e75500           -mov dword ptr [0x55e718], ecx
    app->getMemory<x86::reg32>(x86::reg32(5629720) /* 0x55e718 */) = cpu.ecx;
    // 0049f04c  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0049f04e  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0049f050  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0049f052  e8195c0500             -call 0x4f4c70
    cpu.esp -= 4;
    sub_4f4c70(app, cpu);
    if (cpu.terminate) return;
    // 0049f057  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049f059  0f84de000000           -je 0x49f13d
    if (cpu.flags.zf)
    {
        goto L_0x0049f13d;
    }
    // 0049f05f  833d20e7550000         +cmp dword ptr [0x55e720], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5629728) /* 0x55e720 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049f066  0f84c3000000           -je 0x49f12f
    if (cpu.flags.zf)
    {
        goto L_0x0049f12f;
    }
    // 0049f06c  8b1518e75500           -mov edx, dword ptr [0x55e718]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5629720) /* 0x55e718 */);
    // 0049f072  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0049f079  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049f07b  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049f07e  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049f080  c7048534e7550002000000 -mov dword ptr [eax*4 + 0x55e734], 2
    app->getMemory<x86::reg32>(x86::reg32(5629748) /* 0x55e734 */ + cpu.eax * 4) = 2 /*0x2*/;
    // 0049f08b  8b1518e75500           -mov edx, dword ptr [0x55e718]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5629720) /* 0x55e718 */);
    // 0049f091  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0049f098  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049f09a  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049f09d  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049f09f  bb0f000000             -mov ebx, 0xf
    cpu.ebx = 15 /*0xf*/;
    // 0049f0a4  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049f0a7  bad0c65300             -mov edx, 0x53c6d0
    cpu.edx = 5490384 /*0x53c6d0*/;
    // 0049f0ac  0524e75500             -add eax, 0x55e724
    (cpu.eax) += x86::reg32(x86::sreg32(5629732 /*0x55e724*/));
    // 0049f0b1  e87a1d0400             -call 0x4e0e30
    cpu.esp -= 4;
    sub_4e0e30(app, cpu);
    if (cpu.terminate) return;
    // 0049f0b6  8b1518e75500           -mov edx, dword ptr [0x55e718]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5629720) /* 0x55e718 */);
    // 0049f0bc  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0049f0c3  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049f0c5  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049f0c8  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049f0ca  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 0049f0cc  88148532e75500         -mov byte ptr [eax*4 + 0x55e732], dl
    app->getMemory<x86::reg8>(x86::reg32(5629746) /* 0x55e732 */ + cpu.eax * 4) = cpu.dl;
    // 0049f0d3  8b1518e75500           -mov edx, dword ptr [0x55e718]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5629720) /* 0x55e718 */);
    // 0049f0d9  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0049f0e0  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049f0e2  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049f0e5  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049f0e7  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049f0ea  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 0049f0ef  0524e75500             -add eax, 0x55e724
    (cpu.eax) += x86::reg32(x86::sreg32(5629732 /*0x55e724*/));
    // 0049f0f4  be78e85500             -mov esi, 0x55e878
    cpu.esi = 5630072 /*0x55e878*/;
    // 0049f0f9  8d7818                 -lea edi, [eax + 0x18]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0049f0fc  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049f0fd  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049f0ff  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0049f102  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049f104  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0049f106  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0049f109  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0049f10b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f10c  8b1518e75500           -mov edx, dword ptr [0x55e718]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5629720) /* 0x55e718 */);
    // 0049f112  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0049f119  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049f11b  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049f11e  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049f120  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0049f122  893c8538e75500         -mov dword ptr [eax*4 + 0x55e738], edi
    app->getMemory<x86::reg32>(x86::reg32(5629752) /* 0x55e738 */ + cpu.eax * 4) = cpu.edi;
    // 0049f129  ff0518e75500           -inc dword ptr [0x55e718]
    (app->getMemory<x86::reg32>(x86::reg32(5629720) /* 0x55e718 */))++;
L_0x0049f12f:
    // 0049f12f  e85c060000             -call 0x49f790
    cpu.esp -= 4;
    sub_49f790(app, cpu);
    if (cpu.terminate) return;
    // 0049f134  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049f136  7505                   -jne 0x49f13d
    if (!cpu.flags.zf)
    {
        goto L_0x0049f13d;
    }
    // 0049f138  a318e75500             -mov dword ptr [0x55e718], eax
    app->getMemory<x86::reg32>(x86::reg32(5629720) /* 0x55e718 */) = cpu.eax;
L_0x0049f13d:
    // 0049f13d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f13e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f13f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f140  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f141  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_49f150(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049f150  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049f151  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049f152  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049f153  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049f154  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049f155  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049f157  833d64e8550000         +cmp dword ptr [0x55e864], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5630052) /* 0x55e864 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049f15e  750a                   -jne 0x49f16a
    if (!cpu.flags.zf)
    {
        goto L_0x0049f16a;
    }
    // 0049f160  e87bc10400             -call 0x4eb2e0
    cpu.esp -= 4;
    sub_4eb2e0(app, cpu);
    if (cpu.terminate) return;
    // 0049f165  a364e85500             -mov dword ptr [0x55e864], eax
    app->getMemory<x86::reg32>(x86::reg32(5630052) /* 0x55e864 */) = cpu.eax;
L_0x0049f16a:
    // 0049f16a  833d18e7550000         +cmp dword ptr [0x55e718], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5629720) /* 0x55e718 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049f171  753f                   -jne 0x49f1b2
    if (!cpu.flags.zf)
    {
        goto L_0x0049f1b2;
    }
    // 0049f173  b980250000             -mov ecx, 0x2580
    cpu.ecx = 9600 /*0x2580*/;
    // 0049f178  ba64000000             -mov edx, 0x64
    cpu.edx = 100 /*0x64*/;
    // 0049f17d  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 0049f182  b8d4c65300             -mov eax, 0x53c6d4
    cpu.eax = 5490388 /*0x53c6d4*/;
    // 0049f187  8935e4227a00           -mov dword ptr [0x7a22e4], esi
    app->getMemory<x86::reg32>(x86::reg32(8004324) /* 0x7a22e4 */) = cpu.esi;
    // 0049f18d  e83e720500             -call 0x4f63d0
    cpu.esp -= 4;
    sub_4f63d0(app, cpu);
    if (cpu.terminate) return;
    // 0049f192  b8d8c65300             -mov eax, 0x53c6d8
    cpu.eax = 5490392 /*0x53c6d8*/;
    // 0049f197  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 0049f19c  e88f860500             -call 0x4f7830
    cpu.esp -= 4;
    sub_4f7830(app, cpu);
    if (cpu.terminate) return;
    // 0049f1a1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049f1a3  7406                   -je 0x49f1ab
    if (cpu.flags.zf)
    {
        goto L_0x0049f1ab;
    }
    // 0049f1a5  893520e75500           -mov dword ptr [0x55e720], esi
    app->getMemory<x86::reg32>(x86::reg32(5629728) /* 0x55e720 */) = cpu.esi;
L_0x0049f1ab:
    // 0049f1ab  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049f1ad  e87efeffff             -call 0x49f030
    cpu.esp -= 4;
    sub_49f030(app, cpu);
    if (cpu.terminate) return;
L_0x0049f1b2:
    // 0049f1b2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f1b3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f1b4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f1b5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f1b6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f1b7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_49f1c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049f1c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049f1c1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049f1c2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049f1c3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049f1c5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049f1c7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0049f1c9:
    // 0049f1c9  3b1518e75500           +cmp edx, dword ptr [0x55e718]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5629720) /* 0x55e718 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049f1cf  7d20                   -jge 0x49f1f1
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049f1f1;
    }
    // 0049f1d1  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0049f1d8  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049f1da  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049f1dd  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049f1df  3b1c8534e75500         +cmp ebx, dword ptr [eax*4 + 0x55e734]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5629748) /* 0x55e734 */ + cpu.eax * 4)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049f1e6  7506                   -jne 0x49f1ee
    if (!cpu.flags.zf)
    {
        goto L_0x0049f1ee;
    }
    // 0049f1e8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049f1ea  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f1eb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f1ec  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f1ed  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049f1ee:
    // 0049f1ee  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0049f1ef  ebd8                   -jmp 0x49f1c9
    goto L_0x0049f1c9;
L_0x0049f1f1:
    // 0049f1f1  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0049f1f6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f1f7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f1f8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f1f9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_49f200(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049f200  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049f201  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049f202  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049f203  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049f205  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049f207  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0049f209  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049f20b  e820840400             -call 0x4e7630
    cpu.esp -= 4;
    sub_4e7630(app, cpu);
    if (cpu.terminate) return;
    // 0049f210  833d18e7550007         +cmp dword ptr [0x55e718], 7
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5629720) /* 0x55e718 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049f217  0f8d54010000           -jge 0x49f371
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049f371;
    }
    // 0049f21d  bae4c65300             -mov edx, 0x53c6e4
    cpu.edx = 5490404 /*0x53c6e4*/;
    // 0049f222  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049f224  e8f7150400             -call 0x4e0820
    cpu.esp -= 4;
    sub_4e0820(app, cpu);
    if (cpu.terminate) return;
    // 0049f229  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049f22b  0f8470000000           -je 0x49f2a1
    if (cpu.flags.zf)
    {
        goto L_0x0049f2a1;
    }
    // 0049f231  bad4c65300             -mov edx, 0x53c6d4
    cpu.edx = 5490388 /*0x53c6d4*/;
    // 0049f236  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049f238  e8e3150400             -call 0x4e0820
    cpu.esp -= 4;
    sub_4e0820(app, cpu);
    if (cpu.terminate) return;
    // 0049f23d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049f23f  7423                   -je 0x49f264
    if (cpu.flags.zf)
    {
        goto L_0x0049f264;
    }
    // 0049f241  8b1518e75500           -mov edx, dword ptr [0x55e718]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5629720) /* 0x55e718 */);
    // 0049f247  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0049f24e  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049f250  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049f253  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049f255  bb0f000000             -mov ebx, 0xf
    cpu.ebx = 15 /*0xf*/;
    // 0049f25a  c1e002                 +shl eax, 2
    {
        x86::reg8 tmp = 2 /*0x2*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0049f25d  baf0c65300             -mov edx, 0x53c6f0
    cpu.edx = 5490416 /*0x53c6f0*/;
    // 0049f262  eb31                   -jmp 0x49f295
    goto L_0x0049f295;
L_0x0049f264:
    // 0049f264  bad0c65300             -mov edx, 0x53c6d0
    cpu.edx = 5490384 /*0x53c6d0*/;
    // 0049f269  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049f26b  e8b0150400             -call 0x4e0820
    cpu.esp -= 4;
    sub_4e0820(app, cpu);
    if (cpu.terminate) return;
    // 0049f270  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049f272  7474                   -je 0x49f2e8
    if (cpu.flags.zf)
    {
        goto L_0x0049f2e8;
    }
    // 0049f274  8b1518e75500           -mov edx, dword ptr [0x55e718]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5629720) /* 0x55e718 */);
    // 0049f27a  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0049f281  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049f283  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049f286  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049f288  bb0f000000             -mov ebx, 0xf
    cpu.ebx = 15 /*0xf*/;
    // 0049f28d  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049f290  ba00c75300             -mov edx, 0x53c700
    cpu.edx = 5490432 /*0x53c700*/;
L_0x0049f295:
    // 0049f295  0524e75500             +add eax, 0x55e724
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5629732 /*0x55e724*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049f29a  e8911b0400             -call 0x4e0e30
    cpu.esp -= 4;
    sub_4e0e30(app, cpu);
    if (cpu.terminate) return;
    // 0049f29f  eb47                   -jmp 0x49f2e8
    goto L_0x0049f2e8;
L_0x0049f2a1:
    // 0049f2a1  8b1518e75500           -mov edx, dword ptr [0x55e718]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5629720) /* 0x55e718 */);
    // 0049f2a7  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0049f2ae  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049f2b0  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049f2b3  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049f2b5  c7048534e7550001000000 -mov dword ptr [eax*4 + 0x55e734], 1
    app->getMemory<x86::reg32>(x86::reg32(5629748) /* 0x55e734 */ + cpu.eax * 4) = 1 /*0x1*/;
    // 0049f2c0  8b1518e75500           -mov edx, dword ptr [0x55e718]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5629720) /* 0x55e718 */);
    // 0049f2c6  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0049f2cd  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049f2cf  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049f2d2  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049f2d4  bb0f000000             -mov ebx, 0xf
    cpu.ebx = 15 /*0xf*/;
    // 0049f2d9  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049f2dc  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0049f2de  0524e75500             -add eax, 0x55e724
    (cpu.eax) += x86::reg32(x86::sreg32(5629732 /*0x55e724*/));
    // 0049f2e3  e8481b0400             -call 0x4e0e30
    cpu.esp -= 4;
    sub_4e0e30(app, cpu);
    if (cpu.terminate) return;
L_0x0049f2e8:
    // 0049f2e8  8b1518e75500           -mov edx, dword ptr [0x55e718]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5629720) /* 0x55e718 */);
    // 0049f2ee  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0049f2f5  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049f2f7  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049f2fa  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049f2fc  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 0049f2fe  88148532e75500         -mov byte ptr [eax*4 + 0x55e732], dl
    app->getMemory<x86::reg8>(x86::reg32(5629746) /* 0x55e732 */ + cpu.eax * 4) = cpu.dl;
    // 0049f305  8b1518e75500           -mov edx, dword ptr [0x55e718]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5629720) /* 0x55e718 */);
    // 0049f30b  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0049f312  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049f314  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049f317  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049f319  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049f31c  0524e75500             -add eax, 0x55e724
    (cpu.eax) += x86::reg32(x86::sreg32(5629732 /*0x55e724*/));
    // 0049f321  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 0049f326  83c018                 -add eax, 0x18
    (cpu.eax) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0049f329  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 0049f32b  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049f32d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049f32e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049f330  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0049f333  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049f335  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0049f337  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0049f33a  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0049f33c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f33d  8b1518e75500           -mov edx, dword ptr [0x55e718]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5629720) /* 0x55e718 */);
    // 0049f343  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0049f34a  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049f34c  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049f34f  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049f351  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0049f356  891c8538e75500         -mov dword ptr [eax*4 + 0x55e738], ebx
    app->getMemory<x86::reg32>(x86::reg32(5629752) /* 0x55e738 */ + cpu.eax * 4) = cpu.ebx;
    // 0049f35d  8b3518e75500           -mov esi, dword ptr [0x55e718]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5629720) /* 0x55e718 */);
    // 0049f363  01de                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0049f365  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049f367  893518e75500           -mov dword ptr [0x55e718], esi
    app->getMemory<x86::reg32>(x86::reg32(5629720) /* 0x55e718 */) = cpu.esi;
    // 0049f36d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f36e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f36f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f370  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049f371:
    // 0049f371  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049f373  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f374  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f375  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f376  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_49f380(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049f380  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049f381  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049f382  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049f383  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049f385  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049f388  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049f38a  8955f8                 -mov dword ptr [ebp - 8], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edx;
    // 0049f38d  894dfc                 -mov dword ptr [ebp - 4], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
    // 0049f390  66833d58e8550014       +cmp word ptr [0x55e858], 0x14
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(5630040) /* 0x55e858 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(20 /*0x14*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0049f398  0f8dc4000000           -jge 0x49f462
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049f462;
    }
    // 0049f39e  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0049f3a0:
    // 0049f3a0  a156e85500             -mov eax, dword ptr [0x55e856]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5630038) /* 0x55e856 */);
    // 0049f3a5  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0049f3a8  39c1                   +cmp ecx, eax
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
    // 0049f3aa  7d2b                   -jge 0x49f3d7
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049f3d7;
    }
    // 0049f3ac  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049f3ae  8b155ce85500           -mov edx, dword ptr [0x55e85c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5630044) /* 0x55e85c */);
    // 0049f3b4  c1e006                 -shl eax, 6
    cpu.eax <<= 6 /*0x6*/ % 32;
    // 0049f3b7  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049f3b9  8d582c                 -lea ebx, [eax + 0x2c]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(44) /* 0x2c */);
    // 0049f3bc  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0049f3bf  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049f3c1  e87a5c0500             -call 0x4f5040
    cpu.esp -= 4;
    sub_4f5040(app, cpu);
    if (cpu.terminate) return;
    // 0049f3c6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049f3c8  740a                   -je 0x49f3d4
    if (cpu.flags.zf)
    {
        goto L_0x0049f3d4;
    }
    // 0049f3ca  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049f3cf  e990000000             -jmp 0x49f464
    goto L_0x0049f464;
L_0x0049f3d4:
    // 0049f3d4  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0049f3d5  ebc9                   -jmp 0x49f3a0
    goto L_0x0049f3a0;
L_0x0049f3d7:
    // 0049f3d7  8b155ce85500           -mov edx, dword ptr [0x55e85c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5630044) /* 0x55e85c */);
    // 0049f3dd  c1e006                 -shl eax, 6
    cpu.eax <<= 6 /*0x6*/ % 32;
    // 0049f3e0  8b75f8                 -mov esi, dword ptr [ebp - 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0049f3e3  8d3c02                 -lea edi, [edx + eax]
    cpu.edi = x86::reg32(cpu.edx + cpu.eax * 1);
    // 0049f3e6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0049f3e7:
    // 0049f3e7  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0049f3e9  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0049f3eb  3c00                   +cmp al, 0
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
    // 0049f3ed  7410                   -je 0x49f3ff
    if (cpu.flags.zf)
    {
        goto L_0x0049f3ff;
    }
    // 0049f3ef  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0049f3f2  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049f3f5  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0049f3f8  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049f3fb  3c00                   +cmp al, 0
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
    // 0049f3fd  75e8                   -jne 0x49f3e7
    if (!cpu.flags.zf)
    {
        goto L_0x0049f3e7;
    }
L_0x0049f3ff:
    // 0049f3ff  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f400  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0049f402  eb05                   -jmp 0x49f409
    goto L_0x0049f409;
L_0x0049f404:
    // 0049f404  83f804                 +cmp eax, 4
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
    // 0049f407  7d24                   -jge 0x49f42d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049f42d;
    }
L_0x0049f409:
    // 0049f409  8b4df8                 -mov ecx, dword ptr [ebp - 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0049f40c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049f40e  8a5c0120               -mov bl, byte ptr [ecx + eax + 0x20]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(32) /* 0x20 */ + cpu.eax * 1);
    // 0049f412  8b0d56e85500           -mov ecx, dword ptr [0x55e856]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5630038) /* 0x55e856 */);
    // 0049f418  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0049f41b  8b155ce85500           -mov edx, dword ptr [0x55e85c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5630044) /* 0x55e85c */);
    // 0049f421  c1e106                 -shl ecx, 6
    cpu.ecx <<= 6 /*0x6*/ % 32;
    // 0049f424  40                     -inc eax
    (cpu.eax)++;
    // 0049f425  01d1                   +add ecx, edx
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
    // 0049f427  895c8118               -mov dword ptr [ecx + eax*4 + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */ + cpu.eax * 4) = cpu.ebx;
    // 0049f42b  ebd7                   -jmp 0x49f404
    goto L_0x0049f404;
L_0x0049f42d:
    // 0049f42d  8d792c                 -lea edi, [ecx + 0x2c]
    cpu.edi = x86::reg32(cpu.ecx + x86::reg32(44) /* 0x2c */);
    // 0049f430  8b75fc                 -mov esi, dword ptr [ebp - 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0049f433  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 0049f438  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049f439  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049f43b  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0049f43e  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049f440  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0049f442  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0049f445  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0049f447  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f448  668b1d58e85500         -mov bx, word ptr [0x55e858]
    cpu.bx = app->getMemory<x86::reg16>(x86::reg32(5630040) /* 0x55e858 */);
    // 0049f44f  43                     -inc ebx
    (cpu.ebx)++;
    // 0049f450  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049f455  66891d58e85500         -mov word ptr [0x55e858], bx
    app->getMemory<x86::reg16>(x86::reg32(5630040) /* 0x55e858 */) = cpu.bx;
    // 0049f45c  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0049f45e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f45f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f460  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f461  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049f462:
    // 0049f462  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0049f464:
    // 0049f464  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0049f466  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f467  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f468  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f469  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_49f470(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049f470  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049f471  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049f472  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049f474  833d10e7550000         +cmp dword ptr [0x55e710], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5629712) /* 0x55e710 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049f47b  7524                   -jne 0x49f4a1
    if (!cpu.flags.zf)
    {
        goto L_0x0049f4a1;
    }
    // 0049f47d  8b1de0017a00           -mov ebx, dword ptr [0x7a01e0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(7995872) /* 0x7a01e0 */);
    // 0049f483  83fb07                 +cmp ebx, 7
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049f486  7d19                   -jge 0x49f4a1
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049f4a1;
    }
    // 0049f488  8d7301                 -lea esi, [ebx + 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 0049f48b  8d4248                 -lea eax, [edx + 0x48]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(72) /* 0x48 */);
    // 0049f48e  8935e0017a00           -mov dword ptr [0x7a01e0], esi
    app->getMemory<x86::reg32>(x86::reg32(7995872) /* 0x7a01e0 */) = cpu.esi;
    // 0049f494  e807020000             -call 0x49f6a0
    cpu.esp -= 4;
    sub_49f6a0(app, cpu);
    if (cpu.terminate) return;
    // 0049f499  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049f49e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f49f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f4a0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049f4a1:
    // 0049f4a1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049f4a3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f4a4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f4a5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_49f4b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049f4b0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049f4b1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049f4b2  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049f4b4  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0049f4b7  833d10e7550000         +cmp dword ptr [0x55e710], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5629712) /* 0x55e710 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049f4be  754f                   -jne 0x49f50f
    if (!cpu.flags.zf)
    {
        goto L_0x0049f50f;
    }
    // 0049f4c0  833de0017a0007         +cmp dword ptr [0x7a01e0], 7
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7995872) /* 0x7a01e0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049f4c7  7d46                   -jge 0x49f50f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049f50f;
    }
    // 0049f4c9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049f4cb  e8f0000000             -call 0x49f5c0
    cpu.esp -= 4;
    sub_49f5c0(app, cpu);
    if (cpu.terminate) return;
    // 0049f4d0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049f4d2  750a                   -jne 0x49f4de
    if (!cpu.flags.zf)
    {
        goto L_0x0049f4de;
    }
    // 0049f4d4  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049f4d9  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0049f4db  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f4dc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f4dd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049f4de:
    // 0049f4de  8b35e0017a00           -mov esi, dword ptr [0x7a01e0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(7995872) /* 0x7a01e0 */);
    // 0049f4e4  46                     -inc esi
    (cpu.esi)++;
    // 0049f4e5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049f4e6  6810c75300             -push 0x53c710
    app->getMemory<x86::reg32>(cpu.esp-4) = 5490448 /*0x53c710*/;
    cpu.esp -= 4;
    // 0049f4eb  8d45f4                 -lea eax, [ebp - 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0049f4ee  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049f4ef  8935e0017a00           -mov dword ptr [0x7a01e0], esi
    app->getMemory<x86::reg32>(x86::reg32(7995872) /* 0x7a01e0 */) = cpu.esi;
    // 0049f4f5  e896010400             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 0049f4fa  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0049f4fd  8d45f4                 -lea eax, [ebp - 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0049f500  e89b010000             -call 0x49f6a0
    cpu.esp -= 4;
    sub_49f6a0(app, cpu);
    if (cpu.terminate) return;
    // 0049f505  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049f50a  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0049f50c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f50d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f50e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049f50f:
    // 0049f50f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049f511  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0049f513  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f514  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f515  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_49f520(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049f520  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049f521  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049f522  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049f524  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049f526  40                     -inc eax
    (cpu.eax)++;
    // 0049f527  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049f529  891485e4027a00         -mov dword ptr [eax*4 + 0x7a02e4], edx
    app->getMemory<x86::reg32>(x86::reg32(7996132) /* 0x7a02e4 */ + cpu.eax * 4) = cpu.edx;
L_0x0049f530:
    // 0049f530  83f807                 +cmp eax, 7
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
    // 0049f533  7d0c                   -jge 0x49f541
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049f541;
    }
    // 0049f535  40                     -inc eax
    (cpu.eax)++;
    // 0049f536  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0049f538  891485e4027a00         -mov dword ptr [eax*4 + 0x7a02e4], edx
    app->getMemory<x86::reg32>(x86::reg32(7996132) /* 0x7a02e4 */ + cpu.eax * 4) = cpu.edx;
    // 0049f53f  ebef                   -jmp 0x49f530
    goto L_0x0049f530;
L_0x0049f541:
    // 0049f541  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f542  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f543  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_49f550(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049f550  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049f551  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049f552  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049f553  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049f554  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049f555  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049f556  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049f558  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049f55a  a11ce75500             -mov eax, dword ptr [0x55e71c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5629724) /* 0x55e71c */);
    // 0049f55f  e85cfcffff             -call 0x49f1c0
    cpu.esp -= 4;
    sub_49f1c0(app, cpu);
    if (cpu.terminate) return;
    // 0049f564  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049f566  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049f569  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049f56b  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049f56e  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049f570  833c8538e7550000       +cmp dword ptr [eax*4 + 0x55e738], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5629752) /* 0x55e738 */ + cpu.eax * 4);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049f578  7535                   -jne 0x49f5af
    if (!cpu.flags.zf)
    {
        goto L_0x0049f5af;
    }
    // 0049f57a  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0049f57c  eb05                   -jmp 0x49f583
    goto L_0x0049f583;
L_0x0049f57e:
    // 0049f57e  83f907                 +cmp ecx, 7
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
    // 0049f581  7d2c                   -jge 0x49f5af
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049f5af;
    }
L_0x0049f583:
    // 0049f583  8d3c8d00000000         -lea edi, [ecx*4]
    cpu.edi = x86::reg32(cpu.ecx * 4);
    // 0049f58a  8b9fe8027a00           -mov ebx, dword ptr [edi + 0x7a02e8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(7996136) /* 0x7a02e8 */);
    // 0049f590  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049f592  7418                   -je 0x49f5ac
    if (cpu.flags.zf)
    {
        goto L_0x0049f5ac;
    }
    // 0049f594  b890037a00             -mov eax, 0x7a0390
    cpu.eax = 7996304 /*0x7a0390*/;
    // 0049f599  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0049f59b  e8a05a0500             -call 0x4f5040
    cpu.esp -= 4;
    sub_4f5040(app, cpu);
    if (cpu.terminate) return;
    // 0049f5a0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049f5a2  7408                   -je 0x49f5ac
    if (cpu.flags.zf)
    {
        goto L_0x0049f5ac;
    }
    // 0049f5a4  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0049f5a6  8987e8027a00           -mov dword ptr [edi + 0x7a02e8], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(7996136) /* 0x7a02e8 */) = cpu.eax;
L_0x0049f5ac:
    // 0049f5ac  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0049f5ad  ebcf                   -jmp 0x49f57e
    goto L_0x0049f57e;
L_0x0049f5af:
    // 0049f5af  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f5b0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f5b1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f5b2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f5b3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f5b4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f5b5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_49f5c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049f5c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049f5c1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049f5c2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049f5c3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049f5c4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049f5c5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049f5c6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049f5c8  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049f5ca  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0049f5cc  eb05                   -jmp 0x49f5d3
    goto L_0x0049f5d3;
L_0x0049f5ce:
    // 0049f5ce  83f907                 +cmp ecx, 7
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
    // 0049f5d1  7d26                   -jge 0x49f5f9
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049f5f9;
    }
L_0x0049f5d3:
    // 0049f5d3  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 0049f5da  8b90e8027a00           -mov edx, dword ptr [eax + 0x7a02e8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(7996136) /* 0x7a02e8 */);
    // 0049f5e0  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049f5e2  7412                   -je 0x49f5f6
    if (cpu.flags.zf)
    {
        goto L_0x0049f5f6;
    }
    // 0049f5e4  b890037a00             -mov eax, 0x7a0390
    cpu.eax = 7996304 /*0x7a0390*/;
    // 0049f5e9  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0049f5eb  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0049f5ed  e84e5a0500             -call 0x4f5040
    cpu.esp -= 4;
    sub_4f5040(app, cpu);
    if (cpu.terminate) return;
    // 0049f5f2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049f5f4  7550                   -jne 0x49f646
    if (!cpu.flags.zf)
    {
        goto L_0x0049f646;
    }
L_0x0049f5f6:
    // 0049f5f6  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0049f5f7  ebd5                   -jmp 0x49f5ce
    goto L_0x0049f5ce;
L_0x0049f5f9:
    // 0049f5f9  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0049f5fb  eb06                   -jmp 0x49f603
    goto L_0x0049f603;
L_0x0049f5fd:
    // 0049f5fd  40                     -inc eax
    (cpu.eax)++;
    // 0049f5fe  83f807                 +cmp eax, 7
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
    // 0049f601  7d43                   -jge 0x49f646
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049f646;
    }
L_0x0049f603:
    // 0049f603  8d0c8500000000         -lea ecx, [eax*4]
    cpu.ecx = x86::reg32(cpu.eax * 4);
    // 0049f60a  83b9e8027a0000         +cmp dword ptr [ecx + 0x7a02e8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(7996136) /* 0x7a02e8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049f611  75ea                   -jne 0x49f5fd
    if (!cpu.flags.zf)
    {
        goto L_0x0049f5fd;
    }
    // 0049f613  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049f615  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049f618  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049f61a  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049f61d  0504037a00             -add eax, 0x7a0304
    (cpu.eax) += x86::reg32(x86::sreg32(7996164 /*0x7a0304*/));
    // 0049f622  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049f624  8981e8027a00           -mov dword ptr [ecx + 0x7a02e8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(7996136) /* 0x7a02e8 */) = cpu.eax;
    // 0049f62a  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 0049f62f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049f630  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049f632  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0049f635  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049f637  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0049f639  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0049f63c  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0049f63e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f63f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049f644  eb02                   -jmp 0x49f648
    goto L_0x0049f648;
L_0x0049f646:
    // 0049f646  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0049f648:
    // 0049f648  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f649  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f64a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f64b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f64c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f64d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f64e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_49f650(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049f650  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049f651  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049f652  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049f654  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049f656  8915e4017a00           -mov dword ptr [0x7a01e4], edx
    app->getMemory<x86::reg32>(x86::reg32(7995876) /* 0x7a01e4 */) = cpu.edx;
    // 0049f65c  8915e8017a00           -mov dword ptr [0x7a01e8], edx
    app->getMemory<x86::reg32>(x86::reg32(7995880) /* 0x7a01e8 */) = cpu.edx;
    // 0049f662  8915ec017a00           -mov dword ptr [0x7a01ec], edx
    app->getMemory<x86::reg32>(x86::reg32(7995884) /* 0x7a01ec */) = cpu.edx;
    // 0049f668  8915e0017a00           -mov dword ptr [0x7a01e0], edx
    app->getMemory<x86::reg32>(x86::reg32(7995872) /* 0x7a01e0 */) = cpu.edx;
    // 0049f66e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f66f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f670  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_49f680(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049f680  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049f681  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049f683  833dec017a0000         +cmp dword ptr [0x7a01ec], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7995884) /* 0x7a01ec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049f68a  7404                   -je 0x49f690
    if (cpu.flags.zf)
    {
        goto L_0x0049f690;
    }
    // 0049f68c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049f68e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f68f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049f690:
    // 0049f690  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049f695  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f696  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_49f6a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049f6a0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049f6a1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049f6a2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049f6a3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049f6a4  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049f6a6  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049f6a8  8b3de8017a00           -mov edi, dword ptr [0x7a01e8]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(7995880) /* 0x7a01e8 */);
    // 0049f6ae  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049f6b0  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 0049f6b3  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0049f6b5  bff0017a00             -mov edi, 0x7a01f0
    cpu.edi = 7995888 /*0x7a01f0*/;
    // 0049f6ba  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049f6bc  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0049f6bd:
    // 0049f6bd  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0049f6bf  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0049f6c1  3c00                   +cmp al, 0
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
    // 0049f6c3  7410                   -je 0x49f6d5
    if (cpu.flags.zf)
    {
        goto L_0x0049f6d5;
    }
    // 0049f6c5  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0049f6c8  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049f6cb  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0049f6ce  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049f6d1  3c00                   +cmp al, 0
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
    // 0049f6d3  75e8                   -jne 0x49f6bd
    if (!cpu.flags.zf)
    {
        goto L_0x0049f6bd;
    }
L_0x0049f6d5:
    // 0049f6d5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f6d6  8b35e8017a00           -mov esi, dword ptr [0x7a01e8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(7995880) /* 0x7a01e8 */);
    // 0049f6dc  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049f6de  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 0049f6e1  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0049f6e3  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 0049f6e8  05f0017a00             -add eax, 0x7a01f0
    (cpu.eax) += x86::reg32(x86::sreg32(7995888 /*0x7a01f0*/));
    // 0049f6ed  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0049f6ef  8d780b                 -lea edi, [eax + 0xb]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(11) /* 0xb */);
    // 0049f6f2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049f6f3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049f6f5  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0049f6f8  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049f6fa  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0049f6fc  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0049f6ff  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0049f701  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f702  8b15e8017a00           -mov edx, dword ptr [0x7a01e8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(7995880) /* 0x7a01e8 */);
    // 0049f708  42                     -inc edx
    (cpu.edx)++;
    // 0049f709  be06000000             -mov esi, 6
    cpu.esi = 6 /*0x6*/;
    // 0049f70e  8915e8017a00           -mov dword ptr [0x7a01e8], edx
    app->getMemory<x86::reg32>(x86::reg32(7995880) /* 0x7a01e8 */) = cpu.edx;
    // 0049f714  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049f716  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0049f719  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0049f71b  ff05ec017a00           -inc dword ptr [0x7a01ec]
    (app->getMemory<x86::reg32>(x86::reg32(7995884) /* 0x7a01ec */))++;
    // 0049f721  8915e8017a00           -mov dword ptr [0x7a01e8], edx
    app->getMemory<x86::reg32>(x86::reg32(7995880) /* 0x7a01e8 */) = cpu.edx;
    // 0049f727  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f728  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f729  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f72a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f72b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_49f730(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049f730  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049f731  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049f732  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049f733  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049f734  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049f735  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049f737  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049f739  8b35e4017a00           -mov esi, dword ptr [0x7a01e4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(7995876) /* 0x7a01e4 */);
    // 0049f73f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049f741  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 0049f744  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0049f746  bef0017a00             -mov esi, 0x7a01f0
    cpu.esi = 7995888 /*0x7a01f0*/;
    // 0049f74b  b91f000000             -mov ecx, 0x1f
    cpu.ecx = 31 /*0x1f*/;
    // 0049f750  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049f752  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049f753  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049f755  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0049f758  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049f75a  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0049f75c  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0049f75f  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0049f761  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f762  8b15e4017a00           -mov edx, dword ptr [0x7a01e4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(7995876) /* 0x7a01e4 */);
    // 0049f768  42                     -inc edx
    (cpu.edx)++;
    // 0049f769  be06000000             -mov esi, 6
    cpu.esi = 6 /*0x6*/;
    // 0049f76e  8915e4017a00           -mov dword ptr [0x7a01e4], edx
    app->getMemory<x86::reg32>(x86::reg32(7995876) /* 0x7a01e4 */) = cpu.edx;
    // 0049f774  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049f776  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0049f779  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0049f77b  ff0dec017a00           -dec dword ptr [0x7a01ec]
    (app->getMemory<x86::reg32>(x86::reg32(7995884) /* 0x7a01ec */))--;
    // 0049f781  8915e4017a00           -mov dword ptr [0x7a01e4], edx
    app->getMemory<x86::reg32>(x86::reg32(7995876) /* 0x7a01e4 */) = cpu.edx;
    // 0049f787  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f788  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f789  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f78a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f78b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f78c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_49f790(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049f790  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049f791  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049f792  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049f793  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049f795  81eca4010000           -sub esp, 0x1a4
    (cpu.esp) -= x86::reg32(x86::sreg32(420 /*0x1a4*/));
    // 0049f79b  ba9c010000             -mov edx, 0x19c
    cpu.edx = 412 /*0x19c*/;
    // 0049f7a0  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049f7a2  8955f8                 -mov dword ptr [ebp - 8], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edx;
    // 0049f7a5  894dfc                 -mov dword ptr [ebp - 4], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
    // 0049f7a8  e863000000             -call 0x49f810
    cpu.esp -= 4;
    sub_49f810(app, cpu);
    if (cpu.terminate) return;
    // 0049f7ad  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049f7af  7407                   -je 0x49f7b8
    if (cpu.flags.zf)
    {
        goto L_0x0049f7b8;
    }
    // 0049f7b1  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049f7b6  eb48                   -jmp 0x49f800
    goto L_0x0049f800;
L_0x0049f7b8:
    // 0049f7b8  e8a3030000             -call 0x49fb60
    cpu.esp -= 4;
    sub_49fb60(app, cpu);
    if (cpu.terminate) return;
    // 0049f7bd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049f7bf  7506                   -jne 0x49f7c7
    if (!cpu.flags.zf)
    {
        goto L_0x0049f7c7;
    }
    // 0049f7c1  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0049f7c3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f7c4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f7c5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f7c6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049f7c7:
    // 0049f7c7  8d45fc                 -lea eax, [ebp - 4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0049f7ca  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049f7cb  8d45f8                 -lea eax, [ebp - 8]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0049f7ce  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049f7cf  8d855cfeffff           -lea eax, [ebp - 0x1a4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-420) /* -0x1a4 */);
    // 0049f7d5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049f7d6  89955cfeffff           -mov dword ptr [ebp - 0x1a4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-420) /* -0x1a4 */) = cpu.edx;
    // 0049f7dc  ff15cc057a00           -call dword ptr [0x7a05cc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(7996876) /* 0x7a05cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049f7e2  837df800               +cmp dword ptr [ebp - 8], 0
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
    // 0049f7e6  7506                   -jne 0x49f7ee
    if (!cpu.flags.zf)
    {
        goto L_0x0049f7ee;
    }
    // 0049f7e8  837dfc00               +cmp dword ptr [ebp - 4], 0
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
    // 0049f7ec  7410                   -je 0x49f7fe
    if (cpu.flags.zf)
    {
        goto L_0x0049f7fe;
    }
L_0x0049f7ee:
    // 0049f7ee  e85d040000             -call 0x49fc50
    cpu.esp -= 4;
    sub_49fc50(app, cpu);
    if (cpu.terminate) return;
    // 0049f7f3  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049f7f8  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0049f7fa  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f7fb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f7fc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f7fd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049f7fe:
    // 0049f7fe  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0049f800:
    // 0049f800  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0049f802  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f803  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f804  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f805  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_49f810(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049f810  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049f811  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049f812  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049f813  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049f815  81ec90010000           -sub esp, 0x190
    (cpu.esp) -= x86::reg32(x86::sreg32(400 /*0x190*/));
    // 0049f81b  6a3f                   -push 0x3f
    app->getMemory<x86::reg32>(cpu.esp-4) = 63 /*0x3f*/;
    cpu.esp -= 4;
    // 0049f81d  2eff1550475300         -call dword ptr cs:[0x534750]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457744) /* 0x534750 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049f824  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 0049f826  7407                   -je 0x49f82f
    if (cpu.flags.zf)
    {
        goto L_0x0049f82f;
    }
    // 0049f828  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049f82d  eb41                   -jmp 0x49f870
    goto L_0x0049f870;
L_0x0049f82f:
    // 0049f82f  8d8570feffff           -lea eax, [ebp - 0x190]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-400) /* -0x190 */);
    // 0049f835  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049f836  6801010000             -push 0x101
    app->getMemory<x86::reg32>(cpu.esp-4) = 257 /*0x101*/;
    cpu.esp -= 4;
    // 0049f83b  e870460900             -call 0x533eb0
    cpu.esp -= 4;
    sub_533eb0(app, cpu);
    if (cpu.terminate) return;
    // 0049f840  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049f842  752a                   -jne 0x49f86e
    if (!cpu.flags.zf)
    {
        goto L_0x0049f86e;
    }
    // 0049f844  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049f845  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0049f847  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0049f849  e85c460900             -call 0x533eaa
    cpu.esp -= 4;
    sub_533eaa(app, cpu);
    if (cpu.terminate) return;
    // 0049f84e  83f8ff                 +cmp eax, -1
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
    // 0049f851  7416                   -je 0x49f869
    if (cpu.flags.zf)
    {
        goto L_0x0049f869;
    }
    // 0049f853  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049f854  e84b460900             -call 0x533ea4
    cpu.esp -= 4;
    sub_533ea4(app, cpu);
    if (cpu.terminate) return;
    // 0049f859  e840460900             -call 0x533e9e
    cpu.esp -= 4;
    sub_533e9e(app, cpu);
    if (cpu.terminate) return;
    // 0049f85e  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049f863  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0049f865  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f866  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f867  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f868  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049f869:
    // 0049f869  e830460900             -call 0x533e9e
    cpu.esp -= 4;
    sub_533e9e(app, cpu);
    if (cpu.terminate) return;
L_0x0049f86e:
    // 0049f86e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0049f870:
    // 0049f870  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0049f872  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f873  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f874  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f875  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_49f880(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049f880  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049f881  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049f882  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049f883  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049f884  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049f885  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049f886  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049f888  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049f88b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049f88d  c745f8c0190000         -mov dword ptr [ebp - 8], 0x19c0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = 6592 /*0x19c0*/;
    // 0049f894  e8c7020000             -call 0x49fb60
    cpu.esp -= 4;
    sub_49fb60(app, cpu);
    if (cpu.terminate) return;
    // 0049f899  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049f89b  0f8490000000           -je 0x49f931
    if (cpu.flags.zf)
    {
        goto L_0x0049f931;
    }
    // 0049f8a1  68e4057a00             -push 0x7a05e4
    app->getMemory<x86::reg32>(cpu.esp-4) = 7996900 /*0x7a05e4*/;
    cpu.esp -= 4;
    // 0049f8a6  8d45f8                 -lea eax, [ebp - 8]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0049f8a9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049f8aa  68e8057a00             -push 0x7a05e8
    app->getMemory<x86::reg32>(cpu.esp-4) = 7996904 /*0x7a05e8*/;
    cpu.esp -= 4;
    // 0049f8af  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049f8b1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049f8b2  bb08010000             -mov ebx, 0x108
    cpu.ebx = 264 /*0x108*/;
    // 0049f8b7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049f8b8  890de4057a00           -mov dword ptr [0x7a05e4], ecx
    app->getMemory<x86::reg32>(x86::reg32(7996900) /* 0x7a05e4 */) = cpu.ecx;
    // 0049f8be  891de8057a00           -mov dword ptr [0x7a05e8], ebx
    app->getMemory<x86::reg32>(x86::reg32(7996904) /* 0x7a05e8 */) = cpu.ebx;
    // 0049f8c4  ff15d0057a00           -call dword ptr [0x7a05d0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(7996880) /* 0x7a05d0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049f8ca  83f808                 +cmp eax, 8
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
    // 0049f8cd  720b                   -jb 0x49f8da
    if (cpu.flags.cf)
    {
        goto L_0x0049f8da;
    }
    // 0049f8cf  7611                   -jbe 0x49f8e2
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049f8e2;
    }
    // 0049f8d1  3d5b020000             +cmp eax, 0x25b
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(603 /*0x25b*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049f8d6  740a                   -je 0x49f8e2
    if (cpu.flags.zf)
    {
        goto L_0x0049f8e2;
    }
    // 0049f8d8  eb04                   -jmp 0x49f8de
    goto L_0x0049f8de;
L_0x0049f8da:
    // 0049f8da  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049f8dc  7404                   -je 0x49f8e2
    if (cpu.flags.zf)
    {
        goto L_0x0049f8e2;
    }
L_0x0049f8de:
    // 0049f8de  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0049f8e0  eb4f                   -jmp 0x49f931
    goto L_0x0049f931;
L_0x0049f8e2:
    // 0049f8e2  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049f8e4  7446                   -je 0x49f92c
    if (cpu.flags.zf)
    {
        goto L_0x0049f92c;
    }
    // 0049f8e6  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0049f8e8:
    // 0049f8e8  3b0de4057a00           +cmp ecx, dword ptr [0x7a05e4]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(7996900) /* 0x7a05e4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049f8ee  733c                   -jae 0x49f92c
    if (!cpu.flags.cf)
    {
        goto L_0x0049f92c;
    }
    // 0049f8f0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049f8f2  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 0049f8f5  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049f8f7  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0049f8fa  05e8057a00             -add eax, 0x7a05e8
    (cpu.eax) += x86::reg32(x86::sreg32(7996904 /*0x7a05e8*/));
    // 0049f8ff  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049f902  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0049f905  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 0049f90c  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049f90e  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049f911  01c8                   +add eax, ecx
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
    // 0049f913  bb14000000             -mov ebx, 0x14
    cpu.ebx = 20 /*0x14*/;
    // 0049f918  8d3c06                 -lea edi, [esi + eax]
    cpu.edi = x86::reg32(cpu.esi + cpu.eax * 1);
    // 0049f91b  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0049f91e  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049f920  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0049f921  e80a150400             -call 0x4e0e30
    cpu.esp -= 4;
    sub_4e0e30(app, cpu);
    if (cpu.terminate) return;
    // 0049f926  c6471400               -mov byte ptr [edi + 0x14], 0
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 0049f92a  ebbc                   -jmp 0x49f8e8
    goto L_0x0049f8e8;
L_0x0049f92c:
    // 0049f92c  a1e4057a00             -mov eax, dword ptr [0x7a05e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7996900) /* 0x7a05e4 */);
L_0x0049f931:
    // 0049f931  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0049f933  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f934  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f935  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f936  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f937  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f938  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f939  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_49f940(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049f940  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049f941  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049f942  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049f943  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049f944  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049f946  81ec1c040000           -sub esp, 0x41c
    (cpu.esp) -= x86::reg32(x86::sreg32(1052 /*0x41c*/));
    // 0049f94c  833dc4057a0000         +cmp dword ptr [0x7a05c4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7996868) /* 0x7a05c4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049f953  0f8521010000           -jne 0x49fa7a
    if (!cpu.flags.zf)
    {
        goto L_0x0049fa7a;
    }
    // 0049f959  3b05e4057a00           +cmp eax, dword ptr [0x7a05e4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(7996900) /* 0x7a05e4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049f95f  7602                   -jbe 0x49f963
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049f963;
    }
    // 0049f961  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0049f963:
    // 0049f963  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049f965  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 0049f968  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049f96a  bf1c040000             -mov edi, 0x41c
    cpu.edi = 1052 /*0x41c*/;
    // 0049f96f  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0049f972  89bde4fbffff           -mov dword ptr [ebp - 0x41c], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-1052) /* -0x41c */) = cpu.edi;
    // 0049f978  05e8057a00             -add eax, 0x7a05e8
    (cpu.eax) += x86::reg32(x86::sreg32(7996904 /*0x7a05e8*/));
    // 0049f97d  8dbde8fbffff           -lea edi, [ebp - 0x418]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-1048) /* -0x418 */);
    // 0049f983  8d7004                 -lea esi, [eax + 4]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049f986  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0049f987:
    // 0049f987  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0049f989  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0049f98b  3c00                   +cmp al, 0
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
    // 0049f98d  7410                   -je 0x49f99f
    if (cpu.flags.zf)
    {
        goto L_0x0049f99f;
    }
    // 0049f98f  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0049f992  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049f995  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0049f998  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049f99b  3c00                   +cmp al, 0
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
    // 0049f99d  75e8                   -jne 0x49f987
    if (!cpu.flags.zf)
    {
        goto L_0x0049f987;
    }
L_0x0049f99f:
    // 0049f99f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f9a0  be18c75300             -mov esi, 0x53c718
    cpu.esi = 5490456 /*0x53c718*/;
    // 0049f9a5  8dbde9fcffff           -lea edi, [ebp - 0x317]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-791) /* -0x317 */);
    // 0049f9ab  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0049f9ac:
    // 0049f9ac  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0049f9ae  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0049f9b0  3c00                   +cmp al, 0
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
    // 0049f9b2  7410                   -je 0x49f9c4
    if (cpu.flags.zf)
    {
        goto L_0x0049f9c4;
    }
    // 0049f9b4  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0049f9b7  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049f9ba  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0049f9bd  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049f9c0  3c00                   +cmp al, 0
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
    // 0049f9c2  75e8                   -jne 0x49f9ac
    if (!cpu.flags.zf)
    {
        goto L_0x0049f9ac;
    }
L_0x0049f9c4:
    // 0049f9c4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f9c5  be18c75300             -mov esi, 0x53c718
    cpu.esi = 5490456 /*0x53c718*/;
    // 0049f9ca  8dbd6afdffff           -lea edi, [ebp - 0x296]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-662) /* -0x296 */);
    // 0049f9d0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0049f9d1:
    // 0049f9d1  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0049f9d3  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0049f9d5  3c00                   +cmp al, 0
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
    // 0049f9d7  7410                   -je 0x49f9e9
    if (cpu.flags.zf)
    {
        goto L_0x0049f9e9;
    }
    // 0049f9d9  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0049f9dc  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049f9df  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0049f9e2  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049f9e5  3c00                   +cmp al, 0
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
    // 0049f9e7  75e8                   -jne 0x49f9d1
    if (!cpu.flags.zf)
    {
        goto L_0x0049f9d1;
    }
L_0x0049f9e9:
    // 0049f9e9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049f9ea  be18c75300             -mov esi, 0x53c718
    cpu.esi = 5490456 /*0x53c718*/;
    // 0049f9ef  8d7ded                 -lea edi, [ebp - 0x13]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-19) /* -0x13 */);
    // 0049f9f2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0049f9f3:
    // 0049f9f3  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0049f9f5  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0049f9f7  3c00                   +cmp al, 0
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
    // 0049f9f9  7410                   -je 0x49fa0b
    if (cpu.flags.zf)
    {
        goto L_0x0049fa0b;
    }
    // 0049f9fb  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0049f9fe  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049fa01  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0049fa04  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049fa07  3c00                   +cmp al, 0
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
    // 0049fa09  75e8                   -jne 0x49f9f3
    if (!cpu.flags.zf)
    {
        goto L_0x0049f9f3;
    }
L_0x0049fa0b:
    // 0049fa0b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fa0c  8dbdebfdffff           -lea edi, [ebp - 0x215]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-533) /* -0x215 */);
    // 0049fa12  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0049fa14  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0049fa15:
    // 0049fa15  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0049fa17  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0049fa19  3c00                   +cmp al, 0
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
    // 0049fa1b  7410                   -je 0x49fa2d
    if (cpu.flags.zf)
    {
        goto L_0x0049fa2d;
    }
    // 0049fa1d  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0049fa20  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049fa23  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0049fa26  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049fa29  3c00                   +cmp al, 0
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
    // 0049fa2b  75e8                   -jne 0x49fa15
    if (!cpu.flags.zf)
    {
        goto L_0x0049fa15;
    }
L_0x0049fa2d:
    // 0049fa2d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fa2e  8dbdecfeffff           -lea edi, [ebp - 0x114]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-276) /* -0x114 */);
    // 0049fa34  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0049fa36  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0049fa37:
    // 0049fa37  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0049fa39  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0049fa3b  3c00                   +cmp al, 0
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
    // 0049fa3d  7410                   -je 0x49fa4f
    if (cpu.flags.zf)
    {
        goto L_0x0049fa4f;
    }
    // 0049fa3f  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0049fa42  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049fa45  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0049fa48  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049fa4b  3c00                   +cmp al, 0
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
    // 0049fa4d  75e8                   -jne 0x49fa37
    if (!cpu.flags.zf)
    {
        goto L_0x0049fa37;
    }
L_0x0049fa4f:
    // 0049fa4f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fa50  68c4057a00             -push 0x7a05c4
    app->getMemory<x86::reg32>(cpu.esp-4) = 7996868 /*0x7a05c4*/;
    cpu.esp -= 4;
    // 0049fa55  6880fc4900             -push 0x49fc80
    app->getMemory<x86::reg32>(cpu.esp-4) = 4848768 /*0x49fc80*/;
    cpu.esp -= 4;
    // 0049fa5a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049fa5c  8d85e4fbffff           -lea eax, [ebp - 0x41c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-1052) /* -0x41c */);
    // 0049fa62  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049fa63  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049fa65  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0049fa67  ff15c8057a00           -call dword ptr [0x7a05c8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(7996872) /* 0x7a05c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049fa6d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049fa6f  7409                   -je 0x49fa7a
    if (cpu.flags.zf)
    {
        goto L_0x0049fa7a;
    }
    // 0049fa71  e81a000000             -call 0x49fa90
    cpu.esp -= 4;
    sub_49fa90(app, cpu);
    if (cpu.terminate) return;
    // 0049fa76  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0049fa78  eb05                   -jmp 0x49fa7f
    goto L_0x0049fa7f;
L_0x0049fa7a:
    // 0049fa7a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0049fa7f:
    // 0049fa7f  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0049fa81  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fa82  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fa83  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fa84  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fa85  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_49fa90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049fa90  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049fa91  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049fa92  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049fa93  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049fa94  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049fa95  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049fa96  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049fa98  81eca0000000           -sub esp, 0xa0
    (cpu.esp) -= x86::reg32(x86::sreg32(160 /*0xa0*/));
    // 0049fa9e  8b15c4057a00           -mov edx, dword ptr [0x7a05c4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(7996868) /* 0x7a05c4 */);
    // 0049faa4  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049faa6  7459                   -je 0x49fb01
    if (cpu.flags.zf)
    {
        goto L_0x0049fb01;
    }
    // 0049faa8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049faa9  bba0000000             -mov ebx, 0xa0
    cpu.ebx = 160 /*0xa0*/;
    // 0049faae  ff15d8057a00           -call dword ptr [0x7a05d8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(7996888) /* 0x7a05d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049fab4  899d60ffffff           -mov dword ptr [ebp - 0xa0], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-160) /* -0xa0 */) = cpu.ebx;
    // 0049faba  2eff1568455300         -call dword ptr cs:[0x534568]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457256) /* 0x534568 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049fac1  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x0049fac3:
    // 0049fac3  8d8560ffffff           -lea eax, [ebp - 0xa0]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-160) /* -0xa0 */);
    // 0049fac9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049faca  8b35c4057a00           -mov esi, dword ptr [0x7a05c4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(7996868) /* 0x7a05c4 */);
    // 0049fad0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049fad1  ff15d4057a00           -call dword ptr [0x7a05d4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(7996884) /* 0x7a05d4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049fad7  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049fad9  2eff1568455300         -call dword ptr cs:[0x534568]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457256) /* 0x534568 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049fae0  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049fae2  39c3                   +cmp ebx, eax
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
    // 0049fae4  7604                   -jbe 0x49faea
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049faea;
    }
    // 0049fae6  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049fae8  eb02                   -jmp 0x49faec
    goto L_0x0049faec;
L_0x0049faea:
    // 0049faea  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0049faec:
    // 0049faec  83fe06                 +cmp esi, 6
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
    // 0049faef  75d2                   -jne 0x49fac3
    if (!cpu.flags.zf)
    {
        goto L_0x0049fac3;
    }
    // 0049faf1  81fab80b0000           +cmp edx, 0xbb8
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3000 /*0xbb8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049faf7  77ca                   -ja 0x49fac3
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0049fac3;
    }
    // 0049faf9  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0049fafb  893dc4057a00           -mov dword ptr [0x7a05c4], edi
    app->getMemory<x86::reg32>(x86::reg32(7996868) /* 0x7a05c4 */) = cpu.edi;
L_0x0049fb01:
    // 0049fb01  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0049fb03  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fb04  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fb05  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fb06  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fb07  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fb08  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fb09  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_49fb10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049fb10  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049fb11  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049fb13  833dc0057a0000         +cmp dword ptr [0x7a05c0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7996864) /* 0x7a05c0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049fb1a  743d                   -je 0x49fb59
    if (cpu.flags.zf)
    {
        goto L_0x0049fb59;
    }
    // 0049fb1c  833dc8057a0000         +cmp dword ptr [0x7a05c8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7996872) /* 0x7a05c8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049fb23  7434                   -je 0x49fb59
    if (cpu.flags.zf)
    {
        goto L_0x0049fb59;
    }
    // 0049fb25  833dcc057a0000         +cmp dword ptr [0x7a05cc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7996876) /* 0x7a05cc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049fb2c  742b                   -je 0x49fb59
    if (cpu.flags.zf)
    {
        goto L_0x0049fb59;
    }
    // 0049fb2e  833dd0057a0000         +cmp dword ptr [0x7a05d0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7996880) /* 0x7a05d0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049fb35  7422                   -je 0x49fb59
    if (cpu.flags.zf)
    {
        goto L_0x0049fb59;
    }
    // 0049fb37  833dd4057a0000         +cmp dword ptr [0x7a05d4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7996884) /* 0x7a05d4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049fb3e  7419                   -je 0x49fb59
    if (cpu.flags.zf)
    {
        goto L_0x0049fb59;
    }
    // 0049fb40  833dd8057a0000         +cmp dword ptr [0x7a05d8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7996888) /* 0x7a05d8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049fb47  7410                   -je 0x49fb59
    if (cpu.flags.zf)
    {
        goto L_0x0049fb59;
    }
    // 0049fb49  833ddc057a0000         +cmp dword ptr [0x7a05dc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7996892) /* 0x7a05dc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049fb50  7407                   -je 0x49fb59
    if (cpu.flags.zf)
    {
        goto L_0x0049fb59;
    }
    // 0049fb52  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049fb57  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fb58  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049fb59:
    // 0049fb59  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049fb5b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fb5c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49fb60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049fb60  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049fb61  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049fb62  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049fb63  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049fb64  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049fb65  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049fb66  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049fb68  e8a3ffffff             -call 0x49fb10
    cpu.esp -= 4;
    sub_49fb10(app, cpu);
    if (cpu.terminate) return;
    // 0049fb6d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049fb6f  740a                   -je 0x49fb7b
    if (cpu.flags.zf)
    {
        goto L_0x0049fb7b;
    }
    // 0049fb71  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049fb76  e9c2000000             -jmp 0x49fc3d
    goto L_0x0049fc3d;
L_0x0049fb7b:
    // 0049fb7b  681cc75300             -push 0x53c71c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5490460 /*0x53c71c*/;
    cpu.esp -= 4;
    // 0049fb80  2eff158c455300         -call dword ptr cs:[0x53458c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457292) /* 0x53458c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049fb87  a3c0057a00             -mov dword ptr [0x7a05c0], eax
    app->getMemory<x86::reg32>(x86::reg32(7996864) /* 0x7a05c0 */) = cpu.eax;
    // 0049fb8c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049fb8e  7507                   -jne 0x49fb97
    if (!cpu.flags.zf)
    {
        goto L_0x0049fb97;
    }
    // 0049fb90  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fb91  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fb92  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fb93  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fb94  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fb95  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fb96  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049fb97:
    // 0049fb97  6828c75300             -push 0x53c728
    app->getMemory<x86::reg32>(cpu.esp-4) = 5490472 /*0x53c728*/;
    cpu.esp -= 4;
    // 0049fb9c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049fb9d  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049fba4  6834c75300             -push 0x53c734
    app->getMemory<x86::reg32>(cpu.esp-4) = 5490484 /*0x53c734*/;
    cpu.esp -= 4;
    // 0049fba9  8b15c0057a00           -mov edx, dword ptr [0x7a05c0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(7996864) /* 0x7a05c0 */);
    // 0049fbaf  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049fbb0  a3c8057a00             -mov dword ptr [0x7a05c8], eax
    app->getMemory<x86::reg32>(x86::reg32(7996872) /* 0x7a05c8 */) = cpu.eax;
    // 0049fbb5  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049fbbc  6848c75300             -push 0x53c748
    app->getMemory<x86::reg32>(cpu.esp-4) = 5490504 /*0x53c748*/;
    cpu.esp -= 4;
    // 0049fbc1  8b0dc0057a00           -mov ecx, dword ptr [0x7a05c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(7996864) /* 0x7a05c0 */);
    // 0049fbc7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049fbc8  a3cc057a00             -mov dword ptr [0x7a05cc], eax
    app->getMemory<x86::reg32>(x86::reg32(7996876) /* 0x7a05cc */) = cpu.eax;
    // 0049fbcd  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049fbd4  6858c75300             -push 0x53c758
    app->getMemory<x86::reg32>(cpu.esp-4) = 5490520 /*0x53c758*/;
    cpu.esp -= 4;
    // 0049fbd9  8b1dc0057a00           -mov ebx, dword ptr [0x7a05c0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(7996864) /* 0x7a05c0 */);
    // 0049fbdf  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049fbe0  a3d0057a00             -mov dword ptr [0x7a05d0], eax
    app->getMemory<x86::reg32>(x86::reg32(7996880) /* 0x7a05d0 */) = cpu.eax;
    // 0049fbe5  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049fbec  6870c75300             -push 0x53c770
    app->getMemory<x86::reg32>(cpu.esp-4) = 5490544 /*0x53c770*/;
    cpu.esp -= 4;
    // 0049fbf1  8b35c0057a00           -mov esi, dword ptr [0x7a05c0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(7996864) /* 0x7a05c0 */);
    // 0049fbf7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049fbf8  a3d4057a00             -mov dword ptr [0x7a05d4], eax
    app->getMemory<x86::reg32>(x86::reg32(7996884) /* 0x7a05d4 */) = cpu.eax;
    // 0049fbfd  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049fc04  687cc75300             -push 0x53c77c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5490556 /*0x53c77c*/;
    cpu.esp -= 4;
    // 0049fc09  8b3dc0057a00           -mov edi, dword ptr [0x7a05c0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(7996864) /* 0x7a05c0 */);
    // 0049fc0f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049fc10  a3d8057a00             -mov dword ptr [0x7a05d8], eax
    app->getMemory<x86::reg32>(x86::reg32(7996888) /* 0x7a05d8 */) = cpu.eax;
    // 0049fc15  2eff1558455300         -call dword ptr cs:[0x534558]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457240) /* 0x534558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049fc1c  a3dc057a00             -mov dword ptr [0x7a05dc], eax
    app->getMemory<x86::reg32>(x86::reg32(7996892) /* 0x7a05dc */) = cpu.eax;
    // 0049fc21  e8eafeffff             -call 0x49fb10
    cpu.esp -= 4;
    sub_49fb10(app, cpu);
    if (cpu.terminate) return;
    // 0049fc26  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049fc28  740c                   -je 0x49fc36
    if (cpu.flags.zf)
    {
        goto L_0x0049fc36;
    }
    // 0049fc2a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049fc2f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fc30  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fc31  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fc32  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fc33  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fc34  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fc35  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049fc36:
    // 0049fc36  e815000000             -call 0x49fc50
    cpu.esp -= 4;
    sub_49fc50(app, cpu);
    if (cpu.terminate) return;
    // 0049fc3b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0049fc3d:
    // 0049fc3d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fc3e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fc3f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fc40  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fc41  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fc42  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fc43  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_49fc50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049fc50  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049fc51  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049fc52  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049fc53  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049fc55  8b15c0057a00           -mov edx, dword ptr [0x7a05c0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(7996864) /* 0x7a05c0 */);
    // 0049fc5b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049fc5d  7417                   -je 0x49fc76
    if (cpu.flags.zf)
    {
        goto L_0x0049fc76;
    }
    // 0049fc5f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049fc60  2eff15dc445300         -call dword ptr cs:[0x5344dc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457116) /* 0x5344dc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049fc67  ba24000000             -mov edx, 0x24
    cpu.edx = 36 /*0x24*/;
    // 0049fc6c  b8c0057a00             -mov eax, 0x7a05c0
    cpu.eax = 7996864 /*0x7a05c0*/;
    // 0049fc71  e8960a0400             -call 0x4e070c
    cpu.esp -= 4;
    sub_4e070c(app, cpu);
    if (cpu.terminate) return;
L_0x0049fc76:
    // 0049fc76  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fc77  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fc78  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fc79  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_49fc80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049fc80  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049fc81  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049fc82  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049fc84  81ec04020000           -sub esp, 0x204
    (cpu.esp) -= x86::reg32(x86::sreg32(516 /*0x204*/));
    // 0049fc8a  8b5d10                 -mov ebx, dword ptr [ebp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0049fc8d  8b5514                 -mov edx, dword ptr [ebp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0049fc90  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049fc92  7415                   -je 0x49fca9
    if (cpu.flags.zf)
    {
        goto L_0x0049fca9;
    }
    // 0049fc94  6801020000             -push 0x201
    app->getMemory<x86::reg32>(cpu.esp-4) = 513 /*0x201*/;
    cpu.esp -= 4;
    // 0049fc99  8d85fcfdffff           -lea eax, [ebp - 0x204]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-516) /* -0x204 */);
    // 0049fc9f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049fca0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049fca1  ff15e0057a00           -call dword ptr [0x7a05e0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(7996896) /* 0x7a05e0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049fca7  85c0                   -test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
L_0x0049fca9:
    // 0049fca9  83fb0e                 +cmp ebx, 0xe
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(14 /*0xe*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049fcac  0f82a3000000           -jb 0x49fd55
    if (cpu.flags.cf)
    {
        goto L_0x0049fd55;
    }
    // 0049fcb2  0f86de000000           -jbe 0x49fd96
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049fd96;
    }
    // 0049fcb8  83fb16                 +cmp ebx, 0x16
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(22 /*0x16*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049fcbb  7265                   -jb 0x49fd22
    if (cpu.flags.cf)
    {
        goto L_0x0049fd22;
    }
    // 0049fcbd  0f86d3000000           -jbe 0x49fd96
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049fd96;
    }
    // 0049fcc3  81fb02100000           +cmp ebx, 0x1002
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4098 /*0x1002*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049fcc9  7236                   -jb 0x49fd01
    if (cpu.flags.cf)
    {
        goto L_0x0049fd01;
    }
    // 0049fccb  0f86c5000000           -jbe 0x49fd96
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049fd96;
    }
    // 0049fcd1  81fb00200000           +cmp ebx, 0x2000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8192 /*0x2000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049fcd7  7217                   -jb 0x49fcf0
    if (cpu.flags.cf)
    {
        goto L_0x0049fcf0;
    }
    // 0049fcd9  0f86b7000000           -jbe 0x49fd96
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049fd96;
    }
    // 0049fcdf  81fb01200000           +cmp ebx, 0x2001
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8193 /*0x2001*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049fce5  0f84ab000000           -je 0x49fd96
    if (cpu.flags.zf)
    {
        goto L_0x0049fd96;
    }
    // 0049fceb  e9a6000000             -jmp 0x49fd96
    goto L_0x0049fd96;
L_0x0049fcf0:
    // 0049fcf0  81fb03100000           +cmp ebx, 0x1003
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4099 /*0x1003*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049fcf6  0f849a000000           -je 0x49fd96
    if (cpu.flags.zf)
    {
        goto L_0x0049fd96;
    }
    // 0049fcfc  e995000000             -jmp 0x49fd96
    goto L_0x0049fd96;
L_0x0049fd01:
    // 0049fd01  81fb00100000           +cmp ebx, 0x1000
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
    // 0049fd07  720b                   -jb 0x49fd14
    if (cpu.flags.cf)
    {
        goto L_0x0049fd14;
    }
    // 0049fd09  0f8687000000           -jbe 0x49fd96
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049fd96;
    }
    // 0049fd0f  e982000000             -jmp 0x49fd96
    goto L_0x0049fd96;
L_0x0049fd14:
    // 0049fd14  83fb17                 +cmp ebx, 0x17
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(23 /*0x17*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049fd17  0f8479000000           -je 0x49fd96
    if (cpu.flags.zf)
    {
        goto L_0x0049fd96;
    }
    // 0049fd1d  e974000000             -jmp 0x49fd96
    goto L_0x0049fd96;
L_0x0049fd22:
    // 0049fd22  83fb12                 +cmp ebx, 0x12
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(18 /*0x12*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049fd25  721c                   -jb 0x49fd43
    if (cpu.flags.cf)
    {
        goto L_0x0049fd43;
    }
    // 0049fd27  0f8669000000           -jbe 0x49fd96
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049fd96;
    }
    // 0049fd2d  83fb14                 +cmp ebx, 0x14
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(20 /*0x14*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049fd30  0f8260000000           -jb 0x49fd96
    if (cpu.flags.cf)
    {
        goto L_0x0049fd96;
    }
    // 0049fd36  0f865a000000           -jbe 0x49fd96
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049fd96;
    }
    // 0049fd3c  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0049fd3e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fd3f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fd40  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x0049fd43:
    // 0049fd43  83fb10                 +cmp ebx, 0x10
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
    // 0049fd46  0f824a000000           -jb 0x49fd96
    if (cpu.flags.cf)
    {
        goto L_0x0049fd96;
    }
    // 0049fd4c  7648                   -jbe 0x49fd96
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049fd96;
    }
    // 0049fd4e  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0049fd50  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fd51  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fd52  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x0049fd55:
    // 0049fd55  83fb06                 +cmp ebx, 6
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049fd58  7225                   -jb 0x49fd7f
    if (cpu.flags.cf)
    {
        goto L_0x0049fd7f;
    }
    // 0049fd5a  763a                   -jbe 0x49fd96
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049fd96;
    }
    // 0049fd5c  83fb0a                 +cmp ebx, 0xa
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
    // 0049fd5f  7210                   -jb 0x49fd71
    if (cpu.flags.cf)
    {
        goto L_0x0049fd71;
    }
    // 0049fd61  7633                   -jbe 0x49fd96
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049fd96;
    }
    // 0049fd63  83fb0c                 +cmp ebx, 0xc
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
    // 0049fd66  722e                   -jb 0x49fd96
    if (cpu.flags.cf)
    {
        goto L_0x0049fd96;
    }
    // 0049fd68  762c                   -jbe 0x49fd96
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049fd96;
    }
    // 0049fd6a  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0049fd6c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fd6d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fd6e  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x0049fd71:
    // 0049fd71  83fb08                 +cmp ebx, 8
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
    // 0049fd74  7220                   -jb 0x49fd96
    if (cpu.flags.cf)
    {
        goto L_0x0049fd96;
    }
    // 0049fd76  761e                   -jbe 0x49fd96
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049fd96;
    }
    // 0049fd78  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0049fd7a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fd7b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fd7c  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x0049fd7f:
    // 0049fd7f  83fb02                 +cmp ebx, 2
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
    // 0049fd82  7210                   -jb 0x49fd94
    if (cpu.flags.cf)
    {
        goto L_0x0049fd94;
    }
    // 0049fd84  7610                   -jbe 0x49fd96
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049fd96;
    }
    // 0049fd86  83fb04                 +cmp ebx, 4
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
    // 0049fd89  720b                   -jb 0x49fd96
    if (cpu.flags.cf)
    {
        goto L_0x0049fd96;
    }
    // 0049fd8b  7609                   -jbe 0x49fd96
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049fd96;
    }
    // 0049fd8d  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0049fd8f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fd90  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fd91  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x0049fd94:
    // 0049fd94  85db                   -test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
L_0x0049fd96:
    // 0049fd96  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0049fd98  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fd99  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fd9a  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49fda0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049fda0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049fda1  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049fda3  e8e8f9ffff             -call 0x49f790
    cpu.esp -= 4;
    sub_49f790(app, cpu);
    if (cpu.terminate) return;
    // 0049fda8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049fdaa  750e                   -jne 0x49fdba
    if (!cpu.flags.zf)
    {
        goto L_0x0049fdba;
    }
    // 0049fdac  b870047a00             -mov eax, 0x7a0470
    cpu.eax = 7996528 /*0x7a0470*/;
    // 0049fdb1  e8cafaffff             -call 0x49f880
    cpu.esp -= 4;
    sub_49f880(app, cpu);
    if (cpu.terminate) return;
    // 0049fdb6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049fdb8  7405                   -je 0x49fdbf
    if (cpu.flags.zf)
    {
        goto L_0x0049fdbf;
    }
L_0x0049fdba:
    // 0049fdba  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0049fdbf:
    // 0049fdbf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fdc0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_49fdd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049fdd0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0049fdd2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0049fdd4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0049fdd6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0049fdd8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0049fdda  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0049fddc  8d442000               -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 0049fde0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049fde1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049fde2  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049fde4  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049fde7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049fde9  833da0d46f0000         +cmp dword ptr [0x6fd4a0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7328928) /* 0x6fd4a0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049fdf0  7437                   -je 0x49fe29
    if (cpu.flags.zf)
    {
        goto L_0x0049fe29;
    }
    // 0049fdf2  f6800002000004         +test byte ptr [eax + 0x200], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(512) /* 0x200 */) & 4 /*0x4*/));
    // 0049fdf9  742e                   -je 0x49fe29
    if (cpu.flags.zf)
    {
        goto L_0x0049fe29;
    }
    // 0049fdfb  d9820c010000           +fld dword ptr [edx + 0x10c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(268) /* 0x10c */)));
    // 0049fe01  dc1d94c75300           +fcomp qword ptr [0x53c794]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(5490580) /* 0x53c794 */)));
    cpu.fpu.pop();
    // 0049fe07  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0049fe09  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0049fe0a  720c                   -jb 0x49fe18
    if (cpu.flags.cf)
    {
        goto L_0x0049fe18;
    }
    // 0049fe0c  81ba0c0100000000003f   +cmp dword ptr [edx + 0x10c], 0x3f000000
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(268) /* 0x10c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1056964608 /*0x3f000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049fe16  7e0a                   -jle 0x49fe22
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049fe22;
    }
L_0x0049fe18:
    // 0049fe18  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049fe1d  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0049fe1f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fe20  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fe21  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049fe22:
    // 0049fe22  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0049fe24  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0049fe26  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fe27  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fe28  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049fe29:
    // 0049fe29  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 0049fe2b  d89a0c010000           +fcomp dword ptr [edx + 0x10c]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(268) /* 0x10c */)));
    cpu.fpu.pop();
    // 0049fe31  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0049fe33  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0049fe34  760d                   -jbe 0x49fe43
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049fe43;
    }
    // 0049fe36  d9820c010000           +fld dword ptr [edx + 0x10c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(268) /* 0x10c */)));
    // 0049fe3c  d9e0                   +fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 0049fe3e  d95dfc                 +fstp dword ptr [ebp - 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049fe41  eb09                   -jmp 0x49fe4c
    goto L_0x0049fe4c;
L_0x0049fe43:
    // 0049fe43  8b820c010000           -mov eax, dword ptr [edx + 0x10c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(268) /* 0x10c */);
    // 0049fe49  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
L_0x0049fe4c:
    // 0049fe4c  d945fc                 +fld dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
    // 0049fe4f  d81d9cc75300           +fcomp dword ptr [0x53c79c]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(5490588) /* 0x53c79c */)));
    cpu.fpu.pop();
    // 0049fe55  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0049fe57  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0049fe58  760a                   -jbe 0x49fe64
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049fe64;
    }
    // 0049fe5a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049fe5f  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0049fe61  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fe62  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fe63  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049fe64:
    // 0049fe64  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049fe66  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0049fe68  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fe69  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fe6a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49fde0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0049fde0;
    // 0049fdd0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0049fdd2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0049fdd4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0049fdd6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0049fdd8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0049fdda  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0049fddc  8d442000               -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_entry_0x0049fde0:
    // 0049fde0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049fde1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049fde2  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049fde4  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049fde7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049fde9  833da0d46f0000         +cmp dword ptr [0x6fd4a0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7328928) /* 0x6fd4a0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049fdf0  7437                   -je 0x49fe29
    if (cpu.flags.zf)
    {
        goto L_0x0049fe29;
    }
    // 0049fdf2  f6800002000004         +test byte ptr [eax + 0x200], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(512) /* 0x200 */) & 4 /*0x4*/));
    // 0049fdf9  742e                   -je 0x49fe29
    if (cpu.flags.zf)
    {
        goto L_0x0049fe29;
    }
    // 0049fdfb  d9820c010000           +fld dword ptr [edx + 0x10c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(268) /* 0x10c */)));
    // 0049fe01  dc1d94c75300           +fcomp qword ptr [0x53c794]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(5490580) /* 0x53c794 */)));
    cpu.fpu.pop();
    // 0049fe07  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0049fe09  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0049fe0a  720c                   -jb 0x49fe18
    if (cpu.flags.cf)
    {
        goto L_0x0049fe18;
    }
    // 0049fe0c  81ba0c0100000000003f   +cmp dword ptr [edx + 0x10c], 0x3f000000
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(268) /* 0x10c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1056964608 /*0x3f000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049fe16  7e0a                   -jle 0x49fe22
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049fe22;
    }
L_0x0049fe18:
    // 0049fe18  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049fe1d  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0049fe1f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fe20  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fe21  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049fe22:
    // 0049fe22  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0049fe24  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0049fe26  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fe27  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fe28  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049fe29:
    // 0049fe29  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 0049fe2b  d89a0c010000           +fcomp dword ptr [edx + 0x10c]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(268) /* 0x10c */)));
    cpu.fpu.pop();
    // 0049fe31  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0049fe33  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0049fe34  760d                   -jbe 0x49fe43
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049fe43;
    }
    // 0049fe36  d9820c010000           +fld dword ptr [edx + 0x10c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(268) /* 0x10c */)));
    // 0049fe3c  d9e0                   +fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 0049fe3e  d95dfc                 +fstp dword ptr [ebp - 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049fe41  eb09                   -jmp 0x49fe4c
    goto L_0x0049fe4c;
L_0x0049fe43:
    // 0049fe43  8b820c010000           -mov eax, dword ptr [edx + 0x10c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(268) /* 0x10c */);
    // 0049fe49  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
L_0x0049fe4c:
    // 0049fe4c  d945fc                 +fld dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
    // 0049fe4f  d81d9cc75300           +fcomp dword ptr [0x53c79c]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(5490588) /* 0x53c79c */)));
    cpu.fpu.pop();
    // 0049fe55  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0049fe57  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0049fe58  760a                   -jbe 0x49fe64
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049fe64;
    }
    // 0049fe5a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049fe5f  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0049fe61  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fe62  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fe63  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049fe64:
    // 0049fe64  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049fe66  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0049fe68  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fe69  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fe6a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_49fe70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049fe70  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049fe71  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049fe72  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049fe73  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049fe75  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0049fe78  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049fe7a  d98098000000           -fld dword ptr [eax + 0x98]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(152) /* 0x98 */)));
    // 0049fe80  dc0da4c75300           -fmul qword ptr [0x53c7a4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5490596) /* 0x53c7a4 */));
    // 0049fe86  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049fe89  db1c24                 -fistp dword ptr [esp]
    app->getMemory<x86::reg32>(cpu.esp) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 0049fe8c  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fe8d  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 0049fe90  d9829c000000           -fld dword ptr [edx + 0x9c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(156) /* 0x9c */)));
    // 0049fe96  dc0da4c75300           -fmul qword ptr [0x53c7a4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5490596) /* 0x53c7a4 */));
    // 0049fe9c  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049fe9f  db1c24                 -fistp dword ptr [esp]
    app->getMemory<x86::reg32>(cpu.esp) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 0049fea2  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fea3  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 0049fea6  d982a0000000           -fld dword ptr [edx + 0xa0]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(160) /* 0xa0 */)));
    // 0049feac  dc0da4c75300           -fmul qword ptr [0x53c7a4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5490596) /* 0x53c7a4 */));
    // 0049feb2  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049feb5  db1c24                 -fistp dword ptr [esp]
    app->getMemory<x86::reg32>(cpu.esp) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 0049feb8  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049feb9  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0049febc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049febe  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0049fec3  8a8288000000           -mov al, byte ptr [edx + 0x88]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(136) /* 0x88 */);
    // 0049fec9  83c20c                 -add edx, 0xc
    (cpu.edx) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0049fecc  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049fece  8d45f4                 -lea eax, [ebp - 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0049fed1  e80af8f7ff             -call 0x41f6e0
    cpu.esp -= 4;
    sub_41f6e0(app, cpu);
    if (cpu.terminate) return;
    // 0049fed6  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0049fed8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fed9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049feda  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049fedb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_49fee0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049fee0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049fee1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049fee2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049fee3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049fee4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049fee5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049fee6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049fee8  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049feeb  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049feed  8b0d40d95d00           -mov ecx, dword ptr [0x5dd940]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6150464) /* 0x5dd940 */);
    // 0049fef3  40                     -inc eax
    (cpu.eax)++;
    // 0049fef4  39c8                   +cmp eax, ecx
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
    // 0049fef6  7c02                   -jl 0x49fefa
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049fefa;
    }
    // 0049fef8  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0049fefa:
    // 0049fefa  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049fefc  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0049feff  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049ff01  8b1d48d95d00           -mov ebx, dword ptr [0x5dd948]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(6150472) /* 0x5dd948 */);
    // 0049ff07  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049ff0a  8d3403                 -lea esi, [ebx + eax]
    cpu.esi = x86::reg32(cpu.ebx + cpu.eax * 1);
    // 0049ff0d  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 0049ff14  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049ff16  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049ff19  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049ff1b  8b3d40d95d00           -mov edi, dword ptr [0x5dd940]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(6150464) /* 0x5dd940 */);
    // 0049ff21  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0049ff23  8b33                   -mov esi, dword ptr [ebx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx);
    // 0049ff25  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049ff27  8d4201                 -lea eax, [edx + 1]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0049ff2a  29f3                   -sub ebx, esi
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0049ff2c  39f8                   +cmp eax, edi
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
    // 0049ff2e  7c02                   -jl 0x49ff32
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049ff32;
    }
    // 0049ff30  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
L_0x0049ff32:
    // 0049ff32  895dfc                 -mov dword ptr [ebp - 4], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 0049ff35  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049ff37  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 0049ff3a  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0049ff3d  dd05acc75300           -fld qword ptr [0x53c7ac]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(5490604) /* 0x53c7ac */)));
    // 0049ff43  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0049ff45  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 0049ff47  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049ff49  8b0d48d95d00           -mov ecx, dword ptr [0x5dd948]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6150472) /* 0x5dd948 */);
    // 0049ff4f  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049ff52  8d3401                 -lea esi, [ecx + eax]
    cpu.esi = x86::reg32(cpu.ecx + cpu.eax * 1);
    // 0049ff55  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 0049ff5c  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049ff5e  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049ff61  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049ff63  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0049ff66  8b7108                 -mov esi, dword ptr [ecx + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0049ff69  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0049ff6b  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0049ff6e  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 0049ff71  deca                   -fmulp st(2)
    cpu.fpu.st(2) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0049ff73  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049ff76  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0049ff78  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049ff7b  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049ff7e  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049ff81  e83aaa0400             -call 0x4ea9c0
    cpu.esp -= 4;
    sub_4ea9c0(app, cpu);
    if (cpu.terminate) return;
    // 0049ff86  dc0db4c75300           -fmul qword ptr [0x53c7b4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5490612) /* 0x53c7b4 */));
    // 0049ff8c  e8c5fd0300             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 0049ff91  db5df8                 -fistp dword ptr [ebp - 8]
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 0049ff94  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0049ff97  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0049ff99  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ff9a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ff9b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ff9c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ff9d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ff9e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049ff9f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49ffa0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049ffa0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049ffa1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049ffa2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049ffa3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049ffa4  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0049ffa6  83ec34                 -sub esp, 0x34
    (cpu.esp) -= x86::reg32(x86::sreg32(52 /*0x34*/));
    // 0049ffa9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049ffab  80b88900000000         +cmp byte ptr [eax + 0x89], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(137) /* 0x89 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049ffb2  0f84f5000000           -je 0x4a00ad
    if (cpu.flags.zf)
    {
        goto L_0x004a00ad;
    }
    // 0049ffb8  80b98800000000         -cmp byte ptr [ecx + 0x88], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(136) /* 0x88 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049ffbf  8d55cc                 -lea edx, [ebp - 0x34]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 0049ffc2  8d75f0                 -lea esi, [ebp - 0x10]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0049ffc5  8d410c                 -lea eax, [ecx + 0xc]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0049ffc8  e86302f8ff             -call 0x420230
    cpu.esp -= 4;
    sub_420230(app, cpu);
    if (cpu.terminate) return;
    // 0049ffcd  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0049ffd0  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0049ffd3  dd05bcc75300           -fld qword ptr [0x53c7bc]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(5490620) /* 0x53c7bc */)));
    // 0049ffd9  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 0049ffdc  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 0049ffde  d99948010000           -fstp dword ptr [ecx + 0x148]
    app->getMemory<float>(cpu.ecx + x86::reg32(328) /* 0x148 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049ffe4  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0049ffe7  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0049ffea  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 0049ffed  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 0049ffef  d9994c010000           -fstp dword ptr [ecx + 0x14c]
    app->getMemory<float>(cpu.ecx + x86::reg32(332) /* 0x14c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049fff5  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0049fff8  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0049fffb  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 0049fffe  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004a0000  d99950010000           -fstp dword ptr [ecx + 0x150]
    app->getMemory<float>(cpu.ecx + x86::reg32(336) /* 0x150 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a0006  8b45cc                 -mov eax, dword ptr [ebp - 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 004a0009  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004a000c  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 004a000f  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004a0011  d99924010000           -fstp dword ptr [ecx + 0x124]
    app->getMemory<float>(cpu.ecx + x86::reg32(292) /* 0x124 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a0017  8b45d0                 -mov eax, dword ptr [ebp - 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */);
    // 004a001a  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004a001d  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 004a0020  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004a0022  d99928010000           -fstp dword ptr [ecx + 0x128]
    app->getMemory<float>(cpu.ecx + x86::reg32(296) /* 0x128 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a0028  8b45d4                 -mov eax, dword ptr [ebp - 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 004a002b  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004a002e  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 004a0031  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004a0033  d9992c010000           -fstp dword ptr [ecx + 0x12c]
    app->getMemory<float>(cpu.ecx + x86::reg32(300) /* 0x12c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a0039  8b45d8                 -mov eax, dword ptr [ebp - 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 004a003c  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004a003f  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 004a0042  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004a0044  d99930010000           -fstp dword ptr [ecx + 0x130]
    app->getMemory<float>(cpu.ecx + x86::reg32(304) /* 0x130 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a004a  8b45dc                 -mov eax, dword ptr [ebp - 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 004a004d  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004a0050  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 004a0053  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004a0055  d99934010000           -fstp dword ptr [ecx + 0x134]
    app->getMemory<float>(cpu.ecx + x86::reg32(308) /* 0x134 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a005b  8b45e0                 -mov eax, dword ptr [ebp - 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 004a005e  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004a0061  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 004a0064  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004a0066  d99938010000           -fstp dword ptr [ecx + 0x138]
    app->getMemory<float>(cpu.ecx + x86::reg32(312) /* 0x138 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a006c  8b45e4                 -mov eax, dword ptr [ebp - 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004a006f  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004a0072  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 004a0075  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004a0077  d9993c010000           -fstp dword ptr [ecx + 0x13c]
    app->getMemory<float>(cpu.ecx + x86::reg32(316) /* 0x13c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a007d  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004a0080  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004a0083  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 004a0086  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004a0088  d99940010000           -fstp dword ptr [ecx + 0x140]
    app->getMemory<float>(cpu.ecx + x86::reg32(320) /* 0x140 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a008e  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004a0091  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004a0094  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 004a0097  dec9                   -fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004a0099  8b411c                 -mov eax, dword ptr [ecx + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 004a009c  d99944010000           -fstp dword ptr [ecx + 0x144]
    app->getMemory<float>(cpu.ecx + x86::reg32(324) /* 0x144 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a00a2  e839feffff             -call 0x49fee0
    cpu.esp -= 4;
    sub_49fee0(app, cpu);
    if (cpu.terminate) return;
    // 004a00a7  898154010000           -mov dword ptr [ecx + 0x154], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(340) /* 0x154 */) = cpu.eax;
L_0x004a00ad:
    // 004a00ad  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004a00af  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a00b0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a00b1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a00b2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a00b3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_4a00c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a00c0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a00c1  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a00c3  e858e0f6ff             -call 0x40e120
    cpu.esp -= 4;
    sub_40e120(app, cpu);
    if (cpu.terminate) return;
    // 004a00c8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a00c9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_4a00d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a00d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a00d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a00d2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a00d3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a00d4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a00d5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a00d6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a00d8  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a00db  8d7df0                 -lea edi, [ebp - 0x10]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004a00de  8db030010000           -lea esi, [eax + 0x130]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(304) /* 0x130 */);
    // 004a00e4  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a00e5  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a00e6  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a00e7  817df4cdcccc3d         +cmp dword ptr [ebp - 0xc], 0x3dcccccd
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1036831949 /*0x3dcccccd*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a00ee  7e39                   -jle 0x4a0129
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a0129;
    }
    // 004a00f0  8b88a0000000           -mov ecx, dword ptr [eax + 0xa0]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(160) /* 0xa0 */);
    // 004a00f6  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a00f7  8b989c000000           -mov ebx, dword ptr [eax + 0x9c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(156) /* 0x9c */);
    // 004a00fd  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a00fe  8bb098000000           -mov esi, dword ptr [eax + 0x98]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(152) /* 0x98 */);
    // 004a0104  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a0105  8bb850010000           -mov edi, dword ptr [eax + 0x150]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(336) /* 0x150 */);
    // 004a010b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a010c  8b904c010000           -mov edx, dword ptr [eax + 0x14c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(332) /* 0x14c */);
    // 004a0112  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a0113  8b8848010000           -mov ecx, dword ptr [eax + 0x148]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(328) /* 0x148 */);
    // 004a0119  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a011a  0524010000             +add eax, 0x124
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(292 /*0x124*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a011f  e87c67ffff             -call 0x4968a0
    cpu.esp -= 4;
    sub_4968a0(app, cpu);
    if (cpu.terminate) return;
    // 004a0124  d95dfc                 +fstp dword ptr [ebp - 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a0127  eb07                   -jmp 0x4a0130
    goto L_0x004a0130;
L_0x004a0129:
    // 004a0129  c745fc0000fac6         -mov dword ptr [ebp - 4], 0xc6fa0000
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 3338272768 /*0xc6fa0000*/;
L_0x004a0130:
    // 004a0130  d945fc                 -fld dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
    // 004a0133  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004a0135  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0136  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0137  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0138  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0139  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a013a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a013b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_4a0140(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a0140  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a0141  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a0142  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a0143  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a0144  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a0145  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a0146  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a0148  81eca4000000           -sub esp, 0xa4
    (cpu.esp) -= x86::reg32(x86::sreg32(164 /*0xa4*/));
    // 004a014e  81ed82000000           -sub ebp, 0x82
    (cpu.ebp) -= x86::reg32(x86::sreg32(130 /*0x82*/));
    // 004a0154  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a0156  d98014010000           -fld dword ptr [eax + 0x114]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(276) /* 0x114 */)));
    // 004a015c  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 004a015e  8b781c                 -mov edi, dword ptr [eax + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004a0161  d95dde                 -fstp dword ptr [ebp - 0x22]
    app->getMemory<float>(cpu.ebp + x86::reg32(-34) /* -0x22 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a0164  8b8018010000           -mov eax, dword ptr [eax + 0x118]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(280) /* 0x118 */);
    // 004a016a  8945e2                 -mov dword ptr [ebp - 0x1e], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-30) /* -0x1e */) = cpu.eax;
    // 004a016d  8b861c010000           -mov eax, dword ptr [esi + 0x11c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(284) /* 0x11c */);
    // 004a0173  8945e6                 -mov dword ptr [ebp - 0x1a], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-26) /* -0x1a */) = cpu.eax;
    // 004a0176  8b8614010000           -mov eax, dword ptr [esi + 0x114]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(276) /* 0x114 */);
    // 004a017c  8945ea                 -mov dword ptr [ebp - 0x16], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-22) /* -0x16 */) = cpu.eax;
    // 004a017f  8b8618010000           -mov eax, dword ptr [esi + 0x118]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(280) /* 0x118 */);
    // 004a0185  8945ee                 -mov dword ptr [ebp - 0x12], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-18) /* -0x12 */) = cpu.eax;
    // 004a0188  8b861c010000           -mov eax, dword ptr [esi + 0x11c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(284) /* 0x11c */);
    // 004a018e  8945f2                 -mov dword ptr [ebp - 0xe], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-14) /* -0xe */) = cpu.eax;
    // 004a0191  8b8614010000           -mov eax, dword ptr [esi + 0x114]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(276) /* 0x114 */);
    // 004a0197  8945f6                 -mov dword ptr [ebp - 0xa], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-10) /* -0xa */) = cpu.eax;
    // 004a019a  8b8618010000           -mov eax, dword ptr [esi + 0x118]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(280) /* 0x118 */);
    // 004a01a0  8945fa                 -mov dword ptr [ebp - 6], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-6) /* -0x6 */) = cpu.eax;
    // 004a01a3  d9861c010000           -fld dword ptr [esi + 0x11c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(284) /* 0x11c */)));
    // 004a01a9  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 004a01ab  d95dfe                 -fstp dword ptr [ebp - 2]
    app->getMemory<float>(cpu.ebp + x86::reg32(-2) /* -0x2 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a01ae  d98614010000           -fld dword ptr [esi + 0x114]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(276) /* 0x114 */)));
    // 004a01b4  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 004a01b6  d95d02                 -fstp dword ptr [ebp + 2]
    app->getMemory<float>(cpu.ebp + x86::reg32(2) /* 0x2 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a01b9  8b8618010000           -mov eax, dword ptr [esi + 0x118]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(280) /* 0x118 */);
    // 004a01bf  894506                 -mov dword ptr [ebp + 6], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(6) /* 0x6 */) = cpu.eax;
    // 004a01c2  d9861c010000           -fld dword ptr [esi + 0x11c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(284) /* 0x11c */)));
    // 004a01c8  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 004a01ca  d95d0a                 -fstp dword ptr [ebp + 0xa]
    app->getMemory<float>(cpu.ebp + x86::reg32(10) /* 0xa */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a01cd  d98614010000           -fld dword ptr [esi + 0x114]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(276) /* 0x114 */)));
    // 004a01d3  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 004a01d5  d95d0e                 -fstp dword ptr [ebp + 0xe]
    app->getMemory<float>(cpu.ebp + x86::reg32(14) /* 0xe */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a01d8  d98618010000           -fld dword ptr [esi + 0x118]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(280) /* 0x118 */)));
    // 004a01de  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 004a01e0  d95d12                 -fstp dword ptr [ebp + 0x12]
    app->getMemory<float>(cpu.ebp + x86::reg32(18) /* 0x12 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a01e3  8b861c010000           -mov eax, dword ptr [esi + 0x11c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(284) /* 0x11c */);
    // 004a01e9  894516                 -mov dword ptr [ebp + 0x16], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(22) /* 0x16 */) = cpu.eax;
    // 004a01ec  8b8614010000           -mov eax, dword ptr [esi + 0x114]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(276) /* 0x114 */);
    // 004a01f2  89451a                 -mov dword ptr [ebp + 0x1a], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(26) /* 0x1a */) = cpu.eax;
    // 004a01f5  d98618010000           -fld dword ptr [esi + 0x118]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(280) /* 0x118 */)));
    // 004a01fb  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 004a01fd  d95d1e                 -fstp dword ptr [ebp + 0x1e]
    app->getMemory<float>(cpu.ebp + x86::reg32(30) /* 0x1e */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a0200  8b861c010000           -mov eax, dword ptr [esi + 0x11c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(284) /* 0x11c */);
    // 004a0206  894522                 -mov dword ptr [ebp + 0x22], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(34) /* 0x22 */) = cpu.eax;
    // 004a0209  8d55de                 -lea edx, [ebp - 0x22]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-34) /* -0x22 */);
    // 004a020c  8b8614010000           -mov eax, dword ptr [esi + 0x114]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(276) /* 0x114 */);
    // 004a0212  8d8e98000000           -lea ecx, [esi + 0x98]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(152) /* 0x98 */);
    // 004a0218  894526                 -mov dword ptr [ebp + 0x26], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(38) /* 0x26 */) = cpu.eax;
    // 004a021b  8d9ec0000000           -lea ebx, [esi + 0xc0]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(192) /* 0xc0 */);
    // 004a0221  d98618010000           -fld dword ptr [esi + 0x118]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(280) /* 0x118 */)));
    // 004a0227  8d45de                 -lea eax, [ebp - 0x22]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-34) /* -0x22 */);
    // 004a022a  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 004a022c  d95d2a                 -fstp dword ptr [ebp + 0x2a]
    app->getMemory<float>(cpu.ebp + x86::reg32(42) /* 0x2a */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a022f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a0230  d9861c010000           -fld dword ptr [esi + 0x11c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(284) /* 0x11c */)));
    // 004a0236  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 004a0238  b808000000             -mov eax, 8
    cpu.eax = 8 /*0x8*/;
    // 004a023d  d95d2e                 -fstp dword ptr [ebp + 0x2e]
    app->getMemory<float>(cpu.ebp + x86::reg32(46) /* 0x2e */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a0240  d98614010000           -fld dword ptr [esi + 0x114]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(276) /* 0x114 */)));
    // 004a0246  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 004a0248  d95d32                 -fstp dword ptr [ebp + 0x32]
    app->getMemory<float>(cpu.ebp + x86::reg32(50) /* 0x32 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a024b  d98618010000           -fld dword ptr [esi + 0x118]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(280) /* 0x118 */)));
    // 004a0251  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 004a0253  d95d36                 -fstp dword ptr [ebp + 0x36]
    app->getMemory<float>(cpu.ebp + x86::reg32(54) /* 0x36 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a0256  d9861c010000           -fld dword ptr [esi + 0x11c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(284) /* 0x11c */)));
    // 004a025c  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 004a025e  d95d3a                 -fstp dword ptr [ebp + 0x3a]
    app->getMemory<float>(cpu.ebp + x86::reg32(58) /* 0x3a */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a0261  e8ca010400             -call 0x4e0430
    cpu.esp -= 4;
    sub_4e0430(app, cpu);
    if (cpu.terminate) return;
    // 004a0266  8d04fd00000000         -lea eax, [edi*8]
    cpu.eax = x86::reg32(cpu.edi * 8);
    // 004a026d  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 004a026f  8b1548d95d00           -mov edx, dword ptr [0x5dd948]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6150472) /* 0x5dd948 */);
    // 004a0275  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004a0278  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a027a  8b5015                 -mov edx, dword ptr [eax + 0x15]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(21) /* 0x15 */);
    // 004a027d  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004a0280  c1e209                 -shl edx, 9
    cpu.edx <<= 9 /*0x9*/ % 32;
    // 004a0283  89557e                 -mov dword ptr [ebp + 0x7e], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */) = cpu.edx;
    // 004a0286  dd05c4c75300           -fld qword ptr [0x53c7c4]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(5490628) /* 0x53c7c4 */)));
    // 004a028c  db457e                 -fild dword ptr [ebp + 0x7e]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */))));
    // 004a028f  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004a0291  d95d4a                 -fstp dword ptr [ebp + 0x4a]
    app->getMemory<float>(cpu.ebp + x86::reg32(74) /* 0x4a */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a0294  8b5016                 -mov edx, dword ptr [eax + 0x16]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(22) /* 0x16 */);
    // 004a0297  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004a029a  c1e209                 -shl edx, 9
    cpu.edx <<= 9 /*0x9*/ % 32;
    // 004a029d  89557e                 -mov dword ptr [ebp + 0x7e], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */) = cpu.edx;
    // 004a02a0  db457e                 -fild dword ptr [ebp + 0x7e]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */))));
    // 004a02a3  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004a02a5  d95d4e                 -fstp dword ptr [ebp + 0x4e]
    app->getMemory<float>(cpu.ebp + x86::reg32(78) /* 0x4e */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a02a8  8b5017                 -mov edx, dword ptr [eax + 0x17]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(23) /* 0x17 */);
    // 004a02ab  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004a02ae  c1e209                 -shl edx, 9
    cpu.edx <<= 9 /*0x9*/ % 32;
    // 004a02b1  89557e                 -mov dword ptr [ebp + 0x7e], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */) = cpu.edx;
    // 004a02b4  db457e                 -fild dword ptr [ebp + 0x7e]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */))));
    // 004a02b7  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004a02b9  d95d52                 -fstp dword ptr [ebp + 0x52]
    app->getMemory<float>(cpu.ebp + x86::reg32(82) /* 0x52 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a02bc  db00                   -fild dword ptr [eax]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax))));
    // 004a02be  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004a02c0  db4004                 -fild dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */))));
    // 004a02c3  deca                   -fmulp st(2)
    cpu.fpu.st(2) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004a02c5  d95d56                 -fstp dword ptr [ebp + 0x56]
    app->getMemory<float>(cpu.ebp + x86::reg32(86) /* 0x56 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a02c8  d95d5a                 -fstp dword ptr [ebp + 0x5a]
    app->getMemory<float>(cpu.ebp + x86::reg32(90) /* 0x5a */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a02cb  dd05c4c75300           -fld qword ptr [0x53c7c4]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(5490628) /* 0x53c7c4 */)));
    // 004a02d1  db4008                 -fild dword ptr [eax + 8]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */))));
    // 004a02d4  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004a02d6  db4020                 -fild dword ptr [eax + 0x20]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */))));
    // 004a02d9  d8ca                   -fmul st(2)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(2));
    // 004a02db  db401c                 -fild dword ptr [eax + 0x1c]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */))));
    // 004a02de  decb                   -fmulp st(3)
    cpu.fpu.st(3) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004a02e0  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a02e2  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004a02e4  895576                 -mov dword ptr [ebp + 0x76], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(118) /* 0x76 */) = cpu.edx;
    // 004a02e7  d9c9                   +fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a02e9  d95d5e                 +fstp dword ptr [ebp + 0x5e]
    app->getMemory<float>(cpu.ebp + x86::reg32(94) /* 0x5e */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a02ec  d95d62                 +fstp dword ptr [ebp + 0x62]
    app->getMemory<float>(cpu.ebp + x86::reg32(98) /* 0x62 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a02ef  d9e0                   +fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 004a02f1  d95d6e                 +fstp dword ptr [ebp + 0x6e]
    app->getMemory<float>(cpu.ebp + x86::reg32(110) /* 0x6e */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a02f4  e95d000000             -jmp 0x4a0356
    goto L_0x004a0356;
L_0x004a02f9:
    // 004a02f9  d94562                 +fld dword ptr [ebp + 0x62]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(98) /* 0x62 */)));
    // 004a02fc  eb03                   -jmp 0x4a0301
    goto L_0x004a0301;
L_0x004a02fe:
    // 004a02fe  d9456e                 +fld dword ptr [ebp + 0x6e]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(110) /* 0x6e */)));
L_0x004a0301:
    // 004a0301  d86572                 +fsub dword ptr [ebp + 0x72]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(114) /* 0x72 */));
    // 004a0304  d95d7a                 +fstp dword ptr [ebp + 0x7a]
    app->getMemory<float>(cpu.ebp + x86::reg32(122) /* 0x7a */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x004a0307:
    // 004a0307  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 004a0309  d85d7a                 +fcomp dword ptr [ebp + 0x7a]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(122) /* 0x7a */)));
    cpu.fpu.pop();
    // 004a030c  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004a030e  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004a030f  760a                   -jbe 0x4a031b
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a031b;
    }
    // 004a0311  d9457a                 +fld dword ptr [ebp + 0x7a]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(122) /* 0x7a */)));
    // 004a0314  d9e0                   +fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 004a0316  d95d6a                 +fstp dword ptr [ebp + 0x6a]
    app->getMemory<float>(cpu.ebp + x86::reg32(106) /* 0x6a */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a0319  eb06                   -jmp 0x4a0321
    goto L_0x004a0321;
L_0x004a031b:
    // 004a031b  8b457a                 -mov eax, dword ptr [ebp + 0x7a]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(122) /* 0x7a */);
    // 004a031e  89456a                 -mov dword ptr [ebp + 0x6a], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(106) /* 0x6a */) = cpu.eax;
L_0x004a0321:
    // 004a0321  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 004a0323  d85d76                 +fcomp dword ptr [ebp + 0x76]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(118) /* 0x76 */)));
    cpu.fpu.pop();
    // 004a0326  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004a0328  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004a0329  760a                   -jbe 0x4a0335
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a0335;
    }
    // 004a032b  d94576                 +fld dword ptr [ebp + 0x76]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(118) /* 0x76 */)));
    // 004a032e  d9e0                   +fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 004a0330  d95d66                 +fstp dword ptr [ebp + 0x66]
    app->getMemory<float>(cpu.ebp + x86::reg32(102) /* 0x66 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a0333  eb06                   -jmp 0x4a033b
    goto L_0x004a033b;
L_0x004a0335:
    // 004a0335  8b4576                 -mov eax, dword ptr [ebp + 0x76]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(118) /* 0x76 */);
    // 004a0338  894566                 -mov dword ptr [ebp + 0x66], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(102) /* 0x66 */) = cpu.eax;
L_0x004a033b:
    // 004a033b  d9456a                 +fld dword ptr [ebp + 0x6a]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(106) /* 0x6a */)));
    // 004a033e  d85d66                 +fcomp dword ptr [ebp + 0x66]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(102) /* 0x66 */)));
    cpu.fpu.pop();
    // 004a0341  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004a0343  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004a0344  7606                   -jbe 0x4a034c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a034c;
    }
    // 004a0346  8b457a                 -mov eax, dword ptr [ebp + 0x7a]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(122) /* 0x7a */);
    // 004a0349  894576                 -mov dword ptr [ebp + 0x76], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(118) /* 0x76 */) = cpu.eax;
L_0x004a034c:
    // 004a034c  41                     -inc ecx
    (cpu.ecx)++;
    // 004a034d  83f908                 +cmp ecx, 8
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
    // 004a0350  0f8d99000000           -jge 0x4a03ef
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a03ef;
    }
L_0x004a0356:
    // 004a0356  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 004a035d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a035f  29c8                   +sub eax, ecx
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
    // 004a0361  8d553e                 -lea edx, [ebp + 0x3e]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(62) /* 0x3e */);
    // 004a0364  895d7a                 -mov dword ptr [ebp + 0x7a], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(122) /* 0x7a */) = cpu.ebx;
    // 004a0367  d94485e2               +fld dword ptr [ebp + eax*4 - 0x1e]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-30) /* -0x1e */ + cpu.eax * 4)));
    // 004a036b  d94485e6               +fld dword ptr [ebp + eax*4 - 0x1a]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-26) /* -0x1a */ + cpu.eax * 4)));
    // 004a036f  d94485de               +fld dword ptr [ebp + eax*4 - 0x22]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-34) /* -0x22 */ + cpu.eax * 4)));
    // 004a0373  8d454a                 -lea eax, [ebp + 0x4a]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(74) /* 0x4a */);
    // 004a0376  d86556                 +fsub dword ptr [ebp + 0x56]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(86) /* 0x56 */));
    // 004a0379  d9ca                   +fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004a037b  d8655a                 +fsub dword ptr [ebp + 0x5a]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(90) /* 0x5a */));
    // 004a037e  d9c9                   +fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a0380  d8655e                 +fsub dword ptr [ebp + 0x5e]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(94) /* 0x5e */));
    // 004a0383  d9ca                   +fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004a0385  d95d3e                 +fstp dword ptr [ebp + 0x3e]
    app->getMemory<float>(cpu.ebp + x86::reg32(62) /* 0x3e */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a0388  d95d42                 +fstp dword ptr [ebp + 0x42]
    app->getMemory<float>(cpu.ebp + x86::reg32(66) /* 0x42 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a038b  d95d46                 +fstp dword ptr [ebp + 0x46]
    app->getMemory<float>(cpu.ebp + x86::reg32(70) /* 0x46 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a038e  e85dfe0300             -call 0x4e01f0
    cpu.esp -= 4;
    sub_4e01f0(app, cpu);
    if (cpu.terminate) return;
    // 004a0393  d95572                 +fst dword ptr [ebp + 0x72]
    app->getMemory<float>(cpu.ebp + x86::reg32(114) /* 0x72 */) = float(cpu.fpu.st(0));
    // 004a0396  d85d62                 +fcomp dword ptr [ebp + 0x62]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(98) /* 0x62 */)));
    cpu.fpu.pop();
    // 004a0399  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004a039b  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004a039c  761a                   -jbe 0x4a03b8
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a03b8;
    }
    // 004a039e  8d04fd00000000         -lea eax, [edi*8]
    cpu.eax = x86::reg32(cpu.edi * 8);
    // 004a03a5  8b1548d95d00           -mov edx, dword ptr [0x5dd948]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6150472) /* 0x5dd948 */);
    // 004a03ab  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 004a03ad  f644820e0f             +test byte ptr [edx + eax*4 + 0xe], 0xf
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(14) /* 0xe */ + cpu.eax * 4) & 15 /*0xf*/));
    // 004a03b2  0f8541ffffff           -jne 0x4a02f9
    if (!cpu.flags.zf)
    {
        goto L_0x004a02f9;
    }
L_0x004a03b8:
    // 004a03b8  d94572                 +fld dword ptr [ebp + 0x72]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(114) /* 0x72 */)));
    // 004a03bb  d85d6e                 +fcomp dword ptr [ebp + 0x6e]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(110) /* 0x6e */)));
    cpu.fpu.pop();
    // 004a03be  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004a03c0  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004a03c1  0f8340ffffff           -jae 0x4a0307
    if (!cpu.flags.cf)
    {
        goto L_0x004a0307;
    }
    // 004a03c7  8d04fd00000000         -lea eax, [edi*8]
    cpu.eax = x86::reg32(cpu.edi * 8);
    // 004a03ce  8b1548d95d00           -mov edx, dword ptr [0x5dd948]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6150472) /* 0x5dd948 */);
    // 004a03d4  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 004a03d6  8a44820e               -mov al, byte ptr [edx + eax*4 + 0xe]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(14) /* 0xe */ + cpu.eax * 4);
    // 004a03da  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a03df  c1f804                 -sar eax, 4
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (4 /*0x4*/ % 32));
    // 004a03e2  a80f                   +test al, 0xf
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 15 /*0xf*/));
    // 004a03e4  0f8514ffffff           -jne 0x4a02fe
    if (!cpu.flags.zf)
    {
        goto L_0x004a02fe;
    }
    // 004a03ea  e918ffffff             -jmp 0x4a0307
    goto L_0x004a0307;
L_0x004a03ef:
    // 004a03ef  8d454a                 -lea eax, [ebp + 0x4a]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(74) /* 0x4a */);
    // 004a03f2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a03f3  8d554a                 -lea edx, [ebp + 0x4a]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(74) /* 0x4a */);
    // 004a03f6  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a03fb  ff7576                 -push dword ptr [ebp + 0x76]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(118) /* 0x76 */);
    cpu.esp -= 4;
    // 004a03fe  e84dfc0300             -call 0x4e0050
    cpu.esp -= 4;
    sub_4e0050(app, cpu);
    if (cpu.terminate) return;
    // 004a0403  d9454a                 -fld dword ptr [ebp + 0x4a]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(74) /* 0x4a */)));
    // 004a0406  d88698000000           -fadd dword ptr [esi + 0x98]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(152) /* 0x98 */));
    // 004a040c  d99e98000000           -fstp dword ptr [esi + 0x98]
    app->getMemory<float>(cpu.esi + x86::reg32(152) /* 0x98 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a0412  d9454e                 -fld dword ptr [ebp + 0x4e]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(78) /* 0x4e */)));
    // 004a0415  d8869c000000           -fadd dword ptr [esi + 0x9c]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(156) /* 0x9c */));
    // 004a041b  d99e9c000000           -fstp dword ptr [esi + 0x9c]
    app->getMemory<float>(cpu.esi + x86::reg32(156) /* 0x9c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a0421  d94552                 -fld dword ptr [ebp + 0x52]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(82) /* 0x52 */)));
    // 004a0424  d886a0000000           -fadd dword ptr [esi + 0xa0]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(160) /* 0xa0 */));
    // 004a042a  d99ea0000000           -fstp dword ptr [esi + 0xa0]
    app->getMemory<float>(cpu.esi + x86::reg32(160) /* 0xa0 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a0430  8da582000000           -lea esp, [ebp + 0x82]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(130) /* 0x82 */);
    // 004a0436  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0437  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0438  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0439  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a043a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a043b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a043c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a0440(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a0440  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a0441  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a0442  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a0443  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a0444  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a0445  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a0446  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a0448  83ec40                 -sub esp, 0x40
    (cpu.esp) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 004a044b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a044d  8d7dc0                 -lea edi, [ebp - 0x40]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-64) /* -0x40 */);
    // 004a0450  bed0fd4900             -mov esi, 0x49fdd0
    cpu.esi = 4849104 /*0x49fdd0*/;
    // 004a0455  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a0456  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a0457  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a0458  83b88401000000         +cmp dword ptr [eax + 0x184], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(388) /* 0x184 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a045f  740c                   -je 0x4a046d
    if (cpu.flags.zf)
    {
        goto L_0x004a046d;
    }
    // 004a0461  c745f80000c842         -mov dword ptr [ebp - 8], 0x42c80000
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = 1120403456 /*0x42c80000*/;
    // 004a0468  e9fc000000             -jmp 0x4a0569
    goto L_0x004a0569;
L_0x004a046d:
    // 004a046d  8d7dd8                 -lea edi, [ebp - 0x28]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 004a0470  8d90c0000000           -lea edx, [eax + 0xc0]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(192) /* 0xc0 */);
    // 004a0476  8db130010000           -lea esi, [ecx + 0x130]
    cpu.esi = x86::reg32(cpu.ecx + x86::reg32(304) /* 0x130 */);
    // 004a047c  8d45d8                 -lea eax, [ebp - 0x28]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 004a047f  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a0480  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a0481  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a0482  e869fd0300             -call 0x4e01f0
    cpu.esp -= 4;
    sub_4e01f0(app, cpu);
    if (cpu.terminate) return;
    // 004a0487  d88914010000           +fmul dword ptr [ecx + 0x114]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(276) /* 0x114 */));
    // 004a048d  8d45d8                 -lea eax, [ebp - 0x28]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 004a0490  8d91cc000000           -lea edx, [ecx + 0xcc]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(204) /* 0xcc */);
    // 004a0496  d95dcc                 +fstp dword ptr [ebp - 0x34]
    app->getMemory<float>(cpu.ebp + x86::reg32(-52) /* -0x34 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a0499  e852fd0300             -call 0x4e01f0
    cpu.esp -= 4;
    sub_4e01f0(app, cpu);
    if (cpu.terminate) return;
    // 004a049e  d88918010000           +fmul dword ptr [ecx + 0x118]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(280) /* 0x118 */));
    // 004a04a4  8d45d8                 -lea eax, [ebp - 0x28]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 004a04a7  8d91d8000000           -lea edx, [ecx + 0xd8]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(216) /* 0xd8 */);
    // 004a04ad  d95dd0                 +fstp dword ptr [ebp - 0x30]
    app->getMemory<float>(cpu.ebp + x86::reg32(-48) /* -0x30 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a04b0  e83bfd0300             -call 0x4e01f0
    cpu.esp -= 4;
    sub_4e01f0(app, cpu);
    if (cpu.terminate) return;
    // 004a04b5  d8891c010000           +fmul dword ptr [ecx + 0x11c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(284) /* 0x11c */));
    // 004a04bb  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 004a04bd  d9c9                   +fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a04bf  d95dd4                 +fstp dword ptr [ebp - 0x2c]
    app->getMemory<float>(cpu.ebp + x86::reg32(-44) /* -0x2c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a04c2  d85dcc                 +fcomp dword ptr [ebp - 0x34]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-52) /* -0x34 */)));
    cpu.fpu.pop();
    // 004a04c5  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004a04c7  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004a04c8  7607                   -jbe 0x4a04d1
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a04d1;
    }
    // 004a04ca  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 004a04cf  eb05                   -jmp 0x4a04d6
    goto L_0x004a04d6;
L_0x004a04d1:
    // 004a04d1  bfffffffff             -mov edi, 0xffffffff
    cpu.edi = 4294967295 /*0xffffffff*/;
L_0x004a04d6:
    // 004a04d6  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 004a04d8  d85dd0                 +fcomp dword ptr [ebp - 0x30]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-48) /* -0x30 */)));
    cpu.fpu.pop();
    // 004a04db  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004a04dd  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004a04de  7609                   -jbe 0x4a04e9
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a04e9;
    }
    // 004a04e0  c745f401000000         -mov dword ptr [ebp - 0xc], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = 1 /*0x1*/;
    // 004a04e7  eb07                   -jmp 0x4a04f0
    goto L_0x004a04f0;
L_0x004a04e9:
    // 004a04e9  c745f4ffffffff         -mov dword ptr [ebp - 0xc], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = 4294967295 /*0xffffffff*/;
L_0x004a04f0:
    // 004a04f0  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 004a04f2  d85dd4                 +fcomp dword ptr [ebp - 0x2c]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-44) /* -0x2c */)));
    cpu.fpu.pop();
    // 004a04f5  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004a04f7  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004a04f8  7607                   -jbe 0x4a0501
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a0501;
    }
    // 004a04fa  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 004a04ff  eb05                   -jmp 0x4a0506
    goto L_0x004a0506;
L_0x004a0501:
    // 004a0501  beffffffff             -mov esi, 0xffffffff
    cpu.esi = 4294967295 /*0xffffffff*/;
L_0x004a0506:
    // 004a0506  8b8198000000           -mov eax, dword ptr [ecx + 0x98]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(152) /* 0x98 */);
    // 004a050c  8945e4                 -mov dword ptr [ebp - 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.eax;
    // 004a050f  8b819c000000           -mov eax, dword ptr [ecx + 0x9c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(156) /* 0x9c */);
    // 004a0515  8d55e4                 -lea edx, [ebp - 0x1c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004a0518  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
    // 004a051b  8d9948010000           -lea ebx, [ecx + 0x148]
    cpu.ebx = x86::reg32(cpu.ecx + x86::reg32(328) /* 0x148 */);
    // 004a0521  8b81a0000000           -mov eax, dword ptr [ecx + 0xa0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(160) /* 0xa0 */);
    // 004a0527  8d4dc0                 -lea ecx, [ebp - 0x40]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(-64) /* -0x40 */);
    // 004a052a  8945ec                 -mov dword ptr [ebp - 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
    // 004a052d  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a0532  e8c9fa0300             -call 0x4e0000
    cpu.esp -= 4;
    sub_4e0000(app, cpu);
    if (cpu.terminate) return;
    // 004a0537  8d55c0                 -lea edx, [ebp - 0x40]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-64) /* -0x40 */);
    // 004a053a  8d45d8                 -lea eax, [ebp - 0x28]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 004a053d  e8aefc0300             -call 0x4e01f0
    cpu.esp -= 4;
    sub_4e01f0(app, cpu);
    if (cpu.terminate) return;
    // 004a0542  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004a0545  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004a0548  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 004a054b  d84dd0                 -fmul dword ptr [ebp - 0x30]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-48) /* -0x30 */));
    // 004a054e  897dfc                 -mov dword ptr [ebp - 4], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edi;
    // 004a0551  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 004a0554  d84dcc                 -fmul dword ptr [ebp - 0x34]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-52) /* -0x34 */));
    // 004a0557  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004a0559  8975fc                 -mov dword ptr [ebp - 4], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.esi;
    // 004a055c  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 004a055f  d84dd4                 -fmul dword ptr [ebp - 0x2c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-44) /* -0x2c */));
    // 004a0562  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004a0564  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004a0566  d95df8                 -fstp dword ptr [ebp - 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x004a0569:
    // 004a0569  d945f8                 -fld dword ptr [ebp - 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 004a056c  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004a056e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a056f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0570  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0571  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0572  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0573  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0574  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_4a0580(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a0580  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a0581  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a0582  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a0583  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a0584  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a0585  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a0587  83ec50                 -sub esp, 0x50
    (cpu.esp) -= x86::reg32(x86::sreg32(80 /*0x50*/));
    // 004a058a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a058c  8b15b0d36f00           -mov edx, dword ptr [0x6fd3b0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */);
    // 004a0592  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a0594  7416                   -je 0x4a05ac
    if (cpu.flags.zf)
    {
        goto L_0x004a05ac;
    }
    // 004a0596  c6808800000000         -mov byte ptr [eax + 0x88], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(136) /* 0x88 */) = 0 /*0x0*/;
    // 004a059d  c7808400000000000000   -mov dword ptr [eax + 0x84], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(132) /* 0x84 */) = 0 /*0x0*/;
    // 004a05a7  e905030000             -jmp 0x4a08b1
    goto L_0x004a08b1;
L_0x004a05ac:
    // 004a05ac  833da4fd5e0002         +cmp dword ptr [0x5efda4], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6225316) /* 0x5efda4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a05b3  0f8feb020000           -jg 0x4a08a4
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a08a4;
    }
    // 004a05b9  a1f4d46f00             -mov eax, dword ptr [0x6fd4f4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7329012) /* 0x6fd4f4 */);
    // 004a05be  8b048548fa5e00         -mov eax, dword ptr [eax*4 + 0x5efa48]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6224456) /* 0x5efa48 */ + cpu.eax * 4);
    // 004a05c5  d98198000000           +fld dword ptr [ecx + 0x98]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(152) /* 0x98 */)));
    // 004a05cb  d8a098000000           +fsub dword ptr [eax + 0x98]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(152) /* 0x98 */));
    // 004a05d1  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 004a05d3  d9c9                   +fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a05d5  d95dd8                 +fstp dword ptr [ebp - 0x28]
    app->getMemory<float>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a05d8  d85dd8                 +fcomp dword ptr [ebp - 0x28]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-40) /* -0x28 */)));
    cpu.fpu.pop();
    // 004a05db  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004a05dd  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004a05de  7308                   -jae 0x4a05e8
    if (!cpu.flags.cf)
    {
        goto L_0x004a05e8;
    }
    // 004a05e0  8b45d8                 -mov eax, dword ptr [ebp - 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 004a05e3  8945c8                 -mov dword ptr [ebp - 0x38], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-56) /* -0x38 */) = cpu.eax;
    // 004a05e6  eb08                   -jmp 0x4a05f0
    goto L_0x004a05f0;
L_0x004a05e8:
    // 004a05e8  d945d8                 +fld dword ptr [ebp - 0x28]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-40) /* -0x28 */)));
    // 004a05eb  d9e0                   +fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 004a05ed  d95dc8                 +fstp dword ptr [ebp - 0x38]
    app->getMemory<float>(cpu.ebp + x86::reg32(-56) /* -0x38 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x004a05f0:
    // 004a05f0  8b45c8                 -mov eax, dword ptr [ebp - 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-56) /* -0x38 */);
    // 004a05f3  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 004a05f6  a1f4d46f00             -mov eax, dword ptr [0x6fd4f4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7329012) /* 0x6fd4f4 */);
    // 004a05fb  8b048548fa5e00         -mov eax, dword ptr [eax*4 + 0x5efa48]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6224456) /* 0x5efa48 */ + cpu.eax * 4);
    // 004a0602  d981a0000000           +fld dword ptr [ecx + 0xa0]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(160) /* 0xa0 */)));
    // 004a0608  d8a0a0000000           +fsub dword ptr [eax + 0xa0]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(160) /* 0xa0 */));
    // 004a060e  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 004a0610  d9c9                   +fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a0612  d95de0                 +fstp dword ptr [ebp - 0x20]
    app->getMemory<float>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a0615  d85de0                 +fcomp dword ptr [ebp - 0x20]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-32) /* -0x20 */)));
    cpu.fpu.pop();
    // 004a0618  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004a061a  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004a061b  7308                   -jae 0x4a0625
    if (!cpu.flags.cf)
    {
        goto L_0x004a0625;
    }
    // 004a061d  8b45e0                 -mov eax, dword ptr [ebp - 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 004a0620  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 004a0623  eb08                   -jmp 0x4a062d
    goto L_0x004a062d;
L_0x004a0625:
    // 004a0625  d945e0                 +fld dword ptr [ebp - 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-32) /* -0x20 */)));
    // 004a0628  d9e0                   +fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 004a062a  d95df8                 +fstp dword ptr [ebp - 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x004a062d:
    // 004a062d  d945f0                 +fld dword ptr [ebp - 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-16) /* -0x10 */)));
    // 004a0630  d85df8                 +fcomp dword ptr [ebp - 8]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    cpu.fpu.pop();
    // 004a0633  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004a0635  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004a0636  760e                   -jbe 0x4a0646
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a0646;
    }
    // 004a0638  d945f8                 +fld dword ptr [ebp - 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 004a063b  d80dccc75300           +fmul dword ptr [0x53c7cc]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5490636) /* 0x53c7cc */));
    // 004a0641  d845f0                 +fadd dword ptr [ebp - 0x10]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-16) /* -0x10 */));
    // 004a0644  eb0c                   -jmp 0x4a0652
    goto L_0x004a0652;
L_0x004a0646:
    // 004a0646  d945f0                 -fld dword ptr [ebp - 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-16) /* -0x10 */)));
    // 004a0649  d80dccc75300           -fmul dword ptr [0x53c7cc]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5490636) /* 0x53c7cc */));
    // 004a064f  d845f8                 -fadd dword ptr [ebp - 8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */));
L_0x004a0652:
    // 004a0652  d95dd0                 -fstp dword ptr [ebp - 0x30]
    app->getMemory<float>(cpu.ebp + x86::reg32(-48) /* -0x30 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a0655  8b45d0                 -mov eax, dword ptr [ebp - 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */);
    // 004a0658  898184000000           -mov dword ptr [ecx + 0x84], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(132) /* 0x84 */) = cpu.eax;
    // 004a065e  a1f4d46f00             -mov eax, dword ptr [0x6fd4f4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7329012) /* 0x6fd4f4 */);
    // 004a0663  8b048548fa5e00         -mov eax, dword ptr [eax*4 + 0x5efa48]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6224456) /* 0x5efa48 */ + cpu.eax * 4);
    // 004a066a  8b501c                 -mov edx, dword ptr [eax + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004a066d  8b411c                 -mov eax, dword ptr [ecx + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 004a0670  e84bfaffff             -call 0x4a00c0
    cpu.esp -= 4;
    sub_4a00c0(app, cpu);
    if (cpu.terminate) return;
    // 004a0675  8b35a4fd5e00           -mov esi, dword ptr [0x5efda4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(6225316) /* 0x5efda4 */);
    // 004a067b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a067d  83fe02                 +cmp esi, 2
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
    // 004a0680  0f85f4000000           -jne 0x4a077a
    if (!cpu.flags.zf)
    {
        goto L_0x004a077a;
    }
    // 004a0686  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a068b  2b05f4d46f00           +sub eax, dword ptr [0x6fd4f4]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(7329012) /* 0x6fd4f4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a0691  8b048548fa5e00         -mov eax, dword ptr [eax*4 + 0x5efa48]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6224456) /* 0x5efa48 */ + cpu.eax * 4);
    // 004a0698  d98198000000           +fld dword ptr [ecx + 0x98]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(152) /* 0x98 */)));
    // 004a069e  d8a098000000           +fsub dword ptr [eax + 0x98]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(152) /* 0x98 */));
    // 004a06a4  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 004a06a6  d9c9                   +fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a06a8  d95de8                 +fstp dword ptr [ebp - 0x18]
    app->getMemory<float>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a06ab  d85de8                 +fcomp dword ptr [ebp - 0x18]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-24) /* -0x18 */)));
    cpu.fpu.pop();
    // 004a06ae  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004a06b0  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004a06b1  7308                   -jae 0x4a06bb
    if (!cpu.flags.cf)
    {
        goto L_0x004a06bb;
    }
    // 004a06b3  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004a06b6  8945cc                 -mov dword ptr [ebp - 0x34], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-52) /* -0x34 */) = cpu.eax;
    // 004a06b9  eb08                   -jmp 0x4a06c3
    goto L_0x004a06c3;
L_0x004a06bb:
    // 004a06bb  d945e8                 -fld dword ptr [ebp - 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-24) /* -0x18 */)));
    // 004a06be  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 004a06c0  d95dcc                 -fstp dword ptr [ebp - 0x34]
    app->getMemory<float>(cpu.ebp + x86::reg32(-52) /* -0x34 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x004a06c3:
    // 004a06c3  8b45cc                 -mov eax, dword ptr [ebp - 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 004a06c6  8b15f4d46f00           -mov edx, dword ptr [0x6fd4f4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(7329012) /* 0x6fd4f4 */);
    // 004a06cc  8945ec                 -mov dword ptr [ebp - 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
    // 004a06cf  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a06d4  29d0                   +sub eax, edx
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
    // 004a06d6  8b048548fa5e00         -mov eax, dword ptr [eax*4 + 0x5efa48]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6224456) /* 0x5efa48 */ + cpu.eax * 4);
    // 004a06dd  d981a0000000           +fld dword ptr [ecx + 0xa0]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(160) /* 0xa0 */)));
    // 004a06e3  d8a0a0000000           +fsub dword ptr [eax + 0xa0]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(160) /* 0xa0 */));
    // 004a06e9  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 004a06eb  d9c9                   +fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a06ed  d95ddc                 +fstp dword ptr [ebp - 0x24]
    app->getMemory<float>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a06f0  d85ddc                 +fcomp dword ptr [ebp - 0x24]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-36) /* -0x24 */)));
    cpu.fpu.pop();
    // 004a06f3  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004a06f5  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004a06f6  7308                   -jae 0x4a0700
    if (!cpu.flags.cf)
    {
        goto L_0x004a0700;
    }
    // 004a06f8  8b45dc                 -mov eax, dword ptr [ebp - 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 004a06fb  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 004a06fe  eb08                   -jmp 0x4a0708
    goto L_0x004a0708;
L_0x004a0700:
    // 004a0700  d945dc                 +fld dword ptr [ebp - 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-36) /* -0x24 */)));
    // 004a0703  d9e0                   +fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 004a0705  d95df4                 +fstp dword ptr [ebp - 0xc]
    app->getMemory<float>(cpu.ebp + x86::reg32(-12) /* -0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x004a0708:
    // 004a0708  d945ec                 +fld dword ptr [ebp - 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-20) /* -0x14 */)));
    // 004a070b  d85df4                 +fcomp dword ptr [ebp - 0xc]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-12) /* -0xc */)));
    cpu.fpu.pop();
    // 004a070e  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004a0710  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004a0711  760e                   -jbe 0x4a0721
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a0721;
    }
    // 004a0713  d945f4                 +fld dword ptr [ebp - 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-12) /* -0xc */)));
    // 004a0716  d80dccc75300           +fmul dword ptr [0x53c7cc]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5490636) /* 0x53c7cc */));
    // 004a071c  d845ec                 +fadd dword ptr [ebp - 0x14]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-20) /* -0x14 */));
    // 004a071f  eb0c                   -jmp 0x4a072d
    goto L_0x004a072d;
L_0x004a0721:
    // 004a0721  d945ec                 +fld dword ptr [ebp - 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-20) /* -0x14 */)));
    // 004a0724  d80dccc75300           +fmul dword ptr [0x53c7cc]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5490636) /* 0x53c7cc */));
    // 004a072a  d845f4                 +fadd dword ptr [ebp - 0xc]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-12) /* -0xc */));
L_0x004a072d:
    // 004a072d  d95de4                 +fstp dword ptr [ebp - 0x1c]
    app->getMemory<float>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a0730  d945e4                 +fld dword ptr [ebp - 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-28) /* -0x1c */)));
    // 004a0733  d89984000000           +fcomp dword ptr [ecx + 0x84]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(132) /* 0x84 */)));
    cpu.fpu.pop();
    // 004a0739  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004a073b  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004a073c  7608                   -jbe 0x4a0746
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a0746;
    }
    // 004a073e  8b8184000000           -mov eax, dword ptr [ecx + 0x84]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(132) /* 0x84 */);
    // 004a0744  eb03                   -jmp 0x4a0749
    goto L_0x004a0749;
L_0x004a0746:
    // 004a0746  8b45e4                 -mov eax, dword ptr [ebp - 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
L_0x004a0749:
    // 004a0749  8945d4                 -mov dword ptr [ebp - 0x2c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */) = cpu.eax;
    // 004a074c  8b45d4                 -mov eax, dword ptr [ebp - 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 004a074f  8b35f4d46f00           -mov esi, dword ptr [0x6fd4f4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(7329012) /* 0x6fd4f4 */);
    // 004a0755  898184000000           -mov dword ptr [ecx + 0x84], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(132) /* 0x84 */) = cpu.eax;
    // 004a075b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a0760  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004a0762  8b048548fa5e00         -mov eax, dword ptr [eax*4 + 0x5efa48]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6224456) /* 0x5efa48 */ + cpu.eax * 4);
    // 004a0769  8b501c                 -mov edx, dword ptr [eax + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004a076c  8b411c                 -mov eax, dword ptr [ecx + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 004a076f  e84cf9ffff             -call 0x4a00c0
    cpu.esp -= 4;
    sub_4a00c0(app, cpu);
    if (cpu.terminate) return;
    // 004a0774  39d8                   +cmp eax, ebx
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
    // 004a0776  7f02                   -jg 0x4a077a
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a077a;
    }
    // 004a0778  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x004a077a:
    // 004a077a  895dfc                 -mov dword ptr [ebp - 4], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 004a077d  db45fc                 +fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 004a0780  dc0dd4c75300           +fmul qword ptr [0x53c7d4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5490644) /* 0x53c7d4 */));
    // 004a0786  d98184000000           +fld dword ptr [ecx + 0x84]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(132) /* 0x84 */)));
    // 004a078c  dd55b0                 +fst qword ptr [ebp - 0x50]
    app->getMemory<double>(cpu.ebp + x86::reg32(-80) /* -0x50 */) = double(cpu.fpu.st(0));
    // 004a078f  d9c9                   +fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a0791  dd5db8                 +fstp qword ptr [ebp - 0x48]
    app->getMemory<double>(cpu.ebp + x86::reg32(-72) /* -0x48 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a0794  dc5db8                 +fcomp qword ptr [ebp - 0x48]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-72) /* -0x48 */)));
    cpu.fpu.pop();
    // 004a0797  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004a0799  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004a079a  760b                   -jbe 0x4a07a7
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a07a7;
    }
    // 004a079c  8b45b0                 -mov eax, dword ptr [ebp - 0x50]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-80) /* -0x50 */);
    // 004a079f  8945c0                 -mov dword ptr [ebp - 0x40], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-64) /* -0x40 */) = cpu.eax;
    // 004a07a2  8b45b4                 -mov eax, dword ptr [ebp - 0x4c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-76) /* -0x4c */);
    // 004a07a5  eb09                   -jmp 0x4a07b0
    goto L_0x004a07b0;
L_0x004a07a7:
    // 004a07a7  8b45b8                 -mov eax, dword ptr [ebp - 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-72) /* -0x48 */);
    // 004a07aa  8945c0                 -mov dword ptr [ebp - 0x40], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-64) /* -0x40 */) = cpu.eax;
    // 004a07ad  8b45bc                 -mov eax, dword ptr [ebp - 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-68) /* -0x44 */);
L_0x004a07b0:
    // 004a07b0  8945c4                 -mov dword ptr [ebp - 0x3c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-60) /* -0x3c */) = cpu.eax;
    // 004a07b3  dd45c0                 +fld qword ptr [ebp - 0x40]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-64) /* -0x40 */)));
    // 004a07b6  d99184000000           +fst dword ptr [ecx + 0x84]
    app->getMemory<float>(cpu.ecx + x86::reg32(132) /* 0x84 */) = float(cpu.fpu.st(0));
    // 004a07bc  dc1ddcc75300           +fcomp qword ptr [0x53c7dc]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(5490652) /* 0x53c7dc */)));
    cpu.fpu.pop();
    // 004a07c2  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004a07c4  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004a07c5  7638                   -jbe 0x4a07ff
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a07ff;
    }
    // 004a07c7  80b98800000001         +cmp byte ptr [ecx + 0x88], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(136) /* 0x88 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a07ce  7416                   -je 0x4a07e6
    if (cpu.flags.zf)
    {
        goto L_0x004a07e6;
    }
    // 004a07d0  c7818801000001000000   -mov dword ptr [ecx + 0x188], 1
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(392) /* 0x188 */) = 1 /*0x1*/;
    // 004a07da  8b8188010000           -mov eax, dword ptr [ecx + 0x188]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(392) /* 0x188 */);
    // 004a07e0  89818c010000           -mov dword ptr [ecx + 0x18c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(396) /* 0x18c */) = cpu.eax;
L_0x004a07e6:
    // 004a07e6  c781e400000000000000   -mov dword ptr [ecx + 0xe4], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(228) /* 0xe4 */) = 0 /*0x0*/;
    // 004a07f0  c781ec00000000000000   -mov dword ptr [ecx + 0xec], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(236) /* 0xec */) = 0 /*0x0*/;
    // 004a07fa  e996000000             -jmp 0x4a0895
    goto L_0x004a0895;
L_0x004a07ff:
    // 004a07ff  80b98800000000         +cmp byte ptr [ecx + 0x88], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(136) /* 0x88 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a0806  0f8489000000           -je 0x4a0895
    if (cpu.flags.zf)
    {
        goto L_0x004a0895;
    }
    // 004a080c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a080e  c6818800000000         -mov byte ptr [ecx + 0x88], 0
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(136) /* 0x88 */) = 0 /*0x0*/;
    // 004a0815  e856f6ffff             -call 0x49fe70
    cpu.esp -= 4;
    sub_49fe70(app, cpu);
    if (cpu.terminate) return;
    // 004a081a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a081c  e87ff7ffff             -call 0x49ffa0
    cpu.esp -= 4;
    sub_49ffa0(app, cpu);
    if (cpu.terminate) return;
    // 004a0821  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a0823  e818f9ffff             -call 0x4a0140
    cpu.esp -= 4;
    sub_4a0140(app, cpu);
    if (cpu.terminate) return;
    // 004a0828  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a082a  e8a1f8ffff             -call 0x4a00d0
    cpu.esp -= 4;
    sub_4a00d0(app, cpu);
    if (cpu.terminate) return;
    // 004a082f  c7818801000001000000   -mov dword ptr [ecx + 0x188], 1
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(392) /* 0x188 */) = 1 /*0x1*/;
    // 004a0839  c7816801000000000000   -mov dword ptr [ecx + 0x168], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(360) /* 0x168 */) = 0 /*0x0*/;
    // 004a0843  c7816c01000000000000   -mov dword ptr [ecx + 0x16c], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(364) /* 0x16c */) = 0 /*0x0*/;
    // 004a084d  d99158010000           -fst dword ptr [ecx + 0x158]
    app->getMemory<float>(cpu.ecx + x86::reg32(344) /* 0x158 */) = float(cpu.fpu.st(0));
    // 004a0853  8b8188010000           -mov eax, dword ptr [ecx + 0x188]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(392) /* 0x188 */);
    // 004a0859  d88118010000           -fadd dword ptr [ecx + 0x118]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(280) /* 0x118 */));
    // 004a085f  89818c010000           -mov dword ptr [ecx + 0x18c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(396) /* 0x18c */) = cpu.eax;
    // 004a0865  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a0867  d9999c000000           -fstp dword ptr [ecx + 0x9c]
    app->getMemory<float>(cpu.ecx + x86::reg32(156) /* 0x9c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a086d  e8cefbffff             -call 0x4a0440
    cpu.esp -= 4;
    sub_4a0440(app, cpu);
    if (cpu.terminate) return;
    // 004a0872  d9915c010000           -fst dword ptr [ecx + 0x15c]
    app->getMemory<float>(cpu.ecx + x86::reg32(348) /* 0x15c */) = float(cpu.fpu.st(0));
    // 004a0878  c7815c01000000000000   -mov dword ptr [ecx + 0x15c], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(348) /* 0x15c */) = 0 /*0x0*/;
    // 004a0882  d8a99c000000           -fsubr dword ptr [ecx + 0x9c]
    cpu.fpu.st(0) = app->getMemory<float>(cpu.ecx + x86::reg32(156) /* 0x9c */) - cpu.fpu.st(0);
    // 004a0888  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a088a  d9999c000000           -fstp dword ptr [ecx + 0x9c]
    app->getMemory<float>(cpu.ecx + x86::reg32(156) /* 0x9c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a0890  e82b8cf8ff             -call 0x4294c0
    cpu.esp -= 4;
    sub_4294c0(app, cpu);
    if (cpu.terminate) return;
L_0x004a0895:
    // 004a0895  c6818800000000         -mov byte ptr [ecx + 0x88], 0
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(136) /* 0x88 */) = 0 /*0x0*/;
    // 004a089c  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004a089e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a089f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a08a0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a08a1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a08a2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a08a3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a08a4:
    // 004a08a4  c6808800000000         -mov byte ptr [eax + 0x88], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(136) /* 0x88 */) = 0 /*0x0*/;
    // 004a08ab  899084000000           -mov dword ptr [eax + 0x84], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(132) /* 0x84 */) = cpu.edx;
L_0x004a08b1:
    // 004a08b1  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004a08b3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a08b4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a08b5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a08b6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a08b7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a08b8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4a08c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a08c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a08c1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a08c2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a08c3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a08c4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a08c5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a08c6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a08c8  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a08ca  80b88900000000         +cmp byte ptr [eax + 0x89], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(137) /* 0x89 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a08d1  0f8499000000           -je 0x4a0970
    if (cpu.flags.zf)
    {
        goto L_0x004a0970;
    }
    // 004a08d7  8b15ccd46f00           -mov edx, dword ptr [0x6fd4cc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(7328972) /* 0x6fd4cc */);
    // 004a08dd  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a08df  7439                   -je 0x4a091a
    if (cpu.flags.zf)
    {
        goto L_0x004a091a;
    }
    // 004a08e1  e8eac40300             -call 0x4dcdd0
    cpu.esp -= 4;
    sub_4dcdd0(app, cpu);
    if (cpu.terminate) return;
    // 004a08e6  8b591c                 -mov ebx, dword ptr [ecx + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 004a08e9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a08ea  8bb1a0000000           -mov esi, dword ptr [ecx + 0xa0]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(160) /* 0xa0 */);
    // 004a08f0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a08f1  8bb99c000000           -mov edi, dword ptr [ecx + 0x9c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(156) /* 0x9c */);
    // 004a08f7  898160010000           -mov dword ptr [ecx + 0x160], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(352) /* 0x160 */) = cpu.eax;
    // 004a08fd  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a08fe  8b8198000000           -mov eax, dword ptr [ecx + 0x98]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(152) /* 0x98 */);
    // 004a0904  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a0905  e8e602f8ff             -call 0x420bf0
    cpu.esp -= 4;
    sub_420bf0(app, cpu);
    if (cpu.terminate) return;
    // 004a090a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a090c  7412                   -je 0x4a0920
    if (cpu.flags.zf)
    {
        goto L_0x004a0920;
    }
    // 004a090e  c7816001000000000000   -mov dword ptr [ecx + 0x160], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(352) /* 0x160 */) = 0 /*0x0*/;
    // 004a0918  eb06                   -jmp 0x4a0920
    goto L_0x004a0920;
L_0x004a091a:
    // 004a091a  899160010000           -mov dword ptr [ecx + 0x160], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(352) /* 0x160 */) = cpu.edx;
L_0x004a0920:
    // 004a0920  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a0922  e859fcffff             -call 0x4a0580
    cpu.esp -= 4;
    sub_4a0580(app, cpu);
    if (cpu.terminate) return;
    // 004a0927  83b98401000000         +cmp dword ptr [ecx + 0x184], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(388) /* 0x184 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a092e  7406                   -je 0x4a0936
    if (cpu.flags.zf)
    {
        goto L_0x004a0936;
    }
    // 004a0930  83792000               +cmp dword ptr [ecx + 0x20], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a0934  743a                   -je 0x4a0970
    if (cpu.flags.zf)
    {
        goto L_0x004a0970;
    }
L_0x004a0936:
    // 004a0936  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a0938  e833f5ffff             -call 0x49fe70
    cpu.esp -= 4;
    sub_49fe70(app, cpu);
    if (cpu.terminate) return;
    // 004a093d  6683797600             +cmp word ptr [ecx + 0x76], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(118) /* 0x76 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004a0942  7407                   -je 0x4a094b
    if (cpu.flags.zf)
    {
        goto L_0x004a094b;
    }
    // 004a0944  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a0946  e855f6ffff             -call 0x49ffa0
    cpu.esp -= 4;
    sub_49ffa0(app, cpu);
    if (cpu.terminate) return;
L_0x004a094b:
    // 004a094b  80b98800000000         +cmp byte ptr [ecx + 0x88], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(136) /* 0x88 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a0952  751c                   -jne 0x4a0970
    if (!cpu.flags.zf)
    {
        goto L_0x004a0970;
    }
    // 004a0954  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004a0959  8d410c                 -lea eax, [ecx + 0xc]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004a095c  e87ffef7ff             -call 0x4207e0
    cpu.esp -= 4;
    sub_4207e0(app, cpu);
    if (cpu.terminate) return;
    // 004a0961  898188010000           -mov dword ptr [ecx + 0x188], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(392) /* 0x188 */) = cpu.eax;
    // 004a0967  83e03f                 -and eax, 0x3f
    cpu.eax &= x86::reg32(x86::sreg32(63 /*0x3f*/));
    // 004a096a  89818c010000           -mov dword ptr [ecx + 0x18c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(396) /* 0x18c */) = cpu.eax;
L_0x004a0970:
    // 004a0970  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0971  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0972  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0973  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0974  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0975  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0976  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_4a0980(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a0980  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a0981  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a0982  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a0983  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a0984  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a0986  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a0988  7518                   -jne 0x4a09a2
    if (!cpu.flags.zf)
    {
        goto L_0x004a09a2;
    }
    // 004a098a  b909000000             -mov ecx, 9
    cpu.ecx = 9 /*0x9*/;
    // 004a098f  8db8c0000000           -lea edi, [eax + 0xc0]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(192) /* 0xc0 */);
    // 004a0995  8db024010000           -lea esi, [eax + 0x124]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(292) /* 0x124 */);
    // 004a099b  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a099d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a099e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a099f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a09a0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a09a1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a09a2:
    // 004a09a2  d98024010000           -fld dword ptr [eax + 0x124]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(292) /* 0x124 */)));
    // 004a09a8  8d90c0000000           -lea edx, [eax + 0xc0]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(192) /* 0xc0 */);
    // 004a09ae  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 004a09b0  d91a                   -fstp dword ptr [edx]
    app->getMemory<float>(cpu.edx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a09b2  d98028010000           -fld dword ptr [eax + 0x128]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(296) /* 0x128 */)));
    // 004a09b8  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 004a09ba  d95a04                 -fstp dword ptr [edx + 4]
    app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a09bd  d9802c010000           -fld dword ptr [eax + 0x12c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(300) /* 0x12c */)));
    // 004a09c3  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 004a09c5  d95a08                 -fstp dword ptr [edx + 8]
    app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a09c8  8b8830010000           -mov ecx, dword ptr [eax + 0x130]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(304) /* 0x130 */);
    // 004a09ce  894a0c                 -mov dword ptr [edx + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004a09d1  8b8834010000           -mov ecx, dword ptr [eax + 0x134]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(308) /* 0x134 */);
    // 004a09d7  894a10                 -mov dword ptr [edx + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 004a09da  8b8838010000           -mov ecx, dword ptr [eax + 0x138]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(312) /* 0x138 */);
    // 004a09e0  894a14                 -mov dword ptr [edx + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 004a09e3  d9803c010000           -fld dword ptr [eax + 0x13c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(316) /* 0x13c */)));
    // 004a09e9  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 004a09eb  d95a18                 -fstp dword ptr [edx + 0x18]
    app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a09ee  d98040010000           -fld dword ptr [eax + 0x140]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(320) /* 0x140 */)));
    // 004a09f4  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 004a09f6  d95a1c                 -fstp dword ptr [edx + 0x1c]
    app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a09f9  d98044010000           -fld dword ptr [eax + 0x144]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(324) /* 0x144 */)));
    // 004a09ff  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 004a0a01  d95a20                 -fstp dword ptr [edx + 0x20]
    app->getMemory<float>(cpu.edx + x86::reg32(32) /* 0x20 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a0a04  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0a05  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0a06  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0a07  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0a08  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4a0a10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a0a10  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a0a11  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a0a12  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a0a13  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a0a14  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a0a16  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a0a18  7518                   -jne 0x4a0a32
    if (!cpu.flags.zf)
    {
        goto L_0x004a0a32;
    }
    // 004a0a1a  b909000000             -mov ecx, 9
    cpu.ecx = 9 /*0x9*/;
    // 004a0a1f  8db890010000           -lea edi, [eax + 0x190]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(400) /* 0x190 */);
    // 004a0a25  8db024010000           -lea esi, [eax + 0x124]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(292) /* 0x124 */);
    // 004a0a2b  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a0a2d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0a2e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0a2f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0a30  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0a31  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a0a32:
    // 004a0a32  d98024010000           -fld dword ptr [eax + 0x124]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(292) /* 0x124 */)));
    // 004a0a38  8d9090010000           -lea edx, [eax + 0x190]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(400) /* 0x190 */);
    // 004a0a3e  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 004a0a40  d91a                   -fstp dword ptr [edx]
    app->getMemory<float>(cpu.edx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a0a42  d98028010000           -fld dword ptr [eax + 0x128]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(296) /* 0x128 */)));
    // 004a0a48  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 004a0a4a  d95a04                 -fstp dword ptr [edx + 4]
    app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a0a4d  d9802c010000           -fld dword ptr [eax + 0x12c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(300) /* 0x12c */)));
    // 004a0a53  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 004a0a55  d95a08                 -fstp dword ptr [edx + 8]
    app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a0a58  8b8830010000           -mov ecx, dword ptr [eax + 0x130]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(304) /* 0x130 */);
    // 004a0a5e  894a0c                 -mov dword ptr [edx + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004a0a61  8b8834010000           -mov ecx, dword ptr [eax + 0x134]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(308) /* 0x134 */);
    // 004a0a67  894a10                 -mov dword ptr [edx + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 004a0a6a  8b8838010000           -mov ecx, dword ptr [eax + 0x138]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(312) /* 0x138 */);
    // 004a0a70  894a14                 -mov dword ptr [edx + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 004a0a73  d9803c010000           -fld dword ptr [eax + 0x13c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(316) /* 0x13c */)));
    // 004a0a79  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 004a0a7b  d95a18                 -fstp dword ptr [edx + 0x18]
    app->getMemory<float>(cpu.edx + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a0a7e  d98040010000           -fld dword ptr [eax + 0x140]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(320) /* 0x140 */)));
    // 004a0a84  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 004a0a86  d95a1c                 -fstp dword ptr [edx + 0x1c]
    app->getMemory<float>(cpu.edx + x86::reg32(28) /* 0x1c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a0a89  d98044010000           -fld dword ptr [eax + 0x144]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(324) /* 0x144 */)));
    // 004a0a8f  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 004a0a91  d95a20                 -fstp dword ptr [edx + 0x20]
    app->getMemory<float>(cpu.edx + x86::reg32(32) /* 0x20 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a0a94  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0a95  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0a96  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0a97  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0a98  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4a0aa0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a0aa0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a0aa1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a0aa2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a0aa3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a0aa5  83ec48                 -sub esp, 0x48
    (cpu.esp) -= x86::reg32(x86::sreg32(72 /*0x48*/));
    // 004a0aa8  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a0aaa  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004a0aac  895df8                 -mov dword ptr [ebp - 8], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ebx;
    // 004a0aaf  8d580c                 -lea ebx, [eax + 0xc]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004a0ab2  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004a0ab4  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a0ab6  e885def7ff             -call 0x41e940
    cpu.esp -= 4;
    sub_41e940(app, cpu);
    if (cpu.terminate) return;
    // 004a0abb  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a0abd  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004a0ac0  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 004a0ac2  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004a0ac5  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 004a0ac8  8b55f4                 -mov edx, dword ptr [ebp - 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004a0acb  a148d95d00             -mov eax, dword ptr [0x5dd948]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6150472) /* 0x5dd948 */);
    // 004a0ad0  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a0ad2  897e08                 -mov dword ptr [esi + 8], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 004a0ad5  8b5015                 -mov edx, dword ptr [eax + 0x15]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(21) /* 0x15 */);
    // 004a0ad8  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004a0adb  c1e209                 -shl edx, 9
    cpu.edx <<= 9 /*0x9*/ % 32;
    // 004a0ade  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 004a0ae1  dd05e4c75300           -fld qword ptr [0x53c7e4]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(5490660) /* 0x53c7e4 */)));
    // 004a0ae7  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 004a0aea  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004a0aec  d99e24010000           -fstp dword ptr [esi + 0x124]
    app->getMemory<float>(cpu.esi + x86::reg32(292) /* 0x124 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a0af2  8b5016                 -mov edx, dword ptr [eax + 0x16]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(22) /* 0x16 */);
    // 004a0af5  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004a0af8  c1e209                 -shl edx, 9
    cpu.edx <<= 9 /*0x9*/ % 32;
    // 004a0afb  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 004a0afe  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 004a0b01  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004a0b03  d99e28010000           -fstp dword ptr [esi + 0x128]
    app->getMemory<float>(cpu.esi + x86::reg32(296) /* 0x128 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a0b09  8b5017                 -mov edx, dword ptr [eax + 0x17]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(23) /* 0x17 */);
    // 004a0b0c  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004a0b0f  c1e209                 -shl edx, 9
    cpu.edx <<= 9 /*0x9*/ % 32;
    // 004a0b12  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 004a0b15  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 004a0b18  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004a0b1a  d99e2c010000           -fstp dword ptr [esi + 0x12c]
    app->getMemory<float>(cpu.esi + x86::reg32(300) /* 0x12c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a0b20  8b500d                 -mov edx, dword ptr [eax + 0xd]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(13) /* 0xd */);
    // 004a0b23  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004a0b26  c1e209                 -shl edx, 9
    cpu.edx <<= 9 /*0x9*/ % 32;
    // 004a0b29  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 004a0b2c  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 004a0b2f  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004a0b31  d99e30010000           -fstp dword ptr [esi + 0x130]
    app->getMemory<float>(cpu.esi + x86::reg32(304) /* 0x130 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a0b37  8b500e                 -mov edx, dword ptr [eax + 0xe]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(14) /* 0xe */);
    // 004a0b3a  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004a0b3d  c1e209                 -shl edx, 9
    cpu.edx <<= 9 /*0x9*/ % 32;
    // 004a0b40  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 004a0b43  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 004a0b46  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004a0b48  d99e34010000           -fstp dword ptr [esi + 0x134]
    app->getMemory<float>(cpu.esi + x86::reg32(308) /* 0x134 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a0b4e  8b500f                 -mov edx, dword ptr [eax + 0xf]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(15) /* 0xf */);
    // 004a0b51  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004a0b54  c1e209                 -shl edx, 9
    cpu.edx <<= 9 /*0x9*/ % 32;
    // 004a0b57  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 004a0b5a  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 004a0b5d  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004a0b5f  d99e38010000           -fstp dword ptr [esi + 0x138]
    app->getMemory<float>(cpu.esi + x86::reg32(312) /* 0x138 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a0b65  8b5011                 -mov edx, dword ptr [eax + 0x11]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(17) /* 0x11 */);
    // 004a0b68  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004a0b6b  c1e209                 -shl edx, 9
    cpu.edx <<= 9 /*0x9*/ % 32;
    // 004a0b6e  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 004a0b71  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 004a0b74  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004a0b76  d99e3c010000           -fstp dword ptr [esi + 0x13c]
    app->getMemory<float>(cpu.esi + x86::reg32(316) /* 0x13c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a0b7c  8b5012                 -mov edx, dword ptr [eax + 0x12]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(18) /* 0x12 */);
    // 004a0b7f  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004a0b82  c1e209                 -shl edx, 9
    cpu.edx <<= 9 /*0x9*/ % 32;
    // 004a0b85  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 004a0b88  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 004a0b8b  dec9                   -fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004a0b8d  d99e40010000           -fstp dword ptr [esi + 0x140]
    app->getMemory<float>(cpu.esi + x86::reg32(320) /* 0x140 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a0b93  8b4013                 -mov eax, dword ptr [eax + 0x13]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(19) /* 0x13 */);
    // 004a0b96  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004a0b99  c1e009                 -shl eax, 9
    cpu.eax <<= 9 /*0x9*/ % 32;
    // 004a0b9c  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004a0b9f  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 004a0ba2  dc0de4c75300           -fmul qword ptr [0x53c7e4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5490660) /* 0x53c7e4 */));
    // 004a0ba8  8dbe24010000           -lea edi, [esi + 0x124]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(292) /* 0x124 */);
    // 004a0bae  8d55b8                 -lea edx, [ebp - 0x48]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-72) /* -0x48 */);
    // 004a0bb1  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a0bb3  d99e44010000           -fstp dword ptr [esi + 0x144]
    app->getMemory<float>(cpu.esi + x86::reg32(324) /* 0x144 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a0bb9  e83267ffff             -call 0x4972f0
    cpu.esp -= 4;
    sub_4972f0(app, cpu);
    if (cpu.terminate) return;
    // 004a0bbe  8d8630010000           -lea eax, [esi + 0x130]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(304) /* 0x130 */);
    // 004a0bc4  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a0bc6  e82567ffff             -call 0x4972f0
    cpu.esp -= 4;
    sub_4972f0(app, cpu);
    if (cpu.terminate) return;
    // 004a0bcb  8d863c010000           -lea eax, [esi + 0x13c]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(316) /* 0x13c */);
    // 004a0bd1  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a0bd3  e81867ffff             -call 0x4972f0
    cpu.esp -= 4;
    sub_4972f0(app, cpu);
    if (cpu.terminate) return;
    // 004a0bd8  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a0bda  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a0bdc  e82ff50300             -call 0x4e0110
    cpu.esp -= 4;
    sub_4e0110(app, cpu);
    if (cpu.terminate) return;
    // 004a0be1  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004a0be4  db00                   -fild dword ptr [eax]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax))));
    // 004a0be6  dc0de4c75300           -fmul qword ptr [0x53c7e4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5490660) /* 0x53c7e4 */));
    // 004a0bec  d95ddc                 -fstp dword ptr [ebp - 0x24]
    app->getMemory<float>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a0bef  db4004                 -fild dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */))));
    // 004a0bf2  dc0de4c75300           -fmul qword ptr [0x53c7e4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5490660) /* 0x53c7e4 */));
    // 004a0bf8  d95de0                 -fstp dword ptr [ebp - 0x20]
    app->getMemory<float>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a0bfb  db4008                 -fild dword ptr [eax + 8]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */))));
    // 004a0bfe  dc0de4c75300           -fmul qword ptr [0x53c7e4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5490660) /* 0x53c7e4 */));
    // 004a0c04  8d55b8                 -lea edx, [ebp - 0x48]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-72) /* -0x48 */);
    // 004a0c07  8b45dc                 -mov eax, dword ptr [ebp - 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 004a0c0a  d95de4                 -fstp dword ptr [ebp - 0x1c]
    app->getMemory<float>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a0c0d  8986bc000000           -mov dword ptr [esi + 0xbc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(188) /* 0xbc */) = cpu.eax;
    // 004a0c13  8d45dc                 -lea eax, [ebp - 0x24]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 004a0c16  8b7df4                 -mov edi, dword ptr [ebp - 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004a0c19  e8d2f50300             -call 0x4e01f0
    cpu.esp -= 4;
    sub_4e01f0(app, cpu);
    if (cpu.terminate) return;
    // 004a0c1e  8d55c4                 -lea edx, [ebp - 0x3c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-60) /* -0x3c */);
    // 004a0c21  8d45dc                 -lea eax, [ebp - 0x24]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 004a0c24  d95de8                 -fstp dword ptr [ebp - 0x18]
    app->getMemory<float>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a0c27  e8c4f50300             -call 0x4e01f0
    cpu.esp -= 4;
    sub_4e01f0(app, cpu);
    if (cpu.terminate) return;
    // 004a0c2c  8d55d0                 -lea edx, [ebp - 0x30]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-48) /* -0x30 */);
    // 004a0c2f  8d45dc                 -lea eax, [ebp - 0x24]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 004a0c32  d95dec                 -fstp dword ptr [ebp - 0x14]
    app->getMemory<float>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a0c35  e8b6f50300             -call 0x4e01f0
    cpu.esp -= 4;
    sub_4e01f0(app, cpu);
    if (cpu.terminate) return;
    // 004a0c3a  a148d95d00             -mov eax, dword ptr [0x5dd948]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6150472) /* 0x5dd948 */);
    // 004a0c3f  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 004a0c41  db00                   -fild dword ptr [eax]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax))));
    // 004a0c43  dc0de4c75300           -fmul qword ptr [0x53c7e4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5490660) /* 0x53c7e4 */));
    // 004a0c49  d845e8                 -fadd dword ptr [ebp - 0x18]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-24) /* -0x18 */));
    // 004a0c4c  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a0c4e  d95df0                 -fstp dword ptr [ebp - 0x10]
    app->getMemory<float>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a0c51  d99e98000000           -fstp dword ptr [esi + 0x98]
    app->getMemory<float>(cpu.esi + x86::reg32(152) /* 0x98 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a0c57  db4004                 -fild dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */))));
    // 004a0c5a  dc0de4c75300           -fmul qword ptr [0x53c7e4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5490660) /* 0x53c7e4 */));
    // 004a0c60  d845ec                 -fadd dword ptr [ebp - 0x14]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-20) /* -0x14 */));
    // 004a0c63  d99e9c000000           -fstp dword ptr [esi + 0x9c]
    app->getMemory<float>(cpu.esi + x86::reg32(156) /* 0x9c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a0c69  db4008                 -fild dword ptr [eax + 8]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */))));
    // 004a0c6c  dc0de4c75300           -fmul qword ptr [0x53c7e4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5490660) /* 0x53c7e4 */));
    // 004a0c72  d845f0                 -fadd dword ptr [ebp - 0x10]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-16) /* -0x10 */));
    // 004a0c75  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a0c77  d99ea0000000           -fstp dword ptr [esi + 0xa0]
    app->getMemory<float>(cpu.esi + x86::reg32(160) /* 0xa0 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a0c7d  e83efcffff             -call 0x4a08c0
    cpu.esp -= 4;
    sub_4a08c0(app, cpu);
    if (cpu.terminate) return;
    // 004a0c82  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a0c84  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004a0c86  e815f3ffff             -call 0x49ffa0
    cpu.esp -= 4;
    sub_49ffa0(app, cpu);
    if (cpu.terminate) return;
    // 004a0c8b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a0c8d  e8eefcffff             -call 0x4a0980
    cpu.esp -= 4;
    sub_4a0980(app, cpu);
    if (cpu.terminate) return;
    // 004a0c92  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004a0c94  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a0c96  e875fdffff             -call 0x4a0a10
    cpu.esp -= 4;
    sub_4a0a10(app, cpu);
    if (cpu.terminate) return;
    // 004a0c9b  a148d95d00             -mov eax, dword ptr [0x5dd948]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6150472) /* 0x5dd948 */);
    // 004a0ca0  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 004a0ca2  db4004                 -fild dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */))));
    // 004a0ca5  dc0de4c75300           -fmul qword ptr [0x53c7e4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5490660) /* 0x53c7e4 */));
    // 004a0cab  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a0cad  d99e58010000           -fstp dword ptr [esi + 0x158]
    app->getMemory<float>(cpu.esi + x86::reg32(344) /* 0x158 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a0cb3  e888f7ffff             -call 0x4a0440
    cpu.esp -= 4;
    sub_4a0440(app, cpu);
    if (cpu.terminate) return;
    // 004a0cb8  d9965c010000           -fst dword ptr [esi + 0x15c]
    app->getMemory<float>(cpu.esi + x86::reg32(348) /* 0x15c */) = float(cpu.fpu.st(0));
    // 004a0cbe  c7865c01000000000000   -mov dword ptr [esi + 0x15c], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(348) /* 0x15c */) = 0 /*0x0*/;
    // 004a0cc8  d8ae9c000000           -fsubr dword ptr [esi + 0x9c]
    cpu.fpu.st(0) = app->getMemory<float>(cpu.esi + x86::reg32(156) /* 0x9c */) - cpu.fpu.st(0);
    // 004a0cce  8aa688000000           -mov ah, byte ptr [esi + 0x88]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(136) /* 0x88 */);
    // 004a0cd4  d99e9c000000           -fstp dword ptr [esi + 0x9c]
    app->getMemory<float>(cpu.esi + x86::reg32(156) /* 0x9c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a0cda  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 004a0cdc  7514                   -jne 0x4a0cf2
    if (!cpu.flags.zf)
    {
        goto L_0x004a0cf2;
    }
    // 004a0cde  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004a0ce3  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a0ce5  e8f6faf7ff             -call 0x4207e0
    cpu.esp -= 4;
    sub_4207e0(app, cpu);
    if (cpu.terminate) return;
    // 004a0cea  898688010000           -mov dword ptr [esi + 0x188], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(392) /* 0x188 */) = cpu.eax;
    // 004a0cf0  eb0a                   -jmp 0x4a0cfc
    goto L_0x004a0cfc;
L_0x004a0cf2:
    // 004a0cf2  c7868801000001000000   -mov dword ptr [esi + 0x188], 1
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(392) /* 0x188 */) = 1 /*0x1*/;
L_0x004a0cfc:
    // 004a0cfc  8b8688010000           -mov eax, dword ptr [esi + 0x188]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(392) /* 0x188 */);
    // 004a0d02  83e03f                 -and eax, 0x3f
    cpu.eax &= x86::reg32(x86::sreg32(63 /*0x3f*/));
    // 004a0d05  89868c010000           -mov dword ptr [esi + 0x18c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(396) /* 0x18c */) = cpu.eax;
    // 004a0d0b  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004a0d0d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0d0e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0d0f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0d10  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_4a0d20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a0d20  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a0d21  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a0d22  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a0d23  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a0d25  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a0d28  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a0d2a  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004a0d2c  bae4010000             -mov edx, 0x1e4
    cpu.edx = 484 /*0x1e4*/;
    // 004a0d31  e8d6f90300             -call 0x4e070c
    cpu.esp -= 4;
    sub_4e070c(app, cpu);
    if (cpu.terminate) return;
    // 004a0d36  d94514                 -fld dword ptr [ebp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(20) /* 0x14 */)));
    // 004a0d39  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004a0d3c  8919                   -mov dword ptr [ecx], ebx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.ebx;
    // 004a0d3e  d84d14                 -fmul dword ptr [ebp + 0x14]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(20) /* 0x14 */));
    // 004a0d41  898114010000           -mov dword ptr [ecx + 0x114], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(276) /* 0x114 */) = cpu.eax;
    // 004a0d47  d94518                 -fld dword ptr [ebp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(24) /* 0x18 */)));
    // 004a0d4a  8b4518                 -mov eax, dword ptr [ebp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 004a0d4d  d84d18                 -fmul dword ptr [ebp + 0x18]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(24) /* 0x18 */));
    // 004a0d50  898118010000           -mov dword ptr [ecx + 0x118], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(280) /* 0x118 */) = cpu.eax;
    // 004a0d56  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004a0d58  8b451c                 -mov eax, dword ptr [ebp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 004a0d5b  d9451c                 -fld dword ptr [ebp + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(28) /* 0x1c */)));
    // 004a0d5e  d8c8                   -fmul st(0)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(0));
    // 004a0d60  89811c010000           -mov dword ptr [ecx + 0x11c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(284) /* 0x11c */) = cpu.eax;
    // 004a0d66  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004a0d68  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a0d6b  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a0d6e  e8ad9b0400             -call 0x4ea920
    cpu.esp -= 4;
    sub_4ea920(app, cpu);
    if (cpu.terminate) return;
    // 004a0d73  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004a0d76  d99920010000           -fstp dword ptr [ecx + 0x120]
    app->getMemory<float>(cpu.ecx + x86::reg32(288) /* 0x120 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a0d7c  8981b0000000           -mov dword ptr [ecx + 0xb0], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(176) /* 0xb0 */) = cpu.eax;
    // 004a0d82  a9ffffff7f             +test eax, 0x7fffffff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2147483647 /*0x7fffffff*/));
    // 004a0d87  750a                   -jne 0x4a0d93
    if (!cpu.flags.zf)
    {
        goto L_0x004a0d93;
    }
    // 004a0d89  c781b000000000007a44   -mov dword ptr [ecx + 0xb0], 0x447a0000
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(176) /* 0xb0 */) = 1148846080 /*0x447a0000*/;
L_0x004a0d93:
    // 004a0d93  d981b0000000           -fld dword ptr [ecx + 0xb0]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(176) /* 0xb0 */)));
    // 004a0d99  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 004a0d9b  def1                   -fdivrp st(1)
    cpu.fpu.st(1) = cpu.fpu.st(0) / x86::Float(cpu.fpu.st(1));
    cpu.fpu.pop();
    // 004a0d9d  d9451c                 -fld dword ptr [ebp + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(28) /* 0x1c */)));
    // 004a0da0  dcc8                   -fmul st(0), st(0)
    cpu.fpu.st(0) *= cpu.fpu.st(0);
    // 004a0da2  d94518                 -fld dword ptr [ebp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(24) /* 0x18 */)));
    // 004a0da5  dcc8                   -fmul st(0), st(0)
    cpu.fpu.st(0) *= cpu.fpu.st(0);
    // 004a0da7  d9c1                   -fld st(1)
    cpu.fpu.push(x86::Float(cpu.fpu.st(1)));
    // 004a0da9  d8c1                   -fadd st(1)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(1));
    // 004a0dab  dd05ecc75300           -fld qword ptr [0x53c7ec]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(5490668) /* 0x53c7ec */)));
    // 004a0db1  d981b0000000           -fld dword ptr [ecx + 0xb0]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(176) /* 0xb0 */)));
    // 004a0db7  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004a0db9  deca                   -fmulp st(2)
    cpu.fpu.st(2) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004a0dbb  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a0dbd  d991f0000000           -fst dword ptr [ecx + 0xf0]
    app->getMemory<float>(cpu.ecx + x86::reg32(240) /* 0xf0 */) = float(cpu.fpu.st(0));
    // 004a0dc3  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 004a0dc5  def1                   -fdivrp st(1)
    cpu.fpu.st(1) = cpu.fpu.st(0) / x86::Float(cpu.fpu.st(1));
    cpu.fpu.pop();
    // 004a0dc7  d94514                 -fld dword ptr [ebp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(20) /* 0x14 */)));
    // 004a0dca  dcc8                   -fmul st(0), st(0)
    cpu.fpu.st(0) *= cpu.fpu.st(0);
    // 004a0dcc  dcc4                   -fadd st(4), st(0)
    cpu.fpu.st(4) += x86::Float(cpu.fpu.st(0));
    // 004a0dce  d981b0000000           -fld dword ptr [ecx + 0xb0]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(176) /* 0xb0 */)));
    // 004a0dd4  d8cb                   -fmul st(3)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(3));
    // 004a0dd6  decd                   -fmulp st(5)
    cpu.fpu.st(5) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004a0dd8  d9cc                   -fxch st(4)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(4);
        cpu.fpu.st(4) = tmp;
    }
    // 004a0dda  d991f4000000           -fst dword ptr [ecx + 0xf4]
    app->getMemory<float>(cpu.ecx + x86::reg32(244) /* 0xf4 */) = float(cpu.fpu.st(0));
    // 004a0de0  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 004a0de2  def1                   -fdivrp st(1)
    cpu.fpu.st(1) = cpu.fpu.st(0) / x86::Float(cpu.fpu.st(1));
    cpu.fpu.pop();
    // 004a0de4  d9cc                   -fxch st(4)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(4);
        cpu.fpu.st(4) = tmp;
    }
    // 004a0de6  dec3                   -faddp st(3)
    cpu.fpu.st(3) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004a0de8  d981b0000000           -fld dword ptr [ecx + 0xb0]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(176) /* 0xb0 */)));
    // 004a0dee  deca                   -fmulp st(2)
    cpu.fpu.st(2) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004a0df0  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a0df2  deca                   -fmulp st(2)
    cpu.fpu.st(2) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004a0df4  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a0df6  d991f8000000           -fst dword ptr [ecx + 0xf8]
    app->getMemory<float>(cpu.ecx + x86::reg32(248) /* 0xf8 */) = float(cpu.fpu.st(0));
    // 004a0dfc  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 004a0dfe  def1                   -fdivrp st(1)
    cpu.fpu.st(1) = cpu.fpu.st(0) / x86::Float(cpu.fpu.st(1));
    cpu.fpu.pop();
    // 004a0e00  c7412000000000         -mov dword ptr [ecx + 0x20], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 004a0e07  c7412c00000000         -mov dword ptr [ecx + 0x2c], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */) = 0 /*0x0*/;
    // 004a0e0e  c6818800000000         -mov byte ptr [ecx + 0x88], 0
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(136) /* 0x88 */) = 0 /*0x0*/;
    // 004a0e15  c781a400000000000000   -mov dword ptr [ecx + 0xa4], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(164) /* 0xa4 */) = 0 /*0x0*/;
    // 004a0e1f  c781a800000000000000   -mov dword ptr [ecx + 0xa8], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(168) /* 0xa8 */) = 0 /*0x0*/;
    // 004a0e29  c781ac00000000000000   -mov dword ptr [ecx + 0xac], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(172) /* 0xac */) = 0 /*0x0*/;
    // 004a0e33  c781e400000000000000   -mov dword ptr [ecx + 0xe4], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(228) /* 0xe4 */) = 0 /*0x0*/;
    // 004a0e3d  c781e800000000000000   -mov dword ptr [ecx + 0xe8], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(232) /* 0xe8 */) = 0 /*0x0*/;
    // 004a0e47  c781ec00000000000000   -mov dword ptr [ecx + 0xec], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(236) /* 0xec */) = 0 /*0x0*/;
    // 004a0e51  c7810801000000000000   -mov dword ptr [ecx + 0x108], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(264) /* 0x108 */) = 0 /*0x0*/;
    // 004a0e5b  c7810c0100000000803f   -mov dword ptr [ecx + 0x10c], 0x3f800000
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(268) /* 0x10c */) = 1065353216 /*0x3f800000*/;
    // 004a0e65  c7811001000000000000   -mov dword ptr [ecx + 0x110], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(272) /* 0x110 */) = 0 /*0x0*/;
    // 004a0e6f  66c781640100000000     -mov word ptr [ecx + 0x164], 0
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(356) /* 0x164 */) = 0 /*0x0*/;
    // 004a0e78  c6818b00000000         -mov byte ptr [ecx + 0x8b], 0
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(139) /* 0x8b */) = 0 /*0x0*/;
    // 004a0e7f  c7818801000001000000   -mov dword ptr [ecx + 0x188], 1
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(392) /* 0x188 */) = 1 /*0x1*/;
    // 004a0e89  c7815c01000000000000   -mov dword ptr [ecx + 0x15c], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(348) /* 0x15c */) = 0 /*0x0*/;
    // 004a0e93  c781900000000000803f   -mov dword ptr [ecx + 0x90], 0x3f800000
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(144) /* 0x90 */) = 1065353216 /*0x3f800000*/;
    // 004a0e9d  c781bc00000000000000   -mov dword ptr [ecx + 0xbc], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(188) /* 0xbc */) = 0 /*0x0*/;
    // 004a0ea7  c7816801000000000000   -mov dword ptr [ecx + 0x168], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(360) /* 0x168 */) = 0 /*0x0*/;
    // 004a0eb1  c7816c01000000000000   -mov dword ptr [ecx + 0x16c], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(364) /* 0x16c */) = 0 /*0x0*/;
    // 004a0ebb  c7817001000000000000   -mov dword ptr [ecx + 0x170], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(368) /* 0x170 */) = 0 /*0x0*/;
    // 004a0ec5  c7817401000000000000   -mov dword ptr [ecx + 0x174], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(372) /* 0x174 */) = 0 /*0x0*/;
    // 004a0ecf  c7818401000000000000   -mov dword ptr [ecx + 0x184], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(388) /* 0x184 */) = 0 /*0x0*/;
    // 004a0ed9  8b8188010000           -mov eax, dword ptr [ecx + 0x188]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(392) /* 0x188 */);
    // 004a0edf  89818c010000           -mov dword ptr [ecx + 0x18c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(396) /* 0x18c */) = cpu.eax;
    // 004a0ee5  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004a0ee7  d999b4000000           -fstp dword ptr [ecx + 0xb4]
    app->getMemory<float>(cpu.ecx + x86::reg32(180) /* 0xb4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a0eed  d999fc000000           -fstp dword ptr [ecx + 0xfc]
    app->getMemory<float>(cpu.ecx + x86::reg32(252) /* 0xfc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a0ef3  d99900010000           -fstp dword ptr [ecx + 0x100]
    app->getMemory<float>(cpu.ecx + x86::reg32(256) /* 0x100 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a0ef9  d99904010000           -fstp dword ptr [ecx + 0x104]
    app->getMemory<float>(cpu.ecx + x86::reg32(260) /* 0x104 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a0eff  66c781660100000000     -mov word ptr [ecx + 0x166], 0
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(358) /* 0x166 */) = 0 /*0x0*/;
    // 004a0f08  c6818900000001         -mov byte ptr [ecx + 0x89], 1
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(137) /* 0x89 */) = 1 /*0x1*/;
    // 004a0f0f  c6818a00000000         -mov byte ptr [ecx + 0x8a], 0
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(138) /* 0x8a */) = 0 /*0x0*/;
    // 004a0f16  c7819400000000000000   -mov dword ptr [ecx + 0x94], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(148) /* 0x94 */) = 0 /*0x0*/;
    // 004a0f20  c6818c00000000         -mov byte ptr [ecx + 0x8c], 0
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(140) /* 0x8c */) = 0 /*0x0*/;
    // 004a0f27  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004a0f29  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0f2a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0f2b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0f2c  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a0f30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a0f30  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a0f31  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a0f32  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a0f33  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a0f34  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a0f35  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a0f37  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a0f3a  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004a0f3d  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004a0f3f  f6800002000004         +test byte ptr [eax + 0x200], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(512) /* 0x200 */) & 4 /*0x4*/));
    // 004a0f46  7543                   -jne 0x4a0f8b
    if (!cpu.flags.zf)
    {
        goto L_0x004a0f8b;
    }
    // 004a0f48  d94518                 +fld dword ptr [ebp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(24) /* 0x18 */)));
    // 004a0f4b  d81df4c75300           +fcomp dword ptr [0x53c7f4]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(5490676) /* 0x53c7f4 */)));
    cpu.fpu.pop();
    // 004a0f51  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004a0f53  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004a0f54  7635                   -jbe 0x4a0f8b
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a0f8b;
    }
    // 004a0f56  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004a0f59  b909000000             -mov ecx, 9
    cpu.ecx = 9 /*0x9*/;
    // 004a0f5e  8db890010000           -lea edi, [eax + 0x190]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(400) /* 0x190 */);
    // 004a0f64  8db0c0000000           -lea esi, [eax + 0xc0]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(192) /* 0xc0 */);
    // 004a0f6a  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a0f6c  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a0f6e  89909c010000           -mov dword ptr [eax + 0x19c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(412) /* 0x19c */) = cpu.edx;
    // 004a0f74  8b5304                 -mov edx, dword ptr [ebx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a0f77  8990a0010000           -mov dword ptr [eax + 0x1a0], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(416) /* 0x1a0 */) = cpu.edx;
    // 004a0f7d  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004a0f80  8990a4010000           -mov dword ptr [eax + 0x1a4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(420) /* 0x1a4 */) = cpu.edx;
    // 004a0f86  e9f6000000             -jmp 0x4a1081
    goto L_0x004a1081;
L_0x004a0f8b:
    // 004a0f8b  d94518                 +fld dword ptr [ebp + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(24) /* 0x18 */)));
    // 004a0f8e  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004a0f91  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a0f93  89909c010000           -mov dword ptr [eax + 0x19c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(412) /* 0x19c */) = cpu.edx;
    // 004a0f99  8b5304                 -mov edx, dword ptr [ebx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a0f9c  8990a0010000           -mov dword ptr [eax + 0x1a0], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(416) /* 0x1a0 */) = cpu.edx;
    // 004a0fa2  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004a0fa5  8990a4010000           -mov dword ptr [eax + 0x1a4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(420) /* 0x1a4 */) = cpu.edx;
    // 004a0fab  d81df8c75300           +fcomp dword ptr [0x53c7f8]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(5490680) /* 0x53c7f8 */)));
    cpu.fpu.pop();
    // 004a0fb1  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004a0fb3  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004a0fb4  0f837e000000           -jae 0x4a1038
    if (!cpu.flags.cf)
    {
        goto L_0x004a1038;
    }
    // 004a0fba  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004a0fbd  81c1c0000000           +add ecx, 0xc0
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(192 /*0xc0*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a0fc3  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004a0fc5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a0fc7  e824f20300             -call 0x4e01f0
    cpu.esp -= 4;
    sub_4e01f0(app, cpu);
    if (cpu.terminate) return;
    // 004a0fcc  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 004a0fce  ded9                   +fcompp 
    cpu.fpu.compare(cpu.fpu.st(0), cpu.fpu.st(1));
    cpu.fpu.pop();
    cpu.fpu.pop();
    // 004a0fd0  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004a0fd2  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004a0fd3  730b                   -jae 0x4a0fe0
    if (!cpu.flags.cf)
    {
        goto L_0x004a0fe0;
    }
    // 004a0fd5  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004a0fd7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a0fd9  e812f20300             -call 0x4e01f0
    cpu.esp -= 4;
    sub_4e01f0(app, cpu);
    if (cpu.terminate) return;
    // 004a0fde  eb0b                   -jmp 0x4a0feb
    goto L_0x004a0feb;
L_0x004a0fe0:
    // 004a0fe0  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004a0fe2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a0fe4  e807f20300             -call 0x4e01f0
    cpu.esp -= 4;
    sub_4e01f0(app, cpu);
    if (cpu.terminate) return;
    // 004a0fe9  d9e0                   +fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
L_0x004a0feb:
    // 004a0feb  d95df8                 +fstp dword ptr [ebp - 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a0fee  d945f8                 +fld dword ptr [ebp - 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 004a0ff1  d81df8c75300           +fcomp dword ptr [0x53c7f8]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(5490680) /* 0x53c7f8 */)));
    cpu.fpu.pop();
    // 004a0ff7  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004a0ff9  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004a0ffa  763c                   -jbe 0x4a1038
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a1038;
    }
    // 004a0ffc  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004a0fff  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004a1002  8b7dfc                 -mov edi, dword ptr [ebp - 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004a1005  81c190010000           -add ecx, 0x190
    (cpu.ecx) += x86::reg32(x86::sreg32(400 /*0x190*/));
    // 004a100b  81c2d8000000           -add edx, 0xd8
    (cpu.edx) += x86::reg32(x86::sreg32(216 /*0xd8*/));
    // 004a1011  81c79c010000           -add edi, 0x19c
    (cpu.edi) += x86::reg32(x86::sreg32(412 /*0x19c*/));
    // 004a1017  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004a1019  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a101b  8b75fc                 -mov esi, dword ptr [ebp - 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004a101e  e83df10300             -call 0x4e0160
    cpu.esp -= 4;
    sub_4e0160(app, cpu);
    if (cpu.terminate) return;
    // 004a1023  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a1025  81c6a8010000           +add esi, 0x1a8
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(424 /*0x1a8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a102b  e8c062ffff             -call 0x4972f0
    cpu.esp -= 4;
    sub_4972f0(app, cpu);
    if (cpu.terminate) return;
    // 004a1030  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004a1032  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004a1034  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a1036  eb39                   -jmp 0x4a1071
    goto L_0x004a1071;
L_0x004a1038:
    // 004a1038  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004a103b  8b7dfc                 -mov edi, dword ptr [ebp - 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004a103e  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004a1041  81c1a8010000           -add ecx, 0x1a8
    (cpu.ecx) += x86::reg32(x86::sreg32(424 /*0x1a8*/));
    // 004a1047  81c79c010000           -add edi, 0x19c
    (cpu.edi) += x86::reg32(x86::sreg32(412 /*0x19c*/));
    // 004a104d  05c0000000             -add eax, 0xc0
    (cpu.eax) += x86::reg32(x86::sreg32(192 /*0xc0*/));
    // 004a1052  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004a1054  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004a1056  8b75fc                 -mov esi, dword ptr [ebp - 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004a1059  e802f10300             -call 0x4e0160
    cpu.esp -= 4;
    sub_4e0160(app, cpu);
    if (cpu.terminate) return;
    // 004a105e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a1060  81c690010000           -add esi, 0x190
    (cpu.esi) += x86::reg32(x86::sreg32(400 /*0x190*/));
    // 004a1066  e88562ffff             -call 0x4972f0
    cpu.esp -= 4;
    sub_4972f0(app, cpu);
    if (cpu.terminate) return;
    // 004a106b  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004a106d  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004a106f  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x004a1071:
    // 004a1071  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a1073  e8e8f00300             -call 0x4e0160
    cpu.esp -= 4;
    sub_4e0160(app, cpu);
    if (cpu.terminate) return;
    // 004a1078  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a107a  e87162ffff             -call 0x4972f0
    cpu.esp -= 4;
    sub_4972f0(app, cpu);
    if (cpu.terminate) return;
    // 004a107f  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x004a1081:
    // 004a1081  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004a1083  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1084  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1085  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1086  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1087  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1088  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

}
