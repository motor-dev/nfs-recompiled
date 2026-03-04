#include "nfs2se.h"
#include <lib/thread.h>

namespace nfs2se
{

/* align: skip 0x8b 0xc0 */
void Application::sub_48bd14(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048bd14  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048bd15  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048bd19  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048bd1d  8b15cc605200           -mov edx, dword ptr [0x5260cc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5398732) /* 0x5260cc */);
    // 0048bd23  a1f0844c00             -mov eax, dword ptr [0x4c84f0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5014768) /* 0x4c84f0 */);
    // 0048bd28  83c210                 -add edx, 0x10
    (cpu.edx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0048bd2b  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0048bd2d  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0048bd31  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0048bd33  e86df40000             -call 0x49b1a5
    cpu.esp -= 4;
    sub_49b1a5(app, cpu);
    if (cpu.terminate) return;
    // 0048bd38  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bd39  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48bd3c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048bd3c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048bd3d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048bd3e  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0048bd42  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0048bd46  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048bd4a  8b15cc605200           -mov edx, dword ptr [0x5260cc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5398732) /* 0x5260cc */);
    // 0048bd50  a1f0844c00             -mov eax, dword ptr [0x4c84f0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5014768) /* 0x4c84f0 */);
    // 0048bd55  83c210                 -add edx, 0x10
    (cpu.edx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0048bd58  01db                   -add ebx, ebx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0048bd5a  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0048bd5c  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0048bd5e  e842f40000             -call 0x49b1a5
    cpu.esp -= 4;
    sub_49b1a5(app, cpu);
    if (cpu.terminate) return;
    // 0048bd63  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bd64  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bd65  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48bd68(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048bd68  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048bd69  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048bd6a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048bd6b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048bd6c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048bd6d  83ec3c                 -sub esp, 0x3c
    (cpu.esp) -= x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 0048bd70  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 0048bd74  8b0d44824c00           -mov ecx, dword ptr [0x4c8244]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5014084) /* 0x4c8244 */);
    // 0048bd7a  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0048bd7c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048bd7e  7409                   -je 0x48bd89
    if (cpu.flags.zf)
    {
        goto L_0x0048bd89;
    }
L_0x0048bd80:
    // 0048bd80  83c43c                 -add esp, 0x3c
    (cpu.esp) += x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 0048bd83  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bd84  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bd85  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bd86  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bd87  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bd88  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048bd89:
    // 0048bd89  8d7a08                 -lea edi, [edx + 8]
    cpu.edi = x86::reg32(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0048bd8c  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0048bd8e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048bd90  ba6c8a5200             -mov edx, 0x528a6c
    cpu.edx = 5409388 /*0x528a6c*/;
    // 0048bd95  668b4702               -mov ax, word ptr [edi + 2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 0048bd99  668b37                 -mov si, word ptr [edi]
    cpu.si = app->getMemory<x86::reg16>(cpu.edi);
    // 0048bd9c  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0048bda0  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0048bda4  8b4f04                 -mov ecx, dword ptr [edi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0048bda7  a3cc605200             -mov dword ptr [0x5260cc], eax
    app->getMemory<x86::reg32>(x86::reg32(5398732) /* 0x5260cc */) = cpu.eax;
    // 0048bdac  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0048bdaf  8b5f08                 -mov ebx, dword ptr [edi + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0048bdb2  e859030000             -call 0x48c110
    cpu.esp -= 4;
    sub_48c110(app, cpu);
    if (cpu.terminate) return;
    // 0048bdb7  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0048bdbb  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048bdbd  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 0048bdc0  8a8090a84c00           -mov al, byte ptr [eax + 0x4ca890]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5023888) /* 0x4ca890 */);
    // 0048bdc6  40                     -inc eax
    (cpu.eax)++;
    // 0048bdc7  24fe                   -and al, 0xfe
    cpu.al &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 0048bdc9  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 0048bdcc  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 0048bdd0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048bdd2  a0ec844c00             -mov al, byte ptr [0x4c84ec]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5014764) /* 0x4c84ec */);
    // 0048bdd7  896c242c               -mov dword ptr [esp + 0x2c], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.ebp;
    // 0048bddb  40                     -inc eax
    (cpu.eax)++;
    // 0048bddc  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0048bddf  24fe                   -and al, 0xfe
    cpu.al &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 0048bde1  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0048bde4  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 0048bde7  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048bdea  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0048bdee  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0048bdf2  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048bdf5  e8b6a70000             -call 0x4965b0
    cpu.esp -= 4;
    sub_4965b0(app, cpu);
    if (cpu.terminate) return;
    // 0048bdfa  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0048bdfe  81f900000100           +cmp ecx, 0x10000
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
    // 0048be04  753f                   -jne 0x48be45
    if (!cpu.flags.zf)
    {
        goto L_0x0048be45;
    }
    // 0048be06  39cb                   +cmp ebx, ecx
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
    // 0048be08  753b                   -jne 0x48be45
    if (!cpu.flags.zf)
    {
        goto L_0x0048be45;
    }
    // 0048be0a  833d14824c0000         +cmp dword ptr [0x4c8214], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5014036) /* 0x4c8214 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048be11  0f8494010000           -je 0x48bfab
    if (cpu.flags.zf)
    {
        goto L_0x0048bfab;
    }
    // 0048be17  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0048be1b  83fb01                 +cmp ebx, 1
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
    // 0048be1e  750e                   -jne 0x48be2e
    if (!cpu.flags.zf)
    {
        goto L_0x0048be2e;
    }
    // 0048be20  3b5c2420               +cmp ebx, dword ptr [esp + 0x20]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048be24  7508                   -jne 0x48be2e
    if (!cpu.flags.zf)
    {
        goto L_0x0048be2e;
    }
    // 0048be26  c744242c14bd4800       -mov dword ptr [esp + 0x2c], 0x48bd14
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = 4766996 /*0x48bd14*/;
L_0x0048be2e:
    // 0048be2e  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0048be32  83fb02                 +cmp ebx, 2
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
    // 0048be35  750e                   -jne 0x48be45
    if (!cpu.flags.zf)
    {
        goto L_0x0048be45;
    }
    // 0048be37  3b5c2420               +cmp ebx, dword ptr [esp + 0x20]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048be3b  7508                   -jne 0x48be45
    if (!cpu.flags.zf)
    {
        goto L_0x0048be45;
    }
    // 0048be3d  c744242c3cbd4800       -mov dword ptr [esp + 0x2c], 0x48bd3c
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = 4767036 /*0x48bd3c*/;
L_0x0048be45:
    // 0048be45  837c242c00             +cmp dword ptr [esp + 0x2c], 0
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
    // 0048be4a  753f                   -jne 0x48be8b
    if (!cpu.flags.zf)
    {
        goto L_0x0048be8b;
    }
    // 0048be4c  b8e9c34800             -mov eax, 0x48c3e9
    cpu.eax = 4768745 /*0x48c3e9*/;
    // 0048be51  8b1510824c00           -mov edx, dword ptr [0x4c8210]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5014032) /* 0x4c8210 */);
    // 0048be57  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0048be5b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048be5d  7415                   -je 0x48be74
    if (cpu.flags.zf)
    {
        goto L_0x0048be74;
    }
    // 0048be5f  833d14824c0000         +cmp dword ptr [0x4c8214], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5014036) /* 0x4c8214 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048be66  0f847a010000           -je 0x48bfe6
    if (cpu.flags.zf)
    {
        goto L_0x0048bfe6;
    }
    // 0048be6c  c744242cc4c64800       -mov dword ptr [esp + 0x2c], 0x48c6c4
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = 4769476 /*0x48c6c4*/;
L_0x0048be74:
    // 0048be74  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0048be78  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048be79  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048be7b  b86c8a5200             -mov eax, 0x528a6c
    cpu.eax = 5409388 /*0x528a6c*/;
    // 0048be80  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048be82  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048be84  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048be86  e885b20000             -call 0x497110
    cpu.esp -= 4;
    sub_497110(app, cpu);
    if (cpu.terminate) return;
L_0x0048be8b:
    // 0048be8b  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0048be8d  0f8e00010000           -jle 0x48bf93
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048bf93;
    }
    // 0048be93  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048be95  c1e610                 -shl esi, 0x10
    cpu.esi <<= 16 /*0x10*/ % 32;
    // 0048be98  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0048be9c  89742414               -mov dword ptr [esp + 0x14], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.esi;
L_0x0048bea0:
    // 0048bea0  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0048bea3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048bea5  668b47fe               -mov ax, word ptr [edi - 2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(-2) /* -0x2 */);
    // 0048bea9  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048beab  89442434               -mov dword ptr [esp + 0x34], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 0048beaf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048beb1  0f8ec9000000           -jle 0x48bf80
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048bf80;
    }
    // 0048beb7  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0048bebb  89442430               -mov dword ptr [esp + 0x30], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.eax;
L_0x0048bebf:
    // 0048bebf  8b4c2428               -mov ecx, dword ptr [esp + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0048bec3  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0048bec5  8b4902                 -mov ecx, dword ptr [ecx + 2]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 0048bec8  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0048beca  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0048becd  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 0048bece  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0048bed0  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0048bed2  895604                 -mov dword ptr [esi + 4], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0048bed5  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0048bed8  a178a44c00             -mov eax, dword ptr [0x4ca478]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5022840) /* 0x4ca478 */);
    // 0048bedd  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048bedf  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048bee3  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0048bee7  a17ca44c00             -mov eax, dword ptr [0x4ca47c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5022844) /* 0x4ca47c */);
    // 0048beec  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0048beee  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0048bef2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048bef4  8b742430               -mov esi, dword ptr [esp + 0x30]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0048bef8  668b4704               -mov ax, word ptr [edi + 4]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0048befc  8b0dd4844c00           -mov ecx, dword ptr [0x4c84d4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5014740) /* 0x4c84d4 */);
    // 0048bf02  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0048bf04  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0048bf06  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 0048bf07  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0048bf09  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0048bf0b  895604                 -mov dword ptr [esi + 4], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0048bf0e  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048bf12  8b0d70a44c00           -mov ecx, dword ptr [0x4ca470]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5022832) /* 0x4ca470 */);
    // 0048bf18  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0048bf1a  0faf4c2420             -imul ecx, dword ptr [esp + 0x20]
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */))));
    // 0048bf1f  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0048bf22  8b1574a44c00           -mov edx, dword ptr [0x4ca474]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5022836) /* 0x4ca474 */);
    // 0048bf28  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048bf2a  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048bf2e  0faf74241c             -imul esi, dword ptr [esp + 0x1c]
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */))));
    // 0048bf33  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048bf37  0faf442424             -imul eax, dword ptr [esp + 0x24]
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */))));
    // 0048bf3c  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048bf3e  a1fc844c00             -mov eax, dword ptr [0x4c84fc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5014780) /* 0x4c84fc */);
    // 0048bf43  8b0490                 -mov eax, dword ptr [eax + edx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 0048bf46  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0048bf48  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048bf4a  668b4f06               -mov cx, word ptr [edi + 6]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(6) /* 0x6 */);
    // 0048bf4e  8b1548824c00           -mov edx, dword ptr [0x4c8248]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5014088) /* 0x4c8248 */);
    // 0048bf54  01cd                   -add ebp, ecx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0048bf56  89442438               -mov dword ptr [esp + 0x38], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 0048bf5a  39d5                   +cmp ebp, edx
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048bf5c  0f8f91000000           -jg 0x48bff3
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048bff3;
    }
L_0x0048bf62:
    // 0048bf62  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048bf63  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048bf64  8b4c2440               -mov ecx, dword ptr [esp + 0x40]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0048bf68  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048bf69  ff542438               -call dword ptr [esp + 0x38]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048bf6d  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0048bf70  43                     -inc ebx
    (cpu.ebx)++;
    // 0048bf71  8b742434               -mov esi, dword ptr [esp + 0x34]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0048bf75  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0048bf78  39f3                   +cmp ebx, esi
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
    // 0048bf7a  0f8c3fffffff           -jl 0x48bebf
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048bebf;
    }
L_0x0048bf80:
    // 0048bf80  66ff44241a             -inc word ptr [esp + 0x1a]
    (app->getMemory<x86::reg16>(cpu.esp + x86::reg32(26) /* 0x1a */))++;
    // 0048bf85  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0048bf89  3b742418               +cmp esi, dword ptr [esp + 0x18]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048bf8d  0f8f0dffffff           -jg 0x48bea0
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048bea0;
    }
L_0x0048bf93:
    // 0048bf93  833d14824c0000         +cmp dword ptr [0x4c8214], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5014036) /* 0x4c8214 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048bf9a  0f84e0fdffff           -je 0x48bd80
    if (cpu.flags.zf)
    {
        goto L_0x0048bd80;
    }
    // 0048bfa0  0f77                   -emms 
    cpu.mmx.init();
    // 0048bfa2  83c43c                 -add esp, 0x3c
    (cpu.esp) += x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 0048bfa5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bfa6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bfa7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bfa8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bfa9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bfaa  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048bfab:
    // 0048bfab  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0048bfaf  83fb01                 +cmp ebx, 1
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
    // 0048bfb2  750e                   -jne 0x48bfc2
    if (!cpu.flags.zf)
    {
        goto L_0x0048bfc2;
    }
    // 0048bfb4  3b5c2420               +cmp ebx, dword ptr [esp + 0x20]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048bfb8  7508                   -jne 0x48bfc2
    if (!cpu.flags.zf)
    {
        goto L_0x0048bfc2;
    }
    // 0048bfba  c744242cc0bc4800       -mov dword ptr [esp + 0x2c], 0x48bcc0
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = 4766912 /*0x48bcc0*/;
L_0x0048bfc2:
    // 0048bfc2  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0048bfc6  83fb02                 +cmp ebx, 2
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
    // 0048bfc9  0f8576feffff           -jne 0x48be45
    if (!cpu.flags.zf)
    {
        goto L_0x0048be45;
    }
    // 0048bfcf  3b5c2420               +cmp ebx, dword ptr [esp + 0x20]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048bfd3  0f856cfeffff           -jne 0x48be45
    if (!cpu.flags.zf)
    {
        goto L_0x0048be45;
    }
    // 0048bfd9  c744242ce8bc4800       -mov dword ptr [esp + 0x2c], 0x48bce8
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = 4766952 /*0x48bce8*/;
    // 0048bfe1  e95ffeffff             -jmp 0x48be45
    goto L_0x0048be45;
L_0x0048bfe6:
    // 0048bfe6  c744242c9ec94800       -mov dword ptr [esp + 0x2c], 0x48c99e
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = 4770206 /*0x48c99e*/;
    // 0048bfee  e981feffff             -jmp 0x48be74
    goto L_0x0048be74;
L_0x0048bff3:
    // 0048bff3  e8a0c1feff             -call 0x478198
    cpu.esp -= 4;
    sub_478198(app, cpu);
    if (cpu.terminate) return;
    // 0048bff8  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0048bffa  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048bffc  0f847efdffff           -je 0x48bd80
    if (cpu.flags.zf)
    {
        goto L_0x0048bd80;
    }
    // 0048c002  e95bffffff             -jmp 0x48bf62
    goto L_0x0048bf62;
}

/* align: skip  */
void Application::sub_48c007(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048c007  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048c008  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048c009  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048c00a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048c00b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048c00c  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048c00f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048c011  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0048c013  803a00                 +cmp byte ptr [edx], 0
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
    // 0048c016  7507                   -jne 0x48c01f
    if (!cpu.flags.zf)
    {
        goto L_0x0048c01f;
    }
L_0x0048c018:
    // 0048c018  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048c01a  e99d000000             -jmp 0x48c0bc
    goto L_0x0048c0bc;
L_0x0048c01f:
    // 0048c01f  807a0100               +cmp byte ptr [edx + 1], 0
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
    // 0048c023  751c                   -jne 0x48c041
    if (!cpu.flags.zf)
    {
        goto L_0x0048c041;
    }
    // 0048c025  8a13                   -mov dl, byte ptr [ebx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx);
L_0x0048c027:
    // 0048c027  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0048c029  3ac2                   +cmp al, dl
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
    // 0048c02b  7412                   -je 0x48c03f
    if (cpu.flags.zf)
    {
        goto L_0x0048c03f;
    }
    // 0048c02d  3c00                   +cmp al, 0
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
    // 0048c02f  740c                   -je 0x48c03d
    if (cpu.flags.zf)
    {
        goto L_0x0048c03d;
    }
    // 0048c031  46                     -inc esi
    (cpu.esi)++;
    // 0048c032  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0048c034  3ac2                   +cmp al, dl
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
    // 0048c036  7407                   -je 0x48c03f
    if (cpu.flags.zf)
    {
        goto L_0x0048c03f;
    }
    // 0048c038  46                     -inc esi
    (cpu.esi)++;
    // 0048c039  3c00                   +cmp al, 0
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
    // 0048c03b  75ea                   -jne 0x48c027
    if (!cpu.flags.zf)
    {
        goto L_0x0048c027;
    }
L_0x0048c03d:
    // 0048c03d  2bf6                   +sub esi, esi
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
L_0x0048c03f:
    // 0048c03f  ebd7                   -jmp 0x48c018
    goto L_0x0048c018;
L_0x0048c041:
    // 0048c041  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 0048c046  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 0048c048  30c0                   +xor al, al
    cpu.clear_co();
    cpu.set_szp((cpu.al ^= x86::reg8(x86::sreg8(cpu.al))));
    // 0048c04a  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0048c04b  e30b                   -jecxz 0x48c058
    if (cpu.ecx == 0)
    {
        goto L_0x0048c058;
    }
    // 0048c04d  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 0048c04f  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
    // 0048c051  f2ae                   +repne scasb al, byte ptr es:[edi]
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
    // 0048c053  7503                   -jne 0x48c058
    if (!cpu.flags.zf)
    {
        goto L_0x0048c058;
    }
    // 0048c055  4f                     -dec edi
    (cpu.edi)--;
    // 0048c056  66a989cf               +test ax, 0xcf89
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & 53129 /*0xcf89*/));
    // FakeJmpInstruction
    goto L_0x0048c05a;
L_0x0048c058:
    // 0048c058  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
L_0x0048c05a:
    // 0048c05a  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0048c05b  893c24                 -mov dword ptr [esp], edi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edi;
    // 0048c05e  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0048c060  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0048c061  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0048c063  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 0048c065  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048c067  49                     -dec ecx
    (cpu.ecx)--;
    // 0048c068  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0048c06a  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0048c06c  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0048c06e  49                     -dec ecx
    (cpu.ecx)--;
    // 0048c06f  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0048c070  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
L_0x0048c072:
    // 0048c072  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 0048c075  29f1                   -sub ecx, esi
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0048c077  39e9                   +cmp ecx, ebp
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
    // 0048c079  723f                   -jb 0x48c0ba
    if (cpu.flags.cf)
    {
        goto L_0x0048c0ba;
    }
    // 0048c07b  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 0048c07d  8a03                   -mov al, byte ptr [ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx);
    // 0048c07f  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0048c080  e30b                   -jecxz 0x48c08d
    if (cpu.ecx == 0)
    {
        goto L_0x0048c08d;
    }
    // 0048c082  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 0048c084  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
    // 0048c086  f2ae                   +repne scasb al, byte ptr es:[edi]
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
    // 0048c088  7503                   -jne 0x48c08d
    if (!cpu.flags.zf)
    {
        goto L_0x0048c08d;
    }
    // 0048c08a  4f                     -dec edi
    (cpu.edi)--;
    // 0048c08b  66a989cf               +test ax, 0xcf89
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & 53129 /*0xcf89*/));
    // FakeJmpInstruction
    goto L_0x0048c08f;
L_0x0048c08d:
    // 0048c08d  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
L_0x0048c08f:
    // 0048c08f  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0048c090  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0048c092  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0048c094  7424                   -je 0x48c0ba
    if (cpu.flags.zf)
    {
        goto L_0x0048c0ba;
    }
    // 0048c096  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0048c098  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0048c09a  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0048c09c  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0048c09d  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0048c09f  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 0048c0a1  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0048c0a3  f3a6                   +repe cmpsb byte ptr [esi], byte ptr es:[edi]
    while (cpu.ecx)
    {
        {
            x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi);
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
    // 0048c0a5  7405                   -je 0x48c0ac
    if (cpu.flags.zf)
    {
        goto L_0x0048c0ac;
    }
    // 0048c0a7  19c0                   +sbb eax, eax
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
    // 0048c0a9  83d8ff                 -sbb eax, -1
    (cpu.eax) -= x86::reg32(x86::sreg32(-1 /*-0x1*/) + cpu.flags.cf);
L_0x0048c0ac:
    // 0048c0ac  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0048c0ad  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048c0af  7504                   -jne 0x48c0b5
    if (!cpu.flags.zf)
    {
        goto L_0x0048c0b5;
    }
    // 0048c0b1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048c0b3  eb07                   -jmp 0x48c0bc
    goto L_0x0048c0bc;
L_0x0048c0b5:
    // 0048c0b5  8d7201                 -lea esi, [edx + 1]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0048c0b8  ebb8                   -jmp 0x48c072
    goto L_0x0048c072;
L_0x0048c0ba:
    // 0048c0ba  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0048c0bc:
    // 0048c0bc  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048c0bf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c0c0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c0c1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c0c2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c0c3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c0c4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_48c0c8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048c0c8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048c0c9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048c0ca  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048c0cb  bf80a44c00             -mov edi, 0x4ca480
    cpu.edi = 5022848 /*0x4ca480*/;
    // 0048c0d0  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048c0d2  b940000000             -mov ecx, 0x40
    cpu.ecx = 64 /*0x40*/;
    // 0048c0d7  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048c0d9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c0da  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c0db  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c0dc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48c0dd(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048c0dd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048c0de  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048c0df  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048c0e0  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0048c0e2  be80a44c00             -mov esi, 0x4ca480
    cpu.esi = 5022848 /*0x4ca480*/;
    // 0048c0e7  b940000000             -mov ecx, 0x40
    cpu.ecx = 64 /*0x40*/;
    // 0048c0ec  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048c0ee  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c0ef  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c0f0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c0f1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48c0f2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048c0f2  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048c0f3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048c0f4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048c0f5  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0048c0f7  bf80a44c00             -mov edi, 0x4ca480
    cpu.edi = 5022848 /*0x4ca480*/;
    // 0048c0fc  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048c0fe  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048c100  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0048c103  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048c105  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048c107  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0048c10a  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0048c10c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c10d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c10e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c10f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48c110(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048c110  a388a64c00             -mov dword ptr [0x4ca688], eax
    app->getMemory<x86::reg32>(x86::reg32(5023368) /* 0x4ca688 */) = cpu.eax;
    // 0048c115  891584a64c00           -mov dword ptr [0x4ca684], edx
    app->getMemory<x86::reg32>(x86::reg32(5023364) /* 0x4ca684 */) = cpu.edx;
    // 0048c11b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48c11c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048c11c  a380a64c00             -mov dword ptr [0x4ca680], eax
    app->getMemory<x86::reg32>(x86::reg32(5023360) /* 0x4ca680 */) = cpu.eax;
    // 0048c121  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48c122(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048c122  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048c123  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048c124  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048c125  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0048c129  8b7c2410               -mov edi, dword ptr [esp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0048c12d  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0048c131  033588a64c00           -add esi, dword ptr [0x4ca688]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023368) /* 0x4ca688 */)));
    // 0048c137  033df0844c00           -add edi, dword ptr [0x4c84f0]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014768) /* 0x4c84f0 */)));
    // 0048c13d  8b1584a64c00           -mov edx, dword ptr [0x4ca684]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023364) /* 0x4ca684 */);
    // 0048c143  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048c145  803dec844c0008         +cmp byte ptr [0x4c84ec], 8
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5014764) /* 0x4c84ec */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(8 /*0x8*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048c14c  7f61                   -jg 0x48c1af
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048c1af;
    }
    // 0048c14e  83e904                 +sub ecx, 4
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048c151  783d                   -js 0x48c190
    if (cpu.flags.sf)
    {
        goto L_0x0048c190;
    }
L_0x0048c153:
    // 0048c153  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 0048c155  8a041e                 -mov al, byte ptr [esi + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.ebx * 1);
    // 0048c158  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0048c15b  3cff                   +cmp al, 0xff
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048c15d  7402                   -je 0x48c161
    if (cpu.flags.zf)
    {
        goto L_0x0048c161;
    }
    // 0048c15f  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
L_0x0048c161:
    // 0048c161  8a041e                 -mov al, byte ptr [esi + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.ebx * 1);
    // 0048c164  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0048c167  3cff                   +cmp al, 0xff
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048c169  7403                   -je 0x48c16e
    if (cpu.flags.zf)
    {
        goto L_0x0048c16e;
    }
    // 0048c16b  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
L_0x0048c16e:
    // 0048c16e  8a041e                 -mov al, byte ptr [esi + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.ebx * 1);
    // 0048c171  8b5a0c                 -mov ebx, dword ptr [edx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0048c174  3cff                   +cmp al, 0xff
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048c176  7403                   -je 0x48c17b
    if (cpu.flags.zf)
    {
        goto L_0x0048c17b;
    }
    // 0048c178  884702                 -mov byte ptr [edi + 2], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */) = cpu.al;
L_0x0048c17b:
    // 0048c17b  8a041e                 -mov al, byte ptr [esi + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.ebx * 1);
    // 0048c17e  3cff                   +cmp al, 0xff
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048c180  7403                   -je 0x48c185
    if (cpu.flags.zf)
    {
        goto L_0x0048c185;
    }
    // 0048c182  884703                 -mov byte ptr [edi + 3], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(3) /* 0x3 */) = cpu.al;
L_0x0048c185:
    // 0048c185  83e904                 +sub ecx, 4
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048c188  8d5210                 -lea edx, [edx + 0x10]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0048c18b  8d7f04                 -lea edi, [edi + 4]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0048c18e  79c3                   -jns 0x48c153
    if (!cpu.flags.sf)
    {
        goto L_0x0048c153;
    }
L_0x0048c190:
    // 0048c190  83c103                 +add ecx, 3
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048c193  7816                   -js 0x48c1ab
    if (cpu.flags.sf)
    {
        goto L_0x0048c1ab;
    }
L_0x0048c195:
    // 0048c195  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 0048c197  8a041e                 -mov al, byte ptr [esi + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.ebx * 1);
    // 0048c19a  3cff                   +cmp al, 0xff
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048c19c  7402                   -je 0x48c1a0
    if (cpu.flags.zf)
    {
        goto L_0x0048c1a0;
    }
    // 0048c19e  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
L_0x0048c1a0:
    // 0048c1a0  83e901                 +sub ecx, 1
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
    // 0048c1a3  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0048c1a6  8d7f01                 -lea edi, [edi + 1]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 0048c1a9  79ea                   -jns 0x48c195
    if (!cpu.flags.sf)
    {
        goto L_0x0048c195;
    }
L_0x0048c1ab:
    // 0048c1ab  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c1ac  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c1ad  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c1ae  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048c1af:
    // 0048c1af  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 0048c1b1  803dec844c0010         +cmp byte ptr [0x4c84ec], 0x10
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5014764) /* 0x4c84ec */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048c1b8  7f21                   -jg 0x48c1db
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048c1db;
    }
    // 0048c1ba  83e901                 +sub ecx, 1
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
    // 0048c1bd  78ec                   -js 0x48c1ab
    if (cpu.flags.sf)
    {
        goto L_0x0048c1ab;
    }
L_0x0048c1bf:
    // 0048c1bf  668b045e               -mov ax, word ptr [esi + ebx*2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + cpu.ebx * 2);
    // 0048c1c3  6609c0                 +or ax, ax
    cpu.clear_co();
    cpu.set_szp((cpu.ax |= x86::reg16(x86::sreg16(cpu.ax))));
    // 0048c1c6  7403                   -je 0x48c1cb
    if (cpu.flags.zf)
    {
        goto L_0x0048c1cb;
    }
    // 0048c1c8  668907                 -mov word ptr [edi], ax
    app->getMemory<x86::reg16>(cpu.edi) = cpu.ax;
L_0x0048c1cb:
    // 0048c1cb  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0048c1ce  83e901                 +sub ecx, 1
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
    // 0048c1d1  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0048c1d4  8d7f02                 -lea edi, [edi + 2]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 0048c1d7  79e6                   -jns 0x48c1bf
    if (!cpu.flags.sf)
    {
        goto L_0x0048c1bf;
    }
    // 0048c1d9  ebd0                   -jmp 0x48c1ab
    goto L_0x0048c1ab;
L_0x0048c1db:
    // 0048c1db  83e901                 +sub ecx, 1
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
    // 0048c1de  78cb                   -js 0x48c1ab
    if (cpu.flags.sf)
    {
        goto L_0x0048c1ab;
    }
L_0x0048c1e0:
    // 0048c1e0  8b049e                 -mov eax, dword ptr [esi + ebx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + cpu.ebx * 4);
    // 0048c1e3  09c0                   +or eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(cpu.eax))));
    // 0048c1e5  7402                   -je 0x48c1e9
    if (cpu.flags.zf)
    {
        goto L_0x0048c1e9;
    }
    // 0048c1e7  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
L_0x0048c1e9:
    // 0048c1e9  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0048c1ec  83e901                 +sub ecx, 1
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
    // 0048c1ef  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0048c1f2  8d7f04                 -lea edi, [edi + 4]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0048c1f5  79e9                   -jns 0x48c1e0
    if (!cpu.flags.sf)
    {
        goto L_0x0048c1e0;
    }
    // 0048c1f7  ebb2                   -jmp 0x48c1ab
    goto L_0x0048c1ab;
}

/* align: skip  */
void Application::sub_48c1f9(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048c1f9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048c1fa  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048c1fb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048c1fc  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0048c200  8b7c2410               -mov edi, dword ptr [esp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0048c204  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0048c208  033588a64c00           -add esi, dword ptr [0x4ca688]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023368) /* 0x4ca688 */)));
    // 0048c20e  033df0844c00           -add edi, dword ptr [0x4c84f0]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014768) /* 0x4c84f0 */)));
    // 0048c214  8b1584a64c00           -mov edx, dword ptr [0x4ca684]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023364) /* 0x4ca684 */);
    // 0048c21a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048c21c  83e904                 +sub ecx, 4
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048c21f  7855                   -js 0x48c276
    if (cpu.flags.sf)
    {
        goto L_0x0048c276;
    }
L_0x0048c221:
    // 0048c221  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 0048c223  8a041e                 -mov al, byte ptr [esi + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.ebx * 1);
    // 0048c226  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0048c229  8a8080a44c00           -mov al, byte ptr [eax + 0x4ca480]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5022848) /* 0x4ca480 */);
    // 0048c22f  3cff                   +cmp al, 0xff
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048c231  7402                   -je 0x48c235
    if (cpu.flags.zf)
    {
        goto L_0x0048c235;
    }
    // 0048c233  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
L_0x0048c235:
    // 0048c235  8a041e                 -mov al, byte ptr [esi + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.ebx * 1);
    // 0048c238  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0048c23b  8a8080a44c00           -mov al, byte ptr [eax + 0x4ca480]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5022848) /* 0x4ca480 */);
    // 0048c241  3cff                   +cmp al, 0xff
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048c243  7403                   -je 0x48c248
    if (cpu.flags.zf)
    {
        goto L_0x0048c248;
    }
    // 0048c245  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
L_0x0048c248:
    // 0048c248  8a041e                 -mov al, byte ptr [esi + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.ebx * 1);
    // 0048c24b  8b5a0c                 -mov ebx, dword ptr [edx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0048c24e  8a8080a44c00           -mov al, byte ptr [eax + 0x4ca480]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5022848) /* 0x4ca480 */);
    // 0048c254  3cff                   +cmp al, 0xff
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048c256  7403                   -je 0x48c25b
    if (cpu.flags.zf)
    {
        goto L_0x0048c25b;
    }
    // 0048c258  884702                 -mov byte ptr [edi + 2], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */) = cpu.al;
L_0x0048c25b:
    // 0048c25b  8a041e                 -mov al, byte ptr [esi + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.ebx * 1);
    // 0048c25e  8a8080a44c00           -mov al, byte ptr [eax + 0x4ca480]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5022848) /* 0x4ca480 */);
    // 0048c264  3cff                   +cmp al, 0xff
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048c266  7403                   -je 0x48c26b
    if (cpu.flags.zf)
    {
        goto L_0x0048c26b;
    }
    // 0048c268  884703                 -mov byte ptr [edi + 3], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(3) /* 0x3 */) = cpu.al;
L_0x0048c26b:
    // 0048c26b  83e904                 +sub ecx, 4
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048c26e  8d5210                 -lea edx, [edx + 0x10]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0048c271  8d7f04                 -lea edi, [edi + 4]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0048c274  79ab                   -jns 0x48c221
    if (!cpu.flags.sf)
    {
        goto L_0x0048c221;
    }
L_0x0048c276:
    // 0048c276  83c103                 +add ecx, 3
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048c279  781c                   -js 0x48c297
    if (cpu.flags.sf)
    {
        goto L_0x0048c297;
    }
L_0x0048c27b:
    // 0048c27b  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 0048c27d  8a041e                 -mov al, byte ptr [esi + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.ebx * 1);
    // 0048c280  8a8080a44c00           -mov al, byte ptr [eax + 0x4ca480]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5022848) /* 0x4ca480 */);
    // 0048c286  3cff                   +cmp al, 0xff
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048c288  7402                   -je 0x48c28c
    if (cpu.flags.zf)
    {
        goto L_0x0048c28c;
    }
    // 0048c28a  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
L_0x0048c28c:
    // 0048c28c  83e901                 +sub ecx, 1
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
    // 0048c28f  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0048c292  8d7f01                 -lea edi, [edi + 1]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 0048c295  79e4                   -jns 0x48c27b
    if (!cpu.flags.sf)
    {
        goto L_0x0048c27b;
    }
L_0x0048c297:
    // 0048c297  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c298  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c299  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c29a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48c29b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048c29b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048c29c  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0048c29e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048c29f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048c2a0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048c2a1  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0048c2a4  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0048c2a7  8b4d10                 -mov ecx, dword ptr [ebp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0048c2aa  033588a64c00           -add esi, dword ptr [0x4ca688]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023368) /* 0x4ca688 */)));
    // 0048c2b0  033df0844c00           -add edi, dword ptr [0x4c84f0]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014768) /* 0x4c84f0 */)));
    // 0048c2b6  8b1584a64c00           -mov edx, dword ptr [0x4ca684]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023364) /* 0x4ca684 */);
    // 0048c2bc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0048c2be:
    // 0048c2be  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 0048c2c0  8a041e                 -mov al, byte ptr [esi + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.ebx * 1);
    // 0048c2c3  8a8080a44c00           -mov al, byte ptr [eax + 0x4ca480]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5022848) /* 0x4ca480 */);
    // 0048c2c9  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048c2cc  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0048c2ce  83e901                 +sub ecx, 1
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
    // 0048c2d1  8d7f01                 -lea edi, [edi + 1]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 0048c2d4  75e8                   -jne 0x48c2be
    if (!cpu.flags.zf)
    {
        goto L_0x0048c2be;
    }
    // 0048c2d6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c2d7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c2d8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c2d9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c2da  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48c2db(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048c2db  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048c2dc  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0048c2de  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048c2df  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048c2e0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048c2e1  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0048c2e4  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0048c2e7  8b4d10                 -mov ecx, dword ptr [ebp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0048c2ea  033588a64c00           -add esi, dword ptr [0x4ca688]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023368) /* 0x4ca688 */)));
    // 0048c2f0  033df0844c00           -add edi, dword ptr [0x4c84f0]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014768) /* 0x4c84f0 */)));
    // 0048c2f6  8b1584a64c00           -mov edx, dword ptr [0x4ca684]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023364) /* 0x4ca684 */);
    // 0048c2fc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0048c2fe:
    // 0048c2fe  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 0048c300  8a041e                 -mov al, byte ptr [esi + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.ebx * 1);
    // 0048c303  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048c306  3cfe                   +cmp al, 0xfe
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(254 /*0xfe*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048c308  720a                   -jb 0x48c314
    if (cpu.flags.cf)
    {
        goto L_0x0048c314;
    }
    // 0048c30a  750a                   -jne 0x48c316
    if (!cpu.flags.zf)
    {
        goto L_0x0048c316;
    }
    // 0048c30c  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 0048c30e  8a8080a54c00           -mov al, byte ptr [eax + 0x4ca580]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5023104) /* 0x4ca580 */);
L_0x0048c314:
    // 0048c314  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
L_0x0048c316:
    // 0048c316  83e901                 +sub ecx, 1
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
    // 0048c319  8d7f01                 -lea edi, [edi + 1]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 0048c31c  75e0                   -jne 0x48c2fe
    if (!cpu.flags.zf)
    {
        goto L_0x0048c2fe;
    }
    // 0048c31e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c31f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c320  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c321  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c322  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48c323(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048c323  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048c324  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0048c326  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048c327  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048c328  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048c329  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0048c32c  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0048c32f  8b4d10                 -mov ecx, dword ptr [ebp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0048c332  033588a64c00           -add esi, dword ptr [0x4ca688]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023368) /* 0x4ca688 */)));
    // 0048c338  033df0844c00           -add edi, dword ptr [0x4c84f0]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014768) /* 0x4c84f0 */)));
    // 0048c33e  8b1584a64c00           -mov edx, dword ptr [0x4ca684]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023364) /* 0x4ca684 */);
    // 0048c344  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0048c346:
    // 0048c346  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 0048c348  8a041e                 -mov al, byte ptr [esi + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.ebx * 1);
    // 0048c34b  8a8080a44c00           -mov al, byte ptr [eax + 0x4ca480]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5022848) /* 0x4ca480 */);
    // 0048c351  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048c354  3cfe                   +cmp al, 0xfe
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(254 /*0xfe*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048c356  720a                   -jb 0x48c362
    if (cpu.flags.cf)
    {
        goto L_0x0048c362;
    }
    // 0048c358  750a                   -jne 0x48c364
    if (!cpu.flags.zf)
    {
        goto L_0x0048c364;
    }
    // 0048c35a  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 0048c35c  8a8080a54c00           -mov al, byte ptr [eax + 0x4ca580]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5023104) /* 0x4ca580 */);
L_0x0048c362:
    // 0048c362  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
L_0x0048c364:
    // 0048c364  83e901                 +sub ecx, 1
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
    // 0048c367  8d7f01                 -lea edi, [edi + 1]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 0048c36a  75da                   -jne 0x48c346
    if (!cpu.flags.zf)
    {
        goto L_0x0048c346;
    }
    // 0048c36c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c36d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c36e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c36f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c370  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48c371(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048c371  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048c372  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048c373  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048c374  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048c375  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0048c379  8b6c2414               -mov ebp, dword ptr [esp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0048c37d  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0048c381  033588a64c00           -add esi, dword ptr [0x4ca688]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023368) /* 0x4ca688 */)));
    // 0048c387  032df0844c00           -add ebp, dword ptr [0x4c84f0]
    (cpu.ebp) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014768) /* 0x4c84f0 */)));
    // 0048c38d  8b1584a64c00           -mov edx, dword ptr [0x4ca684]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023364) /* 0x4ca684 */);
    // 0048c393  8b3d80a64c00           -mov edi, dword ptr [0x4ca680]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5023360) /* 0x4ca680 */);
    // 0048c399  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048c39b  83e902                 +sub ecx, 2
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
    // 0048c39e  782e                   -js 0x48c3ce
    if (cpu.flags.sf)
    {
        goto L_0x0048c3ce;
    }
L_0x0048c3a0:
    // 0048c3a0  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 0048c3a2  8a041e                 -mov al, byte ptr [esi + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.ebx * 1);
    // 0048c3a5  8b1c87                 -mov ebx, dword ptr [edi + eax*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.eax * 4);
    // 0048c3a8  8a4500                 -mov al, byte ptr [ebp]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp);
    // 0048c3ab  8a0403                 -mov al, byte ptr [ebx + eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.eax * 1);
    // 0048c3ae  884500                 -mov byte ptr [ebp], al
    app->getMemory<x86::reg8>(cpu.ebp) = cpu.al;
    // 0048c3b1  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0048c3b4  8a041e                 -mov al, byte ptr [esi + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.ebx * 1);
    // 0048c3b7  8b1c87                 -mov ebx, dword ptr [edi + eax*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.eax * 4);
    // 0048c3ba  8a4501                 -mov al, byte ptr [ebp + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(1) /* 0x1 */);
    // 0048c3bd  8a0418                 -mov al, byte ptr [eax + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + cpu.ebx * 1);
    // 0048c3c0  884501                 -mov byte ptr [ebp + 1], al
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0048c3c3  83e902                 +sub ecx, 2
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
    // 0048c3c6  8d5208                 -lea edx, [edx + 8]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0048c3c9  8d6d02                 -lea ebp, [ebp + 2]
    cpu.ebp = x86::reg32(cpu.ebp + x86::reg32(2) /* 0x2 */);
    // 0048c3cc  79d2                   -jns 0x48c3a0
    if (!cpu.flags.sf)
    {
        goto L_0x0048c3a0;
    }
L_0x0048c3ce:
    // 0048c3ce  83c101                 +add ecx, 1
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048c3d1  7811                   -js 0x48c3e4
    if (cpu.flags.sf)
    {
        goto L_0x0048c3e4;
    }
    // 0048c3d3  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 0048c3d5  8a041e                 -mov al, byte ptr [esi + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.ebx * 1);
    // 0048c3d8  8b1c87                 -mov ebx, dword ptr [edi + eax*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.eax * 4);
    // 0048c3db  8a4500                 -mov al, byte ptr [ebp]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp);
    // 0048c3de  8a0418                 -mov al, byte ptr [eax + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + cpu.ebx * 1);
    // 0048c3e1  884500                 -mov byte ptr [ebp], al
    app->getMemory<x86::reg8>(cpu.ebp) = cpu.al;
L_0x0048c3e4:
    // 0048c3e4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c3e5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c3e6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c3e7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c3e8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48c3e9(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048c3e9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048c3ea  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048c3eb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048c3ec  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048c3ed  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0048c3f1  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0048c3f5  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0048c3f9  8b1584a64c00           -mov edx, dword ptr [0x4ca684]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023364) /* 0x4ca684 */);
    // 0048c3ff  033588a64c00           -add esi, dword ptr [0x4ca688]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023368) /* 0x4ca688 */)));
    // 0048c405  033df0844c00           -add edi, dword ptr [0x4c84f0]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014768) /* 0x4c84f0 */)));
    // 0048c40b  8b5a0c                 -mov ebx, dword ptr [edx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0048c40e  803dec844c0008         +cmp byte ptr [0x4c84ec], 8
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5014764) /* 0x4c84ec */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(8 /*0x8*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048c415  0f8f26010000           -jg 0x48c541
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048c541;
    }
    // 0048c41b  83e910                 +sub ecx, 0x10
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048c41e  0f8c99000000           -jl 0x48c4bd
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048c4bd;
    }
    // 0048c424  f7c703000000           +test edi, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & 3 /*0x3*/));
    // 0048c42a  0f85e2000000           -jne 0x48c512
    if (!cpu.flags.zf)
    {
        goto L_0x0048c512;
    }
L_0x0048c430:
    // 0048c430  8b6a08                 -mov ebp, dword ptr [edx + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0048c433  8a2433                 -mov ah, byte ptr [ebx + esi]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 0048c436  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0048c439  8a443500               -mov al, byte ptr [ebp + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.esi * 1);
    // 0048c43d  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0048c440  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx);
    // 0048c442  8a2433                 -mov ah, byte ptr [ebx + esi]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 0048c445  8b5a1c                 -mov ebx, dword ptr [edx + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 0048c448  8a443500               -mov al, byte ptr [ebp + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.esi * 1);
    // 0048c44c  8b6a18                 -mov ebp, dword ptr [edx + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 0048c44f  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 0048c451  8a2433                 -mov ah, byte ptr [ebx + esi]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 0048c454  8b5a14                 -mov ebx, dword ptr [edx + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 0048c457  8a443500               -mov al, byte ptr [ebp + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.esi * 1);
    // 0048c45b  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0048c45e  8b6a10                 -mov ebp, dword ptr [edx + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0048c461  8a2433                 -mov ah, byte ptr [ebx + esi]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 0048c464  8b5a2c                 -mov ebx, dword ptr [edx + 0x2c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(44) /* 0x2c */);
    // 0048c467  8a443500               -mov al, byte ptr [ebp + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.esi * 1);
    // 0048c46b  8b6a28                 -mov ebp, dword ptr [edx + 0x28]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(40) /* 0x28 */);
    // 0048c46e  894704                 -mov dword ptr [edi + 4], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0048c471  8a2433                 -mov ah, byte ptr [ebx + esi]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 0048c474  8b5a24                 -mov ebx, dword ptr [edx + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */);
    // 0048c477  8a443500               -mov al, byte ptr [ebp + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.esi * 1);
    // 0048c47b  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0048c47e  8b6a20                 -mov ebp, dword ptr [edx + 0x20]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 0048c481  8a2433                 -mov ah, byte ptr [ebx + esi]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 0048c484  8b5a3c                 -mov ebx, dword ptr [edx + 0x3c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(60) /* 0x3c */);
    // 0048c487  8a443500               -mov al, byte ptr [ebp + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.esi * 1);
    // 0048c48b  8b6a38                 -mov ebp, dword ptr [edx + 0x38]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(56) /* 0x38 */);
    // 0048c48e  894708                 -mov dword ptr [edi + 8], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0048c491  8a2433                 -mov ah, byte ptr [ebx + esi]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 0048c494  8b5a34                 -mov ebx, dword ptr [edx + 0x34]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(52) /* 0x34 */);
    // 0048c497  8a443500               -mov al, byte ptr [ebp + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.esi * 1);
    // 0048c49b  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0048c49e  8b6a30                 -mov ebp, dword ptr [edx + 0x30]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(48) /* 0x30 */);
    // 0048c4a1  8a2433                 -mov ah, byte ptr [ebx + esi]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 0048c4a4  8b5a4c                 -mov ebx, dword ptr [edx + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(76) /* 0x4c */);
    // 0048c4a7  8a443500               -mov al, byte ptr [ebp + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.esi * 1);
    // 0048c4ab  8d5240                 -lea edx, [edx + 0x40]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(64) /* 0x40 */);
    // 0048c4ae  89470c                 -mov dword ptr [edi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0048c4b1  83e910                 +sub ecx, 0x10
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048c4b4  8d7f10                 -lea edi, [edi + 0x10]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 0048c4b7  0f8973ffffff           -jns 0x48c430
    if (!cpu.flags.sf)
    {
        goto L_0x0048c430;
    }
L_0x0048c4bd:
    // 0048c4bd  83c10c                 +add ecx, 0xc
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048c4c0  7831                   -js 0x48c4f3
    if (cpu.flags.sf)
    {
        goto L_0x0048c4f3;
    }
    // 0048c4c2  f7c703000000           +test edi, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & 3 /*0x3*/));
    // 0048c4c8  7529                   -jne 0x48c4f3
    if (!cpu.flags.zf)
    {
        goto L_0x0048c4f3;
    }
L_0x0048c4ca:
    // 0048c4ca  8b6a08                 -mov ebp, dword ptr [edx + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0048c4cd  8a2433                 -mov ah, byte ptr [ebx + esi]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 0048c4d0  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0048c4d3  8a443500               -mov al, byte ptr [ebp + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.esi * 1);
    // 0048c4d7  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0048c4da  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx);
    // 0048c4dc  8a2433                 -mov ah, byte ptr [ebx + esi]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 0048c4df  8b5a1c                 -mov ebx, dword ptr [edx + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 0048c4e2  8a443500               -mov al, byte ptr [ebp + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.esi * 1);
    // 0048c4e6  8d5210                 -lea edx, [edx + 0x10]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0048c4e9  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 0048c4eb  83e904                 +sub ecx, 4
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048c4ee  8d7f04                 -lea edi, [edi + 4]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0048c4f1  79d7                   -jns 0x48c4ca
    if (!cpu.flags.sf)
    {
        goto L_0x0048c4ca;
    }
L_0x0048c4f3:
    // 0048c4f3  83c103                 +add ecx, 3
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048c4f6  7815                   -js 0x48c50d
    if (cpu.flags.sf)
    {
        goto L_0x0048c50d;
    }
    // 0048c4f8  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
L_0x0048c4fa:
    // 0048c4fa  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 0048c4fd  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0048c500  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0048c502  83e901                 +sub ecx, 1
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
    // 0048c505  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0048c508  8d7f01                 -lea edi, [edi + 1]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 0048c50b  79ed                   -jns 0x48c4fa
    if (!cpu.flags.sf)
    {
        goto L_0x0048c4fa;
    }
L_0x0048c50d:
    // 0048c50d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c50e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c50f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c510  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c511  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048c512:
    // 0048c512  83c110                 -add ecx, 0x10
    (cpu.ecx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0048c515  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
L_0x0048c517:
    // 0048c517  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 0048c51a  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0048c51d  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0048c51f  8d7f01                 -lea edi, [edi + 1]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 0048c522  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0048c525  f7c703000000           +test edi, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & 3 /*0x3*/));
    // 0048c52b  8d49ff                 -lea ecx, [ecx - 1]
    cpu.ecx = x86::reg32(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 0048c52e  75e7                   -jne 0x48c517
    if (!cpu.flags.zf)
    {
        goto L_0x0048c517;
    }
    // 0048c530  8b5a0c                 -mov ebx, dword ptr [edx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0048c533  83e910                 +sub ecx, 0x10
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048c536  0f89f4feffff           -jns 0x48c430
    if (!cpu.flags.sf)
    {
        goto L_0x0048c430;
    }
    // 0048c53c  e97cffffff             -jmp 0x48c4bd
    goto L_0x0048c4bd;
L_0x0048c541:
    // 0048c541  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 0048c543  803dec844c0010         +cmp byte ptr [0x4c84ec], 0x10
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5014764) /* 0x4c84ec */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048c54a  7f1c                   -jg 0x48c568
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048c568;
    }
    // 0048c54c  83e901                 +sub ecx, 1
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
    // 0048c54f  78bc                   -js 0x48c50d
    if (cpu.flags.sf)
    {
        goto L_0x0048c50d;
    }
L_0x0048c551:
    // 0048c551  668b045e               -mov ax, word ptr [esi + ebx*2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + cpu.ebx * 2);
    // 0048c555  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0048c558  668907                 -mov word ptr [edi], ax
    app->getMemory<x86::reg16>(cpu.edi) = cpu.ax;
    // 0048c55b  83e901                 +sub ecx, 1
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
    // 0048c55e  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0048c561  8d7f02                 -lea edi, [edi + 2]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 0048c564  79eb                   -jns 0x48c551
    if (!cpu.flags.sf)
    {
        goto L_0x0048c551;
    }
    // 0048c566  eba5                   -jmp 0x48c50d
    goto L_0x0048c50d;
L_0x0048c568:
    // 0048c568  83e901                 +sub ecx, 1
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
    // 0048c56b  78a0                   -js 0x48c50d
    if (cpu.flags.sf)
    {
        goto L_0x0048c50d;
    }
L_0x0048c56d:
    // 0048c56d  8b049e                 -mov eax, dword ptr [esi + ebx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + cpu.ebx * 4);
    // 0048c570  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0048c573  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 0048c575  83e901                 +sub ecx, 1
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
    // 0048c578  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0048c57b  8d7f04                 -lea edi, [edi + 4]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0048c57e  79ed                   -jns 0x48c56d
    if (!cpu.flags.sf)
    {
        goto L_0x0048c56d;
    }
    // 0048c580  eb8b                   -jmp 0x48c50d
    goto L_0x0048c50d;
}

/* align: skip  */
void Application::sub_48c582(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048c582  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048c583  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048c584  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048c585  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048c586  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0048c58a  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0048c58e  8b6c241c               -mov ebp, dword ptr [esp + 0x1c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0048c592  8b1584a64c00           -mov edx, dword ptr [0x4ca684]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023364) /* 0x4ca684 */);
    // 0048c598  033588a64c00           -add esi, dword ptr [0x4ca688]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023368) /* 0x4ca688 */)));
    // 0048c59e  033df0844c00           -add edi, dword ptr [0x4c84f0]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014768) /* 0x4c84f0 */)));
    // 0048c5a4  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 0048c5a6  83ed01                 +sub ebp, 1
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048c5a9  7820                   -js 0x48c5cb
    if (cpu.flags.sf)
    {
        goto L_0x0048c5cb;
    }
    // 0048c5ab  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048c5ad  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0048c5af:
    // 0048c5af  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 0048c5b2  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0048c5b5  668b0c45a07f5200       -mov cx, word ptr [eax*2 + 0x527fa0]
    cpu.cx = app->getMemory<x86::reg16>(x86::reg32(5406624) /* 0x527fa0 */ + cpu.eax * 2);
    // 0048c5bd  83ed01                 +sub ebp, 1
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048c5c0  66890f                 -mov word ptr [edi], cx
    app->getMemory<x86::reg16>(cpu.edi) = cpu.cx;
    // 0048c5c3  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0048c5c6  8d7f02                 -lea edi, [edi + 2]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 0048c5c9  79e4                   -jns 0x48c5af
    if (!cpu.flags.sf)
    {
        goto L_0x0048c5af;
    }
L_0x0048c5cb:
    // 0048c5cb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c5cc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c5cd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c5ce  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c5cf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48c5d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048c5d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048c5d1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048c5d2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048c5d3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048c5d4  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0048c5d8  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0048c5dc  8b6c241c               -mov ebp, dword ptr [esp + 0x1c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0048c5e0  8b1584a64c00           -mov edx, dword ptr [0x4ca684]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023364) /* 0x4ca684 */);
    // 0048c5e6  033588a64c00           -add esi, dword ptr [0x4ca688]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023368) /* 0x4ca688 */)));
    // 0048c5ec  033df0844c00           -add edi, dword ptr [0x4c84f0]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014768) /* 0x4c84f0 */)));
    // 0048c5f2  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 0048c5f4  83ed01                 +sub ebp, 1
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048c5f7  7822                   -js 0x48c61b
    if (cpu.flags.sf)
    {
        goto L_0x0048c61b;
    }
    // 0048c5f9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0048c5fb:
    // 0048c5fb  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 0048c5fe  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0048c601  3cff                   +cmp al, 0xff
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048c603  740b                   -je 0x48c610
    if (cpu.flags.zf)
    {
        goto L_0x0048c610;
    }
    // 0048c605  668b0c45a07f5200       -mov cx, word ptr [eax*2 + 0x527fa0]
    cpu.cx = app->getMemory<x86::reg16>(x86::reg32(5406624) /* 0x527fa0 */ + cpu.eax * 2);
    // 0048c60d  66890f                 -mov word ptr [edi], cx
    app->getMemory<x86::reg16>(cpu.edi) = cpu.cx;
L_0x0048c610:
    // 0048c610  83ed01                 +sub ebp, 1
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048c613  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0048c616  8d7f02                 -lea edi, [edi + 2]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 0048c619  79e0                   -jns 0x48c5fb
    if (!cpu.flags.sf)
    {
        goto L_0x0048c5fb;
    }
L_0x0048c61b:
    // 0048c61b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c61c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c61d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c61e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c61f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48c620(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048c620  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048c621  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048c622  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048c623  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048c624  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0048c628  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0048c62c  8b6c241c               -mov ebp, dword ptr [esp + 0x1c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0048c630  8b1584a64c00           -mov edx, dword ptr [0x4ca684]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023364) /* 0x4ca684 */);
    // 0048c636  033588a64c00           -add esi, dword ptr [0x4ca688]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023368) /* 0x4ca688 */)));
    // 0048c63c  033df0844c00           -add edi, dword ptr [0x4c84f0]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014768) /* 0x4c84f0 */)));
    // 0048c642  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 0048c644  83ed01                 +sub ebp, 1
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048c647  7822                   -js 0x48c66b
    if (cpu.flags.sf)
    {
        goto L_0x0048c66b;
    }
    // 0048c649  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0048c64b:
    // 0048c64b  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 0048c64e  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0048c651  3cfd                   +cmp al, 0xfd
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(253 /*0xfd*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048c653  731b                   -jae 0x48c670
    if (!cpu.flags.cf)
    {
        goto L_0x0048c670;
    }
    // 0048c655  668b0c45a07f5200       -mov cx, word ptr [eax*2 + 0x527fa0]
    cpu.cx = app->getMemory<x86::reg16>(x86::reg32(5406624) /* 0x527fa0 */ + cpu.eax * 2);
    // 0048c65d  66890f                 -mov word ptr [edi], cx
    app->getMemory<x86::reg16>(cpu.edi) = cpu.cx;
    // 0048c660  83ed01                 +sub ebp, 1
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048c663  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0048c666  8d7f02                 -lea edi, [edi + 2]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 0048c669  79e0                   -jns 0x48c64b
    if (!cpu.flags.sf)
    {
        goto L_0x0048c64b;
    }
L_0x0048c66b:
    // 0048c66b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c66c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c66d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c66e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c66f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048c670:
    // 0048c670  3cfe                   +cmp al, 0xfe
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(254 /*0xfe*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048c672  7435                   -je 0x48c6a9
    if (cpu.flags.zf)
    {
        goto L_0x0048c6a9;
    }
    // 0048c674  3cfd                   +cmp al, 0xfd
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(253 /*0xfd*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048c676  740d                   -je 0x48c685
    if (cpu.flags.zf)
    {
        goto L_0x0048c685;
    }
    // 0048c678  83ed01                 +sub ebp, 1
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048c67b  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0048c67e  8d7f02                 -lea edi, [edi + 2]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 0048c681  79c8                   -jns 0x48c64b
    if (!cpu.flags.sf)
    {
        goto L_0x0048c64b;
    }
    // 0048c683  ebe6                   -jmp 0x48c66b
    goto L_0x0048c66b;
L_0x0048c685:
    // 0048c685  668b0f                 -mov cx, word ptr [edi]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edi);
    // 0048c688  6689c8                 -mov ax, cx
    cpu.ax = cpu.cx;
    // 0048c68b  66c1e902               -shr cx, 2
    cpu.cx >>= 2 /*0x2*/ % 32;
    // 0048c68f  6681e1e739             -and cx, 0x39e7
    cpu.cx &= x86::reg16(x86::sreg16(14823 /*0x39e7*/));
    // 0048c694  6629c8                 -sub ax, cx
    (cpu.ax) -= x86::reg16(x86::sreg16(cpu.cx));
    // 0048c697  668907                 -mov word ptr [edi], ax
    app->getMemory<x86::reg16>(cpu.edi) = cpu.ax;
    // 0048c69a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048c69c  83ed01                 +sub ebp, 1
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048c69f  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0048c6a2  8d7f02                 -lea edi, [edi + 2]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 0048c6a5  79a4                   -jns 0x48c64b
    if (!cpu.flags.sf)
    {
        goto L_0x0048c64b;
    }
    // 0048c6a7  ebc2                   -jmp 0x48c66b
    goto L_0x0048c66b;
L_0x0048c6a9:
    // 0048c6a9  668b0f                 -mov cx, word ptr [edi]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edi);
    // 0048c6ac  66d1e9                 -shr cx, 1
    cpu.cx >>= 1 /*0x1*/ % 32;
    // 0048c6af  6681e1ef7b             -and cx, 0x7bef
    cpu.cx &= x86::reg16(x86::sreg16(31727 /*0x7bef*/));
    // 0048c6b4  66890f                 -mov word ptr [edi], cx
    app->getMemory<x86::reg16>(cpu.edi) = cpu.cx;
    // 0048c6b7  83ed01                 +sub ebp, 1
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048c6ba  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0048c6bd  8d7f02                 -lea edi, [edi + 2]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 0048c6c0  7989                   -jns 0x48c64b
    if (!cpu.flags.sf)
    {
        goto L_0x0048c64b;
    }
    // 0048c6c2  eba7                   -jmp 0x48c66b
    goto L_0x0048c66b;
}

/* align: skip  */
void Application::sub_48c6c4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048c6c4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048c6c5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048c6c6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048c6c7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048c6c8  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0048c6cc  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0048c6d0  8b1584a64c00           -mov edx, dword ptr [0x4ca684]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023364) /* 0x4ca684 */);
    // 0048c6d6  033588a64c00           -add esi, dword ptr [0x4ca688]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023368) /* 0x4ca688 */)));
    // 0048c6dc  033df0844c00           -add edi, dword ptr [0x4c84f0]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014768) /* 0x4c84f0 */)));
    // 0048c6e2  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 0048c6e4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048c6e6  803dec844c0008         +cmp byte ptr [0x4c84ec], 8
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5014764) /* 0x4c84ec */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(8 /*0x8*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048c6ed  0f8f32010000           -jg 0x48c825
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048c825;
    }
    // 0048c6f3  f7c707000000           +test edi, 7
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & 7 /*0x7*/));
    // 0048c6f9  7421                   -je 0x48c71c
    if (cpu.flags.zf)
    {
        goto L_0x0048c71c;
    }
L_0x0048c6fb:
    // 0048c6fb  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 0048c6fe  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0048c701  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0048c703  836c241c01             +sub dword ptr [esp + 0x1c], 1
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048c708  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0048c70b  8d7f01                 -lea edi, [edi + 1]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 0048c70e  0f880c010000           -js 0x48c820
    if (cpu.flags.sf)
    {
        goto L_0x0048c820;
    }
    // 0048c714  f7c707000000           +test edi, 7
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & 7 /*0x7*/));
    // 0048c71a  75df                   -jne 0x48c6fb
    if (!cpu.flags.zf)
    {
        goto L_0x0048c6fb;
    }
L_0x0048c71c:
    // 0048c71c  836c241c08             +sub dword ptr [esp + 0x1c], 8
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048c721  0f8c8d000000           -jl 0x48c7b4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048c7b4;
    }
L_0x0048c727:
    // 0048c727  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 0048c72a  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0048c72d  0f6ec8                 -movd mm1, eax
    cpu.mmx.mm1 = { _mm_cvtsi32_si128(cpu.eax) };
    // 0048c730  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 0048c733  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0048c736  0f6ec0                 -movd mm0, eax
    cpu.mmx.mm0 = { _mm_cvtsi32_si128(cpu.eax) };
    // 0048c739  0f73f008               -psllq mm0, 8
    cpu.mmx.mm0 = { _mm_slli_epi64(cpu.mmx.mm0, 8 /*0x8*/) };
    // 0048c73d  0febc8                 -por mm1, mm0
    cpu.mmx.mm1 = { _mm_or_si128(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 0048c740  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 0048c743  8b5a0c                 -mov ebx, dword ptr [edx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0048c746  0f6ec0                 -movd mm0, eax
    cpu.mmx.mm0 = { _mm_cvtsi32_si128(cpu.eax) };
    // 0048c749  0f73f010               -psllq mm0, 0x10
    cpu.mmx.mm0 = { _mm_slli_epi64(cpu.mmx.mm0, 16 /*0x10*/) };
    // 0048c74d  0febc8                 -por mm1, mm0
    cpu.mmx.mm1 = { _mm_or_si128(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 0048c750  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 0048c753  8b5a10                 -mov ebx, dword ptr [edx + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0048c756  0f6ec0                 -movd mm0, eax
    cpu.mmx.mm0 = { _mm_cvtsi32_si128(cpu.eax) };
    // 0048c759  0f73f018               -psllq mm0, 0x18
    cpu.mmx.mm0 = { _mm_slli_epi64(cpu.mmx.mm0, 24 /*0x18*/) };
    // 0048c75d  0febc8                 -por mm1, mm0
    cpu.mmx.mm1 = { _mm_or_si128(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 0048c760  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 0048c763  8b5a14                 -mov ebx, dword ptr [edx + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 0048c766  0f6ec0                 -movd mm0, eax
    cpu.mmx.mm0 = { _mm_cvtsi32_si128(cpu.eax) };
    // 0048c769  0f73f020               -psllq mm0, 0x20
    cpu.mmx.mm0 = { _mm_slli_epi64(cpu.mmx.mm0, 32 /*0x20*/) };
    // 0048c76d  0febc8                 -por mm1, mm0
    cpu.mmx.mm1 = { _mm_or_si128(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 0048c770  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 0048c773  8b5a18                 -mov ebx, dword ptr [edx + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 0048c776  0f6ec0                 -movd mm0, eax
    cpu.mmx.mm0 = { _mm_cvtsi32_si128(cpu.eax) };
    // 0048c779  0f73f028               -psllq mm0, 0x28
    cpu.mmx.mm0 = { _mm_slli_epi64(cpu.mmx.mm0, 40 /*0x28*/) };
    // 0048c77d  0febc8                 -por mm1, mm0
    cpu.mmx.mm1 = { _mm_or_si128(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 0048c780  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 0048c783  8b5a1c                 -mov ebx, dword ptr [edx + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 0048c786  0f6ec0                 -movd mm0, eax
    cpu.mmx.mm0 = { _mm_cvtsi32_si128(cpu.eax) };
    // 0048c789  0f73f030               -psllq mm0, 0x30
    cpu.mmx.mm0 = { _mm_slli_epi64(cpu.mmx.mm0, 48 /*0x30*/) };
    // 0048c78d  0febc8                 -por mm1, mm0
    cpu.mmx.mm1 = { _mm_or_si128(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 0048c790  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 0048c793  8b5a20                 -mov ebx, dword ptr [edx + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 0048c796  0f6ec0                 -movd mm0, eax
    cpu.mmx.mm0 = { _mm_cvtsi32_si128(cpu.eax) };
    // 0048c799  0f73f038               -psllq mm0, 0x38
    cpu.mmx.mm0 = { _mm_slli_epi64(cpu.mmx.mm0, 56 /*0x38*/) };
    // 0048c79d  0febc8                 -por mm1, mm0
    cpu.mmx.mm1 = { _mm_or_si128(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 0048c7a0  0f7f0f                 -movq qword ptr [edi], mm1
    app->getMemory<x86::reg64>(cpu.edi) = cpu.mmx.mm1;
    // 0048c7a3  836c241c08             +sub dword ptr [esp + 0x1c], 8
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048c7a8  8d5220                 -lea edx, [edx + 0x20]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 0048c7ab  8d7f08                 -lea edi, [edi + 8]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0048c7ae  0f8973ffffff           -jns 0x48c727
    if (!cpu.flags.sf)
    {
        goto L_0x0048c727;
    }
L_0x0048c7b4:
    // 0048c7b4  8344241c04             +add dword ptr [esp + 0x1c], 4
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048c7b9  7849                   -js 0x48c804
    if (cpu.flags.sf)
    {
        goto L_0x0048c804;
    }
L_0x0048c7bb:
    // 0048c7bb  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 0048c7be  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0048c7c1  0f6ec8                 -movd mm1, eax
    cpu.mmx.mm1 = { _mm_cvtsi32_si128(cpu.eax) };
    // 0048c7c4  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 0048c7c7  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0048c7ca  0f6ec0                 -movd mm0, eax
    cpu.mmx.mm0 = { _mm_cvtsi32_si128(cpu.eax) };
    // 0048c7cd  0f73f008               -psllq mm0, 8
    cpu.mmx.mm0 = { _mm_slli_epi64(cpu.mmx.mm0, 8 /*0x8*/) };
    // 0048c7d1  0febc8                 -por mm1, mm0
    cpu.mmx.mm1 = { _mm_or_si128(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 0048c7d4  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 0048c7d7  8b5a0c                 -mov ebx, dword ptr [edx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0048c7da  0f6ec0                 -movd mm0, eax
    cpu.mmx.mm0 = { _mm_cvtsi32_si128(cpu.eax) };
    // 0048c7dd  0f73f010               -psllq mm0, 0x10
    cpu.mmx.mm0 = { _mm_slli_epi64(cpu.mmx.mm0, 16 /*0x10*/) };
    // 0048c7e1  0febc8                 -por mm1, mm0
    cpu.mmx.mm1 = { _mm_or_si128(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 0048c7e4  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 0048c7e7  8b5a10                 -mov ebx, dword ptr [edx + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0048c7ea  0f6ec0                 -movd mm0, eax
    cpu.mmx.mm0 = { _mm_cvtsi32_si128(cpu.eax) };
    // 0048c7ed  0f73f018               -psllq mm0, 0x18
    cpu.mmx.mm0 = { _mm_slli_epi64(cpu.mmx.mm0, 24 /*0x18*/) };
    // 0048c7f1  0febc8                 -por mm1, mm0
    cpu.mmx.mm1 = { _mm_or_si128(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 0048c7f4  0f7e0f                 -movd dword ptr [edi], mm1
    _mm_storeu_si32(&app->getMemory<x86::reg32>(cpu.edi), cpu.mmx.mm1);
    // 0048c7f7  836c241c04             +sub dword ptr [esp + 0x1c], 4
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048c7fc  8d5210                 -lea edx, [edx + 0x10]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0048c7ff  8d7f04                 -lea edi, [edi + 4]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0048c802  79b7                   -jns 0x48c7bb
    if (!cpu.flags.sf)
    {
        goto L_0x0048c7bb;
    }
L_0x0048c804:
    // 0048c804  8344241c03             +add dword ptr [esp + 0x1c], 3
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048c809  7815                   -js 0x48c820
    if (cpu.flags.sf)
    {
        goto L_0x0048c820;
    }
L_0x0048c80b:
    // 0048c80b  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 0048c80e  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0048c811  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0048c813  836c241c01             +sub dword ptr [esp + 0x1c], 1
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048c818  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0048c81b  8d7f01                 -lea edi, [edi + 1]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 0048c81e  79eb                   -jns 0x48c80b
    if (!cpu.flags.sf)
    {
        goto L_0x0048c80b;
    }
L_0x0048c820:
    // 0048c820  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c821  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c822  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c823  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c824  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048c825:
    // 0048c825  803dec844c0010         +cmp byte ptr [0x4c84ec], 0x10
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5014764) /* 0x4c84ec */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048c82c  0f8f47010000           -jg 0x48c979
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048c979;
    }
    // 0048c832  f7c707000000           +test edi, 7
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & 7 /*0x7*/));
    // 0048c838  741f                   -je 0x48c859
    if (cpu.flags.zf)
    {
        goto L_0x0048c859;
    }
L_0x0048c83a:
    // 0048c83a  668b045e               -mov ax, word ptr [esi + ebx*2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + cpu.ebx * 2);
    // 0048c83e  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0048c841  668907                 -mov word ptr [edi], ax
    app->getMemory<x86::reg16>(cpu.edi) = cpu.ax;
    // 0048c844  836c241c01             +sub dword ptr [esp + 0x1c], 1
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048c849  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0048c84c  8d7f02                 -lea edi, [edi + 2]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 0048c84f  78cf                   -js 0x48c820
    if (cpu.flags.sf)
    {
        goto L_0x0048c820;
    }
    // 0048c851  f7c707000000           +test edi, 7
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & 7 /*0x7*/));
    // 0048c857  75e1                   -jne 0x48c83a
    if (!cpu.flags.zf)
    {
        goto L_0x0048c83a;
    }
L_0x0048c859:
    // 0048c859  836c241c08             +sub dword ptr [esp + 0x1c], 8
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048c85e  0f8c92000000           -jl 0x48c8f6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048c8f6;
    }
L_0x0048c864:
    // 0048c864  668b045e               -mov ax, word ptr [esi + ebx*2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + cpu.ebx * 2);
    // 0048c868  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0048c86b  0f6ec8                 -movd mm1, eax
    cpu.mmx.mm1 = { _mm_cvtsi32_si128(cpu.eax) };
    // 0048c86e  668b045e               -mov ax, word ptr [esi + ebx*2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + cpu.ebx * 2);
    // 0048c872  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0048c875  0f6ec0                 -movd mm0, eax
    cpu.mmx.mm0 = { _mm_cvtsi32_si128(cpu.eax) };
    // 0048c878  0f73f010               -psllq mm0, 0x10
    cpu.mmx.mm0 = { _mm_slli_epi64(cpu.mmx.mm0, 16 /*0x10*/) };
    // 0048c87c  0febc8                 -por mm1, mm0
    cpu.mmx.mm1 = { _mm_or_si128(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 0048c87f  668b045e               -mov ax, word ptr [esi + ebx*2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + cpu.ebx * 2);
    // 0048c883  8b5a0c                 -mov ebx, dword ptr [edx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0048c886  0f6ec0                 -movd mm0, eax
    cpu.mmx.mm0 = { _mm_cvtsi32_si128(cpu.eax) };
    // 0048c889  0f73f020               -psllq mm0, 0x20
    cpu.mmx.mm0 = { _mm_slli_epi64(cpu.mmx.mm0, 32 /*0x20*/) };
    // 0048c88d  0febc8                 -por mm1, mm0
    cpu.mmx.mm1 = { _mm_or_si128(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 0048c890  668b045e               -mov ax, word ptr [esi + ebx*2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + cpu.ebx * 2);
    // 0048c894  8b5a10                 -mov ebx, dword ptr [edx + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0048c897  0f6ec0                 -movd mm0, eax
    cpu.mmx.mm0 = { _mm_cvtsi32_si128(cpu.eax) };
    // 0048c89a  0f73f030               -psllq mm0, 0x30
    cpu.mmx.mm0 = { _mm_slli_epi64(cpu.mmx.mm0, 48 /*0x30*/) };
    // 0048c89e  0febc8                 -por mm1, mm0
    cpu.mmx.mm1 = { _mm_or_si128(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 0048c8a1  0f7f0f                 -movq qword ptr [edi], mm1
    app->getMemory<x86::reg64>(cpu.edi) = cpu.mmx.mm1;
    // 0048c8a4  668b045e               -mov ax, word ptr [esi + ebx*2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + cpu.ebx * 2);
    // 0048c8a8  8b5a14                 -mov ebx, dword ptr [edx + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 0048c8ab  0f6ec8                 -movd mm1, eax
    cpu.mmx.mm1 = { _mm_cvtsi32_si128(cpu.eax) };
    // 0048c8ae  668b045e               -mov ax, word ptr [esi + ebx*2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + cpu.ebx * 2);
    // 0048c8b2  8b5a18                 -mov ebx, dword ptr [edx + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 0048c8b5  0f6ec0                 -movd mm0, eax
    cpu.mmx.mm0 = { _mm_cvtsi32_si128(cpu.eax) };
    // 0048c8b8  0f73f010               -psllq mm0, 0x10
    cpu.mmx.mm0 = { _mm_slli_epi64(cpu.mmx.mm0, 16 /*0x10*/) };
    // 0048c8bc  0febc8                 -por mm1, mm0
    cpu.mmx.mm1 = { _mm_or_si128(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 0048c8bf  668b045e               -mov ax, word ptr [esi + ebx*2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + cpu.ebx * 2);
    // 0048c8c3  8b5a1c                 -mov ebx, dword ptr [edx + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 0048c8c6  0f6ec0                 -movd mm0, eax
    cpu.mmx.mm0 = { _mm_cvtsi32_si128(cpu.eax) };
    // 0048c8c9  0f73f020               -psllq mm0, 0x20
    cpu.mmx.mm0 = { _mm_slli_epi64(cpu.mmx.mm0, 32 /*0x20*/) };
    // 0048c8cd  0febc8                 -por mm1, mm0
    cpu.mmx.mm1 = { _mm_or_si128(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 0048c8d0  668b045e               -mov ax, word ptr [esi + ebx*2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + cpu.ebx * 2);
    // 0048c8d4  8b5a20                 -mov ebx, dword ptr [edx + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 0048c8d7  0f6ec0                 -movd mm0, eax
    cpu.mmx.mm0 = { _mm_cvtsi32_si128(cpu.eax) };
    // 0048c8da  0f73f030               -psllq mm0, 0x30
    cpu.mmx.mm0 = { _mm_slli_epi64(cpu.mmx.mm0, 48 /*0x30*/) };
    // 0048c8de  0febc8                 -por mm1, mm0
    cpu.mmx.mm1 = { _mm_or_si128(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 0048c8e1  0f7f4f08               -movq qword ptr [edi + 8], mm1
    app->getMemory<x86::reg64>(cpu.edi + x86::reg32(8) /* 0x8 */) = cpu.mmx.mm1;
    // 0048c8e5  836c241c08             +sub dword ptr [esp + 0x1c], 8
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048c8ea  8d5220                 -lea edx, [edx + 0x20]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 0048c8ed  8d7f10                 -lea edi, [edi + 0x10]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 0048c8f0  0f896effffff           -jns 0x48c864
    if (!cpu.flags.sf)
    {
        goto L_0x0048c864;
    }
L_0x0048c8f6:
    // 0048c8f6  8344241c04             +add dword ptr [esp + 0x1c], 4
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048c8fb  7855                   -js 0x48c952
    if (cpu.flags.sf)
    {
        goto L_0x0048c952;
    }
    // 0048c8fd  f7c703000000           +test edi, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & 3 /*0x3*/));
    // 0048c903  754d                   -jne 0x48c952
    if (!cpu.flags.zf)
    {
        goto L_0x0048c952;
    }
L_0x0048c905:
    // 0048c905  668b045e               -mov ax, word ptr [esi + ebx*2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + cpu.ebx * 2);
    // 0048c909  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0048c90c  0f6ec8                 -movd mm1, eax
    cpu.mmx.mm1 = { _mm_cvtsi32_si128(cpu.eax) };
    // 0048c90f  668b045e               -mov ax, word ptr [esi + ebx*2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + cpu.ebx * 2);
    // 0048c913  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0048c916  0f6ec0                 -movd mm0, eax
    cpu.mmx.mm0 = { _mm_cvtsi32_si128(cpu.eax) };
    // 0048c919  0f73f010               -psllq mm0, 0x10
    cpu.mmx.mm0 = { _mm_slli_epi64(cpu.mmx.mm0, 16 /*0x10*/) };
    // 0048c91d  0febc8                 -por mm1, mm0
    cpu.mmx.mm1 = { _mm_or_si128(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 0048c920  668b045e               -mov ax, word ptr [esi + ebx*2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + cpu.ebx * 2);
    // 0048c924  8b5a0c                 -mov ebx, dword ptr [edx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0048c927  0f6ec0                 -movd mm0, eax
    cpu.mmx.mm0 = { _mm_cvtsi32_si128(cpu.eax) };
    // 0048c92a  0f73f020               -psllq mm0, 0x20
    cpu.mmx.mm0 = { _mm_slli_epi64(cpu.mmx.mm0, 32 /*0x20*/) };
    // 0048c92e  0febc8                 -por mm1, mm0
    cpu.mmx.mm1 = { _mm_or_si128(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 0048c931  668b045e               -mov ax, word ptr [esi + ebx*2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + cpu.ebx * 2);
    // 0048c935  8b5a10                 -mov ebx, dword ptr [edx + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0048c938  0f6ec0                 -movd mm0, eax
    cpu.mmx.mm0 = { _mm_cvtsi32_si128(cpu.eax) };
    // 0048c93b  0f73f030               -psllq mm0, 0x30
    cpu.mmx.mm0 = { _mm_slli_epi64(cpu.mmx.mm0, 48 /*0x30*/) };
    // 0048c93f  0febc8                 -por mm1, mm0
    cpu.mmx.mm1 = { _mm_or_si128(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 0048c942  0f7f0f                 -movq qword ptr [edi], mm1
    app->getMemory<x86::reg64>(cpu.edi) = cpu.mmx.mm1;
    // 0048c945  836c241c04             +sub dword ptr [esp + 0x1c], 4
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048c94a  8d5210                 -lea edx, [edx + 0x10]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0048c94d  8d7f08                 -lea edi, [edi + 8]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0048c950  79b3                   -jns 0x48c905
    if (!cpu.flags.sf)
    {
        goto L_0x0048c905;
    }
L_0x0048c952:
    // 0048c952  8344241c03             +add dword ptr [esp + 0x1c], 3
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048c957  0f88c3feffff           -js 0x48c820
    if (cpu.flags.sf)
    {
        goto L_0x0048c820;
    }
L_0x0048c95d:
    // 0048c95d  668b045e               -mov ax, word ptr [esi + ebx*2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + cpu.ebx * 2);
    // 0048c961  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0048c964  668907                 -mov word ptr [edi], ax
    app->getMemory<x86::reg16>(cpu.edi) = cpu.ax;
    // 0048c967  836c241c01             +sub dword ptr [esp + 0x1c], 1
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048c96c  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0048c96f  8d7f02                 -lea edi, [edi + 2]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 0048c972  79e9                   -jns 0x48c95d
    if (!cpu.flags.sf)
    {
        goto L_0x0048c95d;
    }
    // 0048c974  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c975  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c976  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c977  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c978  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048c979:
    // 0048c979  836c241c01             +sub dword ptr [esp + 0x1c], 1
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048c97e  0f889cfeffff           -js 0x48c820
    if (cpu.flags.sf)
    {
        goto L_0x0048c820;
    }
L_0x0048c984:
    // 0048c984  8b049e                 -mov eax, dword ptr [esi + ebx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + cpu.ebx * 4);
    // 0048c987  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0048c98a  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 0048c98c  836c241c01             +sub dword ptr [esp + 0x1c], 1
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048c991  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0048c994  8d7f04                 -lea edi, [edi + 4]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0048c997  79eb                   -jns 0x48c984
    if (!cpu.flags.sf)
    {
        goto L_0x0048c984;
    }
    // 0048c999  e982feffff             -jmp 0x48c820
    goto L_0x0048c820;
}

/* align: skip  */
void Application::sub_48c99e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048c99e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048c99f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048c9a0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048c9a1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048c9a2  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0048c9a6  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0048c9aa  8b1584a64c00           -mov edx, dword ptr [0x4ca684]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023364) /* 0x4ca684 */);
    // 0048c9b0  033588a64c00           -add esi, dword ptr [0x4ca688]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023368) /* 0x4ca688 */)));
    // 0048c9b6  033df0844c00           -add edi, dword ptr [0x4c84f0]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014768) /* 0x4c84f0 */)));
    // 0048c9bc  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 0048c9be  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048c9c0  803dec844c0008         +cmp byte ptr [0x4c84ec], 8
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5014764) /* 0x4c84ec */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(8 /*0x8*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048c9c7  0f8ffd000000           -jg 0x48caca
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048caca;
    }
    // 0048c9cd  f7c703000000           +test edi, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & 3 /*0x3*/));
    // 0048c9d3  7421                   -je 0x48c9f6
    if (cpu.flags.zf)
    {
        goto L_0x0048c9f6;
    }
L_0x0048c9d5:
    // 0048c9d5  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 0048c9d8  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0048c9db  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0048c9dd  836c241c01             +sub dword ptr [esp + 0x1c], 1
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048c9e2  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0048c9e5  8d7f01                 -lea edi, [edi + 1]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 0048c9e8  0f88d7000000           -js 0x48cac5
    if (cpu.flags.sf)
    {
        goto L_0x0048cac5;
    }
    // 0048c9ee  f7c703000000           +test edi, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & 3 /*0x3*/));
    // 0048c9f4  75df                   -jne 0x48c9d5
    if (!cpu.flags.zf)
    {
        goto L_0x0048c9d5;
    }
L_0x0048c9f6:
    // 0048c9f6  8b5a0c                 -mov ebx, dword ptr [edx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0048c9f9  836c241c08             +sub dword ptr [esp + 0x1c], 8
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048c9fe  7c67                   -jl 0x48ca67
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048ca67;
    }
L_0x0048ca00:
    // 0048ca00  8b6a08                 -mov ebp, dword ptr [edx + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0048ca03  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 0048ca06  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0048ca09  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048ca0b  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 0048ca0e  8a443500               -mov al, byte ptr [ebp + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.esi * 1);
    // 0048ca12  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx);
    // 0048ca14  09c1                   -or ecx, eax
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0048ca16  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 0048ca19  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 0048ca1c  8b5a1c                 -mov ebx, dword ptr [edx + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 0048ca1f  09c1                   -or ecx, eax
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0048ca21  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 0048ca24  8a443500               -mov al, byte ptr [ebp + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.esi * 1);
    // 0048ca28  09c1                   -or ecx, eax
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0048ca2a  8b6a18                 -mov ebp, dword ptr [edx + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 0048ca2d  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 0048ca30  8b5a14                 -mov ebx, dword ptr [edx + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 0048ca33  890f                   -mov dword ptr [edi], ecx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.ecx;
    // 0048ca35  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048ca37  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 0048ca3a  8a443500               -mov al, byte ptr [ebp + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.esi * 1);
    // 0048ca3e  8b6a10                 -mov ebp, dword ptr [edx + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0048ca41  09c1                   -or ecx, eax
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0048ca43  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 0048ca46  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 0048ca49  8b5a2c                 -mov ebx, dword ptr [edx + 0x2c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(44) /* 0x2c */);
    // 0048ca4c  09c1                   -or ecx, eax
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0048ca4e  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 0048ca51  8a443500               -mov al, byte ptr [ebp + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.esi * 1);
    // 0048ca55  09c1                   -or ecx, eax
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0048ca57  836c241c08             +sub dword ptr [esp + 0x1c], 8
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048ca5c  8d5220                 -lea edx, [edx + 0x20]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 0048ca5f  894f04                 -mov dword ptr [edi + 4], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0048ca62  8d7f08                 -lea edi, [edi + 8]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0048ca65  7999                   -jns 0x48ca00
    if (!cpu.flags.sf)
    {
        goto L_0x0048ca00;
    }
L_0x0048ca67:
    // 0048ca67  8344241c04             +add dword ptr [esp + 0x1c], 4
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048ca6c  7839                   -js 0x48caa7
    if (cpu.flags.sf)
    {
        goto L_0x0048caa7;
    }
L_0x0048ca6e:
    // 0048ca6e  8b6a08                 -mov ebp, dword ptr [edx + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0048ca71  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 0048ca74  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0048ca77  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048ca79  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 0048ca7c  8a443500               -mov al, byte ptr [ebp + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.esi * 1);
    // 0048ca80  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx);
    // 0048ca82  09c1                   -or ecx, eax
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0048ca84  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 0048ca87  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 0048ca8a  8b5a1c                 -mov ebx, dword ptr [edx + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 0048ca8d  09c1                   -or ecx, eax
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0048ca8f  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 0048ca92  8a443500               -mov al, byte ptr [ebp + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.esi * 1);
    // 0048ca96  09c1                   -or ecx, eax
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0048ca98  890f                   -mov dword ptr [edi], ecx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.ecx;
    // 0048ca9a  836c241c04             +sub dword ptr [esp + 0x1c], 4
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048ca9f  8d5210                 -lea edx, [edx + 0x10]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0048caa2  8d7f04                 -lea edi, [edi + 4]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0048caa5  79c7                   -jns 0x48ca6e
    if (!cpu.flags.sf)
    {
        goto L_0x0048ca6e;
    }
L_0x0048caa7:
    // 0048caa7  8344241c03             +add dword ptr [esp + 0x1c], 3
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048caac  7817                   -js 0x48cac5
    if (cpu.flags.sf)
    {
        goto L_0x0048cac5;
    }
    // 0048caae  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
L_0x0048cab0:
    // 0048cab0  8a0433                 -mov al, byte ptr [ebx + esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.esi * 1);
    // 0048cab3  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0048cab6  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0048cab8  836c241c01             +sub dword ptr [esp + 0x1c], 1
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048cabd  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0048cac0  8d7f01                 -lea edi, [edi + 1]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 0048cac3  79eb                   -jns 0x48cab0
    if (!cpu.flags.sf)
    {
        goto L_0x0048cab0;
    }
L_0x0048cac5:
    // 0048cac5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cac6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cac7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cac8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cac9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048caca:
    // 0048caca  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048cacc  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 0048cace  803dec844c0010         +cmp byte ptr [0x4c84ec], 0x10
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5014764) /* 0x4c84ec */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048cad5  7f20                   -jg 0x48caf7
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048caf7;
    }
    // 0048cad7  836c241c01             +sub dword ptr [esp + 0x1c], 1
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048cadc  78e7                   -js 0x48cac5
    if (cpu.flags.sf)
    {
        goto L_0x0048cac5;
    }
L_0x0048cade:
    // 0048cade  668b045e               -mov ax, word ptr [esi + ebx*2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + cpu.ebx * 2);
    // 0048cae2  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0048cae5  668907                 -mov word ptr [edi], ax
    app->getMemory<x86::reg16>(cpu.edi) = cpu.ax;
    // 0048cae8  836c241c01             +sub dword ptr [esp + 0x1c], 1
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048caed  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0048caf0  8d7f02                 -lea edi, [edi + 2]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 0048caf3  79e9                   -jns 0x48cade
    if (!cpu.flags.sf)
    {
        goto L_0x0048cade;
    }
    // 0048caf5  ebce                   -jmp 0x48cac5
    goto L_0x0048cac5;
L_0x0048caf7:
    // 0048caf7  836c241c01             +sub dword ptr [esp + 0x1c], 1
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048cafc  78c7                   -js 0x48cac5
    if (cpu.flags.sf)
    {
        goto L_0x0048cac5;
    }
L_0x0048cafe:
    // 0048cafe  8b049e                 -mov eax, dword ptr [esi + ebx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + cpu.ebx * 4);
    // 0048cb01  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0048cb04  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 0048cb06  836c241c01             +sub dword ptr [esp + 0x1c], 1
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048cb0b  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0048cb0e  8d7f04                 -lea edi, [edi + 4]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0048cb11  79eb                   -jns 0x48cafe
    if (!cpu.flags.sf)
    {
        goto L_0x0048cafe;
    }
    // 0048cb13  ebb0                   -jmp 0x48cac5
    goto L_0x0048cac5;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_48cb20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048cb20  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048cb21  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048cb22  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048cb23  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048cb24  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048cb26  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0048cb28  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048cb2a  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 0048cb2c  39d0                   +cmp eax, edx
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
    // 0048cb2e  7540                   -jne 0x48cb70
    if (!cpu.flags.zf)
    {
        goto L_0x0048cb70;
    }
    // 0048cb30  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048cb32  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048cb34  668b4604               -mov ax, word ptr [esi + 4]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0048cb38  668b5704               -mov dx, word ptr [edi + 4]
    cpu.dx = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0048cb3c  39d0                   +cmp eax, edx
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
    // 0048cb3e  7530                   -jne 0x48cb70
    if (!cpu.flags.zf)
    {
        goto L_0x0048cb70;
    }
    // 0048cb40  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048cb42  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048cb44  668b4606               -mov ax, word ptr [esi + 6]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 0048cb48  668b5706               -mov dx, word ptr [edi + 6]
    cpu.dx = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(6) /* 0x6 */);
    // 0048cb4c  39d0                   +cmp eax, edx
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
    // 0048cb4e  7520                   -jne 0x48cb70
    if (!cpu.flags.zf)
    {
        goto L_0x0048cb70;
    }
    // 0048cb50  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0048cb52  8a5e08                 -mov bl, byte ptr [esi + 8]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0048cb55  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048cb57  8a7f08                 -mov bh, byte ptr [edi + 8]
    cpu.bh = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0048cb5a  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0048cb5c  38fb                   +cmp bl, bh
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
    // 0048cb5e  7510                   -jne 0x48cb70
    if (!cpu.flags.zf)
    {
        goto L_0x0048cb70;
    }
L_0x0048cb60:
    // 0048cb60  42                     -inc edx
    (cpu.edx)++;
    // 0048cb61  40                     -inc eax
    (cpu.eax)++;
    // 0048cb62  41                     -inc ecx
    (cpu.ecx)++;
    // 0048cb63  83f808                 +cmp eax, 8
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
    // 0048cb66  7d0f                   -jge 0x48cb77
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048cb77;
    }
    // 0048cb68  8a5908                 -mov bl, byte ptr [ecx + 8]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0048cb6b  3a5a08                 +cmp bl, byte ptr [edx + 8]
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(8) /* 0x8 */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048cb6e  74f0                   -je 0x48cb60
    if (cpu.flags.zf)
    {
        goto L_0x0048cb60;
    }
L_0x0048cb70:
    // 0048cb70  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048cb72  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cb73  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cb74  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cb75  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cb76  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048cb77:
    // 0048cb77  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048cb7c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cb7d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cb7e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cb7f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cb80  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48cb84(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048cb84  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048cb85  833da0a64c0000         +cmp dword ptr [0x4ca6a0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5023392) /* 0x4ca6a0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048cb8c  742b                   -je 0x48cbb9
    if (cpu.flags.zf)
    {
        goto L_0x0048cbb9;
    }
L_0x0048cb8e:
    // 0048cb8e  b810615200             -mov eax, 0x526110
    cpu.eax = 5398800 /*0x526110*/;
    // 0048cb93  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048cb95  e8ea32ffff             -call 0x47fe84
    cpu.esp -= 4;
    sub_47fe84(app, cpu);
    if (cpu.terminate) return;
    // 0048cb9a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048cb9c  7407                   -je 0x48cba5
    if (cpu.flags.zf)
    {
        goto L_0x0048cba5;
    }
    // 0048cb9e  e8e9010000             -call 0x48cd8c
    cpu.esp -= 4;
    sub_48cd8c(app, cpu);
    if (cpu.terminate) return;
    // 0048cba3  ebe9                   -jmp 0x48cb8e
    goto L_0x0048cb8e;
L_0x0048cba5:
    // 0048cba5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048cba6  b810615200             -mov eax, 0x526110
    cpu.eax = 5398800 /*0x526110*/;
    // 0048cbab  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048cbad  e8ca2fffff             -call 0x47fb7c
    cpu.esp -= 4;
    sub_47fb7c(app, cpu);
    if (cpu.terminate) return;
    // 0048cbb2  890da0a64c00           -mov dword ptr [0x4ca6a0], ecx
    app->getMemory<x86::reg32>(x86::reg32(5023392) /* 0x4ca6a0 */) = cpu.ecx;
    // 0048cbb8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0048cbb9:
    // 0048cbb9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cbba  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48cbbc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048cbbc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048cbbd  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048cbbe  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048cbbf  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0048cbc2  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0048cbc6  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0048cbc9  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0048cbcd  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0048cbcf  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048cbd4  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048cbd6  8b0d9ca64c00           -mov ecx, dword ptr [0x4ca69c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5023388) /* 0x4ca69c */);
    // 0048cbdc  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0048cbe0  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048cbe2  7e43                   -jle 0x48cc27
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048cc27;
    }
    // 0048cbe4  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x0048cbe6:
    // 0048cbe6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048cbe8  743d                   -je 0x48cc27
    if (cpu.flags.zf)
    {
        goto L_0x0048cc27;
    }
    // 0048cbea  8b96d0605200           -mov edx, dword ptr [esi + 0x5260d0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5398736) /* 0x5260d0 */);
    // 0048cbf0  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0048cbf3  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048cbf5  7537                   -jne 0x48cc2e
    if (!cpu.flags.zf)
    {
        goto L_0x0048cc2e;
    }
    // 0048cbf7  83ff20                 +cmp edi, 0x20
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048cbfa  7715                   -ja 0x48cc11
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0048cc11;
    }
    // 0048cbfc  8b86f0605200           -mov eax, dword ptr [esi + 0x5260f0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5398768) /* 0x5260f0 */);
    // 0048cc02  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048cc05  bbfa000000             -mov ebx, 0xfa
    cpu.ebx = 250 /*0xfa*/;
    // 0048cc0a  8b50fc                 -mov edx, dword ptr [eax - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 0048cc0d  ff542408               -call dword ptr [esp + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0048cc11:
    // 0048cc11  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048cc15  8b2d9ca64c00           -mov ebp, dword ptr [0x4ca69c]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5023388) /* 0x4ca69c */);
    // 0048cc1b  43                     -inc ebx
    (cpu.ebx)++;
    // 0048cc1c  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048cc1f  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 0048cc23  39eb                   +cmp ebx, ebp
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
    // 0048cc25  7cbf                   -jl 0x48cbe6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048cbe6;
    }
L_0x0048cc27:
    // 0048cc27  83c410                 +add esp, 0x10
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
    // 0048cc2a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cc2b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cc2c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cc2d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048cc2e:
    // 0048cc2e  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048cc32  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048cc36  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0048cc38  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0048cc3a  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0048cc3d  ff5504                 -call dword ptr [ebp + 4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048cc40  ebcf                   -jmp 0x48cc11
    goto L_0x0048cc11;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48cc44(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048cc44  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048cc45  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048cc46  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048cc47  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0048cc4a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048cc4c  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0048cc50  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0048cc53  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0048cc57  8b15a0a64c00           -mov edx, dword ptr [0x4ca6a0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023392) /* 0x4ca6a0 */);
    // 0048cc5d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048cc5f  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048cc61  0f84a4000000           -je 0x48cd0b
    if (cpu.flags.zf)
    {
        goto L_0x0048cd0b;
    }
L_0x0048cc67:
    // 0048cc67  b810615200             -mov eax, 0x526110
    cpu.eax = 5398800 /*0x526110*/;
    // 0048cc6c  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0048cc6e  e8ed30ffff             -call 0x47fd60
    cpu.esp -= 4;
    sub_47fd60(app, cpu);
    if (cpu.terminate) return;
    // 0048cc73  83f8ff                 +cmp eax, -1
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
    // 0048cc76  7407                   -je 0x48cc7f
    if (cpu.flags.zf)
    {
        goto L_0x0048cc7f;
    }
    // 0048cc78  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048cc7a  e80d010000             -call 0x48cd8c
    cpu.esp -= 4;
    sub_48cd8c(app, cpu);
    if (cpu.terminate) return;
L_0x0048cc7f:
    // 0048cc7f  baac000000             -mov edx, 0xac
    cpu.edx = 172 /*0xac*/;
    // 0048cc84  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048cc86  e85124ffff             -call 0x47f0dc
    cpu.esp -= 4;
    sub_47f0dc(app, cpu);
    if (cpu.terminate) return;
    // 0048cc8b  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0048cc8d  a19ca64c00             -mov eax, dword ptr [0x4ca69c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023388) /* 0x4ca69c */);
    // 0048cc92  896c240c               -mov dword ptr [esp + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 0048cc96  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048cc98  7e62                   -jle 0x48ccfc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048ccfc;
    }
    // 0048cc9a  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x0048cc9c:
    // 0048cc9c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048cc9e  755c                   -jne 0x48ccfc
    if (!cpu.flags.zf)
    {
        goto L_0x0048ccfc;
    }
    // 0048cca0  8b87f0605200           -mov eax, dword ptr [edi + 0x5260f0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5398768) /* 0x5260f0 */);
    // 0048cca6  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0048cca9  8b87d0605200           -mov eax, dword ptr [edi + 0x5260d0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5398736) /* 0x5260d0 */);
    // 0048ccaf  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0048ccb2  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048ccb6  894610                 -mov dword ptr [esi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0048ccb9  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0048ccbc  83780400               +cmp dword ptr [eax + 4], 0
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
    // 0048ccc0  0f848d000000           -je 0x48cd53
    if (cpu.flags.zf)
    {
        goto L_0x0048cd53;
    }
L_0x0048ccc6:
    // 0048ccc6  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0048ccca  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0048ccce  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0048ccd2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048ccd3  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048ccd7  8b6e04                 -mov ebp, dword ptr [esi + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0048ccda  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048ccdb  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048ccdd  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048cce1  ff5508                 -call dword ptr [ebp + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048cce4  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x0048cce6:
    // 0048cce6  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048ccea  8b1d9ca64c00           -mov ebx, dword ptr [0x4ca69c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5023388) /* 0x4ca69c */);
    // 0048ccf0  42                     -inc edx
    (cpu.edx)++;
    // 0048ccf1  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048ccf4  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0048ccf8  39da                   +cmp edx, ebx
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
    // 0048ccfa  7ca0                   -jl 0x48cc9c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048cc9c;
    }
L_0x0048ccfc:
    // 0048ccfc  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048ccfe  7572                   -jne 0x48cd72
    if (!cpu.flags.zf)
    {
        goto L_0x0048cd72;
    }
    // 0048cd00  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048cd02  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0048cd05  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cd06  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cd07  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cd08  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x0048cd0b:
    // 0048cd0b  b810615200             -mov eax, 0x526110
    cpu.eax = 5398800 /*0x526110*/;
    // 0048cd10  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048cd12  e8252effff             -call 0x47fb3c
    cpu.esp -= 4;
    sub_47fb3c(app, cpu);
    if (cpu.terminate) return;
    // 0048cd17  b884cb4800             -mov eax, 0x48cb84
    cpu.eax = 4770692 /*0x48cb84*/;
    // 0048cd1c  e8fbe8ffff             -call 0x48b61c
    cpu.esp -= 4;
    sub_48b61c(app, cpu);
    if (cpu.terminate) return;
    // 0048cd21  833d94a64c0000         +cmp dword ptr [0x4ca694], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5023380) /* 0x4ca694 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048cd28  751a                   -jne 0x48cd44
    if (!cpu.flags.zf)
    {
        goto L_0x0048cd44;
    }
    // 0048cd2a  8b1534824c00           -mov edx, dword ptr [0x4c8234]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5014068) /* 0x4c8234 */);
    // 0048cd30  83c209                 -add edx, 9
    (cpu.edx) += x86::reg32(x86::sreg32(9 /*0x9*/));
    // 0048cd33  bf0a000000             -mov edi, 0xa
    cpu.edi = 10 /*0xa*/;
    // 0048cd38  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048cd3a  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0048cd3d  f7ff                   +idiv edi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.edi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0048cd3f  a394a64c00             -mov dword ptr [0x4ca694], eax
    app->getMemory<x86::reg32>(x86::reg32(5023380) /* 0x4ca694 */) = cpu.eax;
L_0x0048cd44:
    // 0048cd44  c705a0a64c0001000000   -mov dword ptr [0x4ca6a0], 1
    app->getMemory<x86::reg32>(x86::reg32(5023392) /* 0x4ca6a0 */) = 1 /*0x1*/;
    // 0048cd4e  e914ffffff             -jmp 0x48cc67
    goto L_0x0048cc67;
L_0x0048cd53:
    // 0048cd53  8b87f0605200           -mov eax, dword ptr [edi + 0x5260f0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5398768) /* 0x5260f0 */);
    // 0048cd59  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048cd5d  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048cd60  e8bbfdffff             -call 0x48cb20
    cpu.esp -= 4;
    sub_48cb20(app, cpu);
    if (cpu.terminate) return;
    // 0048cd65  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048cd67  0f8559ffffff           -jne 0x48ccc6
    if (!cpu.flags.zf)
    {
        goto L_0x0048ccc6;
    }
    // 0048cd6d  e974ffffff             -jmp 0x48cce6
    goto L_0x0048cce6;
L_0x0048cd72:
    // 0048cd72  b810615200             -mov eax, 0x526110
    cpu.eax = 5398800 /*0x526110*/;
    // 0048cd77  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0048cd79  e8122effff             -call 0x47fb90
    cpu.esp -= 4;
    sub_47fb90(app, cpu);
    if (cpu.terminate) return;
    // 0048cd7e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048cd80  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0048cd83  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cd84  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cd85  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cd86  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48cd8c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048cd8c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048cd8d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048cd8e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048cd8f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048cd91  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048cd93  b810615200             -mov eax, 0x526110
    cpu.eax = 5398800 /*0x526110*/;
    // 0048cd98  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048cd9a  e8c12fffff             -call 0x47fd60
    cpu.esp -= 4;
    sub_47fd60(app, cpu);
    if (cpu.terminate) return;
    // 0048cd9f  83f8ff                 +cmp eax, -1
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
    // 0048cda2  7506                   -jne 0x48cdaa
    if (!cpu.flags.zf)
    {
        goto L_0x0048cdaa;
    }
    // 0048cda4  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048cda6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cda7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cda8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cda9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048cdaa:
    // 0048cdaa  8b5904                 -mov ebx, dword ptr [ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0048cdad  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048cdaf  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0048cdb1  ff530c                 -call dword ptr [ebx + 0xc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048cdb4  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048cdb6  b810615200             -mov eax, 0x526110
    cpu.eax = 5398800 /*0x526110*/;
    // 0048cdbb  e8682fffff             -call 0x47fd28
    cpu.esp -= 4;
    sub_47fd28(app, cpu);
    if (cpu.terminate) return;
    // 0048cdc0  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048cdc2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cdc3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cdc4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cdc5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48cdc8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048cdc8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048cdc9  8b7004                 -mov esi, dword ptr [eax + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0048cdcc  ff5610                 -call dword ptr [esi + 0x10]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048cdcf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cdd0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48cdd4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048cdd4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048cdd5  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0048cdd8  ff5114                 -call dword ptr [ecx + 0x14]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048cddb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cddc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48cde0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048cde0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048cde1  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0048cde4  ff5118                 -call dword ptr [ecx + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048cde7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cde8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48cdec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048cdec  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048cded  8b7004                 -mov esi, dword ptr [eax + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0048cdf0  ff561c                 -call dword ptr [esi + 0x1c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048cdf3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cdf4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48cdf8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048cdf8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048cdf9  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0048cdfc  ff5120                 -call dword ptr [ecx + 0x20]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048cdff  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ce00  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48ce04(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048ce04  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048ce05  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0048ce08  ff5124                 -call dword ptr [ecx + 0x24]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048ce0b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ce0c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48ce10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048ce10  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048ce11  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0048ce14  ff5228                 -call dword ptr [edx + 0x28]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(40) /* 0x28 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048ce17  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ce18  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48ce1c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048ce1c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048ce1d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048ce1e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048ce20  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048ce22  b810615200             -mov eax, 0x526110
    cpu.eax = 5398800 /*0x526110*/;
    // 0048ce27  e8342fffff             -call 0x47fd60
    cpu.esp -= 4;
    sub_47fd60(app, cpu);
    if (cpu.terminate) return;
    // 0048ce2c  83f8ff                 +cmp eax, -1
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
    // 0048ce2f  7508                   -jne 0x48ce39
    if (!cpu.flags.zf)
    {
        goto L_0x0048ce39;
    }
    // 0048ce31  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048ce36  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ce37  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ce38  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048ce39:
    // 0048ce39  8b5104                 -mov edx, dword ptr [ecx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0048ce3c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048ce3e  ff522c                 -call dword ptr [edx + 0x2c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(44) /* 0x2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048ce41  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ce42  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ce43  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48ce44(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048ce44  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048ce45  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0048ce48  ff5130                 -call dword ptr [ecx + 0x30]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(48) /* 0x30 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048ce4b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ce4c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48ce50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048ce50  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048ce51  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0048ce54  ff5134                 -call dword ptr [ecx + 0x34]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(52) /* 0x34 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048ce57  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ce58  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48ce5c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048ce5c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048ce5d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048ce5e  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0048ce60  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048ce62  740a                   -je 0x48ce6e
    if (cpu.flags.zf)
    {
        goto L_0x0048ce6e;
    }
    // 0048ce64  c7404400000000         -mov dword ptr [eax + 0x44], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */) = 0 /*0x0*/;
    // 0048ce6b  894848                 -mov dword ptr [eax + 0x48], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */) = cpu.ecx;
L_0x0048ce6e:
    // 0048ce6e  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0048ce70  8b7e04                 -mov edi, dword ptr [esi + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0048ce73  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0048ce75  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048ce77  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048ce79  ff5738                 -call dword ptr [edi + 0x38]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(56) /* 0x38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048ce7c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ce7d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ce7e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48ce80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048ce80  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048ce81  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0048ce84  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0048ce87  ff513c                 -call dword ptr [ecx + 0x3c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(60) /* 0x3c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048ce8a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ce8b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48ce8c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048ce8c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048ce8d  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0048ce90  837e3800               +cmp dword ptr [esi + 0x38], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(56) /* 0x38 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048ce94  7504                   -jne 0x48ce9a
    if (!cpu.flags.zf)
    {
        goto L_0x0048ce9a;
    }
    // 0048ce96  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048ce98  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ce99  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048ce9a:
    // 0048ce9a  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0048ce9d  ff5638                 -call dword ptr [esi + 0x38]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(56) /* 0x38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048cea0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cea1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48cea4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048cea4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048cea5  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0048cea8  837a2400               +cmp dword ptr [edx + 0x24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048ceac  7504                   -jne 0x48ceb2
    if (!cpu.flags.zf)
    {
        goto L_0x0048ceb2;
    }
    // 0048ceae  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048ceb0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ceb1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048ceb2:
    // 0048ceb2  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0048ceb5  ff5224                 -call dword ptr [edx + 0x24]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048ceb8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ceb9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_48cec0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048cec0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048cec1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048cec2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048cec3  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048cec5  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0048cec7  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 0048cecc  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0048cecf  e87c38ffff             -call 0x480750
    cpu.esp -= 4;
    sub_480750(app, cpu);
    if (cpu.terminate) return;
    // 0048ced4  bb06000000             -mov ebx, 6
    cpu.ebx = 6 /*0x6*/;
    // 0048ced9  8d5104                 -lea edx, [ecx + 4]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0048cedc  8d4606                 -lea eax, [esi + 6]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 0048cedf  e86c38ffff             -call 0x480750
    cpu.esp -= 4;
    sub_480750(app, cpu);
    if (cpu.terminate) return;
    // 0048cee4  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0048cee9  8d510a                 -lea edx, [ecx + 0xa]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(10) /* 0xa */);
    // 0048ceec  8d460c                 -lea eax, [esi + 0xc]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0048ceef  e85c38ffff             -call 0x480750
    cpu.esp -= 4;
    sub_480750(app, cpu);
    if (cpu.terminate) return;
    // 0048cef4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cef5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cef6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cef7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48cef8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048cef8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048cef9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048cefa  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048cefb  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048cefd  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0048ceff  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 0048cf04  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0048cf07  e84438ffff             -call 0x480750
    cpu.esp -= 4;
    sub_480750(app, cpu);
    if (cpu.terminate) return;
    // 0048cf0c  bb06000000             -mov ebx, 6
    cpu.ebx = 6 /*0x6*/;
    // 0048cf11  8d5106                 -lea edx, [ecx + 6]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(6) /* 0x6 */);
    // 0048cf14  8d4604                 -lea eax, [esi + 4]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0048cf17  e83438ffff             -call 0x480750
    cpu.esp -= 4;
    sub_480750(app, cpu);
    if (cpu.terminate) return;
    // 0048cf1c  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0048cf21  8d510c                 -lea edx, [ecx + 0xc]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0048cf24  8d460a                 -lea eax, [esi + 0xa]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(10) /* 0xa */);
    // 0048cf27  e82438ffff             -call 0x480750
    cpu.esp -= 4;
    sub_480750(app, cpu);
    if (cpu.terminate) return;
    // 0048cf2c  66c7010600             -mov word ptr [ecx], 6
    app->getMemory<x86::reg16>(cpu.ecx) = 6 /*0x6*/;
    // 0048cf31  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cf32  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cf33  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cf34  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48cf38(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048cf38  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048cf39  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048cf3a  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048cf3d  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0048cf40  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0048cf42  8d4202                 -lea eax, [edx + 2]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0048cf45  66c7020600             -mov word ptr [edx], 6
    app->getMemory<x86::reg16>(cpu.edx) = 6 /*0x6*/;
    // 0048cf4a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048cf4c  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 0048cf51  e89021ffff             -call 0x47f0e6
    cpu.esp -= 4;
    sub_47f0e6(app, cpu);
    if (cpu.terminate) return;
    // 0048cf56  bbff000000             -mov ebx, 0xff
    cpu.ebx = 255 /*0xff*/;
    // 0048cf5b  ba06000000             -mov edx, 6
    cpu.edx = 6 /*0x6*/;
    // 0048cf60  8d4106                 -lea eax, [ecx + 6]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(6) /* 0x6 */);
    // 0048cf63  e87e21ffff             -call 0x47f0e6
    cpu.esp -= 4;
    sub_47f0e6(app, cpu);
    if (cpu.terminate) return;
    // 0048cf68  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0048cf6d  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0048cf6f  8d510c                 -lea edx, [ecx + 0xc]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0048cf72  e8d937ffff             -call 0x480750
    cpu.esp -= 4;
    sub_480750(app, cpu);
    if (cpu.terminate) return;
    // 0048cf77  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048cf7a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cf7b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cf7c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48cf80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048cf80  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048cf81  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048cf82  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048cf83  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048cf84  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048cf85  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0048cf88  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0048cf8a  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0048cf8c  ba0e000000             -mov edx, 0xe
    cpu.edx = 14 /*0xe*/;
    // 0048cf91  a14c8d4c00             -mov eax, dword ptr [0x4c8d4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5016908) /* 0x4c8d4c */);
    // 0048cf96  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0048cf9a  e86920ffff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 0048cf9f  8d442410               -lea eax, [esp + 0x10]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0048cfa3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048cfa4  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048cfa8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048cfa9  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048cfab  681c010000             -push 0x11c
    app->getMemory<x86::reg32>(cpu.esp-4) = 284 /*0x11c*/;
    cpu.esp -= 4;
    // 0048cfb0  8d5e24                 -lea ebx, [esi + 0x24]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 0048cfb3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048cfb4  8b4f34                 -mov ecx, dword ptr [edi + 0x34]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(52) /* 0x34 */);
    // 0048cfb7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048cfb8  e8db7d0200             -call 0x4b4d98
    cpu.esp -= 4;
    sub_4b4d98(app, cpu);
    if (cpu.terminate) return;
    // 0048cfbd  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0048cfc0  a14c8d4c00             -mov eax, dword ptr [0x4c8d4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5016908) /* 0x4c8d4c */);
    // 0048cfc5  e85620ffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 0048cfca  8b6e08                 -mov ebp, dword ptr [esi + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0048cfcd  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0048cfcf  7e47                   -jle 0x48d018
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048d018;
    }
    // 0048cfd1  807f0200               +cmp byte ptr [edi + 2], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048cfd5  754c                   -jne 0x48d023
    if (!cpu.flags.zf)
    {
        goto L_0x0048d023;
    }
L_0x0048cfd7:
    // 0048cfd7  a120b05100             -mov eax, dword ptr [0x51b020]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5353504) /* 0x51b020 */);
    // 0048cfdc  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0048cfe1  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0048cfe4  8d4624                 -lea eax, [esi + 0x24]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 0048cfe7  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048cfe9  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0048cfeb  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0048cfed  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0048cff4  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0048cff6  894620                 -mov dword ptr [esi + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0048cff9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048cffb  740d                   -je 0x48d00a
    if (cpu.flags.zf)
    {
        goto L_0x0048d00a;
    }
    // 0048cffd  837e0804               +cmp dword ptr [esi + 8], 4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048d001  7c07                   -jl 0x48d00a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048d00a;
    }
    // 0048d003  837c24100e             +cmp dword ptr [esp + 0x10], 0xe
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(14 /*0xe*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048d008  742a                   -je 0x48d034
    if (cpu.flags.zf)
    {
        goto L_0x0048d034;
    }
L_0x0048d00a:
    // 0048d00a  c7462000000000         -mov dword ptr [esi + 0x20], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 0048d011  c7460800000000         -mov dword ptr [esi + 8], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
L_0x0048d018:
    // 0048d018  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048d01a  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0048d01d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d01e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d01f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d020  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d021  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d022  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048d023:
    // 0048d023  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0048d025  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0048d027  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048d029  e8ba1f0100             -call 0x49efe8
    cpu.esp -= 4;
    sub_49efe8(app, cpu);
    if (cpu.terminate) return;
    // 0048d02e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048d030  74a5                   -je 0x48cfd7
    if (cpu.flags.zf)
    {
        goto L_0x0048cfd7;
    }
    // 0048d032  ebe4                   -jmp 0x48d018
    goto L_0x0048d018;
L_0x0048d034:
    // 0048d034  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0048d036  8d560c                 -lea edx, [esi + 0xc]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0048d039  e882feffff             -call 0x48cec0
    cpu.esp -= 4;
    sub_48cec0(app, cpu);
    if (cpu.terminate) return;
    // 0048d03e  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048d043  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0048d046  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d047  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d048  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d049  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d04a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d04b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48d04c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048d04c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048d04d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048d04e  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048d051  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0048d053  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0048d056  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0048d058  8d5002                 -lea edx, [eax + 2]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0048d05b  bb30000000             -mov ebx, 0x30
    cpu.ebx = 48 /*0x30*/;
    // 0048d060  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048d062  e83cd6ffff             -call 0x48a6a3
    cpu.esp -= 4;
    sub_48a6a3(app, cpu);
    if (cpu.terminate) return;
    // 0048d067  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048d069  7406                   -je 0x48d071
    if (cpu.flags.zf)
    {
        goto L_0x0048d071;
    }
    // 0048d06b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048d06e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d06f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d070  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048d071:
    // 0048d071  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048d072  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048d073  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 0048d075  bb767273ea             -mov ebx, 0xea737276
    cpu.ebx = 3933434486 /*0xea737276*/;
    // 0048d07a  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048d07c  49                     -dec ecx
    (cpu.ecx)--;
    // 0048d07d  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0048d07f  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0048d081  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0048d083  49                     -dec ecx
    (cpu.ecx)--;
    // 0048d084  41                     -inc ecx
    (cpu.ecx)++;
    // 0048d085  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048d089  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048d08a  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048d08c  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0048d08e  e8bd030000             -call 0x48d450
    cpu.esp -= 4;
    sub_48d450(app, cpu);
    if (cpu.terminate) return;
    // 0048d093  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d094  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d095  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048d098  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d099  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d09a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48d09c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048d09c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048d09d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048d09e  8b0d20b05100           -mov ecx, dword ptr [0x51b020]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5353504) /* 0x51b020 */);
    // 0048d0a4  83c110                 -add ecx, 0x10
    (cpu.ecx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0048d0a7  3b4804                 +cmp ecx, dword ptr [eax + 4]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048d0aa  7c07                   -jl 0x48d0b3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048d0b3;
    }
    // 0048d0ac  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 0048d0ae  3b4820                 +cmp ecx, dword ptr [eax + 0x20]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048d0b1  7408                   -je 0x48d0bb
    if (cpu.flags.zf)
    {
        goto L_0x0048d0bb;
    }
L_0x0048d0b3:
    // 0048d0b3  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048d0b8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d0b9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d0ba  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048d0bb:
    // 0048d0bb  8d580c                 -lea ebx, [eax + 0xc]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0048d0be  8d4204                 -lea eax, [edx + 4]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0048d0c1  8b4a18                 -mov ecx, dword ptr [edx + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 0048d0c4  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048d0c6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048d0c8  e8ff020000             -call 0x48d3cc
    cpu.esp -= 4;
    sub_48d3cc(app, cpu);
    if (cpu.terminate) return;
    // 0048d0cd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048d0cf  75e2                   -jne 0x48d0b3
    if (!cpu.flags.zf)
    {
        goto L_0x0048d0b3;
    }
    // 0048d0d1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d0d2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d0d3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48d0d4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048d0d4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048d0d5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048d0d6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048d0d7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048d0d8  8b4820                 -mov ecx, dword ptr [eax + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0048d0db  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 0048d0dd  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048d0df  39d9                   +cmp ecx, ebx
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
    // 0048d0e1  750e                   -jne 0x48d0f1
    if (!cpu.flags.zf)
    {
        goto L_0x0048d0f1;
    }
    // 0048d0e3  8b7a18                 -mov edi, dword ptr [edx + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 0048d0e6  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0048d0e8  7511                   -jne 0x48d0fb
    if (!cpu.flags.zf)
    {
        goto L_0x0048d0fb;
    }
L_0x0048d0ea:
    // 0048d0ea  c7460400000000         -mov dword ptr [esi + 4], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
L_0x0048d0f1:
    // 0048d0f1  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048d0f6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d0f7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d0f8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d0f9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d0fa  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048d0fb:
    // 0048d0fb  8d5a04                 -lea ebx, [edx + 4]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0048d0fe  8d500c                 -lea edx, [eax + 0xc]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0048d101  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048d103  e8c4020000             -call 0x48d3cc
    cpu.esp -= 4;
    sub_48d3cc(app, cpu);
    if (cpu.terminate) return;
    // 0048d108  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048d10a  75de                   -jne 0x48d0ea
    if (!cpu.flags.zf)
    {
        goto L_0x0048d0ea;
    }
    // 0048d10c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048d111  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d112  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d113  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d114  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d115  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48d118(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048d118  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048d119  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048d11a  81ec90010000           -sub esp, 0x190
    (cpu.esp) -= x86::reg32(x86::sreg32(400 /*0x190*/));
    // 0048d120  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0048d122  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048d123  6801010000             -push 0x101
    app->getMemory<x86::reg32>(cpu.esp-4) = 257 /*0x101*/;
    cpu.esp -= 4;
    // 0048d128  e8657c0200             -call 0x4b4d92
    cpu.esp -= 4;
    sub_4b4d92(app, cpu);
    if (cpu.terminate) return;
    // 0048d12d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048d12f  751f                   -jne 0x48d150
    if (!cpu.flags.zf)
    {
        goto L_0x0048d150;
    }
    // 0048d131  8b942488010000         -mov edx, dword ptr [esp + 0x188]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(392) /* 0x188 */);
    // 0048d138  6685d2                 +test dx, dx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.dx & cpu.dx));
    // 0048d13b  740c                   -je 0x48d149
    if (cpu.flags.zf)
    {
        goto L_0x0048d149;
    }
    // 0048d13d  6689d0                 -mov ax, dx
    cpu.ax = cpu.dx;
L_0x0048d140:
    // 0048d140  81c490010000           +add esp, 0x190
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(400 /*0x190*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048d146  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d147  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d148  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048d149:
    // 0048d149  b800200000             -mov eax, 0x2000
    cpu.eax = 8192 /*0x2000*/;
    // 0048d14e  ebf0                   -jmp 0x48d140
    goto L_0x0048d140;
L_0x0048d150:
    // 0048d150  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048d152  81c490010000           -add esp, 0x190
    (cpu.esp) += x86::reg32(x86::sreg32(400 /*0x190*/));
    // 0048d158  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d159  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d15a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48d15c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048d15c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048d15d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048d15e  e8297c0200             -call 0x4b4d8c
    cpu.esp -= 4;
    sub_4b4d8c(app, cpu);
    if (cpu.terminate) return;
    // 0048d163  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048d165  7508                   -jne 0x48d16f
    if (!cpu.flags.zf)
    {
        goto L_0x0048d16f;
    }
    // 0048d167  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048d16c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d16d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d16e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048d16f:
    // 0048d16f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048d171  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d172  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d173  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48d174(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048d174  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048d175  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048d176  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048d177  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048d178  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048d179  83ec1c                 -sub esp, 0x1c
    (cpu.esp) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0048d17c  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0048d180  bb00030000             -mov ebx, 0x300
    cpu.ebx = 768 /*0x300*/;
    // 0048d185  ba84400100             -mov edx, 0x14084
    cpu.edx = 82052 /*0x14084*/;
    // 0048d18a  b830ed4b00             -mov eax, 0x4bed30
    cpu.eax = 4975920 /*0x4bed30*/;
    // 0048d18f  e8d4b4feff             -call 0x478668
    cpu.esp -= 4;
    sub_478668(app, cpu);
    if (cpu.terminate) return;
    // 0048d194  ba84400100             -mov edx, 0x14084
    cpu.edx = 82052 /*0x14084*/;
    // 0048d199  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048d19b  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0048d19d  e83a1fffff             -call 0x47f0dc
    cpu.esp -= 4;
    sub_47f0dc(app, cpu);
    if (cpu.terminate) return;
    // 0048d1a2  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048d1a4  8d714c                 -lea esi, [ecx + 0x4c]
    cpu.esi = x86::reg32(cpu.ecx + x86::reg32(76) /* 0x4c */);
    // 0048d1a7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048d1a9  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048d1ab  e88c29ffff             -call 0x47fb3c
    cpu.esp -= 4;
    sub_47fb3c(app, cpu);
    if (cpu.terminate) return;
    // 0048d1b0  8d4168                 -lea eax, [ecx + 0x68]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(104) /* 0x68 */);
    // 0048d1b3  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048d1b5  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048d1b7  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0048d1b9  e87e29ffff             -call 0x47fb3c
    cpu.esp -= 4;
    sub_47fb3c(app, cpu);
    if (cpu.terminate) return;
    // 0048d1be  8d8184000000           -lea eax, [ecx + 0x84]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(132) /* 0x84 */);
    // 0048d1c4  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0048d1c6  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048d1c8  8db000400100           -lea esi, [eax + 0x14000]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(81920) /* 0x14000 */);
L_0x0048d1ce:
    // 0048d1ce  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0048d1d0  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048d1d2  81c140010000           -add ecx, 0x140
    (cpu.ecx) += x86::reg32(x86::sreg32(320 /*0x140*/));
    // 0048d1d8  e8b329ffff             -call 0x47fb90
    cpu.esp -= 4;
    sub_47fb90(app, cpu);
    if (cpu.terminate) return;
    // 0048d1dd  39f1                   +cmp ecx, esi
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
    // 0048d1df  75ed                   -jne 0x48d1ce
    if (!cpu.flags.zf)
    {
        goto L_0x0048d1ce;
    }
    // 0048d1e1  68e8030000             -push 0x3e8
    app->getMemory<x86::reg32>(cpu.esp-4) = 1000 /*0x3e8*/;
    cpu.esp -= 4;
    // 0048d1e6  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0048d1e8  6a06                   -push 6
    app->getMemory<x86::reg32>(cpu.esp-4) = 6 /*0x6*/;
    cpu.esp -= 4;
    // 0048d1ea  e8977b0200             -call 0x4b4d86
    cpu.esp -= 4;
    sub_4b4d86(app, cpu);
    if (cpu.terminate) return;
    // 0048d1ef  894734                 -mov dword ptr [edi + 0x34], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 0048d1f2  83f8ff                 +cmp eax, -1
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
    // 0048d1f5  7526                   -jne 0x48d21d
    if (!cpu.flags.zf)
    {
        goto L_0x0048d21d;
    }
L_0x0048d1f7:
    // 0048d1f7  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0048d1f9  7517                   -jne 0x48d212
    if (!cpu.flags.zf)
    {
        goto L_0x0048d212;
    }
    // 0048d1fb  8b5734                 -mov edx, dword ptr [edi + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(52) /* 0x34 */);
    // 0048d1fe  83faff                 +cmp edx, -1
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
    // 0048d201  7406                   -je 0x48d209
    if (cpu.flags.zf)
    {
        goto L_0x0048d209;
    }
    // 0048d203  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048d204  e8777b0200             -call 0x4b4d80
    cpu.esp -= 4;
    sub_4b4d80(app, cpu);
    if (cpu.terminate) return;
L_0x0048d209:
    // 0048d209  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048d20b  e8bcb8feff             -call 0x478acc
    cpu.esp -= 4;
    sub_478acc(app, cpu);
    if (cpu.terminate) return;
    // 0048d210  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x0048d212:
    // 0048d212  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048d214  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0048d217  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d218  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d219  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d21a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d21b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d21c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048d21d:
    // 0048d21d  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0048d21f  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0048d223  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048d224  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0048d229  6a20                   -push 0x20
    app->getMemory<x86::reg32>(cpu.esp-4) = 32 /*0x20*/;
    cpu.esp -= 4;
    // 0048d22b  894c241c               -mov dword ptr [esp + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 0048d22f  68ffff0000             -push 0xffff
    app->getMemory<x86::reg32>(cpu.esp-4) = 65535 /*0xffff*/;
    cpu.esp -= 4;
    // 0048d234  8b5f34                 -mov ebx, dword ptr [edi + 0x34]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(52) /* 0x34 */);
    // 0048d237  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048d238  e83d7b0200             -call 0x4b4d7a
    cpu.esp -= 4;
    sub_4b4d7a(app, cpu);
    if (cpu.terminate) return;
    // 0048d23d  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0048d23f  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0048d243  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048d244  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0048d246  6800400000             -push 0x4000
    app->getMemory<x86::reg32>(cpu.esp-4) = 16384 /*0x4000*/;
    cpu.esp -= 4;
    // 0048d24b  8974241c               -mov dword ptr [esp + 0x1c], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.esi;
    // 0048d24f  68ffff0000             -push 0xffff
    app->getMemory<x86::reg32>(cpu.esp-4) = 65535 /*0xffff*/;
    cpu.esp -= 4;
    // 0048d254  8b4734                 -mov eax, dword ptr [edi + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(52) /* 0x34 */);
    // 0048d257  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048d258  e81d7b0200             -call 0x4b4d7a
    cpu.esp -= 4;
    sub_4b4d7a(app, cpu);
    if (cpu.terminate) return;
    // 0048d25d  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0048d25f  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0048d263  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048d264  6801400000             -push 0x4001
    app->getMemory<x86::reg32>(cpu.esp-4) = 16385 /*0x4001*/;
    cpu.esp -= 4;
    // 0048d269  8974241c               -mov dword ptr [esp + 0x1c], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.esi;
    // 0048d26d  68ffff0000             -push 0xffff
    app->getMemory<x86::reg32>(cpu.esp-4) = 65535 /*0xffff*/;
    cpu.esp -= 4;
    // 0048d272  8b4f34                 -mov ecx, dword ptr [edi + 0x34]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(52) /* 0x34 */);
    // 0048d275  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048d276  e8ff7a0200             -call 0x4b4d7a
    cpu.esp -= 4;
    sub_4b4d7a(app, cpu);
    if (cpu.terminate) return;
    // 0048d27b  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0048d27d  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0048d281  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048d282  680f400000             -push 0x400f
    app->getMemory<x86::reg32>(cpu.esp-4) = 16399 /*0x400f*/;
    cpu.esp -= 4;
    // 0048d287  8974241c               -mov dword ptr [esp + 0x1c], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.esi;
    // 0048d28b  68ffff0000             -push 0xffff
    app->getMemory<x86::reg32>(cpu.esp-4) = 65535 /*0xffff*/;
    cpu.esp -= 4;
    // 0048d290  8b7734                 -mov esi, dword ptr [edi + 0x34]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(52) /* 0x34 */);
    // 0048d293  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048d294  e8e17a0200             -call 0x4b4d7a
    cpu.esp -= 4;
    sub_4b4d7a(app, cpu);
    if (cpu.terminate) return;
    // 0048d299  c744241001000000       -mov dword ptr [esp + 0x10], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = 1 /*0x1*/;
    // 0048d2a1  8d442410               -lea eax, [esp + 0x10]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0048d2a5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048d2a6  687e660480             -push 0x8004667e
    app->getMemory<x86::reg32>(cpu.esp-4) = 2147772030 /*0x8004667e*/;
    cpu.esp -= 4;
    // 0048d2ab  8b5734                 -mov edx, dword ptr [edi + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(52) /* 0x34 */);
    // 0048d2ae  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048d2af  e8c07a0200             -call 0x4b4d74
    cpu.esp -= 4;
    sub_4b4d74(app, cpu);
    if (cpu.terminate) return;
    // 0048d2b4  ba0e000000             -mov edx, 0xe
    cpu.edx = 14 /*0xe*/;
    // 0048d2b9  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0048d2bb  e81c1effff             -call 0x47f0dc
    cpu.esp -= 4;
    sub_47f0dc(app, cpu);
    if (cpu.terminate) return;
    // 0048d2c0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048d2c2  668b442418             -mov ax, word ptr [esp + 0x18]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0048d2c7  ba06000000             -mov edx, 6
    cpu.edx = 6 /*0x6*/;
    // 0048d2cc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048d2cd  6689542404             -mov word ptr [esp + 4], dx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.dx;
    // 0048d2d2  e8977a0200             -call 0x4b4d6e
    cpu.esp -= 4;
    sub_4b4d6e(app, cpu);
    if (cpu.terminate) return;
    // 0048d2d7  6a0e                   -push 0xe
    app->getMemory<x86::reg32>(cpu.esp-4) = 14 /*0xe*/;
    cpu.esp -= 4;
    // 0048d2d9  6689442410             -mov word ptr [esp + 0x10], ax
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ax;
    // 0048d2de  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048d2e2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048d2e3  8b4f34                 -mov ecx, dword ptr [edi + 0x34]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(52) /* 0x34 */);
    // 0048d2e6  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048d2e7  e87c7a0200             -call 0x4b4d68
    cpu.esp -= 4;
    sub_4b4d68(app, cpu);
    if (cpu.terminate) return;
    // 0048d2ec  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048d2ee  0f8503ffffff           -jne 0x48d1f7
    if (!cpu.flags.zf)
    {
        goto L_0x0048d1f7;
    }
    // 0048d2f4  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0048d2f8  bb0e000000             -mov ebx, 0xe
    cpu.ebx = 14 /*0xe*/;
    // 0048d2fd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048d2fe  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048d302  895c2418               -mov dword ptr [esp + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 0048d306  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048d307  8b7734                 -mov esi, dword ptr [edi + 0x34]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(52) /* 0x34 */);
    // 0048d30a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048d30b  e8527a0200             -call 0x4b4d62
    cpu.esp -= 4;
    sub_4b4d62(app, cpu);
    if (cpu.terminate) return;
    // 0048d310  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048d312  0f85dffeffff           -jne 0x48d1f7
    if (!cpu.flags.zf)
    {
        goto L_0x0048d1f7;
    }
    // 0048d318  3b5c2414               +cmp ebx, dword ptr [esp + 0x14]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048d31c  0f85d5feffff           -jne 0x48d1f7
    if (!cpu.flags.zf)
    {
        goto L_0x0048d1f7;
    }
    // 0048d322  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0048d324  8d5738                 -lea edx, [edi + 0x38]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(56) /* 0x38 */);
    // 0048d327  e894fbffff             -call 0x48cec0
    cpu.esp -= 4;
    sub_48cec0(app, cpu);
    if (cpu.terminate) return;
    // 0048d32c  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048d330  668907                 -mov word ptr [edi], ax
    app->getMemory<x86::reg16>(cpu.edi) = cpu.ax;
    // 0048d333  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048d335  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0048d338  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d339  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d33a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d33b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d33c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d33d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48d340(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048d340  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048d341  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048d342  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048d343  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048d345  8b5034                 -mov edx, dword ptr [eax + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    // 0048d348  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048d349  e8327a0200             -call 0x4b4d80
    cpu.esp -= 4;
    sub_4b4d80(app, cpu);
    if (cpu.terminate) return;
    // 0048d34e  8d434c                 -lea eax, [ebx + 0x4c]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(76) /* 0x4c */);
    // 0048d351  e82628ffff             -call 0x47fb7c
    cpu.esp -= 4;
    sub_47fb7c(app, cpu);
    if (cpu.terminate) return;
    // 0048d356  8d4368                 -lea eax, [ebx + 0x68]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(104) /* 0x68 */);
    // 0048d359  e81e28ffff             -call 0x47fb7c
    cpu.esp -= 4;
    sub_47fb7c(app, cpu);
    if (cpu.terminate) return;
    // 0048d35e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048d360  e867b7feff             -call 0x478acc
    cpu.esp -= 4;
    sub_478acc(app, cpu);
    if (cpu.terminate) return;
    // 0048d365  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048d36a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d36b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d36c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d36d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48d370(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048d370  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048d371  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0048d376  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048d378  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0048d37a  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0048d37c  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0048d383  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0048d385  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d386  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48d388(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048d388  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048d389  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048d38a  8d4838                 -lea ecx, [eax + 0x38]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(56) /* 0x38 */);
    // 0048d38d  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0048d38f  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0048d391  e8fa1f0100             -call 0x49f390
    cpu.esp -= 4;
    sub_49f390(app, cpu);
    if (cpu.terminate) return;
    // 0048d396  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d397  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d398  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48d39c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048d39c  e9e3200100             -jmp 0x49f484
    return sub_49f484(app, cpu);
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48d3a4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048d3a4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048d3a5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048d3a6  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048d3a8  bb30000000             -mov ebx, 0x30
    cpu.ebx = 48 /*0x30*/;
    // 0048d3ad  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0048d3b0  e847d0feff             -call 0x47a3fc
    cpu.esp -= 4;
    sub_47a3fc(app, cpu);
    if (cpu.terminate) return;
    // 0048d3b5  8b4134                 -mov eax, dword ptr [ecx + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(52) /* 0x34 */);
    // 0048d3b8  e8731b0100             -call 0x49ef30
    cpu.esp -= 4;
    sub_49ef30(app, cpu);
    if (cpu.terminate) return;
    // 0048d3bd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d3be  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d3bf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48d3c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048d3c0  c6400200               -mov byte ptr [eax + 2], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */) = 0 /*0x0*/;
    // 0048d3c4  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048d3c9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48d3cc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048d3cc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048d3cd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048d3ce  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048d3cf  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 0048d3d4  8d7b04                 -lea edi, [ebx + 4]
    cpu.edi = x86::reg32(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0048d3d7  8d7204                 -lea esi, [edx + 4]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0048d3da  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0048d3dc  f3a6                   +repe cmpsb byte ptr [esi], byte ptr es:[edi]
    while (cpu.ecx)
    {
        {
            x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi);
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
    // 0048d3de  7405                   -je 0x48d3e5
    if (cpu.flags.zf)
    {
        goto L_0x0048d3e5;
    }
    // 0048d3e0  19c0                   +sbb eax, eax
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
    // 0048d3e2  83d8ff                 -sbb eax, -1
    (cpu.eax) -= x86::reg32(x86::sreg32(-1 /*-0x1*/) + cpu.flags.cf);
L_0x0048d3e5:
    // 0048d3e5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048d3e7  7509                   -jne 0x48d3f2
    if (!cpu.flags.zf)
    {
        goto L_0x0048d3f2;
    }
    // 0048d3e9  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048d3ee  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d3ef  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d3f0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d3f1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048d3f2:
    // 0048d3f2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048d3f4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d3f5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d3f6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d3f7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48d3f8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048d3f8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048d3f9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048d3fa  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0048d3fc  8d7038                 -lea esi, [eax + 0x38]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(56) /* 0x38 */);
    // 0048d3ff  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048d404  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048d405  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048d406  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048d407  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048d408  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048d409  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d40a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d40b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48d40c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048d40c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048d40d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048d40e  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048d411  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048d413  83c068                 -add eax, 0x68
    (cpu.eax) += x86::reg32(x86::sreg32(104 /*0x68*/));
    // 0048d416  e84129ffff             -call 0x47fd5c
    cpu.esp -= 4;
    sub_47fd5c(app, cpu);
    if (cpu.terminate) return;
    // 0048d41b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048d41d  760b                   -jbe 0x48d42a
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0048d42a;
    }
L_0x0048d41f:
    // 0048d41f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048d424  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048d427  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d428  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d429  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048d42a:
    // 0048d42a  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0048d42c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048d42d  687f660440             -push 0x4004667f
    app->getMemory<x86::reg32>(cpu.esp-4) = 1074030207 /*0x4004667f*/;
    cpu.esp -= 4;
    // 0048d432  8b4a34                 -mov ecx, dword ptr [edx + 0x34]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(52) /* 0x34 */);
    // 0048d435  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048d436  e839790200             -call 0x4b4d74
    cpu.esp -= 4;
    sub_4b4d74(app, cpu);
    if (cpu.terminate) return;
    // 0048d43b  83f8ff                 +cmp eax, -1
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
    // 0048d43e  7406                   -je 0x48d446
    if (cpu.flags.zf)
    {
        goto L_0x0048d446;
    }
    // 0048d440  833c2400               +cmp dword ptr [esp], 0
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
    // 0048d444  77d9                   -ja 0x48d41f
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0048d41f;
    }
L_0x0048d446:
    // 0048d446  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048d448  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048d44b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d44c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d44d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48d450(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048d450  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048d451  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048d452  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048d453  81ec2c010000           -sub esp, 0x12c
    (cpu.esp) -= x86::reg32(x86::sreg32(300 /*0x12c*/));
    // 0048d459  8bac243c010000         -mov ebp, dword ptr [esp + 0x13c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(316) /* 0x13c */);
    // 0048d460  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0048d462  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0048d464  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0048d466  81fd18010000           +cmp ebp, 0x118
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(280 /*0x118*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048d46c  7e05                   -jle 0x48d473
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048d473;
    }
    // 0048d46e  bd18010000             -mov ebp, 0x118
    cpu.ebp = 280 /*0x118*/;
L_0x0048d473:
    // 0048d473  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 0048d478  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0048d47a  e8118a0000             -call 0x495e90
    cpu.esp -= 4;
    sub_495e90(app, cpu);
    if (cpu.terminate) return;
    // 0048d47f  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048d483  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0048d485  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048d487  e8c432ffff             -call 0x480750
    cpu.esp -= 4;
    sub_480750(app, cpu);
    if (cpu.terminate) return;
    // 0048d48c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0048d48e  7457                   -je 0x48d4e7
    if (cpu.flags.zf)
    {
        goto L_0x0048d4e7;
    }
    // 0048d490  8d94241c010000         -lea edx, [esp + 0x11c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(284) /* 0x11c */);
    // 0048d497  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048d499  e85afaffff             -call 0x48cef8
    cpu.esp -= 4;
    sub_48cef8(app, cpu);
    if (cpu.terminate) return;
L_0x0048d49e:
    // 0048d49e  a14c8d4c00             -mov eax, dword ptr [0x4c8d4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5016908) /* 0x4c8d4c */);
    // 0048d4a3  e8601bffff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 0048d4a8  6a0e                   -push 0xe
    app->getMemory<x86::reg32>(cpu.esp-4) = 14 /*0xe*/;
    cpu.esp -= 4;
    // 0048d4aa  8d842420010000         -lea eax, [esp + 0x120]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(288) /* 0x120 */);
    // 0048d4b1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048d4b2  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048d4b4  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048d4b7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048d4b8  8d442410               -lea eax, [esp + 0x10]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0048d4bc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048d4bd  8b5734                 -mov edx, dword ptr [edi + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(52) /* 0x34 */);
    // 0048d4c0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048d4c1  e896780200             -call 0x4b4d5c
    cpu.esp -= 4;
    sub_4b4d5c(app, cpu);
    if (cpu.terminate) return;
    // 0048d4c6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048d4c8  a14c8d4c00             -mov eax, dword ptr [0x4c8d4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5016908) /* 0x4c8d4c */);
    // 0048d4cd  e84e1bffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 0048d4d2  39ea                   +cmp edx, ebp
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
    // 0048d4d4  7522                   -jne 0x48d4f8
    if (!cpu.flags.zf)
    {
        goto L_0x0048d4f8;
    }
    // 0048d4d6  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048d4db  81c42c010000           +add esp, 0x12c
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(300 /*0x12c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048d4e1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d4e2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d4e3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d4e4  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0048d4e7:
    // 0048d4e7  8d94241c010000         -lea edx, [esp + 0x11c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(284) /* 0x11c */);
    // 0048d4ee  0fbf07                 -movsx eax, word ptr [edi]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.edi)));
    // 0048d4f1  e842faffff             -call 0x48cf38
    cpu.esp -= 4;
    sub_48cf38(app, cpu);
    if (cpu.terminate) return;
    // 0048d4f6  eba6                   -jmp 0x48d49e
    goto L_0x0048d49e;
L_0x0048d4f8:
    // 0048d4f8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048d4fa  81c42c010000           -add esp, 0x12c
    (cpu.esp) += x86::reg32(x86::sreg32(300 /*0x12c*/));
    // 0048d500  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d501  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d502  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d503  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48d508(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048d508  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048d509  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048d50a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048d50b  83ec2c                 -sub esp, 0x2c
    (cpu.esp) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 0048d50e  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0048d510  89542420               -mov dword ptr [esp + 0x20], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 0048d514  895c2424               -mov dword ptr [esp + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 0048d518  894c241c               -mov dword ptr [esp + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 0048d51c  8d584c                 -lea ebx, [eax + 0x4c]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(76) /* 0x4c */);
    // 0048d51f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048d521  e8e626ffff             -call 0x47fc0c
    cpu.esp -= 4;
    sub_47fc0c(app, cpu);
    if (cpu.terminate) return;
    // 0048d526  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048d528  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048d52a  742a                   -je 0x48d556
    if (cpu.flags.zf)
    {
        goto L_0x0048d556;
    }
    // 0048d52c  8d7568                 -lea esi, [ebp + 0x68]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(104) /* 0x68 */);
L_0x0048d52f:
    // 0048d52f  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0048d531  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048d533  e848faffff             -call 0x48cf80
    cpu.esp -= 4;
    sub_48cf80(app, cpu);
    if (cpu.terminate) return;
    // 0048d538  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048d53a  0f84b8000000           -je 0x48d5f8
    if (cpu.flags.zf)
    {
        goto L_0x0048d5f8;
    }
    // 0048d540  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0048d542  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048d544  e87b26ffff             -call 0x47fbc4
    cpu.esp -= 4;
    sub_47fbc4(app, cpu);
    if (cpu.terminate) return;
    // 0048d549  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048d54b  e8bc26ffff             -call 0x47fc0c
    cpu.esp -= 4;
    sub_47fc0c(app, cpu);
    if (cpu.terminate) return;
    // 0048d550  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048d552  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048d554  75d9                   -jne 0x48d52f
    if (!cpu.flags.zf)
    {
        goto L_0x0048d52f;
    }
L_0x0048d556:
    // 0048d556  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0048d55a  8d7c2404               -lea edi, [esp + 4]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048d55e  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048d560  8b742420               -mov esi, dword ptr [esp + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0048d564  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0048d567  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048d568  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048d569  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048d56a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048d56b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048d56c  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0048d56e  896c2418               -mov dword ptr [esp + 0x18], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ebp;
    // 0048d572  8d7d68                 -lea edi, [ebp + 0x68]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(104) /* 0x68 */);
    // 0048d575  ba9cd04800             -mov edx, 0x48d09c
    cpu.edx = 4771996 /*0x48d09c*/;
    // 0048d57a  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048d57c  e89f29ffff             -call 0x47ff20
    cpu.esp -= 4;
    sub_47ff20(app, cpu);
    if (cpu.terminate) return;
    // 0048d581  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048d583  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048d585  0f84a8000000           -je 0x48d633
    if (cpu.flags.zf)
    {
        goto L_0x0048d633;
    }
    // 0048d58b  8d754c                 -lea esi, [ebp + 0x4c]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(76) /* 0x4c */);
L_0x0048d58e:
    // 0048d58e  a120b05100             -mov eax, dword ptr [0x51b020]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5353504) /* 0x51b020 */);
    // 0048d593  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0048d596  3b4104                 +cmp eax, dword ptr [ecx + 4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048d599  0f8c73000000           -jl 0x48d612
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048d612;
    }
    // 0048d59f  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0048d5a2  83e804                 -sub eax, 4
    (cpu.eax) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048d5a5  8b5c243c               -mov ebx, dword ptr [esp + 0x3c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0048d5a9  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 0048d5ad  39d8                   +cmp eax, ebx
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
    // 0048d5af  7e55                   -jle 0x48d606
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048d606;
    }
    // 0048d5b1  895c2428               -mov dword ptr [esp + 0x28], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ebx;
L_0x0048d5b5:
    // 0048d5b5  8b7c2420               -mov edi, dword ptr [esp + 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0048d5b9  8d710c                 -lea esi, [ecx + 0xc]
    cpu.esi = x86::reg32(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0048d5bc  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048d5bd  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048d5be  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048d5bf  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048d5c0  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048d5c1  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0048d5c5  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 0048d5c8  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 0048d5ca  837c242800             +cmp dword ptr [esp + 0x28], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048d5cf  7410                   -je 0x48d5e1
    if (cpu.flags.zf)
    {
        goto L_0x0048d5e1;
    }
    // 0048d5d1  8b5c2428               -mov ebx, dword ptr [esp + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0048d5d5  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0048d5d9  8d4128                 -lea eax, [ecx + 0x28]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(40) /* 0x28 */);
    // 0048d5dc  e86f31ffff             -call 0x480750
    cpu.esp -= 4;
    sub_480750(app, cpu);
    if (cpu.terminate) return;
L_0x0048d5e1:
    // 0048d5e1  8d454c                 -lea eax, [ebp + 0x4c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(76) /* 0x4c */);
    // 0048d5e4  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0048d5e6  e8a525ffff             -call 0x47fb90
    cpu.esp -= 4;
    sub_47fb90(app, cpu);
    if (cpu.terminate) return;
    // 0048d5eb  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0048d5ef  83c42c                 +add esp, 0x2c
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(44 /*0x2c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048d5f2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d5f3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d5f4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d5f5  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0048d5f8:
    // 0048d5f8  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0048d5fa  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048d5fc  e88f25ffff             -call 0x47fb90
    cpu.esp -= 4;
    sub_47fb90(app, cpu);
    if (cpu.terminate) return;
    // 0048d601  e950ffffff             -jmp 0x48d556
    goto L_0x0048d556;
L_0x0048d606:
    // 0048d606  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048d608  7dab                   -jge 0x48d5b5
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048d5b5;
    }
    // 0048d60a  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 0048d60c  897c2428               -mov dword ptr [esp + 0x28], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edi;
    // 0048d610  eba3                   -jmp 0x48d5b5
    goto L_0x0048d5b5;
L_0x0048d612:
    // 0048d612  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0048d614  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048d616  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0048d618  e87325ffff             -call 0x47fb90
    cpu.esp -= 4;
    sub_47fb90(app, cpu);
    if (cpu.terminate) return;
    // 0048d61d  ba9cd04800             -mov edx, 0x48d09c
    cpu.edx = 4771996 /*0x48d09c*/;
    // 0048d622  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048d624  e8f728ffff             -call 0x47ff20
    cpu.esp -= 4;
    sub_47ff20(app, cpu);
    if (cpu.terminate) return;
    // 0048d629  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048d62b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048d62d  0f855bffffff           -jne 0x48d58e
    if (!cpu.flags.zf)
    {
        goto L_0x0048d58e;
    }
L_0x0048d633:
    // 0048d633  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0048d637  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 0048d63d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048d63f  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 0048d642  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d643  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d644  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d645  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_48d648(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048d648  83ec1c                 -sub esp, 0x1c
    (cpu.esp) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0048d64b  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0048d64e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048d650  742b                   -je 0x48d67d
    if (cpu.flags.zf)
    {
        goto L_0x0048d67d;
    }
    // 0048d652  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048d653  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048d654  8d7c240c               -lea edi, [esp + 0xc]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048d658  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0048d65a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048d65b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048d65c  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048d65d  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048d65e  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048d65f  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0048d663  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d664  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0048d665:
    // 0048d665  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0048d667  bad4d04800             -mov edx, 0x48d0d4
    cpu.edx = 4772052 /*0x48d0d4*/;
    // 0048d66c  83c068                 -add eax, 0x68
    (cpu.eax) += x86::reg32(x86::sreg32(104 /*0x68*/));
    // 0048d66f  e8982affff             -call 0x48010c
    cpu.esp -= 4;
    sub_48010c(app, cpu);
    if (cpu.terminate) return;
    // 0048d674  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048d679  83c41c                 +add esp, 0x1c
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(28 /*0x1c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048d67c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048d67d:
    // 0048d67d  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 0048d681  ebe2                   -jmp 0x48d665
    goto L_0x0048d665;
}

/* align: skip 0x90 */
void Application::sub_48d684(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048d684  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048d685  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048d686  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048d687  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048d688  81ec90010000           -sub esp, 0x190
    (cpu.esp) -= x86::reg32(x86::sreg32(400 /*0x190*/));
    // 0048d68e  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048d690  833d00a74c0000         +cmp dword ptr [0x4ca700], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5023488) /* 0x4ca700 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048d697  7410                   -je 0x48d6a9
    if (cpu.flags.zf)
    {
        goto L_0x0048d6a9;
    }
L_0x0048d699:
    // 0048d699  a100a74c00             -mov eax, dword ptr [0x4ca700]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023488) /* 0x4ca700 */);
    // 0048d69e  81c490010000           -add esp, 0x190
    (cpu.esp) += x86::reg32(x86::sreg32(400 /*0x190*/));
    // 0048d6a4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d6a5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d6a6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d6a7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d6a8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048d6a9:
    // 0048d6a9  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0048d6ab  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048d6ac  6801010000             -push 0x101
    app->getMemory<x86::reg32>(cpu.esp-4) = 257 /*0x101*/;
    cpu.esp -= 4;
    // 0048d6b1  e8dc760200             -call 0x4b4d92
    cpu.esp -= 4;
    sub_4b4d92(app, cpu);
    if (cpu.terminate) return;
    // 0048d6b6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048d6b8  75df                   -jne 0x48d699
    if (!cpu.flags.zf)
    {
        goto L_0x0048d699;
    }
    // 0048d6ba  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048d6bb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048d6bc  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048d6be  e8b1faffff             -call 0x48d174
    cpu.esp -= 4;
    sub_48d174(app, cpu);
    if (cpu.terminate) return;
    // 0048d6c3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048d6c5  7440                   -je 0x48d707
    if (cpu.flags.zf)
    {
        goto L_0x0048d707;
    }
    // 0048d6c7  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0048d6cc  bea4a64c00             -mov esi, 0x4ca6a4
    cpu.esi = 5023396 /*0x4ca6a4*/;
    // 0048d6d1  890d00a74c00           -mov dword ptr [0x4ca700], ecx
    app->getMemory<x86::reg32>(x86::reg32(5023488) /* 0x4ca700 */) = cpu.ecx;
    // 0048d6d7  e864fcffff             -call 0x48d340
    cpu.esp -= 4;
    sub_48d340(app, cpu);
    if (cpu.terminate) return;
    // 0048d6dc  a19ca64c00             -mov eax, dword ptr [0x4ca69c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023388) /* 0x4ca69c */);
    // 0048d6e1  bf94ca4c00             -mov edi, 0x4cca94
    cpu.edi = 5032596 /*0x4cca94*/;
    // 0048d6e6  8d2c08                 -lea ebp, [eax + ecx]
    cpu.ebp = x86::reg32(cpu.eax + cpu.ecx * 1);
    // 0048d6e9  893485f0605200         -mov dword ptr [eax*4 + 0x5260f0], esi
    app->getMemory<x86::reg32>(x86::reg32(5398768) /* 0x5260f0 */ + cpu.eax * 4) = cpu.esi;
    // 0048d6f0  893c85d0605200         -mov dword ptr [eax*4 + 0x5260d0], edi
    app->getMemory<x86::reg32>(x86::reg32(5398736) /* 0x5260d0 */ + cpu.eax * 4) = cpu.edi;
    // 0048d6f7  892d9ca64c00           -mov dword ptr [0x4ca69c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5023388) /* 0x4ca69c */) = cpu.ebp;
    // 0048d6fd  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0048d6ff  7406                   -je 0x48d707
    if (cpu.flags.zf)
    {
        goto L_0x0048d707;
    }
    // 0048d701  891da4a64c00           -mov dword ptr [0x4ca6a4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5023396) /* 0x4ca6a4 */) = cpu.ebx;
L_0x0048d707:
    // 0048d707  e880760200             -call 0x4b4d8c
    cpu.esp -= 4;
    sub_4b4d8c(app, cpu);
    if (cpu.terminate) return;
    // 0048d70c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d70d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d70e  a100a74c00             -mov eax, dword ptr [0x4ca700]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023488) /* 0x4ca700 */);
    // 0048d713  81c490010000           -add esp, 0x190
    (cpu.esp) += x86::reg32(x86::sreg32(400 /*0x190*/));
    // 0048d719  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d71a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d71b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d71c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d71d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_48d720(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048d720  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048d721  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048d722  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048d723  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048d724  81ec80000000           -sub esp, 0x80
    (cpu.esp) -= x86::reg32(x86::sreg32(128 /*0x80*/));
    // 0048d72a  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0048d72c  8954247c               -mov dword ptr [esp + 0x7c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(124) /* 0x7c */) = cpu.edx;
    // 0048d730  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0048d732  ff0540824c00           -inc dword ptr [0x4c8240]
    (app->getMemory<x86::reg32>(x86::reg32(5014080) /* 0x4c8240 */))++;
    // 0048d738  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048d73a  7505                   -jne 0x48d741
    if (!cpu.flags.zf)
    {
        goto L_0x0048d741;
    }
    // 0048d73c  bd30b15100             -mov ebp, 0x51b130
    cpu.ebp = 5353776 /*0x51b130*/;
L_0x0048d741:
    // 0048d741  833dc4814c0007         +cmp dword ptr [0x4c81c4], 7
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5013956) /* 0x4c81c4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048d748  0f8525010000           -jne 0x48d873
    if (!cpu.flags.zf)
    {
        goto L_0x0048d873;
    }
    // 0048d74e  837d1c08               +cmp dword ptr [ebp + 0x1c], 8
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048d752  0f8f1b010000           -jg 0x48d873
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048d873;
    }
    // 0048d758  8b44247c               -mov eax, dword ptr [esp + 0x7c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 0048d75c  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0048d75e  48                     -dec eax
    (cpu.eax)--;
    // 0048d75f  8bbd3c040000           -mov edi, dword ptr [ebp + 0x43c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(1084) /* 0x43c */);
    // 0048d765  89442478               -mov dword ptr [esp + 0x78], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */) = cpu.eax;
    // 0048d769  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0048d76b  0f840d010000           -je 0x48d87e
    if (cpu.flags.zf)
    {
        goto L_0x0048d87e;
    }
    // 0048d771  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0048d776:
    // 0048d776  89442470               -mov dword ptr [esp + 0x70], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */) = cpu.eax;
    // 0048d77a  8b44247c               -mov eax, dword ptr [esp + 0x7c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 0048d77e  8d5530                 -lea edx, [ebp + 0x30]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(48) /* 0x30 */);
    // 0048d781  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0048d784  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048d786  8d1c02                 -lea ebx, [edx + eax]
    cpu.ebx = x86::reg32(cpu.edx + cpu.eax * 1);
    // 0048d789  05a07b5200             -add eax, 0x527ba0
    (cpu.eax) += x86::reg32(x86::sreg32(5405600 /*0x527ba0*/));
    // 0048d78e  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0048d790  7e2a                   -jle 0x48d7bc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048d7bc;
    }
    // 0048d792  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
L_0x0048d794:
    // 0048d794  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048d796  8a5801                 -mov bl, byte ptr [eax + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0048d799  0fb67802               -movzx edi, byte ptr [eax + 2]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */));
    // 0048d79d  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 0048d7a0  09df                   -or edi, ebx
    cpu.edi |= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048d7a2  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048d7a4  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 0048d7a6  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048d7a9  c1e310                 -shl ebx, 0x10
    cpu.ebx <<= 16 /*0x10*/ % 32;
    // 0048d7ac  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048d7af  09fb                   -or ebx, edi
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.edi));
    // 0048d7b1  41                     -inc ecx
    (cpu.ecx)++;
    // 0048d7b2  895afc                 -mov dword ptr [edx - 4], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 0048d7b5  39f1                   +cmp ecx, esi
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
    // 0048d7b7  7cdb                   -jl 0x48d794
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048d794;
    }
    // 0048d7b9  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x0048d7bc:
    // 0048d7bc  8b852e040000           -mov eax, dword ptr [ebp + 0x42e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(1070) /* 0x42e */);
    // 0048d7c2  8b54247c               -mov edx, dword ptr [esp + 0x7c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 0048d7c6  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0048d7c9  39d0                   +cmp eax, edx
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
    // 0048d7cb  7e0b                   -jle 0x48d7d8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048d7d8;
    }
    // 0048d7cd  8b44247c               -mov eax, dword ptr [esp + 0x7c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 0048d7d1  66898530040000         -mov word ptr [ebp + 0x430], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(1072) /* 0x430 */) = cpu.ax;
L_0x0048d7d8:
    // 0048d7d8  8b8530040000           -mov eax, dword ptr [ebp + 0x430]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(1072) /* 0x430 */);
    // 0048d7de  8b4c2478               -mov ecx, dword ptr [esp + 0x78]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 0048d7e2  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0048d7e5  39c8                   +cmp eax, ecx
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
    // 0048d7e7  7d0b                   -jge 0x48d7f4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048d7f4;
    }
    // 0048d7e9  8b442478               -mov eax, dword ptr [esp + 0x78]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 0048d7ed  66898532040000         -mov word ptr [ebp + 0x432], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(1074) /* 0x432 */) = cpu.ax;
L_0x0048d7f4:
    // 0048d7f4  837c247000             +cmp dword ptr [esp + 0x70], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048d7f9  740c                   -je 0x48d807
    if (cpu.flags.zf)
    {
        goto L_0x0048d807;
    }
    // 0048d7fb  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0048d7fd  e89e5d0000             -call 0x4935a0
    cpu.esp -= 4;
    sub_4935a0(app, cpu);
    if (cpu.terminate) return;
    // 0048d802  e8558bfeff             -call 0x47635c
    cpu.esp -= 4;
    sub_47635c(app, cpu);
    if (cpu.terminate) return;
L_0x0048d807:
    // 0048d807  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048d809  e8725effff             -call 0x483680
    cpu.esp -= 4;
    sub_483680(app, cpu);
    if (cpu.terminate) return;
    // 0048d80e  80bd5d04000000         +cmp byte ptr [ebp + 0x45d], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(1117) /* 0x45d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048d815  7555                   -jne 0x48d86c
    if (!cpu.flags.zf)
    {
        goto L_0x0048d86c;
    }
    // 0048d817  8b44247c               -mov eax, dword ptr [esp + 0x7c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 0048d81b  8d5530                 -lea edx, [ebp + 0x30]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(48) /* 0x30 */);
    // 0048d81e  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0048d821  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048d823  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048d825  05a07b5200             -add eax, 0x527ba0
    (cpu.eax) += x86::reg32(x86::sreg32(5405600 /*0x527ba0*/));
    // 0048d82a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0048d82c  7e3e                   -jle 0x48d86c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048d86c;
    }
L_0x0048d82e:
    // 0048d82e  8a1a                   -mov bl, byte ptr [edx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx);
    // 0048d830  885802                 -mov byte ptr [eax + 2], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */) = cpu.bl;
    // 0048d833  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 0048d835  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 0048d838  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0048d83e  895c2474               -mov dword ptr [esp + 0x74], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */) = cpu.ebx;
    // 0048d842  8a5c2474               -mov bl, byte ptr [esp + 0x74]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 0048d846  885801                 -mov byte ptr [eax + 1], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = cpu.bl;
    // 0048d849  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 0048d84b  c1eb10                 -shr ebx, 0x10
    cpu.ebx >>= 16 /*0x10*/ % 32;
    // 0048d84e  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0048d854  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048d857  895c2474               -mov dword ptr [esp + 0x74], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */) = cpu.ebx;
    // 0048d85b  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048d85e  8a5c2474               -mov bl, byte ptr [esp + 0x74]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 0048d862  41                     -inc ecx
    (cpu.ecx)++;
    // 0048d863  8858fc                 -mov byte ptr [eax - 4], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.bl;
    // 0048d866  39f1                   +cmp ecx, esi
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
    // 0048d868  7cc4                   -jl 0x48d82e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048d82e;
    }
    // 0048d86a  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x0048d86c:
    // 0048d86c  837c247000             +cmp dword ptr [esp + 0x70], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048d871  7512                   -jne 0x48d885
    if (!cpu.flags.zf)
    {
        goto L_0x0048d885;
    }
L_0x0048d873:
    // 0048d873  81c480000000           -add esp, 0x80
    (cpu.esp) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 0048d879  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d87a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d87b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d87c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d87d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048d87e:
    // 0048d87e  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0048d880  e9f1feffff             -jmp 0x48d776
    goto L_0x0048d776;
L_0x0048d885:
    // 0048d885  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0048d887  e8385d0000             -call 0x4935c4
    cpu.esp -= 4;
    sub_4935c4(app, cpu);
    if (cpu.terminate) return;
    // 0048d88c  81c480000000           -add esp, 0x80
    (cpu.esp) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 0048d892  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d893  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d894  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d895  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d896  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48d898(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048d898  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048d899  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048d89a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048d89c  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0048d89e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048d8a0  8d14b500000000         -lea edx, [esi*4]
    cpu.edx = x86::reg32(cpu.esi * 4);
    // 0048d8a7  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0048d8a9  81c2a07b5200           -add edx, 0x527ba0
    (cpu.edx) += x86::reg32(x86::sreg32(5405600 /*0x527ba0*/));
    // 0048d8af  e8b5870000             -call 0x496069
    cpu.esp -= 4;
    sub_496069(app, cpu);
    if (cpu.terminate) return;
    // 0048d8b4  b830b15100             -mov eax, 0x51b130
    cpu.eax = 5353776 /*0x51b130*/;
    // 0048d8b9  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0048d8bb  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0048d8bd  e85efeffff             -call 0x48d720
    cpu.esp -= 4;
    sub_48d720(app, cpu);
    if (cpu.terminate) return;
    // 0048d8c2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d8c3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d8c4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48d8c8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048d8c8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048d8c9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048d8ca  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048d8cb  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048d8cc  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0048d8cf  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0048d8d3  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0048d8d6  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0048d8d9  05a07b5200             -add eax, 0x527ba0
    (cpu.eax) += x86::reg32(x86::sreg32(5405600 /*0x527ba0*/));
L_0x0048d8de:
    // 0048d8de  4a                     -dec edx
    (cpu.edx)--;
    // 0048d8df  83faff                 +cmp edx, -1
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
    // 0048d8e2  745d                   -je 0x48d941
    if (cpu.flags.zf)
    {
        goto L_0x0048d941;
    }
    // 0048d8e4  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048d8e6  8a0b                   -mov cl, byte ptr [ebx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebx);
    // 0048d8e8  8d2c8d00000000         -lea ebp, [ecx*4]
    cpu.ebp = x86::reg32(cpu.ecx * 4);
    // 0048d8ef  c1f904                 -sar ecx, 4
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (4 /*0x4*/ % 32));
    // 0048d8f2  09cd                   -or ebp, ecx
    cpu.ebp |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048d8f4  896c2404               -mov dword ptr [esp + 4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 0048d8f8  0fb67301               -movzx esi, byte ptr [ebx + 1]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */));
    // 0048d8fc  8a4c2404               -mov cl, byte ptr [esp + 4]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048d900  0fb67b02               -movzx edi, byte ptr [ebx + 2]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(2) /* 0x2 */));
    // 0048d904  884802                 -mov byte ptr [eax + 2], cl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */) = cpu.cl;
    // 0048d907  8d0cb500000000         -lea ecx, [esi*4]
    cpu.ecx = x86::reg32(cpu.esi * 4);
    // 0048d90e  c1fe04                 -sar esi, 4
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (4 /*0x4*/ % 32));
    // 0048d911  09f1                   -or ecx, esi
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.esi));
    // 0048d913  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0048d917  8a4c2404               -mov cl, byte ptr [esp + 4]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048d91b  884801                 -mov byte ptr [eax + 1], cl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = cpu.cl;
    // 0048d91e  8d0cbd00000000         -lea ecx, [edi*4]
    cpu.ecx = x86::reg32(cpu.edi * 4);
    // 0048d925  43                     -inc ebx
    (cpu.ebx)++;
    // 0048d926  c1ff04                 -sar edi, 4
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (4 /*0x4*/ % 32));
    // 0048d929  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048d92c  09f9                   +or ecx, edi
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.edi))));
    // 0048d92e  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0048d92f  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0048d933  c640ffff               -mov byte ptr [eax - 1], 0xff
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-1) /* -0x1 */) = 255 /*0xff*/;
    // 0048d937  8a4c2404               -mov cl, byte ptr [esp + 4]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048d93b  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0048d93c  8848fc                 -mov byte ptr [eax - 4], cl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.cl;
    // 0048d93f  eb9d                   -jmp 0x48d8de
    goto L_0x0048d8de;
L_0x0048d941:
    // 0048d941  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 0048d944  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048d948  b830b15100             -mov eax, 0x51b130
    cpu.eax = 5353776 /*0x51b130*/;
    // 0048d94d  e8cefdffff             -call 0x48d720
    cpu.esp -= 4;
    sub_48d720(app, cpu);
    if (cpu.terminate) return;
    // 0048d952  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0048d955  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d956  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d957  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d958  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d959  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48d95c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048d95c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048d95d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048d95e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048d960  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0048d962  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048d964  8d1c9500000000         -lea ebx, [edx*4]
    cpu.ebx = x86::reg32(cpu.edx * 4);
    // 0048d96b  8d148d00000000         -lea edx, [ecx*4]
    cpu.edx = x86::reg32(cpu.ecx * 4);
    // 0048d972  81c2a07b5200           -add edx, 0x527ba0
    (cpu.edx) += x86::reg32(x86::sreg32(5405600 /*0x527ba0*/));
    // 0048d978  e8d32dffff             -call 0x480750
    cpu.esp -= 4;
    sub_480750(app, cpu);
    if (cpu.terminate) return;
    // 0048d97d  b830b15100             -mov eax, 0x51b130
    cpu.eax = 5353776 /*0x51b130*/;
    // 0048d982  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0048d984  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0048d986  e895fdffff             -call 0x48d720
    cpu.esp -= 4;
    sub_48d720(app, cpu);
    if (cpu.terminate) return;
    // 0048d98b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d98c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d98d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48d990(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048d990  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048d991  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048d992  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0048d994  b9a07b5200             -mov ecx, 0x527ba0
    cpu.ecx = 5405600 /*0x527ba0*/;
    // 0048d999  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0048d99c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048d99e  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048d9a0  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0048d9a2  7e20                   -jle 0x48d9c4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048d9c4;
    }
    // 0048d9a4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x0048d9a6:
    // 0048d9a6  43                     -inc ebx
    (cpu.ebx)++;
    // 0048d9a7  8a4802                 -mov cl, byte ptr [eax + 2]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0048d9aa  884bff                 -mov byte ptr [ebx - 1], cl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */) = cpu.cl;
    // 0048d9ad  43                     -inc ebx
    (cpu.ebx)++;
    // 0048d9ae  8a4801                 -mov cl, byte ptr [eax + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0048d9b1  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048d9b4  884bff                 -mov byte ptr [ebx - 1], cl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */) = cpu.cl;
    // 0048d9b7  43                     -inc ebx
    (cpu.ebx)++;
    // 0048d9b8  8a48fc                 -mov cl, byte ptr [eax - 4]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 0048d9bb  42                     -inc edx
    (cpu.edx)++;
    // 0048d9bc  884bff                 -mov byte ptr [ebx - 1], cl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */) = cpu.cl;
    // 0048d9bf  39f2                   +cmp edx, esi
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
    // 0048d9c1  7ce3                   -jl 0x48d9a6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048d9a6;
    }
    // 0048d9c3  90                     -nop 
    ;
L_0x0048d9c4:
    // 0048d9c4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d9c5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d9c6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48d9c8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048d9c8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048d9c9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048d9ca  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0048d9cc  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0048d9ce  b9a07b5200             -mov ecx, 0x527ba0
    cpu.ecx = 5405600 /*0x527ba0*/;
    // 0048d9d3  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0048d9d6  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048d9d8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048d9da  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0048d9dc  7e12                   -jle 0x48d9f0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048d9f0;
    }
L_0x0048d9de:
    // 0048d9de  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048d9e1  8b19                   -mov ebx, dword ptr [ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0048d9e3  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048d9e6  40                     -inc eax
    (cpu.eax)++;
    // 0048d9e7  895afc                 -mov dword ptr [edx - 4], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 0048d9ea  39f0                   +cmp eax, esi
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
    // 0048d9ec  7cf0                   -jl 0x48d9de
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048d9de;
    }
    // 0048d9ee  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x0048d9f0:
    // 0048d9f0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d9f1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d9f2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48d9f4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048d9f4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048d9f5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048d9f6  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048d9f9  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0048d9fb  b9a07b5200             -mov ecx, 0x527ba0
    cpu.ecx = 5405600 /*0x527ba0*/;
    // 0048da00  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0048da03  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048da05  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048da07  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0048da09  7e41                   -jle 0x48da4c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048da4c;
    }
    // 0048da0b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x0048da0d:
    // 0048da0d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048da0f  8a4802                 -mov cl, byte ptr [eax + 2]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0048da12  c1f902                 -sar ecx, 2
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (2 /*0x2*/ % 32));
    // 0048da15  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 0048da18  8a0c24                 -mov cl, byte ptr [esp]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp);
    // 0048da1b  880b                   -mov byte ptr [ebx], cl
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.cl;
    // 0048da1d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048da1f  8a4801                 -mov cl, byte ptr [eax + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0048da22  c1f902                 -sar ecx, 2
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (2 /*0x2*/ % 32));
    // 0048da25  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 0048da28  8a0c24                 -mov cl, byte ptr [esp]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp);
    // 0048da2b  884b01                 -mov byte ptr [ebx + 1], cl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */) = cpu.cl;
    // 0048da2e  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048da30  43                     -inc ebx
    (cpu.ebx)++;
    // 0048da31  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 0048da33  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048da36  c1f902                 -sar ecx, 2
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (2 /*0x2*/ % 32));
    // 0048da39  43                     -inc ebx
    (cpu.ebx)++;
    // 0048da3a  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 0048da3d  43                     -inc ebx
    (cpu.ebx)++;
    // 0048da3e  8a0c24                 -mov cl, byte ptr [esp]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp);
    // 0048da41  42                     -inc edx
    (cpu.edx)++;
    // 0048da42  884bff                 -mov byte ptr [ebx - 1], cl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */) = cpu.cl;
    // 0048da45  39f2                   +cmp edx, esi
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
    // 0048da47  7cc4                   -jl 0x48da0d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048da0d;
    }
    // 0048da49  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x0048da4c:
    // 0048da4c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048da4f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048da50  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048da51  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_48da54(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048da54  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048da55  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048da56  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0048da58  83ed01                 +sub ebp, 1
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048da5b  780f                   -js 0x48da6c
    if (cpu.flags.sf)
    {
        goto L_0x0048da6c;
    }
L_0x0048da5d:
    // 0048da5d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048da5f  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 0048da61  8a1c0a                 -mov bl, byte ptr [edx + ecx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + cpu.ecx * 1);
    // 0048da64  8818                   -mov byte ptr [eax], bl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.bl;
    // 0048da66  40                     -inc eax
    (cpu.eax)++;
    // 0048da67  83ed01                 +sub ebp, 1
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048da6a  79f1                   -jns 0x48da5d
    if (!cpu.flags.sf)
    {
        goto L_0x0048da5d;
    }
L_0x0048da6c:
    // 0048da6c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048da6d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048da6e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_48da70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048da70  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048da71  8b0d74824c00           -mov ecx, dword ptr [0x4c8274]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5014132) /* 0x4c8274 */);
    // 0048da77  a37c824c00             -mov dword ptr [0x4c827c], eax
    app->getMemory<x86::reg32>(x86::reg32(5014140) /* 0x4c827c */) = cpu.eax;
    // 0048da7c  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0048da7e  a384824c00             -mov dword ptr [0x4c8284], eax
    app->getMemory<x86::reg32>(x86::reg32(5014148) /* 0x4c8284 */) = cpu.eax;
    // 0048da83  a178824c00             -mov eax, dword ptr [0x4c8278]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5014136) /* 0x4c8278 */);
    // 0048da88  891580824c00           -mov dword ptr [0x4c8280], edx
    app->getMemory<x86::reg32>(x86::reg32(5014144) /* 0x4c8280 */) = cpu.edx;
    // 0048da8e  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048da90  891588824c00           -mov dword ptr [0x4c8288], edx
    app->getMemory<x86::reg32>(x86::reg32(5014152) /* 0x4c8288 */) = cpu.edx;
    // 0048da96  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048da97  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48da98(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048da98  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048da99  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048da9a  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0048da9c  89159c824c00           -mov dword ptr [0x4c829c], edx
    app->getMemory<x86::reg32>(x86::reg32(5014172) /* 0x4c829c */) = cpu.edx;
    // 0048daa2  d1fb                   -sar ebx, 1
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (1 /*0x1*/ % 32));
    // 0048daa4  8b157c824c00           -mov edx, dword ptr [0x4c827c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5014140) /* 0x4c827c */);
    // 0048daaa  a398824c00             -mov dword ptr [0x4c8298], eax
    app->getMemory<x86::reg32>(x86::reg32(5014168) /* 0x4c8298 */) = cpu.eax;
    // 0048daaf  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0048dab1  d1f9                   -sar ecx, 1
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (1 /*0x1*/ % 32));
    // 0048dab3  891584824c00           -mov dword ptr [0x4c8284], edx
    app->getMemory<x86::reg32>(x86::reg32(5014148) /* 0x4c8284 */) = cpu.edx;
    // 0048dab9  8b1580824c00           -mov edx, dword ptr [0x4c8280]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5014144) /* 0x4c8280 */);
    // 0048dabf  891d74824c00           -mov dword ptr [0x4c8274], ebx
    app->getMemory<x86::reg32>(x86::reg32(5014132) /* 0x4c8274 */) = cpu.ebx;
    // 0048dac5  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0048dac7  890d78824c00           -mov dword ptr [0x4c8278], ecx
    app->getMemory<x86::reg32>(x86::reg32(5014136) /* 0x4c8278 */) = cpu.ecx;
    // 0048dacd  891588824c00           -mov dword ptr [0x4c8288], edx
    app->getMemory<x86::reg32>(x86::reg32(5014152) /* 0x4c8288 */) = cpu.edx;
    // 0048dad3  8d8800010000           -lea ecx, [eax + 0x100]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(256) /* 0x100 */);
    // 0048dad9  c0e507                 +shl ch, 7
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
    // 0048dadc  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0048dade  00ed                   +add ch, ch
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
    // 0048dae0  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 0048dae2  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048dae4  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0048dae9  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048daeb  8b048514894c00         -mov eax, dword ptr [eax*4 + 0x4c8914]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5015828) /* 0x4c8914 */ + cpu.eax * 4);
    // 0048daf2  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048daf4  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048daf6  8b1d74824c00           -mov ebx, dword ptr [0x4c8274]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5014132) /* 0x4c8274 */);
    // 0048dafc  0fafd8                 -imul ebx, eax
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0048daff  a198824c00             -mov eax, dword ptr [0x4c8298]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5014168) /* 0x4c8298 */);
    // 0048db04  c0e407                 +shl ah, 7
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
    // 0048db07  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0048db09  00e4                   +add ah, ah
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
    // 0048db0b  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 0048db0d  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048db0f  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0048db14  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048db16  8b048514894c00         -mov eax, dword ptr [eax*4 + 0x4c8914]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5015828) /* 0x4c8914 */ + cpu.eax * 4);
    // 0048db1d  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048db1f  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048db21  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048db23  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0048db25  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048db27  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0048db2a  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0048db2c  a38c824c00             -mov dword ptr [0x4c828c], eax
    app->getMemory<x86::reg32>(x86::reg32(5014156) /* 0x4c828c */) = cpu.eax;
    // 0048db31  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0048db33  746a                   -je 0x48db9f
    if (cpu.flags.zf)
    {
        goto L_0x0048db9f;
    }
    // 0048db35  a19c824c00             -mov eax, dword ptr [0x4c829c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5014172) /* 0x4c829c */);
    // 0048db3a  8d8800010000           -lea ecx, [eax + 0x100]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(256) /* 0x100 */);
    // 0048db40  c0e507                 +shl ch, 7
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
    // 0048db43  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0048db45  00ed                   +add ch, ch
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
    // 0048db47  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 0048db49  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048db4b  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0048db50  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048db52  8b048514894c00         -mov eax, dword ptr [eax*4 + 0x4c8914]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5015828) /* 0x4c8914 */ + cpu.eax * 4);
    // 0048db59  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048db5b  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048db5d  8b1578824c00           -mov edx, dword ptr [0x4c8278]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5014136) /* 0x4c8278 */);
    // 0048db63  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048db65  0fafda                 -imul ebx, edx
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0048db68  a19c824c00             -mov eax, dword ptr [0x4c829c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5014172) /* 0x4c829c */);
    // 0048db6d  c0e407                 +shl ah, 7
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
    // 0048db70  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0048db72  00e4                   +add ah, ah
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
    // 0048db74  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 0048db76  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048db78  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0048db7d  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048db7f  8b048514894c00         -mov eax, dword ptr [eax*4 + 0x4c8914]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5015828) /* 0x4c8914 */ + cpu.eax * 4);
    // 0048db86  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048db88  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048db8a  f7db                   -neg ebx
    cpu.ebx = ~cpu.ebx + 1;
    // 0048db8c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048db8e  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0048db90  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048db92  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0048db95  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0048db97  a390824c00             -mov dword ptr [0x4c8290], eax
    app->getMemory<x86::reg32>(x86::reg32(5014160) /* 0x4c8290 */) = cpu.eax;
    // 0048db9c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048db9d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048db9e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048db9f:
    // 0048db9f  8b15a0824c00           -mov edx, dword ptr [0x4c82a0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5014176) /* 0x4c82a0 */);
    // 0048dba5  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0048dba7  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0048dbaa  c1e810                 +shr eax, 0x10
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
    // 0048dbad  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0048dbaf  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0048dbb1  8b1578824c00           -mov edx, dword ptr [0x4c8278]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5014136) /* 0x4c8278 */);
    // 0048dbb7  f7dd                   -neg ebp
    cpu.ebp = ~cpu.ebp + 1;
    // 0048dbb9  a390824c00             -mov dword ptr [0x4c8290], eax
    app->getMemory<x86::reg32>(x86::reg32(5014160) /* 0x4c8290 */) = cpu.eax;
    // 0048dbbe  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048dbc0  892d90824c00           -mov dword ptr [0x4c8290], ebp
    app->getMemory<x86::reg32>(x86::reg32(5014160) /* 0x4c8290 */) = cpu.ebp;
    // 0048dbc6  e805b4ffff             -call 0x488fd0
    cpu.esp -= 4;
    sub_488fd0(app, cpu);
    if (cpu.terminate) return;
    // 0048dbcb  a39c824c00             -mov dword ptr [0x4c829c], eax
    app->getMemory<x86::reg32>(x86::reg32(5014172) /* 0x4c829c */) = cpu.eax;
    // 0048dbd0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dbd1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dbd2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48dbd4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048dbd4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048dbd5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048dbd6  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0048dbd8  c1e20a                 -shl edx, 0xa
    cpu.edx <<= 10 /*0xa*/ % 32;
    // 0048dbdb  be68010000             -mov esi, 0x168
    cpu.esi = 360 /*0x168*/;
    // 0048dbe0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048dbe2  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0048dbe5  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0048dbe7  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0048dbe9  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048dbeb  c1e20a                 -shl edx, 0xa
    cpu.edx <<= 10 /*0xa*/ % 32;
    // 0048dbee  bf68010000             -mov edi, 0x168
    cpu.edi = 360 /*0x168*/;
    // 0048dbf3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048dbf5  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0048dbf8  f7ff                   -idiv edi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.edi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0048dbfa  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0048dbfc  e897feffff             -call 0x48da98
    cpu.esp -= 4;
    sub_48da98(app, cpu);
    if (cpu.terminate) return;
    // 0048dc01  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dc02  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dc03  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48dc04(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048dc04  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048dc05  837e0800               +cmp dword ptr [esi + 8], 0
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
    // 0048dc09  7e46                   -jle 0x48dc51
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048dc51;
    }
    // 0048dc0b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048dc0c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048dc0d  8b0d8c824c00           -mov ecx, dword ptr [0x4c828c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5014156) /* 0x4c828c */);
    // 0048dc13  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 0048dc15  0fafd1                 -imul edx, ecx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0048dc18  8b5e08                 -mov ebx, dword ptr [esi + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0048dc1b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048dc1d  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0048dc20  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0048dc22  8b1584824c00           -mov edx, dword ptr [0x4c8284]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5014148) /* 0x4c8284 */);
    // 0048dc28  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048dc2a  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 0048dc2c  8b2d90824c00           -mov ebp, dword ptr [0x4c8290]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5014160) /* 0x4c8290 */);
    // 0048dc32  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0048dc35  0fafd5                 -imul edx, ebp
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 0048dc38  8b4e08                 -mov ecx, dword ptr [esi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0048dc3b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048dc3d  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0048dc40  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0048dc42  8b1588824c00           -mov edx, dword ptr [0x4c8288]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5014152) /* 0x4c8288 */);
    // 0048dc48  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048dc4a  894704                 -mov dword ptr [edi + 4], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0048dc4d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dc4e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dc4f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dc50  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048dc51:
    // 0048dc51  c7470400000080         -mov dword ptr [edi + 4], 0x80000000
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = 2147483648 /*0x80000000*/;
    // 0048dc58  8b4704                 -mov eax, dword ptr [edi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0048dc5b  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 0048dc5d  800d94824c0001         -or byte ptr [0x4c8294], 1
    app->getMemory<x86::reg8>(x86::reg32(5014164) /* 0x4c8294 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 0048dc64  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dc65  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_48dc70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048dc70  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048dc71  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048dc72  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048dc73  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048dc74  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048dc75  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048dc76  bae8fa4c00             -mov edx, 0x4cfae8
    cpu.edx = 5044968 /*0x4cfae8*/;
    // 0048dc7b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048dc7d  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x0048dc7f:
    // 0048dc7f  83bf10a74c0000         +cmp dword ptr [edi + 0x4ca710], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5023504) /* 0x4ca710 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048dc86  743a                   -je 0x48dcc2
    if (cpu.flags.zf)
    {
        goto L_0x0048dcc2;
    }
L_0x0048dc88:
    // 0048dc88  43                     -inc ebx
    (cpu.ebx)++;
    // 0048dc89  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048dc8c  83fb0a                 +cmp ebx, 0xa
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
    // 0048dc8f  7cee                   -jl 0x48dc7f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048dc7f;
    }
    // 0048dc91  8d4204                 -lea eax, [edx + 4]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0048dc94  2de8fa4c00             -sub eax, 0x4cfae8
    (cpu.eax) -= x86::reg32(x86::sreg32(5044968 /*0x4cfae8*/));
    // 0048dc99  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 0048dc9c  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0048dc9f  a338a74c00             -mov dword ptr [0x4ca738], eax
    app->getMemory<x86::reg32>(x86::reg32(5023544) /* 0x4ca738 */) = cpu.eax;
    // 0048dca4  b84f615200             -mov eax, 0x52614f
    cpu.eax = 5398863 /*0x52614f*/;
    // 0048dca9  24e0                   -and al, 0xe0
    cpu.al &= x86::reg8(x86::sreg8(224 /*0xe0*/));
    // 0048dcab  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 0048dcb1  a304a74c00             -mov dword ptr [0x4ca704], eax
    app->getMemory<x86::reg32>(x86::reg32(5023492) /* 0x4ca704 */) = cpu.eax;
    // 0048dcb6  e805480100             -call 0x4a24c0
    cpu.esp -= 4;
    sub_4a24c0(app, cpu);
    if (cpu.terminate) return;
    // 0048dcbb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dcbc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dcbd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dcbe  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dcbf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dcc0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dcc1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048dcc2:
    // 0048dcc2  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 0048dcc8  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048dccb  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 0048dcd0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048dcd2  88d9                   -mov cl, bl
    cpu.cl = cpu.bl;
    // 0048dcd4  2de8fa4c00             -sub eax, 0x4cfae8
    (cpu.eax) -= x86::reg32(x86::sreg32(5044968 /*0x4cfae8*/));
    // 0048dcd9  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 0048dcdb  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 0048dcde  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 0048dce1  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0048dce4  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0048dce7  898710a74c00           -mov dword ptr [edi + 0x4ca710], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5023504) /* 0x4ca710 */) = cpu.eax;
    // 0048dced  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048dcef  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0048dcf1  7e95                   -jle 0x48dc88
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048dc88;
    }
    // 0048dcf3  88d9                   -mov cl, bl
    cpu.cl = cpu.bl;
L_0x0048dcf5:
    // 0048dcf5  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0048dcf7  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048dcfa  d3e5                   -shl ebp, cl
    cpu.ebp <<= cpu.cl % 32;
    // 0048dcfc  40                     -inc eax
    (cpu.eax)++;
    // 0048dcfd  896afc                 -mov dword ptr [edx - 4], ebp
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */) = cpu.ebp;
    // 0048dd00  39f0                   +cmp eax, esi
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
    // 0048dd02  7d84                   -jge 0x48dc88
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048dc88;
    }
    // 0048dd04  ebef                   -jmp 0x48dcf5
    goto L_0x0048dcf5;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48dd08(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048dd08  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048dd09  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048dd0a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048dd0b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048dd0c  8b2d586b5200           -mov ebp, dword ptr [0x526b58]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5401432) /* 0x526b58 */);
    // 0048dd12  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048dd14  8b0d5c6b5200           -mov ecx, dword ptr [0x526b5c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5401436) /* 0x526b5c */);
    // 0048dd1a  42                     -inc edx
    (cpu.edx)++;
    // 0048dd1b  39c8                   +cmp eax, ecx
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
    // 0048dd1d  751c                   -jne 0x48dd3b
    if (!cpu.flags.zf)
    {
        goto L_0x0048dd3b;
    }
    // 0048dd1f  39ea                   +cmp edx, ebp
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
    // 0048dd21  7e0d                   -jle 0x48dd30
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048dd30;
    }
    // 0048dd23  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0048dd25  0faff5                 -imul esi, ebp
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 0048dd28  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048dd2a  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0048dd2c  39e8                   +cmp eax, ebp
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
    // 0048dd2e  7c26                   -jl 0x48dd56
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048dd56;
    }
L_0x0048dd30:
    // 0048dd30  892d586b5200           -mov dword ptr [0x526b58], ebp
    app->getMemory<x86::reg32>(x86::reg32(5401432) /* 0x526b58 */) = cpu.ebp;
    // 0048dd36  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dd37  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dd38  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dd39  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dd3a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048dd3b:
    // 0048dd3b  891d5c6b5200           -mov dword ptr [0x526b5c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5401436) /* 0x526b5c */) = cpu.ebx;
    // 0048dd41  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0048dd43  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048dd45  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0048dd47  39e8                   +cmp eax, ebp
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
    // 0048dd49  7c0b                   -jl 0x48dd56
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048dd56;
    }
    // 0048dd4b  892d586b5200           -mov dword ptr [0x526b58], ebp
    app->getMemory<x86::reg32>(x86::reg32(5401432) /* 0x526b58 */) = cpu.ebp;
    // 0048dd51  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dd52  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dd53  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dd54  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dd55  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048dd56:
    // 0048dd56  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048dd57  8b1538a74c00           -mov edx, dword ptr [0x4ca738]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023544) /* 0x4ca738 */);
    // 0048dd5d  8d3c8500000000         -lea edi, [eax*4]
    cpu.edi = x86::reg32(cpu.eax * 4);
    // 0048dd64  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0048dd67  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0048dd69  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0048dd6c  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0048dd6e  81c2e8fa4c00           -add edx, 0x4cfae8
    (cpu.edx) += x86::reg32(x86::sreg32(5044968 /*0x4cfae8*/));
    // 0048dd74  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048dd76  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048dd78  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0048dd7a  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0048dd7c  892d586b5200           -mov dword ptr [0x526b58], ebp
    app->getMemory<x86::reg32>(x86::reg32(5401432) /* 0x526b58 */) = cpu.ebp;
L_0x0048dd82:
    // 0048dd82  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 0048dd84  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048dd86  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0048dd89  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048dd8b  894308                 -mov dword ptr [ebx + 8], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0048dd8e  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048dd90  89430c                 -mov dword ptr [ebx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0048dd93  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048dd95  8d5b10                 -lea ebx, [ebx + 0x10]
    cpu.ebx = x86::reg32(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 0048dd98  83e904                 +sub ecx, 4
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048dd9b  7fe5                   -jg 0x48dd82
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048dd82;
    }
    // 0048dd9d  8b2d586b5200           -mov ebp, dword ptr [0x526b58]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5401432) /* 0x526b58 */);
    // 0048dda3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048dda4  892d586b5200           -mov dword ptr [0x526b58], ebp
    app->getMemory<x86::reg32>(x86::reg32(5401432) /* 0x526b58 */) = cpu.ebp;
    // 0048ddaa  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ddab  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ddac  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ddad  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ddae  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48ddb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048ddb0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048ddb1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048ddb2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048ddb3  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0048ddb6  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0048ddb8  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0048ddba  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0048ddbe  a1f0844c00             -mov eax, dword ptr [0x4c84f0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5014768) /* 0x4c84f0 */);
    // 0048ddc3  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0048ddc5  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0048ddc8  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0048ddcb  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0048ddcd  8b0df8844c00           -mov ecx, dword ptr [0x4c84f8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5014776) /* 0x4c84f8 */);
    // 0048ddd3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048ddd5  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048ddd7  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 0048ddd9  8b15fc844c00           -mov edx, dword ptr [0x4c84fc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5014780) /* 0x4c84fc */);
    // 0048dddf  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048dde1  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0048dde4  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048dde6  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0048dde9  0310                   -add edx, dword ptr [eax]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax)));
    // 0048ddeb  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048dded  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0048ddef  8b35e0fa4c00           -mov esi, dword ptr [0x4cfae0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5044960) /* 0x4cfae0 */);
    // 0048ddf5  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0048ddf7  8a25ec844c00           -mov ah, byte ptr [0x4c84ec]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5014764) /* 0x4c84ec */);
    // 0048ddfd  83ee10                 -sub esi, 0x10
    (cpu.esi) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0048de00  80fc10                 +cmp ah, 0x10
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048de03  7733                   -ja 0x48de38
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0048de38;
    }
    // 0048de05  80fc08                 +cmp ah, 8
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(8 /*0x8*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048de08  7602                   -jbe 0x48de0c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0048de0c;
    }
    // 0048de0a  d1fa                   -sar edx, 1
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (1 /*0x1*/ % 32));
L_0x0048de0c:
    // 0048de0c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048de0e  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048de12  e8f9460100             -call 0x4a2510
    cpu.esp -= 4;
    sub_4a2510(app, cpu);
    if (cpu.terminate) return;
    // 0048de17  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048de18  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048de19  a1d8fa4c00             -mov eax, dword ptr [0x4cfad8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5044952) /* 0x4cfad8 */);
    // 0048de1e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048de1f  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0048de21  8b0dd0fa4c00           -mov ecx, dword ptr [0x4cfad0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5044944) /* 0x4cfad0 */);
    // 0048de27  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048de28  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0048de2a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048de2c  e81f490100             -call 0x4a2750
    cpu.esp -= 4;
    sub_4a2750(app, cpu);
    if (cpu.terminate) return;
    // 0048de31  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0048de34  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048de35  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048de36  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048de37  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048de38:
    // 0048de38  c1fa02                 +sar edx, 2
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
    // 0048de3b  ebcf                   -jmp 0x48de0c
    goto L_0x0048de0c;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48de40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048de40  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048de41  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048de42  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048de43  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0048de46  8b6c2420               -mov ebp, dword ptr [esp + 0x20]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0048de4a  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0048de4c  8d1ccd00000000         -lea ebx, [ecx*8]
    cpu.ebx = x86::reg32(cpu.ecx * 8);
    // 0048de53  8d3c1a                 -lea edi, [edx + ebx]
    cpu.edi = x86::reg32(cpu.edx + cpu.ebx * 1);
    // 0048de56  8d1ced00000000         -lea ebx, [ebp*8]
    cpu.ebx = x86::reg32(cpu.ebp * 8);
    // 0048de5d  897c240c               -mov dword ptr [esp + 0xc], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 0048de61  8d3c1a                 -lea edi, [edx + ebx]
    cpu.edi = x86::reg32(cpu.edx + cpu.ebx * 1);
    // 0048de64  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048de68  8b5b04                 -mov ebx, dword ptr [ebx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0048de6b  3b5f04                 +cmp ebx, dword ptr [edi + 4]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048de6e  7e06                   -jle 0x48de76
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048de76;
    }
    // 0048de70  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0048de72  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0048de74  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
L_0x0048de76:
    // 0048de76  c1e503                 -shl ebp, 3
    cpu.ebp <<= 3 /*0x3*/ % 32;
    // 0048de79  c1e103                 -shl ecx, 3
    cpu.ecx <<= 3 /*0x3*/ % 32;
    // 0048de7c  8d3c2a                 -lea edi, [edx + ebp]
    cpu.edi = x86::reg32(cpu.edx + cpu.ebp * 1);
    // 0048de7f  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0048de81  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0048de85  8b4f04                 -mov ecx, dword ptr [edi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0048de88  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0048de8b  29d9                   +sub ecx, ebx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048de8d  894824                 -mov dword ptr [eax + 0x24], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = cpu.ecx;
    // 0048de90  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0048de93  895820                 -mov dword ptr [eax + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 0048de96  7509                   -jne 0x48dea1
    if (!cpu.flags.zf)
    {
        goto L_0x0048dea1;
    }
    // 0048de98  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0048de9b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048de9c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048de9d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048de9e  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0048dea1:
    // 0048dea1  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 0048dea3  c1e310                 -shl ebx, 0x10
    cpu.ebx <<= 16 /*0x10*/ % 32;
    // 0048dea6  895818                 -mov dword ptr [eax + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 0048dea9  8b1f                   -mov ebx, dword ptr [edi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi);
    // 0048deab  2b1a                   -sub ebx, dword ptr [edx]
    (cpu.ebx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
    // 0048dead  c1e310                 -shl ebx, 0x10
    cpu.ebx <<= 16 /*0x10*/ % 32;
    // 0048deb0  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 0048deb4  db44240c               -fild dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */))));
    // 0048deb8  d80c8d302d5400         -fmul dword ptr [ecx*4 + 0x542d30]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5516592) /* 0x542d30 */ + cpu.ecx * 4));
    // 0048debf  d9050ca74c00           -fld dword ptr [0x4ca70c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5023500) /* 0x4ca70c */)));
    // 0048dec5  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0048dec7  d8c1                   -fadd st(1)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(1));
    // 0048dec9  dd18                   -fstp qword ptr [eax]
    app->getMemory<double>(cpu.eax) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0048decb  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0048decd  89501c                 -mov dword ptr [eax + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 0048ded0  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048ded4  8b1c2e                 -mov ebx, dword ptr [esi + ebp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ebp * 1);
    // 0048ded7  8b3c32                 -mov edi, dword ptr [edx + esi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 1);
    // 0048deda  29fb                   -sub ebx, edi
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0048dedc  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 0048dee0  db44240c               -fild dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */))));
    // 0048dee4  d80c8d302d5400         -fmul dword ptr [ecx*4 + 0x542d30]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5516592) /* 0x542d30 */ + cpu.ecx * 4));
    // 0048deeb  d95810                 -fstp dword ptr [eax + 0x10]
    app->getMemory<float>(cpu.eax + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0048deee  8b5c2e04               -mov ebx, dword ptr [esi + ebp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ebp * 1);
    // 0048def2  8b6c3204               -mov ebp, dword ptr [edx + esi + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */ + cpu.esi * 1);
    // 0048def6  29eb                   -sub ebx, ebp
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0048def8  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 0048defc  db44240c               -fild dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */))));
    // 0048df00  d80c8d302d5400         -fmul dword ptr [ecx*4 + 0x542d30]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5516592) /* 0x542d30 */ + cpu.ecx * 4));
    // 0048df07  d95814                 -fstp dword ptr [eax + 0x14]
    app->getMemory<float>(cpu.eax + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0048df0a  db0432                 -fild dword ptr [edx + esi]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 1))));
    // 0048df0d  d8c1                   -fadd st(1)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(1));
    // 0048df0f  dd18                   -fstp qword ptr [eax]
    app->getMemory<double>(cpu.eax) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0048df11  db443204               -fild dword ptr [edx + esi + 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */ + cpu.esi * 1))));
    // 0048df15  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0048df17  dd5808                 -fstp qword ptr [eax + 8]
    app->getMemory<double>(cpu.eax + x86::reg32(8) /* 0x8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0048df1a  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0048df1d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048df1e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048df1f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048df20  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x90 */
void Application::sub_48df24(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048df24  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048df25  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048df26  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048df27  83ec24                 -sub esp, 0x24
    (cpu.esp) -= x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0048df2a  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0048df2e  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0048df30  895c241c               -mov dword ptr [esp + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 0048df34  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0048df38  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 0048df3f  a1fc844c00             -mov eax, dword ptr [0x4c84fc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5014780) /* 0x4c84fc */);
    // 0048df44  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048df46  8b15f0844c00           -mov edx, dword ptr [0x4c84f0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5014768) /* 0x4c84f0 */);
    // 0048df4c  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048df4e  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048df50  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0048df54  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 0048df5b  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0048df5d  8b3d04a74c00           -mov edi, dword ptr [0x4ca704]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5023492) /* 0x4ca704 */);
    // 0048df63  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0048df66  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0048df68  8d3407                 -lea esi, [edi + eax]
    cpu.esi = x86::reg32(cpu.edi + cpu.eax * 1);
    // 0048df6b  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0048df72  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048df74  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0048df77  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048df79  8d41ff                 -lea eax, [ecx - 1]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 0048df7c  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x0048df80:
    // 0048df80  837f2400               +cmp dword ptr [edi + 0x24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048df84  0f8ead000000           -jle 0x48e037
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048e037;
    }
    // 0048df8a  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
L_0x0048df8e:
    // 0048df8e  8b4e24                 -mov ecx, dword ptr [esi + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 0048df91  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048df93  0f8ee2000000           -jle 0x48e07b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048e07b;
    }
    // 0048df99  8b4724                 -mov eax, dword ptr [edi + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */);
    // 0048df9c  39c8                   +cmp eax, ecx
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
    // 0048df9e  0f8d0e010000           -jge 0x48e0b2
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048e0b2;
    }
L_0x0048dfa4:
    // 0048dfa4  8b5724                 -mov edx, dword ptr [edi + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */);
    // 0048dfa7  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0048dfa9  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0048dfad  895724                 -mov dword ptr [edi + 0x24], edx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 0048dfb0  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0048dfb4  8b4e24                 -mov ecx, dword ptr [esi + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 0048dfb7  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048dfb9  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0048dfbb  895c2410               -mov dword ptr [esp + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 0048dfbf  894e24                 -mov dword ptr [esi + 0x24], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.ecx;
    // 0048dfc2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
L_0x0048dfc4:
    // 0048dfc4  74ba                   -je 0x48df80
    if (cpu.flags.zf)
    {
        goto L_0x0048df80;
    }
    // 0048dfc6  8b4e18                 -mov ecx, dword ptr [esi + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0048dfc9  8b4718                 -mov eax, dword ptr [edi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */);
    // 0048dfcc  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0048dfce  81e20000ffff           -and edx, 0xffff0000
    cpu.edx &= x86::reg32(x86::sreg32(4294901760 /*0xffff0000*/));
    // 0048dfd4  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048dfd6  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0048dfd9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048dfdb  0f8fd8000000           -jg 0x48e0b9
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048e0b9;
    }
    // 0048dfe1  0f8c29010000           -jl 0x48e110
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048e110;
    }
L_0x0048dfe7:
    // 0048dfe7  d94610                 -fld dword ptr [esi + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(16) /* 0x10 */)));
    // 0048dfea  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0048dfee  a1f8844c00             -mov eax, dword ptr [0x4c84f8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5014776) /* 0x4c84f8 */);
    // 0048dff3  8b4e18                 -mov ecx, dword ptr [esi + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0048dff6  dc06                   -fadd qword ptr [esi]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(cpu.esi));
    // 0048dff8  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048dffa  dd1e                   -fstp qword ptr [esi]
    app->getMemory<double>(cpu.esi) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0048dffc  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0048dfff  d94614                 -fld dword ptr [esi + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(20) /* 0x14 */)));
    // 0048e002  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048e004  dc4608                 -fadd qword ptr [esi + 8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(cpu.esi + x86::reg32(8) /* 0x8 */));
    // 0048e007  894e18                 -mov dword ptr [esi + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 0048e00a  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 0048e00e  dd5e08                 -fstp qword ptr [esi + 8]
    app->getMemory<double>(cpu.esi + x86::reg32(8) /* 0x8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0048e011  d94710                 -fld dword ptr [edi + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(16) /* 0x10 */)));
    // 0048e014  8b471c                 -mov eax, dword ptr [edi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */);
    // 0048e017  8b5f18                 -mov ebx, dword ptr [edi + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */);
    // 0048e01a  dc07                   -fadd qword ptr [edi]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(cpu.edi));
    // 0048e01c  01c3                   +add ebx, eax
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
    // 0048e01e  dd1f                   +fstp qword ptr [edi]
    app->getMemory<double>(cpu.edi) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0048e020  895f18                 -mov dword ptr [edi + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 0048e023  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0048e027  d94714                 +fld dword ptr [edi + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(20) /* 0x14 */)));
    // 0048e02a  dc4708                 +fadd qword ptr [edi + 8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(cpu.edi + x86::reg32(8) /* 0x8 */));
    // 0048e02d  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0048e02e  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0048e032  dd5f08                 +fstp qword ptr [edi + 8]
    app->getMemory<double>(cpu.edi + x86::reg32(8) /* 0x8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0048e035  eb8d                   -jmp 0x48dfc4
    goto L_0x0048dfc4;
L_0x0048e037:
    // 0048e037  4d                     -dec ebp
    (cpu.ebp)--;
    // 0048e038  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0048e03a  7c22                   -jl 0x48e05e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048e05e;
    }
    // 0048e03c  83ef28                 -sub edi, 0x28
    (cpu.edi) -= x86::reg32(x86::sreg32(40 /*0x28*/));
L_0x0048e03f:
    // 0048e03f  3b6c241c               +cmp ebp, dword ptr [esp + 0x1c]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048e043  742a                   -je 0x48e06f
    if (cpu.flags.zf)
    {
        goto L_0x0048e06f;
    }
    // 0048e045  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0048e049  3b4720                 +cmp eax, dword ptr [edi + 0x20]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048e04c  0f8e2effffff           -jle 0x48df80
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048df80;
    }
    // 0048e052  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0048e057  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0048e05a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e05b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e05c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e05d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048e05e:
    // 0048e05e  8b6c240c               -mov ebp, dword ptr [esp + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048e062  6bc528                 -imul eax, ebp, 0x28
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(40 /*0x28*/)));
    // 0048e065  8b3d04a74c00           -mov edi, dword ptr [0x4ca704]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5023492) /* 0x4ca704 */);
    // 0048e06b  01c7                   +add edi, eax
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
    // 0048e06d  ebd0                   -jmp 0x48e03f
    goto L_0x0048e03f;
L_0x0048e06f:
    // 0048e06f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048e074  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0048e077  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e078  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e079  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e07a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048e07b:
    // 0048e07b  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0048e07f  40                     -inc eax
    (cpu.eax)++;
    // 0048e080  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0048e084  39d0                   +cmp eax, edx
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
    // 0048e086  7c25                   -jl 0x48e0ad
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048e0ad;
    }
    // 0048e088  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048e08a  8b3504a74c00           -mov esi, dword ptr [0x4ca704]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5023492) /* 0x4ca704 */);
    // 0048e090  894c241c               -mov dword ptr [esp + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ecx;
L_0x0048e094:
    // 0048e094  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0048e098  3b4620                 +cmp eax, dword ptr [esi + 0x20]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048e09b  0f8eedfeffff           -jle 0x48df8e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048df8e;
    }
    // 0048e0a1  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0048e0a6  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0048e0a9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e0aa  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e0ab  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e0ac  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048e0ad:
    // 0048e0ad  83c628                 +add esi, 0x28
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(40 /*0x28*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048e0b0  ebe2                   -jmp 0x48e094
    goto L_0x0048e094;
L_0x0048e0b2:
    // 0048e0b2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048e0b4  e9ebfeffff             -jmp 0x48dfa4
    goto L_0x0048dfa4;
L_0x0048e0b9:
    // 0048e0b9  d90485302d5400         -fld dword ptr [eax*4 + 0x542d30]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5516592) /* 0x542d30 */ + cpu.eax * 4)));
    // 0048e0c0  dd07                   -fld qword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.edi)));
    // 0048e0c2  dc26                   -fsub qword ptr [esi]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<double>(cpu.esi));
    // 0048e0c4  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 0048e0c6  d9050ca74c00           -fld dword ptr [0x4ca70c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5023500) /* 0x4ca70c */)));
    // 0048e0cc  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0048e0ce  d8c1                   -fadd st(1)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(1));
    // 0048e0d0  dd1dd0fa4c00           -fstp qword ptr [0x4cfad0]
    app->getMemory<double>(x86::reg32(5044944) /* 0x4cfad0 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0048e0d6  dd4708                 -fld qword ptr [edi + 8]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.edi + x86::reg32(8) /* 0x8 */)));
    // 0048e0d9  dc6608                 -fsub qword ptr [esi + 8]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<double>(cpu.esi + x86::reg32(8) /* 0x8 */));
    // 0048e0dc  deca                   -fmulp st(2)
    cpu.fpu.st(2) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0048e0de  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0048e0e2  8b1500854c00           -mov edx, dword ptr [0x4c8500]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5014784) /* 0x4c8500 */);
    // 0048e0e8  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0048e0ea  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0048e0ed  dd1dd8fa4c00           -fstp qword ptr [0x4cfad8]
    app->getMemory<double>(x86::reg32(5044952) /* 0x4cfad8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0048e0f3  031c8a                 +add ebx, dword ptr [edx + ecx*4]
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + cpu.ecx * 4)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048e0f6  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0048e0f8  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0048e0fb  894c2420               -mov dword ptr [esp + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 0048e0ff  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048e101  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0048e105  ff153ca74c00           -call dword ptr [0x4ca73c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5023548) /* 0x4ca73c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048e10b  e9d7feffff             -jmp 0x48dfe7
    goto L_0x0048dfe7;
L_0x0048e110:
    // 0048e110  8b5f18                 -mov ebx, dword ptr [edi + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */);
    // 0048e113  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0048e116  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0048e118  81e20000ffff           -and edx, 0xffff0000
    cpu.edx &= x86::reg32(x86::sreg32(4294901760 /*0xffff0000*/));
    // 0048e11e  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048e120  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0048e123  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048e125  83f801                 +cmp eax, 1
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
    // 0048e128  7d05                   -jge 0x48e12f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048e12f;
    }
    // 0048e12a  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
L_0x0048e12f:
    // 0048e12f  d9048d302d5400         -fld dword ptr [ecx*4 + 0x542d30]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5516592) /* 0x542d30 */ + cpu.ecx * 4)));
    // 0048e136  dd06                   -fld qword ptr [esi]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esi)));
    // 0048e138  dc27                   -fsub qword ptr [edi]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<double>(cpu.edi));
    // 0048e13a  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 0048e13c  8b1500854c00           -mov edx, dword ptr [0x4c8500]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5014784) /* 0x4c8500 */);
    // 0048e142  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048e144  d9050ca74c00           -fld dword ptr [0x4ca70c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5023500) /* 0x4ca70c */)));
    // 0048e14a  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0048e14c  d8c1                   -fadd st(1)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(1));
    // 0048e14e  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0048e152  dd1dd0fa4c00           -fstp qword ptr [0x4cfad0]
    app->getMemory<double>(x86::reg32(5044944) /* 0x4cfad0 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0048e158  dd4608                 -fld qword ptr [esi + 8]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esi + x86::reg32(8) /* 0x8 */)));
    // 0048e15b  dc6708                 -fsub qword ptr [edi + 8]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<double>(cpu.edi + x86::reg32(8) /* 0x8 */));
    // 0048e15e  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0048e161  deca                   -fmulp st(2)
    cpu.fpu.st(2) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0048e163  031c82                 +add ebx, dword ptr [edx + eax*4]
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048e166  8b5708                 -mov edx, dword ptr [edi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0048e169  dec1                   +faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0048e16b  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0048e16d  dd1dd8fa4c00           +fstp qword ptr [0x4cfad8]
    app->getMemory<double>(x86::reg32(5044952) /* 0x4cfad8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0048e173  ff153ca74c00           -call dword ptr [0x4ca73c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5023548) /* 0x4ca73c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048e179  e969feffff             -jmp 0x48dfe7
    goto L_0x0048dfe7;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48e180(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048e180  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048e181  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048e182  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048e183  83ec24                 -sub esp, 0x24
    (cpu.esp) -= x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0048e186  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0048e18a  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0048e18c  895c241c               -mov dword ptr [esp + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 0048e190  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0048e194  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 0048e19b  a1fc844c00             -mov eax, dword ptr [0x4c84fc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5014780) /* 0x4c84fc */);
    // 0048e1a0  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048e1a2  8b15f0844c00           -mov edx, dword ptr [0x4c84f0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5014768) /* 0x4c84f0 */);
    // 0048e1a8  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048e1aa  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048e1ac  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0048e1ae  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0048e1b2  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0048e1b9  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048e1bb  8b3d04a74c00           -mov edi, dword ptr [0x4ca704]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5023492) /* 0x4ca704 */);
    // 0048e1c1  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0048e1c4  8d3407                 -lea esi, [edi + eax]
    cpu.esi = x86::reg32(cpu.edi + cpu.eax * 1);
    // 0048e1c7  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 0048e1ce  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0048e1d0  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0048e1d3  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048e1d5  8d41ff                 -lea eax, [ecx - 1]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 0048e1d8  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x0048e1dc:
    // 0048e1dc  837e2400               +cmp dword ptr [esi + 0x24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048e1e0  0f8efe000000           -jle 0x48e2e4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048e2e4;
    }
    // 0048e1e6  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
L_0x0048e1ea:
    // 0048e1ea  8b4f24                 -mov ecx, dword ptr [edi + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */);
    // 0048e1ed  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048e1ef  0f8433010000           -je 0x48e328
    if (cpu.flags.zf)
    {
        goto L_0x0048e328;
    }
    // 0048e1f5  8b5e24                 -mov ebx, dword ptr [esi + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 0048e1f8  39d9                   +cmp ecx, ebx
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
    // 0048e1fa  0f8d5d010000           -jge 0x48e35d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048e35d;
    }
    // 0048e200  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x0048e202:
    // 0048e202  8b5724                 -mov edx, dword ptr [edi + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */);
    // 0048e205  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0048e207  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0048e20b  895724                 -mov dword ptr [edi + 0x24], edx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 0048e20e  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0048e212  8b4e24                 -mov ecx, dword ptr [esi + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 0048e215  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048e217  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0048e219  895c2410               -mov dword ptr [esp + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 0048e21d  894e24                 -mov dword ptr [esi + 0x24], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.ecx;
    // 0048e220  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
L_0x0048e222:
    // 0048e222  74b8                   -je 0x48e1dc
    if (cpu.flags.zf)
    {
        goto L_0x0048e1dc;
    }
    // 0048e224  8b4e18                 -mov ecx, dword ptr [esi + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0048e227  8b4718                 -mov eax, dword ptr [edi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */);
    // 0048e22a  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0048e22c  81e20000ffff           -and edx, 0xffff0000
    cpu.edx &= x86::reg32(x86::sreg32(4294901760 /*0xffff0000*/));
    // 0048e232  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048e234  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0048e237  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048e239  0f8e25010000           -jle 0x48e364
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048e364;
    }
    // 0048e23f  d90485302d5400         -fld dword ptr [eax*4 + 0x542d30]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5516592) /* 0x542d30 */ + cpu.eax * 4)));
    // 0048e246  dd07                   -fld qword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.edi)));
    // 0048e248  dc26                   -fsub qword ptr [esi]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<double>(cpu.esi));
    // 0048e24a  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 0048e24c  d9050ca74c00           -fld dword ptr [0x4ca70c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5023500) /* 0x4ca70c */)));
    // 0048e252  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0048e254  d8c1                   -fadd st(1)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(1));
    // 0048e256  dd1dd0fa4c00           -fstp qword ptr [0x4cfad0]
    app->getMemory<double>(x86::reg32(5044944) /* 0x4cfad0 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0048e25c  dd4708                 -fld qword ptr [edi + 8]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.edi + x86::reg32(8) /* 0x8 */)));
    // 0048e25f  dc6608                 -fsub qword ptr [esi + 8]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<double>(cpu.esi + x86::reg32(8) /* 0x8 */));
    // 0048e262  deca                   -fmulp st(2)
    cpu.fpu.st(2) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0048e264  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0048e268  8b1500854c00           -mov edx, dword ptr [0x4c8500]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5014784) /* 0x4c8500 */);
    // 0048e26e  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0048e270  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0048e273  dd1dd8fa4c00           -fstp qword ptr [0x4cfad8]
    app->getMemory<double>(x86::reg32(5044952) /* 0x4cfad8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0048e279  031c8a                 -add ebx, dword ptr [edx + ecx*4]
    (cpu.ebx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + cpu.ecx * 4)));
    // 0048e27c  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0048e27e  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0048e281  894c2420               -mov dword ptr [esp + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 0048e285  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048e287  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
L_0x0048e28b:
    // 0048e28b  ff153ca74c00           -call dword ptr [0x4ca73c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5023548) /* 0x4ca73c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0048e291:
    // 0048e291  d94610                 -fld dword ptr [esi + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(16) /* 0x10 */)));
    // 0048e294  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0048e298  a1f8844c00             -mov eax, dword ptr [0x4c84f8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5014776) /* 0x4c84f8 */);
    // 0048e29d  8b4e18                 -mov ecx, dword ptr [esi + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0048e2a0  dc06                   -fadd qword ptr [esi]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(cpu.esi));
    // 0048e2a2  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048e2a4  dd1e                   -fstp qword ptr [esi]
    app->getMemory<double>(cpu.esi) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0048e2a6  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0048e2a9  d94614                 -fld dword ptr [esi + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(20) /* 0x14 */)));
    // 0048e2ac  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048e2ae  dc4608                 -fadd qword ptr [esi + 8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(cpu.esi + x86::reg32(8) /* 0x8 */));
    // 0048e2b1  894e18                 -mov dword ptr [esi + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 0048e2b4  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 0048e2b8  dd5e08                 -fstp qword ptr [esi + 8]
    app->getMemory<double>(cpu.esi + x86::reg32(8) /* 0x8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0048e2bb  d94710                 -fld dword ptr [edi + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(16) /* 0x10 */)));
    // 0048e2be  8b471c                 -mov eax, dword ptr [edi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */);
    // 0048e2c1  8b5f18                 -mov ebx, dword ptr [edi + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */);
    // 0048e2c4  dc07                   -fadd qword ptr [edi]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(cpu.edi));
    // 0048e2c6  01c3                   +add ebx, eax
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
    // 0048e2c8  dd1f                   +fstp qword ptr [edi]
    app->getMemory<double>(cpu.edi) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0048e2ca  895f18                 -mov dword ptr [edi + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 0048e2cd  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0048e2d1  d94714                 +fld dword ptr [edi + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(20) /* 0x14 */)));
    // 0048e2d4  dc4708                 +fadd qword ptr [edi + 8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(cpu.edi + x86::reg32(8) /* 0x8 */));
    // 0048e2d7  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0048e2d8  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0048e2dc  dd5f08                 +fstp qword ptr [edi + 8]
    app->getMemory<double>(cpu.edi + x86::reg32(8) /* 0x8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0048e2df  e93effffff             -jmp 0x48e222
    goto L_0x0048e222;
L_0x0048e2e4:
    // 0048e2e4  4d                     -dec ebp
    (cpu.ebp)--;
    // 0048e2e5  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0048e2e7  7c22                   -jl 0x48e30b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048e30b;
    }
    // 0048e2e9  83ee28                 -sub esi, 0x28
    (cpu.esi) -= x86::reg32(x86::sreg32(40 /*0x28*/));
L_0x0048e2ec:
    // 0048e2ec  3b6c241c               +cmp ebp, dword ptr [esp + 0x1c]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048e2f0  742a                   -je 0x48e31c
    if (cpu.flags.zf)
    {
        goto L_0x0048e31c;
    }
    // 0048e2f2  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0048e2f6  3b4620                 +cmp eax, dword ptr [esi + 0x20]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048e2f9  0f8eddfeffff           -jle 0x48e1dc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048e1dc;
    }
    // 0048e2ff  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0048e304  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0048e307  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e308  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e309  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e30a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048e30b:
    // 0048e30b  8b6c240c               -mov ebp, dword ptr [esp + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048e30f  6bc528                 -imul eax, ebp, 0x28
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(40 /*0x28*/)));
    // 0048e312  8b3504a74c00           -mov esi, dword ptr [0x4ca704]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5023492) /* 0x4ca704 */);
    // 0048e318  01c6                   +add esi, eax
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
    // 0048e31a  ebd0                   -jmp 0x48e2ec
    goto L_0x0048e2ec;
L_0x0048e31c:
    // 0048e31c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048e321  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0048e324  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e325  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e326  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e327  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048e328:
    // 0048e328  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0048e32c  40                     -inc eax
    (cpu.eax)++;
    // 0048e32d  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0048e331  39d0                   +cmp eax, edx
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
    // 0048e333  7c23                   -jl 0x48e358
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048e358;
    }
    // 0048e335  8b3d04a74c00           -mov edi, dword ptr [0x4ca704]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5023492) /* 0x4ca704 */);
    // 0048e33b  894c241c               -mov dword ptr [esp + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ecx;
L_0x0048e33f:
    // 0048e33f  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0048e343  3b4720                 +cmp eax, dword ptr [edi + 0x20]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048e346  0f8e9efeffff           -jle 0x48e1ea
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048e1ea;
    }
    // 0048e34c  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0048e351  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0048e354  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e355  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e356  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e357  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048e358:
    // 0048e358  83c728                 +add edi, 0x28
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(40 /*0x28*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048e35b  ebe2                   -jmp 0x48e33f
    goto L_0x0048e33f;
L_0x0048e35d:
    // 0048e35d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048e35f  e99efeffff             -jmp 0x48e202
    goto L_0x0048e202;
L_0x0048e364:
    // 0048e364  0f8d27ffffff           -jge 0x48e291
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048e291;
    }
    // 0048e36a  8b5f18                 -mov ebx, dword ptr [edi + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */);
    // 0048e36d  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0048e370  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0048e372  81e20000ffff           -and edx, 0xffff0000
    cpu.edx &= x86::reg32(x86::sreg32(4294901760 /*0xffff0000*/));
    // 0048e378  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048e37a  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0048e37d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048e37f  83f801                 +cmp eax, 1
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
    // 0048e382  7d05                   -jge 0x48e389
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048e389;
    }
    // 0048e384  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
L_0x0048e389:
    // 0048e389  d9048d302d5400         -fld dword ptr [ecx*4 + 0x542d30]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5516592) /* 0x542d30 */ + cpu.ecx * 4)));
    // 0048e390  dd06                   -fld qword ptr [esi]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esi)));
    // 0048e392  dc27                   -fsub qword ptr [edi]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<double>(cpu.edi));
    // 0048e394  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 0048e396  8b1500854c00           -mov edx, dword ptr [0x4c8500]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5014784) /* 0x4c8500 */);
    // 0048e39c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048e39e  d9050ca74c00           -fld dword ptr [0x4ca70c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5023500) /* 0x4ca70c */)));
    // 0048e3a4  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0048e3a6  d8c1                   -fadd st(1)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(1));
    // 0048e3a8  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0048e3ac  dd1dd0fa4c00           -fstp qword ptr [0x4cfad0]
    app->getMemory<double>(x86::reg32(5044944) /* 0x4cfad0 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0048e3b2  dd4608                 -fld qword ptr [esi + 8]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esi + x86::reg32(8) /* 0x8 */)));
    // 0048e3b5  dc6708                 -fsub qword ptr [edi + 8]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<double>(cpu.edi + x86::reg32(8) /* 0x8 */));
    // 0048e3b8  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0048e3bb  deca                   -fmulp st(2)
    cpu.fpu.st(2) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0048e3bd  031c82                 +add ebx, dword ptr [edx + eax*4]
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048e3c0  8b5708                 -mov edx, dword ptr [edi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0048e3c3  dec1                   +faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0048e3c5  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0048e3c7  dd1dd8fa4c00           +fstp qword ptr [0x4cfad8]
    app->getMemory<double>(x86::reg32(5044952) /* 0x4cfad8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0048e3cd  e9b9feffff             -jmp 0x48e28b
    goto L_0x0048e28b;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48e3d4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048e3d4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048e3d5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048e3d6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048e3d7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048e3d8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048e3d9  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048e3da  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048e3dc  bdffffffff             -mov ebp, 0xffffffff
    cpu.ebp = 4294967295 /*0xffffffff*/;
    // 0048e3e1  8b7004                 -mov esi, dword ptr [eax + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0048e3e4  e8c7810000             -call 0x4965b0
    cpu.esp -= 4;
    sub_4965b0(app, cpu);
    if (cpu.terminate) return;
    // 0048e3e9  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 0048e3ec  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048e3ee  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0048e3f0  0fbdc0                 -bsr eax, eax
    if (cpu.eax == 0)
    {
        cpu.flags.zf = 1;
    }
    else
    {
        cpu.flags.zf = 0;
        cpu.eax = x86::reg32(31 - __builtin_clz(cpu.eax));
    }
    // 0048e3f3  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048e3f5  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0048e3fc  892de4fa4c00           -mov dword ptr [0x4cfae4], ebp
    app->getMemory<x86::reg32>(x86::reg32(5044964) /* 0x4cfae4 */) = cpu.ebp;
    // 0048e402  39c6                   +cmp esi, eax
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
    // 0048e404  7e19                   -jle 0x48e41f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048e41f;
    }
L_0x0048e406:
    // 0048e406  833de4fa4c0000         +cmp dword ptr [0x4cfae4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5044964) /* 0x4cfae4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048e40d  7c27                   -jl 0x48e436
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048e436;
    }
    // 0048e40f  83c110                 -add ecx, 0x10
    (cpu.ecx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0048e412  890de0fa4c00           -mov dword ptr [0x4cfae0], ecx
    app->getMemory<x86::reg32>(x86::reg32(5044960) /* 0x4cfae0 */) = cpu.ecx;
    // 0048e418  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e419  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e41a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e41b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e41c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e41d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e41e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048e41f:
    // 0048e41f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048e421  0fbcc0                 -bsf eax, eax
    if (cpu.eax == 0)
    {
        cpu.flags.zf = 1;
    }
    else
    {
        cpu.flags.zf = 0;
        cpu.eax = x86::reg32(__builtin_ctz(cpu.eax));
    }
    // 0048e424  39c3                   +cmp ebx, eax
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
    // 0048e426  75de                   -jne 0x48e406
    if (!cpu.flags.zf)
    {
        goto L_0x0048e406;
    }
    // 0048e428  8b048510a74c00         -mov eax, dword ptr [eax*4 + 0x4ca710]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023504) /* 0x4ca710 */ + cpu.eax * 4);
    // 0048e42f  a3e4fa4c00             -mov dword ptr [0x4cfae4], eax
    app->getMemory<x86::reg32>(x86::reg32(5044964) /* 0x4cfae4 */) = cpu.eax;
    // 0048e434  ebd0                   -jmp 0x48e406
    goto L_0x0048e406;
L_0x0048e436:
    // 0048e436  a138a74c00             -mov eax, dword ptr [0x4ca738]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023544) /* 0x4ca738 */);
    // 0048e43b  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0048e43d  a3e4fa4c00             -mov dword ptr [0x4cfae4], eax
    app->getMemory<x86::reg32>(x86::reg32(5044964) /* 0x4cfae4 */) = cpu.eax;
    // 0048e442  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048e444  e8bff8ffff             -call 0x48dd08
    cpu.esp -= 4;
    sub_48dd08(app, cpu);
    if (cpu.terminate) return;
    // 0048e449  83c110                 -add ecx, 0x10
    (cpu.ecx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0048e44c  890de0fa4c00           -mov dword ptr [0x4cfae0], ecx
    app->getMemory<x86::reg32>(x86::reg32(5044960) /* 0x4cfae0 */) = cpu.ecx;
    // 0048e452  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e453  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e454  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e455  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e456  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e457  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e458  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48e45c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048e45c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048e45d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048e45e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048e45f  83ec3c                 -sub esp, 0x3c
    (cpu.esp) -= x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 0048e462  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0048e466  8954242c               -mov dword ptr [esp + 0x2c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.edx;
    // 0048e46a  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 0048e46e  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0048e472  8b542450               -mov edx, dword ptr [esp + 0x50]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 0048e476  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048e478  8b3504a74c00           -mov esi, dword ptr [0x4ca704]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5023492) /* 0x4ca704 */);
    // 0048e47e  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 0048e482  894c2414               -mov dword ptr [esp + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 0048e486  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0048e488  0f8498020000           -je 0x48e726
    if (cpu.flags.zf)
    {
        goto L_0x0048e726;
    }
L_0x0048e48e:
    // 0048e48e  8b049540a74c00         -mov eax, dword ptr [edx*4 + 0x4ca740]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023552) /* 0x4ca740 */ + cpu.edx * 4);
    // 0048e495  a33ca74c00             -mov dword ptr [0x4ca73c], eax
    app->getMemory<x86::reg32>(x86::reg32(5023548) /* 0x4ca73c */) = cpu.eax;
    // 0048e49a  8a25ec844c00           -mov ah, byte ptr [0x4c84ec]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5014764) /* 0x4c84ec */);
    // 0048e4a0  80fc0f                 +cmp ah, 0xf
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(15 /*0xf*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048e4a3  0f8587020000           -jne 0x48e730
    if (!cpu.flags.zf)
    {
        goto L_0x0048e730;
    }
L_0x0048e4a9:
    // 0048e4a9  8b049560a74c00         -mov eax, dword ptr [edx*4 + 0x4ca760]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023584) /* 0x4ca760 */ + cpu.edx * 4);
    // 0048e4b0  a33ca74c00             -mov dword ptr [0x4ca73c], eax
    app->getMemory<x86::reg32>(x86::reg32(5023548) /* 0x4ca73c */) = cpu.eax;
L_0x0048e4b5:
    // 0048e4b5  8b6c240c               -mov ebp, dword ptr [esp + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048e4b9  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048e4bd  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0048e4c2  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0048e4c4  8b4c242c               -mov ecx, dword ptr [esp + 0x2c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0048e4c8  897c2424               -mov dword ptr [esp + 0x24], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edi;
    // 0048e4cc  897c2428               -mov dword ptr [esp + 0x28], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edi;
    // 0048e4d0  897c2420               -mov dword ptr [esp + 0x20], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.edi;
    // 0048e4d4  8b6d04                 -mov ebp, dword ptr [ebp + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 0048e4d7  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048e4d9  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 0048e4db  89442438               -mov dword ptr [esp + 0x38], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 0048e4df  89442434               -mov dword ptr [esp + 0x34], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 0048e4e3  39d1                   +cmp ecx, edx
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
    // 0048e4e5  7e3a                   -jle 0x48e521
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048e521;
    }
    // 0048e4e7  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048e4eb  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x0048e4ee:
    // 0048e4ee  8b7004                 -mov esi, dword ptr [eax + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0048e4f1  39f7                   +cmp edi, esi
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
    // 0048e4f3  0f8e45020000           -jle 0x48e73e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048e73e;
    }
    // 0048e4f9  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 0048e4fb  89542424               -mov dword ptr [esp + 0x24], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edx;
L_0x0048e4ff:
    // 0048e4ff  8b742434               -mov esi, dword ptr [esp + 0x34]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0048e503  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 0048e505  39f3                   +cmp ebx, esi
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
    // 0048e507  0f8d40020000           -jge 0x48e74d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048e74d;
    }
    // 0048e50d  895c2434               -mov dword ptr [esp + 0x34], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.ebx;
    // 0048e511  89542420               -mov dword ptr [esp + 0x20], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.edx;
L_0x0048e515:
    // 0048e515  8b5c242c               -mov ebx, dword ptr [esp + 0x2c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0048e519  42                     -inc edx
    (cpu.edx)++;
    // 0048e51a  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0048e51d  39da                   +cmp edx, ebx
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
    // 0048e51f  7ccd                   -jl 0x48e4ee
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048e4ee;
    }
L_0x0048e521:
    // 0048e521  3b3de8844c00           +cmp edi, dword ptr [0x4c84e8]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014760) /* 0x4c84e8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048e527  0f8d37020000           -jge 0x48e764
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048e764;
    }
    // 0048e52d  3b2de0844c00           +cmp ebp, dword ptr [0x4c84e0]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014752) /* 0x4c84e0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048e533  0f8c2b020000           -jl 0x48e764
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048e764;
    }
    // 0048e539  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0048e53d  3b05e4844c00           +cmp eax, dword ptr [0x4c84e4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014756) /* 0x4c84e4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048e543  0f8d1b020000           -jge 0x48e764
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048e764;
    }
    // 0048e549  8b442438               -mov eax, dword ptr [esp + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0048e54d  3b05dc844c00           +cmp eax, dword ptr [0x4c84dc]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014748) /* 0x4c84dc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048e553  0f8c0b020000           -jl 0x48e764
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048e764;
    }
    // 0048e559  8b5c244c               -mov ebx, dword ptr [esp + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 0048e55d  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0048e55f  7554                   -jne 0x48e5b5
    if (!cpu.flags.zf)
    {
        goto L_0x0048e5b5;
    }
    // 0048e561  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0048e565  83e802                 -sub eax, 2
    (cpu.eax) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0048e568  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0048e56b  895c2430               -mov dword ptr [esp + 0x30], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.ebx;
    // 0048e56f  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
L_0x0048e573:
    // 0048e573  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0048e577  3b44241c               +cmp eax, dword ptr [esp + 0x1c]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048e57b  7d38                   -jge 0x48e5b5
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048e5b5;
    }
    // 0048e57d  8b742430               -mov esi, dword ptr [esp + 0x30]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0048e581  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048e585  8d5e08                 -lea ebx, [esi + 8]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0048e588  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048e58a  895c2430               -mov dword ptr [esp + 0x30], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.ebx;
    // 0048e58e  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0048e591  8b5e14                 -mov ebx, dword ptr [esi + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0048e594  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0048e596  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0048e599  2b4608                 -sub eax, dword ptr [esi + 8]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */)));
    // 0048e59c  2b5e0c                 -sub ebx, dword ptr [esi + 0xc]
    (cpu.ebx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */)));
    // 0048e59f  2b4e08                 -sub ecx, dword ptr [esi + 8]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */)));
    // 0048e5a2  2b560c                 -sub edx, dword ptr [esi + 0xc]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */)));
    // 0048e5a5  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0048e5a8  0fafd9                 -imul ebx, ecx
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0048e5ab  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0048e5ad  895c244c               -mov dword ptr [esp + 0x4c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */) = cpu.ebx;
    // 0048e5b1  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0048e5b3  74be                   -je 0x48e573
    if (cpu.flags.zf)
    {
        goto L_0x0048e573;
    }
L_0x0048e5b5:
    // 0048e5b5  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0048e5b9  3b05dc844c00           +cmp eax, dword ptr [0x4c84dc]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014748) /* 0x4c84dc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048e5bf  0f8caa010000           -jl 0x48e76f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048e76f;
    }
L_0x0048e5c5:
    // 0048e5c5  8b442438               -mov eax, dword ptr [esp + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0048e5c9  3b05e4844c00           +cmp eax, dword ptr [0x4c84e4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014756) /* 0x4c84e4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048e5cf  0f8dc1010000           -jge 0x48e796
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048e796;
    }
L_0x0048e5d5:
    // 0048e5d5  3b3de0844c00           +cmp edi, dword ptr [0x4c84e0]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014752) /* 0x4c84e0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048e5db  0f8cdc010000           -jl 0x48e7bd
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048e7bd;
    }
L_0x0048e5e1:
    // 0048e5e1  3b2de8844c00           +cmp ebp, dword ptr [0x4c84e8]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014760) /* 0x4c84e8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048e5e7  0f8df7010000           -jge 0x48e7e4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048e7e4;
    }
    // 0048e5ed  837c241400             +cmp dword ptr [esp + 0x14], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048e5f2  746c                   -je 0x48e660
    if (cpu.flags.zf)
    {
        goto L_0x0048e660;
    }
L_0x0048e5f4:
    // 0048e5f4  8b6c240c               -mov ebp, dword ptr [esp + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048e5f8  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048e5fc  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048e5fe  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0048e603  894c2424               -mov dword ptr [esp + 0x24], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ecx;
    // 0048e607  894c2428               -mov dword ptr [esp + 0x28], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ecx;
    // 0048e60b  894c2420               -mov dword ptr [esp + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 0048e60f  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048e611  8b6d04                 -mov ebp, dword ptr [ebp + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 0048e614  89442438               -mov dword ptr [esp + 0x38], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 0048e618  89442434               -mov dword ptr [esp + 0x34], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 0048e61c  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0048e620  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 0048e622  39d0                   +cmp eax, edx
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
    // 0048e624  7e3a                   -jle 0x48e660
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048e660;
    }
    // 0048e626  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048e62a  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x0048e62d:
    // 0048e62d  8b5804                 -mov ebx, dword ptr [eax + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0048e630  39df                   +cmp edi, ebx
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
    // 0048e632  0f8ed5010000           -jle 0x48e80d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048e80d;
    }
    // 0048e638  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0048e63a  89542424               -mov dword ptr [esp + 0x24], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edx;
L_0x0048e63e:
    // 0048e63e  8b4c2434               -mov ecx, dword ptr [esp + 0x34]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0048e642  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 0048e644  39cb                   +cmp ebx, ecx
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
    // 0048e646  0f8dd0010000           -jge 0x48e81c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048e81c;
    }
    // 0048e64c  895c2434               -mov dword ptr [esp + 0x34], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.ebx;
    // 0048e650  89542420               -mov dword ptr [esp + 0x20], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.edx;
L_0x0048e654:
    // 0048e654  8b4c242c               -mov ecx, dword ptr [esp + 0x2c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0048e658  42                     -inc edx
    (cpu.edx)++;
    // 0048e659  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0048e65c  39ca                   +cmp edx, ecx
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
    // 0048e65e  7ccd                   -jl 0x48e62d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048e62d;
    }
L_0x0048e660:
    // 0048e660  39ef                   +cmp edi, ebp
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
    // 0048e662  0f8dcb010000           -jge 0x48e833
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048e833;
    }
    // 0048e668  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0048e66c  8b54242c               -mov edx, dword ptr [esp + 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0048e670  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0048e672  48                     -dec eax
    (cpu.eax)--;
    // 0048e673  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048e675  7e29                   -jle 0x48e6a0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048e6a0;
    }
    // 0048e677  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
L_0x0048e679:
    // 0048e679  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048e67d  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048e681  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048e682  a104a74c00             -mov eax, dword ptr [0x4ca704]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023492) /* 0x4ca704 */);
    // 0048e687  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0048e689  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0048e68b  e8b0f7ffff             -call 0x48de40
    cpu.esp -= 4;
    sub_48de40(app, cpu);
    if (cpu.terminate) return;
    // 0048e690  8b4c242c               -mov ecx, dword ptr [esp + 0x2c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0048e694  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048e696  46                     -inc esi
    (cpu.esi)++;
    // 0048e697  83c528                 -add ebp, 0x28
    (cpu.ebp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 0048e69a  39ce                   +cmp esi, ecx
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
    // 0048e69c  7cdb                   -jl 0x48e679
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048e679;
    }
    // 0048e69e  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x0048e6a0:
    // 0048e6a0  8b742424               -mov esi, dword ptr [esp + 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0048e6a4  8d4601                 -lea eax, [esi + 1]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0048e6a7  8b5c242c               -mov ebx, dword ptr [esp + 0x2c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0048e6ab  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 0048e6af  39d8                   +cmp eax, ebx
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
    // 0048e6b1  7c06                   -jl 0x48e6b9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048e6b9;
    }
    // 0048e6b3  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0048e6b5  896c2428               -mov dword ptr [esp + 0x28], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ebp;
L_0x0048e6b9:
    // 0048e6b9  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0048e6bd  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048e6bf  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 0048e6c1  a0ed844c00             -mov al, byte ptr [0x4c84ed]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5014765) /* 0x4c84ed */);
    // 0048e6c6  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0048e6cc  39c2                   +cmp edx, eax
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
    // 0048e6ce  7415                   -je 0x48e6e5
    if (cpu.flags.zf)
    {
        goto L_0x0048e6e5;
    }
    // 0048e6d0  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048e6d2  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 0048e6d4  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0048e6d8  e8db440000             -call 0x492bb8
    cpu.esp -= 4;
    sub_492bb8(app, cpu);
    if (cpu.terminate) return;
    // 0048e6dd  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0048e6e1  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
L_0x0048e6e5:
    // 0048e6e5  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0048e6e9  e8e6fcffff             -call 0x48e3d4
    cpu.esp -= 4;
    sub_48e3d4(app, cpu);
    if (cpu.terminate) return;
    // 0048e6ee  837c244c00             +cmp dword ptr [esp + 0x4c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048e6f3  0f8c16020000           -jl 0x48e90f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048e90f;
    }
    // 0048e6f9  8b4c242c               -mov ecx, dword ptr [esp + 0x2c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0048e6fd  8b5c2428               -mov ebx, dword ptr [esp + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0048e701  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0048e703  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048e705  e81af8ffff             -call 0x48df24
    cpu.esp -= 4;
    sub_48df24(app, cpu);
    if (cpu.terminate) return;
L_0x0048e70a:
    // 0048e70a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048e70c  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0048e710  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048e712  7407                   -je 0x48e71b
    if (cpu.flags.zf)
    {
        goto L_0x0048e71b;
    }
    // 0048e714  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048e716  e8b1a3feff             -call 0x478acc
    cpu.esp -= 4;
    sub_478acc(app, cpu);
    if (cpu.terminate) return;
L_0x0048e71b:
    // 0048e71b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048e71d  83c43c                 +add esp, 0x3c
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(60 /*0x3c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048e720  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e721  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e722  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e723  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0048e726:
    // 0048e726  e845f5ffff             -call 0x48dc70
    cpu.esp -= 4;
    sub_48dc70(app, cpu);
    if (cpu.terminate) return;
    // 0048e72b  e95efdffff             -jmp 0x48e48e
    goto L_0x0048e48e;
L_0x0048e730:
    // 0048e730  80fc10                 +cmp ah, 0x10
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048e733  0f8470fdffff           -je 0x48e4a9
    if (cpu.flags.zf)
    {
        goto L_0x0048e4a9;
    }
    // 0048e739  e977fdffff             -jmp 0x48e4b5
    goto L_0x0048e4b5;
L_0x0048e73e:
    // 0048e73e  39f5                   +cmp ebp, esi
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048e740  0f8db9fdffff           -jge 0x48e4ff
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048e4ff;
    }
    // 0048e746  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 0048e748  e9b2fdffff             -jmp 0x48e4ff
    goto L_0x0048e4ff;
L_0x0048e74d:
    // 0048e74d  3b5c2438               +cmp ebx, dword ptr [esp + 0x38]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048e751  0f8ebefdffff           -jle 0x48e515
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048e515;
    }
    // 0048e757  895c2438               -mov dword ptr [esp + 0x38], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.ebx;
    // 0048e75b  89542428               -mov dword ptr [esp + 0x28], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 0048e75f  e9b1fdffff             -jmp 0x48e515
    goto L_0x0048e515;
L_0x0048e764:
    // 0048e764  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048e766  83c43c                 -add esp, 0x3c
    (cpu.esp) += x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 0048e769  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e76a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e76b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e76c  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0048e76f:
    // 0048e76f  8d5c2408               -lea ebx, [esp + 8]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048e773  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048e777  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0048e77b  e8b84a0100             -call 0x4a3238
    cpu.esp -= 4;
    sub_4a3238(app, cpu);
    if (cpu.terminate) return;
    // 0048e780  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0048e784  83f803                 +cmp eax, 3
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
    // 0048e787  7cdb                   -jl 0x48e764
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048e764;
    }
    // 0048e789  c744241401000000       -mov dword ptr [esp + 0x14], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = 1 /*0x1*/;
    // 0048e791  e92ffeffff             -jmp 0x48e5c5
    goto L_0x0048e5c5;
L_0x0048e796:
    // 0048e796  8d5c2408               -lea ebx, [esp + 8]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048e79a  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048e79e  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0048e7a2  e8f94b0100             -call 0x4a33a0
    cpu.esp -= 4;
    sub_4a33a0(app, cpu);
    if (cpu.terminate) return;
    // 0048e7a7  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0048e7ab  83f803                 +cmp eax, 3
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
    // 0048e7ae  7cb4                   -jl 0x48e764
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048e764;
    }
    // 0048e7b0  c744241401000000       -mov dword ptr [esp + 0x14], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = 1 /*0x1*/;
    // 0048e7b8  e918feffff             -jmp 0x48e5d5
    goto L_0x0048e5d5;
L_0x0048e7bd:
    // 0048e7bd  8d5c2408               -lea ebx, [esp + 8]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048e7c1  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048e7c5  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0048e7c9  e82a4d0100             -call 0x4a34f8
    cpu.esp -= 4;
    sub_4a34f8(app, cpu);
    if (cpu.terminate) return;
    // 0048e7ce  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0048e7d2  83f803                 +cmp eax, 3
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
    // 0048e7d5  7c8d                   -jl 0x48e764
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048e764;
    }
    // 0048e7d7  c744241401000000       -mov dword ptr [esp + 0x14], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = 1 /*0x1*/;
    // 0048e7df  e9fdfdffff             -jmp 0x48e5e1
    goto L_0x0048e5e1;
L_0x0048e7e4:
    // 0048e7e4  8d5c2408               -lea ebx, [esp + 8]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048e7e8  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048e7ec  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0048e7f0  e8634e0100             -call 0x4a3658
    cpu.esp -= 4;
    sub_4a3658(app, cpu);
    if (cpu.terminate) return;
    // 0048e7f5  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0048e7f9  83f803                 +cmp eax, 3
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
    // 0048e7fc  0f8df2fdffff           -jge 0x48e5f4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048e5f4;
    }
L_0x0048e802:
    // 0048e802  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048e804  83c43c                 -add esp, 0x3c
    (cpu.esp) += x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 0048e807  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e808  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e809  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e80a  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0048e80d:
    // 0048e80d  39dd                   +cmp ebp, ebx
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048e80f  0f8d29feffff           -jge 0x48e63e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048e63e;
    }
    // 0048e815  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0048e817  e922feffff             -jmp 0x48e63e
    goto L_0x0048e63e;
L_0x0048e81c:
    // 0048e81c  3b5c2438               +cmp ebx, dword ptr [esp + 0x38]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048e820  0f8e2efeffff           -jle 0x48e654
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048e654;
    }
    // 0048e826  895c2438               -mov dword ptr [esp + 0x38], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.ebx;
    // 0048e82a  89542428               -mov dword ptr [esp + 0x28], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 0048e82e  e921feffff             -jmp 0x48e654
    goto L_0x0048e654;
L_0x0048e833:
    // 0048e833  75cd                   -jne 0x48e802
    if (!cpu.flags.zf)
    {
        goto L_0x0048e802;
    }
    // 0048e835  837c244c00             +cmp dword ptr [esp + 0x4c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048e83a  0f8cc1000000           -jl 0x48e901
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048e901;
    }
    // 0048e840  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0048e842:
    // 0048e842  8b5c2420               -mov ebx, dword ptr [esp + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0048e846  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048e84a  c1e303                 -shl ebx, 3
    cpu.ebx <<= 3 /*0x3*/ % 32;
    // 0048e84d  8b3504a74c00           -mov esi, dword ptr [0x4ca704]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5023492) /* 0x4ca704 */);
    // 0048e853  db0403                 -fild dword ptr [ebx + eax]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + cpu.eax * 1))));
    // 0048e856  d9050ca74c00           -fld dword ptr [0x4ca70c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5023500) /* 0x4ca70c */)));
    // 0048e85c  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0048e863  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0048e865  d8c1                   -fadd st(1)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(1));
    // 0048e867  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048e869  dd1cc6                 -fstp qword ptr [esi + eax*8]
    app->getMemory<double>(cpu.esi + cpu.eax * 8) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0048e86c  035c2408               -add ebx, dword ptr [esp + 8]
    (cpu.ebx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 0048e870  db4304                 -fild dword ptr [ebx + 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */))));
    // 0048e873  c744c62401000000       -mov dword ptr [esi + eax*8 + 0x24], 1
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */ + cpu.eax * 8) = 1 /*0x1*/;
    // 0048e87b  8b5c2434               -mov ebx, dword ptr [esp + 0x34]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0048e87f  897cc620               -mov dword ptr [esi + eax*8 + 0x20], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */ + cpu.eax * 8) = cpu.edi;
    // 0048e883  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0048e885  c1e310                 -shl ebx, 0x10
    cpu.ebx <<= 16 /*0x10*/ % 32;
    // 0048e888  dd5cc608               -fstp qword ptr [esi + eax*8 + 8]
    app->getMemory<double>(cpu.esi + x86::reg32(8) /* 0x8 */ + cpu.eax * 8) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0048e88c  895cc618               -mov dword ptr [esi + eax*8 + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */ + cpu.eax * 8) = cpu.ebx;
    // 0048e890  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048e892  7577                   -jne 0x48e90b
    if (!cpu.flags.zf)
    {
        goto L_0x0048e90b;
    }
    // 0048e894  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x0048e899:
    // 0048e899  8b5c2428               -mov ebx, dword ptr [esp + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0048e89d  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048e8a1  c1e303                 -shl ebx, 3
    cpu.ebx <<= 3 /*0x3*/ % 32;
    // 0048e8a4  db0403                 -fild dword ptr [ebx + eax]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + cpu.eax * 1))));
    // 0048e8a7  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0048e8ae  d9050ca74c00           -fld dword ptr [0x4ca70c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5023500) /* 0x4ca70c */)));
    // 0048e8b4  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048e8b6  a104a74c00             -mov eax, dword ptr [0x4ca704]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023492) /* 0x4ca704 */);
    // 0048e8bb  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 0048e8be  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0048e8c0  d8c1                   -fadd st(1)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(1));
    // 0048e8c2  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048e8c4  dd18                   -fstp qword ptr [eax]
    app->getMemory<double>(cpu.eax) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0048e8c6  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048e8ca  8b542438               -mov edx, dword ptr [esp + 0x38]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0048e8ce  01f3                   -add ebx, esi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0048e8d0  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0048e8d3  db4304                 -fild dword ptr [ebx + 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */))));
    // 0048e8d6  c7402401000000         -mov dword ptr [eax + 0x24], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = 1 /*0x1*/;
    // 0048e8dd  895018                 -mov dword ptr [eax + 0x18], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 0048e8e0  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 0048e8e5  897820                 -mov dword ptr [eax + 0x20], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.edi;
    // 0048e8e8  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0048e8ea  896c2428               -mov dword ptr [esp + 0x28], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ebp;
    // 0048e8ee  dd5808                 -fstp qword ptr [eax + 8]
    app->getMemory<double>(cpu.eax + x86::reg32(8) /* 0x8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0048e8f1  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0048e8f6  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 0048e8f8  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0048e8fc  e9b8fdffff             -jmp 0x48e6b9
    goto L_0x0048e6b9;
L_0x0048e901:
    // 0048e901  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0048e906  e937ffffff             -jmp 0x48e842
    goto L_0x0048e842;
L_0x0048e90b:
    // 0048e90b  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0048e90d  eb8a                   -jmp 0x48e899
    goto L_0x0048e899;
L_0x0048e90f:
    // 0048e90f  8b4c242c               -mov ecx, dword ptr [esp + 0x2c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0048e913  8b5c2428               -mov ebx, dword ptr [esp + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0048e917  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0048e919  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048e91b  e860f8ffff             -call 0x48e180
    cpu.esp -= 4;
    sub_48e180(app, cpu);
    if (cpu.terminate) return;
    // 0048e920  e9e5fdffff             -jmp 0x48e70a
    goto L_0x0048e70a;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48e928(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048e928  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048e929  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048e92a  81ec00020000           -sub esp, 0x200
    (cpu.esp) -= x86::reg32(x86::sreg32(512 /*0x200*/));
    // 0048e930  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048e932  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0048e934  897c2418               -mov dword ptr [esp + 0x18], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 0048e938  897c240c               -mov dword ptr [esp + 0xc], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 0048e93c  897c2404               -mov dword ptr [esp + 4], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 0048e940  893c24                 -mov dword ptr [esp], edi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edi;
    // 0048e943  8b4002                 -mov eax, dword ptr [eax + 2]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0048e946  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0048e949  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0048e94c  48                     -dec eax
    (cpu.eax)--;
    // 0048e94d  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0048e951  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0048e955  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048e956  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0048e959  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048e95a  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0048e95d  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0048e95f  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0048e962  8d5c2408               -lea ebx, [esp + 8]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048e966  48                     -dec eax
    (cpu.eax)--;
    // 0048e967  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 0048e96c  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 0048e970  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0048e974  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048e976  e8e1faffff             -call 0x48e45c
    cpu.esp -= 4;
    sub_48e45c(app, cpu);
    if (cpu.terminate) return;
    // 0048e97b  81c400020000           -add esp, 0x200
    (cpu.esp) += x86::reg32(x86::sreg32(512 /*0x200*/));
    // 0048e981  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e982  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e983  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48e984(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048e984  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048e985  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048e986  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048e987  81ec04020000           -sub esp, 0x204
    (cpu.esp) -= x86::reg32(x86::sreg32(516 /*0x204*/));
    // 0048e98d  89842400020000         -mov dword ptr [esp + 0x200], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(512) /* 0x200 */) = cpu.eax;
    // 0048e994  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0048e996  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0048e998  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0048e99a  7e1c                   -jle 0x48e9b8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048e9b8;
    }
    // 0048e99c  8d0ced00000000         -lea ecx, [ebp*8]
    cpu.ecx = x86::reg32(cpu.ebp * 8);
    // 0048e9a3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0048e9a5:
    // 0048e9a5  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 0048e9a7  8d3c04                 -lea edi, [esp + eax]
    cpu.edi = x86::reg32(cpu.esp + cpu.eax * 1);
    // 0048e9aa  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0048e9ad  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048e9b0  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048e9b1  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048e9b2  39c8                   +cmp eax, ecx
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
    // 0048e9b4  7cef                   -jl 0x48e9a5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048e9a5;
    }
    // 0048e9b6  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x0048e9b8:
    // 0048e9b8  8b942418020000         -mov edx, dword ptr [esp + 0x218]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(536) /* 0x218 */);
    // 0048e9bf  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048e9c0  8b8c2418020000         -mov ecx, dword ptr [esp + 0x218]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(536) /* 0x218 */);
    // 0048e9c7  8b842404020000         -mov eax, dword ptr [esp + 0x204]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(516) /* 0x204 */);
    // 0048e9ce  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048e9cf  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0048e9d1  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048e9d5  e882faffff             -call 0x48e45c
    cpu.esp -= 4;
    sub_48e45c(app, cpu);
    if (cpu.terminate) return;
    // 0048e9da  81c404020000           -add esp, 0x204
    (cpu.esp) += x86::reg32(x86::sreg32(516 /*0x204*/));
    // 0048e9e0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e9e1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e9e2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048e9e3  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_48e9f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048e9f0  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048e9f2  7501                   -jne 0x48e9f5
    if (!cpu.flags.zf)
    {
        goto L_0x0048e9f5;
    }
    // 0048e9f4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048e9f5:
    // 0048e9f5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048e9f6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048e9f7  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0048e9f9  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 0048e9fa  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0048e9fc  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048e9fe  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048ea00  0facd010               -shrd eax, edx, 0x10
    {
        x86::reg32& destination = cpu.eax;
        destination >>= (16 /*0x10*/ % 32);
        destination |= cpu.edx  << (32 - (16 /*0x10*/ % 32));
    }
    // 0048ea04  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0048ea07  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0048ea09  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 0048ea0c  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0048ea0e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ea0f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ea10  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48ea14(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048ea14  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048ea15  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048ea16  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048ea17  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048ea18  81eca4000000           -sub esp, 0xa4
    (cpu.esp) -= x86::reg32(x86::sreg32(164 /*0xa4*/));
    // 0048ea1e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048ea20  89542434               -mov dword ptr [esp + 0x34], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.edx;
    // 0048ea24  895c244c               -mov dword ptr [esp + 0x4c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */) = cpu.ebx;
    // 0048ea28  8b4002                 -mov eax, dword ptr [eax + 2]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0048ea2b  ba71c34800             -mov edx, 0x48c371
    cpu.edx = 4768625 /*0x48c371*/;
    // 0048ea30  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0048ea33  8954247c               -mov dword ptr [esp + 0x7c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(124) /* 0x7c */) = cpu.edx;
    // 0048ea37  ba6c8a5200             -mov edx, 0x528a6c
    cpu.edx = 5409388 /*0x528a6c*/;
    // 0048ea3c  89842484000000         -mov dword ptr [esp + 0x84], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */) = cpu.eax;
    // 0048ea43  8d4110                 -lea eax, [ecx + 0x10]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0048ea46  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048ea48  e8c3d6ffff             -call 0x48c110
    cpu.esp -= 4;
    sub_48c110(app, cpu);
    if (cpu.terminate) return;
    // 0048ea4d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048ea4f  899c2488000000         -mov dword ptr [esp + 0x88], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */) = cpu.ebx;
    // 0048ea56  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048ea58  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 0048ea5b  8a8090a84c00           -mov al, byte ptr [eax + 0x4ca890]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5023888) /* 0x4ca890 */);
    // 0048ea61  83f820                 +cmp eax, 0x20
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
    // 0048ea64  750b                   -jne 0x48ea71
    if (!cpu.flags.zf)
    {
        goto L_0x0048ea71;
    }
    // 0048ea66  c784248800000002000000 -mov dword ptr [esp + 0x88], 2
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */) = 2 /*0x2*/;
L_0x0048ea71:
    // 0048ea71  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048ea73  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048ea75  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 0048ea78  8a8090a84c00           -mov al, byte ptr [eax + 0x4ca890]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5023888) /* 0x4ca890 */);
    // 0048ea7e  40                     -inc eax
    (cpu.eax)++;
    // 0048ea7f  24fe                   -and al, 0xfe
    cpu.al &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 0048ea81  83f810                 +cmp eax, 0x10
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
    // 0048ea84  750b                   -jne 0x48ea91
    if (!cpu.flags.zf)
    {
        goto L_0x0048ea91;
    }
    // 0048ea86  c784248800000001000000 -mov dword ptr [esp + 0x88], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */) = 1 /*0x1*/;
L_0x0048ea91:
    // 0048ea91  8b44244c               -mov eax, dword ptr [esp + 0x4c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 0048ea95  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0048ea97  8b54244c               -mov edx, dword ptr [esp + 0x4c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 0048ea9b  896c2440               -mov dword ptr [esp + 0x40], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = cpu.ebp;
    // 0048ea9f  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0048eaa2  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0048eaa5  896c243c               -mov dword ptr [esp + 0x3c], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.ebp;
    // 0048eaa9  39c8                   +cmp eax, ecx
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
    // 0048eaab  7e08                   -jle 0x48eab5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048eab5;
    }
    // 0048eaad  c744244001000000       -mov dword ptr [esp + 0x40], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = 1 /*0x1*/;
L_0x0048eab5:
    // 0048eab5  8b44243c               -mov eax, dword ptr [esp + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0048eab9  8b54244c               -mov edx, dword ptr [esp + 0x4c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 0048eabd  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0048eac0  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048eac2  8b44244c               -mov eax, dword ptr [esp + 0x4c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 0048eac6  8b7204                 -mov esi, dword ptr [edx + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0048eac9  3b700c                 +cmp esi, dword ptr [eax + 0xc]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048eacc  7e08                   -jle 0x48ead6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048ead6;
    }
    // 0048eace  c744243c01000000       -mov dword ptr [esp + 0x3c], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = 1 /*0x1*/;
L_0x0048ead6:
    // 0048ead6  8b442440               -mov eax, dword ptr [esp + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0048eada  8b6c244c               -mov ebp, dword ptr [esp + 0x4c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 0048eade  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0048eae1  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0048eae3  8b5514                 -mov edx, dword ptr [ebp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0048eae6  3b5004                 +cmp edx, dword ptr [eax + 4]
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
    // 0048eae9  7e08                   -jle 0x48eaf3
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048eaf3;
    }
    // 0048eaeb  c744244002000000       -mov dword ptr [esp + 0x40], 2
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = 2 /*0x2*/;
L_0x0048eaf3:
    // 0048eaf3  8b54243c               -mov edx, dword ptr [esp + 0x3c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0048eaf7  8b74244c               -mov esi, dword ptr [esp + 0x4c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 0048eafb  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 0048eafe  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0048eb00  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0048eb03  3b4204                 +cmp eax, dword ptr [edx + 4]
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
    // 0048eb06  7d08                   -jge 0x48eb10
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048eb10;
    }
    // 0048eb08  c744243c02000000       -mov dword ptr [esp + 0x3c], 2
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = 2 /*0x2*/;
L_0x0048eb10:
    // 0048eb10  8b44243c               -mov eax, dword ptr [esp + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0048eb14  0b442440               -or eax, dword ptr [esp + 0x40]
    cpu.eax |= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */)));
    // 0048eb18  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 0048eb1d  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0048eb1f  8b4c244c               -mov ecx, dword ptr [esp + 0x4c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 0048eb23  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0048eb27  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 0048eb2e  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0048eb30  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0048eb33  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048eb35  89542448               -mov dword ptr [esp + 0x48], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */) = cpu.edx;
    // 0048eb39  89442444               -mov dword ptr [esp + 0x44], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */) = cpu.eax;
    // 0048eb3d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048eb3f  8b542440               -mov edx, dword ptr [esp + 0x40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0048eb43  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 0048eb46  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0048eb48  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0048eb4a  8b4c243c               -mov ecx, dword ptr [esp + 0x3c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0048eb4e  c1e103                 -shl ecx, 3
    cpu.ecx <<= 3 /*0x3*/ % 32;
    // 0048eb51  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0048eb54  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0048eb56  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0048eb5a  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0048eb5c  2b01                   -sub eax, dword ptr [ecx]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx)));
    // 0048eb5e  8b6904                 -mov ebp, dword ptr [ecx + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0048eb61  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 0048eb65  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0048eb68  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0048eb6a  89442438               -mov dword ptr [esp + 0x38], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 0048eb6e  3d00000100             +cmp eax, 0x10000
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
    // 0048eb73  7d18                   -jge 0x48eb8d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048eb8d;
    }
    // 0048eb75  833d14824c0000         +cmp dword ptr [0x4c8214], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5014036) /* 0x4c8214 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048eb7c  750b                   -jne 0x48eb89
    if (!cpu.flags.zf)
    {
        goto L_0x0048eb89;
    }
L_0x0048eb7e:
    // 0048eb7e  81c4a4000000           +add esp, 0xa4
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(164 /*0xa4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048eb84  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048eb85  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048eb86  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048eb87  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048eb88  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048eb89:
    // 0048eb89  0f77                   -emms 
    cpu.mmx.init();
    // 0048eb8b  ebf1                   -jmp 0x48eb7e
    goto L_0x0048eb7e;
L_0x0048eb8d:
    // 0048eb8d  8b542448               -mov edx, dword ptr [esp + 0x48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0048eb91  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048eb93  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0048eb97  29ea                   -sub edx, ebp
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0048eb99  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0048eb9b  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0048eb9d  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0048eb9f  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0048eba1  8b4c2444               -mov ecx, dword ptr [esp + 0x44]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 0048eba5  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048eba7  89742420               -mov dword ptr [esp + 0x20], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.esi;
    // 0048ebab  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048ebad  89542428               -mov dword ptr [esp + 0x28], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 0048ebb1  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0048ebb3  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048ebb5  7c1e                   -jl 0x48ebd5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048ebd5;
    }
L_0x0048ebb7:
    // 0048ebb7  81f900000100           +cmp ecx, 0x10000
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
    // 0048ebbd  7d23                   -jge 0x48ebe2
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048ebe2;
    }
L_0x0048ebbf:
    // 0048ebbf  833d14824c0000         +cmp dword ptr [0x4c8214], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5014036) /* 0x4c8214 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048ebc6  74b6                   -je 0x48eb7e
    if (cpu.flags.zf)
    {
        goto L_0x0048eb7e;
    }
    // 0048ebc8  0f77                   -emms 
    cpu.mmx.init();
    // 0048ebca  81c4a4000000           -add esp, 0xa4
    (cpu.esp) += x86::reg32(x86::sreg32(164 /*0xa4*/));
    // 0048ebd0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ebd1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ebd2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ebd3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ebd4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048ebd5:
    // 0048ebd5  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 0048ebda  f7d9                   +neg ecx
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
    // 0048ebdc  896c2420               -mov dword ptr [esp + 0x20], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ebp;
    // 0048ebe0  ebd5                   -jmp 0x48ebb7
    goto L_0x0048ebb7;
L_0x0048ebe2:
    // 0048ebe2  81f900000006           +cmp ecx, 0x6000000
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(100663296 /*0x6000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048ebe8  7dd5                   -jge 0x48ebbf
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048ebbf;
    }
    // 0048ebea  8b442440               -mov eax, dword ptr [esp + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0048ebee  8b542434               -mov edx, dword ptr [esp + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0048ebf2  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0048ebf5  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048ebf7  8954242c               -mov dword ptr [esp + 0x2c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.edx;
    // 0048ebfb  8b54244c               -mov edx, dword ptr [esp + 0x4c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 0048ebff  8b7c243c               -mov edi, dword ptr [esp + 0x3c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0048ec03  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048ec05  8b442448               -mov eax, dword ptr [esp + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0048ec09  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 0048ec0d  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0048ec10  c1e703                 -shl edi, 3
    cpu.edi <<= 3 /*0x3*/ % 32;
    // 0048ec13  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0048ec15  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0048ec19  8b5c242c               -mov ebx, dword ptr [esp + 0x2c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0048ec1d  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 0048ec1f  8b2b                   -mov ebp, dword ptr [ebx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx);
    // 0048ec21  89442430               -mov dword ptr [esp + 0x30], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 0048ec25  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048ec27  8b5c2438               -mov ebx, dword ptr [esp + 0x38]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0048ec2b  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0048ec2d  8b6c242c               -mov ebp, dword ptr [esp + 0x2c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0048ec31  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0048ec33  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0048ec35  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0048ec39  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp);
    // 0048ec3c  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0048ec3f  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048ec41  2b542448               -sub edx, dword ptr [esp + 0x48]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */)));
    // 0048ec45  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0048ec49  8b5c242c               -mov ebx, dword ptr [esp + 0x2c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0048ec4d  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0048ec50  2b4304                 -sub eax, dword ptr [ebx + 4]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */)));
    // 0048ec53  8b5c2438               -mov ebx, dword ptr [esp + 0x38]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0048ec57  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0048ec59  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0048ec5b  8b54242c               -mov edx, dword ptr [esp + 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0048ec5f  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0048ec62  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048ec64  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0048ec68  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0048ec6b  8b542434               -mov edx, dword ptr [esp + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0048ec6f  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0048ec72  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048ec74  8954241c               -mov dword ptr [esp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 0048ec78  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0048ec7a  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0048ec7c  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0048ec7e  e86dfdffff             -call 0x48e9f0
    cpu.esp -= 4;
    sub_48e9f0(app, cpu);
    if (cpu.terminate) return;
    // 0048ec83  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048ec85  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0048ec89  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0048ec8c  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0048ec8f  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0048ec92  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048ec94  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0048ec96  41                     -inc ecx
    (cpu.ecx)++;
    // 0048ec97  e854fdffff             -call 0x48e9f0
    cpu.esp -= 4;
    sub_48e9f0(app, cpu);
    if (cpu.terminate) return;
    // 0048ec9c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048ec9d  8b8c2488000000         -mov ecx, dword ptr [esp + 0x88]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */);
    // 0048eca4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048eca5  8b6c2438               -mov ebp, dword ptr [esp + 0x38]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0048eca9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048ecaa  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0048ecac  bb00800000             -mov ebx, 0x8000
    cpu.ebx = 32768 /*0x8000*/;
    // 0048ecb1  b86c8a5200             -mov eax, 0x528a6c
    cpu.eax = 5409388 /*0x528a6c*/;
    // 0048ecb6  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0048ecb8  8b74243c               -mov esi, dword ptr [esp + 0x3c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0048ecbc  e84f840000             -call 0x497110
    cpu.esp -= 4;
    sub_497110(app, cpu);
    if (cpu.terminate) return;
    // 0048ecc1  8b4c244c               -mov ecx, dword ptr [esp + 0x4c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 0048ecc5  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0048ecc9  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0048eccb  8b36                   -mov esi, dword ptr [esi]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi);
    // 0048eccd  8b6d04                 -mov ebp, dword ptr [ebp + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 0048ecd0  8b5904                 -mov ebx, dword ptr [ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0048ecd3  8b39                   -mov edi, dword ptr [ecx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx);
    // 0048ecd5  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 0048ecd8  89bc249c000000         -mov dword ptr [esp + 0x9c], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */) = cpu.edi;
    // 0048ecdf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048ece1  0f8452010000           -je 0x48ee39
    if (cpu.flags.zf)
    {
        goto L_0x0048ee39;
    }
    // 0048ece7  8b542448               -mov edx, dword ptr [esp + 0x48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0048eceb  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0048ecee  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048ecf0  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0048ecf4  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0048ecf8  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048ecfa  2b02                   -sub eax, dword ptr [edx]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
    // 0048ecfc  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048ed00  e8ebfcffff             -call 0x48e9f0
    cpu.esp -= 4;
    sub_48e9f0(app, cpu);
    if (cpu.terminate) return;
    // 0048ed05  8984248c000000         -mov dword ptr [esp + 0x8c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */) = cpu.eax;
    // 0048ed0c  8b5104                 -mov edx, dword ptr [ecx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0048ed0f  8b4c2448               -mov ecx, dword ptr [esp + 0x48]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0048ed13  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0048ed17  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048ed19  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
L_0x0048ed1d:
    // 0048ed1d  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0048ed20  2b4104                 -sub eax, dword ptr [ecx + 4]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
    // 0048ed23  e8c8fcffff             -call 0x48e9f0
    cpu.esp -= 4;
    sub_48e9f0(app, cpu);
    if (cpu.terminate) return;
    // 0048ed28  89842490000000         -mov dword ptr [esp + 0x90], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(144) /* 0x90 */) = cpu.eax;
    // 0048ed2f  3b5c2414               +cmp ebx, dword ptr [esp + 0x14]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048ed33  0f8d25030000           -jge 0x48f05e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048f05e;
    }
    // 0048ed39  8b44243c               -mov eax, dword ptr [esp + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0048ed3d  8b54244c               -mov edx, dword ptr [esp + 0x4c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 0048ed41  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0048ed44  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0048ed48  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048ed4a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048ed4c  0f8438010000           -je 0x48ee8a
    if (cpu.flags.zf)
    {
        goto L_0x0048ee8a;
    }
    // 0048ed52  8b4c2448               -mov ecx, dword ptr [esp + 0x48]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0048ed56  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0048ed59  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048ed5b  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048ed5d  2b442444               -sub eax, dword ptr [esp + 0x44]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */)));
    // 0048ed61  e88afcffff             -call 0x48e9f0
    cpu.esp -= 4;
    sub_48e9f0(app, cpu);
    if (cpu.terminate) return;
    // 0048ed66  8b542438               -mov edx, dword ptr [esp + 0x38]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0048ed6a  89442468               -mov dword ptr [esp + 0x68], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */) = cpu.eax;
    // 0048ed6e  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0048ed72  e879fcffff             -call 0x48e9f0
    cpu.esp -= 4;
    sub_48e9f0(app, cpu);
    if (cpu.terminate) return;
    // 0048ed77  89442460               -mov dword ptr [esp + 0x60], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */) = cpu.eax;
L_0x0048ed7b:
    // 0048ed7b  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0048ed7f  a1e8844c00             -mov eax, dword ptr [0x4c84e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5014760) /* 0x4c84e8 */);
    // 0048ed84  39d0                   +cmp eax, edx
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
    // 0048ed86  7d02                   -jge 0x48ed8a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048ed8a;
    }
    // 0048ed88  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x0048ed8a:
    // 0048ed8a  8b0de0844c00           -mov ecx, dword ptr [0x4c84e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5014752) /* 0x4c84e0 */);
    // 0048ed90  89542450               -mov dword ptr [esp + 0x50], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */) = cpu.edx;
    // 0048ed94  39cb                   +cmp ebx, ecx
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
    // 0048ed96  0f8d1c010000           -jge 0x48eeb8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048eeb8;
    }
L_0x0048ed9c:
    // 0048ed9c  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 0048eda3  89442474               -mov dword ptr [esp + 0x74], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */) = cpu.eax;
L_0x0048eda7:
    // 0048eda7  3b5c2450               +cmp ebx, dword ptr [esp + 0x50]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048edab  0f8dad020000           -jge 0x48f05e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048f05e;
    }
    // 0048edb1  8b94249c000000         -mov edx, dword ptr [esp + 0x9c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */);
    // 0048edb8  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048edba  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0048edbd  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0048edc0  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048edc2  8d0c02                 -lea ecx, [edx + eax]
    cpu.ecx = x86::reg32(cpu.edx + cpu.eax * 1);
    // 0048edc5  2b0de4844c00           -sub ecx, dword ptr [0x4c84e4]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014756) /* 0x4c84e4 */)));
    // 0048edcb  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048edcd  7e02                   -jle 0x48edd1
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048edd1;
    }
    // 0048edcf  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0048edd1:
    // 0048edd1  8b0ddc844c00           -mov ecx, dword ptr [0x4c84dc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5014748) /* 0x4c84dc */);
    // 0048edd7  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048edd9  898c2494000000         -mov dword ptr [esp + 0x94], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(148) /* 0x94 */) = cpu.ecx;
    // 0048ede0  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048ede2  0f8e01020000           -jle 0x48efe9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048efe9;
    }
    // 0048ede8  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048edea  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
L_0x0048edec:
    // 0048edec  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048edee  7e0c                   -jle 0x48edfc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048edfc;
    }
    // 0048edf0  3b1de0844c00           +cmp ebx, dword ptr [0x4c84e0]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014752) /* 0x4c84e0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048edf6  0f8dfb010000           -jge 0x48eff7
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048eff7;
    }
L_0x0048edfc:
    // 0048edfc  8b84248c000000         -mov eax, dword ptr [esp + 0x8c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 0048ee03  8b942490000000         -mov edx, dword ptr [esp + 0x90]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(144) /* 0x90 */);
    // 0048ee0a  8b8c249c000000         -mov ecx, dword ptr [esp + 0x9c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */);
    // 0048ee11  43                     -inc ebx
    (cpu.ebx)++;
    // 0048ee12  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048ee14  01d5                   -add ebp, edx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048ee16  8b542474               -mov edx, dword ptr [esp + 0x74]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 0048ee1a  8b442468               -mov eax, dword ptr [esp + 0x68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 0048ee1e  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048ee21  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048ee23  8b442460               -mov eax, dword ptr [esp + 0x60]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 0048ee27  898c249c000000         -mov dword ptr [esp + 0x9c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */) = cpu.ecx;
    // 0048ee2e  89542474               -mov dword ptr [esp + 0x74], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */) = cpu.edx;
    // 0048ee32  01c7                   +add edi, eax
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
    // 0048ee34  e96effffff             -jmp 0x48eda7
    goto L_0x0048eda7;
L_0x0048ee39:
    // 0048ee39  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0048ee3c  898424a0000000         -mov dword ptr [esp + 0xa0], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(160) /* 0xa0 */) = cpu.eax;
    // 0048ee43  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0048ee47  8b9424a0000000         -mov edx, dword ptr [esp + 0xa0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(160) /* 0xa0 */);
    // 0048ee4e  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0048ee51  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0048ee53  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0048ee57  8b54242c               -mov edx, dword ptr [esp + 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0048ee5b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048ee5d  2b02                   -sub eax, dword ptr [edx]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
    // 0048ee5f  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048ee63  e888fbffff             -call 0x48e9f0
    cpu.esp -= 4;
    sub_48e9f0(app, cpu);
    if (cpu.terminate) return;
    // 0048ee68  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0048ee6c  8984248c000000         -mov dword ptr [esp + 0x8c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */) = cpu.eax;
    // 0048ee73  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0048ee76  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0048ee79  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048ee7b  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0048ee7f  29ca                   +sub edx, ecx
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048ee81  8b4c242c               -mov ecx, dword ptr [esp + 0x2c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0048ee85  e993feffff             -jmp 0x48ed1d
    goto L_0x0048ed1d;
L_0x0048ee8a:
    // 0048ee8a  8b4c2448               -mov ecx, dword ptr [esp + 0x48]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0048ee8e  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0048ee91  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048ee93  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048ee95  2b442444               +sub eax, dword ptr [esp + 0x44]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048ee99  e852fbffff             -call 0x48e9f0
    cpu.esp -= 4;
    sub_48e9f0(app, cpu);
    if (cpu.terminate) return;
    // 0048ee9e  8b542438               -mov edx, dword ptr [esp + 0x38]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0048eea2  89442460               -mov dword ptr [esp + 0x60], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */) = cpu.eax;
    // 0048eea6  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0048eeaa  e841fbffff             -call 0x48e9f0
    cpu.esp -= 4;
    sub_48e9f0(app, cpu);
    if (cpu.terminate) return;
    // 0048eeaf  89442468               -mov dword ptr [esp + 0x68], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */) = cpu.eax;
    // 0048eeb3  e9c3feffff             -jmp 0x48ed7b
    goto L_0x0048ed7b;
L_0x0048eeb8:
    // 0048eeb8  8b44243c               -mov eax, dword ptr [esp + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0048eebc  8b4c2434               -mov ecx, dword ptr [esp + 0x34]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0048eec0  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0048eec3  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0048eec5  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0048eec7  3b0ddc844c00           +cmp ecx, dword ptr [0x4c84dc]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014748) /* 0x4c84dc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048eecd  0f8cc9feffff           -jl 0x48ed9c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048ed9c;
    }
    // 0048eed3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048eed5  3b05e4844c00           +cmp eax, dword ptr [0x4c84e4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014756) /* 0x4c84e4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048eedb  0f8dbbfeffff           -jge 0x48ed9c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048ed9c;
    }
    // 0048eee1  8b442444               -mov eax, dword ptr [esp + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 0048eee5  3b05dc844c00           +cmp eax, dword ptr [0x4c84dc]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014748) /* 0x4c84dc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048eeeb  0f8cabfeffff           -jl 0x48ed9c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048ed9c;
    }
    // 0048eef1  3b05e4844c00           +cmp eax, dword ptr [0x4c84e4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014756) /* 0x4c84e4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048eef7  0f8d9ffeffff           -jge 0x48ed9c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048ed9c;
    }
    // 0048eefd  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0048ef01  3b05dc844c00           +cmp eax, dword ptr [0x4c84dc]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014748) /* 0x4c84dc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048ef07  0f8c8ffeffff           -jl 0x48ed9c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048ed9c;
    }
    // 0048ef0d  3b05e4844c00           +cmp eax, dword ptr [0x4c84e4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014756) /* 0x4c84e4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048ef13  0f8d83feffff           -jge 0x48ed9c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048ed9c;
    }
    // 0048ef19  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 0048ef20  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0048ef23  89842480000000         -mov dword ptr [esp + 0x80], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(128) /* 0x80 */) = cpu.eax;
    // 0048ef2a  8954245c               -mov dword ptr [esp + 0x5c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */) = cpu.edx;
L_0x0048ef2e:
    // 0048ef2e  8b842480000000         -mov eax, dword ptr [esp + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 0048ef35  3b44245c               +cmp eax, dword ptr [esp + 0x5c]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048ef39  0f8d1f010000           -jge 0x48f05e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048f05e;
    }
    // 0048ef3f  8b84249c000000         -mov eax, dword ptr [esp + 0x9c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */);
    // 0048ef46  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0048ef48  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0048ef4b  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0048ef4e  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0048ef50  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048ef52  7e52                   -jle 0x48efa6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048efa6;
    }
    // 0048ef54  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048ef55  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0048ef57  8b8c2488000000         -mov ecx, dword ptr [esp + 0x88]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */);
    // 0048ef5e  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0048ef61  0fafca                 -imul ecx, edx
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0048ef64  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0048ef66  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0048ef69  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048ef6b  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0048ef6f  8a8c248c000000         -mov cl, byte ptr [esp + 0x8c]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 0048ef76  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048ef7a  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 0048ef7c  8b8c2484000000         -mov ecx, dword ptr [esp + 0x84]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */);
    // 0048ef83  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048ef84  8b15fc844c00           -mov edx, dword ptr [0x4c84fc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5014780) /* 0x4c84fc */);
    // 0048ef8a  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0048ef8d  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048ef8f  8b1500854c00           -mov edx, dword ptr [0x4c8500]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5014784) /* 0x4c8500 */);
    // 0048ef95  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048ef97  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 0048ef99  0302                   -add eax, dword ptr [edx]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
    // 0048ef9b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048ef9c  ff942488000000         -call dword ptr [esp + 0x88]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048efa3  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x0048efa6:
    // 0048efa6  8b84248c000000         -mov eax, dword ptr [esp + 0x8c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 0048efad  8b942490000000         -mov edx, dword ptr [esp + 0x90]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(144) /* 0x90 */);
    // 0048efb4  8b8c249c000000         -mov ecx, dword ptr [esp + 0x9c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */);
    // 0048efbb  43                     -inc ebx
    (cpu.ebx)++;
    // 0048efbc  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048efbe  01d5                   -add ebp, edx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048efc0  8b942480000000         -mov edx, dword ptr [esp + 0x80]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 0048efc7  8b442468               -mov eax, dword ptr [esp + 0x68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 0048efcb  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048efce  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048efd0  8b442460               -mov eax, dword ptr [esp + 0x60]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 0048efd4  898c249c000000         -mov dword ptr [esp + 0x9c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */) = cpu.ecx;
    // 0048efdb  89942480000000         -mov dword ptr [esp + 0x80], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(128) /* 0x80 */) = cpu.edx;
    // 0048efe2  01c7                   +add edi, eax
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
    // 0048efe4  e945ffffff             -jmp 0x48ef2e
    goto L_0x0048ef2e;
L_0x0048efe9:
    // 0048efe9  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0048efeb  898c2494000000         -mov dword ptr [esp + 0x94], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(148) /* 0x94 */) = cpu.ecx;
    // 0048eff2  e9f5fdffff             -jmp 0x48edec
    goto L_0x0048edec;
L_0x0048eff7:
    // 0048eff7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048eff8  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048effa  8b8c2488000000         -mov ecx, dword ptr [esp + 0x88]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */);
    // 0048f001  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0048f004  0fafc1                 -imul eax, ecx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0048f007  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0048f009  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0048f00c  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048f00e  8b842498000000         -mov eax, dword ptr [esp + 0x98]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(152) /* 0x98 */);
    // 0048f015  030c856c8a5200         -add ecx, dword ptr [eax*4 + 0x528a6c]
    (cpu.ecx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5409388) /* 0x528a6c */ + cpu.eax * 4)));
    // 0048f01c  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0048f01f  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0048f023  8a8c248c000000         -mov cl, byte ptr [esp + 0x8c]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 0048f02a  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048f02e  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0048f032  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0048f034  8b4c2478               -mov ecx, dword ptr [esp + 0x78]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 0048f038  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048f039  a1fc844c00             -mov eax, dword ptr [0x4c84fc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5014780) /* 0x4c84fc */);
    // 0048f03e  8b1500854c00           -mov edx, dword ptr [0x4c8500]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5014784) /* 0x4c8500 */);
    // 0048f044  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0048f046  0354240c               -add edx, dword ptr [esp + 0xc]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 0048f04a  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048f04c  0302                   -add eax, dword ptr [edx]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
    // 0048f04e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048f04f  ff942488000000         -call dword ptr [esp + 0x88]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048f056  83c40c                 +add esp, 0xc
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
    // 0048f059  e99efdffff             -jmp 0x48edfc
    goto L_0x0048edfc;
L_0x0048f05e:
    // 0048f05e  8b442440               -mov eax, dword ptr [esp + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0048f062  8b4c244c               -mov ecx, dword ptr [esp + 0x4c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 0048f066  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0048f069  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048f06b  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0048f06f  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0048f072  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0048f075  39c3                   +cmp ebx, eax
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
    // 0048f077  0f8d5a030000           -jge 0x48f3d7
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048f3d7;
    }
    // 0048f07d  837c242000             +cmp dword ptr [esp + 0x20], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048f082  0f8471010000           -je 0x48f1f9
    if (cpu.flags.zf)
    {
        goto L_0x0048f1f9;
    }
    // 0048f088  8b542448               -mov edx, dword ptr [esp + 0x48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0048f08c  8b442444               -mov eax, dword ptr [esp + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 0048f090  8b6904                 -mov ebp, dword ptr [ecx + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0048f093  8b31                   -mov esi, dword ptr [ecx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx);
    // 0048f095  29ea                   -sub edx, ebp
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0048f097  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0048f099  e852f9ffff             -call 0x48e9f0
    cpu.esp -= 4;
    sub_48e9f0(app, cpu);
    if (cpu.terminate) return;
    // 0048f09e  8b542438               -mov edx, dword ptr [esp + 0x38]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0048f0a2  89442464               -mov dword ptr [esp + 0x64], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */) = cpu.eax;
    // 0048f0a6  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0048f0aa  e841f9ffff             -call 0x48e9f0
    cpu.esp -= 4;
    sub_48e9f0(app, cpu);
    if (cpu.terminate) return;
    // 0048f0af  8944246c               -mov dword ptr [esp + 0x6c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */) = cpu.eax;
    // 0048f0b3  8b442444               -mov eax, dword ptr [esp + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 0048f0b7  8984249c000000         -mov dword ptr [esp + 0x9c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */) = cpu.eax;
    // 0048f0be  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0048f0c2  8b542434               -mov edx, dword ptr [esp + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0048f0c6  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0048f0c9  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048f0cb  8b442448               -mov eax, dword ptr [esp + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0048f0cf  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0048f0d3  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 0048f0d5  8b6a04                 -mov ebp, dword ptr [edx + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0048f0d8  2b4104                 -sub eax, dword ptr [ecx + 4]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
    // 0048f0db  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048f0df  898424a0000000         -mov dword ptr [esp + 0xa0], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(160) /* 0xa0 */) = cpu.eax;
    // 0048f0e6  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0048f0ea  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048f0ec  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0048f0f0  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048f0f4  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048f0f6  2b02                   -sub eax, dword ptr [edx]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
    // 0048f0f8  8b9424a0000000         -mov edx, dword ptr [esp + 0xa0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(160) /* 0xa0 */);
    // 0048f0ff  e8ecf8ffff             -call 0x48e9f0
    cpu.esp -= 4;
    sub_48e9f0(app, cpu);
    if (cpu.terminate) return;
    // 0048f104  8b542448               -mov edx, dword ptr [esp + 0x48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0048f108  8984248c000000         -mov dword ptr [esp + 0x8c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */) = cpu.eax;
    // 0048f10f  2b5104                 -sub edx, dword ptr [ecx + 4]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
    // 0048f112  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048f116  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048f11a  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0048f11d  2b4104                 -sub eax, dword ptr [ecx + 4]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
    // 0048f120  e8cbf8ffff             -call 0x48e9f0
    cpu.esp -= 4;
    sub_48e9f0(app, cpu);
    if (cpu.terminate) return;
    // 0048f125  89842490000000         -mov dword ptr [esp + 0x90], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(144) /* 0x90 */) = cpu.eax;
L_0x0048f12c:
    // 0048f12c  8b542440               -mov edx, dword ptr [esp + 0x40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0048f130  8b4c244c               -mov ecx, dword ptr [esp + 0x4c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 0048f134  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 0048f137  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0048f139  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0048f13c  a1e8844c00             -mov eax, dword ptr [0x4c84e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5014760) /* 0x4c84e8 */);
    // 0048f141  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0048f144  39c2                   +cmp edx, eax
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
    // 0048f146  7e02                   -jle 0x48f14a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048f14a;
    }
    // 0048f148  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x0048f14a:
    // 0048f14a  8b0de0844c00           -mov ecx, dword ptr [0x4c84e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5014752) /* 0x4c84e0 */);
    // 0048f150  89542454               -mov dword ptr [esp + 0x54], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */) = cpu.edx;
    // 0048f154  39cb                   +cmp ebx, ecx
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
    // 0048f156  0f8dcf000000           -jge 0x48f22b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048f22b;
    }
L_0x0048f15c:
    // 0048f15c  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 0048f163  89442470               -mov dword ptr [esp + 0x70], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */) = cpu.eax;
L_0x0048f167:
    // 0048f167  3b5c2454               +cmp ebx, dword ptr [esp + 0x54]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048f16b  0f8d66020000           -jge 0x48f3d7
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048f3d7;
    }
    // 0048f171  8b94249c000000         -mov edx, dword ptr [esp + 0x9c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */);
    // 0048f178  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048f17a  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0048f17d  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0048f180  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048f182  8d0c02                 -lea ecx, [edx + eax]
    cpu.ecx = x86::reg32(cpu.edx + cpu.eax * 1);
    // 0048f185  2b0de4844c00           -sub ecx, dword ptr [0x4c84e4]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014756) /* 0x4c84e4 */)));
    // 0048f18b  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048f18d  7e02                   -jle 0x48f191
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048f191;
    }
    // 0048f18f  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0048f191:
    // 0048f191  8b0ddc844c00           -mov ecx, dword ptr [0x4c84dc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5014748) /* 0x4c84dc */);
    // 0048f197  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048f199  898c2498000000         -mov dword ptr [esp + 0x98], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(152) /* 0x98 */) = cpu.ecx;
    // 0048f1a0  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048f1a2  0f8ebb010000           -jle 0x48f363
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048f363;
    }
    // 0048f1a8  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048f1aa  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
L_0x0048f1ac:
    // 0048f1ac  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048f1ae  7e0c                   -jle 0x48f1bc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048f1bc;
    }
    // 0048f1b0  3b1de0844c00           +cmp ebx, dword ptr [0x4c84e0]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014752) /* 0x4c84e0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048f1b6  0f8db5010000           -jge 0x48f371
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048f371;
    }
L_0x0048f1bc:
    // 0048f1bc  8b84248c000000         -mov eax, dword ptr [esp + 0x8c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 0048f1c3  8b942490000000         -mov edx, dword ptr [esp + 0x90]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(144) /* 0x90 */);
    // 0048f1ca  8b8c249c000000         -mov ecx, dword ptr [esp + 0x9c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */);
    // 0048f1d1  43                     -inc ebx
    (cpu.ebx)++;
    // 0048f1d2  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048f1d4  01d5                   -add ebp, edx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048f1d6  8b542470               -mov edx, dword ptr [esp + 0x70]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */);
    // 0048f1da  8b442464               -mov eax, dword ptr [esp + 0x64]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 0048f1de  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048f1e1  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048f1e3  8b44246c               -mov eax, dword ptr [esp + 0x6c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */);
    // 0048f1e7  898c249c000000         -mov dword ptr [esp + 0x9c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */) = cpu.ecx;
    // 0048f1ee  89542470               -mov dword ptr [esp + 0x70], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */) = cpu.edx;
    // 0048f1f2  01c7                   +add edi, eax
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
    // 0048f1f4  e96effffff             -jmp 0x48f167
    goto L_0x0048f167;
L_0x0048f1f9:
    // 0048f1f9  8b542448               -mov edx, dword ptr [esp + 0x48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0048f1fd  8b7904                 -mov edi, dword ptr [ecx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0048f200  8b442444               -mov eax, dword ptr [esp + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 0048f204  29fa                   -sub edx, edi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0048f206  2b01                   +sub eax, dword ptr [ecx]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048f208  e8e3f7ffff             -call 0x48e9f0
    cpu.esp -= 4;
    sub_48e9f0(app, cpu);
    if (cpu.terminate) return;
    // 0048f20d  8b542438               -mov edx, dword ptr [esp + 0x38]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0048f211  8944246c               -mov dword ptr [esp + 0x6c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */) = cpu.eax;
    // 0048f215  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0048f219  8b7c2444               -mov edi, dword ptr [esp + 0x44]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 0048f21d  e8cef7ffff             -call 0x48e9f0
    cpu.esp -= 4;
    sub_48e9f0(app, cpu);
    if (cpu.terminate) return;
    // 0048f222  89442464               -mov dword ptr [esp + 0x64], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */) = cpu.eax;
    // 0048f226  e901ffffff             -jmp 0x48f12c
    goto L_0x0048f12c;
L_0x0048f22b:
    // 0048f22b  8b442440               -mov eax, dword ptr [esp + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0048f22f  8b4c2434               -mov ecx, dword ptr [esp + 0x34]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0048f233  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0048f236  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0048f238  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0048f23a  3b0ddc844c00           +cmp ecx, dword ptr [0x4c84dc]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014748) /* 0x4c84dc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048f240  0f8c16ffffff           -jl 0x48f15c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048f15c;
    }
    // 0048f246  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048f248  3b05e4844c00           +cmp eax, dword ptr [0x4c84e4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014756) /* 0x4c84e4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048f24e  0f8d08ffffff           -jge 0x48f15c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048f15c;
    }
    // 0048f254  8b442444               -mov eax, dword ptr [esp + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 0048f258  3b05dc844c00           +cmp eax, dword ptr [0x4c84dc]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014748) /* 0x4c84dc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048f25e  0f8cf8feffff           -jl 0x48f15c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048f15c;
    }
    // 0048f264  3b05e4844c00           +cmp eax, dword ptr [0x4c84e4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014756) /* 0x4c84e4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048f26a  0f8decfeffff           -jge 0x48f15c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048f15c;
    }
    // 0048f270  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0048f274  3b05dc844c00           +cmp eax, dword ptr [0x4c84dc]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014748) /* 0x4c84dc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048f27a  0f8cdcfeffff           -jl 0x48f15c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048f15c;
    }
    // 0048f280  3b05e4844c00           +cmp eax, dword ptr [0x4c84e4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014756) /* 0x4c84e4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048f286  0f8dd0feffff           -jge 0x48f15c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048f15c;
    }
    // 0048f28c  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 0048f293  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0048f296  89442478               -mov dword ptr [esp + 0x78], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */) = cpu.eax;
    // 0048f29a  89542458               -mov dword ptr [esp + 0x58], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */) = cpu.edx;
L_0x0048f29e:
    // 0048f29e  8b442478               -mov eax, dword ptr [esp + 0x78]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 0048f2a2  3b442458               +cmp eax, dword ptr [esp + 0x58]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048f2a6  0f8d2b010000           -jge 0x48f3d7
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048f3d7;
    }
    // 0048f2ac  8b84249c000000         -mov eax, dword ptr [esp + 0x9c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */);
    // 0048f2b3  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0048f2b5  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0048f2b8  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0048f2bb  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0048f2bd  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048f2bf  7e65                   -jle 0x48f326
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048f326;
    }
    // 0048f2c1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048f2c2  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0048f2c4  8b8c2488000000         -mov ecx, dword ptr [esp + 0x88]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */);
    // 0048f2cb  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0048f2ce  0fafca                 -imul ecx, edx
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0048f2d1  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0048f2d3  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0048f2d6  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048f2d8  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0048f2db  898c24a4000000         -mov dword ptr [esp + 0xa4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(164) /* 0xa4 */) = cpu.ecx;
    // 0048f2e2  8a8c248c000000         -mov cl, byte ptr [esp + 0x8c]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 0048f2e9  8b9424a4000000         -mov edx, dword ptr [esp + 0xa4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(164) /* 0xa4 */);
    // 0048f2f0  898424a4000000         -mov dword ptr [esp + 0xa4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(164) /* 0xa4 */) = cpu.eax;
    // 0048f2f7  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 0048f2f9  8b0dfc844c00           -mov ecx, dword ptr [0x4c84fc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5014780) /* 0x4c84fc */);
    // 0048f2ff  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048f300  8b942480000000         -mov edx, dword ptr [esp + 0x80]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 0048f307  a100854c00             -mov eax, dword ptr [0x4c8500]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5014784) /* 0x4c8500 */);
    // 0048f30c  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048f30e  8b9424a8000000         -mov edx, dword ptr [esp + 0xa8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(168) /* 0xa8 */);
    // 0048f315  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048f317  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 0048f319  0302                   -add eax, dword ptr [edx]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
    // 0048f31b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048f31c  ff942488000000         -call dword ptr [esp + 0x88]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048f323  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x0048f326:
    // 0048f326  8b84248c000000         -mov eax, dword ptr [esp + 0x8c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 0048f32d  8b942490000000         -mov edx, dword ptr [esp + 0x90]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(144) /* 0x90 */);
    // 0048f334  8b8c249c000000         -mov ecx, dword ptr [esp + 0x9c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */);
    // 0048f33b  43                     -inc ebx
    (cpu.ebx)++;
    // 0048f33c  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048f33e  01d5                   -add ebp, edx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048f340  8b542478               -mov edx, dword ptr [esp + 0x78]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 0048f344  8b442464               -mov eax, dword ptr [esp + 0x64]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 0048f348  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048f34b  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048f34d  8b44246c               -mov eax, dword ptr [esp + 0x6c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */);
    // 0048f351  898c249c000000         -mov dword ptr [esp + 0x9c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */) = cpu.ecx;
    // 0048f358  89542478               -mov dword ptr [esp + 0x78], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */) = cpu.edx;
    // 0048f35c  01c7                   +add edi, eax
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
    // 0048f35e  e93bffffff             -jmp 0x48f29e
    goto L_0x0048f29e;
L_0x0048f363:
    // 0048f363  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0048f365  898c2498000000         -mov dword ptr [esp + 0x98], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(152) /* 0x98 */) = cpu.ecx;
    // 0048f36c  e93bfeffff             -jmp 0x48f1ac
    goto L_0x0048f1ac;
L_0x0048f371:
    // 0048f371  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048f372  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048f374  8b8c2488000000         -mov ecx, dword ptr [esp + 0x88]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */);
    // 0048f37b  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0048f37e  0fafc1                 -imul eax, ecx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0048f381  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0048f383  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0048f386  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048f388  8b84249c000000         -mov eax, dword ptr [esp + 0x9c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */);
    // 0048f38f  030c856c8a5200         -add ecx, dword ptr [eax*4 + 0x528a6c]
    (cpu.ecx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5409388) /* 0x528a6c */ + cpu.eax * 4)));
    // 0048f396  898c24a4000000         -mov dword ptr [esp + 0xa4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(164) /* 0xa4 */) = cpu.ecx;
    // 0048f39d  8a8c248c000000         -mov cl, byte ptr [esp + 0x8c]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 0048f3a4  8b8424a4000000         -mov eax, dword ptr [esp + 0xa4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(164) /* 0xa4 */);
    // 0048f3ab  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0048f3ad  8b4c2474               -mov ecx, dword ptr [esp + 0x74]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 0048f3b1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048f3b2  a1fc844c00             -mov eax, dword ptr [0x4c84fc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5014780) /* 0x4c84fc */);
    // 0048f3b7  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0048f3ba  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048f3bc  a100854c00             -mov eax, dword ptr [0x4c8500]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5014784) /* 0x4c8500 */);
    // 0048f3c1  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048f3c3  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 0048f3c5  0302                   -add eax, dword ptr [edx]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
    // 0048f3c7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048f3c8  ff942488000000         -call dword ptr [esp + 0x88]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048f3cf  83c40c                 +add esp, 0xc
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
    // 0048f3d2  e9e5fdffff             -jmp 0x48f1bc
    goto L_0x0048f1bc;
L_0x0048f3d7:
    // 0048f3d7  833d14824c0000         +cmp dword ptr [0x4c8214], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5014036) /* 0x4c8214 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048f3de  0f849af7ffff           -je 0x48eb7e
    if (cpu.flags.zf)
    {
        goto L_0x0048eb7e;
    }
    // 0048f3e4  0f77                   -emms 
    cpu.mmx.init();
    // 0048f3e6  81c4a4000000           -add esp, 0xa4
    (cpu.esp) += x86::reg32(x86::sreg32(164 /*0xa4*/));
    // 0048f3ec  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f3ed  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f3ee  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f3ef  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f3f0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48f3f4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048f3f4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048f3f5  83ec30                 -sub esp, 0x30
    (cpu.esp) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 0048f3f8  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 0048f3fa  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 0048f3fd  81c100800000           -add ecx, 0x8000
    (cpu.ecx) += x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 0048f403  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 0048f406  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0048f409  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 0048f40c  81c100800000           -add ecx, 0x8000
    (cpu.ecx) += x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 0048f412  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0048f416  8b4a08                 -mov ecx, dword ptr [edx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0048f419  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 0048f41c  81c100800000           -add ecx, 0x8000
    (cpu.ecx) += x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 0048f422  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0048f426  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0048f429  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 0048f42c  81c100800000           -add ecx, 0x8000
    (cpu.ecx) += x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 0048f432  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0048f436  8b4a10                 -mov ecx, dword ptr [edx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0048f439  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 0048f43c  81c100800000           -add ecx, 0x8000
    (cpu.ecx) += x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 0048f442  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 0048f446  8b5214                 -mov edx, dword ptr [edx + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 0048f449  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0048f44c  81c200800000           -add edx, 0x8000
    (cpu.edx) += x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 0048f452  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 0048f456  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0048f458  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0048f45b  81c200800000           -add edx, 0x8000
    (cpu.edx) += x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 0048f461  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 0048f465  8b5304                 -mov edx, dword ptr [ebx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0048f468  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0048f46b  81c200800000           -add edx, 0x8000
    (cpu.edx) += x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 0048f471  8954241c               -mov dword ptr [esp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 0048f475  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0048f478  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0048f47b  81c200800000           -add edx, 0x8000
    (cpu.edx) += x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 0048f481  89542420               -mov dword ptr [esp + 0x20], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 0048f485  8b530c                 -mov edx, dword ptr [ebx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 0048f488  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0048f48b  81c200800000           -add edx, 0x8000
    (cpu.edx) += x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 0048f491  89542424               -mov dword ptr [esp + 0x24], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 0048f495  8b5310                 -mov edx, dword ptr [ebx + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 0048f498  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0048f49b  81c200800000           -add edx, 0x8000
    (cpu.edx) += x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 0048f4a1  89542428               -mov dword ptr [esp + 0x28], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 0048f4a5  8b5314                 -mov edx, dword ptr [ebx + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 0048f4a8  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0048f4ab  81c200800000           -add edx, 0x8000
    (cpu.edx) += x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 0048f4b1  8d5c2418               -lea ebx, [esp + 0x18]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0048f4b5  8954242c               -mov dword ptr [esp + 0x2c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.edx;
    // 0048f4b9  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0048f4bb  e854f5ffff             -call 0x48ea14
    cpu.esp -= 4;
    sub_48ea14(app, cpu);
    if (cpu.terminate) return;
    // 0048f4c0  83c430                 -add esp, 0x30
    (cpu.esp) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 0048f4c3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f4c4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_48f4d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048f4d0  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048f4d2  7501                   -jne 0x48f4d5
    if (!cpu.flags.zf)
    {
        goto L_0x0048f4d5;
    }
    // 0048f4d4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048f4d5:
    // 0048f4d5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048f4d6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048f4d7  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0048f4d9  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 0048f4da  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0048f4dc  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048f4de  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048f4e0  0facd010               -shrd eax, edx, 0x10
    {
        x86::reg32& destination = cpu.eax;
        destination >>= (16 /*0x10*/ % 32);
        destination |= cpu.edx  << (32 - (16 /*0x10*/ % 32));
    }
    // 0048f4e4  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0048f4e7  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0048f4e9  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 0048f4ec  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0048f4ee  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f4ef  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f4f0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48f4f4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048f4f4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048f4f5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048f4f6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048f4f7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048f4f8  81eca4000000           -sub esp, 0xa4
    (cpu.esp) -= x86::reg32(x86::sreg32(164 /*0xa4*/));
    // 0048f4fe  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048f500  89542434               -mov dword ptr [esp + 0x34], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.edx;
    // 0048f504  895c244c               -mov dword ptr [esp + 0x4c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */) = cpu.ebx;
    // 0048f508  8b4002                 -mov eax, dword ptr [eax + 2]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0048f50b  ba22c14800             -mov edx, 0x48c122
    cpu.edx = 4768034 /*0x48c122*/;
    // 0048f510  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0048f513  8954247c               -mov dword ptr [esp + 0x7c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(124) /* 0x7c */) = cpu.edx;
    // 0048f517  ba6c8a5200             -mov edx, 0x528a6c
    cpu.edx = 5409388 /*0x528a6c*/;
    // 0048f51c  89842484000000         -mov dword ptr [esp + 0x84], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */) = cpu.eax;
    // 0048f523  8d4110                 -lea eax, [ecx + 0x10]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0048f526  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048f528  e8e3cbffff             -call 0x48c110
    cpu.esp -= 4;
    sub_48c110(app, cpu);
    if (cpu.terminate) return;
    // 0048f52d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048f52f  899c2488000000         -mov dword ptr [esp + 0x88], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */) = cpu.ebx;
    // 0048f536  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048f538  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 0048f53b  8a8090a84c00           -mov al, byte ptr [eax + 0x4ca890]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5023888) /* 0x4ca890 */);
    // 0048f541  83f820                 +cmp eax, 0x20
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
    // 0048f544  750b                   -jne 0x48f551
    if (!cpu.flags.zf)
    {
        goto L_0x0048f551;
    }
    // 0048f546  c784248800000002000000 -mov dword ptr [esp + 0x88], 2
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */) = 2 /*0x2*/;
L_0x0048f551:
    // 0048f551  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048f553  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048f555  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 0048f558  8a8090a84c00           -mov al, byte ptr [eax + 0x4ca890]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5023888) /* 0x4ca890 */);
    // 0048f55e  40                     -inc eax
    (cpu.eax)++;
    // 0048f55f  24fe                   -and al, 0xfe
    cpu.al &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 0048f561  83f810                 +cmp eax, 0x10
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
    // 0048f564  750b                   -jne 0x48f571
    if (!cpu.flags.zf)
    {
        goto L_0x0048f571;
    }
    // 0048f566  c784248800000001000000 -mov dword ptr [esp + 0x88], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */) = 1 /*0x1*/;
L_0x0048f571:
    // 0048f571  8b44244c               -mov eax, dword ptr [esp + 0x4c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 0048f575  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0048f577  8b54244c               -mov edx, dword ptr [esp + 0x4c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 0048f57b  896c2440               -mov dword ptr [esp + 0x40], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = cpu.ebp;
    // 0048f57f  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0048f582  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0048f585  896c243c               -mov dword ptr [esp + 0x3c], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.ebp;
    // 0048f589  39c8                   +cmp eax, ecx
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
    // 0048f58b  7e08                   -jle 0x48f595
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048f595;
    }
    // 0048f58d  c744244001000000       -mov dword ptr [esp + 0x40], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = 1 /*0x1*/;
L_0x0048f595:
    // 0048f595  8b44243c               -mov eax, dword ptr [esp + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0048f599  8b54244c               -mov edx, dword ptr [esp + 0x4c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 0048f59d  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0048f5a0  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048f5a2  8b44244c               -mov eax, dword ptr [esp + 0x4c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 0048f5a6  8b7204                 -mov esi, dword ptr [edx + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0048f5a9  3b700c                 +cmp esi, dword ptr [eax + 0xc]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048f5ac  7e08                   -jle 0x48f5b6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048f5b6;
    }
    // 0048f5ae  c744243c01000000       -mov dword ptr [esp + 0x3c], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = 1 /*0x1*/;
L_0x0048f5b6:
    // 0048f5b6  8b442440               -mov eax, dword ptr [esp + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0048f5ba  8b6c244c               -mov ebp, dword ptr [esp + 0x4c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 0048f5be  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0048f5c1  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0048f5c3  8b5514                 -mov edx, dword ptr [ebp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0048f5c6  3b5004                 +cmp edx, dword ptr [eax + 4]
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
    // 0048f5c9  7e08                   -jle 0x48f5d3
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048f5d3;
    }
    // 0048f5cb  c744244002000000       -mov dword ptr [esp + 0x40], 2
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = 2 /*0x2*/;
L_0x0048f5d3:
    // 0048f5d3  8b54243c               -mov edx, dword ptr [esp + 0x3c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0048f5d7  8b74244c               -mov esi, dword ptr [esp + 0x4c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 0048f5db  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 0048f5de  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0048f5e0  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0048f5e3  3b4204                 +cmp eax, dword ptr [edx + 4]
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
    // 0048f5e6  7d08                   -jge 0x48f5f0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048f5f0;
    }
    // 0048f5e8  c744243c02000000       -mov dword ptr [esp + 0x3c], 2
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = 2 /*0x2*/;
L_0x0048f5f0:
    // 0048f5f0  8b44243c               -mov eax, dword ptr [esp + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0048f5f4  0b442440               -or eax, dword ptr [esp + 0x40]
    cpu.eax |= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */)));
    // 0048f5f8  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 0048f5fd  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0048f5ff  8b4c244c               -mov ecx, dword ptr [esp + 0x4c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 0048f603  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0048f607  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 0048f60e  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0048f610  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0048f613  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048f615  89542448               -mov dword ptr [esp + 0x48], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */) = cpu.edx;
    // 0048f619  89442444               -mov dword ptr [esp + 0x44], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */) = cpu.eax;
    // 0048f61d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048f61f  8b542440               -mov edx, dword ptr [esp + 0x40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0048f623  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 0048f626  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0048f628  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0048f62a  8b4c243c               -mov ecx, dword ptr [esp + 0x3c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0048f62e  c1e103                 -shl ecx, 3
    cpu.ecx <<= 3 /*0x3*/ % 32;
    // 0048f631  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0048f634  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0048f636  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0048f63a  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0048f63c  2b01                   -sub eax, dword ptr [ecx]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx)));
    // 0048f63e  8b6904                 -mov ebp, dword ptr [ecx + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0048f641  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 0048f645  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0048f648  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0048f64a  89442438               -mov dword ptr [esp + 0x38], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 0048f64e  3d00000100             +cmp eax, 0x10000
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
    // 0048f653  7d18                   -jge 0x48f66d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048f66d;
    }
    // 0048f655  833d14824c0000         +cmp dword ptr [0x4c8214], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5014036) /* 0x4c8214 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048f65c  750b                   -jne 0x48f669
    if (!cpu.flags.zf)
    {
        goto L_0x0048f669;
    }
L_0x0048f65e:
    // 0048f65e  81c4a4000000           +add esp, 0xa4
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(164 /*0xa4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048f664  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f665  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f666  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f667  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f668  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048f669:
    // 0048f669  0f77                   -emms 
    cpu.mmx.init();
    // 0048f66b  ebf1                   -jmp 0x48f65e
    goto L_0x0048f65e;
L_0x0048f66d:
    // 0048f66d  8b542448               -mov edx, dword ptr [esp + 0x48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0048f671  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048f673  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0048f677  29ea                   -sub edx, ebp
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0048f679  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0048f67b  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0048f67d  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0048f67f  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0048f681  8b4c2444               -mov ecx, dword ptr [esp + 0x44]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 0048f685  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048f687  89742420               -mov dword ptr [esp + 0x20], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.esi;
    // 0048f68b  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048f68d  89542428               -mov dword ptr [esp + 0x28], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 0048f691  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0048f693  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048f695  7c1e                   -jl 0x48f6b5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048f6b5;
    }
L_0x0048f697:
    // 0048f697  81f900000100           +cmp ecx, 0x10000
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
    // 0048f69d  7d23                   -jge 0x48f6c2
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048f6c2;
    }
L_0x0048f69f:
    // 0048f69f  833d14824c0000         +cmp dword ptr [0x4c8214], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5014036) /* 0x4c8214 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048f6a6  74b6                   -je 0x48f65e
    if (cpu.flags.zf)
    {
        goto L_0x0048f65e;
    }
    // 0048f6a8  0f77                   -emms 
    cpu.mmx.init();
    // 0048f6aa  81c4a4000000           -add esp, 0xa4
    (cpu.esp) += x86::reg32(x86::sreg32(164 /*0xa4*/));
    // 0048f6b0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f6b1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f6b2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f6b3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048f6b4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048f6b5:
    // 0048f6b5  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 0048f6ba  f7d9                   +neg ecx
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
    // 0048f6bc  896c2420               -mov dword ptr [esp + 0x20], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ebp;
    // 0048f6c0  ebd5                   -jmp 0x48f697
    goto L_0x0048f697;
L_0x0048f6c2:
    // 0048f6c2  81f900000006           +cmp ecx, 0x6000000
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(100663296 /*0x6000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048f6c8  7dd5                   -jge 0x48f69f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048f69f;
    }
    // 0048f6ca  8b442440               -mov eax, dword ptr [esp + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0048f6ce  8b542434               -mov edx, dword ptr [esp + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0048f6d2  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0048f6d5  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048f6d7  8954242c               -mov dword ptr [esp + 0x2c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.edx;
    // 0048f6db  8b54244c               -mov edx, dword ptr [esp + 0x4c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 0048f6df  8b7c243c               -mov edi, dword ptr [esp + 0x3c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0048f6e3  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048f6e5  8b442448               -mov eax, dword ptr [esp + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0048f6e9  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 0048f6ed  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0048f6f0  c1e703                 -shl edi, 3
    cpu.edi <<= 3 /*0x3*/ % 32;
    // 0048f6f3  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0048f6f5  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0048f6f9  8b5c242c               -mov ebx, dword ptr [esp + 0x2c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0048f6fd  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 0048f6ff  8b2b                   -mov ebp, dword ptr [ebx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx);
    // 0048f701  89442430               -mov dword ptr [esp + 0x30], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 0048f705  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048f707  8b5c2438               -mov ebx, dword ptr [esp + 0x38]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0048f70b  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0048f70d  8b6c242c               -mov ebp, dword ptr [esp + 0x2c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0048f711  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0048f713  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0048f715  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0048f719  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp);
    // 0048f71c  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0048f71f  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048f721  2b542448               -sub edx, dword ptr [esp + 0x48]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */)));
    // 0048f725  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0048f729  8b5c242c               -mov ebx, dword ptr [esp + 0x2c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0048f72d  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0048f730  2b4304                 -sub eax, dword ptr [ebx + 4]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */)));
    // 0048f733  8b5c2438               -mov ebx, dword ptr [esp + 0x38]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0048f737  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0048f739  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0048f73b  8b54242c               -mov edx, dword ptr [esp + 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0048f73f  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0048f742  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048f744  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0048f748  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0048f74b  8b542434               -mov edx, dword ptr [esp + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0048f74f  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0048f752  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048f754  8954241c               -mov dword ptr [esp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 0048f758  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0048f75a  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0048f75c  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0048f75e  e86dfdffff             -call 0x48f4d0
    cpu.esp -= 4;
    sub_48f4d0(app, cpu);
    if (cpu.terminate) return;
    // 0048f763  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048f765  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0048f769  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0048f76c  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0048f76f  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0048f772  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048f774  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0048f776  41                     -inc ecx
    (cpu.ecx)++;
    // 0048f777  e854fdffff             -call 0x48f4d0
    cpu.esp -= 4;
    sub_48f4d0(app, cpu);
    if (cpu.terminate) return;
    // 0048f77c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048f77d  8b8c2488000000         -mov ecx, dword ptr [esp + 0x88]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */);
    // 0048f784  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048f785  8b6c2438               -mov ebp, dword ptr [esp + 0x38]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0048f789  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048f78a  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0048f78c  bb00800000             -mov ebx, 0x8000
    cpu.ebx = 32768 /*0x8000*/;
    // 0048f791  b86c8a5200             -mov eax, 0x528a6c
    cpu.eax = 5409388 /*0x528a6c*/;
    // 0048f796  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0048f798  8b74243c               -mov esi, dword ptr [esp + 0x3c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0048f79c  e86f790000             -call 0x497110
    cpu.esp -= 4;
    sub_497110(app, cpu);
    if (cpu.terminate) return;
    // 0048f7a1  8b4c244c               -mov ecx, dword ptr [esp + 0x4c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 0048f7a5  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0048f7a9  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0048f7ab  8b36                   -mov esi, dword ptr [esi]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi);
    // 0048f7ad  8b6d04                 -mov ebp, dword ptr [ebp + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 0048f7b0  8b5904                 -mov ebx, dword ptr [ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0048f7b3  8b39                   -mov edi, dword ptr [ecx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx);
    // 0048f7b5  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 0048f7b8  89bc249c000000         -mov dword ptr [esp + 0x9c], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */) = cpu.edi;
    // 0048f7bf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048f7c1  0f8452010000           -je 0x48f919
    if (cpu.flags.zf)
    {
        goto L_0x0048f919;
    }
    // 0048f7c7  8b542448               -mov edx, dword ptr [esp + 0x48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0048f7cb  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0048f7ce  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048f7d0  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0048f7d4  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0048f7d8  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048f7da  2b02                   -sub eax, dword ptr [edx]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
    // 0048f7dc  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048f7e0  e8ebfcffff             -call 0x48f4d0
    cpu.esp -= 4;
    sub_48f4d0(app, cpu);
    if (cpu.terminate) return;
    // 0048f7e5  8984248c000000         -mov dword ptr [esp + 0x8c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */) = cpu.eax;
    // 0048f7ec  8b5104                 -mov edx, dword ptr [ecx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0048f7ef  8b4c2448               -mov ecx, dword ptr [esp + 0x48]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0048f7f3  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0048f7f7  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048f7f9  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
L_0x0048f7fd:
    // 0048f7fd  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0048f800  2b4104                 -sub eax, dword ptr [ecx + 4]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
    // 0048f803  e8c8fcffff             -call 0x48f4d0
    cpu.esp -= 4;
    sub_48f4d0(app, cpu);
    if (cpu.terminate) return;
    // 0048f808  89842490000000         -mov dword ptr [esp + 0x90], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(144) /* 0x90 */) = cpu.eax;
    // 0048f80f  3b5c2414               +cmp ebx, dword ptr [esp + 0x14]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048f813  0f8d25030000           -jge 0x48fb3e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048fb3e;
    }
    // 0048f819  8b44243c               -mov eax, dword ptr [esp + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0048f81d  8b54244c               -mov edx, dword ptr [esp + 0x4c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 0048f821  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0048f824  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0048f828  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048f82a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048f82c  0f8438010000           -je 0x48f96a
    if (cpu.flags.zf)
    {
        goto L_0x0048f96a;
    }
    // 0048f832  8b4c2448               -mov ecx, dword ptr [esp + 0x48]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0048f836  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0048f839  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048f83b  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048f83d  2b442444               -sub eax, dword ptr [esp + 0x44]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */)));
    // 0048f841  e88afcffff             -call 0x48f4d0
    cpu.esp -= 4;
    sub_48f4d0(app, cpu);
    if (cpu.terminate) return;
    // 0048f846  8b542438               -mov edx, dword ptr [esp + 0x38]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0048f84a  89442468               -mov dword ptr [esp + 0x68], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */) = cpu.eax;
    // 0048f84e  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0048f852  e879fcffff             -call 0x48f4d0
    cpu.esp -= 4;
    sub_48f4d0(app, cpu);
    if (cpu.terminate) return;
    // 0048f857  89442460               -mov dword ptr [esp + 0x60], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */) = cpu.eax;
L_0x0048f85b:
    // 0048f85b  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0048f85f  a1e8844c00             -mov eax, dword ptr [0x4c84e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5014760) /* 0x4c84e8 */);
    // 0048f864  39d0                   +cmp eax, edx
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
    // 0048f866  7d02                   -jge 0x48f86a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048f86a;
    }
    // 0048f868  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x0048f86a:
    // 0048f86a  8b0de0844c00           -mov ecx, dword ptr [0x4c84e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5014752) /* 0x4c84e0 */);
    // 0048f870  89542450               -mov dword ptr [esp + 0x50], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */) = cpu.edx;
    // 0048f874  39cb                   +cmp ebx, ecx
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
    // 0048f876  0f8d1c010000           -jge 0x48f998
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048f998;
    }
L_0x0048f87c:
    // 0048f87c  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 0048f883  89442474               -mov dword ptr [esp + 0x74], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */) = cpu.eax;
L_0x0048f887:
    // 0048f887  3b5c2450               +cmp ebx, dword ptr [esp + 0x50]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048f88b  0f8dad020000           -jge 0x48fb3e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048fb3e;
    }
    // 0048f891  8b94249c000000         -mov edx, dword ptr [esp + 0x9c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */);
    // 0048f898  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048f89a  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0048f89d  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0048f8a0  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048f8a2  8d0c02                 -lea ecx, [edx + eax]
    cpu.ecx = x86::reg32(cpu.edx + cpu.eax * 1);
    // 0048f8a5  2b0de4844c00           -sub ecx, dword ptr [0x4c84e4]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014756) /* 0x4c84e4 */)));
    // 0048f8ab  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048f8ad  7e02                   -jle 0x48f8b1
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048f8b1;
    }
    // 0048f8af  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0048f8b1:
    // 0048f8b1  8b0ddc844c00           -mov ecx, dword ptr [0x4c84dc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5014748) /* 0x4c84dc */);
    // 0048f8b7  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048f8b9  898c2494000000         -mov dword ptr [esp + 0x94], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(148) /* 0x94 */) = cpu.ecx;
    // 0048f8c0  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048f8c2  0f8e01020000           -jle 0x48fac9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048fac9;
    }
    // 0048f8c8  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048f8ca  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
L_0x0048f8cc:
    // 0048f8cc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048f8ce  7e0c                   -jle 0x48f8dc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048f8dc;
    }
    // 0048f8d0  3b1de0844c00           +cmp ebx, dword ptr [0x4c84e0]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014752) /* 0x4c84e0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048f8d6  0f8dfb010000           -jge 0x48fad7
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048fad7;
    }
L_0x0048f8dc:
    // 0048f8dc  8b84248c000000         -mov eax, dword ptr [esp + 0x8c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 0048f8e3  8b942490000000         -mov edx, dword ptr [esp + 0x90]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(144) /* 0x90 */);
    // 0048f8ea  8b8c249c000000         -mov ecx, dword ptr [esp + 0x9c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */);
    // 0048f8f1  43                     -inc ebx
    (cpu.ebx)++;
    // 0048f8f2  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048f8f4  01d5                   -add ebp, edx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048f8f6  8b542474               -mov edx, dword ptr [esp + 0x74]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 0048f8fa  8b442468               -mov eax, dword ptr [esp + 0x68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 0048f8fe  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048f901  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048f903  8b442460               -mov eax, dword ptr [esp + 0x60]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 0048f907  898c249c000000         -mov dword ptr [esp + 0x9c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */) = cpu.ecx;
    // 0048f90e  89542474               -mov dword ptr [esp + 0x74], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */) = cpu.edx;
    // 0048f912  01c7                   +add edi, eax
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
    // 0048f914  e96effffff             -jmp 0x48f887
    goto L_0x0048f887;
L_0x0048f919:
    // 0048f919  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0048f91c  898424a0000000         -mov dword ptr [esp + 0xa0], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(160) /* 0xa0 */) = cpu.eax;
    // 0048f923  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0048f927  8b9424a0000000         -mov edx, dword ptr [esp + 0xa0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(160) /* 0xa0 */);
    // 0048f92e  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0048f931  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0048f933  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0048f937  8b54242c               -mov edx, dword ptr [esp + 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0048f93b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048f93d  2b02                   -sub eax, dword ptr [edx]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
    // 0048f93f  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048f943  e888fbffff             -call 0x48f4d0
    cpu.esp -= 4;
    sub_48f4d0(app, cpu);
    if (cpu.terminate) return;
    // 0048f948  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0048f94c  8984248c000000         -mov dword ptr [esp + 0x8c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */) = cpu.eax;
    // 0048f953  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0048f956  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0048f959  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048f95b  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0048f95f  29ca                   +sub edx, ecx
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048f961  8b4c242c               -mov ecx, dword ptr [esp + 0x2c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0048f965  e993feffff             -jmp 0x48f7fd
    goto L_0x0048f7fd;
L_0x0048f96a:
    // 0048f96a  8b4c2448               -mov ecx, dword ptr [esp + 0x48]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0048f96e  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0048f971  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048f973  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048f975  2b442444               +sub eax, dword ptr [esp + 0x44]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048f979  e852fbffff             -call 0x48f4d0
    cpu.esp -= 4;
    sub_48f4d0(app, cpu);
    if (cpu.terminate) return;
    // 0048f97e  8b542438               -mov edx, dword ptr [esp + 0x38]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0048f982  89442460               -mov dword ptr [esp + 0x60], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */) = cpu.eax;
    // 0048f986  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0048f98a  e841fbffff             -call 0x48f4d0
    cpu.esp -= 4;
    sub_48f4d0(app, cpu);
    if (cpu.terminate) return;
    // 0048f98f  89442468               -mov dword ptr [esp + 0x68], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */) = cpu.eax;
    // 0048f993  e9c3feffff             -jmp 0x48f85b
    goto L_0x0048f85b;
L_0x0048f998:
    // 0048f998  8b44243c               -mov eax, dword ptr [esp + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0048f99c  8b4c2434               -mov ecx, dword ptr [esp + 0x34]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0048f9a0  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0048f9a3  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0048f9a5  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0048f9a7  3b0ddc844c00           +cmp ecx, dword ptr [0x4c84dc]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014748) /* 0x4c84dc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048f9ad  0f8cc9feffff           -jl 0x48f87c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048f87c;
    }
    // 0048f9b3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048f9b5  3b05e4844c00           +cmp eax, dword ptr [0x4c84e4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014756) /* 0x4c84e4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048f9bb  0f8dbbfeffff           -jge 0x48f87c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048f87c;
    }
    // 0048f9c1  8b442444               -mov eax, dword ptr [esp + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 0048f9c5  3b05dc844c00           +cmp eax, dword ptr [0x4c84dc]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014748) /* 0x4c84dc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048f9cb  0f8cabfeffff           -jl 0x48f87c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048f87c;
    }
    // 0048f9d1  3b05e4844c00           +cmp eax, dword ptr [0x4c84e4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014756) /* 0x4c84e4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048f9d7  0f8d9ffeffff           -jge 0x48f87c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048f87c;
    }
    // 0048f9dd  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0048f9e1  3b05dc844c00           +cmp eax, dword ptr [0x4c84dc]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014748) /* 0x4c84dc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048f9e7  0f8c8ffeffff           -jl 0x48f87c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048f87c;
    }
    // 0048f9ed  3b05e4844c00           +cmp eax, dword ptr [0x4c84e4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014756) /* 0x4c84e4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048f9f3  0f8d83feffff           -jge 0x48f87c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048f87c;
    }
    // 0048f9f9  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 0048fa00  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0048fa03  89842480000000         -mov dword ptr [esp + 0x80], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(128) /* 0x80 */) = cpu.eax;
    // 0048fa0a  8954245c               -mov dword ptr [esp + 0x5c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */) = cpu.edx;
L_0x0048fa0e:
    // 0048fa0e  8b842480000000         -mov eax, dword ptr [esp + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 0048fa15  3b44245c               +cmp eax, dword ptr [esp + 0x5c]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048fa19  0f8d1f010000           -jge 0x48fb3e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048fb3e;
    }
    // 0048fa1f  8b84249c000000         -mov eax, dword ptr [esp + 0x9c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */);
    // 0048fa26  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0048fa28  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0048fa2b  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0048fa2e  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0048fa30  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048fa32  7e52                   -jle 0x48fa86
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048fa86;
    }
    // 0048fa34  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048fa35  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0048fa37  8b8c2488000000         -mov ecx, dword ptr [esp + 0x88]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */);
    // 0048fa3e  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0048fa41  0fafca                 -imul ecx, edx
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0048fa44  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0048fa46  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0048fa49  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048fa4b  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0048fa4f  8a8c248c000000         -mov cl, byte ptr [esp + 0x8c]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 0048fa56  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048fa5a  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 0048fa5c  8b8c2484000000         -mov ecx, dword ptr [esp + 0x84]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */);
    // 0048fa63  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048fa64  8b15fc844c00           -mov edx, dword ptr [0x4c84fc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5014780) /* 0x4c84fc */);
    // 0048fa6a  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0048fa6d  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048fa6f  8b1500854c00           -mov edx, dword ptr [0x4c8500]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5014784) /* 0x4c8500 */);
    // 0048fa75  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048fa77  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 0048fa79  0302                   -add eax, dword ptr [edx]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
    // 0048fa7b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048fa7c  ff942488000000         -call dword ptr [esp + 0x88]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048fa83  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x0048fa86:
    // 0048fa86  8b84248c000000         -mov eax, dword ptr [esp + 0x8c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 0048fa8d  8b942490000000         -mov edx, dword ptr [esp + 0x90]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(144) /* 0x90 */);
    // 0048fa94  8b8c249c000000         -mov ecx, dword ptr [esp + 0x9c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */);
    // 0048fa9b  43                     -inc ebx
    (cpu.ebx)++;
    // 0048fa9c  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048fa9e  01d5                   -add ebp, edx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048faa0  8b942480000000         -mov edx, dword ptr [esp + 0x80]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 0048faa7  8b442468               -mov eax, dword ptr [esp + 0x68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 0048faab  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048faae  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048fab0  8b442460               -mov eax, dword ptr [esp + 0x60]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 0048fab4  898c249c000000         -mov dword ptr [esp + 0x9c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */) = cpu.ecx;
    // 0048fabb  89942480000000         -mov dword ptr [esp + 0x80], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(128) /* 0x80 */) = cpu.edx;
    // 0048fac2  01c7                   +add edi, eax
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
    // 0048fac4  e945ffffff             -jmp 0x48fa0e
    goto L_0x0048fa0e;
L_0x0048fac9:
    // 0048fac9  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0048facb  898c2494000000         -mov dword ptr [esp + 0x94], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(148) /* 0x94 */) = cpu.ecx;
    // 0048fad2  e9f5fdffff             -jmp 0x48f8cc
    goto L_0x0048f8cc;
L_0x0048fad7:
    // 0048fad7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048fad8  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048fada  8b8c2488000000         -mov ecx, dword ptr [esp + 0x88]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */);
    // 0048fae1  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0048fae4  0fafc1                 -imul eax, ecx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0048fae7  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0048fae9  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0048faec  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048faee  8b842498000000         -mov eax, dword ptr [esp + 0x98]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(152) /* 0x98 */);
    // 0048faf5  030c856c8a5200         -add ecx, dword ptr [eax*4 + 0x528a6c]
    (cpu.ecx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5409388) /* 0x528a6c */ + cpu.eax * 4)));
    // 0048fafc  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0048faff  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0048fb03  8a8c248c000000         -mov cl, byte ptr [esp + 0x8c]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 0048fb0a  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048fb0e  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0048fb12  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0048fb14  8b4c2478               -mov ecx, dword ptr [esp + 0x78]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 0048fb18  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048fb19  a1fc844c00             -mov eax, dword ptr [0x4c84fc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5014780) /* 0x4c84fc */);
    // 0048fb1e  8b1500854c00           -mov edx, dword ptr [0x4c8500]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5014784) /* 0x4c8500 */);
    // 0048fb24  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0048fb26  0354240c               -add edx, dword ptr [esp + 0xc]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 0048fb2a  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048fb2c  0302                   -add eax, dword ptr [edx]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
    // 0048fb2e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048fb2f  ff942488000000         -call dword ptr [esp + 0x88]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048fb36  83c40c                 +add esp, 0xc
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
    // 0048fb39  e99efdffff             -jmp 0x48f8dc
    goto L_0x0048f8dc;
L_0x0048fb3e:
    // 0048fb3e  8b442440               -mov eax, dword ptr [esp + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0048fb42  8b4c244c               -mov ecx, dword ptr [esp + 0x4c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 0048fb46  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0048fb49  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048fb4b  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0048fb4f  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0048fb52  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0048fb55  39c3                   +cmp ebx, eax
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
    // 0048fb57  0f8d5a030000           -jge 0x48feb7
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048feb7;
    }
    // 0048fb5d  837c242000             +cmp dword ptr [esp + 0x20], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048fb62  0f8471010000           -je 0x48fcd9
    if (cpu.flags.zf)
    {
        goto L_0x0048fcd9;
    }
    // 0048fb68  8b542448               -mov edx, dword ptr [esp + 0x48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0048fb6c  8b442444               -mov eax, dword ptr [esp + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 0048fb70  8b6904                 -mov ebp, dword ptr [ecx + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0048fb73  8b31                   -mov esi, dword ptr [ecx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx);
    // 0048fb75  29ea                   -sub edx, ebp
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0048fb77  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0048fb79  e852f9ffff             -call 0x48f4d0
    cpu.esp -= 4;
    sub_48f4d0(app, cpu);
    if (cpu.terminate) return;
    // 0048fb7e  8b542438               -mov edx, dword ptr [esp + 0x38]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0048fb82  89442464               -mov dword ptr [esp + 0x64], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */) = cpu.eax;
    // 0048fb86  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0048fb8a  e841f9ffff             -call 0x48f4d0
    cpu.esp -= 4;
    sub_48f4d0(app, cpu);
    if (cpu.terminate) return;
    // 0048fb8f  8944246c               -mov dword ptr [esp + 0x6c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */) = cpu.eax;
    // 0048fb93  8b442444               -mov eax, dword ptr [esp + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 0048fb97  8984249c000000         -mov dword ptr [esp + 0x9c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */) = cpu.eax;
    // 0048fb9e  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0048fba2  8b542434               -mov edx, dword ptr [esp + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0048fba6  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0048fba9  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048fbab  8b442448               -mov eax, dword ptr [esp + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0048fbaf  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0048fbb3  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 0048fbb5  8b6a04                 -mov ebp, dword ptr [edx + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0048fbb8  2b4104                 -sub eax, dword ptr [ecx + 4]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
    // 0048fbbb  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048fbbf  898424a0000000         -mov dword ptr [esp + 0xa0], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(160) /* 0xa0 */) = cpu.eax;
    // 0048fbc6  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0048fbca  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048fbcc  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0048fbd0  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048fbd4  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048fbd6  2b02                   -sub eax, dword ptr [edx]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
    // 0048fbd8  8b9424a0000000         -mov edx, dword ptr [esp + 0xa0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(160) /* 0xa0 */);
    // 0048fbdf  e8ecf8ffff             -call 0x48f4d0
    cpu.esp -= 4;
    sub_48f4d0(app, cpu);
    if (cpu.terminate) return;
    // 0048fbe4  8b542448               -mov edx, dword ptr [esp + 0x48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0048fbe8  8984248c000000         -mov dword ptr [esp + 0x8c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */) = cpu.eax;
    // 0048fbef  2b5104                 -sub edx, dword ptr [ecx + 4]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
    // 0048fbf2  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048fbf6  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048fbfa  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0048fbfd  2b4104                 -sub eax, dword ptr [ecx + 4]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
    // 0048fc00  e8cbf8ffff             -call 0x48f4d0
    cpu.esp -= 4;
    sub_48f4d0(app, cpu);
    if (cpu.terminate) return;
    // 0048fc05  89842490000000         -mov dword ptr [esp + 0x90], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(144) /* 0x90 */) = cpu.eax;
L_0x0048fc0c:
    // 0048fc0c  8b542440               -mov edx, dword ptr [esp + 0x40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0048fc10  8b4c244c               -mov ecx, dword ptr [esp + 0x4c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 0048fc14  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 0048fc17  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0048fc19  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0048fc1c  a1e8844c00             -mov eax, dword ptr [0x4c84e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5014760) /* 0x4c84e8 */);
    // 0048fc21  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0048fc24  39c2                   +cmp edx, eax
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
    // 0048fc26  7e02                   -jle 0x48fc2a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048fc2a;
    }
    // 0048fc28  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x0048fc2a:
    // 0048fc2a  8b0de0844c00           -mov ecx, dword ptr [0x4c84e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5014752) /* 0x4c84e0 */);
    // 0048fc30  89542454               -mov dword ptr [esp + 0x54], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */) = cpu.edx;
    // 0048fc34  39cb                   +cmp ebx, ecx
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
    // 0048fc36  0f8dcf000000           -jge 0x48fd0b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048fd0b;
    }
L_0x0048fc3c:
    // 0048fc3c  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 0048fc43  89442470               -mov dword ptr [esp + 0x70], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */) = cpu.eax;
L_0x0048fc47:
    // 0048fc47  3b5c2454               +cmp ebx, dword ptr [esp + 0x54]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048fc4b  0f8d66020000           -jge 0x48feb7
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048feb7;
    }
    // 0048fc51  8b94249c000000         -mov edx, dword ptr [esp + 0x9c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */);
    // 0048fc58  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048fc5a  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0048fc5d  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0048fc60  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048fc62  8d0c02                 -lea ecx, [edx + eax]
    cpu.ecx = x86::reg32(cpu.edx + cpu.eax * 1);
    // 0048fc65  2b0de4844c00           -sub ecx, dword ptr [0x4c84e4]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014756) /* 0x4c84e4 */)));
    // 0048fc6b  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048fc6d  7e02                   -jle 0x48fc71
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048fc71;
    }
    // 0048fc6f  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0048fc71:
    // 0048fc71  8b0ddc844c00           -mov ecx, dword ptr [0x4c84dc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5014748) /* 0x4c84dc */);
    // 0048fc77  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048fc79  898c2498000000         -mov dword ptr [esp + 0x98], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(152) /* 0x98 */) = cpu.ecx;
    // 0048fc80  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048fc82  0f8ebb010000           -jle 0x48fe43
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048fe43;
    }
    // 0048fc88  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048fc8a  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
L_0x0048fc8c:
    // 0048fc8c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048fc8e  7e0c                   -jle 0x48fc9c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048fc9c;
    }
    // 0048fc90  3b1de0844c00           +cmp ebx, dword ptr [0x4c84e0]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014752) /* 0x4c84e0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048fc96  0f8db5010000           -jge 0x48fe51
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048fe51;
    }
L_0x0048fc9c:
    // 0048fc9c  8b84248c000000         -mov eax, dword ptr [esp + 0x8c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 0048fca3  8b942490000000         -mov edx, dword ptr [esp + 0x90]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(144) /* 0x90 */);
    // 0048fcaa  8b8c249c000000         -mov ecx, dword ptr [esp + 0x9c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */);
    // 0048fcb1  43                     -inc ebx
    (cpu.ebx)++;
    // 0048fcb2  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048fcb4  01d5                   -add ebp, edx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048fcb6  8b542470               -mov edx, dword ptr [esp + 0x70]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */);
    // 0048fcba  8b442464               -mov eax, dword ptr [esp + 0x64]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 0048fcbe  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048fcc1  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048fcc3  8b44246c               -mov eax, dword ptr [esp + 0x6c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */);
    // 0048fcc7  898c249c000000         -mov dword ptr [esp + 0x9c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */) = cpu.ecx;
    // 0048fcce  89542470               -mov dword ptr [esp + 0x70], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */) = cpu.edx;
    // 0048fcd2  01c7                   +add edi, eax
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
    // 0048fcd4  e96effffff             -jmp 0x48fc47
    goto L_0x0048fc47;
L_0x0048fcd9:
    // 0048fcd9  8b542448               -mov edx, dword ptr [esp + 0x48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0048fcdd  8b7904                 -mov edi, dword ptr [ecx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0048fce0  8b442444               -mov eax, dword ptr [esp + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 0048fce4  29fa                   -sub edx, edi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0048fce6  2b01                   +sub eax, dword ptr [ecx]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048fce8  e8e3f7ffff             -call 0x48f4d0
    cpu.esp -= 4;
    sub_48f4d0(app, cpu);
    if (cpu.terminate) return;
    // 0048fced  8b542438               -mov edx, dword ptr [esp + 0x38]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0048fcf1  8944246c               -mov dword ptr [esp + 0x6c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */) = cpu.eax;
    // 0048fcf5  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0048fcf9  8b7c2444               -mov edi, dword ptr [esp + 0x44]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 0048fcfd  e8cef7ffff             -call 0x48f4d0
    cpu.esp -= 4;
    sub_48f4d0(app, cpu);
    if (cpu.terminate) return;
    // 0048fd02  89442464               -mov dword ptr [esp + 0x64], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */) = cpu.eax;
    // 0048fd06  e901ffffff             -jmp 0x48fc0c
    goto L_0x0048fc0c;
L_0x0048fd0b:
    // 0048fd0b  8b442440               -mov eax, dword ptr [esp + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0048fd0f  8b4c2434               -mov ecx, dword ptr [esp + 0x34]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0048fd13  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0048fd16  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0048fd18  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0048fd1a  3b0ddc844c00           +cmp ecx, dword ptr [0x4c84dc]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014748) /* 0x4c84dc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048fd20  0f8c16ffffff           -jl 0x48fc3c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048fc3c;
    }
    // 0048fd26  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048fd28  3b05e4844c00           +cmp eax, dword ptr [0x4c84e4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014756) /* 0x4c84e4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048fd2e  0f8d08ffffff           -jge 0x48fc3c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048fc3c;
    }
    // 0048fd34  8b442444               -mov eax, dword ptr [esp + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 0048fd38  3b05dc844c00           +cmp eax, dword ptr [0x4c84dc]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014748) /* 0x4c84dc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048fd3e  0f8cf8feffff           -jl 0x48fc3c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048fc3c;
    }
    // 0048fd44  3b05e4844c00           +cmp eax, dword ptr [0x4c84e4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014756) /* 0x4c84e4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048fd4a  0f8decfeffff           -jge 0x48fc3c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048fc3c;
    }
    // 0048fd50  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0048fd54  3b05dc844c00           +cmp eax, dword ptr [0x4c84dc]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014748) /* 0x4c84dc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048fd5a  0f8cdcfeffff           -jl 0x48fc3c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048fc3c;
    }
    // 0048fd60  3b05e4844c00           +cmp eax, dword ptr [0x4c84e4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014756) /* 0x4c84e4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048fd66  0f8dd0feffff           -jge 0x48fc3c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048fc3c;
    }
    // 0048fd6c  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 0048fd73  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0048fd76  89442478               -mov dword ptr [esp + 0x78], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */) = cpu.eax;
    // 0048fd7a  89542458               -mov dword ptr [esp + 0x58], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */) = cpu.edx;
L_0x0048fd7e:
    // 0048fd7e  8b442478               -mov eax, dword ptr [esp + 0x78]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 0048fd82  3b442458               +cmp eax, dword ptr [esp + 0x58]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048fd86  0f8d2b010000           -jge 0x48feb7
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048feb7;
    }
    // 0048fd8c  8b84249c000000         -mov eax, dword ptr [esp + 0x9c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */);
    // 0048fd93  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0048fd95  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0048fd98  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0048fd9b  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0048fd9d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048fd9f  7e65                   -jle 0x48fe06
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048fe06;
    }
    // 0048fda1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048fda2  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0048fda4  8b8c2488000000         -mov ecx, dword ptr [esp + 0x88]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */);
    // 0048fdab  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0048fdae  0fafca                 -imul ecx, edx
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0048fdb1  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0048fdb3  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0048fdb6  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048fdb8  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0048fdbb  898c24a4000000         -mov dword ptr [esp + 0xa4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(164) /* 0xa4 */) = cpu.ecx;
    // 0048fdc2  8a8c248c000000         -mov cl, byte ptr [esp + 0x8c]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 0048fdc9  8b9424a4000000         -mov edx, dword ptr [esp + 0xa4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(164) /* 0xa4 */);
    // 0048fdd0  898424a4000000         -mov dword ptr [esp + 0xa4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(164) /* 0xa4 */) = cpu.eax;
    // 0048fdd7  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 0048fdd9  8b0dfc844c00           -mov ecx, dword ptr [0x4c84fc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5014780) /* 0x4c84fc */);
    // 0048fddf  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048fde0  8b942480000000         -mov edx, dword ptr [esp + 0x80]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 0048fde7  a100854c00             -mov eax, dword ptr [0x4c8500]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5014784) /* 0x4c8500 */);
    // 0048fdec  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048fdee  8b9424a8000000         -mov edx, dword ptr [esp + 0xa8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(168) /* 0xa8 */);
    // 0048fdf5  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048fdf7  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 0048fdf9  0302                   -add eax, dword ptr [edx]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
    // 0048fdfb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048fdfc  ff942488000000         -call dword ptr [esp + 0x88]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048fe03  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x0048fe06:
    // 0048fe06  8b84248c000000         -mov eax, dword ptr [esp + 0x8c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 0048fe0d  8b942490000000         -mov edx, dword ptr [esp + 0x90]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(144) /* 0x90 */);
    // 0048fe14  8b8c249c000000         -mov ecx, dword ptr [esp + 0x9c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */);
    // 0048fe1b  43                     -inc ebx
    (cpu.ebx)++;
    // 0048fe1c  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048fe1e  01d5                   -add ebp, edx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048fe20  8b542478               -mov edx, dword ptr [esp + 0x78]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 0048fe24  8b442464               -mov eax, dword ptr [esp + 0x64]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 0048fe28  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048fe2b  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048fe2d  8b44246c               -mov eax, dword ptr [esp + 0x6c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */);
    // 0048fe31  898c249c000000         -mov dword ptr [esp + 0x9c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */) = cpu.ecx;
    // 0048fe38  89542478               -mov dword ptr [esp + 0x78], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */) = cpu.edx;
    // 0048fe3c  01c7                   +add edi, eax
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
    // 0048fe3e  e93bffffff             -jmp 0x48fd7e
    goto L_0x0048fd7e;
L_0x0048fe43:
    // 0048fe43  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0048fe45  898c2498000000         -mov dword ptr [esp + 0x98], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(152) /* 0x98 */) = cpu.ecx;
    // 0048fe4c  e93bfeffff             -jmp 0x48fc8c
    goto L_0x0048fc8c;
L_0x0048fe51:
    // 0048fe51  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048fe52  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048fe54  8b8c2488000000         -mov ecx, dword ptr [esp + 0x88]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */);
    // 0048fe5b  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0048fe5e  0fafc1                 -imul eax, ecx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0048fe61  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0048fe63  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0048fe66  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048fe68  8b84249c000000         -mov eax, dword ptr [esp + 0x9c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */);
    // 0048fe6f  030c856c8a5200         -add ecx, dword ptr [eax*4 + 0x528a6c]
    (cpu.ecx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5409388) /* 0x528a6c */ + cpu.eax * 4)));
    // 0048fe76  898c24a4000000         -mov dword ptr [esp + 0xa4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(164) /* 0xa4 */) = cpu.ecx;
    // 0048fe7d  8a8c248c000000         -mov cl, byte ptr [esp + 0x8c]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 0048fe84  8b8424a4000000         -mov eax, dword ptr [esp + 0xa4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(164) /* 0xa4 */);
    // 0048fe8b  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0048fe8d  8b4c2474               -mov ecx, dword ptr [esp + 0x74]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 0048fe91  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048fe92  a1fc844c00             -mov eax, dword ptr [0x4c84fc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5014780) /* 0x4c84fc */);
    // 0048fe97  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0048fe9a  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048fe9c  a100854c00             -mov eax, dword ptr [0x4c8500]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5014784) /* 0x4c8500 */);
    // 0048fea1  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048fea3  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 0048fea5  0302                   -add eax, dword ptr [edx]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
    // 0048fea7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048fea8  ff942488000000         -call dword ptr [esp + 0x88]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048feaf  83c40c                 +add esp, 0xc
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
    // 0048feb2  e9e5fdffff             -jmp 0x48fc9c
    goto L_0x0048fc9c;
L_0x0048feb7:
    // 0048feb7  833d14824c0000         +cmp dword ptr [0x4c8214], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5014036) /* 0x4c8214 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048febe  0f849af7ffff           -je 0x48f65e
    if (cpu.flags.zf)
    {
        goto L_0x0048f65e;
    }
    // 0048fec4  0f77                   -emms 
    cpu.mmx.init();
    // 0048fec6  81c4a4000000           -add esp, 0xa4
    (cpu.esp) += x86::reg32(x86::sreg32(164 /*0xa4*/));
    // 0048fecc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048fecd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048fece  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048fecf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048fed0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48fed4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048fed4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048fed5  83ec30                 -sub esp, 0x30
    (cpu.esp) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 0048fed8  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 0048feda  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 0048fedd  81c100800000           -add ecx, 0x8000
    (cpu.ecx) += x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 0048fee3  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 0048fee6  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0048fee9  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 0048feec  81c100800000           -add ecx, 0x8000
    (cpu.ecx) += x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 0048fef2  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0048fef6  8b4a08                 -mov ecx, dword ptr [edx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0048fef9  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 0048fefc  81c100800000           -add ecx, 0x8000
    (cpu.ecx) += x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 0048ff02  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0048ff06  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0048ff09  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 0048ff0c  81c100800000           -add ecx, 0x8000
    (cpu.ecx) += x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 0048ff12  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0048ff16  8b4a10                 -mov ecx, dword ptr [edx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0048ff19  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 0048ff1c  81c100800000           -add ecx, 0x8000
    (cpu.ecx) += x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 0048ff22  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 0048ff26  8b5214                 -mov edx, dword ptr [edx + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 0048ff29  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0048ff2c  81c200800000           -add edx, 0x8000
    (cpu.edx) += x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 0048ff32  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 0048ff36  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0048ff38  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0048ff3b  81c200800000           -add edx, 0x8000
    (cpu.edx) += x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 0048ff41  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 0048ff45  8b5304                 -mov edx, dword ptr [ebx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0048ff48  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0048ff4b  81c200800000           -add edx, 0x8000
    (cpu.edx) += x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 0048ff51  8954241c               -mov dword ptr [esp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 0048ff55  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0048ff58  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0048ff5b  81c200800000           -add edx, 0x8000
    (cpu.edx) += x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 0048ff61  89542420               -mov dword ptr [esp + 0x20], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 0048ff65  8b530c                 -mov edx, dword ptr [ebx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 0048ff68  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0048ff6b  81c200800000           -add edx, 0x8000
    (cpu.edx) += x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 0048ff71  89542424               -mov dword ptr [esp + 0x24], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 0048ff75  8b5310                 -mov edx, dword ptr [ebx + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 0048ff78  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0048ff7b  81c200800000           -add edx, 0x8000
    (cpu.edx) += x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 0048ff81  89542428               -mov dword ptr [esp + 0x28], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 0048ff85  8b5314                 -mov edx, dword ptr [ebx + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 0048ff88  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0048ff8b  81c200800000           -add edx, 0x8000
    (cpu.edx) += x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 0048ff91  8d5c2418               -lea ebx, [esp + 0x18]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0048ff95  8954242c               -mov dword ptr [esp + 0x2c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.edx;
    // 0048ff99  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0048ff9b  e854f5ffff             -call 0x48f4f4
    cpu.esp -= 4;
    sub_48f4f4(app, cpu);
    if (cpu.terminate) return;
    // 0048ffa0  83c430                 -add esp, 0x30
    (cpu.esp) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 0048ffa3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ffa4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_48ffb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048ffb0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048ffb1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048ffb2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048ffb3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048ffb4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048ffb5  83ec34                 -sub esp, 0x34
    (cpu.esp) -= x86::reg32(x86::sreg32(52 /*0x34*/));
    // 0048ffb8  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048ffba  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0048ffbc  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048ffbe  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048ffc0  89542430               -mov dword ptr [esp + 0x30], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.edx;
    // 0048ffc4  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0048ffc9  8a15ed844c00           -mov dl, byte ptr [0x4c84ed]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5014765) /* 0x4c84ed */);
    // 0048ffcf  39d0                   +cmp eax, edx
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
    // 0048ffd1  7415                   -je 0x48ffe8
    if (cpu.flags.zf)
    {
        goto L_0x0048ffe8;
    }
    // 0048ffd3  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048ffd5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048ffd7  8a15ed844c00           -mov dl, byte ptr [0x4c84ed]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5014765) /* 0x4c84ed */);
    // 0048ffdd  e8d62b0000             -call 0x492bb8
    cpu.esp -= 4;
    sub_492bb8(app, cpu);
    if (cpu.terminate) return;
    // 0048ffe2  89442430               -mov dword ptr [esp + 0x30], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 0048ffe6  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x0048ffe8:
    // 0048ffe8  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0048ffed  8d542418               -lea edx, [esp + 0x18]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0048fff1  8b4102                 -mov eax, dword ptr [ecx + 2]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 0048fff4  8b7104                 -mov esi, dword ptr [ecx + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0048fff7  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0048fffa  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 0048fffd  895c2418               -mov dword ptr [esp + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 00490001  895c241c               -mov dword ptr [esp + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 00490005  895c2424               -mov dword ptr [esp + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 00490009  83e802                 -sub eax, 2
    (cpu.eax) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049000c  83ee02                 -sub esi, 2
    (cpu.esi) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049000f  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 00490011  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 00490015  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00490017  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 0049001b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049001d  8974242c               -mov dword ptr [esp + 0x2c], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.esi;
    // 00490021  e80a700000             -call 0x497030
    cpu.esp -= 4;
    sub_497030(app, cpu);
    if (cpu.terminate) return;
    // 00490026  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0049002b  897c2418               -mov dword ptr [esp + 0x18], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 0049002f  8974241c               -mov dword ptr [esp + 0x1c], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.esi;
    // 00490033  89742424               -mov dword ptr [esp + 0x24], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.esi;
    // 00490037  89542420               -mov dword ptr [esp + 0x20], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 0049003b  89542428               -mov dword ptr [esp + 0x28], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 0049003f  8954242c               -mov dword ptr [esp + 0x2c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.edx;
    // 00490043  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00490045  8d7510                 -lea esi, [ebp + 0x10]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00490048  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00490049  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049004a  8d7c2408               -lea edi, [esp + 8]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049004e  8d7518                 -lea esi, [ebp + 0x18]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00490051  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00490052  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00490053  8d7c2410               -lea edi, [esp + 0x10]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00490057  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
    // 00490059  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0049005b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049005d  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049005e  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049005f  8d542418               -lea edx, [esp + 0x18]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00490063  8b7c2430               -mov edi, dword ptr [esp + 0x30]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00490067  e8c46f0000             -call 0x497030
    cpu.esp -= 4;
    sub_497030(app, cpu);
    if (cpu.terminate) return;
    // 0049006c  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049006e  7509                   -jne 0x490079
    if (!cpu.flags.zf)
    {
        goto L_0x00490079;
    }
    // 00490070  83c434                 -add esp, 0x34
    (cpu.esp) += x86::reg32(x86::sreg32(52 /*0x34*/));
    // 00490073  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490074  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490075  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490076  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490077  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490078  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00490079:
    // 00490079  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049007b  e84c8afeff             -call 0x478acc
    cpu.esp -= 4;
    sub_478acc(app, cpu);
    if (cpu.terminate) return;
    // 00490080  83c434                 -add esp, 0x34
    (cpu.esp) += x86::reg32(x86::sreg32(52 /*0x34*/));
    // 00490083  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490084  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490085  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490086  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490087  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490088  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49008c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049008c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049008d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049008e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049008f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00490090  83ec38                 -sub esp, 0x38
    (cpu.esp) -= x86::reg32(x86::sreg32(56 /*0x38*/));
    // 00490093  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00490095  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00490097  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00490099  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049009b  8b17                   -mov edx, dword ptr [edi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi);
    // 0049009d  a0ed844c00             -mov al, byte ptr [0x4c84ed]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5014765) /* 0x4c84ed */);
    // 004900a2  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004900a8  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004900aa  39c2                   +cmp edx, eax
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
    // 004900ac  740f                   -je 0x4900bd
    if (cpu.flags.zf)
    {
        goto L_0x004900bd;
    }
    // 004900ae  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004900b0  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 004900b2  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004900b4  e8ff2a0000             -call 0x492bb8
    cpu.esp -= 4;
    sub_492bb8(app, cpu);
    if (cpu.terminate) return;
    // 004900b9  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004900bb  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x004900bd:
    // 004900bd  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004900c2  8b4702                 -mov eax, dword ptr [edi + 2]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 004900c5  8b5704                 -mov edx, dword ptr [edi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 004900c8  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004900cb  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004900ce  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 004900d1  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004900d5  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 004900d9  83e802                 -sub eax, 2
    (cpu.eax) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004900dc  83ea02                 -sub edx, 2
    (cpu.edx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004900df  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004900e3  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004900e7  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004900eb  89442434               -mov dword ptr [esp + 0x34], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 004900ef  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004900f1  8b04c1                 -mov eax, dword ptr [ecx + eax*8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 8);
    // 004900f4  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004900f8  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004900fa  8b44c104               -mov eax, dword ptr [ecx + eax*8 + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.eax * 8);
    // 004900fe  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00490102  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00490105  8b04c1                 -mov eax, dword ptr [ecx + eax*8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 8);
    // 00490108  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0049010c  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0049010f  8b44c104               -mov eax, dword ptr [ecx + eax*8 + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.eax * 8);
    // 00490113  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 00490117  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0049011a  8b04c1                 -mov eax, dword ptr [ecx + eax*8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 8);
    // 0049011d  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 00490121  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00490124  8d5c2418               -lea ebx, [esp + 0x18]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00490128  89542430               -mov dword ptr [esp + 0x30], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.edx;
    // 0049012c  8b44c104               -mov eax, dword ptr [ecx + eax*8 + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.eax * 8);
    // 00490130  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00490132  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 00490136  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00490138  e8f36e0000             -call 0x497030
    cpu.esp -= 4;
    sub_497030(app, cpu);
    if (cpu.terminate) return;
    // 0049013d  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00490141  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00490146  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00490149  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0049014d  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 00490151  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00490155  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 00490159  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0049015d  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00490161  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00490164  8b04c1                 -mov eax, dword ptr [ecx + eax*8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 8);
    // 00490167  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0049016b  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0049016e  8b44c104               -mov eax, dword ptr [ecx + eax*8 + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.eax * 8);
    // 00490172  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00490176  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00490179  8b04c1                 -mov eax, dword ptr [ecx + eax*8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 8);
    // 0049017c  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 00490180  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00490183  8b44c104               -mov eax, dword ptr [ecx + eax*8 + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.eax * 8);
    // 00490187  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 0049018b  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0049018d  8b04c1                 -mov eax, dword ptr [ecx + eax*8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 8);
    // 00490190  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 00490194  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00490196  8d5c2418               -lea ebx, [esp + 0x18]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0049019a  8b44c104               -mov eax, dword ptr [ecx + eax*8 + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.eax * 8);
    // 0049019e  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004901a0  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 004901a4  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004901a6  e8856e0000             -call 0x497030
    cpu.esp -= 4;
    sub_497030(app, cpu);
    if (cpu.terminate) return;
    // 004901ab  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004901ad  7508                   -jne 0x4901b7
    if (!cpu.flags.zf)
    {
        goto L_0x004901b7;
    }
    // 004901af  83c438                 -add esp, 0x38
    (cpu.esp) += x86::reg32(x86::sreg32(56 /*0x38*/));
    // 004901b2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004901b3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004901b4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004901b5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004901b6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004901b7:
    // 004901b7  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004901b9  e80e89feff             -call 0x478acc
    cpu.esp -= 4;
    sub_478acc(app, cpu);
    if (cpu.terminate) return;
    // 004901be  83c438                 -add esp, 0x38
    (cpu.esp) += x86::reg32(x86::sreg32(56 /*0x38*/));
    // 004901c1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004901c2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004901c3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004901c4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004901c5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4901d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004901d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004901d1  8a1dec844c00           -mov bl, byte ptr [0x4c84ec]
    cpu.bl = app->getMemory<x86::reg8>(x86::reg32(5014764) /* 0x4c84ec */);
    // 004901d7  80fb08                 +cmp bl, 8
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(8 /*0x8*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004901da  7411                   -je 0x4901ed
    if (cpu.flags.zf)
    {
        goto L_0x004901ed;
    }
    // 004901dc  80fb10                 +cmp bl, 0x10
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004901df  7419                   -je 0x4901fa
    if (cpu.flags.zf)
    {
        goto L_0x004901fa;
    }
    // 004901e1  80fb0f                 +cmp bl, 0xf
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(15 /*0xf*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004901e4  7414                   -je 0x4901fa
    if (cpu.flags.zf)
    {
        goto L_0x004901fa;
    }
    // 004901e6  80fb20                 +cmp bl, 0x20
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
    // 004901e9  7421                   -je 0x49020c
    if (cpu.flags.zf)
    {
        goto L_0x0049020c;
    }
    // 004901eb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004901ec  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004901ed:
    // 004901ed  8b1d606b5200           -mov ebx, dword ptr [0x526b60]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5401440) /* 0x526b60 */);
    // 004901f3  e8eeeefeff             -call 0x47f0e6
    cpu.esp -= 4;
    sub_47f0e6(app, cpu);
    if (cpu.terminate) return;
    // 004901f8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004901f9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004901fa:
    // 004901fa  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004901fc  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004901fe  668b1d606b5200         -mov bx, word ptr [0x526b60]
    cpu.bx = app->getMemory<x86::reg16>(x86::reg32(5401440) /* 0x526b60 */);
    // 00490205  e8deeefeff             -call 0x47f0e8
    cpu.esp -= 4;
    sub_47f0e8(app, cpu);
    if (cpu.terminate) return;
    // 0049020a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049020b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049020c:
    // 0049020c  8b1d606b5200           -mov ebx, dword ptr [0x526b60]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5401440) /* 0x526b60 */);
    // 00490212  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 00490215  e8d7eefeff             -call 0x47f0f1
    cpu.esp -= 4;
    sub_47f0f1(app, cpu);
    if (cpu.terminate) return;
    // 0049021a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049021b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49021c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049021c  e997350100             -jmp 0x4a37b8
    return sub_4a37b8(app, cpu);
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_490224(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00490224  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00490225  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00490226  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00490229  8b7cda04               -mov edi, dword ptr [edx + ebx*8 + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */ + cpu.ebx * 8);
    // 0049022d  3b7cca04               +cmp edi, dword ptr [edx + ecx*8 + 4]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */ + cpu.ecx * 8)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00490231  7e06                   -jle 0x490239
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00490239;
    }
    // 00490233  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00490235  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00490237  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
L_0x00490239:
    // 00490239  c1e103                 -shl ecx, 3
    cpu.ecx <<= 3 /*0x3*/ % 32;
    // 0049023c  c1e303                 -shl ebx, 3
    cpu.ebx <<= 3 /*0x3*/ % 32;
    // 0049023f  8d340a                 -lea esi, [edx + ecx]
    cpu.esi = x86::reg32(cpu.edx + cpu.ecx * 1);
    // 00490242  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00490244  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00490247  8b7a04                 -mov edi, dword ptr [edx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049024a  29fb                   +sub ebx, edi
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049024c  895824                 -mov dword ptr [eax + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 0049024f  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00490252  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00490255  7506                   -jne 0x49025d
    if (!cpu.flags.zf)
    {
        goto L_0x0049025d;
    }
    // 00490257  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049025a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049025b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049025c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049025d:
    // 0049025d  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 0049025f  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 00490262  894818                 -mov dword ptr [eax + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 00490265  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 00490267  2b0a                   -sub ecx, dword ptr [edx]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
    // 00490269  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 0049026c  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 0049026f  db0424                 -fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 00490272  d80c9d302d5400         -fmul dword ptr [ebx*4 + 0x542d30]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5516592) /* 0x542d30 */ + cpu.ebx * 4));
    // 00490279  d8050ca74c00           -fadd dword ptr [0x4ca70c]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5023500) /* 0x4ca70c */));
    // 0049027f  dd18                   -fstp qword ptr [eax]
    app->getMemory<double>(cpu.eax) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00490281  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00490283  89501c                 -mov dword ptr [eax + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 00490286  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00490289  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049028a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049028b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49028c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049028c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049028d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049028e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049028f  83ec1c                 -sub esp, 0x1c
    (cpu.esp) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00490292  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00490296  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00490298  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0049029a  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0049029e  8b15fc844c00           -mov edx, dword ptr [0x4c84fc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5014780) /* 0x4c84fc */);
    // 004902a4  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004902a7  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004902a9  a1f0844c00             -mov eax, dword ptr [0x4c84f0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5014768) /* 0x4c84f0 */);
    // 004902ae  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 004902b0  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004902b2  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 004902b9  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 004902bd  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004902bf  8b1d04a74c00           -mov ebx, dword ptr [0x4ca704]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5023492) /* 0x4ca704 */);
    // 004902c5  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004902c8  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004902ca  8d0c03                 -lea ecx, [ebx + eax]
    cpu.ecx = x86::reg32(cpu.ebx + cpu.eax * 1);
    // 004902cd  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004902d4  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004902d6  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004902d9  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004902db  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004902df  48                     -dec eax
    (cpu.eax)--;
    // 004902e0  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
L_0x004902e4:
    // 004902e4  837b2400               +cmp dword ptr [ebx + 0x24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004902e8  0f8e89000000           -jle 0x490377
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00490377;
    }
L_0x004902ee:
    // 004902ee  8b6924                 -mov ebp, dword ptr [ecx + 0x24]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */);
    // 004902f1  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004902f3  0f8ebf000000           -jle 0x4903b8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004903b8;
    }
    // 004902f9  8b4324                 -mov eax, dword ptr [ebx + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */);
    // 004902fc  39e8                   +cmp eax, ebp
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
    // 004902fe  0f8de3000000           -jge 0x4903e7
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004903e7;
    }
L_0x00490304:
    // 00490304  8b6b24                 -mov ebp, dword ptr [ebx + 0x24]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */);
    // 00490307  29c5                   -sub ebp, eax
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00490309  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0049030d  896b24                 -mov dword ptr [ebx + 0x24], ebp
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */) = cpu.ebp;
    // 00490310  8b6c240c               -mov ebp, dword ptr [esp + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00490314  8b5124                 -mov edx, dword ptr [ecx + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */);
    // 00490317  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 00490319  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049031b  896c240c               -mov dword ptr [esp + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 0049031f  895124                 -mov dword ptr [ecx + 0x24], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 00490322  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
L_0x00490324:
    // 00490324  74be                   -je 0x4902e4
    if (cpu.flags.zf)
    {
        goto L_0x004902e4;
    }
    // 00490326  8b6918                 -mov ebp, dword ptr [ecx + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 00490329  8b4318                 -mov eax, dword ptr [ebx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 0049032c  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0049032e  81e20000ffff           -and edx, 0xffff0000
    cpu.edx &= x86::reg32(x86::sreg32(4294901760 /*0xffff0000*/));
    // 00490334  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00490336  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00490339  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049033b  0f8fad000000           -jg 0x4903ee
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004903ee;
    }
    // 00490341  0f8cce000000           -jl 0x490415
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00490415;
    }
L_0x00490347:
    // 00490347  8b6c2418               -mov ebp, dword ptr [esp + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0049034b  a1f8844c00             -mov eax, dword ptr [0x4c84f8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5014776) /* 0x4c84f8 */);
    // 00490350  8b5118                 -mov edx, dword ptr [ecx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 00490353  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 00490355  8b411c                 -mov eax, dword ptr [ecx + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 00490358  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049035a  895118                 -mov dword ptr [ecx + 0x18], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 0049035d  896c2418               -mov dword ptr [esp + 0x18], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ebp;
    // 00490361  8b431c                 -mov eax, dword ptr [ebx + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */);
    // 00490364  8b6b18                 -mov ebp, dword ptr [ebx + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 00490367  01c5                   +add ebp, eax
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
    // 00490369  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0049036d  896b18                 -mov dword ptr [ebx + 0x18], ebp
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */) = cpu.ebp;
    // 00490370  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00490371  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00490375  ebad                   -jmp 0x490324
    goto L_0x00490324;
L_0x00490377:
    // 00490377  4e                     -dec esi
    (cpu.esi)--;
    // 00490378  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049037a  7c20                   -jl 0x49039c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049039c;
    }
    // 0049037c  83eb28                 -sub ebx, 0x28
    (cpu.ebx) -= x86::reg32(x86::sreg32(40 /*0x28*/));
L_0x0049037f:
    // 0049037f  39fe                   +cmp esi, edi
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
    // 00490381  7429                   -je 0x4903ac
    if (cpu.flags.zf)
    {
        goto L_0x004903ac;
    }
    // 00490383  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00490387  3b4320                 +cmp eax, dword ptr [ebx + 0x20]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049038a  0f8e54ffffff           -jle 0x4902e4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004902e4;
    }
    // 00490390  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00490395  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00490398  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490399  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049039a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049039b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049039c:
    // 0049039c  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004903a0  6bde28                 -imul ebx, esi, 0x28
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(40 /*0x28*/)));
    // 004903a3  a104a74c00             -mov eax, dword ptr [0x4ca704]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023492) /* 0x4ca704 */);
    // 004903a8  01c3                   +add ebx, eax
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
    // 004903aa  ebd3                   -jmp 0x49037f
    goto L_0x0049037f;
L_0x004903ac:
    // 004903ac  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004903b1  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004903b4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004903b5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004903b6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004903b7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004903b8:
    // 004903b8  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004903bc  47                     -inc edi
    (cpu.edi)++;
    // 004903bd  39c7                   +cmp edi, eax
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
    // 004903bf  7c21                   -jl 0x4903e2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004903e2;
    }
    // 004903c1  8b0d04a74c00           -mov ecx, dword ptr [0x4ca704]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5023492) /* 0x4ca704 */);
    // 004903c7  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x004903c9:
    // 004903c9  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004903cd  3b4120                 +cmp eax, dword ptr [ecx + 0x20]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004903d0  0f8e18ffffff           -jle 0x4902ee
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004902ee;
    }
    // 004903d6  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004903db  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004903de  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004903df  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004903e0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004903e1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004903e2:
    // 004903e2  83c128                 +add ecx, 0x28
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(40 /*0x28*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004903e5  ebe2                   -jmp 0x4903c9
    goto L_0x004903c9;
L_0x004903e7:
    // 004903e7  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004903e9  e916ffffff             -jmp 0x490304
    goto L_0x00490304;
L_0x004903ee:
    // 004903ee  c1fd10                 -sar ebp, 0x10
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (16 /*0x10*/ % 32));
    // 004903f1  8d14ad00000000         -lea edx, [ebp*4]
    cpu.edx = x86::reg32(cpu.ebp * 4);
    // 004903f8  8b2d00854c00           -mov ebp, dword ptr [0x4c8500]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5014784) /* 0x4c8500 */);
    // 004903fe  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00490400  8b6c2418               -mov ebp, dword ptr [esp + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00490404  032a                   +add ebp, dword ptr [edx]
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00490406  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00490408  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0049040a  ff1580a74c00           -call dword ptr [0x4ca780]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5023616) /* 0x4ca780 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00490410  e932ffffff             -jmp 0x490347
    goto L_0x00490347;
L_0x00490415:
    // 00490415  8b4318                 -mov eax, dword ptr [ebx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 00490418  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0049041c  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00490420  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 00490423  81e20000ffff           -and edx, 0xffff0000
    cpu.edx &= x86::reg32(x86::sreg32(4294901760 /*0xffff0000*/));
    // 00490429  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049042b  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0049042e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00490430  83f801                 +cmp eax, 1
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
    // 00490433  7d05                   -jge 0x49043a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049043a;
    }
    // 00490435  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x0049043a:
    // 0049043a  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0049043e  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00490441  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00490444  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00490447  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 0049044a  a100854c00             -mov eax, dword ptr [0x4c8500]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5014784) /* 0x4c8500 */);
    // 0049044f  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00490451  8b6c2418               -mov ebp, dword ptr [esp + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00490455  0328                   +add ebp, dword ptr [eax]
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00490457  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00490459  ff1580a74c00           -call dword ptr [0x4ca780]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5023616) /* 0x4ca780 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049045f  e9e3feffff             -jmp 0x490347
    goto L_0x00490347;
}

/* align: skip  */
void Application::sub_490464(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00490464  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00490465  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00490466  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00490467  83ec1c                 -sub esp, 0x1c
    (cpu.esp) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0049046a  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0049046e  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00490470  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00490472  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00490476  8b15fc844c00           -mov edx, dword ptr [0x4c84fc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5014780) /* 0x4c84fc */);
    // 0049047c  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049047f  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00490481  a1f0844c00             -mov eax, dword ptr [0x4c84f0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5014768) /* 0x4c84f0 */);
    // 00490486  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 00490488  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049048a  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 0049048e  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00490490  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00490497  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00490499  8b1d04a74c00           -mov ebx, dword ptr [0x4ca704]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5023492) /* 0x4ca704 */);
    // 0049049f  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004904a2  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004904a4  8d0c03                 -lea ecx, [ebx + eax]
    cpu.ecx = x86::reg32(cpu.ebx + cpu.eax * 1);
    // 004904a7  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004904ae  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004904b0  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004904b3  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004904b5  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004904b9  48                     -dec eax
    (cpu.eax)--;
    // 004904ba  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
L_0x004904be:
    // 004904be  83792400               +cmp dword ptr [ecx + 0x24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004904c2  0f8e8b000000           -jle 0x490553
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00490553;
    }
L_0x004904c8:
    // 004904c8  8b6b24                 -mov ebp, dword ptr [ebx + 0x24]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */);
    // 004904cb  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004904cd  0f8ec1000000           -jle 0x490594
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00490594;
    }
    // 004904d3  8b5124                 -mov edx, dword ptr [ecx + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */);
    // 004904d6  39d5                   +cmp ebp, edx
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004904d8  0f8de5000000           -jge 0x4905c3
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004905c3;
    }
    // 004904de  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
L_0x004904e0:
    // 004904e0  8b6b24                 -mov ebp, dword ptr [ebx + 0x24]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */);
    // 004904e3  29c5                   -sub ebp, eax
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004904e5  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004904e9  896b24                 -mov dword ptr [ebx + 0x24], ebp
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */) = cpu.ebp;
    // 004904ec  8b6c240c               -mov ebp, dword ptr [esp + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004904f0  8b5124                 -mov edx, dword ptr [ecx + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */);
    // 004904f3  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 004904f5  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004904f7  896c240c               -mov dword ptr [esp + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 004904fb  895124                 -mov dword ptr [ecx + 0x24], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 004904fe  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
L_0x00490500:
    // 00490500  74bc                   -je 0x4904be
    if (cpu.flags.zf)
    {
        goto L_0x004904be;
    }
    // 00490502  8b6918                 -mov ebp, dword ptr [ecx + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 00490505  8b4318                 -mov eax, dword ptr [ebx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 00490508  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0049050a  81e20000ffff           -and edx, 0xffff0000
    cpu.edx &= x86::reg32(x86::sreg32(4294901760 /*0xffff0000*/));
    // 00490510  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00490512  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00490515  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00490517  0f8fad000000           -jg 0x4905ca
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004905ca;
    }
    // 0049051d  0f8cce000000           -jl 0x4905f1
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004905f1;
    }
L_0x00490523:
    // 00490523  8b6c2418               -mov ebp, dword ptr [esp + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00490527  a1f8844c00             -mov eax, dword ptr [0x4c84f8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5014776) /* 0x4c84f8 */);
    // 0049052c  8b5118                 -mov edx, dword ptr [ecx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 0049052f  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 00490531  8b411c                 -mov eax, dword ptr [ecx + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 00490534  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00490536  895118                 -mov dword ptr [ecx + 0x18], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 00490539  896c2418               -mov dword ptr [esp + 0x18], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ebp;
    // 0049053d  8b431c                 -mov eax, dword ptr [ebx + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */);
    // 00490540  8b6b18                 -mov ebp, dword ptr [ebx + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 00490543  01c5                   +add ebp, eax
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
    // 00490545  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00490549  896b18                 -mov dword ptr [ebx + 0x18], ebp
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */) = cpu.ebp;
    // 0049054c  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0049054d  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00490551  ebad                   -jmp 0x490500
    goto L_0x00490500;
L_0x00490553:
    // 00490553  4e                     -dec esi
    (cpu.esi)--;
    // 00490554  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00490556  7c20                   -jl 0x490578
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00490578;
    }
    // 00490558  83e928                 -sub ecx, 0x28
    (cpu.ecx) -= x86::reg32(x86::sreg32(40 /*0x28*/));
L_0x0049055b:
    // 0049055b  39fe                   +cmp esi, edi
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
    // 0049055d  7429                   -je 0x490588
    if (cpu.flags.zf)
    {
        goto L_0x00490588;
    }
    // 0049055f  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00490563  3b4120                 +cmp eax, dword ptr [ecx + 0x20]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00490566  0f8e52ffffff           -jle 0x4904be
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004904be;
    }
    // 0049056c  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00490571  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00490574  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490575  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490576  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490577  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00490578:
    // 00490578  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049057c  6bce28                 -imul ecx, esi, 0x28
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(40 /*0x28*/)));
    // 0049057f  a104a74c00             -mov eax, dword ptr [0x4ca704]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023492) /* 0x4ca704 */);
    // 00490584  01c1                   +add ecx, eax
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
    // 00490586  ebd3                   -jmp 0x49055b
    goto L_0x0049055b;
L_0x00490588:
    // 00490588  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049058d  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00490590  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490591  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490592  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490593  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00490594:
    // 00490594  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00490598  47                     -inc edi
    (cpu.edi)++;
    // 00490599  39c7                   +cmp edi, eax
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
    // 0049059b  7c21                   -jl 0x4905be
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004905be;
    }
    // 0049059d  8b1d04a74c00           -mov ebx, dword ptr [0x4ca704]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5023492) /* 0x4ca704 */);
    // 004905a3  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x004905a5:
    // 004905a5  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004905a9  3b4320                 +cmp eax, dword ptr [ebx + 0x20]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004905ac  0f8e16ffffff           -jle 0x4904c8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004904c8;
    }
    // 004905b2  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004905b7  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004905ba  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004905bb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004905bc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004905bd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004905be:
    // 004905be  83c328                 +add ebx, 0x28
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(40 /*0x28*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004905c1  ebe2                   -jmp 0x4905a5
    goto L_0x004905a5;
L_0x004905c3:
    // 004905c3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004905c5  e916ffffff             -jmp 0x4904e0
    goto L_0x004904e0;
L_0x004905ca:
    // 004905ca  c1fd10                 -sar ebp, 0x10
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (16 /*0x10*/ % 32));
    // 004905cd  8d14ad00000000         -lea edx, [ebp*4]
    cpu.edx = x86::reg32(cpu.ebp * 4);
    // 004905d4  8b2d00854c00           -mov ebp, dword ptr [0x4c8500]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5014784) /* 0x4c8500 */);
    // 004905da  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004905dc  8b6c2418               -mov ebp, dword ptr [esp + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004905e0  032a                   +add ebp, dword ptr [edx]
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004905e2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004905e4  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004905e6  ff1580a74c00           -call dword ptr [0x4ca780]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5023616) /* 0x4ca780 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004905ec  e932ffffff             -jmp 0x490523
    goto L_0x00490523;
L_0x004905f1:
    // 004905f1  8b4318                 -mov eax, dword ptr [ebx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004905f4  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004905f8  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004905fc  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 004905ff  81e20000ffff           -and edx, 0xffff0000
    cpu.edx &= x86::reg32(x86::sreg32(4294901760 /*0xffff0000*/));
    // 00490605  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00490607  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0049060a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049060c  83f801                 +cmp eax, 1
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
    // 0049060f  7d05                   -jge 0x490616
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00490616;
    }
    // 00490611  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x00490616:
    // 00490616  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0049061a  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0049061d  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00490620  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00490623  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 00490626  a100854c00             -mov eax, dword ptr [0x4c8500]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5014784) /* 0x4c8500 */);
    // 0049062b  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0049062d  8b6c2418               -mov ebp, dword ptr [esp + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00490631  0328                   +add ebp, dword ptr [eax]
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00490633  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00490635  ff1580a74c00           -call dword ptr [0x4ca780]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5023616) /* 0x4ca780 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049063b  e9e3feffff             -jmp 0x490523
    goto L_0x00490523;
}

/* align: skip  */
void Application::sub_490640(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00490640  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00490641  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00490642  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00490643  83ec2c                 -sub esp, 0x2c
    (cpu.esp) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00490646  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00490648  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0049064a  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0049064d  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00490651  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00490653  8b0d04a74c00           -mov ecx, dword ptr [0x4ca704]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5023492) /* 0x4ca704 */);
    // 00490659  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0049065d  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049065f  0f84e5010000           -je 0x49084a
    if (cpu.flags.zf)
    {
        goto L_0x0049084a;
    }
L_0x00490665:
    // 00490665  8b44243c               -mov eax, dword ptr [esp + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00490669  8b048584a74c00         -mov eax, dword ptr [eax*4 + 0x4ca784]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023620) /* 0x4ca784 */ + cpu.eax * 4);
    // 00490670  a380a74c00             -mov dword ptr [0x4ca780], eax
    app->getMemory<x86::reg32>(x86::reg32(5023616) /* 0x4ca780 */) = cpu.eax;
    // 00490675  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00490678  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0049067a  8935606b5200           -mov dword ptr [0x526b60], esi
    app->getMemory<x86::reg32>(x86::reg32(5401440) /* 0x526b60 */) = cpu.esi;
    // 00490680  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00490684  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00490688  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0049068b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049068d  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 00490692  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00490695  895c2418               -mov dword ptr [esp + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 00490699  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0049069d  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049069f  39f5                   +cmp ebp, esi
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004906a1  7e31                   -jle 0x4906d4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004906d4;
    }
    // 004906a3  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004906a6  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x004906a9:
    // 004906a9  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004906ac  39d7                   +cmp edi, edx
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
    // 004906ae  0f8ea0010000           -jle 0x490854
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00490854;
    }
    // 004906b4  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004906b6  89742418               -mov dword ptr [esp + 0x18], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.esi;
L_0x004906ba:
    // 004906ba  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004906be  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004906c0  39da                   +cmp edx, ebx
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
    // 004906c2  0f8d9f010000           -jge 0x490867
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00490867;
    }
    // 004906c8  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
L_0x004906cc:
    // 004906cc  46                     -inc esi
    (cpu.esi)++;
    // 004906cd  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004906d0  39ee                   +cmp esi, ebp
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
    // 004906d2  7cd5                   -jl 0x4906a9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004906a9;
    }
L_0x004906d4:
    // 004906d4  3b3de8844c00           +cmp edi, dword ptr [0x4c84e8]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014760) /* 0x4c84e8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004906da  0f8d9a010000           -jge 0x49087a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049087a;
    }
    // 004906e0  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004906e4  3b05e0844c00           +cmp eax, dword ptr [0x4c84e0]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014752) /* 0x4c84e0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004906ea  0f8c8a010000           -jl 0x49087a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049087a;
    }
    // 004906f0  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004906f4  3b05e4844c00           +cmp eax, dword ptr [0x4c84e4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014756) /* 0x4c84e4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004906fa  0f8d7a010000           -jge 0x49087a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049087a;
    }
    // 00490700  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00490704  3b05dc844c00           +cmp eax, dword ptr [0x4c84dc]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014748) /* 0x4c84dc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049070a  0f8c6a010000           -jl 0x49087a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049087a;
    }
    // 00490710  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00490714  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00490716  754f                   -jne 0x490767
    if (!cpu.flags.zf)
    {
        goto L_0x00490767;
    }
    // 00490718  8d45fe                 -lea eax, [ebp - 2]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-2) /* -0x2 */);
    // 0049071b  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0049071e  89742428               -mov dword ptr [esp + 0x28], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.esi;
    // 00490722  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
L_0x00490726:
    // 00490726  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0049072a  3b442410               +cmp eax, dword ptr [esp + 0x10]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049072e  7d37                   -jge 0x490767
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00490767;
    }
    // 00490730  8b742428               -mov esi, dword ptr [esp + 0x28]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00490734  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00490737  8d5e08                 -lea ebx, [esi + 8]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0049073a  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049073c  895c2428               -mov dword ptr [esp + 0x28], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ebx;
    // 00490740  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00490743  8b5e14                 -mov ebx, dword ptr [esi + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00490746  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 00490748  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0049074b  2b4608                 -sub eax, dword ptr [esi + 8]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */)));
    // 0049074e  2b5e0c                 -sub ebx, dword ptr [esi + 0xc]
    (cpu.ebx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */)));
    // 00490751  2b4e08                 -sub ecx, dword ptr [esi + 8]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */)));
    // 00490754  2b560c                 -sub edx, dword ptr [esi + 0xc]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */)));
    // 00490757  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0049075a  0fafd9                 -imul ebx, ecx
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0049075d  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049075f  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 00490763  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00490765  74bf                   -je 0x490726
    if (cpu.flags.zf)
    {
        goto L_0x00490726;
    }
L_0x00490767:
    // 00490767  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0049076b  3b05dc844c00           +cmp eax, dword ptr [0x4c84dc]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014748) /* 0x4c84dc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00490771  0f8c0e010000           -jl 0x490885
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00490885;
    }
L_0x00490777:
    // 00490777  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0049077b  3b05e4844c00           +cmp eax, dword ptr [0x4c84e4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014756) /* 0x4c84e4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00490781  0f8d1b010000           -jge 0x4908a2
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004908a2;
    }
L_0x00490787:
    // 00490787  3b3de0844c00           +cmp edi, dword ptr [0x4c84e0]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014752) /* 0x4c84e0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049078d  0f8c2c010000           -jl 0x4908bf
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004908bf;
    }
L_0x00490793:
    // 00490793  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00490797  3b05e8844c00           +cmp eax, dword ptr [0x4c84e8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014760) /* 0x4c84e8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049079d  0f8d39010000           -jge 0x4908dc
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004908dc;
    }
    // 004907a3  837c240800             +cmp dword ptr [esp + 8], 0
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
    // 004907a8  7436                   -je 0x4907e0
    if (cpu.flags.zf)
    {
        goto L_0x004907e0;
    }
L_0x004907aa:
    // 004907aa  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004907ac  895c2418               -mov dword ptr [esp + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 004907b0  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 004907b3  8b5b04                 -mov ebx, dword ptr [ebx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004907b6  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 004907bb  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004907bd  39f5                   +cmp ebp, esi
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004907bf  7e1f                   -jle 0x4907e0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004907e0;
    }
    // 004907c1  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004907c4  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x004907c7:
    // 004907c7  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004907ca  39d7                   +cmp edi, edx
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
    // 004907cc  0f8e29010000           -jle 0x4908fb
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004908fb;
    }
    // 004907d2  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004907d4  89742418               -mov dword ptr [esp + 0x18], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.esi;
L_0x004907d8:
    // 004907d8  46                     -inc esi
    (cpu.esi)++;
    // 004907d9  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004907dc  39ee                   +cmp esi, ebp
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
    // 004907de  7ce7                   -jl 0x4907c7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004907c7;
    }
L_0x004907e0:
    // 004907e0  8d45ff                 -lea eax, [ebp - 1]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-1) /* -0x1 */);
    // 004907e3  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004907e5  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004907e7  7e37                   -jle 0x490820
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00490820;
    }
    // 004907e9  89742424               -mov dword ptr [esp + 0x24], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.esi;
L_0x004907ed:
    // 004907ed  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004907f1  8b1d04a74c00           -mov ebx, dword ptr [0x4ca704]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5023492) /* 0x4ca704 */);
    // 004907f7  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004907f9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004907fb  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004907ff  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00490801  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00490804  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00490808  e817faffff             -call 0x490224
    cpu.esp -= 4;
    sub_490224(app, cpu);
    if (cpu.terminate) return;
    // 0049080d  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00490811  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00490813  83c328                 -add ebx, 0x28
    (cpu.ebx) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 00490816  46                     -inc esi
    (cpu.esi)++;
    // 00490817  895c2424               -mov dword ptr [esp + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 0049081b  39ee                   +cmp esi, ebp
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
    // 0049081d  7cce                   -jl 0x4907ed
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004907ed;
    }
    // 0049081f  90                     -nop 
    ;
L_0x00490820:
    // 00490820  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00490824  8d5a01                 -lea ebx, [edx + 1]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00490827  39eb                   +cmp ebx, ebp
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
    // 00490829  7c02                   -jl 0x49082d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049082d;
    }
    // 0049082b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0049082d:
    // 0049082d  837c240c00             +cmp dword ptr [esp + 0xc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00490832  0f8cd2000000           -jl 0x49090a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049090a;
    }
    // 00490838  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0049083a  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049083c  e84bfaffff             -call 0x49028c
    cpu.esp -= 4;
    sub_49028c(app, cpu);
    if (cpu.terminate) return;
    // 00490841  83c42c                 +add esp, 0x2c
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(44 /*0x2c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00490844  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490845  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490846  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490847  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0049084a:
    // 0049084a  e821d4ffff             -call 0x48dc70
    cpu.esp -= 4;
    sub_48dc70(app, cpu);
    if (cpu.terminate) return;
    // 0049084f  e911feffff             -jmp 0x490665
    goto L_0x00490665;
L_0x00490854:
    // 00490854  3b542420               +cmp edx, dword ptr [esp + 0x20]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00490858  0f8e5cfeffff           -jle 0x4906ba
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004906ba;
    }
    // 0049085e  89542420               -mov dword ptr [esp + 0x20], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 00490862  e953feffff             -jmp 0x4906ba
    goto L_0x004906ba;
L_0x00490867:
    // 00490867  3b54241c               +cmp edx, dword ptr [esp + 0x1c]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049086b  0f8e5bfeffff           -jle 0x4906cc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004906cc;
    }
    // 00490871  8954241c               -mov dword ptr [esp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 00490875  e952feffff             -jmp 0x4906cc
    goto L_0x004906cc;
L_0x0049087a:
    // 0049087a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049087c  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 0049087f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490880  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490881  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490882  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00490885:
    // 00490885  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00490887  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00490889  e896300100             -call 0x4a3924
    cpu.esp -= 4;
    sub_4a3924(app, cpu);
    if (cpu.terminate) return;
    // 0049088e  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00490890  83f803                 +cmp eax, 3
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
    // 00490893  7ce5                   -jl 0x49087a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049087a;
    }
    // 00490895  c744240801000000       -mov dword ptr [esp + 8], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = 1 /*0x1*/;
    // 0049089d  e9d5feffff             -jmp 0x490777
    goto L_0x00490777;
L_0x004908a2:
    // 004908a2  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004908a4  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004908a6  e861310100             -call 0x4a3a0c
    cpu.esp -= 4;
    sub_4a3a0c(app, cpu);
    if (cpu.terminate) return;
    // 004908ab  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004908ad  83f803                 +cmp eax, 3
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
    // 004908b0  7cc8                   -jl 0x49087a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049087a;
    }
    // 004908b2  c744240801000000       -mov dword ptr [esp + 8], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = 1 /*0x1*/;
    // 004908ba  e9c8feffff             -jmp 0x490787
    goto L_0x00490787;
L_0x004908bf:
    // 004908bf  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004908c1  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004908c3  e81c320100             -call 0x4a3ae4
    cpu.esp -= 4;
    sub_4a3ae4(app, cpu);
    if (cpu.terminate) return;
    // 004908c8  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004908ca  83f803                 +cmp eax, 3
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
    // 004908cd  7cab                   -jl 0x49087a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049087a;
    }
    // 004908cf  c744240801000000       -mov dword ptr [esp + 8], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = 1 /*0x1*/;
    // 004908d7  e9b7feffff             -jmp 0x490793
    goto L_0x00490793;
L_0x004908dc:
    // 004908dc  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004908de  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004908e0  e8df320100             -call 0x4a3bc4
    cpu.esp -= 4;
    sub_4a3bc4(app, cpu);
    if (cpu.terminate) return;
    // 004908e5  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004908e7  83f803                 +cmp eax, 3
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
    // 004908ea  0f8dbafeffff           -jge 0x4907aa
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004907aa;
    }
    // 004908f0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004908f2  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004908f5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004908f6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004908f7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004908f8  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004908fb:
    // 004908fb  39d3                   +cmp ebx, edx
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
    // 004908fd  0f8dd5feffff           -jge 0x4907d8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004907d8;
    }
    // 00490903  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00490905  e9cefeffff             -jmp 0x4907d8
    goto L_0x004907d8;
L_0x0049090a:
    // 0049090a  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0049090c  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049090e  e851fbffff             -call 0x490464
    cpu.esp -= 4;
    sub_490464(app, cpu);
    if (cpu.terminate) return;
    // 00490913  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00490916  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490917  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490918  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490919  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_49091c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049091c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049091d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049091e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049091f  81ec04020000           -sub esp, 0x204
    (cpu.esp) -= x86::reg32(x86::sreg32(516 /*0x204*/));
    // 00490925  89842400020000         -mov dword ptr [esp + 0x200], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(512) /* 0x200 */) = cpu.eax;
    // 0049092c  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0049092e  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00490930  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00490932  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00490934  7e1a                   -jle 0x490950
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00490950;
    }
    // 00490936  8d0ced00000000         -lea ecx, [ebp*8]
    cpu.ecx = x86::reg32(cpu.ebp * 8);
    // 0049093d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0049093f:
    // 0049093f  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 00490941  8d3c04                 -lea edi, [esp + eax]
    cpu.edi = x86::reg32(cpu.esp + cpu.eax * 1);
    // 00490944  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00490947  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049094a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049094b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049094c  39c8                   +cmp eax, ecx
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
    // 0049094e  7cef                   -jl 0x49093f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049093f;
    }
L_0x00490950:
    // 00490950  8b942414020000         -mov edx, dword ptr [esp + 0x214]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(532) /* 0x214 */);
    // 00490957  8b842400020000         -mov eax, dword ptr [esp + 0x200]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(512) /* 0x200 */);
    // 0049095e  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00490960  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00490961  8d5c2404               -lea ebx, [esp + 4]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00490965  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00490967  e8d4fcffff             -call 0x490640
    cpu.esp -= 4;
    sub_490640(app, cpu);
    if (cpu.terminate) return;
    // 0049096c  81c404020000           -add esp, 0x204
    (cpu.esp) += x86::reg32(x86::sreg32(516 /*0x204*/));
    // 00490972  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490973  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490974  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490975  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

}
